#pragma once

bool g_targetBeepIsEnabled = false;
uint32_t g_targetBeepTimer = 0;
uint32_t g_targetBeepTimerDelay = 1000;
uint32_t g_targetBeepTimerDelayInSeconds = 1;
std::string g_targetBeepName;

void EQAPP_TargetBeep_Execute();
void EQAPP_TargetBeep_Print();
void EQAPP_TargetBeep_Set(std::string spawnName, uint32_t timerDelayInSeconds);

void EQAPP_TargetBeep_Execute()
{
    if (g_targetBeepIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_targetBeepTimer, g_targetBeepTimerDelay) == false)
    {
        return;
    }

    uint32_t targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(targetSpawn);

    if (spawnName.size() < EQ_SPAWN_NAME_LENGTH_MIN)
    {
        return;
    }

    if (g_targetBeepName.size() != 0 && spawnName.find(g_targetBeepName) != std::string::npos)
    {
        EQAPP_Beep();
    }
}

void EQAPP_TargetBeep_Print()
{
    if (g_targetBeepTimerDelay == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "timer delay is zero");
        return;
    }

    std::cout << "Target Beep: " <<  g_targetBeepName << " (" << g_targetBeepTimerDelayInSeconds << " second(s))" << std::endl;
}

void EQAPP_TargetBeep_Set(std::string spawnName, uint32_t timerDelayInSeconds)
{
    if (spawnName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "spawn name is NULL");
    }

    g_targetBeepName = spawnName;

    g_targetBeepTimerDelay = (uint32_t)(timerDelayInSeconds * 1000); // convert seconds to milliseconds

    g_targetBeepTimerDelayInSeconds = timerDelayInSeconds;
}

