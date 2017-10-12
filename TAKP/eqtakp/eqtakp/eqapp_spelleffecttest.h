#pragma once

bool g_spellEffectTestIsEnabled = false;

uint32_t g_spellEffectTestID = 0;

uint32_t g_spellEffectTestTimer = 0;
uint32_t g_spellEffectTestTimerDelay = 3000;

void EQAPP_SpellEffectTest_Toggle();
void EQAPP_SpellEffectTest_Execute();

void EQAPP_SpellEffectTest_Toggle()
{
    EQ_ToggleBool(g_spellEffectTestIsEnabled);
    EQAPP_PrintBool("Spell Effect Test", g_spellEffectTestIsEnabled);
}

void EQAPP_SpellEffectTest_Execute()
{
    if (EQAPP_IsKeyDown(VK_PAGEUP) == true)
    {
        if (g_spellEffectTestID == (EQ_NUM_SPELLS - 1))
        {
            g_spellEffectTestID = 0;
        }
        else
        {
            g_spellEffectTestID = g_spellEffectTestID + 1;
        }

        std::cout << "Spell Effect Test ID: " << g_spellEffectTestID << std::endl;

        Sleep(100);

        g_spellEffectTestTimer = 0;
    }

    if (EQAPP_IsKeyDown(VK_PAGEDOWN) == true)
    {
        if (g_spellEffectTestID == 0)
        {
            g_spellEffectTestID = EQ_NUM_SPELLS - 1;
        }
        else
        {
            g_spellEffectTestID = g_spellEffectTestID - 1;
        }

        std::cout << "Spell Effect Test ID: " << g_spellEffectTestID << std::endl;

        Sleep(100);

        g_spellEffectTestTimer = 0;
    }

    if (EQ_HasTimePassed(g_spellEffectTestTimer, g_spellEffectTestTimerDelay) == false)
    {
        return;
    }

    uint16_t spellID = g_spellEffectTestID;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto spell = EQ_GetSpellByID(spellID);
        if (spell != NULL)
        {
            std::cout << "DoSpellEffect: " << spell->Name << " (" << spell->ID << ")" << std::endl;

            EQ::Location location;
            location.Y = playerSpawn->Y;
            location.X = playerSpawn->X;
            location.Z = playerSpawn->Z;

            auto player = (EQClass::EQPlayer*)playerSpawn;

            EQ_DoSpellEffect(2, spell, player, player, &location, NULL, 0);
        }
    }
}
