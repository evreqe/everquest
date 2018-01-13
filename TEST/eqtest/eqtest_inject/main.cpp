#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#define APPLICATION_NAME "EQTest Inject DLL"

#define EQ_STRING_DLL_NAME "eqtest.dll"

#define EQ_STRING_PROCESS_NAME "eqgame.exe"

DWORD EQ_CLIENT_VERSION_DATE_ADDRESS = 0xAE70B8;
#define EQ_CLIENT_VERSION_DATE_STRING "Jan  8 2018"
#define EQ_CLIENT_VERSION_DATE_BYTES "\x4A\x61\x6E\x20\x20\x38\x20\x32\x30\x31\x38\x00"
#define EQ_CLIENT_VERSION_DATE_SIZE 12

DWORD EQ_CLIENT_VERSION_TIME_ADDRESS = 0xAE70C4;
#define EQ_CLIENT_VERSION_TIME_STRING "16:56:08"
#define EQ_CLIENT_VERSION_TIME_BYTES "\x31\x36\x3A\x35\x36\x3A\x30\x38\x00"
#define EQ_CLIENT_VERSION_TIME_SIZE 9

void enable_debug_privileges()
{
    HANDLE token;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
    {
        TOKEN_PRIVILEGES tp;
        TOKEN_PRIVILEGES tp_previous;

        DWORD cb_previous = sizeof(TOKEN_PRIVILEGES);

        LUID luid;

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
        {
            tp.PrivilegeCount           = 1;
            tp.Privileges[0].Luid       = luid;
            tp.Privileges[0].Attributes = 0;

            AdjustTokenPrivileges
            (
                token,
                FALSE,
                &tp,
                sizeof(TOKEN_PRIVILEGES),
                &tp_previous,
                &cb_previous
            );

            tp_previous.PrivilegeCount            = 1;
            tp_previous.Privileges[0].Luid        = luid;
            tp_previous.Privileges[0].Attributes |= (SE_PRIVILEGE_ENABLED);
    
            AdjustTokenPrivileges
            (
                token,
                FALSE,
                &tp_previous,
                cb_previous,
                NULL,
                NULL
            );
        }
    }

    CloseHandle(token);
}

DWORD get_module_base_address(DWORD process_id, const wchar_t* module_name)
{
    DWORD base_address = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, process_id);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 module_entry = {0};
        module_entry.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(snapshot, &module_entry))
        {
            do
            {
                if (wcscmp(module_entry.szModule, module_name) == 0)
                {
                    base_address = (DWORD)module_entry.modBaseAddr;
                    break;
                }
            } while (Module32Next(snapshot, &module_entry));
        }

        CloseHandle(snapshot);
    }

    return base_address;
}

int is_client_version_correct(DWORD process_id, HANDLE process_handle)
{
    int result = 0;

    DWORD base_address = get_module_base_address(process_id, L"eqgame.exe");

    DWORD date_address = (EQ_CLIENT_VERSION_DATE_ADDRESS - 0x400000) + base_address;
    DWORD time_address = (EQ_CLIENT_VERSION_TIME_ADDRESS - 0x400000) + base_address;

    BYTE date_buffer[EQ_CLIENT_VERSION_DATE_SIZE];
    ReadProcessMemory(process_handle, (void*)date_address, &date_buffer, sizeof(date_buffer), 0);

    BYTE time_buffer[EQ_CLIENT_VERSION_TIME_SIZE];
    ReadProcessMemory(process_handle, (void*)time_address, &time_buffer, sizeof(time_buffer), 0);

    if (memcmp(date_buffer, EQ_CLIENT_VERSION_DATE_BYTES, sizeof(date_buffer)) == 0)
    {
        if (memcmp(time_buffer, EQ_CLIENT_VERSION_TIME_BYTES, sizeof(time_buffer)) == 0)
        {
            result = 1;
        }
    }

    if (result == 0)
    {
        char error_text[4096];
        sprintf(error_text, "Expected %s and %s for date and time!", EQ_CLIENT_VERSION_DATE_STRING, EQ_CLIENT_VERSION_TIME_STRING);

        MessageBoxA(NULL, error_text, "Inject DLL Error", MB_ICONERROR);
    }

    return result;
}

int main(int argc, char *argv[])
{
    printf("%s\n", APPLICATION_NAME);

    printf("Enabling debug privileges.\n");

    enable_debug_privileges();

    DWORD processes[4096];
    DWORD needed;
    if (EnumProcesses(processes, sizeof(processes), &needed) == 0)
    {
        printf("Error: EnumProcesses() failed.");
        return 0;
    }

    DWORD num_processes = needed / sizeof(DWORD);

    size_t i = 0;
    for (i = 0; i < num_processes; i++)
    {
        if (processes[i] != 0)
        {
            HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processes[i]);

            if (process_handle != NULL)
            {
                HMODULE module;
                DWORD needed2;

                if (EnumProcessModules(process_handle, &module, sizeof(module), &needed2))
                {
                    char module_name[1024] = {0};
                    GetModuleBaseNameA(process_handle, module, module_name, sizeof(module_name));

                    if (strcmp(module_name, EQ_STRING_PROCESS_NAME) == 0)
                    {
                        int is_dll_already_injected = 0;

                        HMODULE modules[1024];
                        DWORD needed3;

                        if (EnumProcessModules(process_handle, modules, sizeof(modules), &needed3))
                        {
                            DWORD num_modules = needed3 / sizeof(HMODULE);

                            size_t j = 0;
                            for (j = 0; j < num_modules; j++)
                            {
                                char module_name[1024] = {0};
                                GetModuleBaseNameA(process_handle, modules[j], module_name, sizeof(module_name));

                                //printf("Module Name: %s\n", module_name);

                                if (strcmp(module_name, EQ_STRING_DLL_NAME) == 0)
                                {
                                    printf("DLL is already injected in EverQuest. (Name: %s, ID: %d | 0x%08X)\nSkipping...\n", module_name, (int)processes[i], (int)processes[i]);

                                    is_dll_already_injected = 1;

                                    break;
                                }
                            }
                        }

                        if (is_dll_already_injected == 0)
                        {
                            if (is_client_version_correct(processes[i], process_handle) == 1)
                            {
                                printf("EverQuest process found. (Name: %s, ID: %d | 0x%08X)\nInjecting DLL...\n", module_name, (int)processes[i], (int)processes[i]);

                                char dll_path_name[MAX_PATH] = {0};
                                GetFullPathNameA(EQ_STRING_DLL_NAME, MAX_PATH, dll_path_name, NULL);

                                LPVOID remote_memory = VirtualAllocEx(process_handle, NULL, strlen(dll_path_name), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

                                WriteProcessMemory(process_handle, remote_memory, dll_path_name, strlen(dll_path_name), NULL);

                                HANDLE remote_thread = CreateRemoteThread(process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA"), remote_memory, 0, NULL);

                                if (remote_thread == NULL)
                                {
                                    VirtualFreeEx(process_handle, remote_memory, strlen(dll_path_name), MEM_RELEASE);
                                    CloseHandle(remote_thread);

                                    continue;
                                }

                                WaitForSingleObject(remote_thread, INFINITE);

                                DWORD exit_code;
                                GetExitCodeThread(remote_thread, &exit_code);

                                VirtualFreeEx(process_handle, remote_memory, strlen(dll_path_name), MEM_RELEASE);

                                CloseHandle(remote_thread);
                            }
                        }
                    }
                }
            }

            CloseHandle(process_handle);
        }
    }

    printf("Done.\n");

    ////MessageBoxA(NULL, "Done!", "Inject DLL", MB_ICONINFORMATION);

    return EXIT_SUCCESS;
}

/*
    DWORD process_id;
    GetWindowThreadProcessId(everquest_window, &process_id);

    HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);

    char dll_path_name[MAX_PATH] = {0};
    GetFullPathName(APPLICATION_DLL_NAME, MAX_PATH, dll_path_name, NULL);

    LPVOID remote_memory = VirtualAllocEx(process_handle, NULL, strlen(dll_path_name), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    WriteProcessMemory(process_handle, remote_memory, dll_path_name, strlen(dll_path_name), NULL);

    HANDLE remote_thread = CreateRemoteThread(process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("Kernel32"), "LoadLibraryA"), remote_memory, 0, NULL);

    WaitForSingleObject(remote_thread, INFINITE);

    VirtualFreeEx(process_handle, remote_memory, strlen(dll_path_name), MEM_RELEASE);

    CloseHandle(remote_thread);
    CloseHandle(process_handle);
*/
