#pragma once

bool g_useSkillsIsEnabled = true;

// TODO: use list of bool with skill ID as index
bool g_useSkillsSenseHeadingIsEnabled = false;
bool g_useSkillsForageIsEnabled = true;
bool g_useSkillsTauntIsEnabled = true;
bool g_useSkillsKickIsEnabled = true;
bool g_useSkillsBashIsEnabled = false;
bool g_useSkillsSlamIsEnabled = false;
bool g_useSkillsDisarmIsEnabled = true;
bool g_useSkillsBackstabIsEnabled = false;

uint32_t g_useSkillsTimer = 0;
uint32_t g_useSkillsTimerDelay = 1000;

void EQAPP_UseSkills_Toggle();
void EQAPP_UseSkills_Execute();

void EQAPP_UseSkills_Toggle()
{
    EQ_ToggleBool(g_useSkillsIsEnabled);
    EQAPP_PrintBool("Use Skills", g_useSkillsIsEnabled);
}

void EQAPP_UseSkills_Execute()
{
    if (EQ_HasTimePassed(g_useSkillsTimer, g_useSkillsTimerDelay) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (playerSpawn->IsAwayFromKeyboard == 1)
    {
        if (g_useSkillsSenseHeadingIsEnabled == true)
        {
            EQ_UseSkill(EQ_SKILL_SENSE_HEADING, NULL);
        }

        if (playerSpawn->Character->Skill[EQ_SKILL_FORAGE] > 1)
        {
            if (EQ_IsAutoAttackEnabled() == false && playerSpawn->StandingState == EQ_STANDING_STATE_STANDING)
            {
                if (g_useSkillsForageIsEnabled == true)
                {
                    EQ_UseSkill(EQ_SKILL_FORAGE, NULL);

                    if (playerSpawn->Character->CursorItem != NULL)
                    {
                        EQ_AutoInventory(playerSpawn->Character, &playerSpawn->Character->CursorItem, 0);
                    }
                }
            }
        }
    }

    if (EQ_IsAutoAttackEnabled() == true)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL && targetSpawn != playerSpawn)
        {
            float targetSpawnDistance = EQ_CalculateDistance(playerSpawn->X, playerSpawn->Y, targetSpawn->X, targetSpawn->Y);

            float targetSpawnMeleeDistance = EQ_get_melee_range((EQClass::EQPlayer*)playerSpawn, (EQClass::EQPlayer*)targetSpawn);

            if (targetSpawnDistance <= targetSpawnMeleeDistance)
            {
                if (playerSpawn->Class == EQ_CLASS_WARRIOR || playerSpawn->Class == EQ_CLASS_PALADIN || playerSpawn->Class == EQ_CLASS_SHADOWKNIGHT)
                {
                    if (g_useSkillsTauntIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_TAUNT, (EQClass::EQPlayer*)targetSpawn);
                    }

                    if (g_useSkillsKickIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_KICK, (EQClass::EQPlayer*)targetSpawn);
                    }

                    if (g_useSkillsBashIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_BASH, (EQClass::EQPlayer*)targetSpawn);
                    }

                    if (playerSpawn->Race == EQ_RACE_BARBARIAN || playerSpawn->Race == EQ_RACE_OGRE || playerSpawn->Race == EQ_RACE_TROLL)
                    {
                        if (g_useSkillsSlamIsEnabled == true)
                        {
                            EQ_UseSkill(EQ_SKILL_SLAM, (EQClass::EQPlayer*)targetSpawn);
                        }
                    }

                    if (g_useSkillsDisarmIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_DISARM, (EQClass::EQPlayer*)targetSpawn);
                    }
                }
                else if (playerSpawn->Class == EQ_CLASS_ROGUE)
                {
                    if (g_useSkillsBackstabIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_BACKSTAB, (EQClass::EQPlayer*)targetSpawn);
                    }
                }
            }
        }
    }
}

