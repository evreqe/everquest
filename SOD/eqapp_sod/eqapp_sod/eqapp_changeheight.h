#pragma once

bool g_changeHeightIsEnabled = true;
bool g_changeHeightPlayersIsEnabled = true;
bool g_changeHeightPetsIsEnabled = true;

float g_changeHeightDefaultSize = 5.0f;

float g_changeHeightPlayersSize = 5.0f;
float g_changeHeightPetsSize = 2.0f;

uint32_t g_changeHeightTimer = 0;
uint32_t g_changeHeightTimerDelay = 1000;

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

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        // players
        if (g_changeHeightPlayersIsEnabled == true)
        {
            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                float height = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_INFO_HEIGHT);
                if (height > g_changeHeightPlayersSize)
                {
                    EQ_SetSpawnHeight(spawn, g_changeHeightPlayersSize);

                    spawn = EQ_GetNextSpawn(spawn); // next
                    continue;
                }
            }
        }

        // pets
        if (g_changeHeightPetsIsEnabled == true)
        {
            bool isSpawnPlayerOwnedPet = false;

            uint32_t spawnIdPetOwner = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID);
            if (spawnIdPetOwner != 0)
            {
                uint32_t spawnInfoPetOwner = EQ_EQPlayerManager->GetSpawnByID(spawnIdPetOwner);
                if (spawnInfoPetOwner != NULL)
                {
                    int spawnTypePetOwner = EQ_ReadMemory<uint8_t>(spawnInfoPetOwner + EQ_OFFSET_SPAWN_INFO_TYPE);
                    if (spawnTypePetOwner == EQ_SPAWN_TYPE_PLAYER)
                    {
                        isSpawnPlayerOwnedPet = true;
                    }
                }
            }

            if (spawnType == EQ_SPAWN_TYPE_NPC && isSpawnPlayerOwnedPet == true)
            {
                EQ_SetSpawnHeight(spawn, g_changeHeightPetsSize);
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }
}

