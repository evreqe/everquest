#pragma once

bool g_backgroundFpsIsEnabled = true;

void EQAPP_BackgroundFps_Execute();

void EQAPP_BackgroundFps_Execute()
{
    if (g_backgroundFpsIsEnabled == false)
    {
        return;
    }

    // allows you to auto follow better because it is tied to the game framerate
    if (EQ_IsAutoRunEnabled() == true)
    {
        EQ_WriteMemory<uint32_t>(EQ_MAX_BACKGROUND_FPS, EQ_MAX_BACKGROUND_FPS_VALUE_MAX);
    }
    else
    {
        EQ_WriteMemory<uint32_t>(EQ_MAX_BACKGROUND_FPS, EQ_MAX_BACKGROUND_FPS_VALUE_MIN);
    }
}

