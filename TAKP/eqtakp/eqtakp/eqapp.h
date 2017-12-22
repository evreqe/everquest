#pragma once

const char* g_EQAppName = "eqtakp";

volatile int g_EQAppIsLoaded = 0;
volatile int g_EQAppShouldUnload = 0;

const int g_EQAppKillSwitchKey = VK_PAUSE;

bool g_EQAppDebugMessageIsEnabled = false;
bool g_EQAppErrorMessageIsEnabled = false;

bool g_EQAppIsMemorizingSpell = false;

bool g_EQAppIsLeftMouseButtonHeldDown = false;

EQ_ZoneID_t g_EQAppZoneID = 0xDEADBEEF;

uint8_t g_EQAppPlayerClass = EQ_CLASS_UNKNOWN;

std::mt19937 g_EQAppRandomEngine((uint32_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());

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
