#pragma once

bool g_NamedSpawnsIsEnabled = true;

bool g_NamedSpawnsTextIsEnabled = true;

bool g_NamedSpawnsNewSpawnsIsEnabled = false;

std::stringstream g_NamedSpawnsText;

uint32_t g_NamedSpawnsTextXDefault = 400;
uint32_t g_NamedSpawnsTextYDefault = 10;

uint32_t g_NamedSpawnsTextX = g_NamedSpawnsTextXDefault;
uint32_t g_NamedSpawnsTextY = g_NamedSpawnsTextYDefault;

std::vector<std::string> g_NamedSpawnsList;
uint32_t g_NamedSpawnsList_reserve = 1024;

////std::unordered_map<std::string, uint32_t> g_NamedSpawnsUpList; // <spawnName, count>

std::vector<uint32_t> g_NamedSpawnsIDList;

std::unordered_map<std::string, uint32_t> g_NamedSpawnsNameAndCountList;

std::vector<uint32_t> g_NamedSpawnsNewSpawnsIDList;

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
void EQAPP_NamedSpawns_NewSpawns_Toggle();
void EQAPP_NamedSpawns_NewSpawns_On();
void EQAPP_NamedSpawns_NewSpawns_Off();
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
    g_NamedSpawnsList.clear();
    g_NamedSpawnsList.reserve(g_NamedSpawnsList_reserve);

    g_NamedSpawnsNewSpawnsIDList.clear();

    EQAPP_ReadFileToList("namedspawns.txt", g_NamedSpawnsList, false);

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    std::stringstream folderFileName;
    folderFileName << "namedspawns/" << zoneShortName << ".txt";

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), g_NamedSpawnsList, false);
    if (result == true)
    {
        std::cout << "Named Spawns loaded from file: " << folderFileName.str() << std::endl;
    }
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

    g_NamedSpawnsNameAndCountList.clear();

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
                auto it = g_NamedSpawnsNameAndCountList.find(spawnName);
                if (it != g_NamedSpawnsNameAndCountList.end())
                {
                    it->second++;
                }
                else
                {
                    g_NamedSpawnsNameAndCountList.insert( {spawnName, 1} );
                }

                break;
            }
        }
    }

    g_NamedSpawnsText.str(std::string());
    g_NamedSpawnsText.clear();

    g_NamedSpawnsTextX = g_NamedSpawnsTextXDefault;
    g_NamedSpawnsTextY = g_NamedSpawnsTextYDefault;

    g_NamedSpawnsText << "Named Spawns:\n";

    for (auto& it : g_NamedSpawnsNameAndCountList)
    {
        g_NamedSpawnsText << it.first;

        if (it.second > 1)
        {
            g_NamedSpawnsText << " (" << it.second << ")";
        }

        g_NamedSpawnsText << "\n";
    }

    EQ_DrawText(g_NamedSpawnsText.str().c_str(), g_NamedSpawnsTextX, g_NamedSpawnsTextY);
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

void EQAPP_NamedSpawns_NewSpawns_Toggle()
{
    EQ_ToggleBool(g_NamedSpawnsNewSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns New Spawns", g_NamedSpawnsNewSpawnsIsEnabled);

    if (g_NamedSpawnsNewSpawnsIsEnabled == false)
    {
        g_NamedSpawnsNewSpawnsIDList.clear();
    }
}

void EQAPP_NamedSpawns_NewSpawns_On()
{
    if (g_NamedSpawnsNewSpawnsIsEnabled == false)
    {
        EQAPP_NamedSpawns_NewSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_NewSpawns_Off()
{
    if (g_NamedSpawnsNewSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_NewSpawns_Toggle();
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

    auto spawnID = EQ_GetSpawnID(spawn);
    if (g_NamedSpawnsNewSpawnsIsEnabled == true)
    {
        bool bNewSpawn = true;

        if (EQAPP_String_EndsWith(spawnName, " mount") == true || EQAPP_String_EndsWith(spawnName, " Mount") == true)
        {
            bNewSpawn = false;
        }

        if (EQAPP_String_EndsWith(spawnName, " pet") == true || EQAPP_String_EndsWith(spawnName, " Pet") == true)
        {
            bNewSpawn = false;
        }

        std::string spawnLastName = EQ_GetSpawnLastName(spawn);
        if (spawnLastName.size() == 0)
        {
            if (EQAPP_String_EndsWith(spawnLastName, " pet") == true || EQAPP_String_EndsWith(spawnLastName, " Pet") == true)
            {
                bNewSpawn = false;
            }
        }

        if (bNewSpawn == true)
        {
            g_NamedSpawnsNewSpawnsIDList.push_back(spawnID);

            std::cout << "Named Spawns New Spawn added: " << spawnName << " (ID: " << spawnID << ")" << std::endl;
        }
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

    auto spawnID = EQ_GetSpawnID(actorApplicationData);
    if (g_NamedSpawnsNewSpawnsIsEnabled == true)
    {
        g_NamedSpawnsNewSpawnsIDList.erase
        (
            std::remove(g_NamedSpawnsNewSpawnsIDList.begin(), g_NamedSpawnsNewSpawnsIDList.end(), spawnID),
            g_NamedSpawnsNewSpawnsIDList.end()
        );

        bool bNewSpawn = true;

        if (EQAPP_String_EndsWith(spawnName, " mount") == true || EQAPP_String_EndsWith(spawnName, " Mount") == true)
        {
            bNewSpawn = false;
        }

        if (EQAPP_String_EndsWith(spawnName, " pet") == true || EQAPP_String_EndsWith(spawnName, " Pet") == true)
        {
            bNewSpawn = false;
        }

        std::string spawnLastName = EQ_GetSpawnLastName(actorApplicationData);
        if (spawnLastName.size() == 0)
        {
            if (EQAPP_String_EndsWith(spawnLastName, " pet") == true || EQAPP_String_EndsWith(spawnLastName, " Pet") == true)
            {
                bNewSpawn = false;
            }
        }

        if (bNewSpawn == true)
        {
            std::cout << "Named Spawns New Spawn removed: " << spawnName << " (ID: " << spawnID << ")" << std::endl;
        }
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
