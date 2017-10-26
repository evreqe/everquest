#pragma once

#include "eq.h"

const char* EQ_STRING_GRAPHICS_DLL_NAME           = "EQGfx_Dx8.dll";
const char* EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE = "eqgfx_dx8.dll";

#define EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE 0x007F9C50

#define EQ_ADDRESS_POINTER_IDirect3DDevice8 0x10A4F92C

IDirect3DDevice8** EQ_CLASS_POINTER_IDirect3DDevice8_pptr = (IDirect3DDevice8**)EQ_ADDRESS_POINTER_IDirect3DDevice8;
#define EQ_CLASS_POINTER_IDirect3DDevice8 (*EQ_CLASS_POINTER_IDirect3DDevice8_pptr)

uintptr_t* EQ_VTABLE_IDirect3DDevice8 = *(uintptr_t**)EQ_CLASS_POINTER_IDirect3DDevice8;

#define EQ_VTABLE_INDEX_IDirect3DDevice8__Reset 14
#define EQ_VTABLE_INDEX_IDirect3DDevice8__Present 15
#define EQ_VTABLE_INDEX_IDirect3DDevice8__BeginScene 34
#define EQ_VTABLE_INDEX_IDirect3DDevice8__EndScene 35
#define EQ_VTABLE_INDEX_IDirect3DDevice8__Clear 36
#define EQ_VTABLE_INDEX_IDirect3DDevice8__SetRenderState 50
#define EQ_VTABLE_INDEX_IDirect3DDevice8__DrawPrimitive 70
#define EQ_VTABLE_INDEX_IDirect3DDevice8__DrawIndexedPrimitive 71
#define EQ_VTABLE_INDEX_IDirect3DDevice8__SetStreamSource 83

#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation 0x007F9AE4

#define EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dCreateActorEx 0x007F98B4
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dCreateActorEx = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferredPolygons 0x65070
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferredPolygons = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferred2DItems 0x6B7F0
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dRenderDeferred2DItems = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dSelectTexture 0x64CD0
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dSelectTexture = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dPaintHierarchicalSprite 0x442B0
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dPaintHierarchicalSprite = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dPaintHSprite 0x44510
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__t3dPaintHSprite = NULL;

#define EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__s3dPaintDMSprite2 0x489F0
uint32_t EQ_ADDRESS_FUNCTION_EQGraphicsDLL__s3dPaintDMSprite2 = NULL;

#define EQ_GRAPHICS_DLL_DEFERRED_2D_ITEMS_MAX 4000 // t3dDefer...

#define EQ_GRAPHICS_DLL_WORLD_SPACE_TO_SCREEN_SPACE_RESULT_FAILURE 0xFFFF3D3E // world space to screen space failed because the location is not on screen

#define EQ_GRAPHICS_DLL_OFFSET_USE_TNL_BOOLEAN   0xF9238 // uint32_t ; g_bUseTNL ; hardware transform and lightning
#define EQ_GRAPHICS_DLL_OFFSET_USE_UMBRA_BOOLEAN 0xF923C // uint32_t ; b_bUseUmbra ; occlusion culling

#define EQ_GRAPHICS_DLL_OFFSET_TOGGLE_FPS_BOOLEAN 0xA4F770 // uint32_t ; frames per second

#define EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_STATIC  0x873278 // DMSprite: crates, barrels, doors, trees, chairs, tables, etc
#define EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_DYNAMIC 0x9F9C78 // HierachialSprite: lamps with fire emitters, trees with moving branches, players/npcs

#define EQ_GRAPHICS_DLL_NUM_ACTOR_LIST_ACTORS_MAX 4096

#define EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_SIZE 0x10
#define EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_OFFSET_ACTOR_INSTANCE 0x10

// set render state
typedef HRESULT (APIENTRY* EQ_FUNCTION_TYPE_EQIDirect3DDevice8__SetRenderState)
(
    D3DRENDERSTATETYPE state,
    DWORD value
);
EQ_FUNCTION_TYPE_EQIDirect3DDevice8__SetRenderState EQIDirect3DDevice8__SetRenderState;

// draw indexed primitive
typedef HRESULT (APIENTRY* EQ_FUNCTION_TYPE_EQIDirect3DDevice8__DrawIndexedPrimitive)
(
    LPDIRECT3DDEVICE8 device,
    D3DPRIMITIVETYPE primitiveType,
    UINT minIndex,
    UINT numVertices,
    UINT startIndex,
    UINT primitiveCount
);
EQ_FUNCTION_TYPE_EQIDirect3DDevice8__DrawIndexedPrimitive EQIDirect3DDevice8__DrawIndexedPrimitive;

// reset
typedef HRESULT (APIENTRY* EQ_FUNCTION_TYPE_EQIDirect3DDevice8__Reset)
(
    LPDIRECT3DDEVICE8 device,
    D3DPRESENT_PARAMETERS* presentationParameters
);
EQ_FUNCTION_TYPE_EQIDirect3DDevice8__Reset EQIDirect3DDevice8__Reset;

// create actor ex
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx)(int a1, EQ::ActorDefinition_ptr actorDefinition, char* a3, int a4, int a5, int a6, float a7, float a8, int a9, int a10);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dCreateActorEx EQGraphicsDLL__t3dCreateActorEx;

// destroy actor
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDestroyActor)(int CDisplay__Unknown004, EQ::ActorInstance_ptr actorInstance);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDestroyActor EQGraphicsDLL__t3dDestroyActor;

// world space to screen space
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace)(uint32_t cameraDataPointer, EQ::Location* location, float* screenX, float* screenY);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dWorldSpaceToScreenSpace EQGraphicsDLL__t3dWorldSpaceToScreenSpace;

// draw text
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferTextA)(const char* text, uint32_t font, EQ::XYZ_ptr xyz, uint32_t colorARGB, int zero);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferTextA EQGraphicsDLL__t3dDeferTextA;

// draw line
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine)(EQ::Line* line, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferLine EQGraphicsDLL__t3dDeferLine; // eqgfx_dx8.dll+405A0

// draw rectangle
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect)(EQ::Rect* rect, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferRect EQGraphicsDLL__t3dDeferRect; // eqgfx_dx8.dll+406C0

// draw quad (filled rectangle)
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad)(EQ::Rect* rect, uint32_t colorARGB);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dDeferQuad EQGraphicsDLL__t3dDeferQuad; // eqgfx_dx8.dll+40820

// render deferred polygons
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferredPolygons)(void);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferredPolygons EQGraphicsDLL__t3dRenderDeferredPolygons;

// render deferred 2D items
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferred2DItems)(int unknown);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferred2DItems EQGraphicsDLL__t3dRenderDeferred2DItems;

// select texture
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dSelectTexture)(EQ::Texture_ptr texture);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dSelectTexture EQGraphicsDLL__t3dSelectTexture;

// paint hierarchical sprite
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dPaintHierarchicalSprite)(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dPaintHierarchicalSprite EQGraphicsDLL__t3dPaintHierarchicalSprite;

// paint hsprite
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dPaintHSprite)(EQ::ActorInstance_ptr actorInstance, int* hierarchicalSpriteInstance, int* renderContext, int* world);
EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dPaintHSprite EQGraphicsDLL__t3dPaintHSprite;

// paint dm sprite 2
typedef int (__cdecl* EQ_FUNCTION_TYPE_EQGraphicsDLL__s3dPaintDMSprite2)(int* world, int* renderContext, int* actor);
EQ_FUNCTION_TYPE_EQGraphicsDLL__s3dPaintDMSprite2 EQGraphicsDLL__s3dPaintDMSprite2;

uint32_t EQ_GraphicsDLL_GetBaseAddress();
bool EQ_GraphicsDLL_IsShowFPSEnabled();
void EQ_GraphicsDLL_SetShowFPS(bool bEnabled);
void EQ_GraphicsDLL_SetUseTNL(bool bEnabled);
void EQ_GraphicsDLL_SetUseUmbra(bool bEnabled);
bool EQ_GraphicsDLL_LoadFunctions();

uint32_t EQ_GraphicsDLL_GetBaseAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE);
}

bool EQ_GraphicsDLL_IsShowFPSEnabled()
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();

    return (EQ_ReadMemory<uint32_t>(baseAddress + EQ_GRAPHICS_DLL_OFFSET_TOGGLE_FPS_BOOLEAN) == 1);
}

void EQ_GraphicsDLL_SetShowFPS(bool bEnabled)
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();

    uint32_t value = 0;
    if (bEnabled == true)
    {
        value = 1;
    }

    EQ_WriteMemory<uint32_t>(baseAddress + EQ_GRAPHICS_DLL_OFFSET_TOGGLE_FPS_BOOLEAN, value);
}

void EQ_GraphicsDLL_SetUseTNL(bool bEnabled)
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();

    uint32_t value = 0;
    if (bEnabled == true)
    {
        value = 1;
    }

    EQ_WriteMemory<uint32_t>(baseAddress + EQ_GRAPHICS_DLL_OFFSET_USE_TNL_BOOLEAN, value);
}

void EQ_GraphicsDLL_SetUseUmbra(bool bEnabled)
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();

    uint32_t value = 0;
    if (bEnabled == true)
    {
        value = 1;
    }

    EQ_WriteMemory<uint32_t>(baseAddress + EQ_GRAPHICS_DLL_OFFSET_USE_UMBRA_BOOLEAN, value);
}

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

    uint32_t graphicsDLLBaseAddress = EQ_GraphicsDLL_GetBaseAddress();

    EQGraphicsDLL__t3dRenderDeferred2DItems =
    (EQ_FUNCTION_TYPE_EQGraphicsDLL__t3dRenderDeferred2DItems)(graphicsDLLBaseAddress + EQ_GRAPHICS_DLL_OFFSET_EQGraphicsDLL__t3dRenderDeferred2DItems);

    return true;
}