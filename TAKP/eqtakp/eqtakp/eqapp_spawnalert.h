#pragma once

bool g_spawnAlertIsEnabled = false;

void EQAPP_SpawnAlert_Toggle();
void EQAPP_SpawnAlert_PrintAlertMessage(EQ::Spawn_ptr spawn, bool bDespawn);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(class EQPlayer* player);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(EQ::ActorInstance_ptr actorInstance);

void EQAPP_SpawnAlert_Toggle()
{
    EQ_ToggleBool(g_spawnAlertIsEnabled);
    EQAPP_PrintBool("Spawn Alert", g_spawnAlertIsEnabled);
}

void EQAPP_SpawnAlert_PrintAlertMessage(EQ::Spawn_ptr spawn, bool bDespawn)
{
    if (spawn == NULL)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    std::stringstream spawnText;

    spawnText << spawnName;

    if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
    {
        if (bDespawn == false)
        {
            spawnText << " entered the zone.";
        }
        else
        {
            spawnText << " left the zone.";
        }
    }
    else if (spawn->Type == EQ_SPAWN_TYPE_NPC)
    {
        if (bDespawn == false)
        {
            spawnText << " spawned.";
        }
        else
        {
            spawnText << " despawned.";
        }
    }
    else if (spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || spawn->Type == EQ_SPAWN_TYPE_NPC_CORPSE)
    {
        if (bDespawn == true)
        {
            spawnText << " rotted.";
        }
    }

    if (spawn->Type != EQ_SPAWN_TYPE_PLAYER)
    {
        spawnText << " (ID: 0x" << std::hex << spawn->SpawnID << std::dec<< ", Loc: " << spawn->Y << ", " << spawn->Y << ", " << spawn->Z << ")";
    }

    std::cout << spawnText.str() << std::endl;
}

void EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(class EQPlayer* player)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (player == NULL)
    {
        return;
    }

    EQ::Spawn_ptr spawn = (EQ::Spawn_ptr)player;
    if (spawn == NULL || spawn == playerSpawn)
    {
        return;
    }

    // already spawned
    if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
    {
        if (EQ_DoesSpawnExist(spawn) == true)
        {
            return;
        }
    }

    if (EQ_IsSpawnGroupMember(spawn) == true)
    {
        return;
    }

    EQAPP_SpawnAlert_PrintAlertMessage(spawn, false);
}

void EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(EQ::ActorInstance_ptr actorInstance)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (actorInstance == NULL)
    {
        return;
    }

    EQ::Spawn_ptr spawn = actorInstance->Spawn;
    if (spawn == NULL || spawn == playerSpawn)
    {
        return;
    }

    if (EQ_IsSpawnGroupMember(spawn) == true)
    {
        return;
    }

    EQAPP_SpawnAlert_PrintAlertMessage(spawn, true);
}


