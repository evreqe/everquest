#pragma once

bool g_autoLootIsEnabled = true;
std::vector<std::string> g_autoLootList;
uint32_t g_autoLootTimer = 0;
uint32_t g_autoLootTimerDelay = 250;

void EQAPP_AutoLoot_Load();
void EQAPP_AutoLoot_Execute();
void EQAPP_AutoLoot_Add(std::string itemName);
void EQAPP_AutoLoot_Remove(std::string itemName);

void EQAPP_AutoLoot_Load()
{
    std::cout << "Loading Auto Loot..." << std::endl;

    g_autoLootList.clear();

    EQAPP_ReadFileToList("autoloot.txt", g_autoLootList);
}

void EQAPP_AutoLoot_Execute()
{
    if (g_autoLootIsEnabled == false || g_autoLootList.size() == 0)
    {
        return;
    }

    if (EQ_HasTimePassed(g_autoLootTimer, g_autoLootTimerDelay) == false)
    {
        return;
    }

    if (EQ_IsWindowVisible(EQ_ADDRESS_POINTER_CLootWnd) == false)
    {
        g_autoLootTimer = EQ_GetTimer();
        return;
    }

    for (auto& itemName : g_autoLootList)
    {
        bool result = EQ_LootItemByName(itemName);
        if (result == true)
        {
            std::cout << "Auto Loot item name: " << itemName << std::endl;
        }
    }
}

void EQAPP_AutoLoot_Add(std::string itemName)
{
    if (itemName.size() == 0)
    {
        return;
    }

    g_autoLootList.push_back(itemName);

    std::cout << "Auto Loot item added: " << itemName << std::endl;
}

void EQAPP_AutoLoot_Remove(std::string itemName)
{
    if (itemName.size() == 0)
    {
        return;
    }

    for (auto autoLootListIterator = g_autoLootList.begin(); autoLootListIterator != g_autoLootList.end(); autoLootListIterator++)
    {
        if (*autoLootListIterator == itemName)
        {
            autoLootListIterator = g_autoLootList.erase(autoLootListIterator);
            autoLootListIterator--;

            std::cout << "Auto Loot item removed: " << itemName << std::endl;
        }
    }
}