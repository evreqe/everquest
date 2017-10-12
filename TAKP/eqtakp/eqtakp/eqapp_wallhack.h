#pragma once

bool g_wallHackIsEnabled = false;

void EQAPP_WallHack_Toggle();

void EQAPP_WallHack_Toggle()
{
    EQ_ToggleBool(g_wallHackIsEnabled);
    EQAPP_PrintBool("Wall Hack", g_wallHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_wallHackIsEnabled);
}

