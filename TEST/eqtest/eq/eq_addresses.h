#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#include "eq_constants.h"

// the addresses for client version time and date must NOT be 0x0 !!!!

uint32_t EQ_ADDRESS_ClientVersionTime = __ActualVersionTime_x; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_ClientVersionTime __ExpectedVersionTime // "xx:xx:xx"
#define EQ_SIZE_ClientVersionTime 9

uint32_t EQ_ADDRESS_ClientVersionDate = __ActualVersionDate_x; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_ClientVersionDate __ExpectedVersionDate // "xxx xx xxxx"
#define EQ_SIZE_ClientVersionDate 12

uint32_t EQ_ADDRESS_WindowHWND = 0x0; // HWND hWnd    in IDA press G, jump to address: hWnd

#ifdef EQ_FEATURE_GUI
uint32_t EQ_ADDRESS_FUNCTION_WindowProc = 0x0; // can return DefWindowProcA

uint32_t EQ_ADDRESS_FUNCTION_ProcessMouseEvent = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_FlushDxMouse = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_FlushDxKeyboard = 0x0;
#endif // EQ_FEATURE_GUI

uint32_t EQ_ADDRESS_AutoAttack    = 0x0; // uint8_t    // /attack
uint32_t EQ_ADDRESS_AutoFire      = 0x0; // uint8_t    // /autofire
uint32_t EQ_ADDRESS_AutoRun       = 0x0; // uint32_t
uint32_t EQ_ADDRESS_MouseLook     = 0x0; // uint8_t    // holding down right-click to look around
uint32_t EQ_ADDRESS_NetStatus     = 0x0; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_Mouse = 0x0; // EQ::MouseInfo2_ptr

uint32_t EQ_ADDRESS_DirectInputKeyboard      = 0x0;
uint32_t EQ_ADDRESS_DirectInputMouse         = 0x0;
uint32_t EQ_ADDRESS_DirectInputMouseCopy     = 0x0; // EQ::MouseState_ptr
uint32_t EQ_ADDRESS_DirectInputMouseCheck    = 0x0; // DIMOUSESTATE*

uint32_t EQ_ADDRESS_CameraType = 0x0; // uint32_t

uint32_t EQ_ADDRESS_LeftMouseHeldTime = 0x0; // uint32_t
uint32_t EQ_ADDRESS_RightMouseHeldTime = 0x0; // uint32_t

uint32_t EQ_ADDRESS_GroupAggro = 0x0; // struct

uint32_t EQ_ADDRESS_EQZoneInfo = 0x0; // struct

uint32_t EQ_ADDRESS_FUNCTION_CrashDetected = 0x0; // "Crash (char = %s, zone = %s)\n"    "Local Player's World location at time of crash: %f, %f, %f.\n"    "Gamestate at crash = %d\n"    "Crash Details: %s\n"

#ifdef EQ_FEATURE_CollisionCallbackForActors
uint32_t EQ_ADDRESS_FUNCTION_CollisionCallbackForActors = 0x0;
#endif // EQ_FEATURE_CollisionCallbackForActors

uint32_t EQ_ADDRESS_FUNCTION_CastRay = 0x0; // called by CastRay2 function

uint32_t EQ_ADDRESS_FUNCTION_CastRay2 = 0x0; // CCollisionInfoLineSegmentVisibility::`vftable'

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus = 0x0; // "%ldms"    "%0.2f%%"

uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd = 0x0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"

#ifdef EQ_FEATURE_DoSpellEffect
uint32_t EQ_ADDRESS_FUNCTION_DoSpellEffect = 0x0;
#endif // EQ_FEATURE_DoSpellEffect

uint32_t EQ_ADDRESS_POINTER_CDBStr = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_CDBStr__GetString = 0x0;

uint32_t EQ_ADDRESS_POINTER_StringTable = 0x0; // pinstStringTable

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString = 0x0; // "%s (%d)"    "ERROR: String not found."

uint32_t EQ_ADDRESS_POINTER_TargetIndicator = 0x0; // "Initializing target indicator."

uint32_t EQ_ADDRESS_POINTER_PlayerPath = 0x0; // "Initializing player path."

// class EQCharacter
uint32_t EQ_ADDRESS_POINTER_PlayerCharacter = 0x0;
uint32_t EQ_ADDRESS_POINTER_EQ_PC = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney = 0x0;

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_PlayerSpawn = 0x0; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"

uint32_t EQ_ADDRESS_POINTER_TargetSpawn = 0x0; // pinstTarget    ExecuteCmd() case CLEAR_TARGET

// manager for class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager = 0x0; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0; // "Your inventory is full!"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName = 0x0; // "Incorrect Usage. Type /xtarget for correct usage."
uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName = 0x0;

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI = 0x0; // search for xref to autorun
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight = 0x0; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
// this is CDisplay__UpdateItemSlot in Macintosh client
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot = 0x0; // "IT36" "IT159" "IT10758" "IT10742"
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint = 0x0;

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager = 0x0; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows = 0x0; // "DoAllDrawing() failed\n"    GetTickCount()
uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor = 0x0;

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest = 0x0; // pinstCEverQuest

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone = 0x0; // "Initializing world."    "Zone initialized."
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd = 0x0; // "#%s %s"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat = 0x0; // "You cannot purchase an item from yourself!"
#ifdef EQ_FEATURE_CEverQuest__StartCasting
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting = 0x0; // "%s <%s>"
#endif // EQ_FEATURE_CEverQuest__StartCasting
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp = 0x0;
#ifdef EQ_FEATURE_GUI
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel = 0x0;
#endif // EQ_FEATURE_GUI
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState = 0x0;

uint32_t EQ_ADDRESS_POINTER_CDisplay = 0x0; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 = 0x0; // "%ldms"    "%0.2f%%"
#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreateActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor = 0x0;
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS

uint32_t EQ_ADDRESS_FUNCTION_AuraManager__GetSingleton = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_GroundItemManager__Instance = 0x0;

uint32_t EQ_ADDRESS_POINTER_EQSwitchManager = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch = 0x0;
#ifdef EQ_FEATURE_EQSwitch__ChangeState
uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState = 0x0;
#endif // EQ_FEATURE_EQSwitch__ChangeState

uint32_t EQ_ADDRESS_POINTER_SpellManager = 0x0;

uint32_t EQ_ADDRESS_POINTER_AltAdvManager = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_AltAdvManager__GetAAById = 0x0;

uint32_t EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRender = 0x0; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions

uint32_t EQ_ADDRESS_FUNCTION_CRender__ResetDevice = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CXStr__CXStr = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__CXStr1 = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__CXStr3 = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__dCXStr = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__operator_equal = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__operator_equal1 = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal1 = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltip = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltipAtPoint = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__BringToTop = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsActive = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible = 0x0; // "MapSkin" "AtlasSkin"
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__GetWindowTextA = 0x0;

// Trader window
uint32_t EQ_ADDRESS_POINTER_CBazaarWnd = 0x0; // "BazaarWnd"

uint32_t EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x0; // "BazaarConfirmationWnd"

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x0; // "BazaarSearchWnd"

#ifdef EQ_FEATURE_BAZAAR
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg = 0x0; // "You successfully purchased %d %s(s) from %s."    "The item has been sent to your parcels."
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x0;
#endif // EQ_FEATURE_BAZAAR

uint32_t EQ_ADDRESS_POINTER_CCharacterListWnd = 0x0; // "CharacterListWnd"

uint32_t EQ_ADDRESS_FUNCTION_CCharacterListWnd__SelectCharacter = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CCharacterListWnd__EnterWorld = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CCharacterListWnd__Quit = 0x0;

uint32_t EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0; // "TaskSelectWnd"

uint32_t EQ_ADDRESS_POINTER_CLargeDialogWnd = 0x0; // "LargeDialogWnd"

uint32_t EQ_ADDRESS_FUNCTION_CLargeDialogWnd__Open = 0x0;

uint32_t EQ_ADDRESS_POINTER_CConfirmationDialog = 0x0; // "ConfirmationDialogBox"

uint32_t EQ_ADDRESS_POINTER_CPlayerWnd = 0x0; // "PlayerWnd"

uint32_t EQ_ADDRESS_POINTER_CTargetWnd = 0x0; // "TargetWnd"

uint32_t EQ_ADDRESS_POINTER_CPetInfoWindow = 0x0; // "PetInfoWindow"

uint32_t EQ_ADDRESS_POINTER_CBuffWnd_Long = 0x0; // "BuffWindow"
uint32_t EQ_ADDRESS_POINTER_CBuffWnd_Short = 0x0; // "ShortDurationBuffWindow"

uint32_t EQ_ADDRESS_POINTER_CCastSpellWnd = 0x0; // "CastSpellWnd"

uint32_t EQ_ADDRESS_POINTER_CCastingWnd = 0x0; // "CastingWnd"

uint32_t EQ_ADDRESS_POINTER_CMapViewWnd = 0x0; // "MapViewWnd"

uint32_t EQ_ADDRESS_POINTER_CInventoryWnd = 0x0; // "InventoryWnd"

void EQ_InitializeAddresses();

void EQ_InitializeAddresses()
{
    EQ_ADDRESS_ClientVersionTime    = __ActualVersionTime_x;
    EQ_ADDRESS_ClientVersionDate    = __ActualVersionDate_x;

    EQ_ADDRESS_WindowHWND = __HWnd_x;

    // **** //

    EQ_ADDRESS_AutoAttack    = __Attack_x;
    EQ_ADDRESS_AutoFire      = __Autofire_x;
    EQ_ADDRESS_AutoRun       = __pulAutoRun_x;
    EQ_ADDRESS_MouseLook     = __MouseLook_x;
    EQ_ADDRESS_NetStatus     = __NetStatusToggle_x;

    EQ_ADDRESS_Mouse = __Mouse_x;

    EQ_ADDRESS_DirectInputKeyboard      = DI8__Keyboard_x;
    EQ_ADDRESS_DirectInputMouse         = DI8__Mouse_x;
    EQ_ADDRESS_DirectInputMouseCopy     = DI8__Mouse_Copy_x;
    EQ_ADDRESS_DirectInputMouseCheck    = DI8__Mouse_Check_x;

    EQ_ADDRESS_CameraType = CDisplay__cameraType_x;

    EQ_ADDRESS_LeftMouseHeldTime     = __LMouseHeldTime_x;
    EQ_ADDRESS_RightMouseHeldTime    = __RMouseHeldTime_x;

    EQ_ADDRESS_GroupAggro = __GroupAggro_x;

    EQ_ADDRESS_EQZoneInfo = instEQZoneInfo_x;

    EQ_ADDRESS_FUNCTION_CrashDetected                 = CrashDetected_x;
    // **** //
    EQ_ADDRESS_FUNCTION_CastRay                       = __CastRay_x;
    EQ_ADDRESS_FUNCTION_CastRay2                      = __CastRay2_x;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = DrawNetStatus_x;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = __ExecuteCmd_x;
    // **** //

    EQ_ADDRESS_POINTER_CDBStr = pinstCDBStr_x;

    EQ_ADDRESS_FUNCTION_CDBStr__GetString = CDBStr__GetString_x;

    EQ_ADDRESS_POINTER_StringTable = pinstStringTable_x;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = StringTable__getString_x;

    EQ_ADDRESS_POINTER_TargetIndicator = pinstTargetIndicator_x;
    EQ_ADDRESS_POINTER_PlayerPath = pinstPlayerPath_x;

    EQ_ADDRESS_POINTER_PlayerCharacter = pinstCharData_x;
    EQ_ADDRESS_POINTER_EQ_PC = pinstCharData_x;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney = EQ_PC__DestroyHeldItemOrMoney_x;

    EQ_ADDRESS_POINTER_PlayerSpawn = pinstLocalPlayer_x;
    EQ_ADDRESS_POINTER_TargetSpawn = pinstTarget_x;

    EQ_ADDRESS_POINTER_EQPlayerManager = pinstSpawnManager_x;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID                = EQPlayerManager__GetSpawnByID_x;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName              = EQPlayerManager__GetSpawnByName_x;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName    = EQPlayerManager__GetPlayerFromPartialName_x;
    // **** //
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = PlayerZoneClient__ChangeHeight_x;
    // **** //
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = EQPlayer__IsTargetable_x;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = EQPlayer__SetNameSpriteState_x;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = EQPlayer__SetNameSpriteTint_x;

    EQ_ADDRESS_POINTER_CXWndManager = pinstCXWndManager_x;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor    = CXWndManager__DrawCursor_x;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = CXWndManager__DrawWindows_x;

    EQ_ADDRESS_POINTER_CEverQuest = pinstCEverQuest_x;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = CEverQuest__DoPercentConvert_x;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = CEverQuest__EnterZone_x;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = CEverQuest__InterpretCmd_x;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = CEverQuest__dsp_chat_x;
    // **** //
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp            = CEverQuest__LMouseUp_x;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp            = CEverQuest__RMouseUp_x;
    // **** //
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = CEverQuest__SetGameState_x;

    EQ_ADDRESS_POINTER_CDisplay = pinstCDisplay_x;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = CDisplay__WriteTextHD2_x;
    // **** //

    EQ_ADDRESS_FUNCTION_AuraManager__GetSingleton = ClientSOIManager__GetSingleton_x;

    EQ_ADDRESS_FUNCTION_GroundItemManager__Instance = EQGroundItemListManager__Instance_x;

    EQ_ADDRESS_POINTER_EQSwitchManager = pinstSwitchManager_x;

    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = EQSwitch__UseSwitch_x;
    // **** //

    EQ_ADDRESS_POINTER_SpellManager = pinstSpellManager_x;

    EQ_ADDRESS_POINTER_AltAdvManager = pinstAltAdvManager_x;

    EQ_ADDRESS_FUNCTION_AltAdvManager__GetAAById = AltAdvManager__GetAAById_x;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = __DrawHandler_x;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_FUNCTION_CXStr__CXStr                   = CXStr__CXStr_x;
    EQ_ADDRESS_FUNCTION_CXStr__CXStr1                  = CXStr__CXStr1_x;
    EQ_ADDRESS_FUNCTION_CXStr__CXStr3                  = CXStr__CXStr3_x;
    EQ_ADDRESS_FUNCTION_CXStr__dCXStr                  = CXStr__dCXStr_x;
    EQ_ADDRESS_FUNCTION_CXStr__operator_equal          = CXStr__operator_equal_x;
    EQ_ADDRESS_FUNCTION_CXStr__operator_equal1         = CXStr__operator_equal1_x;
    EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal1    = CXStr__operator_plus_equal1_x;

    EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltip           = CXWnd__DrawTooltip_x;
    EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltipAtPoint    = CXWnd__DrawTooltipAtPoint_x;
    EQ_ADDRESS_FUNCTION_CXWnd__BringToTop            = CXWnd__BringToTop_x;
    EQ_ADDRESS_FUNCTION_CXWnd__IsActive              = CXWnd__IsActive_x;
    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible       = CXWnd__IsReallyVisible_x;
    EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem          = CXWnd__GetChildItem_x;
    EQ_ADDRESS_FUNCTION_CXWnd__GetWindowTextA        = CXWnd__GetWindowTextA_x;

    EQ_ADDRESS_POINTER_CBazaarWnd = pinstCBazaarWnd_x;

    EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = pinstCBazaarConfirmationWnd_x;

    EQ_ADDRESS_POINTER_CBazaarSearchWnd = pinstCBazaarSearchWnd_x;
    // **** //

    EQ_ADDRESS_POINTER_CCharacterListWnd = pinstCCharacterListWnd_x;
    EQ_ADDRESS_FUNCTION_CCharacterListWnd__SelectCharacter    = CCharacterListWnd__SelectCharacter_x;
    EQ_ADDRESS_FUNCTION_CCharacterListWnd__EnterWorld         = CCharacterListWnd__EnterWorld_x;
    EQ_ADDRESS_FUNCTION_CCharacterListWnd__Quit               = CCharacterListWnd__Quit_x;

    EQ_ADDRESS_POINTER_CTaskSelectWnd = pinstCTaskSelectWnd_x;

    EQ_ADDRESS_POINTER_CLargeDialogWnd = pinstCLargeDialogWnd_x;
    EQ_ADDRESS_FUNCTION_CLargeDialogWnd__Open    = CLargeDialogWnd__Open_x;

    EQ_ADDRESS_POINTER_CConfirmationDialog = pinstCConfirmationDialog_x;

    EQ_ADDRESS_POINTER_CPlayerWnd = pinstCPlayerWnd_x;
    EQ_ADDRESS_POINTER_CTargetWnd = pinstCTargetWnd_x;

    EQ_ADDRESS_POINTER_CPetInfoWindow = pinstCPetInfoWnd_x;

    EQ_ADDRESS_POINTER_CBuffWnd_Long = pinstCBuffWindowNORMAL_x;
    EQ_ADDRESS_POINTER_CBuffWnd_Short = pinstCBuffWindowSHORT_x;

    EQ_ADDRESS_POINTER_CCastSpellWnd = pinstCCastSpellWnd_x;

    EQ_ADDRESS_POINTER_CCastingWnd = pinstCCastingWnd_x;

    EQ_ADDRESS_POINTER_CMapViewWnd = pinstCMapViewWnd_x;

    EQ_ADDRESS_POINTER_CInventoryWnd = pinstCInventoryWnd_x;

#ifdef EQ_FEATURE_GUI
    EQ_ADDRESS_FUNCTION_WindowProc = 0x006A6AC0;

    EQ_ADDRESS_FUNCTION_ProcessMouseEvent = 0x005FA470;
    EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent = 0x006A5B20;

    EQ_ADDRESS_FUNCTION_FlushDxMouse = 0x006A3BE0;
    EQ_ADDRESS_FUNCTION_FlushDxKeyboard = 0x006A3FE0;
#endif // EQ_FEATURE_GUI

#ifdef EQ_FEATURE_CollisionCallbackForActors
    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors = 0x0051D6D0;
#endif // EQ_FEATURE_CollisionCallbackForActors

#ifdef EQ_FEATURE_DoSpellEffect
    EQ_ADDRESS_FUNCTION_DoSpellEffect = 0x005F9D20;
#endif // EQ_FEATURE_DoSpellEffect

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI = 0x00642D90;
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot = 0x0064AC70;
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

#ifdef EQ_FEATURE_CEverQuest__StartCasting
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting = 0x005DD710;
#endif // EQ_FEATURE_CEverQuest__StartCasting

#ifdef EQ_FEATURE_GUI
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel = 0x005D3C40;
#endif // EQ_FEATURE_GUI

#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00537980;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x005334E0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x005378F0;
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS

#ifdef EQ_FEATURE_EQSwitch__ChangeState
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState = 0x005CB9E0;
#endif // EQ_FEATURE_EQSwitch__ChangeState

#ifdef EQ_FEATURE_BAZAAR
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg    = CBazaarSearchWnd__HandleBazaarMsg_x;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList      = 0x006D8960;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery            = 0x006D9200;
    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem            = 0x006D9730;
#endif // EQ_FEATURE_BAZAAR
}
