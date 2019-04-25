#pragma once

bool g_AutoGroupIsEnabled = true;

bool g_AutoGroupIsInvited = false;

EQApp::Timer g_AutoGroupTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoGroupTimerInterval = 3;

void EQAPP_AutoGroup_Toggle();
void EQAPP_AutoGroup_On();
void EQAPP_AutoGroup_Off();
void EQAPP_AutoGroup_Execute();
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

void EQAPP_AutoGroup_Execute()
{
    if (EQ_IsInvitedToGroup() == true)
    {
        g_AutoGroupIsInvited = true;
    }

    if (g_AutoGroupIsInvited == true)
    {
        if (EQAPP_Timer_HasTimeElapsed(g_AutoGroupTimer, g_AutoGroupTimerInterval) == true)
        {
            EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);
            EQ_ExecuteCommand(EQ_EXECUTECMD_INVITE_FOLLOW, 1);

            g_AutoGroupIsInvited = false;
        }
    }
}

void EQAPP_AutoGroup_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    if
    (
        EQAPP_String_EndsWith(text, "invites you to join a group.") == true ||
        text == "To join the group, click on the 'FOLLOW' option, or 'DECLINE' to cancel."
    )
    {
        g_AutoGroupIsInvited = true;

        g_AutoGroupTimer = EQAPP_Timer_GetTimeNow();

        return;
    }

    if
    (
        EQAPP_String_EndsWith(text, "that you agree to join the group.") == true ||
        text == "You have joined the group." ||
        text == "You have been removed from the group." ||
        text == "You cannot invite someone to join your group, only your leader may do so."
    )
    {
        g_AutoGroupIsInvited = false;
        return;
    }

    if (text == "You cannot invite yourself.")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);
        return;
    }

    EQAPP_AutoGroup_Execute();
}
