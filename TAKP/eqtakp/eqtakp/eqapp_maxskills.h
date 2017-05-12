#pragma once

bool g_maxSkillsIsEnabled = true;

void EQAPP_MaxSkills_Execute();

void EQAPP_MaxSkills_Execute()
{
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SENSE_HEADING] = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SAFE_FALL] = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_TRACKING] = 250;
    EQ_POINTER_PlayerCharacter->Skill[EQ_SKILL_SWIMMING] = 250;
}


