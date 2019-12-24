#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#include "eq_cxwnd.h"
#include "eq_constants.h"

uint32_t EQ_ADDRESS_WindowHWND = 0x0; // HWND hWnd    in IDA press G, jump to address: hWnd

uint32_t EQ_ADDRESS_AutoAttack    = 0x0; // uint8_t    /attack
uint32_t EQ_ADDRESS_AutoFire      = 0x0; // uint8_t
uint32_t EQ_ADDRESS_AutoRun       = 0x0; // uint32_t
uint32_t EQ_ADDRESS_MouseLook     = 0x0; // uint8_t    holding down right-click to look around
uint32_t EQ_ADDRESS_NetStatus     = 0x0; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_LeftMouseHeldTime = 0x0;

uint32_t EQ_ADDRESS_EQZoneInfo = 0x0; // struct

uint32_t EQ_ADDRESS_FUNCTION_FlushDxKeyboard = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_FlushDxMouse = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_ProcessMouseEvent = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_WindowProc = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CollisionCallbackForActors = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CastRay = 0x0; // called by CastRay2 function
uint32_t EQ_ADDRESS_FUNCTION_CastRay2 = 0x0; // CCollisionInfoLineSegmentVisibility::`vftable'
uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus = 0x0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd = 0x0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
uint32_t EQ_ADDRESS_FUNCTION_DoSpellEffect= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_PlaySoundAtLocation= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_GetTime= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_UpdateLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ = 0x0;

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_ControlledSpawn    = 0x0;
uint32_t EQ_ADDRESS_POINTER_PlayerSpawn        = 0x0; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
uint32_t EQ_ADDRESS_POINTER_TargetSpawn        = 0x0; // pinstTarget    ExecuteCmd() case CLEAR_TARGET

// class StringTable
uint32_t EQ_ADDRESS_POINTER_StringTable = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString = 0x0;

// class CDBStr
uint32_t EQ_ADDRESS_POINTER_CDBStr = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_CDBStr__GetString = 0x0;

// class EQ_Character
uint32_t EQ_ADDRESS_POINTER_EQ_Character = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__StunMe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment = 0x0;

// class CharacterZoneClient
uint32_t EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects = 0x0;

// class EQ_PC
uint32_t EQ_ADDRESS_POINTER_EQ_PC = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney = 0x0;

// manager for class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager = 0x0; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID = 0x0; // "Your inventory is full!"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName = 0x0; // "Incorrect Usage. Type /xtarget for correct usage."

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight = 0x0; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel = 0x0; // (Lvl: %d)
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack = 0x0;

uint32_t EQ_ADDRESS_POINTER_EQSwitchManager = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState = 0x0;

// class EQSpell
uint32_t EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects = 0x0;

// class CXStr
uint32_t EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p = 0x0;

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager = 0x0; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows = 0x0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CXWnd
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem = 0x0;

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest = 0x0; // pinstCEverQuest

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone = 0x0; // "Initializing world."    "Zone initialized."
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd = 0x0; // "#%s %s"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat = 0x0; // "You cannot purchase an item from yourself!"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer = 0x0;

uint32_t EQ_ADDRESS_POINTER_CDisplay = 0x0; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 = 0x0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreateActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreateLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight = 0x0;

uint32_t EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRender = 0x0; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions

uint32_t EQ_ADDRESS_FUNCTION_CRender__ResetDevice = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__DrawLineEx = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRenderEx = 0x0; // calculated by offset

uint32_t EQ_ADDRESS_POINTER_CAlertWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem = 0x0;

uint32_t EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CMapViewWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CSpellBookWnd = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft = 0x0;

uint32_t  EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive = 0x0;

void EQ_InitializeAddresses();

void EQ_InitializeAddresses()
{
#ifdef EQ_TEST_SERVER
    // Oct  7 2019 19:45:36

    EQ_SIZE_CXWnd = 0x1E0;
    EQ_SIZE_CSidlScreenWnd = 0x228;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x568;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf2c;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x570;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x310;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x58c;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x554;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x584;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x368;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x4d4;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;

    EQ_ADDRESS_WindowHWND = 0x00F36F5C;

    EQ_ADDRESS_AutoAttack              = 0x00F308A7;
    EQ_ADDRESS_AutoFire                = 0x00F308A8;
    EQ_ADDRESS_AutoRun                 = 0x00E91C10;
    EQ_ADDRESS_MouseLook               = 0x00E91BF2;
    EQ_ADDRESS_NetStatus               = 0x00E91BF5;

    EQ_ADDRESS_EQZoneInfo = 0x00E91DE8;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E8229C;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E821C4;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E82298;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051CEF0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059C8A0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059C8F0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00628600;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00595260;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005FAE40;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x0053A830;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008EDCD0;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x00818A20;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x00800BC0;

    EQ_ADDRESS_POINTER_StringTable = 0x00E81FA8;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B46F0;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DCF724;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00530150;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E81FA0;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D0470;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8390;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DD0B0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DDF20;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D2B80;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D2CA0;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DDDD0;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004B8020;
    EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C1EA0;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00E81FA0;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x00636CB0;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F33A88;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x00650F30;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x00650FE0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x00658E10;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00659840;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x0065B3C0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005932E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00644AC0;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00644DE0;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x0064AA60;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x00987D90;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x00645EB0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00646D80;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064D340;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C8020;
    EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = 0x0065A0F0;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E81CB8;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CC980;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CCE60;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B7660;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016CD4A4;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x00925170;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x009210E0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0F364CC;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x005EA3D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005E4BB0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x005F8910;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E5870;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005D12D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005D3AD0;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005D4A50;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005D5130;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005DEC40;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005DF970;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005D1540;
    EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = 0x005D6020;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E81FA4;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00535530;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00538630;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00534180;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x005385A0;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x005354A0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00538C80;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x00538C50;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CE2E0;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DCF81C;

    EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0DCF800;

    EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00DCF7C0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006DA3D0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006DB1A0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006DAC70;

    EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00DD0050;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DCF8B8;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007F83C0;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007F8520;

#else

    EQ_OFFSET_EQ_Character____ExtendedTargetList    = 0x2838;
    EQ_OFFSET_EQ_Character____GroupInfo             = 0x284C;

    EQ_OFFSET_CMapViewMap__Lines     = 0x258;
    EQ_OFFSET_CMapViewMap__Labels    = 0x25C;

    // Dec 19 2019 15:04:34

    EQ_SIZE_CXWnd = 0x1E0;
    EQ_SIZE_CSidlScreenWnd = 0x228;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x1b4;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf34;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x518;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x570;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x58c;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x394;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x3c8;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x480;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x5ac;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x287c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;
    EQ_OFFSET_CMapViewWnd__CMapViewMap         = 0x360;

    EQ_ADDRESS_WindowHWND = 0x00F6E220;

    EQ_ADDRESS_AutoAttack              = 0x00F6615B;
    EQ_ADDRESS_AutoFire                = 0x00F6615C;
    EQ_ADDRESS_AutoRun                 = 0x00EC74B8;
    EQ_ADDRESS_MouseLook               = 0x00EC749A;
    EQ_ADDRESS_NetStatus               = 0x00EC749D;

    EQ_ADDRESS_LeftMouseHeldTime       = 0x00EC7540;

    EQ_ADDRESS_EQZoneInfo = 0x00EC7690;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00EB7720;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00EB76C8;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00EB771C;

    EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = 0x006BC640;
    EQ_ADDRESS_FUNCTION_FlushDxMouse                  = 0x006BC2C0;
    EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = 0x006BE1B0;
    EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = 0x00612AA0;
    EQ_ADDRESS_FUNCTION_WindowProc                    = 0x006BEC10;
    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0052A2F0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x005B28C0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x005B2910;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x0063F2D0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005AB0D0;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x006119C0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x00547C00;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x00904D80;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x0082F110;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x008172F0;

    EQ_ADDRESS_POINTER_StringTable = 0x00EB9DB8;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008C6490;

    EQ_ADDRESS_POINTER_CDBStr = 0x00E04F1C;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x0053D520;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00EB9DB4;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D3B10;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004DB9B0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004E06D0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004E1540;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D6220;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D6340;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004E13F0;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004BB510;
    EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C54E0;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00EB9DB4;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x0064DD60;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F69340;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x00667F20;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x00667FD0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x0066FE60;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00670890;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x00672410;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005A9160;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x0065BAE0;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x0065BE00;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x00661A60;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0099E7B0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x0065CEC0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x0065DD80;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x00664340;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005DEB50;
    EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = 0x00671140;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00EB7568;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005E34A0;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005E3980;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004BAB50;

    EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p    = 0x00901250;

    EQ_ADDRESS_POINTER_CXWndManager = 0x015FD114;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor     = 0x0093BDE0;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0093BE00;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00937DF0;
    EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem       = 0x00939080;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0F6E250;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x00601010;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005FB7F0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x0060F490;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E8F70;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005E7DF0;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005EA5F0;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005EB570;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005EBC50;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005F5770;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005F65B0;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005E8060;
    EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = 0x005ECB40;

    EQ_ADDRESS_POINTER_CDisplay = 0x0EB9C84;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00542900;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00545A00;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00541550;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00545970;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00542870;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00546050;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x00546020;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x015FDF50;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRenderEx = EQ_ADDRESS_POINTER_CRender + 0x04;

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0E04FC4;

    EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0E05850;

    EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00E05588;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006F09F0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006F17C0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006F1290;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem = 0x006F3E90;

    EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00E05814;

    EQ_ADDRESS_POINTER_CMapViewWnd = 0x00E04FF4;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00E0583C;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x0080EB20;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x0080EC80;

    EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0F818B8;

#endif // EQ_TEST_SERVER
}
