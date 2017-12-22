#pragma once

bool g_ExtraMouseButtonsIsEnabled = true;

uint32_t g_ExtraMouseButtonsTimer = 0;
uint32_t g_ExtraMouseButtonsTimerDelay = 250;

void EQAPP_ExtraMouseButtons_HandleEvent_ProcessMouseEvent();

void EQAPP_ExtraMouseButtons_HandleEvent_ProcessMouseEvent()
{
    auto currentTime = EQ_GetTimer();
    if ((currentTime - g_ExtraMouseButtonsTimer) < g_ExtraMouseButtonsTimerDelay)
    {
        return;
    }

    bool wasButtonPressed = false;

    DIMOUSESTATE2 mouseState;
    HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)&mouseState);
    if (result != DIERR_INPUTLOST && result != DIERR_NOTACQUIRED)
    {
        // mouse middle button
        if (mouseState.rgbButtons[DINPUT_MOUSE_BUTTON_MIDDLE] & 0x80)
        {
            EQAPP_Map_Toggle();
            wasButtonPressed = true;
        }

        // mouse back button
        if (mouseState.rgbButtons[DINPUT_MOUSE_BUTTON_4] & 0x80)
        {
            EQ_OpenAllContainers();
            wasButtonPressed = true;
        }

        // mouse forward button
        if (mouseState.rgbButtons[DINPUT_MOUSE_BUTTON_5] & 0x80)
        {
            EQ_CLASS_POINTER_CDisplay->NewUIProcessEscape();
            wasButtonPressed = true;
        }
    }

    if (wasButtonPressed == true)
    {
        g_ExtraMouseButtonsTimer = EQ_GetTimer();
    }
}

