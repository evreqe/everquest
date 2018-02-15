#pragma once

bool g_ChangeHeightIsEnabled = true;

EQApp::Timer g_ChangeHeightTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_ChangeHeightTimerInterval = 3;

float g_ChangeHeightMinimumHeight = 1.0f;
float g_ChangeHeightMaximumHeight = 5.0f;

void EQAPP_ChangeHeight_Toggle();
void EQAPP_ChangeHeight_Execute();

void EQAPP_ChangeHeight_Toggle()
{
    EQ_ToggleBool(g_ChangeHeightIsEnabled);
    EQAPP_PrintBool("Change Height", g_ChangeHeightIsEnabled);
}

void EQAPP_ChangeHeight_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_ChangeHeightTimer, g_ChangeHeightTimerInterval) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            auto spawnHeight = EQ_GetSpawnHeight(spawn);

            if (spawnHeight > g_ChangeHeightMaximumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMaximumHeight);
            }

            if (spawnHeight < g_ChangeHeightMinimumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMinimumHeight);
            }
        }

        spawn = EQ_GetSpawnNext(spawn);
    }
}
