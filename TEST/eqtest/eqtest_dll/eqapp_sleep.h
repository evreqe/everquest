#pragma once

bool g_SleepIsEnabled = false;

void EQAPP_Sleep_Toggle();
void EQAPP_Sleep_Execute();

void EQAPP_Sleep_Toggle()
{
    EQ_ToggleBool(g_SleepIsEnabled);
    EQAPP_PrintBool("Sleep", g_SleepIsEnabled);
}

void EQAPP_Sleep_Execute()
{
    Sleep(100);
}
