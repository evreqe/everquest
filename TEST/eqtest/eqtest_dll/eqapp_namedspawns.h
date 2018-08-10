#pragma once

bool g_NamedSpawnsIsEnabled = true;

std::vector<std::string> g_NamedSpawnsList;
uint32_t g_NamedSpawnsList_reserve = 1024;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_On();
void EQAPP_NamedSpawns_Off();
void EQAPP_NamedSpawns_Load();
void EQAPP_NamedSpawns_PrintList();
void EQAPP_NamedSpawns_HandleEvent_CDisplay__CreatePlayerActor(void* this_ptr, uint32_t spawn);
void EQAPP_NamedSpawns_HandleEvent_CDisplay__DeleteActor(void* this_ptr, uint32_t cactor);

void EQAPP_NamedSpawns_Toggle()
{
    EQ_ToggleBool(g_NamedSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns", g_NamedSpawnsIsEnabled);
}

void EQAPP_NamedSpawns_On()
{
    if (g_NamedSpawnsIsEnabled == false)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_Off()
{
    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_Load()
{
    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    g_NamedSpawnsList.clear();
    g_NamedSpawnsList.reserve(g_NamedSpawnsList_reserve);

    EQAPP_ReadFileToList("namedspawns.txt", g_NamedSpawnsList, false);

    std::stringstream folderFileName;
    folderFileName << "namedspawns/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(folderFileName.str().c_str(), g_NamedSpawnsList, false);
}

void EQAPP_NamedSpawns_PrintList()
{
    std::cout << "Named Spawns List:" << std::endl;

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        std::cout << namedSpawnName << std::endl;
    }
}

void EQAPP_NamedSpawns_HandleEvent_CDisplay__CreatePlayerActor(void* this_ptr, uint32_t spawn)
{
    if (spawn == NULL)
    {
        return;
    }

    auto spawnType = EQ_GetSpawnType(spawn);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
        {
            std::cout << spawnName << " has spawned." << std::endl;

            break;
        }
    }
}

void EQAPP_NamedSpawns_HandleEvent_CDisplay__DeleteActor(void* this_ptr, uint32_t cactor)
{
    if (cactor == NULL)
    {
        return;
    }

    auto actorType = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_TYPE);
    if (actorType != EQ_ACTOR_TYPE_PLAYER)
    {
        return;
    }

    auto actorApplicationData = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_APPLICATION_DATA);
    if (actorApplicationData == NULL)
    {
        return;
    }

    auto spawnType = EQ_GetSpawnType(actorApplicationData);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(actorApplicationData);
    if (spawnName.size() == 0)
    {
        return;
    }

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
        {
            std::cout << spawnName << " has despawned." << std::endl;

            break;
        }
    }
}
