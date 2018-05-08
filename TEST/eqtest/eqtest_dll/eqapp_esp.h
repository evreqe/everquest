#pragma once

#include "eqapp_spawncastspell.h"

bool g_ESPIsEnabled = false;

bool g_ESPHeightFilterIsEnabled = false;

float g_ESPHeightFilterDistanceLow  = 10.0f;
float g_ESPHeightFilterDistanceHigh = 10.0f;

bool g_ESPShowSpawnIDIsEnabled = false;
bool g_ESPShowSpawnRaceIsEnabled = false;
bool g_ESPShowSpawnClassIsEnabled = false;

float g_ESPDistance = 400.0f;

std::string g_ESPFindSpawnName;
std::string g_ESPFindSpawnLastName;

uint32_t g_ESPFindSpawnLevel = 0;
uint32_t g_ESPFindSpawnType = EQ_SPAWN_TYPE_UNKNOWN;
uint32_t g_ESPFindSpawnRace = EQ_RACE_UNKNOWN;
uint32_t g_ESPFindSpawnClass = EQ_CLASS_UNKNOWN;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_On();
void EQAPP_ESP_Off();
void EQAPP_ESP_HeightFilter_Toggle();
void EQAPP_ESP_ShowSpawnID_Toggle();
void EQAPP_ESP_ShowSpawnRace_Toggle();
void EQAPP_ESP_ShowSpawnClass_Toggle();
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

void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnIDIsEnabled);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnIDIsEnabled);
}

void EQAPP_ESP_ShowSpawnRace_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnRaceIsEnabled);
    EQAPP_PrintBool("ESP Show Spawn Race", g_ESPShowSpawnRaceIsEnabled);
}

void EQAPP_ESP_ShowSpawnClass_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnClassIsEnabled);
    EQAPP_PrintBool("ESP Show Spawn Class", g_ESPShowSpawnClassIsEnabled);
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

        std::string spawnName = EQ_GetSpawnName(spawn);
        std::string spawnLastName = EQ_GetSpawnLastName(spawn);

        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);
        auto spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, spawnY, spawnX);

        auto spawnType = EQ_GetSpawnType(spawn);
        auto spawnLevel = EQ_GetSpawnLevel(spawn);
        auto spawnRace = EQ_GetSpawnRace(spawn);
        auto spawnClass = EQ_GetSpawnClass(spawn);

        bool bIgnoreDistance = false;

        if (g_ESPFindSpawnName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnName, g_ESPFindSpawnName) == true)
            {
                bIgnoreDistance = true;
            }
        }

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnLastName, g_ESPFindSpawnLastName) == true)
            {
                bIgnoreDistance = true;
            }
        }

        if (g_ESPFindSpawnType != EQ_SPAWN_TYPE_UNKNOWN)
        {
            if (spawnType == g_ESPFindSpawnType)
            {
                bIgnoreDistance = true;
            }
        }

        if (g_ESPFindSpawnLevel != 0)
        {
            if (spawnLevel >= g_ESPFindSpawnLevel)
            {
                bIgnoreDistance = true;
            }
        }

        if (g_ESPFindSpawnRace != EQ_RACE_UNKNOWN)
        {
            if (spawnRace == g_ESPFindSpawnRace)
            {
                bIgnoreDistance = true;
            }
        }

        if (g_ESPFindSpawnClass != EQ_CLASS_UNKNOWN)
        {
            if (spawnClass == g_ESPFindSpawnClass)
            {
                bIgnoreDistance = true;
            }
        }

        if (EQ_IsMouseLookEnabled() == false && bIgnoreDistance == false)
        {
            if (spawnDistance > g_ESPDistance)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }

            if (g_ESPHeightFilterIsEnabled == true)
            {
                if (spawnZ < playerSpawnZ)
                {
                    if ((playerSpawnZ - spawnZ) > g_ESPHeightFilterDistanceLow)
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }
                else if (spawnZ > playerSpawnZ)
                {
                    if ((spawnZ - playerSpawnZ) > g_ESPHeightFilterDistanceHigh)
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }
            }
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldSpaceToScreenSpace(spawnY, spawnX, spawnZ, screenX, screenY);
        if (result == true)
        {
            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                // skip mounts
                if (EQAPP_String_Contains(spawnName, "`s Mount") == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                // skip auras
                if (spawnRace == EQ_RACE_INVISIBLE_MAN && spawnClass == EQ_CLASS_OBJECT)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

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
                auto spawnClassName = EQ_GetClassShortNameByKey(spawnClass);
                if (spawnClassName.size() != 0)
                {
                    espText << " " << spawnClassName;
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

            if (g_ESPShowSpawnRaceIsEnabled == true)
            {
                auto spawnRace = EQ_GetSpawnRace(spawn);

                espText << "\n(Race: " << spawnRace << ")";
            }

            if (g_ESPShowSpawnClassIsEnabled == true)
            {
                auto spawnClass = EQ_GetSpawnClass(spawn);

                espText << "\n(Class: " << spawnClass << ")";
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
