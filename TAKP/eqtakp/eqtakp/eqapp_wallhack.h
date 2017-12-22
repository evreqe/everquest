#pragma once

bool g_WallHackIsEnabled = false;

void EQAPP_WallHack_Toggle();

void EQAPP_WallHack_Toggle()
{
    EQ_ToggleBool(g_WallHackIsEnabled);
    EQAPP_PrintBool("Wall Hack", g_WallHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_WallHackIsEnabled);
}

