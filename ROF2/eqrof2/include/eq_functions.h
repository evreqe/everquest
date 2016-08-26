#pragma once

#include <string>
#include <map>

#include <cstdint>
#include <cstring>
#include <cmath>

#include <windows.h>

#include "eq.h"
#include "eq_classes.h"

template <class T>
T EQ_ReadMemory(DWORD address)
{
#ifdef EQ_DEBUG
    EQ_Log("EQ_ReadMemory address: ", address);
#endif

    T* buffer = (T*)address;
    return (*buffer);
}

template <class T>
void EQ_WriteMemory(DWORD address, T value)
{
#ifdef EQ_DEBUG
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

/******************************************************************************************************/

void EQ_AddBaseAddressToAddress(DWORD& address)
{
    DWORD baseAddress = (DWORD)GetModuleHandle(NULL);

    address = address + baseAddress;
}

void EQ_InitializeAddressesAndOffsets()
{
    EQ_AddBaseAddressToAddress(EQ_POINTER_GAME_BASE_ADDRESS);
    EQ_AddBaseAddressToAddress(EQ_POINTER_GRAPHICS_DLL_BASE_ADDRESS);

    EQ_AddBaseAddressToAddress(EQ_POINTER_EQGraphicsDLL);

    EQ_AddBaseAddressToAddress(EQ_POINTER_SPAWN_INFO_FIRST);
    EQ_AddBaseAddressToAddress(EQ_POINTER_SPAWN_INFO_PLAYER);
    EQ_AddBaseAddressToAddress(EQ_POINTER_SPAWN_INFO_TARGET);

    EQ_AddBaseAddressToAddress(EQ_POINTER_CDisplay);
    EQ_AddBaseAddressToAddress(EQ_FUNCTION_CDisplay__WriteTextHD2);

    EQ_AddBaseAddressToAddress(EQ_FUNCTION_DrawNetStatus);

    //

    EQ_ppEQGraphicsDLL = (EQGraphicsDLL**)EQ_POINTER_EQGraphicsDLL;
    EQ_EQGraphicsDLL = (*EQ_ppEQGraphicsDLL);

    EQ_ppCDisplay = (CDisplay**)EQ_POINTER_CDisplay;
    EQ_CDisplay = (*EQ_ppCDisplay);
}

void EQ_GraphicsDll_LoadFunctions()
{
    DWORD baseAddress = EQ_ReadMemory<DWORD>(EQ_POINTER_GRAPHICS_DLL_BASE_ADDRESS);

    DWORD addressDrawLine = baseAddress + EQ_OFFSET_GRAPHICS_DLL_DrawLine;
    EQGraphicsDLL__DrawLine = (EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawLine)addressDrawLine;

    DWORD addressDrawQuad = baseAddress + EQ_OFFSET_GRAPHICS_DLL_DrawQuad;
    EQGraphicsDLL__DrawQuad = (EQ_FUNCTION_TYPE_EQGraphicsDLL__DrawQuad)addressDrawQuad;
}

DWORD EQ_GetCameraInfo()
{
    DWORD display = EQ_ReadMemory<DWORD>(EQ_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<DWORD>(display + EQ_OFFSET_CDisplay_CAMERA_INFO);
}

bool EQ_DrawQuad(float x, float y, float width, float height, unsigned int argbColor)
{
    if (EQGraphicsDLL__DrawQuad == NULL)
    {
        return false;
    }

    EQRECT rect;

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

    EQGraphicsDLL__DrawQuad(EQ_EQGraphicsDLL, &rect, argbColor);

    return true;
}

bool EQ_DrawQuadEx(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, unsigned int argbColor)
{
    if (EQGraphicsDLL__DrawQuad == NULL)
    {
        return false;
    }

    EQRECT rect;

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

    EQGraphicsDLL__DrawQuad(EQ_EQGraphicsDLL, &rect, argbColor);

    return true;
}

bool EQ_DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, unsigned int argbColor)
{
    if (EQGraphicsDLL__DrawLine == NULL)
    {
        return false;
    }

    EQLINE lineBegin;
    lineBegin.X = x1;
    lineBegin.Y = y1;
    lineBegin.Z = z1;

    EQLINE lineEnd;
    lineEnd.X = x2;
    lineEnd.Y = y2;
    lineEnd.Z = z2;

    EQGraphicsDLL__DrawLine(EQ_EQGraphicsDLL, &lineBegin, &lineEnd, argbColor);

    return true;
}

bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, int& screenX, int& screenY)
{
    // this function uses hardcoded offsets

    DWORD cameraInfo = EQ_GetCameraInfo();
    if (cameraInfo == NULL)
    {
        return false;
    }

    FLOAT cameraInfo_0x1A0 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x0C); // boolean for if the world should be drawn
    FLOAT cameraInfo_0x1A4 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x10);
    FLOAT cameraInfo_0x1A8 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x14);
    FLOAT cameraInfo_0x198 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x38); // screen width  divided by two
    FLOAT cameraInfo_0x19C = EQ_ReadMemory<FLOAT>(cameraInfo + 0x3C); // screen height divided by two
    FLOAT cameraInfo_0x22C = EQ_ReadMemory<FLOAT>(cameraInfo + 0x48);
    FLOAT cameraInfo_0x238 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x54);
    FLOAT cameraInfo_0x244 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x60);
    FLOAT cameraInfo_0x260 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x84);
    FLOAT cameraInfo_0x264 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x88);
    FLOAT cameraInfo_0x268 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x8C); // always zero?
    FLOAT cameraInfo_0x26C = EQ_ReadMemory<FLOAT>(cameraInfo + 0x90);
    FLOAT cameraInfo_0x270 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x94);
    FLOAT cameraInfo_0x274 = EQ_ReadMemory<FLOAT>(cameraInfo + 0x98);
    FLOAT cameraInfo_0x1AC = EQ_ReadMemory<FLOAT>(cameraInfo + 0xBC);
    FLOAT cameraInfo_0x1B0 = EQ_ReadMemory<FLOAT>(cameraInfo + 0xC0);
    FLOAT cameraInfo_0x1B4 = EQ_ReadMemory<FLOAT>(cameraInfo + 0xC4);

    float v4 = cameraInfo_0x1AC - worldY; // changed add to substract because Seeds of Destruction has backwards coordinates
    float v5 = cameraInfo_0x1B0 - worldX; // changed add to substract because Seeds of Destruction has backwards coordinates
    float v6 = cameraInfo_0x1B4 - worldZ; // changed add to substract because Seeds of Destruction has backwards coordinates

    float v10 = v6 * cameraInfo_0x268 + v5 * cameraInfo_0x264 + v4 * cameraInfo_0x260;
    float v11 = v6 * cameraInfo_0x274 + v5 * cameraInfo_0x270 + v4 * cameraInfo_0x26C;
    float v7  = v6 * cameraInfo_0x244 + v5 * cameraInfo_0x238 + v4 * cameraInfo_0x22C;

    // point is offscreen
    if (v7 >= cameraInfo_0x1A0) // changed <= to >= because Seeds of Destruction client has backwards coordinates
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

    float a3 = v10 * v8 + cameraInfo_0x198;
    float a4 = cameraInfo_0x19C - v8 * v11;

    screenX = (int)a3;
    screenY = (int)a4;

    // point is offscreen
    //int windowWidth  = EQ_GetWindowWidth();
    //int windowHeight = EQ_GetWindowHeight();
    //if (screenX < 0 || screenX > windowWidth || screenY < 0 || screenY > windowHeight)
    //{
        //screenX = -1;
        //screenY = -1;

        //return false;
    //}

    return true;
}

