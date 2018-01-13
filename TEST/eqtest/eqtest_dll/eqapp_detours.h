#pragma once

void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();

EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);

EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__eqspa_movement_rate);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);

int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, int movementSpeed);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);

void EQAPP_Detours_Load()
{
    EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);

    ////EQ_MACRO_FUNCTION_AddDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);
}

void EQAPP_Detours_Unload()
{
    EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);

    ////EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__InterpretCmd);
}

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_EQAppKillSwitchKey))
    {
        EQAPP_Unload();
        EQAPP_Console_Print();
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    g_EQAppPlayerName = EQ_GetPlayerSpawnName();

    EQ_DrawText("EQTEST", 8, 100);

    if (EQAPP_HasTimeElapsed(g_EQAppWindowTitleTimer, g_EQAppWindowTitleTimerInterval) == true)
    {
        EQAPP_SetWindowTitleToPlayerSpawnName();
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQ_DrawText("- Connected", 8, 120);
        }

        EQAPP_BoxChat_Execute();
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Execute();

        EQ_DrawText("- Always Attack", 8, 140);
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_CombatHotButton_Execute();

        EQ_DrawText("- Combat HotButton", 8, 160);
    }

    if (g_ESPIsEnabled == true)
    {
        EQ_DrawText("- ESP", 8, 180);
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

    EQAPP_Console_Print();

    return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

/*
    if (commandID > EQ_EXECUTECMD_ID_LAST)
    {
        std::cout << "ExecuteCmd: " << commandID << " (Active: " << isActive << ")" << std::endl;
    }
*/

/*
    if (commandID >= EQ_EXECUTECMD_CAST1 && commandID <= EQ_EXECUTECMD_CAST14)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, 0);
            EQ_WriteMemory<uint32_t>(EQ_ADDRESS_AUTO_RUN, 0);
        }
    }
*/

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Execute();
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_1, 2.5f);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_2, 2.5f);

    int result = EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);

    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_1, 15.0f);
    EQ_WriteMemoryProtected<float>(EQ_ADDRESS_FOLLOW_DISTANCE_2, 30.0f);

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, int movementSpeed)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
    }

    // never snared, rooted or slowed below base movement speed
    if (movementSpeed < 0)
    {
        movementSpeed = 0;
    }

    ////std::cout << "movementSpeed: " << movementSpeed << std::endl;

    return EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (g_InterpretCmdIsEnabled == true)
    {
        bool result = EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(this_ptr, player, text);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
}
