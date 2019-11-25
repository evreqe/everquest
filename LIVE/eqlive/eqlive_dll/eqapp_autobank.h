#pragma once

bool g_AutoBankIsEnabled = false;

void EQAPP_AutoBank_Toggle();
void EQAPP_AutoBank_On();
void EQAPP_AutoBank_Off();
void EQAPP_AutoBank_Execute();

void EQAPP_AutoBank_Toggle()
{
    EQ_ToggleBool(g_AutoBankIsEnabled);
    EQAPP_PrintBool("Auto Bank", g_AutoBankIsEnabled);
}

void EQAPP_AutoBank_On()
{
    if (g_AutoBankIsEnabled == false)
    {
        EQAPP_AutoBank_Toggle();
    }
}

void EQAPP_AutoBank_Off()
{
    if (g_AutoBankIsEnabled == true)
    {
        EQAPP_AutoBank_Toggle();
    }
}

void EQAPP_AutoBank_Execute()
{
    EQ_InterpretCommand("/autobank");
}
