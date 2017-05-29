#pragma once

bool g_maxSkillsIsEnabled = true;

uint32_t g_maxSkillsTimer = 0;
uint32_t g_maxSkillsTimerDelay = 1000;

void EQAPP_MaxSkills_Execute();

void EQAPP_MaxSkills_Execute()
{
    if (EQ_HasTimePassed(g_maxSkillsTimer, g_maxSkillsTimerDelay) == false)
    {
        return;
    }

    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SENSE_HEADING] = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SAFE_FALL]     = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_TRACKING]      = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SWIMMING]      = 250;
}


