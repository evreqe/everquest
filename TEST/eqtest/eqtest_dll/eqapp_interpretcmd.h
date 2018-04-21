#pragma once

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
#include "eqapp_hud.h"
#include "eqapp_lua.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_spelllist.h"
#include "eqapp_windowtitle.h"

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
    {"//AutoGroup",                    &EQAPP_AutoGroup_Toggle},
    {"//AG",                           &EQAPP_AutoGroup_Toggle},
    {"//BoxChat",                      &EQAPP_BoxChat_Toggle},
    {"//BC",                           &EQAPP_BoxChat_Toggle},
    {"//BoxChatAutoConnect",           &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//BCAC",                         &EQAPP_BoxChat_AutoConnect_Toggle},
    {"//CombatAlternateAbility",       &EQAPP_CombatAlternateAbility_Toggle},
    {"//CAA",                          &EQAPP_CombatAlternateAbility_Toggle},
    {"//ESP",                          &EQAPP_ESP_Toggle},
    {"//ESPHeightFilter",              &EQAPP_ESP_HeightFilter_Toggle},
    {"//ESPShowSpawnID",               &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ESPShowSpawnRace",             &EQAPP_ESP_ShowSpawnRace_Toggle},
    {"//ESPShowSpawnClass",            &EQAPP_ESP_ShowSpawnClass_Toggle},
    {"//ChangeHeight",                 &EQAPP_ChangeHeight_Toggle},
    {"//CH",                           &EQAPP_ChangeHeight_Toggle},
    {"//LoadSpellList",                &EQAPP_SpellList_Load},
    {"//SpawnCastSpell",               &EQAPP_SpawnCastSpell_Toggle},
    {"//SCS",                          &EQAPP_SpawnCastSpell_Toggle},
    {"//SpawnCastSpellGroupChat",      &EQAPP_SpawnCastSpell_GroupChat_Toggle},
    {"//SCSGC",                        &EQAPP_SpawnCastSpell_GroupChat_Toggle},
    {"//HUD",                          &EQAPP_HUD_Toggle},
    {"//LoadBazaarFilter",             &EQAPP_BazaarFilter_Load},
    {"//LBF",                          &EQAPP_BazaarFilter_Load},
    {"//BazaarFilter",                 &EQAPP_BazaarFilter_Toggle},
    {"//BF",                           &EQAPP_BazaarFilter_Toggle},
    {"//BazaarFilterBeep",             &EQAPP_BazaarFilter_Beep_Toggle},
    {"//BFB",                          &EQAPP_BazaarFilter_Beep_Toggle},
    {"//BazaarFilterList",             &EQAPP_BazaarFilter_PrintItemNameList},
    {"//BFL",                          &EQAPP_BazaarFilter_PrintItemNameList},
    {"//BFB",                          &EQAPP_BazaarFilter_Beep_Toggle},
    {"//BazaarBot",                    &EQAPP_BazaarBot_Toggle},
    {"//BB",                           &EQAPP_BazaarBot_Toggle},
    {"//FollowAI",                     &EQAPP_FollowAI_Toggle},
    {"//FAI",                          &EQAPP_FollowAI_Toggle},
    {"//FollowAIUseZAxis",             &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//FAIUZA",                       &EQAPP_FollowAI_UseZAxis_Toggle},
    {"//WindowTitle",                  &EQAPP_WindowTitle_Toggle},
    ////{"//Null",                         &EQAPP_InterpretCmd_NULL},
    {"//Test",                         &EQAPP_InterpretCmd_NULL},
    {"//Pause",                        &EQAPP_InterpretCmd_NULL},
    {"//InGame",                       &EQAPP_InterpretCmd_NULL},
    {"//NotInGame",                    &EQAPP_InterpretCmd_NULL},
    {"//Beep",                         &EQAPP_InterpretCmd_NULL},
    {"//BeepEx",                       &EQAPP_InterpretCmd_NULL},
    {"//PlaySound",                    &EQAPP_InterpretCmd_NULL},
    {"//PlaySoundEx",                  &EQAPP_InterpretCmd_NULL},
    {"//StopSound",                    &EQAPP_InterpretCmd_NULL},
    {"//StopSoundEx",                  &EQAPP_InterpretCmd_NULL},
    {"//BazaarDoQuery",                &EQAPP_InterpretCmd_NULL},
    {"//BazaarFindItems",              &EQAPP_InterpretCmd_NULL},
    {"//BazaarUpdateTraders",          &EQAPP_InterpretCmd_NULL},
    {"//BazaarReset",                  &EQAPP_InterpretCmd_NULL},
    {"//BazaarBuy",                    &EQAPP_InterpretCmd_NULL},
    {"//BazaarToParcels",              &EQAPP_InterpretCmd_NULL},
    {"//BazaarBeginTrader",            &EQAPP_InterpretCmd_NULL},
    {"//BazaarEndTrader",              &EQAPP_InterpretCmd_NULL},
    {"//Screencap",                    &EQAPP_InterpretCmd_NULL},
    {"//Screenshot",                   &EQAPP_InterpretCmd_NULL},
    {"//Origin",                       &EQAPP_InterpretCmd_NULL},
    {"//Gate",                         &EQAPP_InterpretCmd_NULL},
    {"//MassGroupBuff",                &EQAPP_InterpretCmd_NULL},
    {"//MGB",                          &EQAPP_InterpretCmd_NULL},
    {"//TranquilBlessings",            &EQAPP_InterpretCmd_NULL},
    {"//MGB2",                         &EQAPP_InterpretCmd_NULL},
    {"//ThroneOfHeroes",               &EQAPP_InterpretCmd_NULL},
    {"//GuildLobby",                   &EQAPP_InterpretCmd_NULL},
    {"//GL",                           &EQAPP_InterpretCmd_NULL},
    {"//HarmonicDissonance",           &EQAPP_InterpretCmd_NULL},
    {"//TheaterOfBlood",               &EQAPP_InterpretCmd_NULL},
    {"//BindAffinity",                 &EQAPP_InterpretCmd_NULL},
    {"//Identify",                     &EQAPP_InterpretCmd_NULL},
    {"//LessonOfTheDevoted",           &EQAPP_InterpretCmd_NULL},
    {"//LOTD",                         &EQAPP_InterpretCmd_NULL},
    {"//ExpedientRecovery",            &EQAPP_InterpretCmd_NULL},
    {"//EXPR",                         &EQAPP_InterpretCmd_NULL},
    {"//ArmorOfExperience",            &EQAPP_InterpretCmd_NULL},
    {"//AOEXP",                        &EQAPP_InterpretCmd_NULL},
    {"//InfusionOfTheFaithful",        &EQAPP_InterpretCmd_NULL},
    {"//IOTF",                         &EQAPP_InterpretCmd_NULL},
    {"//IntensityOfTheResolute",       &EQAPP_InterpretCmd_NULL},
    {"//IOTR",                         &EQAPP_InterpretCmd_NULL},
    {"//Banestrike",                   &EQAPP_InterpretCmd_NULL},
    {"//SteadfastServant",             &EQAPP_InterpretCmd_NULL},
    {"//ChaoticJester",                &EQAPP_InterpretCmd_NULL},
    {"//SummonClockworkBanker",        &EQAPP_InterpretCmd_NULL},
    {"//SCB",                          &EQAPP_InterpretCmd_NULL},
    {"//SummonPermutationPeddler",     &EQAPP_InterpretCmd_NULL},
    {"//SPP",                          &EQAPP_InterpretCmd_NULL},
    {"//SummonPersonalTributeMaster",  &EQAPP_InterpretCmd_NULL},
    {"//SPTM",                         &EQAPP_InterpretCmd_NULL},
    {"//SummonResupplyAgent",          &EQAPP_InterpretCmd_NULL},
    {"//SRA",                          &EQAPP_InterpretCmd_NULL},
    {"//SummonTomeOfTheHerosJourney",  &EQAPP_InterpretCmd_NULL},
    {"//STOTHJ",                       &EQAPP_InterpretCmd_NULL},
    {"//AutoAttackOn",                 &EQAPP_InterpretCmd_NULL},
    {"//AutoAttackOff",                &EQAPP_InterpretCmd_NULL},
    {"//AutoFireOn",                   &EQAPP_InterpretCmd_NULL},
    {"//AutoFireOff",                  &EQAPP_InterpretCmd_NULL},
    {"//AutoRunOn",                    &EQAPP_InterpretCmd_NULL},
    {"//AutoRunOff",                   &EQAPP_InterpretCmd_NULL},
    {"//AcceptInvite",                 &EQAPP_InterpretCmd_NULL},
    {"//JoinGroup",                    &EQAPP_InterpretCmd_NULL},
    {"//Disband",                      &EQAPP_InterpretCmd_NULL},
    {"//FieldOfView",                  &EQAPP_InterpretCmd_NULL},
    {"//FOV",                          &EQAPP_InterpretCmd_NULL},
    {"//ChangeTargetHeight1",          &EQAPP_InterpretCmd_NULL},
    {"//ChangeTargetHeight5",          &EQAPP_InterpretCmd_NULL},
    {"//ChangeTargetHeight10",         &EQAPP_InterpretCmd_NULL},
    {"//ChangeTargetHeight",           &EQAPP_InterpretCmd_NULL},
    {"//FaceTargetHeading",            &EQAPP_InterpretCmd_NULL},
    {"//FaceTarget",                   &EQAPP_InterpretCmd_NULL},
    {"//TargetMe",                     &EQAPP_InterpretCmd_NULL},
    {"//TargetMyself",                 &EQAPP_InterpretCmd_NULL},
    {"//Target",                       &EQAPP_InterpretCmd_NULL},
    {"//TargetID",                     &EQAPP_InterpretCmd_NULL},
    {"//Follow",                       &EQAPP_InterpretCmd_NULL},
    {"//StopFollow",                   &EQAPP_InterpretCmd_NULL},
    {"//StopCast",                     &EQAPP_InterpretCmd_NULL},
    {"//StopSong",                     &EQAPP_InterpretCmd_NULL},
    {"//StopAction",                   &EQAPP_InterpretCmd_NULL},
    {"//ClearTarget",                  &EQAPP_InterpretCmd_NULL},
    {"//CloseTopWindow",               &EQAPP_InterpretCmd_NULL},
    {"//CloseAllTopWindows",           &EQAPP_InterpretCmd_NULL},
    {"//Hail",                         &EQAPP_InterpretCmd_NULL},
    {"//Camp",                         &EQAPP_InterpretCmd_NULL},
    {"//Use",                          &EQAPP_InterpretCmd_NULL},
    {"//Jump",                         &EQAPP_InterpretCmd_NULL},
    {"//Duck",                         &EQAPP_InterpretCmd_NULL},
    {"//Crouch",                       &EQAPP_InterpretCmd_NULL},
    {"//SitStand",                     &EQAPP_InterpretCmd_NULL},
    {"//Sit",                          &EQAPP_InterpretCmd_NULL},
    {"//Stand",                        &EQAPP_InterpretCmd_NULL},
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
    {"//Discipline1",                  &EQAPP_InterpretCmd_NULL},
    {"//XTargetCycle",                 &EQAPP_InterpretCmd_NULL},
    {"//XTarget1",                     &EQAPP_InterpretCmd_NULL},
    ////{"//Potion1",                      &EQAPP_InterpretCmd_NULL},
    {"//UseItemCharm",                 &EQAPP_InterpretCmd_NULL},
    {"//UseItemLeftEar",               &EQAPP_InterpretCmd_NULL},
    {"//UseItemHead",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemFace",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemRightEar",              &EQAPP_InterpretCmd_NULL},
    {"//UseItemNeck",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemShoulders",             &EQAPP_InterpretCmd_NULL},
    {"//UseItemArms",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemBack",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemLeftWrist",             &EQAPP_InterpretCmd_NULL},
    {"//UseItemLeftEar",               &EQAPP_InterpretCmd_NULL},
    {"//UseItemRightWrist",            &EQAPP_InterpretCmd_NULL},
    {"//UseItemRange",                 &EQAPP_InterpretCmd_NULL},
    {"//UseItemHands",                 &EQAPP_InterpretCmd_NULL},
    {"//UseItemPrimary",               &EQAPP_InterpretCmd_NULL},
    {"//UseItemSecondary",             &EQAPP_InterpretCmd_NULL},
    {"//UseItemLeftRing",              &EQAPP_InterpretCmd_NULL},
    {"//UseItemRightRing",             &EQAPP_InterpretCmd_NULL},
    {"//UseItemChest",                 &EQAPP_InterpretCmd_NULL},
    {"//UseItemLegs",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemFeet",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemWaist",                 &EQAPP_InterpretCmd_NULL},
    {"//UseItemPowerSource",           &EQAPP_InterpretCmd_NULL},
    {"//UseItemAmmo",                  &EQAPP_InterpretCmd_NULL},
    {"//UseItemBag1_1",                &EQAPP_InterpretCmd_NULL},
    {"//ESPFindName",                  &EQAPP_InterpretCmd_NULL},
    {"//ESPFindLastName",              &EQAPP_InterpretCmd_NULL},
    {"//ESPFindType",                  &EQAPP_InterpretCmd_NULL},
    {"//ESPFindTypePlayer",            &EQAPP_InterpretCmd_NULL},
    {"//ESPFindTypeNPC",               &EQAPP_InterpretCmd_NULL},
    {"//ESPFindTypeCorpse",            &EQAPP_InterpretCmd_NULL},
    {"//ESPFindLevel",                 &EQAPP_InterpretCmd_NULL},
    {"//ESPFindRace",                  &EQAPP_InterpretCmd_NULL},
    {"//ESPFindClass",                 &EQAPP_InterpretCmd_NULL},
    {"//ESPFindClassBanker",           &EQAPP_InterpretCmd_NULL},
    {"//ESPFindClassMerchant",         &EQAPP_InterpretCmd_NULL},
    {"//ESPFindClassObject",           &EQAPP_InterpretCmd_NULL},
    {"//Multiline",                    &EQAPP_InterpretCmd_NULL},
    {"//MultilineRandom",              &EQAPP_InterpretCmd_NULL},
    {"//Cast",                         &EQAPP_InterpretCmd_NULL},
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
    {"//BoxChatStatus",                &EQAPP_InterpretCmd_NULL},
    {"//BCS",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatSetChannel",            &EQAPP_InterpretCmd_NULL},
    {"//BCSC",                         &EQAPP_InterpretCmd_NULL},
    {"//BoxChatTell",                  &EQAPP_InterpretCmd_NULL},
    {"//BCT",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatTellChannel",           &EQAPP_InterpretCmd_NULL},
    {"//BCTC",                         &EQAPP_InterpretCmd_NULL},
    {"//BoxChatOthers",                &EQAPP_InterpretCmd_NULL},
    {"//BCA",                          &EQAPP_InterpretCmd_NULL},
    {"//BoxChatAll",                   &EQAPP_InterpretCmd_NULL},
    {"//BCAA",                         &EQAPP_InterpretCmd_NULL},
    {"//SpawnList",                    &EQAPP_InterpretCmd_NULL},
    {"//Location",                     &EQAPP_InterpretCmd_NULL},
    {"//Loc",                          &EQAPP_InterpretCmd_NULL},
    {"//Melody",                       &EQAPP_InterpretCmd_NULL},
    {"//PrintScriptFolder",            &EQAPP_InterpretCmd_NULL},
    {"//LoadEventScriptList",          &EQAPP_InterpretCmd_NULL},
    {"//PrintEventScriptList",         &EQAPP_InterpretCmd_NULL},
    {"//Script",                       &EQAPP_InterpretCmd_NULL},
    {"//Lua",                          &EQAPP_InterpretCmd_NULL},
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

    // delete comments from command text
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

    if (commandText.find("%PlayerName") != std::string::npos)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnName = EQ_GetSpawnName(playerSpawn);
            if (spawnName.size() != 0)
            {
                EQAPP_String_ReplaceAll(commandText, "%PlayerName", spawnName);
            }
        }
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
        EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarSearchWnd, EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS);

        EQ_PrintTextToChat("Test!");

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
            uint32_t number = std::stoul(numberStr);

            EQAPP_BeepEx(number);
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

    if (commandText == "//Origin")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::General::Origin;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//Gate")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Shared::Gate;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//MassGroupBuff" || commandText == "//MGB")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto spawnClass = EQ_GetSpawnClass(playerSpawn);

            std::stringstream ss;

            if (EQ_IsSpawnClassPriest(spawnClass) == true)
            {
                ss << "/alt activate " << EQAlternateAbilities::Priest::Mass_Group_Buff;
            }
            else if (EQ_IsSpawnClassCaster(spawnClass) == true)
            {
                ss << "/alt activate " << EQAlternateAbilities::Caster::Mass_Group_Buff;
            }

            EQ_InterpretCommand(ss.str().c_str());
        }

        return true;
    }

    if (commandText == "//TranquilBlessings" || commandText == "//MGB2")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Shared::Tranquil_Blessings;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//ThroneOfHeroes" || commandText == "//GuildLobby" || commandText == "//GL")
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
        ss << "/alt activate " << EQAlternateAbilities::Shared::Bind_Affinity;

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

    if (commandText == "//LessonOfTheDevoted" || commandText == "//LOTD")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Lesson_of_the_Devoted;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//ExpendientRecovery" || commandText == "//EXPR")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Expedient_Recovery;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//ArmorOfExperience" || commandText == "//AOEXP")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Armor_of_Experience;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//InfusionOfTheFaithful" || commandText == "//IOTF")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Infusion_of_the_Faithful;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//IntensityOfTheResolute" || commandText == "//IOTR")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Intensity_of_the_Resolute;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//Banestrike")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Banestrike;

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

    if (commandText == "//ChaoticJester")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Chaotic_Jester;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SummonClockworkBanker" || commandText == "//SCB")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Summon_Clockwork_Banker;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SummonPermutationPeddler" || commandText == "//SPP")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Summon_Permutation_Peddler;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SummonPersonalTributeMaster" || commandText == "//SPTM")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Summon_Personal_Tribute_Master;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SummonResupplyAgent" || commandText == "//SRA")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Summon_Resupply_Agent;

        EQ_InterpretCommand(ss.str().c_str());

        return true;
    }

    if (commandText == "//SummonTomeOfTheHerosJourney" || commandText == "//STOTHJ")
    {
        std::stringstream ss;
        ss << "/alt activate " << EQAlternateAbilities::Special::Summon_Tome_of_the_Heros_Journey;

        EQ_InterpretCommand(ss.str().c_str());

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

    if (EQAPP_String_BeginsWith(commandText, "//FieldOfView ") == true || EQAPP_String_BeginsWith(commandText, "//FOV ") == true)
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

    if (commandText == "//ChangeTargetHeight1")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_SetSpawnHeight(targetSpawn, 1.0f);
        }

        return true;
    }

    if (commandText == "//ChangeTargetHeight5")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_SetSpawnHeight(targetSpawn, 5.0f);
        }

        return true;
    }

    if (commandText == "//ChangeTargetHeight10")
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            EQ_SetSpawnHeight(targetSpawn, 10.0f);
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//ChangeTargetHeight ") == true)
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

    if (EQAPP_String_BeginsWith(commandText, "//Face ") == true)
    {
        std::string nameStr = EQAPP_String_GetAfter(commandText, " ");
        if (nameStr.size() != 0)
        {
            auto spawn = EQ_GetSpawnByName(nameStr.c_str());
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

                    std::cout << "Target: " << spawnName << std::endl;
                }
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//TargetID ") == true)
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
            signed int number = std::stoi(numberStr);

            if (number > 0 && number < (EQ_NUM_HOTBAR_BUTTONS + 1))
            {
                g_CombatHotButtonIndex = number - 1;

                std::cout << "Combat HotButton: " << number << std::endl;
            }
        }

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AlwaysHotButton ") == true || EQAPP_String_BeginsWith(commandText, "//AHB ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            signed int number = std::stoi(numberStr);

            if (number > 0 && number < (EQ_NUM_HOTBAR_BUTTONS + 1))
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

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindName ") == true)
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

    if (EQAPP_String_BeginsWith(commandText, "//ESPFindLastName ") == true)
    {
        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            g_ESPFindSpawnLastName = name;

            std::cout << "ESP Find Spawn Last Name: " << name << std::endl;
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
        std::string spawnLevelStr = EQAPP_String_GetAfter(commandText, " ");
        if (spawnLevelStr.size() != 0)
        {
            uint32_t spawnLevel = std::stoul(spawnLevelStr);

            g_ESPFindSpawnLevel = spawnLevel;

            std::cout << "ESP Find Spawn Level: " << g_ESPFindSpawnLevel << std::endl;
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
        std::string spawnRaceStr = EQAPP_String_GetAfter(commandText, " ");
        if (spawnRaceStr.size() != 0)
        {
            uint32_t spawnRace = std::stoul(spawnRaceStr);

            g_ESPFindSpawnRace = spawnRace;

            std::cout << "ESP Find Spawn Race: " << g_ESPFindSpawnRace << std::endl;
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
        std::string spawnClassStr = EQAPP_String_GetAfter(commandText, " ");
        if (spawnClassStr.size() != 0)
        {
            uint32_t spawnClass = std::stoul(spawnClassStr);

            g_ESPFindSpawnClass = spawnClass;

            std::cout << "ESP Find Spawn Class: " << g_ESPFindSpawnClass << std::endl;
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

    if (EQAPP_String_BeginsWith(commandText, "//Multiline ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//MultilineRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Cast ") == true)
    {
        std::string numberStr = EQAPP_String_GetAfter(commandText, " ");
        if (numberStr.size() != 0)
        {
            signed int number = std::stoi(numberStr);

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

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//CastRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/cast ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DoAbility ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DoAbilityRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/doability ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//Discipline ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//DisciplineRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/discipline ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AltActivate ") == true)
    {
        EQAPP_InterpretCmd_InterpretArguments(commandText, "/alt activate ");

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//AltActivateRandom ") == true)
    {
        EQAPP_InterpretCmd_InterpretArgumentsRandom(commandText, "/alt activate ");

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

            std::cout << "Box Chat Set to Channel '" << name << "'" << std::endl;
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

        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            EQAPP_BoxChat_SendText(commandText);

            std::cout << "Box Chat to '" << name << "': " << commandText << std::endl;
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

        std::string name = EQAPP_String_GetAfter(commandText, " ");
        if (name.size() != 0)
        {
            EQAPP_BoxChat_SendText(commandText);

            std::cout << "Box Chat to Channel '" << name << "': " << commandText << std::endl;
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

        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to Others: " << commandText << std::endl;

        return true;
    }

    if (EQAPP_String_BeginsWith(commandText, "//BoxChatAll ") == true || EQAPP_String_BeginsWith(commandText, "//BCAA ") == true)
    {
        if (g_BoxChatIsConnected == false)
        {
            std::cout << "Error: You must first connect to the Box Chat server!" << std::endl;
            return true;
        }

        EQAPP_BoxChat_SendText(commandText);

        std::cout << "Box Chat to All: " << commandText << std::endl;

        return true;
    }

    if (commandText == "//SpawnList")
    {
        std::cout << "Spawn List:" << std::endl;

        auto spawn = EQ_GetFirstSpawn();

        while (spawn != NULL)
        {
            std::stringstream ss;

            if (EQ_GetSpawnClass(spawn) == EQ_CLASS_OBJECT)
            {
                ss << "* ";
            }

            ss << "[" << EQ_GetSpawnLevel(spawn) << "]";

            auto spawnName = EQ_GetSpawnName(spawn);
            if (spawnName.size() != 0)
            {
                ss << " " << spawnName;
            }

            auto spawnType = EQ_GetSpawnType(spawn);
            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                auto spawnLastName = EQ_GetSpawnLastName(spawn);
                if (spawnLastName.size() != 0)
                {
                    ss << " (" << spawnLastName << ")";
                }
            }

            ss << " -";

            ss << " Type=" << spawnType;
            ss << " Race=" << EQ_GetSpawnRace(spawn);
            ss << " Class=" << EQ_GetSpawnClass(spawn);
            ss << " Height=" << EQ_GetSpawnHeight(spawn);

            std::cout << ss.str() << std::endl;

            spawn = EQ_GetSpawnNext(spawn);
        }

        return true;
    }

    if (commandText == "//Location" || commandText == "//Loc")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
            auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
            auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

            std::cout << "Your location is " << playerSpawnY << ", " << playerSpawnX << ", " << playerSpawnZ << "." << std::endl;
        }

        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            auto targetSpawnY = EQ_GetSpawnY(targetSpawn);
            auto targetSpawnX = EQ_GetSpawnX(targetSpawn);
            auto targetSpawnZ = EQ_GetSpawnZ(targetSpawn);

            std::cout << "Your target's location is " << targetSpawnY << ", " << targetSpawnX << ", " << targetSpawnZ << "." << std::endl;
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
            if (EQAPP_String_Contains(commandTextAfterSpace, ",") == true)
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
                        ss << " " << token;
                    }

                    EQ_InterpretCommand(ss.str().c_str());
                }
            }
        }

        return true;
    }

    if (commandText == "//PrintScriptFolder" || commandText == "//Script")
    {
        std::cout << "Scripts:" << std::endl;

        EQAPP_Lua_ScriptFolder_Print();

        return true;
    }

    if (commandText == "//LoadEventScriptList")
    {
        EQAPP_Lua_EventScriptList_Load();
        EQAPP_Lua_EventScriptList_Print();

        return true;
    }

    if (commandText == "//PrintEventScriptList")
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

    return false;
}
