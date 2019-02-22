#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_esp.h"
#include "eqapp_followai.h"
#include "eqapp_freecamera.h"
#include "eqapp_hud.h"
#include "eqapp_interpretcommand.h"
#include "eqapp_lua.h"
#include "eqapp_namecolor.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_windowtitle.h"

#include "eqapp_gui.h"

bool g_DetoursIsCameraDetoured = false;
bool g_DetoursIsRenderDetoured = false;

void EQAPP_Detours_AddDetoursForCamera();
void EQAPP_Detours_RemoveDetoursForCamera();
void EQAPP_Detours_AddDetoursForRender();
void EQAPP_Detours_RemoveDetoursForRender();
void EQAPP_Detours_Load();
void EQAPP_Detours_Unload();
void EQAPP_Detours_OnEnterOrLeaveZone();
void EQAPP_Detours_OnEnterZone();
void EQAPP_Detours_OnLeaveZone();

EQ_MACRO_FUNCTION_DefineDetour(CrashDetected);
#ifdef EQ_FEATURE_CollisionCallbackForActors
EQ_MACRO_FUNCTION_DefineDetour(CollisionCallbackForActors);
#endif // EQ_FEATURE_CollisionCallbackForActors
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);
#ifdef EQ_FEATURE_GUI
EQ_MACRO_FUNCTION_DefineDetour(WindowProc);
EQ_MACRO_FUNCTION_DefineDetour(ProcessMouseEvent);
EQ_MACRO_FUNCTION_DefineDetour(ProcessKeyboardEvent);
#endif // EQ_FEATURE_GUI

EQ_MACRO_FUNCTION_DefineDetour(CXWnd__DrawTooltip);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawCursor);
EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI
#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__UpdateItemSlot);
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__SetNameSpriteTint);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__DoPercentConvert);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
#ifdef EQ_FEATURE_CEverQuest__StartCasting
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__StartCasting);
#endif // EQ_FEATURE_CEverQuest__StartCasting
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__SetGameState);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__LMouseUp);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__RMouseUp);
#ifdef EQ_FEATURE_GUI
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__HandleMouseWheel);
#endif // EQ_FEATURE_GUI

EQ_MACRO_FUNCTION_DefineDetour(CCamera__SetCameraLocation);

EQ_MACRO_FUNCTION_DefineDetour(CRender__ResetDevice);
EQ_MACRO_FUNCTION_DefineDetour(CRender__ClearRenderToBlack);
EQ_MACRO_FUNCTION_DefineDetour(CRender__RenderPartialScene);
EQ_MACRO_FUNCTION_DefineDetour(CRender__UpdateDisplay);

#ifdef EQ_FEATURE_BAZAAR
EQ_MACRO_FUNCTION_DefineDetour(CBazaarSearchWnd__AddItemToList);
#endif // EQ_FEATURE_BAZAAR

#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreateActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreatePlayerActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__DeleteActor);
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected();
#ifdef EQ_FEATURE_CollisionCallbackForActors
int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForActors(uint32_t cactor);
#endif // EQ_FEATURE_CollisionCallbackForActors
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);
#ifdef EQ_FEATURE_GUI
LRESULT __stdcall EQAPP_DETOURED_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMouseEvent();
int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyboardEvent();
#endif // EQ_FEATURE_GUI

int __fastcall EQAPP_DETOURED_FUNCTION_CXWnd__DrawTooltip(void* this_ptr, void* not_used, class EQClass::CXWnd* cxwnd);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawCursor(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI
#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__UpdateItemSlot(void* this_ptr, void* not_used, uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3);
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__SetNameSpriteTint(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQMessage::CEverQuest__StartCasting_ptr message);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, int x, int y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__RMouseUp(void* this_ptr, void* not_used, int x, int y);
#ifdef EQ_FEATURE_GUI
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__HandleMouseWheel(void* this_ptr, void* not_used, signed int delta);
#endif // EQ_FEATURE_GUI

int __fastcall EQAPP_DETOURED_FUNCTION_CCamera__SetCameraLocation(void* this_ptr, void* not_used, EQ::Location& location, bool canSetLocation);

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ResetDevice(void* this_ptr, void* not_used, bool unknown);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__RenderPartialScene(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__UpdateDisplay(void* this_ptr, void* not_used);

#ifdef EQ_FEATURE_BAZAAR
int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);
#endif // EQ_FEATURE_BAZAAR

#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreateActor(void* this_ptr, void* not_used, char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, uint32_t spawn, int a2, int a3, int a4, int a5, int a6);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, uint32_t cactor);
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS

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

                g_DetoursIsCameraDetoured = true;
                return;
            }
        }
    }

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

                g_DetoursIsCameraDetoured = false;
                return;
            }
        }
    }

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

                g_DetoursIsRenderDetoured = true;
                return;
            }
        }
    }

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

                g_DetoursIsRenderDetoured = false;
                return;
            }
        }
    }

    g_DetoursIsRenderDetoured = true;
}

void EQAPP_Detours_Load()
{
    if (EQ_ADDRESS_FUNCTION_CrashDetected != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(CrashDetected);

        EQAPP_Log("AddDetour: CrashDetected");
    }

#ifdef EQ_FEATURE_CollisionCallbackForActors
    if (EQ_ADDRESS_FUNCTION_CollisionCallbackForActors != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(CollisionCallbackForActors);

        EQAPP_Log("AddDetour: CollisionCallbackForActors");
    }
#endif // EQ_FEATURE_CollisionCallbackForActors

    if (EQ_ADDRESS_FUNCTION_DrawNetStatus != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(DrawNetStatus);

        EQAPP_Log("AddDetour: DrawNetStatus");
    }

    if (EQ_ADDRESS_FUNCTION_ExecuteCmd != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(ExecuteCmd);

        EQAPP_Log("AddDetour: ExecuteCmd");
    }

#ifdef EQ_FEATURE_GUI
    if (EQ_ADDRESS_FUNCTION_WindowProc != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(WindowProc);

        EQAPP_Log("AddDetour: WindowProc");
    }

    if (EQ_ADDRESS_FUNCTION_ProcessMouseEvent != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(ProcessMouseEvent);

        EQAPP_Log("AddDetour: ProcessMouseEvent");
    }

    if (EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(ProcessKeyboardEvent);

        EQAPP_Log("AddDetour: ProcessKeyboardEvent");
    }
#endif // EQ_FEATURE_GUI

    if (EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltip != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(CXWnd__DrawTooltip);

        EQAPP_Log("AddDetour: CXWnd__DrawTooltip");
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawCursor);

            EQAPP_Log("AddDetour: CXWndManager__DrawCursor");
        }

        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);

            EQAPP_Log("AddDetour: CXWndManager__DrawWindows");
        }
    }

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
    if (EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);

        EQAPP_Log("AddDetour: EQPlayer__FollowPlayerAI");
    }
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
    if (EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__UpdateItemSlot);

        EQAPP_Log("AddDetour: EQPlayer__UpdateItemSlot");
    }
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

    if (EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__SetNameSpriteTint);

        EQAPP_Log("AddDetour: EQPlayer__SetNameSpriteTint");
    }

    if (EQ_ADDRESS_POINTER_CEverQuest != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__DoPercentConvert);

            EQAPP_Log("AddDetour: CEverQuest__DoPercentConvert");
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__InterpretCmd);

            EQAPP_Log("AddDetour: CEverQuest__InterpretCmd");
        }

#ifdef EQ_FEATURE_CEverQuest__StartCasting
        if (EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__StartCasting);

            EQAPP_Log("AddDetour: CEverQuest__StartCasting");
        }
#endif // EQ_FEATURE_CEverQuest__StartCasting

        if (EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__dsp_chat);

            EQAPP_Log("AddDetour: CEverQuest__dsp_chat");
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__SetGameState);

            EQAPP_Log("AddDetour: CEverQuest__SetGameState");
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__LMouseUp);

            EQAPP_Log("AddDetour: CEverQuest__LMouseUp");
        }

        if (EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__RMouseUp);

            EQAPP_Log("AddDetour: CEverQuest__RMouseUp");
        }

#ifdef EQ_FEATURE_GUI
        if (EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__HandleMouseWheel);

            EQAPP_Log("AddDetour: CEverQuest__HandleMouseWheel");
        }
#endif // EQ_FEATURE_GUI
    }

#ifdef EQ_FEATURE_BAZAAR
    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CBazaarSearchWnd__AddItemToList);

            EQAPP_Log("AddDetour: CBazaarSearchWnd__AddItemToList");
        }
    }
#endif // EQ_FEATURE_BAZAAR

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
        if (EQ_ADDRESS_FUNCTION_CDisplay__CreateActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreateActor);

            EQAPP_Log("AddDetour: CDisplay__CreateActor");
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreatePlayerActor);

            EQAPP_Log("AddDetour: CDisplay__CreatePlayerActor");
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__DeleteActor);

            EQAPP_Log("AddDetour: CDisplay__DeleteActor");
        }
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS
    }

    EQAPP_Detours_AddDetoursForCamera();

    EQAPP_Log("AddDetoursForCamera()");

    EQAPP_Detours_AddDetoursForRender();

    EQAPP_Log("AddDetoursForRender()");
}

void EQAPP_Detours_Unload()
{
    if (EQ_ADDRESS_FUNCTION_CrashDetected != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CrashDetected);
    }

#ifdef EQ_FEATURE_CollisionCallbackForActors
    if (EQ_ADDRESS_FUNCTION_CollisionCallbackForActors != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CollisionCallbackForActors);
    }
#endif // EQ_FEATURE_CollisionCallbackForActors

    if (EQ_ADDRESS_FUNCTION_DrawNetStatus != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(DrawNetStatus);
    }

    if (EQ_ADDRESS_FUNCTION_ExecuteCmd != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(ExecuteCmd);
    }

#ifdef EQ_FEATURE_GUI
    if (EQ_ADDRESS_FUNCTION_WindowProc != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(WindowProc);
    }

    if (EQ_ADDRESS_FUNCTION_ProcessMouseEvent != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(ProcessMouseEvent);

        EQAPP_Log("RemoveDetour: ProcessMouseEvent");
    }

    if (EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(ProcessKeyboardEvent);

        EQAPP_Log("RemoveDetour: ProcessKeyboardEvent");
    }
#endif // EQ_FEATURE_GUI

    if (EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltip != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CXWnd__DrawTooltip);

        EQAPP_Log("RemoveDetour: CXWnd__DrawTooltip");
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawCursor);
        }

        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);
        }
    }

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
    if (EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);
    }
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
    if (EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__UpdateItemSlot);
    }
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

    if (EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__SetNameSpriteTint);
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

#ifdef EQ_FEATURE_CEverQuest__StartCasting
        if (EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__StartCasting);
        }
#endif // EQ_FEATURE_CEverQuest__StartCasting

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

#ifdef EQ_FEATURE_GUI
        if (EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__HandleMouseWheel);
        }
#endif // EQ_FEATURE_GUI
    }

#ifdef EQ_FEATURE_BAZAAR
    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CBazaarSearchWnd__AddItemToList);
        }
    }
#endif // EQ_FEATURE_BAZAAR

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
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
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS
    }

    EQAPP_Detours_RemoveDetoursForCamera();
    EQAPP_Detours_RemoveDetoursForRender();
}

void EQAPP_Detours_OnEnterOrLeaveZone()
{
    EQ_StopFollow();
    g_FollowAISpawn = NULL;
    EQ_SetAutoRun(false);

    g_AutoGroupIsInvited = false;

    g_AutoLoginIsEnabled = false;
    g_AutoLoginCharacterIndex = 0;

    EQAPP_Waypoint_FollowPath_Off();
    EQAPP_WaypointEditor_Reset();

    EQAPP_FindPath_FollowPath_Off();
    g_FindPathFollowPathList.clear();

    EQAPP_FreeCamera_Off();
}

void EQAPP_Detours_OnEnterZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

#ifdef EQ_FEATURE_CollisionCallbackForActors
    EQAPP_ActorCollision_Load();
#endif // EQ_FEATURE_CollisionCallbackForActors
    EQAPP_WaypointList_Load();
    EQAPP_NamedSpawns_Load();

    g_EQAppIsInGame = true;
}

void EQAPP_Detours_OnLeaveZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

    g_EQAppIsInGame = false;
}

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected()
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CrashDetected();
    }

    EQAPP_Log("CrashDetected() called by EverQuest");

    return EQAPP_REAL_FUNCTION_CrashDetected();
}

#ifdef EQ_FEATURE_CollisionCallbackForActors

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

#endif // EQ_FEATURE_CollisionCallbackForActors

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

#ifdef EQ_FEATURE_BAZAAR
    if (g_BazaarBotIsEnabled == false)
    {
#endif // EQ_FEATURE_BAZAAR
        // kill switch
        if (GetAsyncKeyState(g_EQAppKillSwitchKey))
        {
            EQAPP_Unload();
            EQAPP_Console_Print();

            return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
        }
#ifdef EQ_FEATURE_BAZAAR
    }
#endif // EQ_FEATURE_BAZAAR

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();

        g_EQAppIsInGame = true;
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_DrawNetStatus(x, y, unknown);
    }

    if (g_WindowTitleIsEnabled == true)
    {
        if (EQAPP_Timer_HasTimeElapsed(g_WindowTitleTimer, g_WindowTitleTimerInterval) == true)
        {
            EQAPP_WindowTitle_Execute();
        }
    }

    if (g_BoxChatIsEnabled == true)
    {
#ifdef EQ_FEATURE_BAZAAR
        if (g_BazaarBotIsEnabled == true)
        {
            EQAPP_BoxChat_DisconnectEx();
        }
        else
        {
#endif // EQ_FEATURE_BAZAAR
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
#ifdef EQ_FEATURE_BAZAAR
        }
#endif // EQ_FEATURE_BAZAAR
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
    }

    if (g_SpeedIsEnabled == true)
    {
        EQAPP_Speed_Execute();
    }

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Execute();
    }

#ifdef EQ_FEATURE_BAZAAR
    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_Execute();
    }
#endif // EQ_FEATURE_BAZAAR

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

    if (g_FindPathIsEnabled == true && g_FindPathFollowPathIsEnabled == true)
    {
        EQAPP_FindPath_FollowPathList(g_FindPathFollowPathList);
    }

    if (g_WaypointIsEnabled == true && g_WaypointFollowPathIsEnabled == true)
    {
        EQAPP_Waypoint_FollowPathList(g_WaypointFollowPathIndexList);
    }

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawNetStatus");
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawOverUI");
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnFrame");

        if (EQAPP_Timer_HasTimeElapsed(g_LuaOneSecondTimer, g_LuaOneSecondTimerInterval) == true)
        {
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnOneSecond");
        }

        if (EQAPP_Timer_HasTimeElapsed(g_LuaThreeSecondsTimer, g_LuaThreeSecondsTimerInterval) == true)
        {
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnThreeSeconds");
        }

        if (EQAPP_Timer_HasTimeElapsed(g_LuaSixSecondsTimer, g_LuaSixSecondsTimerInterval) == true)
        {
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnSixSeconds");
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnTick");
        }

        if (EQAPP_Timer_HasTimeElapsed(g_LuaOneMinuteTimer, g_LuaOneMinuteTimerInterval) == true)
        {
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnOneMinute");
        }

        if (EQAPP_Timer_HasTimeElapsed(g_LuaOneHourTimer, g_LuaOneHourTimerInterval) == true)
        {
            EQAPP_Lua_EventScriptList_ExecuteFunction("OnOneHour");
        }
    }

    if (EQ_IsWindowInBackground() == false)
    {
        if (g_HUDIsEnabled == true)
        {
            EQAPP_HUD_Execute();
        }
    }

    EQAPP_Console_Print();

    EQAPP_FPS_Execute();

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

    if (commandID == EQ_EXECUTECMD_DUCK)
    {
        g_EQAppIsInGame = true;
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
    }

    ////std::cout << "ExecuteCmd(): " << commandID << " (Active: " << isActive << ") " << zero << std::endl;

    if (g_LuaIsEnabled == true)
    {
        for (auto& script : g_LuaEventScriptList)
        {
            sol::protected_function luaFunction = script->LuaState["OnExecuteCommand"];
            if (luaFunction.valid() == true)
            {
                sol::protected_function_result result = luaFunction(commandID, isActive);
                if (result.valid() == true)
                {
                    int resultValue = result;
                    if (resultValue == 1)
                    {
                        return 1;
                    }
                }
                else
                {
                    std::cout << "Lua file name: " << script->FileName << std::endl;

                    sol::error error = result;

                    std::cout << "Lua error: " << error.what() << std::endl;
                }
            }
        }
    }

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

    if (g_FindPathIsEnabled == true && g_FindPathFollowPathIsEnabled)
    {
        bool result = EQAPP_FindPath_FollowPath_HandleEvent_ExecuteCmd(commandID, isActive, zero);
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

#ifdef EQ_FEATURE_GUI

LRESULT __stdcall EQAPP_DETOURED_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);
    }

    if (EQ_IsInGame() == false)
    {
        EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);
    }

    if (g_EQAppIsInGame == false)
    {
        EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);
    }

    if (g_GUIIsEnabled == true)
    {
        signed int result = EQAPP_GUI_HandleEvent_WindowProc(hwnd, uMsg, wParam, lParam);
        if (result == 1)
        {
            return true;
        }
        else if (result == -1)
        {
            return DefWindowProcA(hwnd, uMsg, wParam, lParam);
        }
    }

    return EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);
}

int __cdecl EQAPP_DETOURED_FUNCTION_ProcessMouseEvent()
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
    }

    if (g_GUIIsEnabled == true)
    {
        bool result = EQAPP_GUI_HandleEvent_ProcessMouseEvent();
        if (result == true)
        {
            return 0;
        }
    }

    return EQAPP_REAL_FUNCTION_ProcessMouseEvent();
}

int __cdecl EQAPP_DETOURED_FUNCTION_ProcessKeyboardEvent()
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_ProcessKeyboardEvent();
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_ProcessKeyboardEvent();
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_ProcessKeyboardEvent();
    }

    if (g_GUIIsEnabled == true)
    {
        bool result =  EQAPP_GUI_HandleEvent_ProcessKeyboardEvent();
        if (result == true)
        {
            return 0;
        }
    }

    return EQAPP_REAL_FUNCTION_ProcessKeyboardEvent();
}

#endif // EQ_FEATURE_GUI

int __fastcall EQAPP_DETOURED_FUNCTION_CXWnd__DrawTooltip(void* this_ptr, void* not_used, class EQClass::CXWnd* cxwnd)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWnd__DrawTooltip(this_ptr, cxwnd);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CXWnd__DrawTooltip(this_ptr, cxwnd);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CXWnd__DrawTooltip(this_ptr, cxwnd);
    }

/*
    //std::cout << "tooltip 1!" << std::endl;

    auto window = (EQUIStructs::CXWND*)cxwnd;
    if (window != NULL)
    {
        //std::cout << "tooltip 2!" << std::endl;

        //if (window->dShow == true)
        {
            //std::cout << "tooltip 3!" << std::endl;

            //if (window->MouseOver == true)
            {
                //std::cout << "tooltip 4!" << std::endl;

                //if (window->Tooltip != NULL)
                {
                    //std::cout << "tooltip 5!" << std::endl;

                    //if (window->Tooltip->Length != 0)
                    {
                        //std::cout << "tooltip 6!" << std::endl;

                        auto playerSpawn = EQ_GetPlayerSpawn();
                        if (playerSpawn != NULL)
                        {
                            auto playerLevel = EQ_GetSpawnLevel(playerSpawn);

                            for (unsigned int i = 0; i < EQ_NUM_ALTERNATE_ABILITIES; i++)
                            {
                                auto alternateAbility = EQ_CLASS_POINTER_AltAdvManager->GetAAById(i, playerLevel);
                                if (alternateAbility == NULL)
                                {
                                    continue;
                                }

                                std::string findString = std::string();

                                std::string alternateAbilityName = EQ_CLASS_POINTER_CDBStr->GetString(alternateAbility->nName, 1, NULL);
                                if (alternateAbilityName.size() == 0)
                                {
                                    continue;
                                }

                                std::string alternateAbilityName2 = EQ_CLASS_POINTER_CDBStr->GetString(alternateAbility->nName, 2, NULL);
                                std::string alternateAbilityName3 = EQ_CLASS_POINTER_CDBStr->GetString(alternateAbility->nName, 3, NULL);

                                if (alternateAbilityName2.size() != 0 && alternateAbilityName3.size() != 0)
                                {
                                    std::stringstream ss;
                                    ss << alternateAbilityName2 << "\n" << alternateAbilityName3;

                                    findString = ss.str();
                                }
                                else
                                {
                                    findString = alternateAbilityName;
                                }

                                if (findString.size() == 0)
                                {
                                    continue;
                                }

                                //std::cout << "findString = " << findString << std::endl;

                                if (window->WindowText == NULL)
                                {
                                    continue;
                                }

                                if (strcmp(window->WindowText->Text, findString.c_str()) == 0)
                                {
                                    std::string alternateAbilityDescription = EQ_CLASS_POINTER_CDBStr->GetString(alternateAbility->nName, 4, NULL);
                                    if (alternateAbilityDescription.size() != 0)
                                    {
                                        std::stringstream ss;
                                        ss << alternateAbilityName << "\n" << alternateAbilityDescription;

                                        std::cout << ss.str().c_str() << std::endl;

                                        //EQ_CXStr_SetEx(&window->Tooltip, ss.str().c_str());

                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
*/

    return EQAPP_REAL_FUNCTION_CXWnd__DrawTooltip(this_ptr, cxwnd);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawCursor(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawCursor(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawCursor(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawCursor(this_ptr);
    }

#ifdef EQ_FEATURE_GUI
    if (g_GUIIsEnabled == true)
    {
        bool result =  EQAPP_GUI_HandleEvent_CXWndManager__DrawCursor();
        if (result == true)
        {
            return 0;
        }
    }
#endif // EQ_FEATURE_GUI

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawCursor(this_ptr);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (EQ_GetGameState() == EQ_GAME_STATE_CHARACTER_SELECT)
    {
        if (g_AutoLoginIsEnabled == true)
        {
            EQAPP_AutoLogin_Execute();
        }
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
    }

    if (g_FindPathIsEnabled == true)
    {
        if (EQAPP_FindPath_IsActive() == true)
        {
            EQAPP_FindPath_Draw();
        }
    }

    if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
    {
        EQAPP_WaypointList_Draw();
        EQAPP_WaypointEditor_DrawText();
    }

    if (EQ_IsWindowInBackground() == false)
    {
        if (g_ESPIsEnabled == true)
        {
            EQAPP_ESP_Execute();
        }
    }

#ifdef EQ_FEATURE_CEverQuest__StartCasting
    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
        EQAPP_SpawnCastSpell_DrawText();
    }
#endif // EQ_FEATURE_CEverQuest__StartCasting

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawWindows");
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawUnderUI");
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
    }

/*
    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Execute();
        return 1;
    }
*/

    return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
}

#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__UpdateItemSlot(void* this_ptr, void* not_used, uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__UpdateItemSlot(this_ptr, updateItemSlot, itemDefinition, b1, serverSide, b3);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__UpdateItemSlot(this_ptr, updateItemSlot, itemDefinition, b1, serverSide, b3);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__UpdateItemSlot(this_ptr, updateItemSlot, itemDefinition, b1, serverSide, b3);
    }

    if (g_EQAppDebugTextIsEnabled == true)
    {
        if (strcmp(itemDefinition, "0") != 0)
        {
            if (strcmp(itemDefinition, "IT0") != 0)
            {
                std::cout << "EQPlayer::UpdateItemSlot(): " << (int)updateItemSlot << " = " << itemDefinition << std::endl;
            }
        }
    }

    if (g_LuaIsEnabled == true)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            if ((uint32_t)this_ptr == playerSpawn)
            {
                for (auto& script : g_LuaEventScriptList)
                {
                    sol::protected_function luaFunction = script->LuaState["OnUpdateItemSlot"];
                    if (luaFunction.valid() == true)
                    {
                        sol::protected_function_result result = luaFunction(updateItemSlot, itemDefinition);
                        if (result.valid() == true)
                        {
                            int resultValue = result.get<int>(0);
                            if (resultValue == 1)
                            {
                                std::string resultItemDefinition = result.get<std::string>(1);
                                if (resultItemDefinition.size() != 0)
                                {
                                    return EQAPP_REAL_FUNCTION_EQPlayer__UpdateItemSlot(this_ptr, updateItemSlot, resultItemDefinition.c_str(), b1, serverSide, b3);
                                }
                            }
                        }
                        else
                        {
                            std::cout << "Lua file name: " << script->FileName << std::endl;

                            sol::error error = result;

                            std::cout << "Lua error: " << error.what() << std::endl;
                        }
                    }
                }
            }
        }
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__UpdateItemSlot(this_ptr, updateItemSlot, itemDefinition, b1, serverSide, b3);
}

#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__SetNameSpriteTint(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    int result = EQAPP_REAL_FUNCTION_EQPlayer__SetNameSpriteTint(this_ptr);

    if (g_NameColorIsEnabled == true)
    {
        EQAPP_NameColor_HandleEvent_EQPlayer__SetNameSpriteTint(this_ptr);
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__DoPercentConvert(this_ptr, text, isOutgoing);
    }

    if (text != NULL && strlen(text) > 0)
    {
        std::string str;
        str.reserve(strlen(text));

        str = text;
    
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

    if (g_LuaIsEnabled == true)
    {
        for (auto& script : g_LuaEventScriptList)
        {
            sol::protected_function luaFunction = script->LuaState["OnInterpretCommand"];
            if (luaFunction.valid() == true)
            {
                sol::protected_function_result result = luaFunction(text);
                if (result.valid() == true)
                {
                    int resultValue = result;
                    if (resultValue == 1)
                    {
                        return 1;
                    }
                }
                else
                {
                    std::cout << "Lua file name: " << script->FileName << std::endl;

                    sol::error error = result;

                    std::cout << "Lua error: " << error.what() << std::endl;
                }
            }
        }
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

#ifdef EQ_FEATURE_CEverQuest__StartCasting

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQMessage::CEverQuest__StartCasting_ptr message)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
    }

/*
    auto spawn = EQ_GetSpawnByID(message->SpawnID);
    if (spawn != NULL)
    {
        std::string spawnName = EQ_GetSpawnName(spawn);

        std::string spellName = EQ_GetSpellNameByID(message->SpellID);

        std::cout << "---- CEverQuest::StartCasting() ----" << std::endl;
        std::cout << "Spawn ID: " << message->SpawnID << " (" << spawnName << ")" << std::endl;
        std::cout << "Spell ID: " << message->SpellID << " <" << spellName << ">" << std::endl;
        std::cout << "Spell Cast Time: " << message->SpellCastTime << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }
*/

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(this_ptr, message);
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__StartCasting(this_ptr, message);
}

#endif // EQ_FEATURE_CEverQuest__StartCasting

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1)
{
    if (g_EQAppShouldUnload == 1)
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

    std::stringstream enterZoneText;
    enterZoneText << "You have entered " << EQ_GetZoneLongName() << ".";

    auto zoneID = EQ_GetZoneID();

    std::string zoneName = EQ_StringMap_GetValueByKey(EQ_ZONE_ID_Name_Strings, zoneID);

    std::stringstream enterZoneTextEx;
    enterZoneTextEx << "You have entered " << zoneName << ".";

    if (chatText == enterZoneText.str() || chatText == enterZoneTextEx.str())
    {
        EQAPP_Detours_OnEnterZone();

        if (g_LuaIsEnabled == true)
        {
            for (auto& script : g_LuaEventScriptList)
            {
                sol::protected_function luaFunction = script->LuaState["OnEnterZone"];
                if (luaFunction.valid() == true)
                {
                    auto playerSpawn = EQ_GetPlayerSpawn();
                    if (playerSpawn != NULL)
                    {
                        auto playerSpawnZoneID = EQ_GetSpawnZoneID(playerSpawn);

                        sol::protected_function_result result = luaFunction(playerSpawnZoneID);
                        if (result.valid() == false)
                        {
                            std::cout << "Lua file name: " << script->FileName << std::endl;

                            sol::error error = result;

                            std::cout << "Lua error: " << error.what() << std::endl;
                        }
                    }
                }
            }
        }
    }

#ifdef EQ_FEATURE_BAZAAR
    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }
#endif // EQ_FEATURE_BAZAAR

    if (g_AutoGroupIsEnabled == true)
    {
        EQAPP_AutoGroup_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }

    if (g_FindPathIsEnabled == true && g_FindPathFollowPathIsEnabled == true)
    {
        EQAPP_FindPath_FollowPath_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }

    if (g_LuaIsEnabled == true)
    {
        for (auto& script : g_LuaEventScriptList)
        {
            sol::protected_function luaFunction = script->LuaState["OnChatText"];
            if (luaFunction.valid() == true)
            {
                sol::protected_function_result result = luaFunction(text, textColor);
                if (result.valid() == true)
                {
                    int resultValue = result;
                    if (resultValue == 1)
                    {
                        return 1;
                    }
                }
                else
                {
                    std::cout << "Lua file name: " << script->FileName << std::endl;

                    sol::error error = result;

                    std::cout << "Lua error: " << error.what() << std::endl;
                }
            }
        }
    }

    return result;
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_CEverQuest__SetGameState(this_ptr, gameState);
    }

    if (gameState == EQ_GAME_STATE_IN_GAME)
    {
        g_AutoLoginIsEnabled = false;
        g_AutoLoginCharacterIndex = 0;
    }

    if (gameState == EQ_GAME_STATE_CHARACTER_SELECT || gameState == EQ_GAME_STATE_IN_GAME)
    {
        EQAPP_SetWindowTitle("EverQuest*");

        EQAPP_InitializeAddresses();
        EQAPP_InitializeAddressPointers();

        EQAPP_Detours_AddDetoursForCamera();
        EQAPP_Detours_AddDetoursForRender();

        EQ_StopFollow();
        g_FollowAISpawn = NULL;
        EQ_SetAutoRun(false);
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

#ifdef EQ_FEATURE_GUI

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

    if (g_GUIIsEnabled == true)
    {
        bool result = EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(delta);
        if (result == true)
        {
            return 0;
        }
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__HandleMouseWheel(this_ptr, delta);
}

#endif // EQ_FEATURE_GUI

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

#ifdef EQ_FEATURE_GUI
    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before();
    }
#endif // EQ_FEATURE_GUI

    int result = EQAPP_REAL_FUNCTION_CRender__ResetDevice(this_ptr, unknown);

#ifdef EQ_FEATURE_GUI
    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_HandleEvent_CRender__ResetDevice_After();
    }
#endif // EQ_FEATURE_GUI

    return result;
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

    // never blind
    return 1;

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

    // reduce CPU and GPU usage to almost 0%
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

    // reduce CPU and GPU usage to almost 0%
    if (g_NoDrawIsEnabled == true)
    {
        bool result = EQAPP_NoDraw_HandleEvent_CRender__UpdateDisplay(this_ptr);
        if (result == true)
        {
            return 1;
        }
    }

#ifdef EQ_FEATURE_GUI
    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_HandleEvent_CRender__UpdateDisplay();
    }
#endif // EQ_FEATURE_GUI

    return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
}

#ifdef EQ_FEATURE_BAZAAR

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

    if (g_BazaarBotIsEnabled == true)
    {
        bool bShouldAddItemToList = EQAPP_BazaarBot_HandleEvent_CBazaarSearchWnd__AddItemToList(itemName, itemPrice, traderName);
        if (bShouldAddItemToList == false)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_CBazaarSearchWnd__AddItemToList(this_ptr, itemName, itemPrice, traderName, a4, a5, a6, a7, a8, a9, a10, a11);
}

#endif // EQ_FEATURE_BAZAAR

#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS

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

/*
    if (actorDefinition != NULL && strlen(actorDefinition) > 0)
    {
        std::cout << "CDisplay::CreateActor(): " << actorDefinition << std::endl;
    }
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

    int result = EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);

/*
    if (spawn != NULL)
    {
        std::string spawnNameNumbered = EQ_GetSpawnNameNumbered(spawn);
        if (spawnNameNumbered.size() != 0)
        {
            std::cout << "CreatePlayerActor(): " << spawnNameNumbered << std::endl;
        }
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
                std::cout << "DeleteActor(): " << spawnNameNumbered << std::endl;
            }
        }
    }
*/

    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_HandleEvent_CDisplay__DeleteActor(this_ptr, cactor);
    }

    return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
}

#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS
