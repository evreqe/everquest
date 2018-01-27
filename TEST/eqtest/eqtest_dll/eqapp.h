#pragma once

#include <cstdint>

#include <chrono>
#include <random>

const char* g_EQAppName = "eqtest";
const char* g_EQAppNameEx = "EQTest";

volatile int g_EQAppIsLoaded = 0;
volatile int g_EQAppShouldUnload = 0;

const int g_EQAppKillSwitchKey = VK_F12;

bool g_EQAppDebugMessageIsEnabled = false;

std::string g_EQAppPlayerName;

std::mt19937 g_EQAppRandomEngine((uint32_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());

std::chrono::time_point<std::chrono::steady_clock> g_EQAppWindowTitleTimer = std::chrono::steady_clock::now();
long long g_EQAppWindowTitleTimerInterval = 3;

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

void EQAPP_FixAddress(DWORD& address);
void EQAPP_InitializeAddressesAndPointers();
