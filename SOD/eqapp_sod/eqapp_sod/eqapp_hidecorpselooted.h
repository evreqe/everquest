#pragma once

bool g_hideCorpseLootedIsEnabled = true;

void EQAPP_HideCorpseLooted_Execute();

void EQAPP_HideCorpseLooted_Execute()
{
    if (g_hideCorpseLootedIsEnabled == false)
    {
        return;
    }

    EQ_SetHideCorpseLooted(true);
}

