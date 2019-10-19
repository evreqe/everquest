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

uint32_t EQ_ADDRESS_EQZoneInfo = 0x0; // struct

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

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager = 0x0; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows = 0x0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CXWnd
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible = 0x0;

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

uint32_t EQ_ADDRESS_POINTER_CAlertWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x0;

uint32_t EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CSpellBookWnd = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive = 0x0;

void EQ_InitializeAddresses();

void EQ_InitializeAddresses()
{
#ifdef EQ_TEST_SERVER
    // Jul 12 2019 11:24:59

    EQ_SIZE_CXWnd = 0x1E0;
    EQ_SIZE_CSidlScreenWnd = 0x228;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x3b8;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf34;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x250;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x3c8;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x5fc;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x608;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x5f4;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x3d4;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x4f0;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;

    EQ_ADDRESS_WindowHWND = 0x00F41154;

    EQ_ADDRESS_AutoAttack    = 0x00F3B55B;
    EQ_ADDRESS_AutoFire      = 0x00F3B55C;
    EQ_ADDRESS_AutoRun       = 0x00E9C8C8;
    EQ_ADDRESS_MouseLook     = 0x00E9C8AA;
    EQ_ADDRESS_NetStatus     = 0x00E9C8AD;

    EQ_ADDRESS_EQZoneInfo = 0x00E9CAA0;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E8CCA8;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E8CC50;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E8CCA4;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051DB20;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059C280;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059C2D0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006289F0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00594B50;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005FADE0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x00539F90;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008F1D00;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x005B9840;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x008040D0;

    EQ_ADDRESS_POINTER_StringTable = 0x00E8F3C8;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B8180;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DDA3CC;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x0052F8F0;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E8F11C;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D0E70;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8E60;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DDBB0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DEA40;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D35D0;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D36F0;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DE8F0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TotalSpellAffects     = 0x004C2920;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav    = 0x004B8E60;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00E8F11C;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x00637150;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F3E748;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x00651420;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x006514D0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x006592E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00659D10;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x0065B890;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x00592BC0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00644F30;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00645250;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x0064AF10;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0098B890;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x00646330;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00647200;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064D840;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C7E20;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E8C970;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CC8F0;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CCDD0;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B84A0;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016D8198;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x00928D00;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00924CD0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0104B19C;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x005EA3D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005E4BC0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x005F88D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E6400;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005D1260;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005D3A40;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005D49D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005D50B0;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005DEBE0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005DF900;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005D14D0;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E8F3BC;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00534D10;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00537DE0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00533940;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00537D50;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00534C80;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00538400;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x005383D0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016D8FD8;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DDAADC;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DDAAA4;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007FC7E0;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007FC940;
#else
    // Oct 15 2019 12:24:00

    EQ_SIZE_CXWnd = 0x1E8;
    EQ_SIZE_CSidlScreenWnd = 0x230;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x5f1;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf34;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x338;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x3d0;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x3c4;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x434;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x3cc;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x614;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x43c;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;

    EQ_ADDRESS_WindowHWND = 0x00F35FDC;

    EQ_ADDRESS_AutoAttack              = 0x00F2F927;
    EQ_ADDRESS_AutoFire                = 0x00F2F928;
    EQ_ADDRESS_AutoRun                 = 0x00E90C90;
    EQ_ADDRESS_MouseLook               = 0x00E90C72;
    EQ_ADDRESS_NetStatus               = 0x00E90C75;

    EQ_ADDRESS_EQZoneInfo = 0x00E90E68;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E8131C;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E81244;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E81318;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D4B0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059C9C0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059CA10;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00628670;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00595390;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005FADA0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x0053AD80;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008EDD10;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x008188F0;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x00800A40;

    EQ_ADDRESS_POINTER_StringTable = 0x00E81028;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B4830;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DCE7A4;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00530680;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E81020;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D01D0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8100;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DCE20;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DDC90;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D28E0;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D2A00;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DDB40;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004B7D70;
    EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C1BF0;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00E81020;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x006371C0;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F32B08;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x006513F0;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x006514A0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x006592B0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00659CE0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x0065B860;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005933D0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00644F00;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00645220;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x0064AEA0;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x00987110;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x006462F0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x006471C0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064D780;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C8060;
    EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = 0x0065A590;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E80D38;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CC9D0;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CCEB0;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B73B0;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016CC524;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x00924600;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x009205C0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0F3554C;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x005EA340;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005E4B20;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x005F8870;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E56A0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005D1240;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005D3A40;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005D49C0;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005D50A0;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005DEBB0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005DF8E0;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005D14B0;
    EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = 0x005D5F90;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E81024;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00535A80;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00538B80;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x005346D0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00538AF0;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x005359F0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x005391D0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x005391A0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CD360;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DCE89C;

    EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0DCE880;

    EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00DCE840;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006DA2F0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006DB0B0;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006DAB80;

    EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00DCF0D0;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DCE938;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007F8200;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007F8360;
#endif // EQ_TEST_SERVER
}
