#ifndef EQAPP_SPAWNCASTSPELL_H
#define EQAPP_SPAWNCASTSPELL_H

typedef struct _EQAPPSPAWNCASTSPELL
{
    DWORD spawnInfo;
    std::string spellName;
    DWORD spellCastTime;
    DWORD timer = 0;
} EQAPPSPAWNCASTSPELL, *PEQAPPSPAWNCASTSPELL;

typedef std::shared_ptr<EQAPPSPAWNCASTSPELL> SPEQAPPSPAWNCASTSPELL;

bool g_spawnCastSpellIsEnabled = true;
std::vector<SPEQAPPSPAWNCASTSPELL> g_spawnCastSpellList;
DWORD g_spawnCastSpellTimerDelay = 5000;

void EQAPP_SpawnCastSpell_Execute();
void EQAPP_SpawnCastSpell_Add(DWORD spawnInfo, DWORD spellId, DWORD spellCastTime);

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

    DWORD currentTime = EQ_GetTimer();

    for (auto spawnCastSpellListIterator = g_spawnCastSpellList.begin(); spawnCastSpellListIterator != g_spawnCastSpellList.end(); spawnCastSpellListIterator++)
    {
        PEQAPPSPAWNCASTSPELL spawnCastSpell = spawnCastSpellListIterator->get();
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        DWORD delay = spawnCastSpell->spellCastTime;
        if (delay < g_spawnCastSpellTimerDelay)
        {
            delay = g_spawnCastSpellTimerDelay;
        }

        DWORD spawnStandingState = EQ_ReadMemory<BYTE>(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_STANDING_STATE);

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

void EQAPP_SpawnCastSpell_Add(DWORD spawnInfo, DWORD spellId, DWORD spellCastTime)
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

    SPEQAPPSPAWNCASTSPELL spawnCastSpell = std::make_shared<EQAPPSPAWNCASTSPELL>();
    spawnCastSpell->spawnInfo     = spawnInfo;
    spawnCastSpell->spellName     = spellName;
    spawnCastSpell->spellCastTime = spellCastTime;
    spawnCastSpell->timer         = EQ_GetTimer();

    g_spawnCastSpellList.push_back(std::move(spawnCastSpell));
}

#endif // EQAPP_SPAWNCASTSPELL_H
