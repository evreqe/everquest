#pragma once

#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_esp.h"
#include "eqapp_followai.h"
#include "eqapp_findpath.h"
#include "eqapp_fps.h"
#include "eqapp_hud.h"
#include "eqapp_lua.h"
#include "eqapp_namecolor.h"
#include "eqapp_namedspawns.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_speed.h"
#include "eqapp_windowtitle.h"
#include "eqapp_waypoint.h"

template <class T>
void EQAPP_LoadOption(T& option, const char* optionName, boost::property_tree::ptree& pt);
void EQAPP_LoadOptions();

template <class T>
void EQAPP_LoadOption(T& option, const char* optionName, boost::property_tree::ptree& pt)
{
    std::stringstream ssOptionName;
    ssOptionName << "Options." << optionName;

    boost::optional<T> result = pt.get_optional<T>(ssOptionName.str().c_str());
    if (result)
    {
        option = result.get();

        std::stringstream ssDebugText;
        ssDebugText << optionName << "=" << option;

        EQAPP_PrintDebugText(__FUNCTION__, ssDebugText.str().c_str());
    }
}

void EQAPP_LoadOptions()
{
    std::stringstream ssFileName;
    ssFileName << g_EQAppName << ".ini";

    boost::property_tree::ptree pt;
    boost::property_tree::read_ini(ssFileName.str().c_str(), pt);

    EQAPP_LoadOption<bool>(g_EQAppDebugTextIsEnabled, "bDebugText", pt);

    EQAPP_LoadOption<int>(g_EQAppKillSwitchKey, "iKillSwitchKey", pt);

    EQAPP_LoadOption<bool>(g_ActorCollisionIsEnabled, "bActorCollision", pt);

    EQAPP_LoadOption<bool>(g_AlwaysAttackIsEnabled, "bAlwaysAttack", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AlwaysAttackTimerInterval, "iAlwaysAttackTimerInterval", pt);
    EQAPP_LoadOption<float>(g_AlwaysAttackDistance, "fAlwaysAttackDistance", pt);

    EQAPP_LoadOption<bool>(g_AlwaysHotButtonIsEnabled, "bAlwaysHotButton", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AlwaysHotButtonTimerInterval, "iAlwaysHotButtonTimerInterval", pt);
    EQAPP_LoadOption<signed int>(g_AlwaysHotButtonIndex, "iAlwaysHotButtonIndex", pt);

    ////EQAPP_LoadOption<bool>(g_AutoAlternateAbilityIsEnabled, "bAutoAlternateAbility", pt);
    ////EQAPP_LoadOption<EQApp::TimerInterval>(g_AutoAlternateAbilityTimerInterval, "iAutoAlternateAbilityTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_AutoGroupIsEnabled, "bAutoGroup", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AutoGroupTimerInterval, "iAutoGroupTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_BazaarBotIsEnabled, "bBazaarBot", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_BazaarBotFindItemsTimerInterval, "iBazaarBotFindItemsTimerInterval", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_BazaarBotBuyItemsTimerInterval, "iBazaarBotBuyItemsTimerInterval", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_BazaarBotToParcelsTimerInterval, "iBazaarBotToParcelsTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_BazaarFilterIsEnabled, "bBazaarFilter", pt);
    EQAPP_LoadOption<bool>(g_BazaarFilterBeepIsEnabled, "bBazaarFilterBeep", pt);
    EQAPP_LoadOption<uint32_t>(g_BazaarFilterItemPriceMinimum, "iBazaarFilterItemPriceMinimum", pt);
    EQAPP_LoadOption<uint32_t>(g_BazaarFilterItemPriceMaximum, "iBazaarFilterItemPriceMaximum", pt);

    EQAPP_LoadOption<bool>(g_BoxChatIsEnabled, "bBoxChat", pt);
    EQAPP_LoadOption<bool>(g_BoxChatAutoConnectIsEnabled, "bBoxChatAutoConnect", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_BoxChatAutoConnectTimerInterval, "iBoxChatAutoConnectTimerInterval", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_BoxChatKeepAliveTimerInterval, "iBoxChatKeepAliveTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_ChangeHeightIsEnabled, "bChangeHeight", pt);

    EQAPP_LoadOption<bool>(g_FollowAIIsEnabled, "bFollowAI", pt);
    EQAPP_LoadOption<float>(g_FollowAIDistancePlayer, "fFollowAIDistancePlayer", pt);
    EQAPP_LoadOption<float>(g_FollowAIDistanceNPC, "fFollowAIDistanceNPC", pt);
    EQAPP_LoadOption<float>(g_FollowAIDistanceCorpse, "fFollowAIDistanceCorpse", pt);
    EQAPP_LoadOption<float>(g_FollowAIDistanceBehind, "fFollowAIDistanceBehind", pt);

    ////EQAPP_LoadOption<bool>(g_CombatAlternateAbilityIsEnabled, "bCombatAlternateAbility", pt);
    ////EQAPP_LoadOption<EQApp::TimerInterval>(g_CombatAlternateAbilityTimerInterval, "iCombatAlternateAbilityTimerInterval", pt);
    ////EQAPP_LoadOption<float>(g_CombatAlternateAbilityDistance, "fCombatAlternateAbilityDistance", pt);

    EQAPP_LoadOption<bool>(g_CombatHotButtonIsEnabled, "bCombatHotButton", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_CombatHotButtonTimerInterval, "iCombatHotButtonTimerInterval", pt);
    EQAPP_LoadOption<signed int>(g_CombatHotButtonIndex, "iCombatHotButtonIndex", pt);
    EQAPP_LoadOption<float>(g_CombatHotButtonDistance, "fCombatHotButtonDistance", pt);

    EQAPP_LoadOption<bool>(g_ConsolePrintIsEnabled, "bConsolePrint", pt);

    EQAPP_LoadOption<bool>(g_ESPIsEnabled, "bESP", pt);
    EQAPP_LoadOption<bool>(g_ESPHeightFilterIsEnabled, "bESPHeightFilter", pt);
    EQAPP_LoadOption<bool>(g_ESPShowSpawnIDIsEnabled, "bESPShowSpawnID", pt);
    EQAPP_LoadOption<bool>(g_ESPShowSpawnRaceIsEnabled, "bESPShowSpawnRace", pt);
    EQAPP_LoadOption<bool>(g_ESPShowSpawnClassIsEnabled, "bESPShowSpawnClass", pt);
    EQAPP_LoadOption<bool>(g_ESPShowDoorsIsEnabled, "bESPShowDoors", pt);
    EQAPP_LoadOption<float>(g_ESPHeightFilterDistanceLow, "fESPHeightFilterDistanceLow", pt);
    EQAPP_LoadOption<float>(g_ESPHeightFilterDistanceHigh, "fESPHeightFilterDistanceHigh", pt);

    EQAPP_LoadOption<bool>(g_FindPathIsEnabled, "bFindPath", pt);
    EQAPP_LoadOption<float>(g_FindPathFollowPathDistance, "fFindPathFollowPathDistance", pt);

    EQAPP_LoadOption<bool>(g_FPSIsEnabled, "bFPS", pt);

    EQAPP_LoadOption<bool>(g_HUDIsEnabled, "bHUD", pt);
    EQAPP_LoadOption<uint32_t>(g_HUDXDefault, "iHUDX", pt);
    EQAPP_LoadOption<uint32_t>(g_HUDYDefault, "iHUDY", pt);

    EQAPP_LoadOption<bool>(g_LuaIsEnabled, "bLua", pt);

    EQAPP_LoadOption<bool>(g_NamedSpawnsIsEnabled, "bNamedSpawns", pt);

    EQAPP_LoadOption<uint32_t>(g_SleepIntervalForeground, "iSleepIntervalForeground", pt);
    EQAPP_LoadOption<uint32_t>(g_SleepIntervalBackground, "iSleepIntervalBackground", pt);

    EQAPP_LoadOption<bool>(g_SpawnCastSpellIsEnabled, "bSpawnCastSpell", pt);
    EQAPP_LoadOption<bool>(g_SpawnCastSpellGroupChatIsEnabled, "bSpawnCastSpellGroupChat", pt);
    EQAPP_LoadOption<bool>(g_SpawnCastSpellESPIsEnabled, "bSpawnCastSpellESP", pt);
    EQAPP_LoadOption<uint32_t>(g_SpawnCastSpellDrawTextX, "iSpawnCastSpellDrawTextX", pt);
    EQAPP_LoadOption<uint32_t>(g_SpawnCastSpellDrawTextY, "iSpawnCastSpellDrawTextY", pt);

    EQAPP_LoadOption<bool>(g_SpeedIsEnabled, "bSpeed", pt);
    EQAPP_LoadOption<float>(g_SpeedMultiplier, "fSpeedMultiplier", pt);

    EQAPP_LoadOption<bool>(g_WindowTitleIsEnabled, "bWindowTitle", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_WindowTitleTimerInterval, "iWindowTitleTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_WaypointIsEnabled, "bWaypoint", pt);
}
