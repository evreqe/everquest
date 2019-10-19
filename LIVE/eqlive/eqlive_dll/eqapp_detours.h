#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_combatmacro.h"
#include "eqapp_console.h"
#include "eqapp_killmobs.h"
#include "eqapp_followai.h"
#include "eqapp_freecamera.h"
#include "eqapp_hud.h"
#include "eqapp_interpretcommand.h"
#include "eqapp_sleep.h"
#include "eqapp_windowtitle.h"

bool g_DetoursIsDX9Detoured = false;
bool g_DetoursIsCameraDetoured = false;
bool g_DetoursIsRenderDetoured = false;

void EQAPP_Detours_AddDetoursForDX9();
void EQAPP_Detours_RemoveDetoursForDX9();
void EQAPP_Detours_AddDetoursForCamera();
void EQAPP_Detours_RemoveDetoursForCamera();
void EQAPP_Detours_AddDetoursForRender();
void EQAPP_Detours_RemoveDetoursForRender();
void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();
void EQAPP_Detours_OnEnterOrLeaveZone();
void EQAPP_Detours_OnEnterZone();
void EQAPP_Detours_OnLeaveZone();

EQ_MACRO_FUNCTION_DefineDetour(CollisionCallbackForActors);
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);

EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__encum_factor);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__TakeFallDamage);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__CanIBreathe);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__CanISeeInvis);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__StunMe);
EQ_MACRO_FUNCTION_DefineDetour(EQ_Character__ProcessEnvironment);

EQ_MACRO_FUNCTION_DefineDetour(CharacterZoneClient__TotalSpellAffects);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__ChangePosition);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__SetNameSpriteTint);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__DoPercentConvert);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__SetGameState);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__LMouseUp);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__RMouseUp);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__HandleMouseWheel);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__SendNewText);

EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreateActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreatePlayerActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__DeleteActor);

EQ_MACRO_FUNCTION_DefineDetour(CCamera__SetCameraLocation);

EQ_MACRO_FUNCTION_DefineDetour(CRender__ResetDevice);
EQ_MACRO_FUNCTION_DefineDetour(CRender__ClearRenderToBlack);
EQ_MACRO_FUNCTION_DefineDetour(CRender__RenderPartialScene);
EQ_MACRO_FUNCTION_DefineDetour(CRender__UpdateDisplay);

EQ_MACRO_FUNCTION_DefineDetour(CBazaarSearchWnd__AddItemToList);

EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__GetSpellMemTicksLeft);
EQ_MACRO_FUNCTION_DefineDetour(CSpellBookWnd__GetSpellScribeTicksLeft);

EQ_MACRO_FUNCTION_DefineDetour(IDirect3DDevice9__DrawIndexedPrimitive);

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

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);

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

void EQAPP_Detours_AddDetoursForDX9()
{
    if (g_DetoursIsDX9Detoured == true)
    {
        return;
    }

    auto devicePointer = EQ_GetDirect3DDevicePointer();
    if (devicePointer != NULL)
    {
        EQ_VTABLE_IDirect3DDevice9 = *(uintptr_t**)EQ_GetDirect3DDevicePointer();
        if (EQ_VTABLE_IDirect3DDevice9 != NULL)
        {
            EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive = EQ_VTABLE_IDirect3DDevice9[EQ_VTABLE_INDEX_IDirect3DDevice9__DrawIndexedPrimitive];
            if (EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive != 0)
            {
                //std::cout << "DrawIndexedPrimitive: 0x" << std::hex << EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive << std::dec << std::endl;

                EQ_MACRO_FUNCTION_AddDetour(IDirect3DDevice9__DrawIndexedPrimitive);

                //std::cout << "AddDetoursForDX9 ok!" << std::endl;

                g_DetoursIsDX9Detoured = true;
                return;
            }
        }
    }

    std::cout << "AddDetoursForDX9 fail!" << std::endl;

    g_DetoursIsDX9Detoured = false;
}

void EQAPP_Detours_RemoveDetoursForDX9()
{
    if (g_DetoursIsDX9Detoured == false)
    {
        return;
    }

    auto devicePointer = EQ_GetDirect3DDevicePointer();
    if (devicePointer != NULL)
    {
        EQ_VTABLE_IDirect3DDevice9 = *(uintptr_t**)EQ_GetDirect3DDevicePointer();
        if (EQ_VTABLE_IDirect3DDevice9 != NULL)
        {
            EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive = EQ_VTABLE_IDirect3DDevice9[EQ_VTABLE_INDEX_IDirect3DDevice9__DrawIndexedPrimitive];
            if (EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive != 0)
            {
                EQ_MACRO_FUNCTION_RemoveDetour(IDirect3DDevice9__DrawIndexedPrimitive);

                //std::cout << "RemoveDetoursForDX9 ok!" << std::endl;

                g_DetoursIsDX9Detoured = false;
                return;
            }
        }
    }

    std::cout << "RemoveDetoursForDX9 fail!" << std::endl;

    g_DetoursIsDX9Detoured = true;
}

void EQAPP_Detours_AddDetoursForCamera()
{
    if (g_DetoursIsCameraDetoured == true)
    {
        return;
    }

    EQ_ADDRESS_POINTER_CCamera = EQ_GetCamera();
    if (EQ_ADDRESS_POINTER_CCamera != 0)
    {
        auto EQ_VFTABLE_CCamera = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CCamera + EQ_OFFSET_CCamera_VFTABLE);
        if (EQ_VFTABLE_CCamera != 0)
        {
            EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CCamera + EQ_VFTABLE_INDEX_CCamera__SetCameraLocation);
            if (EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation != 0)
            {
                EQ_MACRO_FUNCTION_AddDetour(CCamera__SetCameraLocation);

                //std::cout << "AddDetoursForCamera ok!" << std::endl;

                g_DetoursIsCameraDetoured = true;
                return;
            }
        }
    }

    std::cout << "AddDetoursForCamera fail!" << std::endl;

    g_DetoursIsCameraDetoured = false;
}

void EQAPP_Detours_RemoveDetoursForCamera()
{
    if (g_DetoursIsCameraDetoured == false)
    {
        return;
    }

    EQ_ADDRESS_POINTER_CCamera = EQ_GetCamera();
    if (EQ_ADDRESS_POINTER_CCamera != 0)
    {
        auto EQ_VFTABLE_CCamera = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CCamera + EQ_OFFSET_CCamera_VFTABLE);
        if (EQ_VFTABLE_CCamera != 0)
        {
            EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CCamera + EQ_VFTABLE_INDEX_CCamera__SetCameraLocation);
            if (EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation != 0)
            {
                EQ_MACRO_FUNCTION_RemoveDetour(CCamera__SetCameraLocation);

                //std::cout << "RemoveDetoursForCamera ok!" << std::endl;

                g_DetoursIsCameraDetoured = false;
                return;
            }
        }
    }

    std::cout << "RemoveDetoursForCamera fail!" << std::endl;

    g_DetoursIsCameraDetoured = true;
}

void EQAPP_Detours_AddDetoursForRender()
{
    if (g_DetoursIsRenderDetoured == true)
    {
        return;
    }

    auto render = EQ_GetRender();
    if (render != 0)
    {
        auto EQ_VFTABLE_CRender = EQ_ReadMemory<uint32_t>(render + EQ_OFFSET_CRender_VFTABLE);
        if (EQ_VFTABLE_CRender != 0)
        {
            EQ_ADDRESS_FUNCTION_CRender__ResetDevice        = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ResetDevice);
            EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
            EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
            EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__UpdateDisplay);

            if
            (
                EQ_ADDRESS_FUNCTION_CRender__ResetDevice        != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      != 0
            )
            {
                EQ_MACRO_FUNCTION_AddDetour(CRender__ResetDevice);
                EQ_MACRO_FUNCTION_AddDetour(CRender__ClearRenderToBlack);
                EQ_MACRO_FUNCTION_AddDetour(CRender__RenderPartialScene);
                EQ_MACRO_FUNCTION_AddDetour(CRender__UpdateDisplay);

                //std::cout << "AddDetoursForRender ok!" << std::endl;

                g_DetoursIsRenderDetoured = true;
                return;
            }
        }
    }

    std::cout << "AddDetoursForRender fail!" << std::endl;

    g_DetoursIsRenderDetoured = false;
}

void EQAPP_Detours_RemoveDetoursForRender()
{
    if (g_DetoursIsRenderDetoured == false)
    {
        return;
    }

    auto render = EQ_GetRender();
    if (render != 0)
    {
        auto EQ_VFTABLE_CRender = EQ_ReadMemory<uint32_t>(render + EQ_OFFSET_CRender_VFTABLE);
        if (EQ_VFTABLE_CRender != 0)
        {
            EQ_ADDRESS_FUNCTION_CRender__ResetDevice        = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ResetDevice);
            EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
            EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
            EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__UpdateDisplay);

            if
            (
                EQ_ADDRESS_FUNCTION_CRender__ResetDevice        != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      != 0
            )
            {
                EQ_MACRO_FUNCTION_RemoveDetour(CRender__ResetDevice);
                EQ_MACRO_FUNCTION_RemoveDetour(CRender__ClearRenderToBlack);
                EQ_MACRO_FUNCTION_RemoveDetour(CRender__RenderPartialScene);
                EQ_MACRO_FUNCTION_RemoveDetour(CRender__UpdateDisplay);

                //std::cout << "RemoveDetoursForRender ok!" << std::endl;

                g_DetoursIsRenderDetoured = false;
                return;
            }
        }
    }

    std::cout << "RemoveDetoursForRender fail!" << std::endl;

    g_DetoursIsRenderDetoured = true;
}

void EQAPP_Detours_Load()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    if (EQ_ADDRESS_FUNCTION_CollisionCallbackForActors != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(CollisionCallbackForActors);
    }

    if (EQ_ADDRESS_FUNCTION_DrawNetStatus != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);
    }

    if (EQ_ADDRESS_FUNCTION_ExecuteCmd != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__encum_factor);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__TakeFallDamage);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__CanIBreathe);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__CanISeeInvis);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__StunMe != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__StunMe);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQ_Character__ProcessEnvironment);
    }

    if (EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(CharacterZoneClient__TotalSpellAffects);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__ChangePosition);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__SetNameSpriteTint);
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);
        }
    }

    if (EQ_ADDRESS_POINTER_CEverQuest != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__DoPercentConvert);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__dsp_chat);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__SetGameState);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__LMouseUp);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__RMouseUp);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__HandleMouseWheel);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__SendNewText);
        }
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CDisplay__CreateActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreateActor);
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreatePlayerActor);
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__DeleteActor);
        }
    }

    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CBazaarSearchWnd__AddItemToList);
        }
    }

    if (EQ_ADDRESS_POINTER_CSpellBookWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__GetSpellMemTicksLeft);
        }

        if (EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CSpellBookWnd__GetSpellScribeTicksLeft);
        }
    }

    EQAPP_Detours_AddDetoursForDX9();
    EQAPP_Detours_AddDetoursForCamera();
    EQAPP_Detours_AddDetoursForRender();

/*
    DetourFunctionWithTrampoline((PBYTE)EQAPP_REAL_FUNCTION_GetModuleHandleA, (PBYTE)EQAPP_DETOURED_FUNCTION_GetModuleHandleA);
    DetourFunctionWithTrampoline((PBYTE)EQAPP_REAL_FUNCTION_ShellExecuteA, (PBYTE)EQAPP_DETOURED_FUNCTION_ShellExecuteA);
*/

    DetourTransactionCommit();
}

void EQAPP_Detours_Unload()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    if (EQ_ADDRESS_FUNCTION_CollisionCallbackForActors != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CollisionCallbackForActors);
    }

    if (EQ_ADDRESS_FUNCTION_DrawNetStatus != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);
    }

    if (EQ_ADDRESS_FUNCTION_ExecuteCmd != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__encum_factor);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__TakeFallDamage);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__CanIBreathe);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__CanISeeInvis);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__StunMe != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__StunMe);
    }

    if (EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQ_Character__ProcessEnvironment);
    }

    if (EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CharacterZoneClient__TotalSpellAffects);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__ChangePosition);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__SetNameSpriteTint);
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);
        }
    }

    if (EQ_ADDRESS_POINTER_CEverQuest != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__DoPercentConvert);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__InterpretCmd);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__dsp_chat);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__SetGameState);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__LMouseUp);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__RMouseUp);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__HandleMouseWheel);
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__SendNewText);
        }
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CDisplay__CreateActor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__CreateActor);
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__CreatePlayerActor);
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__DeleteActor);
        }
    }

    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CBazaarSearchWnd__AddItemToList);
        }
    }

    if (EQ_ADDRESS_POINTER_CSpellBookWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__GetSpellMemTicksLeft);
        }

        if (EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CSpellBookWnd__GetSpellScribeTicksLeft);
        }
    }

    EQAPP_Detours_RemoveDetoursForDX9();
    EQAPP_Detours_RemoveDetoursForCamera();
    EQAPP_Detours_RemoveDetoursForRender();

/*
    DetourRemove((PBYTE)EQAPP_REAL_FUNCTION_GetModuleHandleA, (PBYTE)EQAPP_DETOURED_FUNCTION_GetModuleHandleA);
    DetourRemove((PBYTE)EQAPP_REAL_FUNCTION_ShellExecuteA, (PBYTE)EQAPP_DETOURED_FUNCTION_ShellExecuteA);
*/

    DetourTransactionCommit();
}

void EQAPP_Detours_OnEnterOrLeaveZone()
{
    EQAPP_FollowAI_StopFollow();

    g_AutoGroupIsInvited = false;

    EQAPP_Waypoint_FollowPath_Off();

    EQAPP_WaypointEditor_Reset();

    EQAPP_KillMobs_Off();

    EQAPP_FreeCamera_Off();
    EQAPP_Speed_Off();
}

void EQAPP_Detours_OnEnterZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

    EQAPP_ActorCollision_Load();
    EQAPP_WaypointList_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_KillMobs_Load();
    EQAPP_ChatEvent_Load();
    EQAPP_Bandolier_Load();
    EQAPP_BazaarFilter_Load();
    EQAPP_CombatMacro_Load();

    g_NoDrawIsEnabled = true;

    g_EQAppIsInGame = true;

    EQ_InterpretCommand("/outputfile inventory");
}

void EQAPP_Detours_OnLeaveZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

    g_NoDrawIsEnabled = false;

    g_EQAppIsInGame = false;
}

int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForActors(uint32_t cactor)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CollisionCallbackForActors(cactor);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CollisionCallbackForActors(cactor);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CollisionCallbackForActors(cactor);
    }

    if (g_ActorCollisionIsEnabled == true)
    {
        bool result = EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors(cactor);
        if (result == true)
        {
            return 0; // no collision
        }

        if (g_ActorCollisionAllIsEnabled == true)
        {
            return 0; // no collision
        }

        if (g_ActorCollisionPlayerIsEnabled == true)
        {
            bool result = EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors_Player(cactor);
            if (result == true)
            {
                return 0; // no collision
            }
        }
    }

    return EQAPP_REAL_FUNCTION_CollisionCallbackForActors(cactor);
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

    // kill switch
    if (GetAsyncKeyState(g_EQAppKillSwitchKey))
    {
        EQAPP_Unload();
        EQAPP_Console_Print();

        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    // show windows
    if (GetAsyncKeyState(g_EQAppShowWindowsKey))
    {
        ShowWindow(EQ_GetWindow(), SW_SHOW);

        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();

        g_EQAppIsInGame = true;
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_NoAlertIsEnabled == true)
    {
        EQAPP_NoAlert_Execute();
    }

    if (g_WindowTitleIsEnabled == true)
    {
        if (EQAPP_Timer_HasTimeElapsed(g_WindowTitleTimer, g_WindowTitleTimerInterval) == true)
        {
            EQAPP_WindowTitle_Execute();
        }
    }

    if (g_WindowForegroundIsEnabled == true)
    {
        EQAPP_WindowForeground_Execute();
    }

    if (g_BoxChatIsEnabled == true)
    {
        if (g_BoxChatIsConnected == true)
        {
            EQAPP_BoxChat_Execute();
        }
        else
        {
            if (g_BoxChatAutoConnectIsEnabled == true)
            {
                if (EQAPP_Timer_HasTimeElapsed(g_BoxChatAutoConnectTimer, g_BoxChatAutoConnectTimerInterval) == true)
                {
                    if (EQAPP_BoxChat_IsServerRunning() == true)
                    {
                        std::string playerSpawnName = EQ_GetPlayerSpawnName();
                        if (playerSpawnName.size() != 0)
                        {
                            EQAPP_BoxChat_Connect(playerSpawnName);
                        }
                    }
                }
            }
        }
    }

    if (g_CheatNeverSlideIsEnabled == true)
    {
        EQ_SetPlayerSpawnFrictionToDefault();
    }

    if (g_CheatLevitateIsEnabled == true)
    {
         EQAPP_Cheat_Levitate_Execute();
    }

    if (g_CheatFlyIsEnabled == true)
    {
         EQAPP_Cheat_Fly_Execute();
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
    }

    if (g_LanternIsEnabled == true)
    {
        EQAPP_Lantern_Execute();
    }

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Execute();
    }

    if (g_AlwaysAttackIsEnabled == true)
    {
        EQAPP_AlwaysAttack_Execute();
    }

    if (g_AlwaysHotButtonIsEnabled == true)
    {
        EQAPP_AlwaysHotButton_Execute();
    }

    if (g_AutoGroupIsEnabled == true)
    {
        EQAPP_AutoGroup_Execute();
    }

    if (g_CombatHotButtonIsEnabled == true)
    {
        EQAPP_CombatHotButton_Execute();
    }

    if (g_CombatMacroIsEnabled == true)
    {
        EQAPP_CombatMacro_Execute();
    }

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    if (g_NameColorIsEnabled == true)
    {
        EQAPP_NameColor_Execute();
    }

    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_Execute();
    }

    if (g_PowerLevelIsEnabled == true)
    {
        EQAPP_PowerLevel_Execute();
    }

    if (g_SpeedIsEnabled == true)
    {
        EQAPP_Speed_Execute();
    }

    if (g_KillMobsIsEnabled == true)
    {
        EQAPP_KillMobs_Execute();
    }

    if (g_WaypointIsEnabled == true && g_WaypointFollowPathIsEnabled == true)
    {
        EQAPP_Waypoint_FollowPathList(g_WaypointFollowPathIndexList);
    }

    if (g_HUDIsEnabled == true)
    {
        EQAPP_HUD_Execute();
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

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

    if (commandID == EQ_EXECUTECMD_DUCK || commandID == EQ_EXECUTECMD_JUMP)
    {
        g_EQAppIsInGame = true;
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

    ////std::cout << "ExecuteCmd(): " << commandID << " (Active: " << isActive << ") " << zero << std::endl;

    if (g_FollowAIIsEnabled == true)
    {
        bool result = EQAPP_FollowAI_HandleEvent_ExecuteCmd(commandID, isActive, zero);
        if (result == true)
        {
            return 1;
        }
    }

    if (g_FreeCameraIsEnabled == true)
    {
        bool result = EQAPP_FreeCamera_HandleEvent_ExecuteCmd(commandID, isActive, zero);
        if (result == true)
        {
            return 1;
        }
    }

    if (g_WaypointIsEnabled == true)
    {
        if (g_WaypointFollowPathIsEnabled == true)
        {
            bool result = EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(commandID, isActive, zero);
            if (result == true)
            {
                return 1;
            }
        }

        if (g_WaypointEditorIsEnabled == true)
        {
            bool result = EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(commandID, isActive, zero);
            if (result == true)
            {
                return 1;
            }
        }
    }

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
}

float __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__encum_factor(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__encum_factor(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__encum_factor(this_ptr);
    }

    if (g_CheatNeverEncumberedIsEnabled == true)
    {
        // never encumbered
        return 1.0f;
    }

    return EQAPP_REAL_FUNCTION_EQ_Character__encum_factor(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__TakeFallDamage(void* this_ptr, void* not_used, float value)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__TakeFallDamage(this_ptr, value);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__TakeFallDamage(this_ptr, value);
    }

    if (g_CheatNoFallDamageIsEnabled == true)
    {
        // never take fall damage
        std::cout << "You would have taken fall damage! (" << value << ")" << std::endl;
        return 0;
    }

    return EQAPP_REAL_FUNCTION_EQ_Character__TakeFallDamage(this_ptr, value);
}

bool __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CanIBreathe(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__CanIBreathe(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__CanIBreathe(this_ptr);
    }

    if (g_CheatAlwaysBreatheUnderwaterIsEnabled == true)
    {
        // always breathe underwater
        return true;
    }

    return EQAPP_REAL_FUNCTION_EQ_Character__CanIBreathe(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__CanISeeInvis(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__CanISeeInvis(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__CanISeeInvis(this_ptr);
    }

    // need to call the function first so infravision and ultravision work
    int result = EQAPP_REAL_FUNCTION_EQ_Character__CanISeeInvis(this_ptr);

    if (g_CheatAlwaysSeeInvisIsEnabled == true)
    {
        // always see invisible
        return 1;
    }

    return result;
}

void __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__StunMe(void* this_ptr, void* not_used, uint32_t duration, int unknown1, int unknown2, uint8_t bSpinInCircle)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__StunMe(this_ptr, duration, unknown1, unknown2, bSpinInCircle);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__StunMe(this_ptr, duration, unknown1, unknown2, bSpinInCircle);
    }

    if (g_CheatNeverStunnedIsEnabled == true)
    {
        // never stunned
        return;
    }

    // never spin in circles when stunned
    bSpinInCircle = 0;

    return EQAPP_REAL_FUNCTION_EQ_Character__StunMe(this_ptr, duration, unknown1, unknown2, bSpinInCircle);
}

void __fastcall EQAPP_DETOURED_FUNCTION_EQ_Character__ProcessEnvironment(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__ProcessEnvironment(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQ_Character__ProcessEnvironment(this_ptr);
    }

    if (g_CheatNoEnvironmentalDamageIsEnabled == true)
    {
        // never take environmental damage
        return;
    }

    return EQAPP_REAL_FUNCTION_EQ_Character__ProcessEnvironment(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CharacterZoneClient__TotalSpellAffects(void* this_ptr, void* not_used, uint32_t spellAffectIndex, int unknown1, int unknown2, int unknown3, int unknown4)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CharacterZoneClient__TotalSpellAffects(this_ptr, spellAffectIndex, unknown1, unknown2, unknown3, unknown4);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CharacterZoneClient__TotalSpellAffects(this_ptr, spellAffectIndex, unknown1, unknown2, unknown3, unknown4);
    }

    int result = EQAPP_REAL_FUNCTION_CharacterZoneClient__TotalSpellAffects(this_ptr, spellAffectIndex, unknown1, unknown2, unknown3, unknown4);

    // always see invisible
    if (g_CheatAlwaysSeeInvisIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_SEE_INVISIBLE)
        {
            return 1;
        }
    }

    // always breathe underwater
    if (g_CheatAlwaysBreatheUnderwaterIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_ENDURING_BREATH)
        {
            return 1;
        }
    }

    // always have ultravision
    if (g_CheatAlwaysHaveUltravisionIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_ULTRAVISION)
        {
            return 2;
        }
    }

    // always have spirit of wolf
    if (g_CheatAlwaysHaveSpiritOfWolfIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_MOVEMENT_RATE)
        {
            if (result >= 0 && result < 60)
            {
                return 60;
            }
        }
    }

    // never rooted
    if (g_CheatNeverRootedIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_ROOT)
        {
            return 0;
        }
    }

    // never snared
    if (g_CheatNeverSnaredIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_MOVEMENT_RATE)
        {
            if (result < 0)
            {
                return 60;
            }
        }
    }

    // never blind
    if (g_CheatNeverBlindIsEnabled == true)
    {
        if (spellAffectIndex == EQ_SPELL_AFFECT_BLIND)
        {
            return 0;
        }
    }

    // always have max bandolier slots
    if (spellAffectIndex == EQ_SPELL_AFFECT_BANDOLIER_SLOTS)
    {
        return EQ_NUM_BANDOLIER_SLOTS;
    }

/*
    // always have max extended target window slots
    if (spellAffectIndex == EQ_SPELL_AFFECT_EXTENDED_TARGET_WINDOW_SLOTS)
    {
        return EQ_NUM_XTARGETS;
    }
*/

/*
    // causes problems with hp/mana regen?
    if (EQ_GetZoneID() == EQ_ZONE_ID_POKNOWLEDGE)
    {
        // never hungry or thirsty
        if (spellAffectIndex == EQ_SPELL_AFFECT_HUNGER_AND_THIRST)
        {
            return 1;
        }
    }
*/

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t standingState)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
    }

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_HandleEvent_EQPlayer__ChangePosition(this_ptr, standingState);
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__ChangePosition(this_ptr, standingState);
}

bool __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__SetNameSpriteTint(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    bool result = EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);

    if (g_NameColorIsEnabled == true)
    {
        EQAPP_NameColor_HandleEvent_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (EQ_IsWindowInBackground() == false)
    {
        if (g_ESPIsEnabled == true)
        {
            EQAPP_ESP_Execute();
        }

        if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
        {
            EQAPP_WaypointList_Draw();
            EQAPP_WaypointEditor_DrawText();
        }
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

char* __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__DoPercentConvert(this_ptr, text, isOutgoing);
    }

    if (text == NULL)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__DoPercentConvert(this_ptr, text, isOutgoing);
    }

    std::string str;
    str.reserve(strlen(text));

    str = text;

    if (EQAPP_String_Contains(str, "${") != false)
    {
        EQAPP_InterpretCommand_ConvertText(str);

        if (str.size() != 0)
        {
            return EQAPP_REAL_FUNCTION_CEverQuest__DoPercentConvert(this_ptr, (char*)str.c_str(), isOutgoing);
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__DoPercentConvert(this_ptr, text, isOutgoing);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (text == NULL)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
    }

    if (g_InterpretCommandIsEnabled == true)
    {
        bool result = EQAPP_InterpretCommand_HandleEvent_CEverQuest__InterpretCmd(this_ptr, player, text);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__InterpretCmd(this_ptr, player, text);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, one_1, one_2, zero_1);
    }

    if (text == NULL)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, one_1, one_2, zero_1);
    }

    std::string chatText = text;

    ////EQAPP_Log(chatText.c_str(), textColor);

    int result = EQAPP_REAL_FUNCTION_CEverQuest__dsp_chat(this_ptr, text, textColor, one_1, one_2, zero_1);

    if (chatText == "LOADING, PLEASE WAIT...")
    {
        EQAPP_Detours_OnLeaveZone();
    }

    if (EQAPP_String_BeginsWith(chatText, "You have entered ") == true)
    {
        if (EQAPP_String_BeginsWith(chatText, "You have entered an ") == false)
        {
            if (g_DetoursIsDX9Detoured == false && g_DetoursIsCameraDetoured == false && g_DetoursIsRenderDetoured == false)
            {
                DetourTransactionBegin();
                DetourUpdateThread(GetCurrentThread());

                EQAPP_Detours_AddDetoursForDX9();
                EQAPP_Detours_AddDetoursForCamera();
                EQAPP_Detours_AddDetoursForRender();

                DetourTransactionCommit();
            }

            EQAPP_Detours_OnEnterZone();
        }
    }

    if (chatText == "It will take you about 30 seconds to prepare your camp.")
    {
        EQ_InterpretCommand("/outputfile inventory");

        if (g_DetoursIsDX9Detoured == true && g_DetoursIsCameraDetoured == true && g_DetoursIsRenderDetoured == true)
        {
            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());

            EQAPP_Detours_RemoveDetoursForDX9();
            EQAPP_Detours_RemoveDetoursForCamera();
            EQAPP_Detours_RemoveDetoursForRender();

            DetourTransactionCommit();
        }
    }

    if (chatText == "You abandon your preparations to camp.")
    {
        if (g_DetoursIsDX9Detoured == false && g_DetoursIsCameraDetoured == false && g_DetoursIsRenderDetoured == false)
        {
            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());

            EQAPP_Detours_AddDetoursForDX9();
            EQAPP_Detours_AddDetoursForCamera();
            EQAPP_Detours_AddDetoursForRender();

            DetourTransactionCommit();
        }
    }

    if (g_AutoGroupIsEnabled == true)
    {
        EQAPP_AutoGroup_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }

    if (g_ChatEventIsEnabled == true)
    {
        EQAPP_ChatEvent_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SetGameState(this_ptr, gameState);
    }

    g_NoDrawIsEnabled = false;

    EQAPP_FollowAI_StopFollow();

    EQAPP_InitializeAddresses();
    EQAPP_InitializeAddressPointers();

    if (gameState != EQ_GAME_STATE_IN_GAME)
    {
        if (g_DetoursIsDX9Detoured == true && g_DetoursIsCameraDetoured == true && g_DetoursIsRenderDetoured == true)
        {
            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());

            EQAPP_Detours_RemoveDetoursForDX9();
            EQAPP_Detours_RemoveDetoursForCamera();
            EQAPP_Detours_RemoveDetoursForRender();

            DetourTransactionCommit();
        }
    }

    if (gameState == EQ_GAME_STATE_CHARACTER_SELECT || gameState == EQ_GAME_STATE_IN_GAME)
    {
        EQAPP_SetWindowTitle("EverQuest*");
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__SetGameState(this_ptr, gameState);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, int x, int y)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
    }

    if (g_ESPIsEnabled == true)
    {
        bool result = EQAPP_ESP_HandleEvent_CEverQuest__LMouseUp(x, y);
        if (result == true)
        {
            return 1;
        }
    }

    if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
    {
        bool result = EQAPP_WaypointEditor_HandleEvent_CEverQuest__LMouseUp(x, y);
        if (result == true)
        {
            EQ_ClearTarget();
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__LMouseUp(this_ptr, x, y);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__RMouseUp(void* this_ptr, void* not_used, int x, int y)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__RMouseUp(this_ptr, x, y);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__RMouseUp(this_ptr, x, y);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__RMouseUp(this_ptr, x, y);
    }

    if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
    {
        bool result = EQAPP_WaypointEditor_HandleEvent_CEverQuest__RMouseUp(x, y);
        if (result == true)
        {
            EQ_ClearTarget();
            return EQAPP_REAL_FUNCTION_CEverQuest__RMouseUp(this_ptr, -20000, -20000); // prevent clicking on merchants or getting stuck in mouse look
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__RMouseUp(this_ptr, x, y);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__HandleMouseWheel(void* this_ptr, void* not_used, signed int delta)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__HandleMouseWheel(this_ptr, delta);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__HandleMouseWheel(this_ptr, delta);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__HandleMouseWheel(this_ptr, delta);
    }

    ////std::cout << "mouse wheel delta: " << delta << std::endl;

    // clamp delta value within valid range due to bug with GUI
    if (delta > EQ_MOUSE_WHEEL_DELTA_MAX || delta < EQ_MOUSE_WHEEL_DELTA_MIN)
    {
        delta = EQ_MOUSE_WHEEL_DELTA_DEFAULT;
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__HandleMouseWheel(this_ptr, delta);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SendNewText(void* this_ptr, void* not_used, int chatType, char* name, char* text, int unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SendNewText(this_ptr, chatType, name, text, unknown);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SendNewText(this_ptr, chatType, name, text, unknown);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SendNewText(this_ptr, chatType, name, text, unknown);
    }

    if (text == NULL)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SendNewText(this_ptr, chatType, name, text, unknown);
    }

    std::string strText = text;

    if (EQAPP_String_Contains(strText, "//") == true)
    {
        std::cout << "Double-slash command blocked from being sent accidentally by CEverQuest::SendNewText()!" << std::endl;
        return 1;
    }


/*
    std::stringstream ss;

    ss << "Chat Type: " << chatType << "\n";

    if (name != NULL)
    {
        ss << "Name: " << name << "\n";
    }

    if (text != NULL)
    {
        ss << "Text: " << text << "\n";
    }

    ss << "--------------------------------------------------\n";

    EQAPP_PrintTextToFile("sendnewtextdebug.txt", ss.str().c_str());
*/

    return EQAPP_REAL_FUNCTION_CEverQuest__SendNewText(this_ptr, chatType, name, text, unknown);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreateActor(void* this_ptr, void* not_used, char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, actorDefinition, y, x, z, a5, a6, a7, a8, a9, a10, a11);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, actorDefinition, y, x, z, a5, a6, a7, a8, a9, a10, a11);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, actorDefinition, y, x, z, a5, a6, a7, a8, a9, a10, a11);
    }

    if (actorDefinition == NULL)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, actorDefinition, y, x, z, a5, a6, a7, a8, a9, a10, a11);
    }

/*
    std::cout << "CDisplay::CreateActor(): " << actorDefinition << std::endl;
*/

    return EQAPP_REAL_FUNCTION_CDisplay__CreateActor(this_ptr, actorDefinition, y, x, z, a5, a6, a7, a8, a9, a10, a11);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, uint32_t spawn, int a2, int a3, int a4, int a5, int a6)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);
    }

    if (spawn == NULL)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);
    }

    int result = EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);

/*
    std::string spawnNameNumbered = EQ_GetSpawnNameNumbered(spawn);
    if (spawnNameNumbered.size() != 0)
    {
        std::cout << "CDisplay::CreatePlayerActor(): " << spawnNameNumbered << std::endl;
    }
*/

    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_HandleEvent_CDisplay__CreatePlayerActor(this_ptr, spawn);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, uint32_t cactor)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
    }

    ////std::cout << "CDisplay::DeleteActor(): 0x" << std::hex << cactor << std::dec << std::endl;

/*
    auto actorType = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_TYPE);
    if (actorType == EQ_ACTOR_TYPE_PLAYER)
    {
        auto actorApplicationData = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_APPLICATION_DATA);
        if (actorApplicationData != NULL)
        {
            std::string spawnNameNumbered = EQ_GetSpawnNameNumbered(actorApplicationData);
            if (spawnNameNumbered.size() != 0)
            {
                std::cout << "CDisplay::DeleteActor(): " << spawnNameNumbered << std::endl;
            }
        }
    }
*/

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_HandleEvent_CDisplay__DeleteActor(this_ptr, cactor);
    }

    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_HandleEvent_CDisplay__DeleteActor(this_ptr, cactor);
    }

    return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CCamera__SetCameraLocation(void* this_ptr, void* not_used, EQ::Location& location, bool canSetLocation)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CCamera__SetCameraLocation(this_ptr, location, canSetLocation);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CCamera__SetCameraLocation(this_ptr, location, canSetLocation);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CCamera__SetCameraLocation(this_ptr, location, canSetLocation);
    }

    if (g_FreeCameraIsEnabled == true)
    {
        EQAPP_FreeCamera_Execute();
        return -1;
    }

    return EQAPP_REAL_FUNCTION_CCamera__SetCameraLocation(this_ptr, location, canSetLocation);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ResetDevice(void* this_ptr, void* not_used, bool unknown)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CRender__ResetDevice(this_ptr, unknown);
    }

    //

    return EQAPP_REAL_FUNCTION_CRender__ResetDevice(this_ptr, unknown);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CRender__ClearRenderToBlack(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__ClearRenderToBlack(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__ClearRenderToBlack(this_ptr);
    }

    if (g_CheatNeverBlindIsEnabled == true)
    {
        // draw the scene so we can see stuff because this gets skipped while blind
        EQ_CLASS_POINTER_CRender->RenderPartialScene();

        // never blind
        return 0;
    }

    return EQAPP_REAL_FUNCTION_CRender__ClearRenderToBlack(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__RenderPartialScene(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CRender__RenderPartialScene(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__RenderPartialScene(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__RenderPartialScene(this_ptr);
    }

    if (g_NoDrawIsEnabled == true)
    {
        bool result = EQAPP_NoDraw_HandleEvent_CRender__RenderPartialScene(this_ptr);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CRender__RenderPartialScene(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__UpdateDisplay(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
    }

    if (g_NoDrawIsEnabled == true)
    {
        bool result = EQAPP_NoDraw_HandleEvent_CRender__UpdateDisplay(this_ptr);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
    }

    if (g_EQAppIsInGame == false)
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

/*
    if (g_BazaarBotIsEnabled == true)
    {
        bool bShouldAddItemToList = EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(itemName, itemPrice, traderName);
        if (bShouldAddItemToList == false)
        {
            return 1;
        }
    }
*/

    return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(this_ptr);
    }

    if (g_CheatMemorizeSpellsInstantlyIsEnabled == true)
    {
        EQAPP_Cheat_MemorizeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellMemTicksLeft(this_ptr);
    }

    return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(this_ptr);
    }

    if (g_CheatScribeSpellsInstantlyIsEnabled == true)
    {
        EQAPP_Cheat_ScribeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellScribeTicksLeft(this_ptr);
    }

    return EQAPP_REAL_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft(this_ptr);
}

HRESULT __stdcall EQAPP_DETOURED_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive(LPDIRECT3DDEVICE9 device, D3DPRIMITIVETYPE primitiveType, INT baseIndex, UINT minIndex, UINT numVertices, UINT startIndex, UINT primitiveCount)
{
    if (device == NULL)
    {
        return EQAPP_REAL_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive(device, primitiveType, baseIndex, minIndex, numVertices, startIndex, primitiveCount);
    }

    if (g_CheatWallHackIsEnabled == true)
    {
        LPDIRECT3DVERTEXBUFFER9 streamData;
        UINT offset = 0;
        UINT stride = 0;

        if (device->GetStreamSource(0, &streamData, &offset, &stride) == D3D_OK)
        {
            streamData->Release();
        }

        //std::cout << "IDirect3DDevice9::DrawIndexedPrimitive()" << std::endl;
        //std::cout << "offset: " << offset << std::endl;
        //std::cout << "stride: " << stride << std::endl;
        //std::cout << "baseIndex: " << baseIndex << std::endl;
        //std::cout << "minIndex: " << minIndex << std::endl;
        //std::cout << "numVertices: " << numVertices << std::endl;
        //std::cout << "startIndex: " << startIndex << std::endl;
        //std::cout << "primitiveCount: " << primitiveCount << std::endl;
        //std::cout << "--------------------------------------------------" << std::endl;

        // stride 24 = World + Static Actors
        // stride 32 = Players/NPCs + Dynamic Actors

        if (stride == 24)
        {
            device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

            device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCCOLOR);
            device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
        }

        HRESULT result = EQAPP_REAL_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive(device, primitiveType, baseIndex, minIndex, numVertices, startIndex, primitiveCount);

        if (stride == 24)
        {
            device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
            device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
        }

        return result;
    }

    return EQAPP_REAL_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive(device, primitiveType, baseIndex, minIndex, numVertices, startIndex, primitiveCount);
}

/*

HMODULE WINAPI EQAPP_DETOURED_FUNCTION_GetModuleHandleA(LPCSTR lpModuleName)
{
    //std::stringstream ss;
    //ss << "GetModuleHandleA() lpModuleName: " << lpModuleName << std::endl;
    //ss << "--------------------------------------------------" << std::endl;

    //EQAPP_Log(ss.str().c_str());

    return EQAPP_REAL_FUNCTION_GetModuleHandleA(lpModuleName); 
}

HINSTANCE WINAPI EQAPP_DETOURED_FUNCTION_ShellExecuteA
(
    HWND     hwnd,
    LPCSTR   lpOperation,
    LPCSTR   lpFile,
    LPCSTR   lpParameters,
    LPCSTR   lpDirectory,
    INT      nShowCmd
)
{
    std::stringstream ss;
    ss << "ShellExecuteA()" << std::endl;
    ss << "lpOperation: " << lpOperation << std::endl;
    ss << "lpFile: " << lpFile << std::endl;
    ss << "lpParameters: " << lpParameters << std::endl;
    ss << "lpDirectory: " << lpDirectory << std::endl;
    ss << "nShowCmd: " << nShowCmd << std::endl;
    ss << "--------------------------------------------------" << std::endl;

    EQAPP_Log(ss.str().c_str());

    return EQAPP_REAL_FUNCTION_ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd);
}

*/
