#pragma once

#include "eqapp_boxchat.h"

bool g_AutoAlternateAbilityIsEnabled = true;

EQApp::Timer g_AutoAlternateAbilityTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoAlternateAbilityTimerInterval = 3;

uint32_t g_AutoAlternateAbilityList_reserve = 128;

void EQAPP_AutoAlternateAbility_Toggle();
void EQAPP_AutoAlternateAbility_On();
void EQAPP_AutoAlternateAbility_Off();
void EQAPP_AutoAlternateAbility_Execute();

void EQAPP_AutoAlternateAbility_Toggle()
{
    EQ_ToggleBool(g_AutoAlternateAbilityIsEnabled);
    EQAPP_PrintBool("Auto Alternate Ability", g_AutoAlternateAbilityIsEnabled);
}

void EQAPP_AutoAlternateAbility_On()
{
    if (g_AutoAlternateAbilityIsEnabled == false)
    {
        EQAPP_AutoAlternateAbility_Toggle();
    }
}

void EQAPP_AutoAlternateAbility_Off()
{
    if (g_AutoAlternateAbilityIsEnabled == true)
    {
        EQAPP_AutoAlternateAbility_Toggle();
    }
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

    auto playerSpawnLevel = EQ_GetSpawnLevel(playerSpawn);
    if (playerSpawnLevel < 50)
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

    auto playerSpawnHPPercent = EQ_GetSpawnHPPercent(playerSpawn);
    if (playerSpawnHPPercent == 0)
    {
        return;
    }

    auto playerSpawnClass = EQ_GetSpawnClass(playerSpawn);

    auto targetSpawn = EQ_GetTargetSpawn();

    std::vector<uint32_t> alternateAbilityList;
    alternateAbilityList.reserve(g_AutoAlternateAbilityList_reserve);

    if (playerSpawnHPPercent < 10)
    {
        alternateAbilityList.push_back(EQAlternateAbilities::Special::Staunch_Recovery);
    }

    if (playerSpawnHPPercent < 25)
    {
        alternateAbilityList.push_back(EQAlternateAbilities::Special::Armor_of_Experience);
        alternateAbilityList.push_back(EQAlternateAbilities::Special::Infusion_of_the_Faithful);
        alternateAbilityList.push_back(EQAlternateAbilities::Special::Intensity_of_the_Resolute);
    }

    if (playerSpawnClass == EQ_CLASS_BARD)
    {
        if (playerSpawnHPPercent < 60)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Fading_Memories);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Hymn_of_the_Last_Stand);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Lyrical_Prankster);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Shield_of_Notes);
            alternateAbilityList.push_back(EQAlternateAbilities::Bard::Tune_Stuck_In_Your_Head);
        }
    }

    if (playerSpawnClass == EQ_CLASS_BERSERKER)
    {
        if (playerSpawnHPPercent < 60)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Hold_the_Line);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Self_Preservation);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Silent_Strikes);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Blood_Sustenance);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Juggernauts_Resolve);
            alternateAbilityList.push_back(EQAlternateAbilities::Berserker::Uncanny_Resilience);
        }
    }

    if (playerSpawnClass == EQ_CLASS_CLERIC)
    {
        if (playerSpawnHPPercent < 75)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Silent_Casting);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Burst_of_Life);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Celestial_Regeneration);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Divine_Retribution);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Exquisite_Benediction);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Fundament_Third_Spire_of_Divinity);
            alternateAbilityList.push_back(EQAlternateAbilities::Cleric::Sanctuary);
        }
    }

    if (playerSpawnClass == EQ_CLASS_DRUID)
    {
        if (playerSpawnHPPercent < 75)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Silent_Casting);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Forceful_Rejuvenation);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Fundament_Third_Spire_of_Nature);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Natures_Boon);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Peaceful_Spirit_of_the_Wood);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Protection_of_Direwood);
            alternateAbilityList.push_back(EQAlternateAbilities::Druid::Wall_of_Wind);
        }
    }

    if (playerSpawnClass == EQ_CLASS_ENCHANTER)
    {
        if (playerSpawnHPPercent < 75)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Silent_Casting);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Arcane_Whisper);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Focus_of_Arcanum);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Forceful_Rejuvenation);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Self_Stasis);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Beguilers_Directed_Banishment);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Doppleganger);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Eldritch_Rune);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Fog_of_Memories);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Fundament_First_Spire_of_Enchantment);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Mind_Over_Matter);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Phantasmal_Opponent);
            alternateAbilityList.push_back(EQAlternateAbilities::Enchanter::Veil_of_Mindshadow);
        }
    }

    if (playerSpawnClass == EQ_CLASS_WARRIOR)
    {
        if (playerSpawnHPPercent < 50)
        {
            // Archetype
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Hold_the_Line);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Projection_of_Fury);

            // Class
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Blade_Guardian);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Brace_for_Impact);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Fundament_Third_Spire_of_the_Warlord);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Imperators_Command);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Mark_of_the_Mage_Hunter);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Resplendent_Glory);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Warlords_Bravery);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Warlords_Resurgence);
            alternateAbilityList.push_back(EQAlternateAbilities::Warrior::Warlords_Tenacity);
        }
    }

    for (auto& alternateAbility : alternateAbilityList)
    {
        EQ_UseAlternateAbility(alternateAbility);
    }
}

