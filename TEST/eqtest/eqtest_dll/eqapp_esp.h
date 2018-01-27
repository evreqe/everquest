#pragma once

bool g_ESPIsEnabled = false;

float g_ESPDistance = 400.0f;

std::string g_ESPFindSpawnName;
std::string g_ESPFindSpawnLastName;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_Execute();

void EQAPP_ESP_Toggle()
{
    EQ_ToggleBool(g_ESPIsEnabled);
    EQAPP_PrintBool("ESP", g_ESPIsEnabled);
}

void EQAPP_ESP_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    float playerSpawnY = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_Y);
    float playerSpawnX = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_X);
    float playerSpawnZ = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_Z);

    auto targetSpawn = EQ_GetTargetSpawn();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        bool bIgnoreDistance = false;

        char spawnName[EQ_SIZE_SPAWN_NAME];
        memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME), sizeof(spawnName));

        if (g_ESPFindSpawnName.size() != 0)
        {
            if (strstr(spawnName, g_ESPFindSpawnName.c_str()) != 0)
            {
                bIgnoreDistance = true;
            }
        }

        char spawnLastName[EQ_SIZE_SPAWN_LAST_NAME];
        memcpy(spawnLastName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_LAST_NAME), sizeof(spawnLastName));

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            if (strstr(spawnLastName, g_ESPFindSpawnLastName.c_str()) != 0)
            {
                bIgnoreDistance = true;
            }
        }

        float spawnY = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Y);
        float spawnX = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_X);
        float spawnZ = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Z);

        float spawnDistance = EQ_CalculateDistance(playerSpawnX, playerSpawnY, spawnX, spawnY);

        int mouseLook = EQ_ReadMemory<uint8_t>(EQ_ADDRESS_MOUSE_LOOK);
        if (mouseLook == 0 && bIgnoreDistance == false)
        {
            if (spawnDistance > g_ESPDistance)
            {
                spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
                continue;
            }
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldSpaceToScreenSpace(spawnX, spawnY, spawnZ, screenX, screenY);
        if (result == true)
        {
            int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_TYPE);

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (strstr(spawnName, "`s Mount") != 0)
                {
                    spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
                    continue;
                }

                if (strstr(spawnName, "Aura ") != 0)
                {
                    spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
                    continue;
                }

                if (strstr(spawnName, " Aura") != 0)
                {
                    spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
                    continue;
                }
            }

            int spawnLevel = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_LEVEL);

            std::stringstream ss;
            ss << "[" << spawnLevel << "] " << spawnName;

            if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                ss << "'s corpse";
            }

            ss << " (" << (int)spawnDistance << ")";

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (strlen(spawnLastName) > 0)
                {
                    ss << "\n(" << spawnLastName << ")";
                }
            }

            int textColor = EQ_DRAW_TEXT_COLOR_WHITE;

            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                textColor = EQ_DRAW_TEXT_COLOR_RED;
            }
            else if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                textColor = EQ_DRAW_TEXT_COLOR_TEAL;
            }
            else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                textColor = EQ_DRAW_TEXT_COLOR_YELLOW;
            }

            if (spawn == targetSpawn)
            {
                textColor = EQ_DRAW_TEXT_COLOR_PINK;
            }

            if (bIgnoreDistance == true)
            {
                textColor = EQ_DRAW_TEXT_COLOR_GREEN;
            }

            EQ_DrawTextEx(ss.str().c_str(), (int)screenX, (int)screenY, textColor);
        }

        spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
    }
}
