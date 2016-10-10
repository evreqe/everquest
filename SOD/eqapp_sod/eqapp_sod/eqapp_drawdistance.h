#pragma once

bool g_drawDistanceIsEnabled = true;
float g_drawDistance = 1000.0f;
uint32_t g_drawDistanceTimer = 0;
uint32_t g_drawDistanceTimerDelay = 1000;

void EQAPP_DrawDistance_Execute();
void EQAPP_DrawDistance_Print();

void EQAPP_DrawDistance_Execute()
{
    if (g_drawDistanceIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_drawDistanceTimer, g_drawDistanceTimerDelay) == false)
    {
        return;
    }

    EQ_SetDrawDistance(g_drawDistance);
}

void EQAPP_DrawDistance_Print()
{
    std::cout << "Draw Distance: " << g_drawDistance << std::endl;
}

