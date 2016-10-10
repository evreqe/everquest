#pragma once

bool g_maxSwimmingSkillIsEnabled = true;
uint32_t g_maxSwimmingSkillTimer = 0;
uint32_t g_maxSwimmingSkillTimerDelay = 1000;

void EQAPP_MaxSwimmingSkill_Execute();

void EQAPP_MaxSwimmingSkill_Execute()
{
    if (g_maxSwimmingSkillIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_maxSwimmingSkillTimer, g_maxSwimmingSkillTimerDelay) == false)
    {
        return;
    }

    EQ_SetSwimmingSkillMax();
}

