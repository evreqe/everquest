#ifndef EQAPP_AUTOGROUP_H
#define EQAPP_AUTOGROUP_H

bool g_autoGroupIsEnabled = true;
DWORD g_autoGroupTimer = 0;
DWORD g_autoGroupTimerDelay = 2000;

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

    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    int isInvitedToGroup = EQ_ReadMemory<BYTE>(EQ_BOOL_INVITED_TO_GROUP);

    int spawnIsInvitedToGroup = EQ_ReadMemory<BYTE>(playerSpawn + EQ_OFFSET_SPAWN_INFO_IS_INVITED_TO_GROUP);

    if (isInvitedToGroup == 1 || spawnIsInvitedToGroup == 1)
    {
        EQ_AcceptGroupInvite();
    }
}

#endif // EQAPP_AUTOGROUP_H
