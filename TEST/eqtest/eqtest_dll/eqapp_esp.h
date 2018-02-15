#pragma once

#include "eqapp_spawncastspell.h"

bool g_ESPIsEnabled = false;

bool g_ESPShowSpawnIDIsEnabled = false;

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

void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnIDIsEnabled);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnIDIsEnabled);
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
            int spawnRace = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_RACE);
            int spawnClass = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_CLASS);

            std::stringstream espText;
            espText << "[" << spawnLevel;

            bool bShowSpawnClass = true;

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (spawnClass == EQ_CLASS_WARRIOR || spawnClass == EQ_CLASS_BANKER || spawnClass == EQ_CLASS_MERCHANT)
                {
                    bShowSpawnClass = false;
                }
            }

            if (bShowSpawnClass == true)
            {
                auto spawnClassIt = EQ_UMAP_CLASS_SHORT_NAME.find(spawnClass);
                if (spawnClassIt != EQ_UMAP_CLASS_SHORT_NAME.end())
                {
                    espText << " " << spawnClassIt->second;
                }
            }

            espText << "] " << spawnName;

            if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                espText << "'s corpse";
            }

            espText << " (" << (int)spawnDistance << "m)";

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (strlen(spawnLastName) > 0)
                {
                    espText << "\n(" << spawnLastName << ")";
                }
            }

            if (g_SpawnCastSpellIsEnabled == true && g_SpawnCastSpellESPIsEnabled == true)
            {
                for (auto& spawnCastSpell : g_SpawnCastSpellList)
                {
                    if (spawnCastSpell->Spawn == NULL)
                    {
                        continue;
                    }

                    if (spawnCastSpell->Spawn == spawn)
                    {
                        espText << "\n<" << spawnCastSpell->SpellName << ">";

                        if (spawnCastSpell->SpellCastTimeCountdown > 0)
                        {
                            float spellCastTimeCurrentFloat = (float)(spawnCastSpell->SpellCastTimeCountdown / 1000.0f);

                            espText.precision(1);
                            espText << " " << std::fixed << spellCastTimeCurrentFloat;
                        }

                        break;
                    }
                }
            }

            if (g_ESPShowSpawnIDIsEnabled == true)
            {
                uint32_t spawnID = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ID);

                espText << "\n(ID: " << spawnID << ")";
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

            EQ_DrawTextEx(espText.str().c_str(), (int)screenX, (int)screenY, textColor);
        }

        spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
    }
}
