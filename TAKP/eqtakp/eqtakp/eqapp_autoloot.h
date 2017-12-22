#pragma once

bool g_AutoLootIsEnabled = true;

std::vector<std::string> g_AutoLootList;

uint32_t g_AutoLootTimer = 0;
uint32_t g_AutoLootTimerDelay = 250;

void EQAPP_AutoLoot_Toggle();
void EQAPP_AutoLoot_Load();
void EQAPP_AutoLoot_Execute();
void EQAPP_AutoLoot_Add(std::string itemName);
void EQAPP_AutoLoot_Remove(std::string itemName);

void EQAPP_AutoLoot_Toggle()
{
    EQ_ToggleBool(g_AutoLootIsEnabled);
    EQAPP_PrintBool("Auto Loot", g_AutoLootIsEnabled);
}

void EQAPP_AutoLoot_Load()
{
    std::cout << "Loading Auto Loot..." << std::endl;

    g_AutoLootList.clear();
    g_AutoLootList.reserve(100);

    EQAPP_ReadFileToList("autoloot.txt", g_AutoLootList);
}

void EQAPP_AutoLoot_Execute()
{
    if (g_AutoLootList.size() == 0)
    {
        return;
    }

    if (EQ_HasTimePassed(g_AutoLootTimer, g_AutoLootTimerDelay) == false)
    {
        return;
    }

    if (EQ_IsWindowVisible(EQ_ADDRESS_POINTER_CLootWnd) == false)
    {
        g_AutoLootTimer = EQ_GetTimer();
        return;
    }

    for (auto& itemName : g_AutoLootList)
    {
        bool result = EQ_LootItemByName(itemName, false);
        if (result == true)
        {
            std::cout << "Auto Loot item name: " << itemName << std::endl;
            break;
        }
    }
}

void EQAPP_AutoLoot_Add(std::string itemName)
{
    if (itemName.size() == 0)
    {
        return;
    }

    g_AutoLootList.push_back(itemName);

    std::cout << "Auto Loot item added: " << itemName << std::endl;
}

void EQAPP_AutoLoot_Remove(std::string itemName)
{
    if (itemName.size() == 0)
    {
        return;
    }

    for (auto autoLootListIterator = g_AutoLootList.begin(); autoLootListIterator != g_AutoLootList.end(); autoLootListIterator++)
    {
        if (*autoLootListIterator == itemName)
        {
            autoLootListIterator = g_AutoLootList.erase(autoLootListIterator);
            autoLootListIterator--;

            std::cout << "Auto Loot item removed: " << itemName << std::endl;
        }
    }
}