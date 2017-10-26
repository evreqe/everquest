#pragma once

bool g_autoStandIsEnabled = true;

bool g_autoStandWhenCastSpellIsEnabled = true;

void EQAPP_AutoStand_HandleEvent_EQ_Character__CastSpell(void* this_ptr, uint8_t spellGemIndex, EQ_SpellID_t spellID, EQ::Item** item, uint16_t unknown);

void EQAPP_AutoStand_HandleEvent_EQ_Character__CastSpell(void* this_ptr, uint8_t spellGemIndex, EQ_SpellID_t spellID, EQ::Item** item, uint16_t unknown)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (playerSpawn->StandingState == EQ_STANDING_STATE_SITTING)
    {
        EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_STANDING);
    }
}

