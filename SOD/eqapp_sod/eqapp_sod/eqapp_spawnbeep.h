#pragma once

bool g_spawnBeepIsEnabled = false;
std::string g_spawnBeepName;

void EQAPP_SpawnBeep_Execute(uint32_t spawnInfo);
void EQAPP_SpawnBeep_Print();
void EQAPP_SpawnBeep_Set(std::string spawnName);

void EQAPP_SpawnBeep_Execute(uint32_t spawnInfo)
{
    if (g_spawnBeepIsEnabled == false)
    {
        return;
    }

    if (spawnInfo == NULL)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(spawnInfo);

    if (spawnName.size() < EQ_SPAWN_NAME_LENGTH_MIN)
    {
        return;
    }

    for (auto& noBeep : g_noBeepList)
    {
        if (noBeep.size() != 0 && spawnName == noBeep)
        {
            return;
        }
    }

    for (auto& namedSpawn : g_namedSpawnsList)
    {
        if (namedSpawn.size() != 0 && spawnName.find(namedSpawn) != std::string::npos)
        {
            EQAPP_Beep();
            break;
        }
    }

    if (g_spawnBeepIsEnabled == true)
    {
        if (g_spawnBeepName.size() != 0 && spawnName.find(g_spawnBeepName) != std::string::npos)
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

