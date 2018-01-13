#pragma once

#include "eqapp_boxchat.h"

bool g_CombatHotButtonIsEnabled = false;

std::chrono::time_point<std::chrono::steady_clock> g_CombatHotButtonTimer = std::chrono::steady_clock::now();
long long g_CombatHotButtonTimerInterval = 6;

void EQAPP_CombatHotButton_Toggle();
void EQAPP_CombatHotButton_Execute();

void EQAPP_CombatHotButton_Toggle()
{
    EQ_ToggleBool(g_CombatHotButtonIsEnabled);
    EQAPP_PrintBool("Combat HotButton", g_CombatHotButtonIsEnabled);
}

void EQAPP_CombatHotButton_Execute()
{
    if (EQAPP_HasTimeElapsed(g_CombatHotButtonTimer, g_CombatHotButtonTimerInterval) == false)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.size() != 0)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    int spawnType = EQ_ReadMemory<uint8_t>(targetSpawn + EQ_OFFSET_SPAWN_TYPE);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    int autoAttack = EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AUTO_ATTACK);
    if (autoAttack == 0)
    {
        return;
    }

    EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_4, 1);
}
