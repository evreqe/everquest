#pragma once

bool g_autoGroupIsEnabled = true;
uint32_t g_autoGroupTimer = 0;
uint32_t g_autoGroupTimerDelay = 2000;

void EQAPP_AutoGroup_Execute();

void EQAPP_AutoGroup_Execute()
{
    if (g_autoGroupIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_autoGroupTimer, g_autoGroupTimerDelay) == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    int isInvitedToGroup = EQ_ReadMemory<uint8_t>(EQ_BOOL_INVITED_TO_GROUP);

    int spawnIsInvitedToGroup = EQ_ReadMemory<uint8_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_IS_INVITED_TO_GROUP);

    if (isInvitedToGroup == 1 || spawnIsInvitedToGroup == 1)
    {
        EQ_AcceptGroupInvite();
    }
}

