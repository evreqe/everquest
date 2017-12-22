#pragma once

namespace EQApp
{
    typedef struct _SpellSetData
    {
        EQ_SpellGemIndex_t SpellGemIndex;
        EQ_SpellID_t SpellID;
        std::string SpellName;
    } SpellSetData, *SpellSetData_ptr;
}

bool g_SpellSetIsEnabled = true;
bool g_SpellSetIsMemorizingInProgress = false;
std::vector<EQApp::SpellSetData> g_SpellSetList;

void EQAPP_SpellSet_Load(const std::string& spellSetName);
void EQAPP_SpellSet_Save(const std::string& spellSetName);
void EQAPP_SpellSet_Load_Default();
void EQAPP_SpellSet_Save_Default();
void EQAPP_SpellSet_StartMemorizing();
void EQAPP_SpellSet_StopMemorizing();
void EQAPP_SpellSet_LoadAndStartMemorizing();
void EQAPP_SpellSet_Memorize();
void EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, EQ_StandingState_t standingState);
void EQAPP_SpellSet_HandleEvent_CSpellBookWnd__FinishMemorizing(void* this_ptr, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID);

void EQAPP_SpellSet_Load(const std::string& spellSetName)
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

    std::string spawnName = EQ_GetSpawnName(playerSpawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    if (spellSetName.size() == 0)
    {
        return;
    }

    EQAPP_SpellSet_StopMemorizing();

    g_SpellSetList.clear();
    g_SpellSetList.reserve(10);

    std::stringstream filePath;
    filePath << g_EQAppName << "/spellsets/" << spawnName << "_" << spellSetName << ".ini";

    std::cout << "Loading spell set from file: " << filePath.str() << std::endl;

    if (EQAPP_FileExists(filePath.str().c_str()) == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    for (uint8_t i = 0; i < EQ_NUM_SPELL_GEMS; i++)
    {
        auto spellGemSpellID = playerSpawn->Character->SpellGemSpellID[i];
        if (EQ_IsSpellIDValid(spellGemSpellID) == false)
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

        g_SpellSetList.push_back(spellSetData);
    }
}

void EQAPP_SpellSet_Save(const std::string& spellSetName)
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

    std::string spawnName = EQ_GetSpawnName(playerSpawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    if (spellSetName.size() == 0)
    {
        return;
    }

    std::stringstream filePath;
    filePath << g_EQAppName << "/spellsets/" << spawnName << "_" << spellSetName << ".ini";

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

    for (signed int i = 0; i < EQ_NUM_SPELL_GEMS; i++)
    {
        auto spellID = playerSpawn->Character->SpellGemSpellID[i];
        if (EQ_IsSpellIDValid(spellID) == false)
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

void EQAPP_SpellSet_Load_Default()
{
    EQAPP_SpellSet_Load("Default");
}

void EQAPP_SpellSet_Save_Default()
{
    EQAPP_SpellSet_Save("Default");
}

void EQAPP_SpellSet_StartMemorizing()
{
    if (g_SpellSetList.size() == 0)
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

    g_SpellSetIsMemorizingInProgress = true;

    EQAPP_SpellSet_Memorize();
}

void EQAPP_SpellSet_StopMemorizing()
{
    g_SpellSetIsMemorizingInProgress = false;
}

void EQAPP_SpellSet_LoadAndStartMemorizing()
{
    EQAPP_SpellSet_Load_Default();
    EQAPP_SpellSet_StartMemorizing();
}

void EQAPP_SpellSet_Memorize()
{
    if (g_SpellSetList.size() == 0)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (EQ_IsInGame() == false)
    {
        EQAPP_SpellSet_StopMemorizing();
        return;
    }

    if (g_EQAppIsMemorizingSpell == true)
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

    for (auto& spellSetData : g_SpellSetList)
    {
        auto spellGemSpellID = playerSpawn->Character->SpellGemSpellID[spellSetData.SpellGemIndex];
        if (EQ_IsSpellIDValid(spellGemSpellID) == false)
        {
            continue;
        }

        if (EQ_IsSpellIDValid(spellSetData.SpellID) == false)
        {
            continue;
        }

        auto spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellSetData.SpellID);
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

void EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(void* this_ptr, EQ_StandingState_t standingState)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if ((playerSpawn != NULL) && ((EQ::Spawn_ptr)this_ptr == playerSpawn))
    {
        if (standingState != EQ_STANDING_STATE_SITTING)
        {
            g_EQAppIsMemorizingSpell = false;

            EQAPP_SpellSet_StopMemorizing();
        }
    }
}

void EQAPP_SpellSet_HandleEvent_CSpellBookWnd__FinishMemorizing(void* this_ptr, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID)
{
    if (g_SpellSetIsMemorizingInProgress == true)
    {
        EQAPP_SpellSet_Memorize();
    }
}


