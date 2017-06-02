#pragma once

bool g_hideCorpseLootedIsEnabled = true;

void EQAPP_HideCorpseLooted_Toggle();
void EQAPP_HideCorpseLooted_Execute();

void EQAPP_HideCorpseLooted_Toggle()
{
    EQ_ToggleBool(g_hideCorpseLootedIsEnabled);
    EQAPP_PrintBool("Hide Corpse Looted", g_hideCorpseLootedIsEnabled);
}

void EQAPP_HideCorpseLooted_Execute()
{
    auto corpseSpawn = EQ_GetCorpseSpawn();
    if (corpseSpawn == NULL)
    {
        return;
    }

    if (corpseSpawn->Type == EQ_SPAWN_TYPE_NPC_CORPSE)
    {
        corpseSpawn->Actor->IsInvisible = 1;
    }
}
