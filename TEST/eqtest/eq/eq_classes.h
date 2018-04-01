#pragma once

#include "eq.h"
#include "eq_macros.h"

namespace EQClass
{
    class CEverQuest;
    class CDisplay;

    class EQPlayerManager;
    class EQPlayer;

    class CXWndManager;

    class CBazaarSearchWnd;
    class CBazaarConfirmationWnd;
    class CBazaarWnd;
} // namespace EQClass

/* CEverQuest */

class EQClass::CEverQuest
{
public:
    void CEverQuest::InterpretCmd(class EQPlayer* player, const char* text);
    void CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
    void CEverQuest::StartCasting(EQMessage::CEverQuest__StartCasting_ptr message);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::InterpretCmd(class EQPlayer* player, const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, class EQPlayer* player, const char* text);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::StartCasting(EQMessage::CEverQuest__StartCasting_ptr message), EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__StartCasting)(void* this_ptr, EQMessage::CEverQuest__StartCasting_ptr message);

////EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
////#define EQ_CLASS_POINTER_CEverQuest (*EQ_CLASS_POINTER_CEverQuest_pptr)
EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr;
EQClass::CEverQuest* EQ_CLASS_POINTER_CEverQuest;

/* CDisplay */

class EQClass::CDisplay
{
public:
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQClass::CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__WriteTextHD2)(void* this_ptr, const char* text, int x, int y, signed int color);

////EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
////#define EQ_CLASS_POINTER_CDisplay (*EQ_CLASS_POINTER_CDisplay_pptr)
EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr;
EQClass::CDisplay* EQ_CLASS_POINTER_CDisplay;

/* EQPlayerManager */

class EQClass::EQPlayerManager
{
public:
    uint32_t* EQPlayerManager::GetSpawnByID(uint32_t spawnID);
    uint32_t* EQPlayerManager::GetSpawnByName(const char* spawnName);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByID(uint32_t spawnID), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByID)(void* this_ptr, uint32_t spawnID);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByName(const char* spawnName), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByName)(void* this_ptr, const char* spawnName);

////EQClass::EQPlayerManager** EQ_CLASS_POINTER_EQPlayerManager_pptr = (EQClass::EQPlayerManager**)EQ_ADDRESS_POINTER_EQPlayerManager;
////#define EQ_CLASS_POINTER_EQPlayerManager (*EQ_CLASS_POINTER_EQPlayerManager_pptr)
EQClass::EQPlayerManager** EQ_CLASS_POINTER_EQPlayerManager_pptr;
EQClass::EQPlayerManager* EQ_CLASS_POINTER_EQPlayerManager;

/* EQPlayer */

class EQClass::EQPlayer
{
public:
    void EQPlayer::FollowPlayerAI();
    void EQPlayer::ChangeHeight(float height, float a2, float a3, int a4);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::FollowPlayerAI(), EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__FollowPlayerAI)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::ChangeHeight(float height, float a2, float a3, int a4), EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangeHeight)(void* this_ptr, float height, float a2, float a3, int a4);

/* CXWndManager */

class EQClass::CXWndManager
{
public:
    int CXWndManager::DrawWindows();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWndManager::DrawWindows(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawWindows)(void* this_ptr);

////EQClass::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
////#define EQ_CLASS_POINTER_CXWndManager (*EQ_CLASS_POINTER_CXWndManager_pptr)
EQClass::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr;
EQClass::CXWndManager* EQ_CLASS_POINTER_CXWndManager;

/* CBazaarSearchWnd */

class EQClass::CBazaarSearchWnd
{
public:
    int CBazaarSearchWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);
    void CBazaarSearchWnd::AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);
    void CBazaarSearchWnd::doQuery();
    bool CBazaarSearchWnd::BuyItem(int quantity);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CBazaarSearchWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__WndNotification);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__WndNotification)(void* this_ptr, uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__AddItemToList)(void* this_ptr, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::doQuery(), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__doQuery)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CBazaarSearchWnd::BuyItem(int quantity), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__BuyItem)(void* this_ptr, int quantity);

////EQClass::CBazaarSearchWnd** EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
////#define EQ_CLASS_POINTER_CBazaarSearchWnd (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr)
EQClass::CBazaarSearchWnd** EQ_CLASS_POINTER_CBazaarSearchWnd_pptr;
EQClass::CBazaarSearchWnd* EQ_CLASS_POINTER_CBazaarSearchWnd;

/* CBazaarConfirmationWnd */

class EQClass::CBazaarConfirmationWnd
{
public:
    int CBazaarConfirmationWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CBazaarConfirmationWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown), EQ_ADDRESS_FUNCTION_CBazaarConfirmationWnd__WndNotification);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarConfirmationWnd__WndNotification)(void* this_ptr, uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);

////EQClass::CBazaarConfirmationWnd** EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr = (EQClass::CBazaarConfirmationWnd**)EQ_ADDRESS_POINTER_CBazaarConfirmationWnd;
////#define EQ_CLASS_POINTER_CBazaarConfirmationWnd (*EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr)
EQClass::CBazaarConfirmationWnd** EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr;
EQClass::CBazaarConfirmationWnd* EQ_CLASS_POINTER_CBazaarConfirmationWnd;

/* CBazaarWnd */

class EQClass::CBazaarWnd
{
public:
    int CBazaarWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CBazaarWnd::WndNotification(uint32_t xwndAddress, uint32_t xwndMessage, void* unknown), EQ_ADDRESS_FUNCTION_CBazaarWnd__WndNotification);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarWnd__WndNotification)(void* this_ptr, uint32_t xwndAddress, uint32_t xwndMessage, void* unknown);

////EQClass::CBazaarWnd** EQ_CLASS_POINTER_CBazaarWnd_pptr = (EQClass::CBazaarWnd**)EQ_ADDRESS_POINTER_CBazaarWnd;
////#define EQ_CLASS_POINTER_CBazaarWnd (*EQ_CLASS_POINTER_CBazaarWnd_pptr)
EQClass::CBazaarWnd** EQ_CLASS_POINTER_CBazaarWnd_pptr;
EQClass::CBazaarWnd* EQ_CLASS_POINTER_CBazaarWnd;
