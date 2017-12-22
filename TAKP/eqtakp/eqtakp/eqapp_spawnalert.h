#pragma once

bool g_SpawnAlertIsEnabled = false;

bool g_SpawnAlertShowNewSpawn = false;
bool g_SpawnAlertShowPlayer = true;
bool g_SpawnAlertShowNPC = false;
bool g_SpawnAlertShowCorpse = false;

std::vector<EQ_SpawnID_t> g_SpawnAlertNewSpawnIDList;

void EQAPP_SpawnAlert_Toggle();
void EQAPP_SpawnAlert_ShowNewSpawn_Toggle();
void EQAPP_SpawnAlert_ShowPlayer_Toggle();
void EQAPP_SpawnAlert_ShowNPC_Toggle();
void EQAPP_SpawnAlert_ShowCorpse_Toggle();
void EQAPP_SpawnAlert_PrintAlertMessage(EQ::Spawn_ptr spawn, bool bDespawn);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(void* this_ptr, class EQPlayer* player);
void EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(void* this_ptr, EQ::ActorInstance_ptr actorInstance);

void EQAPP_SpawnAlert_Toggle()
{
    EQ_ToggleBool(g_SpawnAlertIsEnabled);
    EQAPP_PrintBool("Spawn Alert", g_SpawnAlertIsEnabled);
}

void EQAPP_SpawnAlert_ShowNewSpawn_Toggle()
{
    EQ_ToggleBool(g_SpawnAlertShowNewSpawn);
    EQAPP_PrintBool("Spawn Alert Show New Spawn", g_SpawnAlertShowNewSpawn);

    g_SpawnAlertNewSpawnIDList.clear();
}

void EQAPP_SpawnAlert_ShowPlayer_Toggle()
{
    EQ_ToggleBool(g_SpawnAlertShowPlayer);
    EQAPP_PrintBool("Spawn Alert Show Player", g_SpawnAlertShowPlayer);
}

void EQAPP_SpawnAlert_ShowNPC_Toggle()
{
    EQ_ToggleBool(g_SpawnAlertShowNPC);
    EQAPP_PrintBool("Spawn Alert Show NPC", g_SpawnAlertShowNPC);
}

void EQAPP_SpawnAlert_ShowCorpse_Toggle()
{
    EQ_ToggleBool(g_SpawnAlertShowCorpse);
    EQAPP_PrintBool("Spawn Alert Show Corpse", g_SpawnAlertShowCorpse);
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

    bool bIsPlayer = false;
    bool bIsNPC = false;
    bool bIsCorpse = false;

    std::stringstream spawnText;

    spawnText << "[Spawn Alert] " << spawnName;

    if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
    {
        bIsPlayer = true;

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
        bIsNPC = true;

        if (bDespawn == false)
        {
            spawnText << " spawned.";

            if (g_SpawnAlertShowNewSpawn == true)
            {
                bool bAlreadyExists = false;

                for (auto& spawnID : g_SpawnAlertNewSpawnIDList)
                {
                    if (spawnID == spawn->SpawnID)
                    {
                        bAlreadyExists = true;
                        break;
                    }
                }

                if (bAlreadyExists == false)
                {
                    g_SpawnAlertNewSpawnIDList.push_back(spawn->SpawnID);
                }
            }
        }
        else
        {
            spawnText << " despawned.";
        }
    }
    else if (spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || spawn->Type == EQ_SPAWN_TYPE_NPC_CORPSE)
    {
        bIsCorpse = true;

        if (bDespawn == true)
        {
            spawnText << " rotted.";
        }
    }

    if (spawn->Type != EQ_SPAWN_TYPE_PLAYER)
    {
        spawnText << " (ID: 0x" << std::hex << spawn->SpawnID << std::dec<< ", Loc: " << spawn->Y << ", " << spawn->Y << ", " << spawn->Z << ")";
    }

    auto zoneID = EQ_GetZoneID();

    if (bIsPlayer == true && (zoneID == EQ_ZONE_ID_POKNOWLEDGE || zoneID == EQ_ZONE_ID_BAZAAR))
    {
        return;
    }

    if (bIsPlayer == true && g_SpawnAlertShowPlayer == false)
    {
        return;
    }

    if (bIsNPC == true && g_SpawnAlertShowNPC == false)
    {
        return;
    }

    if (bIsCorpse == true && g_SpawnAlertShowCorpse == false)
    {
        return;
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


