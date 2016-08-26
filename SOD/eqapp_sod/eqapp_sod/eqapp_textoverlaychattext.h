#ifndef EQAPP_TEXTOVERLAYCHATTEXT_H
#define EQAPP_TEXTOVERLAYCHATTEXT_H

bool g_textOverlayOnChatTextIsEnabled = true;
std::vector<std::string> g_textOverlayChatTextList;
int g_textOverlayChatTextDuration = 5000;

void EQAPP_TextOverlayChatText_Load();
void EQAPP_TextOverlayChatText_DisplayText(std::string text);
void EQAPP_TextOverlayChatText_Print();

void EQAPP_TextOverlayChatText_Load()
{
    std::cout << "Loading Text Overlay Chat Text..." << std::endl;

    g_textOverlayChatTextList.clear();

    std::string filePathStr = "eqapp/textoverlaychattext.txt";

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        g_textOverlayChatTextList.push_back(line);
    }

    file.close();
}

void EQAPP_TextOverlayChatText_DisplayText(std::string text)
{
    EQ_DisplayText(text.c_str(), g_textOverlayChatTextDuration);
}

void EQAPP_TextOverlayChatText_Print()
{
    std::cout << "Text Overlay Chat Text List:" << std::endl;

    for (auto& textOverlayChatText : g_textOverlayChatTextList)
    {
        std::cout << textOverlayChatText << std::endl;
    }
}

#endif // EQAPP_TEXTOVERLAYCHATTEXT_H
