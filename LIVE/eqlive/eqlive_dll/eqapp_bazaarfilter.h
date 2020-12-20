#pragma once

bool g_BazaarFilterIsEnabled = false;

bool g_BazaarFilterBeepIsEnabled = false;

std::vector<std::string> g_BazaarFilterItemNameList;
uint32_t g_BazaarFilterItemNameList_reserve = 1024;

// 1    = 1cp                  one copper piece
// 1000 = 1pp                  one platinum piece
// 100000 = 100pp              one hundred platinum pieces
// 2000000000 = 2,000,000pp    two million platinum pieces
uint32_t g_BazaarFilterItemPriceMinimum = 1;       // 1cp
uint32_t g_BazaarFilterItemPriceMaximum = 2000000000;    // 2,000,000pp

void EQAPP_BazaarFilter_Toggle();
void EQAPP_BazaarFilter_On();
void EQAPP_BazaarFilter_Off();
void EQAPP_BazaarFilter_Beep_Toggle();
void EQAPP_BazaarFilter_Load();
void EQAPP_BazaarFilter_LoadEx(const char* fileName);
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

void EQAPP_BazaarFilter_On()
{
    if (g_BazaarFilterIsEnabled == false)
    {
        EQAPP_BazaarFilter_Toggle();
    }
}

void EQAPP_BazaarFilter_Off()
{
    if (g_BazaarFilterIsEnabled == true)
    {
        EQAPP_BazaarFilter_Toggle();
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
    fileName << g_EQAppName << "/bazaarfilter.txt";

    EQAPP_BazaarFilter_LoadEx(fileName.str().c_str());
}

void EQAPP_BazaarFilter_LoadEx(const char* fileName)
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

    g_BazaarFilterItemNameList.clear();
    g_BazaarFilterItemNameList.reserve(g_BazaarFilterItemNameList_reserve);

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

        g_BazaarFilterItemNameList.push_back(line);
    }

    std::cout << "Bazaar Filter loaded from file: " << fileName << "\n";

    file.close();
}

bool EQAPP_BazaarFilter_HandleEvent_CBazaarSearchWnd__AddItemToList(char* itemName, uint32_t itemPrice, char* traderName)
{
    if (itemPrice < g_BazaarFilterItemPriceMinimum || itemPrice > g_BazaarFilterItemPriceMaximum)
    {
        return false;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    bool bShouldAddItemToList = false;

    auto playerSpawnClass = EQ_GetSpawnClass(playerSpawn);

    std::string playerSpawnClassShortName = EQ_GetClassShortNameByID(playerSpawnClass);

    for (auto& filterItemName : g_BazaarFilterItemNameList)
    {
        std::string itemNameAdd = itemName;
        std::string itemNameFilter = filterItemName;

        EQApp::StringComparisonType comparsionType = EQApp::StringComparisonType::Equals;

        if (itemNameFilter.size() > 1)
        {
            if (EQAPP_String_BeginsWith(itemNameFilter, "!") == true)
            {
                itemNameFilter.erase(0, 1);

                comparsionType = EQApp::StringComparisonType::Ignore;
            }
            else if (EQAPP_String_BeginsWith(itemNameFilter, "@") == true)
            {
                itemNameFilter.erase(0, 1);

                comparsionType = EQApp::StringComparisonType::Contains;
            }
            else if (EQAPP_String_BeginsWith(itemNameFilter, "{") == true)
            {
                itemNameFilter.erase(0, 1);

                comparsionType = EQApp::StringComparisonType::BeginsWith;
            }
            else if (EQAPP_String_BeginsWith(itemNameFilter, "}") == true)
            {
                itemNameFilter.erase(0, 1);

                comparsionType = EQApp::StringComparisonType::EndsWith;
            }
        }

        if (comparsionType == EQApp::StringComparisonType::Equals)
        {
            if (itemNameAdd == itemNameFilter)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
        else if (comparsionType == EQApp::StringComparisonType::Ignore)
        {
            if (itemNameAdd == itemNameFilter)
            {
                bShouldAddItemToList = false;
                break;
            }
        }
        else if (comparsionType == EQApp::StringComparisonType::Contains)
        {
            if (EQAPP_String_Contains(itemNameAdd, itemNameFilter) == true)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
        else if (comparsionType == EQApp::StringComparisonType::BeginsWith)
        {
            if (EQAPP_String_BeginsWith(itemNameAdd, itemNameFilter) == true)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
        else if (comparsionType == EQApp::StringComparisonType::EndsWith)
        {
            if (EQAPP_String_EndsWith(itemNameAdd, itemNameFilter) == true)
            {
                bShouldAddItemToList = true;
                break;
            }
        }
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
    std::cout << "Bazaar Filter Item Name List:\n";

    for (auto& itemName : g_BazaarFilterItemNameList)
    {
        std::cout << itemName << "\n";
    }
}

