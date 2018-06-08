#pragma once

bool g_NamedSpawnsIsEnabled = true;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_On();
void EQAPP_NamedSpawns_Off();

void EQAPP_NamedSpawns_Toggle()
{
    EQ_ToggleBool(g_NamedSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns", g_NamedSpawnsIsEnabled);
}

void EQAPP_NamedSpawns_On()
{
    if (g_NamedSpawnsIsEnabled == false)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_Off()
{
    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

// TODO: Load and Execute