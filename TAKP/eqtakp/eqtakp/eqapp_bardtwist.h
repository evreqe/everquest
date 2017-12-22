#pragma once

bool g_BardTwistIsEnabled = false;

void EQAPP_BardTwist_Toggle();
void EQAPP_BardTwist_Execute();

void EQAPP_BardTwist_Toggle()
{
    EQ_ToggleBool(g_BardTwistIsEnabled);
    EQAPP_PrintBool("Bard Twist", g_BardTwistIsEnabled);
}

void EQAPP_BardTwist_Execute()
{
    //
}

