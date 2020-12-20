#pragma once

bool g_BazaarBotIsEnabled = false;

bool g_BazaarBotUseBuyItemsListIsEnabled = false;

EQApp::Timer g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotFindItemsTimerInterval = 10;

EQApp::Timer g_BazaarBotBuyItemsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotBuyItemsTimerInterval = 5;

EQApp::Timer g_BazaarBotToParcelsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarBotToParcelsTimerInterval = 1;

std::vector<std::string> g_BazaarBotBuyItemsList;
uint32_t g_BazaarBotBuyItemsList_reserve = 1024;

std::vector<std::string> g_BazaarBotLoreItemsList;

// 1    = 1cp                  one copper piece
// 1000 = 1pp                  one platinum piece
// 100000 = 100pp              one hundred platinum pieces
// 2000000000 = 2,000,000pp    two million platinum pieces
uint32_t g_BazaarBotItemPriceMinimum = 1;             // 1cp
uint32_t g_BazaarBotItemPriceMaximum = 2000000000;    // 2,000,000pp

void EQAPP_BazaarBot_Toggle();
void EQAPP_BazaarBot_On();
void EQAPP_BazaarBot_Off();
void EQAPP_BazaarBot_UseBuyItemsList_Toggle();
void EQAPP_BazaarBot_UseBuyItemsList_On();
void EQAPP_BazaarBot_UseBuyItemsList_Off();
void EQAPP_BazaarBot_Load();
void EQAPP_BazaarBot_LoadEx(const char* fileName);
void EQAPP_BazaarBot_Execute_BuyEverything();
void EQAPP_BazaarBot_Execute_BuyFromBuyItemsList();
void EQAPP_BazaarBot_ResetLoreItems();
void EQAPP_BazaarBot_RotateBuyItemsList();
void EQAPP_BazaarBot_FindItem(const char* itemName);
void EQAPP_BazaarBot_ClickFindItemsButton();
void EQAPP_BazaarBot_BuyItemByName(const char* itemName);
void EQAPP_BazaarBot_BuyCheapestItemByName(const char* itemName);
void EQAPP_BazaarBot_BuyCheapestItem();
void EQAPP_BazaarBot_BuyAnyItem();
void EQAPP_BazaarBot_ClickToParcelsButton();
void EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);
bool EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName);

void EQAPP_BazaarBot_Toggle()
{
    EQ_ToggleBool(g_BazaarBotIsEnabled);
    EQAPP_PrintBool("Bazaar Bot", g_BazaarBotIsEnabled);

    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_Load();
    }

    EQAPP_BazaarBot_ResetLoreItems();
}

void EQAPP_BazaarBot_On()
{
    if (g_BazaarBotIsEnabled == false)
    {
        EQAPP_BazaarBot_Toggle();
    }
}

void EQAPP_BazaarBot_Off()
{
    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_Toggle();
    }
}

void EQAPP_BazaarBot_UseBuyItemsList_Toggle()
{
    EQ_ToggleBool(g_BazaarBotUseBuyItemsListIsEnabled);
    EQAPP_PrintBool("Bazaar Bot Use Buy Items List", g_BazaarBotUseBuyItemsListIsEnabled);
}

void EQAPP_BazaarBot_UseBuyItemsList_On()
{
    if (g_BazaarBotUseBuyItemsListIsEnabled == false)
    {
        EQAPP_BazaarBot_UseBuyItemsList_Toggle();
    }
}

void EQAPP_BazaarBot_UseBuyItemsList_Off()
{
    if (g_BazaarBotUseBuyItemsListIsEnabled == true)
    {
        EQAPP_BazaarBot_UseBuyItemsList_Toggle();
    }
}

void EQAPP_BazaarBot_Load()
{
    std::stringstream fileName;
    fileName << g_EQAppName << "/bazaarbot.txt";

    EQAPP_BazaarBot_LoadEx(fileName.str().c_str());
}

void EQAPP_BazaarBot_LoadEx(const char* fileName)
{
    std::fstream file;
    file.open(fileName, std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << fileName;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    g_BazaarBotBuyItemsList.clear();
    g_BazaarBotBuyItemsList.reserve(g_BazaarBotBuyItemsList_reserve);

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        g_BazaarBotBuyItemsList.push_back(line);
    }

    std::cout << "Bazaar Bot loaded from file: " << fileName << "\n";

    file.close();
}

void EQAPP_BazaarBot_Execute_BuyEverything()
{
    EQAPP_BazaarBot_ClickFindItemsButton();
    EQAPP_BazaarBot_BuyCheapestItem();
    EQAPP_BazaarBot_ClickToParcelsButton();
}

void EQAPP_BazaarBot_Execute_BuyFromBuyItemsList()
{
    std::vector<std::string> randomItemNames;

    std::sample
    (
        g_BazaarBotBuyItemsList.begin(),
        g_BazaarBotBuyItemsList.end(),
        std::back_inserter(randomItemNames),
        1,
        std::mt19937{std::random_device{}()}
    );

    if (randomItemNames.size() == 0)
    {
        return;
    }

    std::string randomItemName = randomItemNames.at(0);
    if (randomItemName.size() == 0)
    {
        return;
    }

    EQAPP_BazaarBot_FindItem(randomItemName.c_str());
    EQAPP_BazaarBot_BuyCheapestItemByName(randomItemName.c_str());
    EQAPP_BazaarBot_ClickToParcelsButton();
}

void EQAPP_BazaarBot_ResetLoreItems()
{
    g_BazaarBotLoreItemsList.clear();
}

void EQAPP_BazaarBot_RotateBuyItemsList()
{
    // move first item to end of list
    auto g_BazaarBotBuyItemsList_it = g_BazaarBotBuyItemsList.begin();
    std::rotate(g_BazaarBotBuyItemsList_it, g_BazaarBotBuyItemsList_it + 1, g_BazaarBotBuyItemsList.end());
}

void EQAPP_BazaarBot_FindItem(const char* itemName)
{
    if (EQAPP_Timer_HasTimeElapsed(g_BazaarBotFindItemsTimer, g_BazaarBotFindItemsTimerInterval) == false)
    {
        return;
    }

    if (EQ_BazaarConfirmationWindow_IsOpen() == true)
    {
        return;
    }

    std::cout << "[Bazaar Bot] Searching for: " << itemName << "\n";

    EQ_BazaarSearchWindow_FindItem(itemName);

    EQ_BazaarSearchWindow_ClickUpdateTradersButton();

    EQAPP_BazaarBot_RotateBuyItemsList();
}

void EQAPP_BazaarBot_ClickFindItemsButton()
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

    EQ_BazaarSearchWindow_ClickUpdateTradersButton();
    EQ_BazaarSearchWindow_ClickFindItemsButton();
}

void EQAPP_BazaarBot_BuyItemByName(const char* itemName)
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

    auto listIndex = EQ_BazaarSearchWindow_GetListIndexByItemName(itemName, true);
    if (listIndex == EQ_BAZAAR_SEARCH_LIST_INDEX_NULL)
    {
        return;
    }

    std::cout << "[Bazaar Bot] Attempting to purchase: " << itemName << "\n";

    for (auto& loreItemName : g_BazaarBotLoreItemsList)
    {
        if (itemName == loreItemName)
        {
            std::cout << "[Bazaar Bot] " << itemName << " found in the lore items list.\n";
            return;
        }
    }

    EQ_BazaarSearchWindow_BuyItem(listIndex);
}

void EQAPP_BazaarBot_BuyCheapestItemByName(const char* itemName)
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

    auto listIndex = EQ_BazaarSearchWindow_GetListIndexByLowestPrice();
    if (listIndex == EQ_BAZAAR_SEARCH_LIST_INDEX_NULL)
    {
        return;
    }

    std::string listItemName = EQ_BazaarSearchWindow_GetItemName(listIndex);
    if (listItemName.size() != 0)
    {
        std::string itemNameStr = itemName;
        if (listItemName != itemNameStr)
        {
            return;
        }

        auto listItemPrice = EQ_BazaarSearchWindow_GetItemPrice(listIndex);
        if (listItemPrice > 0)
        {
            std::cout << "[Bazaar Bot] Attempting to purchase " << listItemName << " for " << (listItemPrice / 1000) << "pp.\n";

            for (auto& loreItemName : g_BazaarBotLoreItemsList)
            {
                if (listItemName == loreItemName)
                {
                    std::cout << "[Bazaar Bot] " << listItemName << " found in the lore items list.\n";
                    return;
                }
            }
        }
    }

    EQ_BazaarSearchWindow_BuyItem(listIndex);
}

void EQAPP_BazaarBot_BuyCheapestItem()
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

    auto listIndex = EQ_BazaarSearchWindow_GetListIndexByLowestPrice();
    if (listIndex == EQ_BAZAAR_SEARCH_LIST_INDEX_NULL)
    {
        return;
    }

    std::string itemName = EQ_BazaarSearchWindow_GetItemName(listIndex);
    if (itemName.size() != 0)
    {
        std::cout << "[Bazaar Bot] Attempting to purchase: " << itemName << "\n";

        for (auto& loreItemName : g_BazaarBotLoreItemsList)
        {
            if (itemName == loreItemName)
            {
                std::cout << "[Bazaar Bot] " << itemName << " found in the lore items list.\n";
                return;
            }
        }
    }

    EQ_BazaarSearchWindow_BuyItem(listIndex);
}

void EQAPP_BazaarBot_BuyAnyItem()
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

    auto listCount = EQ_BazaarSearchWindow_GetListCount();
    if (listCount > 0)
    {
        listIndex = EQAPP_GetRandomNumber(0, listCount - 1);
    }

    std::string itemName = EQ_BazaarSearchWindow_GetItemName(listIndex);
    if (itemName.size() != 0)
    {
        std::cout << "[Bazaar Bot] Attempting to purchase: " << itemName << "\n";

        for (auto& loreItemName : g_BazaarBotLoreItemsList)
        {
            if (itemName == loreItemName)
            {
                std::cout << "[Bazaar Bot] " << itemName << " found in the lore items list.\n";
                return;
            }
        }
    }

    EQ_BazaarSearchWindow_BuyItem(listIndex);
}

void EQAPP_BazaarBot_ClickToParcelsButton()
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

    std::cout << "[Bazaar Bot] Clicking To Parcels button.\n";

    EQ_BazaarConfirmationWindow_ClickToParcelsButton();
}

void EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    bool bResult = true;

    if (text == "That item is no longer for sale in the bazaar.")
    {
        bResult = false;
    }

    if (EQAPP_String_BeginsWith(text, "Your attempt to purchase") == true)
    {
        if (EQAPP_String_Contains(text, "was unsuccessful.") == true)
        {
            bResult = false;
        }

        if (EQAPP_String_Contains(text, "failed because your bazaar data is out of date.") == true)
        {
            bResult = false;
        }

        if (EQAPP_String_Contains(text, "failed because you already possess that lore item.") == true)
        {
            ////std::cout << "[Bazaar Bot] You are attemping to purchase a lore item you already possess." << "\n";

            uint32_t listIndex = EQ_BazaarSearchWindow_GetListIndex();
            if (listIndex != EQ_BAZAAR_SEARCH_LIST_INDEX_NULL)
            {
                std::string itemName = EQ_BazaarSearchWindow_GetItemName(listIndex);
                if (itemName.size() != 0)
                {
                    g_BazaarBotLoreItemsList.push_back(itemName);

                    std::cout << "[Bazaar Bot] " << itemName << " added to the lore items list.\n";
                }
                else
                {
                    std::cout << "[Bazaar Bot] itemName.size() == 0\n";
                }
            }
            //else
            //{
                ////std::cout << "[Bazaar Bot] ERROR: list index is null.\n";
            //}

            bResult = false;
        }
    }

    if (EQAPP_String_BeginsWith(text, "You successfully purchased") == true)
    {
        bResult = true;

        g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();
    }

    if (bResult == false)
    {
        if (EQ_BazaarSearchWindow_IsOpen() == true)
        {
            EQ_BazaarSearchWindow_ClickUpdateTradersButton();
            EQ_BazaarSearchWindow_ClickFindItemsButton();
        }
    }
}

bool EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName)
{
    if (itemPrice == 0)
    {
        return false;
    }

    if (itemPrice < g_BazaarBotItemPriceMinimum || itemPrice > g_BazaarBotItemPriceMaximum)
    {
        std::cout << "[Bazaar Bot] " << itemName << " was NOT added to the search list because the price was too high. (" << (itemPrice / 1000) << "pp)\n";

        return false;
    }

    std::string itemNameStr = itemName;

    for (auto& loreItemName : g_BazaarBotLoreItemsList)
    {
        if (itemNameStr == loreItemName)
        {
            std::cout << "[Bazaar Bot] " << itemName << " was NOT added to the search list because it was found in the lore items list.\n";

            return false;
        }
    }

    bool bShouldAddItemToList = false;

    for (auto& buyItemName : g_BazaarBotBuyItemsList)
    {
        if (itemNameStr == buyItemName)
        {
            bShouldAddItemToList = true;
            break;
        }
    }

    return bShouldAddItemToList;
}

