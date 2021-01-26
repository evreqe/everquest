#pragma once

bool g_CombatHotButtonIsEnabled = false;

EQApp::Timer g_CombatHotButtonTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_CombatHotButtonTimerInterval = 6;

signed int g_CombatHotButtonIndex = 3; // -1;

float g_CombatHotButtonDistance = 25.0f;

void EQAPP_CombatHotButton_Toggle();
void EQAPP_CombatHotButton_On();
void EQAPP_CombatHotButton_Off();
void EQAPP_CombatHotButton_SetIndex(signed int index);
void EQAPP_CombatHotButton_Execute();

void EQAPP_CombatHotButton_Toggle()
{
    EQ_ToggleBool(g_CombatHotButtonIsEnabled);
    EQAPP_PrintBool("Combat HotButton", g_CombatHotButtonIsEnabled);
}

void EQAPP_CombatHotButton_On()
{
    if (g_CombatHotButtonIsEnabled == false)
    {
        EQAPP_CombatHotButton_Toggle();
    }
}

void EQAPP_CombatHotButton_Off()
{
    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_CombatHotButton_Toggle();
    }
}

void EQAPP_CombatHotButton_SetIndex(signed int index)
{
    g_CombatHotButtonIndex = index;
}

void EQAPP_CombatHotButton_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInSeconds(g_CombatHotButtonTimer, g_CombatHotButtonTimerInterval) == false)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.empty() == false)
    {
        return;
    }

    if (EQ_IsAutoAttackEnabled() == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetSpawnType = EQ_GetSpawnType(targetSpawn);
    if (targetSpawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    float targetSpawnDistance = EQ_GetSpawnDistance(targetSpawn);
    if (targetSpawnDistance > g_CombatHotButtonDistance)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerSpawnStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    if (g_CombatHotButtonIndex < 0 || g_CombatHotButtonIndex > (EQ_NUM_HOTBAR_BUTTONS - 1))
    {
        return;
    }

    signed int command = -1;

    switch (g_CombatHotButtonIndex)
    {
        case 0:
            command = EQ_EXECUTECMD_HOT1_1;
            break;

        case 1:
            command = EQ_EXECUTECMD_HOT1_2;
            break;

        case 2:
            command = EQ_EXECUTECMD_HOT1_3;
            break;

        case 3:
            command = EQ_EXECUTECMD_HOT1_4;
            break;

        case 4:
            command = EQ_EXECUTECMD_HOT1_5;
            break;

        case 5:
            command = EQ_EXECUTECMD_HOT1_6;
            break;

        case 6:
            command = EQ_EXECUTECMD_HOT1_7;
            break;

        case 7:
            command = EQ_EXECUTECMD_HOT1_8;
            break;

        case 8:
            command = EQ_EXECUTECMD_HOT1_9;
            break;

        case 9:
            command = EQ_EXECUTECMD_HOT1_10;
            break;

        case 10:
            command = EQ_EXECUTECMD_HOT1_11;
            break;

        case 11:
            command = EQ_EXECUTECMD_HOT1_12;
            break;

        default:
            command = -1;
            break;
    }

    if (command == -1)
    {
        return;
    }

    EQ_ExecuteCommand(command, 1);
}

