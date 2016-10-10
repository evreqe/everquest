#pragma once

void EQAPP_Doors_OpenAll(bool bOpen);
void EQAPP_Doors_Print();

void EQAPP_Doors_OpenAll(bool bOpen)
{
    std::cout << "Setting open state for ALL doors to: " << std::boolalpha << bOpen << std::noboolalpha << std::endl;

    uint32_t switchManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "switch manager is NULL");
        return;
    }

    uint32_t numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
    if (numDoors == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "number of doors is zero");
        return;
    }

    for (size_t i = 0; i < numDoors; i++)
    {
        uint32_t doorInfo = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST + (i * 4));
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
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "player spawn is NULL");
        return;
    }

    uint32_t switchManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SWITCH_MANAGER);
    if (switchManager == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "switch manager is NULL");
        return;
    }

    uint32_t numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS);
    if (numDoors == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "number of doors is zero");
        return;
    }

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    std::cout << "Door List:";

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

        char doorName[EQ_SIZE_DOOR_INFO_NAME] = {0};
        memcpy(doorName, (void*)(doorInfo + EQ_OFFSET_DOOR_INFO_NAME), sizeof(doorName));

        if (strlen(doorName) == 0)
        {
            continue;
        }

        std::cout << "#" << i << ": " << doorName << std::endl;
    }
}

