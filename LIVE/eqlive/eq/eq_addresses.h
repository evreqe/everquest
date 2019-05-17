#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#include "eq_constants.h"

uint32_t EQ_ADDRESS_WindowHWND = 0x0; // HWND hWnd    in IDA press G, jump to address: hWnd

uint32_t EQ_ADDRESS_AutoAttack    = 0x0; // uint8_t    /attack
uint32_t EQ_ADDRESS_AutoRun       = 0x0; // uint32_t
uint32_t EQ_ADDRESS_MouseLook     = 0x0; // uint8_t    holding down right-click to look around
uint32_t EQ_ADDRESS_NetStatus     = 0x0; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_FUNCTION_CollisionCallbackForActors = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_CastRay = 0x0; // called by CastRay2 function

uint32_t EQ_ADDRESS_FUNCTION_CastRay2 = 0x0; // CCollisionInfoLineSegmentVisibility::`vftable'

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus = 0x0; // "%ldms"    "%0.2f%%"

uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd = 0x0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_PlayerSpawn = 0x0; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"

uint32_t EQ_ADDRESS_POINTER_TargetSpawn = 0x0; // pinstTarget    ExecuteCmd() case CLEAR_TARGET

// manager for class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager = 0x0; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID = 0x0; // "Your inventory is full!"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName = 0x0; // "Incorrect Usage. Type /xtarget for correct usage."

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight = 0x0; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel = 0x0; // (Lvl: %d)

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager = 0x0; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows = 0x0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest = 0x0; // pinstCEverQuest

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone = 0x0; // "Initializing world."    "Zone initialized."
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd = 0x0; // "#%s %s"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat = 0x0; // "You cannot purchase an item from yourself!"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState = 0x0;

uint32_t EQ_ADDRESS_POINTER_CDisplay = 0x0; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 = 0x0; // "%ldms"    "%0.2f%%"

uint32_t EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRender = 0x0; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions

uint32_t EQ_ADDRESS_FUNCTION_CRender__ResetDevice = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay = 0x0; // calculated at runtime

void EQ_InitializeAddresses();

void EQ_InitializeAddresses()
{
    // May 13 2019 11:56:03

    EQ_ADDRESS_WindowHWND = 0x00F328F4;

    EQ_ADDRESS_AutoAttack    = 0x00F2CCFB;
    EQ_ADDRESS_AutoRun       = 0x00E8E068;
    EQ_ADDRESS_MouseLook     = 0x00E8E04A;
    EQ_ADDRESS_NetStatus     = 0x00E8E04D;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D6D0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059BCA0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059BCF0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006279B0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005945C0;

    EQ_ADDRESS_POINTER_PlayerSpawn    = 0x00E805BC;
    EQ_ADDRESS_POINTER_TargetSpawn    = 0x00E80690;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F2FEE8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064FD90;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064FDB0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x006579A0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = 0x00659F30;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016C9938;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091AFC0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103D948;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E9540;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E3D30;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F7890;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E61E0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005D0440;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E806A0;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x005350B0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CA778;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime
}

/*
void EQ_InitializeAddresses()
{
    // Apr 18 2019 17:51:12

    EQ_ADDRESS_WindowHWND = 0x00F318E4;

    EQ_ADDRESS_AutoAttack    = 0x00F2BCEB;
    EQ_ADDRESS_AutoRun       = 0x00E8D058;
    EQ_ADDRESS_MouseLook     = 0x00E8D03A;
    EQ_ADDRESS_NetStatus     = 0x00E8D03D;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D410;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059BB10;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059BB60;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00627100;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00594400;

    EQ_ADDRESS_POINTER_PlayerSpawn    = 0x00E7F5A4;
    EQ_ADDRESS_POINTER_TargetSpawn    = 0x00E7F678;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F2EED8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064F690;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064F6B0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x006572C0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = 0x00659850;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016C8928;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091A620;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103C944;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E8FE0;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E37D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F7330;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E6440;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005CFEE0;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E7F68C;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x00534E20;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016C9768;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime
}
*/