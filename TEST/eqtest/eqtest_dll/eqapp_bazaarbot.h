#pragma once

bool g_BazaarBotIsEnabled = false;

EQApp::Timer g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotFindItemsTimerInterval = 6;

EQApp::Timer g_BazaarBotBuyItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotBuyItemsTimerInterval = 3;

EQApp::Timer g_BazaarBotToParcelsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotToParcelsTimerInterval = 1;

std::vector<std::string> g_BazaarBotLoreItemsList;

void EQAPP_BazaarBot_Toggle();
void EQAPP_BazaarBot_Execute();
void EQAPP_BazaarBot_ResetLoreItems();

void EQAPP_BazaarBot_FindItems_Execute();
void EQAPP_BazaarBot_BuyItems_Execute();
void EQAPP_BazaarBot_ToParcels_Execute();

void EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);
bool EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName);

void EQAPP_BazaarBot_Toggle()
{
    EQ_ToggleBool(g_BazaarBotIsEnabled);
    EQAPP_PrintBool("Bazaar Bot", g_BazaarBotIsEnabled);

    EQAPP_BazaarBot_ResetLoreItems();
}

void EQAPP_BazaarBot_Execute()
{
    EQAPP_BazaarBot_FindItems_Execute();
    EQAPP_BazaarBot_BuyItems_Execute();
    EQAPP_BazaarBot_ToParcels_Execute();
}

void EQAPP_BazaarBot_ResetLoreItems()
{
    g_BazaarBotLoreItemsList.clear();
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

    EQ_BazaarSearchWindow_ClickFindItemsButton();
    ////EQ_BazaarSearchWindow_DoQuery();
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

    uint32_t listIndex = 0;

    std::string itemName = EQ_BazaarSearchWindow_GetItemName(listIndex);
    if (itemName.size() != 0)
    {
        for (auto& loreItemName : g_BazaarBotLoreItemsList)
        {
            if (itemName == loreItemName)
            {
                std::cout << "[Bazaar Bot] " << itemName << " found in the lore items list." << std::endl;
                return;
            }
        }
    }

    bool result = EQ_BazaarSearchWindow_BuyItem(listIndex);
    if (result == true)
    {
        g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
    }
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

    bool result = EQ_BazaarConfirmationWindow_ClickToParcelsButton();
    if (result == true)
    {
        g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
    }
}

void EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    if (text == "That item is no longer for sale in the bazaar.")
    {
        if (EQ_BazaarSearchWindow_IsOpen() == true)
        {
            g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();

            EQ_BazaarSearchWindow_ClickFindItemsButton();
        }
    }

    if (EQAPP_String_BeginsWith(text, "Your attempt to purchase") == true)
    {
        if (EQAPP_String_Contains(text, "failed because your bazaar data is out of date.") == true)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();

                EQ_BazaarSearchWindow_ClickFindItemsButton();
            }
        }

        if (EQAPP_String_Contains(text, "failed because you already possess that lore item.") == true)
        {
            signed int buyItemListIndex = EQ_BazaarSearchWindow_GetBuyItemListIndex();
            if (buyItemListIndex != -1)
            {
                std::string itemName = EQ_BazaarSearchWindow_GetItemName(buyItemListIndex);
                if (itemName.size() != 0)
                {
                    g_BazaarBotLoreItemsList.push_back(itemName);

                    std::cout << "[Bazaar Bot] " << itemName << " added to the lore items list." << std::endl;
                }
            }
        }
    }
}

bool EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName)
{
    bool bShouldAddItemToList = true;

    std::string itemNameStr = itemName;

    for (auto& loreItemName : g_BazaarBotLoreItemsList)
    {
        if (itemNameStr == loreItemName)
        {
            std::cout << "[Bazaar Bot] " << itemName << " was NOT added to the search list because it was found in the lore items list." << std::endl;

            bShouldAddItemToList = false;
            break;
        }
    }

    return bShouldAddItemToList;
}
