#pragma once

bool g_drawDistanceIsEnabled = true;

uint32_t g_drawDistanceTimer = 0;
uint32_t g_drawDistanceTimerDelay = 1000;

float g_drawDistanceValue = 1000.0f;

void EQAPP_DrawDistance_Toggle();
void EQAPP_DrawDistance_Load();
void EQAPP_DrawDistance_Execute();

void EQAPP_DrawDistance_Toggle()
{
    EQ_ToggleBool(g_drawDistanceIsEnabled);
    EQAPP_PrintBool("Draw Distance`", g_drawDistanceIsEnabled);
}

void EQAPP_DrawDistance_Load()
{
    // TODO
}

void EQAPP_DrawDistance_Execute()
{
    if (EQ_HasTimePassed(g_drawDistanceTimer, g_drawDistanceTimerDelay) == false)
    {
        return;
    }

    if (EQ_POINTER_Camera->DrawDistance < g_drawDistanceValue)
    {
        EQ_POINTER_Camera->DrawDistance = g_drawDistanceValue;
    }

    if (EQ_POINTER_Zone.MinClip < g_drawDistanceValue)
    {
        EQ_POINTER_Zone.MinClip = g_drawDistanceValue;
    }

    if (EQ_POINTER_Zone.MaxClip < g_drawDistanceValue)
    {
        EQ_POINTER_Zone.MaxClip = g_drawDistanceValue;
    }
}

