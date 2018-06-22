#pragma once

bool g_FPSIsEnabled = false;

EQApp::Timer g_FPSTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_FPSTimerInterval = 1;

uint32_t g_FPSValue = 0;
uint32_t g_FPSCounter = 0;

void EQAPP_FPS_Toggle();
void EQAPP_FPS_On();
void EQAPP_FPS_Off();
void EQAPP_FPS_Execute();

void EQAPP_FPS_Toggle()
{
    EQ_ToggleBool(g_FPSIsEnabled);
    EQAPP_PrintBool("FPS", g_FPSIsEnabled);

    if (g_FPSIsEnabled == false)
    {
        EQ_SetAutoAttack(false);
    }
}

void EQAPP_FPS_On()
{
    if (g_FPSIsEnabled == false)
    {
        EQAPP_FPS_Toggle();
    }
}

void EQAPP_FPS_Off()
{
    if (g_FPSIsEnabled == true)
    {
        EQAPP_FPS_Toggle();
    }
}

void EQAPP_FPS_Execute()
{
    g_FPSCounter++;

    if (EQAPP_Timer_HasTimeElapsed(g_FPSTimer, g_FPSTimerInterval) == true)
    {
        g_FPSValue = g_FPSCounter;
        g_FPSCounter = 0;
    }
}
