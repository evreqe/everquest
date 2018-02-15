#pragma once

#include "eqapp_boxchat.h"

bool g_CombatAlternateAbilityIsEnabled = false;

EQApp::Timer g_CombatAlternateAbilityTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_CombatAlternateAbilityTimerInterval = 6;

void EQAPP_CombatAlternateAbility_Toggle();
void EQAPP_CombatAlternateAbility_Execute();

void EQAPP_CombatAlternateAbility_Toggle()
{
    EQ_ToggleBool(g_CombatAlternateAbilityIsEnabled);
    EQAPP_PrintBool("Combat Alternate Ability", g_CombatAlternateAbilityIsEnabled);
}

void EQAPP_CombatAlternateAbility_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_CombatAlternateAbilityTimer, g_CombatAlternateAbilityTimerInterval) == false)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.size() != 0)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    int targetSpawnType = EQ_ReadMemory<uint8_t>(targetSpawn + EQ_OFFSET_SPAWN_TYPE);
    if (targetSpawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    int autoAttack = EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AUTO_ATTACK);
    if (autoAttack == 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::vector<uint32_t> alternateAbilityList;

    int spawnClass = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_CLASS);

    if (spawnClass == EQ_CLASS_WARRIOR)
    {
        alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_BLAST_OF_ANGER);
        alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_CALL_OF_CHALLENGE);
        alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_KNEE_STRIKE);
        alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_GUT_PUNCH);
        alternateAbilityList.push_back(EQ_ALTERNATE_ABILITY_VEHEMENT_RAGE);
    }

    for (auto& alternateAbility : alternateAbilityList)
    {
        std::stringstream ss;
        ss << "/alt activate " << alternateAbility;

        EQ_InterpretCommand(ss.str().c_str());
    }
}
