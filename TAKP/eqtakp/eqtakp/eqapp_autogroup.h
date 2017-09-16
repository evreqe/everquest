#pragma once

bool g_autoGroupIsEnabled = true;

uint32_t g_autoGroupTimer = 0;
uint32_t g_autoGroupTimerDelay = 3000;

void EQAPP_AutoGroup_Toggle()
{
    EQ_ToggleBool(g_autoGroupIsEnabled);
    EQAPP_PrintBool("Auto Group", g_autoGroupIsEnabled);
}

void EQAPP_AutoGroup_Execute()
{
    if (EQ_HasTimePassed(g_autoGroupTimer, g_autoGroupTimerDelay) == false)
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