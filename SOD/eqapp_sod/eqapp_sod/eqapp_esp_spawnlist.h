#pragma once

namespace EQApp
{
    typedef struct _ESPSpawn
    {
        uint32_t spawnInfo;
        char name[EQ_SIZE_SPAWN_INFO_NAME];
        char lastName[EQ_SIZE_SPAWN_INFO_LAST_NAME];
        float y;
        float x;
        float z;
        float distance;
        int level;
        int type;
        int _class;
        int guildId;
        int standingState;
        int hp;
        int isHoldingPrimary;
        int isHoldingSecondary;
        int isPet;
        int isLfg;
        int isPvp;
        int isTrader;
        int isAfk;
        int isGm;
        bool showAtAnyDistance = false;
        bool isTarget = false;
        bool isInGroup = false;
        bool isFindSpawn = false;
        bool isHalfDistance = false;
    } ESPSpawn, *ESPSpawn_ptr;
}

std::vector<EQApp::ESPSpawn> g_espSpawnList;
uint32_t g_espSpawnListTimer = 0;
uint32_t g_espSpawnListTimerDelay = 1000;

void EQAPP_ESP_SpawnList_Update();

void EQAPP_ESP_SpawnList_Update()
{
    if (EQ_HasTimePassed(g_espSpawnListTimer, g_espSpawnListTimerDelay) == false)
    {
        return;
    }

    g_espSpawnList.clear();

    uint32_t numNpcCorpse = 0;

    g_espFindCount = 0;

    uint32_t targetSpawn = EQ_GetTargetSpawn();
    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    // spawn
    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        EQApp::ESPSpawn espSpawn;
        espSpawn.spawnInfo = spawn;

        memcpy(espSpawn.name, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(espSpawn.name));
        memcpy(espSpawn.lastName, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_LAST_NAME), sizeof(espSpawn.lastName));

        espSpawn.y = EQ_GetSpawnY(spawn);
        espSpawn.x = EQ_GetSpawnX(spawn);
        espSpawn.z = EQ_GetSpawnZ(spawn);

        espSpawn.distance = EQ_CalculateDistance3d(playerX, playerY, playerZ, espSpawn.x, espSpawn.y, espSpawn.z);

        espSpawn.level = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);

        if (espSpawn.level < EQ_LEVEL_MIN || espSpawn.level > EQ_LEVEL_MAX)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        espSpawn.type = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
        espSpawn._class = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_CLASS);
        espSpawn.guildId = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_GUILD_ID);

        espSpawn.standingState = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_STANDING_STATE);

        espSpawn.hp = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_HP);

        espSpawn.isHoldingPrimary   = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_HOLDING_PRIMARY);
        espSpawn.isHoldingSecondary = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_HOLDING_SECONDARY);

        espSpawn.isPet    = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID);
        espSpawn.isLfg    = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_LFG);
        espSpawn.isPvp    = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_PVP);
        espSpawn.isTrader = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_TRADER);
        espSpawn.isAfk    = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_AFK);
        espSpawn.isGm     = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_IS_GM);

        if (spawn == targetSpawn)
        {
            espSpawn.isTarget = true;
        }

        if (EQ_IsSpawnInGroup(spawn) == true)
        {
            espSpawn.isInGroup = true;
        }

        if (g_espFindIsEnabled == true && g_espFindSpawnName.size() != 0)
        {
            if (strstr(espSpawn.name, g_espFindSpawnName.c_str()) != NULL)
            {
                bool ignoreFind = false;

                if (g_espFindIgnoreNpcCorpseIsEnabled && espSpawn.type == EQ_SPAWN_TYPE_NPC_CORPSE)
                {
                    ignoreFind = true;
                }

                if (ignoreFind == false)
                {
                    espSpawn.showAtAnyDistance = true;
                    espSpawn.isFindSpawn = true;

                    g_espFindCount++;
                }
            }
        }

        if (espSpawn.type == EQ_SPAWN_TYPE_NPC && espSpawn.isPet == 0)
        {
            for (auto& namedSpawn : g_namedSpawnsList)
            {
                if (strstr(espSpawn.name, namedSpawn.c_str()) != NULL)
                {
                    espSpawn.showAtAnyDistance = true;
                    break;
                }
            }
        }

        if (espSpawn.type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            numNpcCorpse++;

            if (espSpawn.isTarget == false && espSpawn.showAtAnyDistance == false)
            {
                if (numNpcCorpse > g_espNumNpcCorpseMax)
                {
                    spawn = EQ_GetNextSpawn(spawn); // next
                    continue;
                }
            }
        }

        if (espSpawn.type == EQ_SPAWN_TYPE_NPC && espSpawn.distance > g_espSpawnDistance && espSpawn.showAtAnyDistance == false)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        if (espSpawn.distance > (g_espSpawnDistance * 0.5f))
        {
            espSpawn.isHalfDistance = true;
        }

        g_espSpawnList.push_back(espSpawn);

        spawn = EQ_GetNextSpawn(spawn); // next
    }
}

