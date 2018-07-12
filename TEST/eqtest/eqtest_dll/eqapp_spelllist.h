#pragma once

std::unordered_map<uint32_t, std::string> g_SpellList; // <Spell ID, Spell Name>

uint32_t g_SpellList_reserve = EQ_NUM_SPELLS + 1;

std::string g_SpellListFileName = "spells_us.txt";

void EQAPP_SpellList_Load();
void EQAPP_SpellList_LoadEx(const char* filename);
std::string EQAPP_SpellList_GetNameByID(uint32_t spellID);
uint32_t EQAPP_SpellList_GetIDByName(const char* spellName);
uint32_t EQAPP_SpellList_GetSpellGemIndexBySpellName(const char* spellName);

void EQAPP_SpellList_Load()
{
    EQAPP_SpellList_LoadEx(g_SpellListFileName.c_str());
}

void EQAPP_SpellList_LoadEx(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filename;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    g_SpellList.clear();
    g_SpellList.reserve(g_SpellList_reserve);

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(line, '^');

        if (tokens.size() > 1)
        {
            uint32_t spellID = std::stoul(tokens.at(0));

            std::string spellName = tokens.at(1);
            if (spellName.size() == 0)
            {
                continue;
            }

            ////std::cout << "Spell ID: " << spellID << std::endl;
            ////std::cout << "Spell Name: " << spellName << std::endl;

            g_SpellList.insert({spellID, spellName});
        }
    }

    file.close();
}

std::string EQAPP_SpellList_GetNameByID(uint32_t spellID)
{
    auto it = g_SpellList.find(spellID);
    if (it != g_SpellList.end())
    {
        return it->second;
    }

    return std::string();
}

uint32_t EQAPP_SpellList_GetIDByName(const char* spellName)
{
    for (auto it = g_SpellList.begin(); it != g_SpellList.end(); ++it)
    {
        if (it->second == spellName)
        {
            return it->first;
        }
    }

    return EQ_SPELL_ID_NULL;
}

uint32_t EQAPP_SpellList_GetSpellGemIndexBySpellName(const char* spellName)
{
    uint32_t spellGemIndex = EQ_SPELL_GEM_INDEX_NULL;

    auto spellID = EQAPP_SpellList_GetIDByName(spellName);
    if (spellID != EQ_SPELL_ID_NULL)
    {
        for (unsigned int i = 0; i < EQ_NUM_SPELL_GEMS; i++)
        {
            auto memorizedSpellID = EQ_GetMemorizedSpellID(i);
            if (memorizedSpellID == spellID)
            {
                spellGemIndex = i + 1;
                break;
            }
        }
    }

    return spellGemIndex;
}
