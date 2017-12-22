#pragma once

namespace EQApp
{
    typedef struct _SpawnCastSpell
    {
        EQ::Spawn_ptr Spawn;
        std::string SpellName;
        uint32_t SpellCastTime; // time it takes to cast the spell in milliseconds
        uint32_t SpellCastTimeCountdown; // spell cast time in milliseconds that decreases until it reaches a value of 0
        uint32_t StartCastingTime = 0; // time you started to cast the spell in the global timer
    } SpawnCastSpell, *SpawnCastSpell_ptr;

    typedef std::shared_ptr<EQApp::SpawnCastSpell> SpawnCastSpell_sharedptr;
}

bool g_SpawnCastSpellIsEnabled = true;
bool g_SpawnCastSpellESPIsEnabled = true;

std::vector<EQApp::SpawnCastSpell_sharedptr> g_SpawnCastSpellList;

uint32_t g_SpawnCastSpellMinimumCastTime = 3000;

uint32_t g_SpawnCastSpellCountdownTimer = 0;
uint32_t g_SpawnCastSpellCountdownTimerDelay = 100;

uint32_t g_SpawnCastSpellDrawTextX = 1200;
uint32_t g_SpawnCastSpellDrawTextY = 500;

void EQAPP_SpawnCastSpell_Execute();
void EQAPP_SpawnCastSpell_DrawText();
void EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQ::CEverQuestStartCastingMessage_ptr message);

void EQAPP_SpawnCastSpell_Execute()
{
    if (g_SpawnCastSpellList.size() == 0)
    {
        return;
    }

    uint32_t currentTime = EQ_GetTimer();

    bool bCountdownTimerHasPassed = false;
    if (EQ_HasTimePassed(g_SpawnCastSpellCountdownTimer, g_SpawnCastSpellCountdownTimerDelay) == true)
    {
        bCountdownTimerHasPassed = true;
    }

    for (auto spawnCastSpellListIterator = g_SpawnCastSpellList.begin(); spawnCastSpellListIterator != g_SpawnCastSpellList.end(); spawnCastSpellListIterator++)
    {
        EQApp::SpawnCastSpell_ptr spawnCastSpell = spawnCastSpellListIterator->get();
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        auto spawn = spawnCastSpell->Spawn;
        if (spawn == NULL)
        {
            spawnCastSpellListIterator = g_SpawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }

        if (spawn->StandingState != EQ_STANDING_STATE_STANDING)
        {
            spawnCastSpell->SpellCastTime = 0;
            spawnCastSpell->SpellCastTimeCountdown = 0;
        }

        if (bCountdownTimerHasPassed == true)
        {
            if (spawnCastSpell->SpellCastTimeCountdown > 0 && spawnCastSpell->SpellCastTimeCountdown > g_SpawnCastSpellCountdownTimerDelay)
            {
                spawnCastSpell->SpellCastTimeCountdown -= g_SpawnCastSpellCountdownTimerDelay;
            }
            else if (spawnCastSpell->SpellCastTimeCountdown <= g_SpawnCastSpellCountdownTimerDelay)
            {
                spawnCastSpell->SpellCastTimeCountdown = 0;
            }
        }

        uint32_t spellCastTime = spawnCastSpell->SpellCastTime;
        if (spellCastTime < g_SpawnCastSpellMinimumCastTime)
        {
            spellCastTime = g_SpawnCastSpellMinimumCastTime;
        }

        if ((currentTime - spawnCastSpell->StartCastingTime) > spellCastTime)
        {
            spawnCastSpellListIterator = g_SpawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }
    }
}

void EQAPP_SpawnCastSpell_DrawText()
{
    if (g_SpawnCastSpellList.size() == 0)
    {
        return;
    }

    std::stringstream drawText;

    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        auto spawn = spawnCastSpell->Spawn;
        if (spawn == NULL)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawnCastSpell->Spawn);
        if (spawnName.size() == 0)
        {
            continue;
        }

        drawText << spawnName << " (" << spawnCastSpell->SpellName << ")\n";
    }

    EQ_DrawText(drawText.str().c_str(), g_SpawnCastSpellDrawTextX, g_SpawnCastSpellDrawTextY, EQ_COLOR_ARGB_WHITE);
}

void EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQ::CEverQuestStartCastingMessage_ptr message)
{
    EQ::Spawn_ptr spawn = EQ_GetSpawnByID(message->SpawnID);
    if (spawn == NULL)
    {
        return;
    }

    uint32_t spellCastTime = message->SpellCastTime;
    if (spellCastTime == 0)
    {
        return;
    }

    uint16_t spellID = message->SpellID;
    if (EQ_IsSpellIDValid(spellID) == false)
    {
        return;
    }

    auto spell = EQ_GetSpellByID(spellID);
    if (spell == NULL)
    {
        return;
    }

    std::string spellName = spell->Name;
    if (spellName.size() == 0)
    {
        return;
    }

    // update if spawn already exists in the list
    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (spawnCastSpell->Spawn == spawn)
        {
            spawnCastSpell->SpellName              = spellName;
            spawnCastSpell->SpellCastTime          = spellCastTime;
            spawnCastSpell->SpellCastTimeCountdown = spellCastTime;
            spawnCastSpell->StartCastingTime       = EQ_GetTimer();
            return;
        }
    }

    // add to the list
    EQApp::SpawnCastSpell_sharedptr spawnCastSpell = std::make_shared<EQApp::SpawnCastSpell>();
    spawnCastSpell->Spawn                  = spawn;
    spawnCastSpell->SpellName              = spellName;
    spawnCastSpell->SpellCastTime          = spellCastTime;
    spawnCastSpell->SpellCastTimeCountdown = spellCastTime;
    spawnCastSpell->StartCastingTime       = EQ_GetTimer();

    g_SpawnCastSpellList.push_back(std::move(spawnCastSpell));
}

