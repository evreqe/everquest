#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autoalternateability.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_boxchat.h"
#include "eqapp_combatalternateability.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_esp.h"
#include "eqapp_sleep.h"

bool g_HUDIsEnabled = true;

uint32_t g_HUDXDefault = 200;
uint32_t g_HUDYDefault = 10;
uint32_t g_HUDFontHeight = 12;

uint32_t g_HUDX = g_HUDXDefault;
uint32_t g_HUDY = g_HUDYDefault;

void EQAPP_HUD_Toggle();
void EQAPP_HUD_DrawText(const char* text);
void EQAPP_HUD_Execute();

void EQAPP_HUD_Toggle()
{
    EQ_ToggleBool(g_HUDIsEnabled);
    EQAPP_PrintBool("HUD", g_HUDIsEnabled);
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

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        std::stringstream ss1;
        ss1 << "- HP: " << EQ_GetSpawnHPPercent(playerSpawn) << "%";
        ss1 << " MP: " << EQ_GetSpawnManaPercent(playerSpawn) << "%";
        ss1 << " END: " << EQ_GetSpawnEndurancePercent(playerSpawn) << "%";

        EQAPP_HUD_DrawText(ss1.str().c_str());
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- SLEEP!");
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_HUD_DrawText("- Box Chat is connected");
        }
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

    if (g_BazaarFilterIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Bazaar Filter");
    }

    if (g_BazaarFilterBeepIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Bazaar Filter Beep");
    }

    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Bazaar Bot");
    }

/*
    int drawX = 800;
    int drawY = 200;

    for (size_t i = 0; i < 32; i++)
    {
        std::stringstream ss;
        ss << i << ": Testing123";

        EQ_DrawTextEx(ss.str().c_str(), drawX, drawY, i);

        drawY += 10;
    }
*/
}
