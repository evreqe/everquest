#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autoalternateability.h"
#include "eqapp_boxchat.h"
#include "eqapp_combatalternateability.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_esp.h"
#include "eqapp_followpath.h"
#include "eqapp_fps.h"
#include "eqapp_sleep.h"

bool g_HUDIsEnabled = true;

bool g_HUDDebugTextIsEnabled = false;

uint32_t g_HUDXDefault = 200;
uint32_t g_HUDYDefault = 10;

uint32_t g_HUDX = g_HUDXDefault;
uint32_t g_HUDY = g_HUDYDefault;

void EQAPP_HUD_Toggle();
void EQAPP_HUD_On();
void EQAPP_HUD_Off();
void EQAPP_HUD_DebugText_Toggle();
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

void EQAPP_HUD_Execute()
{
    fmt::MemoryWriter ssHUDText;

    g_HUDX = g_HUDXDefault;
    g_HUDY = g_HUDYDefault;

    if (g_HUDDebugTextIsEnabled == true)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
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

        return;
    }

    ssHUDText << "EQTEST\n";

    if (g_SleepIsEnabled == true)
    {
        ssHUDText << "- SLEEP!\n";
    }

    if (g_FPSIsEnabled == true)
    {
        ssHUDText << "- FPS: " << g_FPSValue << "\n";
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            ssHUDText << "- Box Chat: Connected (" << g_BoxChatChannelName << ")\n";
        }
    }

    if (g_FreeCameraIsEnabled == true)
    {
        ssHUDText << "- Free Camera\n";
    }

    if (g_FollowPathIsEnabled == true)
    {
        ssHUDText << "- Follow Path\n";
    }

    if (g_BazaarBotIsEnabled == true)
    {
        ssHUDText << "- Bazaar Bot\n";
    }

    if (g_BazaarFilterIsEnabled == true)
    {
        ssHUDText << "- Bazaar Filter\n";
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        ssHUDText << "- Always Attack\n";
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        fmt::MemoryWriter ss;
        ss << "- Always HotButton: " << g_AlwaysHotButtonIndex + 1 << "\n";

        ssHUDText << ss.c_str();
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        fmt::MemoryWriter ss;
        ss << "- Combat HotButton: " << g_CombatHotButtonIndex + 1 << "\n";

        ssHUDText << ss.c_str();
    }

    if (g_AutoAlternateAbilityIsEnabled == true)
    {
        ssHUDText << "- Auto Alternate Ability\n";
    }

    if (g_CombatAlternateAbilityIsEnabled == true)
    {
        ssHUDText << "- Combat Alternate Ability\n";
    }

    if (g_ESPIsEnabled == true)
    {
        ssHUDText << "- ESP\n";
    }

    if (g_ESPHeightFilterIsEnabled == true)
    {
        ssHUDText << "- ESP Height Filter\n";
    }

    if (g_ESPShowSpawnIDIsEnabled == true)
    {
        ssHUDText << "- ESP Show Spawn ID\n";
    }

    if (g_ESPShowSpawnRaceIsEnabled == true)
    {
        ssHUDText << "- ESP Show Spawn Race\n";
    }

    if (g_ESPShowSpawnClassIsEnabled == true)
    {
        ssHUDText << "- ESP Show Spawn Class\n";
    }

    if (g_ESPShowDoorsIsEnabled == true)
    {
        ssHUDText << "- ESP Show Doors\n";
    }

    if (g_FollowAIBehindIsEnabled == true)
    {
        ssHUDText << "- Follow AI Behind\n";
    }

    if (g_FollowAIUseZAxisIsEnabled == true)
    {
        ssHUDText << "- Follow AI Use Z-Axis\n";
    }

    EQ_DrawText(ssHUDText.c_str(), g_HUDX, g_HUDY);

/*
    if (g_ChangeHeightIsEnabled == true)
    {
        ssHUDText << "- Change Height\n");
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        ssHUDText << "- Spawn Cast Spell\n");
    }

    if (g_SpawnCastSpellGroupChatIsEnabled == true)
    {
        ssHUDText << "- Spawn Cast Spell Group Chat\n");
    }
*/

/*
    int drawX = 800;
    int drawY = 200;

    for (size_t i = 0; i < 32; i++)
    {
        std::stringstream ss;
        ss << i << " ^ Test123";

        EQ_DrawTextEx(ss.str().c_str(), drawX, drawY, i);

        drawY += 10;
    }
*/
}
