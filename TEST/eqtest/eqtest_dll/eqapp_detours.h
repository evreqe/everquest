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
EQ_MACRO_FUNCTION_DefineDetour(CollisionCallbackForActors);
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);
EQ_MACRO_FUNCTION_DefineDetour(WindowProc);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__FollowPlayerAI);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__UpdateItemSlot);
EQ_MACRO_FUNCTION_DefineDetour(EQPlayer__SetNameSpriteTint);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__DoPercentConvert);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__StartCasting);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__SetGameState);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__LMouseUp);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__RMouseUp);

EQ_MACRO_FUNCTION_DefineDetour(CCamera__SetCameraLocation);

EQ_MACRO_FUNCTION_DefineDetour(CRender__ClearRenderToBlack);
EQ_MACRO_FUNCTION_DefineDetour(CRender__RenderPartialScene);
EQ_MACRO_FUNCTION_DefineDetour(CRender__UpdateDisplay);

EQ_MACRO_FUNCTION_DefineDetour(CBazaarSearchWnd__AddItemToList);

EQ_MACRO_FUNCTION_DefineDetour(CDisplay__CreatePlayerActor);
EQ_MACRO_FUNCTION_DefineDetour(CDisplay__DeleteActor);

char* __cdecl EQAPP_DETOURED_FUNCTION_CrashDetected();
int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForActors(uint32_t cactor);
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);
LRESULT __stdcall EQAPP_DETOURED_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__FollowPlayerAI(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__UpdateItemSlot(void* this_ptr, void* not_used, uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3);
int __fastcall EQAPP_DETOURED_FUNCTION_EQPlayer__SetNameSpriteTint(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__StartCasting(void* this_ptr, void* not_used, EQMessage::CEverQuest__StartCasting_ptr message);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, int x, int y);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__RMouseUp(void* this_ptr, void* not_used, int x, int y);

int __fastcall EQAPP_DETOURED_FUNCTION_CCamera__SetCameraLocation(void* this_ptr, void* not_used, EQ::Location& location, bool canSetLocation);

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__RenderPartialScene(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__UpdateDisplay(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CBazaarSearchWnd__AddItemToList(void* this_ptr, void* not_used, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);

int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, uint32_t spawn, int a2, int a3, int a4, int a5, int a6);
int __fastcall EQAPP_DETOURED_FUNCTION_CDisplay__DeleteActor(void* this_ptr, void* not_used, uint32_t cactor);

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

    EQ_ADDRESS_POINTER_CRender = EQ_GetRender();
    if (EQ_ADDRESS_POINTER_CRender != 0)
    {
        auto EQ_VFTABLE_CRender = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CRender + EQ_OFFSET_CRender_VFTABLE);
        if (EQ_VFTABLE_CRender != 0)
        {
            EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
            EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
            EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__UpdateDisplay);

            if
            (
                EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      != 0
            )
            {
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

    EQ_ADDRESS_POINTER_CRender = EQ_GetRender();
    if (EQ_ADDRESS_POINTER_CRender != 0)
    {
        auto EQ_VFTABLE_CRender = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CRender + EQ_OFFSET_CRender_VFTABLE);
        if (EQ_VFTABLE_CRender != 0)
        {
            EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
            EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
            EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      = EQ_ReadMemory<uint32_t>(EQ_VFTABLE_CRender + EQ_VFTABLE_INDEX_CRender__UpdateDisplay);

            if
            (
                EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene != 0 &&
                EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay      != 0
            )
            {
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
    }

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

    if (EQ_ADDRESS_FUNCTION_WindowProc != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(WindowProc);
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CXWndManager__DrawWindows);
        }
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__FollowPlayerAI);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__UpdateItemSlot);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint != 0)
    {
        EQ_MACRO_FUNCTION_AddDetour(EQPlayer__SetNameSpriteTint);
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

        if (EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CEverQuest__StartCasting);
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
    }

    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CBazaarSearchWnd__AddItemToList);
        }
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__CreatePlayerActor);
        }

        if (EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor != 0)
        {
            EQ_MACRO_FUNCTION_AddDetour(CDisplay__DeleteActor);
        }
    }

    EQAPP_Detours_AddDetoursForCamera();
    EQAPP_Detours_AddDetoursForRender();
}

void EQAPP_Detours_Unload()
{
    if (EQ_ADDRESS_FUNCTION_CrashDetected != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(CrashDetected);
    }

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

    if (EQ_ADDRESS_FUNCTION_WindowProc != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(WindowProc);
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CXWndManager__DrawWindows);
        }
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__FollowPlayerAI);
    }

    if (EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot != 0)
    {
        EQ_MACRO_FUNCTION_RemoveDetour(EQPlayer__UpdateItemSlot);
    }

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

        if (EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CEverQuest__StartCasting);
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
    }

    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CBazaarSearchWnd__AddItemToList);
        }
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__CreatePlayerActor);
        }
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        if (EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor != 0)
        {
            EQ_MACRO_FUNCTION_RemoveDetour(CDisplay__DeleteActor);
        }
    }

    EQAPP_Detours_RemoveDetoursForCamera();
    EQAPP_Detours_RemoveDetoursForRender();
}

void EQAPP_Detours_OnEnterOrLeaveZone()
{
    g_AutoGroupIsInvited = false;

    EQAPP_Waypoint_FollowPath_Off();
    EQAPP_Waypoint_Editor_Reset();

    EQAPP_FindPath_FollowPath_Off();
    g_FindPathFollowPathList.clear();

    EQAPP_FreeCamera_Off();
}

void EQAPP_Detours_OnEnterZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

    EQAPP_ActorCollision_Load();
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

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CrashDetected();
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CrashDetected();
    }

    char* result = EQAPP_REAL_FUNCTION_CrashDetected();

    EQAPP_Log(result);

    return result;
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

    if (g_HUDIsEnabled == true)
    {
        EQAPP_HUD_Execute();
    }

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawNetStatus");
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawOverUI");
    }

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

    if (g_WaypointIsEnabled == true && g_WaypointFollowPathIsEnabled == true)
    {
        bool result = EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(commandID, isActive, zero);
        if (result == true)
        {
            return 1;
        }
    }

    if (g_WaypointIsEnabled == true && g_WaypointEditorIsEnabled == true)
    {
        bool result = EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(commandID, isActive, zero);
        if (result == true)
        {
            return 1;
        }
    }

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
}

LRESULT __stdcall EQAPP_DETOURED_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_EQAppShouldUnload == 1)
    {
        return EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);
    }

    LRESULT result = EQAPP_REAL_FUNCTION_WindowProc(hwnd, uMsg, wParam, lParam);

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

    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Execute();
    }

    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Execute();
        EQAPP_SpawnCastSpell_DrawText();
    }

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawWindows");
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnDrawUnderUI");
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
}

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

    if (g_FollowAIIsEnabled == true)
    {
        EQAPP_FollowAI_Execute();
        return 1;
    }

    return EQAPP_REAL_FUNCTION_EQPlayer__FollowPlayerAI(this_ptr);
}

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

    std::string str;
    str.reserve(strlen(text));

    str = text;
    
    EQAPP_InterpretCommand_ConvertText(str);
    
    strcpy_s(text, str.length() + 1, str.c_str());

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

    if (chatText == "LOADING, PLEASE WAIT...")
    {
        EQAPP_Detours_OnLeaveZone();
    }

    std::stringstream enterZoneText;
    enterZoneText << "You have entered " << EQ_GetZoneLongName() << ".";

    if (chatText == enterZoneText.str())
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

    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_HandleEvent_CEverQuest__dsp_chat(chatText, textColor);
    }

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

    EQAPP_InitializeAddresses();

    bool result = EQAPP_InitializeAddressPointers();
    if (result == false)
    {
        MessageBoxA(NULL, "Failed to initialize address pointers!", "Error", MB_ICONERROR);
    }

    EQAPP_Detours_AddDetoursForCamera();
    EQAPP_Detours_AddDetoursForRender();

    return EQAPP_REAL_FUNCTION_CEverQuest__SetGameState(this_ptr, gameState);
}

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__LMouseUp(void* this_ptr, void* not_used, int x, int y)
{
    if (g_EQAppShouldUnload == 1)
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

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used)
{
    if (g_EQAppShouldUnload == 1)
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

    // kill switch
    if (GetAsyncKeyState(g_EQAppKillSwitchKey))
    {
        EQAPP_Unload();
        EQAPP_Console_Print();
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
    }

    if (g_EQAppIsLoaded == 0)
    {
        EQAPP_Load();

        g_EQAppIsInGame = true;
    }

    if (g_EQAppIsInGame == false)
    {
        return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
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
        if (g_BazaarBotIsEnabled == true)
        {
            EQAPP_BoxChat_DisconnectEx();
        }
        else
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
    }

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
    }

    if (g_SpeedIsEnabled == true)
    {
        EQAPP_Speed_Execute();
    }

    if (g_BazaarBotIsEnabled == true)
    {
        EQAPP_BazaarBot_Execute();
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

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
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

    if (g_InterpretCommandIsEnabled == true)
    {
        EQAPP_InterpretCommand_Execute();
    }

    EQAPP_Console_Print();

    EQAPP_FPS_Execute();

    // reduce CPU and GPU usage to almost 0%
    if (g_NoDrawIsEnabled == true)
    {
        bool result = EQAPP_NoDraw_HandleEvent_CRender__UpdateDisplay(this_ptr);
        if (result == true)
        {
            return 1;
        }
    }

    int result = EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);

    if (g_NameColorIsEnabled == true)
    {
        EQAPP_NameColor_Execute();
    }

    return result;
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

    // TODO: spawn alert

    return EQAPP_REAL_FUNCTION_CDisplay__CreatePlayerActor(this_ptr, spawn, a2, a3, a4, a5, a6);
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

    // TODO: spawn alert

    return EQAPP_REAL_FUNCTION_CDisplay__DeleteActor(this_ptr, cactor);
}
