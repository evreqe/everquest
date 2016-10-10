#pragma once

namespace EQApp
{
    typedef struct _SpawnCastSpell
    {
        uint32_t spawnInfo;
        std::string spellName;
        uint32_t spellCastTime;
        uint32_t timer = 0;
    } SpawnCastSpell, *SpawnCastSpell_ptr;

    typedef std::shared_ptr<EQApp::SpawnCastSpell> SpawnCastSpell_sharedptr;
}

bool g_spawnCastSpellIsEnabled = true;
std::vector<EQApp::SpawnCastSpell_sharedptr> g_spawnCastSpellList;
uint32_t g_spawnCastSpellTimerDelay = 5000;

void EQAPP_SpawnCastSpell_Execute();
void EQAPP_SpawnCastSpell_Add(uint32_t spawnInfo, uint32_t spellId, uint32_t spellCastTime);

void EQAPP_SpawnCastSpell_Execute()
{
    if (g_spawnCastSpellIsEnabled == false)
    {
        return;
    }

    if (g_spawnCastSpellList.size() == 0)
    {
        return;
    }

    uint32_t currentTime = EQ_GetTimer();

    for (auto spawnCastSpellListIterator = g_spawnCastSpellList.begin(); spawnCastSpellListIterator != g_spawnCastSpellList.end(); spawnCastSpellListIterator++)
    {
        EQApp::SpawnCastSpell* spawnCastSpell = spawnCastSpellListIterator->get();
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        uint32_t delay = spawnCastSpell->spellCastTime;
        if (delay < g_spawnCastSpellTimerDelay)
        {
            delay = g_spawnCastSpellTimerDelay;
        }

        int spawnStandingState = EQ_ReadMemory<uint8_t>(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_STANDING_STATE);

        if
        (
            ((currentTime - spawnCastSpell->timer) > delay) || spawnStandingState == EQ_STANDING_STATE_DUCKING
        )
        {
            spawnCastSpellListIterator = g_spawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }
    }
}

void EQAPP_SpawnCastSpell_Add(uint32_t spawnInfo, uint32_t spellId, uint32_t spellCastTime)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    std::string spellName = EQ_GetSpellNameById(spellId);
    if (spellName.size() == 0)
    {
        return;
    }

    for (auto& spawnCastSpell : g_spawnCastSpellList)
    {
        if (spawnCastSpell->spawnInfo == spawnInfo)
        {
            spawnCastSpell->spellName     = spellName;
            spawnCastSpell->spellCastTime = spellCastTime;
            spawnCastSpell->timer         = EQ_GetTimer();
            return;
        }
    }

    EQApp::SpawnCastSpell_sharedptr spawnCastSpell = std::make_shared<EQApp::SpawnCastSpell>();
    spawnCastSpell->spawnInfo     = spawnInfo;
    spawnCastSpell->spellName     = spellName;
    spawnCastSpell->spellCastTime = spellCastTime;
    spawnCastSpell->timer         = EQ_GetTimer();

    g_spawnCastSpellList.push_back(std::move(spawnCastSpell));
}

