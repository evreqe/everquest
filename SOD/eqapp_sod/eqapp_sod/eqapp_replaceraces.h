#ifndef EQAPP_REPLACERACES_H
#define EQAPP_REPLACERACES_H

bool g_replaceRacesIsEnabled = true;

void EQAPP_ReplaceRaces_Execute();

void EQAPP_ReplaceRaces_Execute()
{
    if (g_replaceRacesIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    DWORD spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnGender = EQ_ReadMemory<BYTE>(playerSpawn + EQ_OFFSET_SPAWN_INFO_GENDER);

        int spawnRace = EQ_ReadMemory<DWORD>(playerSpawn + EQ_OFFSET_SPAWN_INFO_RACE);

        if (spawnRace == EQ_RACE_INVISIBLE_MAN)
        {
            EQ_SetSpawnForm(spawn, EQ_RACE_HUMAN, spawnGender);
        }
        else if (spawnRace == EQ_RACE_SKELETON)
        {
            EQ_SetSpawnForm(spawn, EQ_RACE_SKELETON2, spawnGender);
        }

        if (spawn == playerSpawn)
        {
            if (spawnRace == EQ_RACE_CHOKADAI)
            {
                EQ_SetSpawnForm(spawn, EQ_RACE_HUMAN, spawnGender);
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }
}

#endif // EQAPP_REPLACERACES_H
