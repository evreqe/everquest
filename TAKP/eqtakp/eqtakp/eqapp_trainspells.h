#pragma once

bool g_trainSpellsIsEnabled = false;

bool g_trainSpellsShouldSit = false;

uint32_t g_trainSpellsTimer = 0;
uint32_t g_trainSpellsTimerDelay = 1000;
uint32_t g_trainSpellsTimerDelayDefault = 1000;

uint32_t g_trainSpellsSitAtManaPercent = 25;
uint32_t g_trainSpellsStandAtManaPercent = 90;

std::string g_trainSpellsSpellName;

void EQAPP_TrainSpells_Toggle();
void EQAPP_TrainSpells_Execute();

void EQAPP_TrainSpells_Toggle()
{
    EQ_ToggleBool(g_trainSpellsIsEnabled);
    EQAPP_PrintBool("Train Spells", g_trainSpellsIsEnabled);

    if (g_trainSpellsIsEnabled == false)
    {
        g_trainSpellsShouldSit = false;

        g_trainSpellsTimerDelay = g_trainSpellsTimerDelayDefault;
    }
}

void EQAPP_TrainSpells_Execute()
{
    if (EQ_HasTimePassed(g_trainSpellsTimer, g_trainSpellsTimerDelay) == false)
    {
        return;
    }

    if (g_trainSpellsSpellName.size() == 0)
    {
        std::cout << __FUNCTION__ << ": Spell Name size is zero." << std::endl;
        std::cout << __FUNCTION__ << ": Spell Name has NOT been set." << std::endl;
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        std::cout << __FUNCTION__ << ": Player Spawn is NULL." << std::endl;
        return;
    }

    auto playerClass = playerSpawn->Class;
    if (playerClass == EQ_CLASS_WARRIOR || playerClass == EQ_CLASS_MONK || playerClass == EQ_CLASS_ROGUE)
    {
        std::cout << __FUNCTION__ << ": Player Class is NOT a caster." << std::endl;
        return;
    }

    std::cout << __FUNCTION__ << ": Spell Name: " << g_trainSpellsSpellName << std::endl;

    auto spellID = EQ_GetSpellIDBySpellName(g_trainSpellsSpellName);
    if (spellID == EQ_SPELL_ID_NULL)
    {
        std::cout << __FUNCTION__ << ": Spell ID is NULL in EQ_GetSpellIDBySpellName() result." << std::endl;
        std::cout << __FUNCTION__ << ": Spell with that name does not exist!" << std::endl;
        return;
    }

    auto spell = EQ_GetSpellByID(spellID);
    if (spell == NULL)
    {
        std::cout << __FUNCTION__ << ": Spell is NULL in EQ_GetSpellByID() result." << std::endl;
        std::cout << __FUNCTION__ << ": Spell was NOT found in the spell list!" << std::endl;
        return;
    }

    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);
    if (spellGemIndex == -1)
    {
        std::cout << __FUNCTION__ << ": Spell Gem Index is -1 in EQ_GetSpellGemIndexBySpellID() result." << std::endl;
        std::cout << __FUNCTION__ << ": Spell is NOT memorized!" << std::endl;
        return;
    }

    auto randomDelay = EQAPP_GetRandomNumber(100, 200);

    g_trainSpellsTimerDelay = spell->CastTime + spell->RecoveryTime + spell->RecastTime + randomDelay;
    if (g_trainSpellsTimerDelay < g_trainSpellsTimerDelayDefault)
    {
        g_trainSpellsTimerDelay = g_trainSpellsTimerDelayDefault;
    }

     std::cout << __FUNCTION__ << ": Timer Delay: " << g_trainSpellsTimerDelay << std::endl;

    auto playerMana = playerSpawn->Character->Mana;
    auto playerManaMax = EQ_CLASS_POINTER_PlayerCharacter->Max_Mana();
    auto playerManaPercent = EQ_GetPlayerManaPercent();

    std::cout << __FUNCTION__ << ": Player Mana: " << playerMana << std::endl;
    std::cout << __FUNCTION__ << ": Player Mana Max: " << playerManaMax << std::endl;
    std::cout << __FUNCTION__ << ": Player Mana Percent: " << playerManaPercent << std::endl;

    std::cout << __FUNCTION__ << ": Spell Casting Time: " << EQ_GetSpellCastingTime() << std::endl;

    if (playerManaPercent <= g_trainSpellsSitAtManaPercent || playerMana < spell->ManaCost)
    {
        g_trainSpellsShouldSit = true;
    }
    else if (playerManaPercent > g_trainSpellsStandAtManaPercent && playerMana > spell->ManaCost)
    {
        g_trainSpellsShouldSit = false;
    }

    if (g_trainSpellsShouldSit == true)
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

