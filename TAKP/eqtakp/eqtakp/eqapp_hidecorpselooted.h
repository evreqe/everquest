#pragma once

bool g_HideCorpseLootedIsEnabled = true;

void EQAPP_HideCorpseLooted_Toggle();
void EQAPP_HideCorpseLooted_HandleEvent_CLootWnd__Deactivate(void* this_ptr);

void EQAPP_HideCorpseLooted_Toggle()
{
    EQ_ToggleBool(g_HideCorpseLootedIsEnabled);
    EQAPP_PrintBool("Hide Corpse Looted", g_HideCorpseLootedIsEnabled);
}

void EQAPP_HideCorpseLooted_HandleEvent_CLootWnd__Deactivate(void* this_ptr)
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
