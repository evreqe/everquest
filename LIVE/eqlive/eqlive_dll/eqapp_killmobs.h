#pragma once

#include "eqapp_followai.h"

bool g_KillMobsIsEnabled = false;

EQApp::Timer g_KillMobsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_KillMobsTimerInterval = 1;

float g_KillMobsDistance = 400.0f;

std::vector<std::string> g_KillMobsList;
uint32_t g_KillMobsList_reserve = 1024;

void EQAPP_KillMobs_Toggle();
void EQAPP_KillMobs_On();
void EQAPP_KillMobs_Off();
void EQAPP_KillMobs_Load();
void EQAPP_KillMobs_Execute();

void EQAPP_KillMobs_Toggle()
{
    EQ_ToggleBool(g_KillMobsIsEnabled);
    EQAPP_PrintBool("Kill Mobs", g_KillMobsIsEnabled);

    if (g_KillMobsIsEnabled == false)
    {
        g_FollowAISpawn = NULL;
        EQ_SetAutoRun(false);

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
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    std::stringstream folderFileName;
    folderFileName << "killmobs/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(folderFileName.str().c_str(), g_KillMobsList, false);
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

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance();

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

            for (auto& killMobsName : g_KillMobsList)
            {
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

                        g_FollowAISpawn = spawn;
                        EQ_SetAutoRun(true);

                        EQ_SetAutoAttack(true);

                        return;
                    }
                }
            }
        }
    }

    targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance();

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

            if (EQ_IsSpawnWithinDistance(spawn, g_KillMobsDistance) == false)
            {
                continue;
            }

            std::string spawnName = EQ_GetSpawnName(spawn);
            if (spawnName.size() == 0)
            {
                continue;
            }

            for (auto& killMobsName : g_KillMobsList)
            {
                if (spawnName == killMobsName)
                {
                    EQ_SetTargetSpawn(spawn);

                    g_FollowAISpawn = spawn;
                    EQ_SetAutoRun(true);

                    EQ_SetAutoAttack(true);

                    return;
                }
            }
        }
    }

    targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        bool foundTarget = false;

        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance();

        for (auto& spawnID : spawnIDList)
        {
            if (foundTarget == true)
            {
                break;
            }

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

            for (auto& killMobsName : g_KillMobsList)
            {
                if (spawnName == killMobsName)
                {
                    g_FollowAISpawn = spawn;
                    EQ_SetAutoRun(true);

                    EQ_SetAutoAttack(true);

                    return;
                }
            }
        }
    }

    if (g_FollowAISpawn == NULL)
    {
        EQ_SetAutoRun(false);

        EQ_SetAutoAttack(false);
    }
}

