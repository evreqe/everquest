#pragma once

bool g_FollowAIIsEnabled = true;

bool g_FollowAIUseZAxisIsEnabled = false;

float g_FollowAIDistancePlayer = 15.0f;
float g_FollowAIDistanceNPC    = 10.0f;
float g_FollowAIDistanceCorpse = 5.0f;

void EQAPP_FollowAI_Toggle();
void EQAPP_FollowAI_Execute();

void EQAPP_FollowAI_Toggle()
{
    EQ_ToggleBool(g_FollowAIIsEnabled);
    EQAPP_PrintBool("Follow AI", g_FollowAIIsEnabled);

    if (g_FollowAIIsEnabled == false)
    {
        EQ_StopFollow();
    }
}

void EQAPP_FollowAI_UseZAxis_Toggle()
{
    EQ_ToggleBool(g_FollowAIUseZAxisIsEnabled);
    EQAPP_PrintBool("Follow AI Use Z-Axis", g_FollowAIUseZAxisIsEnabled);

    // look forward
    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
    EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);
}

void EQAPP_FollowAI_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto followSpawn = EQ_GetSpawnFollowSpawn(playerSpawn);
    if (followSpawn == NULL)
    {
        return;
    }

    EQ_TurnPlayerTowardsSpawn(followSpawn);

    float followSpawnDistance = EQ_GetSpawnDistance(followSpawn);

    auto followSpawnType = EQ_GetSpawnType(followSpawn);

    if (followSpawnType = EQ_SPAWN_TYPE_PLAYER)
    {
        if (followSpawnDistance < g_FollowAIDistancePlayer)
        {
            EQ_SetAutoRun(false);
            return;
        }
    }
    else if (followSpawnType = EQ_SPAWN_TYPE_NPC)
    {
        if (followSpawnDistance < g_FollowAIDistanceNPC)
        {
            EQ_SetAutoRun(false);
            return;
        }
    }
    else if (followSpawnType = EQ_SPAWN_TYPE_CORPSE)
    {
        if (followSpawnDistance < g_FollowAIDistanceCorpse)
        {
            EQ_SetAutoRun(false);
            return;
        }
    }

    EQ_SetAutoRun(true);

    if (g_FollowAIUseZAxisIsEnabled == true)
    {
        auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);
        auto followSpawnZ = EQ_GetSpawnZ(followSpawn);

        if ((followSpawnZ - 1.0f) > playerSpawnZ)
        {
            // look up
            EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
            EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHUP, 1);
        }
        else if ((followSpawnZ + 1.0f) < playerSpawnZ)
        {
            // look down
            EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
            EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHDOWN, 1);
        }
        else
        {
            // look forward
            EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
            EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);
        }
    }
}
