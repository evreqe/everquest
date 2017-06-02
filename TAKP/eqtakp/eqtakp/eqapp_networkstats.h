#pragma once

namespace EQApp
{
    typedef struct _NetworkStats
    {
        uint8_t ErrorCode;
        uint8_t Reserved1;
        char SpawnName[30];
        uint16_t SpawnHPCurrent;
        uint16_t SpawnHPMax;
        uint16_t SpawnManaCurrent;
        uint16_t SpawnManaMax;
        uint8_t SpawnHasPet;
        uint8_t Reserved2;
        char SpawnPetName[30];
        uint16_t SpawnPetHPCurrent;
        uint16_t SpawnPetHPMax;
    } NetworkStats, *NetworkStats_ptr;
}

bool g_networkStatsIsEnabled = true;

std::vector<std::string> g_networkStatsPlayerList;
std::vector<EQApp::NetworkStats> g_networkStatsList;

uint32_t g_networkStatsDrawX = 8;
uint32_t g_networkStatsDrawY = 100;

uint32_t g_networkStatsTimer = 0;
uint32_t g_networkStatsTimerDelay = 1000;

void EQAPP_NetworkStats_Load();
void EQAPP_NetworkStats_Draw();
void EQAPP_NetworkStats_Execute();
void EQAPP_NetworkStats_Write();
EQApp::NetworkStats EQAPP_NetworkStats_Read(std::string spawnName);

void EQAPP_NetworkStats_Toggle()
{
    EQ_ToggleBool(g_networkStatsIsEnabled);
    EQAPP_PrintBool("Network Stats", g_networkStatsIsEnabled);
}

void EQAPP_NetworkStats_Load()
{
    std::cout << "Loading Network Stats players..." << std::endl;

    g_networkStatsPlayerList.clear();

    EQAPP_ReadFileToList("networkstats.txt", g_networkStatsPlayerList);
}

void EQAPP_NetworkStats_Draw()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    std::stringstream drawText;

    for (auto& networkStats : g_networkStatsList)
    {
        drawText << "Name: " << networkStats.SpawnName << "\n";
        drawText << "HP: " << networkStats.SpawnHPCurrent << " / " << networkStats.SpawnHPMax << "\n";
        drawText << "Mana: " << networkStats.SpawnManaCurrent << " / " << networkStats.SpawnManaMax << "\n";

        if (networkStats.SpawnHasPet == 1)
        {
            drawText << "\n";
            drawText << "Pet Name: " << networkStats.SpawnPetName << "\n";
            drawText << "Pet HP: " << networkStats.SpawnPetHPCurrent << " / " << networkStats.SpawnPetHPMax << "\n";
        }

        drawText << "\n";
    }

    EQ_DrawText(drawText.str().c_str(), g_networkStatsDrawX, g_networkStatsDrawY, EQ_TEXT_COLOR_WHITE);
}

void EQAPP_NetworkStats_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_networkStatsTimer, g_networkStatsTimerDelay) == false)
    {
        return;
    }

    EQAPP_NetworkStats_Write();

    g_networkStatsList.clear();

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerSpawnName = EQ_CLASS_POINTER_CEverQuest->trimName(playerSpawn->Name);
    if (playerSpawnName.size() == 0)
    {
        return;
    }

    for (auto& spawnName : g_networkStatsPlayerList)
    {
        if (spawnName == playerSpawnName)
        {
            continue;
        }

        if (EQ_GetSpawnByName(spawnName) == NULL)
        {
            continue;
        }

        EQApp::NetworkStats networkStats = EQAPP_NetworkStats_Read(spawnName);
        if (networkStats.ErrorCode == 0)
        {
            g_networkStatsList.push_back(networkStats);
        }
    }
}

void EQAPP_NetworkStats_Write()
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
    filePath << g_applicationName << "/networkstats/" << spawnName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    EQApp::NetworkStats networkStats;
    networkStats.ErrorCode   = 0;
    networkStats.Reserved1   = 0;
    networkStats.SpawnHasPet = 0;
    networkStats.Reserved2   = 0;

    strncpy_s(networkStats.SpawnName, sizeof(networkStats.SpawnName), spawnName.c_str(), sizeof(networkStats.SpawnName));

    networkStats.SpawnHPCurrent   = playerSpawn->HPCurrent;
    networkStats.SpawnHPMax       = playerSpawn->HPMax;
    networkStats.SpawnManaCurrent = playerSpawn->Character->Mana;
    networkStats.SpawnManaMax     = EQ_CLASS_POINTER_PlayerCharacter->Max_Mana();

    auto playerPetSpawn = EQ_GetPlayerPetSpawn();
    if (playerPetSpawn != NULL)
    {
        std::string spawnPetName = EQ_CLASS_POINTER_CEverQuest->trimName(playerPetSpawn->Name);
        if (spawnPetName.size() != 0)
        {
            networkStats.SpawnHasPet = 1;

            strncpy_s(networkStats.SpawnPetName, sizeof(networkStats.SpawnPetName), spawnPetName.c_str(), sizeof(networkStats.SpawnPetName));

            networkStats.SpawnPetHPCurrent = playerPetSpawn->HPCurrent;
            networkStats.SpawnPetHPMax     = playerPetSpawn->HPMax;
        }
    }

    file.seekg(0, std::fstream::beg);
    file.write((char*)&networkStats, sizeof(networkStats));
    file.close();
}

EQApp::NetworkStats EQAPP_NetworkStats_Read(std::string spawnName)
{
    EQApp::NetworkStats networkStats;
    networkStats.ErrorCode   = 1;
    networkStats.Reserved1   = 0;
    networkStats.SpawnHasPet = 0;
    networkStats.Reserved2   = 0;

    if (spawnName.size() == 0)
    {
        return networkStats;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/networkstats/" << spawnName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in | std::fstream::binary);
    if (file.is_open() == false)
    {
        return networkStats;
    }

    file.read((char*)&networkStats, sizeof(networkStats));
    file.close();

    return networkStats;
}
