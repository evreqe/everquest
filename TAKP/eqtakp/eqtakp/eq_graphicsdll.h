#pragma once

#include "eq.h"

const char* EQ_STRING_GRAPHICS_DLL_NAME           = "EQGfx_Dx8.dll";
const char* EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE = "eqgfx_dx8.dll";

#define EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE 0x007F9C50

#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation 0x007F9AE4

#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx 0x007F98B4

#define EQ_GRAPHICS_DLL_DEFERRED_2D_ITEMS_MAX 4000 // t3dDefer...

#define EQ_GRAPHICS_DLL_WORLD_SPACE_TO_SCREEN_SPACE_RESULT_FAILURE 0xFFFF3D3E // world space to screen space failed because the location is not on screen

// create actor ex
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx)(int a1, EQ::ActorDefinition_ptr a2, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx EQGraphicsDLL__t3dCreateActorEx;

// destroy actor
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDestroyActor)(int a1, EQ::ActorInstance_ptr a2);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDestroyActor EQGraphicsDLL__t3dDestroyActor;

// world space to screen space
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)(uint32_t cameraDataPointer, EQ::Location*, float* resultX, float* resultY);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace EQGraphicsDLL__t3dWorldSpaceToScreenSpace;

// draw line
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine)(EQ::Line*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine EQGraphicsDLL__t3dDeferLine; // eqgfx_dx8.dll+405A0

// draw rectangle
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect)(EQ::Rect*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect EQGraphicsDLL__t3dDeferRect; // eqgfx_dx8.dll+406C0

// draw quad (filled rectangle)
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad)(EQ::Rect*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad EQGraphicsDLL__t3dDeferQuad; // eqgfx_dx8.dll+40820

bool EQ_GraphicsDLL_LoadFunctions()
{
    HINSTANCE graphicsDLL = LoadLibraryA(EQ_STRING_GRAPHICS_DLL_NAME);
    if (graphicsDLL == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dCreateActorEx = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx)GetProcAddress(graphicsDLL, "t3dCreateActorEx");
    if (EQGraphicsDLL__t3dCreateActorEx == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dDestroyActor = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDestroyActor)GetProcAddress(graphicsDLL, "t3dDestroyActor");
    if (EQGraphicsDLL__t3dDestroyActor == NULL)
    {
        return false;
    }

    EQGraphicsDLL__t3dWorldSpaceToScreenSpace = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)GetProcAddress(graphicsDLL, "t3dWorldSpaceToScreenSpace");
    if (EQGraphicsDLL__t3dWorldSpaceToScreenSpace == NULL)
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

    return true;
}