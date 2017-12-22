#pragma once

bool g_DrawDistanceIsEnabled = true;

uint32_t g_DrawDistanceTimer = 0;
uint32_t g_DrawDistanceTimerDelay = 1000;

float g_DrawDistanceValue = 1000.0f;
float g_DrawDistanceValueDefault = 1000.0f;

void EQAPP_DrawDistance_Toggle();
void EQAPP_DrawDistance_Load();
void EQAPP_DrawDistance_Execute();

void EQAPP_DrawDistance_Toggle()
{
    EQ_ToggleBool(g_DrawDistanceIsEnabled);
    EQAPP_PrintBool("Draw Distance`", g_DrawDistanceIsEnabled);
}

void EQAPP_DrawDistance_Load()
{
    g_DrawDistanceValue = g_DrawDistanceValueDefault;

    auto zoneID = EQ_GetZoneID();

    if (zoneID == EQ_ZONE_ID_WAKENING)
    {
        g_DrawDistanceValue = 100.0f;
    }
}

void EQAPP_DrawDistance_Execute()
{
    if (EQ_HasTimePassed(g_DrawDistanceTimer, g_DrawDistanceTimerDelay) == false)
    {
        return;
    }

    if (EQ_POINTER_Camera->DrawDistance < g_DrawDistanceValue)
    {
        EQ_POINTER_Camera->DrawDistance = g_DrawDistanceValue;
    }

    if (EQ_POINTER_Zone.MinClip < g_DrawDistanceValue)
    {
        EQ_POINTER_Zone.MinClip = g_DrawDistanceValue;
    }

    if (EQ_POINTER_Zone.MaxClip < g_DrawDistanceValue)
    {
        EQ_POINTER_Zone.MaxClip = g_DrawDistanceValue;
    }
}

