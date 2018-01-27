#pragma once

#include "eq.h"
#include "eq_macros.h"

namespace EQClass
{
    class EQPlayerManager;
    class EQPlayer;
    class EQ_Character;

    class CXWndManager;

    class CEverQuest;
    class CDisplay;
} // namespace EQClass

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

/* EQ_Character */

class EQClass::EQ_Character
{
public:
    void EQ_Character::eqspa_movement_rate(int movementSpeed);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_Character::eqspa_movement_rate(int movementSpeed), EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)(void* this_ptr, int movementSpeed);

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

/* CEverQuest */

class EQClass::CEverQuest
{
public:
    void CEverQuest::InterpretCmd(class EQPlayer* player, const char* text);
    void CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
};

////EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
////#define EQ_CLASS_POINTER_CEverQuest (*EQ_CLASS_POINTER_CEverQuest_pptr)
EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr;
EQClass::CEverQuest* EQ_CLASS_POINTER_CEverQuest;

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::InterpretCmd(class EQPlayer* player, const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, class EQPlayer* player, const char* text);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);

/* CDisplay */

class EQClass::CDisplay
{
public:
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color);
};

////EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
////#define EQ_CLASS_POINTER_CDisplay (*EQ_CLASS_POINTER_CDisplay_pptr)
EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr;
EQClass::CDisplay* EQ_CLASS_POINTER_CDisplay;

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQClass::CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__WriteTextHD2)(void* this_ptr, const char* text, int x, int y, signed int color);
