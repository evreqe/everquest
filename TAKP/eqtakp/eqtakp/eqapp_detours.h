#pragma once

uint32_t g_detoursOnZoneChangedTimer = 0;
uint32_t g_detoursOnZoneChangedTimerDelay = 1000;

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();
void EQAPP_Detours_OnZoneChanged_Event();
void EQAPP_Detours_OnZoneChanged_Load();

EQ_MACRO_DefineDetour(DrawNetStatus);

EQ_MACRO_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_DefineDetour(CEverQuest__LMouseDown);
EQ_MACRO_DefineDetour(CEverQuest__LMouseUp);
EQ_MACRO_DefineDetour(CEverQuest__StartCasting);
EQ_MACRO_DefineDetour(CEverQuest__MoveToZone);
EQ_MACRO_DefineDetour(CEverQuest__MoveToZone__2);
EQ_MACRO_DefineDetour(CEverQuest__EnterZone);

EQ_MACRO_DefineDetour(EQPlayer__ChangePosition);
EQ_MACRO_DefineDetour(EQPlayer__FollowPlayerAI);
EQ_MACRO_DefineDetour(EQPlayer__do_change_form);

EQ_MACRO_DefineDetour(EQ_Character__eqspa_movement_rate);
EQ_MACRO_DefineDetour(EQ_Character__CastSpell);

EQ_MACRO_DefineDetour(CDisplay__CreateActor);
EQ_MACRO_DefineDetour(CDisplay__CreatePlayerActor);
EQ_MACRO_DefineDetour(CDisplay__DeleteActor);
EQ_MACRO_DefineDetour(CDisplay__SetNameSpriteState);
EQ_MACRO_DefineDetour(CDisplay__SetNameSpriteTint);
EQ_MACRO_DefineDetour(CDisplay__ToggleView);
EQ_MACRO_DefineDetour(CDisplay__UpdateItemSlot);

EQ_MACRO_DefineDetour(CBazaarSearchWnd__HandleBazaarMsg);

EQ_MACRO_DefineDetour(CBuffWindow__RefreshBuffDisplay);
EQ_MACRO_DefineDetour(CBuffWindow__PostDraw);

EQ_MACRO_DefineDetour(CItemDisplayWnd__SetItem);
EQ_MACRO_DefineDetour(CItemDisplayWnd__SetSpell);

EQ_MACRO_DefineDetour(CSpellBookWnd__StartSpellMemorization);
EQ_MACRO_DefineDetour(CSpellBookWnd__FinishMemorizing);
EQ_MACRO_DefineDetour(CSpellBookWnd__TurnToPage);
EQ_MACRO_DefineDetour(CSpellBookWnd__HandleKeys);

EQ_MACRO_DefineDetour(CLootWnd__Deactivate);

EQ_MACRO_DefineDetour(CMerchantWnd__PostDraw);

EQ_MACRO_DefineDetour(CListWnd__SetItemText);

EQ_MACRO_DefineDetour(CContainerMgr__OpenContainer);

EQ_MACRO_DefineDetour(HandleMouseWheel);
EQ_MACRO_DefineDetour(ProcessMouseEvent);
EQ_MACRO_DefineDetour(ProcessKeyDown);
EQ_MACRO_DefineDetour(ProcessKeyUp);
EQ_MACRO_DefineDetour(ProcessMovementKeys);
EQ_MACRO_DefineDetour(AutoInventory);
EQ_MACRO_DefineDetour(ExecuteCmd);
EQ_MACRO_DefineDetour(CollisionCallbackForMove);
EQ_MACRO_DefineDetour(do_target);

EQ_MACRO_DefineDetour(EQGraphicsDLL__t3dCreateActorEx);
EQ_MACRO_DefineDetour(EQGraphicsDLL__t3dRenderDeferredPolygons);

EQ_MACRO_DefineDetour(EQIDirect3DDevice8__DrawIndexedPrimitive);

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOUR_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* a1, char* a2);
int __fastcall EQAPP_DETOUR_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* a1, int a2, bool a3);
int __fastcall EQAPP_DETOUR_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2);
int __fastcall EQAPP_DETOUR_CEverQuest__LMouseUp(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2);
int __fastcall EQAPP_DETOUR_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuestStartCastingMessage_ptr a1);
int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone(void* this_ptr, void* not_used, int a1, char* a2, int a3, int a4);
int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone__2(void* this_ptr, void* not_used, char* a1, char* a2, int a3, int a4);
int __fastcall EQAPP_DETOUR_CEverQuest__EnterZone(void* this_ptr, void* not_used, int a1);

int __fastcall EQAPP_DETOUR_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t a1);
int __fastcall EQAPP_DETOUR_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOUR_EQPlayer__do_change_form(void* this_ptr, void* not_used, EQ::ChangeForm_ptr a1);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1);
int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, uint8_t a1, uint16_t a2, EQ::Item** a3, uint16_t a4);

int __fastcall EQAPP_DETOUR_CDisplay__CreateActor(void* this_ptr, void* not_used, char* name, float a2, float a3, float a4, float a5, float a6, float a7, int a8, int a9);
int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr a1);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__ToggleView(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOUR_CDisplay__UpdateItemSlot(void* this_ptr, void* not_used, class EQPlayer* a1, uint8_t a2, char* a3, bool a4);

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr a1);

int __fastcall EQAPP_DETOUR_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOUR_CBuffWindow__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr a1, bool a2);
int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, uint16_t a1, bool a2, int a3);

int __fastcall EQAPP_DETOUR_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int a1, uint8_t a2, bool a3);
int __fastcall EQAPP_DETOUR_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, uint8_t a1, uint16_t a2);
int __fastcall EQAPP_DETOUR_CSpellBookWnd__TurnToPage(void* this_ptr, void* not_used, signed int a1);
int __fastcall EQAPP_DETOUR_CSpellBookWnd__HandleKeys(void* this_ptr, void* not_used, uint32_t a1, bool a2);

int __fastcall EQAPP_DETOUR_CLootWnd__Deactivate(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CMerchantWnd__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CListWnd__SetItemText(void* this_ptr, void* not_used, int a1, int a2, EQ::CXStr_ptr a3);

int __fastcall EQAPP_DETOUR_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr a1, int a2);

int __cdecl EQAPP_DETOUR_HandleMouseWheel(int a1);
int __cdecl EQAPP_DETOUR_ProcessMouseEvent(void);
int __cdecl EQAPP_DETOUR_ProcessKeyDown(int a1);
int __cdecl EQAPP_DETOUR_ProcessKeyUp(int a1);
int __cdecl EQAPP_DETOUR_ProcessMovementKeys(int a1);
int __cdecl EQAPP_DETOUR_AutoInventory(EQ::Character_ptr a1, EQ::Item** a2, short a3);
int __cdecl EQAPP_DETOUR_ExecuteCmd(uint32_t a1, int a2, int a3);
int __cdecl EQAPP_DETOUR_CollisionCallbackForMove(EQ::ActorInstance_ptr a1, EQ::Spawn_ptr a2);
int __cdecl EQAPP_DETOUR_do_target(class EQClass::EQPlayer* a1, const char* a2);

int __cdecl EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx(int a1, EQ::ActorDefinition_ptr a2, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10);
int __cdecl EQAPP_DETOUR_EQGraphicsDLL__t3dRenderDeferredPolygons(void);

HRESULT __stdcall EQAPP_DETOUR_EQIDirect3DDevice8__DrawIndexedPrimitive(LPDIRECT3DDEVICE8 Device, D3DPRIMITIVETYPE Type, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);

void EQAPP_Detours_Add()
{
    EQ_MACRO_AddDetour(DrawNetStatus);

    EQ_MACRO_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_AddDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_AddDetour(EQPlayer__ChangePosition);
    EQ_MACRO_AddDetour(EQPlayer__FollowPlayerAI);
    EQ_MACRO_AddDetour(EQPlayer__do_change_form);

    EQ_MACRO_AddDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_AddDetour(EQ_Character__CastSpell);

    EQ_MACRO_AddDetour(CDisplay__CreateActor);
    EQ_MACRO_AddDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_AddDetour(CDisplay__DeleteActor);
    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_AddDetour(CDisplay__ToggleView);
    EQ_MACRO_AddDetour(CDisplay__UpdateItemSlot);

    EQ_MACRO_AddDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_AddDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_AddDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_AddDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_AddDetour(CSpellBookWnd__StartSpellMemorization);
    EQ_MACRO_AddDetour(CSpellBookWnd__FinishMemorizing);
    EQ_MACRO_AddDetour(CSpellBookWnd__TurnToPage);
    EQ_MACRO_AddDetour(CSpellBookWnd__HandleKeys);

    EQ_MACRO_AddDetour(CLootWnd__Deactivate);

    EQ_MACRO_AddDetour(CMerchantWnd__PostDraw);

    EQ_MACRO_AddDetour(CListWnd__SetItemText);

    ////EQ_MACRO_AddDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_AddDetour(CEverQuest__dsp_chat);
    EQ_MACRO_AddDetour(CEverQuest__LMouseDown);
    EQ_MACRO_AddDetour(CEverQuest__LMouseUp);
    EQ_MACRO_AddDetour(CEverQuest__StartCasting);
    EQ_MACRO_AddDetour(CEverQuest__MoveToZone);
    EQ_MACRO_AddDetour(CEverQuest__MoveToZone__2);
    EQ_MACRO_AddDetour(CEverQuest__EnterZone);

    EQ_MACRO_AddDetour(HandleMouseWheel);
    EQ_MACRO_AddDetour(ProcessMouseEvent);
    EQ_MACRO_AddDetour(ProcessKeyDown);
    EQ_MACRO_AddDetour(ProcessKeyUp);
    EQ_MACRO_AddDetour(ExecuteCmd);
    EQ_MACRO_AddDetour(CollisionCallbackForMove);
    EQ_MACRO_AddDetour(do_target);

    uint32_t graphicsDLLBaseAddress = EQ_GraphicsDLL_GetBaseAddress();

    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx);

    EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx =
    (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx)DetourFunction
    (
        (PBYTE)EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx,
        (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx
    );

/*
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferredPolygons;

    EQAPP_REAL_EQGraphicsDLL__t3dRenderDeferredPolygons =
    (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferredPolygons)DetourFunction
    (
        (PBYTE)EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons,
        (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dRenderDeferredPolygons
    );
*/

    EQAPP_REAL_EQIDirect3DDevice8__DrawIndexedPrimitive =
    (EQ_FUNCTION_TYPE_EQIDirect3DDevice8__DrawIndexedPrimitive)DetourFunction
    (
        (PBYTE)EQ_VTABLE_IDirect3DDevice8[71],
        (PBYTE)EQAPP_DETOUR_EQIDirect3DDevice8__DrawIndexedPrimitive
    );

}

void EQAPP_Detours_Remove()
{
    EQ_MACRO_RemoveDetour(DrawNetStatus);

    EQ_MACRO_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_RemoveDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_RemoveDetour(EQPlayer__ChangePosition);
    EQ_MACRO_RemoveDetour(EQPlayer__FollowPlayerAI);
    EQ_MACRO_RemoveDetour(EQPlayer__do_change_form);

    EQ_MACRO_RemoveDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_RemoveDetour(EQ_Character__CastSpell);

    EQ_MACRO_RemoveDetour(CDisplay__CreateActor);
    EQ_MACRO_RemoveDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_RemoveDetour(CDisplay__DeleteActor);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_RemoveDetour(CDisplay__ToggleView);
    EQ_MACRO_RemoveDetour(CDisplay__UpdateItemSlot);

    EQ_MACRO_RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_RemoveDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_RemoveDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_RemoveDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_RemoveDetour(CSpellBookWnd__StartSpellMemorization);
    EQ_MACRO_RemoveDetour(CSpellBookWnd__FinishMemorizing);
    EQ_MACRO_RemoveDetour(CSpellBookWnd__TurnToPage);
    EQ_MACRO_RemoveDetour(CSpellBookWnd__HandleKeys);

    EQ_MACRO_RemoveDetour(CLootWnd__Deactivate);

    EQ_MACRO_RemoveDetour(CMerchantWnd__PostDraw);

    EQ_MACRO_RemoveDetour(CListWnd__SetItemText);

    ////EQ_MACRO_RemoveDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_RemoveDetour(CEverQuest__dsp_chat);
    EQ_MACRO_RemoveDetour(CEverQuest__LMouseDown);
    EQ_MACRO_RemoveDetour(CEverQuest__LMouseUp);
    EQ_MACRO_RemoveDetour(CEverQuest__StartCasting);
    EQ_MACRO_RemoveDetour(CEverQuest__MoveToZone);
    EQ_MACRO_RemoveDetour(CEverQuest__MoveToZone__2);
    EQ_MACRO_RemoveDetour(CEverQuest__EnterZone);

    EQ_MACRO_RemoveDetour(HandleMouseWheel);
    EQ_MACRO_RemoveDetour(ProcessMouseEvent);
    EQ_MACRO_RemoveDetour(ProcessKeyDown);
    EQ_MACRO_RemoveDetour(ProcessKeyUp);
    EQ_MACRO_RemoveDetour(ExecuteCmd);
    EQ_MACRO_RemoveDetour(CollisionCallbackForMove);
    EQ_MACRO_RemoveDetour(do_target);

    DetourRemove
    (
        (PBYTE)EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx,
        (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx
    );

/*
    DetourRemove
    (
        (PBYTE)EQAPP_REAL_EQGraphicsDLL__t3dRenderDeferredPolygons,
        (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dRenderDeferredPolygons
    );
*/

    DetourRemove
    (
        (PBYTE)EQAPP_REAL_EQIDirect3DDevice8__DrawIndexedPrimitive,
        (PBYTE)EQAPP_DETOUR_EQIDirect3DDevice8__DrawIndexedPrimitive
    );

}

void EQAPP_Detours_OnZoneChanged_Event()
{
    if (EQ_HasTimePassed(g_detoursOnZoneChangedTimer, g_detoursOnZoneChangedTimerDelay) == false)
    {
        return;
    }

    auto zoneID = EQ_GetZoneID();
    if (g_zoneID != zoneID && zoneID != 0xDEADBEEF)
    {
        g_zoneID = zoneID;

        EQAPP_Detours_OnZoneChanged_Load();
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerClass = playerSpawn->Class;
        if (g_playerClass != playerClass && playerClass != EQ_CLASS_UNKNOWN)
        {
            g_playerClass = playerClass;

            EQAPP_UseSkills_Load();
        }
    }
}

void EQAPP_Detours_OnZoneChanged_Load()
{
    ////std::cout << "Zone changed..." << std::endl;

    EQ_GraphicsDLL_SetUseTNL(true);
    EQ_GraphicsDLL_SetUseUmbra(true);

    EQAPP_WriteInventoryToFile();

    EQ_UpdateLight(EQ_POINTER_PlayerCharacter);

    g_alwaysAttackIsEnabled = false;

    g_spawnAlertNewSpawnIDList.clear();

    EQAPP_FreeCamera_SetEnabled(false);

    EQ_SetUseVisActorList(false);

    EQ_SetRun(true);

    ////EQAPP_BoxChat_Load();

    EQAPP_Mouse_Load();

    EQAPP_Map_Load();
    EQAPP_ExtendedTargets_Load();
    EQAPP_NetworkStats_Load();
    EQAPP_AutoLoot_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_FoodAndDrink_Load();
    EQAPP_BazaarSearchWindow_LoadItemNames();

    EQAPP_DestroyActors_Load(EQ_POINTER_Zone.ShortName);
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

    EQAPP_Detours_OnZoneChanged_Event();

    if (g_hotButtonKeysIsEnabled == true)
    {
        EQAPP_HotButtonKeys_Execute();
    }

    if (g_freeCameraIsEnabled == true)
    {
        EQAPP_FreeCamera_Execute();
    }

    if (g_boxChatIsEnabled == true)
    {
        EQAPP_BoxChat_Execute();
    }

    if (g_networkStatsIsEnabled == true)
    {
        EQAPP_NetworkStats_Execute();
    }

    if (g_drawDistanceIsEnabled == true)
    {
        EQAPP_DrawDistance_Execute();
    }

    if (g_destroyActorsIsEnabled == true)
    {
        EQAPP_DestroyActors_Execute();
    }

    if (g_spawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
    }

    if (g_autoGroupIsEnabled == true)
    {
        EQAPP_AutoGroup_Execute();
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

    if (g_replaceRacesIsEnabled == true)
    {
        EQAPP_ReplaceRaces_Execute();
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

    if (g_trainSpellsIsEnabled == true)
    {
        EQAPP_TrainSpells_Execute();
    }

    if (g_destroyActorsIsEnabled == true)
    {
        EQAPP_DestroyActors_Execute();
    }

    // mouse fix
    EQAPP_Mouse_Acquire();

    // redraw the mouse cursor
    EQ_DrawMouseCursor();

    EQAPP_Console_Print();

    return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int __fastcall EQAPP_DETOUR_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CXWndManager__DrawWindows(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_spawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_DrawText();
    }

    if (g_extendedTargetsIsEnabled == true)
    {
        EQAPP_ExtendedTargets_Execute();
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

        if (g_namedSpawnsIsEnabled == true)
        {
            EQAPP_NamedSpawns_Execute();
        }
    }

    if (g_networkStatsIsEnabled == true)
    {
        EQAPP_NetworkStats_DrawText();
        EQAPP_NetworkStats_DrawBars();
    }

    if (g_HUDTextIsEnabled == true && g_mainMenuGUIMenu.IsOpen() == false)
    {
        EQAPP_HUDText_Execute();
    }

    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_Execute();
    }

    return EQAPP_REAL_CXWndManager__DrawWindows(this_ptr);
}

int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* a1, char* a2)
{
    // a1 = player
    // a2 = command text

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, a1, a2);
    }

    if (g_interpretCmdIsEnabled == true)
    {
        bool result = EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(this_ptr, a1, a2);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, a1, a2);
}

int __fastcall EQAPP_DETOUR_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* a1, int a2, bool a3)
{
    // a1 = text
    // a2 = textColor
    // a3 = filtered

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    if (a1 == NULL)
    {
        return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    if (g_trainSpellsIsEnabled == true)
    {
        EQAPP_TrainSpells_HandleEvent_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
}

int __fastcall EQAPP_DETOUR_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__LMouseDown(this_ptr, a1, a2);
    }

    //

    return EQAPP_REAL_CEverQuest__LMouseDown(this_ptr, a1, a2);
}

int __fastcall EQAPP_DETOUR_CEverQuest__LMouseUp(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__LMouseUp(this_ptr, a1, a2);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_CEverQuest__LMouseUp(this_ptr, a1, a2);
    }

    if (EQ_IsMouseHoveringOverCXWnd() == true)
    {
        return EQAPP_REAL_CEverQuest__LMouseUp(this_ptr, a1, a2);
    }

    if (g_GUIIsEnabled == true)
    {
        if (EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(a1, a2) == true)
        {
            return 1;
        }
    }

    if (g_extendedTargetsIsEnabled == true)
    {
        if (EQAPP_ExtendedTargets_HandleEvent_CEverQuest__LMouseUp(a1, a2) == true)
        {
            return 1;
        }
    }

    if (g_mapIsEnabled == true)
    {
        if (EQAPP_Map_IsMouseOver() == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_CEverQuest__LMouseUp(this_ptr, a1, a2);
}

int __fastcall EQAPP_DETOUR_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuestStartCastingMessage_ptr a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__StartCasting(this_ptr, a1);
    }

    if (g_startCastingisEnabled == true)
    {
        EQAPP_StartCasting_HandleEvent_CEverQuest__StartCasting(this_ptr, a1);
    }

    if (g_spawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(this_ptr, a1);
    }

    return EQAPP_REAL_CEverQuest__StartCasting(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone(void* this_ptr, void* not_used, int a1, char* a2, int a3, int a4)
{
    // a1 = zoneID
    // a2 = text
    // a3 = destinationType
    // a4 = zoneRequestReason

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__MoveToZone(this_ptr, a1, a2, a3, a4);
    }

    int result = EQAPP_REAL_CEverQuest__MoveToZone(this_ptr, a1, a2, a3, a4);

    EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone(this_ptr, a1, a2, a3, a4);

    return result;
}

int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone__2(void* this_ptr, void* not_used, char* a1, char* a2, int a3, int a4)
{
    // a1 = zoneShortName
    // a2 = text
    // a3 = destinationType
    // a4 = zoneRequestReason

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__MoveToZone__2(this_ptr, a1, a2, a3, a4);
    }

    EQAPP_DestroyActors_Load(a1);

    return EQAPP_REAL_CEverQuest__MoveToZone__2(this_ptr, a1, a2, a3, a4);
}

int __fastcall EQAPP_DETOUR_CEverQuest__EnterZone(void* this_ptr, void* not_used, int a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__EnterZone(this_ptr, a1);
    }

    int result = EQAPP_REAL_CEverQuest__EnterZone(this_ptr, a1);

    //

    return result;
}

int __fastcall EQAPP_DETOUR_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t a1)
{
    // this_ptr = spawn
    // a1 = standingState

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__ChangePosition(this_ptr, a1);
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL && playerSpawn == (EQ::Spawn_ptr)this_ptr)
    {
        if (g_neverFrozenIsEnabled == true)
        {
            EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(this_ptr, a1);
        }

        if (a1 == EQ_STANDING_STATE_SITTING || a1 == EQ_STANDING_STATE_DUCKING)
        {
            if (g_freeCameraIsEnabled == true)
            {
                EQAPP_FreeCamera_SetEnabled(false);
            }

            if (g_spellSetIsEnabled == true)
            {
                EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(this_ptr, a1);
            }
        }

        if (a1 == EQ_STANDING_STATE_DUCKING)
        {
            if (g_trainSpellsIsEnabled == true)
            {
                EQAPP_TrainSpells_Toggle();
            }
        }
    }

    return EQAPP_REAL_EQPlayer__ChangePosition(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__FollowPlayerAI(this_ptr);
    }

    if (g_autoFollowIsEnabled == true)
    {
        EQAPP_AutoFollow_HandleEvent__EQPlayer__FollowPlayerAI(this_ptr);
    }

    int result = EQAPP_REAL_EQPlayer__FollowPlayerAI(this_ptr);

    EQAPP_AutoFollow_SetFollowDistanceToDefault();

    return result;
}

int __fastcall EQAPP_DETOUR_EQPlayer__do_change_form(void* this_ptr, void* not_used, EQ::ChangeForm_ptr a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__do_change_form(this_ptr, a1);
    }

/*
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[EQPlayer__do_change_form] Spawn ID: " << (int)a1->SpawnID << std::endl;
    std::cout << "[EQPlayer__do_change_form] Race: " << (int)a1->Race << std::endl;
    std::cout << "[EQPlayer__do_change_form] Gender: " << (int)a1->Gender << std::endl;
    std::cout << "[EQPlayer__do_change_form] Texture: " << (int)a1->Texture << std::endl;
    std::cout << "[EQPlayer__do_change_form] Helmet Texture: " << (int)a1->HelmetTexture << std::endl;
    std::cout << "[EQPlayer__do_change_form] Unknown07: " << (int)a1->Unknown07 << std::endl;
    std::cout << "[EQPlayer__do_change_form] Face: " << (int)a1->Face << std::endl;
    std::cout << "[EQPlayer__do_change_form] Hair Type: " << (int)a1->HairType << std::endl;
    std::cout << "[EQPlayer__do_change_form] Hair Color: " << (int)a1->HairColor << std::endl;
    std::cout << "[EQPlayer__do_change_form] Beard Type: " << (int)a1->BeardType << std::endl;
    std::cout << "[EQPlayer__do_change_form] Beard Color: " << (int)a1->BeardColor << std::endl;
    std::cout << "[EQPlayer__do_change_form] Size: " << (int)a1->Size << std::endl;
    std::cout << "[EQPlayer__do_change_form] Unknown10: " << (int)a1->Unknown10 << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
*/

    if (g_replaceRacesIsEnabled == true)
    {
        bool result = EQAPP_ReplaceRaces_HandleEvent_EQPlayer__do_change_form(this_ptr, a1);
        if (result == true)
        {
            return 0;
        }
    }

    return EQAPP_REAL_EQPlayer__do_change_form(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1)
{
    // a1 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);
    }

    int result = EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);

    // never rooted or snared
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        if (playerSpawn->Actor->MovementSpeedModifier < 0.0f)
        {
            playerSpawn->Actor->MovementSpeedModifier = 0.0f;
        }
    }

    if (g_speedHackIsEnabled == true)
    {
        EQAPP_SpeedHack_HandleEvent_EQ_Character__eqspa_movement_rate(this_ptr, a1);
    }

    return result;
}

int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, uint8_t a1, uint16_t a2, EQ::Item** a3, uint16_t a4)
{
    // a1 = spellGemIndex
    // a2 = spellID
    // a3 = item
    // a4 = unknown, always equals -1

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__CastSpell(this_ptr, a1, a2, a3, a4);
    }

    if (g_autoStandIsEnabled == true && g_autoStandWhenCastSpellIsEnabled == true)
    {
        EQAPP_AutoStand_HandleEvent_EQ_Character__CastSpell(this_ptr, a1, a2, a3, a4);
    }

    return EQAPP_REAL_EQ_Character__CastSpell(this_ptr, a1, a2, a3, a4);
}

int __fastcall EQAPP_DETOUR_CDisplay__CreateActor(void* this_ptr, void* not_used, char* name, float a1, float a2, float a3, float a4, float a5, float a6, int a7, int a8)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__CreateActor(this_ptr, name, a1, a2, a3, a4, a5, a6, a7, a8);
    }

    // remove doors in POK zone
    //if (strstr(name, "POKDOOR") != NULL)
    //{
        //return 0;
    //}

    return EQAPP_REAL_CDisplay__CreateActor(this_ptr, name, a1, a2, a3, a4, a5, a6, a7, a8);
}

int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* a1)
{
    // a1 = player

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__CreatePlayerActor(this_ptr, a1);
    }

    if (g_spawnAlertIsEnabled == true)
    {
        EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(this_ptr, a1);
    }

    return EQAPP_REAL_CDisplay__CreatePlayerActor(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr a1)
{
    // a1 = actor instance

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__DeleteActor(this_ptr, a1);
    }

    if (g_spawnAlertIsEnabled == true)
    {
        EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(this_ptr, a1);
    }

    return EQAPP_REAL_CDisplay__DeleteActor(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2)
{
    // a1 = player
    // a2 = show

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__SetNameSpriteState(this_ptr, a1, a2);
    }

    int result = EQAPP_REAL_CDisplay__SetNameSpriteState(this_ptr, a1, a2);

    if (g_nameSpriteStateIsEnabled == true && a2 != 0)
    {
        if (EQAPP_NameSpriteState_HandleEvent_CDisplay__SetNameSpriteState(this_ptr, a1, a2) == false)
        {
            return result;
        }
    }

    EQAPP_DETOUR_CDisplay__SetNameSpriteTint(this_ptr, not_used, a1);

    return result;
}

int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1)
{
    // a1 = player

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__SetNameSpriteTint(this_ptr, a1);
    }

    int result = EQAPP_REAL_CDisplay__SetNameSpriteTint(this_ptr, a1);

    if (g_nameSpriteTintIsEnabled == true)
    {
        if (EQAPP_NameSpriteTint_HandleEvent_CDisplay__SetNameSpriteTint(this_ptr, a1) == false)
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

    if (g_toggleViewIsEnabled == true)
    {
        EQAPP_ToggleView_HandleEvent_CDisplay__ToggleView(this_ptr);
    }

    return EQAPP_REAL_CDisplay__ToggleView(this_ptr);
}

int __fastcall EQAPP_DETOUR_CDisplay__UpdateItemSlot(void* this_ptr, void* not_used, class EQPlayer* a1, uint8_t a2, char* a3, bool a4)
{
    // a1 = player
    // a2 = itemSlot
    // a3 = itemDef
    // a4 = clientSideOnly

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
    }

/*
    if (a1 == NULL)
    {
        return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
    }

    auto spawn = (EQ::Spawn_ptr)a1;
    if (spawn == NULL)
    {
        return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
    }

    std::string spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
    }

    std::string itemDef = a3;
    if (itemDef.size() == 0)
    {
        return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Spawn Name: " << spawnName << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Item Slot: " << (int)a2 << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Item Def: " << a3 << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Client Side Only: " << (int)a4 << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
*/

/*
    if (itemDef.find("IT") != std::string::npos)
    {
        if (itemDef == "IT120")
        {
            itemDef = "IT145";

            return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, (char*)itemDef.c_str(), true);
        }
    }
*/

    return EQAPP_REAL_CDisplay__UpdateItemSlot(this_ptr, a1, a2, a3, a4);
}

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, a1);
    }

    int result = EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, a1);

/*
    if (a1->Action == EQ_BAZAAR_ACTION_SEARCH_RESULTS)
    {
        auto spawn = EQ_GetSpawnByID(a1->SpawnID);
        if (spawn != NULL)
        {
            std::cout << "--------------------------------------------------" << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Action: " << a1->Action << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Quantity: " << a1->ItemQuantity << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item ID: " << std::hex << a1->ItemID << std::dec << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Seller Name: " << spawn->Name << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Price: " << EQ_CLASS_POINTER_CBazaarSearchWnd->GetPriceString(a1->ItemValue) << std::endl;
            std::cout << "[CBazaarSearchWnd__HandleBazaarMsg] Item Name: " << a1->ItemName << std::endl;
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
        EQAPP_BuffTimers_HandleEvent_CBuffWindow__RefreshBuffDisplay(this_ptr);
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
        EQAPP_BuffTimers_HandleEvent_CBuffWindow__PostDraw(this_ptr);
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

    if (g_itemDisplayWindowIsEnabled == true && g_itemDisplayWindowItemsIsEnabled == true)
    {
        EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetItem(this_ptr, a1, a2);
    }

    return result;
}


int __fastcall EQAPP_DETOUR_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, uint16_t a1, bool a2, int a3)
{
    // a1 = spellID
    // a2 = hasDescription
    // a3 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CItemDisplayWnd__SetSpell(this_ptr, a1, a2, a3);
    }

    int result = EQAPP_REAL_CItemDisplayWnd__SetSpell(this_ptr, a1, a2, a3);

    if (g_itemDisplayWindowIsEnabled == true && g_itemDisplayWindowSpellsIsEnabled == true)
    {
        EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetSpell(this_ptr, a1, a2, a3);
    }

    return result;
};

int __fastcall EQAPP_DETOUR_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int a1, uint8_t a2, bool a3)
{
    // a1 = spellBookIndex
    // a2 = spellGemIndex
    // a3 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CSpellBookWnd__StartSpellMemorization(this_ptr, a1, a2, a3);
    }

    g_bIsMemorizingSpell = true;

    return EQAPP_REAL_CSpellBookWnd__StartSpellMemorization(this_ptr, a1, a2, a3);
}

int __fastcall EQAPP_DETOUR_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, uint8_t a1, uint16_t a2)
{
    // a1 = spellGemIndex
    // a2 = spellID

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CSpellBookWnd__FinishMemorizing(this_ptr, a1, a2);
    }

    int result = EQAPP_REAL_CSpellBookWnd__FinishMemorizing(this_ptr, a1, a2);

    g_bIsMemorizingSpell = false;

    if (g_spellSetIsEnabled == true)
    {
        EQAPP_SpellSet_HandleEvent_CSpellBookWnd__FinishMemorizing(this_ptr, a1, a2);
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CSpellBookWnd__TurnToPage(void* this_ptr, void* not_used, signed int a1)
{
    // a1 = pageNumber

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CSpellBookWnd__TurnToPage(this_ptr, a1);
    }

    if (g_spellBookWindowIsEnabled == true)
    {
        a1 = EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__TurnToPage(this_ptr, a1);
    }

    return EQAPP_REAL_CSpellBookWnd__TurnToPage(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CSpellBookWnd__HandleKeys(void* this_ptr, void* not_used, uint32_t a1, bool a2)
{
    // a1 = keyID
    // a2 = unknown, always 1 or true

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CSpellBookWnd__HandleKeys(this_ptr, a1, a2);
    }

    if (g_spellBookWindowIsEnabled == true)
    {
        EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__HandleKeys(this_ptr, a1, a2);
    }

    return EQAPP_REAL_CSpellBookWnd__HandleKeys(this_ptr, a1, a2);
}

int __fastcall EQAPP_DETOUR_CLootWnd__Deactivate(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CLootWnd__Deactivate(this_ptr);
    }

    int result = EQAPP_REAL_CLootWnd__Deactivate(this_ptr);

    if (g_hideCorpseLootedIsEnabled == true)
    {
        EQAPP_HideCorpseLooted_HandleEvent_CLootWnd__Deactivate(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CMerchantWnd__PostDraw(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CMerchantWnd__PostDraw(this_ptr);
    }

    if (g_merchantWindowIsEnabled == true)
    {
        EQAPP_MerchantWindow_AppendSpellLevelToToolTipText(this_ptr);
    }

    int result = EQAPP_REAL_CMerchantWnd__PostDraw(this_ptr);

    if (g_merchantWindowIsEnabled == true)
    {
        EQAPP_MerchantWindow_HandleEvent_CMerchantWnd__PostDraw(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CListWnd__SetItemText(void* this_ptr, void* not_used, int a1, int a2, EQ::CXStr_ptr a3)
{
    // a1 = index
    // a2 = column
    // a3 = text

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CListWnd__SetItemText(this_ptr, a1, a2, a3);
    }

    int result = EQAPP_REAL_CListWnd__SetItemText(this_ptr, a1, a2, a3);

    if (g_bazaarSearchWindowIsEnabled == true)
    {
        EQAPP_BazaarSearchWindow_HandleEvent_CListWnd__SetItemText(this_ptr, a1, a2, a3);
    }

    return result;
}

int __fastcall EQAPP_DETOUR_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr a1, int a2)
{
    // a1 = container
    // a2 = inventorySlotIndex

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CContainerMgr__OpenContainer(this_ptr, a1, a2);
    }

    ////std::cout << "[CContainerMgr__OpenContainer] inventorySlotIndex: " << a2 << std::endl;

    return EQAPP_REAL_CContainerMgr__OpenContainer(this_ptr, a1, a2);
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

    if (EQ_IsMouseHoveringOverCXWnd() == true)
    {
        return EQAPP_REAL_HandleMouseWheel(a1);
    }

    if (g_mapIsEnabled == true)
    {
        EQAPP_Map_HandleEvent_HandleMouseWheel(a1);
    }

    return EQAPP_REAL_HandleMouseWheel(a1);
}

int __cdecl EQAPP_DETOUR_ProcessMouseEvent(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_ProcessMouseEvent();
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_ProcessMouseEvent();
    }

    if (g_extraMouseButtonsIsEnabled == true)
    {
        EQAPP_ExtraMouseButtons_HandleEvent_ProcessMouseEvent();
    }

    return EQAPP_REAL_ProcessMouseEvent();
}

int __cdecl EQAPP_DETOUR_ProcessKeyDown(int a1)
{
    // a1 = keyID

    if (g_bExit == 1)
    {
        return EQAPP_REAL_ProcessKeyDown(a1);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ProcessKey(a1);
        if (result == true)
        {
            return EQAPP_REAL_ProcessKeyDown(NULL);
        }
    }

    return EQAPP_REAL_ProcessKeyDown(a1);
}

int __cdecl EQAPP_DETOUR_ProcessKeyUp(int a1)
{
    // a1 = Key ID

    if (g_bExit == 1)
    {
        return EQAPP_REAL_ProcessKeyUp(a1);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ProcessKey(a1);
        if (result == true)
        {
            return EQAPP_REAL_ProcessKeyUp(NULL);
        }
    }

    return EQAPP_REAL_ProcessKeyUp(a1);
}

int __cdecl EQAPP_DETOUR_ExecuteCmd(uint32_t a1, int a2, int a3)
{
    // a1 = commandID
    // a2 = isActive
    // a3 = zero

    if (g_bExit == 1)
    {
        return EQAPP_REAL_ExecuteCmd(a1, a2, a3);
    }

    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_HandleEvent_ExecuteCmd(a1, a2, a3);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ExecuteCmd(a1, a2, a3);
        if (result == true)
        {
            return EQAPP_REAL_ExecuteCmd(NULL, 0, 0);
        }
    }

/*
    if (a1 == EQ_EXECUTECMD_TARGETPC && a2 == 1 && a3 == 0)
    {
        EQAPP_TargetNearestPlayer();
        return EQAPP_REAL_ExecuteCmd(NULL, 0, 0);
    }
    else if (a1 == EQ_EXECUTECMD_TARGETNPC && a2 == 1 && a3 == 0)
    {
        EQAPP_TargetNearestNPC();
        return EQAPP_REAL_ExecuteCmd(NULL, 0, 0);
    }
*/

    return EQAPP_REAL_ExecuteCmd(a1, a2, a3);
}

int __cdecl EQAPP_DETOUR_CollisionCallbackForMove(EQ::ActorInstance_ptr a1, EQ::Spawn_ptr a2)
{
    // a2 = spawn that collides with actor instance
    // a1 = actor instance of actor that spawn has collided into

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CollisionCallbackForMove(a1, a2);
    }

    if (g_collisionHackIsEnabled == true)
    {
        EQAPP_CollisionHack_HandleEvent_CollisionCallbackForMove(a1, a2);
    }

    int result = EQAPP_REAL_CollisionCallbackForMove(a1, a2);

    EQ_SetActorCollision(true);

    return result;
}

int __cdecl EQAPP_DETOUR_do_target(class EQClass::EQPlayer* a1, const char* a2)
{
    // a1 = player
    // a2 = findSpawnName

    if (g_bExit == 1)
    {
        return EQAPP_REAL_do_target(a1, a2);
    }

    if (g_doTargetIsEnabled == true)
    {
        bool result = EQAPP_DoTarget_HandleEvent_do_target(a1, a2);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_do_target(a1, a2);
}

int __cdecl EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx(int a1, EQ::ActorDefinition_ptr a2, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

/*
    EQAPP_Log("EQGraphicsDLL__t3dCreateActorEx", 0);
    EQAPP_Log("a1", a1);
    EQAPP_Log("a2", a2);
    EQAPP_Log("a3", a3);
    EQAPP_Log("a4", a4);
    EQAPP_Log("a5", a5);
    EQAPP_Log("a6", a6);
    EQAPP_Log("a7", a7);
    EQAPP_Log("a8", a8);
    EQAPP_Log("a9", a9);
    EQAPP_Log("a10", a10);
*/

    int result = EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);

    if (g_destroyActorsIsEnabled == true)
    {
        EQAPP_DestroyActors_HandleEvent_EQGraphicsDLL__t3dCreateActorEx((EQ::ActorInstance_ptr)result, a2);
    }

/*
    EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)result;

    if (a2 != NULL && actorInstance != NULL)
    {
        std::string actorDef = a2->Name;
        if (actorDef.size() != 0)
        {
            EQAPP_Log(actorDef.c_str(), (int)a2->MagicNumber6);
        }
    }
*/

    return result;
}

int __cdecl EQAPP_DETOUR_EQGraphicsDLL__t3dRenderDeferredPolygons(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQGraphicsDLL__t3dRenderDeferredPolygons();
    }

    //// old wallhack

    ////EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZENABLE, FALSE);

    int result = EQAPP_REAL_EQGraphicsDLL__t3dRenderDeferredPolygons();

    ////EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZENABLE, TRUE);

    return result;
}

HRESULT __stdcall EQAPP_DETOUR_EQIDirect3DDevice8__DrawIndexedPrimitive(LPDIRECT3DDEVICE8 Device, D3DPRIMITIVETYPE Type, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQIDirect3DDevice8__DrawIndexedPrimitive(Device, Type, MinIndex, NumVertices, StartIndex, PrimitiveCount);
    }

    if (g_wallHackIsEnabled == true)
    {
        LPDIRECT3DVERTEXBUFFER8 streamData;
        UINT stride = 0;

        if (Device->GetStreamSource(0, &streamData, &stride) == D3D_OK)
        {
            streamData->Release();
        }

        //std::cout << "Stride: " << stride << std::endl;

        //std::cout << "MinIndex: " << MinIndex << std::endl;
        //std::cout << "NumVertices: " << NumVertices << std::endl;
        //std::cout << "StartIndex: " << StartIndex << std::endl;
        //std::cout << "PrimitiveCount: " << PrimitiveCount << std::endl;

        // 24 = World
        // 32 = Actors

        if (stride == 24)
        {
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCCOLOR);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);

            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
        }

        if (stride == 32)
        {
            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZENABLE, FALSE);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZFUNC, D3DCMP_NOTEQUAL);
        }

        int result = EQAPP_REAL_EQIDirect3DDevice8__DrawIndexedPrimitive(Device, Type, MinIndex, NumVertices, StartIndex, PrimitiveCount);

        if (stride == 24)
        {
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
        }

        if (stride == 32)
        {
            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZENABLE, TRUE);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
        }

        return result;
    }

    return EQAPP_REAL_EQIDirect3DDevice8__DrawIndexedPrimitive(Device, Type, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}



