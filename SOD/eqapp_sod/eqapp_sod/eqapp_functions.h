#ifndef EQAPP_FUNCTIONS_H
#define EQAPP_FUNCTIONS_H

#include "eqapp.h"

template <class T>
void EQAPP_Log(const char* text, T number);

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName);

void EQAPP_CenterWindow(HWND hwnd);
bool EQAPP_IsForegroundWindowCurrentProcessId();

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_IMGUI_TextBool(bool& b);

void EQAPP_PrintErrorMessage(const char* functionName, std::string text);
void EQAPP_PrintDebugMessage(const char* functionName, std::string text);

void EQAPP_COUT_SaveFlags();
void EQAPP_COUT_RestoreFlags();

int EQAPP_INI_ReadInt(const char* filename, const char* section, const char* key, int defaultValue);
bool EQAPP_INI_ReadBool(const char* filename, const char* section, const char* key, int defaultValue);
float EQAPP_INI_ReadFloat(const char* filename, const char* section, const char* key, float defaultValue);
std::string EQAPP_INI_ReadString(const char* filename, const char* section, const char* key, const char* defaultValue);

bool EQAPP_IsAnImportantWindowOpen();

void EQAPP_LootDebugInformation_Print();
void EQAPP_ExecuteCmdDebugInformation_Print();
void EQAPP_SpawnInformation_Print(DWORD spawnInfo);
void EQAPP_BankCurrency_Print();
void EQAPP_CastRayToTarget_Print();
void EQAPP_MeleeRangeToTarget_Print();
void EQAPP_ZoneInformation_Print();

void EQAPP_OpenZoneMapFile();
void EQAPP_PlaySound(const char* filename);
void EQAPP_Beep();
void EQAPP_DeleteFileContents(const char* filename);

//****************************************************************************************************//

void EQAPP_Load();
void EQAPP_Unload();

void EQAPP_SetWindowTitles();

//****************************************************************************************************//

template <class T>
void EQAPP_Log(const char* text, T number)
{
    std::fstream file;
    file.open("eqapp/eqapplog.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
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

DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName)
{
    DWORD moduleBaseAddress = 0;
    DWORD processId = GetCurrentProcessId();
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);

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

void EQAPP_CenterWindow(HWND hwnd)
{
    if (hwnd == NULL)
    {
        return;
    }

    HWND desktopWindow = GetDesktopWindow();
    if (desktopWindow == NULL)
    {
        return;
    }

    RECT desktopRect;
    GetWindowRect(desktopWindow, &desktopRect);

    RECT hwndRect;
    GetWindowRect(hwnd, &hwndRect);

    hwndRect.left = (LONG)(desktopRect.left + ((desktopRect.right  - desktopRect.left) - (hwndRect.right  - hwndRect.left)) * 0.5f);
    hwndRect.top  = (LONG)(desktopRect.top  + ((desktopRect.bottom - desktopRect.top)  - (hwndRect.bottom - hwndRect.top))  * 0.5f);

    HWND taskbarWindow = FindWindowA("Shell_TrayWnd", NULL);
    if (taskbarWindow == NULL)
    {
        return;
    }

    RECT taskbarRect;
    GetWindowRect(taskbarWindow, &taskbarRect);

    hwndRect.top = (LONG)(hwndRect.top - (taskbarRect.bottom - taskbarRect.top) * 0.5f);

    SetWindowPos(hwnd, HWND_DESKTOP, hwndRect.left, hwndRect.top, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE);
    UpdateWindow(hwnd);
}

bool EQAPP_IsForegroundWindowCurrentProcessId()
{
    HWND foregroundHwnd = GetForegroundWindow();

    DWORD foregroundProcessId;
    GetWindowThreadProcessId(foregroundHwnd, &foregroundProcessId);

    return (foregroundProcessId == GetCurrentProcessId());
}

void EQAPP_PrintBool(const char* text, bool& b)
{
    std::cout << text << ": ";

    if (b == true)
    {
        std::cout << "On";
    }
    else
    {
        std::cout << "Off";
    }

    std::cout << std::endl;
}

void EQAPP_IMGUI_TextBool(bool& b)
{
    if (b == false)
    {
        ImGui::Text("Off");
    }
    else
    {
        ImGui::Text("On");
    }
}

void EQAPP_PrintErrorMessage(const char* functionName, std::string text)
{
    std::cout << "[error] " << functionName << ": " << text << std::endl;
}

void EQAPP_PrintDebugMessage(const char* functionName, std::string text)
{
    std::cout << "[debug] " << functionName << ": " << text << std::endl;
}

void EQAPP_COUT_SaveFlags()
{
    g_coutFlags.copyfmt(std::cout);
}

void EQAPP_COUT_RestoreFlags()
{
    std::cout.copyfmt(g_coutFlags);
}

int EQAPP_INI_ReadInt(const char* filename, const char* section, const char* key, int defaultValue)
{
    return GetPrivateProfileIntA(section, key, defaultValue, filename);
}

bool EQAPP_INI_ReadBool(const char* filename, const char* section, const char* key, int defaultValue)
{
    int result = GetPrivateProfileIntA(section, key, defaultValue, filename);

    return (result != 0);
}

float EQAPP_INI_ReadFloat(const char* filename, const char* section, const char* key, float defaultValue)
{
    char bufferDefault[128];
    _snprintf_s(bufferDefault, sizeof(bufferDefault), _TRUNCATE, "%f", defaultValue);

    char bufferResult[128];
    GetPrivateProfileStringA(section, key, bufferDefault, bufferResult, sizeof(bufferResult), filename);

    float result = (float)atof(bufferResult);

    return result;
}

std::string EQAPP_INI_ReadString(const char* filename, const char* section, const char* key, const char* defaultValue)
{
    char result[1024];
    GetPrivateProfileStringA(section, key, defaultValue, result, 1024, filename);
    return result;
}

bool EQAPP_IsAnImportantWindowOpen()
{
    for (auto& window : g_importantWindowsList)
    {
        if (EQ_IsWindowVisible(window) == true)
        {
            return true;
        }
    }

    return false;
}

void EQAPP_LootDebugInformation_Print()
{
    std::cout << "Loot Debug Information:" << std::endl;

    DWORD lootWindow = EQ_ReadMemory<DWORD>(EQ_POINTER_CLootWnd);
    if (lootWindow == NULL)
    {
        std::cout << "Loot Window is NULL." << std::endl;
        return;
    }

    DWORD lootWindowIsVisible = EQ_ReadMemory<BYTE>(lootWindow + EQ_OFFSET_WINDOW_IS_VISIBLE);
    if (lootWindowIsVisible == 0)
    {
        std::cout << "Loot Window is NOT open." << std::endl;
        return;
    }

    for (size_t i = 0; i < EQ_NUM_LOOT_WINDOW_SLOTS; i++)
    {
        DWORD itemInfo = EQ_ReadMemory<DWORD>(lootWindow + (EQ_OFFSET_CLootWnd_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            std::cout << "#" << i << ": item info is NULL" << std::endl;
            continue;
        }

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName == NULL)
        {
            std::cout << "#" << i << ": item name is NULL" << std::endl;
            continue;
        }

        std::cout << "#" << i << ": " << itemName << std::endl;
    }
}

void EQAPP_ExecuteCmdDebugInformation_Print()
{
    std::cout << "ExecuteCmd Debug Information:" << std::endl;

    EQAPP_DeleteFileContents("eqapp/executecmddebug.txt");

    std::fstream file;
    file.open("eqapp/executecmddebug.txt", std::ios::out | std::ios::app);

    for (size_t i = 0; i < EQ_NUM_EXECUTECMD; i++)
    {
        std::string commandName = EQ_GetExecuteCmdName(i);

        if (commandName.size() == 0)
        {
            break;
        }

        std::stringstream ss;
        ss << "#: " << i << " (" << commandName << ")";

        std::cout << ss.str() << std::endl;

        file << "#define EQ_EXECUTECMD_" << commandName << " " << i << std::endl;
    }

    file.close();
}

void EQAPP_SpawnInformation_Print(DWORD spawnInfo)
{
    if (spawnInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__ , " spawn is NULL");
        return;
    }

    std::cout << "Spawn Information:" << std::endl;

    // name

    char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
    memcpy(spawnNumberedName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

    std::cout << "NAME:  " << spawnNumberedName;

    int spawnType = EQ_ReadMemory<BYTE>(spawnInfo + EQ_OFFSET_SPAWN_INFO_TYPE);
    if (spawnType != EQ_SPAWN_TYPE_PLAYER)
    {
        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        std::cout << " (" << spawnName << ")";
    }

    std::cout << std::endl;

    // level

    int spawnLevel = EQ_ReadMemory<BYTE>(spawnInfo + EQ_OFFSET_SPAWN_INFO_LEVEL);

    std::cout << "LEVEL: " << spawnLevel << std::endl;

    // guild

    int spawnGuildId = EQ_ReadMemory<DWORD>(spawnInfo + EQ_OFFSET_SPAWN_INFO_GUILD_ID);

    const char* spawnGuildName = EQ_EQ_Guilds.GetGuildNameById(spawnGuildId);

    std::cout << "GUILD: " << spawnGuildName << " (" << spawnGuildId << ")" << std::endl;

    // race

    int spawnRace = EQ_ReadMemory<DWORD>(spawnInfo + EQ_OFFSET_SPAWN_INFO_RACE);

    const char* spawnRaceDescription = EQ_CEverQuest->GetRaceDesc(spawnRace);

    std::cout << "RACE:  " << spawnRaceDescription << " (" << spawnRace << ")" << std::endl;

    // class

    int spawnClass = EQ_ReadMemory<BYTE>(spawnInfo + EQ_OFFSET_SPAWN_INFO_CLASS);

    const char* spawnClassDescription = EQ_CEverQuest->GetClassDesc(spawnClass);

    std::cout << "CLASS: " << spawnClassDescription << " (" << spawnClass << ")" << std::endl;

    // deity

    int spawnDeity = EQ_ReadMemory<BYTE>(spawnInfo + EQ_OFFSET_SPAWN_INFO_DEITY);

    const char* spawnDeityDescription = EQ_CEverQuest->GetDeityDesc(spawnDeity);

    std::cout << "DEITY: " << spawnDeityDescription << " (" << spawnDeity << ")" << std::endl;

    // body type description

    std::string spawnBodyTypeDescription = EQ_GetSpawnBodyTypeDescription(spawnInfo);

    std::cout << "BANE:  " << spawnBodyTypeDescription << std::endl;
}

void EQAPP_BankCurrency_Print()
{
    DWORD charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        return;
    }

    DWORD bankPlatinum = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_PLATINUM);
    DWORD bankGold     = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_GOLD);
    DWORD bankSilver   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_SILVER);
    DWORD bankCopper   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_COPPER);

    std::cout << "You have "
              << bankPlatinum << "p "
              << bankGold     << "g "
              << bankSilver   << "s "
              << bankCopper   << "c in the bank."
              << std::endl;
}

void EQAPP_CastRayToTarget_Print()
{
    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        DWORD targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn == NULL)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "target is NULL");
            return;
        }

        FLOAT targetY = EQ_GetSpawnY(targetSpawn);
        FLOAT targetX = EQ_GetSpawnX(targetSpawn);
        FLOAT targetZ = EQ_GetSpawnZ(targetSpawn);

        int result = EQ_CastRay(playerSpawn, targetY, targetX, targetZ);

        std::string resultString;
        if (result == 0)
        {
            resultString = "Failed";
        }
        else
        {
            resultString = "Succeeded";
        }

        std::cout << "Cast Ray to Target result: " << resultString << std::endl;
    }
}

void EQAPP_MeleeRangeToTarget_Print()
{
    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        DWORD targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn == NULL)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "target is NULL");
            return;
        }

        FLOAT meleeRange = EQ_get_melee_range(playerSpawn, targetSpawn);

        std::cout << "Melee Range to Target: " << meleeRange << std::endl;
    }
}

void EQAPP_ZoneInformation_Print()
{
    DWORD zoneId = EQ_GetZoneId();

    std::string zoneLongName = EQ_GetZoneLongName();
    if (zoneLongName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone long name is NULL");
        return;
    }

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::cout << "Zone Information: " << zoneLongName << " (" << zoneShortName << ") " << "(ID: " << zoneId << ")" << std::endl;
}

void EQAPP_OpenZoneMapFile()
{
    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << "maps\\" << zoneShortName << ".txt";

    ShellExecuteA(0, "open", filePath.str().c_str(), 0, 0, SW_SHOW);

    std::cout << "Opening zone map file: " << filePath.str() << std::endl;

    for (size_t i = 1; i < (EQ_NUM_MAP_LAYERS + 1); i++)
    {
        std::stringstream filePath;
        filePath << "maps\\" << zoneShortName << "_" << i << ".txt";

        ShellExecuteA(0, "open", filePath.str().c_str(), 0, 0, SW_SHOW);

        std::cout << "Opening zone map file: " << filePath.str() << std::endl;
    }
}

void EQAPP_PlaySound(const char* filename)
{
    PlaySoundA(filename, 0, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQAPP_Beep()
{
    MessageBeep(0);
}

void EQAPP_DeleteFileContents(const char* filename)
{
    std::fstream file;
    file.open(filename, std::ios::out | std::ios::trunc);
    file.close();
}

#endif // EQAPP_FUNCTIONS_H
