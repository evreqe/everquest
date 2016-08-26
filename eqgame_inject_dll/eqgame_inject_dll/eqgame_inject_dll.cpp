#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>
#include <psapi.h>

#define APPLICATION_NAME "EverQuest Inject DLL"

#define EVERQUEST_CLIENT "eqgame.exe"
#define EVERQUEST_TITLE  "EverQuest"

int file_exists(char *filename)
{
    FILE *file = fopen(filename, "r");

    int result = (file == NULL ? 0 : 1);

    fclose(file);

    return result;
}

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

int main(int argc, char *argv[])
{
    printf("%s\n", APPLICATION_NAME);

    if (argc < 2)
    {
        printf("Usage: %s name_of_dll_to_inject.dll\n", argv[0]);
        return 0;
    }

    char *dll_name = argv[1];

    if (strlen(dll_name) == 0)
    {
        printf("Error: Injected filename must not be blank.\n");
        return 0;
    }

    if (strstr(dll_name, ".dll") == NULL)
    {
        printf("Error: Injected filename must contain the *.dll extension.\n");
        return 0;
    }

    if (file_exists(dll_name) == 0)
    {
        printf("Error: Injected filename '%s' file not found.\n", dll_name);
        return 0;
    }

    printf("DLL Name: %s\n", argv[1]);

    HWND everquest_window = FindWindowA(NULL, EVERQUEST_TITLE);
    if (everquest_window == NULL)
    {
        printf("Error: EverQuest window '%s' not found.\n", EVERQUEST_TITLE);
        return 0;
    }

    printf("Enabling debug privileges.\n");

    enable_debug_privileges();

    DWORD processes[1024];
    DWORD needed;
    if (!EnumProcesses(processes, sizeof(processes), &needed))
    {
        return 0;
    }

    DWORD num_processes = needed / sizeof(DWORD);

    unsigned int i;
    for (i = 0; i < num_processes; i++)
    {
        if (processes[i] != 0)
        {
            HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processes[i]);

            if (process_handle != NULL)
            {
                HMODULE module;
                DWORD needed_ex;
                if (EnumProcessModules(process_handle, &module, sizeof(module), &needed_ex))
                {
                    char process_name[MAX_PATH] = {0};

                    GetModuleBaseNameA(process_handle, module, process_name, sizeof(process_name));

                    if (strcmp(process_name, EVERQUEST_CLIENT) == 0)
                    {
                        printf("EverQuest client found. (Process ID: %d) %s\n", (int)processes[i], process_name);

                        char dll_path_name[MAX_PATH] = {0};
                        GetFullPathNameA(dll_name, MAX_PATH, dll_path_name, NULL);

                        LPVOID remote_memory = VirtualAllocEx(process_handle, NULL, strlen(dll_path_name), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

                        WriteProcessMemory(process_handle, remote_memory, dll_path_name, strlen(dll_path_name), NULL);

                        HANDLE remote_thread = CreateRemoteThread(process_handle, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA"), remote_memory, 0, NULL);

                        WaitForSingleObject(remote_thread, INFINITE);

                        VirtualFreeEx(process_handle, remote_memory, strlen(dll_path_name), MEM_RELEASE);

                        CloseHandle(remote_thread);
                    }
                }
            }

            CloseHandle(process_handle);
        }
    }

    printf("Done.\n");

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
