#pragma once

const char* g_applicationName = "eqtakp";

volatile int g_bLoaded = 0;
volatile int g_bExit = 0;

int g_killSwitchKey = VK_PAUSE;

int g_zoneID = 0;

std::mt19937 g_randomEngine((uint32_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());

HMODULE g_module;

HANDLE g_handleThreadLoad;
HANDLE g_handleThreadLoop;
HANDLE g_handleThreadConsole;

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param);
DWORD WINAPI EQAPP_ThreadLoop(LPVOID param);
DWORD WINAPI EQAPP_ThreadConsole(LPVOID param);
BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved);

void EQAPP_Load();
void EQAPP_Unload();



