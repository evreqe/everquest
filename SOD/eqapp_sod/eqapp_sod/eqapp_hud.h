#ifndef EQAPP_HUD_H
#define EQAPP_HUD_H

bool g_hudIsEnabled = true;
unsigned int g_hudX = 5;
unsigned int g_hudY = 28;
float g_hudWidth  = 127.0f;
float g_hudHeight = 0.0f;
DWORD g_hudTextColor = 0xFFFFFFFF;

void EQAPP_Hud_Execute();

void EQAPP_Hud_Execute()
{
    if (g_hudIsEnabled == false)
    {
        return;
    }

    float width  = g_hudWidth;
    float height = g_hudHeight;

    EQ_DrawQuad((float)g_hudX, (float)g_hudY, width, height, EQ_TOOLTIP_COLOR);

    unsigned int fontSize   = 2;
    unsigned int fontHeight = EQ_GetFontHeight(fontSize);

    unsigned int numDrawText = 0;

    std::stringstream ssDrawText;

    ssDrawText << "FPS: " << std::dec << (int)EQ_GetAverageFps() << "\n";
    numDrawText++;

    DWORD numPlayersInZone = EQ_GetNumPlayersInZone();
    if (numPlayersInZone != 0)
    {
        ssDrawText << "Players in Zone: " << numPlayersInZone << "\n";
        numDrawText++;
    }

    if (g_movementSpeedHackIsEnabled == true)
    {
        ssDrawText << "Movement Speed: " << g_movementSpeedHackModifier << "\n";
        numDrawText++;
    }

    if (g_freeCameraIsEnabled == true)
    {
        ssDrawText << "Free Camera is on.\n";
        numDrawText++;
    }

    if (EQ_IsAutoAttackEnabled() == true)
    {
        ssDrawText << "Auto Attack is on.\n";
        numDrawText++;
    }

    if (EQ_IsAutoFireEnabled() == true)
    {
        ssDrawText << "Auto Fire is on.\n";
        numDrawText++;
    }

    if (g_alwaysAttackIsEnabled == true)
    {
        ssDrawText << "Always Attack is on.\n";
        numDrawText++;
    }

    if (g_alwaysHotbuttonIsEnabled == true)
    {
        ssDrawText << "Always Hotbutton: " << g_alwaysHotbuttonNumber << " (" << g_alwaysHotbuttonTimerDelayInSeconds << "s)\n";
        numDrawText++;
    }

    if (g_combatHotbuttonIsEnabled == true)
    {
        ssDrawText << "Combat Hotbutton: " << g_combatHotbuttonNumber << " (" << g_combatHotbuttonTimerDelayInSeconds << "s)\n";
        numDrawText++;
    }

    if (g_targetBeepIsEnabled == true)
    {
        ssDrawText << "Target Beep: " << g_targetBeepName << " (" << g_targetBeepTimerDelayInSeconds << "s)\n";
        numDrawText++;
    }

    if (g_spawnBeepIsEnabled == true && g_spawnBeepName.size() != 0)
    {
        ssDrawText << "Spawn Beep: " << g_spawnBeepName << "\n";
        numDrawText++;
    }

    if (g_espLocatorIsEnabled == true)
    {
        ssDrawText << "Locator: " << g_espLocatorY << ", " << g_espLocatorX << ", " << g_espLocatorZ << "\n";
        numDrawText++;
    }

    if (g_espFindIsEnabled == true && g_espFindSpawnName.size() != 0)
    {
        ssDrawText << "Find: " << g_espFindSpawnName << " (" << g_espFindCount << ")\n";
        numDrawText++;
    }

    if (g_autoLootIsEnabled == true)
    {
        ssDrawText << "Auto Loot is on.\n";
        numDrawText++;

        for (auto& itemName : g_autoLootList)
        {
            ssDrawText << "AL Item: " << itemName << "\n";
            numDrawText++;
        }
    }

    if (g_debugIsEnabled == true)
    {
        ssDrawText << "Debug is on.\n";
        numDrawText++;

        ssDrawText << "ESP Num Draw Text: " << g_espNumDrawText << "\n";
        numDrawText++;
    }

    EQ_DrawText(ssDrawText.str().c_str(), g_hudX, g_hudY, g_hudTextColor, fontSize);

    if (numDrawText > 0)
    {
        g_hudHeight = (float)((numDrawText * fontHeight) + 2.0f);
    }
}

#endif // EQAPP_HUD_H
