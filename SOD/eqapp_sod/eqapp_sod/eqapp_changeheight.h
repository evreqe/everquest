#ifndef EQAPP_CHANGEHEIGHT_H
#define EQAPP_CHANGEHEIGHT_H

bool g_changeHeightIsEnabled = true;
float g_changeHeightMinimum = 1.0f;
float g_changeHeightMaximum = 5.0f;
DWORD g_changeHeightTimer = 0;
DWORD g_changeHeightTimerDelay = 1000;

void EQAPP_ChangeHeight_Execute();

void EQAPP_ChangeHeight_Execute()
{
    if (g_changeHeightIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_changeHeightTimer, g_changeHeightTimerDelay) == false)
    {
        return;
    }

    DWORD spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        // shrink players
        int spawnType = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            float height = EQ_ReadMemory<FLOAT>(spawn + EQ_OFFSET_SPAWN_INFO_HEIGHT);
            if (height > g_changeHeightMaximum)
            {
                EQ_SetSpawnHeight(spawn, g_changeHeightMaximum);

                spawn = EQ_GetNextSpawn(spawn); // next
                continue;
            }
        }

        // shrink player pets
        bool isSpawnPlayerOwnedPet = false;

        DWORD spawnPetOwnerSpawnId = EQ_ReadMemory<DWORD>(spawn + EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID);
        if (spawnPetOwnerSpawnId != 0)
        {
            DWORD spawnPetOwnerSpawnInfo = EQ_EQPlayerManager->GetSpawnByID(spawnPetOwnerSpawnId);
            if (spawnPetOwnerSpawnInfo != NULL)
            {
                int spawnType = EQ_ReadMemory<BYTE>(spawnPetOwnerSpawnInfo + EQ_OFFSET_SPAWN_INFO_TYPE);
                if (spawnType == EQ_SPAWN_TYPE_PLAYER)
                {
                    isSpawnPlayerOwnedPet = true;
                }
            }
        }

        if (spawnType == EQ_SPAWN_TYPE_NPC && isSpawnPlayerOwnedPet == true)
        {
            EQ_SetSpawnHeight(spawn, g_changeHeightMinimum);
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }
}

#endif // EQAPP_CHANGEHEIGHT_H
