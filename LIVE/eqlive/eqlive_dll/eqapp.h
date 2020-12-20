#pragma once

#include "inc_master.h"

const char* g_EQAppName = "eqlive";
const char* g_EQAppNameEx = "EQLive";

volatile int g_EQAppIsLoaded = 0;
volatile int g_EQAppShouldUnload = 0;

int g_EQAppKillSwitchKey = VK_PAUSE;

int g_EQAppShowWindowsKey = VK_PRINT;

bool g_EQAppIsInGame = false;

bool g_EQAppDebugTextIsEnabled = false;

bool g_EQAppDoubleClickMouseFixIsEnabled = true;

uint32_t g_EQAppDoubleClickMouseFixDelay = 500;

uint32_t g_EQAppDoubleClickMouseFixLMouseUpTimePrevious = 0;

bool g_EQAppWindowProcLastMessageWasDoubleClick = false;

std::random_device g_EQAppRandomDevice;
std::mt19937 g_EQAppRandomEngine(g_EQAppRandomDevice());

std::unordered_map<std::string, HWND> g_EQAppClientWindowList;

HMODULE g_EQAppModule;

HANDLE g_EQAppHandleThreadLoad;
HANDLE g_EQAppHandleThreadLoop;
HANDLE g_EQAppHandleThreadConsole;

void EQAPP_Load();
void EQAPP_Unload();

void EQAPP_LoadFiles();

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param);
DWORD WINAPI EQAPP_ThreadLoop(LPVOID param);
DWORD WINAPI EQAPP_ThreadConsole(LPVOID param);

namespace EQApp
{
    enum class StringComparisonType : uint8_t
    {
        Equals,
        Ignore,
        Contains,
        BeginsWith,
        EndsWith
    };
}
