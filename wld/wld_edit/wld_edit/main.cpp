#include <cstdlib>
#include <cstdint>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef struct WLDHEADER
{
    uint32_t magicNumber;
    uint32_t version;
    uint32_t fragmentCount;
    uint32_t unknown1;
    uint32_t unknown2;
    uint32_t stringHashSize;
    uint32_t unknown3;
} WLDHEADER;

typedef struct WLDFRAGMENTHEADER
{
    uint32_t size;
    uint32_t type;
    int nameReference;
} WLDFRAGMENTHEADER;

// placeable
typedef struct WLDFRAGMENT15
{
    WLDFRAGMENTHEADER header;
    int nameReference;
    uint32_t flags;
    uint32_t unknown1;
    float y, x, z;
    float rotation[3];
    float scale[3];
    uint32_t unknown2;
    uint32_t flags2;
} WLDFRAGMENT15;

// zone geometry
typedef struct WLDFRAGMENT36
{
    WLDFRAGMENTHEADER header;
    uint32_t flags;
    int textureListReference;
    int animationVerticesReference;
    uint32_t unknown1;
    uint32_t unknown2;
    float x, y, z;
    float rotation[3];
    float maxDistance;
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
    uint16_t vertexCount;
    uint16_t uvCount; // texture coordinates
    uint16_t normalCount;
    uint16_t colorCount;
    uint16_t polygonCount;
    uint16_t vertexPieceCount;
    uint16_t polygonTextureCount;
    uint16_t vertexTextureCount;
    uint16_t size9;
    uint16_t scale;
} WLDFRAGMENT36;

void WLD_DecodeString(char* str, size_t length)
{
    unsigned char hash[] = {0x95, 0x3A, 0xC5, 0x2A, 0x95, 0x7A, 0x95, 0x6A};

    for(size_t i = 0; i < length; i++)
    {
        str[i] ^= hash[i % 8];
    }
}

const char* WLD_GetName(const char* stringHash, int stringHashSize, int nameReference)
{
    if (nameReference < 0 && -nameReference < stringHashSize)
    {
        return &stringHash[-nameReference];
    }

    return nullptr;
}

int main(int argc, char* argv[])
{
    if (argc == 0)
    {
        return 0;
    }

    if (argc < 3)
    {
        std::cout << "argc < 3" << std::endl;
        return 0;
    }

    std::stringstream fileName;
    fileName << argv[1] << "/objects.wld";

    std::cout << "File: " << fileName.str() << std::endl;

    std::string searchTerm(argv[2]);
    std::cout << "Search Term: " << searchTerm << std::endl;

    std::fstream output;
    output.open("output.txt", std::ios::out);
    output << "";
    output.close();

    output.open("output.txt", std::ios::in | std::ios::out | std::ios::app);

    std::fstream file;
    file.open(fileName.str().c_str(), std::ios::in | std::ios::out | std::ios::binary);

    auto fileContentsBinary = [&file]
    {
      std::ostringstream ss{};
      ss << file.rdbuf();
      return ss.str();
    } ();

    file.clear();
    file.seekg(0, std::ios::beg);

    std::string fileContents = std::string
    (
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );

    char* wldContents = (char*)fileContents.c_str();

    WLDHEADER wldHeader;
    memcpy(&wldHeader, wldContents, sizeof(WLDHEADER));

    std::cout << "Magic Number: " << std::hex << wldHeader.magicNumber << std::dec << std::endl;
    if (wldHeader.magicNumber != 0x54503D02)
    {
        std::cout << "Magic Number is incorrect!" << std::endl;
    }

    std::cout << "Version: " << std::hex << wldHeader.version << std::dec << std::endl;
    if (wldHeader.version == 0x00015500)
    {
        std::cout << "Version is old format." << std::endl;
    }
    else if (wldHeader.version == 0x1000C800)
    {
        std::cout << "Version is new format." << std::endl;
    }

    std::cout << "Fragment Count: " << wldHeader.fragmentCount << std::endl;

    std::cout << "String Hash Size: " << wldHeader.stringHashSize << std::endl;

    size_t filePosition = sizeof(WLDHEADER);

    char* stringHash = wldContents + filePosition;
    WLD_DecodeString(stringHash, wldHeader.stringHashSize);

    //std::cout << "String Hash:" << std::endl;
    //std::cout << stringHash << std::endl;

    filePosition = (sizeof(WLDHEADER) + wldHeader.stringHashSize);

    for(size_t i = 0; i < wldHeader.fragmentCount; i++)
    {
        WLDFRAGMENTHEADER fragmentHeader;
        memcpy(&fragmentHeader, (wldContents + filePosition), sizeof(WLDFRAGMENTHEADER));

        if (fragmentHeader.type == 0x15)
        {
            WLDFRAGMENT15 fragment15;
            memcpy(&fragment15, (wldContents + filePosition), sizeof(WLDFRAGMENT15));

            std::string name = WLD_GetName(stringHash, wldHeader.stringHashSize, fragment15.nameReference);

            //std::cout << "Name: " << name << std::endl;

/*
            output << "Name: " << name << std::endl;
            output << "NameReference: " << fragment15.nameReference << std::endl;
            output << "NameReference Hex: " << std::hex << fragment15.nameReference << std::dec << std::endl;
            output << "Y: " << fragment15.y << std::endl;
            output << "X: " << fragment15.x << std::endl;
            output << "Z: " << fragment15.z << std::endl;
            output << "R0: " << fragment15.rotation[0] << std::endl;
            output << "R1: " << fragment15.rotation[1] << std::endl;
            output << "R2: " << fragment15.rotation[2] << std::endl;
            output << "S0: " << fragment15.scale[0] << std::endl;
            output << "S1: " << fragment15.scale[1] << std::endl;
            output << "S2: " << fragment15.scale[2] << std::endl;
*/

            output << fragment15.y << ", " << fragment15.x << ", " << fragment15.z << ", " << name << std::endl;

            if (searchTerm.size() != 0 && searchTerm != "ignore" && name.find(searchTerm.c_str()) != std::string::npos)
            {
                fileContentsBinary.at(filePosition + 4) = '\x00';
            }
        }
        //else if (fragmentHeader.type == 0x36)
        //{
            //WLDFRAGMENT36 fragment36;
            //memcpy(&fragment36, (wldContents + filePosition), sizeof(WLDFRAGMENT36));

            //std::cout << "Fragment 36: " << std::hex << fragment36.header.nameReference << std::dec << std::endl;

            //std::string name = WLD_GetName(stringHash, wldHeader.stringHashSize, fragment36.header.nameReference);

            //std::cout << "Name: " << name << std::endl;

            //output << name << std::endl;
        //}

        filePosition += sizeof(WLDFRAGMENTHEADER) + fragmentHeader.size - 4;
    }

    file.close();

    output.close();

    if (searchTerm.size() != 0 && searchTerm != "ignore")
    {
        std::fstream newFile;
        newFile.open("objects.wld", std::ios::out | std::ios::binary);
        newFile.write(fileContentsBinary.c_str(), fileContentsBinary.size());
        newFile.close();
    }

    return 0;
}