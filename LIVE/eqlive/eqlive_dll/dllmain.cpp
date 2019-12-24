//#define EQ_TEST_SERVER 1
#undef EQ_TEST_SERVER

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <set>
#include <string>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <vector>
#include <filesystem>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#define _WINSOCKAPI_ // prevent windows.h from including winsock.h, we use winsock2.h instead

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

// DirectX 9
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

// imgui
// https://github.com/ocornut/imgui
#include "imgui.h"
#include "imgui_internal.h"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

// Microsoft Detours
#include "detours.h"
#pragma comment(lib, "detours.lib")

// EverQuest
#include "eq.h"
#include "eq_functions.h"

// EQApp
#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_addresses.h"
#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autobank.h"
#include "eqapp_autoinventory.h"
#include "eqapp_autogroup.h"
#include "eqapp_bandolier.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_cheat.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_combatmacro.h"
#include "eqapp_macro.h"
#include "eqapp_killmobs.h"
#include "eqapp_lantern.h"
#include "eqapp_namecolor.h"
#include "eqapp_namedspawns.h"
#include "eqapp_powerlevel.h"
#include "eqapp_speed.h"
#include "eqapp_waypoint.h"
#include "eqapp_area.h"
#include "eqapp_console.h"
#include "eqapp_detours.h"
#include "eqapp_followai.h"
#include "eqapp_freecamera.h"
#include "eqapp_esp.h"
#include "eqapp_hud.h"
#include "eqapp_interpretcommand.h"
#include "eqapp_nodraw.h"
#include "eqapp_noalert.h"
#include "eqapp_sleep.h"
#include "eqapp_windowtitle.h"
#include "eqapp_windowforeground.h"

#include "eqapp_gui.h"

void EQAPP_Load()
{
    g_GUIIsLoaded = EQAPP_GUI_Load();

    EQAPP_LoadFiles();

    if (g_WindowTitleIsEnabled == true)
    {
        EQAPP_WindowTitle_Execute();
    }

    if (g_BoxChatIsEnabled == true && g_BoxChatAutoConnectIsEnabled == true)
    {
        if (EQAPP_BoxChat_IsServerRunning() == true)
        {
            std::string playerSpawnName = EQ_GetPlayerSpawnName();
            if (playerSpawnName.size() != 0)
            {
                EQAPP_BoxChat_Connect(playerSpawnName);
            }
        }
    }

/*
    auto render = EQ_GetRender();
    if (render != NULL)
    {
        std::cout << "CRender: 0x" << std::hex << render << std::dec << std::endl;

        auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
        if (devicePointer != NULL)
        {
            std::cout << "CRender Device Pointer: 0x" << std::hex << devicePointer << std::dec << std::endl;
        }
    }

    std::cout << "PlayerSpawn: 0x" << std::hex << EQ_GetPlayerSpawn() << std::dec << std::endl;

    std::cout << "PlayerPhysicsClient: 0x" << std::hex << EQ_GetPlayerSpawnPhysicsClient() << std::dec << std::endl;
*/

    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << "Loaded!    " << timeText;

    g_EQAppIsLoaded = 1;
}

void EQAPP_Unload()
{
    g_NoDrawIsEnabled = false;

    EQAPP_FreeCamera_Off();
    EQAPP_Speed_Off();

    g_WindowTitleIsEnabled = false;
    EQAPP_WindowTitle_Reset();

    EQAPP_FollowAI_StopFollow();

    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << "Unloaded!    " << timeText;

    g_EQAppShouldUnload = 1;
}

void EQAPP_LoadFiles()
{
    EQAPP_ActorCollision_Load();
    EQAPP_WaypointList_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_KillMobs_Load();
    EQAPP_ChatEvent_Load();
    EQAPP_Bandolier_Load();
    EQAPP_BazaarBot_Load();
    EQAPP_BazaarFilter_Load();
    EQAPP_CombatMacro_Load();
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_EQAppShouldUnload == 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // wait for the console to unload
    while (g_ConsoleIsLoaded == 1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    EQAPP_GUI_Unload();

    EQAPP_BoxChat_Unload();
    EQAPP_Detours_Unload();

    CloseHandle(g_EQAppHandleThreadLoad);
    CloseHandle(g_EQAppHandleThreadConsole);

    TerminateThread(EQAPP_ThreadLoad, 0);
    TerminateThread(EQAPP_ThreadConsole, 0);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    FreeLibraryAndExitThread(g_EQAppModule, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    EQAPP_InitializeAddresses();
    EQAPP_InitializeAddressPointers();

    g_EQAppHandleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_ConsoleIsLoaded == 0);

    g_EQAppHandleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Load();

    EQ_SetNetStatus(true);

    EQAPP_SetWindowTitle("EverQuest*");

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
