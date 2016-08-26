#ifndef EQAPP_SPAWNBEEP_H
#define EQAPP_SPAWNBEEP_H

bool g_spawnBeepIsEnabled = false;
std::string g_spawnBeepName;

void EQAPP_SpawnBeep_Execute(DWORD spawnInfo);
void EQAPP_SpawnBeep_Print();
void EQAPP_SpawnBeep_Set(std::string spawnName);

void EQAPP_SpawnBeep_Execute(DWORD spawnInfo)
{
    if (g_spawnBeepIsEnabled == false)
    {
        return;
    }

    if (spawnInfo == NULL)
    {
        return;
    }

    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
    memcpy(spawnName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

    if (strlen(spawnName) < EQ_SPAWN_NAME_LENGTH_MIN)
    {
        return;
    }

    for (auto& noBeep : g_noBeepList)
    {
        if (noBeep.size() != 0 && strcmp(spawnName, noBeep.c_str()) == 0)
        {
            return;
        }
    }

    for (auto& namedSpawn : g_namedSpawnsList)
    {
        if (namedSpawn.size() != 0 && strstr(spawnName, namedSpawn.c_str()) != NULL)
        {
            EQAPP_Beep();
            break;
        }
    }

    if (g_spawnBeepIsEnabled == true)
    {
        if (g_spawnBeepName.size() != 0 && strstr(spawnName, g_spawnBeepName.c_str()) != NULL)
        {
            EQAPP_Beep();
        }
    }
}

void EQAPP_SpawnBeep_Print()
{
    std::cout << "Spawn Beep: " << g_spawnBeepName << std::endl;
}

void EQAPP_SpawnBeep_Set(std::string spawnName)
{
    g_spawnBeepName = spawnName;
}

#endif // EQAPP_SPAWNBEEP_H
