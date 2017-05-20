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

        if (EQ_IsAutoAttackEnabled() == false)
        {
            EQ_UseSkill(EQ_SKILL_FORAGE, NULL);

            if (playerSpawn->Character->CursorItem != NULL)
            {
                EQ_AutoInventory(playerSpawn->Character, &playerSpawn->Character->CursorItem, 0);
            }
        }
    }

    if (playerSpawn->Class == EQ_CLASS_WARRIOR)
    {
        if (EQ_IsAutoAttackEnabled() == true)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn != NULL && targetSpawn != playerSpawn)
            {
                float targetSpawnDistance = EQ_CalculateDistance(playerSpawn->X, playerSpawn->Y, targetSpawn->X, targetSpawn->Y);

                float targetSpawnMeleeDistance = EQ_get_melee_range((EQClass::EQPlayer*)playerSpawn, (EQClass::EQPlayer*)targetSpawn);

                if (targetSpawnDistance <= targetSpawnMeleeDistance)
                {
                    EQ_UseSkill(EQ_SKILL_TAUNT, (EQClass::EQPlayer*)targetSpawn);
                    EQ_UseSkill(EQ_SKILL_KICK, (EQClass::EQPlayer*)targetSpawn);
                    EQ_UseSkill(EQ_SKILL_DISARM, (EQClass::EQPlayer*)targetSpawn);
                }
            }
        }
    }
}

