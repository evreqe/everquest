#pragma once

bool g_ChatEventIsEnabled = true;

bool g_ChatEventDebugIsEnabled = false;

std::unordered_map<std::string, std::string> g_ChatEventList;
uint32_t g_ChatEventList_reserve = 1024;

void EQAPP_ChatEvent_Toggle();
void EQAPP_ChatEvent_On();
void EQAPP_ChatEvent_Off();
void EQAPP_ChatEvent_Debug_Toggle();
void EQAPP_ChatEvent_Debug_On();
void EQAPP_ChatEvent_Debug_Off();
void EQAPP_ChatEvent_Load();
void EQAPP_ChatEvent_AddToList(std::string chatText, std::string commandText);
void EQAPP_ChatEvent_RemoveFromList(std::string chatText);
void EQAPP_ChatEvent_ClearList();
void EQAPP_ChatEvent_PrintList();
void EQAPP_ChatEvent_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);

void EQAPP_ChatEvent_Toggle()
{
    EQ_ToggleBool(g_ChatEventIsEnabled);
    EQAPP_PrintBool("Chat Event", g_ChatEventIsEnabled);
}

void EQAPP_ChatEvent_On()
{
    if (g_ChatEventIsEnabled == false)
    {
        EQAPP_ChatEvent_Toggle();
    }
}

void EQAPP_ChatEvent_Off()
{
    if (g_ChatEventIsEnabled == true)
    {
        EQAPP_ChatEvent_Toggle();
    }
}

void EQAPP_ChatEvent_Debug_Toggle()
{
    EQ_ToggleBool(g_ChatEventDebugIsEnabled);
    EQAPP_PrintBool("Chat Event Debug", g_ChatEventDebugIsEnabled);
}

void EQAPP_ChatEvent_Debug_On()
{
    if (g_ChatEventDebugIsEnabled == false)
    {
        EQAPP_ChatEvent_Debug_Toggle();
    }
}

void EQAPP_ChatEvent_Debug_Off()
{
    if (g_ChatEventDebugIsEnabled == true)
    {
        EQAPP_ChatEvent_Debug_Toggle();
    }
}

void EQAPP_ChatEvent_Load()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.size() == 0)
    {
        return;
    }

    g_ChatEventList.clear();
    g_ChatEventList.reserve(g_ChatEventList_reserve);

    std::stringstream filePath;
    filePath << g_EQAppName << "/chatevent/" << playerName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    std::cout << "Loading chat events..." << std::endl;

    unsigned int index = 0;

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

        if (EQAPP_String_Contains(line, "|") == false)
        {
            continue;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(line, '|');
        if (tokens.size() != 2)
        {
            continue;
        }

        //std::string chatText = tokens.at(0);
        //std::string commandText = tokens.at(1);

        //std::cout << "[" << index << "] Chat Text: " << chatText << std::endl;
        //std::cout << "[" << index << "] Command Text: " << commandText << std::endl;

        //g_ChatEventList.insert(std::make_pair(chatText, commandText));

        g_ChatEventList.insert(std::make_pair(tokens.at(0), tokens.at(1)));

        index++;
    }

    file.close();
}

void EQAPP_ChatEvent_AddToList(std::string chatText, std::string commandText)
{
    if (chatText.size() == 0)
    {
        return;
    }

    if (commandText.size() == 0)
    {
        return;
    }

    g_ChatEventList.insert(std::make_pair(chatText, commandText));
}

void EQAPP_ChatEvent_RemoveFromList(std::string chatText)
{
    g_ChatEventList.erase(chatText);
}

void EQAPP_ChatEvent_ClearList()
{
    g_ChatEventList.clear();
    g_ChatEventList.reserve(g_ChatEventList_reserve);
}

void EQAPP_ChatEvent_PrintList()
{
    std::cout << "Chat Events:" << std::endl;

    bool bDisable = false;

    if (g_ChatEventIsEnabled == true)
    {
        bDisable = true;

        g_ChatEventIsEnabled = false;
    }

    unsigned int index = 0;

    for (auto& keyValue : g_ChatEventList)
    {
        std::cout << "[" << index << "] Chat Text: " << keyValue.first << std::endl;
        std::cout << "[" << index << "] Command Text: " << keyValue.second << std::endl;

        index++;
    }

    if (bDisable == true)
    {
        g_ChatEventIsEnabled = true;
    }
}

void EQAPP_ChatEvent_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    if (g_ChatEventDebugIsEnabled == true)
    {
        EQAPP_PrintTextToFile("chateventdebug.txt", text.c_str());
    }

    for (auto& keyValue : g_ChatEventList)
    {
        if (text == keyValue.first)
        {
            EQ_InterpretCommand(keyValue.second.c_str());
            return;
        }

        std::string findText = keyValue.first;

        if (EQAPP_String_BeginsWith(findText, "@") == true)
        {
            findText.erase(0, 1);

            if (EQAPP_String_Contains(text, findText) == true)
            {
                EQ_InterpretCommand(keyValue.second.c_str());
                return;
            }
        }

        if (EQAPP_String_BeginsWith(findText, "{") == true)
        {
            findText.erase(0, 1);

            if (EQAPP_String_BeginsWith(text, findText) == true)
            {
                EQ_InterpretCommand(keyValue.second.c_str());
                return;
            }
        }

        if (EQAPP_String_BeginsWith(findText, "}") == true)
        {
            findText.erase(0, 1);

            if (EQAPP_String_EndsWith(text, findText) == true)
            {
                EQ_InterpretCommand(keyValue.second.c_str());
                return;
            }
        }
    }
}
