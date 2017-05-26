#pragma once

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();

EQ_FUNCTION_TYPE_DrawNetStatus EQAPP_REAL_DrawNetStatus = NULL;

EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd EQAPP_REAL_CEverQuest__InterpretCmd = NULL;

EQ_FUNCTION_TYPE_CEverQuest__dsp_chat EQAPP_REAL_CEverQuest__dsp_chat = NULL;

EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate EQAPP_REAL_EQ_Character__eqspa_movement_rate = NULL;

EQ_FUNCTION_TYPE_EQ_Character__CastSpell EQAPP_REAL_EQ_Character__CastSpell = NULL;

EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor EQAPP_REAL_CDisplay__CreatePlayerActor = NULL;
EQ_FUNCTION_TYPE_CDisplay__DeleteActor EQAPP_REAL_CDisplay__DeleteActor = NULL;

EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteState EQAPP_REAL_CDisplay__SetNameSpriteState = NULL;
EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteTint EQAPP_REAL_CDisplay__SetNameSpriteTint = NULL;

EQ_FUNCTION_TYPE_CDisplay__ToggleView EQAPP_REAL_CDisplay__ToggleView = NULL;

EQ_FUNCTION_TYPE_CBazaarSearchWnd__HandleBazaarMsg EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg = NULL;

EQ_FUNCTION_TYPE_CBuffWindow__RefreshBuffDisplay EQAPP_REAL_CBuffWindow__RefreshBuffDisplay = NULL;
EQ_FUNCTION_TYPE_CBuffWindow__PostDraw EQAPP_REAL_CBuffWindow__PostDraw = NULL;

EQ_FUNCTION_TYPE_CItemDisplayWnd__SetItem EQAPP_REAL_CItemDisplayWnd__SetItem = NULL;
EQ_FUNCTION_TYPE_CItemDisplayWnd__SetSpell EQAPP_REAL_CItemDisplayWnd__SetSpell = NULL;

EQ_FUNCTION_TYPE_CSpellBookWnd__StartSpellMemorization EQAPP_REAL_CSpellBookWnd__StartSpellMemorization = NULL;
EQ_FUNCTION_TYPE_CSpellBookWnd__FinishMemorizing EQAPP_REAL_CSpellBookWnd__FinishMemorizing = NULL;

EQ_FUNCTION_TYPE_CLootWnd__Deactivate EQAPP_REAL_CLootWnd__Deactivate = NULL;

EQ_FUNCTION_TYPE_CContainerMgr__OpenContainer EQAPP_REAL_CContainerMgr__OpenContainer = NULL;

EQ_FUNCTION_TYPE_CEverQuest__LMouseDown EQAPP_REAL_CEverQuest__LMouseDown = NULL;
EQ_FUNCTION_TYPE_CEverQuest__LMouseUp EQAPP_REAL_CEverQuest__LMouseUp = NULL;

EQ_FUNCTION_TYPE_HandleMouseWheel EQAPP_REAL_HandleMouseWheel = NULL;

EQ_FUNCTION_TYPE_ProcessMouseEvent EQAPP_REAL_ProcessMouseEvent = NULL;

EQ_FUNCTION_TYPE_ProcessKeyDown EQAPP_REAL_ProcessKeyDown = NULL;
EQ_FUNCTION_TYPE_ProcessKeyUp EQAPP_REAL_ProcessKeyUp = NULL;

EQ_FUNCTION_TYPE_ProcessMovementKeys EQAPP_REAL_ProcessMovementKeys = NULL;

EQ_FUNCTION_TYPE_AutoInventory EQAPP_REAL_AutoInventory = NULL;

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* a1, char* a2);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1);

int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, unsigned char a1, short a2, EQ::Item** a3, short a4);

int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr a1);

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1);

int __fastcall EQAPP_DETOUR_CDisplay__ToggleView(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndBazaarMsg_ptr message);

int __fastcall EQAPP_DETOUR_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOUR_CBuffWindow__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr a1, bool a2);
int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, short a1, bool a2, int a3);

int __fastcall EQAPP_DETOUR_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int a1, int a2, bool a3);
int __fastcall EQAPP_DETOUR_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, int a1, short a2);

int __fastcall EQAPP_DETOUR_CLootWnd__Deactivate(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr a1, int a2);

int __fastcall EQAPP_DETOUR_CEverQuest__LMouseDown(void* this_ptr, void* not_used, unsigned short a1, unsigned short a2);
int __fastcall EQAPP_DETOUR_CEverQuest__LMouseUp(void* this_ptr, void* not_used, unsigned short a1, unsigned short a2);

int __cdecl EQAPP_DETOUR_HandleMouseWheel(int a1);

int __cdecl EQAPP_DETOUR_ProcessMouseEvent(void);

int __cdecl EQAPP_DETOUR_ProcessKeyDown(int a1);
int __cdecl EQAPP_DETOUR_ProcessKeyUp(int a1);

int __cdecl EQAPP_DETOUR_ProcessMovementKeys(int a1);

int __cdecl EQAPP_DETOUR_AutoInventory(EQ::Character_ptr a1, EQ::Item** a2, short a3);

void EQAPP_Detours_Add()
{
    EQ_MACRO_AddDetour(DrawNetStatus);

    EQ_MACRO_AddDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_AddDetour(EQ_Character__CastSpell);

    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_AddDetour(CDisplay__ToggleView);

    EQ_MACRO_AddDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_AddDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_AddDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_AddDetour(CLootWnd__Deactivate);

    ////EQ_MACRO_AddDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_AddDetour(HandleMouseWheel);

    EQ_MACRO_AddDetour(ProcessMouseEvent);
}

void EQAPP_Detours_Remove()
{
    EQ_MACRO_RemoveDetour(DrawNetStatus);

    EQ_MACRO_RemoveDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_RemoveDetour(EQ_Character__CastSpell);

    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_RemoveDetour(CDisplay__ToggleView);

    EQ_MACRO_RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_RemoveDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_RemoveDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_RemoveDetour(CLootWnd__Deactivate);

    ////EQ_MACRO_RemoveDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_RemoveDetour(HandleMouseWheel);

    EQ_MACRO_RemoveDetour(ProcessMouseEvent);
}

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10)
{
    // a4 = x
    // a5 = y

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
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    EQ_DrawText("EQTAKP", 200, 6, EQ_TEXT_COLOR_PINK);

    // on changed zone event
    auto zoneID = EQ_GetZoneID();
    if (g_zoneID != zoneID && zoneID != 0)
    {
        g_zoneID = zoneID;

        EQAPP_Map_Load();
        EQAPP_AutoLoot_Load();
        EQAPP_NamedSpawns_Load();

        if (zoneID == EQ_ZONE_ID_FIELDOFBONE)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn != NULL)
            {
                if (playerSpawn->Class == EQ_CLASS_WARRIOR)
                {
                    g_alwaysAttackIsEnabled = true;
                }
            }
        }
        else
        {
            g_alwaysAttackIsEnabled = false;
        }
    }

    if (g_mapIsEnabled == true)
    {
        EQAPP_Map_Execute();
    }
    else
    {
        if (g_ESPIsEnabled == true)
        {
            EQAPP_ESP_Execute();
        }
    }

    if (g_autoLootIsEnabled == true)
    {
        EQAPP_AutoLoot_Execute();
    }

    if (g_alwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Execute();
    }

    if (g_changeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    if (g_maxSkillsIsEnabled == true)
    {
        EQAPP_MaxSkills_Execute();
    }

    if (g_useSkillsIsEnabled == true)
    {
        EQAPP_UseSkills_Execute();
    }

    if (g_foodAndDrinkIsEnabled == true)
    {
        EQAPP_FoodAndDrink_Execute();
    }

    // mouse fix
    if (EQ_CLASS_POINTER_IDirectInput8 != NULL && EQ_CLASS_POINTER_DInputMouse != NULL)
    {
        if (EQAPP_IsForegroundWindowCurrentProcessId() == true)
        {
            DIMOUSESTATE mouseState;
            HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
            if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
            {
                if (EQ_CLASS_POINTER_DInputMouse->Acquire() == DI_OK)
                {
                    SetCapture(GetForegroundWindow());
                    EQ_WriteChatText("Mouse Acquired.");
                }
            }
        }
    }
/*
        else
        {
            DIMOUSESTATE mouseState;
            HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
            if (result == DI_OK)
            {
                EQ_CLASS_POINTER_DInputMouse->Unacquire();
                ReleaseCapture();

                EQ_WriteChatText("Mouse UnAcquired.");
            }
        }
    }
*/

    // redraw the mouse cursor
    uint32_t mouseClickState = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_CLICK_STATE);
    if (mouseClickState != EQ_MOUSE_CLICK_STATE_RIGHT) // do not draw the cursor while mouse looking
    {
        EQ_CLASS_POINTER_CXWndManager->DrawCursor();
    }

    EQAPP_Console_Print();

    return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1)
{
    // a1 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);
    }

    int result = EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);

    if (g_speedHackIsEnabled == true)
    {
        EQAPP_SpeedHack_Execute();
    }

    return result;
}

int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, unsigned char a1, short a2, EQ::Item** a3, short a4)
{
    // a1 = gemIndex
    // a2 = spellID
    // a3 = item
    // a4 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__CastSpell(this_ptr, a1, a2, a3, a4);
    }

    if (g_standWhenCastSpellIsEnabled == true)
    {
        EQAPP_StandWhenCastSpell_Execute();
    }

    return EQAPP_REAL_EQ_Character__CastSpell(this_ptr, a1, a2, a3, a4);
}

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2)
{
    // a1 = spawn
    // a2 = show

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__SetNameSpriteState(this_ptr, a1, a2);
    }

    int result = EQAPP_REAL_CDisplay__SetNameSpriteState(this_ptr, a1, a2);

    if (g_nameSpriteStateIsEnabled == true && a2 != 0)
    {
        if (EQAPP_NameSpriteState_Execute(a1) == false)
        {
            return result;
        }
    }

    EQAPP_DETOUR_CDisplay__SetNameSpriteTint(this_ptr, not_used, a1);

    return result;
}

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1)
{
    // a1 = spawn

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__SetNameSpriteTint(this_ptr, a1);
    }

    int result = EQAPP_REAL_CDisplay__SetNameSpriteTint(this_ptr, a1);

    if (g_nameSpriteTintIsEnabled == true)
    {
        if (EQAPP_NameSpriteTint_Execute(a1) == false)
        {
            return result;
        }
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CDisplay__ToggleView(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__ToggleView(this_ptr);
    }

    uint32_t cameraView = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_CAMERA_VIEW);

    if (cameraView == EQ_CAMERA_VIEW_FIRST_PERSON || cameraView == EQ_CAMERA_VIEW_THIRD_PERSON_1 || cameraView == EQ_CAMERA_VIEW_THIRD_PERSON_2)
    {
        EQ_SetCameraView(EQ_CAMERA_VIEW_THIRD_PERSON_3);
    }

    return EQAPP_REAL_CDisplay__ToggleView(this_ptr);
}

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndBazaarMsg_ptr message)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);
    }

    int result = EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);

/*
    if (message->Action == EQ_BAZAAR_ACTION_SEARCH_RESULTS)
    {
        auto spawn = EQ_GetSpawnFromIDArray(message->SpawnIDArrayIndex);
        if (spawn != NULL)
        {
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Action: " << message->Action << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Quantity: " << message->ItemQuantity << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item ID: " << std::hex << message->ItemID << std::dec << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Seller Name: " << spawn->Name << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Price: " << EQ_CLASS_POINTER_CBazaarSearchWnd->GetPriceString(message->ItemValue) << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Name: " << message->ItemName << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
        }
    }
*/

    return result;
}

int __fastcall EQAPP_DETOUR_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CBuffWindow__RefreshBuffDisplay(this_ptr);
    }

    int result = EQAPP_REAL_CBuffWindow__RefreshBuffDisplay(this_ptr);

    if (g_buffTimersIsEnabled == true)
    {
        EQAPP_BuffTimers_RefreshBuffDisplay(this_ptr);
    }

    return result;
};

int __fastcall EQAPP_DETOUR_CBuffWindow__PostDraw(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CBuffWindow__PostDraw(this_ptr);
    }

    int result = EQAPP_REAL_CBuffWindow__PostDraw(this_ptr);

    if (g_buffTimersIsEnabled == true)
    {
        EQAPP_BuffTimers_PostDraw(this_ptr);
    }

    return result;
};

int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr a1, bool a2)
{
    // a1 = item
    // a2 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CItemDisplayWnd__SetItem(this_ptr, a1, a2);
    }

    int result = EQAPP_REAL_CItemDisplayWnd__SetItem(this_ptr, a1, a2);

    if (g_itemDisplayIsEnabled == true && g_itemDisplayItemsIsEnabled == true)
    {
        EQAPP_ItemDisplay_SetItem(a1);
    }

    return result;
}


int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, short a1, bool a2, int a3)
{
    // a1 = spellID
    // a2 = hasDescription
    // a3 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CItemDisplayWnd__SetSpell(this_ptr, a1, a2, a3);
    }

    int result = EQAPP_REAL_CItemDisplayWnd__SetSpell(this_ptr, a1, a2, a3);

    if (g_itemDisplayIsEnabled == true && g_itemDisplaySpellsIsEnabled == true)
    {
        EQAPP_ItemDisplay_SetSpell(a1, a2);
    }

    return result;
};

int __fastcall EQAPP_DETOUR_CLootWnd__Deactivate(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CLootWnd__Deactivate(this_ptr);
    }

    int result = EQAPP_REAL_CLootWnd__Deactivate(this_ptr);

    if (g_hideCorpseLootedIsEnabled == true)
    {
        EQAPP_HideCorpseLooted_Execute();
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr a1, int a2)
{
    // a1 = contaienr
    // a2 = inventorySlotIndex

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CContainerMgr__OpenContainer(this_ptr, a1, a2);
    }

    int result = EQAPP_REAL_CContainerMgr__OpenContainer(this_ptr, a1, a2);

    ////std::cout << "[CContainerMgr__OpenContainer] inventorySlotIndex: " << a2 << std::endl;

    return result;
}

int __cdecl EQAPP_DETOUR_HandleMouseWheel(int a1)
{
    // a1 = delta

    if (g_bExit == 1)
    {
        return EQAPP_REAL_HandleMouseWheel(a1);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_HandleMouseWheel(a1);
    }

    if (EQ_IsNetStatusEnabled() == false)
    {
        return EQAPP_REAL_HandleMouseWheel(a1);
    }

    if (EQ_IsMouseHoveringOverCXWnd() == true)
    {
        return EQAPP_REAL_HandleMouseWheel(a1);
    }

    int mouseWheelDelta = a1;

    EQAPP_Map_HandleMouseWheel(mouseWheelDelta);

    return EQAPP_REAL_HandleMouseWheel(a1);
}

int __cdecl EQAPP_DETOUR_ProcessMouseEvent(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_ProcessMouseEvent();
    }

    DIMOUSESTATE mouseState;
    HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
    if (result != DIERR_INPUTLOST && result != DIERR_NOTACQUIRED)
    {
        if (mouseState.rgbButtons[DINPUT_MOUSE_BUTTON_4] & 0x80)
        {
            EQ_OpenAllContainers();
        }
    }

    return EQAPP_REAL_ProcessMouseEvent();
}
