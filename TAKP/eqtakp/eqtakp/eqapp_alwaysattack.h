#pragma once

bool g_alwaysAttackIsEnabled = false;

void EQAPP_AlwaysAttack_Execute();

void EQAPP_AlwaysAttack_Execute()
{
    if (g_alwaysAttackIsEnabled == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL || targetSpawn == playerSpawn)
    {
        return;
    }

    if (playerSpawn->StandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    if (targetSpawn->Type != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    EQ_SetAutoAttack(true);
}

