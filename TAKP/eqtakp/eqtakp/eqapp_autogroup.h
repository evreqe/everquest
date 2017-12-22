#pragma once

bool g_AutoGroupIsEnabled = true;

uint32_t g_AutoGroupTimer = 0;
uint32_t g_AutoGroupTimerDelay = 3000;

void EQAPP_AutoGroup_Toggle()
{
    EQ_ToggleBool(g_AutoGroupIsEnabled);
    EQAPP_PrintBool("Auto Group", g_AutoGroupIsEnabled);
}

void EQAPP_AutoGroup_Execute()
{
    if (EQ_HasTimePassed(g_AutoGroupTimer, g_AutoGroupTimerDelay) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto player = (EQClass::EQPlayer*)playerSpawn;
    if (player == NULL)
    {
        return;
    }

    if (player->IsInvited() == true)
    {
        EQ_CLASS_POINTER_CEverQuest->Follow();
    }
}