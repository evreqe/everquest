#pragma once

#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_followai.h"
#include "eqapp_hud.h"
#include "eqapp_nodraw.h"
#include "eqapp_sleep.h"
#include "eqapp_windowtitle.h"

bool g_InterpretCommandIsEnabled = true;

void EQAPP_InterpretCommand_NULL();

void EQAPP_InterpretCommand_NULL()
{
    return;
}

std::map<std::string, std::function<void()>> g_InterpretCommandList =
{
    {"//Unload",                       &EQAPP_Unload},
    {"//DebugText",                    &EQAPP_DebugText_Toggle},
    {"//DebugTextOn",                  &EQAPP_DebugText_On},
    {"//DebugTextOff",                 &EQAPP_DebugText_Off},
    {"//Sleep",                        &EQAPP_Sleep_Toggle},
    {"//SleepOn",                      &EQAPP_Sleep_On},
    {"//SleepOff",                     &EQAPP_Sleep_Off},
    {"//ActorCollision",               &EQAPP_ActorCollision_Toggle},
    {"//ActorCollisionOn",             &EQAPP_ActorCollision_On},
    {"//ActorCollisionOff",            &EQAPP_ActorCollision_Off},
    {"//ActorCollisionLoad",           &EQAPP_ActorCollision_Load},
    {"//ActorCollisionList",           &EQAPP_ActorCollision_PrintActorDefinitionList},
    {"//ActorCollisionDebugList",      &EQAPP_ActorCollision_PrintActorDefinitionDebugList},
    {"//ActorCollisionDebug",          &EQAPP_ActorCollision_Debug_Toggle},
    {"//ActorCollisionAll",            &EQAPP_ActorCollision_All_Toggle},
    {"//ActorCollisionPlayer",         &EQAPP_ActorCollision_Player_Toggle},
    {"//AC",                           &EQAPP_ActorCollision_Toggle},
    {"//ACOn",                         &EQAPP_ActorCollision_On},
    {"//ACOff",                        &EQAPP_ActorCollision_Off},
    {"//ACLoad",                       &EQAPP_ActorCollision_Load},
    {"//ACList",                       &EQAPP_ActorCollision_PrintActorDefinitionList},
    {"//ACDebugList",                  &EQAPP_ActorCollision_PrintActorDefinitionDebugList},
    {"//ACDebug",                      &EQAPP_ActorCollision_Debug_Toggle},
    {"//ACAll",                        &EQAPP_ActorCollision_All_Toggle},
    {"//ACPlayer",                     &EQAPP_ActorCollision_Player_Toggle},
    {"//AlwaysAttack",                 &EQAPP_AlwaysAttack_Toggle},
    {"//AlwaysAttackOn",               &EQAPP_AlwaysAttack_On},
    {"//AlwaysAttackOff",              &EQAPP_AlwaysAttack_Off},
    {"//AA",                           &EQAPP_AlwaysAttack_Toggle},
    {"//AAOn",                         &EQAPP_AlwaysAttack_On},
    {"//AAOff",                        &EQAPP_AlwaysAttack_Off},
    {"//AlwaysHotButton",              &EQAPP_AlwaysHotButton_Toggle},
    {"//AlwaysHotButtonOn",            &EQAPP_AlwaysHotButton_On},
    {"//AlwaysHotButtonOff",           &EQAPP_AlwaysHotButton_Off},
    {"//AHB",                          &EQAPP_AlwaysHotButton_Toggle},
    {"//AHBOn",                        &EQAPP_AlwaysHotButton_On},
    {"//AHBOff",                       &EQAPP_AlwaysHotButton_Off},
    {"//CombatHotButton",              &EQAPP_CombatHotButton_Toggle},
    {"//CombatHotButtonOn",            &EQAPP_CombatHotButton_On},
    {"//CombatHotButtonOff",           &EQAPP_CombatHotButton_Off},
    {"//CHB",                          &EQAPP_CombatHotButton_Toggle},
    {"//CHBOn",                        &EQAPP_CombatHotButton_On},
    {"//CHBOff",                       &EQAPP_CombatHotButton_Off},
    {"//AutoGroup",                    &EQAPP_AutoGroup_Toggle},
    {"//AutoGroupOn",                  &EQAPP_AutoGroup_On},
    {"//AutoGroupOff",                 &EQAPP_AutoGroup_Off},
    {"//AG",                           &EQAPP_AutoGroup_Toggle},
    {"//AGOn",                         &EQAPP_AutoGroup_On},
    {"//AGOff",                        &EQAPP_AutoGroup_Off},
    {"//BoxChat",                      &EQAPP_BoxChat_Toggle},
    {"//BoxChatOn",                    &EQAPP_BoxChat_On},
    {"//BoxChatOff",                   &EQAPP_BoxChat_Off},
    {"//BoxChatAutoConnect",           &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//BoxChatAutoConnectOn",         &EQAPP_BoxChat_AutoConnect_On},
    {"//BoxChatAutoConnectOff",        &EQAPP_BoxChat_AutoConnect_Off},
    {"//BC",                           &EQAPP_BoxChat_Toggle},
    {"//BCOn",                         &EQAPP_BoxChat_On},
    {"//BCOff",                        &EQAPP_BoxChat_Off},
    {"//BCAC",                         &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//ConsolePrint",                 &EQAPP_Console_Print_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
    {"//ESPOn",                        &EQAPP_ESP_On},
    {"//ESPOff",                       &EQAPP_ESP_Off},
    {"//ESPHeightFilter",              &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPFindLine",                  &EQAPP_ESP_FindLine_Toggle},
    {"//ESPShowSpawns",                &EQAPP_ESP_ShowSpawns_Toggle},
    {"//ESPHF",                        &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPFL",                        &EQAPP_ESP_FindLine_Toggle},
    {"//ESPSpawns",                    &EQAPP_ESP_ShowSpawns_Toggle},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    {"//ChangeHeightOn",               &EQAPP_ChangeHeight_On},
    {"//ChangeHeightOff",              &EQAPP_ChangeHeight_Off},
    {"//CH",                           &EQAPP_ChangeHeight_Toggle},
    {"//CHOn",                         &EQAPP_ChangeHeight_On},
    {"//CHOff",                        &EQAPP_ChangeHeight_Off},
    {"//ChatEvent",                    &EQAPP_ChatEvent_Toggle},
    {"//ChatEventOn",                  &EQAPP_ChatEvent_On},
    {"//ChatEventOff",                 &EQAPP_ChatEvent_Off},
    {"//ChatEventLoad",                &EQAPP_ChatEvent_Load},
    {"//ChatEventClear",               &EQAPP_ChatEvent_ClearList},
    {"//ChatEventList",                &EQAPP_ChatEvent_PrintList},
    {"//CE",                           &EQAPP_ChatEvent_Toggle},
    {"//CEOn",                         &EQAPP_ChatEvent_On},
    {"//CEOff",                        &EQAPP_ChatEvent_Off},
    {"//CELoad",                       &EQAPP_ChatEvent_Load},
    {"//CEClear",                      &EQAPP_ChatEvent_ClearList},
    {"//CEList",                       &EQAPP_ChatEvent_PrintList},
    {"//HUD",                          &EQAPP_HUD_Toggle},
    {"//HUDOn",                        &EQAPP_HUD_On},
    {"//HUDOff",                       &EQAPP_HUD_Off},
    {"//FollowAI",                     &EQAPP_FollowAI_Toggle},
    {"//FollowAIOn",                   &EQAPP_FollowAI_On},
    {"//FollowAIOff",                  &EQAPP_FollowAI_Off},
    {"//FollowAIUseZAxis",             &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FollowAIUseZAxisOn",           &EQAPP_FollowAI_UseZAxis_On},
    {"//FollowAIUseZAxisOff",          &EQAPP_FollowAI_UseZAxis_Off},
    {"//FollowAIBehind",               &EQAPP_FollowAI_Behind_Toggle},
    {"//FollowAIBehindOn",             &EQAPP_FollowAI_Behind_On},
    {"//FollowAIBehindOff",            &EQAPP_FollowAI_Behind_Off},
    {"//FollowOn",                     &EQAPP_FollowAI_On},
    {"//FollowOff",                    &EQAPP_FollowAI_Off},
    {"//FollowZ",                      &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FollowZOn",                    &EQAPP_FollowAI_UseZAxis_On},
    {"//FollowZOff",                   &EQAPP_FollowAI_UseZAxis_Off},
    {"//FZ",                           &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FZOn",                         &EQAPP_FollowAI_UseZAxis_On},
    {"//FZOff",                        &EQAPP_FollowAI_UseZAxis_Off},
    {"//FollowBehind",                 &EQAPP_FollowAI_Behind_Toggle},
    {"//FollowBehindOn",               &EQAPP_FollowAI_Behind_On},
    {"//FollowBehindOff",              &EQAPP_FollowAI_Behind_Off},
    {"//FB",                           &EQAPP_FollowAI_Behind_Toggle},
    {"//FBOn",                         &EQAPP_FollowAI_Behind_On},
    {"//FBOff",                        &EQAPP_FollowAI_Behind_Off},
    {"//WindowTitle",                  &EQAPP_WindowTitle_Toggle},
    {"//WindowTitleOn",                &EQAPP_WindowTitle_On},
    {"//WindowTitleOff",               &EQAPP_WindowTitle_Off},
    {"//WT",                           &EQAPP_WindowTitle_Toggle},
    {"//WTOn",                         &EQAPP_WindowTitle_On},
    {"//WTOff",                        &EQAPP_WindowTitle_Off},
    {"//FreeCamera",                   &EQAPP_FreeCamera_Toggle},
    {"//FreeCameraOn",                 &EQAPP_FreeCamera_On},
    {"//FreeCameraOff",                &EQAPP_FreeCamera_Off},
    {"//FC",                           &EQAPP_FreeCamera_Toggle},
    {"//FCOn",                         &EQAPP_FreeCamera_On},
    {"//FCOff",                        &EQAPP_FreeCamera_Off},
    {"//NoDraw",                       &EQAPP_NoDraw_Toggle},
    {"//NoDrawOn",                     &EQAPP_NoDraw_On},
    {"//NoDrawOff",                    &EQAPP_NoDraw_Off},
    {"//ND",                           &EQAPP_NoDraw_Toggle},
    {"//NDOn",                         &EQAPP_NoDraw_On},
    {"//NDOff",                        &EQAPP_NoDraw_Off},
};

void EQAPP_InterpretCommand_PrintList();
void EQAPP_InterpretCommand_ConvertText(std::string& text);
bool EQAPP_InterpretCommand_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_);
void EQAPP_InterpretCommand_InterpretArguments(const std::string& commandText, const std::string& prependText);
void EQAPP_InterpretCommand_InterpretArgumentsRandom(const std::string& commandText, const std::string& prependText);
bool EQAPP_InterpretCommand_HandleCommandText(std::string commandText);
void EQAPP_InterpretCommand_Execute(const std::string& commandText);

void EQAPP_InterpretCommand_PrintList()
{
    std::cout << "Command List: " << std::endl;

    for (auto& cmd : g_InterpretCommandList)
    {
        std::cout << cmd.first << std::endl;
    }
}

void EQAPP_InterpretCommand_ConvertText(std::string& text)
{
    if (text.find("${Player.ID}") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnID = EQ_GetSpawnID(playerSpawn);

            std::string str = std::to_string(spawnID);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "${Player.ID}", str);
            }
        }
    }

    if (text.find("${Player.Name}") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            std::string str = EQ_GetSpawnName(playerSpawn);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "${Player.Name}", str);
            }
        }
    }

    if (text.find("${Target.ID}") != std::string::npos)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            auto spawnID = EQ_GetSpawnID(targetSpawn);

            std::string str = std::to_string(spawnID);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "${Target.ID}", str);
            }
        }
    }

    if (text.find("${Target.Name}") != std::string::npos)
    {
        auto targetpawn = EQ_GetTargetSpawn();
        if (targetpawn != NULL)
        {
            std::string str = EQ_GetSpawnName(targetpawn);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "${Target.Name}", str);
            }
        }
    }
}

bool EQAPP_InterpretCommand_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_)
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

    if (commandText.at(0) == '\\')
    {
        return true;
    }

    EQAPP_InterpretCommand_ConvertText(commandText);

    // remove comments from command text
    std::string::size_type findComment1 = commandText.find(" #");
    if (findComment1 != std::string::npos)
    {
        commandText = commandText.substr(0, findComment1);
    }
    else
    {
        std::string::size_type findComment2 = commandText.find("#");
        if (findComment2 != std::string::npos)
        {
            commandText = commandText.substr(0, findComment2);
        }
    }

    std::string firstTwoCharacters = commandText.substr(0, 2);
    if (firstTwoCharacters == "//")
    {
        EQAPP_InterpretCommand_Execute(commandText);
        return true;
    }

    return false;
}

void EQAPP_InterpretCommand_InterpretArguments(const std::string& commandText, const std::string& prependText)
{
    std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
    if (commandTextAfterSpace.size() == 0)
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

void EQAPP_InterpretCommand_InterpretArgumentsRandom(const std::string& commandText, const std::string& prependText)
{
    std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
    if (commandTextAfterSpace.size() == 0)
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

    ////std::cout << "random number: " << number << std::endl;

    std::stringstream ss;
    ss << prependText << number;

    EQ_InterpretCommand(ss.str().c_str());
}

void EQAPP_InterpretCommand_Execute(const std::string& commandText)
{
    if (commandText.size() == 0)
    {
        return;
    }

    std::stringstream ss;
    ss << "commandText=" << commandText;

    EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());

    // handle special commands that are not in the command list
    bool result = EQAPP_InterpretCommand_HandleCommandText(commandText);
    if (result == true)
    {
        return;
    }

    // handle interpret command list functions
    auto cmd = g_InterpretCommandList.find(commandText);
    if (cmd != g_InterpretCommandList.end())
    {
        cmd->second();
        return;
    }
}

bool EQAPP_InterpretCommand_HandleCommandText(std::string commandText)
{
    if (commandText == "//Help" || commandText == "//Commands")
    {
        EQAPP_InterpretCommand_PrintList();

        return true;
    }

    if (commandText == "//Test")
    {
        std::cout << "Testing123" << std::endl;

        return true;
    }

    if (commandText == "//TestChatTextColors")
    {
        for (unsigned int i = 0; i < 25; i++)
        {
            std::stringstream ss;
            ss << i << " ^ Test123";

            EQ_PrintTextToChatByColor(ss.str().c_str(), i);
        }

        return true;
    }

    if (commandText == "//InGame")
    {
        g_EQAppIsInGame = true;

        return true;
    }

    if (commandText == "//NotInGame")
    {
        g_EQAppIsInGame = false;

        return true;
    }

    if (commandText == "//Beep")
    {
        EQAPP_Beep();

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BeepEx ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t beepType = std::stoul(commandTextAfterSpace);

                EQAPP_BeepEx(beepType);
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//PlaySound ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_EndsWith(commandTextAfterSpace, ".mp3") == false)
            {
                std::stringstream fileName;
                fileName << commandTextAfterSpace;

                if (EQAPP_String_EndsWith(commandTextAfterSpace, ".wav") == false)
                {
                    fileName << ".wav";
                }

                EQ_PlaySound(fileName.str().c_str());
            }
            else
            {
                std::cout << "MP3 files are not supported." << std::endl;
            }
        }

        return true;
    }

    if (commandText == "//StopSound")
    {
        EQ_StopSound();

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//PlaySoundEx ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_EndsWith(commandTextAfterSpace, ".mp3") == false)
            {
                std::stringstream fileName;
                fileName << commandTextAfterSpace;

                if (EQAPP_String_EndsWith(commandTextAfterSpace, ".wav") == false)
                {
                    fileName << ".wav";
                }

                EQAPP_PlaySound(fileName.str().c_str());
            }
            else
            {
                std::cout << "MP3 files are not supported." << std::endl;
            }
        }

        return true;
    }

    if (commandText == "//StopSoundEx")
    {
        EQAPP_StopSound();

        return true;
    }

    if (commandText == "//Screencap" || commandText == "//Screenshot")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_SCREENCAP, 1);

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//TakeScreenshot ") == true)
    {
        std::string fileName = EQAPP_String_GetAfter(commandText, " ");
        if (fileName.size() != 0)
        {
            std::stringstream ss;
            ss << "Screenshots\\" << fileName << ".jpg";

            EQ_TakeScreenshot(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//AutoAttack")
    {
        if (EQ_IsAutoAttackEnabled() == false)
        {
            EQ_SetAutoAttack(true);
        }
        else
        {
            EQ_SetAutoAttack(false);
        }

        return true;
    }

    if (commandText == "//AutoAttackOn")
    {
        EQ_SetAutoAttack(true);

        return true;
    }

    if (commandText == "//AutoAttackOff")
    {
        EQ_SetAutoAttack(false);

        return true;
    }

    if (commandText == "//AutoRun")
    {
        if (EQ_IsAutoRunEnabled() == false)
        {
            EQ_SetAutoRun(true);
        }
        else
        {
            EQ_SetAutoRun(false);
        }

        return true;
    }

    if (commandText == "//AutoRunOn")
    {
        EQ_SetAutoRun(true);

        return true;
    }

    if (commandText == "//AutoRunOff")
    {
        EQ_SetAutoRun(false);

        return true;
    }

    if (commandText == "//AcceptInvite" || commandText == "//JoinGroup")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLEAR_TARGET, 1);
        EQ_ExecuteCommand(EQ_EXECUTECMD_INVITE_FOLLOW, 1);

        return true;
    }

    if (commandText == "//Disband")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_DISBAND, 1);

        return true;
    }

    if (commandText == "//GetFieldOfView")
    {
        std::stringstream ss;
        ss << "Field of View: " << EQ_GetCameraFieldOfView();

        std::cout << ss.str() << std::endl;

        return true;
    }

    if (commandText == "//FieldOfViewDefault" || commandText == "//FOVDefault")
    {
        EQ_SetCameraFieldOfView(EQ_CAMERA_FIELD_OF_VIEW_DEFAULT);

        std::cout << "Field of View set to default." << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FieldOfView ") == true || EQAPP_String_BeginsWith(commandText, "//FOV ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                float fieldOfView = std::stof(commandTextAfterSpace);
                if (fieldOfView > 0.0f)
                {
                    EQ_SetCameraFieldOfView(fieldOfView);

                    std::cout << "Field of View: " << fieldOfView << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//GetDrawDistance")
    {
        std::stringstream ss;
        ss << "Draw Distance: " << EQ_GetCameraDrawDistance();

        std::cout << ss.str() << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DrawDistance ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                float distance = std::stof(commandTextAfterSpace);
                if (distance > 0.0f)
                {
                    EQ_SetCameraDrawDistance(distance);

                    std::cout << "Draw Distance: " << distance << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//GetFarClipPlane")
    {
        std::stringstream ss;
        ss << "Far Clip Plane: " << EQ_GetCameraFarClipPlane();

        std::cout << ss.str() << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FarClipPlane ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                float distance = std::stof(commandTextAfterSpace);
                if (distance > 0.0f)
                {
                    EQ_SetCameraFarClipPlane(distance);

                    std::cout << "Far Clip Plane: " << distance << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//ShrinkTarget")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            float targetHeight = EQ_GetSpawnHeight(targetSpawn);

            targetHeight = targetHeight - 1.0f;

            if (targetHeight < 1.0f)
            {
                targetHeight = 1.0f;
            }

            EQ_SetSpawnHeight(targetSpawn, targetHeight);
        }

        return true;
    }

    if (commandText == "//GrowTarget")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            float targetHeight = EQ_GetSpawnHeight(targetSpawn);

            targetHeight = targetHeight + 1.0f;

            if (targetHeight > 100.0f)
            {
                targetHeight = 100.0f;
            }

            EQ_SetSpawnHeight(targetSpawn, targetHeight);
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ChangeTargetHeight ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            float height = std::stof(commandTextAfterSpace);
            if (height > 0.0f)
            {
                auto targetSpawn = EQ_GetTargetSpawn();
                if (targetSpawn != NULL)
                {
                    EQ_SetSpawnHeight(targetSpawn, height);
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Face ") == true)
    {
        std::string spawnName = EQAPP_String_GetAfter(commandText, " ");
        if (spawnName.size() != 0)
        {
            auto spawn = EQ_GetSpawnByName(spawnName.c_str());
            if (spawn != NULL)
            {
                EQ_TurnPlayerTowardsSpawn(spawn);
            }
        }

        return true;
    }

    if (commandText == "//FaceTargetHeading")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            float targetSpawnHeading = EQ_GetSpawnHeading(targetSpawn);

            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                EQ_SetSpawnHeading(playerSpawn, targetSpawnHeading);
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

    if (EQAPP_String_BeginsWith(commandText, "//Target ") == true)
    {
        std::string spawnName = EQAPP_String_GetAfter(commandText, " ");
        if (spawnName.size() != 0)
        {
            EQ_SetTargetSpawnByName(spawnName.c_str());
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//TargetID ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t spawnID = std::stoul(commandTextAfterSpace);

                EQ_SetTargetSpawnByID(spawnID);
            }
        }

        return true;
    }

    if (commandText == "//Follow")
    {
        ////EQ_FollowTarget();

        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_StopFollow();

            g_FollowAISpawn = targetSpawn;
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Follow ") == true)
    {
        std::string spawnName = EQAPP_String_GetAfter(commandText, " ");
        if (spawnName.size() != 0)
        {
            auto spawn = EQ_GetSpawnByName(spawnName.c_str());
            if (spawn != NULL)
            {
                ////EQ_FollowSpawnByName(spawnName.c_str());

                EQ_StopFollow();

                EQ_SetTargetSpawn(spawn);

                g_FollowAISpawn = spawn;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FollowID ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t spawnID = std::stoul(commandTextAfterSpace);

                ////EQ_FollowSpawnByID(spawnID);

                auto spawn = EQ_GetSpawnByID(spawnID);
                if (spawn != NULL)
                {
                    EQ_StopFollow();

                    EQ_SetTargetSpawn(spawn);

                    g_FollowAISpawn = spawn;
                }
            }
        }

        return true;
    }

    if (commandText == "//StopFollow")
    {
        EQ_StopFollow();

        g_FollowAISpawn = NULL;

        return true;
    }

    if (commandText == "//StopCast")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_STOP_CAST, 1);

        return true;
    }

    if (commandText == "//StopSong")
    {
        EQ_InterpretCommand("/stopsong");
        EQ_InterpretCommand("/melody");

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

        EQ_ClearTarget();

        return true;
    }

    if (commandText == "//CloseTopWindow")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLOSE_TOP_WINDOW, 1);

        return true;
    }

    if (commandText == "//CloseAllTopWindows")
    {
        for (unsigned int i = 0; i < 10; i++)
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

    if (commandText == "//Duck" || commandText == "//Crouch")
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

    if (commandText == "//LookAtTarget")
    {
        if (g_FreeCameraIsEnabled == true)
        {
            EQ_LookCameraAtTarget();
        }
        else
        {
            EQ_LookPlayerAtTarget();
        }

        return true;
    }

    if (commandText == "//LookAtTargetFromAbove")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            auto targetY = EQ_GetSpawnY(targetSpawn);
            auto targetX = EQ_GetSpawnX(targetSpawn);

            auto targetZ = EQ_GetSpawnFloorZ(targetSpawn) + (EQ_GetSpawnHeightZ(targetSpawn) * 4.0f) + 1.0f;

            EQAPP_FreeCamera_On();

            EQ_SetCameraLocation(targetY, targetX, targetZ);

            EQ_LookCameraAtTarget();
        }

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

    if (commandText == "//Consider")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CONSIDER, 1);

        return true;
    }

    if (commandText == "//InspectBuffs")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_INSPECT_BUFFS, 1);

        return true;
    }

    if (commandText == "//Party1" || commandText == "//Group1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PARTY1, 1);

        return true;
    }

    if (commandText == "//Party2" || commandText == "//Group2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PARTY2, 1);

        return true;
    }

    if (commandText == "//Party3" || commandText == "//Group3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PARTY3, 1);

        return true;
    }

    if (commandText == "//Party4" || commandText == "//Group4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PARTY4, 1);

        return true;
    }

    if (commandText == "//Party5" || commandText == "//Group5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_PARTY5, 1);

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

    if (commandText == "//Discipline1")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK1, 1);
    }

    if (commandText == "//Discipline2")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK2, 1);
    }

    if (commandText == "//Discipline3")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK3, 1);
    }

    if (commandText == "//Discipline4")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK4, 1);
    }

    if (commandText == "//Discipline5")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK5, 1);
    }

    if (commandText == "//Discipline6")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK6, 1);
    }

    if (commandText == "//Discipline7")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK7, 1);
    }

    if (commandText == "//Discipline8")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CMD_OPENING_ATTACK8, 1);
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

    if (commandText == "//UseItemCharm")
    {
        EQ_InterpretCommand("/useitem 0");

        return true;
    }

    if (commandText == "//UseItemLeftEar")
    {
        EQ_InterpretCommand("/useitem 1");

        return true;
    }

    if (commandText == "//UseItemHead")
    {
        EQ_InterpretCommand("/useitem 2");

        return true;
    }

    if (commandText == "//UseItemFace")
    {
        EQ_InterpretCommand("/useitem 3");

        return true;
    }

    if (commandText == "//UseItemRightEar")
    {
        EQ_InterpretCommand("/useitem 4");

        return true;
    }

    if (commandText == "//UseItemNeck")
    {
        EQ_InterpretCommand("/useitem 5");

        return true;
    }

    if (commandText == "//UseItemShoulders")
    {
        EQ_InterpretCommand("/useitem 6");

        return true;
    }

    if (commandText == "//UseItemArms")
    {
        EQ_InterpretCommand("/useitem 7");

        return true;
    }

    if (commandText == "//UseItemBack")
    {
        EQ_InterpretCommand("/useitem 8");

        return true;
    }

    if (commandText == "//UseItemLeftWrist")
    {
        EQ_InterpretCommand("/useitem 9");

        return true;
    }

    if (commandText == "//UseItemRightWrist")
    {
        EQ_InterpretCommand("/useitem 10");

        return true;
    }

    if (commandText == "//UseItemRange")
    {
        EQ_InterpretCommand("/useitem 11");

        return true;
    }

    if (commandText == "//UseItemHands")
    {
        EQ_InterpretCommand("/useitem 12");

        return true;
    }

    if (commandText == "//UseItemPrimary")
    {
        EQ_InterpretCommand("/useitem 13");

        return true;
    }

    if (commandText == "//UseItemSecondary")
    {
        EQ_InterpretCommand("/useitem 14");

        return true;
    }

    if (commandText == "//UseItemLeftRing")
    {
        EQ_InterpretCommand("/useitem 15");

        return true;
    }

    if (commandText == "//UseItemRightRing")
    {
        EQ_InterpretCommand("/useitem 16");

        return true;
    }

    if (commandText == "//UseItemChest")
    {
        EQ_InterpretCommand("/useitem 17");

        return true;
    }

    if (commandText == "//UseItemLegs")
    {
        EQ_InterpretCommand("/useitem 18");

        return true;
    }

    if (commandText == "//UseItemFeet")
    {
        EQ_InterpretCommand("/useitem 19");

        return true;
    }

    if (commandText == "//UseItemWaist")
    {
        EQ_InterpretCommand("/useitem 20");

        return true;
    }

    if (commandText == "//UseItemPowerSource")
    {
        EQ_InterpretCommand("/useitem 21");

        return true;
    }

    if (commandText == "//UseItemAmmo")
    {
        EQ_InterpretCommand("/useitem 22");

        return true;
    }

    // //UseItemBag <bagNumber>,<slotNumber>
    if (EQAPP_String_BeginsWith(commandText, "//UseItemBag ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                {
                    // /useitem <bagIndex> <slotIndex>
                    // Bag 1  = 23
                    // Bag 2  = 24
                    // Bag 3  = 25
                    // Bag 4  = 26
                    // Bag 5  = 27
                    // Bag 6  = 28
                    // Bag 7  = 29
                    // Bag 8  = 30
                    // Bag 9  = 31
                    // Bag 10 = 32

                    uint32_t bagNumber = std::stoul(tokens.at(0));

                    if (bagNumber > 0 && bagNumber < (EQ_NUM_BAGS + 1))
                    {
                        bagNumber = bagNumber + 22; // 1+22=23, 2+2=24, 3+22=25, 10+22=32, etc

                        uint32_t slotNumber = std::stoul(tokens.at(1));

                        if (slotNumber > 0 && slotNumber < (EQ_NUM_BAG_SLOTS + 1))
                        {
                            slotNumber = slotNumber - 1; // slots start at index 0

                            std::stringstream ss;
                            ss << "/useitem " << bagNumber << " " << slotNumber;

                            std::cout << ss.str() << std::endl;

                            EQ_InterpretCommand(ss.str().c_str());
                        }
                    }
                }
            }
        }

        return true;
    }

    // //UseItem <itemName>
    if (EQAPP_String_BeginsWith(commandText, "//UseItem ") == true)
    {
        std::string itemName = EQAPP_String_GetAfter(commandText, " ");
        if (itemName.size() != 0)
        {
            std::stringstream ss;
            ss << "/useitem " << itemName;

            EQ_InterpretCommand(ss.str().c_str());
        }
    }

    if (EQAPP_String_BeginsWith(commandText, "//CombatHotButton ") == true || EQAPP_String_BeginsWith(commandText, "//CHB ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                signed int buttonNumber = std::stoi(commandTextAfterSpace);

                if (buttonNumber > 0 && buttonNumber < (EQ_NUM_HOTBAR_BUTTONS + 1))
                {
                    g_CombatHotButtonIndex = buttonNumber - 1;

                    std::cout << "Combat HotButton: " << buttonNumber << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AlwaysHotButton ") == true || EQAPP_String_BeginsWith(commandText, "//AHB ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                signed int buttonNumber = std::stoi(commandTextAfterSpace);

                if (buttonNumber > 0 && buttonNumber < (EQ_NUM_HOTBAR_BUTTONS + 1))
                {
                    g_AlwaysHotButtonIndex = buttonNumber - 1;

                    std::cout << "Always HotButton: " << buttonNumber << std::endl;
                }
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

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindName ") == true)
    {
        std::string findText = EQAPP_String_GetAfter(commandText, " ");
        if (findText.size() != 0)
        {
            g_ESPFindSpawnName = findText;

            std::cout << "ESP Find Spawn Name: " << findText << std::endl;
        }

        return true;
    }

    if (commandText == "//ESPFindLastName")
    {
        g_ESPFindSpawnLastName = std::string();

        std::cout << "ESP Find Spawn Last Name reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindLastName ") == true)
    {
        std::string findText = EQAPP_String_GetAfter(commandText, " ");
        if (findText.size() != 0)
        {
            g_ESPFindSpawnLastName = findText;

            std::cout << "ESP Find Spawn Last Name: " << findText << std::endl;
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Multiline ") == true)
    {
        EQAPP_InterpretCommand_InterpretArguments(commandText, "");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//MultilineRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Cast ") == true || EQAPP_String_BeginsWith(commandText, "//Casting ") == true)
    {
        std::string spellGemNumberOrSpellName = EQAPP_String_GetAfter(commandText, " ");
        if (spellGemNumberOrSpellName.size() != 0)
        {
            if (EQAPP_String_IsDigits(spellGemNumberOrSpellName) == true)
            {
                uint32_t spellGemNumber = std::stoul(spellGemNumberOrSpellName);

                EQ_CastSpellByGemIndex(spellGemNumber - 1);
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//CastRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "//Cast ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//CastingRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "//Casting ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DoAbility ") == true)
    {
        EQAPP_InterpretCommand_InterpretArguments(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DoAbilityRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Discipline ") == true)
    {
        EQAPP_InterpretCommand_InterpretArguments(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DisciplineRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AltActivate ") == true)
    {
        EQAPP_InterpretCommand_InterpretArguments(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AltActivateRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatConnect ") == true || EQAPP_String_BeginsWith(commandText, "//BCC ") == true)
    {
        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            std::cout << "Box Chat Connect as Name: " << name << std::endl;

            if (EQAPP_BoxChat_Connect(name) == false)
            {
                std::cout << "Box Chat failed to connect!" << std::endl;
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
        }

        return true;
    }

    if (commandText == "//BoxChatDisconnect" || commandText == "//BCD")
    {
        EQAPP_BoxChat_Disconnect();

        return true;
    }

    if (commandText == "//BoxChatStatus" || commandText == "//BCS")
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Box Chat Status: You are disconnected." << std::endl;
        }
        else
        {
            std::cout << "Box Chat Status: You are connected." << std::endl;

            if (g_BoxChatClientName.size() != 0)
            {
                std::cout << "Client Name: " << g_BoxChatClientName << std::endl;
            }

            if (g_BoxChatChannelName.size() != 0)
            {
                std::cout << "Channel Name: " << g_BoxChatChannelName << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatSetChannel ") == true || EQAPP_String_BeginsWith(commandText, "//BCSC ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            EQAPP_BoxChat_SetChannel(name);

            std::cout << "Box Chat Channel set to '" << name << "'" << std::endl;
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatTell ") == true || EQAPP_String_BeginsWith(commandText, "//BCT ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(commandText, ' ');
        if (tokens.size() > 2)
        {
            std::string name = tokens.at(1);
            if (name.size() != 0)
            {
                EQAPP_BoxChat_SendText(commandText);

                std::cout << "Box Chat to '" << name << "': " << commandText << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatToChannel ") == true || EQAPP_String_BeginsWith(commandText, "//BCTC ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(commandText, ' ');
        if (tokens.size() > 2)
        {
            std::string name = tokens.at(1);
            if (name.size() != 0)
            {
                EQAPP_BoxChat_SendText(commandText);

                std::cout << "Box Chat to Channel '" << name << "': " << commandText << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatOthers ") == true || EQAPP_String_BeginsWith(commandText, "//BCA ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_BoxChat_SendText(commandText);

            std::cout << "Box Chat to Others: " << commandTextAfterSpace << std::endl;
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatAll ") == true || EQAPP_String_BeginsWith(commandText, "//BCAA ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_BoxChat_SendText(commandText);

            std::cout << "Box Chat to All: " << commandTextAfterSpace << std::endl;
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ChatEventAdd ") == true || EQAPP_String_BeginsWith(commandText, "//CEAdd ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_Contains(commandTextAfterSpace, "^") == true)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, '^');
                if (tokens.size() == 2)
                {
                    std::string chatText = tokens.at(0);
                    std::string commandText = tokens.at(1);

                    if (chatText.size() != 0 && commandText.size() != 0)
                    {
                        EQAPP_ChatEvent_AddToList(chatText, commandText);

                        std::cout << "Chat Event added." << std::endl;
                        std::cout << "Chat Text: " << chatText << std::endl;
                        std::cout << "Command Text: " << commandText << std::endl;
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ChatEventRemove ") == true || EQAPP_String_BeginsWith(commandText, "//CERemove ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_ChatEvent_RemoveFromList(commandTextAfterSpace);

            std::cout << "Chat Event removed." << std::endl;
            std::cout << "Chat Text: " << commandTextAfterSpace << std::endl;
        }

        return true;
    }

    if (commandText == "//SpawnList")
    {
        std::cout << "Spawn List:" << std::endl;

        EQAPP_PrintSpawnList();

        return true;
    }

    if (commandText == "//Location" || commandText == "//Loc")
    {
        EQAPP_PrintLocation();

        return true;
    }

    if (commandText == "//MouseLocation" || commandText == "//MouseLoc")
    {
        EQAPP_PrintMouseLocation();

        return true;
    }

    if (commandText == "//NearbyNPCList")
    {
        std::cout << "Nearby NPC List:" << std::endl;

        uint32_t spawnIndex = 0;

        std::vector<uint32_t> spawnIDList = EQAPP_GetNPCSpawnIDListSortedByDistance();

        for (auto& spawnID : spawnIDList)
        {
            if (spawnIndex > 19)
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

            std::cout << (spawnIndex + 1) << ": " << spawnName << " (ID: " << spawnID << ")" << std::endl;

            spawnIndex++;
        }

        return true;
    }

    if (commandText == "//Melody")
    {
        EQ_InterpretCommand("/stopsong");
        EQ_InterpretCommand("/melody");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Melody ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() != 0)
            {
                EQ_InterpretCommand("/stopsong");
                EQ_InterpretCommand("/melody");

                std::stringstream ss;
                ss << "/melody";

                for (auto& token : tokens)
                {
                    if (EQAPP_String_IsDigits(token) == true)
                    {
                        ss << " " << token;
                    }
                }

                EQ_InterpretCommand(ss.str().c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Echo ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQ_PrintTextToChat(commandTextAfterSpace.c_str());
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfMoving ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQ_IsPlayerMoving() == true)
            {
                EQ_InterpretCommand(commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfNotMoving ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQ_IsPlayerMoving() == false)
            {
                EQ_InterpretCommand(commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//InventoryFind ") == true  || EQAPP_String_BeginsWith(commandText, "//InvFind ") == true)
    {
        std::string findText = EQAPP_String_GetAfter(commandText, " ");
        if (findText.size() != 0)
        {
            EQAPP_InventoryFind(findText.c_str());
        }

        return true;
    }

    if (commandText == "//TurnLeft")
    {
        EQ_TurnLeft();

        return true;
    }

    if (commandText == "//TurnRight")
    {
        EQ_TurnRight();

        return true;
    }

    if (commandText == "//TurnAround")
    {
        EQ_TurnAround();

        return true;
    }

    if (commandText == "//FaceNorth")
    {

        EQ_SetPlayerSpawnHeadingNorth();

        return true;
    }

    if (commandText == "//FaceNorthWest")
    {

        EQ_SetPlayerSpawnHeadingNorthWest();

        return true;
    }

    if (commandText == "//FaceWest")
    {

        EQ_SetPlayerSpawnHeadingWest();

        return true;
    }

    if (commandText == "//FaceSouthWest")
    {

        EQ_SetPlayerSpawnHeadingSouthWest();

        return true;
    }

    if (commandText == "//FaceSouth")
    {

        EQ_SetPlayerSpawnHeadingSouth();

        return true;
    }

    if (commandText == "//FaceSouthEast")
    {

        EQ_SetPlayerSpawnHeadingSouthEast();

        return true;
    }

    if (commandText == "//FaceEast")
    {

        EQ_SetPlayerSpawnHeadingEast();

        return true;
    }

    if (commandText == "//FaceNorthEast")
    {

        EQ_SetPlayerSpawnHeadingNorthEast();

        return true;
    }

    if (commandText == "//ShowWindow")
    {
        ShowWindow(EQ_GetWindow(), SW_SHOW);

        return true;
    }

    if (commandText == "//HideWindow")
    {
        ShowWindow(EQ_GetWindow(), SW_HIDE);

        return true;
    }

    if (commandText == "//ForegroundWindow" || commandText == "//Foreground")
    {
        auto window = EQ_GetWindow();

        ShowWindow(window, SW_SHOW);
        SetForegroundWindow(window);
        SetFocus(window);

        return true;
    }

    if (commandText == "//GroupRoleMainTank" || commandText == "//GroupRoleTank")
    {
        std::string playerName = EQ_GetPlayerSpawnName();
        if (playerName.size() != 0)
        {
            std::stringstream ss;
            ss << "/grouproles set " << playerName << " 1";

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//GroupRoleMainAssist" || commandText == "//GroupRoleAssist")
    {
        std::string playerName = EQ_GetPlayerSpawnName();
        if (playerName.size() != 0)
        {
            std::stringstream ss;
            ss << "/grouproles set " << playerName << " 2";

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//GroupRolePuller")
    {
        std::string playerName = EQ_GetPlayerSpawnName();
        if (playerName.size() != 0)
        {
            std::stringstream ss;
            ss << "/grouproles set " << playerName << " 3";

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//GroupRoleMarkNPC")
    {
        std::string playerName = EQ_GetPlayerSpawnName();
        if (playerName.size() != 0)
        {
            std::stringstream ss;
            ss << "/grouproles set " << playerName << " 4";

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//GroupRoleMasterLooter")
    {
        std::string playerName = EQ_GetPlayerSpawnName();
        if (playerName.size() != 0)
        {
            std::stringstream ss;
            ss << "/grouproles set " << playerName << " 5";

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    return false;
}
