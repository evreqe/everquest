#pragma once

bool g_HUDIsEnabled = true;

uint32_t g_HUDXDefault = 8;
uint32_t g_HUDYDefault = 100;
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

    if (g_EQAppSleepIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- SLEEP!");
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_HUD_DrawText("- Box Chat Connected");
        }
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Always Attack");
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Always HotButton");
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Combat HotButton");
    }

    if (g_ESPIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- ESP");
    }

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Change Height");
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_HUD_DrawText("- Spawn Cast Spell");
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
