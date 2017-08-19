#pragma once

bool g_spawnAlertIsEnabled = false;

std::vector<uint16_t> g_spawnAlertSpawnIDList;

void EQAPP_SpawnAlert_Toggle();
void EQAPP_SpawnAlert_PrintAlertMessage(EQ::Spawn_ptr spawn, bool bDespawn);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(void* this_ptr, class EQPlayer* player);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(void* this_ptr, EQ::ActorInstance_ptr actorInstance);

void EQAPP_SpawnAlert_Toggle()
{
    EQ_ToggleBool(g_spawnAlertIsEnabled);
    EQAPP_PrintBool("Spawn Alert", g_spawnAlertIsEnabled);

    g_spawnAlertSpawnIDList.clear();
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

    spawnText << "[Spawn Alert] " << spawnName;

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

            bool bAlreadyExists = false;

            for (auto& spawnID : g_spawnAlertSpawnIDList)
            {
                if (spawnID == spawn->SpawnID)
                {
                    bAlreadyExists = true;
                    break;
                }
            }

            if (bAlreadyExists == false)
            {
                g_spawnAlertSpawnIDList.push_back(spawn->SpawnID);
            }
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

void EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(void* this_ptr, class EQPlayer* player)
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

    EQAPP_SpawnAlert_PrintAlertMessage(spawn, false);
}

void EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(void* this_ptr, EQ::ActorInstance_ptr actorInstance)
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

    if (actorInstance->MagicNumber != 24 || actorInstance == (EQ::ActorInstance_ptr)EQ_ADDRESS_POINTER_CAMERA_ACTOR_INSTANCE)
    {
        return;
    }

    if (actorInstance->ActorDefinition == NULL)
    {
        return;
    }

    if (actorInstance->ActorDefinition->MagicNumber6 != 17)
    {
        return;
    }

    if (actorInstance->UserData == NULL)
    {
        return;
    }

    if (actorInstance->UserData->MagicNumber != 3)
    {
        return;
    }

    EQ::Spawn_ptr spawn = actorInstance->Spawn;
    if (spawn == NULL || spawn == playerSpawn)
    {
        return;
    }

    EQAPP_SpawnAlert_PrintAlertMessage(spawn, true);
}


