#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::string ul_to_hex(unsigned long ul)
{
    std::stringstream buffer;
    buffer << std::setw(8) << std::setfill('0') << std::hex << std::uppercase << ul;

    return buffer.str();
}

template <class T>
std::string read_string_from_file(T& file)
{
    std::stringstream bytes;
    char byte;

    while (!file.eof())
    {
        file >> std::noskipws >> byte;

        if (byte == '\0')
            return bytes.str();
        else
            bytes << byte;
    }

    return "";
}

template <class T>
std::string read_data_from_file(T& file, unsigned int size)
{
    std::stringstream bytes;
    char byte;

    unsigned int i = 0;
    for (i = 0; i < size; i++)
    {
        file >> std::noskipws >> byte;

        bytes << byte;
    }

    return bytes.str();
}

bool write_stringstream_data_to_file(const std::string& filename, std::stringstream& ss)
{
    std::fstream file;
    file.open(filename.c_str(), std::ios::out | std::ios::binary);

    if (!file.good() || file.fail())
        return false;

    file << ss.str();

    file.close();

    return true;
}
