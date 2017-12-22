#pragma once

bool g_MaxSkillsIsEnabled = true;

uint32_t g_MaxSkillsTimer = 0;
uint32_t g_MaxSkillsTimerDelay = 1000;

uint16_t g_MaxSkillsValue = 250;

void EQAPP_MaxSkills_Toggle();
void EQAPP_MaxSkills_Execute();

void EQAPP_MaxSkills_Toggle()
{
    EQ_ToggleBool(g_MaxSkillsIsEnabled);
    EQAPP_PrintBool("Max Skills", g_MaxSkillsIsEnabled);
}

void EQAPP_MaxSkills_Execute()
{
    if (EQ_HasTimePassed(g_MaxSkillsTimer, g_MaxSkillsTimerDelay) == false)
    {
        return;
    }

    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SENSE_HEADING] = g_MaxSkillsValue;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SAFE_FALL]     = g_MaxSkillsValue;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_TRACKING]      = g_MaxSkillsValue;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SWIMMING]      = g_MaxSkillsValue;
}


