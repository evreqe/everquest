#pragma once

bool g_NamedSpawnsIsEnabled = true;

bool g_NamedSpawnsTextIsEnabled = true;

bool g_NamedSpawnsNewSpawnsIsEnabled = false;

std::stringstream g_NamedSpawnsText;

uint32_t g_NamedSpawnsTextXDefault = 400;
uint32_t g_NamedSpawnsTextYDefault = 20;

uint32_t g_NamedSpawnsTextX = g_NamedSpawnsTextXDefault;
uint32_t g_NamedSpawnsTextY = g_NamedSpawnsTextYDefault;

std::vector<std::string> g_NamedSpawnsList;
uint32_t g_NamedSpawnsList_reserve = 1024;

////std::unordered_map<std::string, uint32_t> g_NamedSpawnsUpList; // <spawnName, count>

std::vector<uint32_t> g_NamedSpawnsIDList;

std::unordered_map<std::string, uint32_t> g_NamedSpawnsNameAndCountList;

std::vector<uint32_t> g_NamedSpawnsNewSpawnsIDList;

std::vector<uint32_t> g_NamedSpawnsSpecialSpawnsIDList;

EQApp::Timer g_NamedSpawnsIDTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NamedSpawnsIDTimerInterval = 3;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_On();
void EQAPP_NamedSpawns_Off();
void EQAPP_NamedSpawns_Load();
void EQAPP_NamedSpawns_Execute();
void EQAPP_NamedSpawns_DrawText();
void EQAPP_NamedSpawns_PrintList();
void EQAPP_NamedSpawns_PrintIDList();
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

    g_NamedSpawnsSpecialSpawnsIDList.clear();

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
        std::cout << "Named Spawns loaded from file: " << folderFileName.str() << "\n";
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

    if (g_NamedSpawnsIDList.size() == 0 && g_NamedSpawnsSpecialSpawnsIDList.size() == 0)
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

        auto g_NamedSpawnsNameAndCountList_it = g_NamedSpawnsNameAndCountList.find(spawnName);
        if (g_NamedSpawnsNameAndCountList_it != g_NamedSpawnsNameAndCountList.end())
        {
            g_NamedSpawnsNameAndCountList_it->second++;
        }
        else
        {
            g_NamedSpawnsNameAndCountList.insert( {spawnName, 1} );
        }
    }

    for (auto& spawnID : g_NamedSpawnsSpecialSpawnsIDList)
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

        auto g_NamedSpawnsNameAndCountList_it = g_NamedSpawnsNameAndCountList.find(spawnName);
        if (g_NamedSpawnsNameAndCountList_it != g_NamedSpawnsNameAndCountList.end())
        {
            g_NamedSpawnsNameAndCountList_it->second++;
        }
        else
        {
            g_NamedSpawnsNameAndCountList.insert( {spawnName, 1} );
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
    std::cout << "Named Spawns List:" << "\n";

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        std::cout << namedSpawnName << "\n";
    }
}

void EQAPP_NamedSpawns_PrintIDList()
{
    std::cout << "Named Spawns ID List:" << "\n";

    for (auto& namedSpawnID : g_NamedSpawnsIDList)
    {
        std::cout << namedSpawnID << "\n";
    }
}


void EQAPP_NamedSpawns_PrintUp()
{
    std::cout << "Named Spawns Up:" << "\n";

    for (auto& spawnID : g_NamedSpawnsIDList)
    {
        //std::cout << "spawnID == " << spawnID << "\n";

        auto spawn = EQ_GetSpawnByID(spawnID);
        if (spawn == NULL)
        {
            //std::cout << "spawn == NULL\n";
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() == 0)
        {
            //std::cout << "spawnName.size() == 0\n";
            continue;
        }

        //std::cout << "spawnName == " << spawnName << "\n";

        for (auto& namedSpawnName : g_NamedSpawnsList)
        {
            if (namedSpawnName.size() == 0)
            {
                //std::cout << "namedSpawnName.size() == 0\n";
                continue;
            }

            if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
            {
                std::cout << spawnName << " is up!" << "\n";

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
        if (spawnName.size() == 0)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        for (auto& namedSpawnName : g_NamedSpawnsList)
        {
            if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
            {
                auto spawnID = EQ_GetSpawnID(spawn);

                g_NamedSpawnsIDList.push_back(spawnID);

                break;
            }
        }

        // Eldrig the Old
        auto zoneID = EQ_GetZoneID();
        if (zoneID == EQ_ZONE_ID_SKYFIRE)
        {
            if
            (
                EQ_IsSpawnWithinDistanceOfLocation(spawn, 1770, -3850, -167, 400.0f) == true ||
                EQ_IsSpawnWithinDistanceOfLocation(spawn, 550,  -4085, -159, 400.0f) == true
            )
            {
                auto spawnID = EQ_GetSpawnID(spawn);

                g_NamedSpawnsSpecialSpawnsIDList.push_back(spawnID);
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

    auto zoneID = EQ_GetZoneID();

    // Eldrig the Old
    if (zoneID == EQ_ZONE_ID_SKYFIRE)
    {
        if
        (
            EQ_IsSpawnWithinDistanceOfLocation(spawn, 1770, -3850, -167, 400.0f) == true ||
            EQ_IsSpawnWithinDistanceOfLocation(spawn, 550,  -4085, -159, 400.0f) == true
        )
        {
            std::cout << "Eldrig the Old placeholder or named has spawned!" << "\n";

            auto spawnID = EQ_GetSpawnID(spawn);

            g_NamedSpawnsSpecialSpawnsIDList.push_back(spawnID);
        }
    }

    // Quillmane
    if (zoneID == EQ_ZONE_ID_SOUTHKARANA)
    {
        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);

        int numVertices = 4;
        float verticesX[] = { 3318.0f, -3783.0f, -3733.0f,  3303.0f};
        float verticesY[] = {-2752.0f, -2752.0f, -6809.0f, -6818.0f};

        if (EQ_IsPointInsidePolygon(spawnX, spawnY, numVertices, verticesX, verticesY) == true)
        {
            auto spawnID = EQ_GetSpawnID(spawn);

            g_NamedSpawnsSpecialSpawnsIDList.push_back(spawnID);

            std::cout << spawnName << " spawned in the Quillmane rectangle!" << "\n";
        }
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

            std::cout << "Named Spawns New Spawn added: " << spawnName << " (ID: " << spawnID << ")" << "\n";
        }
    }

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
        {
            std::cout << "Named Spawns: " << spawnName << " has spawned." << "\n";

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

    g_NamedSpawnsSpecialSpawnsIDList.erase
    (
        std::remove(g_NamedSpawnsSpecialSpawnsIDList.begin(), g_NamedSpawnsSpecialSpawnsIDList.end(), spawnID),
        g_NamedSpawnsSpecialSpawnsIDList.end()
    );

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
            std::cout << "Named Spawns New Spawn removed: " << spawnName << " (ID: " << spawnID << ")" << "\n";
        }
    }

    for (auto& namedSpawnName : g_NamedSpawnsList)
    {
        if (EQAPP_String_Contains(spawnName, namedSpawnName) == true)
        {
            std::cout << "Named Spawns: " << spawnName << " has despawned." << "\n";

            break;
        }
    }
}
