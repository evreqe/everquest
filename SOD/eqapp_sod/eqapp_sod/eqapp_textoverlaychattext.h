#pragma once

bool g_textOverlayOnChatTextIsEnabled = true;
std::vector<std::string> g_textOverlayChatTextList;
uint32_t g_textOverlayChatTextDuration = 5000;

void EQAPP_TextOverlayChatText_Load();
void EQAPP_TextOverlayChatText_DisplayText(std::string text);
void EQAPP_TextOverlayChatText_Print();

void EQAPP_TextOverlayChatText_Load()
{
    std::cout << "Loading Text Overlay Chat Text..." << std::endl;

    g_textOverlayChatTextList.clear();

    EQAPP_ReadFileToList("textoverlaychattext.txt", g_textOverlayChatTextList);
}

void EQAPP_TextOverlayChatText_DisplayText(std::string text)
{
    EQ_DisplayText(text.c_str(), g_textOverlayChatTextDuration);
}

void EQAPP_TextOverlayChatText_Print()
{
    std::cout << "Text Overlay Chat Text List:" << std::endl;

    for (auto& text : g_textOverlayChatTextList)
    {
        std::cout << text << std::endl;
    }
}

