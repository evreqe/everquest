#pragma once

#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_bandolier.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_cheat.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_killmobs.h"
#include "eqapp_lantern.h"
#include "eqapp_console.h"
#include "eqapp_followai.h"
#include "eqapp_namedspawns.h"
#include "eqapp_namecolor.h"
#include "eqapp_speed.h"
#include "eqapp_waypoint.h"
#include "eqapp_hud.h"
#include "eqapp_nodraw.h"
#include "eqapp_sleep.h"
#include "eqapp_windowtitle.h"
#include "eqapp_windowforeground.h"

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
    {"//Bandolier",                    &EQAPP_Bandolier_Toggle},
    {"//BandolierOn",                  &EQAPP_Bandolier_On},
    {"//BandolierOff",                 &EQAPP_Bandolier_Off},
    {"//BandolierLoad",                &EQAPP_Bandolier_Load},
    {"//BandolierSave",                &EQAPP_Bandolier_Save},
    {"//BandolierPrint",               &EQAPP_Bandolier_Print},
    {"//CombatHotButton",              &EQAPP_CombatHotButton_Toggle},
    {"//CombatHotButtonOn",            &EQAPP_CombatHotButton_On},
    {"//CombatHotButtonOff",           &EQAPP_CombatHotButton_Off},
    {"//CHB",                          &EQAPP_CombatHotButton_Toggle},
    {"//CHBOn",                        &EQAPP_CombatHotButton_On},
    {"//CHBOff",                       &EQAPP_CombatHotButton_Off},
    {"//AlwaysSeeInvis",               &EQAPP_Cheat_AlwaysSeeInvis_Toggle},
    {"//AlwaysSeeInvisOn",             &EQAPP_Cheat_AlwaysSeeInvis_On},
    {"//AlwaysSeeInvisOff",            &EQAPP_Cheat_AlwaysSeeInvis_Off},
    {"//AlwaysBreatheUnderwater",      &EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle},
    {"//AlwaysBreatheUnderwaterOn",    &EQAPP_Cheat_AlwaysBreatheUnderwater_On},
    {"//AlwaysBreatheUnderwaterOff",   &EQAPP_Cheat_AlwaysBreatheUnderwater_Off},
    {"//NeverBlind",                   &EQAPP_Cheat_NeverBlind_Toggle},
    {"//NeverBlindOn",                 &EQAPP_Cheat_NeverBlind_On},
    {"//NeverBlindOff",                &EQAPP_Cheat_NeverBlind_Off},
    {"//NeverEncumbered",              &EQAPP_Cheat_NeverEncumbered_Toggle},
    {"//NeverEncumberedOn",            &EQAPP_Cheat_NeverEncumbered_On},
    {"//NeverEncumberedOff",           &EQAPP_Cheat_NeverEncumbered_Off},
    {"//NeverStunned",                 &EQAPP_Cheat_NeverStunned_Toggle},
    {"//NeverStunnedOn",               &EQAPP_Cheat_NeverStunned_On},
    {"//NeverStunnedOff",              &EQAPP_Cheat_NeverStunned_Off},
    {"//NeverSlide",                   &EQAPP_Cheat_NeverSlide_Toggle},
    {"//NeverSlideOn",                 &EQAPP_Cheat_NeverSlide_On},
    {"//NeverSlideOff",                &EQAPP_Cheat_NeverSlide_Off},
    {"//NoFallDamage",                 &EQAPP_Cheat_NoFallDamage_Toggle},
    {"//NoFallDamageOn",               &EQAPP_Cheat_NoFallDamage_On},
    {"//NoFallDamageOff",              &EQAPP_Cheat_NoFallDamage_Off},
    {"//NoEnvironmentalDamage",        &EQAPP_Cheat_NoEnvironmentalDamage_Toggle},
    {"//NoEnvironmentalDamageOn",      &EQAPP_Cheat_NoEnvironmentalDamage_On},
    {"//NoEnvironmentalDamageOff",     &EQAPP_Cheat_NoEnvironmentalDamage_Off},
    {"//Levitate",                     &EQAPP_Cheat_Levitate_Toggle},
    {"//LevitateOn",                   &EQAPP_Cheat_Levitate_On},
    {"//LevitateOff",                  &EQAPP_Cheat_Levitate_Off},
    {"//Fly",                          &EQAPP_Cheat_Fly_Toggle},
    {"//FlyOn",                        &EQAPP_Cheat_Fly_On},
    {"//FlyOff",                       &EQAPP_Cheat_Fly_Off},
    {"//MemorizeSpellsInstantly",      &EQAPP_Cheat_MemorizeSpellsInstantly_Toggle},
    {"//MemorizeSpellsInstantlyOn",    &EQAPP_Cheat_MemorizeSpellsInstantly_On},
    {"//MemorizeSpellsInstantlyOff",   &EQAPP_Cheat_MemorizeSpellsInstantly_Off},
    {"//ScribeSpellsInstantly",        &EQAPP_Cheat_ScribeSpellsInstantly_Toggle},
    {"//ScribeSpellsInstantlyOn",      &EQAPP_Cheat_ScribeSpellsInstantly_On},
    {"//ScribeSpellsInstantlyOff",     &EQAPP_Cheat_ScribeSpellsInstantly_Off},
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
    {"//ESPLineOfSight",               &EQAPP_ESP_LineOfSight_Toggle},
    {"//ESPShowSpawns",                &EQAPP_ESP_ShowSpawns_Toggle},
    {"//ESPShowDoors",                 &EQAPP_ESP_ShowDoors_Toggle},
    {"//ESPHF",                        &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPFL",                        &EQAPP_ESP_FindLine_Toggle},
    {"//ESPLOS",                       &EQAPP_ESP_LineOfSight_Toggle},
    {"//ESPSpawns",                    &EQAPP_ESP_ShowSpawns_Toggle},
    {"//ESPDoors",                     &EQAPP_ESP_ShowDoors_Toggle},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    {"//ChangeHeightOn",               &EQAPP_ChangeHeight_On},
    {"//ChangeHeightOff",              &EQAPP_ChangeHeight_Off},
    {"//CH",                           &EQAPP_ChangeHeight_Toggle},
    {"//CHOn",                         &EQAPP_ChangeHeight_On},
    {"//CHOff",                        &EQAPP_ChangeHeight_Off},
    {"//ChatEvent",                    &EQAPP_ChatEvent_Toggle},
    {"//ChatEventOn",                  &EQAPP_ChatEvent_On},
    {"//ChatEventOff",                 &EQAPP_ChatEvent_Off},
    {"//ChatEventDebug",               &EQAPP_ChatEvent_Debug_Toggle},
    {"//ChatEventDebugOn",             &EQAPP_ChatEvent_Debug_On},
    {"//ChatEventDebugOff",            &EQAPP_ChatEvent_Debug_Off},
    {"//ChatEventLoad",                &EQAPP_ChatEvent_Load},
    {"//ChatEventClear",               &EQAPP_ChatEvent_ClearList},
    {"//ChatEventList",                &EQAPP_ChatEvent_PrintList},
    {"//CE",                           &EQAPP_ChatEvent_Toggle},
    {"//CEOn",                         &EQAPP_ChatEvent_On},
    {"//CEOff",                        &EQAPP_ChatEvent_Off},
    {"//CEDebug",                      &EQAPP_ChatEvent_Debug_Toggle},
    {"//CEDebugOn",                    &EQAPP_ChatEvent_Debug_On},
    {"//CEDebugOff",                   &EQAPP_ChatEvent_Debug_Off},
    {"//CELoad",                       &EQAPP_ChatEvent_Load},
    {"//CEClear",                      &EQAPP_ChatEvent_ClearList},
    {"//CEList",                       &EQAPP_ChatEvent_PrintList},
    {"//Speed",                        &EQAPP_Speed_Toggle},
    {"//SpeedOn",                      &EQAPP_Speed_On},
    {"//SpeedOff",                     &EQAPP_Speed_Off},
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
    {"//WindowForeground",             &EQAPP_WindowForeground_Toggle},
    {"//WindowForegroundOn",           &EQAPP_WindowForeground_On},
    {"//WindowForegroundOff",          &EQAPP_WindowForeground_Off},
    {"//WF",                           &EQAPP_WindowForeground_Toggle},
    {"//WFOn",                         &EQAPP_WindowForeground_On},
    {"//WFOff",                        &EQAPP_WindowForeground_Off},
    {"//FreeCamera",                   &EQAPP_FreeCamera_Toggle},
    {"//FreeCameraOn",                 &EQAPP_FreeCamera_On},
    {"//FreeCameraOff",                &EQAPP_FreeCamera_Off},
    {"//FC",                           &EQAPP_FreeCamera_Toggle},
    {"//FCOn",                         &EQAPP_FreeCamera_On},
    {"//FCOff",                        &EQAPP_FreeCamera_Off},
    {"//WPLoad",                       &EQAPP_WaypointList_Load},
    {"//WPSave",                       &EQAPP_WaypointList_Save},
    {"//WPList",                       &EQAPP_WaypointList_Print},
    {"//WPNames",                      &EQAPP_WaypointList_PrintNames},
    {"//WPClear",                      &EQAPP_WaypointList_Clear},
    {"//WPEditor",                     &EQAPP_WaypointEditor_Toggle},
    {"//WPEditorOn",                   &EQAPP_WaypointEditor_On},
    {"//WPEditorOff",                  &EQAPP_WaypointEditor_Off},
    {"//WPEditorHeightFilter",         &EQAPP_WaypointEditor_HeightFilter_Toggle},
    {"//WPEditorHeightFilterOn",       &EQAPP_WaypointEditor_HeightFilter_On},
    {"//WPEditorHeightFilterOff",      &EQAPP_WaypointEditor_HeightFilter_Off},
    {"//WPEditorDistanceFilter",       &EQAPP_WaypointEditor_DistanceFilter_Toggle},
    {"//WPEditorDistanceFilterOn",     &EQAPP_WaypointEditor_DistanceFilter_On},
    {"//WPEditorDistanceFilterOff",    &EQAPP_WaypointEditor_DistanceFilter_Off},
    {"//WPEdit",                       &EQAPP_WaypointEditor_Toggle},
    {"//WPEditOn",                     &EQAPP_WaypointEditor_On},
    {"//WPEditOff",                    &EQAPP_WaypointEditor_Off},
    {"//WPEditHF",                     &EQAPP_WaypointEditor_HeightFilter_Toggle},
    {"//WPEditHFOn",                   &EQAPP_WaypointEditor_HeightFilter_On},
    {"//WPEditHFOff",                  &EQAPP_WaypointEditor_HeightFilter_Off},
    {"//WPEditDF",                     &EQAPP_WaypointEditor_DistanceFilter_Toggle},
    {"//WPEditDFOn",                   &EQAPP_WaypointEditor_DistanceFilter_On},
    {"//WPEditDFOff",                  &EQAPP_WaypointEditor_DistanceFilter_Off},
    {"//NameColor",                    &EQAPP_NameColor_Toggle},
    {"//NameColorOn",                  &EQAPP_NameColor_On},
    {"//NameColorOff",                 &EQAPP_NameColor_Off},
    {"//NC",                           &EQAPP_NameColor_Toggle},
    {"//NCOn",                         &EQAPP_NameColor_On},
    {"//NCOff",                        &EQAPP_NameColor_Off},
    {"//NamedSpawns",                  &EQAPP_NamedSpawns_Toggle},
    {"//NamedSpawnsOn",                &EQAPP_NamedSpawns_On},
    {"//NamedSpawnsOff",               &EQAPP_NamedSpawns_Off},
    {"//NamedSpawnsNewSpawns",         &EQAPP_NamedSpawns_NewSpawns_Toggle},
    {"//NamedSpawnsNewSpawnsOn",       &EQAPP_NamedSpawns_NewSpawns_On},
    {"//NamedSpawnsNewSpawnsOff",      &EQAPP_NamedSpawns_NewSpawns_Off},
    {"//NamedSpawnsLoad",              &EQAPP_NamedSpawns_Load},
    {"//NamedSpawnsList",              &EQAPP_NamedSpawns_PrintList},
    {"//NamedSpawnsUp",                &EQAPP_NamedSpawns_PrintUp},
    {"//NS",                           &EQAPP_NamedSpawns_Toggle},
    {"//NSOn",                         &EQAPP_NamedSpawns_On},
    {"//NSOff",                        &EQAPP_NamedSpawns_Off},
    {"//NSNewSpawns",                  &EQAPP_NamedSpawns_NewSpawns_Toggle},
    {"//NSNewSpawnsOn",                &EQAPP_NamedSpawns_NewSpawns_On},
    {"//NSNewSpawnsOff",               &EQAPP_NamedSpawns_NewSpawns_Off},
    {"//NSLoad",                       &EQAPP_NamedSpawns_Load},
    {"//NSList",                       &EQAPP_NamedSpawns_PrintList},
    {"//NSUp",                         &EQAPP_NamedSpawns_PrintUp},
    {"//NoDraw",                       &EQAPP_NoDraw_Toggle},
    {"//NoDrawOn",                     &EQAPP_NoDraw_On},
    {"//NoDrawOff",                    &EQAPP_NoDraw_Off},
    {"//ND",                           &EQAPP_NoDraw_Toggle},
    {"//NDOn",                         &EQAPP_NoDraw_On},
    {"//NDOff",                        &EQAPP_NoDraw_Off},
    {"//Lantern",                      &EQAPP_Lantern_Toggle},
    {"//LanternOn",                    &EQAPP_Lantern_On},
    {"//LanternOff",                   &EQAPP_Lantern_Off},
    {"//KillMobs",                     &EQAPP_KillMobs_Toggle},
    {"//KillMobsOn",                   &EQAPP_KillMobs_On},
    {"//KillMobsOff",                  &EQAPP_KillMobs_Off},
    {"//KillMobsLoad",                 &EQAPP_KillMobs_Load},
    {"//KM",                           &EQAPP_KillMobs_Toggle},
    {"//KMOn",                         &EQAPP_KillMobs_On},
    {"//KMOff",                        &EQAPP_KillMobs_Off},
    {"//KMLoad",                       &EQAPP_KillMobs_Load},
    {"//OpenAllDoors",                 &EQ_OpenAllDoors},
    {"//CloseAllDoors",                &EQ_CloseAllDoors},
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

        std::cout << "Character: 0x" << std::hex << EQ_GetCharacter() << std::dec << std::endl;

        std::cout << "CharacterBase: 0x" << std::hex << EQ_GetCharacterBase() << std::dec << std::endl;

        std::cout << "ProfileManager: 0x" << std::hex << EQ_GetProfileManager() << std::dec << std::endl;

        std::cout << "CharInfo2: 0x" << std::hex << EQ_GetCharInfo2() << std::dec << std::endl;

        std::cout << "Bandolier: 0x" << std::hex << EQ_GetCharInfo2() + EQ_OFFSET_CharInfo2__Bandolier << std::dec << std::endl;

        auto charInfo2 = EQ_GetCharInfo2();

        auto charInfo2Bandolier = (EQ::CharInfo2Bandolier_ptr)(charInfo2 + EQ_OFFSET_CharInfo2__Bandolier);

        for (unsigned int i = 0; i < EQ_NUM_BANDOLIER_SLOTS; i++)
        {
            std::cout << "[" << i + 1 << "] " << charInfo2Bandolier->Bandolier[i].Name << std::endl;

            std::cout << "[" << i + 1 << "-1] " << charInfo2Bandolier->Bandolier[i].Items[0].Name << std::endl;
            std::cout << "[" << i + 1 << "-2] " << charInfo2Bandolier->Bandolier[i].Items[1].Name << std::endl;
            std::cout << "[" << i + 1 << "-3] " << charInfo2Bandolier->Bandolier[i].Items[2].Name << std::endl;
            std::cout << "[" << i + 1 << "-4] " << charInfo2Bandolier->Bandolier[i].Items[3].Name << std::endl;
        }

/*
        auto playerSpawn = EQ_GetPlayerSpawn();

        std::cout << "spawn: 0x" << std::hex << playerSpawn << std::dec << std::endl;

        auto spawnActorClient = EQ_GetSpawnActorClient(playerSpawn);
        if (spawnActorClient != NULL)
        {
            std::cout << "spawnActorClient: 0x" << std::hex << spawnActorClient << std::dec << std::endl;

            auto spawnActorInterface = EQ_ReadMemory<uint32_t>(spawnActorClient + EQ_OFFSET_CActorClient_CActorInterface);
            if (spawnActorInterface != NULL)
            {
                std::cout << "spawnActorInterface: 0x" << std::hex << spawnActorInterface << std::dec << std::endl;

                std::cout << "spawnActorInterface &: 0x" << std::hex << spawnActorInterface << std::dec << std::endl;
            }

            auto spawnLightInterface = EQ_ReadMemory<uint32_t>(spawnActorClient + EQ_OFFSET_CActorClient_CActorInterface + 0x04);
            if (spawnActorInterface != NULL)
            {
                std::cout << "spawnLightInterface: 0x" << std::hex << spawnLightInterface << std::dec << std::endl;

                std::cout << "spawnLightInterface &: 0x" << std::hex << spawnLightInterface << std::dec << std::endl;
            }
        }
*/

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//TestEx ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t value = std::stoul(commandTextAfterSpace);

                auto playerSpawn = EQ_GetPlayerSpawn();

                std::cout << "playerSpawn: " << std::hex << playerSpawn << std::dec << std::endl;

                auto actorClient = EQ_GetSpawnActorClient(playerSpawn);

                std::cout << "actorClient: " << std::hex << actorClient << std::dec << std::endl;

                auto actorClientValue = EQ_ReadMemory<signed int>(actorClient + value);

                std::cout << "actorClientValue: " << actorClientValue << std::endl;
            }
        }

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

    if (commandText == "//Sit")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_SITTING);
        }

        return true;
    }

    if (commandText == "//Stand")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnStandingState(playerSpawn, EQ_STANDING_STATE_STANDING);
        }

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

    if (commandText == "//ESPFindID")
    {
        g_ESPFindSpawnID = 0;

        std::cout << "ESP Find Spawn ID reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindID ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t ID = std::stoul(commandTextAfterSpace);

                g_ESPFindSpawnID = ID;

                std::cout << "ESP Find Spawn ID: " << ID << std::endl;
            }
        }

        return true;
    }

    if (commandText == "//ESPFindLevel")
    {
        g_ESPFindSpawnLevel = 0;

        std::cout << "ESP Find Spawn Level reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindLevel ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t level = std::stoul(commandTextAfterSpace);

                g_ESPFindSpawnLevel = level;

                std::cout << "ESP Find Spawn Level: " << level << std::endl;
            }
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

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatIP ") == true || EQAPP_String_BeginsWith(commandText, "//BCIP ") == true)
    {
        std::string ipAddress = EQAPP_String_GetAfter(commandText, " ");
        if (ipAddress.size() != 0)
        {
            g_BoxChatServerIPAddress = ipAddress;

            std::cout << "Box Chat IP Address: " << g_BoxChatServerIPAddress << std::endl;
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
                        //std::cout << "Chat Text: " << chatText << std::endl;
                        //std::cout << "Command Text: " << commandText << std::endl;
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
            //std::cout << "Chat Text: " << commandTextAfterSpace << std::endl;
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

    if (EQAPP_String_BeginsWith(commandText, "//IfTarget ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn != NULL)
            {
                EQ_InterpretCommand(commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfNoTarget ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn == NULL)
            {
                EQ_InterpretCommand(commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfTargetLineOfSight ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    if (EQ_CanSpawnCastRayToSpawn(playerSpawn, targetSpawn) == true)
                    {
                        EQ_InterpretCommand(commandTextAfterSpace.c_str());
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfTargetNoLineOfSight ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn != NULL)
            {
                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    if (EQ_CanSpawnCastRayToSpawn(playerSpawn, targetSpawn) == false)
                    {
                        EQ_InterpretCommand(commandTextAfterSpace.c_str());
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfTargetWithinDistance ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, '^');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                {
                    float distance = std::stof(tokens.at(0));

                    auto targetSpawn = EQ_GetTargetSpawn();
                    if (targetSpawn != NULL)
                    {
                        if (EQ_IsSpawnWithinDistance(targetSpawn, distance) == true)
                        {
                            EQ_InterpretCommand(tokens.at(1).c_str());
                        }
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfTargetNotWithinDistance ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, '^');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                {
                    float distance = std::stof(tokens.at(0));

                    auto targetSpawn = EQ_GetTargetSpawn();
                    if (targetSpawn != NULL)
                    {
                        if (EQ_IsSpawnWithinDistance(targetSpawn, distance) == false)
                        {
                            EQ_InterpretCommand(tokens.at(1).c_str());
                        }
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfNumPlayersInZone ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, '^');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                {
                    uint32_t count = std::stoul(tokens.at(0));

                    auto numPlayersInZone = EQ_GetNumSpawnsInZone(EQ_SPAWN_TYPE_PLAYER);
                    if (numPlayersInZone >= count)
                    {
                        EQ_InterpretCommand(tokens.at(1).c_str());
                    }
                }
            }
        }

        return true;
    }

    if (commandText == "//UseDoor")
    {
        EQ_UseDoorByDistance(EQ_USE_DOOR_DISTANCE_DEFAULT);

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//UseDoor ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                float distance = std::stof(commandTextAfterSpace);
                if (distance > 0.0f)
                {
                    EQ_UseDoorByDistance(distance);
                }
            }
            else
            {
                EQ_UseDoor(commandTextAfterSpace.c_str());
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

    if (commandText == "//ZoneInfo")
    {
        auto zoneID = EQ_GetZoneID();
        auto zoneLongName = EQ_GetZoneLongName();
        auto zoneShortName = EQ_GetZoneShortName();

        std::cout << "Zone: " << zoneLongName << " (" << zoneShortName << ") [ID: " << zoneID << "]";

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//SpeedMultiplier ") == true || EQAPP_String_BeginsWith(commandText, "//Speed ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            float multiplier = std::stof(commandTextAfterSpace);
            if (multiplier > 0.0f)
            {
                g_SpeedMultiplier = multiplier;

                std::cout << "Speed Multiplier: " << multiplier << std::endl;
            }
        }

        return true;
    }

/********** BEGIN OF WAYPOINT EDITOR **********/

    if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
    {
        if (commandText == "//WPUndo")
        {
            EQAPP_Waypoint_Undo();

            return true;
        }

        if (commandText == "//WPRedo")
        {
            EQAPP_Waypoint_Redo();

            return true;
        }

        if (commandText == "//WPA" || commandText == "//WPAdd")
        {
            EQAPP_Waypoint_AddAtPlayer("");

            return true;
        }

        // //WPAdd <name>
        if (EQAPP_String_BeginsWith(commandText, "//WPA ") == true || EQAPP_String_BeginsWith(commandText, "//WPAdd ") == true)
        {
            std::string name = EQAPP_String_GetAfter(commandText, " ");
            if (name.size() != 0)
            {
                EQAPP_Waypoint_AddAtPlayer(name.c_str());
            }

            return true;
        }

        if (commandText == "//WPAC" || commandText == "//WPAddConnect")
        {
            EQAPP_Waypoint_AddAtPlayerAndConnectToLastAddedIndex();

            return true;
        }

        // //WPAddBetween <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPAB ") == true || EQAPP_String_BeginsWith(commandText, "//WPAddBetween ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_AddAtPlayerBetween(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        if (commandText == "//WPAT" || commandText == "//WPAddTarget")
        {
            EQAPP_Waypoint_AddAtTarget("");

            return true;
        }

        // //WPAddTarget <name>
        if (EQAPP_String_BeginsWith(commandText, "//WPAT ") == true || EQAPP_String_BeginsWith(commandText, "//WPAddTarget ") == true)
        {
            std::string name = EQAPP_String_GetAfter(commandText, " ");
            if (name.size() != 0)
            {
                EQAPP_Waypoint_AddAtTarget(name.c_str());
            }

            return true;
        }

        if (commandText == "//WPATC" || commandText == "//WPAddTargetConnect")
        {
            EQAPP_Waypoint_AddAtTargetAndConnectToLastAddedIndex();

            return true;
        }

        if (commandText == "//WPABT" || commandText == "//WPAddBehindTarget")
        {
            EQAPP_Waypoint_AddBehindTarget("");

            return true;
        }

        // //WPAddBehindTarget <name>
        if (EQAPP_String_BeginsWith(commandText, "//WPABT ") == true || EQAPP_String_BeginsWith(commandText, "//WPAddBehindTarget ") == true)
        {
            std::string name = EQAPP_String_GetAfter(commandText, " ");
            if (name.size() != 0)
            {
                EQAPP_Waypoint_AddBehindTarget(name.c_str());
            }

            return true;
        }

        if (commandText == "//WPABTC" || commandText == "//WPAddBehindTargetConnect")
        {
            EQAPP_Waypoint_AddBehindTargetAndConnectToLastAddedIndex();

            return true;
        }

        // //WPAddTargetBetween <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPATB ") == true || EQAPP_String_BeginsWith(commandText, "//WPAddTargetBetween ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_AddAtTargetBetween(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPRemove <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPR ") == true || EQAPP_String_BeginsWith(commandText, "//WPRemove ") == true)
        {
            std::string indexText = EQAPP_String_GetAfter(commandText, " ");
            if (indexText.size() != 0)
            {
                if (EQAPP_String_IsDigits(indexText) == true)
                {
                    uint32_t index = std::stoul(indexText);

                    EQAPP_Waypoint_Remove(index);
                }
            }

            return true;
        }

        // //WPConnect <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPC ") == true || EQAPP_String_BeginsWith(commandText, "//WPConnect ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Connect(fromIndex, toIndex, false);
                    }
                }
            }

            return true;
        }

        // //WPConnect1 <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPC1 ") == true || EQAPP_String_BeginsWith(commandText, "//WPConnect1 ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Connect(fromIndex, toIndex, true);
                    }
                }
            }

            return true;
        }

        // //WPDisconnect <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPD ") == true || EQAPP_String_BeginsWith(commandText, "//WPDisconnect ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Disconnect(fromIndex, toIndex, false);
                    }
                }
            }

            return true;
        }

        // //WPDisconnectAll <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPDA ") == true || EQAPP_String_BeginsWith(commandText, "//WPDisconnectAll ") == true)
        {
            std::string indexText = EQAPP_String_GetAfter(commandText, " ");
            if (indexText.size() != 0)
            {
                if (EQAPP_String_IsDigits(indexText) == true)
                {
                    uint32_t index = std::stoul(indexText);

                    EQAPP_Waypoint_DisconnectAll(index);
                }
            }

            return true;
        }

        // //WPDisconnect1 <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPD1 ") == true || EQAPP_String_BeginsWith(commandText, "//WPDisconnect1 ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Disconnect(fromIndex, toIndex, true);
                    }
                }
            }

            return true;
        }

        // //WPName <index>,<name>
        if (EQAPP_String_BeginsWith(commandText, "//WPN ") == true || EQAPP_String_BeginsWith(commandText, "//WPName ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));

                        std::string name = tokens.at(1);
                        if (name.size() != 0)
                        {
                            auto waypoint = EQAPP_Waypoint_GetByIndex(index);
                            if (waypoint != NULL)
                            {
                                EQAPP_Waypoint_SetName(index, name.c_str());
                            }
                        }
                    }
                }
            }

            return true;
        }

        // //WPScriptFileName <index>,<name>
        if (EQAPP_String_BeginsWith(commandText, "//WPSF ") == true || EQAPP_String_BeginsWith(commandText, "//WPScriptFileName ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));

                        auto waypoint = EQAPP_Waypoint_GetByIndex(index);
                        if (waypoint != NULL)
                        {
                            std::string scriptFileName = tokens.at(1);
                            if (scriptFileName.size() != 0)
                            {
                                EQAPP_Waypoint_SetScriptFileName(index, scriptFileName.c_str());
                            }
                        }
                    }
                }
            }

            return true;
        }

        // //WPDisconnectAll <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPDA ") == true || EQAPP_String_BeginsWith(commandText, "//WPDisconnectAll ") == true)
        {
            std::string indexText = EQAPP_String_GetAfter(commandText, " ");
            if (indexText.size() != 0)
            {
                if (EQAPP_String_IsDigits(indexText) == true)
                {
                    uint32_t index = std::stoul(indexText);

                    EQAPP_Waypoint_DisconnectAll(index);
                }
            }

            return true;
        }

        // //WPAddFlag <index>,<flag>
        if (EQAPP_String_BeginsWith(commandText, "//WPAF ") == true || EQAPP_String_BeginsWith(commandText, "//WPAddFlag ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)))
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        uint32_t flag = EQ_StringMap_GetKeyByValue(EQApp::WaypointFlagsStrings, tokens.at(1));

                        if (flag != EQApp::WaypointFlagNull)
                        {
                            EQAPP_Waypoint_AddFlag(index, flag);
                        }
                    }
                }
            }

            return true;
        }

        // //WPRemoveFlag <index>,<flag>
        if (EQAPP_String_BeginsWith(commandText, "//WPRF ") == true || EQAPP_String_BeginsWith(commandText, "//WPRemoveFlag ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        uint32_t flag = EQ_StringMap_GetKeyByValue(EQApp::WaypointFlagsStrings, tokens.at(1));

                        if (flag != EQApp::WaypointFlagNull)
                        {
                            EQAPP_Waypoint_RemoveFlag(index, flag);
                        }
                    }
                }
            }

            return true;
        }

        // //WPClearFlags <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPCF ") == true || EQAPP_String_BeginsWith(commandText, "//WPClearFlags ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
                {
                    uint32_t index = std::stoul(commandTextAfterSpace);

                    EQAPP_Waypoint_ClearFlags(index);
                }
            }

            return true;
        }

        // //WPAlign <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPAL ") == true || EQAPP_String_BeginsWith(commandText, "//WPAlign ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Align(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPAlignY <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPALY ") == true || EQAPP_String_BeginsWith(commandText, "//WPAlignY ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_AlignY(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPAlignX <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPALX ") == true || EQAPP_String_BeginsWith(commandText, "//WPAlignX ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_AlignX(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPAlignZ <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPALZ ") == true || EQAPP_String_BeginsWith(commandText, "//WPAlignZ ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_AlignZ(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPSplit <from index>,<to index>
        if (EQAPP_String_BeginsWith(commandText, "//WPSplit ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                    {
                        uint32_t fromIndex = std::stoul(tokens.at(0));
                        uint32_t toIndex = std::stoul(tokens.at(1));

                        EQAPP_Waypoint_Split(fromIndex, toIndex);
                    }
                }
            }

            return true;
        }

        // //WPPush <index,distance>
        if (EQAPP_String_BeginsWith(commandText, "//WPPush ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        float distance = std::stof(tokens.at(1));

                        EQAPP_Waypoint_PushAwayFromPlayer(index, distance, false);
                    }
                }
            }

            return true;
        }

        // //WPPushRounded <index,distance>
        if (EQAPP_String_BeginsWith(commandText, "//WPPushR ") == true || EQAPP_String_BeginsWith(commandText, "//WPPushRounded ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        float distance = std::stof(tokens.at(1));

                        EQAPP_Waypoint_PushAwayFromPlayer(index, distance, true);
                    }
                }
            }

            return true;
        }

        // //WPPullRounded <index,distance>
        if (EQAPP_String_BeginsWith(commandText, "//WPPullR ") == true || EQAPP_String_BeginsWith(commandText, "//WPPullRounded ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        float distance = std::stof(tokens.at(1));

                        EQAPP_Waypoint_PullTowardsPlayer(index, distance, true);
                    }
                }
            }

            return true;
        }

        // //WPMoveToPlayer <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPMTP ") == true || EQAPP_String_BeginsWith(commandText, "//WPMoveToPlayer ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
                {
                    uint32_t index = std::stoul(commandTextAfterSpace);

                    EQAPP_Waypoint_MoveToPlayer(index);
                }
            }

            return true;
        }

        // //WPMoveToTarget <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPMTT ") == true || EQAPP_String_BeginsWith(commandText, "//WPMoveToTarget ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
                {
                    uint32_t index = std::stoul(commandTextAfterSpace);

                    EQAPP_Waypoint_MoveToTarget(index);
                }
            }

            return true;
        }

        // //WPMoveTo <index>
        if (EQAPP_String_BeginsWith(commandText, "//WPMT ") == true || EQAPP_String_BeginsWith(commandText, "//WPMoveTo ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 4)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));

                        float y = std::stof(tokens.at(1));
                        float x = std::stof(tokens.at(2));
                        float z = std::stof(tokens.at(3));

                        EQAPP_Waypoint_MoveToLocation(index, y, x, z);
                    }
                }
            }

            return true;
        }

        // //WPMoveUp <index>,<distance>
        if (EQAPP_String_BeginsWith(commandText, "//WPMU ") == true || EQAPP_String_BeginsWith(commandText, "//WPMoveUp ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        float distance = std::stof(tokens.at(1));

                        EQAPP_Waypoint_MoveUp(index, distance);
                    }
                }
            }

            return true;
        }

        // //WPMoveDown <index>,<distance>
        if (EQAPP_String_BeginsWith(commandText, "//WPMD ") == true || EQAPP_String_BeginsWith(commandText, "//WPMoveDown ") == true)
        {
            std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
            if (commandTextAfterSpace.size() != 0)
            {
                std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
                if (tokens.size() == 2)
                {
                    if (EQAPP_String_IsDigits(tokens.at(0)) == true)
                    {
                        uint32_t index = std::stoul(tokens.at(0));
                        float distance = std::stof(tokens.at(1));

                        EQAPP_Waypoint_MoveDown(index, distance);
                    }
                }
            }

            return true;
        }

    } // if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)

    /********** END OF WAYPOINT EDITOR **********/

    // //WPGetPath <from index>,<to index>
    if (EQAPP_String_BeginsWith(commandText, "//WPGP ") == true || EQAPP_String_BeginsWith(commandText, "//WPGetPath ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                {
                    uint32_t fromIndex = std::stoul(tokens.at(0));
                    uint32_t toIndex = std::stoul(tokens.at(1));

                    g_WaypointGetPathIndexList = EQAPP_Waypoint_GetPathList(fromIndex, toIndex);
                    if (g_WaypointGetPathIndexList.size() != 0)
                    {
                        EQAPP_Waypoint_PrintPathList(g_WaypointGetPathIndexList, fromIndex);
                    }
                }
            }
        }

        return true;
    }

    // //WPFollowPath <from index>,<to index>
    if (EQAPP_String_BeginsWith(commandText, "//WPFP ") == true || EQAPP_String_BeginsWith(commandText, "//WPFollowPath ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                {
                    uint32_t fromIndex = std::stoul(tokens.at(0));
                    uint32_t toIndex = std::stoul(tokens.at(1));

                    EQAPP_Waypoint_FollowPath(fromIndex, toIndex);
                }
            }
        }

        return true;
    }

    if (commandText == "//WPFP" || commandText == "//WPFollowPath")
    {
        EQAPP_Waypoint_FollowPath_Toggle();

        return true;
    }

    if (commandText == "//WPIW" || commandText == "//WPIgnoreWait")
    {
        EQAPP_Waypoint_IgnoreWait_Toggle();

        return true;
    }

    if (commandText == "//WPIM" || commandText == "//WPIgnoreMovement")
    {
        EQAPP_Waypoint_IgnoreMovement_Toggle();

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//WPGoto ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t toIndex = std::stoul(commandTextAfterSpace);

                EQAPP_Waypoint_Goto(toIndex);
            }
            else
            {
                EQAPP_Waypoint_GotoByName(commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//WPGotoSpawn ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_Waypoint_GotoBySpawnName(commandTextAfterSpace.c_str());
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//WPGotoRandom ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() != 0)
            {
                bool isDigits = false;

                for (auto& token : tokens)
                {
                    if (EQAPP_String_IsDigits(token) == true)
                    {
                        isDigits = true;
                        break;
                    }
                }

                auto tokenIndex = EQAPP_GetRandomNumber(0, tokens.size() - 1);

                if (isDigits == true)
                {
                    auto waypointIndex = std::stoul(tokens.at(tokenIndex));

                    EQAPP_Waypoint_Goto(waypointIndex);
                }
                else
                {
                    EQAPP_Waypoint_GotoByName(tokens.at(tokenIndex).c_str());
                }
            }
        }

        return true;
    }

    // //WPGetSlope <from index>,<to index>
    if (EQAPP_String_BeginsWith(commandText, "//WPGetSlope ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ',');
            if (tokens.size() == 2)
            {
                if (EQAPP_String_IsDigits(tokens.at(0)) == true && EQAPP_String_IsDigits(tokens.at(1)) == true)
                {
                    uint32_t fromIndex = std::stoul(tokens.at(0));
                    uint32_t toIndex = std::stoul(tokens.at(1));

                    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
                    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
                    if (fromWaypoint != NULL && toIndex != NULL)
                    {
                        float slope = EQ_GetLineSlope(fromWaypoint->Y, fromWaypoint->X, toWaypoint->Y, toWaypoint->X);

                        std::cout << "Slope: " << slope << std::endl;

                        if (std::isinf(slope) == true)
                        {
                            std::cout << "Slope is vertical (North <-> South)" << std::endl;
                        }
                        else if (slope == 0 || slope == -0)
                        {
                            std::cout << "Slope is horizontal (West <-> East)" << std::endl;
                        }
                        else if (slope < 0 || slope == -1)
                        {
                            std::cout << "Slope is diagonal (South West <-> North East)" << std::endl;
                        }
                        else if (slope > 0|| slope == 1)
                        {
                            std::cout << "Slope is diagonal (North West <-> South East)" << std::endl;
                        }
                    }
                }
            }
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

    if (commandText == "//ChangePlayerLight")
    {
        EQ_ChangePlayerLight();

        return true;
    }

    if (commandText == "//UpdateLight")
    {
        auto character = EQ_GetCharacter();
        if (character != NULL)
        {
            EQ_FUNCTION_UpdateLight(character);
        }

        return true;
    }

    if (commandText == "//CreateLight")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            if (EQ_GetSpawnLightInterface(playerSpawn) == NULL)
            {
                float playerY = EQ_GetSpawnY(playerSpawn);
                float playerX = EQ_GetSpawnX(playerSpawn);
                float playerZ = EQ_GetSpawnZ(playerSpawn);

                uint32_t light = EQ_CLASS_POINTER_CDisplay->CreateLight(EQ_LIGHT_TYPE_GLOOMING_DEEP_LANTERN, 0.0f, playerY, playerX, playerZ + 4.0f);

                EQ_SetPlayerLightInterface(light);
            }
        }

        return true;
    }

    if (commandText == "//GroundOn" || commandText == "//Ground")
    {
        EQAPP_Cheat_Levitate_Off();
        EQAPP_Cheat_Fly_Off();

        EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_GROUND);

        return true;
    }

    return false;
}
