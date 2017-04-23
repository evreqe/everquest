#pragma once

const char* EQ_STRING_GRAPHICS_DLL_NAME           = "EQGfx_Dx8.dll";
const char* EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE = "eqgfx_dx8.dll";

#define EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE 0x007F9C50

#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation 0x007F9AE4

#define EQ_GRAPHICS_DLL_DEFERRED_2D_ITEMS_MAX 4000 // t3dDefer...

#define EQ_ADDRESS_POINTER_CAMERA_DATA 0x0063B924 // pass this as first argument to graphics DLL world space to screen space funtion

#define EQ_GRAPHICS_DLL_WORLD_SPACE_TO_SCREEN_SPACE_RESULT_FAILURE 0xFFFF3D3E // world space to screen space failed because the location is not on screen

// world space to screen space
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)(uint32_t cameraDataPointer, EQ::Location*, float* resultX, float* resultY);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace EQGraphicsDLL__t3dWorldSpaceToScreenSpace;

// draw line
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine)(EQ::Line*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine EQGraphicsDLL__t3dDeferLine;

// draw rectangle
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect)(EQ::Rect*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect EQGraphicsDLL__t3dDeferRect;

// draw quad (filled rectangle)
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad)(EQ::Rect*, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad EQGraphicsDLL__t3dDeferQuad;

bool EQ_GraphicsDLL_LoadFunctions()
{
    HINSTANCE graphicsDLL = LoadLibraryA(EQ_STRING_GRAPHICS_DLL_NAME);
    if (graphicsDLL == nullptr)
    {
        return false;
    }

    EQGraphicsDLL__t3dWorldSpaceToScreenSpace = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)GetProcAddress(graphicsDLL, "t3dWorldSpaceToScreenSpace");
    if (EQGraphicsDLL__t3dWorldSpaceToScreenSpace == nullptr)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferLine = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine)GetProcAddress(graphicsDLL, "t3dDeferLine");
    if (EQGraphicsDLL__t3dDeferLine == nullptr)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferRect = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect)GetProcAddress(graphicsDLL, "t3dDeferRect");
    if (EQGraphicsDLL__t3dDeferRect == nullptr)
    {
        return false;
    }

    EQGraphicsDLL__t3dDeferQuad = (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad)GetProcAddress(graphicsDLL, "t3dDeferQuad");
    if (EQGraphicsDLL__t3dDeferQuad == nullptr)
    {
        return false;
    }

    return true;
}