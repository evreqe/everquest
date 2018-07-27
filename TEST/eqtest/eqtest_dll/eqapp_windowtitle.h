#pragma once

bool g_WindowTitleIsEnabled = true;

EQApp::Timer g_WindowTitleTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_WindowTitleTimerInterval = 3;

void EQAPP_WindowTitle_Toggle();
void EQAPP_WindowTitle_On();
void EQAPP_WindowTitle_Off();
void EQAPP_WindowTitle_Reset();
void EQAPP_WindowTitle_Execute();

void EQAPP_WindowTitle_Toggle()
{
    EQ_ToggleBool(g_WindowTitleIsEnabled);
    EQAPP_PrintBool("Window Title", g_WindowTitleIsEnabled);

    if (g_WindowTitleIsEnabled == false)
    {
        EQAPP_WindowTitle_Reset();
    }
}

void EQAPP_WindowTitle_On()
{
    if (g_WindowTitleIsEnabled == false)
    {
        EQAPP_WindowTitle_Toggle();
    }
}

void EQAPP_WindowTitle_Off()
{
    if (g_WindowTitleIsEnabled == true)
    {
        EQAPP_WindowTitle_Toggle();
    }
}

void EQAPP_WindowTitle_Reset()
{
    EQAPP_SetWindowTitle(EQ_WINDOW_TITLE_DEFAULT);
}

void EQAPP_WindowTitle_Execute()
{
    HWND hwnd = EQ_GetWindow();
    if (hwnd == NULL)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(playerSpawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    std::stringstream ss;
    ss << "EQ: " << spawnName;

    auto spawnClass = EQ_GetSpawnClass(playerSpawn);

    std::string spawnClassShortName = EQ_GetClassShortNameByID(spawnClass);
    if (spawnClassShortName.size() != 0)
    {
        ss << " (" << spawnClassShortName << ")";
    }

    SetWindowTextA(hwnd, ss.str().c_str());
}
