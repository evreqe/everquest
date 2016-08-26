#ifndef EQAPP_ESP_FUNCTIONS_H
#define EQAPP_ESP_FUNCTIONS_H

#include "eqapp_esp.h"

#include "eqapp_esp_custom.h"
#include "eqapp_esp_spawnlist.h"

void EQAPP_ESP_Execute();
void EQAPP_ESP_Spawns_Draw();
void EQAPP_ESP_GroundSpawns_Draw();
void EQAPP_ESP_Doors_Draw();
void EQAPP_ESP_ZoneActors_Draw();
void EQAPP_ESP_Waypoints_Draw();
void EQAPP_ESP_Locator_Draw();
void EQAPP_ESP_Locator_Print();
void EQAPP_ESP_Find_Print();
void EQAPP_ESP_SpawnSkeleton_Draw(DWORD spawnInfo, DWORD argbColor);

void EQAPP_ESP_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (g_espIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    } 

    EQAPP_ESP_SpawnList_Update();

    g_espNumDrawText = 0;

    // draw order is least important to most important
    EQAPP_ESP_Custom_Draw();
    EQAPP_ESP_Waypoints_Draw();
    EQAPP_ESP_ZoneActors_Draw();
    EQAPP_ESP_Doors_Draw();
    EQAPP_ESP_GroundSpawns_Draw();
    EQAPP_ESP_Locator_Draw();
    EQAPP_ESP_Spawns_Draw();
}

void EQAPP_ESP_Spawns_Draw()
{
    if (g_espSpawnIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto& spawn : g_espSpawnList)
    {
        if (spawn.spawnInfo == NULL)
        {
            continue;
        }

        // force coordinates to update fast
        spawn.y = EQ_GetSpawnY(spawn.spawnInfo);
        spawn.x = EQ_GetSpawnX(spawn.spawnInfo);
        spawn.z = EQ_GetSpawnZ(spawn.spawnInfo);

        int fontSize = 3;

        if (spawn.isHalfDistance == true)
        {
            fontSize = 2;
        }

        if (spawn.showAtAnyDistance == true || spawn.isFindSpawn == true)
        {
            fontSize = 5;
        }

        int screenX = -1;
        int screenY = -1;
        bool result = EQ_WorldSpaceToScreenSpace(spawn.x, spawn.y, spawn.z, screenX, screenY);
        if (result == false)
        {
            continue;
        }

        DWORD textColor = 0xFFFFFFFF; // white

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER)
        {
            textColor = 0xFFFF0000; // red
        }
        else if (spawn.type == EQ_SPAWN_TYPE_NPC)
        {
            textColor = 0xFF00FFFF; // cyan
        }
        else if (spawn.type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            textColor = 0xFFFF8000; // orange
        }
        else if (spawn.type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            textColor = 0xFFFFFF00; // yellow
        }

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (EQ_IsSpawnInGroup(spawn.spawnInfo) == true)
            {
                textColor = 0xFF00FF00; // green
            }

            if (strlen(spawn.name) < EQ_SPAWN_NAME_LENGTH_MIN)
            {
                textColor = 0xFFC0C0C0; // gray
            }
        }

        if (spawn.showAtAnyDistance == true)
        {
            textColor = 0xFF00FF80; // greenish blue
        }

        if (spawn.isTarget == true || spawn.isGm == 1)
        {
            textColor = 0xFFFF00FF; // pink
        }

        if (spawn.isHalfDistance == true)
        {
            EQ_HexColorDarken(textColor, 0.9f);
        }

        if (g_espSkeletonIsEnabled == true)
        {
            if (spawn.distance < g_espSkeletonDistance)
            {
                if (EQ_CastRay(playerSpawn, spawn.y, spawn.x, spawn.z) == 0)
                {
                    EQAPP_ESP_SpawnSkeleton_Draw(spawn.spawnInfo, textColor);
                }
            }
        }

        std::stringstream ssDrawText;
        ssDrawText << "+ " << spawn.name;

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER_CORPSE || spawn.type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            ssDrawText << " corpse";
        }

        ssDrawText << " L" << spawn.level;

        if (spawn._class > EQ_CLASS_UNKNOWN && spawn._class < EQ_CLASS_BANKER)
        {
            if (spawn.type == EQ_SPAWN_TYPE_PLAYER || (spawn.type == EQ_SPAWN_TYPE_NPC && EQ_IsKeyControlPressed() == true))
            {
                const char* spawnClassThreeLetterCode = EQ_CEverQuest->GetClassThreeLetterCode(spawn._class);

                ssDrawText << " " << spawnClassThreeLetterCode;
            }
        }

        ssDrawText << " (" << (int)spawn.distance << ")";

        if (spawn.isLfg == 1)
        {
            ssDrawText << "  LFG";
        }

        if (spawn.isPvp == 1)
        {
            ssDrawText << "  PVP";
        }

        if (spawn.isTrader == 1)
        {
            ssDrawText << "  TRADER";
        }

        if (spawn.isAfk == 1)
        {
            ssDrawText << "  AFK";
        }

        if (spawn.isGm == 1)
        {
            ssDrawText << "  *GM*";
        }

        ssDrawText << "\n";
        g_espNumDrawText++;

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawn.standingState == EQ_STANDING_STATE_FEIGNED)
            {
                ssDrawText << "*Feign Death*\n";
                g_espNumDrawText++;
            }

            if (EQ_IsKeyControlPressed() == true)
            {
                if (spawn.guildId > 0 && spawn.guildId < EQ_NUM_GUILDS)
                {
                    const char* spawnGuildName = EQ_EQ_Guilds.GetGuildNameById(spawn.guildId);

                    ssDrawText << "<" << spawnGuildName << ">\n";
                    g_espNumDrawText++;
                }
            }
        }
        else if (spawn.type == EQ_SPAWN_TYPE_NPC)
        {
            if (strlen(spawn.lastName) > 0)
            {
                ssDrawText << "(" << spawn.lastName << ")\n";
                g_espNumDrawText++;
            }

            if (EQ_IsKeyControlPressed() == true)
            {
                const char* spawnBodyTypeDescription = EQ_CEverQuest->GetBodyTypeDesc(spawn.spawnInfo + EQ_OFFSET_SPAWN_INFO_BODY_TYPE_DESCRIPTION);

                ssDrawText << "[" << spawnBodyTypeDescription << "]\n";
                g_espNumDrawText++;

                if (spawn.isHoldingPrimary != 0 && spawn.isHoldingSecondary != 0)
                {
                    ssDrawText << "Holding Primary & Secondary\n";
                    g_espNumDrawText++;
                }
                else if (spawn.isHoldingPrimary != 0)
                {
                    ssDrawText << "Holding Primary\n";
                    g_espNumDrawText++;
                }
                else if (spawn.isHoldingSecondary != 0)
                {
                    ssDrawText << "Holding Secondary\n";
                    g_espNumDrawText++;
                }
            }
        }

        if (g_spawnCastSpellIsEnabled == true)
        {
            for (auto& spawnCastSpell : g_spawnCastSpellList)
            {
                if (spawnCastSpell->spawnInfo == spawn.spawnInfo)
                {
                    ssDrawText << "(" << spawnCastSpell->spellName << ")\n";
                    g_espNumDrawText++;
                    break;
                }
            }
        }

        EQ_DrawText(ssDrawText.str().c_str(), screenX, screenY, textColor, fontSize);

        if (g_espFindIsEnabled == true && g_espFindDrawLineIsEnabled == true && spawn.isFindSpawn == true)
        {
            DWORD windowWidth  = EQ_GetWindowWidth();
            DWORD windowHeight = EQ_GetWindowHeight();

            EQ_DrawLine((float)(windowWidth * 0.5f), (float)windowHeight, 0.0f, (float)screenX, (float)screenY, 0.0f, g_espFindColor);
        }
    }
}

void EQAPP_ESP_GroundSpawns_Draw()
{
    if (g_espGroundSpawnIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    // ground spawn
    DWORD spawn = EQ_GetFirstGroundSpawn();
    while (spawn)
    {
        // note Z X Y instead of Y X Z
        FLOAT spawnZ = EQ_GetGroundSpawnZ(spawn);
        FLOAT spawnX = EQ_GetGroundSpawnX(spawn);
        FLOAT spawnY = EQ_GetGroundSpawnY(spawn);

        float spawnDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, spawnX, spawnY, spawnZ);

        if (spawnDistance > g_espGroundSpawnDistance)
        {
            spawn = EQ_GetNextGroundSpawn(spawn); // next
            continue;
        }

        int screenX = -1;
        int screenY = -1;
        bool result = EQ_WorldSpaceToScreenSpace(spawnX, spawnY, spawnZ, screenX, screenY);
        if (result == false)
        {
            spawn = EQ_GetNextGroundSpawn(spawn); // next
            continue;
        }

        char spawnName[EQ_SIZE_GROUND_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_GROUND_SPAWN_INFO_NAME), sizeof(spawnName));

        std::string spawnNameEx = spawnName;

        auto find = EQ_KEYVALUE_ACTOR_DEFINITIONS.find(spawnName);
        if (find != EQ_KEYVALUE_ACTOR_DEFINITIONS.end())
        {
            spawnNameEx = find->second;

            std::stringstream ss;
            ss << "+ " << spawnNameEx << " (" << (int)spawnDistance << ")";

            EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espGroundSpawnColor, 2);
            g_espNumDrawText++;
        }

        spawn = EQ_GetNextGroundSpawn(spawn); // next
    }
}

void EQAPP_ESP_Doors_Draw()
{
    if (g_espDoorIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    DWORD switchManager = EQ_ReadMemory<DWORD>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager != NULL)
    {
        DWORD numDoors = EQ_ReadMemory<DWORD>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
        if (numDoors != 0)
        {
            for (size_t i = 0; i < numDoors; i++)
            {
                DWORD doorInfo = EQ_ReadMemory<DWORD>(switchManager + EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST + (i * 4));
                if (doorInfo == NULL)
                {
                    continue;
                }

                FLOAT doorY = EQ_ReadMemory<FLOAT>(doorInfo + EQ_OFFSET_DOOR_INFO_Y);
                FLOAT doorX = EQ_ReadMemory<FLOAT>(doorInfo + EQ_OFFSET_DOOR_INFO_X);
                FLOAT doorZ = EQ_ReadMemory<FLOAT>(doorInfo + EQ_OFFSET_DOOR_INFO_Z);

                float doorDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, doorX, doorY, doorZ);
                if (doorDistance > g_espDoorDistance)
                {
                    continue;
                }

                int screenX = -1;
                int screenY = -1;
                bool result = EQ_WorldSpaceToScreenSpace(doorX, doorY, doorZ, screenX, screenY);
                if (result == false)
                {
                    continue;
                }

                char doorName[EQ_SIZE_DOOR_INFO_NAME] = {0};
                memcpy(doorName, (LPVOID)(doorInfo + EQ_OFFSET_DOOR_INFO_NAME), sizeof(doorName));

                std::stringstream ss;
                ss << "+ " << doorName << " [#" << i + 1 << "]" << " (" << (int)doorDistance << ")";

                EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espDoorColor, 2);
                g_espNumDrawText++;
            }
        }
    }
}

void EQAPP_ESP_ZoneActors_Draw()
{
    if (g_espZoneActorIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    DWORD pointer1 = EQ_ReadMemory<DWORD>(EQ_POINTER_0x00B112C0);
    if (pointer1 != NULL)
    {
        DWORD pointer2 = EQ_ReadMemory<DWORD>(pointer1 + EQ_OFFSET_0x00B112C0_POINTER_2);
        if (pointer2 != NULL)
        {
            DWORD zoneActor = EQ_ReadMemory<DWORD>(pointer2 + EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST);

            while (zoneActor)
            {
                DWORD zoneActor0x0C = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x0C);
                if (zoneActor0x0C == 2)
                {
                    zoneActor = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                int zoneActor0x2C = EQ_ReadMemory<BYTE>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2C);
                int zoneActor0x2D = EQ_ReadMemory<BYTE>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2D);
                int zoneActor0x2E = EQ_ReadMemory<BYTE>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2E);
                int zoneActor0x2F = EQ_ReadMemory<BYTE>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2F);

                DWORD zoneActor0x1C = EQ_ReadMemory<DWORD>(zoneActor + 0x1C);
                DWORD zoneActor0x20 = EQ_ReadMemory<DWORD>(zoneActor + 0x20);
                DWORD zoneActor0x24 = EQ_ReadMemory<DWORD>(zoneActor + 0x24);
                DWORD zoneActor0x28 = EQ_ReadMemory<DWORD>(zoneActor + 0x28);

                FLOAT zoneActor0x40 = EQ_ReadMemory<FLOAT>(zoneActor + 0x40);
                FLOAT zoneActor0x44 = EQ_ReadMemory<FLOAT>(zoneActor + 0x44);
                FLOAT zoneActor0x4C = EQ_ReadMemory<FLOAT>(zoneActor + 0x4C);

                DWORD zoneActor0x50 = EQ_ReadMemory<DWORD>(zoneActor + 0x50);
                DWORD zoneActor0x54 = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x54);

                FLOAT zoneActorY = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Y);
                FLOAT zoneActorX = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_X);
                FLOAT zoneActorZ = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Z);

                FLOAT zoneActorRotation = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION);
                FLOAT zoneActorScale = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_SCALE);

                float zoneActorDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, zoneActorX, zoneActorY, zoneActorZ);
                if (zoneActorDistance > g_espZoneActorDistance)
                {
                    zoneActor = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                int screenX = -1;
                int screenY = -1;
                bool result = EQ_WorldSpaceToScreenSpace(zoneActorX, zoneActorY, zoneActorZ, screenX, screenY);
                if (result == false)
                {
                    zoneActor = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                std::string zoneActorName = "ZONEACTOR";

                DWORD zoneActor0x14 = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x14);
                if (zoneActor0x14 != NULL)
                {
                    DWORD zoneActor0x14x18 = EQ_ReadMemory<DWORD>(zoneActor0x14 + EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18);
                    if (zoneActor0x14x18 != NULL)
                    {
                        PCHAR zoneActorNamePointer = EQ_ReadMemory<PCHAR>(zoneActor0x14x18 + EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08);
                        if (zoneActorNamePointer != NULL)
                        {
                            zoneActorName = std::string(zoneActorNamePointer);
                        }
                    }
                }

                std::string zoneActorExName = "ZONEACTOREX";

                DWORD zoneActorSpawnInfo = NULL;

                FLOAT zoneActorEx0x08 = NULL;
                FLOAT zoneActorEx0x0C = NULL;
                FLOAT zoneActorEx0x10 = NULL;
                FLOAT zoneActorEx0x14 = NULL;

                FLOAT zoneActorExY1 = 0.0f;
                FLOAT zoneActorExX1 = 0.0f;
                FLOAT zoneActorExZ1 = 0.0f;

                FLOAT zoneActorExY2 = 0.0f;
                FLOAT zoneActorExX2 = 0.0f;
                FLOAT zoneActorExZ2 = 0.0f;

                FLOAT zoneActorExY3 = 0.0f;
                FLOAT zoneActorExX3 = 0.0f;
                FLOAT zoneActorExZ3 = 0.0f;

                DWORD zoneActorEx = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_SUB_INFO);
                if (zoneActorEx != NULL)
                {
                    zoneActorSpawnInfo = EQ_ReadMemory<DWORD>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_SPAWN_INFO);

                    if (zoneActorSpawnInfo == NULL)
                    {
                        PCHAR zoneActorExNamePointer = (PCHAR)(zoneActorEx - EQ_OFFSET_ZONE_ACTOR_SUB_INFO_NAME);
                        if (zoneActorExNamePointer != NULL)
                        {
                            zoneActorExName = std::string(zoneActorExNamePointer);
                        }
                    }

                    zoneActorEx0x08 = EQ_ReadMemory<FLOAT>(zoneActorEx + 0x08);
                    zoneActorEx0x0C = EQ_ReadMemory<FLOAT>(zoneActorEx + 0x0C);
                    zoneActorEx0x10 = EQ_ReadMemory<FLOAT>(zoneActorEx + 0x10);
                    zoneActorEx0x14 = EQ_ReadMemory<FLOAT>(zoneActorEx + 0x14);

                    zoneActorExY1 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y1);
                    zoneActorExX1 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X1);
                    zoneActorExZ1 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z1);

                    zoneActorExY2 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y2);
                    zoneActorExX2 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X2);
                    zoneActorExZ2 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z2);

                    zoneActorExY3 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y3);
                    zoneActorExX3 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X3);
                    zoneActorExZ3 = EQ_ReadMemory<FLOAT>(zoneActorEx + EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z3);
                }

                std::stringstream ssDrawText;
                ssDrawText << "+ " << zoneActorName << " (" << (int)zoneActorDistance << ")\n";

/*
                ssDrawText << "Address: " << std::hex << zoneActor << "\n";
                ssDrawText << "Address Ex: " << std::hex << zoneActorEx << "\n";
*/

                ssDrawText << "Y: " << zoneActorY << "\n";
                ssDrawText << "X: " << zoneActorX << "\n";
                ssDrawText << "Z: " << zoneActorZ << "\n";

                ssDrawText << "Rotation: " << zoneActorRotation << "\n";
                ssDrawText << "Scale: " << zoneActorScale << "\n";

/*
                ssDrawText << "0x2C: " << zoneActor0x2C << "\n";
                ssDrawText << "0x2D: " << zoneActor0x2D << "\n";
                ssDrawText << "0x2E: " << zoneActor0x2E << "\n";
                ssDrawText << "0x2F: " << zoneActor0x2F << "\n";

                ssDrawText << "0x1C: " << std::hex << zoneActor0x1C << "\n";
                ssDrawText << "0x20: " << std::hex << zoneActor0x20 << "\n";
                ssDrawText << "0x24: " << std::hex << zoneActor0x24 << "\n";
                ssDrawText << "0x28: " << std::hex << zoneActor0x28 << "\n";

                ssDrawText << "0x40: " << zoneActor0x40 << "\n";
                ssDrawText << "0x44: " << zoneActor0x44 << "\n";
                ssDrawText << "0x4C: " << zoneActor0x4C << "\n";

                ssDrawText << "0x50: " << std::hex << zoneActor0x50 << "\n";
                ssDrawText << "0x54: " << std::hex << zoneActor0x54 << "\n";
*/

/*
                ssDrawText << zoneActorExName << "\n";

                ssDrawText << "Y1: " << zoneActorExY1 << "\n";
                ssDrawText << "X1: " << zoneActorExX1 << "\n";
                ssDrawText << "Z1: " << zoneActorExZ1 << "\n";

                ssDrawText << "Y2: " << zoneActorExY2 << "\n";
                ssDrawText << "X2: " << zoneActorExX2 << "\n";
                ssDrawText << "Z2: " << zoneActorExZ2 << "\n";

                ssDrawText << "Y3: " << zoneActorExY3 << "\n";
                ssDrawText << "X3: " << zoneActorExX3 << "\n";
                ssDrawText << "Z3: " << zoneActorExZ3 << "\n";
*/

                if (zoneActorSpawnInfo != NULL)
                {
                    ssDrawText << "Spawn Info: " << std::hex << zoneActorSpawnInfo << "\n";
                }

                EQ_DrawText(ssDrawText.str().c_str(), screenX, screenY, g_espZoneActorColor, 2);

                zoneActor = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
            }
        }
    }
}

void EQAPP_ESP_Waypoints_Draw()
{
    if (g_espWaypointIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto& waypoint : g_waypointList)
    {
        float distance = EQ_CalculateDistance3d(playerX, playerY, playerZ, waypoint.x, waypoint.y, waypoint.z);
        if (distance > g_espWaypointDistance)
        {
            continue;
        }

        int screenX = -1;
        int screenY = -1;
        bool result = EQ_WorldSpaceToScreenSpace(waypoint.x, waypoint.y, waypoint.z, screenX, screenY);
        if (result == false)
        {
            continue;
        }

        for (auto& connectIndex : waypoint.connectList)
        {
            if (connectIndex > g_waypointList.size())
            {
                continue;
            }

            PEQAPPWAYPOINT connectWaypoint = EQAPP_Waypoint_GetByIndex(connectIndex);
            if (connectWaypoint == NULL)
            {
                EQAPP_PrintErrorMessage(__FUNCTION__ , "connect waypoint is NULL");
                continue;
            }

            float distance2 = EQ_CalculateDistance3d(playerX, playerY, playerZ, connectWaypoint->x, connectWaypoint->y, connectWaypoint->z);
            if (distance2 > g_espWaypointDistance)
            {
                continue;
            }

            int screenX2 = -1;
            int screenY2 = -1;
            bool result2 = EQ_WorldSpaceToScreenSpace(connectWaypoint->x, connectWaypoint->y, connectWaypoint->z, screenX2, screenY2);
            if (result2 == false)
            {
                continue;
            }

            EQ_DrawLine((float)screenX, (float)screenY, 0.0f, (float)screenX2, (float)screenY2, 0.0f, g_espWaypointColor);
        }

        std::stringstream ss;
        ss << "@ " << waypoint.name << " (" << (int)distance << ")";
        EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espWaypointColor, 2);
    }
}

void EQAPP_ESP_Locator_Draw()
{
    if (g_espLocatorIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    int screenX = -1;
    int screenY = -1;
    bool result = EQ_WorldSpaceToScreenSpace(g_espLocatorX, g_espLocatorY, g_espLocatorZ, screenX, screenY);
    if (result == true)
    {
        float distance = EQ_CalculateDistance3d(playerX, playerY, playerZ, g_espLocatorX, g_espLocatorY, g_espLocatorZ);

        if (g_espLocatorDrawLineIsEnabled == true)
        {
            DWORD windowWidth  = EQ_GetWindowWidth();
            DWORD windowHeight = EQ_GetWindowHeight();

            EQ_DrawLine((float)(windowWidth * 0.5f), (float)windowHeight, 0.0f, (float)screenX, (float)screenY, 0.0f, g_espLocatorColor);
        }

        std::stringstream ss;
        ss << "+ Locator (" << (int)distance << ")";

        EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espLocatorColor, 5);
        g_espNumDrawText++;
    }
}

void EQAPP_ESP_Locator_Print()
{
    std::cout << "Locator: " << g_espLocatorY << ", " << g_espLocatorX << ", " << g_espLocatorZ << std::endl;
}

void EQAPP_ESP_Find_Print()
{
    std::cout << "Find: " << g_espFindSpawnName << std::endl;
}

void EQAPP_ESP_SpawnSkeleton_Draw(DWORD spawnInfo, DWORD argbColor)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    //char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
    //memcpy(spawnNumberedName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

    //EQAPP_Log("----------", 0);
    //EQAPP_Log(spawnNumberedName, 0);

    DWORD actorInfo = EQ_GetSpawnActorInfo(spawnInfo);
    if (actorInfo == NULL)
    {
        return;
    }

    DWORD modelInfo = EQ_ReadMemory<DWORD>(actorInfo + EQ_OFFSET_ACTOR_INFO_MODEL_INFO);
    if (modelInfo == NULL)
    {
        return;
    }

    DWORD boneList = EQ_ReadMemory<DWORD>(modelInfo + EQ_OFFSET_MODEL_INFO_BONE_LIST);
    if (boneList == NULL)
    {
        return;
    }

    DWORD firstBoneInfo = EQ_ReadMemory<DWORD>(boneList + 0x00);
    if (firstBoneInfo == NULL)
    {
        return;
    }

    DWORD firstBoneMagicNumber = EQ_ReadMemory<DWORD>(firstBoneInfo + 0x00);
    if (firstBoneMagicNumber == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_BONES; i++)
    {
        //EQAPP_Log("boneIndex", i);

        DWORD boneInfo = EQ_ReadMemory<DWORD>(boneList + (i * 4));
        if (boneInfo == NULL)
        {
            continue;
        }

        if ((boneInfo > (boneList + 0x4000)) || (boneInfo < boneList))
        {
            continue;
        }

        if (boneInfo == firstBoneMagicNumber)
        {
            break;
        }

        //EQAPP_Log("boneInfo", boneInfo);

        DWORD boneMagicNumber = EQ_ReadMemory<DWORD>(boneInfo + 0x00);
        if (boneMagicNumber == NULL)
        {
            continue;
        }

        if (boneMagicNumber != firstBoneMagicNumber)
        {
            break;
        }

        //EQAPP_Log("boneMagicNumber", boneMagicNumber);

        FLOAT boneY = EQ_ReadMemory<FLOAT>(boneInfo + EQ_OFFSET_BONE_INFO_Y);
        FLOAT boneX = EQ_ReadMemory<FLOAT>(boneInfo + EQ_OFFSET_BONE_INFO_X);
        FLOAT boneZ = EQ_ReadMemory<FLOAT>(boneInfo + EQ_OFFSET_BONE_INFO_Z);

        //EQAPP_Log("boneY", boneY);
        //EQAPP_Log("boneX", boneX);
        //EQAPP_Log("boneZ", boneZ);

        if (boneY == 0.0f || boneX == 0.0f || boneZ == 0.0f)
        {
            continue;
        }

        int screenX = -1;
        int screenY = -1;
        bool result = EQ_WorldSpaceToScreenSpace(boneX, boneY, boneZ, screenX, screenY);
        if (result == false)
        {
            continue;
        }

        // draw a line instead of text for performance
        EQ_DrawLine((float)screenX, (float)screenY, 1.0f, (float)screenX, (float)(screenY + 1.0f), 1.0f, argbColor);
    }
}

#endif // EQAPP_ESP_FUNCTIONS_H
