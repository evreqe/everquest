#pragma once

LRESULT __stdcall EQAPP_DETOURED_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMouseEvent();
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyboardEvent();
int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForActors(uint32_t cactor);
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);

float __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__encum_factor(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__TakeFallDamage(void* this_ptr, void* not_used, float value);
bool __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CanIBreathe(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CanISeeInvis(void* this_ptr, void* not_used);
void __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__StunMe(void* this_ptr, void* not_used, uint32_t duration, int unknown1, int unknown2, uint8_t bSpinInCircle);
void __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__ProcessEnvironment(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CharacterZoneClient__TotalSpellAffects(void* this_ptr, void* not_used, uint32_t spellAffectIndex, int unknown1, int unknown2, int unknown3, int unknown4);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t standingState);
bool __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__SetNameSpriteTint(void* this_ptr, void* not_used);
bool __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__UpdateItemSlot(void* this_ptr, void* not_used, uint8_t updateItemSlot, int itemDefinition, bool b1, bool serverSide, bool b3);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawCursor(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

char* __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, int x, int y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__RMouseUp(void* this_ptr, void* not_used, int x, int y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__HandleMouseWheel(void* this_ptr, void* not_used, signed int delta);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SendNewText(void* this_ptr, void* not_used, int chatType, char* name, char* text, int unknown);

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreateActor(void* this_ptr, void* not_used, char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, uint32_t spawn, int a2, int a3, int a4, int a5, int a6);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, uint32_t cactor);

int __fastcall EQAPP_DETOURED_FUNCTION_CCamera__SetCameraLocation(void* this_ptr, void* not_used, EQ::Location& location, bool canSetLocation);

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ResetDevice(void* this_ptr, void* not_used, bool unknown);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__RenderPartialScene(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__UpdateDisplay(void* this_ptr, void* not_used);
//int __fastcall EQAPP_DETOURED_FUNCTION_CRender__DrawLineEx(void* this_ptr, void* not_used, int a1, int a2, uint32_t colorARGB);

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, uint32_t itemIconID, uint32_t itemID, void* a9, int a10, void* a11);
int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__FindItem(void* this_ptr, void* not_used, char* itemName);

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(void* this_ptr, void* not_used);

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive(LPDIRECT3DDEVICE9 device, D3DPRIMITIVETYPE primitiveType, INT baseIndex, UINT minIndex, UINT numVertices, UINT startIndex, UINT primitiveCount);

/*

HMODULE WINAPI EQAPP_REAL_FUNCTION_GetModuleHandleA(LPCSTR lpModuleName);
DETOUR_TRAMPOLINE(HMODULE WINAPI EQAPP_REAL_FUNCTION_GetModuleHandleA(LPCSTR lpModuleName), GetModuleHandleA);

HMODULE WINAPI EQAPP_DETOURED_FUNCTION_GetModuleHandleA(LPCSTR lpModuleName);

HINSTANCE WINAPI EQAPP_REAL_FUNCTION_ShellExecuteA
(
    HWND     hwnd,
    LPCSTR   lpOperation,
    LPCSTR   lpFile,
    LPCSTR   lpParameters,
    LPCSTR   lpDirectory,
    INT      nShowCmd
);
DETOUR_TRAMPOLINE(HINSTANCE WINAPI EQAPP_REAL_FUNCTION_ShellExecuteA
(
    HWND     hwnd,
    LPCSTR   lpOperation,
    LPCSTR   lpFile,
    LPCSTR   lpParameters,
    LPCSTR   lpDirectory,
    INT      nShowCmd
), ShellExecuteA);

HINSTANCE WINAPI EQAPP_DETOURED_FUNCTION_ShellExecuteA
(
    HWND     hwnd,
    LPCSTR   lpOperation,
    LPCSTR   lpFile,
    LPCSTR   lpParameters,
    LPCSTR   lpDirectory,
    INT      nShowCmd
);

*/
