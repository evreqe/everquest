#pragma once

bool g_AlwaysHotButtonIsEnabled = false;

EQApp::Timer g_AlwaysHotButtonTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AlwaysHotButtonTimerInterval = 1;

signed int g_AlwaysHotButtonIndex = -1;

void EQAPP_AlwaysHotButton_Toggle();
void EQAPP_AlwaysHotButton_On();
void EQAPP_AlwaysHotButton_Off();
void EQAPP_AlwaysHotButton_SetIndex(signed int index);
void EQAPP_AlwaysHotButton_Execute();

void EQAPP_AlwaysHotButton_Toggle()
{
    EQ_ToggleBool(g_AlwaysHotButtonIsEnabled);
    EQAPP_PrintBool("Always HotButton", g_AlwaysHotButtonIsEnabled);
}

void EQAPP_AlwaysHotButton_On()
{
    if (g_AlwaysHotButtonIsEnabled == false)
    {
        EQAPP_AlwaysHotButton_Toggle();
    }
}

void EQAPP_AlwaysHotButton_Off()
{
    if (g_AlwaysHotButtonIsEnabled == true)
    {
        EQAPP_AlwaysHotButton_Toggle();
    }
}

void EQAPP_AlwaysHotButton_SetIndex(signed int index)
{
    g_AlwaysHotButtonIndex = index;
}

void EQAPP_AlwaysHotButton_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInSeconds(g_AlwaysHotButtonTimer, g_AlwaysHotButtonTimerInterval) == false)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.empty() == false)
    {
        return;
    }

    if (g_AlwaysHotButtonIndex < 0 || g_AlwaysHotButtonIndex > (EQ_NUM_HOTBAR_BUTTONS - 1))
    {
        return;
    }

    signed int command = -1;

    switch (g_AlwaysHotButtonIndex)
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
