#pragma once

extern void EQAPP_FindPath_FollowPath_Off();
extern void EQAPP_Waypoint_FollowPath_Off();

bool g_FollowAIIsEnabled = true;

bool g_FollowAIUseZAxisIsEnabled = false;

bool g_FollowAIBehindIsEnabled = false;

float g_FollowAIDistancePlayer = 10.0f;
float g_FollowAIDistanceNPC    = 10.0f;
float g_FollowAIDistanceCorpse = 10.0f;
float g_FollowAIDistanceBehind = 5.0f;

uint32_t g_FollowAISpawn = NULL;

void EQAPP_FollowAI_Toggle();
void EQAPP_FollowAI_On();
void EQAPP_FollowAI_Off();
void EQAPP_FollowAI_UseZAxis_Toggle();
void EQAPP_FollowAI_UseZAxis_On();
void EQAPP_FollowAI_UseZAxis_Off();
void EQAPP_FollowAI_Behind_Toggle();
void EQAPP_FollowAI_Behind_On();
void EQAPP_FollowAI_Behind_Off();
void EQAPP_FollowAI_Execute();
bool EQAPP_FollowAI_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FollowAI_Toggle()
{
    EQ_ToggleBool(g_FollowAIIsEnabled);
    EQAPP_PrintBool("Follow AI", g_FollowAIIsEnabled);

    if (g_FollowAIIsEnabled == false)
    {
        EQ_StopFollow();

        g_FollowAISpawn = NULL;
    }
}

void EQAPP_FollowAI_On()
{
    if (g_FollowAIIsEnabled == false)
    {
        EQAPP_FollowAI_Toggle();
    }
}

void EQAPP_FollowAI_Off()
{
    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Toggle();
    }
}

void EQAPP_FollowAI_UseZAxis_Toggle()
{
    EQ_ToggleBool(g_FollowAIUseZAxisIsEnabled);
    EQAPP_PrintBool("Follow AI Use Z-Axis", g_FollowAIUseZAxisIsEnabled);

    EQ_SetCameraType(EQ_CAMERA_TYPE_FIRST_PERSON);
    EQ_CenterView();
}

void EQAPP_FollowAI_UseZAxis_On()
{
    if (g_FollowAIUseZAxisIsEnabled == false)
    {
        EQAPP_FollowAI_UseZAxis_Toggle();
    }
}

void EQAPP_FollowAI_UseZAxis_Off()
{
    if (g_FollowAIUseZAxisIsEnabled == true)
    {
        EQAPP_FollowAI_UseZAxis_Toggle();
    }
}

void EQAPP_FollowAI_Behind_Toggle()
{
    EQ_ToggleBool(g_FollowAIBehindIsEnabled);
    EQAPP_PrintBool("Follow AI Behind", g_FollowAIBehindIsEnabled);
}

void EQAPP_FollowAI_Behind_On()
{
    if (g_FollowAIBehindIsEnabled == false)
    {
        EQAPP_FollowAI_Behind_Toggle();
    }
}

void EQAPP_FollowAI_Behind_Off()
{
    if (g_FollowAIBehindIsEnabled == true)
    {
        EQAPP_FollowAI_Behind_Toggle();
    }
}

void EQAPP_FollowAI_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (playerSpawn != NULL)
    {
        auto playerHPCurrent = EQ_GetSpawnHPCurrent(playerSpawn);
        if (playerHPCurrent <= 0)
        {
            g_FollowAISpawn = NULL;
            EQ_SetAutoRun(false);

            return;
        }
    }

    //auto followSpawn = EQ_GetSpawnFollowSpawn(playerSpawn);
    //if (followSpawn == NULL)
    //{
        //return;
    //}

    if (EQ_DoesSpawnExist(g_FollowAISpawn) == false)
    {
        return;
    }

    auto followSpawn = g_FollowAISpawn;
    if (followSpawn == NULL)
    {
        return;
    }
    else
    {
        if (EQ_IsAutoRunEnabled() == true)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn == NULL || targetSpawn == playerSpawn)
            {
                g_FollowAISpawn = NULL;
                EQ_SetAutoRun(false);

                return;
            }

            if (targetSpawn != NULL)
            {
                auto targetType = EQ_GetSpawnType(targetSpawn);
                if (targetType == EQ_SPAWN_TYPE_CORPSE)
                {
                    g_FollowAISpawn = NULL;
                    EQ_SetAutoRun(false);

                    return;
                }

                auto targetHPCurrent = EQ_GetSpawnHPCurrent(targetSpawn);
                if (targetHPCurrent <= 0)
                {
                    g_FollowAISpawn = NULL;
                    EQ_SetAutoRun(false);

                    return;
                }
            }
        }
    }

    EQAPP_FindPath_FollowPath_Off();
    EQAPP_Waypoint_FollowPath_Off();

    bool bFollowBehind = false;
    bool bFollowBehindCanCastRay = false;

    float playerSpawnY = EQ_GetSpawnY(playerSpawn);
    float playerSpawnX = EQ_GetSpawnX(playerSpawn);
    float playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    float followSpawnY = EQ_GetSpawnY(followSpawn);
    float followSpawnX = EQ_GetSpawnX(followSpawn);
    float followSpawnZ = EQ_GetSpawnZ(followSpawn);

    float followSpawnHeading = EQ_GetSpawnHeading(followSpawn);

    auto followSpawnType = EQ_GetSpawnType(followSpawn);

    if (followSpawnType == EQ_SPAWN_TYPE_NPC)
    {
        if (g_FollowAIBehindIsEnabled == true)
        {
            bFollowBehind = true;
        }

        auto playerSpawnClass = EQ_GetSpawnClass(playerSpawn);
        if (playerSpawnClass == EQ_CLASS_ROGUE)
        {
            bFollowBehind = true;
        }
    }

    float behindSpawnY = followSpawnY;
    float behindSpawnX = followSpawnX;
    float behindSpawnZ = followSpawnZ;

    float behindSpawnHeading = followSpawnHeading;

    if (bFollowBehind == true)
    {
        EQ_ApplyBackwardMovement(behindSpawnY, behindSpawnX, behindSpawnHeading, g_FollowAIDistanceBehind);

        bool bFollowSpawnCastRay = EQ_CanSpawnCastRayToLocation(playerSpawn, followSpawnY, followSpawnX, followSpawnZ);

        uint32_t followSpawnLineColorARGB = 0xFFFF0000; // red
        if (bFollowSpawnCastRay == true)
        {
            followSpawnLineColorARGB = 0xFF00FF00; // green
        }

        EQ_DrawLine3D(playerSpawnY, playerSpawnX, playerSpawnZ, followSpawnY, followSpawnX, followSpawnZ, followSpawnLineColorARGB);

        bFollowBehindCanCastRay = EQ_CanSpawnCastRayToLocation(playerSpawn, behindSpawnY, behindSpawnX, behindSpawnZ);

        uint32_t behindSpawnLineColorARGB = 0xFF800000; // dark red
        if (bFollowBehindCanCastRay == true)
        {
            behindSpawnLineColorARGB = 0xFF008000; // dark green
        }

        EQ_DrawLine3D(playerSpawnY, playerSpawnX, playerSpawnZ, behindSpawnY, behindSpawnX, behindSpawnZ, behindSpawnLineColorARGB);
    }

    if (bFollowBehind == true && bFollowBehindCanCastRay == true)
    {
        EQ_TurnSpawnTowardsLocation(playerSpawn, behindSpawnY, behindSpawnX);

        float behindSpawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, behindSpawnY, behindSpawnX);
        if (behindSpawnDistance < 1.0f)
        {
            EQ_SetAutoRun(false);
            EQ_TurnPlayerTowardsSpawn(followSpawn);
            return;
        }
    }
    else
    {
        EQ_TurnPlayerTowardsSpawn(followSpawn);

        float followSpawnDistance = EQ_GetSpawnDistance(followSpawn);

        if (followSpawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            if (followSpawnDistance < g_FollowAIDistancePlayer)
            {
                EQ_SetAutoRun(false);
                return;
            }
        }
        else if (followSpawnType == EQ_SPAWN_TYPE_NPC)
        {
            if (followSpawnDistance < g_FollowAIDistanceNPC)
            {
                EQ_SetAutoRun(false);
                return;
            }
        }
        else if (followSpawnType == EQ_SPAWN_TYPE_CORPSE)
        {
            if (followSpawnDistance < g_FollowAIDistanceCorpse)
            {
                EQ_SetAutoRun(false);
                return;
            }
        }
    }

    EQ_SetAutoRun(true);

    bool isPlayerFlyingLevitatingOrSwimming =
    (
        EQ_GetSpawnGravityType(playerSpawn) == EQ_GRAVITY_TYPE_FLYING ||
        EQ_GetSpawnGravityType(playerSpawn) == EQ_GRAVITY_TYPE_LEVITATING ||
        EQ_GetSpawnGravityType(playerSpawn) == EQ_GRAVITY_TYPE_SWIMMING
    );

    // follow while swimming or levitating
    if (g_FollowAIUseZAxisIsEnabled == true || EQ_IsSpawnSwimming(playerSpawn) == true || isPlayerFlyingLevitatingOrSwimming == true)
    {
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
    else
    {
        if (EQ_GetCameraType() == EQ_CAMERA_TYPE_FIRST_PERSON)
        {
            // look forward
            EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);
        }
    }
}

bool EQAPP_FollowAI_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1)
    {
        return false;
    }

    if
    (
        commandID == EQ_EXECUTECMD_SIT_STAND  ||
        commandID == EQ_EXECUTECMD_DUCK       ||
        commandID == EQ_EXECUTECMD_JUMP       ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        g_FollowAISpawn = NULL;
        return false;
    }

    return false;
}
