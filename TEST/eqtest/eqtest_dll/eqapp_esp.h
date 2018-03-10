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

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto targetSpawn = EQ_GetTargetSpawn();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        bool bIgnoreDistance = false;

        std::string spawnName = EQ_GetSpawnName(spawn);

        if (g_ESPFindSpawnName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnName, g_ESPFindSpawnName) == true)
            {
                bIgnoreDistance = true;
            }
        }

        std::string spawnLastName = EQ_GetSpawnLastName(spawn);

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnLastName, g_ESPFindSpawnLastName) == true)
            {
                bIgnoreDistance = true;
            }
        }

        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);
        auto spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance(playerSpawnX, playerSpawnY, spawnX, spawnY);

        if (EQ_IsMouseLookEnabled() == false && bIgnoreDistance == false)
        {
            if (spawnDistance > g_ESPDistance)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldSpaceToScreenSpace(spawnX, spawnY, spawnZ, screenX, screenY);
        if (result == true)
        {
            auto spawnType = EQ_GetSpawnType(spawn);

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (EQAPP_String_Contains(spawnName, "`s Mount") == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                if (EQAPP_String_Contains(spawnName, "Aura ") == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                if (EQAPP_String_Contains(spawnName, " Aura") == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

            auto spawnLevel = EQ_GetSpawnLevel(spawn);
            auto spawnRace = EQ_GetSpawnRace(spawn);
            auto spawnClass = EQ_GetSpawnClass(spawn);

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
                auto spawnClassIt = EQ_TABLE_CLASS_SHORT_NAME.find(spawnClass);
                if (spawnClassIt != EQ_TABLE_CLASS_SHORT_NAME.end())
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
                if (spawnLastName.size() != 0)
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
                auto spawnID = EQ_GetSpawnID(spawn);

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

        spawn = EQ_GetSpawnNext(spawn);
    }
}
