#pragma once

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();
void EQAPP_Detours_OnZoneChanged_Event();
void EQAPP_Detours_OnZoneChanged_Load();

EQ_FUNCTION_TYPE_DrawNetStatus EQAPP_REAL_DrawNetStatus = NULL;

EQ_FUNCTION_TYPE_CXWndManager__DrawWindows EQAPP_REAL_CXWndManager__DrawWindows = NULL;

EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd EQAPP_REAL_CEverQuest__InterpretCmd = NULL;
EQ_FUNCTION_TYPE_CEverQuest__dsp_chat EQAPP_REAL_CEverQuest__dsp_chat = NULL;

EQ_FUNCTION_TYPE_EQPlayer__ChangePosition EQAPP_REAL_EQPlayer__ChangePosition = NULL;
EQ_FUNCTION_TYPE_EQPlayer__FollowPlayerAI EQAPP_REAL_EQPlayer__FollowPlayerAI = NULL;

EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate EQAPP_REAL_EQ_Character__eqspa_movement_rate = NULL;
EQ_FUNCTION_TYPE_EQ_Character__CastSpell EQAPP_REAL_EQ_Character__CastSpell = NULL;

EQ_FUNCTION_TYPE_CDisplay__CreateActor EQAPP_REAL_CDisplay__CreateActor = NULL;
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
EQ_FUNCTION_TYPE_CSpellBookWnd__TurnToPage EQAPP_REAL_CSpellBookWnd__TurnToPage = NULL;
EQ_FUNCTION_TYPE_CSpellBookWnd__HandleKeys EQAPP_REAL_CSpellBookWnd__HandleKeys = NULL;

EQ_FUNCTION_TYPE_CLootWnd__Deactivate EQAPP_REAL_CLootWnd__Deactivate = NULL;

EQ_FUNCTION_TYPE_CMerchantWnd__PostDraw EQAPP_REAL_CMerchantWnd__PostDraw = NULL;

EQ_FUNCTION_TYPE_CContainerMgr__OpenContainer EQAPP_REAL_CContainerMgr__OpenContainer = NULL;

EQ_FUNCTION_TYPE_CEverQuest__LMouseDown EQAPP_REAL_CEverQuest__LMouseDown = NULL;
EQ_FUNCTION_TYPE_CEverQuest__LMouseUp EQAPP_REAL_CEverQuest__LMouseUp = NULL;
EQ_FUNCTION_TYPE_CEverQuest__StartCasting EQAPP_REAL_CEverQuest__StartCasting = NULL;

EQ_FUNCTION_TYPE_HandleMouseWheel EQAPP_REAL_HandleMouseWheel = NULL;
EQ_FUNCTION_TYPE_ProcessMouseEvent EQAPP_REAL_ProcessMouseEvent = NULL;
EQ_FUNCTION_TYPE_ProcessKeyDown EQAPP_REAL_ProcessKeyDown = NULL;
EQ_FUNCTION_TYPE_ProcessKeyUp EQAPP_REAL_ProcessKeyUp = NULL;
EQ_FUNCTION_TYPE_ProcessMovementKeys EQAPP_REAL_ProcessMovementKeys = NULL;
EQ_FUNCTION_TYPE_AutoInventory EQAPP_REAL_AutoInventory = NULL;
EQ_FUNCTION_TYPE_ExecuteCmd EQAPP_REAL_ExecuteCmd = NULL;
EQ_FUNCTION_TYPE_CollisionCallbackForMove EQAPP_REAL_CollisionCallbackForMove = NULL;
EQ_FUNCTION_TYPE_do_target EQAPP_REAL_do_target = NULL;

EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx = NULL;

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOUR_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* a1, char* a2);

int __fastcall EQAPP_DETOUR_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t a1);
int __fastcall EQAPP_DETOUR_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, short a1);
int __fastcall EQAPP_DETOUR_EQ_Character__CastSpell(void* this_ptr, void* not_used, uint8_t a1, uint16_t a2, EQ::Item** a3, uint16_t a4);

int __fastcall EQAPP_DETOUR_CDisplay__CreateActor(void* this_ptr, void* not_used, char* name, float a2, float a3, float a4, float a5, float a6, float a7, int a8, int a9);
int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr a1);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* a1, bool a2);
int __fastcall EQAPP_DETOUR_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* a1);
int __fastcall EQAPP_DETOUR_CDisplay__ToggleView(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr message);

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

int __fastcall EQAPP_DETOUR_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr a1, int a2);

int __fastcall EQAPP_DETOUR_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2);
int __fastcall EQAPP_DETOUR_CEverQuest__LMouseUp(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2);
int __fastcall EQAPP_DETOUR_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuestStartCastingMessage_ptr a1);

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

void EQAPP_Detours_Add()
{
    EQ_MACRO_AddDetour(DrawNetStatus);

    EQ_MACRO_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_AddDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_AddDetour(EQPlayer__ChangePosition);
    EQ_MACRO_AddDetour(EQPlayer__FollowPlayerAI);

    EQ_MACRO_AddDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_AddDetour(EQ_Character__CastSpell);

    EQ_MACRO_AddDetour(CDisplay__CreateActor);
    EQ_MACRO_AddDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_AddDetour(CDisplay__DeleteActor);
    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_AddDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_AddDetour(CDisplay__ToggleView);

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

    ////EQ_MACRO_AddDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_AddDetour(CEverQuest__LMouseDown);
    EQ_MACRO_AddDetour(CEverQuest__LMouseUp);
    EQ_MACRO_AddDetour(CEverQuest__StartCasting);

    EQ_MACRO_AddDetour(HandleMouseWheel);
    EQ_MACRO_AddDetour(ProcessMouseEvent);
    EQ_MACRO_AddDetour(ProcessKeyDown);
    EQ_MACRO_AddDetour(ProcessKeyUp);
    EQ_MACRO_AddDetour(ExecuteCmd);
    EQ_MACRO_AddDetour(CollisionCallbackForMove);
    EQ_MACRO_AddDetour(do_target);

    uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx);

    EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx =
        (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx)DetourFunction((PBYTE)EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx, (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx);
}

void EQAPP_Detours_Remove()
{
    EQ_MACRO_RemoveDetour(DrawNetStatus);

    EQ_MACRO_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_RemoveDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_RemoveDetour(EQPlayer__ChangePosition);
    EQ_MACRO_RemoveDetour(EQPlayer__FollowPlayerAI);

    EQ_MACRO_RemoveDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_RemoveDetour(EQ_Character__CastSpell);

    EQ_MACRO_RemoveDetour(CDisplay__CreateActor);
    EQ_MACRO_RemoveDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_RemoveDetour(CDisplay__DeleteActor);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_RemoveDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_RemoveDetour(CDisplay__ToggleView);

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

    ////EQ_MACRO_RemoveDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_RemoveDetour(CEverQuest__LMouseDown);
    EQ_MACRO_RemoveDetour(CEverQuest__LMouseUp);
    EQ_MACRO_RemoveDetour(CEverQuest__StartCasting);

    EQ_MACRO_RemoveDetour(HandleMouseWheel);
    EQ_MACRO_RemoveDetour(ProcessMouseEvent);
    EQ_MACRO_RemoveDetour(ProcessKeyDown);
    EQ_MACRO_RemoveDetour(ProcessKeyUp);
    EQ_MACRO_RemoveDetour(ExecuteCmd);
    EQ_MACRO_RemoveDetour(CollisionCallbackForMove);
    EQ_MACRO_RemoveDetour(do_target);

    DetourRemove((PBYTE)EQAPP_REAL_EQGraphicsDLL__t3dCreateActorEx, (PBYTE)EQAPP_DETOUR_EQGraphicsDLL__t3dCreateActorEx);
}

void EQAPP_Detours_OnZoneChanged_Event()
{
    auto zoneID = EQ_GetZoneID();
    if (g_zoneID != zoneID && zoneID != 0xDEADBEEF)
    {
        g_zoneID = zoneID;

        EQAPP_Detours_OnZoneChanged_Load();
    }
}

void EQAPP_Detours_OnZoneChanged_Load()
{
    ////std::cout << "Zone changed..." << std::endl;

    EQAPP_WriteInventoryToFile();

    EQ_UpdateLight(EQ_POINTER_PlayerCharacter);

    g_alwaysAttackIsEnabled = false;

    EQAPP_FreeCamera_SetEnabled(false);

    ////EQAPP_BoxChat_Load();

    EQAPP_Mouse_Load();

    EQAPP_Map_Load();
    EQAPP_ExtendedTargets_Load();
    EQAPP_NetworkStats_Load();
    EQAPP_AutoLoot_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_FoodAndDrink_Load();
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

    if (g_spawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
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

    if (g_trainSpellsIsEnabled == true)
    {
        EQAPP_TrainSpells_Execute();
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
        if (g_freeCameraIsEnabled == true)
        {
            EQAPP_FreeCamera_SetEnabled(false);
        }

        if (g_trainSpellsIsEnabled == true)
        {
            EQAPP_TrainSpells_Toggle();
        }

        if (g_neverFrozenIsEnabled == true)
        {
            EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(this_ptr, a1);
        }

        if (g_spellSetIsEnabled == true)
        {
            EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(this_ptr, a1);
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
    // a1 = name

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
        EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(a1);
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
        EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(a1);
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

int __fastcall EQAPP_DETOUR_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr message)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);
    }

    int result = EQAPP_REAL_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);

/*
    if (message->Action == EQ_BAZAAR_ACTION_SEARCH_RESULTS)
    {
        auto spawn = EQ_GetSpawnByID(message->SpawnID);
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

    if (g_itemDisplayIsEnabled == true && g_itemDisplayItemsIsEnabled == true)
    {
        EQAPP_ItemDisplay_HandleEvent_CItemDisplayWnd__SetItem(a1);
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

    if (g_itemDisplayIsEnabled == true && g_itemDisplaySpellsIsEnabled == true)
    {
        EQAPP_ItemDisplay_HandleEvent_CItemDisplayWnd__SetSpell(a1, a2);
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

int __fastcall EQAPP_DETOUR_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t a1, uint16_t a2)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__LMouseDown(this_ptr, a1, a2);
    }

    ////std::cout << "CEverQuest__LMouseDown()" << std::endl;

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

    EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)result;

    if (a2 != NULL && actorInstance != NULL)
    {
        std::string actorDef = a2->Name;
        if (actorDef.size() != 0)
        {
            //EQAPP_Log(actorDef.c_str(), (int)a2->MagicNumber6);

            if (EQ_GetZoneID() == EQ_ZONE_ID_POKNOWLEDGE)
            {
                bool bFound = false;

                if (actorDef.find("POKBANNER") != std::string::npos)
                {
                    bFound = true;
                }

                if (actorDef.find("POKFLAG") != std::string::npos)
                {
                    bFound = true;
                }

                if (actorDef.find("LAMP") != std::string::npos)
                {
                    bFound = true;
                }

                if (actorDef.find("TORCH") != std::string::npos)
                {
                    bFound = true;
                }

                if (actorDef.find("SCONCE") != std::string::npos)
                {
                    bFound = true;
                }

                if (bFound == true)
                {
                    EQGraphicsDLL__t3dDestroyActor(EQ_POINTER_CDisplay->Unknown0004, actorInstance);
                }
            }
        }
    }

    return result;
}
