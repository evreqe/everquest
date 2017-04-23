#pragma once

#include "eq.h"
#include "eq_structures.h"
#include "eq_classes.h"

/* structures */

#define EQ_ADDRESS_STRUCTURE_GUILD_LIST 0x007F9C94

EQ::GuildList* EQ_POINTER_GuildList_ptr = (EQ::GuildList*)EQ_ADDRESS_STRUCTURE_GUILD_LIST;
#define EQ_POINTER_GuildList (*EQ_POINTER_GuildList_ptr)

#define EQ_ADDRESS_STRUCTURE_GROUP_LIST 0x007913F8

EQ::GroupList* EQ_POINTER_GroupList_ptr = (EQ::GroupList*)EQ_ADDRESS_STRUCTURE_GROUP_LIST;
#define EQ_POINTER_GroupList (*EQ_POINTER_GroupList_ptr)

#define EQ_ADDRESS_STRUCTURE_ZONE 0x00798784

EQ::Zone* EQ_POINTER_Zone_ptr = (EQ::Zone*)EQ_ADDRESS_STRUCTURE_ZONE;
#define EQ_POINTER_Zone (*EQ_POINTER_Zone_ptr)

/* other */

#define EQ_ADDRESS_POINTER_EqSoundManager 0x0063DEA8

#define EQ_ADDRESS_POINTER_CInvSlotMgr 0x0063D6B4

/* camera */

#define EQ_ADDRESS_POINTER_Camera 0x0063B928

EQ::Camera** EQ_POINTER_Camera_pptr = (EQ::Camera**)EQ_ADDRESS_POINTER_Camera;
#define EQ_POINTER_Camera (*EQ_POINTER_Camera_pptr)

/* SpellManager */

#define EQ_ADDRESS_POINTER_SpellManager 0x00805CB0

EQ::SpellList** EQ_POINTER_SpellList_pptr = (EQ::SpellList**)EQ_ADDRESS_POINTER_SpellManager;
#define EQ_POINTER_SpellList (*EQ_POINTER_SpellList_pptr)

/* CXWndManager */

#define EQ_ADDRESS_POINTER_CXWndManager 0x00809DB4

EQ::CXWndManager** EQ_POINTER_CXWndManager_pptr = (EQ::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
#define EQ_POINTER_CXWndManager (*EQ_POINTER_CXWndManager_pptr)

EQClasses::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr = (EQClasses::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
#define EQ_CLASS_POINTER_CXWndManager (*EQ_CLASS_POINTER_CXWndManager_pptr)

/* CDisplay */

#define EQ_ADDRESS_POINTER_CDisplay 0x007F9510

EQClasses::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr = (EQClasses::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
#define EQ_CLASS_POINTER_CDisplay (*EQ_CLASS_POINTER_CDisplay_pptr)

/* CEverQuest */

#define EQ_ADDRESS_POINTER_CEverQuest 0x00809478

EQClasses::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr = (EQClasses::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
#define EQ_CLASS_POINTER_CEverQuest (*EQ_CLASS_POINTER_CEverQuest_pptr)

/* EQ_Character */

#define EQ_ADDRESS_POINTER_EQ_Character 0x007F94E8

EQClasses::EQ_Character** EQ_CLASS_POINTER_EQ_Character_pptr = (EQClasses::EQ_Character**)EQ_ADDRESS_POINTER_EQ_Character;
#define EQ_CLASS_POINTER_EQ_Character (*EQ_CLASS_POINTER_EQ_Character_pptr)

/* EQPlayer */

#define EQ_ADDRESS_POINTER_PLAYER_SPAWN        0x007F94CC
#define EQ_ADDRESS_POINTER_TARGET_SPAWN        0x007F94EC
#define EQ_ADDRESS_POINTER_CONTROLLED_SPAWN    0x007F94E0

// targetted spawns
#define EQ_ADDRESS_POINTER_TRADE_SPAWN         0x007F94C8
#define EQ_ADDRESS_POINTER_MERCHANT_SPAWN      0x007F94F8
#define EQ_ADDRESS_POINTER_BANKER_SPAWN        0x007F94FC
#define EQ_ADDRESS_POINTER_CORPSE_SPAWN        0x007F9500
#define EQ_ADDRESS_POINTER_GAMEMASTER_SPAWN    0x007F9504

EQ::Spawn** EQ_POINTER_PlayerSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_PLAYER_SPAWN;
#define EQ_POINTER_PlayerSpawn (*EQ_POINTER_PlayerSpawn_pptr)

EQ::Spawn** EQ_POINTER_TargetSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_TARGET_SPAWN;
#define EQ_POINTER_TargetSpawn (*EQ_POINTER_TargetSpawn_pptr)

EQ::Spawn** EQ_POINTER_ControlledSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_CONTROLLED_SPAWN;
#define EQ_POINTER_ControlledSpawn (*EQ_POINTER_ControlledSpawn_pptr)

EQ::Spawn** EQ_POINTER_TradeSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_TRADE_SPAWN;
#define EQ_POINTER_TradeSpawn (*EQ_POINTER_TradeSpawn_pptr)

EQ::Spawn** EQ_POINTER_MerchantSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_MERCHANT_SPAWN;
#define EQ_POINTER_MerchantSpawn (*EQ_POINTER_MerchantSpawn_pptr)

EQ::Spawn** EQ_POINTER_BankerSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_BANKER_SPAWN;
#define EQ_POINTER_BankerSpawn (*EQ_POINTER_BankerSpawn_pptr)

EQ::Spawn** EQ_POINTER_CorpseSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_CORPSE_SPAWN;
#define EQ_POINTER_CorpseSpawn (*EQ_POINTER_CorpseSpawn_pptr)

EQ::Spawn** EQ_POINTER_GamemasterSpawn_pptr = (EQ::Spawn**)EQ_ADDRESS_POINTER_GAMEMASTER_SPAWN;
#define EQ_POINTER_GamemasterSpawn (*EQ_POINTER_GamemasterSpawn_pptr)


/* windows */

#define EQ_ADDRESS_POINTER_CBuffWindow     0x0063D638
#define EQ_ADDRESS_POINTER_CGiveWnd        0x0063D678
#define EQ_ADDRESS_POINTER_CHotButtonWnd   0x0063D628
#define EQ_ADDRESS_POINTER_CItemDisplayWnd 0x0063D5E0
#define EQ_ADDRESS_POINTER_CTradeWnd       0x0063D668
#define EQ_ADDRESS_POINTER_CSpellBookWnd   0x0063D64C
#define EQ_ADDRESS_POINTER_CLootWnd        0x0063D65C
#define EQ_ADDRESS_POINTER_CTrackingWnd    0x0063D67C
