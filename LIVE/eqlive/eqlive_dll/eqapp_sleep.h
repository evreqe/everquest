#pragma once

bool g_SleepIsEnabled = false;

uint32_t g_SleepIntervalForeground = 100;   // delay in milliseconds
uint32_t g_SleepIntervalBackground = 100;   // delay in milliseconds

void EQAPP_Sleep_Toggle();
void EQAPP_Sleep_On();
void EQAPP_Sleep_Off();
void EQAPP_Sleep_Execute();

void EQAPP_Sleep_Toggle()
{
    EQ_ToggleBool(g_SleepIsEnabled);
    EQAPP_PrintBool("Sleep", g_SleepIsEnabled);
}

void EQAPP_Sleep_On()
{
    if (g_SleepIsEnabled == false)
    {
        EQAPP_Sleep_Toggle();
    }
}

void EQAPP_Sleep_Off()
{
    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Toggle();
    }
}

void EQAPP_Sleep_Execute()
{
    if (EQAPP_IsForegroundWindowCurrentProcessID() == true)
    {
        Sleep(g_SleepIntervalForeground);
    }
    else
    {
        Sleep(g_SleepIntervalBackground);
    }
}


