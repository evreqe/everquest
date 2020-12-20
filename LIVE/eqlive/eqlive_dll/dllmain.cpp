#define EQ_TEST_SERVER 1
//#undef EQ_TEST_SERVER

#include "inc_master.h"

void EQAPP_Load()
{
    EQAPP_LoadOptions();

    EQAPP_LoadFiles();

    g_GUIIsLoaded = EQAPP_GUI_Load();

    if (g_WindowTitleIsEnabled == true)
    {
        EQAPP_WindowTitle_Execute();
    }

    if (g_BoxChatIsEnabled == true && g_BoxChatAutoConnectIsEnabled == true)
    {
        if (EQAPP_BoxChat_IsServerRunning() == true)
        {
            std::string playerSpawnName = EQ_GetPlayerSpawnName();
            if (playerSpawnName.empty() == false)
            {
                EQAPP_BoxChat_Connect(playerSpawnName);
            }
        }
    }

    std::string timeText = EQAPP_GetTimeAsString();

    std::cout << "Loaded!    " << timeText << "\n";

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

    std::string timeText = EQAPP_GetTimeAsString();

    std::cout << "Unloaded!    " << timeText << "\n";

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

BOOL __stdcall DllMain(HMODULE hmodule, DWORD reason, LPVOID reserved)
{
    g_EQAppModule = hmodule;

    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hmodule);
        g_EQAppHandleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
    }
    else if (reason == DLL_PROCESS_DETACH)
    {
        //
    }

    return TRUE;
}
