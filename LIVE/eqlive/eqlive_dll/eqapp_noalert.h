#pragma once

bool g_NoAlertIsEnabled = true;

EQApp::Timer g_NoAlertTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NoAlertTimerInterval = 1;

void EQAPP_NoAlert_Toggle();
void EQAPP_NoAlert_On();
void EQAPP_NoAlert_Off();
void EQAPP_NoAlert_Execute();

void EQAPP_NoAlert_Toggle()
{
    EQ_ToggleBool(g_NoAlertIsEnabled);
    EQAPP_PrintBool("No Alert", g_NoAlertIsEnabled);
}

void EQAPP_NoAlert_On()
{
    if (g_NoAlertIsEnabled == false)
    {
        EQAPP_NoAlert_Toggle();
    }
}

void EQAPP_NoAlert_Off()
{
    if (g_NoAlertIsEnabled == true)
    {
        EQAPP_NoAlert_Toggle();
    }
}

void EQAPP_NoAlert_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_NoAlertTimer, g_NoAlertTimerInterval) == false)
    {
        return;
    }

    // close popup ad window for free to play characters
    if (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CAlertWnd) == true)
    {
        EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CAlertWnd, EQ_OFFSET_CAlertWnd_BUTTON_CLOSE);
    }

    // close popup ad window for free to play characters
    if (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CAlertStackWnd) == true)
    {
        EQ_CLASS_POINTER_CAlertStackWnd->Deactivate();
    }
}
