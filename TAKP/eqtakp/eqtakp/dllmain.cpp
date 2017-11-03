#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <array>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "ws2_32.lib")

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#include <d3d8.h>
#pragma comment(lib, "d3d8.lib")

#pragma comment(lib, "dxguid.lib")

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#define DINPUT_MOUSE_BUTTON_LEFT   0
#define DINPUT_MOUSE_BUTTON_RIGHT  1
#define DINPUT_MOUSE_BUTTON_MIDDLE 2
#define DINPUT_MOUSE_BUTTON_4      3
#define DINPUT_MOUSE_BUTTON_5      4
#define DINPUT_MOUSE_BUTTON_6      5
#define DINPUT_MOUSE_BUTTON_7      6
#define DINPUT_MOUSE_BUTTON_8      7

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "eq.h"
#include "eq_offsets.h"
#include "eq_functions.h"
#include "eq_graphicsdll.h"

#include "eqapp.h"
#include "eqapp_functions.h"
//
#include "eqapp_gui_classes.h"
#include "eqapp_gui_base.h"
#include "eqapp_gui_button.h"
#include "eqapp_gui_menu.h"
#include "eqapp_gui_menuitem.h"
#include "eqapp_gui.h"
//
#include "eqapp_console.h"
#include "eqapp_ini.h"
#include "eqapp_memory.h"
//
#include "eqapp_autoinventory.h"
#include "eqapp_autoloot.h"
#include "eqapp_namedspawns.h"
//
#include "eqapp_drm.h"
#include "eqapp_autofollow.h"
#include "eqapp_autogroup.h"
#include "eqapp_networkstats.h"
#include "eqapp_speedhack.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_bufftimers.h"
#include "eqapp_dotarget.h"
#include "eqapp_spellbookwindow.h"
#include "eqapp_containerwindow.h"
#include "eqapp_merchantwindow.h"
#include "eqapp_itemdisplaywindow.h"
#include "eqapp_bazaarsearchwindow.h"
#include "eqapp_hidecorpselooted.h"
#include "eqapp_namespritestate.h"
#include "eqapp_namespritetint.h"
#include "eqapp_changeheight.h"
#include "eqapp_autostand.h"
#include "eqapp_maxskills.h"
#include "eqapp_useskills.h"
#include "eqapp_foodanddrink.h"
#include "eqapp_spellset.h"
#include "eqapp_drawdistance.h"
#include "eqapp_neverfrozen.h"
#include "eqapp_trainspells.h"
#include "eqapp_spawnalert.h"
#include "eqapp_freecamera.h"
#include "eqapp_collisionhack.h"
#include "eqapp_toggleview.h"
#include "eqapp_startcasting.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_bardtwist.h"
#include "eqapp_replaceraces.h"
#include "eqapp_destroyactors.h"
#include "eqapp_enteringzone.h"
#include "eqapp_hotbuttonkeys.h"
#include "eqapp_wallhack.h"
#include "eqapp_waterhack.h"
#include "eqapp_treehack.h"
#include "eqapp_spelleffecttest.h"
#include "eqapp_targetring.h"
#include "eqapp_levelofdetail.h"
//
#include "eqapp_extendedtargets.h"
#include "eqapp_map.h"
#include "eqapp_esp.h"
//
#include "eqapp_extramousebuttons.h"
//
#include "eqapp_boxchat.h"
//
#include "eqapp_mainmenu.h"
#include "eqapp_skillsmenu.h"
#include "eqapp_espmenu.h"
#include "eqapp_mapmenu.h"
#include "eqapp_memorymenu.h"
#include "eqapp_othermenu.h"
#include "eqapp_hudtext.h"
//
//
#include "eqapp_interpretcmd.h"
//
#include "eqapp_detours.h"

void EQAPP_Load()
{
    EQ_WriteChatText("Loading...");

    EQ_GraphicsDLL_SetUseTNL(false);
    EQ_GraphicsDLL_SetUseUmbra(true);

    EQAPP_Mouse_Load();
    ////EQAPP_Keyboard_Load();

    EQAPP_Memory_Load();
    EQAPP_UseSkills_Load();

    EQAPP_MainMenu_Load();
    EQAPP_SkillsMenu_Load();
    EQAPP_ESPMenu_Load();
    EQAPP_MapMenu_Load();
    EQAPP_MemoryMenu_Load();
    EQAPP_OtherMenu_Load();

    if (EQ_IsInGame() == true)
    {
        g_zoneID = EQ_GetZoneID();

        EQAPP_Detours_OnZoneChanged_Load();
    }

    EQ_WriteChatText("Loaded!");

    g_bLoaded = 1;
}

void EQAPP_Unload()
{
    EQ_WriteChatText("Unloading...");

    EQ_GraphicsDLL_SetUseTNL(false);
    EQ_GraphicsDLL_SetUseUmbra(true);

    EQAPP_FreeCamera_SetEnabled(false);

    EQAPP_Memory_Unload();

    EQAPP_Mouse_Unload();
    ////EQAPP_Keyboard_Unload();

    EQAPP_BoxChat_Unload();

    if (EQ_IsInGame() == true)
    {
        EQ_FUNCTION_UpdateLight(EQ_POINTER_PlayerCharacter);
    }

    EQ_WriteChatText("Unloaded!");

    g_bExit = 1;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_bExit == 0)
    {
        Sleep(100);
    }

    // wait for the console to unload
    while (g_bConsole == 1)
    {
        Sleep(100);
    }

    EQAPP_Detours_Unload();

    TerminateThread(EQAPP_ThreadLoad, 0);
    TerminateThread(EQAPP_ThreadConsole, 0);

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

    EQAPP_Detours_Load();

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

    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(module);
        g_handleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
    }
    else if (reason == DLL_PROCESS_DETACH)
    {
        //
    }

    return TRUE;
}
