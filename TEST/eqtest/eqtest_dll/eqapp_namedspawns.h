#pragma once

bool g_NamedSpawnsIsEnabled = true;

bool g_NamedSpawnsTextIsEnabled = true;

fmt::MemoryWriter g_NamedSpawnsText;

uint32_t g_NamedSpawnsTextXDefault = 400;
uint32_t g_NamedSpawnsTextYDefault = 10;

uint32_t g_NamedSpawnsTextX = g_NamedSpawnsTextXDefault;
uint32_t g_NamedSpawnsTextY = g_NamedSpawnsTextYDefault;

std::vector<std::string> g_NamedSpawnsList;
uint32_t g_NamedSpawnsList_reserve = 1024;

////std::unordered_map<std::string, uint32_t> g_NamedSpawnsUpList; // <spawnName, count>

std::vector<uint32_t> g_NamedSpawnsIDList;

EQApp::Timer g_NamedSpawnsIDTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NamedSpawnsIDTimerInterval = 3;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_On();
void EQAPP_NamedSpawns_Off();
void EQAPP_NamedSpawns_Load();
void EQAPP_NamedSpawns_Execute();
void EQAPP_NamedSpawns_DrawText();
void EQAPP_NamedSpawns_PrintList();
void EQAPP_NamedSpawns_PrintUp();
void EQAPP_NamedSpawns_UpdateIDList();
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

void EQAPP_NamedSpawns_Execute()
{
    EQAPP_NamedSpawns_UpdateIDList();

    EQAPP_NamedSpawns_DrawText();
}

void EQAPP_NamedSpawns_DrawText()
{
    if (g_NamedSpawnsTextIsEnabled == false)
    {
        return;
    }

    if (g_NamedSpawnsIDList.size() == 0)
    {
        return;
    }

    g_NamedSpawnsText.clear();

    g_NamedSpawnsTextX = g_NamedSpawnsTextXDefault;
    g_NamedSpawnsTextY = g_NamedSpawnsTextYDefault;

    g_NamedSpawnsText << "Named Spawns:\n";

    for (auto& spawnID : g_NamedSpawnsIDList)
    {
        auto spawn = EQ_GetSpawnByID(spawnID);
        if (spawn == NULL)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() == 0)
        {
            continue;
        }

        for (auto& namedSpawnName : g_NamedSpawnsList)
        {
            if (namedSpawnName.size() == 0)
            {
                continue;
            }

            if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
            {
                g_NamedSpawnsText << spawnName << "\n";

                break;
            }
        }
    }

    EQ_DrawText(g_NamedSpawnsText.c_str(), g_NamedSpawnsTextX, g_NamedSpawnsTextY);
}

void EQAPP_NamedSpawns_PrintList()
{
    std::cout << "Named Spawns List:" << std::endl;

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        std::cout << namedSpawnName << std::endl;
    }
}

void EQAPP_NamedSpawns_PrintUp()
{
    std::cout << "Named Spawns up:" << std::endl;

    for (auto& spawnID : g_NamedSpawnsIDList)
    {
        auto spawn = EQ_GetSpawnByID(spawnID);
        if (spawn == NULL)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() == 0)
        {
            continue;
        }

        for (auto& namedSpawnName : g_NamedSpawnsList)
        {
            if (namedSpawnName.size() == 0)
            {
                continue;
            }

            if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
            {
                std::cout << spawnName << " is up!" << std::endl;

                break;
            }
        }
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
            std::cout << "Named Spawns: " << spawnName << " has spawned." << std::endl;

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
            std::cout << "Named Spawns: " << spawnName << " has despawned." << std::endl;

            break;
        }
    }
}

void EQAPP_NamedSpawns_UpdateIDList()
{
    if (EQAPP_Timer_HasTimeElapsed(g_NamedSpawnsIDTimer, g_NamedSpawnsIDTimerInterval) == false)
    {
        return;
    }

    g_NamedSpawnsIDList.clear();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType != EQ_SPAWN_TYPE_NPC)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);

        for (auto& namedSpawnName : g_NamedSpawnsList)
        {
            if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
            {
                auto spawnID = EQ_GetSpawnID(spawn);

                g_NamedSpawnsIDList.push_back(spawnID);

                break;
            }
        }

        spawn = EQ_GetSpawnNext(spawn);
    }
}
