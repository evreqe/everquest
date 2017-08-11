#pragma once

#include "eqapp_map.h"

bool g_namedSpawnsIsEnabled = true;

std::vector<std::string> g_namedSpawnsList;

std::vector<std::string> g_namedSpawnsInZoneList;
std::unordered_map<std::string, uint32_t> g_namedSpawnsInZoneMap; // spawnName, count

std::stringstream g_namedSpawnsDrawText;

uint32_t g_namedSpawnsX = 1200;
uint32_t g_namedSpawnsY = 4;

uint32_t g_namedSpawnsTimer = 0;
uint32_t g_namedSpawnsTimerDelay = 1000;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_Load();

void EQAPP_NamedSpawns_Toggle()
{
    EQ_ToggleBool(g_namedSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns", g_namedSpawnsIsEnabled);
}

void EQAPP_NamedSpawns_Load()
{
    std::cout << "Loading Named Spawns..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_namedSpawnsList.clear();

    EQAPP_ReadFileToList("namedspawns.txt", g_namedSpawnsList);

    std::stringstream filePath;
    filePath << "namedspawns/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_namedSpawnsList);
}

void EQAPP_NamedSpawns_Update()
{
    g_namedSpawnsInZoneList.clear();
    g_namedSpawnsInZoneMap.clear();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        std::string spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() == 0)
        {
            spawn = spawn->Next;
            continue;
        }

        if (spawn->Type != EQ_SPAWN_TYPE_NPC)
        {
            spawn = spawn->Next;
            continue;
        }

        for (auto& name : g_namedSpawnsList)
        {
            if (spawnName.find(name) != std::string::npos)
            {
                g_namedSpawnsInZoneList.push_back(spawnName);
                break;
            }
        }

        spawn = spawn->Next;
    }

    if (g_namedSpawnsInZoneList.size() == 0)
    {
        return;
    }

    for (auto& name : g_namedSpawnsInZoneList)
    {
        auto it = g_namedSpawnsInZoneMap.find(name);
        if (it != g_namedSpawnsInZoneMap.end())
        {
            it->second++;
        }
        else
        {
            g_namedSpawnsInZoneMap.insert(std::make_pair(name, 1));
        }
    }

    g_namedSpawnsDrawText.str(std::string());
    g_namedSpawnsDrawText.clear();

    g_namedSpawnsDrawText << "Named Spawns:\n";

    for (auto& it : g_namedSpawnsInZoneMap)
    {
        g_namedSpawnsDrawText << it.first;

        if (it.second > 1)
        {
            g_namedSpawnsDrawText << " (" << it.second << ")";
        }

        g_namedSpawnsDrawText << "\n";
    }
}

void EQAPP_NamedSpawns_Execute()
{
    if (EQ_HasTimePassed(g_namedSpawnsTimer, g_namedSpawnsTimerDelay) == true)
    {
        EQAPP_NamedSpawns_Update();
    }

    if (g_namedSpawnsInZoneMap.size() == 0)
    {
        return;
    }

    EQ_DrawText(g_namedSpawnsDrawText.str().c_str(), g_namedSpawnsX, g_namedSpawnsY, EQ_TEXT_COLOR_WHITE);
}


