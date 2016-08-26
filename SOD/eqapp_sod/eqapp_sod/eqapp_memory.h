#ifndef EQAPP_MEMORY_H
#define EQAPP_MEMORY_H

typedef struct _EQAPPMEMORY
{
    unsigned int index;
    std::string name;
    std::string filename;
    std::string description;
    bool isEnabled;
} EQAPPMEMORY, *PEQAPPMEMORY;

bool g_memoryIsEnabled = true;
std::vector<EQAPPMEMORY> g_memoryList;
unsigned int g_memoryFilesMax = 255;
unsigned int g_memoryAddressesMax = 8;

void EQAPP_Memory_Load();
void EQAPP_Memory_Unload();
void EQAPP_Memory_Set(PEQAPPMEMORY pMemory, bool bEnable);
void EQAPP_Memory_ToggleByIndex(unsigned int index);
void EQAPP_Memory_Print();

void EQAPP_Memory_Load()
{
    std::cout << "Loading Memory..." << std::endl;

    g_memoryList.clear();

    g_memoryIsEnabled = EQAPP_INI_ReadBool("eqapp/memory.ini", "Memory", "bEnabled", 1);

    if (g_memoryIsEnabled == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "memory is disabled");
        return;
    }

    for (size_t i = 0; i < g_memoryFilesMax; i++)
    {
        std::stringstream ssFilename;
        ssFilename << "sFilename" << i;

        std::string filename = EQAPP_INI_ReadString("eqapp/memory.ini", "Memory", ssFilename.str().c_str(), "");
        if (filename.size() == 0)
        {
            break;
        }

        std::stringstream filepath;
        filepath << "eqapp/memory/" << filename;

        std::stringstream ssEnabled;
        ssEnabled << "bEnabled" << i;

        EQAPPMEMORY memory;
        memory.isEnabled = EQAPP_INI_ReadBool("eqapp/memory.ini", "Memory", ssEnabled.str().c_str(), 0);

        std::cout << __FUNCTION__ << ": " << filename << " isEnabled: " << std::boolalpha << memory.isEnabled << std::noboolalpha << std::endl;

        memory.index          = i;
        memory.filename       = filepath.str();
        memory.name           = EQAPP_INI_ReadString(filepath.str().c_str(), "Memory", "Name", "");
        memory.description    = EQAPP_INI_ReadString(filepath.str().c_str(), "Memory", "Description", "");
        
        g_memoryList.push_back(memory);
    }

    for (auto& memory : g_memoryList)
    {
        if (memory.isEnabled == true)
        {
            EQAPP_Memory_Set(&memory, true);

            std::cout << __FUNCTION__ << ": " << memory.filename << " has been enabled" << std::endl;
        }
    }
}

void EQAPP_Memory_Unload()
{
    std::cout << "Unloading Memory..." << std::endl;

    for (auto& memory : g_memoryList)
    {
        EQAPP_Memory_Set(&memory, false);
    }
}

void EQAPP_Memory_Set(PEQAPPMEMORY pMemory, bool bEnable)
{
    if (pMemory == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "memory is NULL");
        return;
    }

    pMemory->isEnabled = bEnable;

    for (size_t i = 0; i < g_memoryAddressesMax; i++)
    {
        std::stringstream ssAddress;
        ssAddress << "Address" << i;

        std::string sAddress = EQAPP_INI_ReadString(pMemory->filename.c_str(), "Memory", ssAddress.str().c_str(), "");
            
        if (sAddress.size() == 0)
        {
            continue;
        }

        if (sAddress.find("+") == std::string::npos)
        {
            continue;
        }

        std::transform(sAddress.begin(), sAddress.end(), sAddress.begin(), ::tolower);

        std::stringstream ssEnable;
        ssEnable << "Enable" << i;

        std::stringstream ssDisable;
        ssDisable << "Disable" << i;

        std::string sEnable  = EQAPP_INI_ReadString(pMemory->filename.c_str(), "Memory", ssEnable.str().c_str(), "");
        std::string sDisable = EQAPP_INI_ReadString(pMemory->filename.c_str(), "Memory", ssDisable.str().c_str(), "");

        DWORD baseAddress = 0;

        // find eqgame.exe or EQGraphicsDX9.dll and get base address
        if (sAddress.find(EQ_STRING_PROCESS_NAME) != std::string::npos)
        {
            baseAddress = EQ_BASE_ADDRESS;
        }
        else if (sAddress.find(EQ_STRING_GRAPHICS_DLL_NAME) != std::string::npos || sAddress.find(EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE) != std::string::npos)
        {
            baseAddress = EQ_ReadMemory<DWORD>(EQ_GRAPHICS_DLL_POINTER_BASE_ADDRESS);
        }

        std::istringstream addressSplit(sAddress);
        std::vector<std::string> addressTokens;
        for (std::string addressToken; std::getline(addressSplit, addressToken, '+'); addressTokens.push_back(addressToken));

        DWORD offset = std::stoul(addressTokens.back(), nullptr, 16);

        DWORD address = baseAddress + offset;

        std::string sBytes;
        if (bEnable == true)
        {
            sBytes = sEnable;
        }
        else
        {
            sBytes = sDisable;
        }

        if (sBytes.size() == 0)
        {
            break;
        }

        std::istringstream bytesSplit(sBytes);
        std::vector<std::string> bytesTokens;
        for (std::string bytesToken; std::getline(bytesSplit, bytesToken, ' '); bytesTokens.push_back(bytesToken));

        BYTE value[256];
        size_t valueSize = 0;

        for (auto& token : bytesTokens)
        {
            value[valueSize] = (BYTE)(std::stoul(token, nullptr, 16));
            valueSize++;
        }

        DWORD oldProtection;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, valueSize, PAGE_EXECUTE_READWRITE, &oldProtection);

        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, value, valueSize, 0);

        DWORD tempProtection;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, valueSize, oldProtection, &tempProtection);
    }
}

void EQAPP_Memory_ToggleByIndex(unsigned int index)
{
    if (index > (g_memoryList.size() - 1))
    {
        std::stringstream ss;
        ss << "no memory found at specified index: " << index;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    PEQAPPMEMORY pMemory = &g_memoryList.at(index);
    EQ_ToggleBool(pMemory->isEnabled);
    EQAPP_Memory_Set(pMemory, pMemory->isEnabled);
    EQAPP_PrintBool(pMemory->name.c_str(), pMemory->isEnabled);
}

void EQAPP_Memory_Print()
{
    std::cout << "Memory List:" << std::endl;
    std::cout << "Index : Enabled : Name (Description)" << std::endl;

    for (auto& memory : g_memoryList)
    {
        std::cout << "#" << memory.index << " : " << memory.isEnabled << " : " << memory.name << " (" << memory.description << ")" << std::endl;
    }
}

#endif // EQAPP_MEMORY_H
