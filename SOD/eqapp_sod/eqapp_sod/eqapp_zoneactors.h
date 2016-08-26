#ifndef EQAPP_ZONEACTORS_H
#define EQAPP_ZONEACTORS_H

void EQAPP_ZoneActors_Debug();

void EQAPP_ZoneActors_Debug()
{
    std::cout << "ESP Zone Actors Debug:" << std::endl;
    std::cout << "Saving zone actors to file..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << "eqapp/zoneactors/" << zoneShortName << ".txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
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

                DWORD zoneActor0x54 = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x54);

                FLOAT zoneActorY = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Y);
                FLOAT zoneActorX = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_X);
                FLOAT zoneActorZ = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Z);

                FLOAT zoneActorRotation = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION);
                FLOAT zoneActorScale = EQ_ReadMemory<FLOAT>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_SCALE);

                float zoneActorDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, zoneActorX, zoneActorY, zoneActorZ);

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

                std::cout << "Name: " << zoneActorName << std::endl;

                std::cout << "Distance: " << (int)zoneActorDistance << std::endl;

                std::cout << "Y: " << zoneActorY << std::endl;
                std::cout << "X: " << zoneActorX << std::endl;
                std::cout << "Z: " << zoneActorZ << std::endl;

                std::cout << "Rotation: " << zoneActorRotation << std::endl;
                std::cout << "Scale: " << zoneActorScale << std::endl;

                std::cout << "0x2C: " << zoneActor0x2C << std::endl;
                std::cout << "0x2D: " << zoneActor0x2D << std::endl;
                std::cout << "0x2E: " << zoneActor0x2E << std::endl;
                std::cout << "0x2F: " << zoneActor0x2F << std::endl;

                std::cout << "0x54: " << std::hex << zoneActor0x54 << std::dec << std::endl;

                std::cout << "Name Ex: " << zoneActorExName << std::endl;

                if (zoneActorSpawnInfo != NULL)
                {
                    std::cout << "Spawn Info: " << zoneActorSpawnInfo << std::endl;
                }

                std::cout << "Y1: " << zoneActorExY1 << std::endl;
                std::cout << "X1: " << zoneActorExX1 << std::endl;
                std::cout << "Z1: " << zoneActorExZ1 << std::endl;

                std::cout << "Y2: " << zoneActorExY2 << std::endl;
                std::cout << "X2: " << zoneActorExX2 << std::endl;
                std::cout << "Z2: " << zoneActorExZ2 << std::endl;

                std::cout << "Y3: " << zoneActorExY3 << std::endl;
                std::cout << "X3: " << zoneActorExX3 << std::endl;
                std::cout << "Z3: " << zoneActorExZ3 << std::endl;

                std::cout << "--------------------------------------------------" << std::endl;

                if (zoneActorSpawnInfo == NULL && zoneActorName.size() > 0)
                {
                    file << zoneActorName << " " << zoneActorY << " " << zoneActorX << " " << zoneActorZ << " " << zoneActorRotation << " " << zoneActorScale << std::endl;
                }

                zoneActor = EQ_ReadMemory<DWORD>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
            }
        }
    }

    file.close();
}

#endif // EQAPP_ZONEACTORS_H
