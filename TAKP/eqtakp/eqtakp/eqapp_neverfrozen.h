#pragma once

bool g_NeverFrozenIsEnabled = true;

void EQAPP_NeverFrozen_Toggle();
void EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, EQ_StandingState_t standingState);

void EQAPP_NeverFrozen_Toggle()
{
    EQ_ToggleBool(g_NeverFrozenIsEnabled);
    EQAPP_PrintBool("Never Frozen", g_NeverFrozenIsEnabled);
}

void EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, EQ_StandingState_t standingState)
{
    if (standingState == EQ_STANDING_STATE_FROZEN)
    {
        standingState = EQ_STANDING_STATE_STANDING;
    }
}

