#pragma once

bool g_WindowTitleIsEnabled = true;

EQApp::Timer g_WindowTitleTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_WindowTitleTimerInterval = 3;

void EQAPP_WindowTitle_Toggle();
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

void EQAPP_WindowTitle_Reset()
{
    HWND hwnd = EQ_GetWindow();
    if (hwnd == NULL)
    {
        return;
    }

    SetWindowTextA(hwnd, EQ_WINDOW_TITLE_DEFAULT);
}

void EQAPP_WindowTitle_Execute()
{
    HWND hwnd = EQ_GetWindow();
    if (hwnd == NULL)
    {
        return;
    }

    std::string playerSpawnName = EQ_GetPlayerSpawnName();
    if (playerSpawnName.size() == 0)
    {
        return;
    }

    std::stringstream ss;
    ss << "EQ: " << playerSpawnName;

    SetWindowTextA(hwnd, ss.str().c_str());
}
