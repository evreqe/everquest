#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include <s3d/boost_foreach.hpp>
#include <s3d/boost_zlib.hpp>
#include <s3d/boost_filesystem.hpp>

#include <s3d/utility.hpp>

namespace s3d
{
    struct file_t
    {
        unsigned long checksum;
        unsigned long offset;
        unsigned long size; // decompressed size
    };

    struct file_block_t
    {
        unsigned long deflated_length; // compressed size
        unsigned long inflated_length; // decompressed size
    };

    struct sort_files_by_offset_t
    {
        bool operator() (const file_t& file1, const file_t& file2)
        {
            return file1.offset < file2.offset;
        }
    };

    class file
    {
        private:
            std::fstream m_file;
            std::string m_filename;
            std::string::size_type m_file_size;
            std::string m_file_contents;

            unsigned long m_files_offset;
            unsigned long m_file_names_offset;

            unsigned long m_num_files;

            std::vector<file_t> m_files;
            std::vector<file_t>::iterator m_files_it;

            std::vector<std::string> m_file_names;

        public:
            file();
            file(const std::string& filename);
            ~file();

            bool open(const std::string& filename);
            void close();

            std::string read_file_from_offset(unsigned long offset, unsigned long size);

            void extract(bool extract_to_new_folder = true, bool extract_textures_only = false, std::string filename = "null");

            std::string get_filename();
            std::string::size_type get_file_size();
            std::string get_file_contents();

            unsigned long get_num_files();

            std::vector<file_t> get_files();
            std::vector<std::string> get_file_names();
    };

    file::file()
    {
        //
    }

    file::file(const std::string& filename)
    {
        open(filename);
    }

    file::~file()
    {
        close();
    }

    bool file::open(const std::string& filename)
    {
        m_file.open(filename.c_str(), std::ios::in | std::ios::binary);

        if (!m_file.good() || m_file.fail())
            return false;

        m_filename = filename;

        m_file.seekg(0, std::ios::end);
        m_file_size = m_file.tellg();

        m_file_contents.resize(m_file_size, ' ');
        m_file.seekg(0);
        m_file.read(&m_file_contents[0], m_file_size);

        m_file.seekg(0, std::ios::beg);
        m_file.read((char*)&m_files_offset, 4);

        m_file.seekg(m_files_offset, std::ios::beg);
        m_file.read((char*)&m_num_files, 4);

        unsigned int i = 0;
        for (i = 0; i < m_num_files; i++)
        {
            file_t file;

            m_file.read((char*)&file.checksum, 4);
            m_file.read((char*)&file.offset,   4);
            m_file.read((char*)&file.size,     4);

            m_files.push_back(file);
        }

        std::sort(m_files.begin(), m_files.end(), sort_files_by_offset_t());

        std::string file_names_data = read_file_from_offset(m_files.back().offset, m_files.back().size);

        /*
            std::string file_names_data;
            for (m_files_it = m_files.begin(); m_files_it != m_files.end(); m_files_it++)
            {
                if ((*m_files_it).checksum == 0x61580AC9)
                {
                    file_names_data = read_file_from_offset((*m_files_it).offset, (*m_files_it).size);
                }
            }
        */

        std::istringstream file_names_data_iss(file_names_data);
        file_names_data_iss.seekg(0, std::ios::beg);
        file_names_data_iss.seekg(8, std::ios::cur);

        unsigned int j = 0;
        for (j = 0; j < (m_num_files - 1); j++)
        {
            std::string file_name = read_string_from_file(file_names_data_iss);
            m_file_names.push_back(file_name);

            file_names_data_iss.seekg(4, std::ios::cur);
        }

        return true;
    }

    void file::close()
    {
        m_file.close();
    }

    std::string file::read_file_from_offset(unsigned long offset, unsigned long size)
    {
        m_file.seekg(offset, std::ios::beg);

        std::stringstream file_block_data_decompressed;

        unsigned int inflated = 0;
        while (inflated != size)
        {
            file_block_t file_block;

            m_file.read((char*)&file_block.deflated_length, 4);
            m_file.read((char*)&file_block.inflated_length, 4);
            
            std::string file_block_data_compressed = read_data_from_file(m_file, file_block.deflated_length);

            file_block_data_decompressed << decompress_string_fast(file_block_data_compressed);

            inflated += file_block.inflated_length;
        }

        return file_block_data_decompressed.str();
    }

    void file::extract(bool extract_to_new_folder, bool extract_textures_only, std::string filename)
    {
        unsigned int file_index = 0;

        foreach (file_t file, m_files)
        {
            if (file_index >= (m_num_files - 1))
            {
                continue;
            }

            if (file.offset == m_file_names_offset)
            {
                continue;
            }

            m_file.seekg(file.offset, std::ios::beg);

            std::string file_data = read_file_from_offset(file.offset, file.size);
            std::stringstream file_data_ss(file_data);

            std::string file_name = m_file_names.at(file_index);
            std::string file_extension = file_name.substr(file_name.find_last_of(".") + 1);

            file_index++;

            if (extract_textures_only)
            {
                if (file_extension == "bmp" || file_extension == "dds")
                {
                    //
                }
                else
                {
                    continue;
                }
            }

            if (filename != "null")
            {
                if (file_name != filename)
                {
                    continue;
                }
            }

            std::string folder_name;

            if (extract_to_new_folder == true)
            {
                folder_name = m_filename.substr(0, m_filename.find_last_of("."));

                if (boost::filesystem::exists(folder_name) == false)
                {
                    boost::filesystem::create_directory(folder_name);
                }
            }

            std::stringstream out_filename;

            if (extract_to_new_folder == true)
            {
                out_filename << folder_name << "\\" << file_name;
            }
            else
            {
                out_filename << file_name;
            }

            write_stringstream_data_to_file(out_filename.str(), file_data_ss);
        }
    }

    std::string file::get_filename() { return m_filename; }
    std::string::size_type file::get_file_size() { return m_file_size; }
    std::string file::get_file_contents() { return m_file_contents; }

    unsigned long file::get_num_files() { return m_num_files - 1; }

    std::vector<file_t> file::get_files() { return m_files; }
    std::vector<std::string> file::get_file_names() { return m_file_names; }
}
