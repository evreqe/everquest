#ifndef EQAPP_TARGETBEEP_H
#define EQAPP_TARGETBEEP_H

bool g_targetBeepIsEnabled = false;
DWORD g_targetBeepTimer = 0;
DWORD g_targetBeepTimerDelay = 1000;
DWORD g_targetBeepTimerDelayInSeconds = 1;
std::string g_targetBeepName;

void EQAPP_TargetBeep_Execute();
void EQAPP_TargetBeep_Print();
void EQAPP_TargetBeep_Set(std::string spawnName, DWORD timerDelayInSeconds);

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

    DWORD targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
    memcpy(spawnName, (LPVOID)(targetSpawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

    if (strlen(spawnName) < EQ_SPAWN_NAME_LENGTH_MIN)
    {
        return;
    }

    if (g_targetBeepName.size() != 0 && strstr(spawnName, g_targetBeepName.c_str()) != NULL)
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

void EQAPP_TargetBeep_Set(std::string spawnName, DWORD timerDelayInSeconds)
{
    if (spawnName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "spawn name is NULL");
    }

    g_targetBeepName = spawnName;

    g_targetBeepTimerDelay = (DWORD)(timerDelayInSeconds * 1000); // convert seconds to milliseconds

    g_targetBeepTimerDelayInSeconds = timerDelayInSeconds;
}

#endif // EQAPP_TARGETBEEP_H
