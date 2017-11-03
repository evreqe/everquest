#pragma once

uint32_t g_detoursOnZoneChangedTimer = 0;
uint32_t g_detoursOnZoneChangedTimerDelay = 1000;

void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();
void EQAPP_Detours_OnZoneChanged_Event();
void EQAPP_Detours_OnZoneChanged_Load();

EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__LMouseDown);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__LMouseUp);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__StartCasting);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__MoveToZone);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__MoveToZone__2);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__EnterZone);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__ChangePosition);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__do_change_form);

EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__eqspa_movement_rate);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__CastSpell);

EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreateActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreatePlayerActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__DeleteActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__SetNameSpriteState);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__SetNameSpriteTint);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__ToggleView);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__UpdateItemSlot);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__GetNearestPlayerInView);

EQ_MACRO_FUNCTION_DefineDetour(CBazaarSearchWnd__HandleBazaarMsg);

EQ_MACRO_FUNCTION_DefineDetour(CBuffWindow__RefreshBuffDisplay);
EQ_MACRO_FUNCTION_DefineDetour(CBuffWindow__PostDraw);

EQ_MACRO_FUNCTION_DefineDetour(CItemDisplayWnd__SetItem);
EQ_MACRO_FUNCTION_DefineDetour(CItemDisplayWnd__SetSpell);

EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__StartSpellMemorization);
EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__FinishMemorizing);
EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__TurnToPage);
EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__HandleKeys);

EQ_MACRO_FUNCTION_DefineDetour(CLootWnd__Deactivate);

EQ_MACRO_FUNCTION_DefineDetour(CContainerWnd__PostDraw);

EQ_MACRO_FUNCTION_DefineDetour(CMerchantWnd__PostDraw);

EQ_MACRO_FUNCTION_DefineDetour(CListWnd__SetItemText);

EQ_MACRO_FUNCTION_DefineDetour(CContainerMgr__OpenContainer);

EQ_MACRO_FUNCTION_DefineDetour(HandleMouseWheel);
EQ_MACRO_FUNCTION_DefineDetour(ProcessMouseEvent);
EQ_MACRO_FUNCTION_DefineDetour(ProcessKeyDown);
EQ_MACRO_FUNCTION_DefineDetour(ProcessKeyUp);
EQ_MACRO_FUNCTION_DefineDetour(ProcessMovementKeys);
EQ_MACRO_FUNCTION_DefineDetour(AutoInventory);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);
EQ_MACRO_FUNCTION_DefineDetour(CollisionCallbackForMove);
EQ_MACRO_FUNCTION_DefineDetour(do_target);
EQ_MACRO_FUNCTION_DefineDetour(DoSpellEffect);

EQ_MACRO_FUNCTION_DefineDetour(EQGraphicsDLL__t3dCreateActorEx);
EQ_MACRO_FUNCTION_DefineDetour(EQGraphicsDLL__t3dRenderDeferredPolygons);
EQ_MACRO_FUNCTION_DefineDetour(EQGraphicsDLL__t3dSelectTexture);
EQ_MACRO_FUNCTION_DefineDetour(EQGraphicsDLL__t3dPaintHierarchicalSprite);
EQ_MACRO_FUNCTION_DefineDetour(EQGraphicsDLL__s3dPaintDMSprite2);

EQ_MACRO_FUNCTION_DefineDetour(EQIDirect3DDevice8__SetRenderState);
EQ_MACRO_FUNCTION_DefineDetour(EQIDirect3DDevice8__DrawIndexedPrimitive);
EQ_MACRO_FUNCTION_DefineDetour(EQIDirect3DDevice8__Reset);

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short x, unsigned short y, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, char* commandText);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool filtered);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t x, uint16_t y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, uint16_t x, uint16_t y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuestStartCastingMessage_ptr message);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__MoveToZone(void* this_ptr, void* not_used, EQ_ZoneID_t zoneID, char* text, int destinationType, int zoneRequestReason);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__MoveToZone__2(void* this_ptr, void* not_used, char* zoneShortName, char* text, int destinationType, int zoneRequestReason);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__EnterZone(void* this_ptr, void* not_used, int unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangePosition(void* this_ptr, void* not_used, EQ_StandingState_t standingState);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__do_change_form(void* this_ptr, void* not_used, EQ::ChangeForm_ptr changeForm);

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, signed short movementSpeed);
int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CastSpell(void* this_ptr, void* not_used, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID, EQ::Item** item, uint16_t unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreateActor(void* this_ptr, void* not_used, char* name, float a2, float a3, float a4, float a5, float a6, float a7, int a8, int a9);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* player);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr actorInstance);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* player, bool show);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* player);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__ToggleView(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__UpdateItemSlot(void* this_ptr, void* not_used, class EQPlayer* player, uint8_t updateItemSlot, char* itemDefinition, bool clientSideOnly);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__GetNearestPlayerInView(void* this_ptr, void* not_used, float maxDistance, EQ_SpawnType_t spawnType);

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr message);

int __fastcall EQAPP_DETOURED_FUNCTION_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CBuffWindow__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr item, bool unknown);
int __fastcall EQAPP_DETOURED_FUNCTION_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, EQ_SpellID_t spellID, bool hasDescription, int unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int spellBookIndex, EQ_SpellGemIndex_t spellGemIndex, bool unknown);
int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID);
int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__TurnToPage(void* this_ptr, void* not_used, signed int pageNumber);
int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__HandleKeys(void* this_ptr, void* not_used, int keyID, bool unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_CLootWnd__Deactivate(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CContainerWnd__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CMerchantWnd__PostDraw(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CListWnd__SetItemText(void* this_ptr, void* not_used, int index, int column, EQ::CXStr_ptr text);

int __fastcall EQAPP_DETOURED_FUNCTION_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr container, int inventorySlotIndex);

int __cdecl EQAPP_DETOURED_FUNCTION_HandleMouseWheel(signed int delta);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMouseEvent(void);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyDown(int keyID);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyUp(int keyID);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMovementKeys(int keyID);
int __cdecl EQAPP_DETOURED_FUNCTION_AutoInventory(EQ::Character_ptr character, EQ::Item** item, short unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, int zero);
int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForMove(EQ::ActorInstance_ptr actorInstance, EQ::Spawn_ptr spawn);
int __cdecl EQAPP_DETOURED_FUNCTION_do_target(class EQClass::EQPlayer* player, const char* spawnName);
int __cdecl EQAPP_DETOURED_FUNCTION_DoSpellEffect(int type, EQ::Spell_ptr spell, class EQClass::EQPlayer* player1, class EQClass::EQPlayer* player2, EQ::Location_ptr location, int* missile, uint32_t duration);

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dCreateActorEx(int a1, EQ::ActorDefinition_ptr actorDefinition, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10);
int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons(void);
int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dSelectTexture(EQ::Texture_ptr texture);
int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance);
int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2(int* world, int* renderContext, int* actor);

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__SetRenderState(D3DRENDERSTATETYPE state, DWORD value);
HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive(LPDIRECT3DDEVICE8 device, D3DPRIMITIVETYPE primitiveType, UINT minIndex, UINT numVertices, UINT startIndex, UINT primitiveCount);
HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__Reset(LPDIRECT3DDEVICE8 device, D3DPRESENT_PARAMETERS* presentationParameters);

void EQAPP_Detours_Load()
{
    EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);

    EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__ChangePosition);
    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);
    EQ_MACRO_FUNCTION_AddDetour(EQPlayer__do_change_form);

    EQ_MACRO_FUNCTION_AddDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_FUNCTION_AddDetour(EQ_Character__CastSpell);

    EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreateActor);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__DeleteActor);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__ToggleView);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__UpdateItemSlot);
    EQ_MACRO_FUNCTION_AddDetour(CDisplay__GetNearestPlayerInView);

    EQ_MACRO_FUNCTION_AddDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_FUNCTION_AddDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_FUNCTION_AddDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_FUNCTION_AddDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_FUNCTION_AddDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__StartSpellMemorization);
    EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__FinishMemorizing);
    EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__TurnToPage);
    EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__HandleKeys);

    EQ_MACRO_FUNCTION_AddDetour(CLootWnd__Deactivate);

    EQ_MACRO_FUNCTION_AddDetour(CContainerWnd__PostDraw);

    EQ_MACRO_FUNCTION_AddDetour(CMerchantWnd__PostDraw);

    EQ_MACRO_FUNCTION_AddDetour(CListWnd__SetItemText);

    ////EQ_MACRO_FUNCTION_AddDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__dsp_chat);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__LMouseDown);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__LMouseUp);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__StartCasting);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__MoveToZone);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__MoveToZone__2);
    EQ_MACRO_FUNCTION_AddDetour(CEverQuest__EnterZone);

    EQ_MACRO_FUNCTION_AddDetour(HandleMouseWheel);
    EQ_MACRO_FUNCTION_AddDetour(ProcessMouseEvent);
    EQ_MACRO_FUNCTION_AddDetour(ProcessKeyDown);
    EQ_MACRO_FUNCTION_AddDetour(ProcessKeyUp);
    EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);
    EQ_MACRO_FUNCTION_AddDetour(CollisionCallbackForMove);
    EQ_MACRO_FUNCTION_AddDetour(do_target);
    EQ_MACRO_FUNCTION_AddDetour(DoSpellEffect);

    uint32_t graphicsDLLBaseAddress = EQ_GraphicsDLL_GetBaseAddress();

    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx);
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferredPolygons;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dSelectTexture = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dSelectTexture;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dPaintHierarchicalSprite;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2 = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__s3dPaintDMSprite2;

    EQ_MACRO_FUNCTION_AddDetour(EQGraphicsDLL__t3dCreateActorEx);
    EQ_MACRO_FUNCTION_AddDetour(EQGraphicsDLL__t3dRenderDeferredPolygons);
    EQ_MACRO_FUNCTION_AddDetour(EQGraphicsDLL__t3dSelectTexture);
    EQ_MACRO_FUNCTION_AddDetour(EQGraphicsDLL__t3dPaintHierarchicalSprite);
    EQ_MACRO_FUNCTION_AddDetour(EQGraphicsDLL__s3dPaintDMSprite2);

    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__SetRenderState = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__SetRenderState];
    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__DrawIndexedPrimitive];
    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__Reset = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__Reset];

    EQ_MACRO_FUNCTION_AddDetour(EQIDirect3DDevice8__SetRenderState);
    EQ_MACRO_FUNCTION_AddDetour(EQIDirect3DDevice8__DrawIndexedPrimitive);
    EQ_MACRO_FUNCTION_AddDetour(EQIDirect3DDevice8__Reset);
}

void EQAPP_Detours_Unload()
{
    EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);

    EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);

    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__InterpretCmd);

    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__ChangePosition);
    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);
    EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__do_change_form);

    EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__eqspa_movement_rate);
    EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__CastSpell);

    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__CreateActor);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__CreatePlayerActor);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__DeleteActor);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__SetNameSpriteState);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__SetNameSpriteTint);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__ToggleView);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__UpdateItemSlot);
    EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__GetNearestPlayerInView);

    EQ_MACRO_FUNCTION_RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);

    EQ_MACRO_FUNCTION_RemoveDetour(CBuffWindow__RefreshBuffDisplay);
    EQ_MACRO_FUNCTION_RemoveDetour(CBuffWindow__PostDraw);
    
    EQ_MACRO_FUNCTION_RemoveDetour(CItemDisplayWnd__SetItem);
    EQ_MACRO_FUNCTION_RemoveDetour(CItemDisplayWnd__SetSpell);

    EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__StartSpellMemorization);
    EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__FinishMemorizing);
    EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__TurnToPage);
    EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__HandleKeys);

    EQ_MACRO_FUNCTION_RemoveDetour(CLootWnd__Deactivate);

    EQ_MACRO_FUNCTION_RemoveDetour(CContainerWnd__PostDraw);

    EQ_MACRO_FUNCTION_RemoveDetour(CMerchantWnd__PostDraw);

    EQ_MACRO_FUNCTION_RemoveDetour(CListWnd__SetItemText);

    ////EQ_MACRO_FUNCTION_RemoveDetour(CContainerMgr__OpenContainer);

    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__dsp_chat);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__LMouseDown);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__LMouseUp);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__StartCasting);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__MoveToZone);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__MoveToZone__2);
    EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__EnterZone);

    EQ_MACRO_FUNCTION_RemoveDetour(HandleMouseWheel);
    EQ_MACRO_FUNCTION_RemoveDetour(ProcessMouseEvent);
    EQ_MACRO_FUNCTION_RemoveDetour(ProcessKeyDown);
    EQ_MACRO_FUNCTION_RemoveDetour(ProcessKeyUp);
    EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);
    EQ_MACRO_FUNCTION_RemoveDetour(CollisionCallbackForMove);
    EQ_MACRO_FUNCTION_RemoveDetour(do_target);
    EQ_MACRO_FUNCTION_RemoveDetour(DoSpellEffect);

    uint32_t graphicsDLLBaseAddress = EQ_GraphicsDLL_GetBaseAddress();

    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx);
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferredPolygons;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dSelectTexture = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dSelectTexture;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dPaintHierarchicalSprite;
    EQ_ADDRESS_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2 = graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__s3dPaintDMSprite2;

    EQ_MACRO_FUNCTION_RemoveDetour(EQGraphicsDLL__t3dCreateActorEx);
    EQ_MACRO_FUNCTION_RemoveDetour(EQGraphicsDLL__t3dRenderDeferredPolygons);
    EQ_MACRO_FUNCTION_RemoveDetour(EQGraphicsDLL__t3dSelectTexture);
    EQ_MACRO_FUNCTION_RemoveDetour(EQGraphicsDLL__t3dPaintHierarchicalSprite);
    EQ_MACRO_FUNCTION_RemoveDetour(EQGraphicsDLL__s3dPaintDMSprite2);

    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__SetRenderState = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__SetRenderState];
    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__DrawIndexedPrimitive];
    EQ_ADDRESS_FUNCTION_EQIDirect3DDevice8__Reset = EQ_VTABLE_IDirect3DDevice8[EQ_VTABLE_INDEX_IDirect3DDevice8__Reset];

    EQ_MACRO_FUNCTION_RemoveDetour(EQIDirect3DDevice8__SetRenderState);
    EQ_MACRO_FUNCTION_RemoveDetour(EQIDirect3DDevice8__DrawIndexedPrimitive);
    EQ_MACRO_FUNCTION_RemoveDetour(EQIDirect3DDevice8__Reset);
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

    EQ_GraphicsDLL_SetUseTNL(false);
    EQ_GraphicsDLL_SetUseUmbra(true);

    g_alwaysAttackIsEnabled = false;

    g_wallHackIsEnabled = false;
    g_waterHackIsEnabled = false;
    g_treeHackIsEnabled = false;

    g_spawnAlertNewSpawnIDList.clear();

    EQAPP_FreeCamera_SetEnabled(false);

    EQ_SetUseVisActorList(false);

    EQ_SetRun(true);

    EQAPP_WriteInventoryToFile();

    ////EQAPP_BoxChat_Load();

    EQAPP_Mouse_Load();
    ////EQAPP_Keyboard_Load();

    EQAPP_DrawDistance_Load();
    EQAPP_Map_Load();
    EQAPP_ExtendedTargets_Load();
    EQAPP_NetworkStats_Load();
    EQAPP_AutoLoot_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_FoodAndDrink_Load();
    EQAPP_BazaarSearchWindow_LoadItemNames();
    EQAPP_DestroyActors_Load();
    EQAPP_WaterHack_Load();
    EQAPP_TreeHack_Load();

    EQ_FUNCTION_UpdateLight(EQ_POINTER_PlayerCharacter);
}

int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short x, unsigned short y, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(a1, a2, a3, x, y, a6, a7, a8, a9, a10);
    }

    if (g_bLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_killSwitchKey))
    {
        EQAPP_Unload();
        return EQAPP_REAL_FUNCTION_DrawNetStatus(a1, a2, a3, x, y, a6, a7, a8, a9, a10);
    }

    EQAPP_Detours_OnZoneChanged_Event();

    if (g_DRMIsEnabled == true)
    {
        EQAPP_DRM_Execute();
    }

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

    if (g_targetRingIsEnabled == true)
    {
        EQAPP_TargetRing_Execute();
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

    if (g_spellEffectTestIsEnabled == true)
    {
        EQAPP_SpellEffectTest_Execute();
    }

    // mouse and keyboard fix
    EQAPP_Mouse_Acquire();
    ////EQAPP_Keyboard_Acquire();

    EQAPP_Console_Print();

    return EQAPP_REAL_FUNCTION_DrawNetStatus(a1, a2, a3, x, y, a6, a7, a8, a9, a10);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
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
        if (g_map3DIsEnabled == true)
        {
            EQAPP_Map_3D_Execute();
        }
        else
        {
            EQAPP_Map_Execute();
        }
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

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, char* commandText)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, commandText);
    }

    if (g_interpretCmdIsEnabled == true)
    {
        bool result = EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(this_ptr, player, commandText);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, commandText);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool filtered)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, filtered);
    }

    if (text == NULL)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, filtered);
    }

    if (g_trainSpellsIsEnabled == true)
    {
        EQAPP_TrainSpells_HandleEvent_CEverQuest__dsp_chat(this_ptr, text, textColor, filtered);
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, filtered);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseDown(void* this_ptr, void* not_used, uint16_t x, uint16_t y)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseDown(this_ptr, x, y);
    }

    g_bIsLeftMouseButtonHeldDown = true;

    return EQAPP_REAL_FUNCTION_CEverQuest__LMouseDown(this_ptr, x, y);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, uint16_t x, uint16_t y)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    g_bIsLeftMouseButtonHeldDown = false;

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    if (EQ_IsMouseHoveringOverCXWnd() == true)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    if (g_GUIIsEnabled == true)
    {
        if (EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(x, y) == true)
        {
            return 1;
        }
    }

    if (g_extendedTargetsIsEnabled == true)
    {
        if (EQAPP_ExtendedTargets_HandleEvent_CEverQuest__LMouseUp(x, y) == true)
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

    return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQ::CEverQuestStartCastingMessage_ptr message)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

    if (g_startCastingisEnabled == true)
    {
        EQAPP_StartCasting_HandleEvent_CEverQuest__StartCasting(this_ptr, message);
    }

    if (g_spawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(this_ptr, message);
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__MoveToZone(void* this_ptr, void* not_used, EQ_ZoneID_t zoneID, char* text, int destinationType, int zoneRequestReason)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__MoveToZone(this_ptr, zoneID, text, destinationType, zoneRequestReason);
    }

    int result = EQAPP_REAL_FUNCTION_CEverQuest__MoveToZone(this_ptr, zoneID, text, destinationType, zoneRequestReason);

    EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone(this_ptr, zoneID, text, destinationType, zoneRequestReason);

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__MoveToZone__2(void* this_ptr, void* not_used, char* zoneShortName, char* text, int destinationType, int zoneRequestReason)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__MoveToZone__2(this_ptr, zoneShortName, text, destinationType, zoneRequestReason);
    }

    EQAPP_DestroyActors_LoadEx(zoneShortName);

    return EQAPP_REAL_FUNCTION_CEverQuest__MoveToZone__2(this_ptr, zoneShortName, text, destinationType, zoneRequestReason);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__EnterZone(void* this_ptr, void* not_used, int unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__EnterZone(this_ptr, unknown);
    }

    int result = EQAPP_REAL_FUNCTION_CEverQuest__EnterZone(this_ptr, unknown);

    // TODO

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangePosition(void* this_ptr, void* not_used, EQ_StandingState_t standingState)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL && playerSpawn == (EQ::Spawn_ptr)this_ptr)
    {
        if (g_neverFrozenIsEnabled == true)
        {
            EQAPP_NeverFrozen_HandleEvent_EQPlayer__ChangePosition(this_ptr, standingState);
        }

        if (standingState == EQ_STANDING_STATE_SITTING || standingState == EQ_STANDING_STATE_DUCKING)
        {
            if (g_freeCameraIsEnabled == true)
            {
                EQAPP_FreeCamera_SetEnabled(false);
            }

            if (g_spellSetIsEnabled == true)
            {
                EQAPP_SpellSet_HandleEvent_EQPlayer__ChangePosition(this_ptr, standingState);
            }
        }

        if (standingState == EQ_STANDING_STATE_DUCKING)
        {
            if (g_trainSpellsIsEnabled == true)
            {
                EQAPP_TrainSpells_Toggle();
            }
        }
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    if (g_autoFollowIsEnabled == true)
    {
        EQAPP_AutoFollow_HandleEvent__EQPlayer__FollowPlayerAI(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);

    EQAPP_AutoFollow_SetFollowDistanceToDefault();

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__do_change_form(void* this_ptr, void* not_used, EQ::ChangeForm_ptr changeForm)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__do_change_form(this_ptr, changeForm);
    }

/*
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[EQPlayer__do_change_form] Spawn ID: " << (int)changeForm->SpawnID << std::endl;
    std::cout << "[EQPlayer__do_change_form] Race: " << (int)changeForm->Race << std::endl;
    std::cout << "[EQPlayer__do_change_form] Gender: " << (int)changeForm->Gender << std::endl;
    std::cout << "[EQPlayer__do_change_form] Texture: " << (int)changeForm->Texture << std::endl;
    std::cout << "[EQPlayer__do_change_form] Helmet Texture: " << (int)changeForm->HelmetTexture << std::endl;
    std::cout << "[EQPlayer__do_change_form] Unknown07: " << (int)changeForm->Unknown07 << std::endl;
    std::cout << "[EQPlayer__do_change_form] Face: " << (int)changeForm->Face << std::endl;
    std::cout << "[EQPlayer__do_change_form] Hair Type: " << (int)changeForm->HairType << std::endl;
    std::cout << "[EQPlayer__do_change_form] Hair Color: " << (int)changeForm->HairColor << std::endl;
    std::cout << "[EQPlayer__do_change_form] Beard Type: " << (int)changeForm->BeardType << std::endl;
    std::cout << "[EQPlayer__do_change_form] Beard Color: " << (int)changeForm->BeardColor << std::endl;
    std::cout << "[EQPlayer__do_change_form] Size: " << (int)changeForm->Size << std::endl;
    std::cout << "[EQPlayer__do_change_form] Unknown10: " << (int)changeForm->Unknown10 << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
*/

    if (g_replaceRacesIsEnabled == true)
    {
        bool result = EQAPP_ReplaceRaces_HandleEvent_EQPlayer__do_change_form(this_ptr, changeForm);
        if (result == true)
        {
            return 0;
        }
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__do_change_form(this_ptr, changeForm);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, signed short movementSpeed)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
    }

    int result = EQAPP_REAL_FUNCTION_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);

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
        EQAPP_SpeedHack_HandleEvent_EQ_Character__eqspa_movement_rate(this_ptr, movementSpeed);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CastSpell(void* this_ptr, void* not_used, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID, EQ::Item** item, uint16_t unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__CastSpell(this_ptr, spellGemIndex, spellID, item, unknown);
    }

    if (g_autoStandIsEnabled == true && g_autoStandWhenCastSpellIsEnabled == true)
    {
        EQAPP_AutoStand_HandleEvent_EQ_Character__CastSpell(this_ptr, spellGemIndex, spellID, item, unknown);
    }

    return EQAPP_REAL_FUNCTION_EQ_Character__CastSpell(this_ptr, spellGemIndex, spellID, item, unknown);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreateActor(void* this_ptr, void* not_used, char* name, float a2, float a3, float a4, float a5, float a6, float a7, int a8, int a9)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, name, a2, a3, a4, a5, a6, a7, a8, a9);
    }

    // remove doors in POK zone
    //if (strstr(name, "POKDOOR") != NULL)
    //{
        //return 0;
    //}

    return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, name, a2, a3, a4, a5, a6, a7, a8, a9);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, class EQPlayer* player)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, player);
    }

    if (g_spawnAlertIsEnabled == true)
    {
        EQAPP_SpawnAlert_HandleEvent_CDisplay__CreatePlayerActor(this_ptr, player);
    }

    return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, player);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, EQ::ActorInstance_ptr actorInstance)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, actorInstance);
    }

    if (g_spawnAlertIsEnabled == true)
    {
        EQAPP_SpawnAlert_HandleEvent_CDisplay__DeleteActor(this_ptr, actorInstance);
    }

    return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, actorInstance);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__SetNameSpriteState(void* this_ptr, void* not_used, class EQPlayer* player, bool show)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__SetNameSpriteState(this_ptr, player, show);
    }

    int result = EQAPP_REAL_FUNCTION_CDisplay__SetNameSpriteState(this_ptr, player, show);

    if (g_nameSpriteStateIsEnabled == true && show != 0)
    {
        if (EQAPP_NameSpriteState_HandleEvent_CDisplay__SetNameSpriteState(this_ptr, player, show) == false)
        {
            return result;
        }
    }

    EQAPP_DETOURED_FUNCTION_CDisplay__SetNameSpriteTint(this_ptr, not_used, player);

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__SetNameSpriteTint(void* this_ptr, void* not_used, class EQPlayer* player)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__SetNameSpriteTint(this_ptr, player);
    }

    int result = EQAPP_REAL_FUNCTION_CDisplay__SetNameSpriteTint(this_ptr, player);

    if (g_nameSpriteTintIsEnabled == true)
    {
        if (EQAPP_NameSpriteTint_HandleEvent_CDisplay__SetNameSpriteTint(this_ptr, player) == false)
        {
            return result;
        }
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__ToggleView(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__ToggleView(this_ptr);
    }

    if (g_toggleViewIsEnabled == true)
    {
        EQAPP_ToggleView_HandleEvent_CDisplay__ToggleView(this_ptr);
    }

    return EQAPP_REAL_FUNCTION_CDisplay__ToggleView(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__UpdateItemSlot(void* this_ptr, void* not_used, class EQPlayer* player, uint8_t updateItemSlot, char* itemDefinition, bool clientSideOnly)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
    }

/*
    if (player == NULL)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
    }

    auto spawn = (EQ::Spawn_ptr)player;
    if (spawn == NULL)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
    }

    std::string spawnName = EQ_GetSpawnName(spawn);
    if (spawnName.size() == 0)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
    }

    std::string itemDef = itemDefinition;
    if (itemDef.size() == 0)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Spawn Name: " << spawnName << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Item Slot: " << (int)updateItemSlot << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Item Definition: " << itemDef << std::endl;
    std::cout << "[CDisplay__UpdateItemSlot] Client Side Only: " << (int)clientSideOnly << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
*/

/*
    if (itemDef.find("IT") != std::string::npos)
    {
        if (itemDef == "IT120")
        {
            itemDef = "IT145";

            return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, (char*)itemDef.c_str(), true);
        }
    }
*/

    return EQAPP_REAL_FUNCTION_CDisplay__UpdateItemSlot(this_ptr, player, updateItemSlot, itemDefinition, clientSideOnly);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__GetNearestPlayerInView(void* this_ptr, void* not_used, float maxDistance, EQ_SpawnType_t spawnType)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__GetNearestPlayerInView(this_ptr, maxDistance, spawnType);
    }

    int result = EQAPP_REAL_FUNCTION_CDisplay__GetNearestPlayerInView(this_ptr, maxDistance, spawnType);

    EQ::Spawn_ptr spawn = (EQ::Spawn_ptr)result;

    auto targetSpawn = EQ_GetTargetSpawn();

    if (spawn == NULL || spawn == targetSpawn)
    {
        spawn = EQ_GetNearestSpawn(spawnType, 100.0f, 10.0f, targetSpawn);
        if (spawn != NULL)
        {
            std::cout << "[CDisplay__GetNearestPlayerInView] Using EQ_SetTargetSpawn()." << std::endl;

            EQ_SetTargetSpawn(spawn);
        }

        return NULL;
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg(void* this_ptr, void* not_used, EQ::CBazaarSearchWndResultMessage_ptr message)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);
    }

    int result = EQAPP_REAL_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg(this_ptr, message);

/*
    if (message->Action == EQ_BAZAAR_ACTION_SEARCH_RESULTS)
    {
        auto spawn = EQ_GetSpawnByID(message->SpawnID);
        if (spawn != NULL)
        {
            std::cout << "--------------------------------------------------" << std::endl;
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

int __fastcall EQAPP_DETOURED_FUNCTION_CBuffWindow__RefreshBuffDisplay(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CBuffWindow__RefreshBuffDisplay(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_CBuffWindow__RefreshBuffDisplay(this_ptr);

    if (g_buffTimersIsEnabled == true)
    {
        EQAPP_BuffTimers_HandleEvent_CBuffWindow__RefreshBuffDisplay(this_ptr);
    }

    return result;
};

int __fastcall EQAPP_DETOURED_FUNCTION_CBuffWindow__PostDraw(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CBuffWindow__PostDraw(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_CBuffWindow__PostDraw(this_ptr);

    if (g_buffTimersIsEnabled == true)
    {
        EQAPP_BuffTimers_HandleEvent_CBuffWindow__PostDraw(this_ptr);
    }

    return result;
};

int __fastcall EQAPP_DETOURED_FUNCTION_CItemDisplayWnd__SetItem(void* this_ptr, void* not_used, EQ::Item_ptr item, bool unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CItemDisplayWnd__SetItem(this_ptr, item ,unknown);
    }

    int result = EQAPP_REAL_FUNCTION_CItemDisplayWnd__SetItem(this_ptr, item ,unknown);

    if (g_itemDisplayWindowIsEnabled == true && g_itemDisplayWindowItemsIsEnabled == true)
    {
        EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetItem(this_ptr, item ,unknown);
    }

    return result;
}


int __fastcall EQAPP_DETOURED_FUNCTION_CItemDisplayWnd__SetSpell(void* this_ptr, void* not_used, EQ_SpellID_t spellID, bool hasDescription, int unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CItemDisplayWnd__SetSpell(this_ptr, spellID, hasDescription, unknown);
    }

    int result = EQAPP_REAL_FUNCTION_CItemDisplayWnd__SetSpell(this_ptr, spellID, hasDescription, unknown);

    if (g_itemDisplayWindowIsEnabled == true && g_itemDisplayWindowSpellsIsEnabled == true)
    {
        EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetSpell(this_ptr, spellID, hasDescription, unknown);
    }

    return result;
};

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__StartSpellMemorization(void* this_ptr, void* not_used, int spellBookIndex, EQ_SpellGemIndex_t spellGemIndex, bool unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__StartSpellMemorization(this_ptr, spellBookIndex, spellGemIndex, unknown);
    }

    g_bIsMemorizingSpell = true;

    return EQAPP_REAL_FUNCTION_CSpellBookWnd__StartSpellMemorization(this_ptr, spellBookIndex, spellGemIndex, unknown);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__FinishMemorizing(void* this_ptr, void* not_used, EQ_SpellGemIndex_t spellGemIndex, EQ_SpellID_t spellID)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__FinishMemorizing(this_ptr, spellGemIndex, spellID);
    }

    int result = EQAPP_REAL_FUNCTION_CSpellBookWnd__FinishMemorizing(this_ptr, spellGemIndex, spellID);

    g_bIsMemorizingSpell = false;

    if (g_spellSetIsEnabled == true)
    {
        EQAPP_SpellSet_HandleEvent_CSpellBookWnd__FinishMemorizing(this_ptr, spellGemIndex, spellID);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__TurnToPage(void* this_ptr, void* not_used, signed int pageNumber)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__TurnToPage(this_ptr, pageNumber);
    }

    if (g_spellBookWindowIsEnabled == true)
    {
        pageNumber = EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__TurnToPage(this_ptr, pageNumber);
    }

    return EQAPP_REAL_FUNCTION_CSpellBookWnd__TurnToPage(this_ptr, pageNumber);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__HandleKeys(void* this_ptr, void* not_used, int keyID, bool unknown)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__HandleKeys(this_ptr, keyID, unknown);
    }

    if (g_spellBookWindowIsEnabled == true)
    {
        EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__HandleKeys(this_ptr, keyID, unknown);
    }

    return EQAPP_REAL_FUNCTION_CSpellBookWnd__HandleKeys(this_ptr, keyID, unknown);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CLootWnd__Deactivate(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CLootWnd__Deactivate(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_CLootWnd__Deactivate(this_ptr);

    if (g_hideCorpseLootedIsEnabled == true)
    {
        EQAPP_HideCorpseLooted_HandleEvent_CLootWnd__Deactivate(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CContainerWnd__PostDraw(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CContainerWnd__PostDraw(this_ptr);
    }

    if (g_containerWindowIsEnabled == true)
    {
       EQAPP_ContainerWindow_AppendSpellLevelToToolTipText_HandleEvent_CContainerWnd__PostDraw(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_CContainerWnd__PostDraw(this_ptr);

    if (g_containerWindowIsEnabled == true)
    {
        EQAPP_ContainerWindow_AppendSpellLevelToItemSlot_HandleEvent_CContainerWnd__PostDraw(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CMerchantWnd__PostDraw(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CMerchantWnd__PostDraw(this_ptr);
    }

    if (g_merchantWindowIsEnabled == true)
    {
        EQAPP_MerchantWindow_AppendSpellLevelToToolTipText_HandleEvent_CMerchantWnd__PostDraw(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_CMerchantWnd__PostDraw(this_ptr);

    if (g_merchantWindowIsEnabled == true)
    {
        EQAPP_MerchantWindow_AppendSpellLevelToItemSlot_HandleEvent_CMerchantWnd__PostDraw(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CListWnd__SetItemText(void* this_ptr, void* not_used, int index, int column, EQ::CXStr_ptr text)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CListWnd__SetItemText(this_ptr, index, column, text);
    }

    int result = EQAPP_REAL_FUNCTION_CListWnd__SetItemText(this_ptr, index, column, text);

    if (g_bazaarSearchWindowIsEnabled == true)
    {
        EQAPP_BazaarSearchWindow_HandleEvent_CListWnd__SetItemText(this_ptr, index, column, text);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CContainerMgr__OpenContainer(void* this_ptr, void* not_used, EQ::EQ_Container_ptr container, int inventorySlotIndex)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CContainerMgr__OpenContainer(this_ptr, container, inventorySlotIndex);
    }

    ////std::cout << "[CContainerMgr__OpenContainer] inventorySlotIndex: " << inventorySlotIndex << std::endl;

    return EQAPP_REAL_FUNCTION_CContainerMgr__OpenContainer(this_ptr, container, inventorySlotIndex);
}

int __cdecl EQAPP_DETOURED_FUNCTION_HandleMouseWheel(signed int delta)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_HandleMouseWheel(delta);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_HandleMouseWheel(delta);
    }

    if (EQ_IsMouseHoveringOverCXWnd() == true)
    {
        return EQAPP_REAL_FUNCTION_HandleMouseWheel(delta);
    }

    if (g_mapIsEnabled == true)
    {
        EQAPP_Map_HandleEvent_HandleMouseWheel(delta);
    }

    return EQAPP_REAL_FUNCTION_HandleMouseWheel(delta);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMouseEvent(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
    }

    if (g_extraMouseButtonsIsEnabled == true)
    {
        EQAPP_ExtraMouseButtons_HandleEvent_ProcessMouseEvent();
    }

    return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
}

int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyDown(int keyID)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_ProcessKeyDown(keyID);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ProcessKey(keyID);
        if (result == true)
        {
            return EQAPP_REAL_FUNCTION_ProcessKeyDown(NULL);
        }
    }

    return EQAPP_REAL_FUNCTION_ProcessKeyDown(keyID);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyUp(int keyID)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_ProcessKeyUp(keyID);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ProcessKey(keyID);
        if (result == true)
        {
            return EQAPP_REAL_FUNCTION_ProcessKeyUp(NULL);
        }
    }

    return EQAPP_REAL_FUNCTION_ProcessKeyUp(keyID);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, zero);
    }

    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_HandleEvent_ExecuteCmd(commandID, isActive, zero);
    }

    if (g_freeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ExecuteCmd(commandID, isActive, zero);
        if (result == true)
        {
            return EQAPP_REAL_FUNCTION_ExecuteCmd(NULL, 0, 0);
        }
    }

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, zero);
}

int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForMove(EQ::ActorInstance_ptr actorInstance, EQ::Spawn_ptr spawn)
{
    // arg1 = actor instance of actor that spawn has collided into
    // arg2 = spawn that collides with actor instance

    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_CollisionCallbackForMove(actorInstance, spawn);
    }

    if (g_collisionHackIsEnabled == true)
    {
        EQAPP_CollisionHack_HandleEvent_CollisionCallbackForMove(actorInstance, spawn);
    }

    int result = EQAPP_REAL_FUNCTION_CollisionCallbackForMove(actorInstance, spawn);

    EQ_SetActorCollision(true);

    return result;
}

int __cdecl EQAPP_DETOURED_FUNCTION_do_target(class EQClass::EQPlayer* player, const char* spawnName)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_do_target(player, spawnName);
    }

    if (g_doTargetIsEnabled == true)
    {
        bool result = EQAPP_DoTarget_HandleEvent_do_target(player, spawnName);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_do_target(player, spawnName);
}

int __cdecl EQAPP_DETOURED_FUNCTION_DoSpellEffect(int type, EQ::Spell_ptr spell, class EQClass::EQPlayer* player1, class EQClass::EQPlayer* player2, EQ::Location_ptr location, int* missile, uint32_t duration)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_DoSpellEffect(type, spell, player1, player2, location, missile, duration);
    }

/*
    std::cout << "Type: " << a1 << std::endl;

    if (a2)
    {
        std::cout << "Spell ID: " << a2->ID << std::endl;
        std::cout << "Spell Name: " << a2->Name << std::endl;
    }

    if (a3)
    {
        auto spawn = (EQ::Spawn_ptr)a3;

        std::cout << "Spawn1 Name: " << spawn->Name << std::endl;
    }

    if (a4)
    {
        auto spawn = (EQ::Spawn_ptr)a4;

        std::cout << "Spawn2 Name: " << spawn->Name << std::endl;
    }

    std::cout << "Missile: " << a6 << std::endl;
    std::cout << "Duration: " << a7 << std::endl;
*/

    return EQAPP_REAL_FUNCTION_DoSpellEffect(type, spell, player1, player2, location, missile, duration);
}

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dCreateActorEx(int a1, EQ::ActorDefinition_ptr actorDefinition, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dCreateActorEx(a1, actorDefinition, a3, a4, a5, a6, a7, a8, a9, a10);
    }

/*
    EQAPP_Log("EQGraphicsDLL__t3dCreateActorEx", 0);
    EQAPP_Log("a1", a1);
    EQAPP_Log("actorDefinition", actorDefinition);
    EQAPP_Log("a3", a3);
    EQAPP_Log("a4", a4);
    EQAPP_Log("a5", a5);
    EQAPP_Log("a6", a6);
    EQAPP_Log("a7", a7);
    EQAPP_Log("a8", a8);
    EQAPP_Log("a9", a9);
    EQAPP_Log("a10", a10);
*/

    int result = EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dCreateActorEx(a1, actorDefinition, a3, a4, a5, a6, a7, a8, a9, a10);

    if (g_destroyActorsIsEnabled == true)
    {
        EQAPP_DestroyActors_HandleEvent_EQGraphicsDLL__t3dCreateActorEx((EQ::ActorInstance_ptr)result, actorDefinition);
    }

/*
    EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)result;

    if (actorDefinition != NULL && actorInstance != NULL)
    {
        std::string actorDef = actorDefinition->Name;
        if (actorDef.size() != 0)
        {
            EQAPP_Log(actorDef.c_str(), (int)actorDefinition->MagicNumber6);
        }
    }
*/

    return result;
}

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons(void)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons();
    }

    //

    return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons();
}

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dSelectTexture(EQ::Texture_ptr texture)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dSelectTexture(texture);
    }

    if (texture == NULL)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dSelectTexture(texture);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dSelectTexture(texture);
    }

    bool bUseCustomAlpha = false;

    if (g_waterHackIsEnabled == true)
    {
        std::string textureFileName = texture->TextureFileName;

        std::transform(textureFileName.begin(), textureFileName.end(), textureFileName.begin(), toupper);

        for (auto& waterHackTextureFileName : g_waterHackTextureFileNameList)
        {
            if (textureFileName == waterHackTextureFileName)
            {
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCCOLOR);
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);

                bUseCustomAlpha = true;

                break;
            }
        }
    }

    if (g_treeHackIsEnabled == true)
    {
        std::string textureFileName = texture->TextureFileName;

        std::transform(textureFileName.begin(), textureFileName.end(), textureFileName.begin(), toupper);

        for (auto& treeHackTextureFileName : g_treeHackTextureFileNameList)
        {
            if (textureFileName == treeHackTextureFileName)
            {
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
                EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

                bUseCustomAlpha = true;

                break;
            }
        }
    }

    if (bUseCustomAlpha == false)
    {
        EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    }

    return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dSelectTexture(texture);
}

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite(world, renderContext, actorInstance);
    }

    if (g_levelOfDetailIsEnabled == true)
    {
        bool result = EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__t3dPaintHierarchicalSprite(world, renderContext, actorInstance);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite(world, renderContext, actorInstance);
}

int __cdecl EQAPP_DETOURED_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2(int* world, int* renderContext, int* actor)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2(world, renderContext, actor);
    }

    if (g_levelOfDetailIsEnabled == true)
    {
        bool result = EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__s3dPaintDMSprite2(world, renderContext, actor);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2(world, renderContext, actor);
}

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__SetRenderState(D3DRENDERSTATETYPE state, DWORD value)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__SetRenderState(state, value);
    }

    //if (state == D3DRS_x)
    //{
        //value = y;
    //}

    return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__SetRenderState(state, value);
}

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive(LPDIRECT3DDEVICE8 device, D3DPRIMITIVETYPE primitiveType, UINT minIndex, UINT numVertices, UINT startIndex, UINT primitiveCount)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive(device, primitiveType, minIndex, numVertices, startIndex, primitiveCount);
    }

    if (g_wallHackIsEnabled == true)
    {
        LPDIRECT3DVERTEXBUFFER8 streamData;
        UINT stride = 0;

        if (device->GetStreamSource(0, &streamData, &stride) == D3D_OK)
        {
            streamData->Release();
        }

        //std::cout << "Stride: " << stride << std::endl;
        //std::cout << "MinIndex: " << minIndex << std::endl;
        //std::cout << "NumVertices: " << numVertices << std::endl;
        //std::cout << "StartIndex: " << startIndex << std::endl;
        //std::cout << "PrimitiveCount: " << primitiveCount << std::endl;

        // 24 = World + Static Actors
        // 32 = Players/NPCs + Dynamic Actors

        if (stride == 24)
        {
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCCOLOR);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);

            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
        }

        if (stride == 32)
        {
            //EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZENABLE, FALSE);
            EQ_CLASS_POINTER_IDirect3DDevice8->SetRenderState(D3DRS_ZFUNC, D3DCMP_NOTEQUAL);
        }

        int result = EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive(device, primitiveType, minIndex, numVertices, startIndex, primitiveCount);

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

    return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__DrawIndexedPrimitive(device, primitiveType, minIndex, numVertices, startIndex, primitiveCount);
}

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_EQIDirect3DDevice8__Reset(LPDIRECT3DDEVICE8 device, D3DPRESENT_PARAMETERS* presentationParameters)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__Reset(device, presentationParameters);
    }

    //

    return EQAPP_REAL_FUNCTION_EQIDirect3DDevice8__Reset(device, presentationParameters);
}




