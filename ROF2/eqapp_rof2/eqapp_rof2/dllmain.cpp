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
#include <tlhelp32.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "eq.h"
#include "eq_utility.h"
#include "eq_classes.h"
#include "eq_functions.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_detours.h"
#include "eqapp_console.h"

/*
#include "eqapp_memory.h"
#include "eqapp_sounds.h"
#include "eqapp_waypoint.h"
#include "eqapp_zoneshortnames.h"
#include "eqapp_freecamera.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_hidecorpselooted.h"
#include "eqapp_maxswimmingskill.h"
#include "eqapp_changeheight.h"
#include "eqapp_swimspeed.h"
#include "eqapp_linetotarget.h"
#include "eqapp_namedspawns.h"
#include "eqapp_census.h"
#include "eqapp_nobeep.h"
#include "eqapp_spawnbeep.h"
#include "eqapp_targetbeep.h"
#include "eqapp_characterfile.h"
#include "eqapp_textoverlaychattext.h"
#include "eqapp_doors.h"
#include "eqapp_maplocations.h"
#include "eqapp_onscreentext.h"
#include "eqapp_autoloot.h"
#include "eqapp_maplabels.h"
#include "eqapp_playeralert.h"
#include "eqapp_drawdistance.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_spawnlist.h"
#include "eqapp_banklist.h"
#include "eqapp_inventorylist.h"
#include "eqapp_replaceraces.h"
#include "eqapp_autogroup.h"
#include "eqapp_zoneactors.h"
#include "eqapp_esp.h"                 // needs to be included last
#include "eqapp_esp_functions.h"       // needs to be included last
#include "eqapp_hud.h"                 // needs to be included last
#include "eqapp_interpretcommand.h"    // needs to be included last
*/

void EQAPP_Load()
{
    std::cout << "Loading..." << std::endl;

    //

    std::cout << "Loaded." << std::endl;

    g_bLoaded = 1;
}

void EQAPP_Unload()
{
    std::cout << "Unloading..." << std::endl;

    //

    std::cout << "Unloaded." << std::endl;

    g_bExit = 1;
}

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    if (g_bLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_killSwitchKey))
    {
        EQAPP_Unload();
    }

    //EQ_DrawLine(0, 0, 1, 800, 600, 1, 0xFFFF00FF);

    //EQ_CDisplay->WriteTextHD2("TESTING123", 200, 100, 7);

    int screenX = -1;
    int screenY = -1;
    bool result = EQ_WorldSpaceToScreenSpace(-47, 14, -28, screenX, screenY);
    if (result == true)
    {
        EQ_CDisplay->WriteTextHD2("TESTING123!@#", screenX, screenY, 7);
    }

    //if (EQ_IsInGame() == false)
    //{
        //return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    //}

    //if (EQ_IsScreenshotBeingTaken() == true)
    //{
        //return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    //}

    return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

//int __cdecl EQAPP_DETOUR_Exit()
//{
    //EQAPP_Unload();

    //return EQAPP_REAL_Exit();
//}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    EQAPP_Console_Load();

    while (g_bExit == 0)
    {
        Sleep(1);
    }

    EQAPP_Console_Unload();

    return 0;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_bExit == 0)
    {
        Sleep(100);
    }

    // wait for the console to unload
    while (g_bConsole == 1);

    Sleep(100);

    EQAPP_Detours_Remove();

    Sleep(1000);

    FreeLibraryAndExitThread(g_module, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    EQ_InitializeAddressesAndOffsets();

    EQ_GraphicsDll_LoadFunctions();

    g_handleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_bConsole == 0);

    g_handleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Add();

    return 0;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
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
