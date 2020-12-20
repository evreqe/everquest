#pragma once

extern uint32_t g_FollowAISpawn;
extern void EQAPP_FollowAI_SetFollowSpawn(uint32_t spawn);
extern void EQAPP_FollowAI_StopFollow();

bool g_KillMobsIsEnabled = false;

EQApp::Timer g_KillMobsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_KillMobsTimerInterval = 1;

float g_KillMobsDistance = 400.0f;

std::vector<std::string> g_KillMobsList;
uint32_t g_KillMobsList_reserve = 1024;

bool g_KillMobsMaxPlayersIsEnabled = true;
uint32_t g_KillMobsMaxPlayersInZone = 2;

void EQAPP_KillMobs_Toggle();
void EQAPP_KillMobs_On();
void EQAPP_KillMobs_Off();
void EQAPP_KillMobs_Load();
void EQAPP_KillMobs_Execute();
bool EQAPP_KillMobs_IsSpawnSafeToKill(uint32_t spawn);
bool EQAPP_KillMobs_IsSpawnInHillGiantRectangle(uint32_t spawn);
bool EQAPP_KillMobs_IsSpawnInSarnakCourierRectangle(uint32_t spawn);
void EQAPP_KillMobs_MaxPlayers_Toggle();
void EQAPP_KillMobs_MaxPlayers_On();
void EQAPP_KillMobs_MaxPlayers_Off();

void EQAPP_KillMobs_Toggle()
{
    EQ_ToggleBool(g_KillMobsIsEnabled);
    EQAPP_PrintBool("Kill Mobs", g_KillMobsIsEnabled);

    EQ_ClearTarget();

    if (g_KillMobsIsEnabled == false)
    {
        EQAPP_FollowAI_StopFollow();

        EQ_SetAutoAttack(false);
    }
}

void EQAPP_KillMobs_On()
{
    if (g_KillMobsIsEnabled == false)
    {
        EQAPP_KillMobs_Toggle();
    }
}

void EQAPP_KillMobs_Off()
{
    if (g_KillMobsIsEnabled == true)
    {
        EQAPP_KillMobs_Toggle();
    }
}

void EQAPP_KillMobs_Load()
{
    g_KillMobsList.clear();
    g_KillMobsList.reserve(g_KillMobsList_reserve);

    EQAPP_ReadFileToList("killmobs.txt", g_KillMobsList, false);

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zoneShortName is empty");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        std::string playerName = EQ_GetSpawnName(playerSpawn);
        if (playerName.size() != 0)
        {
            std::stringstream folderFileName;
            folderFileName << "killmobs/" << zoneShortName << "_" << playerName << ".txt";

            bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), g_KillMobsList, false);
            if (result == true)
            {
                std::cout << "Kill Mobs loaded from file: " << folderFileName.str() << "\n";
                return;
            }
        }
    }

    std::stringstream folderFileName;
    folderFileName << "killmobs/" << zoneShortName << ".txt";

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), g_KillMobsList, false);
    if (result == true)
    {
        std::cout << "Kill Mobs loaded from file: " << folderFileName.str() << "\n";
    }
}

void EQAPP_KillMobs_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_KillMobsTimer, g_KillMobsTimerInterval) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    auto zoneID = EQ_GetZoneID();

    auto numPlayersInZone = EQ_GetNumSpawnsInZone(EQ_SPAWN_TYPE_PLAYER);

    auto numNearbyPlayers = EQ_GetNumNearbySpawns(EQ_SPAWN_TYPE_PLAYER, 100.0f, 10.0f);

    auto targetSpawn = EQ_GetTargetSpawn();

/*
    if (g_KillMobsMaxPlayersIsEnabled == true)
    {
        if (targetSpawn == NULL)
        {
            auto numPlayersInZone = EQ_GetNumSpawnsInZone(EQ_SPAWN_TYPE_PLAYER);
            if (numPlayersInZone > g_KillMobsMaxPlayersInZone)
            {
                g_FollowAISpawn = NULL;
                EQ_SetAutoRun(false);

                EQ_ClearTarget();

                return;
            }
        }
    }
*/

    if (targetSpawn != NULL)
    {
        auto targetType = EQ_GetSpawnType(targetSpawn);
        if (targetType != EQ_SPAWN_TYPE_NPC)
        {
            g_FollowAISpawn = NULL;
            EQ_SetAutoRun(false);

            EQ_ClearTarget();

            return;
        }

        std::string targetName = EQ_GetSpawnName(targetSpawn);
        if (targetName.size() != 0)
        {
            std::string targetName2 = "*" + targetName;

            auto it = std::find(g_KillMobsList.begin(), g_KillMobsList.end(), targetName);
            auto it2 = std::find(g_KillMobsList.begin(), g_KillMobsList.end(), targetName2);

            if (it == g_KillMobsList.end() && it2 == g_KillMobsList.end())
            {
                g_FollowAISpawn = NULL;
                EQ_SetAutoRun(false);

                EQ_ClearTarget();

                return;
            }
        }
    }

    if (targetSpawn == NULL && g_FollowAISpawn != NULL)
    {
        auto followSpawnType = EQ_GetSpawnType(g_FollowAISpawn);
        if (followSpawnType == EQ_SPAWN_TYPE_NPC)
        {
            if (zoneID == EQ_ZONE_ID_LAKEOFILLOMEN)
            {
                std::string followSpawnName = EQ_GetSpawnName(g_FollowAISpawn);
                if (followSpawnName.size() != 0)
                {
                    if (EQAPP_String_Contains(followSpawnName, "sarnak courier") == false)
                    {
                        if (EQAPP_KillMobs_IsSpawnInSarnakCourierRectangle(g_FollowAISpawn) == false)
                        {
                            g_FollowAISpawn = NULL;
                            EQ_SetAutoRun(false);

                            return;
                        }
                    }
                }
            }

            if (zoneID == EQ_ZONE_ID_RATHEMTN)
            {
                if (EQAPP_KillMobs_IsSpawnInHillGiantRectangle(g_FollowAISpawn) == false)
                {
                    g_FollowAISpawn = NULL;
                    EQ_SetAutoRun(false);

                    return;
                }
            }

            if (EQAPP_KillMobs_IsSpawnSafeToKill(g_FollowAISpawn) == false)
            {
                g_FollowAISpawn = NULL;
                EQ_SetAutoRun(false);

                std::cout << "Kill Mob skipping followed spawn because it is NOT safe to kill." << "\n";
                return;
            }

            if (EQ_IsSpawnWithinDistance(g_FollowAISpawn, g_KillMobsDistance) == true)
            {
                EQ_SetTargetSpawn(g_FollowAISpawn);
                return;
            }
        }
        else
        {
            g_FollowAISpawn = NULL;
            EQ_SetAutoRun(false);

            return;
        }
    }

    targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL && g_FollowAISpawn == NULL)
    {
        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance(false);

        if (numNearbyPlayers > 0)
        {
            EQAPP_RandomizeList(spawnIDList);
        }

        for (auto& spawnID : spawnIDList)
        {
            auto spawn = EQ_GetSpawnByID(spawnID);
            if (spawn == NULL)
            {
                continue;
            }

            auto spawnType = EQ_GetSpawnType(spawn);
            if (spawnType != EQ_SPAWN_TYPE_NPC)
            {
                continue;
            }

            std::string spawnName = EQ_GetSpawnName(spawn);
            if (spawnName.size() == 0)
            {
                continue;
            }

            if (zoneID == EQ_ZONE_ID_LAKEOFILLOMEN)
            {
                if (EQAPP_String_Contains(spawnName, "sarnak courier") == false)
                {
                    if (EQAPP_KillMobs_IsSpawnInSarnakCourierRectangle(spawn) == false)
                    {
                        EQ_ClearTarget();

                        continue;
                    }
                }
            }

            if (zoneID == EQ_ZONE_ID_RATHEMTN)
            {
                if (EQAPP_KillMobs_IsSpawnInHillGiantRectangle(spawn) == false)
                {
                    EQ_ClearTarget();

                    continue;
                }
            }

            if (EQAPP_KillMobs_IsSpawnSafeToKill(spawn) == false)
            {
                EQ_ClearTarget();

                std::cout << "Kill Mob skipping '" << spawnName << "' because it is NOT safe to kill." << "\n";
                continue;
            }

            for (auto& killMobsName : g_KillMobsList)
            {
                if (g_KillMobsMaxPlayersIsEnabled == true)
                {
                    if (numPlayersInZone > g_KillMobsMaxPlayersInZone)
                    {
                        if (zoneID == EQ_ZONE_ID_NORTHKARANA)
                        {
                            if (EQAPP_String_Contains(killMobsName, "a highland lion") == false)
                            {
                                continue;
                            }
                        }
                    }
                }

                if (EQAPP_String_BeginsWith(killMobsName, "*") == true)
                {
                    std::string killSpawnName = killMobsName;

                    killSpawnName.erase(0, 1);

                    if (spawnName == killSpawnName)
                    {
                        if (EQ_IsSpawnWithinDistance(spawn, g_KillMobsDistance) == true)
                        {
                            EQ_SetTargetSpawn(spawn);
                        }

                        EQAPP_FollowAI_SetFollowSpawn(spawn);
                        EQ_SetAutoRun(true);

                        EQ_SetAutoAttack(true);

                        std::cout << "Kill Mob Name: " << killMobsName << "\n";

                        return;
                    }
                }
            }
        }
    }

    targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL && g_FollowAISpawn == NULL)
    {
        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance(false);

        if (numNearbyPlayers > 0)
        {
            EQAPP_RandomizeList(spawnIDList);
        }

        for (auto& spawnID : spawnIDList)
        {
            auto spawn = EQ_GetSpawnByID(spawnID);
            if (spawn == NULL)
            {
                continue;
            }

            auto spawnType = EQ_GetSpawnType(spawn);
            if (spawnType != EQ_SPAWN_TYPE_NPC)
            {
                continue;
            }

            std::string spawnName = EQ_GetSpawnName(spawn);
            if (spawnName.size() == 0)
            {
                continue;
            }

            if (zoneID == EQ_ZONE_ID_LAKEOFILLOMEN)
            {
                if (EQAPP_String_Contains(spawnName, "sarnak courier") == false)
                {
                    if (EQAPP_KillMobs_IsSpawnInSarnakCourierRectangle(spawn) == false)
                    {
                        EQ_ClearTarget();

                        continue;
                    }
                }
            }

            if (zoneID == EQ_ZONE_ID_RATHEMTN)
            {
                if (EQAPP_KillMobs_IsSpawnInHillGiantRectangle(spawn) == false)
                {
                    EQ_ClearTarget();

                    continue;
                }
            }

            if (EQAPP_KillMobs_IsSpawnSafeToKill(spawn) == false)
            {
                EQ_ClearTarget();

                std::cout << "Kill Mob skipping '" << spawnName << "' because it is NOT safe to kill." << "\n";
                continue;
            }

            for (auto& killMobsName : g_KillMobsList)
            {
                if (g_KillMobsMaxPlayersIsEnabled == true)
                {
                    if (numPlayersInZone > g_KillMobsMaxPlayersInZone)
                    {
                        if (zoneID == EQ_ZONE_ID_NORTHKARANA)
                        {
                            if (EQAPP_String_Contains(killMobsName, "a highland lion") == false)
                            {
                                continue;
                            }
                        }
                    }
                }

                if (spawnName == killMobsName)
                {
                    if (EQ_IsSpawnWithinDistance(spawn, g_KillMobsDistance) == true)
                    {
                        EQ_SetTargetSpawn(spawn);
                    }

                    EQAPP_FollowAI_SetFollowSpawn(spawn);
                    EQ_SetAutoRun(true);

                    EQ_SetAutoAttack(true);

                    std::cout << "Kill Mob Name: " << killMobsName << "\n";

                    return;
                }
            }
        }
    }

    targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL && g_FollowAISpawn == NULL)
    {
        EQ_SetAutoRun(false);

        EQ_SetAutoAttack(false);
    }
}

bool EQAPP_KillMobs_IsSpawnSafeToKill(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return false;
    }

    auto spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return false;
    }

    auto zoneID = EQ_GetZoneID();
    if (zoneID == EQ_ZONE_ID_NORTHKARANA)
    {
        if (spawnName == "a willowisp")
        {
            auto kosSpawn = EQ_GetSpawnByName("Sir Gerwin Thunderblade");
            if (kosSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (EQ_IsSpawnWithinDistanceOfSpawn(playerSpawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }

                if (EQ_IsSpawnWithinDistanceOfSpawn(spawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }
            }
        }

        if (spawnName != "a highland lion")
        {
            uint32_t kosSpawn = NULL;

            kosSpawn = EQ_GetSpawnByName("Brianna Treewhisper");
            if (kosSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (EQ_IsSpawnWithinDistanceOfSpawn(playerSpawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }

                if (EQ_IsSpawnWithinDistanceOfSpawn(spawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }
            }

            kosSpawn = EQ_GetSpawnByName("Tak Whistler");
            if (kosSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (EQ_IsSpawnWithinDistanceOfSpawn(playerSpawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }

                if (EQ_IsSpawnWithinDistanceOfSpawn(spawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }
            }

            kosSpawn = EQ_GetSpawnByName("a druid");
            if (kosSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (EQ_IsSpawnWithinDistanceOfSpawn(playerSpawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }

                if (EQ_IsSpawnWithinDistanceOfSpawn(spawn, kosSpawn, 1000.0f) == true)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool EQAPP_KillMobs_IsSpawnInHillGiantRectangle(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return false;
    }

    auto zoneID = EQ_GetZoneID();
    if (zoneID != EQ_ZONE_ID_RATHEMTN)
    {
        return false;
    }

    float spawnY = EQ_GetSpawnY(spawn);
    float spawnX = EQ_GetSpawnX(spawn);

    int numVertices = 4;
    float verticesX[] = {-510.0f, -508.0f, -2408.0f, -2243.0f};
    float verticesY[] = {3674.0f, 2505.0f,  2650.0f,  3726.0f};

    if (EQ_IsPointInsidePolygon(spawnX, spawnY, numVertices, verticesX, verticesY) == true)
    {
        return true;
    }

    return false;
}

bool EQAPP_KillMobs_IsSpawnInSarnakCourierRectangle(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return false;
    }

    auto zoneID = EQ_GetZoneID();
    if (zoneID != EQ_ZONE_ID_LAKEOFILLOMEN)
    {
        return false;
    }

    float spawnY = EQ_GetSpawnY(spawn);
    float spawnX = EQ_GetSpawnX(spawn);

    int numVertices = 4;
    float verticesX[] = {-3688.0f, -3688.0f, -700.0f, -785.0f};
    float verticesY[] = {-3657.0f,   105.0f,  520.0f, -3915.0f};

    if (EQ_IsPointInsidePolygon(spawnX, spawnY, numVertices, verticesX, verticesY) == 1)
    {
        return true;
    }

    return false;
}

void EQAPP_KillMobs_MaxPlayers_Toggle()
{
    EQ_ToggleBool(g_KillMobsMaxPlayersIsEnabled);
    EQAPP_PrintBool("Kill Mobs Max Players In Zone", g_KillMobsMaxPlayersIsEnabled);
}

void EQAPP_KillMobs_MaxPlayers_On()
{
    if (g_KillMobsMaxPlayersIsEnabled == false)
    {
        EQAPP_KillMobs_MaxPlayers_Toggle();
    }
}

void EQAPP_KillMobs_MaxPlayers_Off()
{
    if (g_KillMobsMaxPlayersIsEnabled == true)
    {
        EQAPP_KillMobs_MaxPlayers_Toggle();
    }
}

