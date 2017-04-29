#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <random>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "eq.h"
#include "eq_offsets.h"
#include "eq_functions.h"
#include "eq_graphicsdll.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_console.h"
#include "eqapp_ini.h"
#include "eqapp_memory.h"

#include "eqapp_speedhack.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_bufftimers.h"

#include "eqapp_detours.h"

void EQAPP_Load()
{
    EQ_WriteChatText("Loading...");

    EQAPP_Memory_Load();

    g_bLoaded = 1;

    EQ_WriteChatText("Loaded!");
}

void EQAPP_Unload()
{
    EQ_WriteChatText("Unloading...");

    EQAPP_Memory_Unload();

    g_bExit = 1;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_bExit == 0)
    {
        Sleep(1000);
    }

    // wait for the console to unload
    while (g_bConsole == 1)
    {
        Sleep(1000);
    }

    Sleep(1000);

    EQAPP_Detours_Remove();

    Sleep(1000);

    FreeLibraryAndExitThread(g_module, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    if (EQ_GraphicsDLL_LoadFunctions() == false)
    {
        MessageBoxA(NULL, "Error: Failed to load graphics DLL functions!", g_applicationName, MB_ICONERROR);

        FreeLibraryAndExitThread(g_module, 0);
        return 0;
    }

    g_handleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_bConsole == 0);

    g_handleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Add();

    ExitThread(0);

    return 0;
}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    EQAPP_Console_Load();

    while (g_bExit == 0)
    {
        Sleep(100);
    }

    EQAPP_Console_Unload();

    ExitThread(0);

    return 0;
}

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    g_module = module;

    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(module);
            g_handleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
            break;

        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}
