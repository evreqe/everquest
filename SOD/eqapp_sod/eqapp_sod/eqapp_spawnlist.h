#ifndef EQAPP_SPAWNLIST_H
#define EQAPP_SPAWNLIST_H

void EQAPP_SpawnList_Print(const char* filterSpawnName);

void EQAPP_SpawnList_Print(const char* filterSpawnName)
{
    if (EQ_IsInGame() == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "not in-game");
        return;
    }

    EQAPP_COUT_SaveFlags();

    std::cout << "Spawn List:";
    if (filterSpawnName != NULL)
    {
        std::cout << " " << filterSpawnName;
    }
    std::cout << std::endl;

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    DWORD spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        char spawnLastName[EQ_SIZE_SPAWN_INFO_LAST_NAME] = {0};
        memcpy(spawnLastName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_INFO_LAST_NAME), sizeof(spawnLastName));

        int spawnLevel = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);

        if (spawnLevel < EQ_LEVEL_MIN || spawnLevel > EQ_LEVEL_MAX)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        if (filterSpawnName != NULL && strlen(spawnName) > 0)
        {
            if (strstr(spawnName, filterSpawnName) == NULL)
            {
                spawn = EQ_GetNextSpawn(spawn); // next
                continue;
            }
        }

        int spawnType = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        int spawnClass = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_CLASS);

        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            std::cout << "[PLAYER]    ";
        }
        else if (spawnType == EQ_SPAWN_TYPE_NPC)
        {
            std::cout << "[NPC]       ";
        }
        else
        {
            std::cout << "[CORPSE]    ";
        }

        std::cout << "L" << std::setfill('0') << std::setw(2) << spawnLevel << " ";

        if (spawnClass > EQ_CLASS_UNKNOWN && spawnClass < EQ_CLASS_BANKER && spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            const char* spawnClassThreeLetterCode = EQ_CEverQuest->GetClassThreeLetterCode(spawnClass);

            std::cout << spawnClassThreeLetterCode << "    ";
        }
        else
        {
            std::cout << "       ";
        }

        std::cout << spawnName << " ";

        if (strlen(spawnLastName) > 0)
        {
            if (spawnType == EQ_SPAWN_TYPE_NPC || spawnType == EQ_SPAWN_TYPE_NPC_CORPSE)
            {
                std::cout << "(";
            }

            std::cout << spawnLastName;

            if (spawnType == EQ_SPAWN_TYPE_NPC || spawnType == EQ_SPAWN_TYPE_NPC_CORPSE)
            {
                std::cout << ")";
            }
        }

        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            int spawnIsLfg = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_IS_LFG);
            if (spawnIsLfg == 1)
            {
                std::cout << "  LFG";
            }

            int spawnIsPvp = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_IS_PVP);
            if (spawnIsPvp == 1)
            {
                std::cout << "  PVP";
            }

            int spawnIsTrader = EQ_ReadMemory<DWORD>(spawn + EQ_OFFSET_SPAWN_INFO_IS_TRADER);
            if (spawnIsTrader == 1)
            {
                std::cout << "  TRADER";
            }

            int spawnIsAfk = EQ_ReadMemory<DWORD>(spawn + EQ_OFFSET_SPAWN_INFO_IS_AFK);
            if (spawnIsAfk == 1)
            {
                std::cout << "  AFK";
            }

            int spawnIsGm = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_IS_GM);
            if (spawnIsGm == 1)
            {
                std::cout << "  *GM*";
            }
        }

        if (g_debugIsEnabled == true && playerSpawn != NULL)
        {
            FLOAT spawnY = EQ_GetSpawnY(spawn);
            FLOAT spawnX = EQ_GetSpawnX(spawn);
            FLOAT spawnZ = EQ_GetSpawnZ(spawn);

            float spawnDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, spawnX, spawnY, spawnZ);

            std::cout << "    (Distance: " << (int)spawnDistance << ")";
        }

        std::cout << std::endl;

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    EQAPP_COUT_RestoreFlags();
}

#endif // EQAPP_SPAWNLIST_H
