#ifndef EQAPP_DRAWDISTANCE_H
#define EQAPP_DRAWDISTANCE_H

bool g_drawDistanceIsEnabled = true;
float g_drawDistance = 1000.0f;
DWORD g_drawDistanceTimer = 0;
DWORD g_drawDistanceTimerDelay = 1000;

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

#endif // EQAPP_DRAWDISTANCE_H
