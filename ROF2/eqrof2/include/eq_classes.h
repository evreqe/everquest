#pragma once

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

/******************************************************************************************************/

class EQGraphicsDLL;

class EQGraphicsDLL
{
public:
    int EQGraphicsDLL::DrawLine(EQLINE* lineBegin, EQLINE* lineEnd, DWORD argbColor);
    int EQGraphicsDLL::DrawQuad(EQRECT* rect, DWORD argbColor);
};

EQGraphicsDLL** EQ_ppEQGraphicsDLL;
EQGraphicsDLL* EQ_EQGraphicsDLL;

typedef int (__thiscall* EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine)(void* pThis, EQLINE* lineBegin, EQLINE* lineEnd, DWORD argbColor);
EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine EQGraphicsDLL__DrawLine = NULL;

typedef int (__thiscall* EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad)(void* pThis, EQRECT* rect, DWORD argbColor);
EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad EQGraphicsDLL__DrawQuad = NULL;

/******************************************************************************************************/

class CDisplay;

class CDisplay
{
public:
    void CDisplay::CreatePlayerActor(DWORD spawnInfo, int a2, int a3, int a4, int a5);
    void CDisplay::DeleteActor(DWORD actorInstance);
    void CDisplay::SetViewActor(DWORD actorInstance);
    void CDisplay::SetViewActorByName(const char* spawnName);
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, int color);
};

CDisplay** EQ_ppCDisplay;
CDisplay* EQ_CDisplay;

//typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)(void* pThis, DWORD spawnInfo, int a2, int a3, int a4, int a5);
//EQ_FUNCTION_AT_ADDRESS(void CDisplay::CreatePlayerActor(DWORD spawnInfo, int a2, int a3, int a4, int a5), EQ_FUNCTION_CDisplay__CreatePlayerActor);

//typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__DeleteActor)(void* pThis, DWORD actorInstance);
//EQ_FUNCTION_AT_ADDRESS(void CDisplay::DeleteActor(DWORD actorInstance), EQ_FUNCTION_CDisplay__DeleteActor);

//typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetViewActor)(void* pThis, DWORD actorInstance);
//EQ_FUNCTION_AT_ADDRESS(void CDisplay::SetViewActor(DWORD actorInstance), EQ_FUNCTION_CDisplay__SetViewActor);

//typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__SetViewActorByName)(void* pThis, const char* spawnName);
//EQ_FUNCTION_AT_ADDRESS(void CDisplay::SetViewActorByName(const char* spawnName), EQ_FUNCTION_CDisplay__SetViewActorByName);

EQ_FUNCTION_AT_ADDRESS(int CDisplay::WriteTextHD2(const char* text, int x, int y, int color), EQ_FUNCTION_CDisplay__WriteTextHD2);

/******************************************************************************************************/

typedef int (__cdecl* EQ_FUNCTION_TYPE_DrawNetStatus)(int, unsigned short, unsigned short, unsigned short x, unsigned short y, int, unsigned short, unsigned long, long, unsigned long);