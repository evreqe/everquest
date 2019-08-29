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
    HWND window = EQ_GetWindow();
    if (window == NULL)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.size() == 0)
    {
        return;
    }

    std::stringstream ss;
    ss << "EQ: " << playerName;

    SetWindowTextA(window, ss.str().c_str());

    // keep window maximized to prevent UI windows from moving around
    HWND foregroundWindow = GetForegroundWindow();
    if (window == foregroundWindow)
    {
        ShowWindow(window, SW_MAXIMIZE);
    }

    // close popup ad window for free to play characters
    if (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CAlertWnd) == true)
    {
        EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CAlertWnd, EQ_OFFSET_CAlertWnd_BUTTON_CLOSE);
    }
}
