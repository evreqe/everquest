#pragma once

#include <cstdint>

#include <chrono>
#include <random>
#include <unordered_map>
#include <vector>

#include "eqapp_string.h"
#include "eqapp_timer.h"
#include "eqapp_ini.h"

const char* g_EQAppName = "eqtest";
const char* g_EQAppNameEx = "EQTest";

volatile int g_EQAppIsLoaded = 0;
volatile int g_EQAppShouldUnload = 0;

int g_EQAppKillSwitchKey = VK_F12;

bool g_EQAppIsInGame = false;

std::random_device g_EQAppRandomDevice;
std::mt19937 g_EQAppRandomEngine(g_EQAppRandomDevice());

bool g_EQAppDebugTextIsEnabled = false;

std::map<std::string, HWND> g_EQAppClientWindowList;

HMODULE g_EQAppModule;

HANDLE g_EQAppHandleThreadLoad;
HANDLE g_EQAppHandleThreadLoop;
HANDLE g_EQAppHandleThreadConsole;

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param);
DWORD WINAPI EQAPP_ThreadLoop(LPVOID param);
DWORD WINAPI EQAPP_ThreadConsole(LPVOID param);

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved);

void EQAPP_Load();
void EQAPP_Unload();

namespace EQApp
{
    enum class StringComparsionType : uint8_t
    {
        Equals,
        Ignore,
        Contains,
        BeginsWith,
        EndsWith
    };
}
