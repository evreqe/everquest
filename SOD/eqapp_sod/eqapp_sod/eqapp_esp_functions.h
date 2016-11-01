#pragma once

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
void EQAPP_ESP_SpawnSkeleton_Draw(uint32_t spawnInfo, uint32_t colorARGB);

void EQAPP_ESP_Execute()
{
    if (g_espIsEnabled == false)
    {
        return;
    }

    if (EQ_IsInGame() == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
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

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

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

        uint32_t textColorARGB = 0xFFFFFFFF; // white

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER)
        {
            textColorARGB = 0xFFFF0000; // red
        }
        else if (spawn.type == EQ_SPAWN_TYPE_NPC)
        {
            textColorARGB = 0xFF00FFFF; // cyan
        }
        else if (spawn.type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            textColorARGB = 0xFFFF8000; // orange
        }
        else if (spawn.type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            textColorARGB = 0xFFFFFF00; // yellow
        }

        if (spawn.type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (EQ_IsSpawnInGroup(spawn.spawnInfo) == true)
            {
                textColorARGB = 0xFF00FF00; // green
            }

            if (strlen(spawn.name) < EQ_SPAWN_NAME_LENGTH_MIN)
            {
                textColorARGB = 0xFFC0C0C0; // gray
            }
        }

        if (spawn.showAtAnyDistance == true)
        {
            textColorARGB = 0xFF00FF80; // greenish blue
        }

        if (spawn.isTarget == true || spawn.isGm == 1)
        {
            textColorARGB = 0xFFFF00FF; // pink
        }

        if (spawn.isHalfDistance == true)
        {
            EQ_ColorARGB_Darken(textColorARGB, g_espHalfDistanceColorDarkenPercent);
        }

        if (g_espSkeletonIsEnabled == true)
        {
            if (spawn.distance < g_espSkeletonDistance)
            {
                bool shouldDrawSkeleton = true;

                if (g_espSkeletonHideByLineOfSightIsEnabled == true && EQ_CastRay(playerSpawn, spawn.y, spawn.x, spawn.z) != 0)
                {
                    shouldDrawSkeleton = false;
                }

                if (shouldDrawSkeleton == true)
                {
                    EQAPP_ESP_SpawnSkeleton_Draw(spawn.spawnInfo, textColorARGB);
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
            else if (spawn.standingState == EQ_STANDING_STATE_FROZEN)
            {
                ssDrawText << "*Frozen*\n";
                g_espNumDrawText++;
            }
            else if (spawn.standingState == EQ_STANDING_STATE_LOOTING)
            {
                ssDrawText << "*Looting*\n";
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

        if (g_spawnCastSpellIsEnabled == true && g_spawnCastSpellEspIsEnabled == true)
        {
            for (auto& spawnCastSpell : g_spawnCastSpellList)
            {
                if (spawnCastSpell->spawnInfo == spawn.spawnInfo)
                {
                    ssDrawText << "(" << spawnCastSpell->spellName << ")";

                    if (spawnCastSpell->spellCastTimeCountdown > 0)
                    {
                        float spellCastTimeCurrentFloat = (float)(spawnCastSpell->spellCastTimeCountdown / 1000.0f);

                        ssDrawText.precision(1);
                        ssDrawText << " " << std::fixed << spellCastTimeCurrentFloat;
                    }

                    ssDrawText << "\n";

                    g_espNumDrawText++;
                    break;
                }
            }
        }

        EQ_DrawText(ssDrawText.str().c_str(), screenX, screenY, textColorARGB, fontSize);

        if (g_espFindIsEnabled == true && g_espFindDrawLineIsEnabled == true && spawn.isFindSpawn == true)
        {
            uint32_t windowWidth = EQ_GetWindowWidth();
            uint32_t windowHeight = EQ_GetWindowHeight();

            EQ_DrawLine((float)(windowWidth * 0.5f), (float)windowHeight, 0.0f, (float)screenX, (float)screenY, 0.0f, g_espFindColorARGB);
        }
    }
}

void EQAPP_ESP_GroundSpawns_Draw()
{
    if (g_espGroundSpawnIsEnabled == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    // ground spawn
    uint32_t spawn = EQ_GetFirstGroundSpawn();
    while (spawn)
    {
        // note Z X Y instead of Y X Z
        float spawnZ = EQ_GetGroundSpawnZ(spawn);
        float spawnX = EQ_GetGroundSpawnX(spawn);
        float spawnY = EQ_GetGroundSpawnY(spawn);

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
        memcpy(spawnName, (void*)(spawn + EQ_OFFSET_GROUND_SPAWN_INFO_NAME), sizeof(spawnName));

        std::string spawnNameEx = spawnName;

        auto find = EQ_KEYVALUE_ACTOR_DEFINITIONS.find(spawnName);
        if (find != EQ_KEYVALUE_ACTOR_DEFINITIONS.end())
        {
            spawnNameEx = find->second;

            std::stringstream ss;
            ss << "+ " << spawnNameEx << " (" << (int)spawnDistance << ")";

            EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espGroundSpawnColorARGB, 2);
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

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t switchManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager != NULL)
    {
        uint32_t numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
        if (numDoors != 0)
        {
            for (size_t i = 0; i < numDoors; i++)
            {
                uint32_t doorInfo = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST + (i * 4));
                if (doorInfo == NULL)
                {
                    continue;
                }

                float doorY = EQ_ReadMemory<float>(doorInfo + EQ_OFFSET_DOOR_INFO_Y);
                float doorX = EQ_ReadMemory<float>(doorInfo + EQ_OFFSET_DOOR_INFO_X);
                float doorZ = EQ_ReadMemory<float>(doorInfo + EQ_OFFSET_DOOR_INFO_Z);

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
                memcpy(doorName, (void*)(doorInfo + EQ_OFFSET_DOOR_INFO_NAME), sizeof(doorName));

                std::stringstream ss;
                ss << "+ " << doorName << " [#" << i + 1 << "]" << " (" << (int)doorDistance << ")";

                EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espDoorColorARGB, 2);
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

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t pointer1 = EQ_ReadMemory<uint32_t>(EQ_POINTER_0x00B112C0);
    if (pointer1 != NULL)
    {
        uint32_t pointer2 = EQ_ReadMemory<uint32_t>(pointer1 + EQ_OFFSET_0x00B112C0_POINTER_2);
        if (pointer2 != NULL)
        {
            uint32_t zoneActor = EQ_ReadMemory<uint32_t>(pointer2 + EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST);

            while (zoneActor)
            {
                uint32_t zoneActor0x0C = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x0C);
                if (zoneActor0x0C == 2)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                int zoneActor0x2C = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2C);
                int zoneActor0x2D = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2D);
                int zoneActor0x2E = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2E);
                int zoneActor0x2F = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2F);

                uint32_t zoneActor0x1C = EQ_ReadMemory<uint32_t>(zoneActor + 0x1C);
                uint32_t zoneActor0x20 = EQ_ReadMemory<uint32_t>(zoneActor + 0x20);
                uint32_t zoneActor0x24 = EQ_ReadMemory<uint32_t>(zoneActor + 0x24);
                uint32_t zoneActor0x28 = EQ_ReadMemory<uint32_t>(zoneActor + 0x28);

                float zoneActor0x40 = EQ_ReadMemory<float>(zoneActor + 0x40);
                float zoneActor0x44 = EQ_ReadMemory<float>(zoneActor + 0x44);
                float zoneActor0x4C = EQ_ReadMemory<float>(zoneActor + 0x4C);

                uint32_t zoneActor0x50 = EQ_ReadMemory<uint32_t>(zoneActor + 0x50);
                uint32_t zoneActor0x54 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x54);

                float zoneActorY = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Y);
                float zoneActorX = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_X);
                float zoneActorZ = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Z);

                float zoneActorRotation = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION);
                float zoneActorScale = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_SCALE);

                float zoneActorDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, zoneActorX, zoneActorY, zoneActorZ);
                if (zoneActorDistance > g_espZoneActorDistance)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                int screenX = -1;
                int screenY = -1;
                bool result = EQ_WorldSpaceToScreenSpace(zoneActorX, zoneActorY, zoneActorZ, screenX, screenY);
                if (result == false)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                std::string zoneActorName = "ZONEACTOR";

                uint32_t zoneActor0x14 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x14);
                if (zoneActor0x14 != NULL)
                {
                    uint32_t zoneActor0x14x18 = EQ_ReadMemory<uint32_t>(zoneActor0x14 + EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18);
                    if (zoneActor0x14x18 != NULL)
                    {
                        char* zoneActorNamePointer = EQ_ReadMemory<char*>(zoneActor0x14x18 + EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08);
                        if (zoneActorNamePointer != NULL)
                        {
                            zoneActorName = std::string(zoneActorNamePointer);
                        }
                    }
                }

                std::string zoneActorExName = "ZONEACTOREX";

                uint32_t zoneActorSpawnInfo = NULL;

                float zoneActorExY1 = 0.0f;
                float zoneActorExX1 = 0.0f;
                float zoneActorExZ1 = 0.0f;

                float zoneActorExY2 = 0.0f;
                float zoneActorExX2 = 0.0f;
                float zoneActorExZ2 = 0.0f;

                float zoneActorExY3 = 0.0f;
                float zoneActorExX3 = 0.0f;
                float zoneActorExZ3 = 0.0f;

                uint32_t zoneActorEx = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_INFO);
                if (zoneActorEx != NULL)
                {
                    zoneActorSpawnInfo = EQ_ReadMemory<uint32_t>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_SPAWN_INFO);

                    if (zoneActorSpawnInfo == NULL)
                    {
                        char* zoneActorExNamePointer = (char*)(zoneActorEx - EQ_OFFSET_ACTOR_INFO_NAME);
                        if (zoneActorExNamePointer != NULL)
                        {
                            zoneActorExName = std::string(zoneActorExNamePointer);
                        }
                    }

                    zoneActorExY1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y1);
                    zoneActorExX1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X1);
                    zoneActorExZ1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z1);

                    zoneActorExY2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y2);
                    zoneActorExX2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X2);
                    zoneActorExZ2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z2);

                    zoneActorExY3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y3);
                    zoneActorExX3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X3);
                    zoneActorExZ3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z3);
                }

                std::stringstream ssDrawText;
                ssDrawText << "+ " << zoneActorName << " (" << (int)zoneActorDistance << ")\n";

                ssDrawText << "Address: " << std::hex << zoneActor << "\n";

                ssDrawText << "Y: " << zoneActorY << "\n";
                ssDrawText << "X: " << zoneActorX << "\n";
                ssDrawText << "Z: " << zoneActorZ << "\n";

                ssDrawText << "Rotation: " << zoneActorRotation << "\n";
                ssDrawText << "Scale: " << zoneActorScale << "\n";

                if (EQ_IsKeyControlPressed() == true)
                {
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
                }

                ssDrawText << zoneActorExName << "\n";

                ssDrawText << "Address Ex: " << std::hex << zoneActorEx << "\n";

                if (EQ_IsKeyControlPressed() == true)
                {
                    ssDrawText << "Y1: " << zoneActorExY1 << "\n";
                    ssDrawText << "X1: " << zoneActorExX1 << "\n";
                    ssDrawText << "Z1: " << zoneActorExZ1 << "\n";

                    ssDrawText << "Y2: " << zoneActorExY2 << "\n";
                    ssDrawText << "X2: " << zoneActorExX2 << "\n";
                    ssDrawText << "Z2: " << zoneActorExZ2 << "\n";

                    ssDrawText << "Y3: " << zoneActorExY3 << "\n";
                    ssDrawText << "X3: " << zoneActorExX3 << "\n";
                    ssDrawText << "Z3: " << zoneActorExZ3 << "\n";
                }

                if (zoneActorSpawnInfo != NULL)
                {
                    ssDrawText << "Spawn Info: " << std::hex << zoneActorSpawnInfo << "\n";
                }

                EQ_DrawText(ssDrawText.str().c_str(), screenX, screenY, g_espZoneActorColorARGB, 2);

                zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
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

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

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

            EQApp::Waypoint* connectWaypoint = EQAPP_WaypointList_GetByIndex(connectIndex);
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

            EQ_DrawLine((float)screenX, (float)screenY, 0.0f, (float)screenX2, (float)screenY2, 0.0f, g_espWaypointColorARGB);
        }

        std::stringstream ss;
        ss << "@ " << waypoint.name << " (" << (int)distance << ")";
        EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espWaypointColorARGB, 2);
    }
}

void EQAPP_ESP_Locator_Draw()
{
    if (g_espLocatorIsEnabled == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    int screenX = -1;
    int screenY = -1;
    bool result = EQ_WorldSpaceToScreenSpace(g_espLocatorX, g_espLocatorY, g_espLocatorZ, screenX, screenY);
    if (result == true)
    {
        float distance = EQ_CalculateDistance3d(playerX, playerY, playerZ, g_espLocatorX, g_espLocatorY, g_espLocatorZ);

        if (g_espLocatorDrawLineIsEnabled == true)
        {
            uint32_t windowWidth = EQ_GetWindowWidth();
            uint32_t windowHeight = EQ_GetWindowHeight();

            EQ_DrawLine((float)(windowWidth * 0.5f), (float)windowHeight, 0.0f, (float)screenX, (float)screenY, 0.0f, g_espLocatorColorARGB);
        }

        std::stringstream ss;
        ss << "+ Locator (" << (int)distance << ")";

        EQ_DrawText(ss.str().c_str(), screenX, screenY, g_espLocatorColorARGB, g_espLocatorFontSize);
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

void EQAPP_ESP_SpawnSkeleton_Draw(uint32_t spawnInfo, uint32_t colorARGB)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    uint32_t actorInfo = EQ_GetSpawnActorInfo(spawnInfo);
    if (actorInfo == NULL)
    {
        return;
    }

    uint32_t modelInfo = EQ_ReadMemory<uint32_t>(actorInfo + EQ_OFFSET_ACTOR_INFO_MODEL_INFO);
    if (modelInfo == NULL)
    {
        return;
    }

    uint32_t boneList = EQ_ReadMemory<uint32_t>(modelInfo + EQ_OFFSET_MODEL_INFO_BONE_LIST);
    if (boneList == NULL)
    {
        return;
    }

    uint32_t firstBoneInfo = EQ_ReadMemory<uint32_t>(boneList + 0x00);
    if (firstBoneInfo == NULL)
    {
        return;
    }

    uint32_t firstBoneMagicNumber = EQ_ReadMemory<uint32_t>(firstBoneInfo + 0x00);
    if (firstBoneMagicNumber == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_BONES; i++)
    {
        uint32_t boneInfo = EQ_ReadMemory<uint32_t>(boneList + (i * 4));
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

        uint32_t boneMagicNumber = EQ_ReadMemory<uint32_t>(boneInfo + 0x00);
        if (boneMagicNumber == NULL)
        {
            continue;
        }

        if (boneMagicNumber != firstBoneMagicNumber)
        {
            continue;
        }

        float boneY = EQ_ReadMemory<float>(boneInfo + EQ_OFFSET_BONE_INFO_Y);
        float boneX = EQ_ReadMemory<float>(boneInfo + EQ_OFFSET_BONE_INFO_X);
        float boneZ = EQ_ReadMemory<float>(boneInfo + EQ_OFFSET_BONE_INFO_Z);

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

        if (g_espSkeletonDrawLinesIsEnabled == false)
        {
            // draw a line that looks like a dot instead of using text to get better performance
            EQ_DrawLine((float)screenX, (float)screenY, 1.0f, (float)screenX, (float)(screenY + 1.0f), 1.0f, colorARGB);
        }

        for (size_t j = 0; j < EQ_NUM_BONES; j++)
        {
            uint32_t boneChildInfo = EQ_ReadMemory<uint32_t>(boneInfo + EQ_OFFSET_BONE_INFO_CHILD_BONE_LIST + (j * 4));
            if (boneChildInfo == NULL)
            {
                break;
            }

            if ((boneChildInfo > (boneList + 0x4000)) || (boneChildInfo < boneList))
            {
                break;
            }

            if (boneChildInfo == firstBoneMagicNumber)
            {
                break;
            }

            uint32_t boneChildMagicNumber = EQ_ReadMemory<uint32_t>(boneChildInfo + 0x00);
            if (boneChildMagicNumber == NULL)
            {
                break;
            }

            if (boneChildMagicNumber != firstBoneMagicNumber)
            {
                break;
            }

            float boneChildY = EQ_ReadMemory<float>(boneChildInfo + EQ_OFFSET_BONE_INFO_Y);
            float boneChildX = EQ_ReadMemory<float>(boneChildInfo + EQ_OFFSET_BONE_INFO_X);
            float boneChildZ = EQ_ReadMemory<float>(boneChildInfo + EQ_OFFSET_BONE_INFO_Z);

            if (boneChildY == 0.0f || boneChildX == 0.0f || boneChildZ == 0.0f)
            {
                continue;
            }

            int screenChildX = -1;
            int screenChildY = -1;
            bool resultChild = EQ_WorldSpaceToScreenSpace(boneChildX, boneChildY, boneChildZ, screenChildX, screenChildY);
            if (resultChild == false)
            {
                continue;
            }

            if (g_espSkeletonDrawLinesIsEnabled == false)
            {
                // draw a line that looks like a dot instead of using text to get better performance
                EQ_DrawLine((float)screenChildX, (float)screenChildY, 1.0f, (float)screenChildX, (float)(screenChildY + 1.0f), 1.0f, colorARGB);
            }
            else
            {
                // draw a line to the next bone
                EQ_DrawLine((float)screenX, (float)screenY, 1.0f, (float)screenChildX, (float)screenChildY, 1.0f, colorARGB);
            }
        }

        if (g_espSkeletonDrawAddressesIsEnabled == true)
        {
            std::stringstream boneText;
            boneText << "0x" << std::hex << boneInfo << std::dec;
            EQ_DrawText(boneText.str().c_str(), screenX, screenY, colorARGB, 2);
        }
    }
}

