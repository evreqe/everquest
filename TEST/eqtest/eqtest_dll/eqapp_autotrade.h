#pragma once

bool g_AutoTradeIsEnabled = false;

EQApp::Timer g_AutoTradeTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoTradeTimerInterval = 1;

void EQAPP_AutoTrade_Toggle();
void EQAPP_AutoTrade_On();
void EQAPP_AutoTrade_Off();
void EQAPP_AutoTrade_Execute();

void EQAPP_AutoTrade_Toggle()
{
    EQ_ToggleBool(g_AutoTradeIsEnabled);
    EQAPP_PrintBool("Auto Trade", g_AutoTradeIsEnabled);
}

void EQAPP_AutoTrade_On()
{
    if (g_AutoTradeIsEnabled == false)
    {
        EQAPP_AutoTrade_Toggle();
    }
}

void EQAPP_AutoTrade_Off()
{
    if (g_AutoTradeIsEnabled == true)
    {
        EQAPP_AutoTrade_Toggle();
    }
}

void EQAPP_AutoTrade_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_AutoTradeTimer, g_AutoTradeTimerInterval) == false)
    {
        return;
    }

    //
}