#pragma once

bool g_InterpretCmdIsEnabled = true;

void EQAPP_InterpretCmd_NULL();

void EQAPP_InterpretCmd_NULL()
{
    return;
}

std::map<std::string, std::function<void()>> g_InterpretCmdList =
{
    {"//Null",                         &EQAPP_InterpretCmd_NULL},
    {"//AlwaysAttack",                 &EQAPP_AlwaysAttack_Toggle},
    {"//AA",                           &EQAPP_AlwaysAttack_Toggle},
    {"//CombatHotButton",              &EQAPP_CombatHotButton_Toggle},
    {"//CHB",                          &EQAPP_CombatHotButton_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
};

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_);
bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText);
void EQAPP_InterpretCmd_Execute(std::string commandText);
bool EQAPP_InterpretCmd_HandleCommandText(std::string commandText);

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_)
{
    if (player == NULL || commandText_ == NULL)
    {
        return true;
    }

    std::string commandText = commandText_;
    if (commandText.size() == 0)
    {
        return true;
    }

    if (commandText.find("%PlayerID") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            uint32_t spawnID = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_ID);

            std::string strID = std::to_string(spawnID);
            if (strID.size() != 0)
            {
                EQAPP_String_ReplaceAll(commandText, "%PlayerID", strID);
            }
        }
    }

    if (commandText.find("%TargetID") != std::string::npos)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            uint32_t spawnID = EQ_ReadMemory<uint32_t>(targetSpawn + EQ_OFFSET_SPAWN_ID);

            std::string strID = std::to_string(spawnID);
            if (strID.size() != 0)
            {
                EQAPP_String_ReplaceAll(commandText, "%TargetID", strID);
            }
        }
    }

    std::string firstTwoCharacters = commandText.substr(0, 2);
    if (firstTwoCharacters == "//")
    {
        EQAPP_InterpretCmd_Execute(commandText);
        return true;
    }
    else
    {
        if (commandText.find("//") != std::string::npos)
        {
            return true;
        }

        if (commandText.find("/") != std::string::npos)
        {
            for (auto& cmd : g_InterpretCmdList)
            {
                std::string cmdText = cmd.first;
                std::string cmdTextStripped = cmdText.substr(2, cmdText.size());

                if (commandText.find(cmdTextStripped) != std::string::npos)
                {
                    return true;
                }
            }
        }

        for (auto& cmd : g_InterpretCmdList)
        {
            if (commandText == cmd.first)
            {
                return true;
            }
        }
    }

    return false;
}

bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText)
{
    if (commandText.find("\"") == std::string::npos && commandText.back() != '"')
    {
        std::cout << "InterpretCmd Error: Command argument missing quotes." << std::endl;
        return false;
    }

    return true;
}

void EQAPP_InterpretCmd_Execute(std::string commandText)
{
    if (commandText.size() == 0)
    {
        return;
    }

    std::cout << "InterpretCmd: " << commandText << std::endl;

    bool result = EQAPP_InterpretCmd_HandleCommandText(commandText);
    if (result == true)
    {
        return;
    }

    // handle interpret command list functions
    auto cmd = g_InterpretCmdList.find(commandText);
    if (cmd != g_InterpretCmdList.end())
    {
        cmd->second();
        return;
    }
}

bool EQAPP_InterpretCmd_HandleCommandText(std::string commandText)
{
    if (commandText == "//Help" || commandText == "//Commands")
    {
        std::cout << "Command List: " << std::endl;

        for (auto& cmd : g_InterpretCmdList)
        {
            std::cout << cmd.first << std::endl;
        }

        return true;
    }

    if (commandText == "//Test")
    {
        EQ_WriteChatText("Test!");

        return true;
    }

    if (commandText == "//WindowTitle")
    {
        EQAPP_SetWindowTitleToPlayerSpawnName();

        return true;
    }

    if (commandText == "//AcceptInvite")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETME, 1);
        EQ_ExecuteCommand(EQ_EXECUTECMD_INVITE_FOLLOW, 1);
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);

        return true;
    }

    if (commandText == "//TargetSelf")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETME, 1);

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Target ") == true)
    {
        std::vector<std::string> tokens;
        EQAPP_String_Split(commandText, tokens, ' ');

        if (tokens.size() > 1)
        {
            std::string spawnName = tokens.at(1);
            if (spawnName.size() != 0)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    auto spawn = EQ_GetSpawnByName(spawnName.c_str());
                    if (spawn != NULL)
                    {
                        EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN, spawn);

                        std::cout << "Target: " << spawnName << std::endl;
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//TargetID ") == true)
    {
        std::vector<std::string> tokens;
        EQAPP_String_Split(commandText, tokens, ' ');

        if (tokens.size() > 1)
        {
            std::string str = tokens.at(1);
            if (str.size() != 0)
            {
                uint32_t spawnID = std::stoul(str);

                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    auto spawn = EQ_GetSpawnByID(spawnID);
                    if (spawn != NULL)
                    {
                        EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN, spawn);

                        std::cout << "Target by ID: " << str << std::endl;
                    }
                }
            }
        }

        return true;
    }

    if (commandText == "//Follow")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, targetSpawn);
            }
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Follow ") == true)
    {
        std::vector<std::string> tokens;
        EQAPP_String_Split(commandText, tokens, ' ');

        if (tokens.size() > 1)
        {
            std::string spawnName = tokens.at(1);
            if (spawnName.size() != 0)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    auto spawn = EQ_GetSpawnByName(spawnName.c_str());
                    if (spawn != NULL)
                    {
                        EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN, spawn);
                        EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, spawn);

                        std::cout << "Follow: " << spawnName << std::endl;
                    }
                }
            }
        }

        return true;
    }

    if (commandText == "//StopFollow")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, 0);
            EQ_WriteMemory<uint32_t>(EQ_ADDRESS_AUTO_RUN, 0);
        }

        return true;
    }

    if (commandText == "//StopCast")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_STOP_CAST, 1);

        return true;
    }

    if (commandText == "//StopAction")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_STOP_ACTION, 1);

        return true;
    }

    if (commandText == "//ClearTarget")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);

        return true;
    }

    if (commandText == "//CloseTopWindow")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLOSE_TOP_WINDOW, 1);

        return true;
    }

    if (commandText == "//HotButton1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_1, 1);

        return true;
    }

    if (commandText == "//HotButton2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_2, 1);

        return true;
    }

    if (commandText == "//HotButton3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_3, 1);

        return true;
    }

    if (commandText == "//HotButton4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_4, 1);

        return true;
    }

    if (commandText == "//HotButton5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_5, 1);

        return true;
    }

    if (commandText == "//HotButton6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_6, 1);

        return true;
    }

    if (commandText == "//HotButton7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_7, 1);

        return true;
    }

    if (commandText == "//HotButton8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_8, 1);

        return true;
    }

    if (commandText == "//HotButton9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_9, 1);

        return true;
    }

    if (commandText == "//HotButton10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_10, 1);

        return true;
    }

    if (commandText == "//HotButton11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_11, 1);

        return true;
    }

    if (commandText == "//HotButton12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_12, 1);

        return true;
    }

    if (commandText == "//HotButton2_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_1, 1);

        return true;
    }

    if (commandText == "//XTarget1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_1, 1);

        return true;
    }

    if (commandText == "//XTarget2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_2, 1);

        return true;
    }

    if (commandText == "//XTarget3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_3, 1);

        return true;
    }

    if (commandText == "//XTarget4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_4, 1);

        return true;
    }

    if (commandText == "//XTarget5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_5, 1);

        return true;
    }

    if (commandText == "//XTarget6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_6, 1);

        return true;
    }

    if (commandText == "//XTarget7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_7, 1);

        return true;
    }

    if (commandText == "//XTarget8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_8, 1);

        return true;
    }

    if (commandText == "//XTarget9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_9, 1);

        return true;
    }

    if (commandText == "//XTarget10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_10, 1);

        return true;
    }

    if (commandText == "//XTarget11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_11, 1);

        return true;
    }

    if (commandText == "//XTarget12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_12, 1);

        return true;
    }

    if (commandText == "//XTarget13")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_13, 1);

        return true;
    }

    if (commandText == "//XTarget14")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_14, 1);

        return true;
    }

    if (commandText == "//XTarget15")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_15, 1);

        return true;
    }

    if (commandText == "//XTarget16")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_16, 1);

        return true;
    }

    if (commandText == "//XTarget17")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_17, 1);

        return true;
    }

    if (commandText == "//XTarget18")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_18, 1);

        return true;
    }

    if (commandText == "//XTarget19")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_19, 1);

        return true;
    }

    if (commandText == "//XTarget20")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGET_XTARGET_20, 1);

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BCC ") == true)
    {
        std::vector<std::string> tokens;
        EQAPP_String_Split(commandText, tokens, ' ');

        if (tokens.size() > 1)
        {
            std::string name = tokens.at(1);
            if (name.size() != 0)
            {
                std::cout << "Box Chat Connect as Name: " << name << std::endl;

                if (EQAPP_BoxChat_Connect(name) == false)
                {
                    std::cout << "Box Chat failed to connect!" << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//BoxChatConnect" || commandText == "//BCC")
    {
        std::string playerSpawnName = EQ_GetPlayerSpawnName();
        if (playerSpawnName.size() != 0)
        {
            if (EQAPP_BoxChat_Connect(playerSpawnName) == false)
            {
                std::cout << "Box Chat failed to connect!" << std::endl;
            }

            EQAPP_SetWindowTitleToPlayerSpawnName();
        }

        return true;
    }

    if (commandText == "//BoxChatDisconnect" || commandText == "//BCD")
    {
        EQAPP_BoxChat_Disconnect();

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BCT ") == true)
    {
        std::vector<std::string> tokens;
        EQAPP_String_Split(commandText, tokens, ' ');

        if (tokens.size() > 1)
        {
            std::string spawnName = tokens.at(1);
            if (spawnName.size() != 0)
            {
                EQAPP_BoxChat_SendText(commandText);

                std::cout << "Box Chat to '" << spawnName << "': " << commandText << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BCA ") == true)
    {
        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to Others: " << commandText << std::endl;

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BCAA ") == true)
    {
        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to All: " << commandText << std::endl;

        return true;
    }

    return false;
}
