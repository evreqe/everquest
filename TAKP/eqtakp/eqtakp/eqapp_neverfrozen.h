#pragma once

bool g_neverFrozenIsEnabled = true;

void EQAPP_NeverFrozen_Toggle();
void EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, uint8_t standingState);

void EQAPP_NeverFrozen_Toggle()
{
    EQ_ToggleBool(g_neverFrozenIsEnabled);
    EQAPP_PrintBool("Never Frozen", g_neverFrozenIsEnabled);
}

void EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, uint8_t standingState)
{
    if (standingState == EQ_STANDING_STATE_FROZEN)
    {
        standingState = EQ_STANDING_STATE_STANDING;
    }
}

