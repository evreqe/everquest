#pragma once

bool g_changeHeightIsEnabled = true;

uint32_t g_changeHeightTimer = 0;
uint32_t g_changeHeightTimerDelay = 1000;

float g_changeHeightMaximumHeight = 5.0f;

void EQAPP_ChangeHeight_Toggle();
void EQAPP_ChangeHeight_Execute();

void EQAPP_ChangeHeight_Toggle()
{
    EQ_ToggleBool(g_changeHeightIsEnabled);
    EQAPP_PrintBool("Change Height", g_changeHeightIsEnabled);
}

void EQAPP_ChangeHeight_Execute()
{
    if (EQ_HasTimePassed(g_changeHeightTimer, g_changeHeightTimerDelay) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawn->Height > g_changeHeightMaximumHeight)
            {
                ((EQClass::EQPlayer*)spawn)->ChangeHeight(g_changeHeightMaximumHeight);
            }
        }

        spawn = spawn->Next;
    }
}

