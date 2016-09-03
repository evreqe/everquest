#pragma once

bool g_alwaysAttackIsEnabled = false;

void EQAPP_AlwaysAttack_Execute();

void EQAPP_AlwaysAttack_Execute()
{
    if (g_alwaysAttackIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    DWORD targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL || targetSpawn == playerSpawn)
    {
        return;
    }

    int standingState = EQ_ReadMemory<BYTE>(playerSpawn + EQ_OFFSET_SPAWN_INFO_STANDING_STATE);
    if (standingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    int spawnType = EQ_ReadMemory<BYTE>(targetSpawn + EQ_OFFSET_SPAWN_INFO_TYPE);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    EQ_SetAutoAttack(true);
}

