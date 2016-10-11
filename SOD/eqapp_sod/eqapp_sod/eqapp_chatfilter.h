#pragma once

bool g_chatFilterIsEnabled = true;
std::vector<std::string> g_chatFilterList;

void EQAPP_ChatFilter_Load();
void EQAPP_ChatFilter_Reset();
void EQAPP_ChatFilter_Add(const char* chatText);
void EQAPP_ChatFilter_Remove(const char* chatText);
void EQAPP_ChatFilter_Print();

void EQAPP_ChatFilter_Load()
{
    std::cout << "Loading Chat Filter..." << std::endl;

    g_chatFilterList.clear();

    EQAPP_ReadFileToList("chatfilter.txt", g_chatFilterList);
}

void EQAPP_ChatFilter_Reset()
{
    g_chatFilterList.clear();

    std::cout << "Chat Filter reset." << std::endl;
}

void EQAPP_ChatFilter_Add(const char* chatText)
{
    if (chatText == NULL || strlen(chatText) == 0)
    {
        return;
    }

    g_chatFilterList.push_back(chatText);

    std::cout << "Chat Filter text added: " << chatText << std::endl;
}

void EQAPP_ChatFilter_Remove(const char* chatText)
{
    if (chatText == NULL || strlen(chatText) == 0)
    {
        return;
    }

    for (auto chatFilterListIterator = g_chatFilterList.begin(); chatFilterListIterator != g_chatFilterList.end(); chatFilterListIterator++)
    {
        if (strcmp(chatFilterListIterator->c_str(), chatText) == 0)
        {
            chatFilterListIterator = g_chatFilterList.erase(chatFilterListIterator);
            chatFilterListIterator--;

            std::cout << "Chat Filter text removed: " << chatText << std::endl;
        }
    }
}

void EQAPP_ChatFilter_Print()
{
    std::cout << "Chat Filter List:" << std::endl;

    for (auto& text : g_chatFilterList)
    {
        std::cout << text << std::endl;
    }
}
