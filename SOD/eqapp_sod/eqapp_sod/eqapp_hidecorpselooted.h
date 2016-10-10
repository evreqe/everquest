#pragma once

bool g_hideCorpseLootedIsEnabled = true;
uint32_t g_hideCorpseLootedTimer = 0;
uint32_t g_hideCorpseLootedTimerDelay = 1000;

void EQAPP_HideCorpseLooted_Execute();

void EQAPP_HideCorpseLooted_Execute()
{
    if (g_hideCorpseLootedIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_hideCorpseLootedTimer, g_hideCorpseLootedTimerDelay) == false)
    {
        return;
    }

    EQ_SetHideCorpseLooted(true);
}

