#pragma once

bool g_ChangeHeightIsEnabled = true;

EQApp::Timer g_ChangeHeightTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_ChangeHeightTimerInterval = 1;

float g_ChangeHeightMinimumHeight = 1.0f;
float g_ChangeHeightMaximumHeight = 5.0f;

void EQAPP_ChangeHeight_Toggle();
void EQAPP_ChangeHeight_On();
void EQAPP_ChangeHeight_Off();
void EQAPP_ChangeHeight_Execute();
bool EQAPP_ChangeHeight_SetSpawnHeight(uint32_t spawn);

void EQAPP_ChangeHeight_Toggle()
{
    EQ_ToggleBool(g_ChangeHeightIsEnabled);
    EQAPP_PrintBool("Change Height", g_ChangeHeightIsEnabled);
}

void EQAPP_ChangeHeight_On()
{
    if (g_ChangeHeightIsEnabled == false)
    {
        EQAPP_ChangeHeight_Toggle();
    }
}

void EQAPP_ChangeHeight_Off()
{
    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Toggle();
    }
}

void EQAPP_ChangeHeight_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_ChangeHeightTimer, g_ChangeHeightTimerInterval) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        EQAPP_ChangeHeight_SetSpawnHeight(playerSpawn);
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            bool result = EQAPP_ChangeHeight_SetSpawnHeight(spawn);
            if (result == true)
            {
                break;
            }
        }

        spawn = EQ_GetSpawnNext(spawn);
    }
}

bool EQAPP_ChangeHeight_SetSpawnHeight(uint32_t spawn)
{
    auto spawnHeight = EQ_GetSpawnHeight(spawn);

    if (spawnHeight < 1.0f)
    {
        return false;
    }

    if (spawnHeight > g_ChangeHeightMaximumHeight)
    {
        EQ_SetSpawnHeight(spawn, g_ChangeHeightMaximumHeight);

        return true;
    }

    if (spawnHeight < g_ChangeHeightMinimumHeight)
    {
        EQ_SetSpawnHeight(spawn, g_ChangeHeightMinimumHeight);

        return true;
    }

    return false;
}

