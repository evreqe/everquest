#pragma once

bool g_AutoGroupIsEnabled = true;

bool g_AutoGroupIsInvited = false;

EQApp::Timer g_AutoGroupTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoGroupTimerInterval = 3;

void EQAPP_AutoGroup_Toggle();
void EQAPP_AutoGroup_On();
void EQAPP_AutoGroup_Off();
void EQAPP_AutoGroup_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);

void EQAPP_AutoGroup_Toggle()
{
    EQ_ToggleBool(g_AutoGroupIsEnabled);
    EQAPP_PrintBool("Auto Group", g_AutoGroupIsEnabled);
}

void EQAPP_AutoGroup_On()
{
    if (g_AutoGroupIsEnabled == false)
    {
        EQAPP_AutoGroup_Toggle();
    }
}

void EQAPP_AutoGroup_Off()
{
    if (g_AutoGroupIsEnabled == true)
    {
        EQAPP_AutoGroup_Toggle();
    }
}

void EQAPP_AutoGroup_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    if (text == "To join the group, click on the 'FOLLOW' option, or 'DECLINE' to cancel.")
    {
        g_AutoGroupIsInvited = true;

        g_AutoGroupTimer = EQAPP_Timer_GetTimeNow();
    }

    if
    (
        text == "You have joined the group." ||
        text == "You have been removed from the group." ||
        text == "You cannot invite someone to join your group, only your leader may do so."
    )
    {
        g_AutoGroupIsInvited = false;
    }

    if (text == "You cannot invite yourself.")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);
    }

    if (g_AutoGroupIsInvited == true)
    {
        if (EQAPP_Timer_HasTimeElapsed(g_AutoGroupTimer, g_AutoGroupTimerInterval) == true)
        {
            EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);
            EQ_ExecuteCommand(EQ_EXECUTECMD_INVITE_FOLLOW, 1);
        }
    }
}
