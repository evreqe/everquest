#pragma once

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();

EQ_FUNCTION_TYPE_DrawNetStatus EQAPP_REAL_DrawNetStatus = nullptr;

EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd EQAPP_REAL_CEverQuest__InterpretCmd = nullptr;

EQ_FUNCTION_TYPE_CEverQuest__dsp_chat EQAPP_REAL_CEverQuest__dsp_chat = nullptr;

EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate EQAPP_REAL_EQ_Character__eqspa_movement_rate = nullptr;

EQ_FUNCTION_TYPE_EQ_Character__CastSpell EQAPP_REAL_EQ_Character__CastSpell = nullptr;

EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor EQAPP_REAL_CDisplay__CreatePlayerActor = nullptr;
EQ_FUNCTION_TYPE_CDisplay__DeleteActor EQAPP_REAL_CDisplay__DeleteActor = nullptr;

EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteState EQAPP_REAL_CDisplay__SetNameSpriteState = nullptr;
EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteTint EQAPP_REAL_CDisplay__SetNameSpriteTint = nullptr;

EQ_FUNCTION_TYPE_CBuffWindow__RefreshBuffDisplay EQAPP_REAL_CBuffWindow__RefreshBuffDisplay = nullptr;
EQ_FUNCTION_TYPE_CBuffWindow__PostDraw EQAPP_REAL_CBuffWindow__PostDraw = nullptr;

EQ_FUNCTION_TYPE_CItemDisplayWnd__SetItem EQAPP_REAL_CItemDisplayWnd__SetItem = nullptr;
EQ_FUNCTION_TYPE_CItemDisplayWnd__SetSpell EQAPP_REAL_CItemDisplayWnd__SetSpell = nullptr;

EQ_FUNCTION_TYPE_CSpellBookWnd__StartSpellMemorization EQAPP_REAL_CSpellBookWnd__StartSpellMemorization = nullptr;
EQ_FUNCTION_TYPE_CSpellBookWnd__FinishMemorizing EQAPP_REAL_CSpellBookWnd__FinishMemorizing = nullptr;

EQ_FUNCTION_TYPE_CLootWnd__Deactivate EQAPP_REAL_CLootWnd__Deactivate = nullptr;

EQ_FUNCTION_TYPE_CEverQuest__LMouseDown EQAPP_REAL_CEverQuest__LMouseDown = nullptr;
EQ_FUNCTION_TYPE_CEverQuest__LMouseUp EQAPP_REAL_CEverQuest__LMouseUp = nullptr;

EQ_FUNCTION_TYPE_HandleMouseWheel EQAPP_REAL_HandleMouseWheel = nullptr;

EQ_FUNCTION_TYPE_ProcessMouseEvent EQAPP_REAL_ProcessMouseEvent = nullptr;

EQ_FUNCTION_TYPE_ProcessKeyDown EQAPP_REAL_ProcessKeyDown = nullptr;
EQ_FUNCTION_TYPE_ProcessKeyUp EQAPP_REAL_ProcessKeyUp = nullptr;

EQ_FUNCTION_TYPE_ProcessMovementKeys EQAPP_REAL_ProcessMovementKeys = nullptr;

EQ_FUNCTION_TYPE_AutoInventory EQAPP_REAL_AutoInventory = nullptr;

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* a1, char* a2);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1);

int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, unsigned char a1, short a2, EQ::Item** a3, short a4);

int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr a1);

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1);

int __fastcall EQAPP_DETOUR_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOUR_CBuffWindow__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr a1, bool a2);
int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, short a1, bool a2, int a3);

int __fastcall EQAPP_DETOUR_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int a1, int a2, bool a3);
int __fastcall EQAPP_DETOUR_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, int a1, short a2);

int __fastcall EQAPP_DETOUR_CLootWnd__Deactivate(void* this_ptr, void* not_used);

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

    EQ_MACRO_AddDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_AddDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_AddDetour(CLootWnd__Deactivate);

    EQ_MACRO_AddDetour(ProcessMouseEvent);
}

void EQAPP_Detours_Remove()
{
    EQ_MACRO_RemoveDetour(DrawNetStatus);

    EQ_MACRO_RemoveDetour(EQ_Character__eqspa_movement_rate);

    EQ_MACRO_RemoveDetour(EQ_Character__CastSpell);

    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteTint);

    EQ_MACRO_RemoveDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_RemoveDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_RemoveDetour(CLootWnd__Deactivate);

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

/*
    if (GetAsyncKeyState(VK_F1))
    {
        auto groundSpawn = EQ_GetFirstGroundSpawn();
        while (groundSpawn != nullptr)
        {
            std::stringstream buffer;
            buffer << groundSpawn->ID << ": " << groundSpawn->ActorDef;

            EQ_WriteChatText(buffer.str().c_str());

            groundSpawn = groundSpawn->Next;
        }

        Sleep(100);
    }
*/

    EQ_DrawText("EQTAKP", 200, 6, EQ_TEXT_COLOR_PINK);

    std::stringstream ssZoneType;
    ssZoneType << "Zone Type: " << (int)EQ_POINTER_Zone.Type;

    EQ_DrawText(ssZoneType.str().c_str(), 400, 6, EQ_TEXT_COLOR_PINK);

    if (g_changeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Execute();
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
    if (EQAPP_IsForegroundWindowCurrentProcessId() == true)
    {
        SetCapture(GetForegroundWindow());

        //DIMOUSESTATE mouseState;
        //HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(mouseState), (LPVOID)&mouseState);
        //if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
        //{
            EQ_CLASS_POINTER_DInputMouse->Acquire();
        //}
    }
    else
    {
        ReleaseCapture();

        EQ_CLASS_POINTER_DInputMouse->Unacquire();
    }

    // redraw the mouse cursor
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

    if (g_nameSpriteStateIsEnabled == true)
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

int __cdecl EQAPP_DETOUR_ProcessMouseEvent(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_ProcessMouseEvent();
    }

    return EQAPP_REAL_ProcessMouseEvent();
}
