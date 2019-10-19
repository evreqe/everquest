#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_boxchat.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_esp.h"
#include "eqapp_sleep.h"

bool g_HUDIsEnabled = true;

std::stringstream g_HUDText;

uint32_t g_HUDXDefault = 200;
uint32_t g_HUDYDefault = 10;

uint32_t g_HUDX = g_HUDXDefault;
uint32_t g_HUDY = g_HUDYDefault;

bool g_HUDPlayersInZoneIsEnabled = true;

bool g_HUDNearbyPlayersIsEnabled = true;

float g_HUDNearbyPlayersDistance = 30.0f;
float g_HUDNearbyPlayersDistanceZ = 20.0f;

void EQAPP_HUD_Toggle();
void EQAPP_HUD_On();
void EQAPP_HUD_Off();
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

void EQAPP_HUD_AddText(const char* text)
{
    g_HUDText << text << "\n";
}

void EQAPP_HUD_Execute()
{
    g_HUDText.str(std::string());
    g_HUDText.clear();

    g_HUDX = g_HUDXDefault;
    g_HUDY = g_HUDYDefault;

    g_HUDText << g_EQAppNameEx << "\n";

    if (g_SleepIsEnabled == true)
    {
        g_HUDText << "- SLEEP!\n";
    }

    auto numClients = EQAPP_GetNumClients();
    if (numClients > 1)
    {
        g_HUDText << "- Clients: " << numClients << "\n";
    }

    if (g_HUDPlayersInZoneIsEnabled == true)
    {
        auto numPlayersInZone = EQ_GetNumSpawnsInZone(EQ_SPAWN_TYPE_PLAYER);
        if (numPlayersInZone > 0)
        {
            g_HUDText << "- Players in Zone: " << numPlayersInZone << "\n";
        }
    }

    if (g_HUDNearbyPlayersIsEnabled == true)
    {
        auto numNearbyPlayers = EQ_GetNumNearbySpawns(EQ_SPAWN_TYPE_PLAYER, g_HUDNearbyPlayersDistance, g_HUDNearbyPlayersDistanceZ);
        if (numNearbyPlayers > 0)
        {
            g_HUDText << "- Nearby Players: " << numNearbyPlayers << "\n";
        }
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

    if (g_WaypointIsEnabled == true)
    {
        if (g_WaypointFollowPathIsEnabled == true)
        {
            g_HUDText << "- Waypoint Follow Path\n";
        }
    }

    if (g_SpeedIsEnabled == true)
    {
        g_HUDText << "- Speed: " << g_SpeedMultiplier << "\n";
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        g_HUDText << "- Always Attack";

        if (EQ_IsAutoAttackEnabled() == true)
        {
            g_HUDText << " (Auto-Attacking)";
        }

        g_HUDText << "\n";
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        g_HUDText << "- Always HotButton: " << g_AlwaysHotButtonIndex + 1 << "\n";
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        g_HUDText << "- Combat HotButton: " << g_CombatHotButtonIndex + 1 << "\n";
    }

    if (g_CombatMacroIsEnabled == true)
    {
        g_HUDText << "- Combat Macros: " << g_CombatMacroList.size() << "\n";
    }

    if (g_ESPIsEnabled == true)
    {
        g_HUDText << "- ESP\n";

        if (g_ESPHeightFilterIsEnabled == true)
        {
            g_HUDText << "- ESP Height Filter\n";
        }

        if (g_ESPFindSpawnName.size() != 0)
        {
            g_HUDText << "- ESP Find Spawn Name: " << g_ESPFindSpawnName << " (" << g_ESPFindSpawnNameCount << ")\n";
        }

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            g_HUDText << "- ESP Find Spawn Last Name: " << g_ESPFindSpawnLastName << " (" << g_ESPFindSpawnLastNameCount << ")\n";
        }

        if (g_ESPFindSpawnID != 0)
        {
            g_HUDText << "- ESP Find Spawn ID: " << g_ESPFindSpawnID << " (" << g_ESPFindSpawnIDCount << ")\n";
        }

        if (g_ESPFindSpawnLevel != 0)
        {
            g_HUDText << "- ESP Find Spawn Level: " << g_ESPFindSpawnLevel << " (" << g_ESPFindSpawnLevelCount << ")\n";
        }

        if (g_ESPShowSpawnIDIsEnabled == true)
        {
            g_HUDText << "- ESP Show Spawn ID\n";
        }
    }

    if (g_FollowAIIsEnabled == true)
    {
        if (g_FollowAIBehindIsEnabled == true)
        {
            g_HUDText << "- Follow AI Behind\n";
        }

        if (g_FollowAIUseZAxisIsEnabled == true)
        {
            g_HUDText << "- Follow AI Use Z-Axis\n";
        }
    }

    if (g_ChangeHeightIsEnabled == true)
    {
        g_HUDText << "- Change Height\n";
    }

    if (g_ChatEventIsEnabled == true)
    {
        g_HUDText << "- Chat Event (" << g_ChatEventList.size() << ")\n";
    }

    if (g_KillMobsIsEnabled == true)
    {
        g_HUDText << "- Kill Mobs (" << g_KillMobsList.size() << ")\n";
    }

    if (g_PowerLevelIsEnabled == true)
    {
        g_HUDText << "- Power Level: " << g_PowerLevelHPPercent << "%\n";
    }

    EQ_DrawText(g_HUDText.str().c_str(), g_HUDX, g_HUDY);
}
