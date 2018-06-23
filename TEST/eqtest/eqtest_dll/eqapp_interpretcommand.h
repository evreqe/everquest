#pragma once

#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autoalternateability.h"
#include "eqapp_autogroup.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_combatalternateability.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_esp.h"
#include "eqapp_followai.h"
#include "eqapp_followpath.h"
#include "eqapp_fps.h"
#include "eqapp_hud.h"
#include "eqapp_loadoptions.h"
#include "eqapp_lua.h"
#include "eqapp_namedspawns.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_speed.h"
#include "eqapp_spelllist.h"
#include "eqapp_windowtitle.h"
#include "eqapp_waypoint.h"

bool g_InterpretCommandIsEnabled = true;

std::list<std::string> g_InterpretCommandQueue;

EQApp::Timer g_InterpretCommandQueueTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_InterpretCommandQueueTimerInterval = 1;

void EQAPP_InterpretCommand_NULL();

void EQAPP_InterpretCommand_NULL()
{
    return;
}

std::map<std::string, std::function<void()>> g_InterpretCommandList =
{
    {"//Unload",                       &EQAPP_Unload},
    {"//LoadOptions",                  &EQAPP_LoadOptions},
    {"//DebugText",                    &EQAPP_ToggleDebugText},
    {"//Sleep",                        &EQAPP_Sleep_Toggle},
    {"//SleepOn",                      &EQAPP_Sleep_On},
    {"//SleepOff",                     &EQAPP_Sleep_Off},
    {"//ActorCollision",               &EQAPP_ActorCollision_Toggle},
    {"//ActorCollisionOn",             &EQAPP_ActorCollision_On},
    {"//ActorCollisionOff",            &EQAPP_ActorCollision_Off},
    {"//LoadActorCollision",           &EQAPP_ActorCollision_Load},
    {"//AC",                           &EQAPP_ActorCollision_Toggle},
    {"//ACOn",                         &EQAPP_ActorCollision_On},
    {"//ACOff",                        &EQAPP_ActorCollision_Off},
    {"//ACLoad",                       &EQAPP_ActorCollision_Load},
    {"//ActorCollisionDebug",          &EQAPP_ActorCollision_Debug_Toggle},
    {"//ACDebug",                      &EQAPP_ActorCollision_Debug_Toggle},
    {"//ActorCollisionAll",            &EQAPP_ActorCollision_All_Toggle},
    {"//ACAll",                        &EQAPP_ActorCollision_All_Toggle},
    {"//ActorCollisionPlayer",         &EQAPP_ActorCollision_Player_Toggle},
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
    {"//AutoAlternateAbility",         &EQAPP_AutoAlternateAbility_Toggle},
    {"//AutoAlternateAbilityOn",       &EQAPP_AutoAlternateAbility_On},
    {"//AutoAlternateAbilityOff",      &EQAPP_AutoAlternateAbility_Off},
    {"//AAA",                          &EQAPP_AutoAlternateAbility_Toggle},
    {"//AAAOn",                        &EQAPP_AutoAlternateAbility_On},
    {"//AAAOff",                       &EQAPP_AutoAlternateAbility_Off},
    {"//AutoGroup",                    &EQAPP_AutoGroup_Toggle},
    {"//AutoGroupOn",                  &EQAPP_AutoGroup_On},
    {"//AutoGroupOff",                 &EQAPP_AutoGroup_Off},
    {"//AG",                           &EQAPP_AutoGroup_Toggle},
    {"//AGOn",                         &EQAPP_AutoGroup_On},
    {"//AGOff",                        &EQAPP_AutoGroup_Off},
    {"//BazaarBot",                    &EQAPP_BazaarBot_Toggle},
    {"//BazaarBotOn",                  &EQAPP_BazaarBot_On},
    {"//BazaarBotOff",                 &EQAPP_BazaarBot_Off},
    {"//BB",                           &EQAPP_BazaarBot_Toggle},
    {"//BBOn",                         &EQAPP_BazaarBot_On},
    {"//BBOff",                        &EQAPP_BazaarBot_Off},
    {"//LoadBazaarFilter",             &EQAPP_BazaarFilter_Load},
    {"//BFLoad",                       &EQAPP_BazaarFilter_Load},
    {"//BazaarFilter",                 &EQAPP_BazaarFilter_Toggle},
    {"//BazaarFilterOn",               &EQAPP_BazaarFilter_On},
    {"//BazaarFilterOff",              &EQAPP_BazaarFilter_Off},
    {"//BF",                           &EQAPP_BazaarFilter_Toggle},
    {"//BFOn",                         &EQAPP_BazaarFilter_On},
    {"//BFOff",                        &EQAPP_BazaarFilter_Off},
    {"//BazaarFilterBeep",             &EQAPP_BazaarFilter_Beep_Toggle},
    {"//BFBeep",                       &EQAPP_BazaarFilter_Beep_Toggle},
    {"//BazaarFilterList",             &EQAPP_BazaarFilter_PrintItemNameList},
    {"//BFList",                       &EQAPP_BazaarFilter_PrintItemNameList},
    {"//BoxChat",                      &EQAPP_BoxChat_Toggle},
    {"//BoxChatOn",                    &EQAPP_BoxChat_On},
    {"//BoxChatOff",                   &EQAPP_BoxChat_Off},
    {"//BC",                           &EQAPP_BoxChat_Toggle},
    {"//BCOn",                         &EQAPP_BoxChat_On},
    {"//BCOff",                        &EQAPP_BoxChat_Off},
    {"//BoxChatAutoConnect",           &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//BCAC",                         &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//CombatAlternateAbility",       &EQAPP_CombatAlternateAbility_Toggle},
    {"//CombatAlternateAbilityOn",     &EQAPP_CombatAlternateAbility_On},
    {"//CombatAlternateAbilityOff",    &EQAPP_CombatAlternateAbility_Off},
    {"//CAA",                          &EQAPP_CombatAlternateAbility_Toggle},
    {"//CAAOn",                        &EQAPP_CombatAlternateAbility_On},
    {"//CAAOff",                       &EQAPP_CombatAlternateAbility_Off},
    {"//ConsolePrint",                 &EQAPP_Console_Print_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
    {"//ESPOn",                        &EQAPP_ESP_On},
    {"//ESPOff",                       &EQAPP_ESP_Off},
    {"//ESPHeightFilter",              &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPHF",                        &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPShowSpawnID",               &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ESPID",                        &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ESPShowSpawnRace",             &EQAPP_ESP_ShowSpawnRace_Toggle},
    {"//ESPRace",                      &EQAPP_ESP_ShowSpawnRace_Toggle},
    {"//ESPShowSpawnClass",            &EQAPP_ESP_ShowSpawnClass_Toggle},
    {"//ESPClass",                     &EQAPP_ESP_ShowSpawnClass_Toggle},
    {"//ESPShowDoors",                 &EQAPP_ESP_ShowDoors_Toggle},
    {"//ESPDoors",                     &EQAPP_ESP_ShowDoors_Toggle},
    {"//FPS",                          &EQAPP_FPS_Toggle},
    {"//FPSOn",                        &EQAPP_FPS_On},
    {"//FPSOff",                       &EQAPP_FPS_Off},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    {"//ChangeHeightOn",               &EQAPP_ChangeHeight_On},
    {"//ChangeHeightOff",              &EQAPP_ChangeHeight_Off},
    {"//CH",                           &EQAPP_ChangeHeight_Toggle},
    {"//CHOn",                         &EQAPP_ChangeHeight_On},
    {"//CHOff",                        &EQAPP_ChangeHeight_Off},
    {"//LoadSpellList",                &EQAPP_SpellList_Load},
    {"//SLLoad",                       &EQAPP_SpellList_Load},
    {"//SpawnCastSpell",               &EQAPP_SpawnCastSpell_Toggle},
    {"//SpawnCastSpellOn",             &EQAPP_SpawnCastSpell_On},
    {"//SpawnCastSpellOff",            &EQAPP_SpawnCastSpell_Off},
    {"//SCS",                          &EQAPP_SpawnCastSpell_Toggle},
    {"//SCSOn",                        &EQAPP_SpawnCastSpell_On},
    {"//SCSOff",                       &EQAPP_SpawnCastSpell_Off},
    {"//SpawnCastSpellESP",            &EQAPP_SpawnCastSpell_ESP_Toggle},
    {"//SCSESP",                       &EQAPP_SpawnCastSpell_ESP_Toggle},
    {"//SpawnCastSpellGroupChat",      &EQAPP_SpawnCastSpell_GroupChat_Toggle},
    {"//SCSGroupChat",                 &EQAPP_SpawnCastSpell_GroupChat_Toggle},
    {"//Speed",                        &EQAPP_Speed_Toggle},
    {"//SpeedOn",                      &EQAPP_Speed_On},
    {"//SpeedOff",                     &EQAPP_Speed_Off},
    {"//HUD",                          &EQAPP_HUD_Toggle},
    {"//HUDOn",                        &EQAPP_HUD_On},
    {"//HUDOff",                       &EQAPP_HUD_Off},
    {"//HUDDebugText",                 &EQAPP_HUD_DebugText_Toggle},
    {"//FollowAI",                     &EQAPP_FollowAI_Toggle},
    {"//FollowAIOn",                   &EQAPP_FollowAI_On},
    {"//FollowAIOff",                  &EQAPP_FollowAI_Off},
    {"//FAI",                          &EQAPP_FollowAI_Toggle},
    {"//FAIOn",                        &EQAPP_FollowAI_On},
    {"//FAIOff",                       &EQAPP_FollowAI_Off},
    {"//FollowAIUseZAxis",             &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FAIUseZAxis",                  &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FZ",                           &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FollowAIBehind",               &EQAPP_FollowAI_Behind_Toggle},
    {"//FAIBehind",                    &EQAPP_FollowAI_Behind_Toggle},
    {"//FB",                           &EQAPP_FollowAI_Behind_Toggle},
    {"//FollowPath",                   &EQAPP_FollowPath_Toggle},
    {"//FollowPathOn",                 &EQAPP_FollowPath_On},
    {"//FollowPathOff",                &EQAPP_FollowPath_Off},
    {"//FP",                           &EQAPP_FollowPath_Toggle},
    {"//FPOn",                         &EQAPP_FollowPath_On},
    {"//FPOff",                        &EQAPP_FollowPath_Off},
    {"//FollowPathAutomatic",          &EQAPP_FollowPath_Automatic_Toggle},
    {"//FPAutomatic",                  &EQAPP_FollowPath_Automatic_Toggle},
    {"//WindowTitle",                  &EQAPP_WindowTitle_Toggle},
    {"//WindowTitleOn",                &EQAPP_WindowTitle_On},
    {"//WindowTitleOff",               &EQAPP_WindowTitle_Off},
    {"//WT",                           &EQAPP_WindowTitle_Toggle},
    {"//WTOn",                         &EQAPP_WindowTitle_On},
    {"//WTOff",                        &EQAPP_WindowTitle_Off},
    {"//Lua",                          &EQAPP_Lua_Toggle},
    {"//LuaOn",                        &EQAPP_Lua_On},
    {"//LuaOff",                       &EQAPP_Lua_Off},
    {"//LuaResetTimers",               &EQAPP_Lua_ResetTimers},
    {"//FreeCamera",                   &EQAPP_FreeCamera_Toggle},
    {"//FreeCameraOn",                 &EQAPP_FreeCamera_On},
    {"//FreeCameraOff",                &EQAPP_FreeCamera_Off},
    {"//FC",                           &EQAPP_FreeCamera_Toggle},
    {"//FCOn",                         &EQAPP_FreeCamera_On},
    {"//FCOff",                        &EQAPP_FreeCamera_Off},
    {"//OpenAllDoors",                 &EQ_OpenAllDoors},
    {"//CloseAllDoors",                &EQ_CloseAllDoors},
    {"//LoadWaypoints",                &EQAPP_WaypointList_Load},
    {"//SaveWaypoints",                &EQAPP_WaypointList_Save},
    {"//PrintWaypoints",               &EQAPP_WaypointList_Print},
    {"//ClearWaypoints",               &EQAPP_WaypointList_Clear},
    {"//WPLoad",                       &EQAPP_WaypointList_Load},
    {"//WPSave",                       &EQAPP_WaypointList_Save},
    {"//WPPrint",                      &EQAPP_WaypointList_Print},
    {"//WPClear",                      &EQAPP_WaypointList_Clear},
    {"//WPDebug",                      &EQAPP_Waypoint_Debug_Toggle},
    ////
    ////{"//Null",                         &EQAPP_InterpretCommand_NULL},
    ////
    {"//Test",                         &EQAPP_InterpretCommand_NULL},
    {"//TestChatTextColors",           &EQAPP_InterpretCommand_NULL},
    {"//Pause",                        &EQAPP_InterpretCommand_NULL},
    {"//InGame",                       &EQAPP_InterpretCommand_NULL},
    {"//NotInGame",                    &EQAPP_InterpretCommand_NULL},
    {"//Beep",                         &EQAPP_InterpretCommand_NULL},
    {"//BeepEx",                       &EQAPP_InterpretCommand_NULL},
    {"//PlaySound",                    &EQAPP_InterpretCommand_NULL},
    {"//PlaySoundEx",                  &EQAPP_InterpretCommand_NULL},
    {"//StopSound",                    &EQAPP_InterpretCommand_NULL},
    {"//StopSoundEx",                  &EQAPP_InterpretCommand_NULL},
    {"//TaskAccept",                   &EQAPP_InterpretCommand_NULL},
    {"//TaskDecline",                  &EQAPP_InterpretCommand_NULL},
    {"//BazaarListCount",              &EQAPP_InterpretCommand_NULL},
    {"//BazaarListIndex",              &EQAPP_InterpretCommand_NULL},
    {"//BazaarPrintList",              &EQAPP_InterpretCommand_NULL},
    {"//BazaarDoQuery",                &EQAPP_InterpretCommand_NULL},
    {"//BazaarFindItems",              &EQAPP_InterpretCommand_NULL},
    {"//BazaarUpdateTraders",          &EQAPP_InterpretCommand_NULL},
    {"//BazaarReset",                  &EQAPP_InterpretCommand_NULL},
    {"//BazaarBuy",                    &EQAPP_InterpretCommand_NULL},
    {"//BazaarToParcels",              &EQAPP_InterpretCommand_NULL},
    {"//BazaarBeginTrader",            &EQAPP_InterpretCommand_NULL},
    {"//BazaarEndTrader",              &EQAPP_InterpretCommand_NULL},
    {"//Screencap",                    &EQAPP_InterpretCommand_NULL},
    {"//Screenshot",                   &EQAPP_InterpretCommand_NULL},
    {"//TakeScreenshot",               &EQAPP_InterpretCommand_NULL},
    {"//Campfire",                     &EQAPP_InterpretCommand_NULL},
    {"//Stein",                        &EQAPP_InterpretCommand_NULL},
    {"//Origin",                       &EQAPP_InterpretCommand_NULL},
    {"//Gate",                         &EQAPP_InterpretCommand_NULL},
    {"//MassGroupBuff",                &EQAPP_InterpretCommand_NULL},
    {"//MGB",                          &EQAPP_InterpretCommand_NULL},
    {"//TranquilBlessings",            &EQAPP_InterpretCommand_NULL},
    {"//MGB2",                         &EQAPP_InterpretCommand_NULL},
    {"//ThroneOfHeroes",               &EQAPP_InterpretCommand_NULL},
    {"//GuildLobby",                   &EQAPP_InterpretCommand_NULL},
    {"//GL",                           &EQAPP_InterpretCommand_NULL},
    {"//HarmonicDissonance",           &EQAPP_InterpretCommand_NULL},
    {"//TheaterOfBlood",               &EQAPP_InterpretCommand_NULL},
    {"//BindAffinity",                 &EQAPP_InterpretCommand_NULL},
    {"//Identify",                     &EQAPP_InterpretCommand_NULL},
    {"//LessonOfTheDevoted",           &EQAPP_InterpretCommand_NULL},
    {"//LOTD",                         &EQAPP_InterpretCommand_NULL},
    {"//ExpedientRecovery",            &EQAPP_InterpretCommand_NULL},
    {"//EXPR",                         &EQAPP_InterpretCommand_NULL},
    {"//ArmorOfExperience",            &EQAPP_InterpretCommand_NULL},
    {"//AOEXP",                        &EQAPP_InterpretCommand_NULL},
    {"//InfusionOfTheFaithful",        &EQAPP_InterpretCommand_NULL},
    {"//IOTF",                         &EQAPP_InterpretCommand_NULL},
    {"//IntensityOfTheResolute",       &EQAPP_InterpretCommand_NULL},
    {"//IOTR",                         &EQAPP_InterpretCommand_NULL},
    {"//Banestrike",                   &EQAPP_InterpretCommand_NULL},
    {"//SteadfastServant",             &EQAPP_InterpretCommand_NULL},
    {"//ChaoticJester",                &EQAPP_InterpretCommand_NULL},
    {"//SummonClockworkBanker",        &EQAPP_InterpretCommand_NULL},
    {"//SCB",                          &EQAPP_InterpretCommand_NULL},
    {"//SummonPermutationPeddler",     &EQAPP_InterpretCommand_NULL},
    {"//SPP",                          &EQAPP_InterpretCommand_NULL},
    {"//SummonPersonalTributeMaster",  &EQAPP_InterpretCommand_NULL},
    {"//SPTM",                         &EQAPP_InterpretCommand_NULL},
    {"//SummonResupplyAgent",          &EQAPP_InterpretCommand_NULL},
    {"//SRA",                          &EQAPP_InterpretCommand_NULL},
    {"//AutoAttack",                   &EQAPP_InterpretCommand_NULL},
    {"//AutoAttackOn",                 &EQAPP_InterpretCommand_NULL},
    {"//AutoAttackOff",                &EQAPP_InterpretCommand_NULL},
    {"//AutoFire",                     &EQAPP_InterpretCommand_NULL},
    {"//AutoFireOn",                   &EQAPP_InterpretCommand_NULL},
    {"//AutoFireOff",                  &EQAPP_InterpretCommand_NULL},
    {"//AutoRun",                      &EQAPP_InterpretCommand_NULL},
    {"//AutoRunOn",                    &EQAPP_InterpretCommand_NULL},
    {"//AutoRunOff",                   &EQAPP_InterpretCommand_NULL},
    {"//AcceptInvite",                 &EQAPP_InterpretCommand_NULL},
    {"//JoinGroup",                    &EQAPP_InterpretCommand_NULL},
    {"//Disband",                      &EQAPP_InterpretCommand_NULL},
    {"//FieldOfView",                  &EQAPP_InterpretCommand_NULL},
    {"//FOV",                          &EQAPP_InterpretCommand_NULL},
    {"//FieldOfViewDefault",           &EQAPP_InterpretCommand_NULL},
    {"//FOVDefault",                   &EQAPP_InterpretCommand_NULL},
    {"//DrawDistance",                 &EQAPP_InterpretCommand_NULL},
    {"//FogOff",                       &EQAPP_InterpretCommand_NULL},
    {"//FogOn",                        &EQAPP_InterpretCommand_NULL},
    {"//FogDistanceBegin",             &EQAPP_InterpretCommand_NULL},
    {"//FogDistanceEnd",               &EQAPP_InterpretCommand_NULL},
    {"//ShrinkTarget",                 &EQAPP_InterpretCommand_NULL},
    {"//GrowTarget",                   &EQAPP_InterpretCommand_NULL},
    {"//ChangeTargetHeight",           &EQAPP_InterpretCommand_NULL},
    {"//FaceTargetHeading",            &EQAPP_InterpretCommand_NULL},
    {"//FaceTarget",                   &EQAPP_InterpretCommand_NULL},
    {"//TargetMe",                     &EQAPP_InterpretCommand_NULL},
    {"//TargetMyself",                 &EQAPP_InterpretCommand_NULL},
    {"//Target",                       &EQAPP_InterpretCommand_NULL},
    {"//TargetID",                     &EQAPP_InterpretCommand_NULL},
    {"//Follow",                       &EQAPP_InterpretCommand_NULL},
    {"//StopFollow",                   &EQAPP_InterpretCommand_NULL},
    {"//StopCast",                     &EQAPP_InterpretCommand_NULL},
    {"//StopSong",                     &EQAPP_InterpretCommand_NULL},
    {"//StopAction",                   &EQAPP_InterpretCommand_NULL},
    {"//ClearTarget",                  &EQAPP_InterpretCommand_NULL},
    {"//CloseTopWindow",               &EQAPP_InterpretCommand_NULL},
    {"//CloseAllTopWindows",           &EQAPP_InterpretCommand_NULL},
    {"//Hail",                         &EQAPP_InterpretCommand_NULL},
    {"//Camp",                         &EQAPP_InterpretCommand_NULL},
    {"//Use",                          &EQAPP_InterpretCommand_NULL},
    {"//Jump",                         &EQAPP_InterpretCommand_NULL},
    {"//Duck",                         &EQAPP_InterpretCommand_NULL},
    {"//Crouch",                       &EQAPP_InterpretCommand_NULL},
    {"//SitStand",                     &EQAPP_InterpretCommand_NULL},
    {"//Sit",                          &EQAPP_InterpretCommand_NULL},
    {"//Stand",                        &EQAPP_InterpretCommand_NULL},
    {"//RunWalk",                      &EQAPP_InterpretCommand_NULL},
    {"//ConfirmNo",                    &EQAPP_InterpretCommand_NULL},
    {"//ConfirmYes",                   &EQAPP_InterpretCommand_NULL},
    {"//PitchDown",                    &EQAPP_InterpretCommand_NULL},
    {"//LookDown",                     &EQAPP_InterpretCommand_NULL},
    {"//PitchUp",                      &EQAPP_InterpretCommand_NULL},
    {"//LookUp",                       &EQAPP_InterpretCommand_NULL},
    {"//CenterView",                   &EQAPP_InterpretCommand_NULL},
    {"//LookForward",                  &EQAPP_InterpretCommand_NULL},
    {"//FirstPersonCamera",            &EQAPP_InterpretCommand_NULL},
    {"//OverheadCamera",               &EQAPP_InterpretCommand_NULL},
    {"//ChaseCamera",                  &EQAPP_InterpretCommand_NULL},
    {"//User1Camera",                  &EQAPP_InterpretCommand_NULL},
    {"//ThirdPersonCamera1",           &EQAPP_InterpretCommand_NULL},
    {"//User2Camera",                  &EQAPP_InterpretCommand_NULL},
    {"//ThirdPersonCamera2",           &EQAPP_InterpretCommand_NULL},
    {"//ThirdPersonCamera",            &EQAPP_InterpretCommand_NULL},
    {"//TetherCamera",                 &EQAPP_InterpretCommand_NULL},
    {"//OpenBags",                     &EQAPP_InterpretCommand_NULL},
    {"//CloseBags",                    &EQAPP_InterpretCommand_NULL},
    {"//InspectBuffs",                 &EQAPP_InterpretCommand_NULL},
    {"//Consider",                     &EQAPP_InterpretCommand_NULL},
    {"//Party1",                       &EQAPP_InterpretCommand_NULL},
    {"//Group1",                       &EQAPP_InterpretCommand_NULL},
    {"//HotButton1",                   &EQAPP_InterpretCommand_NULL},
    {"//HotButton1_1",                 &EQAPP_InterpretCommand_NULL},
    {"//Discipline1",                  &EQAPP_InterpretCommand_NULL},
    {"//XTargetCycle",                 &EQAPP_InterpretCommand_NULL},
    {"//XTarget1",                     &EQAPP_InterpretCommand_NULL},
    {"//UseItemCharm",                 &EQAPP_InterpretCommand_NULL},
    {"//UseItemLeftEar",               &EQAPP_InterpretCommand_NULL},
    {"//UseItemHead",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemFace",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemRightEar",              &EQAPP_InterpretCommand_NULL},
    {"//UseItemNeck",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemShoulders",             &EQAPP_InterpretCommand_NULL},
    {"//UseItemArms",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemBack",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemLeftWrist",             &EQAPP_InterpretCommand_NULL},
    {"//UseItemLeftEar",               &EQAPP_InterpretCommand_NULL},
    {"//UseItemRightWrist",            &EQAPP_InterpretCommand_NULL},
    {"//UseItemRange",                 &EQAPP_InterpretCommand_NULL},
    {"//UseItemHands",                 &EQAPP_InterpretCommand_NULL},
    {"//UseItemPrimary",               &EQAPP_InterpretCommand_NULL},
    {"//UseItemSecondary",             &EQAPP_InterpretCommand_NULL},
    {"//UseItemLeftRing",              &EQAPP_InterpretCommand_NULL},
    {"//UseItemRightRing",             &EQAPP_InterpretCommand_NULL},
    {"//UseItemChest",                 &EQAPP_InterpretCommand_NULL},
    {"//UseItemLegs",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemFeet",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemWaist",                 &EQAPP_InterpretCommand_NULL},
    {"//UseItemPowerSource",           &EQAPP_InterpretCommand_NULL},
    {"//UseItemAmmo",                  &EQAPP_InterpretCommand_NULL},
    {"//UseItemBag1_1",                &EQAPP_InterpretCommand_NULL},
    {"//ESPFindName",                  &EQAPP_InterpretCommand_NULL},
    {"//ESPFindLastName",              &EQAPP_InterpretCommand_NULL},
    {"//ESPFindType",                  &EQAPP_InterpretCommand_NULL},
    {"//ESPFindTypePlayer",            &EQAPP_InterpretCommand_NULL},
    {"//ESPFindTypeNPC",               &EQAPP_InterpretCommand_NULL},
    {"//ESPFindTypeCorpse",            &EQAPP_InterpretCommand_NULL},
    {"//ESPFindLevel",                 &EQAPP_InterpretCommand_NULL},
    {"//ESPFindRace",                  &EQAPP_InterpretCommand_NULL},
    {"//ESPFindClass",                 &EQAPP_InterpretCommand_NULL},
    {"//ESPFindClassBanker",           &EQAPP_InterpretCommand_NULL},
    {"//ESPFindClassMerchant",         &EQAPP_InterpretCommand_NULL},
    {"//ESPFindClassObject",           &EQAPP_InterpretCommand_NULL},
    {"//Multiline",                    &EQAPP_InterpretCommand_NULL},
    {"//MultilineRandom",              &EQAPP_InterpretCommand_NULL},
    {"//Cast",                         &EQAPP_InterpretCommand_NULL},
    {"//CastRandom",                   &EQAPP_InterpretCommand_NULL},
    {"//DoAbility",                    &EQAPP_InterpretCommand_NULL},
    {"//DoAbilityRandom",              &EQAPP_InterpretCommand_NULL},
    {"//Discipline",                   &EQAPP_InterpretCommand_NULL},
    {"//DisciplineRandom",             &EQAPP_InterpretCommand_NULL},
    {"//AltActivate",                  &EQAPP_InterpretCommand_NULL},
    {"//AltActivateRandom",            &EQAPP_InterpretCommand_NULL},
    {"//BoxChatConnect",               &EQAPP_InterpretCommand_NULL},
    {"//BCC",                          &EQAPP_InterpretCommand_NULL},
    {"//BoxChatDisconnect",            &EQAPP_InterpretCommand_NULL},
    {"//BCD",                          &EQAPP_InterpretCommand_NULL},
    {"//BoxChatStatus",                &EQAPP_InterpretCommand_NULL},
    {"//BCS",                          &EQAPP_InterpretCommand_NULL},
    {"//BoxChatSetChannel",            &EQAPP_InterpretCommand_NULL},
    {"//BCSC",                         &EQAPP_InterpretCommand_NULL},
    {"//BoxChatTell",                  &EQAPP_InterpretCommand_NULL},
    {"//BCT",                          &EQAPP_InterpretCommand_NULL},
    {"//BoxChatTellChannel",           &EQAPP_InterpretCommand_NULL},
    {"//BCTC",                         &EQAPP_InterpretCommand_NULL},
    {"//BoxChatTellGroup",             &EQAPP_InterpretCommand_NULL},
    {"//BCTG",                         &EQAPP_InterpretCommand_NULL},
    {"//BoxChatOthers",                &EQAPP_InterpretCommand_NULL},
    {"//BCA",                          &EQAPP_InterpretCommand_NULL},
    {"//BoxChatAll",                   &EQAPP_InterpretCommand_NULL},
    {"//BCAA",                         &EQAPP_InterpretCommand_NULL},
    {"//SpawnList",                    &EQAPP_InterpretCommand_NULL},
    {"//Location",                     &EQAPP_InterpretCommand_NULL},
    {"//Loc",                          &EQAPP_InterpretCommand_NULL},
    {"//MouseLocation",                &EQAPP_InterpretCommand_NULL},
    {"//MouseLoc",                     &EQAPP_InterpretCommand_NULL},
    {"//NearbyNPC",                    &EQAPP_InterpretCommand_NULL},
    {"//Melody",                       &EQAPP_InterpretCommand_NULL},
    {"//ScriptFolder",                 &EQAPP_InterpretCommand_NULL},
    {"//Scripts",                      &EQAPP_InterpretCommand_NULL},
    {"//Script",                       &EQAPP_InterpretCommand_NULL},
    {"//LoadScripts",                  &EQAPP_InterpretCommand_NULL},
    {"//LoadEventScriptList",          &EQAPP_InterpretCommand_NULL},
    {"//LoadEventScripts",             &EQAPP_InterpretCommand_NULL},
    {"//EventScriptList",              &EQAPP_InterpretCommand_NULL},
    {"//Lua",                          &EQAPP_InterpretCommand_NULL},
    {"//LuaEvent",                     &EQAPP_InterpretCommand_NULL},
    {"//Echo",                         &EQAPP_InterpretCommand_NULL},
    {"//ItemSlotPrimary",              &EQAPP_InterpretCommand_NULL},
    {"//ItemSlotSecondary",            &EQAPP_InterpretCommand_NULL},
    {"//ItemSlotHead",                 &EQAPP_InterpretCommand_NULL},
    {"//IfMoving",                     &EQAPP_InterpretCommand_NULL},
    {"//IfNotMoving",                  &EQAPP_InterpretCommand_NULL},
    {"//UseDoor",                      &EQAPP_InterpretCommand_NULL},
    {"//InventoryFind",                &EQAPP_InterpretCommand_NULL},
    {"//InvFind",                      &EQAPP_InterpretCommand_NULL},
    {"//ZoneInfo",                     &EQAPP_InterpretCommand_NULL},
};

void EQAPP_InterpretCommand_Execute();
void EQAPP_InterpretCommand_ConvertPercentText(std::string& text);
bool EQAPP_InterpretCommand_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, const char* commandText_);
void EQAPP_InterpretCommand_InterpretArguments(const std::string& commandText, const std::string& prependText);
void EQAPP_InterpretCommand_InterpretArgumentsRandom(const std::string& commandText, const std::string& prependText);
void EQAPP_InterpretCommand_Execute(std::string commandText);
bool EQAPP_InterpretCommand_HandleCommandText(std::string commandText);

void EQAPP_InterpretCommand_Execute()
{
    if (g_InterpretCommandQueue.size() == 0)
    {
        return;
    }

    if (EQAPP_Timer_HasTimeElapsed(g_InterpretCommandQueueTimer, g_InterpretCommandQueueTimerInterval) == false)
    {
        return;
    }

    EQ_InterpretCommand(g_InterpretCommandQueue.front().c_str());

    g_InterpretCommandQueue.pop_front();
}

void EQAPP_InterpretCommand_ConvertPercentText(std::string& text)
{
    if (text.find("%PlayerName") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            std::string str = EQ_GetSpawnName(playerSpawn);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "%PlayerName", str);
            }
        }

        return;
    }

    if (text.find("%PlayerID") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnID = EQ_GetSpawnID(playerSpawn);

            std::string str = std::to_string(spawnID);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "%PlayerID", str);
            }
        }

        return;
    }

    if (text.find("%PlayerClass") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnClass = EQ_GetSpawnClass(playerSpawn);

            std::string str = EQ_GetClassNameByKey(spawnClass);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "%PlayerClass", str);
            }
        }

        return;
    }

    if (text.find("%PlayerClassShortName") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnClass = EQ_GetSpawnClass(playerSpawn);

            std::string str = EQ_GetClassShortNameByKey(spawnClass);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "%PlayerClassShortName", str);
            }
        }

        return;
    }

    if (text.find("%TargetID") != std::string::npos)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            auto spawnID = EQ_GetSpawnID(targetSpawn);

            std::string str = std::to_string(spawnID);
            if (str.size() != 0)
            {
                EQAPP_String_ReplaceAll(text, "%TargetID", str);
            }
        }

        return;
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

    EQAPP_InterpretCommand_ConvertPercentText(commandText);

    std::string firstTwoCharacters = commandText.substr(0, 2);
    if (firstTwoCharacters == "//")
    {
        EQAPP_InterpretCommand_Execute(commandText);
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
            for (auto& cmd : g_InterpretCommandList)
            {
                std::string cmdText = cmd.first;
                std::string cmdTextStripped = cmdText.substr(2, cmdText.size());

                if (commandText.find(cmdTextStripped) != std::string::npos)
                {
                    return true;
                }
            }
        }

        for (auto& cmd : g_InterpretCommandList)
        {
            if (commandText == cmd.first)
            {
                return true;
            }
        }
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

        ////EQ_InterpretCommand(ss.str().c_str());
        g_InterpretCommandQueue.push_back(ss.str());
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

    ////std::cout << "Random Number: " << number << std::endl;

    std::stringstream ss;
    ss << prependText << number;

    ////EQ_InterpretCommand(ss.str().c_str());
    g_InterpretCommandQueue.push_back(ss.str());
}

void EQAPP_InterpretCommand_Execute(std::string commandText)
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
        std::cout << "Command List: " << std::endl;

        for (auto& cmd : g_InterpretCommandList)
        {
            std::cout << cmd.first << std::endl;
        }

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

            EQ_PrintTextToChatEx(ss.str().c_str(), i);
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
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                uint32_t number = std::stoul(numberStr);

                EQAPP_BeepEx(number);
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
                std::stringstream filename;
                filename << commandTextAfterSpace;

                if (EQAPP_String_EndsWith(commandTextAfterSpace, ".wav") == false)
                {
                    filename << ".wav";
                }

                EQ_PlaySound(filename.str().c_str());
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
                std::stringstream filename;
                filename << commandTextAfterSpace;

                if (EQAPP_String_EndsWith(commandTextAfterSpace, ".wav") == false)
                {
                    filename << ".wav";
                }

                EQAPP_PlaySound(filename.str().c_str());
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

    if (commandText == "//TaskAccept")
    {
        if (EQ_TaskSelectWindow_IsOpen() == true)
        {
            EQ_TaskSelectWindow_ClickAcceptButton();
        }

        return true;
    }

    if (commandText == "//TaskDecline")
    {
        if (EQ_TaskSelectWindow_IsOpen() == true)
        {
            EQ_TaskSelectWindow_ClickAcceptButton();
        }

        return true;
    }

    if (commandText == "//BazaarListCount")
    {
        if (EQ_BazaarSearchWindow_IsOpen() == true)
        {
            auto listCount = EQ_BazaarSearchWindow_GetListCount();

            std::cout << "Bazaar List Count: " << listCount << std::endl;
        }

        return true;
    }

    if (commandText == "//BazaarListIndex")
    {
        if (EQ_BazaarSearchWindow_IsOpen() == true)
        {
            auto listIndex = EQ_BazaarSearchWindow_GetListIndex();

            std::cout << "Bazaar List Index: " << listIndex << std::endl;
        }

        return true;
    }

    if (commandText == "//BazaarPrintList")
    {
        if (EQ_BazaarSearchWindow_IsOpen() == true)
        {
            EQ_BazaarSearchWindow_PrintList();
        }

        return true;
    }

    if (commandText == "//BazaarDoQuery")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == false)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                EQ_BazaarSearchWindow_DoQuery();
            }
        }

        return true;
    }

    if (commandText == "//BazaarFindItems")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == false)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                EQ_BazaarSearchWindow_ClickFindItemsButton();
            }
        }

        return true;
    }

    if (commandText == "//BazaarUpdateTraders")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == false)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                EQ_BazaarSearchWindow_ClickUpdateTradersButton();
            }
        }

        return true;
    }

    if (commandText == "//BazaarReset")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == false)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                EQ_BazaarSearchWindow_ClickResetButton();
            }
        }

        return true;
    }

    if (commandText == "//BazaarBuy")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == false)
        {
            if (EQ_BazaarSearchWindow_IsOpen() == true)
            {
                EQ_BazaarSearchWindow_BuyItem(0);
            }
        }

        return true;
    }

    if (commandText == "//BazaarToParcels")
    {
        if (EQ_BazaarConfirmationWindow_IsOpen() == true)
        {
            EQ_BazaarConfirmationWindow_ClickToParcelsButton();
        }

        return true;
    }

    if (commandText == "//BazaarBeginTrader")
    {
        if (EQ_BazaarWindow_IsOpen() == true)
        {
            EQ_BazaarWindow_ClickBeginTraderButton();
        }

        return true;
    }

    if (commandText == "//BazaarEndTrader")
    {
        if (EQ_BazaarWindow_IsOpen() == true)
        {
            EQ_BazaarWindow_ClickEndTraderButton();
        }

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

    if (commandText == "//Campfire")
    {
        EQ_UseItem("Fellowship Registration Insignia");

        return true;
    }

    if (commandText == "//Stein")
    {
        EQ_UseItem("Drunkard's Stein");

        return true;
    }

    if (commandText == "//Origin")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::General::Origin);

        return true;
    }

    if (commandText == "//Gate")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Shared::Gate);

        return true;
    }

    if (commandText == "//MassGroupBuff" || commandText == "//MGB")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnClass = EQ_GetSpawnClass(playerSpawn);

            if (EQ_IsSpawnClassPriest(spawnClass) == true)
            {
                EQ_UseAlternateAbility(EQAlternateAbilities::Priest::Mass_Group_Buff);
            }
            else if (EQ_IsSpawnClassCaster(spawnClass) == true)
            {
                EQ_UseAlternateAbility(EQAlternateAbilities::Caster::Mass_Group_Buff);
            }
        }

        return true;
    }

    if (commandText == "//TranquilBlessings" || commandText == "//MGB2")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Shared::Tranquil_Blessings);

        return true;
    }

    if (commandText == "//ThroneOfHeroes" || commandText == "//GuildLobby" || commandText == "//GL")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Throne_of_Heroes);

        return true;
    }

    if (commandText == "//HarmonicDissonance" || commandText == "//TheaterOfBlood")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Harmonic_Dissonance);

        return true;
    }

    if (commandText == "//BindAffinity")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Shared::Bind_Affinity);

        return true;
    }

    if (commandText == "//Identify")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::General::Identify);

        return true;
    }

    if (commandText == "//LessonOfTheDevoted" || commandText == "//LOTD")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Lesson_of_the_Devoted);

        return true;
    }

    if (commandText == "//ExpendientRecovery" || commandText == "//EXPR")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Expedient_Recovery);

        return true;
    }

    if (commandText == "//ArmorOfExperience" || commandText == "//AOEXP")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Armor_of_Experience);

        return true;
    }

    if (commandText == "//InfusionOfTheFaithful" || commandText == "//IOTF")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Infusion_of_the_Faithful);

        return true;
    }

    if (commandText == "//IntensityOfTheResolute" || commandText == "//IOTR")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Intensity_of_the_Resolute);

        return true;
    }

    if (commandText == "//Banestrike")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Banestrike);

        return true;
    }

    if (commandText == "//SteadfastServant")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Steadfast_Servant);

        return true;
    }

    if (commandText == "//ChaoticJester")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Chaotic_Jester);

        return true;
    }

    if (commandText == "//SummonClockworkBanker" || commandText == "//SCB")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Summon_Clockwork_Banker);

        return true;
    }

    if (commandText == "//SummonPermutationPeddler" || commandText == "//SPP")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Summon_Permutation_Peddler);

        return true;
    }

    if (commandText == "//SummonPersonalTributeMaster" || commandText == "//SPTM")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Summon_Personal_Tribute_Master);

        return true;
    }

    if (commandText == "//SummonResupplyAgent" || commandText == "//SRA")
    {
        EQ_UseAlternateAbility(EQAlternateAbilities::Special::Summon_Resupply_Agent);

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

    if (commandText == "//AutoFire")
    {
        if (EQ_IsAutoFireEnabled() == false)
        {
            EQ_SetAutoFire(true);
        }
        else
        {
            EQ_SetAutoFire(false);
        }

        return true;
    }

    if (commandText == "//AutoFireOn")
    {
        EQ_SetAutoFire(true);

        return true;
    }

    if (commandText == "//AutoFireOff")
    {
        EQ_SetAutoFire(false);

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

    if (commandText == "//FieldOfViewDefault" || commandText == "//FOVDefault")
    {
        EQ_SetCameraFieldOfView(EQ_CAMERA_FIELD_OF_VIEW_DEFAULT);

        std::cout << "Field of View set to default." << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FieldOfView ") == true || EQAPP_String_BeginsWith(commandText, "//FOV ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                float number = std::stof(numberStr);
                if (number > 0.0f)
                {
                    EQ_SetCameraFieldOfView(number);

                    std::cout << "Field of View: " << number << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DrawDistance ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                float number = std::stof(numberStr);
                if (number > 0.0f)
                {
                    EQ_SetCameraDrawDistance(number);

                    std::cout << "Draw Distance: " << number << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//FogOff")
    {
        EQ_SetFog(false);

        return true;
    }

    if (commandText == "//FogOn")
    {
        EQ_SetFog(true);

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FogDistanceBegin ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                float number = std::stof(numberStr);
                if (number > 0.0f)
                {
                    EQ_SetFogDistanceBegin(number);

                    std::cout << "Fog Distance Begin: " << number << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//FogDistanceEnd ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                float number = std::stof(numberStr);
                if (number > 0.0f)
                {
                    EQ_SetFogDistanceEnd(number);

                    std::cout << "Fog Distance End: " << number << std::endl;
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

            float newHeight = targetHeight - 1.0f;
            if (newHeight < 1.0f)
            {
                newHeight = 1.0f;
            }

            EQ_SetSpawnHeight(targetSpawn, newHeight);
        }

        return true;
    }

    if (commandText == "//GrowTarget")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            float targetHeight = EQ_GetSpawnHeight(targetSpawn);

            float newHeight = targetHeight + 1.0f;
            if (newHeight > 100.0f)
            {
                newHeight = 100.0f;
            }

            EQ_SetSpawnHeight(targetSpawn, newHeight);
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ChangeTargetHeight ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            float height = std::stof(numberStr);
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
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawn = EQ_GetSpawnByName(spawnName.c_str());
                if (spawn != NULL)
                {
                    EQ_SetTargetSpawn(spawn);

                    ////std::cout << "Target: " << spawnName << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//TargetID ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                uint32_t spawnID = std::stoul(numberStr);

                auto playerSpawn = EQ_GetPlayerSpawn();
                if (playerSpawn != NULL)
                {
                    auto spawn = EQ_GetSpawnByID(spawnID);
                    if (spawn != NULL)
                    {
                        EQ_SetTargetSpawn(spawn);

                        ////std::cout << "Target by ID: " << spawnID << std::endl;
                    }
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

    if (EQAPP_String_BeginsWith(commandText, "//Follow ") == true)
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

                    ////std::cout << "Follow: " << spawnName << std::endl;
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

        return true;
    }

    if (commandText == "//CloseTopWindow")
    {
        EQ_ExecuteCommand(EQ_EXECUTECMD_CLOSE_TOP_WINDOW, 1);

        return true;
    }

    if (commandText == "//CloseAllTopWindows")
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

    if (commandText == "//Duck" || commandText == "//Crouch")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
            if (spawnStandingState != EQ_STANDING_STATE_DUCKING)
            {
                EQ_ExecuteCommand(EQ_EXECUTECMD_DUCK, 1);
            }
        }

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
            auto spawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
            if (spawnStandingState != EQ_STANDING_STATE_SITTING)
            {
                EQ_ExecuteCommand(EQ_EXECUTECMD_SIT_STAND, 1);
            }
        }

        return true;
    }

    if (commandText == "//Stand")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
            if (spawnStandingState != EQ_STANDING_STATE_STANDING)
            {
                EQ_InterpretCommand("/stand");
            }
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

    // //UseItemBag1_1, //UseItemBag1_2, //UseItemBag1_3
    // //UseItemBag10_40 is Bag #10 Slot #40
    if (EQAPP_String_BeginsWith(commandText, "//UseItemBag") == true)
    {
        ////std::cout << "commandText: " << commandText << std::endl;

        std::string numbers = EQAPP_String_GetAfter(commandText, "//UseItemBag");

        ////std::cout << "numbers: " << numbers << std::endl;

        if (numbers.size() != 0)
        {
            if (EQAPP_String_Contains(numbers, "_") == true)
            {
                ////std::cout << "underscore found" << std::endl;

                std::vector<std::string> tokens = EQAPP_String_Split(numbers, '_');
                if (tokens.size() == 2)
                {
                    ////std::cout << "tokens size == 2" << std::endl;

                    std::string number1 = tokens.at(0);
                    std::string number2 = tokens.at(1);

                    ////std::cout << "number1: " << number1 << std::endl;
                    ////std::cout << "number2: " << number2 << std::endl;

                    if (EQAPP_String_IsDigits(number1) == true && EQAPP_String_IsDigits(number2) == true)
                    {
                        ////std::cout << "both numbers are digits" << std::endl;

                        // /useitem <bag> <bag_slot>
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

                        uint32_t bagNumber = std::stoul(number1);

                        ////std::cout << "bagNumber : " << bagNumber  << std::endl;

                        if (bagNumber > 0 && bagNumber < (EQ_NUM_BAGS + 1))
                        {
                            bagNumber = bagNumber + 22; // 1+22=23, 2+2=24, 3+22=25, 10+22=32, etc

                            uint32_t bagSlotNumber = std::stoul(number2);

                            ////std::cout << "bagSlotNumber : " << bagSlotNumber  << std::endl;

                            if (bagSlotNumber > 0 && bagSlotNumber < (EQ_NUM_BAG_SLOTS + 1))
                            {
                                bagSlotNumber = bagSlotNumber - 1; // <bag_slot> starts at index 0

                                std::stringstream ss;
                                ss << "/useitem " << bagNumber << " " << bagSlotNumber;

                                std::cout << ss.str() << std::endl;

                                EQ_InterpretCommand(ss.str().c_str());
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//CombatHotButton ") == true || EQAPP_String_BeginsWith(commandText, "//CHB ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                signed int number = std::stoi(numberStr);

                if (number > 0 && number < (EQ_NUM_HOTBAR_BUTTONS + 1))
                {
                    g_CombatHotButtonIndex = number - 1;

                    std::cout << "Combat HotButton: " << number << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AlwaysHotButton ") == true || EQAPP_String_BeginsWith(commandText, "//AHB ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                signed int number = std::stoi(numberStr);

                if (number > 0 && number < (EQ_NUM_HOTBAR_BUTTONS + 1))
                {
                    g_AlwaysHotButtonIndex = number - 1;

                    std::cout << "Always HotButton: " << number << std::endl;
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

    if (commandText == "//ESPFindType")
    {
        g_ESPFindSpawnType = EQ_SPAWN_TYPE_UNKNOWN;

        std::cout << "ESP Find Spawn Type reset!" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindTypePlayer")
    {
        g_ESPFindSpawnType = EQ_SPAWN_TYPE_PLAYER;

        std::cout << "ESP Find Spawn Type: Player" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindTypeNPC")
    {
        g_ESPFindSpawnType = EQ_SPAWN_TYPE_NPC;

        std::cout << "ESP Find Spawn Type: NPC" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindTypeCorpse")
    {
        g_ESPFindSpawnType = EQ_SPAWN_TYPE_CORPSE;

        std::cout << "ESP Find Spawn Type: Corpse" << std::endl;

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
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                uint32_t spawnLevel = std::stoul(numberStr);

                g_ESPFindSpawnLevel = spawnLevel;

                std::cout << "ESP Find Spawn Level: " << g_ESPFindSpawnLevel << std::endl;
            }
        }

        return true;
    }

    if (commandText == "//ESPFindRace")
    {
        g_ESPFindSpawnRace = EQ_RACE_UNKNOWN;

        std::cout << "ESP Find Spawn Race reset!" << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindRace ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t spawnRace = std::stoul(commandTextAfterSpace);

                g_ESPFindSpawnRace = spawnRace;

                std::cout << "ESP Find Spawn Race: " << g_ESPFindSpawnRace << std::endl;
            }
            else
            {
                auto key = EQ_StringMap_GetKeyByValue(EQ_STRING_MAP_RACE_NAME, commandTextAfterSpace);
                if (key != 0xFFFFFFFF)
                {
                    g_ESPFindSpawnRace = key;

                    std::cout << "ESP Find Spawn Race: " << commandTextAfterSpace << std::endl;
                }

                auto key2 = EQ_StringMap_GetKeyByValue(EQ_STRING_MAP_RACE_SHORT_NAME, commandTextAfterSpace);
                if (key2 != 0xFFFFFFFF)
                {
                    g_ESPFindSpawnRace = key2;

                    std::cout << "ESP Find Spawn Race: " << commandTextAfterSpace << std::endl;
                }
            }
        }

        return true;
    }

    if (commandText == "//ESPFindClass")
    {
        g_ESPFindSpawnClass = EQ_CLASS_UNKNOWN;

        std::cout << "ESP Find Spawn Class reset!" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindClassBanker")
    {
        g_ESPFindSpawnClass = EQ_CLASS_BANKER;

        std::cout << "ESP Find Spawn Class: Banker" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindClassMerchant")
    {
        g_ESPFindSpawnClass = EQ_CLASS_MERCHANT;

        std::cout << "ESP Find Spawn Class: Merchant" << std::endl;

        return true;
    }

    if (commandText == "//ESPFindClassObject")
    {
        g_ESPFindSpawnClass = EQ_CLASS_OBJECT;

        std::cout << "ESP Find Spawn Class: Object" << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindClass ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t spawnClass = std::stoul(commandTextAfterSpace);

                g_ESPFindSpawnClass = spawnClass;

                std::cout << "ESP Find Spawn Class: " << EQ_GetClassNameByKey(g_ESPFindSpawnClass) << std::endl;
            }
            else
            {
                auto key = EQ_StringMap_GetKeyByValue(EQ_STRING_MAP_CLASS_NAME, commandTextAfterSpace);
                if (key != 0xFFFFFFFF)
                {
                    g_ESPFindSpawnClass = key;

                    std::cout << "ESP Find Spawn Class: " << commandTextAfterSpace << std::endl;
                }

                auto key2 = EQ_StringMap_GetKeyByValue(EQ_STRING_MAP_CLASS_SHORT_NAME, commandTextAfterSpace);
                if (key2 != 0xFFFFFFFF)
                {
                    g_ESPFindSpawnClass = key;

                    std::cout << "ESP Find Spawn Class: " << commandTextAfterSpace << std::endl;
                }
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

    if (EQAPP_String_BeginsWith(commandText, "//Cast ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            if (EQAPP_String_IsDigits(numberStr) == true)
            {
                uint32_t number = std::stoul(numberStr);

                if (number > 0 && number < (EQ_NUM_SPELL_GEMS + 1))
                {
                    std::stringstream ss;
                    ss << "/cast " << number;

                    // cast the spell multiple times in case of fizzles
                    for (unsigned int i = 0; i < 4; i++)
                    {
                        EQ_InterpretCommand(ss.str().c_str());
                    }
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//CastRandom ") == true)
    {
        EQAPP_InterpretCommand_InterpretArgumentsRandom(commandText, "/cast ");

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

                std::cout << "Box Chat to '" << name << "': " << tokens.at(2) << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatTellChannel ") == true || EQAPP_String_BeginsWith(commandText, "//BCTC ") == true)
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

                std::cout << "Box Chat to Channel '" << name << "': " << tokens.at(2) << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatTellGroup ") == true || EQAPP_String_BeginsWith(commandText, "//BCTG ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto groupMemberSpawnList = EQ_GetGroupMemberSpawnList();
            if (groupMemberSpawnList.size() != 0)
            {
                for (auto& groupMemberSpawn : groupMemberSpawnList)
                {
                    if (groupMemberSpawn == NULL)
                    {
                        continue;
                    }

                    std::string groupMemberSpawnName = EQ_GetSpawnName(groupMemberSpawn);
                    if (groupMemberSpawnName.size() == 0)
                    {
                        continue;
                    }

                    std::stringstream ss;
                    ss << "//BoxChatTell " << groupMemberSpawnName << " " << commandTextAfterSpace << "\n";

                    EQAPP_BoxChat_SendText(ss.str());
                }
            }

            std::cout << "Box Chat to Group: " << commandTextAfterSpace << std::endl;
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

    if (commandText == "//NearbyNPC")
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

    if (commandText == "//ScriptFolder" || commandText == "//Scripts" || commandText == "//Script")
    {
        std::cout << "Script Folder:" << std::endl;

        EQAPP_Lua_ScriptFolder_Print();

        return true;
    }

    if (commandText == "//LoadScripts")
    {
        std::cout << "Loading scripts..." << std::endl;

        EQAPP_Lua_LoadGlobalScripts(&g_LuaState);

        EQAPP_Lua_EventScriptList_Load();

        EQAPP_Lua_ScriptFolder_Print();

        return true;
    }

    if (commandText == "//LoadEventScriptList" || commandText == "//LoadEventScripts")
    {
        std::cout << "Loading Event Script list..." << std::endl;

        EQAPP_Lua_EventScriptList_Load();
        EQAPP_Lua_EventScriptList_Print();

        return true;
    }

    if (commandText == "//EventScriptList")
    {
        std::cout << "Event Scripts:" << std::endl;

        EQAPP_Lua_EventScriptList_Print();

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Script ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::stringstream filename;
            filename << commandTextAfterSpace;

            if (EQAPP_String_EndsWith(commandTextAfterSpace, ".lua") == false)
            {
                filename << ".lua";
            }

            bool result = EQAPP_Lua_ExecuteFile(&g_LuaState, filename.str().c_str());
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Lua ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            bool result = EQAPP_Lua_ExecuteCode(&g_LuaState, commandTextAfterSpace.c_str());
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//LuaEvent ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            std::vector<std::string> tokens = EQAPP_String_Split(commandTextAfterSpace, ';');
            if (tokens.size() == 2)
            {
                std::string filename = tokens.at(0);
                std::string luaCode = tokens.at(1);

                if (filename.size() != 0 && luaCode.size() != 0)
                {
                    for (auto& script : g_LuaEventScriptList)
                    {
                        if (filename == script->Filename)
                        {
                            bool result = EQAPP_Lua_ExecuteCode(&script->LuaState, luaCode.c_str());

                            break;
                        }
                    }
                }
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

    if (EQAPP_String_BeginsWith(commandText, "//ItemSlotPrimary ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                EQ_SetSpawnItemSlotPrimary(playerSpawn, commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ItemSlotSecondary ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                EQ_SetSpawnItemSlotSecondary(playerSpawn, commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ItemSlotHead ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                EQ_SetSpawnItemSlotHead(playerSpawn, commandTextAfterSpace.c_str());
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfMoving ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawnMovementSpeed = EQ_GetSpawnMovementSpeed(playerSpawn);
                if (spawnMovementSpeed != 0.0f)
                {
                    EQ_InterpretCommand(commandTextAfterSpace.c_str());
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//IfNotMoving ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                auto spawnMovementSpeed = EQ_GetSpawnMovementSpeed(playerSpawn);
                if (spawnMovementSpeed == 0.0f)
                {
                    EQ_InterpretCommand(commandTextAfterSpace.c_str());
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
                float number = std::stof(commandTextAfterSpace);
                if (number > 0.0f)
                {
                    EQ_UseDoorByDistance(number);
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
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_InventoryFind(commandTextAfterSpace.c_str());
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
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            float number = std::stof(numberStr);
            if (number > 0.0f)
            {
                g_SpeedMultiplier = number;

                std::cout << "Speed Multiplier: " << number << std::endl;
            }
        }

        return true;
    }

    if (commandText == "//WPA"  || commandText == "//WaypointAdd")
    {
        EQAPP_Waypoint_Add("");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//WPA ") == true || EQAPP_String_BeginsWith(commandText, "//WPAdd ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            EQAPP_Waypoint_Add(commandTextAfterSpace.c_str());
        }

        return true;
    }

    if (commandText == "//WPAC" || commandText == "//WPAddConnect")
    {
        EQAPP_Waypoint_Add("");

        EQApp::Waypoint_ptr lastWaypoint = &g_WaypointList.back();
        if (lastWaypoint != NULL)
        {
            auto lastIndex = lastWaypoint->Index;
            if (lastIndex > 0)
            {
                EQAPP_Waypoint_Connect(lastIndex, lastIndex - 1, false);
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//WPR ") == true || EQAPP_String_BeginsWith(commandText, "//WPRemove ") == true)
    {
        std::string commandTextAfterSpace = EQAPP_String_GetAfter(commandText, " ");
        if (commandTextAfterSpace.size() != 0)
        {
            if (EQAPP_String_IsDigits(commandTextAfterSpace) == true)
            {
                uint32_t number = std::stoul(commandTextAfterSpace);

                EQAPP_Waypoint_Remove(number);
            }
        }

        return true;
    }

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
                    uint32_t number1 = std::stoul(tokens.at(0));
                    uint32_t number2 = std::stoul(tokens.at(1));

                    EQAPP_Waypoint_Connect(number1, number2, false);
                }
            }
        }

        return true;
    }

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
                    uint32_t number1 = std::stoul(tokens.at(0));
                    uint32_t number2 = std::stoul(tokens.at(1));

                    EQAPP_Waypoint_Connect(number1, number2, true);
                }
            }
        }

        return true;
    }

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
                    uint32_t number1 = std::stoul(tokens.at(0));
                    uint32_t number2 = std::stoul(tokens.at(1));

                    EQAPP_Waypoint_Disconnect(number1, number2, false);
                }
            }
        }

        return true;
    }

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
                    uint32_t number1 = std::stoul(tokens.at(0));
                    uint32_t number2 = std::stoul(tokens.at(1));

                    EQAPP_Waypoint_Disconnect(number1, number2, true);
                }
            }
        }

        return true;
    }

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
                    uint32_t number1 = std::stoul(tokens.at(0));
                    uint32_t number2 = std::stoul(tokens.at(1));

                    g_WaypointPathIndexList = EQAPP_Waypoint_GetPath(number1, number2);
                    if (g_WaypointPathIndexList.size() != 0)
                    {
                        EQAPP_Waypoint_PrintPath(g_WaypointPathIndexList, number1);
                    }
                }
            }
        }

        return true;
    }

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
                    uint32_t number = std::stoul(tokens.at(0));

                    std::string str = tokens.at(1);
                    if (str.size() != 0)
                    {
                        auto waypoint = EQAPP_Waypoint_GetByIndex(number);
                        if (waypoint != NULL)
                        {
                            waypoint->Name = str;

                            std::cout << "Waypoint index " << waypoint->Index << " name set to: " << str;
                        }
                    }
                }
            }
        }

        return true;
    }

    return false;
}
