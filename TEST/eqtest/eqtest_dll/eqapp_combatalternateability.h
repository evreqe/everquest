#pragma once

#include "eqapp_boxchat.h"

bool g_CombatAlternateAbilityIsEnabled = true;

EQApp::Timer g_CombatAlternateAbilityTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_CombatAlternateAbilityTimerInterval = 3;

float g_CombatAlternateAbilityDistance = 25.0f;

uint32_t g_CombatAlternateAbilityList_reserve = 128;

void EQAPP_CombatAlternateAbility_Toggle();
void EQAPP_CombatAlternateAbility_On();
void EQAPP_CombatAlternateAbility_Off();
void EQAPP_CombatAlternateAbility_Execute();

void EQAPP_CombatAlternateAbility_Toggle()
{
    EQ_ToggleBool(g_CombatAlternateAbilityIsEnabled);
    EQAPP_PrintBool("Combat Alternate Ability", g_CombatAlternateAbilityIsEnabled);
}

void EQAPP_CombatAlternateAbility_On()
{
    if (g_CombatAlternateAbilityIsEnabled == false)
    {
        EQAPP_CombatAlternateAbility_Toggle();
    }
}

void EQAPP_CombatAlternateAbility_Off()
{
    if (g_CombatAlternateAbilityIsEnabled == true)
    {
        EQAPP_CombatAlternateAbility_Toggle();
    }
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

    if (EQ_IsAutoAttackEnabled() == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetSpawnType = EQ_GetSpawnType(targetSpawn);
    if (targetSpawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    float targetSpawnDistance = EQ_GetSpawnDistance(targetSpawn);
    if (targetSpawnDistance > g_CombatAlternateAbilityDistance)
    {
        return;
    }

    auto targetSpawnLastName = EQ_GetSpawnLastName(targetSpawn);
    if (targetSpawnLastName.size() != 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerSpawnStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    auto playerSpawnZoneID = EQ_GetSpawnZoneID(playerSpawn);
    if (EQ_IsZoneIDSafe(playerSpawnZoneID) == true)
    {
        return;
    }

    auto playerSpawnMovementSpeed = EQ_GetSpawnMovementSpeed(playerSpawn);
    if (playerSpawnMovementSpeed > 0.0f)
    {
        return;
    }

    auto targetSpawnHPPercent = EQ_GetSpawnHPPercent(targetSpawn);

    auto playerSpawnHPPercent = EQ_GetSpawnHPPercent(playerSpawn);
    auto playerSpawnEndurancePercent = EQ_GetSpawnEndurancePercent(playerSpawn);

    std::vector<uint32_t> alternateAbilityList;
    alternateAbilityList.reserve(g_CombatAlternateAbilityList_reserve);

    alternateAbilityList.push_back(EQAlternateAbilities::Special::Banestrike);

    auto playerSpawnClass = EQ_GetSpawnClass(playerSpawn);

    if (playerSpawnClass == EQ_CLASS_WARRIOR)
    {
        if (targetSpawnHPPercent > 10)
        {
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Blast_of_Anger);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Call_of_Challenge);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Gut_Punch);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Knee_Strike);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Ageless_Enmity);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Vehement_Rage);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Warlords_Fury);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Rage_of_Rallos_Zek);
        }
    }

    if (playerSpawnClass == EQ_CLASS_CLERIC)
    {
        if (targetSpawnHPPercent > 10 && targetSpawnHPPercent < 90)
        {
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Divine_Avatar);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Celestial_Hammer);
        }
    }

    if (playerSpawnClass == EQ_CLASS_ENCHANTER)
    {
        if (targetSpawnHPPercent > 25)
        {
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Dreary_Deeds);
        }
    }

    if (playerSpawnClass == EQ_CLASS_DRUID)
    {
        if (targetSpawnHPPercent > 25 && targetSpawnHPPercent < 75)
        {
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Natures_Guardian);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Spirits_of_Nature);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Storm_Strike);
        }
    }

    if (playerSpawnClass == EQ_CLASS_BARD)
    {
        if (targetSpawnHPPercent > 10 && targetSpawnHPPercent < 90)
        {
            if (playerSpawnEndurancePercent > 75)
            {
                alternateAbilityList.push_back(EQAlternateAbilities::Bard::Boastful_Bellow);
                alternateAbilityList.push_back(EQAlternateAbilities::Bard::Vainglorious_Shout);
            }

            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Bladed_Song);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Cacophony);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Dance_of_Blades);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Fierce_Eye);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Fundament_First_Spire_of_the_Minstrels);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Funeral_Dirge);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Quick_Time);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Song_of_Stone);
        }
    }

    if (playerSpawnClass == EQ_CLASS_BERSERKER)
    {
        if (targetSpawnHPPercent > 10 && targetSpawnHPPercent < 90)
        {
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Silent_Strikes);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Rampage);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Blinding_Fury);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Drawn_to_Blood);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Desperation);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Vehement_Rage);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Fundament_Third_Spire_of_Savagery);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Juggernaut_Surge);

            if (playerSpawnHPPercent > 90)
            {
                alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Blood_Pact);
                alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Savage_Spirit);
                alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Untamed_Rage);
            }
        }
    }

    for (auto& alternateAbility : alternateAbilityList)
    {
        EQ_UseAlternateAbility(alternateAbility);
    }
}
