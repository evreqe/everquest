#pragma once

bool g_BazaarFilterIsEnabled = false;

bool g_BazaarFilterBeepIsEnabled = false;

EQApp::Timer g_BazaarFilterDoQueryTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BazaarFilterDoQueryTimerInterval = 10;

std::vector<std::string> g_BazaarFilterItemNameList;
uint32_t g_BazaarFilterItemNameList_reserve = 1024;

// 1    = 1cp    one copper piece
// 1000 = 1pp    one platinum piece
uint32_t g_BazaarFilterItemPriceMinimum = 1;
uint32_t g_BazaarFilterItemPriceMaximum = 1000 * 1000;

void EQAPP_BazaarFilter_Toggle();
void EQAPP_BazaarFilter_Beep_Toggle();
void EQAPP_BazaarFilter_Load();
void EQAPP_BazaarFilter_LoadEx(const char* filename);
bool EQAPP_BazaarFilter_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName);
void EQAPP_BazaarFilter_PrintItemNameList();

void EQAPP_BazaarFilter_Toggle()
{
    EQ_ToggleBool(g_BazaarFilterIsEnabled);
    EQAPP_PrintBool("Bazaar Filter", g_BazaarFilterIsEnabled);

    if (g_BazaarFilterIsEnabled == true)
    {
        EQAPP_BazaarFilter_Load();
    }
}

void EQAPP_BazaarFilter_Beep_Toggle()
{
    EQ_ToggleBool(g_BazaarFilterBeepIsEnabled);
    EQAPP_PrintBool("Bazaar Filter Beep", g_BazaarFilterBeepIsEnabled);
}

void EQAPP_BazaarFilter_Load()
{
    std::stringstream fileName;
    fileName << g_EQAppName << "-bazaarfilter.txt";

    EQAPP_BazaarFilter_LoadEx(fileName.str().c_str());
}

void EQAPP_BazaarFilter_LoadEx(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filename;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str());
        return;
    }

    g_BazaarFilterItemNameList.clear();
    g_BazaarFilterItemNameList.reserve(g_BazaarFilterItemNameList_reserve);

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (EQAPP_String_StartsWith(line, "#") == true)
        {
            continue;
        }

        g_BazaarFilterItemNameList.push_back(line);
    }

    file.close();
}

bool EQAPP_BazaarFilter_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName)
{
    bool bShouldAddItemToList = false;

    if (strlen(itemName) == 0)
    {
        return bShouldAddItemToList;
    }

    for (auto& filterItemName : g_BazaarFilterItemNameList)
    {
        std::string itemNameAdd = itemName;
        std::string itemNameFilter = filterItemName;

        bool bUseExactComparsion = true;

        if (itemNameFilter.size() > 1)
        {
            if (EQAPP_String_StartsWith(itemNameFilter, "@") == true)
            {
                itemNameFilter.erase(0, 1);

                bUseExactComparsion = false;
            }
        }

        if (bUseExactComparsion == true)
        {
            if (itemNameAdd == itemNameFilter)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
        else
        {
            if (EQAPP_String_Contains(itemNameAdd, itemNameFilter) == true)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
    }

    if (itemPrice < g_BazaarFilterItemPriceMinimum || itemPrice > g_BazaarFilterItemPriceMaximum)
    {
        bShouldAddItemToList = false;
    }

    if (bShouldAddItemToList == true)
    {
        if (g_BazaarFilterBeepIsEnabled == true)
        {
            EQAPP_Beep();
        }
    }

    return bShouldAddItemToList;
}

void EQAPP_BazaarFilter_PrintItemNameList()
{
    std::cout << "Bazaar Filter Item Name List:" << std::endl;

    for (auto& itemName : g_BazaarFilterItemNameList)
    {
        std::cout << itemName << std::endl;
    }
}