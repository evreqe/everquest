#pragma once

bool g_InterpretCmdIsEnabled = true;

void EQAPP_InterpretCmd_NULL();

void EQAPP_InterpretCmd_NULL()
{
    return;
}

std::map<std::string, std::function<void()>> g_InterpretCmdList =
{
    {"//Unload",                       &EQAPP_Unload},
    {"//Sleep",                        &EQAPP_Sleep_Toggle},
    {"//AlwaysAttack",                 &EQAPP_AlwaysAttack_Toggle},
    {"//AA",                           &EQAPP_AlwaysAttack_Toggle},
    {"//AlwaysHotButton",              &EQAPP_AlwaysHotButton_Toggle},
    {"//AHB",                          &EQAPP_AlwaysHotButton_Toggle},
    {"//CombatHotButton",              &EQAPP_CombatHotButton_Toggle},
    {"//CHB",                          &EQAPP_CombatHotButton_Toggle},
    {"//AutoAlternateAbility",         &EQAPP_AutoAlternateAbility_Toggle},
    {"//AAA",                          &EQAPP_AutoAlternateAbility_Toggle},
    {"//CombatAlternateAbility",       &EQAPP_CombatAlternateAbility_Toggle},
    {"//CAA",                          &EQAPP_CombatAlternateAbility_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
    {"//ESPShowSpawnID",               &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    {"//CH",                           &EQAPP_ChangeHeight_Toggle},
    {"//LoadSpellList",                &EQAPP_SpellList_Load},
    {"//SpawnCastSpell",               &EQAPP_SpawnCastSpell_Toggle},
    {"//SCS",                          &EQAPP_SpawnCastSpell_Toggle},
    {"//HUD",                          &EQAPP_HUD_Toggle},
    {"//LoadBazaarFilter",             &EQAPP_BazaarFilter_Load},
    {"//BazaarFilter",                 &EQAPP_BazaarFilter_Toggle},
    {"//BF",                           &EQAPP_BazaarFilter_Toggle},
    {"//BazaarFilterDoQuery",          &EQAPP_BazaarFilter_DoQuery_Toggle},
    {"//BFDQ",                         &EQAPP_BazaarFilter_DoQuery_Toggle},
    {"//FollowAI",                     &EQAPP_FollowAI_Toggle},
    ////{"//Null",                         &EQAPP_InterpretCmd_NULL},
    {"//Test",                         &EQAPP_InterpretCmd_NULL},
    {"//Screenshot",                   &EQAPP_InterpretCmd_NULL},
    {"//Origin",                       &EQAPP_InterpretCmd_NULL},
    {"//Gate",                         &EQAPP_InterpretCmd_NULL},
    {"//ThroneOfHeroes",               &EQAPP_InterpretCmd_NULL},
    {"//GuildLobby",                   &EQAPP_InterpretCmd_NULL},
    {"//HarmonicDissonance",           &EQAPP_InterpretCmd_NULL},
    {"//TheaterOfBlood",               &EQAPP_InterpretCmd_NULL},
    {"//BindAffinity",                 &EQAPP_InterpretCmd_NULL},
    {"//Identify",                     &EQAPP_InterpretCmd_NULL},
    {"//LessonOfTheDevoted",           &EQAPP_InterpretCmd_NULL},
    {"//ExpedientRecovery",            &EQAPP_InterpretCmd_NULL},
    {"//SteadfastServant",             &EQAPP_InterpretCmd_NULL},
    {"//WindowTitle",                  &EQAPP_InterpretCmd_NULL},
    {"//AcceptInvite",                 &EQAPP_InterpretCmd_NULL},
    {"//JoinGroup",                    &EQAPP_InterpretCmd_NULL},
    {"//Disband",                      &EQAPP_InterpretCmd_NULL},
    {"//FieldOfView",                  &EQAPP_InterpretCmd_NULL},
    {"//FOV",                          &EQAPP_InterpretCmd_NULL},
    {"//ShrinkTarget",                 &EQAPP_InterpretCmd_NULL},
    {"//GrowTarget",                   &EQAPP_InterpretCmd_NULL},
    {"//ChangeTargetHeight",           &EQAPP_InterpretCmd_NULL},
    {"//FaceTarget",                   &EQAPP_InterpretCmd_NULL},
    {"//TargetMe",                     &EQAPP_InterpretCmd_NULL},
    {"//TargetMyself",                 &EQAPP_InterpretCmd_NULL},
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
    {"//Camp",                         &EQAPP_InterpretCmd_NULL},
    {"//Use",                          &EQAPP_InterpretCmd_NULL},
    {"//Jump",                         &EQAPP_InterpretCmd_NULL},
    {"//Duck",                         &EQAPP_InterpretCmd_NULL},
    {"//SitStand",                     &EQAPP_InterpretCmd_NULL},
    {"//RunWalk",                      &EQAPP_InterpretCmd_NULL},
    {"//ConfirmNo",                    &EQAPP_InterpretCmd_NULL},
    {"//ConfirmYes",                   &EQAPP_InterpretCmd_NULL},
    {"//PitchDown",                    &EQAPP_InterpretCmd_NULL},
    {"//LookDown",                     &EQAPP_InterpretCmd_NULL},
    {"//PitchUp",                      &EQAPP_InterpretCmd_NULL},
    {"//LookUp",                       &EQAPP_InterpretCmd_NULL},
    {"//CenterView",                   &EQAPP_InterpretCmd_NULL},
    {"//LookForward",                  &EQAPP_InterpretCmd_NULL},
    {"//FirstPersonCamera",            &EQAPP_InterpretCmd_NULL},
    {"//OverheadCamera",               &EQAPP_InterpretCmd_NULL},
    {"//ChaseCamera",                  &EQAPP_InterpretCmd_NULL},
    {"//User1Camera",                  &EQAPP_InterpretCmd_NULL},
    {"//ThirdPersonCamera1",           &EQAPP_InterpretCmd_NULL},
    {"//User2Camera",                  &EQAPP_InterpretCmd_NULL},
    {"//ThirdPersonCamera2",           &EQAPP_InterpretCmd_NULL},
    {"//ThirdPersonCamera",            &EQAPP_InterpretCmd_NULL},
    {"//TetherCamera",                 &EQAPP_InterpretCmd_NULL},
    {"//OpenBags",                     &EQAPP_InterpretCmd_NULL},
    {"//CloseBags",                    &EQAPP_InterpretCmd_NULL},
    {"//HotButton1",                   &EQAPP_InterpretCmd_NULL},
    {"//HotButton1_1",                 &EQAPP_InterpretCmd_NULL},
    {"//XTargetCycle",                 &EQAPP_InterpretCmd_NULL},
    {"//XTarget1",                     &EQAPP_InterpretCmd_NULL},
    {"//Potion1",                      &EQAPP_InterpretCmd_NULL},
    {"//ESPFindName",                  &EQAPP_InterpretCmd_NULL},
    {"//ESPFindLastName",              &EQAPP_InterpretCmd_NULL},
    {"//Multiline",                    &EQAPP_InterpretCmd_NULL},
    {"//MultilineRandom",              &EQAPP_InterpretCmd_NULL},
    {"//CastRandom",                   &EQAPP_InterpretCmd_NULL},
    {"//DoAbility",                    &EQAPP_InterpretCmd_NULL},
    {"//DoAbilityRandom",              &EQAPP_InterpretCmd_NULL},
    {"//Discipline",                   &EQAPP_InterpretCmd_NULL},
    {"//DisciplineRandom",             &EQAPP_InterpretCmd_NULL},
    {"//AltActivate",                  &EQAPP_InterpretCmd_NULL},
    {"//AltActivateRandom",            &EQAPP_InterpretCmd_NULL},
    {"//BoxChatConnect",               &EQAPP_InterpretCmd_NULL},
    {"//BCC",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatDisconnect",            &EQAPP_InterpretCmd_NULL},
    {"//BCD",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatTell",                  &EQAPP_InterpretCmd_NULL},
    {"//BCT",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatOthers",                &EQAPP_InterpretCmd_NULL},
    {"//BCA",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatAll",                   &EQAPP_InterpretCmd_NULL},
    {"//BCAA",                         &EQAPP_InterpretCmd_NULL},
};

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_);
bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText);
void EQAPP_InterpretCmd_InterpretArguments(const std::string& commandText, const std::string& prependText);
void EQAPP_InterpretCmd_InterpretArgumentsRandom(const std::string& commandText, const std::string& prependText);
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
            auto spawnID = EQ_GetSpawnID(playerSpawn);

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
            auto spawnID = EQ_GetSpawnID(targetSpawn);

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

    if (EQAPP_String_Contains(commandTextAfterSpace, ",") == false)
    {
        return;
    }

    std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');

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

void EQAPP_InterpretCmd_InterpretArgumentsRandom(const std::string& commandText, const std::string& prependText)
{
    std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
    if (commandTextAfterSpace.size() == 0)
    {
        return;
    }

    if (EQAPP_String_Contains(commandTextAfterSpace, ",") == false)
    {
        return;
    }

    std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');

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

        EQ_InterpretCommand("/say hail");

        return true;
    }

    if (commandText == "//Screenshot")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_SCREENCAP, 1);

        return true;
    }

    if (commandText == "//Origin")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::General::Origin;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//Gate")
    {
        // TODO: per class

        //std::stringstream ss;
        //ss << "/alt activate " << EQAlternateAbilities::;

        //EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//MassGroupBuff")
    {
        // TODO: per class

        //std::stringstream ss;
        //ss << "/alt activate " << EQAlternateAbilities::;

        //EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//ThroneOfHeroes" || commandText == "//GuildLobby")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Throne_of_Heroes;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//HarmonicDissonance" || commandText == "//TheaterOfBlood")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Harmonic_Dissonance;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//BindAffinity")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Shared::BindAffinity;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//Identify")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::General::Identify;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//LessonOfTheDevoted")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Lesson_of_the_Devoted;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//ExpendientRecovery")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Expedient_Recovery;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SteadfastServant")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Steadfast_Servant;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//WindowTitle")
    {
        EQAPP_SetWindowTitleToPlayerSpawnName();

        return true;
    }

    if (commandText == "//AcceptInvite" || commandText == "//JoinGroup")
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

    if (EQAPP_String_StartsWith(commandText, "//FieldOfView ") == true || EQAPP_String_StartsWith(commandText, "//FOV ") == true)
    {
        std::string fieldOfViewStr = EQAPP_String_GetAfter(commandText, " ");
        if (fieldOfViewStr.size() != 0)
        {
            float fieldOfView = std::stof(fieldOfViewStr);
            if (fieldOfView > 0.0f)
            {
                EQ_SetCameraFieldOfView(fieldOfView);

                std::cout << "Field of View: " << fieldOfView << std::endl;
            }
        }

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

    if (EQAPP_String_StartsWith(commandText, "//ChangeTargetHeight ") == true)
    {
        std::string heightStr = EQAPP_String_GetAfter(commandText, " ");
        if (heightStr.size() != 0)
        {
            float height = std::stof(heightStr);
            if (height > 0.0f)
            {
                auto targetSpawn = EQ_GetTargetSpawn();
                if (targetSpawn != NULL)
                {
                    EQ_SetSpawnHeight(targetSpawn, height);

                    std::cout << "Change Target Height: " << height << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//FaceTarget")
    {
        EQ_TurnPlayerTowardsTarget();

        return true;
    }

    if (commandText == "//TargetMe" || commandText == "//TargetMyself")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETME, 1);

        return true;
    }

    if (commandText == "//TargetPC" || commandText == "//TargetPlayer")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETPC, 1);

        return true;
    }

    if (commandText == "//TargetNPC")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETNPC, 1);

        return true;
    }

    if (commandText == "//TargetCorpse")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TARGETCORPSE, 1);

        return true;
    }

    if (commandText == "//TargetPCCycle" || commandText == "//TargetPlayerCycle")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CYCLEPCTARGETS, 1);

        return true;
    }

    if (commandText == "//TargetNPCCycle")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CYCLENPCTARGETS, 1);

        return true;
    }

    if (commandText == "//TargetCorpseCycle")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CYCLECORPSETARGETS, 1);

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Target ") == true)
    {
        std::string spawnName = EQAPP_String_GetAfter(commandText, " ");
        if (spawnName.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawn = EQ_GetSpawnByName(spawnName.c_str());
                if (spawn != NULL)
                {
                    EQ_SetTargetSpawn(spawn);

                    std::cout << "Target: " << spawnName << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//TargetID ") == true)
    {
        std::string spawnIDStr = EQAPP_String_GetAfter(commandText, " ");
        if (spawnIDStr.size() != 0)
        {
            uint32_t spawnID = std::stoul(spawnIDStr);

            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawn = EQ_GetSpawnByID(spawnID);
                if (spawn != NULL)
                {
                    EQ_SetTargetSpawn(spawn);

                    std::cout << "Target by ID: " << spawnIDStr << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//Follow")
    {
        EQ_FollowTarget();

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Follow ") == true)
    {
        std::string spawnName = EQAPP_String_GetAfter(commandText, " ");
        if (spawnName.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawn = EQ_GetSpawnByName(spawnName.c_str());
                if (spawn != NULL)
                {
                    EQ_SetTargetSpawn(spawn);
                    EQ_SetSpawnFollowSpawn(playerSpawn, spawn);

                    std::cout << "Follow: " << spawnName << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//StopFollow")
    {
        EQ_StopFollow();

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

    if (commandText == "//Camp")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CAMP, 1);

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

    if (commandText == "//Duck")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_DUCK, 1);

        return true;
    }

    if (commandText == "//SitStand")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_SIT_STAND, 1);

        return true;
    }

    if (commandText == "//RunWalk")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_RUN_WALK, 1);

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

    if (commandText == "//PitchDown" || commandText == "//LookDown")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHDOWN, 1);

        return true;
    }

    if (commandText == "//PitchUp" || commandText == "//LookUp")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHUP, 1);

        return true;
    }

    if (commandText == "//CenterView" || commandText == "//LookForward")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);

        return true;
    }

    if (commandText == "//FirstPersonCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);

        return true;
    }

    if (commandText == "//OverheadCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_OVERHEAD_CAMERA, 1);

        return true;
    }

    if (commandText == "//ChaseCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CHASE_CAMERA, 1);

        return true;
    }

    if (commandText == "//User1Camera" || commandText == "//ThirdPersonCamera1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_USER1_CAMERA, 1);

        return true;
    }

    if (commandText == "//User2Camera" || commandText == "//ThirdPersonCamera2" || commandText == "//ThirdPersonCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_USER2_CAMERA, 1);

        return true;
    }

    if (commandText == "//TetherCamera")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_TETHER_CAMERA, 1);

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

    if (commandText == "//HotButton1_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_1, 1);
    }

    if (commandText == "//HotButton1_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_2, 1);
    }

    if (commandText == "//HotButton1_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_3, 1);
    }

    if (commandText == "//HotButton1_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_4, 1);
    }

    if (commandText == "//HotButton1_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_5, 1);
    }

    if (commandText == "//HotButton1_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_6, 1);
    }

    if (commandText == "//HotButton1_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_7, 1);
    }

    if (commandText == "//HotButton1_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_8, 1);
    }

    if (commandText == "//HotButton1_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_9, 1);
    }

    if (commandText == "//HotButton1_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_10, 1);
    }

    if (commandText == "//HotButton1_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_11, 1);
    }

    if (commandText == "//HotButton1_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT1_12, 1);
    }

    if (commandText == "//HotButton2_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_1, 1);
    }

    if (commandText == "//HotButton2_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_2, 1);
    }

    if (commandText == "//HotButton2_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_3, 1);
    }

    if (commandText == "//HotButton2_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_4, 1);
    }

    if (commandText == "//HotButton2_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_5, 1);
    }

    if (commandText == "//HotButton2_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_6, 1);
    }

    if (commandText == "//HotButton2_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_7, 1);
    }

    if (commandText == "//HotButton2_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_8, 1);
    }

    if (commandText == "//HotButton2_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_9, 1);
    }

    if (commandText == "//HotButton2_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_10, 1);
    }

    if (commandText == "//HotButton2_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_11, 1);
    }

    if (commandText == "//HotButton2_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT2_12, 1);
    }

    if (commandText == "//HotButton3_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_1, 1);
    }

    if (commandText == "//HotButton3_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_2, 1);
    }

    if (commandText == "//HotButton3_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_3, 1);
    }

    if (commandText == "//HotButton3_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_4, 1);
    }

    if (commandText == "//HotButton3_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_5, 1);
    }

    if (commandText == "//HotButton3_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_6, 1);
    }

    if (commandText == "//HotButton3_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_7, 1);
    }

    if (commandText == "//HotButton3_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_8, 1);
    }

    if (commandText == "//HotButton3_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_9, 1);
    }

    if (commandText == "//HotButton3_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_10, 1);
    }

    if (commandText == "//HotButton3_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_11, 1);
    }

    if (commandText == "//HotButton3_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT3_12, 1);
    }

    if (commandText == "//HotButton4_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_1, 1);
    }

    if (commandText == "//HotButton4_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_2, 1);
    }

    if (commandText == "//HotButton4_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_3, 1);
    }

    if (commandText == "//HotButton4_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_4, 1);
    }

    if (commandText == "//HotButton4_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_5, 1);
    }

    if (commandText == "//HotButton4_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_6, 1);
    }

    if (commandText == "//HotButton4_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_7, 1);
    }

    if (commandText == "//HotButton4_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_8, 1);
    }

    if (commandText == "//HotButton4_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_9, 1);
    }

    if (commandText == "//HotButton4_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_10, 1);
    }

    if (commandText == "//HotButton4_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_11, 1);
    }

    if (commandText == "//HotButton4_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT4_12, 1);
    }

    if (commandText == "//HotButton5_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_1, 1);
    }

    if (commandText == "//HotButton5_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_2, 1);
    }

    if (commandText == "//HotButton5_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_3, 1);
    }

    if (commandText == "//HotButton5_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_4, 1);
    }

    if (commandText == "//HotButton5_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_5, 1);
    }

    if (commandText == "//HotButton5_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_6, 1);
    }

    if (commandText == "//HotButton5_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_7, 1);
    }

    if (commandText == "//HotButton5_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_8, 1);
    }

    if (commandText == "//HotButton5_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_9, 1);
    }

    if (commandText == "//HotButton5_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_10, 1);
    }

    if (commandText == "//HotButton5_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_11, 1);
    }

    if (commandText == "//HotButton5_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT5_12, 1);
    }

    if (commandText == "//HotButton6_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_1, 1);
    }

    if (commandText == "//HotButton6_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_2, 1);
    }

    if (commandText == "//HotButton6_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_3, 1);
    }

    if (commandText == "//HotButton6_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_4, 1);
    }

    if (commandText == "//HotButton6_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_5, 1);
    }

    if (commandText == "//HotButton6_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_6, 1);
    }

    if (commandText == "//HotButton6_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_7, 1);
    }

    if (commandText == "//HotButton6_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_8, 1);
    }

    if (commandText == "//HotButton6_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_9, 1);
    }

    if (commandText == "//HotButton6_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_10, 1);
    }

    if (commandText == "//HotButton6_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_11, 1);
    }

    if (commandText == "//HotButton6_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT6_12, 1);
    }

    if (commandText == "//HotButton7_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_1, 1);
    }

    if (commandText == "//HotButton7_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_2, 1);
    }

    if (commandText == "//HotButton7_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_3, 1);
    }

    if (commandText == "//HotButton7_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_4, 1);
    }

    if (commandText == "//HotButton7_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_5, 1);
    }

    if (commandText == "//HotButton7_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_6, 1);
    }

    if (commandText == "//HotButton7_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_7, 1);
    }

    if (commandText == "//HotButton7_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_8, 1);
    }

    if (commandText == "//HotButton7_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_9, 1);
    }

    if (commandText == "//HotButton7_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_10, 1);
    }

    if (commandText == "//HotButton7_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_11, 1);
    }

    if (commandText == "//HotButton7_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT7_12, 1);
    }

    if (commandText == "//HotButton8_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_1, 1);
    }

    if (commandText == "//HotButton8_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_2, 1);
    }

    if (commandText == "//HotButton8_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_3, 1);
    }

    if (commandText == "//HotButton8_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_4, 1);
    }

    if (commandText == "//HotButton8_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_5, 1);
    }

    if (commandText == "//HotButton8_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_6, 1);
    }

    if (commandText == "//HotButton8_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_7, 1);
    }

    if (commandText == "//HotButton8_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_8, 1);
    }

    if (commandText == "//HotButton8_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_9, 1);
    }

    if (commandText == "//HotButton8_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_10, 1);
    }

    if (commandText == "//HotButton8_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_11, 1);
    }

    if (commandText == "//HotButton8_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT8_12, 1);
    }

    if (commandText == "//HotButton9_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_1, 1);
    }

    if (commandText == "//HotButton9_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_2, 1);
    }

    if (commandText == "//HotButton9_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_3, 1);
    }

    if (commandText == "//HotButton9_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_4, 1);
    }

    if (commandText == "//HotButton9_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_5, 1);
    }

    if (commandText == "//HotButton9_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_6, 1);
    }

    if (commandText == "//HotButton9_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_7, 1);
    }

    if (commandText == "//HotButton9_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_8, 1);
    }

    if (commandText == "//HotButton9_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_9, 1);
    }

    if (commandText == "//HotButton9_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_10, 1);
    }

    if (commandText == "//HotButton9_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_11, 1);
    }

    if (commandText == "//HotButton9_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT9_12, 1);
    }

    if (commandText == "//HotButton10_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_1, 1);
    }

    if (commandText == "//HotButton10_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_2, 1);
    }

    if (commandText == "//HotButton10_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_3, 1);
    }

    if (commandText == "//HotButton10_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_4, 1);
    }

    if (commandText == "//HotButton10_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_5, 1);
    }

    if (commandText == "//HotButton10_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_6, 1);
    }

    if (commandText == "//HotButton10_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_7, 1);
    }

    if (commandText == "//HotButton10_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_8, 1);
    }

    if (commandText == "//HotButton10_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_9, 1);
    }

    if (commandText == "//HotButton10_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_10, 1);
    }

    if (commandText == "//HotButton10_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_11, 1);
    }

    if (commandText == "//HotButton10_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT10_12, 1);
    }

    if (commandText == "//HotButton11_1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_1, 1);
    }

    if (commandText == "//HotButton11_2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_2, 1);
    }

    if (commandText == "//HotButton11_3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_3, 1);
    }

    if (commandText == "//HotButton11_4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_4, 1);
    }

    if (commandText == "//HotButton11_5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_5, 1);
    }

    if (commandText == "//HotButton11_6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_6, 1);
    }

    if (commandText == "//HotButton11_7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_7, 1);
    }

    if (commandText == "//HotButton11_8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_8, 1);
    }

    if (commandText == "//HotButton11_9")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_9, 1);
    }

    if (commandText == "//HotButton11_10")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_10, 1);
    }

    if (commandText == "//HotButton11_11")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_11, 1);
    }

    if (commandText == "//HotButton11_12")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_HOT11_12, 1);
    }

    if (commandText == "//XTargetCycle")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CYCLE_XTARGET, 1);

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

/*
    // potion belt was removed and replaced with hotbar 11

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
*/

    if (EQAPP_String_StartsWith(commandText, "//CombatHotButton ") == true || EQAPP_String_StartsWith(commandText, "//CHB ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            signed int number = std::stoi(numberStr);

            if (number > 0 && number < (EQ_NUM_HOT_BUTTONS + 1))
            {
                g_CombatHotButtonIndex = number - 1;

                std::cout << "Combat HotButton: " << number << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//AlwaysHotButton ") == true || EQAPP_String_StartsWith(commandText, "//AHB ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            signed int number = std::stoi(numberStr);

            if (number > 0 && number < (EQ_NUM_HOT_BUTTONS + 1))
            {
                g_AlwaysHotButtonIndex = number - 1;

                std::cout << "Always HotButton: " << number << std::endl;
            }
        }

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

    if (commandText == "//GetNearbyNPCs")
    {
        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance();

        std::cout << "Nearby NPCs:" << std::endl;

        uint32_t spawnIndex = 0;

        for (auto& spawnID : spawnIDList)
        {
            if (spawnIndex > 10)
            {
                break;
            }

            auto spawn = EQ_GetSpawnByID(spawnID);
            if (spawn == NULL)
            {
                spawnIndex++;
                continue;
            }

            std::string spawnName = EQ_GetSpawnName(spawn);
            if (spawnName.size() == 0)
            {
                spawnIndex++;
                continue;
            }

            std::cout << spawnIndex + 1 << ": " << spawnName << " (ID: " << spawnID << ")" << std::endl;

            spawnIndex++;
        }

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Multiline ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//MultilineRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//CastRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/cast ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DoAbility ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DoAbilityRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//Discipline ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//DisciplineRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//AltActivate ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//AltActivateRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_StartsWith(commandText, "//BoxChatConnect ") == true || EQAPP_String_StartsWith(commandText, "//BCC ") == true)
    {
        g_BoxChatAutoConnect = false; // prevent crash when the auto connect thread calls EQAPP_BoxChat_Connect()

        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            std::cout << "Box Chat Connect as Name: " << name << std::endl;

            if (EQAPP_BoxChat_Connect(name) == false)
            {
                std::cout << "Box Chat failed to connect!" << std::endl;
            }
        }

        g_BoxChatAutoConnect = true; // prevent crash when the auto connect thread calls EQAPP_BoxChat_Connect()

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

    if (g_BoxChatIsConnected == false)
    {
        std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
    }
    else
    {
        if (EQAPP_String_StartsWith(commandText, "//BoxChatTell ") == true || EQAPP_String_StartsWith(commandText, "//BCT ") == true)
        {
            std::string name = EQAPP_String_GetAfter(commandText, " ");
            if (name.size() != 0)
            {
                EQAPP_BoxChat_SendText(commandText);

                std::cout << "Box Chat to '" << name << "': " << commandText << std::endl;
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
    }

    return false;
}
