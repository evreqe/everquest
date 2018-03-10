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

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "eq.h"
#include "eq_functions.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_spelllist.h"

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_autoalternateability.h"
#include "eqapp_combatalternateability.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_changeheight.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_followai.h"
#include "eqapp_esp.h"
#include "eqapp_sleep.h"
#include "eqapp_boxchat.h"

#include "eqapp_hud.h"
#include "eqapp_console.h"
#include "eqapp_interpretcmd.h"
#include "eqapp_detours.h"

void EQAPP_Load()
{
    EQAPP_BazaarFilter_Load();
    EQAPP_SpellList_Load();

    EQAPP_SetWindowTitleToPlayerSpawnName();

    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << g_EQAppNameEx << " Loaded!    " << timeText;

    g_EQAppIsLoaded = 1;
}

void EQAPP_Unload()
{
    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << g_EQAppNameEx << " Unloaded!    " << timeText;

    g_EQAppShouldUnload = 1;
}

void EQAPP_FixAddress(uint32_t& address)
{
    uint32_t baseAddress = (uint32_t)GetModuleHandle(NULL);

    address = (address - EQ_BASE_ADDRESS_VALUE) + baseAddress;
}

void EQAPP_InitializeAddressesAndPointers()
{
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_ATTACK);
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_FIRE);
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_RUN);
    EQAPP_FixAddress(EQ_ADDRESS_MOUSE_LOOK);
    EQAPP_FixAddress(EQ_ADDRESS_NET_STATUS);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_WINDOW_HWND);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CrashDetected);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TARGET_SPAWN);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CONTROLLED_SPAWN);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_LOCAL_SPAWN);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PLAYER_SPAWN);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);

    ////EQAPP_FixAddress(EQ_ADDRESS_POINTER_PLAYER_CHARACTER);
    ////EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__WndNotification);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    EQ_CLASS_POINTER_EQPlayerManager_pptr = (EQClass::EQPlayerManager**)EQ_ADDRESS_POINTER_EQPlayerManager;
    EQ_CLASS_POINTER_EQPlayerManager = (*EQ_CLASS_POINTER_EQPlayerManager_pptr);

    EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
    EQ_CLASS_POINTER_CXWndManager = (*EQ_CLASS_POINTER_CXWndManager_pptr);

    EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
    EQ_CLASS_POINTER_CEverQuest = (*EQ_CLASS_POINTER_CEverQuest_pptr);

    EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
    EQ_CLASS_POINTER_CDisplay = (*EQ_CLASS_POINTER_CDisplay_pptr);

    EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
    EQ_CLASS_POINTER_CBazaarSearchWnd = (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr);
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_EQAppShouldUnload == 0)
    {
        if (g_BoxChatIsEnabled == true)
        {
            if (g_BoxChatIsConnected == true)
            {
                EQAPP_BoxChat_Execute();
            }
            else
            {
                if (g_BoxChatAutoConnect == true)
                {
                    if (g_EQAppPlayerName.size() != 0)
                    {
                        EQAPP_BoxChat_Connect(g_EQAppPlayerName);
                    }
                }
            }
        }

        Sleep(100);
    }

    // wait for the console to unload
    while (g_ConsoleIsLoaded == 1)
    {
        Sleep(100);
    }

    EQAPP_BoxChat_Unload();

    EQAPP_Detours_Unload();

    TerminateThread(EQAPP_ThreadLoad, 0);
    TerminateThread(EQAPP_ThreadConsole, 0);

    FreeLibraryAndExitThread(g_EQAppModule, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    EQAPP_InitializeAddressesAndPointers();

    g_EQAppHandleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_ConsoleIsLoaded == 0);

    g_EQAppHandleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Load();

    EQ_SetNetStatus(true);

    return 0;
}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    EQAPP_Console_Load();

    while (g_EQAppShouldUnload == 0)
    {
        Sleep(100);
    }

    EQAPP_Console_Unload();

    return 0;
}

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    g_EQAppModule = module;

    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(module);
        g_EQAppHandleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
    }
    else if (reason == DLL_PROCESS_DETACH)
    {
        //
    }

    return TRUE;
}
