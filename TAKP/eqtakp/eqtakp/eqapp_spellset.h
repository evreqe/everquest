#pragma once

namespace EQApp
{
    typedef struct _SpellSetData
    {
        uint32_t SpellGemIndex;
        uint32_t SpellID;
        std::string SpellName;
    } SpellSetData, *SpellSetData_ptr;
}

bool g_spellSetIsEnabled = true;
std::vector<EQApp::SpellSetData> g_spellSetList;

void EQAPP_SpellSet_Load();
void EQAPP_SpellSet_Save();
void EQAPP_SpellSet_Memorize();

void EQAPP_SpellSet_Load()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    g_spellSetList.clear();

    std::string classShortName = EQ_GetClassShortName(playerSpawn->Class);

    std::stringstream filePath;
    filePath << g_applicationName << "/spellsets/" << classShortName << ".ini";

    for (size_t i = 0; i < EQ_NUM_SPELL_GEMS; i++)
    {
        if (playerSpawn->Character->MemorizedSpell[i] != EQ_SPELL_ID_NULL)
        {
            continue;
        }

        EQApp::SpellSetData spellSetData;

        spellSetData.SpellGemIndex = i;

        std::stringstream ssSpellID;
        ssSpellID << "SpellID" << i;

        spellSetData.SpellID = EQAPP_INI_ReadInt(filePath.str().c_str(), "SpellSet", ssSpellID.str().c_str(), EQ_SPELL_ID_NULL);

        std::stringstream ssSpellName;
        ssSpellName << "SpellName" << i;

        spellSetData.SpellName = EQAPP_INI_ReadString(filePath.str().c_str(), "SpellSet", ssSpellName.str().c_str(), "(null)");

        g_spellSetList.push_back(spellSetData);
    }
}

void EQAPP_SpellSet_Save()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string classShortName = EQ_GetClassShortName(playerSpawn->Class);

    std::stringstream filePath;
    filePath << g_applicationName << "/spellsets/" << classShortName << ".ini";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    file << "[SpellSet]\n";

    for (size_t i = 0; i < EQ_NUM_SPELL_GEMS; i++)
    {
        uint16_t spellID = playerSpawn->Character->MemorizedSpell[i];
        if (spellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        std::string spellName = EQ_POINTER_SpellList->Spell[spellID]->Name;
        if (spellName.size() == 0)
        {
            continue;
        }

        file << "SpellID" << i << "=" << spellID << "\n";

        file << "SpellName" << i << "=" << spellName << "\n";
    }

    file.close();
}

void EQAPP_SpellSet_Memorize()
{
    //
}

