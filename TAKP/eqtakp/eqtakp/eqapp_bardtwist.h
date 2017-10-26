#pragma once

bool g_bardTwistIsEnabled = false;

void EQAPP_BardTwist_Toggle();
void EQAPP_BardTwist_Execute();

void EQAPP_BardTwist_Toggle()
{
    EQ_ToggleBool(g_bardTwistIsEnabled);
    EQAPP_PrintBool("Bard Twist", g_bardTwistIsEnabled);
}

void EQAPP_BardTwist_Execute()
{
    //
}

