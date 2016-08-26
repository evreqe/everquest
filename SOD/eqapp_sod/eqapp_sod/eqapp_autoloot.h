#ifndef EQAPP_AUTOLOOT_H
#define EQAPP_AUTOLOOT_H

bool g_autoLootIsEnabled = false;
std::vector<std::string> g_autoLootList;
DWORD g_autoLootTimer = 0;
DWORD g_autoLootTimerDelay = 500;

void EQAPP_AutoLoot_Execute();
void EQAPP_AutoLoot_Toggle();
void EQAPP_AutoLoot_Reset();
void EQAPP_AutoLoot_Add(const char* itemName);
void EQAPP_AutoLoot_Remove(const char* itemName);
void EQAPP_AutoLoot_Print();

void EQAPP_AutoLoot_Execute()
{
    if (g_autoLootIsEnabled == false || g_autoLootList.size() == 0)
    {
        return;
    }

    if (EQ_IsWindowVisible(EQ_POINTER_CLootWnd) == false)
    {
        g_autoLootTimer = EQ_GetTimer();
        return;
    }

    if (EQ_HasTimePassed(g_autoLootTimer, g_autoLootTimerDelay) == false)
    {
        return;
    }

    for (auto& itemName : g_autoLootList)
    {
        bool result = EQ_LootItemByName(itemName.c_str());
        if (result == true)
        {
            std::cout << "Auto Loot Item: " << itemName << std::endl;
        }
    }
}

void EQAPP_AutoLoot_Toggle()
{
    EQ_ToggleBool(g_autoLootIsEnabled);

    if (g_autoLootIsEnabled == false)
    {
        g_autoLootList.clear();
    }

    EQAPP_PrintBool("Auto Loot", g_autoLootIsEnabled);
}

void EQAPP_AutoLoot_Reset()
{
    g_autoLootList.clear();

    std::cout << "Auto Loot reset." << std::endl;
}

void EQAPP_AutoLoot_Add(const char* itemName)
{
    if (itemName == NULL || strlen(itemName) == 0)
    {
        return;
    }

    g_autoLootList.push_back(itemName);

    std::cout << "Auto Loot item added: " << itemName << std::endl;
}

void EQAPP_AutoLoot_Remove(const char* itemName)
{
    if (itemName == NULL || strlen(itemName) == 0)
    {
        return;
    }

    for (auto autoLootListIterator = g_autoLootList.begin(); autoLootListIterator != g_autoLootList.end(); autoLootListIterator++)
    {
        if (strcmp(autoLootListIterator->c_str(), itemName) == 0)
        {
            autoLootListIterator = g_autoLootList.erase(autoLootListIterator);
            autoLootListIterator--;

            std::cout << "Auto Loot item removed: " << itemName << std::endl;
        }
    }
}

void EQAPP_AutoLoot_Print()
{
    std::cout << "Auto Loot List:" << std::endl;

    for (auto& itemName : g_autoLootList)
    {
        std::cout << itemName << std::endl;
    }
}

#endif // EQAPP_AUTOLOOT_H
