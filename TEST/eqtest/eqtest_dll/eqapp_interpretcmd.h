#pragma once

bool g_InterpretCmdIsEnabled = true;

void EQAPP_InterpretCmd_NULL();

void EQAPP_InterpretCmd_NULL()
{
    return;
}

std::map<std::string, std::function<void()>> g_InterpretCmdList =
{
    {"//AlwaysAttack",                 &EQAPP_AlwaysAttack_Toggle},
    {"//AA",                           &EQAPP_AlwaysAttack_Toggle},
    {"//CombatHotButton",              &EQAPP_CombatHotButton_Toggle},
    {"//CHB",                          &EQAPP_CombatHotButton_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    ////{"//Null",                         &EQAPP_InterpretCmd_NULL},
    {"//Test",                         &EQAPP_InterpretCmd_NULL},
    {"//WindowTitle",                  &EQAPP_InterpretCmd_NULL},
    {"//AcceptInvite",                 &EQAPP_InterpretCmd_NULL},
    {"//Disband",                      &EQAPP_InterpretCmd_NULL},
    {"//ShrinkTarget",                 &EQAPP_InterpretCmd_NULL},
    {"//GrowTarget",                   &EQAPP_InterpretCmd_NULL},
    {"//FaceTarget",                   &EQAPP_InterpretCmd_NULL},
    {"//TargetMe",                     &EQAPP_InterpretCmd_NULL},
    {"//Target",                       &EQAPP_InterpretCmd_NULL},
    {"//TargetID",                     &EQAPP_InterpretCmd_NULL},
    {"//Follow",                       &EQAPP_InterpretCmd_NULL},
    {"//StopFollow",                   &EQAPP_InterpretCmd_NULL},
    {"//StopCast",                     &EQAPP_InterpretCmd_NULL},
    {"//StopAction",                   &EQAPP_InterpretCmd_NULL},
    {"//ClearTarget",                  &EQAPP_InterpretCmd_NULL},
    {"//CloseTopWindow",               &EQAPP_InterpretCmd_NULL},
    {"//CloseTopWindows",              &EQAPP_InterpretCmd_NULL},
    {"//Hail",                         &EQAPP_InterpretCmd_NULL},
    {"//Use",                          &EQAPP_InterpretCmd_NULL},
    {"//Jump",                         &EQAPP_InterpretCmd_NULL},
    {"//ConfirmNo",                    &EQAPP_InterpretCmd_NULL},
    {"//ConfirmYes",                   &EQAPP_InterpretCmd_NULL},
    {"//PitchDown",                    &EQAPP_InterpretCmd_NULL},
    {"//PitchUp",                      &EQAPP_InterpretCmd_NULL},
    {"//CenterView",                   &EQAPP_InterpretCmd_NULL},
    {"//FirstPersonCamera",            &EQAPP_InterpretCmd_NULL},
    {"//OpenBags",                     &EQAPP_InterpretCmd_NULL},
    {"//CloseBags",                    &EQAPP_InterpretCmd_NULL},
    {"//HotButton1",                   &EQAPP_InterpretCmd_NULL},
    {"//XTarget1",                     &EQAPP_InterpretCmd_NULL},
    {"//Potion1",                      &EQAPP_InterpretCmd_NULL},
    {"//ESPFindName",                  &EQAPP_InterpretCmd_NULL},
    {"//ESPFindLastName",              &EQAPP_InterpretCmd_NULL},
    {"//Multi",                        &EQAPP_InterpretCmd_NULL},
    {"//MultiRandom",                  &EQAPP_InterpretCmd_NULL},
    {"//CastRandom",                   &EQAPP_InterpretCmd_NULL},
    {"//DoAbility",                    &EQAPP_InterpretCmd_NULL},
    {"//DoAbilityRandom",              &EQAPP_InterpretCmd_NULL},
    {"//Discipline",                   &EQAPP_InterpretCmd_NULL},
    {"//DisciplineRandom",             &EQAPP_InterpretCmd_NULL},
    {"//AltActivate",                  &EQAPP_InterpretCmd_NULL},
    {"//AltActivateRandom",            &EQAPP_InterpretCmd_NULL},
    {"//BCC",                          &EQAPP_InterpretCmd_NULL},
    {"//BCD",                          &EQAPP_InterpretCmd_NULL},
    {"//BCT",                          &EQAPP_InterpretCmd_NULL},
    {"//BCA",                          &EQAPP_InterpretCmd_NULL},
    {"//BCAA",                         &EQAPP_InterpretCmd_NULL},
    {"//BoxChatConnect",               &EQAPP_InterpretCmd_NULL},
    {"//BoxChatDisconnect",            &EQAPP_InterpretCmd_NULL},
    {"//BoxChatTell",                  &EQAPP_InterpretCmd_NULL},
    {"//BoxChatOthers",                &EQAPP_InterpretCmd_NULL},
    {"//BoxChatAll",                   &EQAPP_InterpretCmd_NULL},
};

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_);
bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText);
void EQAPP_InterpretCmd_InterpretArguments(const std::string& commandText, const std::string& prependText);
void EQAPP_InterpretCmd_InterpretRandomArgument(const std::string& commandText, const std::string& prependText);
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

void EQAPP_InterpretCmd_InterpretArguments(const std::string& commandText, const std::string& prependText)
{
    std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
    if (commandTextAfterSpace.size() == 0)
    {
        return;
    }

    if (commandTextAfterSpace.find(";") == std::string::npos)
    {
        return;
    }

    std::vector<std::string> tokens;
    EQAPP_String_Split(commandTextAfterSpace, tokens, ';');

    if (tokens.size() == 0)
    {
        return;
    }

    for (auto& token : tokens)
    {
        std::stringstream ss;
        ss << prependText << token;

        EQ_InterpretCommand(ss.str().c_str());
    }
}

void EQAPP_InterpretCmd_InterpretRandomArgument(const std::string& commandText, const std::string& prependText)
{
    std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
    if (commandTextAfterSpace.size() == 0)
    {
        return;
    }

    if (commandTextAfterSpace.find(";") == std::string::npos)
    {
        return;
    }

    std::vector<std::string> tokens;
    EQAPP_String_Split(commandTextAfterSpace, tokens, ';');

    if (tokens.size() == 0)
    {
        return;
    }

    uint32_t random = EQAPP_GetRandomNumber(0, tokens.size() - 1);
    if (random > tokens.size())
    {
        return;
    }

    std::string number = tokens.at(random);
    if (number.size() == 0)
    {
        return;
    }

    ////std::cout << "Random Number: " << number << std::endl;

    std::stringstream ss;
    ss << prependText << number;

    EQ_InterpretCommand(ss.str().c_str());
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

    if (commandText == "//Disband")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_DISBAND, 1);

        return true;
    }

    if (commandText == "//ShrinkTarget")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_SetSpawnHeight(targetSpawn, 1.0f);
        }

        return true;
    }

    if (commandText == "//GrowTarget")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_SetSpawnHeight(targetSpawn, 10.0f);
        }

        return true;
    }

    if (commandText == "//FaceTarget")
    {
        EQ_TurnPlayerTowardsTarget();

        return true;
    }

    if (commandText == "//TargetMe")
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

    if (commandText == "//CloseTopWindows")
    {
        for (unsigned int i = 0; i < 100; i++)
        {
            EQ_ExecuteCommand(EQ_EXECUTECMD_CLOSE_TOP_WINDOW, 1);
        }

        return true;
    }

    if (commandText == "//Hail")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HAIL, 1);

        return true;
    }

    if (commandText == "//Use")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_USE, 1);

        return true;
    }

    if (commandText == "//Jump")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_JUMP, 1);

        return true;
    }

    if (commandText == "//ConfirmNo")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CONFIRM_NO, 1);

        return true;
    }

    if (commandText == "//ConfirmYes")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CONFIRM_YES, 1);

        return true;
    }

    if (commandText == "//PitchDown")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHDOWN, 1);

        return true;
    }

    if (commandText == "//PitchUp")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHUP, 1);

        return true;
    }

    if (commandText == "//CenterView")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);

        return true;
    }

    if (commandText == "//FirstPersonCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);

        return true;
    }

    if (commandText == "//OpenBags")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_OPEN_INV_BAGS, 1);

        return true;
    }

    if (commandText == "//CloseBags")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLOSE_INV_BAGS, 1);

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

    if (commandText == "//Potion1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_POTION_SLOT_1, 1);

        return true;
    }

    if (commandText == "//Potion2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_POTION_SLOT_2, 1);

        return true;
    }

    if (commandText == "//Potion3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_POTION_SLOT_3, 1);

        return true;
    }

    if (commandText == "//Potion4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_POTION_SLOT_4, 1);

        return true;
    }

    if (commandText == "//Potion5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_POTION_SLOT_5, 1);

        return true;
    }

    if (commandText == "//ESPFindName")
    {
        g_ESPFindSpawnName = std::string();

        std::cout << "ESP Find Spawn Name reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//ESPFindName ") == true)
    {
        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            g_ESPFindSpawnName = name;

            std::cout << "ESP Find Spawn Name: " << name << std::endl;
        }

        return true;
    }

    if (commandText == "//ESPFindLastName")
    {
        g_ESPFindSpawnLastName = std::string();

        std::cout << "ESP Find Spawn Last Name reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//ESPFindLastName ") == true)
    {
        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            g_ESPFindSpawnLastName = name;

            std::cout << "ESP Find Spawn Last Name: " << name << std::endl;
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Multi ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//MultiRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretRandomArgument(commandText, "");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//CastRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretRandomArgument(commandText, "/cast ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DoAbility ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DoAbilityRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretRandomArgument(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Discipline ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DisciplineRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretRandomArgument(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//AltActivate ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//AltActivateRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretRandomArgument(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BoxChatConnect ") == true || EQAPP_String_StartsWith(commandText, "//BCC ") == true)
    {
        g_BoxChatAutoConnect = false;

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

        g_BoxChatAutoConnect = true;

        return true;
    }

    if (commandText == "//BoxChatConnect" || commandText == "//BCC")
    {
        g_BoxChatAutoConnect = false;

        std::string playerSpawnName = EQ_GetPlayerSpawnName();
        if (playerSpawnName.size() != 0)
        {
            if (EQAPP_BoxChat_Connect(playerSpawnName) == false)
            {
                std::cout << "Box Chat failed to connect!" << std::endl;
            }

            EQAPP_SetWindowTitleToPlayerSpawnName();
        }

        g_BoxChatAutoConnect = true;

        return true;
    }

    if (commandText == "//BoxChatDisconnect" || commandText == "//BCD")
    {
        EQAPP_BoxChat_Disconnect();

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BoxChatTell ") == true || EQAPP_String_StartsWith(commandText, "//BCT ") == true)
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

    if (EQAPP_String_StartsWith(commandText, "//BoxChatOthers ") == true || EQAPP_String_StartsWith(commandText, "//BCA ") == true)
    {
        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to Others: " << commandText << std::endl;

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BoxChatAll ") == true || EQAPP_String_StartsWith(commandText, "//BCAA ") == true)
    {
        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to All: " << commandText << std::endl;

        return true;
    }

    return false;
}
