#pragma once

bool g_speedHackIsEnabled = true;

float g_speedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;

void EQAPP_SpeedHack_Execute();

void EQAPP_SpeedHack_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == nullptr)
    {
        return;
    }

    if (playerSpawn->Actor->MovementSpeedModifier < g_speedHackModifier)
    {
        playerSpawn->Actor->MovementSpeedModifier = g_speedHackModifier;
    }
}

