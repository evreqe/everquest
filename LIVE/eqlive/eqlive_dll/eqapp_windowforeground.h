#pragma once

bool g_WindowForegroundIsEnabled = false;

void EQAPP_WindowForeground_Toggle();
void EQAPP_WindowForeground_On();
void EQAPP_WindowForeground_Off();
void EQAPP_WindowForeground_Execute();

void EQAPP_WindowForeground_Toggle()
{
    EQ_ToggleBool(g_WindowForegroundIsEnabled);
    EQAPP_PrintBool("Window Foreground", g_WindowForegroundIsEnabled);
}

void EQAPP_WindowForeground_On()
{
    if (g_WindowForegroundIsEnabled == false)
    {
        EQAPP_WindowForeground_Toggle();
    }
}

void EQAPP_WindowForeground_Off()
{
    if (g_WindowForegroundIsEnabled == true)
    {
        EQAPP_WindowForeground_Toggle();
    }
}

void EQAPP_WindowForeground_Execute()
{
    HWND window = EQ_GetWindow();
    if (window == NULL)
    {
        return;
    }

    ShowWindow(window, SW_MAXIMIZE);

    SetForegroundWindow(window);
    SetCapture(window);
}
