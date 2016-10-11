#pragma once

#include <string>
#include <map>

#include <cstdint>
#include <cstring>
#include <cmath>

#include <windows.h>

#include "eq.h"

#define EQ_FUNCTION_AT_ADDRESS(function,offset) __declspec(naked) function\
{\
    __asm{mov eax, offset};\
    __asm{jmp eax};\
}

#define EQ_FUNCTION_AT_VARIABLE_ADDRESS(function,variable) __declspec(naked) function\
{\
    __asm{mov eax, [variable]};\
    __asm{jmp eax};\
}

#define EQ_FUNCTION_AT_VIRTUAL_ADDRESS(function,virtualoffset) __declspec(naked) function\
{\
    __asm{mov eax, [ecx]};\
    __asm{lea eax, [eax+virtualoffset]};\
    __asm{mov eax, [eax]};\
    __asm{jmp eax};\
}

template <class T>
void EQ_Log(const char* text, T number)
{
    std::fstream file;
    file.open("Logs/eqlog.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

template <class T>
T EQ_ReadMemory(DWORD address)
{
#ifdef _DEBUG
    EQ_Log("EQ_ReadMemory address: ", address);
#endif

    T* buffer = (T*)address;
    return (*buffer);
}

template <class T>
void EQ_WriteMemory(DWORD address, T value)
{
#ifdef _DEBUG
    EQ_Log("EQ_WriteMemory address: ", address);
#endif

    T* buffer = (T*)address;
    *buffer = value;
}

template <class T>
T EQ_ReadMemoryProtected(DWORD address)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), PAGE_READWRITE, &oldProtect);

    T* buffer = (T*)address;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), oldProtect, &oldProtect);

    return (*buffer);
}

template <class T>
void EQ_WriteMemoryProtected(DWORD address, T value)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), PAGE_READWRITE, &oldProtect);

    T* buffer = (T*)address;
    *buffer = value;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), oldProtect, &oldProtect);
}

// direct input

//IDirectInput8** EQ_ppIDirectInput8 = (IDirectInput8**)EQ_DINPUT_ROOT;
//#define EQ_IDirectInput8 (*EQ_ppIDirectInput8)

//IDirectInputDevice8** EQ_ppIDirectInputDevice8_Keyboard = (IDirectInputDevice8**)EQ_DINPUT_DEVICE_KEYBOARD;
//#define EQ_IDirectInputDevice8_Keyboard (*EQ_ppIDirectInputDevice8_Keyboard)

//IDirectInputDevice8** EQ_ppIDirectInputDevice8_Mouse = (IDirectInputDevice8**)EQ_DINPUT_DEVICE_MOUSE;
//#define EQ_IDirectInputDevice8_Mouse (*EQ_ppIDirectInputDevice8_Mouse)

class EQGraphicsDLL;
class EQ_Guilds;

class CXStr;
class CSidlScreenWnd;
class CXWndManager;
class CXWnd;
class CXPoint;
class CXRect;

class StringTable;

class CDisplay;
class CEverQuest;
class CHotButtonWnd;
class CLootWnd;
class CMapViewWnd;
class CTextEntryWnd;
class CTextOverlay;
class EQPlayer;
class EQPlayerManager;
class EQSwitch;
class EQ_Character;
class MapViewMap;

class EQGraphicsDLL
{
public:
    int EQGraphicsDLL::DrawLine(EQ::Line* lineBegin, EQ::Line* lineEnd, uint32_t colorARGB);
    int EQGraphicsDLL::DrawQuad(EQ::Rect* rect, uint32_t colorARGB);
};

EQGraphicsDLL** EQ_ppEQGraphicsDLL = (EQGraphicsDLL**)EQ_POINTER_EQGraphicsDLL;
#define EQ_EQGraphicsDLL (*EQ_ppEQGraphicsDLL)

class EQ_Guilds
{
public:
    char* EQ_Guilds::GetGuildNameById(uint32_t id);
};

EQ_Guilds* EQ_ppEQ_Guilds = (EQ_Guilds*)EQ_GUILDS;
#define EQ_EQ_Guilds (*EQ_ppEQ_Guilds)

class CXStr
{
public:
    CXStr::~CXStr(void);
    CXStr::CXStr(char const *);
    void CXStr::operator+=(char const *);
    void CXStr::operator=(char const *);
    class CXStr& CXStr::operator=(class CXStr const&);
};

class CSidlScreenWnd
{
public:
    //
};

class StringTable
{
public:
    char* StringTable::getString(unsigned long index, bool* a2);
};

StringTable** EQ_ppStringTable = (StringTable**)EQ_POINTER_StringTable;
#define EQ_StringTable (*EQ_ppStringTable)

class CDisplay
{
public:
    void CDisplay::CreatePlayerActor(uint32_t spawnInfo, int a2, int a3, int a4, int a5);
    void CDisplay::DeleteActor(uint32_t actorInstance);
    void CDisplay::SetViewActor(uint32_t actorInstance);
    void CDisplay::SetViewActorByName(const char* spawnName);
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, int color);
};

CDisplay** EQ_ppCDisplay = (CDisplay**)EQ_POINTER_CDisplay;
#define EQ_CDisplay (*EQ_ppCDisplay)

class CButtonWnd
{
public:
    //
};

class CEverQuest
{
public:
    void CEverQuest::dsp_chat(const char* text, int color, bool filtered);
    void CEverQuest::dsp_chat(const char* text);
    void CEverQuest::EnterZone(struct HWND__*);
    char* CEverQuest::GetBodyTypeDesc(int bodyType);
    char* CEverQuest::GetClassDesc(int);
    char* CEverQuest::GetClassThreeLetterCode(int);
    char* CEverQuest::GetDeityDesc(int);
    char* CEverQuest::GetRaceDesc(int);
    void CEverQuest::InterpretCmd(uint32_t spawnInfo, const char* text);
    int __cdecl CEverQuest::LMouseUp(int x, int y);
    int __cdecl CEverQuest::RMouseUp(int x, int y);
    void CEverQuest::MoveToZone(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    void CEverQuest::SetGameState(int state);
    void CEverQuest::StartCasting(int a1);
};

CEverQuest** EQ_ppCEverQuest = (CEverQuest**)EQ_POINTER_CEverQuest;
#define EQ_CEverQuest (*EQ_ppCEverQuest)

class CHotButtonWnd : public CSidlScreenWnd
{
public:
    void CHotButtonWnd::DoHotButton(uint32_t buttonIndex, bool allowAutoRightClick);
};

CHotButtonWnd** EQ_ppCHotButtonWnd = (CHotButtonWnd**)EQ_POINTER_CHotButtonWnd;
#define EQ_CHotButtonWnd (*EQ_ppCHotButtonWnd)

class CLootWnd : public CSidlScreenWnd
{
public:
    void CLootWnd::Deactivate(void);
    void CLootWnd::RequestLootSlot(int slotIndex, bool autoLoot);
};

CLootWnd** EQ_ppCLootWnd = (CLootWnd**)EQ_POINTER_CLootWnd;
#define EQ_CLootWnd (*EQ_ppCLootWnd)

class CMapViewWnd : public CSidlScreenWnd
{
public:
    CMapViewWnd::~CMapViewWnd();
    void CMapViewWnd::DrawMap(int a1, int a2, int a3, int a4);
};

CMapViewWnd** EQ_ppCMapViewWnd = (CMapViewWnd**)EQ_POINTER_CMapViewWnd;
#define EQ_CMapViewWnd (*EQ_ppCMapViewWnd)

class CTextEntryWnd
{
public:
    void CTextEntryWnd::Activate(void* parentWindow, int a2, char* displayText, int a4, int a5, char* defaultText);
};

CTextEntryWnd** EQ_ppCTextEntryWnd = (CTextEntryWnd**)EQ_POINTER_CTextEntryWnd;
#define EQ_CTextEntryWnd (*EQ_ppCTextEntryWnd)

class CTextOverlay
{
public:
    void CTextOverlay::DisplayText(const char* text, int textColor, int font, int alpha, int x,int y, int duration); // alpha is 0-255, duration is in milliseconds
};

CTextOverlay** EQ_ppCTextOverlay = (CTextOverlay**)EQ_POINTER_CTextOverlay;
#define EQ_CTextOverlay (*EQ_ppCTextOverlay)

class EQPlayer
{
public:
    void EQPlayer::ChangeHeight(float height);
    void EQPlayer::ChangePosition(uint8_t standingState);
    void EQPlayer::do_change_form(EQ::ChangeForm* changeForm);
    void EQPlayer::FacePlayer(uint32_t spawnInfo);
    void EQPlayer::SetRace(int raceId);
    int EQPlayer::UpdateAppearance(int a1, int a2, int a3);
};

class EQPlayerManager
{
public:
    uint32_t EQPlayerManager::GetSpawnByID(int spawnId);
    uint32_t EQPlayerManager::GetSpawnByName(char* spawnName);
};

EQPlayerManager** EQ_ppEQPlayerManager = (EQPlayerManager**)EQ_POINTER_EQPlayerManager;
#define EQ_EQPlayerManager (*EQ_ppEQPlayerManager)

class EQSwitch
{
public:
    void EQSwitch::ChangeState(uint8_t state, int a2, int a3);
};

class EQ_Character
{
public:
    void EQ_Character::eqspa_movement_rate(int unknown);
    int EQ_Character::UseSkill(unsigned char skill, class EQPlayer* targetSpawn);
};

EQ_Character** EQ_ppEQ_Character = (EQ_Character**)EQ_POINTER_EQ_Character;
#define EQ_EQ_Character (*EQ_ppEQ_Character)

class MapViewMap
{
public:
    int MapViewMap::AddLabel(float x, float y, float z, uint32_t colorARGB, int size, const char* text);
    void MapViewMap::RemoveLabel(uint32_t mapLabelInfo);
    void MapViewMap::Save(char* shortZoneName);
    void MapViewMap::SaveEx(char* shortZoneName, int layer);
};

/* EQGraphicsDLL */

typedef int (__thiscall* EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine)(void* this_ptr, EQ::Line* lineBegin, EQ::Line* lineEnd, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine EQGraphicsDLL__DrawLine = NULL;

typedef int (__thiscall* EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad)(void* this_ptr, EQ::Rect* rect, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad EQGraphicsDLL__DrawQuad = NULL;

/* EQ_Guilds */

#ifdef EQ_FUNCTION_EQ_Guilds__GetGuildNameById
EQ_FUNCTION_AT_ADDRESS(char* EQ_Guilds::GetGuildNameById(uint32_t id), EQ_FUNCTION_EQ_Guilds__GetGuildNameById);
#endif

/* StringTable */

#ifdef EQ_FUNCTION_StringTable__getString
EQ_FUNCTION_AT_ADDRESS(char* StringTable::getString(unsigned long index, bool* a2), EQ_FUNCTION_StringTable__getString);
#endif

/* CDisplay */

#ifdef EQ_FUNCTION_CDisplay__CreatePlayerActor
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)(void* this_ptr, uint32_t spawnInfo, int a2, int a3, int a4, int a5);
EQ_FUNCTION_AT_ADDRESS(void CDisplay::CreatePlayerActor(uint32_t spawnInfo, int a2, int a3, int a4, int a5), EQ_FUNCTION_CDisplay__CreatePlayerActor);
#endif

#ifdef EQ_FUNCTION_CDisplay__DeleteActor
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__DeleteActor)(void* this_ptr, uint32_t actorInstance);
EQ_FUNCTION_AT_ADDRESS(void CDisplay::DeleteActor(uint32_t actorInstance), EQ_FUNCTION_CDisplay__DeleteActor);
#endif

#ifdef EQ_FUNCTION_CDisplay__SetViewActor
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetViewActor)(void* this_ptr, uint32_t actorInstance);
EQ_FUNCTION_AT_ADDRESS(void CDisplay::SetViewActor(uint32_t actorInstance), EQ_FUNCTION_CDisplay__SetViewActor);
#endif

#ifdef EQ_FUNCTION_CDisplay__SetViewActorByName
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetViewActorByName)(void* this_ptr, const char* spawnName);
EQ_FUNCTION_AT_ADDRESS(void CDisplay::SetViewActorByName(const char* spawnName), EQ_FUNCTION_CDisplay__SetViewActorByName);
#endif

#ifdef EQ_FUNCTION_CDisplay__WriteTextHD2
EQ_FUNCTION_AT_ADDRESS(int CDisplay::WriteTextHD2(const char* text, int x, int y, int color), EQ_FUNCTION_CDisplay__WriteTextHD2);
#endif

/* CEverQuest */

#ifdef EQ_FUNCTION_CEverQuest__dsp_chat
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, int textColor, bool filtered);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::dsp_chat(const char* text, int textColor, bool filtered), EQ_FUNCTION_CEverQuest__dsp_chat);
#endif

#ifdef EQ_FUNCTION_CEverQuest__dsp_chat__2
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::dsp_chat(const char* text), EQ_FUNCTION_CEverQuest__dsp_chat__2);
#endif

#ifdef EQ_FUNCTION_CEverQuest__EnterZone
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__EnterZone)(void* this_ptr, struct HWND__*);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::EnterZone(struct HWND__ *), EQ_FUNCTION_CEverQuest__EnterZone);
#endif

#ifdef EQ_FUNCTION_CEverQuest__GetBodyTypeDesc
EQ_FUNCTION_AT_ADDRESS(char* CEverQuest::GetBodyTypeDesc(int bodyType), EQ_FUNCTION_CEverQuest__GetBodyTypeDesc);
#endif

#ifdef EQ_FUNCTION_CEverQuest__GetClassDesc
EQ_FUNCTION_AT_ADDRESS(char* CEverQuest::GetClassDesc(int class_), EQ_FUNCTION_CEverQuest__GetClassDesc);
#endif

#ifdef EQ_FUNCTION_CEverQuest__GetClassThreeLetterCode
EQ_FUNCTION_AT_ADDRESS(char* CEverQuest::GetClassThreeLetterCode(int class_), EQ_FUNCTION_CEverQuest__GetClassThreeLetterCode);
#endif

#ifdef EQ_FUNCTION_CEverQuest__GetDeityDesc
EQ_FUNCTION_AT_ADDRESS(char* CEverQuest::GetDeityDesc(int deity), EQ_FUNCTION_CEverQuest__GetDeityDesc);
#endif

#ifdef EQ_FUNCTION_CEverQuest__GetRaceDesc
EQ_FUNCTION_AT_ADDRESS(char* CEverQuest::GetRaceDesc(int race), EQ_FUNCTION_CEverQuest__GetRaceDesc);
#endif

#ifdef EQ_FUNCTION_CEverQuest__InterpretCmd
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, uint32_t spawnInfo, const char* text);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::InterpretCmd(uint32_t spawnInfo, const char* text), EQ_FUNCTION_CEverQuest__InterpretCmd);
#endif

#ifdef EQ_FUNCTION_CEverQuest__LMouseUp
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LMouseUp)(void* this_ptr, int x, int y);
EQ_FUNCTION_AT_ADDRESS(int __cdecl CEverQuest::LMouseUp(int, int), EQ_FUNCTION_CEverQuest__LMouseUp);
#endif

#ifdef EQ_FUNCTION_CEverQuest__RMouseUp
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RMouseUp)(void* this_ptr, int x, int y);
EQ_FUNCTION_AT_ADDRESS(int __cdecl CEverQuest::RMouseUp(int, int), EQ_FUNCTION_CEverQuest__RMouseUp);
#endif

#ifdef EQ_FUNCTION_CEverQuest__MoveToZone
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__MoveToZone)(void* this_ptr, int, int, int, int, int, int, int, int);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::MoveToZone(int, int, int, int, int, int, int, int), EQ_FUNCTION_CEverQuest__MoveToZone);
#endif

#ifdef EQ_FUNCTION_CEverQuest__SetGameState
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__SetGameState)(void* this_ptr, int state);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::SetGameState(int state), EQ_FUNCTION_CEverQuest__SetGameState);
#endif

#ifdef EQ_FUNCTION_CEverQuest__StartCasting
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__StartCasting)(void* this_ptr, int a1);
EQ_FUNCTION_AT_ADDRESS(void CEverQuest::StartCasting(int a1), EQ_FUNCTION_CEverQuest__StartCasting);
#endif

/* CMapViewWnd */

#ifdef EQ_FUNCTION_CMapViewWnd__dCMapViewWnd
typedef int (__thiscall* EQ_FUNCTION_TYPE_CMapViewWnd__dCMapViewWnd)(void* this_ptr);
EQ_FUNCTION_AT_ADDRESS(CMapViewWnd::~CMapViewWnd(), EQ_FUNCTION_CMapViewWnd__dCMapViewWnd);
#endif

#ifdef EQ_FUNCTION_CMapViewWnd__DrawMap
typedef int (__thiscall* EQ_FUNCTION_TYPE_CMapViewWnd__DrawMap)(void* this_ptr, int a1, int a2, int a3, int a4);
EQ_FUNCTION_AT_ADDRESS(void CMapViewWnd::DrawMap(int, int, int, int), EQ_FUNCTION_CMapViewWnd__DrawMap);
#endif

/* CHotButtonWnd */

#ifdef EQ_FUNCTION_CHotButtonWnd__DoHotButton
EQ_FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButton(uint32_t buttonIndex, bool allowAutoRightClick), EQ_FUNCTION_CHotButtonWnd__DoHotButton);
#endif

/* CLootWnd */

#ifdef EQ_FUNCTION_CLootWnd__Deactivate
EQ_FUNCTION_AT_ADDRESS(void CLootWnd::Deactivate(void), EQ_FUNCTION_CLootWnd__Deactivate);
#endif

#ifdef EQ_FUNCTION_CLootWnd__RequestLootSlot
EQ_FUNCTION_AT_ADDRESS(void CLootWnd::RequestLootSlot(int slotIndex, bool autoLoot), EQ_FUNCTION_CLootWnd__RequestLootSlot);
#endif

/* CTextEntryWnd */

#ifdef EQ_FUNCTION_CTextEntryWnd__Activate
typedef int (__thiscall* EQ_FUNCTION_TYPE_CTextEntryWnd__Activate)(void* this_ptr, void*, int, char*, int, int, char*);
EQ_FUNCTION_AT_ADDRESS(void CTextEntryWnd::Activate(void*, int, char*, int, int, char*), EQ_FUNCTION_CTextEntryWnd__Activate);
#endif

/* CTextOverlay */

#ifdef EQ_FUNCTION_CTextOverlay__DisplayText
typedef int (__thiscall* EQ_FUNCTION_TYPE_CTextOverlay__DisplayText)(void* this_ptr, const char* text, int textColor, int font, int alpha, int x, int y, int duration);
EQ_FUNCTION_AT_ADDRESS(void CTextOverlay::DisplayText(const char* text, int textColor, int font, int alpha, int x, int y, int duration), EQ_FUNCTION_CTextOverlay__DisplayText);
#endif

/* EQPlayer */

#ifdef EQ_FUNCTION_EQPlayer__ChangeHeight
EQ_FUNCTION_AT_ADDRESS(void EQPlayer::ChangeHeight(float height), EQ_FUNCTION_EQPlayer__ChangeHeight);
#endif

#ifdef EQ_FUNCTION_EQPlayer__ChangePosition
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangePosition)(void* this_ptr, uint8_t standingState);
EQ_FUNCTION_AT_ADDRESS(void EQPlayer::ChangePosition(uint8_t standingState), EQ_FUNCTION_EQPlayer__ChangePosition);
#endif

#ifdef EQ_FUNCTION_EQPlayer__do_change_form
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__do_change_form)(void* this_ptr, EQ::ChangeForm* changeForm);
EQ_FUNCTION_AT_ADDRESS(void EQPlayer::do_change_form(EQ::ChangeForm* changeForm), EQ_FUNCTION_EQPlayer__do_change_form);
#endif

#ifdef EQ_FUNCTION_EQPlayer__FacePlayer
EQ_FUNCTION_AT_ADDRESS(void EQPlayer::FacePlayer(uint32_t spawnInfo), EQ_FUNCTION_EQPlayer__FacePlayer);
#endif

#ifdef EQ_FUNCTION_EQPlayer__SetRace
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__SetRace)(void* this_ptr, int raceId);
EQ_FUNCTION_AT_ADDRESS(void EQPlayer::SetRace(int raceId), EQ_FUNCTION_EQPlayer__SetRace);
#endif

#ifdef EQ_FUNCTION_EQPlayer__UpdateAppearance
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__UpdateAppearance)(void* this_ptr, int a1, int a2, int a3);
EQ_FUNCTION_AT_ADDRESS(int EQPlayer::UpdateAppearance(int a1, int a2, int a3), EQ_FUNCTION_EQPlayer__UpdateAppearance);
#endif

/* EQPlayerManager */

#ifdef EQ_FUNCTION_EQPlayerManager__GetSpawnByID
EQ_FUNCTION_AT_ADDRESS(uint32_t EQPlayerManager::GetSpawnByID(int spawnId), EQ_FUNCTION_EQPlayerManager__GetSpawnByID);
#endif

#ifdef EQ_FUNCTION_EQPlayerManager__GetSpawnByName
EQ_FUNCTION_AT_ADDRESS(uint32_t EQPlayerManager::GetSpawnByName(char* spawnName), EQ_FUNCTION_EQPlayerManager__GetSpawnByName);
#endif

/* EQSwitch */

#ifdef EQ_FUNCTION_EQSwitch__ChangeState
EQ_FUNCTION_AT_ADDRESS(void EQSwitch::ChangeState(uint8_t state, int a2, int a3), EQ_FUNCTION_EQSwitch__ChangeState);
#endif

/* EQ_Character */

#ifdef EQ_FUNCTION_EQ_Character__eqspa_movement_rate
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)(void* this_ptr, int unknown);
EQ_FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_movement_rate(int), EQ_FUNCTION_EQ_Character__eqspa_movement_rate);
#endif

#ifdef EQ_FUNCTION_EQ_Character__UseSkill
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_Character__UseSkill)(void* this_ptr, unsigned char skill, class EQPlayer* targetSpawn);
EQ_FUNCTION_AT_ADDRESS(int EQ_Character::UseSkill(unsigned char, class EQPlayer*), EQ_FUNCTION_EQ_Character__UseSkill);
#endif

/* MapViewMap */

#ifdef EQ_FUNCTION_MapViewMap__AddLabel
typedef int (__thiscall* EQ_FUNCTION_TYPE_MapViewMap__AddLabel)(void* this_ptr, float x, float y, float z, uint32_t colorARGB, int size, const char* text);
EQ_FUNCTION_AT_ADDRESS(int MapViewMap::AddLabel(float x, float y, float z, uint32_t colorARGB, int size, const char* text), EQ_FUNCTION_MapViewMap__AddLabel);
#endif

#ifdef EQ_FUNCTION_MapViewMap__RemoveLabel
typedef int (__thiscall* EQ_FUNCTION_TYPE_MapViewMap__RemoveLabel)(void* this_ptr, uint32_t mapLabelInfo);
EQ_FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(uint32_t mapLabelInfo), EQ_FUNCTION_MapViewMap__RemoveLabel);
#endif

#ifdef EQ_FUNCTION_MapViewMap__Save
typedef int (__thiscall* EQ_FUNCTION_TYPE_MapViewMap__Save)(void* this_ptr, char* shortZoneName);
EQ_FUNCTION_AT_ADDRESS(void MapViewMap::Save(char* shortZoneName), EQ_FUNCTION_MapViewMap__Save);
#endif

#ifdef EQ_FUNCTION_MapViewMap__SaveEx
typedef int (__thiscall* EQ_FUNCTION_TYPE_MapViewMap__SaveEx)(void* this_ptr, char* shortZoneName, int layer);
EQ_FUNCTION_AT_ADDRESS(void MapViewMap::SaveEx(char* shortZoneName, int layer), EQ_FUNCTION_MapViewMap__SaveEx);
#endif

/* other */

#ifdef EQ_FUNCTION_Exit
typedef int (__cdecl* EQ_FUNCTION_TYPE_Exit)();
EQ_FUNCTION_AT_ADDRESS(void EQ_Exit(), EQ_FUNCTION_Exit);
#endif

#ifdef EQ_FUNCTION_ResetDevice
EQ_FUNCTION_AT_ADDRESS(int __cdecl EQ_ResetDevice(), EQ_FUNCTION_ResetDevice);
#endif

#ifdef EQ_FUNCTION_WindowResize
EQ_FUNCTION_AT_ADDRESS(int __cdecl EQ_WindowResize(WPARAM wparam, LPARAM lparam), EQ_FUNCTION_WindowResize);
#endif

#ifdef EQ_FUNCTION_CastRay
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay)(uint32_t originSpawn, float y, float x, float z);
EQ_FUNCTION_AT_ADDRESS(int __cdecl EQ_CastRay(uint32_t originSpawn, float y, float x, float z), EQ_FUNCTION_CastRay);
#endif

#ifdef EQ_FUNCTION_CXWnd_DrawColoredRect
typedef int (__cdecl* EQ_FUNCTION_TYPE_CXWnd_DrawColoredRect)(EQ::CXRect* rect, uint32_t colorARGB);
EQ_FUNCTION_AT_ADDRESS(int __cdecl EQ_CXWnd_DrawColoredRect(EQ::CXRect* rect, uint32_t colorARGB), EQ_FUNCTION_CXWnd_DrawColoredRect);
#endif

#ifdef EQ_FUNCTION_DrawNetStatus
typedef int (__cdecl* EQ_FUNCTION_TYPE_DrawNetStatus)(int, unsigned short, unsigned short, unsigned short x, unsigned short y, int, unsigned short, unsigned long, long, unsigned long);
#endif

#ifdef EQ_FUNCTION_GetMeleeRange
EQ_FUNCTION_AT_ADDRESS(float __cdecl EQ_GetMeleeRange(uint32_t spawn1, uint32_t spawn2), EQ_FUNCTION_GetMeleeRange);
#endif

#ifdef EQ_FUNCTION_GetBearing
EQ_FUNCTION_AT_ADDRESS(float __cdecl EQ_GetBearing(float y1, float x1, float y2, float x2), EQ_FUNCTION_GetBearing);
#endif

#ifdef EQ_FUNCTION_ExecuteCommand
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCommand)(uint32_t command, int hold, void* unknown);
EQ_FUNCTION_AT_ADDRESS(void EQ_ExecuteCommand(uint32_t command, int hold, void* unknown), EQ_FUNCTION_ExecuteCommand);
#endif

#ifdef EQ_FUNCTION_SetTarget
typedef int (__cdecl* EQ_FUNCTION_TYPE_SetTarget)(uint32_t a1, const char* spawnName);
EQ_FUNCTION_AT_ADDRESS(int __cdecl EQ_SetTarget(uint32_t a1, const char* spawnName), EQ_FUNCTION_SetTarget);
#endif

#ifdef EQ_FUNCTION_OpenAllContainers
EQ_FUNCTION_AT_ADDRESS(void EQ_OpenAllContainers(), EQ_FUNCTION_OpenAllContainers);
#endif

#ifdef EQ_FUNCTION_CloseAllContainers
EQ_FUNCTION_AT_ADDRESS(void EQ_CloseAllContainers(), EQ_FUNCTION_CloseAllContainers);
#endif

#ifdef EQ_FUNCTION_AcceptGroupInvite
EQ_FUNCTION_AT_ADDRESS(void EQ_AcceptGroupInvite(), EQ_FUNCTION_AcceptGroupInvite);
#endif

#ifdef EQ_FUNCTION_UpdateLight
EQ_FUNCTION_AT_ADDRESS(void EQ_UpdateLight(uint32_t charInfo), EQ_FUNCTION_UpdateLight);
#endif

/* functions */

void EQ_ToggleBool(bool& b)
{
    b = !b;
}

float EQ_CalculateDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float EQ_CalculateDistance3d(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void EQ_Rotate2d(float cx, float cy, float& x, float& y, float angle)
{
    float radians = angle * (EQ_PI / 256.0f); // 512 / 2 = 256

    float c = cosf(radians);
    float s = sinf(radians);

    float nx = (c * (x - cx)) - (s * (y - cy)) + cx;
    float ny = (s * (x - cx)) + (c * (y - cy)) + cy;

    x = nx;
    y = ny;
}

float EQ_GetRadians(float degrees)
{
    return degrees * EQ_PI / EQ_HEADING_MAX_HALVED;
}

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight)
{
    if (pointX < rectX)                return false;
    if (pointY < rectY)                return false;
    if (pointX > (rectX + rectWidth))  return false;
    if (pointY > (rectY + rectHeight)) return false;

    return true;
}

void EQ_ColorARGB_Darken(uint32_t& colorARGB, float percent)
{
    uint32_t alpha = (colorARGB >> 24) & 0xFF;
    uint32_t red   = (colorARGB >> 16) & 0xFF;
    uint32_t green = (colorARGB >> 8)  & 0xFF;
    uint32_t blue  =  colorARGB        & 0xFF;

    red   = (uint32_t)(red   * percent);
    green = (uint32_t)(green * percent);
    blue  = (uint32_t)(blue  * percent);

    colorARGB = (alpha << 24) + (red << 16) + (green << 8) + blue;
}

void EQ_CopyStringToClipboard(std::string& str)
{
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, str.size() + 1);
    memcpy(GlobalLock(mem), str.c_str(), str.size() + 1);
    GlobalUnlock(mem);

    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, mem);
    CloseClipboard();
}

bool EQ_IsInGame()
{
    uint32_t everquest = EQ_ReadMemory<uint32_t>(EQ_POINTER_CEverQuest);
    if (everquest == NULL)
    {
        return false;
    }

    uint32_t gameState = EQ_ReadMemory<uint32_t>(everquest + EQ_OFFSET_CEverQuest_GAME_STATE);
    if (gameState != EQ_GAME_STATE_IN_GAME)
    {
        return false;
    }

    return true;
}

bool EQ_IsNetStatusEnabled()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_NET_STATUS);

    return (b == 1);
}

bool EQ_IsSafeLockEnabled()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_SAFELOCK);

    return (b == 1);
}

bool EQ_IsScreenshotBeingTaken()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_SCREENSHOT);

    return (b == 1);
}

bool EQ_IsAutoAttackEnabled()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_AUTO_ATTACK);

    return (b == 1);
}

bool EQ_IsAutoFireEnabled()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_AUTO_FIRE);

    return (b == 1);
}

bool EQ_IsAutoRunEnabled()
{
    uint32_t b = EQ_ReadMemory<uint32_t>(EQ_BOOL_AUTO_RUN);

    return (b == 1);
}

void EQ_SetNetStatus(bool b)
{
    if (b == true)
    {
        EQ_WriteMemory<uint8_t>(EQ_BOOL_NET_STATUS, 0x01);
    }
    else
    {
        EQ_WriteMemory<uint8_t>(EQ_BOOL_NET_STATUS, 0x00);
    }
}

void EQ_SetAutoAttack(bool b)
{
    if (b == true)
    {
        EQ_WriteMemory<uint8_t>(EQ_BOOL_AUTO_ATTACK, 0x01);
    }
    else
    {
        EQ_WriteMemory<uint8_t>(EQ_BOOL_AUTO_ATTACK, 0x00);
    }
}

void EQ_SetAutoRun(bool b)
{
    if (b == true)
    {
        EQ_WriteMemory<uint32_t>(EQ_BOOL_AUTO_RUN, 1);
    }
    else
    {
        EQ_WriteMemory<uint32_t>(EQ_BOOL_AUTO_RUN, 0);
    }
}

bool EQ_IsKeyShiftPressed()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_KEYBOARD_SHIFT);

    return (b == 1);
}

bool EQ_IsKeyAltPressed()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_KEYBOARD_ALT);

    return (b == 1);
}

bool EQ_IsKeyControlPressed()
{
    int b = EQ_ReadMemory<uint8_t>(EQ_BOOL_KEYBOARD_CONTROL);

    return (b == 1);
}

uint32_t EQ_GetExitStatus()
{
    return EQ_ReadMemory<uint8_t>(EQ_EXIT_STATUS);
}

HWND EQ_GetWindow()
{
    return EQ_ReadMemory<HWND>(EQ_WINDOW_HWND);
}

uint32_t EQ_GetWindowWidth()
{
    return EQ_ReadMemory<uint32_t>(EQ_WINDOW_WIDTH);
}

uint32_t EQ_GetWindowHeight()
{
    return EQ_ReadMemory<uint32_t>(EQ_WINDOW_HEIGHT);
}

uint32_t EQ_GetCharInfo()
{
    return EQ_ReadMemory<uint32_t>(EQ_POINTER_CHAR_INFO);
}

uint32_t EQ_GetCharInfo_CI2()
{
    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_CI2);
}

uint32_t EQ_GetCharInfo2()
{
    uint32_t charInfo_CI2 = EQ_GetCharInfo_CI2();
    if (charInfo_CI2 == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(charInfo_CI2 + EQ_OFFSET_CI2_CHAR_INFO_2);
}

uint32_t EQ_GetFirstSpawn()
{
    uint32_t spawnManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SPAWN_MANAGER);
    if (spawnManager == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(spawnManager + EQ_OFFSET_SPAWN_MANAGER_SPAWN_INFO_FIRST);
}

uint32_t EQ_GetLastSpawn()
{
    uint32_t spawnManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SPAWN_MANAGER);
    if (spawnManager == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(spawnManager + EQ_OFFSET_SPAWN_MANAGER_SPAWN_INFO_LAST);
}

uint32_t EQ_GetPreviousSpawn(uint32_t spawnInfo)
{
    return EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_PREVIOUS);
}

uint32_t EQ_GetNextSpawn(uint32_t spawnInfo)
{
    return EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_NEXT);
}

uint32_t EQ_GetPlayerSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_POINTER_SPAWN_INFO_PLAYER);
}

uint32_t EQ_GetTargetSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_POINTER_SPAWN_INFO_TARGET);
}

uint32_t EQ_GetSpawnActorInfo(uint32_t spawnInfo)
{
    return EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_ACTOR_INFO);
}

float EQ_GetSpawnY(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_SPAWN_INFO_Y);
}

float EQ_GetSpawnX(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_SPAWN_INFO_X);
}

float EQ_GetSpawnZ(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_SPAWN_INFO_Z);
}

std::string EQ_GetSpawnName(uint32_t spawnInfo)
{
    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = { 0 };
    memcpy(spawnName, (void*)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

    return spawnName;
}

std::string EQ_GetSpawnNumberedName(uint32_t spawnInfo)
{
    char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = { 0 };
    memcpy(spawnNumberedName, (void*)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

    return spawnNumberedName;
}

std::string EQ_GetSpawnBodyTypeDescription(uint32_t spawnInfo)
{
    return EQ_CEverQuest->GetBodyTypeDesc(spawnInfo + EQ_OFFSET_SPAWN_INFO_BODY_TYPE_DESCRIPTION);
}

uint32_t EQ_GetFirstGroundSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_POINTER_GROUND_SPAWN_INFO_FIRST);
}

uint32_t EQ_GetPreviousGroundSpawn(uint32_t spawnInfo)
{
    return EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_GROUND_SPAWN_INFO_PREVIOUS);
}

uint32_t EQ_GetNextGroundSpawn(uint32_t spawnInfo)
{
    return EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_GROUND_SPAWN_INFO_NEXT);
}

float EQ_GetGroundSpawnY(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_GROUND_SPAWN_INFO_Y);
}

float EQ_GetGroundSpawnX(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_GROUND_SPAWN_INFO_X);
}

float EQ_GetGroundSpawnZ(uint32_t spawnInfo)
{
    return EQ_ReadMemory<float>(spawnInfo + EQ_OFFSET_GROUND_SPAWN_INFO_Z);
}

std::string EQ_GetZoneShortName()
{
    char zoneShortName[EQ_SIZE_ZONE_INFO_SHORT_NAME] = {0};
    memcpy(zoneShortName, (void*)(EQ_ZONE_INFO_SHORT_NAME), sizeof(zoneShortName));

    std::string zoneShortNameString = zoneShortName;

    auto find = EQ_KEYVALUE_SHORT_ZONE_NAMES_EMU.find(zoneShortNameString);
    if (find != EQ_KEYVALUE_SHORT_ZONE_NAMES_EMU.end())
    {
        zoneShortNameString = find->second;
    }

    return zoneShortNameString;
}

std::string EQ_GetZoneLongName()
{
    char zoneLongName[EQ_SIZE_ZONE_INFO_LONG_NAME] = {0};
    memcpy(zoneLongName, (void*)(EQ_ZONE_INFO_LONG_NAME), sizeof(zoneLongName));

    return zoneLongName;
}

std::string EQ_GetCharacterName()
{
    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        return std::string();
    }

    char characterName[EQ_SIZE_CHAR_INFO_CHARACTER_NAME] = {0};
    memcpy(characterName, (void*)(charInfo + EQ_OFFSET_CHAR_INFO_CHARACTER_NAME), sizeof(characterName));

    return characterName;
}

void EQ_SetCameraView(uint32_t cameraView)
{
    EQ_WriteMemory<uint32_t>(EQ_CAMERA_VIEW, cameraView);
}

uint32_t EQ_GetZoneId()
{
    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        return NULL;
    }

    uint32_t zoneId = EQ_ReadMemory<uint16_t>(charInfo + EQ_OFFSET_CHAR_INFO_ZONE_ID);

    return zoneId;
}

bool EQ_IsRacePlayable(uint32_t raceId)
{
    if
    (
        raceId >= EQ_RACE_HUMAN && raceId <= EQ_RACE_GNOME ||
        raceId == EQ_RACE_IKSAR                            ||
        raceId == EQ_RACE_VAH_SHIR                         ||
        raceId == EQ_RACE_FROGLOK                          ||
        raceId == EQ_RACE_DRAKKIN
    )
    {
        return true;
    }

    return false;
}

void EQ_SetSpawnForm(uint32_t spawnInfo, uint32_t raceId, uint8_t gender)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    uint32_t spawnId = EQ_ReadMemory<uint16_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_ID);

    uint8_t unknown73 = 0xFF;
    uint8_t unknown76 = 0xFF;

    if (EQ_IsRacePlayable(raceId) == false)
    {
        gender = EQ_GENDER_NEUTRAL;

        unknown73 = 0x00;
        unknown76 = 0x00;
    }

    static EQ::ChangeForm changeForm = {};
    changeForm.SpawnId      = spawnId;
    changeForm.RaceId       = raceId;
    changeForm.Gender       = gender;
    changeForm.Unknown73    = unknown73;
    changeForm.Unknown76    = unknown76;
    changeForm.Unknown80    = 0x06;

    ((EQPlayer*)spawnInfo)->do_change_form(&changeForm);
}

void EQ_WriteToChat(const char* text)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    EQ_CEverQuest->dsp_chat(text);
}

void EQ_WriteToChat(const char* text, int textColor)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    EQ_CEverQuest->dsp_chat(text, textColor, false);
}

void EQ_SetSpawnCollisionRadius(uint32_t spawnInfo, float radius)
{
    if (radius < 0.1f)
    {
        return;
    }

    if (spawnInfo == NULL)
    {
        return;
    }

    uint32_t actorInfo = EQ_GetSpawnActorInfo(spawnInfo);
    if (actorInfo == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(actorInfo + EQ_OFFSET_ACTOR_INFO_COLLISION_RADIUS, radius);
}

bool EQ_IsZoneCity()
{
    // TODO

    uint32_t zoneId = EQ_GetZoneId();

    if
    (
        zoneId == 1   || // south newport
        zoneId == 2   || // north newport
        zoneId == 3   || // surefall
        zoneId == 23  || // erudin palace
        zoneId == 24  || // erudin
        zoneId == 29  || // halas
        zoneId == 55  || // underhill
        zoneId == 61  || // athica a
        zoneId == 62  || // athica b
        zoneId == 74  || // sadri malath
        zoneId == 114    // thurgadin
    )
    {
        return true;
    }

    return false;
}

bool EQ_IsPlayerCastingSpell()
{
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    uint32_t spellCastingTimer = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_SPELL_CASTING_TIMER);
    if (spellCastingTimer > 0)
    {
        return true;
    }

    return false;
}

bool EQ_IsSpawnInGroup(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return false;
    }

    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        return false;
    }

    uint32_t groupInfo = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_GROUP_INFO);
    if (groupInfo == NULL)
    {
        return false;
    }

    for (size_t i = 1; i < EQ_NUM_GROUP_MEMBERS + 1; i++)
    {
        uint32_t groupMemberInfo = EQ_ReadMemory<uint32_t>(groupInfo + (i * 4));
        if (groupMemberInfo == NULL)
        {
            continue;
        }

        uint32_t groupMemberSpawnInfo = EQ_ReadMemory<uint32_t>(groupMemberInfo + EQ_OFFSET_GROUP_MEMBER_INFO_SPAWN_INFO);
        if (groupMemberSpawnInfo == NULL)
        {
            continue;
        }

        if (groupMemberSpawnInfo == spawnInfo)
        {
            return true;
        }
    }

    return false;
}

uint32_t EQ_GetTimer()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    uint32_t timer = EQ_ReadMemory<uint32_t>(display + EQ_OFFSET_CDisplay_TIMER);

    return timer;
}

bool EQ_IsHideCorpseLootedEnabled()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    int hideCorpseLooted = EQ_ReadMemory<uint8_t>(display + EQ_OFFSET_CDisplay_IS_HIDE_CORPSE_LOOTED_ENABLED);

    return (hideCorpseLooted == 1);
}

void EQ_SetHideCorpseLooted(bool b)
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_POINTER_CDisplay);
    if (display == NULL)
    {
        return;
    }

    uint8_t value = 0x00;

    if (b == true)
    {
        value = 0x01;
    }

    EQ_WriteMemory<uint8_t>(display + EQ_OFFSET_CDisplay_IS_HIDE_CORPSE_LOOTED_ENABLED, value);
}

void EQ_String_ReplaceUnderscoresWithSpaces(char* str)
{
    while (*str)
    {
        if (*str == '_')
        {
            *str = ' ';
        }

        str++;
    }
}

void EQ_String_ReplaceSpacesWithUnderscores(char* str)
{
    while (*str)
    {
        if (*str == ' ')
        {
            *str = '_';
        }

        str++;
    }
}

void EQ_DrawText(const char* text, int x, int y, uint32_t colorARGB, uint32_t size)
{
    // color is ARGB format: 0xAARRGGBB

    if (size == 0)
    {
        return;
    }

    uint32_t windowManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_CXWndManager);
    if (windowManager == NULL)
    {
        return;
    }

    uint32_t fontManager = EQ_ReadMemory<uint32_t>(windowManager + EQ_OFFSET_CXWndManager_FONT_MANAGER);
    if (fontManager == NULL)
    {
        return;
    }

    uint32_t fontInfo2 = EQ_ReadMemory<uint32_t>(fontManager + EQ_OFFSET_FONT_MANAGER_FONT_INFO_2);
    if (fontInfo2 == NULL)
    {
        return;
    }

    // modifies the game function then restores it to normal

    EQ_WriteMemoryProtected<uint32_t>(EQ_FONT_INFO_2_COLOR_ADDRESS, colorARGB); // write new color

    EQ_WriteMemory<uint32_t>(fontInfo2 + EQ_OFFSET_FONT_INFO_SIZE, size); // write new font size

    EQ_CDisplay->WriteTextHD2(text, x, y, 0); // 0 is the color index that gets overwritten

    EQ_WriteMemoryProtected<uint32_t>(EQ_FONT_INFO_2_COLOR_ADDRESS, EQ_FONT_INFO_2_COLOR_VALUE); // restore old color

    EQ_WriteMemory<uint32_t>(fontInfo2 + EQ_OFFSET_FONT_INFO_SIZE, 2); // restore old font size
}


void EQ_DrawColoredRectangle(int x, int y, uint32_t width, uint32_t height, uint32_t colorARGB)
{
    EQ::CXRect rect;

    // top left
    rect.X1 = x;
    rect.Y1 = y;

    // bottom right
    rect.X2 = x + width;
    rect.Y2 = y + height;

    EQ_CXWnd_DrawColoredRect(&rect, colorARGB);
}

void EQ_DrawQuad(float x, float y, float width, float height, uint32_t colorARGB)
{
    EQ::Rect rect;

    // top left
    rect.X1 = x;
    rect.Y1 = y;
    rect.Z1 = 0.0f;

    // top right
    rect.X2 = x + width;
    rect.Y2 = y;
    rect.Z2 = 0.0f;

    // bottom right
    rect.X3 = x + width;
    rect.Y3 = y + height;
    rect.Z3 = 0.0f;

    // bottom left
    rect.X4 = x;
    rect.Y4 = y + height;
    rect.Z4 = 0.0f;

    EQGraphicsDLL__DrawQuad(EQ_EQGraphicsDLL, &rect, colorARGB);
}

void EQ_DrawQuadEx(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, uint32_t colorARGB)
{
    EQ::Rect rect;

    // top left
    rect.X1 = x1;
    rect.Y1 = y1;
    rect.Z1 = 0.0f;

    // top right
    rect.X2 = x2;
    rect.Y2 = y2;
    rect.Z2 = 0.0f;

    // bottom right
    rect.X3 = x3;
    rect.Y3 = y3;
    rect.Z3 = 0.0f;

    // bottom left
    rect.X4 = x4;
    rect.Y4 = y4;
    rect.Z4 = 0.0f;

    EQGraphicsDLL__DrawQuad(EQ_EQGraphicsDLL, &rect, colorARGB);
}

bool EQ_DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, uint32_t colorARGB)
{
    if (EQGraphicsDLL__DrawLine == NULL)
    {
        return false;
    }

    EQ::Line lineBegin;
    lineBegin.X = x1;
    lineBegin.Y = y1;
    lineBegin.Z = z1;

    EQ::Line lineEnd;
    lineEnd.X = x2;
    lineEnd.Y = y2;
    lineEnd.Z = z2;

    EQGraphicsDLL__DrawLine(EQ_EQGraphicsDLL, &lineBegin, &lineEnd, colorARGB);

    return true;
}

uint32_t EQ_GetCameraData()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(display + EQ_OFFSET_CDisplay_CAMERA_DATA);
}

bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, int& screenX, int& screenY)
{
    // this function uses hardcoded offsets

    uint32_t cameraData = EQ_GetCameraData();
    if (cameraData == NULL)
    {
        return false;
    }

    float cameraData_0x1A0 = EQ_ReadMemory<float>(cameraData + 0x0C); // boolean for if the world should be drawn
    float cameraData_0x1A4 = EQ_ReadMemory<float>(cameraData + 0x10);
    float cameraData_0x1A8 = EQ_ReadMemory<float>(cameraData + 0x14);
    float cameraData_0x198 = EQ_ReadMemory<float>(cameraData + 0x38); // screen width  divided by two
    float cameraData_0x19C = EQ_ReadMemory<float>(cameraData + 0x3C); // screen height divided by two
    float cameraData_0x22C = EQ_ReadMemory<float>(cameraData + 0x48);
    float cameraData_0x238 = EQ_ReadMemory<float>(cameraData + 0x54);
    float cameraData_0x244 = EQ_ReadMemory<float>(cameraData + 0x60);
    float cameraData_0x260 = EQ_ReadMemory<float>(cameraData + 0x84);
    float cameraData_0x264 = EQ_ReadMemory<float>(cameraData + 0x88);
    float cameraData_0x268 = EQ_ReadMemory<float>(cameraData + 0x8C); // always zero?
    float cameraData_0x26C = EQ_ReadMemory<float>(cameraData + 0x90);
    float cameraData_0x270 = EQ_ReadMemory<float>(cameraData + 0x94);
    float cameraData_0x274 = EQ_ReadMemory<float>(cameraData + 0x98);
    float cameraData_0x1AC = EQ_ReadMemory<float>(cameraData + 0xBC);
    float cameraData_0x1B0 = EQ_ReadMemory<float>(cameraData + 0xC0);
    float cameraData_0x1B4 = EQ_ReadMemory<float>(cameraData + 0xC4);

    float v4 = cameraData_0x1AC - worldY; // changed add to substract because Seeds of Destruction has backwards coordinates
    float v5 = cameraData_0x1B0 - worldX; // changed add to substract because Seeds of Destruction has backwards coordinates
    float v6 = cameraData_0x1B4 - worldZ; // changed add to substract because Seeds of Destruction has backwards coordinates

    float v10 = v6 * cameraData_0x268 + v5 * cameraData_0x264 + v4 * cameraData_0x260;
    float v11 = v6 * cameraData_0x274 + v5 * cameraData_0x270 + v4 * cameraData_0x26C;
    float v7  = v6 * cameraData_0x244 + v5 * cameraData_0x238 + v4 * cameraData_0x22C;

    // point is offscreen
    if (v7 >= cameraData_0x1A0) // changed <= to >= because Seeds of Destruction client has backwards coordinates
    {
        screenX = -1;
        screenY = -1;

        return false;
    }

    // prevent divide by zero
    if (v7 == 0.0f)
    {
        screenX = -1;
        screenY = -1;

        return false;
    }

    float v8 = 1.0f / v7;

    float a3 = v10 * v8 + cameraData_0x198;
    float a4 = cameraData_0x19C - v8 * v11;

    screenX = (int)a3;
    screenY = (int)a4;

    // point is offscreen
    int windowWidth  = EQ_GetWindowWidth();
    int windowHeight = EQ_GetWindowHeight();
    if (screenX < 0 || screenX > windowWidth || screenY < 0 || screenY > windowHeight)
    {
        screenX = -1;
        screenY = -1;

        return false;
    }

    return true;
}

void EQ_SetFieldOfView(float fov)
{
    uint32_t cameraData = EQ_GetCameraData();
    if (cameraData == NULL)
    {
        return;
    }

    if (fov < 1.0f)
    {
        fov = EQ_FIELD_OF_VIEW_DEFAULT;
    }

    EQ_WriteMemory<float>(cameraData + EQ_OFFSET_CAMERA_DATA_FIELD_OF_VIEW, fov);
}

void EQ_SetDrawDistance(float distance)
{
    uint32_t cameraData = EQ_GetCameraData();
    if (cameraData == NULL)
    {
        return;
    }

    if (distance < 1.0f)
    {
        distance = EQ_DRAW_DISTANCE_DEFAULT;
    }

    EQ_WriteMemory<float>(EQ_ZONE_INFO_MIN_CLIP, distance);
    EQ_WriteMemory<float>(EQ_ZONE_INFO_MAX_CLIP, distance);

    EQ_WriteMemory<float>(EQ_ZONE_INFO_FOG_MIN_CLIP, distance);
    EQ_WriteMemory<float>(EQ_ZONE_INFO_FOG_MAX_CLIP, distance);

    EQ_WriteMemory<float>(EQ_DRAW_DISTANCE_MAX, distance);

    EQ_WriteMemory<float>(cameraData + EQ_OFFSET_CAMERA_DATA_DRAW_DISTANCE, distance);
}

std::string EQ_GetSpellNameById(uint32_t spellId)
{
    if (spellId > EQ_NUM_SPELLS)
    {
        return "Unknown Spell";
    }

    uint32_t spellManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_SPELL_MANAGER);
    if (spellManager == NULL)
    {
        return "Unknown Spell";
    }

    uint32_t spellInfo = EQ_ReadMemory<uint32_t>(spellManager + (EQ_OFFSET_SPELL_MANAGER_SPELL_INFO_FIRST + (spellId * 4)));
    if (spellInfo == NULL)
    {
        return "Unknown Spell";
    }

    char spellName[EQ_SIZE_SPELL_INFO_NAME] = {0};
    memcpy(spellName, (void*)(spellInfo + EQ_OFFSET_SPELL_INFO_NAME), sizeof(spellName));

    return spellName;
}

uint32_t EQ_GetNumPlayersInZone()
{
    uint32_t numPlayers = 0;

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            int spawnLevel = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);
            if (spawnLevel > EQ_LEVEL_MIN && spawnLevel < EQ_LEVEL_MAX)
            {
                char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
                memcpy(spawnNumberedName, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

                if (strlen(spawnNumberedName) > EQ_SPAWN_NAME_LENGTH_MIN - 1)
                {
                    numPlayers++;
                }
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    return numPlayers;
}

bool EQ_DoesSpawnExist(uint32_t spawnInfo)
{
    uint32_t numPlayers = 0;

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        if (spawn == spawnInfo)
        {
            return true;
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    return false;
}

uint32_t EQ_GetSpawnByName(const char* name, bool bUseInternalName = false, bool bUsePartialMatch = false)
{
    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        uint32_t offset = EQ_OFFSET_SPAWN_INFO_NAME;
        if (bUseInternalName == true)
        {
            offset = EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME;
        }

        char spawnName[0x40] = {0};
        memcpy(spawnName, (void*)(spawn + offset), sizeof(spawnName));

        if (bUsePartialMatch == true)
        {
            if (strstr(spawnName, name) != NULL)
            {
                return spawn;
            }
        }
        else
        {
            if (strcmp(spawnName, name) == 0)
            {
                return spawn;
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    return NULL;
}

EQ::MapLabel* EQ_MapWindow_AddLabel(EQ::MapLabel* mapLabel)
{
    uint32_t mapViewWnd = EQ_ReadMemory<uint32_t>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        return NULL;
    }

    EQ::MapLabel* node = EQ_ReadMemory<EQ::MapLabel*>(mapViewWnd + EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST);
    if (node == NULL)
    {
        return NULL;
    }

    while (node->Next != NULL)
    {
        node = node->Next;
    }

    node->Next = (EQ::MapLabel*)malloc(sizeof(EQ::MapLabel));

    node->Next->Next = NULL;
    node->Next->Prev = node;

    node->Next->Location = mapLabel->Location;
    node->Next->Color = mapLabel->Color;
    node->Next->Size = mapLabel->Size;
    node->Next->Label = mapLabel->Label;
    node->Next->Layer = mapLabel->Layer;
    node->Next->Width = mapLabel->Width;
    node->Next->Height = mapLabel->Height;

    node->Next->Data = mapLabel->Data;

    return node;
}

void EQ_MapWindow_RemoveLabelByData(uint32_t data)
{
    uint32_t mapViewWnd = EQ_ReadMemory<uint32_t>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        return;
    }

    EQ::MapLabel* node = EQ_ReadMemory<EQ::MapLabel*>(mapViewWnd + EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST);
    if (node == NULL)
    {
        return;
    }

    EQ::MapLabel* first = node;

    //std::cout << "first: " << first->Label << std::endl;

    while (node->Next != NULL)
    {
        node = node->Next;
    }

    EQ::MapLabel* last = node;

    //std::cout << "last: " << last->Label << std::endl;

    node = first;

    while (node != NULL)
    {
        EQ::MapLabel* after  = node->Next;
        EQ::MapLabel* before = node->Prev;

        if (node->Data == data)
        {
            //std::cout << "remove: " << node->Label << std::endl;

            if (node == first && node == last)
            {
                node = NULL;
            }
            else if (node == first)
            {
                first = node->Next;
                first->Prev = NULL;
            }
            else if (node == last)
            {
                last = node->Prev;
                last->Next = NULL;
            }
            else
            {
                before->Next = after;
                after->Prev  = before;
            }

            node = NULL;
            free(node);
        }

        node = after;
    }
}

bool EQ_LootItemByName(const char* name)
{
    uint32_t lootWindow = EQ_ReadMemory<uint32_t>(EQ_POINTER_CLootWnd);
    if (lootWindow == NULL)
    {
        return false;
    }

    int lootWindowIsVisible = EQ_ReadMemory<uint8_t>(lootWindow + EQ_OFFSET_WINDOW_IS_VISIBLE);
    if (lootWindowIsVisible == 0)
    {
        return false;
    }

    bool result = false;

    for (size_t i = 0; i < EQ_NUM_LOOT_WINDOW_SLOTS; i++)
    {
        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(lootWindow + (EQ_OFFSET_CLootWnd_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            continue;
        }

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName == NULL)
        {
            continue;
        }

        if (strlen(itemName) == 0)
        {
            continue;
        }

        if (strstr(itemName, name) != NULL)
        {
            EQ_CLootWnd->RequestLootSlot(i, true);

            result = true;
        }
    }

    return result;
}

uint32_t EQ_GetFontHeight(uint32_t fontSize)
{
    // TODO

    if (fontSize == 2)
    {
        return 14;
    }

    return 14;
}

float EQ_GetAverageFps()
{
    // average frames per second

    uint32_t baseAddress = EQ_ReadMemory<uint32_t>(EQ_GRAPHICS_DLL_POINTER_BASE_ADDRESS);
    if (baseAddress == NULL)
    {
        return 0.0f;
    }

    return EQ_ReadMemory<float>(baseAddress + EQ_GRAPHICS_DLL_OFFSET_FRAMES_PER_SECOND);
}

bool EQ_HasTimePassed(uint32_t& timer, uint32_t& delay)
{
    uint32_t currentTime = EQ_GetTimer();

    if ((currentTime - timer) > delay)
    {
        timer = currentTime;
        return true;
    }

    return false;
}

void EQ_SetViewActorBySpawn(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    uint32_t actorInstance = EQ_ReadMemory<uint32_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_ACTOR_INFO);
    if (actorInstance == NULL)
    {
        return;
    }

    EQ_CDisplay->SetViewActor(actorInstance);
}

void EQ_ResetViewActor()
{
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetViewActorBySpawn(playerSpawn);
}

std::string EQ_GetSpawnMapLocationString(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return "NULL";
    }

    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
    memcpy(spawnName, (void*)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

    EQ_String_ReplaceSpacesWithUnderscores(spawnName);

    float spawnY = EQ_GetSpawnY(spawnInfo);
    float spawnX = EQ_GetSpawnX(spawnInfo);
    float spawnZ = EQ_GetSpawnZ(spawnInfo);

    // -X, -Y, Z, red, green, blue, size, name
    // note X and Y are negative
    std::stringstream ss;
    ss.precision(5);
    ss << "P " <<  -spawnX << ", " << -spawnY << ", " << spawnZ << ", 192, 0, 0, 2, " << spawnName;

    return ss.str();
}

std::string EQ_GetSpawnEspCustomLocationString(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return "NULL";
    }

    float spawnY = EQ_GetSpawnY(spawnInfo);
    float spawnX = EQ_GetSpawnX(spawnInfo);
    float spawnZ = EQ_GetSpawnZ(spawnInfo);

    // y x z red green blue size text
    std::stringstream ss;
    ss.precision(5);
    ss << spawnY << " " << spawnX << " " << spawnZ << " " << "255 128 255 2 placeholder";

    return ss.str();
}

void EQ_CopySpawnMapLocationToClipboard(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    std::string mapLocation = EQ_GetSpawnMapLocationString(spawnInfo);

    EQ_CopyStringToClipboard(mapLocation);
}

void EQ_CopySpawnEspCustomLocationToClipboard(uint32_t spawnInfo)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    std::string espCustomLocation = EQ_GetSpawnEspCustomLocationString(spawnInfo);

    EQ_CopyStringToClipboard(espCustomLocation);
}

uint32_t EQ_GetMapViewMap()
{
    uint32_t mapViewWnd = EQ_ReadMemory<uint32_t>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        return NULL;
    }

    return mapViewWnd + EQ_OFFSET_CMapViewWnd_MAP;
}

void EQ_UpdateMap()
{
    uint32_t mapViewWnd = EQ_ReadMemory<uint32_t>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        return;
    }

    // force map to update
    EQ_WriteMemory<uint8_t>(mapViewWnd + EQ_OFFSET_CMapViewWnd_SHOULD_UPDATE_MAP, 0x01);
}

bool EQ_IsWindowVisible(uint32_t windowPointer)
{
    uint32_t window = EQ_ReadMemory<uint32_t>(windowPointer);
    if (window == NULL)
    {
        return false;
    }

    int isVisible = EQ_ReadMemory<uint8_t>(window + EQ_OFFSET_WINDOW_IS_VISIBLE);
    if (isVisible == 0)
    {
        return false;
    }

    return true;
}

std::string EQ_GetExecuteCommandName(uint32_t commandIndex)
{
    if (commandIndex > (EQ_NUM_EXECUTECMD - 1))
    {
        return "Unknown Command";
    }

    char* commandName = EQ_ReadMemory<char*>(EQ_EXECUTECMD_LIST + (commandIndex * 4));

    if (commandName == NULL || strlen(commandName) == 0)
    {
        return "Unknown Command";
    }

    return commandName;
}

void EQ_FixHeading(float& heading)
{
    if (heading < 0.0f)
    {
        heading = heading + EQ_HEADING_MAX;
    }
}

void EQ_TurnPlayerTowardsLocation(float y, float x)
{
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);

    float locationHeading = EQ_GetBearing(playerY, playerX, y, x);

    EQ_WriteMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_INFO_HEADING, locationHeading);
}

void EQ_Door_SetState(uint32_t doorInfo, uint8_t doorState)
{
    ((EQSwitch*)doorInfo)->ChangeState(doorState, 0, 0);
}

void EQ_WalkPlayerToLocation(float y, float x)
{
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_TurnPlayerTowardsLocation(y, x);

    EQ_SetAutoRun(true);
}

void EQ_SetFollowSpawn(uint32_t spawnInfo)
{
    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_FOLLOW_SPAWN_INFO, spawnInfo);
}

uint32_t EQ_GetSpawnNearestToLocation(float y, float x, float z)
{
    std::map<float, uint32_t> distanceList;

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        float spawnY = EQ_GetSpawnY(spawn);
        float spawnX = EQ_GetSpawnX(spawn);
        float spawnZ = EQ_GetSpawnZ(spawn);

        float distance = EQ_CalculateDistance3d(x, y, z, spawnX, spawnY, spawnZ);

        distanceList.insert(std::make_pair(distance, spawn));

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    return distanceList.begin()->second;
}

void EQ_SetSwimmingSkillMax()
{
    uint32_t charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        return;
    }

    EQ_WriteMemory<uint8_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_SKILL_SWIMMING, EQ_SKILL_MAX);
}

void EQ_SetWindowTitle(const char* text)
{
    HWND window = EQ_GetWindow();
    if (window != NULL)
    {
        SetWindowTextA(window, text);
    }
}

void EQ_SetSpawnHeight(uint32_t spawnInfo, float height)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    if (height < 1.0f)
    {
        height = 1.0f;
    }

    ((EQPlayer*)spawnInfo)->ChangeHeight(height);
}

void EQ_DoHotButton(uint32_t buttonNumber)
{
    uint32_t buttonIndex = buttonNumber - 1; // convert number to index that starts at 0

    if (buttonIndex < (EQ_HOTBUTTON_NUMBER_MIN - 1) || buttonIndex > (EQ_HOTBUTTON_NUMBER_MAX - 1))
    {
        return;
    }

    EQ_CHotButtonWnd->DoHotButton(buttonIndex, 0);
}

void EQ_DisplayText(const char* text, uint32_t duration)
{
    uint32_t windowWidth = EQ_GetWindowWidth();
    uint32_t windowHeight = EQ_GetWindowHeight();

    EQ_CTextOverlay->DisplayText(text, EQ_TEXT_COLOR_WHITE, 15, 192, (int)(windowWidth * 0.5f), (int)(windowHeight * 0.3f), duration);
}

void EQ_LoadGraphicsDllFunctions()
{
    uint32_t baseAddress = EQ_ReadMemory<uint32_t>(EQ_GRAPHICS_DLL_POINTER_BASE_ADDRESS);

    uint32_t addressDrawLine = baseAddress + EQ_GRAPHICS_DLL_OFFSET_DrawLine;
    EQGraphicsDLL__DrawLine = (EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine)addressDrawLine;

    uint32_t addressDrawQuad = baseAddress + EQ_GRAPHICS_DLL_OFFSET_DrawQuad;
    EQGraphicsDLL__DrawQuad = (EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad)addressDrawQuad;
}

void EQ_SetTarget(uint32_t spawnInfo)
{
    EQ_WriteMemory<uint32_t>(EQ_POINTER_SPAWN_INFO_TARGET, spawnInfo);
}

void EQ_SetTargetByName(const char* name, float maxDistance)
{
    if (name == NULL)
    {
        return;
    }

    std::multimap<float, uint32_t> distanceList;

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        if (strlen(spawnName) < EQ_SPAWN_NAME_LENGTH_MIN)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        float spawnY = EQ_GetSpawnY(spawn);
        float spawnX = EQ_GetSpawnX(spawn);
        float spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, spawnX, spawnY, spawnZ);
        if (spawnDistance > maxDistance)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        distanceList.insert(std::make_pair(spawnDistance, spawn));

        spawn = EQ_GetNextSpawn(spawn); // next
    }

/*
    for (auto& distancePair : distanceList)
    {
        uint32_t spawn = distancePair.second;

        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        std::cout << "Distance List: " << spawnName << " : " << distancePair.first << std::endl;
    }
*/

    for (auto& distancePair : distanceList)
    {
        uint32_t spawn = distancePair.second;
        if (spawn == NULL)
        {
            continue;
        }

        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (void*)(spawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        if (strlen(spawnName) < EQ_SPAWN_NAME_LENGTH_MIN)
        {
            continue;
        }

        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        if (spawnType == EQ_SPAWN_TYPE_PLAYER_CORPSE || spawnType == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            const char* corpseText = " corpse";
            size_t corpseTextLength = strlen(corpseText);

            if (strlen(name) > corpseTextLength && strstr(name, corpseText) != NULL)
            {
                std::string str = name;
                std::string tokenName = str.substr(0, str.size() - corpseTextLength);
                std::string tokenType = str.substr(str.size() - corpseTextLength, corpseTextLength);

                if (tokenType == corpseText)
                {
                    if (strcmp(spawnName, tokenName.c_str()) == 0)
                    {
                        EQ_SetTarget(spawn);
                        return;
                    }

                    if (strstr(spawnName, tokenName.c_str()) != NULL)
                    {
                        EQ_SetTarget(spawn);
                        return;
                    }
                }
            }

            continue;
        }

        uint32_t spawnIdPetOwner = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID);

        if (spawnIdPetOwner != 0)
        {
            const char* petText = " pet";
            size_t petTextLength = strlen(petText);

            if (strlen(name) > petTextLength && strstr(name, petText) != NULL)
            {
                std::string str = name;
                std::string tokenName = str.substr(0, str.size() - petTextLength);
                std::string tokenType = str.substr(str.size() - petTextLength, petTextLength);

                if (tokenType == petText)
                {
                    if (strcmp(spawnName, tokenName.c_str()) == 0)
                    {
                        EQ_SetTarget(spawn);
                        return;
                    }

                    if (strstr(spawnName, tokenName.c_str()) != NULL)
                    {
                        EQ_SetTarget(spawn);
                        return;
                    }
                }
            }

            continue;
        }

        if (strcmp(spawnName, name) == 0)
        {
            EQ_SetTarget(spawn);
            return;
        }

        if (strstr(spawnName, name) != NULL)
        {
            EQ_SetTarget(spawn);
            return;
        }
    }
}

bool EQ_IsContainerWindowOpen()
{
    uint32_t containerManager = EQ_ReadMemory<uint32_t>(EQ_POINTER_CONTAINER_MANAGER);
    if (containerManager == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < EQ_NUM_CONTAINERS; i++)
    {
        uint32_t containerWindowPointer = containerManager + EQ_OFFSET_CONTAINER_MANAGER_CONTAINER_WINDOW_INFO_FIRST + (i * 4);
        if (containerWindowPointer == NULL)
        {
            continue;
        }

        if (EQ_IsWindowVisible(containerWindowPointer) == true)
        {
            return true;
        }
    }

    return false;
}
