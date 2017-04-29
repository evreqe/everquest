#pragma once

#include <string>
#include <map>

#include <cstdint>
#include <cstring>
#include <cmath>

#include <windows.h>

#include "eq.h"
#include "eq_macros.h"
#include "eq_structures.h"
#include "eq_classes.h"
#include "eq_pointers.h"
#include "eq_graphicsdll.h"

template <class T>
void EQ_Log(const char* text, T number);

template <class T>
T EQ_ReadMemory(uintptr_t address);

template <class T>
void EQ_WriteMemory(uintptr_t address, T value);

template <class T>
T EQ_ReadMemoryProtected(uint32_t address);

template <class T>
void EQ_WriteMemoryProtected(uint32_t address, T value);

void EQ_ReadMemoryString(uint32_t address, size_t size, char result[]);
void EQ_WriteMemoryString(uint32_t address, const char* value);

void EQ_ToggleBool(bool& b);
float EQ_CalculateDistance(float x1, float y1, float x2, float y2);
float EQ_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2);
void EQ_Rotate2D(float cx, float cy, float& x, float& y, float angle);
float EQ_GetRadians(float degrees);
bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight);
void EQ_ColorARGB_Darken(uint32_t& colorARGB, float percent);
void EQ_CopyStringToClipboard(std::string& str);
void EQ_CXStr_Set(EQ::CXStr** cxstr, char* text);
void EQ_CXStr_Append(EQ::CXStr** cxstr, char* text);
bool EQ_IsInGame();
bool EQ_IsAutoAttackEnabled();
bool EQ_IsNetStatusEnabled();
bool EQ_IsNotTypingInChat();
bool EQ_IsInspectEnabled();
bool EQ_IsShowNPCNamesEnabled();
bool EQ_IsKeyPressedControl();
bool EQ_IsKeyPressedAlt();
bool EQ_IsKeyPressedShift();
bool EQ_IsMouseHoveringOverCXWnd();
void EQ_SetAutoAttack(bool bEnabled);
void EQ_SetFreeCamera(bool bEnabled);
size_t EQ_GetFontTextWidth(char text[], uint32_t fontPointer);
void EQ_DrawTooltipText(char text[], int x, int y, uint32_t fontPointer);
void EQ_DrawText(const char* text, int x, int y, int textColor);
void EQ_DrawTextEx(const char* text, int x, int y, int textColor, uint32_t fontPointer);
void EQ_DrawLine(float x1, float y1, float x2, float y2, uint32_t colorARGB);
void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled = false);
void EQ_WriteChatText(const char* text);
std::string EQ_GetTickTimeString(int ticks);

uint32_t EQ_GetTimer();

EQ::Spawn_ptr EQ_GetPlayerSpawn();
EQ::Spawn_ptr EQ_GetTargetSpawn();
EQ::Spawn_ptr EQ_GetControlledSpawn();
EQ::Spawn_ptr EQ_GetTradeSpawn();
EQ::Spawn_ptr EQ_GetMerchantSpawn();
EQ::Spawn_ptr EQ_GetBankerSpawn();
EQ::Spawn_ptr EQ_GetCorpseSpawn();
EQ::Spawn_ptr EQ_GetGamemasterSpawn();

uint32_t EQ_GetPlayerSpawnAddress();
uint32_t EQ_GetTargetSpawnAddress();
uint32_t EQ_GetControlledSpawnAddress();
uint32_t EQ_GetTradeSpawnAddress();
uint32_t EQ_GetMerchantSpawnAddress();
uint32_t EQ_GetBankerSpawnAddress();
uint32_t EQ_GetCorpseSpawnAddress();
uint32_t EQ_GetGamemasterSpawnAddress();

template <class T>
void EQ_Log(const char* text, T number)
{
    std::fstream file;
    file.open("Logs/eqlog.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

template <class T>
T EQ_ReadMemory(uintptr_t address)
{
#ifdef _DEBUG
    EQ_Log("EQ_ReadMemory address: ", address);
#endif

    T* buffer = (T*)address;
    return (*buffer);
}

template <class T>
void EQ_WriteMemory(uintptr_t address, T value)
{
#ifdef _DEBUG
    EQ_Log("EQ_WriteMemory address: ", address);
#endif

    T* buffer = (T*)address;
    *buffer = value;
}

template <class T>
T EQ_ReadMemoryProtected(uint32_t address)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), PAGE_READWRITE, &oldProtect);

    T* buffer = (T*)address;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), oldProtect, &oldProtect);

    return (*buffer);
}

template <class T>
void EQ_WriteMemoryProtected(uint32_t address, T value)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), PAGE_READWRITE, &oldProtect);

    T* buffer = (T*)address;
    *buffer = value;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), oldProtect, &oldProtect);
}

void EQ_ReadMemoryString(uint32_t address, size_t size, char result[])
{
    char* buffer = new char[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = *(unsigned char*)(address + i);
    }

    result = buffer;

    delete[] buffer;
}

void EQ_WriteMemoryString(uint32_t address, const char* value)
{
    size_t length = strlen(value);

    size_t j = 0;

    for (size_t i = 0; i < length; i++)
    {
        *(unsigned char*)(address + j) = value[i];
        j++;
    }

    *(unsigned char*)(address + j) = '\0';
}

/* game's functions */

#define EQ_ADDRESS_FUNCTION_DrawNetStatus 0x0054D3AE
typedef int (__cdecl* EQ_FUNCTION_TYPE_DrawNetStatus)(int, unsigned short, unsigned short, unsigned short x, unsigned short y, int, unsigned short, unsigned long, long, unsigned long);

#define EQ_ADDRESS_FUNCTION_HandleMouseWheel 0x0055B2E0
typedef int (__cdecl* EQ_FUNCTION_TYPE_HandleMouseWheel)(int mouseWheelDelta);

#define EQ_ADDRESS_FUNCTION_ProcessKeyDown 0x00525B04
typedef int (__cdecl* EQ_FUNCTION_TYPE_ProcessKeyDown)(int key);

#define EQ_ADDRESS_FUNCTION_ProcessKeyUp 0x0052462A
typedef int (__cdecl* EQ_FUNCTION_TYPE_ProcessKeyUp)(int key);

#define EQ_ADDRESS_FUNCTION_ProcessMovementKeys 0x005257FA
typedef int (__cdecl* EQ_FUNCTION_TYPE_ProcessMovementKeys)(int key);

#define EQ_ADDRESS_FUNCTION_GetKey 0x0055AFE2
typedef int (__cdecl* EQ_FUNCTION_TYPE_GetKey)(void);

#define EQ_ADDRESS_FUNCTION_get_bearing 0x004F3777

#define EQ_ADDRESS_FUNCTION_ExecuteCmd 0x0054050C

#define EQ_ADDRESS_FUNCTION_send_message 0x0054E51A

#define EQ_ADDRESS_FUNCTION_CastRay 0x004F20DB
EQ_MACRO_FunctionAtAddress(int __cdecl EQ_CastRay(class EQPlayer* spawn, float y, float x, float z), EQ_ADDRESS_FUNCTION_CastRay);

#define EQ_ADDRESS_FUNCTION_AutoInventory 0x004F0EEB
EQ_MACRO_FunctionAtAddress(int __cdecl EQ_AutoInventory(EQ::Character_ptr character, EQ::Item** item, short unknown = 0), EQ_ADDRESS_FUNCTION_AutoInventory);
typedef int (__cdecl* EQ_FUNCTION_TYPE_AutoInventory)(EQ::Character_ptr character, EQ::Item** item, short unknown);

#define EQ_ADDRESS_FUNCTION_get_melee_range 0x004F3898
EQ_MACRO_FunctionAtAddress(float __cdecl EQ_get_melee_range(class EQPlayer* spawn1, class EQPlayer* spawn2), EQ_ADDRESS_FUNCTION_get_melee_range);

/* functions */

void EQ_ToggleBool(bool& b)
{
    b = !b;
}

float EQ_CalculateDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float EQ_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void EQ_Rotate2D(float cx, float cy, float& x, float& y, float angle)
{
    float radians = angle * (EQ_PI / EQ_HEADING_MAX_HALVED); // 512 / 2 = 256

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

void EQ_CXStr_Set(EQ::CXStr** cxstr, char* text)
{ 
    EQClass::CXStr* temp = (EQClass::CXStr*)cxstr;

    (*temp) = text;

    cxstr = (EQ::CXStr**)temp;
}

void EQ_CXStr_Append(EQ::CXStr** cxstr, char* text)
{
    EQClass::CXStr* temp = (EQClass::CXStr*)cxstr;

    (*temp) += text;

    cxstr = (EQ::CXStr**)temp;
}

bool EQ_IsInGame()
{
    return (EQ_POINTER_CEverQuest->GameState == EQ_GAME_STATE_IN_GAME);
}

bool EQ_IsAutoAttackEnabled()
{
    return (EQ_ReadMemory<uint8_t>(EQ_ADDRESS_IS_AUTO_ATTACK_ENABLED) == 1);
}

bool EQ_IsNetStatusEnabled()
{
    return (EQ_ReadMemory<uint8_t>(EQ_ADDRESS_IS_NET_STATUS_ENABLED) == 1);
}

bool EQ_IsNotTypingInChat()
{
    return (EQ_ReadMemory<uint8_t>(EQ_ADDRESS_IS_NOT_TYPING_IN_CHAT) == 1);
}

bool EQ_IsInspectEnabled()
{
    return (EQ_ReadMemory<uint8_t>(EQ_ADDRESS_IS_INSPECT_ENABLED) == 1);
}

bool EQ_IsShowNPCNamesEnabled()
{
    return (EQ_ReadMemory<uint8_t>(EQ_ADDRESS_IS_SHOW_NPC_NAMES_ENABLED) == 1);
}

bool EQ_IsKeyPressedControl()
{
    return (EQ_ReadMemory<uint32_t>(EQ_ADDRESS_IS_KEY_PRESSED_CONTROL) == 1);
}

bool EQ_IsKeyPressedAlt()
{
    return (EQ_ReadMemory<uint32_t>(EQ_ADDRESS_IS_KEY_PRESSED_ALT) == 1);
}

bool EQ_IsKeyPressedShift()
{
    return (EQ_ReadMemory<uint32_t>(EQ_ADDRESS_IS_KEY_PRESSED_SHIFT) == 1);
}

bool EQ_IsMouseHoveringOverCXWnd()
{
    return (EQ_ReadMemory<uint32_t>(EQ_ADDRESS_CXWND_MANAGER_MOUSE_HOVER_WINDOW) != 0);
}

void EQ_SetAutoAttack(bool bEnabled)
{
    if (bEnabled == true)
    {
        EQ_WriteMemory<uint8_t>(EQ_ADDRESS_IS_AUTO_ATTACK_ENABLED, 0x01);
    }
    else
    {
        EQ_WriteMemory<uint8_t>(EQ_ADDRESS_IS_AUTO_ATTACK_ENABLED, 0x00);
    }
}

void EQ_SetFreeCamera(bool bEnabled)
{
    uint32_t baseAddress = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation);

    if (bEnabled == true)
    {
        uint32_t address = 0;
        DWORD oldProtection = 0;
        DWORD tempProtection = 0;

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }
    else
    {
        uint32_t address = 0;
        DWORD oldProtection = 0;
        DWORD tempProtection = 0;

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x01", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x41\x04", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x51\x08", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }

    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_CAMERA_VIEW, EQ_CAMERA_VIEW_FIRST_PERSON);
}

size_t EQ_GetFontTextWidth(char text[], uint32_t fontPointer)
{
    size_t textLength = strlen(text);

    if (textLength == 0)
    {
        return 0;
    }

    int* fontGlyphArray = 0;

    if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL10)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL10;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL12)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL12;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL14)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL14;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL15)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL15;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL16)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL16;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL20)
    {
        fontGlyphArray = EQ_FONT_GLYPH_SIZES_ARIAL20;
    }

    if (fontGlyphArray == 0)
    {
        return 0;
    }

    size_t width = 0;

    for (size_t i = 0; i < textLength; i++)
    {
        int asciiIndex = (int)text[i];

        if (asciiIndex > EQ_ASCII_TABLE_SIZE)
        {
            continue;
        }

        width += fontGlyphArray[asciiIndex];
    }

    return width;
}

void EQ_DrawTooltipText(char text[], int x, int y, uint32_t fontPointer)
{
    size_t textLength = strlen(text);

    if (textLength == 0)
    {
        return;
    }

    uint32_t fontHeight = 0;

    if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL10)
    {
        fontHeight = 10;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL12)
    {
        fontHeight = 12;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL14)
    {
        fontHeight = 14;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL15)
    {
        fontHeight = 15;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL16)
    {
        fontHeight = 16;
    }
    else if (fontPointer == EQ_ADDRESS_POINTER_FONT_ARIAL20)
    {
        fontHeight = 20;
    }

    if (fontHeight == 0)
    {
        return;
    }

    size_t textWidth = EQ_GetFontTextWidth(text, fontPointer);

    if (textWidth == 0)
    {
        return;
    }

    textWidth = textWidth + 1;

    int textX = x - 1;

    EQ_DrawRectangle((float)textX, (float)y, (float)textWidth, (float)fontHeight, EQ_TOOLTIP_TEXT_BACKGROUND_COLOR, true);

    uint32_t font = EQ_ReadMemory<uint32_t>(fontPointer);

    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, EQ_TEXT_COLOR_WHITE, font);
}

void EQ_DrawText(const char* text, int x, int y, int textColor)
{
    uint32_t font = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_FONT_ARIAL14);

    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, textColor, font);
}

void EQ_DrawTextEx(const char* text, int x, int y, int textColor, uint32_t fontPointer)
{
    uint32_t font = EQ_ReadMemory<uint32_t>(fontPointer);

    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, textColor, font);
}

void EQ_DrawLine(float x1, float y1, float x2, float y2, uint32_t colorARGB)
{
    EQ::Line line;

    // begin
    line.X1 = x1;
    line.Y1 = y1;
    line.Z1 = 1.0f;

    // end
    line.X2 = x2;
    line.Y2 = y2;
    line.Z2 = 1.0f;

    EQGraphicsDLL__t3dDeferLine(&line, colorARGB);
}

void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled) // isFilled = false
{
    EQ::Rect rect;

    // top left
    rect.X1 = x;
    rect.Y1 = y;
    rect.Z1 = 1.0f;

    // top right
    rect.X2 = x + width;
    rect.Y2 = y;
    rect.Z2 = 1.0f;

    // bottom right
    rect.X3 = x + width;
    rect.Y3 = y + height;
    rect.Z3 = 1.0f;

    // bottom left
    rect.X4 = x;
    rect.Y4 = y + height;
    rect.Z4 = 1.0f;

    if (isFilled == false)
    {
        EQGraphicsDLL__t3dDeferRect(&rect, colorARGB);
    }
    else
    {
        EQGraphicsDLL__t3dDeferQuad(&rect, colorARGB);
    }
}

void EQ_WriteChatText(const char* text)
{
    EQ_CLASS_POINTER_CEverQuest->dsp_chat(text);
}

void EQ_CalculateTickTime(int ticks, int& hours, int& minutes, int& seconds)
{
    if (ticks > 0)
    {
        seconds = ticks * 3;

        if (seconds > 0)
        {
            hours = seconds / (60 * 60);

            seconds = seconds - hours * (60 * 60);

            if (seconds > 0)
            {
                minutes = seconds / 60;

                seconds = seconds - minutes * 60;
            }
        }
    }
}

std::string EQ_GetTickTimeString(int ticks)
{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    EQ_CalculateTickTime(ticks, hours, minutes, seconds);

    std::stringstream ssTimeText;

    if (hours > 0)
    {
        ssTimeText << hours << "h";
    }

    if (minutes > 0)
    {
        if (hours > 0)
        {
            ssTimeText << " ";
        }

        ssTimeText << minutes << "m";
    }

    if (hours == 0 && minutes == 0)
    {
        if (seconds > 0)
        {
            ssTimeText << seconds << "s";
        }
    }

    return ssTimeText.str();
}

uint32_t EQ_GetTimer()
{
    return EQ_POINTER_CDisplay->Timer;
}

EQ::Spawn_ptr EQ_GetPlayerSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_PlayerSpawn;
}

EQ::Spawn_ptr EQ_GetTargetSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_TargetSpawn;
}

EQ::Spawn_ptr EQ_GetControlledSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_ControlledSpawn;
}

EQ::Spawn_ptr EQ_GetTradeSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_TradeSpawn;
}

EQ::Spawn_ptr EQ_GetMerchantSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_MerchantSpawn;
}

EQ::Spawn_ptr EQ_GetBankerSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_BankerSpawn;
}

EQ::Spawn_ptr EQ_GetCorpseSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_CorpseSpawn;
}

EQ::Spawn_ptr EQ_GetGamemasterSpawn()
{
    return (EQ::Spawn_ptr)EQ_POINTER_GamemasterSpawn;
}

uint32_t EQ_GetPlayerSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PLAYER_SPAWN);
}

uint32_t EQ_GetTargetSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN);
}

uint32_t EQ_GetControlledSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CONTROLLED_SPAWN);
}

uint32_t EQ_GetTradeSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TRADE_SPAWN);
}

uint32_t EQ_GetMerchantSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_MERCHANT_SPAWN);
}

uint32_t EQ_GetBankerSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_BANKER_SPAWN);
}

uint32_t EQ_GetCorpseSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CORPSE_SPAWN);
}

uint32_t EQ_GetGamemasterSpawnAddress()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_GAMEMASTER_SPAWN);
}
