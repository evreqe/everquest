#pragma once

bool g_HotButtonKeysIsEnabled = false;

uint32_t g_HotButtonKeysTimer = 0;
uint32_t g_HotButtonKeysTimerDelay = 500;

int g_HotButtonKeysModifier = VK_CONTROL;

void EQAPP_HotButtonKeys_Toggle();
void EQAPP_HotButtonKeys_Execute();
void EQAPP_HotButtonKeys_SetModifierToAlt();
void EQAPP_HotButtonKeys_SetModifierToControl();
void EQAPP_HotButtonKeys_SetModifierToShift();

void EQAPP_HotButtonKeys_Toggle()
{
    EQ_ToggleBool(g_HotButtonKeysIsEnabled);
    EQAPP_PrintBool("Hot Button Keys", g_HotButtonKeysIsEnabled);
}

void EQAPP_HotButtonKeys_Execute()
{
    uint32_t currentTime = EQ_GetTimer();
    if ((currentTime - g_HotButtonKeysTimer) < g_HotButtonKeysTimerDelay)
    {
        return;
    }

    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        if (EQAPP_IsKeyDown(g_HotButtonKeysModifier) == true)
        {
            if (EQAPP_IsKeyDown(VK_1) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(0, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_2) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(1, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_3) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(2, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_4) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(3, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_5) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(4, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_6) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(5, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_7) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(6, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_8) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(7, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_9) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(8, 0);

                g_HotButtonKeysTimer = currentTime;
                return;
            }

            if (EQAPP_IsKeyDown(VK_0) == true)
            {
                EQ_CLASS_POINTER_CHotButtonWnd->DoHotButton(9, 1);

                g_HotButtonKeysTimer = currentTime;
                return;
            }
        }
    }
}

void EQAPP_HotButtonKeys_SetModifierToAlt()
{
    g_HotButtonKeysModifier = VK_ALT;
}

void EQAPP_HotButtonKeys_SetModifierToControl()
{
    g_HotButtonKeysModifier = VK_CONTROL;
}

void EQAPP_HotButtonKeys_SetModifierToShift()
{
    g_HotButtonKeysModifier = VK_SHIFT;
}