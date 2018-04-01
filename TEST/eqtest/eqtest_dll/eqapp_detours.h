#pragma once

void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();

EQ_MACRO_FUNCTION_DefineDetour(CrashDetected);
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__ChangeHeight);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__StartCasting);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);

EQ_MACRO_FUNCTION_DefineDetour(CBazaarSearchWnd__AddItemToList);

EQ_MACRO_FUNCTION_DefineDetour(CBazaarConfirmationWnd__WndNotification);

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected();
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangeHeight(void* this_ptr, void* not_used, float height, float a2, float a3, int a4);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQMessage::CEverQuest__StartCasting_ptr message);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarConfirmationWnd__WndNotification(void* this_ptr, void* not_used, uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);

void EQAPP_Detours_Load()
{
    EQ_MACRO_FUNCTION_AddDetour(CrashDetected);
    EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);
    ////EQ_MACRO_FUNCTION_AddDetour(EQPlayer__ChangeHeight);

    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__StartCasting);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__dsp_chat);

    EQ_MACRO_FUNCTION_AddDetour(CBazaarSearchWnd__AddItemToList);

    ////EQ_MACRO_FUNCTION_AddDetour(CBazaarConfirmationWnd__WndNotification);
}

void EQAPP_Detours_Unload()
{
    EQ_MACRO_FUNCTION_RemoveDetour(CrashDetected);
    EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);
    ////EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);

    EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);
    ////EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__ChangeHeight);

    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__InterpretCmd);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__StartCasting);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__dsp_chat);

    EQ_MACRO_FUNCTION_RemoveDetour(CBazaarSearchWnd__AddItemToList);

    ////EQ_MACRO_FUNCTION_RemoveDetour(CBazaarConfirmationWnd__WndNotification);
}

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected()
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CrashDetected();
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        std::cout << "********** CRASH DETECTED **********" << std::endl;
    }

    return EQAPP_REAL_FUNCTION_CrashDetected();
}

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();

        g_EQAppIsInGame = true;
    }

    // kill switch
    if (GetAsyncKeyState(g_EQAppKillSwitchKey))
    {
        EQAPP_Unload();
        EQAPP_Console_Print();
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    g_EQAppPlayerName = EQ_GetPlayerSpawnName();

    if (EQAPP_Timer_HasTimeElapsed(g_EQAppWindowTitleTimer, g_EQAppWindowTitleTimerInterval) == true)
    {
        EQAPP_SetWindowTitleToPlayerSpawnName();

        EQ_InterpretCommand("/fontface Arial"); // April Fool's fix
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_BoxChat_Execute();
        }
        else
        {
            if (g_BoxChatAutoConnect == true)
            {
                if (EQAPP_Timer_HasTimeElapsed(g_BoxChatAutoConnectTimer, g_BoxChatAutoConnectTimerInterval) == true)
                {
                    if (EQAPP_BoxChat_IsServerRunning() == true)
                    {
                        if (g_EQAppPlayerName.size() != 0)
                        {
                            EQAPP_BoxChat_Connect(g_EQAppPlayerName);
                        }
                    }
                }
            }
        }
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
    }

    if (g_HUDIsEnabled == true)
    {
        EQAPP_HUD_Execute();
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_BoxChat_Execute();
        }
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Execute();
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        EQAPP_AlwaysHotButton_Execute();
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_CombatHotButton_Execute();
    }

    if (g_AutoAlternateAbilityIsEnabled == true)
    {
        EQAPP_AutoAlternateAbility_Execute();
    }

    if (g_CombatAlternateAbilityIsEnabled == true)
    {
        EQAPP_CombatAlternateAbility_Execute();
    }

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_Execute();
    }

    EQAPP_Console_Print();

    return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

    std::cout << "ExecuteCmd(): " << commandID << " (Active: " << isActive << ") " << zero << std::endl;

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

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
        EQAPP_SpawnCastSpell_DrawText();
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Execute();
        return 1;
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangeHeight(void* this_ptr, void* not_used, float height, float a2, float a3, int a4)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangeHeight(this_ptr, height, a2, a3, a4);
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        if ((uint32_t)this_ptr == playerSpawn)
        {
            std::cout << "EQPlayer__ChangeHeight(): " << height << ", " << a2 << ", " << a3 << ", " << a4;
        }
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__ChangeHeight(this_ptr, height, a2, a3, a4);
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

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQMessage::CEverQuest__StartCasting_ptr message)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

/*
    auto spawn = EQ_GetSpawnByID(message->SpawnID);

    std::string spawnName = EQ_GetSpawnName(spawn);

    std::string spellName = EQAPP_SpellList_GetNameByID(message->SpellID);

    std::cout << "---- CEverQuest::StartCasting() ----" << std::endl;
    std::cout << "Spawn ID: " << message->SpawnID << " (" << spawnName << ")" << std::endl;
    std::cout << "Spell ID: " << message->SpellID << " <" << spellName << ">" << std::endl;
    std::cout << "Spell Cast Time: " << message->SpellCastTime << std::endl;
    std::cout << "------------------------------------" << std::endl;
*/

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(this_ptr, message);
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, one_1, one_2, zero_1);
    }

    std::string chatText = text;

    ////EQAPP_Log(chatText.c_str(), textColor);

    int result = EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, one_1, one_2, zero_1);

    if (EQAPP_String_StartsWith(chatText, "LOADING, PLEASE WAIT...") == true)
    {
        g_EQAppIsInGame = false;
    }

    if (EQAPP_String_StartsWith(chatText, "You have entered") == true)
    {
        g_EQAppIsInGame = true;
    }

    if (g_BazaarBotIsEnabled == true)
    {
        if (EQAPP_String_StartsWith(chatText, "Your attempt to purchase") == true)
        {
            if (EQAPP_String_Contains(chatText, "failed because your bazaar data is out of date.") == true)
            {
                if (EQ_BazaarSearchWindow_IsOpen() == true)
                {
                    g_BazaarBotFindItemsTimer = EQAPP_Timer_GetTimeNow();

                    EQ_BazaarSearchWindow_ClickFindItemsButton();
                }
            }

            if (EQAPP_String_Contains(chatText, "failed because you already possess that lore item.") == true)
            {
                signed int buyItemListIndex = EQ_BazaarSearchWindow_GetBuyItemListIndex();
                if (buyItemListIndex != -1)
                {
                    std::string itemName = EQ_BazaarSearchWindow_GetItemName(buyItemListIndex);
                    if (itemName.size() != 0)
                    {
                        g_BazaarBotLoreItemsList.push_back(itemName);

                        std::cout << "[Bazaar Bot] " << itemName << " added to the lore items list." << std::endl;
                    }
                }
            }
        }
    }

/*
    // Drunkard's Stein anniversary quest
    if (EQAPP_String_Contains(chatText, "Galdorin Visigothe says") == true)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL)
        {
            std::string targetSpawnName = EQ_GetSpawnName(targetSpawn);
            if (EQAPP_String_Contains(targetSpawnName, "Galdorin Visigothe") == true)
            {
                if (EQAPP_String_Contains(chatText, "My stinky stein has rough dirty lips,") == true)
                {
                    EQ_InterpretCommand("/say My stinky stein has rough dirty lips,");
                }

                if (EQAPP_String_Contains(chatText, "but she loves a deep carouse.") == true)
                {
                    EQ_InterpretCommand("/say but she loves a deep carouse.");
                }

                if (EQAPP_String_Contains(chatText, "Beer or ale are her great trips.") == true)
                {
                    EQ_InterpretCommand("/say Beer or ale are her great trips.");
                }

                if (EQAPP_String_Contains(chatText, "No matter how many vows") == true)
                {
                    EQ_InterpretCommand("/say No matter how many vows");
                }

                if (EQAPP_String_Contains(chatText, "I make or break, my drinking glass") == true)
                {
                    EQ_InterpretCommand("/say I make or break, my drinking glass");
                }

                if (EQAPP_String_Contains(chatText, "reminds me of my lovely Brasse.") == true)
                {
                    EQ_InterpretCommand("/say reminds me of my lovely Brasse.");
                }
            }
        }
    }
*/

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
    }

    ////std::cout << "CBazaarSearchWnd::AddItemToList(): " << itemName << "^" << itemPrice << "^" << traderName << "^" << a4 << "^"  << a5 << "^" << a6 << "^" << a7 << "^" << a8 <<  "^" << a10 << std::endl;

    if (g_BazaarFilterIsEnabled == true)
    {
        bool bShouldAddItemToList = EQAPP_BazaarFilter_HandleEvent_CBazaarSearchWnd__AddItemToList(itemName, itemPrice, traderName);
        if (bShouldAddItemToList == false)
        {
            return 1;
        }
    }

    if (g_BazaarBotIsEnabled == true)
    {
        std::string itemNameStr = itemName;

        for (auto& loreItemName : g_BazaarBotLoreItemsList)
        {
            if (itemNameStr == loreItemName)
            {
                std::cout << "[Bazaar Bot] " << itemName << " was NOT added to the search list because it was found in the lore items list." << std::endl;

                return 1;
            }
        }
    }

    return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarConfirmationWnd__WndNotification(void* this_ptr, void* not_used, uint32_t xwndAddress, uint32_t xwndMessage, void* unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CBazaarConfirmationWnd__WndNotification(this_ptr, xwndAddress, xwndMessage, unknown);
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "CBazaarConfirmationWnd::WndNotification() XWnd: " << std::hex << xwndAddress << std::dec << std::endl;
    std::cout << "CBazaarConfirmationWnd::WndNotification() Message: " << xwndMessage << std::endl;
    std::cout << "CBazaarConfirmationWnd::WndNotification() Unknown: " << unknown << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return EQAPP_REAL_FUNCTION_CBazaarConfirmationWnd__WndNotification(this_ptr, xwndAddress, xwndMessage, unknown);
}
