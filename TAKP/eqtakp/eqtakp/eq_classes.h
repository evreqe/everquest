#pragma once

#include "eq.h"
#include "eq_macros.h"

namespace EQClasses
{
    class StringTable;

    class EQ_Guilds;

    class CXStr;
    class CSidlScreenWnd;
    class CXWndManager;
    class CXWnd;
    class CXPoint;
    class CXRect;

    class CButtonWnd;
    class CDisplay;
    class CEverQuest;
    class CHotButtonWnd;
    class CLootWnd;
    class CTextEntryWnd;
    class CTextOverlay;
    class EQPlayer;
    class EQPlayerManager;
    class EQSwitch;
    class EQ_Character;
}

/* CXStr */

class CXStr
{
public:
    CXStr::~CXStr(void);
    CXStr::CXStr(char const *);
    void CXStr::operator+=(char const *);
    void CXStr::operator=(char const *);
    class CXStr& CXStr::operator=(class CXStr const&);
};

/* CXWndManager */

class EQClasses::CXWndManager
{
public:
    int CXWndManager::DrawCursor(void) const;
    int CXWndManager::DrawWindows(void) const;
};

#define EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor 0x0059E320
EQ_MACRO_FunctionAtAddress(int EQClasses::CXWndManager::DrawCursor(void) const, EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor);

#define EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows 0x0059E000
EQ_MACRO_FunctionAtAddress(int EQClasses::CXWndManager::DrawWindows(void) const, EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

/* CDisplay */

class EQClasses::CDisplay
{
public:
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, int textColor, int font);
};

#define EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 0x004AA5AA
EQ_MACRO_FunctionAtAddress(int EQClasses::CDisplay::WriteTextHD2(const char* text, int x, int y, int textColor, int font), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

/* CEverQuest */

class EQClasses::CEverQuest
{
public:
    void CEverQuest::dsp_chat(const char* text, short textColor, bool filtered);
    void CEverQuest::dsp_chat(const char* text);
};

#define EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat 0x00537F99
EQ_MACRO_FunctionAtAddress(void EQClasses::CEverQuest::dsp_chat(const char* text, short textColor, bool filtered), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, short textColor, bool filtered);

#define EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat__2 0x005380FD
EQ_MACRO_FunctionAtAddress(void EQClasses::CEverQuest::dsp_chat(const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat__2);

/* EQ_Player */

class EQClasses::EQPlayer
{
public:
    void EQPlayer::ChangeHeight(float height);
    void EQPlayer::ChangePosition(unsigned char standingState);
    void EQPlayer::FacePlayer(class EQPlayer* spawn);
};

/* EQ_Character */

class EQClasses::EQ_Character
{
public:
    unsigned short EQ_Character::Max_Mana(void);
    void EQ_Character::eqspa_movement_rate(short unknown);
    int EQ_Character::CastSpell(unsigned char gemIndex, short spellID, EQ::Item** item, short unknown);
    int EQ_Character::StopSpellCast(unsigned char gemIndex);
    int EQ_Character::StopSpellCast(unsigned char gemIndex, short spellID);
    int EQ_Character::UseSkill(unsigned char skill, class EQPlayer* targetSpawn);
};

#define EQ_ADDRESS_FUNCTION_EQ_Character__Max_Mana 0x004B9483
EQ_MACRO_FunctionAtAddress(unsigned short EQClasses::EQ_Character::Max_Mana(void), EQ_ADDRESS_FUNCTION_EQ_Character__Max_Mana);

#define EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate 0x004CAABA
EQ_MACRO_FunctionAtAddress(void EQClasses::EQ_Character::eqspa_movement_rate(short), EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)(void* this_ptr, short unknown);

/* Direct Input */

//IDirectInput8** EQ_POINTER_ppIDirectInput8 = (IDirectInput8**)EQ_DINPUT_ROOT;
//#define EQ_POINTER_IDirectInput8 (*EQ_POINTER_ppIDirectInput8)

//IDirectInputDevice8** EQ_POINTER_ppIDirectInputDevice8_Keyboard = (IDirectInputDevice8**)EQ_DINPUT_DEVICE_KEYBOARD;
//#define EQ_POINTER_IDirectInputDevice8_Keyboard (*EQ_POINTER_ppIDirectInputDevice8_Keyboard)

//IDirectInputDevice8** EQ_POINTER_ppIDirectInputDevice8_Mouse = (IDirectInputDevice8**)EQ_DINPUT_DEVICE_MOUSE;
//#define EQ_POINTER_IDirectInputDevice8_Mouse (*EQ_POINTER_ppIDirectInputDevice8_Mouse)

