#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

#include <cstdint>
#include <cstring>
#include <cmath>

#include <windows.h>

#include "eq_addresses.h"
#include "eq_classes.h"
#include "eq_memory.h"
#include "eq_macros.h"

/* game functions */

typedef int (__cdecl* EQ_FUNCTION_TYPE_DrawNetStatus)(int x, int y, int unknown);

EQ_MACRO_FUNCTION_FunctionAtAddress(char* __cdecl EQ_FUNCTION_CrashDetected(), EQ_ADDRESS_FUNCTION_CrashDetected);
typedef char* (__cdecl* EQ_FUNCTION_TYPE_CrashDetected)();

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CastRay(uint32_t spawn, float y, float x, float z), EQ_ADDRESS_FUNCTION_CastRay);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay)(uint32_t spawn, float y, float x, float z);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero), EQ_ADDRESS_FUNCTION_ExecuteCmd);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCmd)(uint32_t commandID, int isActive, void* unknown, int zero);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_GetExecuteCmdIDByName(const char* commandName), EQ_ADDRESS_FUNCTION_GetExecuteCmdIDByName);
typedef int (__cdecl* EQ_FUNCTION_TYPE_GetExecuteCmdIDByName)(const char* commandName);

EQ_MACRO_FUNCTION_FunctionAtAddress(char* __cdecl EQ_FUNCTION_GetExecuteCmdNameByID(int commandID), EQ_ADDRESS_FUNCTION_GetExecuteCmdNameByID);
typedef char* (__cdecl* EQ_FUNCTION_TYPE_GetExecuteCmdNameByID)(int commandID);


/* function prototypes */

void EQ_Log(const char* text);

void EQ_ToggleBool(bool& b);

float EQ_CalculateDistance(float y1, float x1, float y2, float x2);
float EQ_CalculateDistance3D(float y1, float x1, float z1, float y2, float x2, float z2);
bool EQ_IsWithinDistance(float y1, float x1, float y2, float x2, float distance);

float EQ_GetBearing(float y1, float x1, float y2, float x2);
void EQ_FixHeading(float& heading);
void EQ_FixPitch(float& pitch);
float EQ_GetRadians(float degrees);

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight);
void EQ_ColorARGB_Darken(uint32_t& colorARGB, float percent);

uint32_t EQ_GetGameState();
bool EQ_IsInGame();
bool EQ_IsSpellIDValid(uint32_t spellID);
bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& timerInterval);
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

void EQ_SetFogDistanceBegin(float distance);
void EQ_SetFogDistanceEnd(float distance);
void EQ_SetFarClipPlane(uint32_t value);
void EQ_SetFarClipPlanePercent(uint32_t percent);

uint32_t EQ_GetSpawnByID(uint32_t spawnID);
uint32_t EQ_GetSpawnByName(const char* spawnName);

uint32_t EQ_GetFirstSpawn();
uint32_t EQ_GetLastSpawn();

uint32_t EQ_GetPlayerSpawn();
uint32_t EQ_GetTargetSpawn();

void EQ_SetTargetSpawn(uint32_t spawn);

std::string EQ_GetPlayerSpawnNameNumbered();
std::string EQ_GetPlayerSpawnName();
std::string EQ_GetPlayerSpawnLastName();

std::string EQ_GetTargetSpawnNameNumbered();
std::string EQ_GetTargetSpawnName();
std::string EQ_GetTargetSpawnLastName();

float EQ_GetSpawnDistance(uint32_t spawn);
float EQ_GetSpawnDistance3D(uint32_t spawn);

bool EQ_IsSpawnWithinDistance(uint32_t spawn, float distance);
bool EQ_IsSpawnWithinDistanceOfLocation(uint32_t spawn, float distance, float y, float x, float z);

bool EQ_CanSpawnCastRayToLocation(uint32_t spawn, float y, float x, float z);

bool EQ_IsSpawnTargetable(uint32_t spawn);

bool EQ_IsSpawnSwimming(uint32_t spawn);
bool EQ_IsSpawnSwimmingUnderwater(uint32_t spawn);

bool EQ_IsSpawnBehindSpawn(uint32_t  spawn1, uint32_t  spawn2);
bool EQ_IsSpawnBehindSpawnEx(uint32_t  spawn1, uint32_t  spawn2, float angle);
bool EQ_IsPlayerBehindTarget();

bool EQ_IsSpawnClassTank(uint32_t spawn); // WAR PAL SHD
bool EQ_IsSpawnClassPriest(uint32_t spawn); // CLR DRU SHM
bool EQ_IsSpawnClassCaster(uint32_t spawn); // NEC WIZ MAG ENC
bool EQ_IsSpawnClassMelee(uint32_t spawn); // BER MNK ROG
bool EQ_IsSpawnClassHybrid(uint32_t spawn); // BRD BST RNG

std::string EQ_GetSpawnNameNumbered(uint32_t spawn);
std::string EQ_GetSpawnName(uint32_t spawn);
std::string EQ_GetSpawnLastName(uint32_t spawn);

uint32_t EQ_GetSpawnPrevious(uint32_t spawn);
uint32_t EQ_GetSpawnNext(uint32_t spawn);
float EQ_GetSpawnJumpStrength(uint32_t spawn);
float EQ_GetSpawnMovementSpeedBonus(uint32_t spawn);
float EQ_GetSpawnAreaFriction(uint32_t spawn);
float EQ_GetSpawnAccelerationFriction(uint32_t spawn);
uint32_t EQ_GetSpawnCollideWithActorType(uint32_t spawn);
float EQ_GetSpawnFloorZ(uint32_t spawn);
float EQ_GetSpawnY(uint32_t spawn);
float EQ_GetSpawnX(uint32_t spawn);
float EQ_GetSpawnZ(uint32_t spawn);
float EQ_GetSpawnMovementSpeed(uint32_t spawn);
float EQ_GetSpawnHeading(uint32_t spawn);
float EQ_GetSpawnHeadingSpeed(uint32_t spawn);
float EQ_GetSpawnPitch(uint32_t spawn);
uint32_t EQ_GetSpawnUnderwaterEnvironmentType(uint32_t spawn);
uint32_t EQ_GetSpawnHeadEnvironmentType(uint32_t spawn);
uint32_t EQ_GetSpawnFeetEnvironmentType(uint32_t spawn);
uint32_t EQ_GetSpawnBodyEnvironmentType(uint32_t spawn);
uint32_t EQ_GetSpawnType(uint32_t spawn);
float EQ_GetSpawnHeightZ(uint32_t spawn);
float EQ_GetSpawnHeight(uint32_t spawn);
uint32_t EQ_GetSpawnID(uint32_t spawn);
uint32_t EQ_GetSpawnStateFlags(uint32_t spawn);
uint32_t EQ_GetSpawnVehicleSpawn(uint32_t spawn);
uint32_t EQ_GetSpawnMountSpawn(uint32_t spawn);
uint32_t EQ_GetSpawnMountRiderSpawn(uint32_t spawn);
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
uint32_t EQ_GetSpawnDirection(uint32_t spawn);

void EQ_SetSpawnAreaFriction(uint32_t spawn, float friction);
void EQ_SetSpawnAccelerationFriction(uint32_t spawn, float friction);
void EQ_SetSpawnHeading(uint32_t spawn, float heading);
void EQ_SetSpawnPitch(uint32_t spawn, float pitch);
void EQ_SetSpawnHeight(uint32_t spawn, float height);
void EQ_SetSpawnFollowSpawn(uint32_t spawn, uint32_t followSpawn);

bool EQ_SetSpawnItemSlot(uint32_t spawn, uint32_t updateItemSlot, const char* itemDefinition);
bool EQ_SetSpawnItemSlotPrimary(uint32_t spawn, const char* itemDefinition);
bool EQ_SetSpawnItemSlotSecondary(uint32_t spawn, const char* itemDefinition);
bool EQ_SetSpawnItemSlotHead(uint32_t spawn, const char* itemDefinition);

void EQ_TurnSpawnTowardsLocation(uint32_t spawn, float y, float x);
void EQ_TurnSpawnAwayFromLocation(uint32_t spawn, float y, float x);
void EQ_TurnSpawnTowardsSpawn(uint32_t spawn1, uint32_t spawn2);
void EQ_TurnSpawnAwayFromSpawn(uint32_t spawn1, uint32_t spawn2);
void EQ_TurnPlayerTowardsSpawn(uint32_t spawn);
void EQ_TurnPlayerAwayFromSpawn(uint32_t spawn);
void EQ_TurnPlayerTowardsTarget();
void EQ_TurnPlayerAwayFromTarget();

void EQ_InterpretCommand(const char* text);
void EQ_ExecuteCommand(uint32_t commandID, int isActive);
void EQ_ExecuteCommandEx(const char* commandName, int isActive);
uint32_t EQ_GetExecuteCommandIDByName(const char* commandName);
std::string EQ_GetExecuteCommandNameByID(uint32_t commandID);

void EQ_PrintTextToChat(const char* text);
void EQ_PrintTextToChatEx(const char* text, int color);

void EQ_DrawText(const char* text, int x, int y);
void EQ_DrawTextEx(const char* text, int x, int y, int color);

void EQ_DrawLine(float lineBeginX, float lineBeginY, float lineEndX, float lineEndY, uint32_t colorARGB);
void EQ_DrawLine3D(float lineBeginY, float lineBeginX, float lineBeginZ, float lineEndY, float lineEndX, float lineEndZ, uint32_t colorARGB);
void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled);

float EQ_GetCameraPitch();
float EQ_GetCameraFieldOfView();
float EQ_GetCameraDrawDistance();

void EQ_SetCameraPitch(float pitch);
void EQ_SetCameraFieldOfView(float fieldOfView);
void EQ_SetCameraDrawDistance(float drawDistance);

bool EQ_WorldSpaceToScreenSpace(float worldY, float worldX, float worldZ, float& screenX, float& screenY);
bool EQ_WorldSpaceToScreenSpaceEx(float worldY, float worldX, float worldZ, float& screenX, float& screenY);

void EQ_PlaySound(const char* filename);
void EQ_StopSound();

void EQ_StopFollow();
void EQ_FollowTarget();

bool EQ_CXWnd_IsOpen(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_Open(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_Close(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset);

uint32_t EQ_PlayerWindow_GetCombatState();

bool EQ_BazaarSearchWindow_IsOpen();
void EQ_BazaarSearchWindow_DoQuery();
uint32_t EQ_BazaarSearchWindow_GetListIndexByItemName(const char* itemName, bool useExactComparsion);
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

std::string EQ_StringMap_GetValueByKey(std::unordered_map<uint32_t, std::string>& stringMap, uint32_t key);
uint32_t EQ_StringMap_GetKeyByValue(std::unordered_map<uint32_t, std::string>& stringMap, std::string value);
std::string EQ_GetSpawnTypeNameByKey(uint32_t key);
std::string EQ_GetStandingStateNameByKey(uint32_t key);
std::string EQ_GetDirectionNameByKey(uint32_t key);
std::string EQ_GetZoneNameByKey(uint32_t key);
std::string EQ_GetZoneShortNameByKey(uint32_t key);
std::string EQ_GetRaceNameByKey(uint32_t key);
std::string EQ_GetRaceShortNameByKey(uint32_t key);
std::string EQ_GetClassNameByKey(uint32_t key);
std::string EQ_GetClassShortNameByKey(uint32_t key);

void EQ_UseAlternateAbility(uint32_t alternateAbilityID);
void EQ_UseDiscipline(const char* disciplineName);
void EQ_UseAbility(uint32_t abilityNumber);
void EQ_UseItem(const char* itemName);

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

float EQ_CalculateDistance(float y1, float x1, float y2, float x2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

float EQ_CalculateDistance3D(float y1, float x1, float z1, float y2, float x2, float z2)
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) + std::pow(z2 - z1, 2));
}

bool EQ_IsWithinDistance(float y1, float x1, float y2, float x2, float distance)
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

void EQ_FixHeading(float& heading)
{
    if (heading < 0.0f)
    {
        heading = heading + EQ_HEADING_MAX;
    }
    else if (heading > EQ_HEADING_MAX)
    {
        heading = heading - EQ_HEADING_MAX;
    }
}

void EQ_FixPitch(float& pitch)
{
    if (pitch < EQ_SPAWN_PITCH_MIN)
    {
        pitch = EQ_SPAWN_PITCH_MIN;
    }
    else if (pitch > EQ_SPAWN_PITCH_MAX)
    {
        pitch = EQ_SPAWN_PITCH_MAX;
    }
}

float EQ_GetRadians(float degrees)
{
    return degrees * EQ_PI / EQ_HEADING_MAX_HALF;
}

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight)
{
    if (pointX < rectangleX)                        return false;
    if (pointY < rectangleY)                        return false;
    if (pointX > (rectangleX + rectangleWidth))     return false;
    if (pointY > (rectangleY + rectangleHeight))    return false;

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

bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& timerInterval)
{
    auto currentTimer = EQ_GetTimer();

    if ((currentTimer - timer) > timerInterval)
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

void EQ_SetFogDistanceBegin(float distance)
{
    EQ_WriteMemory<float>(EQ_ADDRESS_FOG_DISTANCE_BEGIN, distance);
}

void EQ_SetFogDistanceEnd(float distance)
{
    EQ_WriteMemory<float>(EQ_ADDRESS_FOG_DISTANCE_END, distance);
}

void EQ_SetFarClipPlane(uint32_t value)
{
    if (value >= EQ_FAR_CLIP_PLANE_MAX && value <= EQ_FAR_CLIP_PLANE_MAX)
    {
        EQ_WriteMemory<uint32_t>(EQ_ADDRESS_FAR_CLIP_PLANE, value);
    }
}

void EQ_SetFarClipPlanePercent(uint32_t percent)
{
    uint32_t value = 100;

    if (percent > 0)
    {
        if (percent > 100)
        {
            value = 100;
        }
        else
        {
            if (EQ_FAR_CLIP_PLANE_MAX > 0)
            {
                uint32_t percentPerValue = 100 / EQ_FAR_CLIP_PLANE_MAX;

                value = percent / percentPerValue;
            }
            else
            {
                value = 0;
            }
        }
    }
    else
    {
        value = 0;
    }

    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_FAR_CLIP_PLANE, value);
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

uint32_t EQ_GetPlayerSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PLAYER_SPAWN);
}

uint32_t EQ_GetTargetSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN);
}

void EQ_SetTargetSpawn(uint32_t spawn)
{
    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TARGET_SPAWN, spawn);
}

std::string EQ_GetPlayerSpawnNameNumbered()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnNameNumbered(playerSpawn);
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

std::string EQ_GetTargetSpawnNameNumbered()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return std::string();
    }

    return EQ_GetSpawnNameNumbered(targetSpawn);
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

    bool result = EQ_IsWithinDistance(playerSpawnY, playerSpawnX, spawnY, spawnX, distance);

    return result;
}

bool EQ_IsSpawnWithinDistanceOfLocation(uint32_t spawn, float distance, float y, float x, float z)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    auto diffY = std::fabs(spawnY - y);
    auto diffX = std::fabs(spawnX - x);
    auto diffZ = std::fabs(spawnZ - z);

    bool result = (diffY < distance && diffX < distance && diffZ < 10.0f);

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

    float spawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, spawnY, spawnX);

    return spawnDistance;
}

float EQ_GetSpawnDistance3D(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return -1.0f;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    float spawnDistance = EQ_CalculateDistance3D(playerSpawnY, playerSpawnX, playerSpawnZ, spawnY, spawnX, spawnZ);

    return spawnDistance;
}

bool EQ_CanSpawnCastRayToLocation(uint32_t spawn, float y, float x, float z)
{
    int result = EQ_FUNCTION_CastRay(spawn, y, x, z);

    return (result != 0);
}

bool EQ_IsSpawnTargetable(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_IS_TARGETABLE);
}

bool EQ_IsSpawnSwimming(uint32_t spawn)
{
    auto underwater = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_UNDERWATER_ENVIRONMENT_TYPE);
    if (underwater != 0)
    {
        return true;
    }

    auto head = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_HEAD_ENVIRONMENT_TYPE);
    if (head != 0)
    {
        return true;
    }

    auto body = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_BODY_ENVIRONMENT_TYPE);
    auto feet = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_FEET_ENVIRONMENT_TYPE);
    if (body != 0 && feet != 0)
    {
        return true;
    }

    return false;
}

bool EQ_IsSpawnSwimmingUnderwater(uint32_t spawn)
{
    auto underwater = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_UNDERWATER_ENVIRONMENT_TYPE);
    if (underwater != 0)
    {
        return true;
    }

    auto head = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_HEAD_ENVIRONMENT_TYPE);
    auto body = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_BODY_ENVIRONMENT_TYPE);
    auto feet = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_FEET_ENVIRONMENT_TYPE);
    if (head != 0 && body != 0 && feet != 0)
    {
        return true;
    }

    return false;
}

bool EQ_IsSpawnBehindSpawn(uint32_t spawn1, uint32_t spawn2)
{
    // use 512 / 8 = 64 for tighter angle
    // use 512 / 4 = 128 for wider angle

    if (EQ_IsSpawnBehindSpawnEx(spawn1, spawn2, 64.0f) == true)
    {
        return true;
    }

    return false;
}

bool EQ_IsSpawnBehindSpawnEx(uint32_t spawn1, uint32_t spawn2, float angle)
{
    float heading1 = EQ_GetSpawnHeading(spawn1);
    float heading2 = EQ_GetSpawnHeading(spawn2);

    float headingDifference = std::fabsf(heading1 - heading2);

    if (headingDifference <= angle)
    {
        return true;
    }

    return false;
}

bool EQ_IsPlayerBehindTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return false;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    if (EQ_IsSpawnBehindSpawnEx(playerSpawn, targetSpawn, 64.0f) == true)
    {
        return true;
    }

    return false;
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

std::string EQ_GetSpawnNameNumbered(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return std::string();
    }

    char spawnNameNumbered[EQ_SIZE_SPAWN_NAME];
    ////memcpy(spawnNameNumbered, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME_NUMBERED), sizeof(spawnNameNumbered));
    std::memmove(spawnNameNumbered, (LPVOID)(spawn + EQ_OFFSET_SPAWN_NAME_NUMBERED), sizeof(spawnNameNumbered));

    if (strlen(spawnNameNumbered) == 0)
    {
        return std::string();
    }

    return spawnNameNumbered;
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

    return spawnName;
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

uint32_t EQ_GetSpawnPrevious(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_PREVIOUS);
}

uint32_t EQ_GetSpawnNext(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_NEXT);
}

float EQ_GetSpawnJumpStrength(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_JUMP_STRENGTH);
}

float EQ_GetSpawnMovementSpeedBonus(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_MOVEMENT_SPEED_BONUS);
}

float EQ_GetSpawnAreaFriction(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_AREA_FRICTION);
}

float EQ_GetSpawnAccelerationFriction(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_ACCELERATION_FRICTION);
}

uint32_t EQ_GetSpawnCollideWithActorType(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_COLLIDE_WITH_ACTOR_TYPE);
}

float EQ_GetSpawnFloorZ(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_FLOOR_Z);
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

float EQ_GetSpawnMovementSpeed(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_MOVEMENT_SPEED);
}

float EQ_GetSpawnHeading(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEADING);
}

float EQ_GetSpawnHeadingSpeed(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEADING_SPEED);
}

float EQ_GetSpawnPitch(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_PITCH);
}

uint32_t EQ_GetSpawnUnderwaterEnvironmentType(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_UNDERWATER_ENVIRONMENT_TYPE);
}

uint32_t EQ_GetSpawnHeadEnvironmentType(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_HEAD_ENVIRONMENT_TYPE);
}

uint32_t EQ_GetSpawnFeetEnvironmentType(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_FEET_ENVIRONMENT_TYPE);
}

uint32_t EQ_GetSpawnBodyEnvironmentType(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_BODY_ENVIRONMENT_TYPE);
}

uint32_t EQ_GetSpawnType(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_TYPE);
}

float EQ_GetSpawnHeightZ(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEIGHT_Z);
}

float EQ_GetSpawnHeight(uint32_t spawn)
{
    return EQ_ReadMemory<float>(spawn + EQ_OFFSET_SPAWN_HEIGHT);
}

uint32_t EQ_GetSpawnID(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ID);
}

uint32_t EQ_GetSpawnStateFlags(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_STATE_FLAGS);
}

uint32_t EQ_GetSpawnVehicleSpawn(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_VEHICLE_SPAWN);
}

uint32_t EQ_GetSpawnMountSpawn(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_MOUNT_SPAWN);
}

uint32_t EQ_GetSpawnMountRiderSpawn(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_MOUNT_RIDER_SPAWN);
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

uint32_t EQ_GetSpawnDirection(uint32_t spawn)
{
    float spawnHeading = EQ_GetSpawnHeading(spawn);

    uint32_t spawnHeadingInt = (uint32_t)spawnHeading;

    uint32_t direction = EQ_DIRECTION_UNKNOWN;

    if (spawnHeadingInt > 479)
    {
        direction = EQ_DIRECTION_NORTH;
    }
    else if (spawnHeadingInt > 416)
    {
        direction = EQ_DIRECTION_NORTH_EAST;
    }
    else if (spawnHeadingInt > 352)
    {
        direction = EQ_DIRECTION_EAST;
    }
    else if (spawnHeadingInt > 288)
    {
        direction = EQ_DIRECTION_SOUTH_EAST;
    }
    else if (spawnHeadingInt > 224)
    {
        direction = EQ_DIRECTION_SOUTH;
    }
    else if (spawnHeadingInt > 160)
    {
        direction = EQ_DIRECTION_SOUTH_WEST;
    }
    else if (spawnHeadingInt > 96)
    {
        direction = EQ_DIRECTION_WEST;
    }
    else if (spawnHeadingInt > 32)
    {
        direction = EQ_DIRECTION_NORTH_WEST;
    }
    else
    {
        direction = EQ_DIRECTION_NORTH;
    }

    return direction;
}

void EQ_SetSpawnAreaFriction(uint32_t spawn, float friction)
{
    EQ_WriteMemory<float>(spawn + EQ_OFFSET_SPAWN_AREA_FRICTION, friction);

    auto spawnMountSpawn = EQ_GetSpawnMountSpawn(spawn);
    if (spawnMountSpawn != NULL)
    {
        EQ_WriteMemory<float>(spawnMountSpawn + EQ_OFFSET_SPAWN_AREA_FRICTION, friction);
    }
}

void EQ_SetSpawnAccelerationFriction(uint32_t spawn, float friction)
{
    EQ_WriteMemory<float>(spawn + EQ_OFFSET_SPAWN_ACCELERATION_FRICTION, friction);

    auto spawnMountSpawn = EQ_GetSpawnMountSpawn(spawn);
    if (spawnMountSpawn != NULL)
    {
        EQ_WriteMemory<float>(spawnMountSpawn + EQ_OFFSET_SPAWN_ACCELERATION_FRICTION, friction);
    }
}

void EQ_SetSpawnHeading(uint32_t spawn, float heading)
{
    EQ_WriteMemory<float>(spawn + EQ_OFFSET_SPAWN_HEADING, heading);

    auto spawnMountSpawn = EQ_GetSpawnMountSpawn(spawn);
    if (spawnMountSpawn != NULL)
    {
        EQ_WriteMemory<float>(spawnMountSpawn + EQ_OFFSET_SPAWN_HEADING, heading);
    }
}

void EQ_SetSpawnPitch(uint32_t spawn, float pitch)
{
    EQ_WriteMemory<float>(spawn + EQ_OFFSET_SPAWN_PITCH, pitch);

    auto spawnMountSpawn = EQ_GetSpawnMountSpawn(spawn);
    if (spawnMountSpawn != NULL)
    {
        EQ_WriteMemory<float>(spawnMountSpawn + EQ_OFFSET_SPAWN_PITCH, pitch);
    }
}

void EQ_SetSpawnHeight(uint32_t spawn, float height)
{
    ((EQClass::EQPlayer*)spawn)->ChangeHeight(height, 0.0f, 1.0f, 0);
}

void EQ_SetSpawnFollowSpawn(uint32_t spawn, uint32_t followSpawn)
{
    EQ_WriteMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_FOLLOW_SPAWN, followSpawn);
}

bool EQ_SetSpawnItemSlot(uint32_t spawn, uint32_t updateItemSlot, const char* itemDefinition)
{
    return ((EQClass::EQPlayer*)spawn)->UpdateItemSlot(updateItemSlot, itemDefinition, false, true, false);
}

bool EQ_SetSpawnItemSlotPrimary(uint32_t spawn, const char* itemDefinition)
{
    return EQ_SetSpawnItemSlot(spawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, itemDefinition);
}

bool EQ_SetSpawnItemSlotSecondary(uint32_t spawn, const char* itemDefinition)
{
    return EQ_SetSpawnItemSlot(spawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, itemDefinition);
}

bool EQ_SetSpawnItemSlotHead(uint32_t spawn, const char* itemDefinition)
{
    return EQ_SetSpawnItemSlot(spawn, EQ_UPDATE_ITEM_SLOT_HEAD, itemDefinition);
}

void EQ_TurnSpawnTowardsLocation(uint32_t spawn, float y, float x)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    float heading = EQ_GetBearing(spawnY, spawnX, y, x);

    EQ_SetSpawnHeading(spawn, heading);
}

void EQ_TurnSpawnAwayFromLocation(uint32_t spawn, float y, float x)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    float heading = EQ_GetBearing(y, x, spawnY, spawnX);

    EQ_SetSpawnHeading(spawn, heading);
}

void EQ_TurnSpawnTowardsSpawn(uint32_t spawn1, uint32_t spawn2)
{
    auto spawnY = EQ_GetSpawnY(spawn2);
    auto spawnX = EQ_GetSpawnX(spawn2);

    EQ_TurnSpawnTowardsLocation(spawn1, spawnY, spawnX);
}

void EQ_TurnSpawnAwayFromSpawn(uint32_t spawn1, uint32_t spawn2)
{
    auto spawnY = EQ_GetSpawnY(spawn2);
    auto spawnX = EQ_GetSpawnX(spawn2);

    EQ_TurnSpawnAwayFromLocation(spawn1, spawnY, spawnX);
}

void EQ_TurnPlayerTowardsSpawn(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    EQ_TurnSpawnTowardsLocation(playerSpawn, spawnY, spawnX);
}

void EQ_TurnPlayerAwayFromSpawn(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    EQ_TurnSpawnAwayFromLocation(playerSpawn, spawnY, spawnX);
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

void EQ_TurnPlayerAwayFromTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    EQ_TurnPlayerAwayFromSpawn(targetSpawn);
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

void EQ_ExecuteCommandEx(const char* commandName, int isActive)
{
    int commandID = EQ_FUNCTION_GetExecuteCmdIDByName(commandName);

    EQ_ExecuteCommand(commandID, isActive);
}

uint32_t EQ_GetExecuteCommandIDByName(const char* commandName)
{
    return EQ_FUNCTION_GetExecuteCmdIDByName(commandName);
}

std::string EQ_GetExecuteCommandNameByID(uint32_t commandID)
{
    return EQ_FUNCTION_GetExecuteCmdNameByID(commandID);
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

void EQ_DrawLine(float lineBeginX, float lineBeginY, float lineEndX, float lineEndY, uint32_t colorARGB)
{
    if (EQ_ADDRESS_POINTER_CRender == 0)
    {
        return;
    }

    EQ::Point lineBegin;
    lineBegin.X = lineBeginX;
    lineBegin.Y = lineBeginY;
    lineBegin.Z = 1.0f;

    EQ::Point lineEnd;
    lineEnd.X = lineEndX;
    lineEnd.Y = lineEndY;
    lineEnd.Z = 1.0f;

    EQ_CLASS_POINTER_CRender->DrawLine(lineBegin, lineEnd, colorARGB);
}

void EQ_DrawLine3D(float lineBeginY, float lineBeginX, float lineBeginZ, float lineEndY, float lineEndX, float lineEndZ, uint32_t colorARGB)
{
    if (EQ_ADDRESS_POINTER_CRender == 0)
    {
        return;
    }

    float screenBeginX = 0.0f;
    float screenBeginY = 0.0f;
    bool resultBegin = EQ_WorldSpaceToScreenSpace(lineBeginY, lineBeginX, lineBeginZ, screenBeginX, screenBeginY);

    float screenEndX = 0.0f;
    float screenEndY = 0.0f;
    bool resultEnd = EQ_WorldSpaceToScreenSpace(lineEndY, lineEndX, lineEndZ, screenEndX, screenEndY);

    EQ_DrawLine(screenBeginX, screenBeginY, screenEndX, screenEndY, colorARGB);
}

void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled)
{
    if (EQ_ADDRESS_POINTER_CRender == 0)
    {
        return;
    }

    if (isFilled == true)
    {
        EQ::Rectangle rectangle;

        // top left
        rectangle.X1 = x;
        rectangle.Y1 = y;
        rectangle.Z1 = 1.0f;

        // top right
        rectangle.X2 = x + width;
        rectangle.Y2 = y;
        rectangle.Z2 = 1.0f;

        // bottom right
        rectangle.X3 = x + width;
        rectangle.Y3 = y + height;
        rectangle.Z3 = 1.0f;

        // bottom left
        rectangle.X4 = x;
        rectangle.Y4 = y + height;
        rectangle.Z4 = 1.0f;

        EQ_CLASS_POINTER_CRender->DrawFilledRectangle(rectangle, colorARGB);
    }
    else
    {
        EQ::Point p1;
        EQ::Point p2;
        EQ::Point p3;
        EQ::Point p4;

        // top left
        p1.X = x;
        p1.Y = y;
        p1.Z = 1.0f;

        // top right
        p2.X = x + width;
        p2.Y = y;
        p2.Z = 1.0f;

        // bottom right
        p3.X = x + width;
        p3.Y = y + height;
        p3.Z = 1.0f;

        // bottom left
        p4.X = x;
        p4.Y = y + height;
        p4.Z = 1.0f;

        EQ_CLASS_POINTER_CRender->DrawLine(p1, p2, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(p2, p3, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(p3, p4, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(p4, p1, colorARGB);
    }
}

float EQ_GetCameraPitch()
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return EQ_CAMERA_PITCH_MAX * 2.0f;
    }

    return EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_PITCH);
}

float EQ_GetCameraFieldOfView()
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return -1.0f;
    }

    return EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_FIELD_OF_VIEW);
}

float EQ_GetCameraDrawDistance()
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return -1.0f;
    }

    return EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_DRAW_DISTANCE);
}

void EQ_SetCameraPitch(float pitch)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemoryProtected<float>(camera + EQ_OFFSET_CCamera_PITCH, pitch);
}

void EQ_SetCameraFieldOfView(float fieldOfView)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_FIELD_OF_VIEW, fieldOfView);
}

void EQ_SetCameraDrawDistance(float drawDistance)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_DRAW_DISTANCE, drawDistance);
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

bool EQ_WorldSpaceToScreenSpace(float worldY, float worldX, float worldZ, float& screenX, float& screenY)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return false;
    }

    EQ::Location location;
    location.Y = worldY;
    location.X = worldX;
    location.Z = worldZ;

    return ((EQClass::CCamera*)camera)->WorldSpaceToScreenSpace(location, screenX, screenY);
}

bool EQ_WorldSpaceToScreenSpaceEx(float worldY, float worldX, float worldZ, float& screenX, float& screenY)
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

bool EQ_CXWnd_IsOpen(uint32_t cxwndAddressPointer)
{
    if (cxwndAddressPointer == 0)
    {
        return false;
    }

    uint32_t window = EQ_ReadMemory<uint32_t>(cxwndAddressPointer);
    if (window == NULL)
    {
        return false;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(window + EQ_OFFSET_CXWnd_IS_OPEN);

    return (isOpen == 1);

    ////return ((EQClass::CXWnd*)window)->IsReallyVisible();
}

bool EQ_CXWnd_Open(uint32_t cxwndAddressPointer)
{
    if (cxwndAddressPointer == 0)
    {
        return false;
    }

    uint32_t window = EQ_ReadMemory<uint32_t>(cxwndAddressPointer);
    if (window == NULL)
    {
        return false;
    }

    ((EQClass::CXWnd*)window)->Activate();

    return true;
}

bool EQ_CXWnd_Close(uint32_t cxwndAddressPointer)
{
    if (cxwndAddressPointer == 0)
    {
        return false;
    }

    uint32_t window = EQ_ReadMemory<uint32_t>(cxwndAddressPointer);
    if (window == NULL)
    {
        return false;
    }

    ((EQClass::CXWnd*)window)->Deactivate();

    return true;
}

bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset)
{
    if (cxwndAddressPointer == 0)
    {
        return false;
    }

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

uint32_t EQ_PlayerWindow_GetCombatState()
{
    uint32_t playerWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CPlayerWindow);
    if (playerWindow == NULL)
    {
        return 0xFFFFFFF;
    }

    return EQ_ReadMemory<uint32_t>(playerWindow + EQ_OFFSET_CPlayerWindow_COMBAT_STATE);
}

bool EQ_BazaarSearchWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBazaarSearchWnd) == true);
}

void EQ_BazaarSearchWindow_DoQuery()
{
    EQ_CLASS_POINTER_CBazaarSearchWnd->doQuery();
}

uint32_t EQ_BazaarSearchWindow_GetListIndexByItemName(const char* itemName, bool useExactComparsion)
{
    uint32_t bazaarSearchWindow = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    if (bazaarSearchWindow == NULL)
    {
        return 0xFFFFFFFF;
    }

    uint8_t isOpen = EQ_ReadMemory<uint8_t>(bazaarSearchWindow + EQ_OFFSET_CXWnd_IS_OPEN);
    if (isOpen == 0)
    {
        return 0xFFFFFFFF;
    }

    for (size_t i = 0; i < EQ_BAZAAR_SEARCH_MAX_RESULTS_PER_TRADER; i++)
    {
        char itemNameEx[EQ_SIZE_CBazaarSearchWnd_ITEM_NAME];
        std::memmove(itemNameEx, (LPVOID)(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME + (i * EQ_SIZE_CBazaarSearchWnd_ITEM))), sizeof(itemNameEx));

        if (strlen(itemNameEx) == 0)
        {
            break;
        }

        if (useExactComparsion == true)
        {
            if (strcmp(itemNameEx, itemName) == 0)
            {
                return i;
            }
        }
        else
        {
            if (strstr(itemNameEx, itemName) != 0)
            {
                return i;
            }
        }
    }

    return 0xFFFFFFFF;
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

std::string EQ_StringMap_GetValueByKey(std::unordered_map<uint32_t, std::string>& stringMap, uint32_t key)
{
    auto it = stringMap.find(key);
    if (it != stringMap.end())
    {
        return it->second;
    }

    return std::string();
}

uint32_t EQ_StringMap_GetKeyByValue(std::unordered_map<uint32_t, std::string>& stringMap, std::string value)
{
    for (auto it = stringMap.begin(); it != stringMap.end(); ++it)
    {
        if (it->second == value)
        {
            return it->first;
        }
    }

    return 0xFFFFFFFF;
}

std::string EQ_GetSpawnTypeNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_SPAWN_TYPE_NAME, key);
}

std::string EQ_GetStandingStateNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_STANDING_STATE_NAME, key);
}

std::string EQ_GetDirectionNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_DIRECTION_NAME, key);
}

std::string EQ_GetZoneNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_ZONE_NAME, key);
}

std::string EQ_GetZoneShortNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_ZONE_SHORT_NAME, key);
}

std::string EQ_GetRaceNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_RACE_NAME, key);
}

std::string EQ_GetRaceShortNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_RACE_SHORT_NAME, key);
}

std::string EQ_GetClassNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_CLASS_NAME, key);
}

std::string EQ_GetClassShortNameByKey(uint32_t key)
{
    return EQ_StringMap_GetValueByKey(EQ_STRING_MAP_CLASS_SHORT_NAME, key);
}

void EQ_UseAlternateAbility(uint32_t alternateAbilityID)
{
    std::stringstream ss;
    ss << "/alt activate " << alternateAbilityID;

    EQ_InterpretCommand(ss.str().c_str());
}

void EQ_UseDiscipline(const char* disciplineName)
{
    std::stringstream ss;
    ss << "/discipline " << disciplineName;

    EQ_InterpretCommand(ss.str().c_str());
}

void EQ_UseAbility(uint32_t abilityNumber)
{
    std::stringstream ss;
    ss << "/doability " << abilityNumber;

    EQ_InterpretCommand(ss.str().c_str());
}

void EQ_UseItem(const char* itemName)
{
    std::stringstream ss;
    ss << "/useitem " << itemName;

    EQ_InterpretCommand(ss.str().c_str());
}
