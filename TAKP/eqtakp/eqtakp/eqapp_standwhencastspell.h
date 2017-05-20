#pragma once

bool g_standWhenCastSpellIsEnabled = true;

void EQAPP_StandWhenCastSpell_Execute();

void EQAPP_StandWhenCastSpell_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        if (playerSpawn->StandingState == EQ_STANDING_STATE_SITTING)
        {
            ((EQClass::EQPlayer*)playerSpawn)->ChangePosition(EQ_STANDING_STATE_STANDING);
        }
    }
}

