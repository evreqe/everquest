#pragma once

bool g_changeHeightIsEnabled = true;

uint32_t g_changeHeightTimer = 0;
uint32_t g_changeHeightTimerDelay = 1000;

void EQAPP_ChangeHeight_Execute();

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
            if (spawn->Height > 5.0f)
            {
                ((EQClass::EQPlayer*)spawn)->ChangeHeight(5.0f);
            }
        }

        spawn = spawn->Next;
    }
}

