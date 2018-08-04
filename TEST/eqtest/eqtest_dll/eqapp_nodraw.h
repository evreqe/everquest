#pragma once

bool g_NoDrawIsEnabled = true;

EQApp::Timer g_NoDrawRenderPartialSceneTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NoDrawRenderPartialSceneTimerInterval = 30;

EQApp::Timer g_NoDrawUpdateDisplayTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NoDrawUpdateDisplayTimerInterval = 30;

bool g_NoDrawUseTimersIsEnabled = false;

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
        if (EQAPP_Timer_HasTimeElapsed(g_NoDrawRenderPartialSceneTimer, g_NoDrawRenderPartialSceneTimerInterval) == true)
        {
            g_NoDrawRenderPartialSceneTimer = EQAPP_Timer_GetTimeNow();

            return false;
        }
    }

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
        if (EQAPP_Timer_HasTimeElapsed(g_NoDrawUpdateDisplayTimer, g_NoDrawUpdateDisplayTimerInterval) == true)
        {
            g_NoDrawUpdateDisplayTimer = EQAPP_Timer_GetTimeNow();

            return false;
        }
    }

    if (EQ_IsWindowInBackground() == true)
    {
        return true;
    }

    return false;
}
