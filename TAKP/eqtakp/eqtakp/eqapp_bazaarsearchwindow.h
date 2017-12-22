#pragma once

bool g_BazaarSearchWindowIsEnabled = true;

uint32_t g_BazaarSearchWindowItemNameColorARGB = 0xFFFF00FF;

std::vector<std::string> g_BazaarSearchWindowItemNamesList;

void EQAPP_BazaarSearchWindow_LoadItemNames();
void EQAPP_BazaarSearchWindow_HandleEvent_CListWnd__SetItemText(void* this_ptr, int index, int column, EQ::CXStr_ptr text);

void EQAPP_BazaarSearchWindow_LoadItemNames()
{
    std::cout << "Loading Bazaar Search Item Names..." << std::endl;

    g_BazaarSearchWindowItemNamesList.clear();
    g_BazaarSearchWindowItemNamesList.reserve(100);

    EQAPP_ReadFileToList("bazaarsearchitemnames.txt", g_BazaarSearchWindowItemNamesList);
}

void EQAPP_BazaarSearchWindow_HandleEvent_CListWnd__SetItemText(void* this_ptr, int index, int column, EQ::CXStr_ptr text)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (this_ptr == NULL)
    {
        return;
    }

    if (EQ_IsWindowVisible(EQ_ADDRESS_POINTER_CBazaarSearchWnd) == false)
    {
        return;
    }

    if (EQ_POINTER_CBazaarSearchWnd->SearchListWnd == NULL)
    {
        return;
    }

    if ((EQ::CListWnd_ptr)this_ptr != EQ_POINTER_CBazaarSearchWnd->SearchListWnd)
    {
        return;
    }

    if (text == NULL)
    {
        return;
    }

    std::string listText = text->Text;
    if (listText.size() == 0)
    {
        return;
    }

    if (column != 0)
    {
        return;
    }

    for (auto& itemName : g_BazaarSearchWindowItemNamesList)
    {
        if (listText.find(itemName) != std::string::npos)
        {
            ((EQClass::CListWnd*)this_ptr)->SetItemColor(index, 0, g_BazaarSearchWindowItemNameColorARGB);
            ((EQClass::CListWnd*)this_ptr)->SetItemColor(index, 1, g_BazaarSearchWindowItemNameColorARGB);
            ((EQClass::CListWnd*)this_ptr)->SetItemColor(index, 2, g_BazaarSearchWindowItemNameColorARGB);

            break;
        }
    }
}
