#pragma once

bool g_SpellEffectTestIsEnabled = false;

EQ_SpellID_t g_SpellEffectTestSpellID = 0;

uint32_t g_SpellEffectTestTimer = 0;
uint32_t g_SpellEffectTestTimerDelay = 3000;

void EQAPP_SpellEffectTest_Toggle();
void EQAPP_SpellEffectTest_Execute();

void EQAPP_SpellEffectTest_Toggle()
{
    EQ_ToggleBool(g_SpellEffectTestIsEnabled);
    EQAPP_PrintBool("Spell Effect Test", g_SpellEffectTestIsEnabled);
}

void EQAPP_SpellEffectTest_Execute()
{
    if (EQAPP_IsKeyDown(VK_PAGEUP) == true)
    {
        if (g_SpellEffectTestSpellID == (EQ_NUM_SPELLS - 1))
        {
            g_SpellEffectTestSpellID = 0;
        }
        else
        {
            g_SpellEffectTestSpellID = g_SpellEffectTestSpellID + 1;
        }

        std::cout << "Spell Effect Test ID: " << g_SpellEffectTestSpellID << std::endl;

        Sleep(100);

        g_SpellEffectTestTimer = 0;
    }

    if (EQAPP_IsKeyDown(VK_PAGEDOWN) == true)
    {
        if (g_SpellEffectTestSpellID == 0)
        {
            g_SpellEffectTestSpellID = EQ_NUM_SPELLS - 1;
        }
        else
        {
            g_SpellEffectTestSpellID = g_SpellEffectTestSpellID - 1;
        }

        std::cout << "Spell Effect Test ID: " << g_SpellEffectTestSpellID << std::endl;

        Sleep(100);

        g_SpellEffectTestTimer = 0;
    }

    if (EQ_HasTimePassed(g_SpellEffectTestTimer, g_SpellEffectTestTimerDelay) == false)
    {
        return;
    }

    EQ_SpellID_t spellID = g_SpellEffectTestSpellID;
    if (EQ_IsSpellIDValid(spellID) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spell = EQ_GetSpellByID(spellID);
    if (spell == NULL)
    {
        return;
    }

    std::cout << "DoSpellEffect: " << spell->Name << " (" << spell->ID << ")" << std::endl;

    EQ::Location location;
    location.Y = playerSpawn->Y;
    location.X = playerSpawn->X;
    location.Z = playerSpawn->Z;

    auto player = (EQClass::EQPlayer*)playerSpawn;

    EQ_FUNCTION_DoSpellEffect(2, spell, player, player, &location, NULL, 0);
}
