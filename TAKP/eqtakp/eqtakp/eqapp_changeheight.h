#pragma once

bool g_ChangeHeightIsEnabled = true;

uint32_t g_ChangeHeightTimer = 0;
uint32_t g_ChangeHeightTimerDelay = 1000;

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
    if (EQ_HasTimePassed(g_ChangeHeightTimer, g_ChangeHeightTimerDelay) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawn->Height > g_ChangeHeightMaximumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMaximumHeight);
            }

            if (spawn->Height < g_ChangeHeightMinimumHeight)
            {
                EQ_SetSpawnHeight(spawn, g_ChangeHeightMinimumHeight);
            }
        }

        spawn = spawn->Next;
    }
}

