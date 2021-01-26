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
void EQAPP_ChatEvent_LoadEx(const char* filename);
void EQAPP_ChatEvent_AddToList(const std::string& chatText, const std::string& commandText);
void EQAPP_ChatEvent_RemoveFromList(const std::string& chatText);
void EQAPP_ChatEvent_ClearList();
void EQAPP_ChatEvent_PrintList();
void EQAPP_ChatEvent_HandleEvent_CEverQuest__dsp_chat(std::string_view chatText, int chatTextColor);

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
    g_ChatEventList.clear();
    g_ChatEventList.reserve(g_ChatEventList_reserve);

    std::stringstream filePath;
    filePath << g_EQAppName << "/chatevent.txt";

    EQAPP_ChatEvent_LoadEx(filePath.str().c_str());

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.empty() == true)
    {
        return;
    }

    std::stringstream filePath2;
    filePath2 << g_EQAppName << "/chatevent/" << playerName << ".txt";

    EQAPP_ChatEvent_LoadEx(filePath2.str().c_str());
}

void EQAPP_ChatEvent_LoadEx(const char* filename)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.empty() == true)
    {
        return;
    }

    std::fstream file;
    file.open(filename, std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filename;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    unsigned int index = 0;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() == true)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        if (EQAPP_String_Contains(line, "^") == false)
        {
            continue;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(line, '^');
        if (tokens.size() != 2)
        {
            continue;
        }

        //std::string chatText = tokens.at(0);
        //std::string commandText = tokens.at(1);

        //std::cout << "[" << index << "] Chat Text: " << chatText << "\n";
        //std::cout << "[" << index << "] Command Text: " << commandText << "\n";

        //g_ChatEventList.insert(std::make_pair(chatText, commandText));

        g_ChatEventList.insert(std::make_pair(tokens.at(0), tokens.at(1)));

        index++;
    }

    std::cout << "Chat Events loaded from file: " << filename << "\n";

    file.close();
}

void EQAPP_ChatEvent_AddToList(const std::string& chatText, const std::string& commandText)
{
    if (chatText.empty() == true)
    {
        return;
    }

    if (commandText.empty() == true)
    {
        return;
    }

    g_ChatEventList.insert(std::make_pair(chatText, commandText));
}

void EQAPP_ChatEvent_RemoveFromList(const std::string& chatText)
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
    std::cout << "Chat Events:\n";

    // bDisable is used to temporarily disable Chat Event
    // so that the events are not reacted to when
    // printing out the search text

    bool bDisable = false;

    if (g_ChatEventIsEnabled == true)
    {
        bDisable = true;

        g_ChatEventIsEnabled = false;
    }

    unsigned int index = 1;

    for (auto& [searchText, commandText] : g_ChatEventList)
    {
        std::cout << "[" << index << "] Search Text: " << searchText << "\n";
        std::cout << "[" << index << "] Command Text: " << commandText << "\n";

        index++;
    }

    if (bDisable == true)
    {
        g_ChatEventIsEnabled = true;
    }
}

void EQAPP_ChatEvent_HandleEvent_CEverQuest__dsp_chat(std::string_view chatText, int chatTextColor)
{
    if (g_ChatEventDebugIsEnabled == true)
    {
        EQAPP_PrintTextToFile("chatevent_debug.txt", chatText.data());
    }

    for (auto& [searchText, commandText] : g_ChatEventList)
    {
        if (chatText == searchText)
        {
            EQ_InterpretCommand(commandText.c_str());
            return;
        }

        std::string_view searchTextWithoutPrefix = searchText;

        searchTextWithoutPrefix.remove_prefix(1);

        if (EQAPP_String_BeginsWith(searchText, "@") == true)
        {
            if (EQAPP_StringView_Contains(chatText, searchTextWithoutPrefix) == true)
            {
                EQ_InterpretCommand(commandText.c_str());
                return;
            }
        }

        if (EQAPP_String_BeginsWith(searchText, "{") == true)
        {
            if (EQAPP_StringView_BeginsWith(chatText, searchTextWithoutPrefix) == true)
            {
                EQ_InterpretCommand(commandText.c_str());
                return;
            }
        }

        if (EQAPP_String_BeginsWith(searchText, "}") == true)
        {
            if (EQAPP_StringView_EndsWith(chatText, searchTextWithoutPrefix) == true)
            {
                EQ_InterpretCommand(commandText.c_str());
                return;
            }
        }
    }
}
