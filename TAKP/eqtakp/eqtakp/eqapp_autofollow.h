#pragma once

bool g_autoFollowIsEnabled = true;

uint32_t g_autoFollowTimer = 0;
uint32_t g_autoFollowTimerDelay = 500;

void EQAPP_AutoFollow_SetFollowDistanceToDefault();
void EQAPP_AutoFollow_SetFollowDistanceToZero();
void EQAPP_AutoFollow_HandleEvent__EQPlayer__FollowPlayerAI(void* this_ptr);

void EQAPP_AutoFollow_SetFollowDistanceToDefault()
{
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_ADD_1, EQ_FOLLOW_DISTANCE_ADD_1_DEFAULT);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_ADD_2, EQ_FOLLOW_DISTANCE_ADD_2_DEFAULT);
}

void EQAPP_AutoFollow_SetFollowDistanceToZero()
{
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_ADD_1, 0.0f);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_ADD_2, 0.0f);
}

void EQAPP_AutoFollow_HandleEvent__EQPlayer__FollowPlayerAI(void* this_ptr)
{
    bool bHasTimePassed = EQ_HasTimePassed(g_autoFollowTimer, g_autoFollowTimerDelay);

    auto thisSpawn = (EQ::Spawn_ptr)this_ptr;
    if (thisSpawn == NULL || thisSpawn->Actor == NULL)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL || thisSpawn != playerSpawn)
    {
        return;
    }

    auto followedSpawn = thisSpawn->Actor->FollowedSpawn;
    if (followedSpawn == NULL)
    {
        return;
    }

    if (followedSpawn->Type != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    EQAPP_AutoFollow_SetFollowDistanceToZero();


    if (followedSpawn->MovementSpeed != 0.0f)
    {
        float followedSpawnDistance = EQ_CalculateDistance(followedSpawn->X, followedSpawn->Y, playerSpawn->X, playerSpawn->Y);

        if (followedSpawnDistance <= 5.0f)
        {
            EQ_SetAutoRun(false);

            playerSpawn->Actor->MovementSpeedModifier = -0.1f;

            playerSpawn->MovementSpeed = 0.0f;
            playerSpawn->MovementSpeedX = 0.0f;
            playerSpawn->MovementSpeedY = 0.0f;
            playerSpawn->MovementSpeedZ = 0.0f;
            playerSpawn->MovementSpeedHeading = 0.0f;
        }

        if (bHasTimePassed == true && followedSpawnDistance > 7.0f)
        {
            EQ_SetAutoRun(true);
        }
    }
}

