#pragma once

bool g_speedHackIsEnabled = true;

float g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;

void EQAPP_SpeedHack_Toggle();
void EQAPP_SpeedHack_Execute();
void EQAPP_SpeedHack_SetSpeedRun1();
void EQAPP_SpeedHack_SetSpeedRun2();
void EQAPP_SpeedHack_SetSpeedRun3();
void EQAPP_SpeedHack_SetSpeedSpiritOfWolf();
void EQAPP_SpeedHack_SetSpeedFast();

void EQAPP_SpeedHack_Toggle()
{
    EQ_ToggleBool(g_speedHackIsEnabled);
    EQAPP_PrintBool("Speed Hack", g_speedHackIsEnabled);
}

void EQAPP_SpeedHack_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (EQ_POINTER_Zone.Type == EQ_ZONE_TYPE_INDOORS)
    {
        return;
    }

    if (EQ_IsZoneInList(EQ_ZONE_ID_LIST_INDOORS) == true)
    {
        return;
    }

    if (playerSpawn->Actor->MovementSpeedModifier < g_speedHackModifier)
    {
        playerSpawn->Actor->MovementSpeedModifier = g_speedHackModifier;
    }
}

void EQAPP_SpeedHack_SetSpeedRun1()
{
    g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_1;
}

void EQAPP_SpeedHack_SetSpeedRun2()
{
    g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_2;
}

void EQAPP_SpeedHack_SetSpeedRun3()
{
    g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_3;
}

void EQAPP_SpeedHack_SetSpeedSpiritOfWolf()
{
    g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;
}

void EQAPP_SpeedHack_SetSpeedFast()
{
    g_speedHackModifier = 1.0f;
}





