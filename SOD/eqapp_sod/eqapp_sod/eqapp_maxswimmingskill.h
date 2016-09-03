#pragma once

bool g_maxSwimmingSkillIsEnabled = true;

void EQAPP_MaxSwimmingSkill_Execute();

void EQAPP_MaxSwimmingSkill_Execute()
{
    if (g_maxSwimmingSkillIsEnabled == false)
    {
        return;
    }

    EQ_SetSwimmingSkillMax();
}

