#pragma once

bool g_AutoInventoryIsEnabled = false;

void EQAPP_AutoInventory_Toggle();
void EQAPP_AutoInventory_On();
void EQAPP_AutoInventory_Off();
void EQAPP_AutoInventory_Execute();

void EQAPP_AutoInventory_Toggle()
{
    EQ_ToggleBool(g_AutoInventoryIsEnabled);
    EQAPP_PrintBool("Auto Inventory", g_AutoInventoryIsEnabled);
}

void EQAPP_AutoInventory_On()
{
    if (g_AutoInventoryIsEnabled == false)
    {
        EQAPP_AutoInventory_Toggle();
    }
}

void EQAPP_AutoInventory_Off()
{
    if (g_AutoInventoryIsEnabled == true)
    {
        EQAPP_AutoInventory_Toggle();
    }
}

void EQAPP_AutoInventory_Execute()
{
    EQ_InterpretCommand("/autoinventory");
}

