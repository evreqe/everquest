#pragma once

#include "eq.h"
#include "eq_macros.h"

namespace EQClass
{
    class StringTable;
    class EQWorldData;

    class CDisplay;
    class CEverQuest;
    class CInvSlot;
    class CInvSlotMgr;

    class EQPlayer;
    class EQ_Character;
    class EQ_Item;
    class EQ_Container;
    class EQ_Spell;
    class EQSwitch;

    class CXStr;
    class CXPoint;
    class CXRect;
    class CXWndManager;
    class CXWnd;
    class CSidlScreenWnd;
    class CButtonWnd;
    class CContainerWnd;
    class CContainerMgr;

    class CBazaarSearchWnd;
    class CBuffWindow;
    class CGiveWnd;
    class CHotButtonWnd;
    class CItemDisplayWnd;
    class CLootWnd;
    class CMerchantWnd;
    class CSpellBookWnd;
    class CTextEntryWnd;
    class CTrackingWnd;
    class CTradeWnd;
} // namespace EQClass

/* StringTable */

class EQClass::StringTable
{
public:
    char* StringTable::getString(unsigned long ID, bool* result = false);
};

#define EQ_ADDRESS_FUNCTION_StringTable__getString 0x00550EFE
EQ_MACRO_FunctionAtAddress(char* EQClass::StringTable::getString(unsigned long ID, bool* result), EQ_ADDRESS_FUNCTION_StringTable__getString);

/* EQWorldData */

class EQClass::EQWorldData
{
public:
    //
};

#define EQ_ADDRESS_FUNCTION_EQWorldData__GetFullZoneName 0x00523E49

#define EQ_ADDRESS_FUNCTION_EQWorldData__GetZoneNameFromIndex 0x00523F73

/* CDisplay */

class EQClass::CDisplay
{
public:
    void CDisplay::Render_World();
    void CDisplay::RealRender_World();
    void CDisplay::MoveLocalPlayerToSafeCoords();
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, int textColor, int font);
    EQ::StringSprite_ptr CDisplay::ChangeDagStringSprite(EQ::ModelBone_ptr modelBone, int fontTexture, const char* text);
    int __cdecl CDisplay::SetNameSpriteState(class EQPlayer* player, bool show);
    int __cdecl CDisplay::SetNameSpriteTint(class EQPlayer* player);
    void CDisplay::CreatePlayerActor(class EQPlayer* player);
    void CDisplay::DeleteActor(EQ::ActorInstance_ptr actorInstance);
    void CDisplay::SetViewActor(EQ::ActorInstance_ptr actorInstance);
    int CDisplay::ToggleView();
    void CDisplay::NewUIProcessEscape();
    EQ::Spawn_ptr CDisplay::GetNearestPlayerInView(float maxDistance, uint8_t spawnType);
};

#define EQ_ADDRESS_FUNCTION_CDisplay__Render_World 0x004AA8BC
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::Render_World(), EQ_ADDRESS_FUNCTION_CDisplay__Render_World);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__Render_World)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CDisplay__RealRender_World 0x004AAA1B
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::RealRender_World(), EQ_ADDRESS_FUNCTION_CDisplay__RealRender_World);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__RealRender_World)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CDisplay__MoveLocalPlayerToSafeCoords 0x004B459C
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::MoveLocalPlayerToSafeCoords(), EQ_ADDRESS_FUNCTION_CDisplay__MoveLocalPlayerToSafeCoords);

#define EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 0x004AA5AA
EQ_MACRO_FunctionAtAddress(int EQClass::CDisplay::WriteTextHD2(const char* text, int x, int y, int textColor, int font), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

#define EQ_ADDRESS_FUNCTION_CDisplay__ChangeDagStringSprite 0x004B0AA8
EQ_MACRO_FunctionAtAddress(EQ::StringSprite_ptr EQClass::CDisplay::ChangeDagStringSprite(EQ::ModelBone_ptr modelBone, int fontTexture, const char* text), EQ_ADDRESS_FUNCTION_CDisplay__ChangeDagStringSprite);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__ChangeDagStringSprite)(void* this_ptr, EQ::ModelBone_ptr modelBone, int fontTexture, const char* text);

#define EQ_ADDRESS_FUNCTION_CDisplay__SetNameSpriteState 0x004B0BD9
EQ_MACRO_FunctionAtAddress(int EQClass::CDisplay::SetNameSpriteState(class EQPlayer* player, bool show), EQ_ADDRESS_FUNCTION_CDisplay__SetNameSpriteState);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteState)(void* this_ptr, class EQPlayer* player, bool show);

#define EQ_ADDRESS_FUNCTION_CDisplay__SetNameSpriteTint 0x004B114D
EQ_MACRO_FunctionAtAddress(int EQClass::CDisplay::SetNameSpriteTint(class EQPlayer* player), EQ_ADDRESS_FUNCTION_CDisplay__SetNameSpriteTint);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteTint)(void* this_ptr, class EQPlayer* player);

#define EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor 0x004ADF2C
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::CreatePlayerActor(class EQPlayer* player), EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)(void* this_ptr, class EQPlayer* player);

#define EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor 0x004B0507
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::DeleteActor(EQ::ActorInstance_ptr actorInstance), EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__DeleteActor)(void* this_ptr, EQ::ActorInstance_ptr actorInstance);

#define EQ_ADDRESS_FUNCTION_CDisplay__SetViewActor 0x004AC9F7
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::SetViewActor(EQ::ActorInstance_ptr actorInstance), EQ_ADDRESS_FUNCTION_CDisplay__SetViewActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetViewActor)(void* this_ptr, EQ::ActorInstance_ptr actorInstance);

#define EQ_ADDRESS_FUNCTION_CDisplay__ToggleView 0x004ADC80
EQ_MACRO_FunctionAtAddress(int EQClass::CDisplay::ToggleView(), EQ_ADDRESS_FUNCTION_CDisplay__ToggleView);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__ToggleView)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CDisplay__NewUIProcessEscape 0x004A7A7C
EQ_MACRO_FunctionAtAddress(void EQClass::CDisplay::NewUIProcessEscape(), EQ_ADDRESS_FUNCTION_CDisplay__NewUIProcessEscape);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__NewUIProcessEscape)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CDisplay__GetNearestPlayerInView 0x004AC17F
EQ_MACRO_FunctionAtAddress(EQ::Spawn_ptr EQClass::CDisplay::GetNearestPlayerInView(float maxDistance, uint8_t spawnType), EQ_ADDRESS_FUNCTION_CDisplay__GetNearestPlayerInView);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__GetNearestPlayerInView)(void* this_ptr, float maxDistance, uint8_t spawnType);

/* CEverQuest */

class EQClass::CEverQuest
{
public:
    void CEverQuest::InterpretCmd(class EQPlayer* player, char* text);
    void CEverQuest::dsp_chat(const char* text, uint16_t textColor, bool filtered);
    void CEverQuest::dsp_chat(const char* text);
    int __cdecl CEverQuest::LMouseDown(uint16_t x, uint16_t y);
    int __cdecl CEverQuest::LMouseUp(uint16_t x, uint16_t y);
    int __cdecl CEverQuest::RMouseDown(uint16_t x, uint16_t y);
    int __cdecl CEverQuest::RMouseUp(uint16_t x, uint16_t y);
    char* CEverQuest::trimName(char* spawnName);
    int CEverQuest::MoveToZone(char* zoneShortName, char* text, int destinationType, int zoneRequestReason);
    int CEverQuest::MoveToZone(int zoneID, char* text, int destinationType, int zoneRequestReason);
    int CEverQuest::LootCorpse(class EQPlayer* player, int unknown);
    void CEverQuest::DropHeldItemOnGround(bool showDropMessage);
    void CEverQuest::StartCasting(EQ::CEverQuestStartCastingMessage_ptr message);
};

#define EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd 0x0054572F
EQ_MACRO_FunctionAtAddress(void EQClass::CEverQuest::InterpretCmd(class EQPlayer* player, char* text), EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, class EQPlayer* player, char* text);

#define EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat 0x00537F99
EQ_MACRO_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text, uint16_t textColor, bool filtered), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, uint16_t textColor, bool filtered);

#define EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat__2 0x005380FD
EQ_MACRO_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat__2);

#define EQ_ADDRESS_FUNCTION_CEverQuest__LMouseDown 0x005465AA
EQ_MACRO_FunctionAtAddress(int __cdecl EQClass::CEverQuest::LMouseDown(uint16_t x, uint16_t y), EQ_ADDRESS_FUNCTION_CEverQuest__LMouseDown);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LMouseDown)(void* this_ptr, uint16_t x, uint16_t y);

#define EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp 0x00531614
EQ_MACRO_FunctionAtAddress(int __cdecl EQClass::CEverQuest::LMouseUp(uint16_t x, uint16_t y), EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LMouseUp)(void* this_ptr, uint16_t x, uint16_t y);

#define EQ_ADDRESS_FUNCTION_CEverQuest__RMouseDown 0x0054699D
EQ_MACRO_FunctionAtAddress(int __cdecl EQClass::CEverQuest::RMouseDown(uint16_t x, uint16_t y), EQ_ADDRESS_FUNCTION_CEverQuest__RMouseDown);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RMouseDown)(void* this_ptr, uint16_t x, uint16_t y);

#define EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp 0x00546B71
EQ_MACRO_FunctionAtAddress(int __cdecl EQClass::CEverQuest::RMouseUp(uint16_t x, uint16_t y), EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RMouseUp)(void* this_ptr, uint16_t x, uint16_t y);

#define EQ_ADDRESS_FUNCTION_CEverQuest__trimName 0x00537D39
EQ_MACRO_FunctionAtAddress(char* EQClass::CEverQuest::trimName(char* spawnName), EQ_ADDRESS_FUNCTION_CEverQuest__trimName);

#define EQ_ADDRESS_FUNCTION_CEverQuest__MoveToZone 0x005460B5
EQ_MACRO_FunctionAtAddress(int EQClass::CEverQuest::MoveToZone(char* zoneShortName, char* text, int destinationType, int zoneRequestReason), EQ_ADDRESS_FUNCTION_CEverQuest__MoveToZone);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__MoveToZone)(void* this_ptr, char* zoneShortName, char* text, int destinationType, int zoneRequestReason);

#define EQ_ADDRESS_FUNCTION_CEverQuest__MoveToZone__2 0x00546081
EQ_MACRO_FunctionAtAddress(int EQClass::CEverQuest::MoveToZone(int zoneID, char* text, int destinationType, int zoneRequestReason), EQ_ADDRESS_FUNCTION_CEverQuest__MoveToZone__2);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__MoveToZone2)(void* this_ptr, int zoneId, char* text, int destinationType, int zoneRequestReason);

#define EQ_ADDRESS_FUNCTION_CEverQuest__LootCorpse 0x00547808
EQ_MACRO_FunctionAtAddress(int EQClass::CEverQuest::LootCorpse(class EQPlayer* player, int unknown), EQ_ADDRESS_FUNCTION_CEverQuest__LootCorpse);
typedef signed int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LootCorpse)(void* this_ptr, class EQPlayer* player, int unknown);

#define EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround 0x00530D7E
EQ_MACRO_FunctionAtAddress(void EQClass::CEverQuest::DropHeldItemOnGround(bool showDropMessage), EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround);
typedef signed int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__DropHeldItemOnGround)(void* this_ptr, bool showDropMessage);

#define EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting 0x0052CBE7
EQ_MACRO_FunctionAtAddress(void EQClass::CEverQuest::StartCasting(EQ::CEverQuestStartCastingMessage_ptr message), EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__StartCasting)(void* this_ptr, EQ::CEverQuestStartCastingMessage_ptr message);

/* EQPlayer */

class EQClass::EQPlayer
{
public:
    void EQPlayer::ChangeHeight(float height);
    void EQPlayer::ChangePosition(uint8_t standingState);
    void EQPlayer::FacePlayer(class EQPlayer* player);
    void EQPlayer::FollowPlayerAI();
};

#define EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight 0x0050C160
EQ_MACRO_FunctionAtAddress(void EQClass::EQPlayer::ChangeHeight(float), EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);

#define EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition 0x0050BE3C
EQ_MACRO_FunctionAtAddress(void EQClass::EQPlayer::ChangePosition(uint8_t standingState), EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition);
typedef signed int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangePosition)(void* this_ptr, uint8_t standingState);

#define EQ_ADDRESS_FUNCTION_EQPlayer__FacePlayer 0x00508120
EQ_MACRO_FunctionAtAddress(void EQClass::EQPlayer::FacePlayer(class EQPlayer* player), EQ_ADDRESS_FUNCTION_EQPlayer__FacePlayer);

#define EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI 0x00507B08
EQ_MACRO_FunctionAtAddress(void EQClass::EQPlayer::FollowPlayerAI(), EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
typedef signed int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__FollowPlayerAI)(void* this_ptr);

/* EQ_Character */

class EQClass::EQ_Character
{
public:
    uint16_t EQ_Character::Max_Mana();
    void EQ_Character::eqspa_movement_rate(short unknown);
    int EQ_Character::CastSpell(uint8_t spellGemIndex, uint16_t spellID, EQ::Item** item, uint16_t unknown);
    int EQ_Character::StopSpellCast(uint8_t spellGemIndex, uint16_t spellID);
    int EQ_Character::StopSpellCast(uint8_t spellGemIndex);
    int EQ_Character::UseSkill(uint8_t skillID, class EQPlayer* targetSpawn);
};

#define EQ_ADDRESS_FUNCTION_EQ_Character__Max_Mana 0x004B9483
EQ_MACRO_FunctionAtAddress(uint16_t EQClass::EQ_Character::Max_Mana(), EQ_ADDRESS_FUNCTION_EQ_Character__Max_Mana);

#define EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate 0x004CAABA
EQ_MACRO_FunctionAtAddress(void EQClass::EQ_Character::eqspa_movement_rate(short unknown), EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)(void* this_ptr, short unknown);

#define EQ_ADDRESS_FUNCTION_EQ_Character__CastSpell 0x004C483B
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__CastSpell)(void* this_ptr, uint8_t spellGemIndex, uint16_t spellID, EQ::Item** item, uint16_t unknown);
EQ_MACRO_FunctionAtAddress(int EQClass::EQ_Character::CastSpell(uint8_t spellGemIndex, uint16_t spellID, EQ::Item** item, uint16_t unknown), EQ_ADDRESS_FUNCTION_EQ_Character__CastSpell);

#define EQ_ADDRESS_FUNCTION_EQ_Character__StopSpellCast 0x004CB510
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__StopSpellCast)(void* this_ptr, uint8_t spellGemIndex, uint16_t spellID);
EQ_MACRO_FunctionAtAddress(int EQClass::EQ_Character::StopSpellCast(uint8_t spellGemIndex, uint16_t spellID), EQ_ADDRESS_FUNCTION_EQ_Character__StopSpellCast);

#define EQ_ADDRESS_FUNCTION_EQ_Character__StopSpellCast__2 0x004CB4E8
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__StopSpellCast__2)(void* this_ptr, uint8_t spellGemIndex);
EQ_MACRO_FunctionAtAddress(int EQClass::EQ_Character::StopSpellCast(uint8_t spellGemIndex), EQ_ADDRESS_FUNCTION_EQ_Character__StopSpellCast__2);

#define EQ_ADDRESS_FUNCTION_EQ_Character__UseSkill 0x004BDF2F
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__UseSkill)(void* this_ptr, uint8_t skillID, class EQPlayer* targetSpawn);
EQ_MACRO_FunctionAtAddress(int EQClass::EQ_Character::UseSkill(uint8_t skillID, class EQPlayer* targetSpawn), EQ_ADDRESS_FUNCTION_EQ_Character__UseSkill);

/* EQ_Item */

class EQClass::EQ_Item
{
public:
    //
};

/* EQ_Container */

class EQClass::EQ_Container
{
public:
    //
};

/* EQ_Spell */

class EQClass::EQ_Spell
{
public:
    //
};

/* EQSwitch */

class EQClass::EQSwitch
{
public:
    //
};

/* CXStr */

class EQClass::CXStr
{
public:
    CXStr::~CXStr();
    CXStr::CXStr(char const *);
    void CXStr::operator+=(char const *);
    void CXStr::operator=(char const *);
    class CXStr& CXStr::operator=(class CXStr const&);
};

// constructor
#define EQ_ADDRESS_FUNCTION_CXStr__CXStr_char_const 0x00575F30
EQ_MACRO_FunctionAtAddress(EQClass::CXStr::CXStr(char const *), EQ_ADDRESS_FUNCTION_CXStr__CXStr_char_const);

// append char*
#define EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal_char_const 0x00577310
EQ_MACRO_FunctionAtAddress(void EQClass::CXStr::operator+=(char const *), EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal_char_const);

// set char*
#define EQ_ADDRESS_FUNCTION_CXStr__operator_equal_char_const 0x00576190
EQ_MACRO_FunctionAtAddress(void EQClass::CXStr::operator=(char const *), EQ_ADDRESS_FUNCTION_CXStr__operator_equal_char_const);

// set CXStr
#define EQ_ADDRESS_FUNCTION_CXStr__operator_equal_CXStr_const 0x00576140
EQ_MACRO_FunctionAtAddress(class EQClass::CXStr& EQClass::CXStr::operator=(class CXStr const&), EQ_ADDRESS_FUNCTION_CXStr__operator_equal_CXStr_const);

/* CXPoint */

class EQClass::CXPoint
{
public:
    uint32_t X;
    uint32_t Y;
};

/* CXRect */

class EQClass::CXRect
{
public:
    uint32_t X1;
    uint32_t Y1;
    uint32_t X2;
    uint32_t Y2;
};

/* CXWndManager */

class EQClass::CXWndManager
{
public:
    int CXWndManager::DrawCursor();
    int CXWndManager::DrawWindows();
};

#define EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor 0x0059E320
EQ_MACRO_FunctionAtAddress(int EQClass::CXWndManager::DrawCursor(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawCursor)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows 0x0059E000
EQ_MACRO_FunctionAtAddress(int EQClass::CXWndManager::DrawWindows(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawWindows)(void* this_ptr);

/* CXWnd */

class EQClass::CXWnd
{
public:
    void CXWnd::DrawTooltipAtPoint(int x, int y);
    class CXRect CXWnd::GetRelativeRect() const;
    class CXRect CXWnd::GetScreenRect() const;
};

#define EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltipAtPoint 0x00574800
EQ_MACRO_FunctionAtAddress(void EQClass::CXWnd::DrawTooltipAtPoint(int x, int y), EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltipAtPoint);

#define EQ_ADDRESS_FUNCTION_CXWnd__GetRelativeRect 0x005750C0
EQ_MACRO_FunctionAtAddress(class EQClass::CXRect EQClass::CXWnd::GetRelativeRect() const, EQ_ADDRESS_FUNCTION_CXWnd__GetRelativeRect);

#define EQ_ADDRESS_FUNCTION_CXWnd__GetScreenRect 0x005751C0
EQ_MACRO_FunctionAtAddress(class EQClass::CXRect EQClass::CXWnd::GetScreenRect() const, EQ_ADDRESS_FUNCTION_CXWnd__GetScreenRect);

/* CSidlScreenWnd */

class EQClass::CSidlScreenWnd
{
public:
    //
};

/* CButtonWnd */

class EQClass::CButtonWnd
{
public:
    //
};

/* CContainerWnd */

class EQClass::CContainerWnd : public EQClass::CSidlScreenWnd
{
public:
    //
};

/* CContainerMgr */

class EQClass::CContainerMgr
{
public:
    void CContainerMgr::OpenContainer(EQ::EQ_Container_ptr container, int inventorySlotIndex);
    void CContainerMgr::CloseContainer(EQ::EQ_Container_ptr container, bool unknown);
    bool CContainerMgr::CloseAllContainers();
};

#define EQ_ADDRESS_FUNCTION_CContainerMgr__OpenContainer 0x004168BD
EQ_MACRO_FunctionAtAddress(void EQClass::CContainerMgr::OpenContainer(EQ::EQ_Container_ptr container, int inventorySlotIndex), EQ_ADDRESS_FUNCTION_CContainerMgr__OpenContainer);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CContainerMgr__OpenContainer)(void* this_ptr, EQ::EQ_Container_ptr container, int inventorySlotIndex);

#define EQ_ADDRESS_FUNCTION_CContainerMgr__CloseContainer 0x004169E5
EQ_MACRO_FunctionAtAddress(void EQClass::CContainerMgr::CloseContainer(EQ::EQ_Container_ptr container, bool unknown), EQ_ADDRESS_FUNCTION_CContainerMgr__CloseContainer);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CContainerMgr__CloseContainer)(void* this_ptr, EQ::EQ_Container_ptr container, bool unknown);

#define EQ_ADDRESS_FUNCTION_CContainerMgr__CloseAllContainers 0x00416A43
EQ_MACRO_FunctionAtAddress(bool EQClass::CContainerMgr::CloseAllContainers(), EQ_ADDRESS_FUNCTION_CContainerMgr__CloseAllContainers);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CContainerMgr__CloseAllContainers)(void* this_ptr);

/* CInvSlot */

class EQClass::CInvSlot
{
public:
    void CInvSlot::HandleRButtonUp(int x, int y);
};

#define EQ_ADDRESS_FUNCTION_CInvSlot__HandleRButtonUp 0x00422804
EQ_MACRO_FunctionAtAddress(void EQClass::CInvSlot::HandleRButtonUp(int x, int y), EQ_ADDRESS_FUNCTION_CInvSlot__HandleRButtonUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CInvSlot__HandleRButtonUp)(void* this_ptr, int x, int y);

/* CInvSlotMgr */

class EQClass::CInvSlotMgr
{
public:
    class CInvSlot* CInvSlotMgr::FindInvSlot(int slotID);
};

#define EQ_ADDRESS_FUNCTION_CInvSlotMgr__FindInvSlot 0x00423010
EQ_MACRO_FunctionAtAddress(class EQClass::CInvSlot* EQClass::CInvSlotMgr::FindInvSlot(int slotID), EQ_ADDRESS_FUNCTION_CInvSlotMgr__FindInvSlot);

/* CBazaarSearchWnd */

class EQClass::CBazaarSearchWnd : public EQClass::CSidlScreenWnd
{
public:
    void CBazaarSearchWnd::Activate();
    void CBazaarSearchWnd::Deactivate();
    void CBazaarSearchWnd::doQuery();
    char* CBazaarSearchWnd::GetPriceString(uint32_t itemValue);
    void CBazaarSearchWnd::HandleBazaarMsg(EQ::CBazaarSearchWndBazaarMessage_ptr message);
    void CBazaarSearchWnd::SortItemList(uint32_t columnIndex); // 1 = Item Name, 2 = Price, 3 = Seller
    void CBazaarSearchWnd::UpdateComboButtons();
    void CBazaarSearchWnd::UpdatePlayerCombo(); // update traders
};

#define EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__GetPriceString 0x0040570E
EQ_MACRO_FunctionAtAddress(char* EQClass::CBazaarSearchWnd::GetPriceString(uint32_t itemValue), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__GetPriceString);

#define EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg 0x004060B5
EQ_MACRO_FunctionAtAddress(void EQClass::CBazaarSearchWnd::HandleBazaarMsg(EQ::CBazaarSearchWndBazaarMessage_ptr message), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__HandleBazaarMsg)(void* this_ptr, EQ::CBazaarSearchWndBazaarMessage_ptr message);

/* CBuffWindow */

class EQClass::CBuffWindow : public EQClass::CSidlScreenWnd
{
public:
    void CBuffWindow::RefreshBuffDisplay();
    void CBuffWindow::OnProcessFrame();
    void CBuffWindow::PostDraw();
};

#define EQ_ADDRESS_FUNCTION_CBuffWindow__SetBuffIcon 0x00409520

#define EQ_ADDRESS_FUNCTION_CBuffWindow__RefreshBuffDisplay 0x00409334
EQ_MACRO_FunctionAtAddress(void EQClass::CBuffWindow::RefreshBuffDisplay(), EQ_ADDRESS_FUNCTION_CBuffWindow__RefreshBuffDisplay);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBuffWindow__RefreshBuffDisplay)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CBuffWindow__RefreshIconArrangement 0x004090E9

#define EQ_ADDRESS_FUNCTION_CBuffWindow__OnProcessFrame 0x00408F9F
EQ_MACRO_FunctionAtAddress(void EQClass::CBuffWindow::OnProcessFrame(), EQ_ADDRESS_FUNCTION_CBuffWindow__OnProcessFrame);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBuffWindow__OnProcessFrame)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CBuffWindow__PostDraw 0x004095FE
EQ_MACRO_FunctionAtAddress(void EQClass::CBuffWindow::PostDraw(), EQ_ADDRESS_FUNCTION_CBuffWindow__PostDraw);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBuffWindow__PostDraw)(void* this_ptr);

/* CGiveWnd */

class EQClass::CGiveWnd : public EQClass::CSidlScreenWnd
{
public:
    //
};

/* CHotButtonWnd */

class EQClass::CHotButtonWnd : public EQClass::CSidlScreenWnd
{
public:
    void CHotButtonWnd::DoHotButton(uint16_t buttonIndex, bool allowAutoRightClick);
};

#define EQ_ADDRESS_FUNCTION_CHotButtonWnd__DoHotButton 0x004209BD
EQ_MACRO_FunctionAtAddress(void EQClass::CHotButtonWnd::DoHotButton(uint16_t buttonIndex, bool allowAutoRightClick), EQ_ADDRESS_FUNCTION_CHotButtonWnd__DoHotButton);

/* CItemDisplayWnd */

class EQClass::CItemDisplayWnd : public EQClass::CSidlScreenWnd
{
public:
    void CItemDisplayWnd::SetItem(EQ::Item_ptr item, bool unknown);
    void CItemDisplayWnd::SetSpell(uint16_t spellID, bool hasDescription, int unknown);
};

#define EQ_ADDRESS_FUNCTION_CItemDisplayWnd__SetItem 0x00423640
EQ_MACRO_FunctionAtAddress(void EQClass::CItemDisplayWnd::SetItem(EQ::Item_ptr item, bool unknown), EQ_ADDRESS_FUNCTION_CItemDisplayWnd__SetItem);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CItemDisplayWnd__SetItem)(void* this_ptr, EQ::Item_ptr item, bool unknown);

#define EQ_ADDRESS_FUNCTION_CItemDisplayWnd__SetSpell 0x00425957
EQ_MACRO_FunctionAtAddress(void EQClass::CItemDisplayWnd::SetSpell(uint16_t spellID, bool hasDescription, int unknown), EQ_ADDRESS_FUNCTION_CItemDisplayWnd__SetSpell);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CItemDisplayWnd__SetSpell)(void* this_ptr, uint16_t spellID, bool hasDescription, int unknown);

/* CLootWnd */

class EQClass::CLootWnd : public EQClass::CSidlScreenWnd
{
public:
    void CLootWnd::Deactivate();
    void CLootWnd::RequestLootSlot(int slotIndex, bool autoLoot);
};

#define EQ_ADDRESS_FUNCTION_CLootWnd__Deactivate 0x0042651F
EQ_MACRO_FunctionAtAddress(void EQClass::CLootWnd::Deactivate(), EQ_ADDRESS_FUNCTION_CLootWnd__Deactivate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CLootWnd__Deactivate)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CLootWnd__RequestLootSlot 0x00426B02
EQ_MACRO_FunctionAtAddress(void EQClass::CLootWnd::RequestLootSlot(int slotIndex, bool autoLoot), EQ_ADDRESS_FUNCTION_CLootWnd__RequestLootSlot);

/* CMerchantWnd */

class EQClass::CMerchantWnd : public EQClass::CSidlScreenWnd
{
public:
    void CMerchantWnd::PostDraw();
};

#define EQ_ADDRESS_FUNCTION_CMerchantWnd__PostDraw 0x004270DC
EQ_MACRO_FunctionAtAddress(void EQClass::CMerchantWnd::PostDraw(), EQ_ADDRESS_FUNCTION_CMerchantWnd__PostDraw);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CMerchantWnd__PostDraw)(void* this_ptr);

/* CSpellBookWnd */

class EQClass::CSpellBookWnd : public EQClass::CSidlScreenWnd
{
public:
    void CSpellBookWnd::Activate();
    char* CSpellBookWnd::UpdateSpellBookDisplay();
    bool CSpellBookWnd::StartSpellMemorization(int spellBookIndex, uint8_t spellGemIndex, bool unknown);
    int CSpellBookWnd::FinishMemorizing(uint8_t spellGemIndex, uint16_t spellID);
    int CSpellBookWnd::GetSpellMemTicksLeft();
    void CSpellBookWnd::TurnToPage(signed int pageNumber);
    void CSpellBookWnd::HandleKeys(uint32_t keyID, bool unknown);
};

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__Activate 0x0043441F
EQ_MACRO_FunctionAtAddress(void EQClass::CSpellBookWnd::Activate(), EQ_ADDRESS_FUNCTION_CSpellBookWnd__Activate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__Activate)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__UpdateSpellBookDisplay 0x004352FF
EQ_MACRO_FunctionAtAddress(char* EQClass::CSpellBookWnd::UpdateSpellBookDisplay(), EQ_ADDRESS_FUNCTION_CSpellBookWnd__UpdateSpellBookDisplay);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__UpdateSpellBookDisplay)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__StartSpellMemorization 0x00434A05
EQ_MACRO_FunctionAtAddress(bool EQClass::CSpellBookWnd::StartSpellMemorization(int spellBookIndex, uint8_t spellGemIndex, bool unknown), EQ_ADDRESS_FUNCTION_CSpellBookWnd__StartSpellMemorization);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__StartSpellMemorization)(void* this_ptr, int spellBookIndex, uint8_t spellGemIndex, bool unknown);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__FinishMemorizing 0x00434B38
EQ_MACRO_FunctionAtAddress(int EQClass::CSpellBookWnd::FinishMemorizing(uint8_t spellGemIndex, uint16_t spellID), EQ_ADDRESS_FUNCTION_CSpellBookWnd__FinishMemorizing);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__FinishMemorizing)(void* this_ptr, uint8_t spellGemIndex, uint16_t spellID);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft 0x00434C05
EQ_MACRO_FunctionAtAddress(int EQClass::CSpellBookWnd::GetSpellMemTicksLeft(), EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__GetSpellMemTicksLeft)(void* this_ptr);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__TurnToPage 0x004352C8
EQ_MACRO_FunctionAtAddress(void EQClass::CSpellBookWnd::TurnToPage(signed int pageNumber), EQ_ADDRESS_FUNCTION_CSpellBookWnd__TurnToPage);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__TurnToPage)(void* this_ptr, signed int pageNumber);

#define EQ_ADDRESS_FUNCTION_CSpellBookWnd__HandleKeys 0x004346AF
EQ_MACRO_FunctionAtAddress(void EQClass::CSpellBookWnd::HandleKeys(uint32_t keyID, bool unknown), EQ_ADDRESS_FUNCTION_CSpellBookWnd__HandleKeys);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__HandleKeys)(void* this_ptr, uint32_t keyID, bool unknown);

/* CTrackingWnd */

class EQClass::CTrackingWnd : public EQClass::CSidlScreenWnd
{
public:
    void CTrackingWnd::Activate();
};

#define EQ_ADDRESS_FUNCTION_CTrackingWnd__Activate 0x004382A1
EQ_MACRO_FunctionAtAddress(void EQClass::CTrackingWnd::Activate(), EQ_ADDRESS_FUNCTION_CTrackingWnd__Activate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CTrackingWnd__Activate)(void* this_ptr);

/* CTradeWnd */

class EQClass::CTradeWnd : public CSidlScreenWnd
{
public:
    void CTradeWnd::Activate(class EQPlayer* player, bool isTargetNPC); // if (isTargetNpc == true) show CGiveWnd instead
};

#define EQ_ADDRESS_FUNCTION_CTradeWnd__Activate 0x004392C9
EQ_MACRO_FunctionAtAddress(void EQClass::CTradeWnd::Activate(class EQPlayer* player, bool isTargetNPC), EQ_ADDRESS_FUNCTION_CTradeWnd__Activate);


