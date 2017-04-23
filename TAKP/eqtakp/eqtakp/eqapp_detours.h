#pragma once

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();

EQ_FUNCTION_TYPE_DrawNetStatus EQAPP_REAL_DrawNetStatus = nullptr;

EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate EQAPP_REAL_EQ_Character__eqspa_movement_rate = nullptr;

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1);

void EQAPP_Detours_Add()
{
    EQAPP_REAL_DrawNetStatus = (EQ_FUNCTION_TYPE_DrawNetStatus)DetourFunction((PBYTE)EQ_ADDRESS_FUNCTION_DrawNetStatus, (PBYTE)EQAPP_DETOUR_DrawNetStatus);

    EQAPP_REAL_EQ_Character__eqspa_movement_rate = (EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)DetourFunction((PBYTE)EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate, (PBYTE)EQAPP_DETOUR_EQ_Character__eqspa_movement_rate);
}

void EQAPP_Detours_Remove()
{
    DetourRemove((PBYTE)EQAPP_REAL_DrawNetStatus, (PBYTE)EQAPP_DETOUR_DrawNetStatus);

    DetourRemove((PBYTE)EQAPP_REAL_EQ_Character__eqspa_movement_rate, (PBYTE)EQAPP_DETOUR_EQ_Character__eqspa_movement_rate);
}

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    if (g_bLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_killSwitchKey))
    {
        EQAPP_Unload();
    }

    EQ_DrawText("EQTAKP", 200, 6, EQ_TEXT_COLOR_PINK);

    //EQ_DrawLine(0, 0, 1024, 768, 0xFFFF0000);
    //EQ_DrawTooltipText("to be honest fam", 400, 400, EQ_ADDRESS_POINTER_FONT_ARIAL14);

    // redraw the cursor
    uint32_t mouseClickState = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_CLICK_STATE);
    if (mouseClickState != EQ_MOUSE_CLICK_STATE_RIGHT) // do not draw the cursor while mouse looking
    {
        EQ_CLASS_POINTER_CXWndManager->DrawCursor();
    }

    // print redirected std::cout to the console
    for (std::string text; std::getline(g_consoleStringStream, text, '\n');)
    {
        EQ_WriteChatText(text.c_str());
    }
    g_consoleStringStream.str(std::string());
    g_consoleStringStream.clear();

    return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);
    }

    int result = EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);

    if (g_speedHackIsEnabled == true)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != nullptr)
        {
            if (playerSpawn->Actor->MovementSpeedModifier < g_speedHackModifier)
            {
                playerSpawn->Actor->MovementSpeedModifier = g_speedHackModifier;
            }
        }
    }

    return result;
}