#pragma once

#include "eq.h"
#include "eq_structures.h"
#include "eq_classes.h"

/* structures */

#define EQ_ADDRESS_STRUCTURE_SPAWN_ID_ARRAY 0x0078C47C

uint32_t* EQ_POINTER_SpawnIDArray_ptr = (uint32_t*)EQ_ADDRESS_STRUCTURE_SPAWN_ID_ARRAY;
#define EQ_POINTER_SpawnIDArray (*EQ_POINTER_SpawnIDArray_ptr)

#define EQ_ADDRESS_STRUCTURE_COMMAND_LIST 0x00609AF8

EQ::CommandList* EQ_POINTER_CommandList_ptr = (EQ::CommandList*)EQ_ADDRESS_STRUCTURE_COMMAND_LIST;
#define EQ_POINTER_CommandList (*EQ_POINTER_CommandList_ptr)

#define EQ_ADDRESS_STRUCTURE_GUILD_LIST 0x007F9C94

EQ::GuildList* EQ_POINTER_GuildList_ptr = (EQ::GuildList*)EQ_ADDRESS_STRUCTURE_GUILD_LIST;
#define EQ_POINTER_GuildList (*EQ_POINTER_GuildList_ptr)

#define EQ_ADDRESS_STRUCTURE_GROUP_LIST 0x007913F8

EQ::GroupList* EQ_POINTER_GroupList_ptr = (EQ::GroupList*)EQ_ADDRESS_STRUCTURE_GROUP_LIST;
#define EQ_POINTER_GroupList (*EQ_POINTER_GroupList_ptr)

#define EQ_ADDRESS_STRUCTURE_ZONE 0x00798784

EQ::Zone* EQ_POINTER_Zone_ptr = (EQ::Zone*)EQ_ADDRESS_STRUCTURE_ZONE;
#define EQ_POINTER_Zone (*EQ_POINTER_Zone_ptr)

/* Direct Input */

#define EQ_ADDRESS_POINTER_DINPUT_ROOT               0x8092DC
#define EQ_ADDRESS_POINTER_DINPUT_DEVICE_KEYBOARD    0x8092E0
#define EQ_ADDRESS_POINTER_DINPUT_DEVICE_MOUSE       0x8092E4

IDirectInput8** EQ_CLASS_POINTER_IDirectInput8_pptr = (IDirectInput8**)EQ_ADDRESS_POINTER_DINPUT_ROOT;
#define EQ_CLASS_POINTER_IDirectInput8 (*EQ_CLASS_POINTER_IDirectInput8_pptr)

IDirectInputDevice8** EQ_CLASS_POINTER_DInputKeyboard_pptr = (IDirectInputDevice8**)EQ_ADDRESS_POINTER_DINPUT_DEVICE_KEYBOARD;
#define EQ_CLASS_POINTER_DInputKeyboard (*EQ_CLASS_POINTER_DInputKeyboard_pptr)

IDirectInputDevice8** EQ_CLASS_POINTER_DInputMouse_pptr = (IDirectInputDevice8**)EQ_ADDRESS_POINTER_DINPUT_DEVICE_MOUSE;
#define EQ_CLASS_POINTER_DInputMouse (*EQ_CLASS_POINTER_DInputMouse_pptr)

/* StringTable */

#define EQ_ADDRESS_POINTER_StringTable 0x007F9490 // eqstr_xx.txt

EQClass::StringTable** EQ_CLASS_POINTER_StringTable_pptr = (EQClass::StringTable**)EQ_ADDRESS_POINTER_StringTable;
#define EQ_CLASS_POINTER_StringTable (*EQ_CLASS_POINTER_StringTable_pptr)

/* EQWorldData */

#define EQ_ADDRESS_POINTER_EQWorldData 0x007F9494

EQ::EQWorldData** EQ_POINTER_EQWorldData_pptr = (EQ::EQWorldData**)EQ_ADDRESS_POINTER_EQWorldData;
#define EQ_POINTER_EQWorldData (*EQ_POINTER_EQWorldData_pptr)

EQClass::EQWorldData** EQ_CLASS_POINTER_EQWorldData_pptr = (EQClass::EQWorldData**)EQ_ADDRESS_POINTER_EQWorldData;
#define EQ_CLASS_POINTER_EQWorldData (*EQ_CLASS_POINTER_EQWorldData_pptr)

/* EqSoundManager */

#define EQ_ADDRESS_POINTER_EqSoundManager 0x0063DEA8

/* CContainerMgr */

#define EQ_ADDRESS_POINTER_CContainerMgr 0x0063D6B8

EQClass::CContainerMgr** EQ_CLASS_POINTER_CContainerMgr_pptr = (EQClass::CContainerMgr**)EQ_ADDRESS_POINTER_CContainerMgr;
#define EQ_CLASS_POINTER_CContainerMgr (*EQ_CLASS_POINTER_CContainerMgr_pptr)

/* SpellManager */

#define EQ_ADDRESS_POINTER_SpellManager 0x00805CB0

EQ::SpellManager** EQ_POINTER_SpellManager_pptr = (EQ::SpellManager**)EQ_ADDRESS_POINTER_SpellManager;
#define EQ_POINTER_SpellManager (*EQ_POINTER_SpellManager_pptr)

#define EQ_POINTER_SpellList EQ_POINTER_SpellManager

/* camera */

#define EQ_ADDRESS_POINTER_Camera 0x0063B928

EQ::Camera** EQ_POINTER_Camera_pptr = (EQ::Camera**)EQ_ADDRESS_POINTER_Camera;
#define EQ_POINTER_Camera (*EQ_POINTER_Camera_pptr)

/* CDisplay */

#define EQ_ADDRESS_POINTER_CDisplay 0x007F9510

EQ::CDisplay** EQ_POINTER_CDisplay_pptr = (EQ::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
#define EQ_POINTER_CDisplay (*EQ_POINTER_CDisplay_pptr)

EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
#define EQ_CLASS_POINTER_CDisplay (*EQ_CLASS_POINTER_CDisplay_pptr)

/* CEverQuest */

#define EQ_ADDRESS_POINTER_CEverQuest 0x00809478

EQ::CEverQuest** EQ_POINTER_CEverQuest_pptr = (EQ::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
#define EQ_POINTER_CEverQuest (*EQ_POINTER_CEverQuest_pptr)

EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
#define EQ_CLASS_POINTER_CEverQuest (*EQ_CLASS_POINTER_CEverQuest_pptr)

/* EQPlayer */

#define EQ_ADDRESS_POINTER_FIRST_SPAWN 0x007F9498 // spawn list

#define EQ_ADDRESS_POINTER_PLAYER_SPAWN        0x007F94CC
#define EQ_ADDRESS_POINTER_TARGET_SPAWN        0x007F94EC
#define EQ_ADDRESS_POINTER_CONTROLLED_SPAWN    0x007F94E0

// targetted spawns
#define EQ_ADDRESS_POINTER_TRADE_SPAWN         0x007F94C8
#define EQ_ADDRESS_POINTER_MERCHANT_SPAWN      0x007F94F8
#define EQ_ADDRESS_POINTER_BANKER_SPAWN        0x007F94FC
#define EQ_ADDRESS_POINTER_CORPSE_SPAWN        0x007F9500
#define EQ_ADDRESS_POINTER_GAMEMASTER_SPAWN    0x007F9504

EQ::EQPlayer** EQ_POINTER_FirstSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_FIRST_SPAWN;
#define EQ_POINTER_FirstSpawn (*EQ_POINTER_FirstSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_PlayerSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_PLAYER_SPAWN;
#define EQ_POINTER_PlayerSpawn (*EQ_POINTER_PlayerSpawn_pptr)

EQClass::EQPlayer** EQ_CLASS_POINTER_PlayerSpawn_pptr = (EQClass::EQPlayer**)EQ_ADDRESS_POINTER_PLAYER_SPAWN;
#define EQ_CLASS_POINTER_PlayerSpawn (*EQ_CLASS_POINTER_PlayerSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_TargetSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_TARGET_SPAWN;
#define EQ_POINTER_TargetSpawn (*EQ_POINTER_TargetSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_ControlledSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_CONTROLLED_SPAWN;
#define EQ_POINTER_ControlledSpawn (*EQ_POINTER_ControlledSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_TradeSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_TRADE_SPAWN;
#define EQ_POINTER_TradeSpawn (*EQ_POINTER_TradeSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_MerchantSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_MERCHANT_SPAWN;
#define EQ_POINTER_MerchantSpawn (*EQ_POINTER_MerchantSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_BankerSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_BANKER_SPAWN;
#define EQ_POINTER_BankerSpawn (*EQ_POINTER_BankerSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_CorpseSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_CORPSE_SPAWN;
#define EQ_POINTER_CorpseSpawn (*EQ_POINTER_CorpseSpawn_pptr)

EQ::EQPlayer** EQ_POINTER_GamemasterSpawn_pptr = (EQ::EQPlayer**)EQ_ADDRESS_POINTER_GAMEMASTER_SPAWN;
#define EQ_POINTER_GamemasterSpawn (*EQ_POINTER_GamemasterSpawn_pptr)

/* GroundSpawn */

#define EQ_ADDRESS_POINTER_FIRST_GROUND_SPAWN 0x007F949C // ground spawn list

EQ::GroundSpawn** EQ_POINTER_FirstGroundSpawn_pptr = (EQ::GroundSpawn**)EQ_ADDRESS_POINTER_FIRST_GROUND_SPAWN;
#define EQ_POINTER_FirstGroundSpawn (*EQ_POINTER_FirstGroundSpawn_pptr)

/* DoorSpawn */

#define EQ_ADDRESS_POINTER_FIRST_DOOR_SPAWN 0x007F94B8 // door list

EQ::DoorSpawn** EQ_POINTER_FirstDoorSpawn_pptr = (EQ::DoorSpawn**)EQ_ADDRESS_POINTER_FIRST_DOOR_SPAWN;
#define EQ_POINTER_FirstDoorSpawn (*EQ_POINTER_FirstDoorSpawn_pptr)

/* EQ_Character */

#define EQ_ADDRESS_POINTER_PLAYER_CHARACTER 0x007F94E8

EQ::EQ_Character** EQ_POINTER_PlayerCharacter_pptr = (EQ::EQ_Character**)EQ_ADDRESS_POINTER_PLAYER_CHARACTER;
#define EQ_POINTER_PlayerCharacter (*EQ_POINTER_PlayerCharacter_pptr)

EQClass::EQ_Character** EQ_CLASS_POINTER_PlayerCharacter_pptr = (EQClass::EQ_Character**)EQ_ADDRESS_POINTER_PLAYER_CHARACTER;
#define EQ_CLASS_POINTER_PlayerCharacter (*EQ_CLASS_POINTER_PlayerCharacter_pptr)

/* CInvSlotMgr */

#define EQ_ADDRESS_POINTER_CInvSlotMgr 0x0063D6B4

EQClass::CInvSlotMgr** EQ_CLASS_POINTER_CInvSlotMgr_pptr = (EQClass::CInvSlotMgr**)EQ_ADDRESS_POINTER_CInvSlotMgr;
#define EQ_CLASS_POINTER_CInvSlotMgr (*EQ_CLASS_POINTER_CInvSlotMgr_pptr)

/* CXWndManager */

#define EQ_ADDRESS_POINTER_CXWndManager 0x00809DB4

EQ::CXWndManager** EQ_POINTER_CXWndManager_pptr = (EQ::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
#define EQ_POINTER_CXWndManager (*EQ_POINTER_CXWndManager_pptr)

EQClass::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
#define EQ_CLASS_POINTER_CXWndManager (*EQ_CLASS_POINTER_CXWndManager_pptr)

/* CBazaarSearchWnd */

#define EQ_ADDRESS_POINTER_CBazaarSearchWnd 0x0063D674

EQClass::CBazaarSearchWnd** EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
#define EQ_CLASS_POINTER_CBazaarSearchWnd (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr)

/* CBuffWindow */

#define EQ_ADDRESS_POINTER_CBuffWindow 0x0063D638

EQ::CBuffWindow** EQ_POINTER_CBuffWindow_pptr = (EQ::CBuffWindow**)EQ_ADDRESS_POINTER_CBuffWindow;
#define EQ_POINTER_CBuffWindow (*EQ_POINTER_CBuffWindow_pptr)

EQClass::CBuffWindow** EQ_CLASS_POINTER_CBuffWindow_pptr = (EQClass::CBuffWindow**)EQ_ADDRESS_POINTER_CBuffWindow;
#define EQ_CLASS_POINTER_CBuffWindow (*EQ_CLASS_POINTER_CBuffWindow_pptr)

/* CGiveWnd */

#define EQ_ADDRESS_POINTER_CGiveWnd 0x0063D678

EQClass::CGiveWnd** EQ_CLASS_POINTER_CGiveWnd_pptr = (EQClass::CGiveWnd**)EQ_ADDRESS_POINTER_CGiveWnd;
#define EQ_CLASS_POINTER_CGiveWnd (*EQ_CLASS_POINTER_CGiveWnd_pptr)

/* CHotButtonWnd */

#define EQ_ADDRESS_POINTER_CHotButtonWnd 0x0063D628

////EQ::CHotButtonWnd** EQ_POINTER_CHotButtonWnd_pptr = (EQ::CHotButtonWnd**)EQ_ADDRESS_POINTER_CHotButtonWnd;
////#define EQ_POINTER_CHotButtonWnd (*EQ_POINTER_CHotButtonWnd_pptr)

EQClass::CHotButtonWnd** EQ_CLASS_POINTER_CHotButtonWnd_pptr = (EQClass::CHotButtonWnd**)EQ_ADDRESS_POINTER_CHotButtonWnd;
#define EQ_CLASS_POINTER_CHotButtonWnd (*EQ_CLASS_POINTER_CHotButtonWnd_pptr)

/* CItemDisplayWnd */

#define EQ_ADDRESS_POINTER_CItemDisplayWnd 0x0063D5E0

EQ::CItemDisplayWnd** EQ_POINTER_CItemDisplayWnd_pptr = (EQ::CItemDisplayWnd**)EQ_ADDRESS_POINTER_CItemDisplayWnd;
#define EQ_POINTER_CItemDisplayWnd (*EQ_POINTER_CItemDisplayWnd_pptr)

EQClass::CItemDisplayWnd** EQ_CLASS_POINTER_CItemDisplayWnd_pptr = (EQClass::CItemDisplayWnd**)EQ_ADDRESS_POINTER_CItemDisplayWnd;
#define EQ_CLASS_POINTER_CItemDisplayWnd (*EQ_CLASS_POINTER_CItemDisplayWnd_pptr)

/* CLootWnd */

#define EQ_ADDRESS_POINTER_CLootWnd 0x0063D65C

EQ::CLootWnd** EQ_POINTER_CLootWnd_pptr = (EQ::CLootWnd**)EQ_ADDRESS_POINTER_CLootWnd;
#define EQ_POINTER_CLootWnd (*EQ_POINTER_CLootWnd_pptr)

EQClass::CLootWnd** EQ_CLASS_POINTER_CLootWnd_pptr = (EQClass::CLootWnd**)EQ_ADDRESS_POINTER_CLootWnd;
#define EQ_CLASS_POINTER_CLootWnd (*EQ_CLASS_POINTER_CLootWnd_pptr)

/* CSpellBookWnd */

#define EQ_ADDRESS_POINTER_CSpellBookWnd 0x0063D64C

EQClass::CSpellBookWnd** EQ_CLASS_POINTER_CSpellBookWnd_pptr = (EQClass::CSpellBookWnd**)EQ_ADDRESS_POINTER_CSpellBookWnd;
#define EQ_CLASS_POINTER_CSpellBookWnd (*EQ_CLASS_POINTER_CSpellBookWnd_pptr)

/* CTrackingWnd */

#define EQ_ADDRESS_POINTER_CTrackingWnd 0x0063D67C

EQClass::CTrackingWnd** EQ_CLASS_POINTER_CTrackingWnd_pptr = (EQClass::CTrackingWnd**)EQ_ADDRESS_POINTER_CTrackingWnd;
#define EQ_CLASS_POINTER_CTrackingWnd (*EQ_CLASS_POINTER_CTrackingWnd_pptr)

/* CTradeWnd */

#define EQ_ADDRESS_POINTER_CTradeWnd 0x0063D668

EQClass::CTradeWnd** EQ_CLASS_POINTER_CTradeWnd_pptr = (EQClass::CTradeWnd**)EQ_ADDRESS_POINTER_CTradeWnd;
#define EQ_CLASS_POINTER_CTradeWnd (*EQ_CLASS_POINTER_CTradeWnd_pptr)

