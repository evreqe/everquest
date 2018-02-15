#pragma once

#include "eqapp_boxchat.h"

bool g_AutoAlternateAbilityIsEnabled = false;

EQApp::Timer g_AutoAlternateAbilityTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoAlternateAbilityTimerInterval = 3;

void EQAPP_AutoAlternateAbility_Toggle();
void EQAPP_AutoAlternateAbility_Execute();

void EQAPP_AutoAlternateAbility_Toggle()
{
    EQ_ToggleBool(g_AutoAlternateAbilityIsEnabled);
    EQAPP_PrintBool("Auto Alternate Ability", g_AutoAlternateAbilityIsEnabled);
}

void EQAPP_AutoAlternateAbility_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_AutoAlternateAbilityTimer, g_AutoAlternateAbilityTimerInterval) == false)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.size() != 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (spawnStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    auto spawnHPPercent = EQ_GetSpawnHPPercent(playerSpawn);
    if (spawnHPPercent == 0)
    {
        return;
    }

    std::vector<uint32_t> alternateAbilityList;

    auto spawnClass = EQ_GetSpawnClass(playerSpawn);

    if (spawnClass == EQ_CLASS_WARRIOR)
    {
        if (spawnHPPercent < 75)
        {
            alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_WARLORDS_TENACITY);
            alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_RESPLENDANT_GLORY);
            alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_HOLD_THE_LINE);
        }
    }

    for (auto& alternateAbility : alternateAbilityList)
    {
        std::stringstream ss;
        ss << "/alt activate " << alternateAbility;

        EQ_InterpretCommand(ss.str().c_str());
    }
}

