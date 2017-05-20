#pragma once

bool g_speedHackIsEnabled = true;

float g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;

void EQAPP_SpeedHack_Execute();

void EQAPP_SpeedHack_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto zoneID = EQ_GetZoneID();

    if (EQ_POINTER_Zone.Type != EQ_ZONE_TYPE_INDOORS && zoneID != EQ_ZONE_ID_KURN)
    {
        if (playerSpawn->Actor->MovementSpeedModifier < g_speedHackModifier)
        {
            playerSpawn->Actor->MovementSpeedModifier = g_speedHackModifier;
        }
    }
}

