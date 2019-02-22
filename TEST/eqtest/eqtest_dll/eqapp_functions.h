#pragma once

#include "eqapp.h"

void EQAPP_Log(const char* text);
void EQAPP_PrintTextToFile(const char* fileName, const char* text);
void EQAPP_PrintTextToFileNoDuplicates(const char* fileName, const char* text);

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_PrintDebugText(const char* functionName, const char* text);
void EQAPP_ToggleDebugText();

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(DWORD processID, const wchar_t* moduleName);
uint32_t EQAPP_GetNumClients();
bool EQAPP_IsProcessRunning(const wchar_t* fileName);
bool EQAPP_IsForegroundWindowCurrentProcessID();
bool EQAPP_IsVKKeyDown(int vkKey);
uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high);
void EQAPP_PlaySound(const char* fileName);
void EQAPP_StopSound();
void EQAPP_Beep();
void EQAPP_BeepEx(UINT beepType);
bool EQAPP_FileExists(const char* fileName);
void EQAPP_DeleteFileContents(const char* fileName);
std::string EQAPP_ReadFileToString(const char* fileName);
void EQAPP_ReadFileToList(const char* fileName, std::vector<std::string>& list, bool printLines = true);
std::vector<uint32_t> EQAPP_GetNPCSpawnIDListSortedByDistance();
bool EQAPP_IsInGame();
void EQAPP_CopyTextToClipboard(const char* text);
void EQAPP_PrintSpawnList();
void EQAPP_PrintLocation();
void EQAPP_PrintMouseLocation();
void EQAPP_InventoryFind(const char* text);
void EQAPP_SetWindowTitle(const char* text);
BOOL CALLBACK EQAPP_UpdateClientWindowList_EnumWindowsProc(HWND hwnd, LPARAM lParam);
bool EQAPP_UpdateClientWindowList();

void EQAPP_Log(const char* text)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/log.txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << std::endl;
    file.close();
}

void EQAPP_PrintTextToFile(const char* fileName, const char* text)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << fileName;

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << text << std::endl;
    file.close();
}

void EQAPP_PrintTextToFileNoDuplicates(const char* fileName, const char* text)
{
    std::vector<std::string> fileContents;
    EQAPP_ReadFileToList(fileName, fileContents, false);

    for (auto& fileLine : fileContents)
    {
        if (fileLine.size() == 0)
        {
            continue;
        }

        if (fileLine == text)
        {
            return;
        }
    }

    EQAPP_PrintTextToFile(fileName, text);
}

void EQAPP_PrintBool(const char* text, bool& b)
{
    std::cout << text << ": " << (b ? "On" : "Off") << std::endl;
}

void EQAPP_PrintDebugText(const char* functionName, const char* text)
{
    if (g_EQAppDebugTextIsEnabled == false)
    {
        return;
    }

    std::cout << "[DEBUG] " << functionName << "(): " << text << std::endl;
}

void EQAPP_ToggleDebugText()
{
    EQ_ToggleBool(g_EQAppDebugTextIsEnabled);
    EQAPP_PrintBool("Debug Text", g_EQAppDebugTextIsEnabled);
}

void EQAPP_EnableDebugPrivileges()
{
    HANDLE token;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
    {
        TOKEN_PRIVILEGES tp;
        TOKEN_PRIVILEGES tpPrevious;

        DWORD cbPrevious = sizeof(TOKEN_PRIVILEGES);

        LUID luid;

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
        {
            tp.PrivilegeCount           = 1;
            tp.Privileges[0].Luid       = luid;
            tp.Privileges[0].Attributes = 0;

            AdjustTokenPrivileges(token, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), &tpPrevious, &cbPrevious);

            tpPrevious.PrivilegeCount            = 1;
            tpPrevious.Privileges[0].Luid        = luid;
            tpPrevious.Privileges[0].Attributes |= (SE_PRIVILEGE_ENABLED);

            AdjustTokenPrivileges(token, FALSE, &tpPrevious, cbPrevious, NULL, NULL);
        }
    }

    CloseHandle(token);
}

DWORD EQAPP_GetModuleBaseAddress(DWORD processID, const wchar_t* moduleName)
{
    DWORD moduleBaseAddress = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processID);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 ModuleEntry32 = {0};
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(snapshot, &ModuleEntry32))
        {
            do
            {
                if (wcscmp(ModuleEntry32.szModule, moduleName) == 0)
                {
                    moduleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                    break;
                }
            } while (Module32Next(snapshot, &ModuleEntry32));
        }

        CloseHandle(snapshot);
    }

    return moduleBaseAddress;
}

uint32_t EQAPP_GetNumClients()
{
    uint32_t count = 0;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        return count;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &pe32))
    {
        do
        {
            if (lstrcmpi(pe32.szExeFile, L"eqgame.exe") == 0)
            {
                count++;
            }

        } while (Process32Next(snapshot, &pe32));
    }

    CloseHandle(snapshot);

    return count;
}

bool EQAPP_IsProcessRunning(const wchar_t* fileName)
{
    bool result = false;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        return result;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &pe32))
    {
        do
        {
            if (lstrcmpi(pe32.szExeFile, fileName) == 0)
            {
                result = true;
                break;
            }

        } while (Process32Next(snapshot, &pe32));
    }

    CloseHandle(snapshot);

    return result;
}

bool EQAPP_IsForegroundWindowCurrentProcessID()
{
    HWND foregroundHwnd = GetForegroundWindow();

    DWORD foregroundProcessId;
    GetWindowThreadProcessId(foregroundHwnd, &foregroundProcessId);

    return (foregroundProcessId == GetCurrentProcessId());
}

bool EQAPP_IsVKKeyDown(int vkKey)
{
    if (GetAsyncKeyState(vkKey) & 0x8000)
    {
        return true;
    }

    return false;
}

uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high)
{
    std::uniform_int_distribution<uint32_t> uid;
    std::uniform_int_distribution<uint32_t>::param_type uidpt(low, high);

    return uid(g_EQAppRandomEngine, uidpt);
}

template <class T>
T EQAPP_GetRandomNumberAny(T low, T high)
{
    std::uniform_int_distribution<T> uid;
    std::uniform_int_distribution<T>::param_type uidpt(low, high);

    return uid(g_EQAppRandomEngine, uidpt);
}

void EQAPP_PlaySound(const char* fileName)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/sounds/" << fileName;

    PlaySoundA(filePath.str().c_str(), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQAPP_StopSound()
{
    PlaySoundA(NULL, NULL, NULL);
}

void EQAPP_Beep()
{
    MessageBeep(0);
}

void EQAPP_BeepEx(UINT beepType)
{
    MessageBeep(beepType);
}

bool EQAPP_FileExists(const char* fileName)
{
    std::ifstream file(fileName);
    return file.good();
}

void EQAPP_DeleteFileContents(const char* fileName)
{
    std::fstream file;
    file.open(fileName, std::fstream::out | std::fstream::trunc);
    file.close();
}

std::string EQAPP_ReadFileToString(const char* fileName)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << fileName;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return std::string();
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();

    return buffer.str();
}

void EQAPP_ReadFileToList(const char* fileName, std::vector<std::string>& list, bool printLines)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << fileName;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        if (printLines == true)
        {
            std::cout << fileName << ": " << line << std::endl;
        }

        list.push_back(line);
    }

    file.close();
}

std::vector<uint32_t> EQAPP_GetNPCSpawnIDListSortedByDistance()
{
    std::vector<uint32_t> spawnIDList;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return spawnIDList;
    }

    std::map<float, uint32_t> spawnList;

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType != EQ_SPAWN_TYPE_NPC)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        // skip mounts
        auto spawnMountRiderSpawn = EQ_GetSpawnMountRiderSpawn(spawn);
        if (spawnMountRiderSpawn != NULL)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        auto spawnRace = EQ_GetSpawnRace(spawn);
        auto spawnClass = EQ_GetSpawnClass(spawn);

        // skip auras
        if (spawnRace == EQ_RACE_INVISIBLE_MAN && spawnClass == EQ_CLASS_OBJECT)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        float spawnY = EQ_GetSpawnY(spawn);
        float spawnX = EQ_GetSpawnX(spawn);
        float spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance3D(playerSpawnY, playerSpawnX, playerSpawnZ, spawnY, spawnX, spawnZ);

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(spawnY, spawnX, spawnZ, screenX, screenY);
        if (result == false)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        uint32_t spawnID = EQ_GetSpawnID(spawn);

        spawnList.insert({spawnDistance, spawnID});

        spawn = EQ_GetSpawnNext(spawn);
    }

    for (auto& s : spawnList)
    {
        spawnIDList.push_back(s.second);
    }

    return spawnIDList;
}

bool EQAPP_IsInGame()
{
    return g_EQAppIsInGame;
}

void EQAPP_CopyTextToClipboard(const char* text)
{
    size_t length = strlen(text) + 1;

    HGLOBAL memory = GlobalAlloc(GMEM_MOVEABLE, length);
    memcpy(GlobalLock(memory), text, length);
    GlobalUnlock(memory);

    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, memory);
    CloseClipboard();
}

void EQAPP_PrintSpawnList()
{
    auto spawn = EQ_GetFirstSpawn();

    while (spawn != NULL)
    {
        std::stringstream ss;

        if (EQ_GetSpawnClass(spawn) == EQ_CLASS_OBJECT)
        {
            ss << "* ";
        }

        ss << "[" << EQ_GetSpawnLevel(spawn) << "]";

        auto spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() != 0)
        {
            ss << " " << spawnName;
        }

        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType == EQ_SPAWN_TYPE_NPC)
        {
            auto spawnLastName = EQ_GetSpawnLastName(spawn);
            if (spawnLastName.size() != 0)
            {
                ss << " (" << spawnLastName << ")";
            }
        }

        ss << " -";

        ss << " Type=" << spawnType;
        ss << " Race=" << EQ_GetSpawnRace(spawn);
        ss << " Class=" << EQ_GetSpawnClass(spawn);
        ss << " Height=" << EQ_GetSpawnHeight(spawn);

        std::cout << ss.str() << std::endl;

        spawn = EQ_GetSpawnNext(spawn);
    }
}

void EQAPP_PrintLocation()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
        auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
        auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

        std::cout << "Your location is " << playerSpawnY << ", " << playerSpawnX << ", " << playerSpawnZ << "." << std::endl;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn != NULL)
    {
        auto targetSpawnY = EQ_GetSpawnY(targetSpawn);
        auto targetSpawnX = EQ_GetSpawnX(targetSpawn);
        auto targetSpawnZ = EQ_GetSpawnZ(targetSpawn);

        std::cout << "Your target's location is " << targetSpawnY << ", " << targetSpawnX << ", " << targetSpawnZ << "." << std::endl;
    }
}

void EQAPP_PrintMouseLocation()
{
    std::cout << "Mouse X,Y: " << EQ_GetMouseX() << "," << EQ_GetMouseY() << std::endl;
}

void EQAPP_InventoryFind(const char* text)
{
    uint32_t resultsCount = 0;

    for (auto& it : std__filesystem::directory_iterator(std__filesystem::current_path()))
    {
        if (it.path().extension().string() != ".txt")
        {
            continue;
        }

        std::string fileName = it.path().filename().string();

        if (EQAPP_String_EndsWith(fileName, "-Inventory.txt") == false)
        {
            continue;
        }

        ////std::cout << fileName << std::endl;

        std::fstream file;
        file.open(fileName, std::fstream::in);
        if (file.is_open() == false)
        {
            std::stringstream ss;
            ss << "failed to open file: " << fileName;

            EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
            continue;
        }

        std::string line;
        while (std::getline(file, line))
        {
            if (line.size() == 0)
            {
                continue;
            }

            if (EQAPP_String_Contains(line, text) == true)
            {
                std::cout << fileName << ": " << line << "\n";

                resultsCount++;
            }
        }

        file.close();
    }

    std::cout << resultsCount << " result(s) for '" << text << "'" << std::endl;
}

void EQAPP_SetWindowTitle(const char* text)
{
    HWND hwnd = EQ_GetWindow();
    if (hwnd == NULL)
    {
        return;
    }

    SetWindowTextA(hwnd, text);
}

BOOL CALLBACK EQAPP_UpdateClientWindowList_EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    if (hwnd == EQ_GetWindow())
    {
        return TRUE;
    }

    int windowTitleLength = GetWindowTextLengthA(hwnd) + 1;

    std::string windowTitle(windowTitleLength, L'\0');
    GetWindowTextA(hwnd, &windowTitle[0], windowTitleLength);

    if (windowTitle.size() != 0)
    {
        if (EQAPP_String_BeginsWith(windowTitle, "EverQuest") == true || EQAPP_String_BeginsWith(windowTitle, "EQ: ") == true)
        {
            g_EQAppClientWindowList.insert( {windowTitle, hwnd} );
        }

        for (auto& classShortName : EQ_CLASS_ShortName_Strings)
        {
            if (EQAPP_String_BeginsWith(windowTitle, classShortName.second))
            {
                g_EQAppClientWindowList.insert( {windowTitle, hwnd} );
            }
        }
    }

    return TRUE;
}

bool EQAPP_UpdateClientWindowList()
{
    g_EQAppClientWindowList.clear();

    EnumWindows(EQAPP_UpdateClientWindowList_EnumWindowsProc, NULL);

    return (g_EQAppClientWindowList.size() != 0);
}
