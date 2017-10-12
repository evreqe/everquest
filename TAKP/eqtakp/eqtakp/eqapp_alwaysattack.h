#pragma once

bool g_alwaysAttackIsEnabled = false;

void EQAPP_AlwaysAttack_Toggle();
void EQAPP_AlwaysAttack_Execute();

void EQAPP_AlwaysAttack_Toggle()
{
    EQ_ToggleBool(g_alwaysAttackIsEnabled);
    EQAPP_PrintBool("Always Attack", g_alwaysAttackIsEnabled);
}

void EQAPP_AlwaysAttack_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto bankerSpawn = EQ_GetBankerSpawn();
    if (bankerSpawn != NULL)
    {
        EQ_SetAutoAttack(false);
        return;
    }

    auto merchantSpawn = EQ_GetMerchantSpawn();
    if (merchantSpawn != NULL)
    {
        EQ_SetAutoAttack(false);
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


