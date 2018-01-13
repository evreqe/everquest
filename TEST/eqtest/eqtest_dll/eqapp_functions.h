#pragma once

#include "eqapp.h"

template <class T>
void EQAPP_Log(const char* text, T number);

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_PrintDebugMessage(const char* functionName, const std::string& text);

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(DWORD processID, const wchar_t* moduleName);
bool EQAPP_IsForegroundWindowCurrentProcessId();
bool EQAPP_IsKeyDown(int vkKey);

uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high);

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);
bool EQAPP_String_StartsWith(std::string& subject, const std::string& search);
std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_JoinStrings(const std::vector<std::string>& elements, const std::string& separator);
void EQAPP_String_Split(const std::string& subject, std::vector<std::string>& tokens, char delimiter);

int EQAPP_INI_ReadInt(const char* filename, const char* section, const char* key, int defaultValue);
bool EQAPP_INI_ReadBool(const char* filename, const char* section, const char* key, int defaultValue);
float EQAPP_INI_ReadFloat(const char* filename, const char* section, const char* key, float defaultValue);
std::string EQAPP_INI_ReadString(const char* filename, const char* section, const char* key, const char* defaultValue);

void EQAPP_PlaySound(const char* filename);
void EQAPP_Beep();
void EQAPP_BeepEx(UINT beepType);
bool EQAPP_FileExists(const char *fileName);
void EQAPP_DeleteFileContents(const char* filename);
std::string EQAPP_ReadFileContents(const char* filename);
void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list, bool coutLines = true);

void EQAPP_SetWindowTitleToPlayerSpawnName();

bool EQAPP_HasTimeElapsed(std::chrono::time_point<std::chrono::steady_clock>& timer, long long timerInterval);

template <class T>
void EQAPP_Log(const char* text, T number)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/log.txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

void EQAPP_PrintBool(const char* text, bool& b)
{
    std::cout << text << ": " << (b ? "On" : "Off") << std::endl;
}

void EQAPP_PrintDebugMessage(const char* functionName, const std::string& text)
{
    if (g_EQAppDebugMessageIsEnabled == false)
    {
        return;
    }

    std::cout << "[DEBUG] " << functionName << "(): " << text << std::endl;
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

bool EQAPP_IsForegroundWindowCurrentProcessId()
{
    HWND foregroundHwnd = GetForegroundWindow();

    DWORD foregroundProcessId;
    GetWindowThreadProcessId(foregroundHwnd, &foregroundProcessId);

    return (foregroundProcessId == GetCurrentProcessId());
}

bool EQAPP_IsKeyDown(int vkKey)
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

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
    std::size_t position = 0;
    while ((position = subject.find(search, position)) != std::string::npos)
    {
         subject.replace(position, search.length(), replace);
         position += replace.length();
    }
}

bool EQAPP_String_StartsWith(std::string& subject, const std::string& search)
{
    return (subject.compare(0, search.size(), search) == 0);
}

std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end)
{
    std::size_t beginPosition;
    if ((beginPosition = subject.find(begin)) != std::string::npos)
    {
        beginPosition = beginPosition + begin.length();

        std::size_t endPosition;
        if ((endPosition = subject.find(end, beginPosition)) != std::string::npos && endPosition != beginPosition)
        {
            return subject.substr(beginPosition, endPosition - beginPosition);
        }
    }

    return std::string();
}

std::string EQAPP_String_JoinStrings(const std::vector<std::string>& elements, const std::string& separator)
{
    if (elements.empty() == false)
    {
        std::stringstream ss;

        auto it = elements.cbegin();
        while (true)
        {
            ss << *it++;

            if (it != elements.cend())
            {
                ss << separator;
            }
            else
            {
                return ss.str();
            }
        }
    }

    return std::string();
}

void EQAPP_String_Split(const std::string& subject, std::vector<std::string>& tokens, char delimiter)
{
    std::istringstream iss(subject);
    for (std::string token; std::getline(iss, token, delimiter); tokens.push_back(token));
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
    char buffer[1024];
    int result = GetPrivateProfileStringA(section, key, defaultValue, buffer, sizeof(buffer), filename);

    return std::string(buffer, result);
}

void EQAPP_PlaySound(const char* filename)
{
    PlaySoundA(filename, 0, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQAPP_Beep()
{
    MessageBeep(0);
}

void EQAPP_BeepEx(UINT beepType)
{
    MessageBeep(beepType);
}

bool EQAPP_FileExists(const char *fileName)
{
    std::ifstream file(fileName);
    return file.good();
}

void EQAPP_DeleteFileContents(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::out | std::fstream::trunc);
    file.close();
}

std::string EQAPP_ReadFileContents(const char* filename)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << filename;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());
        return std::string();
    }

    std::string fileContents((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    file.close();

    return fileContents;
}

void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list, bool coutLines)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << filename;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());
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

        if (coutLines == true)
        {
            std::cout << filename << ": " << line << std::endl;
        }

        list.push_back(line);
    }

    file.close();
}

void EQAPP_SetWindowTitleToPlayerSpawnName()
{
    std::string playerSpawnName = EQ_GetPlayerSpawnName();
    if (playerSpawnName.size() != 0)
    {
        std::stringstream ss;
        ss << "EQ: " << playerSpawnName;

        HWND hwnd = EQ_GetWindow();
        if (hwnd != NULL)
        {
            ////std::cout << "Window HWND: " << std::hex << hwnd << std::dec << std::endl;

            SetWindowTextA(hwnd, ss.str().c_str());
        }
    }
}

bool EQAPP_HasTimeElapsed(std::chrono::time_point<std::chrono::steady_clock>& timer, long long timerInterval)
{
    auto timeNow = std::chrono::steady_clock::now();

    auto timeElapsed = std::chrono::duration_cast<std::chrono::seconds>(timeNow - timer).count();
    if (timeElapsed >= timerInterval)
    {
        timer = std::chrono::steady_clock::now();
        return true;
    }

    return false;
}
