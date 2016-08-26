#ifndef EQAPP_DOORS_H
#define EQAPP_DOORS_H

void EQAPP_Doors_OpenAll(bool bOpen);
void EQAPP_Doors_Print();

void EQAPP_Doors_OpenAll(bool bOpen)
{
    std::cout << "Setting open state for ALL doors to: " << std::boolalpha << bOpen << std::noboolalpha << std::endl;

    DWORD switchManager = EQ_ReadMemory<DWORD>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "switch manager is NULL");
        return;
    }

    DWORD numDoors = EQ_ReadMemory<DWORD>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
    if (numDoors == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "number of doors is zero");
        return;
    }

    for (size_t i = 0; i < numDoors; i++)
    {
        DWORD doorInfo = EQ_ReadMemory<DWORD>(switchManager + EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST + (i * 4));
        if (doorInfo == NULL)
        {
            continue;
        }

        if (bOpen == true)
        {
            EQ_Door_SetState(doorInfo, EQ_DOOR_STATE_OPEN);
        }
        else
        {
            EQ_Door_SetState(doorInfo, EQ_DOOR_STATE_CLOSED);
        }
    }
}

void EQAPP_Doors_Print()
{
    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "player spawn is NULL");
        return;
    }

    DWORD switchManager = EQ_ReadMemory<DWORD>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "switch manager is NULL");
        return;
    }

    DWORD numDoors = EQ_ReadMemory<DWORD>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
    if (numDoors == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "number of doors is zero");
        return;
    }

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    std::cout << "Door List:";

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

        char doorName[EQ_SIZE_DOOR_INFO_NAME] = {0};
        memcpy(doorName, (LPVOID)(doorInfo + EQ_OFFSET_DOOR_INFO_NAME), sizeof(doorName));

        if (strlen(doorName) == 0)
        {
            continue;
        }

        std::cout << "#" << i << ": " << doorName << std::endl;
    }
}

#endif // EQAPP_DOORS_H
