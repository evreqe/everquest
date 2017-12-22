#pragma once

bool g_TrainSpellsIsEnabled = false;

bool g_TrainSpellsDebugIsEnabled = false;

bool g_TrainSpellsShouldSit = false;

uint32_t g_TrainSpellsTimer = 0;
uint32_t g_TrainSpellsTimerDelay = 1000;
uint32_t g_TrainSpellsTimerDelayDefault = 1000;

uint32_t g_TrainSpellsSitAtManaPercent = 25;
uint32_t g_TrainSpellsStandAtManaPercent = 90;

std::string g_TrainSpellsSpellName;

void EQAPP_TrainSpells_Toggle();
void EQAPP_TrainSpells_Debug_Toggle();
void EQAPP_TrainSpells_Execute();
void EQAPP_TrainSpells_HandleEvent_CEverQuest__dsp_chat(void* this_ptr, const char* text, int textColor, bool filtered);

void EQAPP_TrainSpells_Toggle()
{
    EQ_ToggleBool(g_TrainSpellsIsEnabled);
    EQAPP_PrintBool("Train Spells", g_TrainSpellsIsEnabled);

    if (g_TrainSpellsIsEnabled == false)
    {
        g_TrainSpellsShouldSit = false;

        g_TrainSpellsTimerDelay = g_TrainSpellsTimerDelayDefault;
    }
}

void EQAPP_TrainSpells_Debug_Toggle()
{
    EQ_ToggleBool(g_TrainSpellsDebugIsEnabled);
    EQAPP_PrintBool("Train Spells Debug", g_TrainSpellsDebugIsEnabled);
}

void EQAPP_TrainSpells_Execute()
{
    if (EQ_HasTimePassed(g_TrainSpellsTimer, g_TrainSpellsTimerDelay) == false)
    {
        return;
    }

    if (g_TrainSpellsSpellName.size() == 0)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Spell Name size is zero." << std::endl;
            std::cout << __FUNCTION__ << ": Spell Name has NOT been set." << std::endl;
        }

        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Player Spawn is NULL." << std::endl;
        }

        return;
    }

    auto playerClass = playerSpawn->Class;
    if (playerClass == EQ_CLASS_WARRIOR || playerClass == EQ_CLASS_MONK || playerClass == EQ_CLASS_ROGUE)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Player Class is NOT a caster." << std::endl;
        }

        return;
    }

    if (g_TrainSpellsDebugIsEnabled == true)
    {
        std::cout << __FUNCTION__ << ": Spell Name: " << g_TrainSpellsSpellName << std::endl;
    }

    auto spellID = EQ_GetSpellIDBySpellName(g_TrainSpellsSpellName);
    if (EQ_IsSpellIDValid(spellID) == false)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Spell ID is not valid in EQ_GetSpellIDBySpellName() result." << std::endl;
            std::cout << __FUNCTION__ << ": Spell with that name does not exist!" << std::endl;
        }

        return;
    }

    auto spell = EQ_GetSpellByID(spellID);
    if (spell == NULL)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Spell is NULL in EQ_GetSpellByID() result." << std::endl;
            std::cout << __FUNCTION__ << ": Spell was NOT found in the spell list!" << std::endl;
        }

        return;
    }

    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);
    if (spellGemIndex == -1)
    {
        if (g_TrainSpellsDebugIsEnabled == true)
        {
            std::cout << __FUNCTION__ << ": Spell Gem Index is -1 in EQ_GetSpellGemIndexBySpellID() result." << std::endl;
            std::cout << __FUNCTION__ << ": Spell is NOT memorized!" << std::endl;
        }

        return;
    }

    auto randomDelay = EQAPP_GetRandomNumber(100, 200);

    g_TrainSpellsTimerDelay = spell->CastTime + spell->RecoveryTime + spell->RecastTime + randomDelay;
    if (g_TrainSpellsTimerDelay < g_TrainSpellsTimerDelayDefault)
    {
        g_TrainSpellsTimerDelay = g_TrainSpellsTimerDelayDefault;
    }

    if (g_TrainSpellsDebugIsEnabled == true)
    {
        std::cout << __FUNCTION__ << ": Timer Delay: " << g_TrainSpellsTimerDelay << std::endl;
    }

    auto playerMana = playerSpawn->Character->Mana;
    auto playerManaMax = EQ_CLASS_POINTER_PlayerCharacter->Max_Mana();
    auto playerManaPercent = EQ_GetPlayerManaPercent();

    if (g_TrainSpellsDebugIsEnabled == true)
    {
        std::cout << __FUNCTION__ << ": Player Mana: " << playerMana << std::endl;
        std::cout << __FUNCTION__ << ": Player Mana Max: " << playerManaMax << std::endl;
        std::cout << __FUNCTION__ << ": Player Mana Percent: " << playerManaPercent << std::endl;

        std::cout << __FUNCTION__ << ": Spell Casting Time: " << EQ_FUNCTION_GetSpellCastingTime() << std::endl;
    }

    if (playerManaPercent <= g_TrainSpellsSitAtManaPercent || playerMana < spell->ManaCost)
    {
        g_TrainSpellsShouldSit = true;
    }
    else if (playerManaPercent > g_TrainSpellsStandAtManaPercent && playerMana > spell->ManaCost)
    {
        g_TrainSpellsShouldSit = false;
    }

    if (g_TrainSpellsShouldSit == true)
    {
        EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_SITTING);
    }
    else
    {
        if (EQ_IsPlayerCastingSpell() == false)
        {
            EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_STANDING);

            EQ_CLASS_POINTER_PlayerCharacter->CastSpell(spellGemIndex, spellID, NULL, -1);
        }
    }
}

void EQAPP_TrainSpells_HandleEvent_CEverQuest__dsp_chat(void* this_ptr, const char* text, int textColor, bool filtered)
{
    if (text == NULL)
    {
        return;
    }

    if (strcmp(text, "Your spell fizzles!") == 0)
    {
        g_TrainSpellsTimer = EQ_GetTimer();
        g_TrainSpellsTimerDelay = 0;

        EQAPP_TrainSpells_Execute();
    }
}

