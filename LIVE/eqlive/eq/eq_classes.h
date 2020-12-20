#pragma once

#include "eq_constants.h"
#include "eq_structures.h"
#include "eq_macros.h"
#include "eq_messages.h"
#include "eq_addresses.h"

namespace EQClass
{
    class CEverQuest;
    class CDisplay;

    class EQ_Character;
    class CharacterZoneClient;

    class EQ_PC;

    class EQPlayerManager;
    class EQPlayer;

    class EQSwitchManager;
    class EQSwitch;

    class EQSpell;

    class CXPoint;
    class CXStr;

    class CXWndManager;
    class CXWnd;

    class CAlertWnd;
    class CAlertStackWnd;
    class CBazaarSearchWnd;
    class CBazaarConfirmationWnd;
    class CCharacterListWnd;
    class CConfirmationDialog;
    class CLargeDialogWnd;
    class CMapViewWnd;
    class CSpellBookWnd;
    class CTaskSelectWnd;

    // EQGraphicsDX9.dll
    class CCamera;
    class CRender;
    class CRenderEx;

    class CActorInterface;

    class CVector3; // needed by CastRay2
} // namespace EQClass

//////////////////////////////////////////////////
/* IDirect3DDevice9 */
//////////////////////////////////////////////////

//IDirect3DDevice9** EQ_CLASS_POINTER_IDirect3DDevice9_pptr = NULL;
//IDirect3DDevice9* EQ_CLASS_POINTER_IDirect3DDevice9 = NULL;

uintptr_t* EQ_VTABLE_IDirect3DDevice9 = NULL;

#define EQ_VTABLE_INDEX_IDirect3DDevice9__Reset                   16
#define EQ_VTABLE_INDEX_IDirect3DDevice9__Present                 17
#define EQ_VTABLE_INDEX_IDirect3DDevice9__BeginScene              41
#define EQ_VTABLE_INDEX_IDirect3DDevice9__EndScene                42
#define EQ_VTABLE_INDEX_IDirect3DDevice9__Clear                   43
#define EQ_VTABLE_INDEX_IDirect3DDevice9__SetRenderState          57
#define EQ_VTABLE_INDEX_IDirect3DDevice9__DrawPrimitive           81
#define EQ_VTABLE_INDEX_IDirect3DDevice9__DrawIndexedPrimitive    82
#define EQ_VTABLE_INDEX_IDirect3DDevice9__SetStreamSource         100

// DrawIndexedPrimitive
typedef HRESULT (__stdcall* EQ_FUNCTION_TYPE_IDirect3DDevice9__DrawIndexedPrimitive)
(
    LPDIRECT3DDEVICE9 device,
    D3DPRIMITIVETYPE primitiveType,
    INT baseIndex,
    UINT minIndex,
    UINT numVertices,
    UINT startIndex,
    UINT primitiveCount
);
EQ_FUNCTION_TYPE_IDirect3DDevice9__DrawIndexedPrimitive IDirect3DDevice9__DrawIndexedPrimitive;

//////////////////////////////////////////////////
/* CEverQuest */
//////////////////////////////////////////////////

class EQClass::CEverQuest
{
public:
    char* DoPercentConvert(char* text, bool isOutgoing);
    void InterpretCmd(class EQPlayer* player, const char* text);
    void dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
    void SetGameState(int gameState);
    void LMouseUp(int x, int y);
    void RMouseUp(int x, int y);
    void HandleMouseWheel(signed int delta);
    void SendNewText(int chatType, char* name, char* text, int unknown);
    void DropHeldItemOnGround(int noDrop);
    void RightClickedOnPlayer(uint32_t spawn);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(char* EQClass::CEverQuest::DoPercentConvert(char* text, bool isOutgoing), EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert);
typedef char* (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__DoPercentConvert)(void* this_ptr, char* text, bool isOutgoing);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::InterpretCmd(class EQPlayer* player, const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, class EQPlayer* player, const char* text);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::SetGameState(int gameState), EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__SetGameState)(void* this_ptr, int gameState);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::LMouseUp(int x, int y), EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LMouseUp)(void* this_ptr, int x, int y);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::RMouseUp(int x, int y), EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RMouseUp)(void* this_ptr, int x, int y);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::HandleMouseWheel(signed int delta), EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__HandleMouseWheel)(void* this_ptr, signed int delta);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::SendNewText(int chatType, char* name, char* text, int unknown), EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__SendNewText)(void* this_ptr, int chatType, char* name, char* text, int unknown);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::DropHeldItemOnGround(int NoDrop), EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__DropHeldItemOnGround)(void* this_ptr, int noDrop);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::RightClickedOnPlayer(uint32_t spawn), EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RightClickedOnPlayer)(void* this_ptr, uint32_t spawn);

EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr;
EQClass::CEverQuest* EQ_CLASS_POINTER_CEverQuest;

//////////////////////////////////////////////////
/* CDisplay */
//////////////////////////////////////////////////

class EQClass::CDisplay
{
public:
    static int __cdecl WriteTextHD2(const char* text, int x, int y, signed int color);
    int CreateActor(char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);
    int CreatePlayerActor(uint32_t spawn, int a2, int a3, int a4, int a5, int a6);
    void DeleteActor(uint32_t cactor);
    uint8_t GetIntensity(uint8_t lightType);
    int DeleteLight(uint32_t* lightInterface);
    uint32_t CreateLight(uint8_t lightType, float zero, float y, float x, float z);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQClass::CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__WriteTextHD2)(void* this_ptr, const char* text, int x, int y, signed int color);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CDisplay::CreateActor(char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11), EQ_ADDRESS_FUNCTION_CDisplay__CreateActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreateActor)(void* this_ptr, char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CDisplay::CreatePlayerActor(uint32_t spawn, int a2, int a3, int a4, int a5, int a6), EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)(void* this_ptr, uint32_t spawn, int a2, int a3, int a4, int a5, int a6);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CDisplay::DeleteActor(uint32_t cactor), EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__DeleteActor)(void* this_ptr, uint32_t cactor);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint8_t EQClass::CDisplay::GetIntensity(uint8_t lightType), EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity);
typedef uint8_t (__thiscall* EQ_FUNCTION_TYPE_CDisplay__GetIntensity)(void* this_ptr, uint8_t lightType);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t EQClass::CDisplay::CreateLight(uint8_t lightType, float zero, float y, float x, float z), EQ_ADDRESS_FUNCTION_CDisplay__CreateLight);
typedef uint32_t (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreateLight)(void* this_ptr, uint8_t lightType, float zero, float y, float x, float z);

EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr;
EQClass::CDisplay* EQ_CLASS_POINTER_CDisplay;

//////////////////////////////////////////////////
/* EQ_Character */
//////////////////////////////////////////////////

class EQClass::EQ_Character
{
public:
    float encum_factor();
    int TakeFallDamage(float value);
    bool CanIBreathe();
    int CanISeeInvis();
    void StunMe(uint32_t duration, int unknown1, int unknown2, uint8_t bSpinInCircle); // (x, 0, 0, 0);
    void UnStunMe();
    void ProcessEnvironment();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(float EQClass::EQ_Character::encum_factor(), EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor);
typedef float (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__encum_factor)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQ_Character::TakeFallDamage(float value), EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__TakeFallDamage)(void* this_ptr, float value);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQ_Character::CanIBreathe(), EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe);
typedef bool (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__CanIBreathe)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQ_Character::CanISeeInvis(), EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__CanISeeInvis)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_Character::StunMe(uint32_t duration, int unknown1, int unknown2, uint8_t bSpinInCircle), EQ_ADDRESS_FUNCTION_EQ_Character__StunMe);
typedef void (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__StunMe)(void* this_ptr, uint32_t duration, int unknown1, int unknown2, uint8_t bSpinInCircle);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_Character::UnStunMe(), EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe);
typedef void (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__UnStunMe)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_Character::ProcessEnvironment(), EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment);
typedef void (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__ProcessEnvironment)(void* this_ptr);

EQClass::EQ_Character** EQ_CLASS_POINTER_EQ_Character_pptr;
EQClass::EQ_Character* EQ_CLASS_POINTER_EQ_Character;

//////////////////////////////////////////////////
/* CharacterZoneClient */
//////////////////////////////////////////////////

class EQClass::CharacterZoneClient
{
public:
    void SetNoGrav(int gravityType);
    int TotalSpellAffects(uint32_t spellAffectIndex, int unknown1, int unknown2, int unknown3, int unknown4);  // (x, 1, 0, 1, 1);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CharacterZoneClient::SetNoGrav(int gravityType), EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav);
typedef void (__thiscall* EQ_FUNCTION_TYPE_CharacterZoneClient__SetNoGrav)(void* this_ptr, int gravityType);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CharacterZoneClient::TotalSpellAffects(uint32_t spellAffectIndex, int unknown1, int unknown2, int unknown3, int unknown4), EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CharacterZoneClient__TotalSpellAffects)(void* this_ptr, uint32_t spellAffectIndex, int unknown1, int unknown2, int unknown3, int unknown4);

//////////////////////////////////////////////////
/* EQ_PC */
//////////////////////////////////////////////////

class EQClass::EQ_PC
{
public:
    void DestroyHeldItemOrMoney();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_PC::DestroyHeldItemOrMoney(), EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney);
typedef void (__thiscall* EQ_FUNCTION_TYPE_EQ_PC__DestroyHeldItemOrMoney)(void* this_ptr);

EQClass::EQ_PC** EQ_CLASS_POINTER_EQ_PC_pptr;
EQClass::EQ_PC* EQ_CLASS_POINTER_EQ_PC;

//////////////////////////////////////////////////
/* EQPlayerManager */
//////////////////////////////////////////////////

class EQClass::EQPlayerManager
{
public:
    uint32_t* GetSpawnByID(uint32_t spawnID);
    uint32_t* GetSpawnByName(const char* spawnName);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByID(uint32_t spawnID), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByID)(void* this_ptr, uint32_t spawnID);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByName(const char* spawnName), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByName)(void* this_ptr, const char* spawnName);

EQClass::EQPlayerManager** EQ_CLASS_POINTER_EQPlayerManager_pptr;
EQClass::EQPlayerManager* EQ_CLASS_POINTER_EQPlayerManager;

//////////////////////////////////////////////////
/* EQPlayer */
//////////////////////////////////////////////////

class EQClass::EQPlayer
{
public:
    void ChangeHeight(float height, float a2, float a3, int a4);
    void ChangePosition(uint8_t standingState);
    uint8_t GetLevel();
    uint32_t GetActorClient();
    bool UpdateItemSlot(uint8_t updateItemSlot, int itemDefinition, bool b1, bool serverSide, bool b3);
    bool IsTargetable();
    int SetNameSpriteState(bool isNameVisible);
    bool SetNameSpriteTint();
    void ChangeLight();
    uint32_t GetPlayerPhysicsClient();
    int push_along_heading(float speed);
    void Unknown();
    bool AllowedToAttack(uint32_t spawn, uint32_t spellID);
};

#define EQ_VFTABLE_INDEX_EQPlayer__Unknown                   0x60    // Dismount
#define EQ_VFTABLE_INDEX_EQPlayer__GetPlayerPhysicsClient    0x78

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::ChangeHeight(float height, float a2, float a3, int a4), EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangeHeight)(void* this_ptr, float height, float a2, float a3, int a4);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::ChangePosition(uint8_t standingState), EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangePosition)(void* this_ptr, uint8_t standingState);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint8_t EQClass::EQPlayer::GetLevel(), EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t EQClass::EQPlayer::GetActorClient(), EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::UpdateItemSlot(uint8_t updateItemSlot, int itemDefinition, bool b1, bool serverSide, bool b3), EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);
typedef bool (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__UpdateItemSlot)(void* this_ptr, uint8_t updateItemSlot, int itemDefinition, bool b1, bool serverSide, bool b3);

// IsTargetable

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQPlayer::SetNameSpriteState(bool isNameVisible), EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__SetNameSpriteState)(void* this_ptr, bool isNameVisible);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::SetNameSpriteTint(), EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint);
typedef bool (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__SetNameSpriteTint)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::ChangeLight(), EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangeLight)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t EQClass::EQPlayer::GetPlayerPhysicsClient(), EQ_VFTABLE_INDEX_EQPlayer__GetPlayerPhysicsClient);
typedef uint32_t (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__GetPlayerPhysicsClient)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQPlayer::push_along_heading(float speed), EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__push_along_heading)(void* this_ptr, float speed);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::EQPlayer::Unknown(), EQ_VFTABLE_INDEX_EQPlayer__Unknown);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__Unknown)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::AllowedToAttack(uint32_t spawn, uint32_t spellID), EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack);
typedef bool (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__AllowedToAttack)(void* this_ptr, uint32_t spawn, uint32_t spellID);

//////////////////////////////////////////////////
/* EQSwitchManager */
//////////////////////////////////////////////////

class EQClass::EQSwitchManager
{
public:
    //
};

//

EQClass::EQSwitchManager** EQ_CLASS_POINTER_EQSwitchManager_pptr;
EQClass::EQSwitchManager* EQ_CLASS_POINTER_EQSwitchManager;

//////////////////////////////////////////////////
/* EQSwitch */
//////////////////////////////////////////////////

class EQClass::EQSwitch
{
public:
    void UseSwitch(uint32_t spawnID, uint32_t keyID, uint32_t pickSkill, const void* hitLocation = 0);
    void ChangeState(uint8_t state, int zero1, int zero2);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQSwitch::UseSwitch(uint32_t spawnID, uint32_t keyID, uint32_t pickSkill, const void* hitLocation), EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQSwitch::ChangeState(uint8_t state, int zero1, int zero2), EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState);

//////////////////////////////////////////////////
/* EQSpell */
//////////////////////////////////////////////////

class EQClass::EQSpell
{
public:
    int SpellAffects(uint32_t spellAffectIndex);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQSpell::SpellAffects(uint32_t spellAffectIndex), EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQSpell__SpellAffects)(void* this_ptr, uint32_t spellAffectIndex);

//////////////////////////////////////////////////
/* CXPoint */
//////////////////////////////////////////////////

class EQClass::CXPoint
{
public:
    class CXPoint operator=(class CXPoint);

    uint32_t X;
    uint32_t Y;
};

//////////////////////////////////////////////////
/* CStrPtr */
//////////////////////////////////////////////////

struct CStrPtr
{
    int RefCount;
    long MaxLength;
    long Length;
    int Encoding;
    void *Buff;
    union
    {
        char Ansi[1000];
        wchar_t Unicode[500];
        CStrPtr* pNext;
    };
};

//////////////////////////////////////////////////
/* CXStr */
//////////////////////////////////////////////////

class EQClass::CXStr
{
public:
    CXStr(char const *);

    CStrPtr* ptr;
};

// CXStr(const char*) constructor
EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXStr::CXStr(char const *), EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p);

//////////////////////////////////////////////////
/* CXWndManager */
//////////////////////////////////////////////////

class EQClass::CXWndManager
{
public:
    int DrawCursor();
    int DrawWindows();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWndManager::DrawCursor(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawCursor)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWndManager::DrawWindows(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawWindows)(void* this_ptr);

EQClass::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr;
EQClass::CXWndManager* EQ_CLASS_POINTER_CXWndManager;

//////////////////////////////////////////////////
/* CXWnd */
//////////////////////////////////////////////////

class EQClass::CXWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void Activate();
    void Deactivate();
    bool IsReallyVisible();
    EQClass::CXWnd* GetChildItem(const EQClass::CXStr& name);
};

#define EQ_VFTABLE_INDEX_CXWnd__WndNotification       0x88
#define EQ_VFTABLE_INDEX_CXWnd__Activate              0x90 // show window
#define EQ_VFTABLE_INDEX_CXWnd__Deactivate            0x94 // hide window

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CXWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CXWnd::Activate(), EQ_VFTABLE_INDEX_CXWnd__Activate);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CXWnd::Deactivate(), EQ_VFTABLE_INDEX_CXWnd__Deactivate);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CXWnd::IsReallyVisible(), EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible);

EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXWnd* EQClass::CXWnd::GetChildItem(const EQClass::CXStr& name), EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem);

//////////////////////////////////////////////////
/* CAlertWnd */
//////////////////////////////////////////////////

class EQClass::CAlertWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CAlertWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CAlertWnd** EQ_CLASS_POINTER_CAlertWnd_pptr;
EQClass::CAlertWnd* EQ_CLASS_POINTER_CAlertWnd;

//////////////////////////////////////////////////
/* CAlertStackWnd */
//////////////////////////////////////////////////

class EQClass::CAlertStackWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void Deactivate();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CAlertStackWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CAlertStackWnd::Deactivate(), EQ_VFTABLE_INDEX_CXWnd__Deactivate);

EQClass::CAlertStackWnd** EQ_CLASS_POINTER_CAlertStackWnd_pptr;
EQClass::CAlertStackWnd* EQ_CLASS_POINTER_CAlertStackWnd;

//////////////////////////////////////////////////
/* CBazaarSearchWnd */
//////////////////////////////////////////////////

class EQClass::CBazaarSearchWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, uint32_t itemIconID, uint32_t itemID, void* a9, int a10, void* a11);
    void doQuery();
    bool BuyItem(int quantity);
    void FindItem(char* itemName);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CBazaarSearchWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, uint32_t itemIconID, uint32_t itemID, void* a9, int a10, void* a11), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__AddItemToList)(void* this_ptr, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, uint32_t itemIconID, uint32_t itemID, void* a9, int a10, void* a11);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::doQuery(), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__doQuery)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CBazaarSearchWnd::BuyItem(int quantity), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__BuyItem)(void* this_ptr, int quantity);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::FindItem(char* itemName), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__FindItem)(void* this_ptr, char* itemName);

EQClass::CBazaarSearchWnd** EQ_CLASS_POINTER_CBazaarSearchWnd_pptr;
EQClass::CBazaarSearchWnd* EQ_CLASS_POINTER_CBazaarSearchWnd;

//////////////////////////////////////////////////
/* CBazaarConfirmationWnd */
//////////////////////////////////////////////////

class EQClass::CBazaarConfirmationWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CBazaarConfirmationWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CBazaarConfirmationWnd** EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr;
EQClass::CBazaarConfirmationWnd* EQ_CLASS_POINTER_CBazaarConfirmationWnd;

//////////////////////////////////////////////////
/* CMapViewWnd */
//////////////////////////////////////////////////

class EQClass::CMapViewWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CMapViewWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CMapViewWnd** EQ_CLASS_POINTER_CMapViewWnd_pptr;
EQClass::CMapViewWnd* EQ_CLASS_POINTER_CMapViewWnd;

//////////////////////////////////////////////////
/* CSpellBookWnd */
//////////////////////////////////////////////////

class EQClass::CSpellBookWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    int GetSpellMemTicksLeft();
    int GetSpellScribeTicksLeft();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CSpellBookWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CSpellBookWnd::GetSpellMemTicksLeft(), EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__GetSpellMemTicksLeft)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CSpellBookWnd::GetSpellScribeTicksLeft(), EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CSpellBookWnd__GetSpellScribeTicksLeft)(void* this_ptr);

EQClass::CSpellBookWnd** EQ_CLASS_POINTER_CSpellBookWnd_pptr;
EQClass::CSpellBookWnd* EQ_CLASS_POINTER_CSpellBookWnd;

//////////////////////////////////////////////////
/* CTaskSelectWnd */
//////////////////////////////////////////////////

class EQClass::CTaskSelectWnd
{
public:
    int WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CTaskSelectWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CTaskSelectWnd** EQ_CLASS_POINTER_CTaskSelectWnd_pptr;
EQClass::CTaskSelectWnd* EQ_CLASS_POINTER_CTaskSelectWnd;

//////////////////////////////////////////////////
/* CCamera */
//////////////////////////////////////////////////

class EQClass::CCamera
{
public:
    int SetCameraLocation(EQ::Location& location, bool canSetLocation);
    bool WorldSpaceToScreenSpace(EQ::Location& location, float& screenX, float& screenY);
};

#define EQ_VFTABLE_INDEX_CCamera__SetCameraLocation          0x38
#define EQ_VFTABLE_INDEX_CCamera__WorldSpaceToScreenSpace    0x74

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CCamera::SetCameraLocation(EQ::Location& location, bool canSetLocation), EQ_VFTABLE_INDEX_CCamera__SetCameraLocation);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CCamera__SetCameraLocation)(void* this_ptr, EQ::Location& location, bool canSetLocation);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CCamera::WorldSpaceToScreenSpace(EQ::Location& location, float& screenX, float& screenY), EQ_VFTABLE_INDEX_CCamera__WorldSpaceToScreenSpace);

// calculated at run time
EQClass::CCamera** EQ_CLASS_POINTER_CCamera_pptr;
EQClass::CCamera* EQ_CLASS_POINTER_CCamera;

//////////////////////////////////////////////////
/* CRender */
//////////////////////////////////////////////////

class EQClass::CRender
{
public:
    bool ResetDevice(bool unknown);
    bool DrawLine(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB);
    bool DrawLineEx(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB); // TODO: figure this out
    bool DrawWrappedText(uint32_t fontStyle, const char* text, EQ::CXRect& cxrect1, EQ::CXRect& cxrect2, uint32_t colorARGB, uint16_t flags, int startX);
    bool DrawColoredRectangle(EQ::Rectangle& rectangle, uint32_t colorARGB);
    void ClearRenderToBlack();
    void RenderPartialScene();
    void Render0xB0();
    void UpdateDisplay();
    void TakeScreenshot(const char* fileName);
};

#define EQ_VFTABLE_INDEX_CRender__InitDevice              0x5C
#define EQ_VFTABLE_INDEX_CRender__ResetDevice             0x64    // "ResetDevice() failed!"
#define EQ_VFTABLE_INDEX_CRender__DrawLine                0x88
#define EQ_VFTABLE_INDEX_CRender__DrawLineEx              0x8C
#define EQ_VFTABLE_INDEX_CRender__DrawWrappedText         0x94
#define EQ_VFTABLE_INDEX_CRender__DrawColoredRectangle    0xA0    // "*ScreenShot.jpg"
#define EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack      0xA8
#define EQ_VFTABLE_INDEX_CRender__RenderPartialScene      0xAC
#define EQ_VFTABLE_INDEX_CRender__Render0xB0              0xB0    // does something, called after ClearRenderToBlack() while blind
#define EQ_VFTABLE_INDEX_CRender__UpdateDisplay           0xB4
#define EQ_VFTABLE_INDEX_CRender__TakeScreenshot          0xC4

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::ResetDevice(bool unknown), EQ_VFTABLE_INDEX_CRender__ResetDevice);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__ResetDevice)(void* this_ptr, bool unknown);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawLine(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB), EQ_VFTABLE_INDEX_CRender__DrawLine);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawLineEx(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEn, uint32_t colorARGB), EQ_VFTABLE_INDEX_CRender__DrawLineEx);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__DrawLineEx)(void* this_ptr, EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawWrappedText(uint32_t fontStyle, const char* text, EQ::CXRect& cxrect1, EQ::CXRect& cxrect2, uint32_t colorARGB, uint16_t flags, int startX), EQ_VFTABLE_INDEX_CRender__DrawWrappedText);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawColoredRectangle(EQ::Rectangle& rectangle, uint32_t colorARGB), EQ_VFTABLE_INDEX_CRender__DrawColoredRectangle);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::ClearRenderToBlack(), EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__ClearRenderToBlack)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::RenderPartialScene(), EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__RenderPartialScene)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::Render0xB0(), EQ_VFTABLE_INDEX_CRender__Render0xB0);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__Render0xB0)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::UpdateDisplay(), EQ_VFTABLE_INDEX_CRender__UpdateDisplay);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__UpdateDisplay)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::TakeScreenshot(const char* fileName), EQ_VFTABLE_INDEX_CRender__TakeScreenshot);

EQClass::CRender** EQ_CLASS_POINTER_CRender_pptr;
EQClass::CRender* EQ_CLASS_POINTER_CRender;

//////////////////////////////////////////////////
/* CRenderEx */
//////////////////////////////////////////////////

class EQClass::CRenderEx
{
public:
    void SetAreaWireframeDrawing(bool bEnabled);
    bool IsAreaWireframeDrawingEnabled();
};

#define EQ_VFTABLE_INDEX_CRenderEx__SetAreaWireframeDrawing          0x44
#define EQ_VFTABLE_INDEX_CRenderEx__IsAreaWireframeDrawingEnabled    0x48

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRenderEx::SetAreaWireframeDrawing(bool bEnabled), EQ_VFTABLE_INDEX_CRenderEx__SetAreaWireframeDrawing);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRenderEx__SetAreaWireframeDrawing)(void* this_ptr, bool bEnabled);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRenderEx::IsAreaWireframeDrawingEnabled(), EQ_VFTABLE_INDEX_CRenderEx__IsAreaWireframeDrawingEnabled);
typedef bool (__thiscall* EQ_FUNCTION_TYPE_CRenderEx__IsAreaWireframeDrawingEnabled)(void* this_ptr);

EQClass::CRenderEx** EQ_CLASS_POINTER_CRenderEx_pptr;
EQClass::CRenderEx* EQ_CLASS_POINTER_CRenderEx;

//////////////////////////////////////////////////
/* CVector3 */
//////////////////////////////////////////////////

class EQClass::CVector3
{
public:
    float X;
    float Y;
    float Z;

    float NormalizeAndReturnLength(void);
    void Normalize(void);

    void Set(float x, float y, float z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    inline CVector3& operator-=(const CVector3& vec)
    {
        X -= vec.X;
        Y -= vec.Y;
        Z -= vec.Z;

        return *this;
    }

    inline CVector3& operator+=(const CVector3& vec)
    {
        X += vec.X;
        Y += vec.Y;
        Z += vec.Z;

        return *this;
    }

    inline void Scale(float value)
    {
        X *= value;
        Y *= value;
        Z *= value;
    }

    inline CVector3 operator*(float value) const
    {
        CVector3 vector(*this);
        vector.Scale(value);
        return vector;
    }

    void SetMax()
    {
        X = Y = Z = 3.402823466e+38F;
    }

    float GetLengthSquared() const
    {
        return ((X * X) + (Y * Y) + (Z * Z));
    }

    float GetLength() const
    { 
        return std::sqrtf(GetLengthSquared());
    }

    CVector3 operator-() const
    {
        CVector3 vector;
        vector.Set(-X, -Y, -Z);
        return vector;
    }

    CVector3 operator-(const CVector3& vector) const
    {
        CVector3 result;
        result.Set(X - vector.X, Y - vector.Y, Z - vector.Z);
        return result;
    }

    CVector3 operator+(const CVector3& vector) const
    {
        CVector3 result;
        result.Set(vector.X + X, vector.Y + Y, vector.Z + Z);
        return result;
    }

    float GetDistanceSquared(const CVector3& vector) const
    {
        CVector3 result = *this - vector;
        return result.GetLengthSquared();
    }
};

//////////////////////////////////////////////////
/* CProfileManager */
//////////////////////////////////////////////////

enum eProfileListType
{
    ePLT_Regular,
    cPLT_MonsterMission
};

class ProfileList
{
    // has no vftable
public:
/*0x00*/    eProfileListType ListType;
/*0x04*/    uint32_t* pFirst;
/*0x08*/    uint32_t* pLast;
/*0x0c*/    ProfileList* pNext;
/*0x10*/    ProfileList* pPrev;
/*0x14*/
};

class CProfileManager
{
    //has no vftable
public:
/*0x00*/    ProfileList* pFirst;
/*0x04*/    eProfileListType CurProfileList;
/*0x08*/

    inline const ProfileList* GetCurrentProfileList() const
    {
        ProfileList *pWalk = pFirst;
        while ( pWalk != NULL ) {
            if ( pWalk->ListType == CurProfileList )
            {
                return pWalk;
            }
            pWalk = pWalk->pNext;
        }
        return NULL;
    }

    inline const uint32_t* GetCurrentProfile() const
    {
        const ProfileList *pList = GetCurrentProfileList();
        if ( pList != NULL )
        {
            return pList->pFirst;
        }
        return NULL;
    }
};

//////////////////////////////////////////////////
/* CActorInterface */
//////////////////////////////////////////////////

// EQData::_SPAWNINFO::mActorClient->pcactorex
class EQClass::CActorInterface
{
public:
    bool CanSetName(uint32_t zero);
    void SetNameColor(uint32_t& colorARGB);
    void ChangeBoneStringSprite(int, int, char* text);
};

#define EQ_VFTABLE_INDEX_CActorInterface__CanSetName                0x1A8    // 424 dec
#define EQ_VFTABLE_INDEX_CActorInterface__SetNameColor              0x194    // 404 dec
#define EQ_VFTABLE_INDEX_CActorInterface__ChangeBoneStringSprite    0x190    // 400 dec

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CActorInterface::CanSetName(uint32_t zero), EQ_VFTABLE_INDEX_CActorInterface__CanSetName);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CActorInterface::SetNameColor(uint32_t& colorARGB), EQ_VFTABLE_INDEX_CActorInterface__SetNameColor);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CActorInterface::ChangeBoneStringSprite(int, int, char* text), EQ_VFTABLE_INDEX_CActorInterface__ChangeBoneStringSprite);

//////////////////////////////////////////////////
/* CCollisionCallbackForActors */
//////////////////////////////////////////////////

// these classes are unknown and used in the game's CollisionCallbackForActors() function
// we use them to disable collision with players in the eqapp_actorcollision.h header

class CCollisionCallbackForActors1
{
public:
    uint32_t Call_0x20();
    uint32_t Call_0x30();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors1::Call_0x20(), 0x20);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors1::Call_0x30(), 0x30);

class CCollisionCallbackForActors2
{
public:
    uint32_t Call_0x0C();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors2::Call_0x0C(), 0x0C);

class CCollisionCallbackForActors3
{
public:
    uint32_t Call_0x44();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors3::Call_0x44(), 0x44);
