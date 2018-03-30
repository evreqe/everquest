#pragma once

bool g_BazaarBotIsEnabled = false;

EQApp::Timer g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotFindItemsTimerInterval = 6;

EQApp::Timer g_BazaarBotBuyItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotBuyItemsTimerInterval = 3;

EQApp::Timer g_BazaarBotToParcelsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotToParcelsTimerInterval = 1;

void EQAPP_BazaarBot_Toggle();
void EQAPP_BazaarBot_Execute();

void EQAPP_BazaarBot_FindItems_Execute();
void EQAPP_BazaarBot_BuyItems_Execute();
void EQAPP_BazaarBot_ToParcels_Execute();

void EQAPP_BazaarBot_Toggle()
{
    EQ_ToggleBool(g_BazaarBotIsEnabled);
    EQAPP_PrintBool("Bazaar Bot", g_BazaarBotIsEnabled);
}

void EQAPP_BazaarBot_Execute()
{
    EQAPP_BazaarBot_FindItems_Execute();
    EQAPP_BazaarBot_BuyItems_Execute();
    EQAPP_BazaarBot_ToParcels_Execute();
}

void EQAPP_BazaarBot_FindItems_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_BazaarBotFindItemsTimer, g_BazaarBotFindItemsTimerInterval) == false)
    {
        return;
    }

    if (EQ_BazaarSearchWindow_IsOpen() == false)
    {
        return;
    }

    if (EQ_BazaarConfirmationWindow_IsOpen() == true)
    {
        return;
    }

    EQ_BazaarSearchWindow_FindItems();
}

void EQAPP_BazaarBot_BuyItems_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_BazaarBotBuyItemsTimer, g_BazaarBotBuyItemsTimerInterval) == false)
    {
        return;
    }

    if (EQ_BazaarSearchWindow_IsOpen() == false)
    {
        return;
    }

    if (EQ_BazaarConfirmationWindow_IsOpen() == true)
    {
        return;
    }

    EQ_BazaarSearchWindow_BuyItem(0);
}

void EQAPP_BazaarBot_ToParcels_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_BazaarBotToParcelsTimer, g_BazaarBotToParcelsTimerInterval) == false)
    {
        return;
    }

    if (EQ_BazaarSearchWindow_IsOpen() == false)
    {
        return;
    }

    if (EQ_BazaarConfirmationWindow_IsOpen() == false)
    {
        return;
    }

    EQ_BazaarConfirmationWindow_ClickToParcelsButton();
}

