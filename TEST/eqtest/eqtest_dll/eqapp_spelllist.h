#pragma once

std::unordered_map<uint32_t, std::string> g_SpellList; // ID, Name

void EQAPP_SpellList_Load();
void EQAPP_SpellList_LoadEx(const char* filename);
std::string EQAPP_SpellList_GetNameByID(uint32_t spellID);

void EQAPP_SpellList_Load()
{
    EQAPP_SpellList_LoadEx("spells_us.txt");
}

void EQAPP_SpellList_LoadEx(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filename;

        EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());
        return;
    }

    g_SpellList.clear();

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

            g_SpellList.insert({spellID, tokens.at(1)});
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
    else
    {
        return std::string();
    }
}
