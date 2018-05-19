#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autoalternateability.h"
#include "eqapp_boxchat.h"
#include "eqapp_combatalternateability.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_esp.h"
#include "eqapp_sleep.h"

bool g_HUDIsEnabled = true;

bool g_HUDDebugTextIsEnabled = false;

uint32_t g_HUDXDefault = 200;
uint32_t g_HUDYDefault = 10;
uint32_t g_HUDFontHeight = 12;

uint32_t g_HUDX = g_HUDXDefault;
uint32_t g_HUDY = g_HUDYDefault;

void EQAPP_HUD_Toggle();
void EQAPP_HUD_On();
void EQAPP_HUD_Off();
void EQAPP_HUD_DebugText_Toggle();
void EQAPP_HUD_DrawText(const char* text);
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

void EQAPP_HUD_DrawText(const char* text)
{
    EQ_DrawText(text, g_HUDX, g_HUDY);

    g_HUDY += g_HUDFontHeight;
}

void EQAPP_HUD_Execute()
{
    g_HUDX = g_HUDXDefault;
    g_HUDY = g_HUDYDefault;

    EQAPP_HUD_DrawText("EQTEST");

    if (g_HUDDebugTextIsEnabled == true)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            std::stringstream ss;

            ss << "DEBUG\n";

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

            EQAPP_HUD_DrawText(ss.str().c_str());
        }

        return;
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- SLEEP!");
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_HUD_DrawText("- Box Chat: Connected");
        }
    }

    if (g_FreeCameraIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Free Camera");
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Always Attack");
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        std::stringstream ss;
        ss << "- Always HotButton: " << g_AlwaysHotButtonIndex + 1;

        EQAPP_HUD_DrawText(ss.str().c_str());
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        std::stringstream ss;
        ss << "- Combat HotButton: " << g_CombatHotButtonIndex + 1;

        EQAPP_HUD_DrawText(ss.str().c_str());
    }

    if (g_AutoAlternateAbilityIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Auto Alternate Ability");
    }

    if (g_CombatAlternateAbilityIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Combat Alternate Ability");
    }

    if (g_ESPIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP");
    }

    if (g_ESPHeightFilterIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP Height Filter");
    }

    if (g_ESPShowSpawnIDIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP Show Spawn ID");
    }

    if (g_ESPShowSpawnRaceIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP Show Spawn Race");
    }

    if (g_ESPShowSpawnClassIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP Show Spawn Class");
    }

    if (g_FollowAIUseZAxisIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Follow AI Use Z-Axis");
    }

/*
    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Change Height");
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Spawn Cast Spell");
    }

    if (g_SpawnCastSpellGroupChatIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Spawn Cast Spell Group Chat");
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
