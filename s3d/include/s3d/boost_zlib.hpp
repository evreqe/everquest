#include <string>
#include <sstream>

#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/device/back_inserter.hpp>

std::string decompress_string(const std::string& s)
{
    std::stringstream compressed;
    compressed << s;

    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::zlib_decompressor());
    in.push(compressed);

    std::stringstream decompressed;
    boost::iostreams::copy(in, decompressed);

    return decompressed.str();
}

std::string decompress_string_fast(const std::string& s)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::zlib_decompressor());
    in.push(boost::make_iterator_range(s));

    std::string decompressed;
    boost::iostreams::copy(in, boost::iostreams::back_inserter(decompressed));

    return decompressed;
}

void decompress_string_fast_ex(const std::string& s, std::string& buffer)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::zlib_decompressor());
    in.push(boost::make_iterator_range(s));

    boost::iostreams::copy(in, boost::iostreams::back_inserter(buffer));
}
