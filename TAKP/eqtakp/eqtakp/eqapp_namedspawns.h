#pragma once

#include "eqapp_map.h"

bool g_namedSpawnsIsEnabled = true;

std::vector<std::string> g_namedSpawnsList;

uint32_t g_namedSpawnsX = 1200;
uint32_t g_namedSpawnsY = 4;

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

void EQAPP_NamedSpawns_Execute()
{
    std::vector<std::string> namedSpawnsList;
    std::unordered_map<std::string, uint32_t> namedSpawnsMap;

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
                namedSpawnsList.push_back(spawnName);
                break;
            }
        }

        spawn = spawn->Next;
    }

    if (namedSpawnsList.size() == 0)
    {
        return;
    }

    for (auto& name : namedSpawnsList)
    {
        auto it = namedSpawnsMap.find(name);
        if (it != namedSpawnsMap.end())
        {
            it->second++;
        }
        else
        {
            namedSpawnsMap.insert(std::make_pair(name, 1));
        }
    }

    std::stringstream drawText;

    drawText << "Named Spawns:\n";

    for (auto& it : namedSpawnsMap)
    {
        drawText << it.first;

        if (it.second > 1)
        {
            drawText << " (" << it.second << ")";
        }

        drawText << "\n";
    }

    EQ_DrawText(drawText.str().c_str(), g_namedSpawnsX, g_namedSpawnsY, EQ_TEXT_COLOR_WHITE);
}


