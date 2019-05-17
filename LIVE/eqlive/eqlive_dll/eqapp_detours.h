#pragma once

#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_followai.h"
#include "eqapp_freecamera.h"
#include "eqapp_hud.h"
#include "eqapp_interpretcommand.h"
#include "eqapp_sleep.h"
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

EQ_MACRO_FUNCTION_DefineDetour(CollisionCallbackForActors);
EQ_MACRO_FUNCTION_DefineDetour(DrawNetStatus);
EQ_MACRO_FUNCTION_DefineDetour(ExecuteCmd);

EQ_MACRO_FUNCTION_DefineDetour(CXWndManager__DrawWindows);

EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__DoPercentConvert);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__InterpretCmd);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__dsp_chat);
EQ_MACRO_FUNCTION_DefineDetour(CEverQuest__SetGameState);

EQ_MACRO_FUNCTION_DefineDetour(CCamera__SetCameraLocation);

EQ_MACRO_FUNCTION_DefineDetour(CRender__ResetDevice);
EQ_MACRO_FUNCTION_DefineDetour(CRender__ClearRenderToBlack);
EQ_MACRO_FUNCTION_DefineDetour(CRender__RenderPartialScene);
EQ_MACRO_FUNCTION_DefineDetour(CRender__UpdateDisplay);

int __cdecl EQAPP_DETOURED_FUNCTION_CollisionCallbackForActors(uint32_t cactor);
int __cdecl EQAPP_DETOURED_FUNCTION_DrawNetStatus(int x, int y, int unknown);
int __cdecl EQAPP_DETOURED_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero);

int __fastcall EQAPP_DETOURED_FUNCTION_CXWndManager__DrawWindows(void* this_ptr, void* not_used);

int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__DoPercentConvert(void* this_ptr, void* not_used, char* text, bool isOutgoing);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, class EQPlayer* player, const char* text);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
int __fastcall EQAPP_DETOURED_FUNCTION_CEverQuest__SetGameState(void* this_ptr, void* not_used, int gameState);

int __fastcall EQAPP_DETOURED_FUNCTION_CCamera__SetCameraLocation(void* this_ptr, void* not_used, EQ::Location& location, bool canSetLocation);

int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ResetDevice(void* this_ptr, void* not_used, bool unknown);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__ClearRenderToBlack(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__RenderPartialScene(void* this_ptr, void* not_used);
int __fastcall EQAPP_DETOURED_FUNCTION_CRender__UpdateDisplay(void* this_ptr, void* not_used);

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
    }

    EQAPP_Detours_AddDetoursForCamera();
    EQAPP_Detours_AddDetoursForRender();
}

void EQAPP_Detours_Unload()
{
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

    EQAPP_FreeCamera_Off();
}

void EQAPP_Detours_OnEnterZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

    EQAPP_ActorCollision_Load();

    EQAPP_ChatEvent_Load();

    g_EQAppIsInGame = true;
}

void EQAPP_Detours_OnLeaveZone()
{
    EQAPP_Detours_OnEnterOrLeaveZone();

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

    if (g_WindowTitleIsEnabled == true)
    {
        if (EQAPP_Timer_HasTimeElapsed(g_WindowTitleTimer, g_WindowTitleTimerInterval) == true)
        {
            EQAPP_WindowTitle_Execute();
        }
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

    if (g_SleepIsEnabled == true)
    {
        EQAPP_Sleep_Execute();
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

    if (g_ChangeHeightIsEnabled == true)
    {
        EQAPP_ChangeHeight_Execute();
    }

    if (EQ_IsWindowInBackground() == false)
    {
        if (g_HUDIsEnabled == true)
        {
            EQAPP_HUD_Execute();
        }
    }

    EQAPP_Detours_AddDetoursForCamera();
    EQAPP_Detours_AddDetoursForRender();

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

    if (commandID == EQ_EXECUTECMD_DUCK)
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

    return EQAPP_REAL_FUNCTION_ExecuteCmd(commandID, isActive, unknown, zero);
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
    }

    return EQAPP_REAL_FUNCTION_CXWndManager__DrawWindows(this_ptr);
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
            EQAPP_Detours_OnEnterZone();
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

    EQAPP_Detours_RemoveDetoursForCamera();
    EQAPP_Detours_RemoveDetoursForRender();

    EQAPP_InitializeAddresses();
    EQAPP_InitializeAddressPointers();

    if (gameState == EQ_GAME_STATE_CHARACTER_SELECT || gameState == EQ_GAME_STATE_IN_GAME)
    {
        EQAPP_SetWindowTitle("EverQuest*");

        EQ_StopFollow();

        g_FollowAISpawn = NULL;
    }

    return EQAPP_REAL_FUNCTION_CEverQuest__SetGameState(this_ptr, gameState);
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

    // never blind
    return 0;

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

    return EQAPP_REAL_FUNCTION_CRender__UpdateDisplay(this_ptr);
}
