#pragma once

bool g_startCastingisEnabled = true;

void EQAPP_StartCasting_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQ::CEverQuestStartCastingMessage_ptr a1);

void EQAPP_StartCasting_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQ::CEverQuestStartCastingMessage_ptr a1)
{
    auto spawn = EQ_GetSpawnByID(a1->SpawnID);
    if (spawn == NULL)
    {
        return;
    }

    if (spawn->Type != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    if (a1->SpellID == EQ_SPELL_ID_NULL)
    {
        return;
    }

    auto spell = EQ_GetSpellByID(a1->SpellID);
    if (spell == NULL)
    {
        return;
    }

    std::string spellName = spell->Name;
    if (spellName.size() == 0)
    {
        return;
    }

    std::cout << spawnName << " starts to cast " << spellName << "." << std::endl;
}

