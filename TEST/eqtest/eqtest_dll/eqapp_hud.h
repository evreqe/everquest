#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
////#include "eqapp_autoalternateability.h"
#include "eqapp_boxchat.h"
////#include "eqapp_combatalternateability.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_esp.h"
#include "eqapp_followpath.h"
#include "eqapp_fps.h"
#include "eqapp_lua.h"
#include "eqapp_sleep.h"
#include "eqapp_speed.h"

bool g_HUDIsEnabled = true;

bool g_HUDDebugTextIsEnabled = false;

fmt::MemoryWriter g_HUDText;

uint32_t g_HUDXDefault = 200;
uint32_t g_HUDYDefault = 10;

uint32_t g_HUDX = g_HUDXDefault;
uint32_t g_HUDY = g_HUDYDefault;

void EQAPP_HUD_Toggle();
void EQAPP_HUD_On();
void EQAPP_HUD_Off();
void EQAPP_HUD_DebugText_Toggle();
void EQAPP_HUD_DrawDebugText();
void EQAPP_HUD_AddText(const char* text);
void EQAPP_HUD_Execute();

void EQAPP_HUD_Toggle()
{
    EQ_ToggleBool(g_HUDIsEnabled);
    EQAPP_PrintBool("HUD", g_HUDIsEnabled);
}

void EQAPP_HUD_On()
{
    if (g_HUDIsEnabled == false)
    {
        EQAPP_HUD_Toggle();
    }
}

void EQAPP_HUD_Off()
{
    if (g_HUDIsEnabled == true)
    {
        EQAPP_HUD_Toggle();
    }
}

void EQAPP_HUD_DebugText_Toggle()
{
    EQ_ToggleBool(g_HUDDebugTextIsEnabled);
    EQAPP_PrintBool("HUD Debug Text", g_HUDDebugTextIsEnabled);
}

void EQAPP_HUD_DrawDebugText()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    fmt::MemoryWriter ss;

    ss << "EQTEST DEBUG\n";

    ss << "Name: " << EQ_GetSpawnName(targetSpawn) << "\n";
    ss << "Last Name: " << EQ_GetSpawnLastName(targetSpawn) << "\n";

    ss << "Name Numbered: " << EQ_GetSpawnNameNumbered(targetSpawn) << "\n";

    ss << "ID: " << EQ_GetSpawnID(targetSpawn) << "\n";

    auto spawnType = EQ_GetSpawnType(targetSpawn);
    ss << "Type: " << EQ_GetSpawnTypeNameByKey(spawnType) << " (" << spawnType << ")\n";

    ss << "Y: " << EQ_GetSpawnY(targetSpawn) << "\n";
    ss << "X: " << EQ_GetSpawnX(targetSpawn) << "\n";
    ss << "Z: " << EQ_GetSpawnZ(targetSpawn) << "\n";

    ss << "Heading: " << EQ_GetSpawnHeading(targetSpawn) << "\n";

    ss << "Movement Speed: " << EQ_GetSpawnMovementSpeed(targetSpawn) << "\n";

    ss << "Height: " << EQ_GetSpawnHeight(targetSpawn) << "\n";

    ss << "HP: " << EQ_GetSpawnHPCurrent(targetSpawn) << " / " << EQ_GetSpawnHPMax(targetSpawn) << " (" << EQ_GetSpawnHPPercent(targetSpawn) << "%)\n";
    ss << "Mana: " << EQ_GetSpawnManaCurrent(targetSpawn) << " / " << EQ_GetSpawnManaMax(targetSpawn) << " (" << EQ_GetSpawnManaPercent(targetSpawn) << "%)\n";
    ss << "Endurance: " << EQ_GetSpawnEnduranceCurrent(targetSpawn) << " / " << EQ_GetSpawnEnduranceMax(targetSpawn) << " (" << EQ_GetSpawnEndurancePercent(targetSpawn) << "%)\n";

    auto spawnZoneID = EQ_GetSpawnZoneID(targetSpawn);
    ss << "Zone Name: " << EQ_GetZoneNameByKey(spawnZoneID) << " (" << spawnZoneID << ")\n";

    ss << "Level: " << EQ_GetSpawnLevel(targetSpawn) << "\n";

    auto spawnRace = EQ_GetSpawnRace(targetSpawn);
    ss << "Race: " << EQ_GetRaceNameByKey(spawnRace) << " (" << spawnRace << ")\n";

    auto spawnClass = EQ_GetSpawnClass(targetSpawn);
    ss << "Class: " << EQ_GetClassNameByKey(spawnClass) << " (" << spawnClass << ")\n";

    auto spawnStandingState = EQ_GetSpawnStandingState(targetSpawn);
    ss << "Standing State: " << EQ_GetStandingStateNameByKey(spawnStandingState) << " (" << spawnStandingState << ")\n";

    auto followSpawn = EQ_GetSpawnFollowSpawn(targetSpawn);
    if (followSpawn != NULL)
    {
        ss << "Follow Name: " << EQ_GetSpawnName(followSpawn) << "\n";
    }

    EQ_DrawText(ss.c_str(), g_HUDX, g_HUDY);
}

void EQAPP_HUD_AddText(const char* text)
{
    g_HUDText << text << "\n";
}

void EQAPP_HUD_Execute()
{
    g_HUDText.clear();

    g_HUDX = g_HUDXDefault;
    g_HUDY = g_HUDYDefault;

    if (g_HUDDebugTextIsEnabled == true)
    {
        EQAPP_HUD_DrawDebugText();
        return;
    }

    g_HUDText << "EQTEST\n";

    if (g_SleepIsEnabled == true)
    {
        g_HUDText << "- SLEEP!\n";
    }

    if (g_FPSIsEnabled == true)
    {
        g_HUDText << "- FPS: " << g_FPSValue << "\n";
    }

    auto numClients = EQAPP_GetNumClients();
    if (numClients > 1)
    {
        g_HUDText << "- Clients: " << numClients << "\n";
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            g_HUDText << "- Box Chat: Connected (" << g_BoxChatChannelName << ")\n";
        }
    }

    if (g_FreeCameraIsEnabled == true)
    {
        g_HUDText << "- Free Camera\n";
    }

    if (g_FollowPathIsEnabled == true)
    {
        g_HUDText << "- Follow Path\n";
    }

    if (g_SpeedIsEnabled == true)
    {
        g_HUDText << "- Speed: " << g_SpeedMultiplier << "\n";
    }

    if (g_BazaarBotIsEnabled == true)
    {
        g_HUDText << "- Bazaar Bot\n";
    }

    if (g_BazaarFilterIsEnabled == true)
    {
        g_HUDText << "- Bazaar Filter\n";
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        g_HUDText << "- Always Attack\n";
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        g_HUDText << "- Always HotButton: " << g_AlwaysHotButtonIndex + 1 << "\n";
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        g_HUDText << "- Combat HotButton: " << g_CombatHotButtonIndex + 1 << "\n";
    }

    ////if (g_AutoAlternateAbilityIsEnabled == true)
    ////{
        ////g_HUDText << "- Auto Alternate Ability\n";
    ////}

    ////if (g_CombatAlternateAbilityIsEnabled == true)
    ////{
        ////g_HUDText << "- Combat Alternate Ability\n";
    ////}

    if (g_ESPIsEnabled == true)
    {
        g_HUDText << "- ESP\n";
    }

    if (g_ESPHeightFilterIsEnabled == true)
    {
        g_HUDText << "- ESP Height Filter\n";
    }

    if (g_ESPShowSpawnIDIsEnabled == true)
    {
        g_HUDText << "- ESP Show Spawn ID\n";
    }

    if (g_ESPShowSpawnRaceIsEnabled == true)
    {
        g_HUDText << "- ESP Show Spawn Race\n";
    }

    if (g_ESPShowSpawnClassIsEnabled == true)
    {
        g_HUDText << "- ESP Show Spawn Class\n";
    }

    if (g_ESPShowDoorsIsEnabled == true)
    {
        g_HUDText << "- ESP Show Doors\n";
    }

    if (g_FollowAIBehindIsEnabled == true)
    {
        g_HUDText << "- Follow AI Behind\n";
    }

    if (g_FollowAIUseZAxisIsEnabled == true)
    {
        g_HUDText << "- Follow AI Use Z-Axis\n";
    }

/*
    if (g_ChangeHeightIsEnabled == true)
    {
        g_HUDText << "- Change Height\n");
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        g_HUDText << "- Spawn Cast Spell\n");
    }

    if (g_SpawnCastSpellGroupChatIsEnabled == true)
    {
        g_HUDText << "- Spawn Cast Spell Group Chat\n");
    }
*/

    for (auto& script : g_LuaEventScriptList)
    {
        sol::protected_function luaFunction = script->LuaState["OnDrawHUD"];
        if (luaFunction.valid() == true)
        {
            sol::protected_function_result result = luaFunction();
            if (result.valid() == true)
            {
                int resultValue1 = result.get<int>(0);
                if (resultValue1 == 1)
                {
                    std::string resultValue2 = result.get<std::string>(1);
                    if (resultValue2.size() != 0)
                    {
                        EQAPP_HUD_AddText(resultValue2.c_str());
                    }
                }
            }
            else
            {
                std::cout << "Lua filename: " << script->Filename << std::endl;

                sol::error error = result;

                std::cout << "Lua error: " << error.what() << std::endl;
            }
        }
    }

    EQ_DrawText(g_HUDText.c_str(), g_HUDX, g_HUDY);
}
