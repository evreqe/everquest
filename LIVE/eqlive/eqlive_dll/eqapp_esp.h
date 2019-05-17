#pragma once

bool g_ESPIsEnabled = false;

bool g_ESPHeightFilterIsEnabled = false;

float g_ESPHeightFilterDistanceLow  = 10.0f;
float g_ESPHeightFilterDistanceHigh = 10.0f;

bool g_ESPShowSpawnsIsEnabled = true;

float g_ESPSpawnDistance = 400.0f;

bool g_ESPFindLineIsEnabled = false;

std::string g_ESPFindSpawnName;
std::string g_ESPFindSpawnLastName;

uint32_t g_ESPFindSpawnNameCount = 0;
uint32_t g_ESPFindSpawnLastNameCount = 0;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_On();
void EQAPP_ESP_Off();
void EQAPP_ESP_HeightFilter_Toggle();
void EQAPP_ESP_FindLine_Toggle();
void EQAPP_ESP_ShowSpawns_Toggle();
void EQAPP_ESP_DrawSpawns();
void EQAPP_ESP_Execute();

void EQAPP_ESP_Toggle()
{
    EQ_ToggleBool(g_ESPIsEnabled);
    EQAPP_PrintBool("ESP", g_ESPIsEnabled);
}

void EQAPP_ESP_On()
{
    if (g_ESPIsEnabled == false)
    {
        EQAPP_ESP_Toggle();
    }
}

void EQAPP_ESP_Off()
{
    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Toggle();
    }
}

void EQAPP_ESP_HeightFilter_Toggle()
{
    EQ_ToggleBool(g_ESPHeightFilterIsEnabled);
    EQAPP_PrintBool("ESP Height Filter", g_ESPHeightFilterIsEnabled);
}

void EQAPP_ESP_FindLine_Toggle()
{
    EQ_ToggleBool(g_ESPFindLineIsEnabled);
    EQAPP_PrintBool("ESP Find Line", g_ESPFindLineIsEnabled);
}

void EQAPP_ESP_ShowSpawns_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnsIsEnabled);
    EQAPP_PrintBool("ESP Show Spawns", g_ESPShowSpawnsIsEnabled);
}

void EQAPP_ESP_DrawSpawns()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto targetSpawn = EQ_GetTargetSpawn();

    g_ESPFindSpawnNameCount = 0;
    g_ESPFindSpawnLastNameCount = 0;

    auto spawnList = EQ_GetSpawnList();
    for (auto spawnListIt = spawnList.begin(); spawnListIt != spawnList.end(); spawnListIt++)
    {
        auto spawn = *spawnListIt;
        if (spawn == NULL)
        {
            continue;
        }

        // move players to the back of the list
        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            std::rotate(spawnListIt, spawnListIt + 1, spawnList.end());
        }
    }

    for (auto& spawn : spawnList)
    {
        if (spawn == NULL)
        {
            continue;
        }

        if (spawn == playerSpawn)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        std::string spawnLastName = EQ_GetSpawnLastName(spawn);

        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);
        auto spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, spawnY, spawnX);

        auto spawnID = EQ_GetSpawnID(spawn);
        auto spawnType = EQ_GetSpawnType(spawn);

        auto spawnLevel = EQ_GetSpawnLevel(spawn);

        bool bIgnoreDistance = false;
        bool bOutOfRange = false;
        bool bDrawLine = false;

        if (g_ESPFindSpawnName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnName, g_ESPFindSpawnName) == true)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnNameCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnLastName, g_ESPFindSpawnLastName) == true)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnLastNameCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (spawnDistance > g_ESPSpawnDistance)
        {
            bOutOfRange = true;
        }

        if (EQ_IsMouseLookEnabled() == false && bIgnoreDistance == false)
        {
            if (bOutOfRange == true)
            {
                continue;
            }

            if (g_ESPHeightFilterIsEnabled == true)
            {
                if (spawnZ < playerSpawnZ)
                {
                    if ((playerSpawnZ - spawnZ) > g_ESPHeightFilterDistanceLow)
                    {
                        continue;
                    }
                }
                else if (spawnZ > playerSpawnZ)
                {
                    if ((spawnZ - playerSpawnZ) > g_ESPHeightFilterDistanceHigh)
                    {
                        continue;
                    }
                }
            }
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(spawnY, spawnX, spawnZ, screenX, screenY);
        if (result == true)
        {
            //if (spawnType == EQ_SPAWN_TYPE_NPC)
            //{
                // (EQ_IsSpawnMount(spawn) == true)
                //{
                    //continue;
                //}

                //if (EQ_IsSpawnAura(spawn) == true)
                //{
                    //continue;
                //}
            //}

            std::stringstream drawText;

            drawText << "[" << (int)spawnLevel << "] " << spawnName;

            if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                drawText << "'s corpse";
            }

            drawText << " (" << (int)spawnDistance << "m)";

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (spawnLastName.size() != 0)
                {
                    drawText << "\n(" << spawnLastName << ")";
                }
            }

            int textColor = EQ_DRAW_TEXT_COLOR_WHITE;

            if (spawn == targetSpawn)
            {
                textColor = EQ_DRAW_TEXT_COLOR_PINK;
            }
            else
            {
                if (bIgnoreDistance == true)
                {
                    textColor = EQ_DRAW_TEXT_COLOR_GREEN;
                }
                else
                {
                    if (spawnType == EQ_SPAWN_TYPE_PLAYER)
                    {
                        textColor = EQ_DRAW_TEXT_COLOR_RED;
                    }
                    else if (spawnType == EQ_SPAWN_TYPE_NPC)
                    {
                        if (bOutOfRange == true)
                        {
                            textColor = EQ_DRAW_TEXT_COLOR_GRAY;
                        }
                        else
                        {
                            textColor = EQ_DRAW_TEXT_COLOR_TEAL;
                        }
                    }
                    else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
                    {
                        textColor = EQ_DRAW_TEXT_COLOR_YELLOW;
                    }
                }
            }

            if (g_ESPFindLineIsEnabled == true && bDrawLine == true)
            {
                EQ_DrawLine(0.0f, 0.0f, screenX, screenY, EQ_COLOR_ARGB_GREY);
            }

            EQ_DrawTextByColor(drawText.str().c_str(), (int)screenX, (int)screenY, textColor);
        }
    }
}

void EQAPP_ESP_Execute()
{
    if (g_ESPShowSpawnsIsEnabled == true)
    {
        EQAPP_ESP_DrawSpawns();
    }
}
