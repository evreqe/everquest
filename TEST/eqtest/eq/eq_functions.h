#pragma once

#include <string>

#include <cstdint>
#include <cstring>
#include <cmath>

#include <windows.h>

#include "eq.h"
#include "eq_memory.h"
#include "eq_macros.h"
#include "eq_classes.h"

/* game functions */

typedef int (__cdecl* EQ_FUNCTION_TYPE_DrawNetStatus)(int x, int y, int unknown);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CrashDetected(), EQ_ADDRESS_FUNCTION_CrashDetected);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CrashDetected)();

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero), EQ_ADDRESS_FUNCTION_ExecuteCmd);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCmd)(uint32_t commandID, int isActive, void* unknown, int zero);

EQ_MACRO_FUNCTION_FunctionAtAddress(float __cdecl EQ_FUNCTION_get_bearing(float y1, float x1, float y2, float x2), EQ_ADDRESS_FUNCTION_get_bearing);
typedef float (__cdecl* EQ_FUNCTION_TYPE_get_bearing)(float y1, float x1, float y2, float x2);

/* function prototypes */

template <class T>
void EQ_Log(const char* text, T number);

void EQ_ToggleBool(bool& b);
float EQ_CalculateDistance(float x1, float y1, float x2, float y2);
float EQ_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2);
bool EQ_IsWithinDistance(float x1, float y1, float x2, float y2, float distance);
bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight);
void EQ_ColorARGB_Darken(uint32_t& colorARGB, float percent);
void EQ_CopyStringToClipboard(const std::string& str);
bool EQ_IsSpellIDValid(uint32_t spellID);
uint32_t EQ_GetFirstSpawn();
uint32_t EQ_GetLastSpawn();
std::string EQ_GetSpawnName(uint32_t spawn);
uint32_t EQ_GetTargetSpawn();
std::string EQ_GetTargetSpawnName();
uint32_t EQ_GetPlayerSpawn();
std::string EQ_GetPlayerSpawnName();
uint32_t EQ_GetSpawnByID(uint32_t spawnID);
uint32_t EQ_GetSpawnByName(const char* spawnName);
void EQ_SetSpawnHeight(uint32_t spawn, float height);
void EQ_InterpretCommand(const char* text);
void EQ_ExecuteCommand(uint32_t commandID, int isActive);
HWND EQ_GetWindow();
void EQ_WriteChatText(const char* text);
void EQ_WriteChatTextEx(const char* text, int color);
void EQ_DrawText(const char* text, int x, int y);
void EQ_DrawTextEx(const char* text, int x, int y, int color);
uint32_t EQ_GetTimer();
uint32_t EQ_GetCamera();
void EQ_SetCameraPitch(float pitch);
void EQ_SetCameraFieldOfView(float fieldOfView);
bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, float& screenX, float& screenY);
void EQ_TurnPlayerTowardsTarget();
void EQAPP_GetNPCSpawnIDListSortedByDistance(std::vector<uint32_t>& spawnIDList);

/* functions */

template <class T>
void EQ_Log(const char* text, T number)
{
    std::fstream file;
    file.open("Logs/eqlog.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

void EQ_ToggleBool(bool& b)
{
    b = !b;
}

float EQ_CalculateDistance(float x1, float y1, float x2, float y2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

float EQ_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) + std::pow(z2 - z1, 2));
}

bool EQ_IsWithinDistance(float x1, float y1, float x2, float y2, float distance)
{
    return (std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2)) <= std::pow(distance, 2);
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

void EQ_CopyStringToClipboard(const std::string& str)
{
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, str.size() + 1);
    memcpy(GlobalLock(mem), str.c_str(), str.size() + 1);
    GlobalUnlock(mem);

    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, mem);
    CloseClipboard();
}

bool EQ_IsSpellIDValid(uint32_t spellID)
{
    return (spellID - 1) <= EQ_NUM_SPELLS;
}

uint32_t EQ_GetFirstSpawn()
{
    uint32_t playerManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQPlayerManager);
    if (playerManager == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerManager + EQ_OFFSET_EQPlayerManager_FIRST_SPAWN);
}

uint32_t EQ_GetLastSpawn()
{
    uint32_t playerManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQPlayerManager);
    if (playerManager == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerManager + EQ_OFFSET_EQPlayerManager_LAST_SPAWN);
}

std::string EQ_GetSpawnName(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return std::string();
    }

    char spawnName[EQ_SIZE_SPAWN_NAME];
    memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME), sizeof(spawnName));

    if (strlen(spawnName) == 0)
    {
        return std::string();
    }

    std::string result = spawnName;

    std::string::size_type findPosition1 = result.find("`");
    if (findPosition1 != std::string::npos)
    {
        return result.substr(0, findPosition1);
    }

    std::string::size_type findPosition2 = result.find("'");
    if (findPosition2 != std::string::npos)
    {
        return result.substr(0, findPosition2);
    }

    return result;
}

uint32_t EQ_GetTargetSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN);
}

std::string EQ_GetTargetSpawnName()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnName(targetSpawn);
}

uint32_t EQ_GetPlayerSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PLAYER_SPAWN);
}

std::string EQ_GetPlayerSpawnName()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnName(playerSpawn);
}

uint32_t EQ_GetSpawnByID(uint32_t spawnID)
{
    uint32_t* player = EQ_CLASS_POINTER_EQPlayerManager->GetSpawnByID(spawnID);
    if (player == NULL)
    {
        return NULL;
    }

    uint32_t spawn = (uint32_t)*&player;
    if (spawn == NULL)
    {
        return NULL;
    }

    return spawn;
}

uint32_t EQ_GetSpawnByName(const char* spawnName)
{
    uint32_t* player = EQ_CLASS_POINTER_EQPlayerManager->GetSpawnByName(spawnName);
    if (player == NULL)
    {
        return NULL;
    }

    uint32_t spawn = (uint32_t)*&player;
    if (spawn == NULL)
    {
        return NULL;
    }

    return spawn;
}

void EQ_SetSpawnHeight(uint32_t spawn, float height)
{
    if (spawn == NULL)
    {
        return;
    }

    ((EQClass::EQPlayer*)spawn)->ChangeHeight(height, 0.0f, 1.0f, 0);
}

void EQ_InterpretCommand(const char* text)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        EQ_CLASS_POINTER_CEverQuest->InterpretCmd((EQClass::EQPlayer*)playerSpawn, text);
    }
}

void EQ_ExecuteCommand(uint32_t commandID, int isActive)
{
    EQ_FUNCTION_ExecuteCmd(commandID, isActive, 0, 0);
}

HWND EQ_GetWindow()
{
    return EQ_ReadMemory<HWND>(EQ_ADDRESS_POINTER_WINDOW_HWND);
}

void EQ_WriteChatText(const char* text)
{
    EQ_CLASS_POINTER_CEverQuest->dsp_chat(text, EQ_CHAT_TEXT_COLOR_YELLOW, 1, 1, 0);
}

void EQ_WriteChatTextEx(const char* text, int color)
{
    EQ_CLASS_POINTER_CEverQuest->dsp_chat(text, color, 1, 1, 0);
}

void EQ_DrawText(const char* text, int x, int y)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, EQ_DRAW_TEXT_COLOR_GRAY);
}

void EQ_DrawTextEx(const char* text, int x, int y, int color)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, color);
}

uint32_t EQ_GetTimer()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(display + EQ_OFFSET_CDisplay_TIMER);
}

bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& interval)
{
    uint32_t currentTimer = EQ_GetTimer();

    if ((currentTimer - timer) > interval)
    {
        timer = currentTimer;
        return true;
    }

    return false;
}

uint32_t EQ_GetCamera()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(display + EQ_OFFSET_CDisplay_CAMERA);
}

void EQ_SetCameraPitch(float pitch)
{
    uint32_t camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemoryProtected<float>(camera + EQ_OFFSET_CAMERA_PITCH, pitch);
}

void EQ_SetCameraFieldOfView(float fieldOfView)
{
    uint32_t camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CAMERA_FIELD_OF_VIEW, fieldOfView);
}

bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, float& screenX, float& screenY)
{
    // this function uses hardcoded offsets

    uint32_t camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return false;
    }

    float camera_0x1A0 = EQ_ReadMemory<float>(camera + 0x0C); // 0.0 to 1.0
    float camera_0x1A4 = EQ_ReadMemory<float>(camera + 0x10);
    float camera_0x1A8 = EQ_ReadMemory<float>(camera + 0x14); // draw distance
    float camera_0x198 = EQ_ReadMemory<float>(camera + 0x38); // screen width  divided by two
    float camera_0x19C = EQ_ReadMemory<float>(camera + 0x3C); // screen height divided by two
    float camera_0x22C = EQ_ReadMemory<float>(camera + 0x48);
    float camera_0x238 = EQ_ReadMemory<float>(camera + 0x54);
    float camera_0x244 = EQ_ReadMemory<float>(camera + 0x60);
    float camera_0x260 = EQ_ReadMemory<float>(camera + 0x84);
    float camera_0x264 = EQ_ReadMemory<float>(camera + 0x88);
    float camera_0x268 = EQ_ReadMemory<float>(camera + 0x8C); // always zero?
    float camera_0x26C = EQ_ReadMemory<float>(camera + 0x90);
    float camera_0x270 = EQ_ReadMemory<float>(camera + 0x94);
    float camera_0x274 = EQ_ReadMemory<float>(camera + 0x98);
    float camera_0x1AC = EQ_ReadMemory<float>(camera + 0xBC); // Y
    float camera_0x1B0 = EQ_ReadMemory<float>(camera + 0xC0); // X
    float camera_0x1B4 = EQ_ReadMemory<float>(camera + 0xC4); // Z

    float v4 = camera_0x1AC - worldY; // changed add to substract because Seeds of Destruction or newer has backwards coordinates
    float v5 = camera_0x1B0 - worldX; // changed add to substract because Seeds of Destruction or newer has backwards coordinates
    float v6 = camera_0x1B4 - worldZ; // changed add to substract because Seeds of Destruction or newer has backwards coordinates

    float v10 = v6 * camera_0x268 + v5 * camera_0x264 + v4 * camera_0x260;
    float v11 = v6 * camera_0x274 + v5 * camera_0x270 + v4 * camera_0x26C;
    float v7  = v6 * camera_0x244 + v5 * camera_0x238 + v4 * camera_0x22C;

    // point is offscreen
    if (v7 >= camera_0x1A0) // changed <= to >= because Seeds of Destruction or newer has backwards coordinates
    {
        screenX = -1.0f;
        screenY = -1.0f;

        return false;
    }

    // prevent divide by zero
    if (v7 == 0.0f)
    {
        screenX = -1.0f;
        screenY = -1.0f;

        return false;
    }

    float v8 = 1.0f / v7;

    float a3 = v10 * v8 + camera_0x198;
    float a4 = camera_0x19C - v8 * v11;

    screenX = a3;
    screenY = a4;

    return true;
}

void EQ_TurnPlayerTowardsTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    float playerSpawnY = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_Y);
    float playerSpawnX = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_X);

    float targetSpawnY = EQ_ReadMemory<float>(targetSpawn + EQ_OFFSET_SPAWN_Y);
    float targetSpawnX = EQ_ReadMemory<float>(targetSpawn + EQ_OFFSET_SPAWN_X);

    float bearing = EQ_FUNCTION_get_bearing(playerSpawnY, playerSpawnX, targetSpawnY, targetSpawnX);

    EQ_WriteMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_HEADING, bearing);
}

void EQAPP_GetNPCSpawnIDListSortedByDistance(std::vector<uint32_t>& spawnIDList)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::map<float, uint32_t> spawnList;

    float playerSpawnY = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_Y);
    float playerSpawnX = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_X);
    float playerSpawnZ = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_Z);

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_TYPE);
        if (spawnType != EQ_SPAWN_TYPE_NPC)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        char spawnName[EQ_SIZE_SPAWN_NAME];
        memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME), sizeof(spawnName));

        if (strstr(spawnName, "`s Mount") != 0)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        if (strstr(spawnName, "Aura ") != 0)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        if (strstr(spawnName, " Aura") != 0)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        float spawnY = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Y);
        float spawnX = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_X);
        float spawnZ = EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Z);

        float spawnDistance = EQ_CalculateDistance3D(playerSpawnX, playerSpawnY, playerSpawnZ, spawnX, spawnY, spawnZ);

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldSpaceToScreenSpace(spawnX, spawnY, spawnZ, screenX, screenY);
        if (result == false)
        {
            spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
            continue;
        }

        uint32_t spawnID = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ID);

        spawnList.insert({spawnDistance, spawnID});

        spawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
    }

    spawnIDList.clear();

    for (auto& s : spawnList)
    {
        spawnIDList.push_back(s.second);
    }
}
