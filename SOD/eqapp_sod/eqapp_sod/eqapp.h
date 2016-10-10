#pragma once

#include <windows.h>

const char* g_applicationName = "eqapp";

volatile int g_bLoaded = 0;
volatile int g_bExit   = 0;

volatile int g_bOnEnterZone = 0;

HMODULE g_module;

HANDLE g_handleThreadLoad;
HANDLE g_handleThreadLoop;
HANDLE g_handleThreadConsole;

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param);
DWORD WINAPI EQAPP_ThreadLoop(LPVOID param);
DWORD WINAPI EQAPP_ThreadConsole(LPVOID param);
BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved);

std::ios g_coutFlags(NULL);

std::mt19937 g_randomEngine((uint32_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());

int g_killSwitchKey = VK_PAUSE;

bool g_debugIsEnabled          = false;
bool g_neverFrozenIsEnabled    = true;

uint32_t g_videoModeWidth  = 1920;
uint32_t g_videoModeHeight = 1080;

GLFWwindow* g_consoleWindow;
ImVec4 g_consoleWindowClearColor = ImColor(0, 128, 96);
HWND g_consoleWindowHwnd;
const char* g_consoleWindowTitle = "EQC";
uint32_t g_consoleWindowWidth  = 1440;
uint32_t g_consoleWindowHeight = 900;

bool g_movementSpeedHackIsEnabled = true;
float g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;

bool g_setTargetIsEnabled = true;
bool g_setTargetMaxDistanceIsEnabled = false;
float g_setTargetMaxDistance = 25.0f;

int g_setRaceId = EQ_RACE_HUMAN;

// TODO
//bool g_waypointBotIsEnabled = false;
//std::string g_waypointBotSpawnName;
//uint32_t g_waypointBotSpawnInfo;

const std::vector<uint32_t> g_importantWindowsList
{
    EQ_POINTER_CAAWnd,
    EQ_POINTER_CBankWnd,
    EQ_POINTER_CBazaarWnd,
    EQ_POINTER_CBazaarSearchWnd,
    EQ_POINTER_CInspectWnd,
    EQ_POINTER_CInventoryWnd,
    EQ_POINTER_CLootWnd,
    EQ_POINTER_CMapViewWnd,
    EQ_POINTER_CMerchantWnd,
    EQ_POINTER_CSkillsWnd,
    EQ_POINTER_CSkillsSelectWnd,
    EQ_POINTER_CSocialEditWnd,
    EQ_POINTER_CSpellBookWnd,
    EQ_POINTER_CTextEntryWnd,
    EQ_POINTER_CTrackingWnd,
    EQ_POINTER_CTradeWnd,
    EQ_POINTER_CTrainWnd,
};

namespace EQApp
{

    typedef struct _Spawn
    {
        /* 0x00 */    uint32_t Unknown0x00;
    } Spawn, *Spawn_ptr;

    typedef struct _Item
    {
        /* 0x00 */    uint32_t Unknown0x00;
    } Item, *Item_ptr;

    typedef struct _ZoneActor
    {
        /* 0x00 */    uint32_t Unknown0x00;
    } ZoneActor, *ZoneActor_ptr;

}
