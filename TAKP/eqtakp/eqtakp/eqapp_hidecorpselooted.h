#pragma once

bool g_hideCorpseLootedIsEnabled = true;

void EQAPP_HideCorpseLooted_Execute();

void EQAPP_HideCorpseLooted_Execute()
{
    auto corpseSpawn = EQ_GetCorpseSpawn();
    if (corpseSpawn == nullptr)
    {
        return;
    }

    if (corpseSpawn->Type == EQ_SPAWN_TYPE_NPC_CORPSE)
    {
        corpseSpawn->Actor->IsInvisible = 1;
    }
}
