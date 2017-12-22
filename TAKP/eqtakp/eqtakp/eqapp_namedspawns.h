#pragma once

#include "eqapp_map.h"

bool g_NamedSpawnsIsEnabled = true;

std::vector<std::string> g_NamedSpawnsList;

std::vector<std::string> g_NamedSpawnsInZoneList;
std::unordered_map<std::string, uint32_t> g_NamedSpawnsInZoneMap; // <spawnName, count>

std::stringstream g_NamedSpawnsDrawText;

uint32_t g_NamedSpawnsDrawTextX = 1200;
uint32_t g_NamedSpawnsDrawTextY = 4;

uint32_t g_NamedSpawnsTimer = 0;
uint32_t g_NamedSpawnsTimerDelay = 1000;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_Load();

void EQAPP_NamedSpawns_Toggle()
{
    EQ_ToggleBool(g_NamedSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns", g_NamedSpawnsIsEnabled);
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

    g_NamedSpawnsList.clear();
    g_NamedSpawnsList.reserve(100);

    EQAPP_ReadFileToList("namedspawns.txt", g_NamedSpawnsList);

    std::stringstream filePath;
    filePath << "namedspawns/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_NamedSpawnsList);
}

void EQAPP_NamedSpawns_Update()
{
    g_NamedSpawnsInZoneList.clear();
    g_NamedSpawnsInZoneMap.clear();

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

        for (auto& name : g_NamedSpawnsList)
        {
            if (spawnName.find(name) != std::string::npos)
            {
                g_NamedSpawnsInZoneList.push_back(spawnName);
                break;
            }
        }

        spawn = spawn->Next;
    }

    if (g_NamedSpawnsInZoneList.size() == 0)
    {
        return;
    }

    for (auto& name : g_NamedSpawnsInZoneList)
    {
        auto it = g_NamedSpawnsInZoneMap.find(name);
        if (it != g_NamedSpawnsInZoneMap.end())
        {
            it->second++;
        }
        else
        {
            g_NamedSpawnsInZoneMap.insert(std::make_pair(name, 1));
        }
    }

    g_NamedSpawnsDrawText.str(std::string());
    g_NamedSpawnsDrawText.clear();

    g_NamedSpawnsDrawText << "Named Spawns:\n";

    for (auto& it : g_NamedSpawnsInZoneMap)
    {
        g_NamedSpawnsDrawText << it.first;

        if (it.second > 1)
        {
            g_NamedSpawnsDrawText << " (" << it.second << ")";
        }

        g_NamedSpawnsDrawText << "\n";
    }
}

void EQAPP_NamedSpawns_Execute()
{
    if (EQ_HasTimePassed(g_NamedSpawnsTimer, g_NamedSpawnsTimerDelay) == true)
    {
        EQAPP_NamedSpawns_Update();
    }

    if (g_NamedSpawnsInZoneMap.size() == 0)
    {
        return;
    }

    EQ_DrawText(g_NamedSpawnsDrawText.str().c_str(), g_NamedSpawnsDrawTextX, g_NamedSpawnsDrawTextY, EQ_COLOR_ARGB_WHITE);
}


