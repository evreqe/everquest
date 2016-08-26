#ifndef EQAPP_SWIMSPEED_H
#define EQAPP_SWIMSPEED_H

bool g_swimSpeedHackIsEnabled = true;
float g_swimSpeedHackModifier = 0.0f;
DWORD g_swimSpeedHackTimer = 0;
DWORD g_swimSpeedHackTimerDelay = 1000;

void EQAPP_SwimSpeed_On();
void EQAPP_SwimSpeed_Off();
void EQAPP_SwimSpeed_Toggle();
void EQAPP_SwimSpeed_Execute();

void EQAPP_SwimSpeed_On()
{
    g_swimSpeedHackIsEnabled = true;
    EQAPP_PrintBool("Swim Speed Hack", g_swimSpeedHackIsEnabled);
}

void EQAPP_SwimSpeed_Off()
{
    g_swimSpeedHackIsEnabled = false;
    EQAPP_PrintBool("Swim Speed Hack", g_swimSpeedHackIsEnabled);

    EQ_WriteMemory<FLOAT>(EQ_SWIM_SPEED_MULTIPLIER, EQ_SWIM_SPEED_MODIFIER_DEFAULT);
}

void EQAPP_SwimSpeed_Toggle()
{
    if (g_swimSpeedHackIsEnabled == false)
    {
        EQAPP_SwimSpeed_On();
    }
    else
    {
        EQAPP_SwimSpeed_Off();
    }
}

void EQAPP_SwimSpeed_Execute()
{
    if (EQ_HasTimePassed(g_swimSpeedHackTimer, g_swimSpeedHackTimerDelay) == false)
    {
        return;
    }

    if (g_swimSpeedHackIsEnabled == false)
    {
        EQ_WriteMemory<FLOAT>(EQ_SWIM_SPEED_MULTIPLIER, EQ_SWIM_SPEED_MODIFIER_DEFAULT);
        return;
    }

    EQ_WriteMemory<FLOAT>(EQ_SWIM_SPEED_MULTIPLIER, EQ_SWIM_SPEED_MODIFIER_DEFAULT + g_swimSpeedHackModifier);
}

#endif // EQAPP_SWIMSPEED_H
