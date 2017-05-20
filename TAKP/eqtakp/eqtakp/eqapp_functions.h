#pragma once

#include "eqapp.h"

template <class T>
void EQAPP_Log(const char* text, T number);

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName);
bool EQAPP_IsForegroundWindowCurrentProcessId();

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_PrintErrorMessage(const char* functionName, std::string text);
void EQAPP_PrintDebugMessage(const char* functionName, std::string text);

template <class T>
void EQAPP_Log(const char* text, T number)
{
    std::stringstream filePath;
    filePath << g_applicationName << "/log.txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
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

void EQAPP_PrintErrorMessage(const char* functionName, std::string text)
{
    std::cout << "[ERROR] " << functionName << ": " << text << std::endl;
}

void EQAPP_PrintDebugMessage(const char* functionName, std::string text)
{
    std::cout << "[DEBUG] " << functionName << ": " << text << std::endl;
}
