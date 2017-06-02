#pragma once

bool g_useSkillsIsEnabled = true;

uint32_t g_useSkillsTimer = 0;
uint32_t g_useSkillsTimerDelay = 1000;

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
        ////EQ_UseSkill(EQ_SKILL_SENSE_HEADING, NULL);

        if (playerSpawn->Character->Skill[EQ_SKILL_FORAGE] > 1)
        {
            if (EQ_IsAutoAttackEnabled() == false && playerSpawn->StandingState == EQ_STANDING_STATE_STANDING)
            {
                EQ_UseSkill(EQ_SKILL_FORAGE, NULL);

                if (playerSpawn->Character->CursorItem != NULL)
                {
                    EQ_AutoInventory(playerSpawn->Character, &playerSpawn->Character->CursorItem, 0);
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
                if (playerSpawn->Class == EQ_CLASS_WARRIOR)
                {
                    EQ_UseSkill(EQ_SKILL_TAUNT, (EQClass::EQPlayer*)targetSpawn);
                    EQ_UseSkill(EQ_SKILL_KICK, (EQClass::EQPlayer*)targetSpawn);
                    EQ_UseSkill(EQ_SKILL_DISARM, (EQClass::EQPlayer*)targetSpawn);
                }
                else if (playerSpawn->Class == EQ_CLASS_ROGUE)
                {
                    EQ_UseSkill(EQ_SKILL_BACKSTAB, (EQClass::EQPlayer*)targetSpawn);
                }
            }
        }
    }
}

