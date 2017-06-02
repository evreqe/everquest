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
bool g_spellSetIsMemorizingInProgress = false;
std::vector<EQApp::SpellSetData> g_spellSetList;

void EQAPP_SpellSet_Load();
void EQAPP_SpellSet_Save();
void EQAPP_SpellSet_StartMemorizing();
void EQAPP_SpellSet_StopMemorizing();
void EQAPP_SpellSet_LoadAndStartMemorizing();
void EQAPP_SpellSet_Memorize();
void EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, uint8_t standingState);

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

    EQAPP_SpellSet_StopMemorizing();

    g_spellSetList.clear();

    std::string spawnName = EQ_CLASS_POINTER_CEverQuest->trimName(playerSpawn->Name);
    if (spawnName.size() == 0)
    {
        return;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/spellsets/" << spawnName << ".ini";

    std::cout << "Loading spell set from file: " << filePath.str() << std::endl;

    if (EQAPP_FileExists(filePath.str().c_str()) == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

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

    std::string spawnName = EQ_CLASS_POINTER_CEverQuest->trimName(playerSpawn->Name);
    if (spawnName.size() == 0)
    {
        return;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/spellsets/" << spawnName << ".ini";

    std::string filePathStr = filePath.str();

    std::cout << "Saving spell set to file: " << filePathStr << std::endl;

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

void EQAPP_SpellSet_StartMemorizing()
{
    if (g_spellSetList.size() == 0)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (EQ_IsInGame() == false)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (playerSpawn->StandingState == EQ_STANDING_STATE_STANDING)
    {
        ((EQClass::EQPlayer*)playerSpawn)->ChangePosition(EQ_STANDING_STATE_SITTING);
    }

    g_spellSetIsMemorizingInProgress = true;

    EQAPP_SpellSet_Memorize();
}

void EQAPP_SpellSet_StopMemorizing()
{
    g_spellSetIsMemorizingInProgress = false;
}

void EQAPP_SpellSet_LoadAndStartMemorizing()
{
    EQAPP_SpellSet_Load();
    EQAPP_SpellSet_StartMemorizing();
}

void EQAPP_SpellSet_Memorize()
{
    if (g_spellSetList.size() == 0)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (EQ_IsInGame() == false)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (g_bIsMemorizingSpell == true)
    {
        return;
    }

    if (EQ_CLASS_POINTER_CSpellBookWnd->GetSpellMemTicksLeft() != 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (playerSpawn->StandingState != EQ_STANDING_STATE_SITTING)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    bool bWasAbleToMemorizeSpell = false;

    for (auto& spellSetData : g_spellSetList)
    {
        if (playerSpawn->Character->MemorizedSpell[spellSetData.SpellGemIndex] != EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (spellSetData.SpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        signed int spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellSetData.SpellID);
        if (spellBookIndex == -1)
        {
            continue;
        }

        EQ_CLASS_POINTER_CSpellBookWnd->Activate();
        EQ_CLASS_POINTER_CSpellBookWnd->StartSpellMemorization(spellBookIndex, spellSetData.SpellGemIndex, 0);

        bWasAbleToMemorizeSpell = true;

        break;
    }

    if (bWasAbleToMemorizeSpell == false)
    {
        EQAPP_SpellSet_StopMemorizing();
    }
}

void EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, uint8_t standingState)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if ((playerSpawn != NULL) && ((EQ::Spawn_ptr)this_ptr == playerSpawn))
    {
        if (standingState != EQ_STANDING_STATE_SITTING)
        {
            g_bIsMemorizingSpell = false;

            EQAPP_SpellSet_StopMemorizing();
        }
    }
}


