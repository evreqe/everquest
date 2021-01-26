#pragma once

bool g_AlwaysAttackIsEnabled = false;

EQApp::Timer g_AlwaysAttackTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AlwaysAttackTimerInterval = 1;

float g_AlwaysAttackMeleeDistance = 30.0f;

float g_AlwaysAttackRangeDistance = 400.0f;

void EQAPP_AlwaysAttack_Toggle();
void EQAPP_AlwaysAttack_On();
void EQAPP_AlwaysAttack_Off();
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

void EQAPP_AlwaysAttack_On()
{
    if (g_AlwaysAttackIsEnabled == false)
    {
        EQAPP_AlwaysAttack_Toggle();
    }
}

void EQAPP_AlwaysAttack_Off()
{
    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Toggle();
    }
}

void EQAPP_AlwaysAttack_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInSeconds(g_AlwaysAttackTimer, g_AlwaysAttackTimerInterval) == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        EQ_SetAutoAttack(false);
        EQ_SetAutoFire(false);
        return;
    }

    auto targetType = EQ_GetSpawnType(targetSpawn);
    if (targetType != EQ_SPAWN_TYPE_NPC)
    {
        EQ_SetAutoAttack(false);
        EQ_SetAutoFire(false);
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerStandingState != EQ_STANDING_STATE_STANDING)
    {
        EQ_SetAutoAttack(false);
        EQ_SetAutoFire(false);
        return;
    }

    float targetDistance = EQ_GetSpawnDistance(targetSpawn);

    auto playerClass = EQ_GetSpawnClass(playerSpawn);
    if (playerClass == EQ_CLASS_RANGER)
    {
        if (targetDistance > g_AlwaysAttackMeleeDistance && targetDistance < g_AlwaysAttackRangeDistance)
        {
            EQ_SetAutoAttack(false);
            EQ_SetAutoFire(true);
            return;
        }
    }

    if (targetDistance > g_AlwaysAttackMeleeDistance)
    {
        return;
    }

    EQ_SetAutoAttack(true);
}
