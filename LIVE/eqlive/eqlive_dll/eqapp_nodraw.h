#pragma once

bool g_NoDrawIsEnabled = true;

EQApp::Timer g_NoDrawRenderPartialSceneTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NoDrawRenderPartialSceneTimerInterval = 60;

EQApp::Timer g_NoDrawUpdateDisplayTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NoDrawUpdateDisplayTimerInterval = 60;

EQApp::TimerInterval g_NoDrawRandomTimerIntervalMin = 30;
EQApp::TimerInterval g_NoDrawRandomTimerIntervalMax = 60;

// this allows the game to draw a frame every now and then
// the game stores some things in RAM and we need to draw to free up the memory and prevent crashing
// mostly seems to be spell cast particles and animations
bool g_NoDrawUseTimersIsEnabled = true;

void EQAPP_NoDraw_Toggle();
void EQAPP_NoDraw_On();
void EQAPP_NoDraw_Off();
bool EQAPP_NoDraw_HandleEvent_CRender__RenderPartialScene(void* this_ptr);
bool EQAPP_NoDraw_HandleEvent_CRender__UpdateDisplay(void* this_ptr);

void EQAPP_NoDraw_Toggle()
{
    EQ_ToggleBool(g_NoDrawIsEnabled);
    EQAPP_PrintBool("No Draw", g_NoDrawIsEnabled);
}

void EQAPP_NoDraw_On()
{
    if (g_NoDrawIsEnabled == false)
    {
        EQAPP_NoDraw_Toggle();
    }
}

void EQAPP_NoDraw_Off()
{
    if (g_NoDrawIsEnabled == true)
    {
        EQAPP_NoDraw_Toggle();
    }
}

bool EQAPP_NoDraw_HandleEvent_CRender__RenderPartialScene(void* this_ptr)
{
    if (g_NoDrawUseTimersIsEnabled == true)
    {
        if (EQAPP_Timer_HasTimeElapsedInSeconds(g_NoDrawRenderPartialSceneTimer, g_NoDrawRenderPartialSceneTimerInterval) == true)
        {
            auto randomTimerInterval = EQAPP_GetRandomNumberInt<EQApp::TimerInterval>(g_NoDrawRandomTimerIntervalMin, g_NoDrawRandomTimerIntervalMax);

            g_NoDrawRenderPartialSceneTimerInterval = randomTimerInterval;

            g_NoDrawRenderPartialSceneTimer = EQAPP_Timer_GetTimeNow();

            return false;
        }
    }

    // reduce CPU and GPU usage to almost 0%
    if (EQ_IsWindowInBackground() == true)
    {
        return true;
    }

    return false;
}

bool EQAPP_NoDraw_HandleEvent_CRender__UpdateDisplay(void* this_ptr)
{
    if (g_NoDrawUseTimersIsEnabled == true)
    {
        if (EQAPP_Timer_HasTimeElapsedInSeconds(g_NoDrawUpdateDisplayTimer, g_NoDrawUpdateDisplayTimerInterval) == true)
        {
            auto randomTimerInterval = EQAPP_GetRandomNumberInt<EQApp::TimerInterval>(g_NoDrawRandomTimerIntervalMin, g_NoDrawRandomTimerIntervalMax);

            g_NoDrawUpdateDisplayTimerInterval = randomTimerInterval;

            g_NoDrawUpdateDisplayTimer = EQAPP_Timer_GetTimeNow();

            return false;
        }
    }

    // reduce CPU and GPU usage to almost 0%
    if (EQ_IsWindowInBackground() == true)
    {
        return true;
    }

    return false;
}

