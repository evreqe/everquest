#pragma once

#include "eq.h"

const char* g_EQGraphicsDLLName          = "EQGfx_Dx8.dll";
const char* g_EQGraphicsDLLNameLowercase = "eqgfx_dx8.dll";

#define EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE 0x007F9C50

////#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation 0x007F9AE4

// world space to screen space
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)(uint32_t cameraDataPointer, EQ::Location* location, float* screenX, float* screenY);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace EQGraphicsDLL__t3dWorldSpaceToScreenSpace;




uint32_t EQ_GraphicsDLL_GetBaseAddress();
bool EQ_GraphicsDLL_LoadFunctions();

uint32_t EQ_GraphicsDLL_GetBaseAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE);
}

bool EQ_GraphicsDLL_LoadFunctions()
{
    return true;

    HINSTANCE graphicsDLL = LoadLibraryA(g_EQGraphicsDLLName);
    if (graphicsDLL == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dWorldSpaceToScreenSpace = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)GetProcAddress(graphicsDLL, "t3dWorldSpaceToScreenSpace");
    if (EQGraphicsDLL__t3dWorldSpaceToScreenSpace == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferTextA = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferTextA)GetProcAddress(graphicsDLL, "t3dDeferTextA");
    if (EQGraphicsDLL__t3dDeferTextA == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferLine = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine)GetProcAddress(graphicsDLL, "t3dDeferLine");
    if (EQGraphicsDLL__t3dDeferLine == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferRect = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect)GetProcAddress(graphicsDLL, "t3dDeferRect");
    if (EQGraphicsDLL__t3dDeferRect == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferQuad = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad)GetProcAddress(graphicsDLL, "t3dDeferQuad");
    if (EQGraphicsDLL__t3dDeferQuad == NULL)
    {
        return false;
    }

    ////uint32_t graphicsDLLBaseAddress = EQ_GraphicsDLL_GetBaseAddress();

    ////EQGraphicsDLL__t3dRenderDeferred2DItems =
    ////(EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferred2DItems)(graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferred2DItems);

    return true;
}