#pragma once

bool g_ChangeHeightIsEnabled = true;

std::chrono::time_point<std::chrono::steady_clock> g_ChangeHeightTimer = std::chrono::steady_clock::now();
long long g_ChangeHeightTimerInterval = 3;

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
    if (EQAPP_HasTimeElapsed(g_ChangeHeightTimer, g_ChangeHeightTimerInterval) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_TYPE);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            float spawnHeight = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEIGHT);

            if (spawnHeight > g_ChangeHeightMaximumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMaximumHeight);
            }

            if (spawnHeight < g_ChangeHeightMinimumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMinimumHeight);
            }
        }

        spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
    }
}
