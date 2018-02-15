#pragma once

bool g_AlwaysAttackIsEnabled = false;

EQApp::Timer g_AlwaysAttackTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AlwaysAttackTimerInterval = 1;

void EQAPP_AlwaysAttack_Toggle();
void EQAPP_AlwaysAttack_Execute();

void EQAPP_AlwaysAttack_Toggle()
{
    EQ_ToggleBool(g_AlwaysAttackIsEnabled);
    EQAPP_PrintBool("Always Attack", g_AlwaysAttackIsEnabled);

    if (g_AlwaysAttackIsEnabled == false)
    {
        EQ_SetAutoAttack(false);
    }
}

void EQAPP_AlwaysAttack_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_AlwaysAttackTimer, g_AlwaysAttackTimerInterval) == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        EQ_SetAutoAttack(false);
        return;
    }

    auto spawnType = EQ_GetSpawnType(targetSpawn);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        EQ_SetAutoAttack(false);
        return;
    }

    EQ_SetAutoAttack(true);
}
