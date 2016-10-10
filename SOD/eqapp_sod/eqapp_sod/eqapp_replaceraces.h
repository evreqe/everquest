#pragma once

bool g_replaceRacesIsEnabled = true;
uint32_t g_replaceRacesTimer = 0;
uint32_t g_replaceRacesTimerDelay = 1000;

void EQAPP_ReplaceRaces_Execute();

void EQAPP_ReplaceRaces_Execute()
{
    if (g_replaceRacesIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_replaceRacesTimer, g_replaceRacesTimerDelay) == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        int spawnGender = EQ_ReadMemory<uint8_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_GENDER);

        uint32_t spawnRace = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_RACE);

        if (spawnRace == EQ_RACE_INVISIBLE_MAN)
        {
            EQ_SetSpawnForm(spawn, EQ_RACE_HUMAN, spawnGender);
        }
        else if (spawnRace == EQ_RACE_SKELETON)
        {
            EQ_SetSpawnForm(spawn, EQ_RACE_SKELETON2, spawnGender);
        }

        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawnRace == EQ_RACE_CHOKADAI)
            {
                EQ_SetSpawnForm(spawn, EQ_RACE_HUMAN, spawnGender);
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }
}

