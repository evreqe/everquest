#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

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

EQ_MACRO_FUNCTION_FunctionAtAddress(char* __cdecl EQ_FUNCTION_CrashDetected(), EQ_ADDRESS_FUNCTION_CrashDetected);
typedef char* (__cdecl* EQ_FUNCTION_TYPE_CrashDetected)();

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero), EQ_ADDRESS_FUNCTION_ExecuteCmd);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCmd)(uint32_t commandID, int isActive, void* unknown, int zero);

/* function prototypes */

void EQ_Log(const char* text);

void EQ_ToggleBool(bool& b);

float EQ_CalculateDistance(float x1, float y1, float x2, float y2);
float EQ_CalculateDistance3D(float x1, float y1, float z1, float x2, float y2, float z2);
bool EQ_IsWithinDistance(float x1, float y1, float x2, float y2, float distance);

float EQ_GetBearing(float y1, float x1, float y2, float x2);

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectX, int rectY, int rectWidth, int rectHeight);
void EQ_ColorARGB_Darken(uint32_t& colorARGB, float percent);

uint32_t EQ_GetGameState();
bool EQ_IsInGame();
bool EQ_IsSpellIDValid(uint32_t spellID);
bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& interval);
bool EQ_IsZoneIDSafe(uint32_t zoneID);
HWND EQ_GetWindow();
uint32_t EQ_GetTimer();
uint32_t EQ_GetCamera();

bool EQ_IsNetStatusEnabled();
bool EQ_IsAutoAttackEnabled();
bool EQ_IsAutoFireEnabled();
bool EQ_IsAutoRunEnabled();
bool EQ_IsMouseLookEnabled();

void EQ_SetNetStatus(bool b);
void EQ_SetAutoAttack(bool b);
void EQ_SetAutoFire(bool b);
void EQ_SetAutoRun(bool b);
void EQ_SetMouseLook(bool b);

uint32_t EQ_GetSpawnByID(uint32_t spawnID);
uint32_t EQ_GetSpawnByName(const char* spawnName);

uint32_t EQ_GetFirstSpawn();
uint32_t EQ_GetLastSpawn();

uint32_t EQ_GetTargetSpawn();
uint32_t EQ_GetPlayerSpawn();

void EQ_SetTargetSpawn(uint32_t spawn);

uint32_t EQ_GetSpawnNext(uint32_t spawn);
uint32_t EQ_GetSpawnPrevious(uint32_t spawn);

std::string EQ_GetSpawnName(uint32_t spawn);
std::string EQ_GetSpawnLastName(uint32_t spawn);

std::string EQ_GetPlayerSpawnName();
std::string EQ_GetPlayerSpawnLastName();
std::string EQ_GetTargetSpawnName();
std::string EQ_GetPlayerSpawnLastName();

bool EQ_IsSpawnWithinDistance(uint32_t spawn, float distance);
float EQ_GetSpawnDistance(uint32_t spawn);
float EQ_GetSpawnDistance3D(uint32_t spawn);

float EQ_GetSpawnY(uint32_t spawn);
float EQ_GetSpawnX(uint32_t spawn);
float EQ_GetSpawnZ(uint32_t spawn);
float EQ_GetSpawnHeading(uint32_t spawn);
uint32_t EQ_GetSpawnType(uint32_t spawn);
float EQ_GetSpawnHeight(uint32_t spawn);
uint32_t EQ_GetSpawnID(uint32_t spawn);
uint32_t EQ_GetSpawnZoneID(uint32_t spawn);
uint32_t EQ_GetSpawnLevel(uint32_t spawn);
uint32_t EQ_GetSpawnRace(uint32_t spawn);
uint32_t EQ_GetSpawnClass(uint32_t spawn);
uint32_t EQ_GetSpawnStandingState(uint32_t spawn);
uint32_t EQ_GetSpawnHPCurrent(uint32_t spawn);
uint32_t EQ_GetSpawnHPMax(uint32_t spawn);
uint32_t EQ_GetSpawnHPPercent(uint32_t spawn);
uint32_t EQ_GetSpawnManaCurrent(uint32_t spawn);
uint32_t EQ_GetSpawnManaMax(uint32_t spawn);
uint32_t EQ_GetSpawnManaPercent(uint32_t spawn);
uint32_t EQ_GetSpawnEnduranceCurrent(uint32_t spawn);
uint32_t EQ_GetSpawnEnduranceMax(uint32_t spawn);
uint32_t EQ_GetSpawnEndurancePercent(uint32_t spawn);
uint32_t EQ_GetSpawnFollowSpawn(uint32_t spawn);

void EQ_SetSpawnHeading(uint32_t spawn, float heading);
void EQ_SetSpawnHeight(uint32_t spawn, float height);
void EQ_SetSpawnFollowSpawn(uint32_t spawn, uint32_t followSpawn);
void EQ_TurnPlayerTowardsSpawn(uint32_t spawn);

bool EQ_IsSpawnClassTank(uint32_t spawn); // WAR PAL SHD
bool EQ_IsSpawnClassPriest(uint32_t spawn); // CLR DRU SHM
bool EQ_IsSpawnClassCaster(uint32_t spawn); // NEC WIZ MAG ENC
bool EQ_IsSpawnClassMelee(uint32_t spawn); // BER MNK ROG
bool EQ_IsSpawnClassHybrid(uint32_t spawn); // BRD BST RNG

void EQ_InterpretCommand(const char* text);
void EQ_ExecuteCommand(uint32_t commandID, int isActive);

void EQ_PrintTextToChat(const char* text);
void EQ_PrintTextToChatEx(const char* text, int color);

void EQ_DrawText(const char* text, int x, int y);
void EQ_DrawTextEx(const char* text, int x, int y, int color);

void EQ_SetCameraPitch(float pitch);
void EQ_SetCameraFieldOfView(float fieldOfView);

bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, float& screenX, float& screenY);

void EQ_PlaySound(const char* filename);
void EQ_StopSound();

void EQ_StopFollow();
void EQ_FollowTarget();
void EQ_TurnPlayerTowardsTarget();

bool EQ_CXWnd_IsOpen(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset);

bool EQ_BazaarSearchWindow_IsOpen();
void EQ_BazaarSearchWindow_DoQuery();
bool EQ_BazaarSearchWindow_BuyItem(uint32_t listIndex);
signed int EQ_BazaarSearchWindow_GetBuyItemListIndex();
uint32_t EQ_BazaarSearchWindow_GetItemID(uint32_t listIndex);
uint32_t EQ_BazaarSearchWindow_GetItemQuantity(uint32_t listIndex);
uint32_t EQ_BazaarSearchWindow_GetItemPrice(uint32_t listIndex);
std::string EQ_BazaarSearchWindow_GetItemName(uint32_t listIndex);
bool EQ_BazaarSearchWindow_ClickFindItemsButton();
bool EQ_BazaarSearchWindow_ClickUpdateTradersButton();
bool EQ_BazaarSearchWindow_ClickResetButton();

bool EQ_BazaarConfirmationWindow_IsOpen();
bool EQ_BazaarConfirmationWindow_ClickToParcelsButton();
bool EQ_BazaarConfirmationWindow_ClickCancelButton();

bool EQ_BazaarWindow_IsOpen();
bool EQ_BazaarWindow_ClickBeginTraderButton();
bool EQ_BazaarWindow_ClickEndTraderButton();

std::string EQ_GetZoneNameByKey(uint32_t key);
std::string EQ_GetZoneShortNameByKey(uint32_t key);
std::string EQ_GetRaceNameByKey(uint32_t key);
std::string EQ_GetRaceShortNameByKey(uint32_t key);
std::string EQ_GetClassNameByKey(uint32_t key);
std::string EQ_GetClassShortNameByKey(uint32_t key);

/* functions */

void EQ_Log(const char* text)
{
    std::fstream file;
    file.open("Logs/eq-log.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << std::endl;
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

float EQ_GetBearing(float y1, float x1, float y2, float x2)
{
    float v4 = 0.0f;
    float v5 = 0.0f;
    float v6 = 0.0f;
    float v7 = 0.0f;
    float v8 = 0.0f;
    float v9 = 0.0f;
    float v10 = 0.0f;
    float v11 = 0.0f;
    float v13 = 0.0f;

    v4 = y2;
    v5 = std::fabs(y1 - y2);
    v6 = x1;
    v7 = std::fabs(x1 - x2);

    if (v5 < 0.0000009999999974752427f)
    {
        v5 = 0.0000009999999974752427f;
    }

    v8 = v7;
    v9 = v5;
    v10 = x2;

    v11 = std::atan2(v8, v9) * 180.0f * 0.3183099014828645f;

    if (y1 < v4)
    {
        v13 = y1;
    }
    else
    {
        if (x2 >= v6)
        {
            return (90.0f - v11 + 90.0f) * 511.5f * 0.0027777778f;
        }

        if (x2 <= v6)
        {
            return (v11 + 180.0f) * 511.5f * 0.0027777778f;
        }

        v13 = y1;
        v10 = x2;
    }

    float result = 0.0f;

    if (v13 > v4 || v10 > v6)
    {
        result = v11 * 511.5f * 0.0027777778f;
    }
    else
    {
        result = (90.0f - v11 + 270.0f) * 511.5f * 0.0027777778f;
    }

    return result;
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

uint32_t EQ_GetGameState()
{
    uint32_t everquest = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CEverQuest);
    if (everquest == NULL)
    {
        return 255;
    }

    return EQ_ReadMemory<uint32_t>(everquest + EQ_OFFSET_CEverQuest_GAME_STATE);
}

bool EQ_IsInGame()
{
    return EQ_GetGameState() == EQ_GAME_STATE_IN_GAME;
}

bool EQ_IsSpellIDValid(uint32_t spellID)
{
    return (spellID - 1) <= EQ_NUM_SPELLS;
}

bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& interval)
{
    auto currentTimer = EQ_GetTimer();

    if ((currentTimer - timer) > interval)
    {
        timer = currentTimer;
        return true;
    }

    return false;
}

bool EQ_IsZoneIDSafe(uint32_t zoneID)
{
    if
    (
        zoneID == EQ_ZONE_ID_BAZAAR           ||
        zoneID == EQ_ZONE_ID_NEXUS            ||
        zoneID == EQ_ZONE_ID_POKNOWLEDGE      ||
        zoneID == EQ_ZONE_ID_POTRANQUILITY    ||
        zoneID == EQ_ZONE_ID_GUILDLOBBY       ||
        zoneID == EQ_ZONE_ID_GUILDHALL        ||
        zoneID == EQ_ZONE_ID_BARTER
    )
    {
        return true;
    }

    return false;
}

HWND EQ_GetWindow()
{
    return EQ_ReadMemory<HWND>(EQ_ADDRESS_POINTER_WINDOW_HWND);
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

uint32_t EQ_GetCamera()
{
    uint32_t display = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CDisplay);
    if (display == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(display + EQ_OFFSET_CDisplay_CAMERA);
}

bool EQ_IsNetStatusEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_NET_STATUS);
}

bool EQ_IsAutoAttackEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AUTO_ATTACK);
}

bool EQ_IsAutoFireEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AUTO_FIRE);
}

bool EQ_IsAutoRunEnabled()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_AUTO_RUN);
}

bool EQ_IsMouseLookEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_MOUSE_LOOK);
}

void EQ_SetNetStatus(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_NET_STATUS, value);
}

void EQ_SetAutoAttack(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_AUTO_ATTACK, value);
}

void EQ_SetAutoFire(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_AUTO_FIRE, value);
}

void EQ_SetAutoRun(bool b)
{
    uint32_t value = (uint32_t)b;

    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_AUTO_RUN, value);
}

void EQ_SetMouseLook(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_MOUSE_LOOK, value);
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

uint32_t EQ_GetTargetSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN);
}

uint32_t EQ_GetPlayerSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PLAYER_SPAWN);
}

void EQ_SetTargetSpawn(uint32_t spawn)
{
    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN, spawn);
}

uint32_t EQ_GetSpawnNext(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
}

uint32_t EQ_GetSpawnPrevious(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_PREVIOUS);
}

std::string EQ_GetSpawnName(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return std::string();
    }

    char spawnName[EQ_SIZE_SPAWN_NAME];
    ////memcpy(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME), sizeof(spawnName));
    std::memmove(spawnName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME), sizeof(spawnName));

    if (strlen(spawnName) == 0)
    {
        return std::string();
    }

    std::string result = spawnName;

    auto spawnType = EQ_GetSpawnType(spawn);
    if (spawnType == EQ_SPAWN_TYPE_PLAYER)
    {
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
    }

    return result;
}

std::string EQ_GetSpawnLastName(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return std::string();
    }

    char spawnLastName[EQ_SIZE_SPAWN_LAST_NAME];
    ////memcpy(spawnLastName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_LAST_NAME), sizeof(spawnLastName));
    std::memmove(spawnLastName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_LAST_NAME), sizeof(spawnLastName));

    if (strlen(spawnLastName) == 0)
    {
        return std::string();
    }

    return spawnLastName;
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

std::string EQ_GetPlayerSpawnLastName()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnLastName(playerSpawn);
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

std::string EQ_GetTargetSpawnLastName()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnLastName(targetSpawn);
}

bool EQ_IsSpawnWithinDistance(uint32_t spawn, float distance)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    bool result = EQ_IsWithinDistance(playerSpawnX, playerSpawnY, spawnX, spawnY, distance);

    return result;
}

float EQ_GetSpawnDistance(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return -1.0f;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    float spawnDistance = EQ_CalculateDistance(playerSpawnX, playerSpawnY, spawnX, spawnY);

    return spawnDistance;
}

float EQ_GetSpawnDistance3D(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return 0.0f;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    float spawnDistance = EQ_CalculateDistance3D(playerSpawnX, playerSpawnY, playerSpawnZ, spawnX, spawnY, spawnZ);

    return spawnDistance;
}

float EQ_GetSpawnY(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Y);
}

float EQ_GetSpawnX(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_X);
}

float EQ_GetSpawnZ(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_Z);
}

float EQ_GetSpawnHeading(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEADING);
}

uint32_t EQ_GetSpawnType(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_TYPE);
}

float EQ_GetSpawnHeight(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEIGHT);
}

uint32_t EQ_GetSpawnID(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ID);
}

uint32_t EQ_GetSpawnZoneID(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ZONE_ID);
}

uint32_t EQ_GetSpawnLevel(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_LEVEL);
}

uint32_t EQ_GetSpawnRace(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_RACE);
}

uint32_t EQ_GetSpawnClass(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_CLASS);
}

uint32_t EQ_GetSpawnStandingState(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_STANDING_STATE);
}

uint32_t EQ_GetSpawnHPCurrent(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_HP_CURRENT);
}

uint32_t EQ_GetSpawnHPMax(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_HP_MAX);
}

uint32_t EQ_GetSpawnHPPercent(uint32_t spawn)
{
    auto current = EQ_GetSpawnHPCurrent(spawn);
    auto max     = EQ_GetSpawnHPMax(spawn);

    uint32_t multiplied = current * 100;

    // prevent divide by zero
    if (multiplied == 0 || max == 0)
    {
        return 0;
    }

    return (uint32_t)(multiplied / max);
}

uint32_t EQ_GetSpawnManaCurrent(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_MANA_CURRENT);
}

uint32_t EQ_GetSpawnManaMax(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_MANA_MAX);
}

uint32_t EQ_GetSpawnManaPercent(uint32_t spawn)
{
    auto current = EQ_GetSpawnManaCurrent(spawn);
    auto max     = EQ_GetSpawnManaMax(spawn);

    uint32_t multiplied = current * 100;

    // prevent divide by zero
    if (multiplied == 0 || max == 0)
    {
        return 0;
    }

    return (uint32_t)(multiplied / max);
}

uint32_t EQ_GetSpawnEnduranceCurrent(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ENDURANCE_CURRENT);
}

uint32_t EQ_GetSpawnEnduranceMax(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ENDURANCE_MAX);
}

uint32_t EQ_GetSpawnEndurancePercent(uint32_t spawn)
{
    auto current = EQ_GetSpawnEnduranceCurrent(spawn);
    auto max     = EQ_GetSpawnEnduranceMax(spawn);

    uint32_t multiplied = current * 100;

    // prevent divide by zero
    if (multiplied == 0 || max == 0)
    {
        return 0;
    }

    return (uint32_t)(multiplied / max);
}

uint32_t EQ_GetSpawnFollowSpawn(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN);
}

void EQ_SetSpawnHeading(uint32_t spawn, float heading)
{
    EQ_WriteMemory<float>(spawn + EQ_OFFSET_SPAWN_HEADING, heading);
}

void EQ_SetSpawnHeight(uint32_t spawn, float height)
{
    ((EQClass::EQPlayer*)spawn)->ChangeHeight(height, 0.0f, 1.0f, 0);
}

void EQ_SetSpawnFollowSpawn(uint32_t spawn, uint32_t followSpawn)
{
    EQ_WriteMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, followSpawn);
}

void EQ_TurnPlayerTowardsSpawn(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    float heading = EQ_GetBearing(playerSpawnY, playerSpawnX, spawnY, spawnX);

    EQ_SetSpawnHeading(playerSpawn, heading);
}

// WAR PAL SHD
bool EQ_IsSpawnClassTank(uint32_t spawn)
{
    auto spawnClass = EQ_GetSpawnClass(spawn);

    if
    (
        spawnClass == EQ_CLASS_WARRIOR         ||
        spawnClass == EQ_CLASS_PALADIN         ||
        spawnClass == EQ_CLASS_SHADOWKNIGHT
    )
    {
        return true;
    }

    return false;
}

// CLR DRU SHM
bool EQ_IsSpawnClassPriest(uint32_t spawn)
{
    auto spawnClass = EQ_GetSpawnClass(spawn);

    if
    (
        spawnClass == EQ_CLASS_CLERIC    ||
        spawnClass == EQ_CLASS_DRUID     ||
        spawnClass == EQ_CLASS_SHAMAN
    )
    {
        return true;
    }

    return false;
}

// NEC WIZ MAG ENC
bool EQ_IsSpawnClassCaster(uint32_t spawn)
{
    auto spawnClass = EQ_GetSpawnClass(spawn);

    if
    (
        spawnClass == EQ_CLASS_NECROMANCER    ||
        spawnClass == EQ_CLASS_WIZARD         ||
        spawnClass == EQ_CLASS_MAGICIAN       ||
        spawnClass == EQ_CLASS_ENCHANTER
    )
    {
        return true;
    }

    return false;
}

// BER MNK ROG
bool EQ_IsSpawnClassMelee(uint32_t spawn)
{
    auto spawnClass = EQ_GetSpawnClass(spawn);

    if
    (
        spawnClass == EQ_CLASS_BERSERKER    ||
        spawnClass == EQ_CLASS_MONK         ||
        spawnClass == EQ_CLASS_ROGUE
    )
    {
        return true;
    }

    return false;
}

// BRD BST RNG
bool EQ_IsSpawnClassHybrid(uint32_t spawn)
{
    auto spawnClass = EQ_GetSpawnClass(spawn);

    if
    (
        spawnClass == EQ_CLASS_BARD         ||
        spawnClass == EQ_CLASS_BEASTLORD    ||
        spawnClass == EQ_CLASS_RANGER
    )
    {
        return true;
    }

    return false;
}

void EQ_InterpretCommand(const char* text)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_CLASS_POINTER_CEverQuest->InterpretCmd((EQClass::EQPlayer*)playerSpawn, text);
}

void EQ_ExecuteCommand(uint32_t commandID, int isActive)
{
    EQ_FUNCTION_ExecuteCmd(commandID, isActive, 0, 0);
}

void EQ_PrintTextToChat(const char* text)
{
    EQ_CLASS_POINTER_CEverQuest->dsp_chat(text, EQ_CHAT_TEXT_COLOR_YELLOW, 1, 1, 0);
}

void EQ_PrintTextToChatEx(const char* text, int color)
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

void EQ_SetCameraPitch(float pitch)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemoryProtected<float>(camera + EQ_OFFSET_CAMERA_PITCH, pitch);
}

void EQ_SetCameraFieldOfView(float fieldOfView)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CAMERA_FIELD_OF_VIEW, fieldOfView);
}

void EQ_PlaySound(const char* filename)
{
    std::stringstream filePath;
    filePath << "sounds/" << filename;

    PlaySoundA(filePath.str().c_str(), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQ_StopSound()
{
    PlaySoundA(NULL, NULL, NULL);
}

bool EQ_WorldSpaceToScreenSpace(float worldX, float worldY, float worldZ, float& screenX, float& screenY)
{
    // this function uses hardcoded offsets

    auto camera = EQ_GetCamera();
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

    float v4 = camera_0x1AC - worldY; // changed add to substract because Titanium client or newer has backwards coordinates
    float v5 = camera_0x1B0 - worldX; // changed add to substract because Titanium client or newer has backwards coordinates
    float v6 = camera_0x1B4 - worldZ; // changed add to substract because Titanium client or newer has backwards coordinates

    float v10 = v6 * camera_0x268 + v5 * camera_0x264 + v4 * camera_0x260;
    float v11 = v6 * camera_0x274 + v5 * camera_0x270 + v4 * camera_0x26C;
    float v7  = v6 * camera_0x244 + v5 * camera_0x238 + v4 * camera_0x22C;

    // point is offscreen
    if (v7 >= camera_0x1A0) // changed <= to >= because Titanium client or newer has backwards coordinates
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

void EQ_StopFollow()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnFollowSpawn(playerSpawn, 0);
    EQ_SetAutoRun(false);
}

void EQ_FollowTarget()
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

    EQ_SetSpawnFollowSpawn(playerSpawn, targetSpawn);
}

void EQ_TurnPlayerTowardsTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    EQ_TurnPlayerTowardsSpawn(targetSpawn);
}

bool EQ_CXWnd_IsOpen(uint32_t cxwndAddressPointer)
{
    uint32_t window = EQ_ReadMemory<uint32_t>(cxwndAddressPointer);
    if (window == NULL)
    {
        return false;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(window + EQ_OFFSET_CXWnd_IS_OPEN);

    return (isOpen == 1);

    ////return ((EQClass::CXWnd*)window)->IsReallyVisible();
}

bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset)
{
    uint32_t window = EQ_ReadMemory<uint32_t>(cxwndAddressPointer);
    if (window == NULL)
    {
        return false;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(window + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return false;
    }

    uint32_t button = EQ_ReadMemory<uint32_t>(window + cxwndButtonOffset);
    if (button == NULL)
    {
        return false;
    }

    ((EQClass::CXWnd*)window)->WndNotification(button, EQ_CXWND_MESSAGE_LEFT_CLICK, (void*)0);

    return true;
}

bool EQ_BazaarSearchWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBazaarSearchWnd) == true);
}

void EQ_BazaarSearchWindow_DoQuery()
{
    EQ_CLASS_POINTER_CBazaarSearchWnd->doQuery();
}

bool EQ_BazaarSearchWindow_BuyItem(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return false;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return false;
    }

    EQ_WriteMemory<uint32_t>(bazaarSearchWindow + EQ_OFFSET_CBazaarSearchWnd_BUY_ITEM_LIST_INDEX, listIndex);

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_ID);
    if (itemID == 0)
    {
        return false;
    }

    uint32_t itemPrice = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE);
    if (itemPrice == 0)
    {
        return false;
    }

    uint32_t itemQuantity = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY);
    if (itemQuantity == 0)
    {
        return false;
    }

    bool result = EQ_CLASS_POINTER_CBazaarSearchWnd->BuyItem(itemQuantity);

    return result;
}

signed int EQ_BazaarSearchWindow_GetBuyItemListIndex()
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return -1;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return -1;
    }

    uint32_t buyItemListIndex = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + EQ_OFFSET_CBazaarSearchWnd_BUY_ITEM_LIST_INDEX);

    return buyItemListIndex;
}

uint32_t EQ_BazaarSearchWindow_GetItemID(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_ID);

    return itemID;
}

uint32_t EQ_BazaarSearchWindow_GetItemQuantity(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_ID);
    if (itemID == 0)
    {
        return 0;
    }

    uint32_t itemQuantity = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY);

    return itemQuantity;
}

uint32_t EQ_BazaarSearchWindow_GetItemPrice(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_ID);
    if (itemID == 0)
    {
        return 0;
    }

    uint32_t itemPrice = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE);

    return itemPrice;
}

std::string EQ_BazaarSearchWindow_GetItemName(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return std::string();
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return std::string();
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_ID);
    if (itemID == 0)
    {
        return std::string();
    }

    char itemName[EQ_SIZE_CBazaarSearchWnd_ITEM_NAME];
    std::memmove(itemName, (LPVOID)(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM * listIndex) + EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME), sizeof(itemName));

    return itemName;
}

bool EQ_BazaarSearchWindow_ClickFindItemsButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarSearchWnd, EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS);
}

bool EQ_BazaarSearchWindow_ClickUpdateTradersButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarSearchWnd, EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS);
}

bool EQ_BazaarSearchWindow_ClickResetButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarSearchWnd, EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET);
}

bool EQ_BazaarConfirmationWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd) == true);
}

bool EQ_BazaarConfirmationWindow_ClickToParcelsButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd, EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS);
}

bool EQ_BazaarConfirmationWindow_ClickCancelButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd, EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL);
}

bool EQ_BazaarWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBazaarWnd) == true);
}

bool EQ_BazaarWindow_ClickBeginTraderButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarWnd, EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER);
}

bool EQ_BazaarWindow_ClickEndTraderButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBazaarWnd, EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER);
}

std::string EQ_GetZoneNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_ZONE_NAME.find(key);
    if (it != EQ_TABLE_ZONE_NAME.end())
    {
        return it->second;
    }

    return std::string();
}

std::string EQ_GetZoneShortNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_ZONE_SHORT_NAME.find(key);
    if (it != EQ_TABLE_ZONE_SHORT_NAME.end())
    {
        return it->second;
    }

    return std::string();
}

std::string EQ_GetRaceNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_RACE_NAME.find(key);
    if (it != EQ_TABLE_RACE_NAME.end())
    {
        return it->second;
    }

    return std::string();
}

std::string EQ_GetRaceShortNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_RACE_SHORT_NAME.find(key);
    if (it != EQ_TABLE_RACE_SHORT_NAME.end())
    {
        return it->second;
    }

    return std::string();
}

std::string EQ_GetClassNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_CLASS_NAME.find(key);
    if (it != EQ_TABLE_CLASS_NAME.end())
    {
        return it->second;
    }

    return std::string();
}

std::string EQ_GetClassShortNameByKey(uint32_t key)
{
    auto it = EQ_TABLE_CLASS_SHORT_NAME.find(key);
    if (it != EQ_TABLE_CLASS_SHORT_NAME.end())
    {
        return it->second;
    }

    return std::string();
}
