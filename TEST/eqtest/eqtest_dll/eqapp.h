#pragma once

#include <cstdint>

#include <chrono>
#include <random>

#include "eqapp_string.h"
#include "eqapp_timer.h"
#include "eqapp_ini.h"

const char* g_EQAppName = "eqtest";
const char* g_EQAppNameEx = "EQTest";

volatile int g_EQAppIsLoaded = 0;
volatile int g_EQAppShouldUnload = 0;

const int g_EQAppKillSwitchKey = VK_F12;

bool g_EQAppIsInGame = false;

bool g_EQAppDebugTextIsEnabled = false;

std::mt19937 g_EQAppRandomEngine((uint32_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());

EQApp::Timer g_EQAppDebugTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_EQAppDebugTimerInterval = 1;

uint32_t g_ItemDefinitionIndex = 0;

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

template <class T>
void EQAPP_LoadOption(T& option, const char* optionName, boost::property_tree::ptree& pt);
void EQAPP_LoadOptions();

void EQAPP_FixAddress(uint32_t& address);
void EQAPP_InitializeAddressesAndPointers();
