#pragma once

#include <string>
#include <sstream>
#include <tuple>
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

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CollisionCallbackForActors(uint32_t cactor), EQ_ADDRESS_FUNCTION_CollisionCallbackForActors);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CollisionCallbackForActors)(uint32_t cactor);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CastRay(uint32_t spawn, float y, float x, float z), EQ_ADDRESS_FUNCTION_CastRay);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay)(uint32_t spawn, float y, float x, float z);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CastRay2(const EQClass::CVector3& sourcePosition, int race, float destinationX, float destinationY, float destinationZ), EQ_ADDRESS_FUNCTION_CastRay2);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay2)(const EQClass::CVector3& sourcePosition, int race, float destinationX, float destinationY, float destinationZ);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero), EQ_ADDRESS_FUNCTION_ExecuteCmd);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCmd)(uint32_t commandID, int isActive, void* unknown, int zero);

/* function prototypes */

void EQ_Log(const char* text);

void EQ_ToggleBool(bool& b);

float EQ_CalculateDistance(float y1, float x1, float y2, float x2);
float EQ_CalculateDistance3D(float y1, float x1, float z1, float y2, float x2, float z2);
bool EQ_IsWithinDistance(float y1, float x1, float y2, float x2, float distance);

float EQ_GetBearing(float y1, float x1, float y2, float x2);
float EQ_RoundHeading(float heading);
float EQ_FixHeading(float heading);
float EQ_FixPitch(float pitch);
float EQ_GetRadians(float degrees);
float EQ_GetDegrees(float radians);

void EQ_ApplyForwardMovement(float& y, float& x, float heading, float distance);
void EQ_ApplyBackwardMovement(float& y, float& x, float heading, float distance);
void EQ_ApplyLeftwardMovement(float& y, float& x, float heading, float distance);
void EQ_ApplyRightwardMovement(float& y, float& x, float heading, float distance);

std::tuple<float, float> EQ_ApplyForwardMovementAsTuple(float y, float x, float heading, float distance);
std::tuple<float, float> EQ_ApplyBackwardMovementAsTuple(float y, float x, float heading, float distance);
std::tuple<float, float> EQ_ApplyLeftwardMovementAsTuple(float y, float x, float heading, float distance);
std::tuple<float, float> EQ_ApplyRightwardMovementAsTuple(float y, float x, float heading, float distance);

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight);
uint32_t EQ_ColorARGB_Darken(uint32_t colorARGB, float percent);

EQ::Vector2f EQ_Vector2f_GetMidpoint(float y1, float x1, float y2, float x2);
EQ::Vector3f EQ_Vector3f_GetMidpoint(float y1, float x1, float z1, float y2, float x2, float z2);
float EQ_GetLineSlope(float y1, float x1, float y2, float x2);

float EQ_Vector3f_GetLengthSquared(float y, float x, float z);
float EQ_Vector3f_GetLength(float y, float x, float z);
float EQ_Vector3f_GetDotProduct(float y1, float x1, float z1, float y2, float x2, float z2);
EQ::Vector3f EQ_Vector3f_GetCrossProduct(float y1, float x1, float z1, float y2, float x2, float z2);

uint32_t EQ_GetGameState();
bool EQ_IsInGame();
bool EQ_IsSpellIDValid(uint32_t spellID);
bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& timerInterval);
HWND EQ_GetWindow();
uint32_t EQ_GetTimer();
uint32_t EQ_GetCamera();
uint32_t EQ_GetRender();

POINT EQ_GetMousePosition();
std::tuple<int, int> EQ_GetMousePositionAsTuple();
int EQ_GetMouseX();
int EQ_GetMouseY();

bool EQ_IsNetStatusEnabled();
bool EQ_IsAutoAttackEnabled();
bool EQ_IsAutoRunEnabled();
bool EQ_IsMouseLookEnabled();

void EQ_SetNetStatus(bool b);
void EQ_SetAutoAttack(bool b);
void EQ_SetAutoRun(bool b);
void EQ_SetMouseLook(bool b);

bool EQ_CastSpellByGemIndex(uint32_t spellGemIndex);

std::vector<uint32_t> EQ_GetSpawnList();
bool EQ_DoesSpawnExist(uint32_t spawn);
uint32_t EQ_GetNumNearbySpawns(uint32_t spawnType, float distance, float distanceZ);

uint32_t EQ_GetSpawnByID(uint32_t spawnID);
uint32_t EQ_GetSpawnByName(const char* spawnName);

uint32_t EQ_GetFirstSpawn();
uint32_t EQ_GetLastSpawn();

uint32_t EQ_GetPlayerSpawn();
uint32_t EQ_GetTargetSpawn();

void EQ_SetTargetSpawn(uint32_t spawn);
void EQ_SetTargetSpawnByName(const char* spawnName);
void EQ_SetTargetSpawnByID(uint32_t spawnID);

std::string EQ_GetPlayerSpawnNameNumbered();
std::string EQ_GetPlayerSpawnName();
std::string EQ_GetPlayerSpawnLastName();

std::string EQ_GetTargetSpawnNameNumbered();
std::string EQ_GetTargetSpawnName();
std::string EQ_GetTargetSpawnLastName();

float EQ_GetSpawnDistance(uint32_t spawn);
float EQ_GetSpawnDistance3D(uint32_t spawn);

bool EQ_IsSpawnWithinDistance(uint32_t spawn, float distance);
bool EQ_IsSpawnWithinDistanceOfLocation(uint32_t spawn, float y, float x, float z, float distance);
bool EQ_IsSpawnWithinDistanceOfSpawn(uint32_t spawn1, uint32_t spawn2, float distance);

bool EQ_CastRay(float y1, float x1, float z1, float y2, float x2, float z2);
bool EQ_CanSpawnCastRayToLocation(uint32_t spawn, float y, float x, float z);
bool EQ_CanSpawnCastRayToSpawn(uint32_t spawn1, uint32_t spawn2);

bool EQ_IsSpawnTargetable(uint32_t spawn);

bool EQ_IsLocationOnScreen(float y, float x, float z);
bool EQ_IsSpawnOnScreen(uint32_t spawn);

bool EQ_IsSpawnSwimming(uint32_t spawn);
bool EQ_IsSpawnSwimmingUnderwater(uint32_t spawn);

bool EQ_IsSpawnMoving(uint32_t spawn);
bool EQ_IsPlayerMoving();
bool EQ_IsTargetMoving();

bool EQ_IsSpawnBehindSpawn(uint32_t spawn1, uint32_t spawn2);
bool EQ_IsSpawnBehindSpawnEx(uint32_t spawn1, uint32_t spawn2, float angle);
bool EQ_IsPlayerBehindSpawn(uint32_t spawn);
bool EQ_IsPlayerBehindTarget();
bool EQ_IsSpawnBehindPlayer(uint32_t spawn);
bool EQ_IsTargetBehindPlayer();

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
uint8_t EQ_GetSpawnLevel(uint32_t spawn);

void EQ_SetSpawnAreaFriction(uint32_t spawn, float friction);
void EQ_SetSpawnAccelerationFriction(uint32_t spawn, float friction);
void EQ_SetSpawnHeading(uint32_t spawn, float heading);
void EQ_SetSpawnPitch(uint32_t spawn, float pitch);
void EQ_SetSpawnHeight(uint32_t spawn, float height);

void EQ_SetPlayerSpawnHeadingNorth();
void EQ_SetPlayerSpawnHeadingNorthWest();
void EQ_SetPlayerSpawnHeadingWest();
void EQ_SetPlayerSpawnHeadingSouthWest();
void EQ_SetPlayerSpawnHeadingSouth();
void EQ_SetPlayerSpawnHeadingSouthEast();
void EQ_SetPlayerSpawnHeadingEast();
void EQ_SetPlayerSpawnHeadingNorthEast();

void EQ_TurnLeft();
void EQ_TurnRight();
void EQ_TurnAround();

void EQ_TurnCameraTowardsLocation(float y, float x);
void EQ_TurnSpawnTowardsLocation(uint32_t spawn, float y, float x);
void EQ_TurnSpawnAwayFromLocation(uint32_t spawn, float y, float x);
void EQ_TurnSpawnTowardsSpawn(uint32_t spawn1, uint32_t spawn2);
void EQ_TurnSpawnAwayFromSpawn(uint32_t spawn1, uint32_t spawn2);
void EQ_TurnPlayerTowardsSpawn(uint32_t spawn);
void EQ_TurnPlayerAwayFromSpawn(uint32_t spawn);
void EQ_TurnPlayerTowardsTarget();
void EQ_TurnPlayerAwayFromTarget();

void EQ_LookCameraAtLocation(float y, float x, float z);
void EQ_LookCameraAtSpawn(uint32_t spawn);
void EQ_LookCameraAtTarget();
void EQ_LookPlayerAtLocation(float y, float x, float z);
void EQ_LookPlayerAtSpawn(uint32_t spawn);
void EQ_LookPlayerAtTarget();

void EQ_InterpretCommand(const char* text);
void EQ_ExecuteCommand(uint32_t commandID, int isActive);

void EQ_PrintTextToChat(const char* text);
void EQ_PrintTextToChatByColor(const char* text, int color);

void EQ_DrawText(const char* text, int x, int y);
void EQ_DrawTextByColor(const char* text, int x, int y, int color);

void EQ_DrawLine(float lineBeginX, float lineBeginY, float lineEndX, float lineEndY, uint32_t colorARGB);
void EQ_DrawLine3D(float lineBeginY, float lineBeginX, float lineBeginZ, float lineEndY, float lineEndX, float lineEndZ, uint32_t colorARGB);
void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled);

float EQ_GetCameraPitch();
float EQ_GetCameraFieldOfView();
float EQ_GetCameraDrawDistance();
float EQ_GetCameraFarClipPlane();

void EQ_SetCameraLocation(float y, float x, float z);
void EQ_SetCameraPitch(float pitch);
void EQ_SetCameraFieldOfView(float fieldOfView);
void EQ_SetCameraDrawDistance(float distance);
void EQ_SetCameraFarClipPlane(float distance);

bool EQ_WorldLocationToScreenLocation(float worldY, float worldX, float worldZ, float& screenX, float& screenY);
bool EQ_WorldLocationToScreenLocationEx(float worldY, float worldX, float worldZ, float& screenX, float& screenY);
std::tuple<float, float, bool> EQ_WorldLocationToScreenLocationAsTuple(float worldY, float worldX, float worldZ);

void EQ_TakeScreenshot(const char* fileName);

void EQ_PlaySound(const char* fileName);
void EQ_StopSound();

void EQ_CenterView();
void EQ_LookUp();
void EQ_LookDown();
void EQ_StopFollow();
void EQ_FollowTarget();
void EQ_FollowSpawnByName(const char* spawnName);
void EQ_FollowSpawnByID(uint32_t spawnID);
void EQ_ClearTarget();

std::string EQ_StringMap_GetValueByKey(std::unordered_map<uint32_t, std::string>& stringMap, uint32_t key);
uint32_t EQ_StringMap_GetKeyByValue(std::unordered_map<uint32_t, std::string>& stringMap, const std::string& value);

void EQ_UseAlternateAbility(uint32_t alternateAbilityID);
void EQ_UseDiscipline(const char* disciplineName);
void EQ_UseAbility(uint32_t abilityNumber);
void EQ_UseItem(const char* itemName);

bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset);

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
    return std::sqrtf(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

float EQ_CalculateDistance3D(float y1, float x1, float z1, float y2, float x2, float z2)
{
    return std::sqrtf(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) + std::pow(z2 - z1, 2));
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

float EQ_RoundHeading(float heading)
{
    if (heading == 0.0f)
    {
        return heading;
    }

    heading = std::roundf(heading / EQ_HEADING_MAX_QUARTER) * EQ_HEADING_MAX_QUARTER;

    return heading;
}

float EQ_FixHeading(float heading)
{
    if (heading < 0.0f)
    {
        heading = heading + EQ_HEADING_MAX;
    }
    else if (heading > EQ_HEADING_MAX)
    {
        heading = heading - EQ_HEADING_MAX;
    }

    return heading;
}

float EQ_FixPitch(float pitch)
{
    if (pitch < EQ_SPAWN_PITCH_MIN)
    {
        pitch = EQ_SPAWN_PITCH_MIN;
    }
    else if (pitch > EQ_SPAWN_PITCH_MAX)
    {
        pitch = EQ_SPAWN_PITCH_MAX;
    }

    return pitch;
}

float EQ_GetRadians(float degrees)
{
    if (degrees == 0.0f)
    {
        return 0.0f;
    }

    return (degrees * EQ_PI) / EQ_HEADING_MAX_HALF;
}

float EQ_GetDegrees(float radians)
{
    if (radians == 0.0f)
    {
        return 0.0f;
    }

    return (radians * EQ_HEADING_MAX_HALF) / EQ_PI;
}

void EQ_ApplyForwardMovement(float& y, float& x, float heading, float distance)
{
    heading = heading + 128.0f;

    heading = EQ_FixHeading(heading);

    float headingRadians = EQ_GetRadians(heading);

    float addY = std::sinf(headingRadians);
    float addX = std::cosf(headingRadians);

    y += addY * distance;
    x -= addX * distance;
}

void EQ_ApplyBackwardMovement(float& y, float& x, float heading, float distance)
{
    heading = heading - 128.0f;

    heading = EQ_FixHeading(heading);

    float headingRadians = EQ_GetRadians(heading);

    float addY = std::sinf(headingRadians);
    float addX = std::cosf(headingRadians);

    y += addY * distance;
    x -= addX * distance;
}

void EQ_ApplyLeftwardMovement(float& y, float& x, float heading, float distance)
{
    //heading = heading + 0.0f;

    heading = EQ_FixHeading(heading);

    float headingRadians = EQ_GetRadians(heading);

    float addY = std::sinf(headingRadians);
    float addX = std::cosf(headingRadians);

    y -= addY * distance;
    x += addX * distance;
}

void EQ_ApplyRightwardMovement(float& y, float& x, float heading, float distance)
{
    heading = heading + 256.0f;

    heading = EQ_FixHeading(heading);

    float headingRadians = EQ_GetRadians(heading);

    float addY = std::sinf(headingRadians);
    float addX = std::cosf(headingRadians);

    y -= addY * distance;
    x += addX * distance;
}

// returns <newY, newX>
std::tuple<float, float> EQ_ApplyForwardMovementAsTuple(float y, float x, float heading, float distance)
{
    float resultY = y;
    float resultX = x;

    EQ_ApplyForwardMovement(resultY, resultX, heading, distance);

    return std::make_tuple(resultY, resultX);
}

// returns <newY, newX>
std::tuple<float, float> EQ_ApplyBackwardMovementAsTuple(float y, float x, float heading, float distance)
{
    float resultY = y;
    float resultX = x;

    EQ_ApplyBackwardMovement(resultY, resultX, heading, distance);

    return std::make_tuple(resultY, resultX);
}

// returns <newY, newX>
std::tuple<float, float> EQ_ApplyLeftwardMovementAsTuple(float y, float x, float heading, float distance)
{
    float resultY = y;
    float resultX = x;

    EQ_ApplyLeftwardMovement(resultY, resultX, heading, distance);

    return std::make_tuple(resultY, resultX);
}

// returns <newY, newX>
std::tuple<float, float> EQ_ApplyRightwardMovementAsTuple(float y, float x, float heading, float distance)
{
    float resultY = y;
    float resultX = x;

    EQ_ApplyRightwardMovement(resultY, resultX, heading, distance);

    return std::make_tuple(resultY, resultX);
}

bool EQ_IsPointInsideRectangle(int pointX, int pointY, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight)
{
    if (pointX < rectangleX)                        return false;
    if (pointY < rectangleY)                        return false;
    if (pointX > (rectangleX + rectangleWidth))     return false;
    if (pointY > (rectangleY + rectangleHeight))    return false;

    return true;
}

uint32_t EQ_ColorARGB_Darken(uint32_t colorARGB, float percent)
{
    if (percent == 0.0f)
    {
        return colorARGB;
    }

    percent = percent / 100.0f; // value between 0.0 and 1.0

    uint32_t alpha = (colorARGB >> 24) & 0xFF;
    uint32_t red   = (colorARGB >> 16) & 0xFF;
    uint32_t green = (colorARGB >> 8)  & 0xFF;
    uint32_t blue  =  colorARGB        & 0xFF;

    red   = (uint32_t)(red   * percent);
    green = (uint32_t)(green * percent);
    blue  = (uint32_t)(blue  * percent);

    return ((alpha << 24) + (red << 16) + (green << 8) + blue);
}

EQ::Vector2f EQ_Vector2f_GetMidpoint(float y1, float x1, float y2, float x2)
{
    EQ::Vector2f vector;
    vector.Y = (y1 + y2) * 0.5f;
    vector.X = (x1 + x2) * 0.5f;

    return vector;
}

EQ::Vector3f EQ_Vector3f_GetMidpoint(float y1, float x1, float z1, float y2, float x2, float z2)
{
    EQ::Vector3f vector;
    vector.X = (x1 + x2) * 0.5f;
    vector.Y = (y1 + y2) * 0.5f;
    vector.Z = (z1 + z2) * 0.5f;

    return vector;
}

float EQ_GetLineSlope(float y1, float x1, float y2, float x2)
{
    return (y2 - y1) / (x2 - x1);
}

float EQ_Vector3f_GetLengthSquared(float y, float x, float z)
{
    return (x * x) + (y * y) + (z * z);
}

float EQ_Vector3f_GetLength(float y, float x, float z)
{
    return std::sqrtf(EQ_Vector3f_GetLengthSquared(y, x, z));
}

float EQ_Vector3f_GetDotProduct(float y1, float x1, float z1, float y2, float x2, float z2)
{
    return (x1 * x2) + (y1 * y2) + (z1 * z2);
}

EQ::Vector3f EQ_Vector3f_GetCrossProduct(float y1, float x1, float z1, float y2, float x2, float z2)
{
    EQ::Vector3f vector;
    vector.X = (y1 * z2) - (y2 * z1);
    vector.Y = (z1 * x2) - (z2 * x1);
    vector.Z = (x1 * y2) - (x2 * y1);

    return vector;
}

uint32_t EQ_GetGameState()
{
    uint32_t everquest = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CEverQuest);
    if (everquest == NULL)
    {
        return EQ_GAME_STATE_NULL;
    }

    return EQ_ReadMemory<uint32_t>(everquest + EQ_OFFSET_CEverQuest_GAME_STATE);
}

bool EQ_IsInGame()
{
    return EQ_GetGameState() == EQ_GAME_STATE_IN_GAME;
}

bool EQ_IsSpellIDValid(uint32_t spellID)
{
    return spellID <= (EQ_NUM_SPELLS - 1);
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

HWND EQ_GetWindow()
{
    return EQ_ReadMemory<HWND>(EQ_ADDRESS_WindowHWND);
}

bool EQ_IsWindowInBackground()
{
    HWND eqWindow = EQ_GetWindow();
    if (eqWindow == NULL)
    {
        return true;
    }

    HWND foregroundWindow = GetForegroundWindow();
    if (foregroundWindow == NULL)
    {
        return true;
    }

    return eqWindow != foregroundWindow;
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

uint32_t EQ_GetRender()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CRender);
}

POINT EQ_GetMousePosition()
{
    HWND window = EQ_GetWindow();

    POINT point;
    GetCursorPos(&point);

    ScreenToClient(window, &point);

    return point;
}

std::tuple<int, int> EQ_GetMousePositionAsTuple()
{
    auto mousePosition = EQ_GetMousePosition();

    return std::make_tuple(mousePosition.x, mousePosition.y);
}

int EQ_GetMouseX()
{
    auto mousePosition = EQ_GetMousePosition();

    return mousePosition.x;
}

int EQ_GetMouseY()
{
    auto mousePosition = EQ_GetMousePosition();

    return mousePosition.y;
}

bool EQ_IsNetStatusEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_NetStatus);
}

bool EQ_IsAutoAttackEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AutoAttack);
}

bool EQ_IsAutoRunEnabled()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_AutoRun);
}

bool EQ_IsMouseLookEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_MouseLook);
}

void EQ_SetNetStatus(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_NetStatus, value);
}

void EQ_SetAutoAttack(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_AutoAttack, value);
}

void EQ_SetAutoRun(bool b)
{
    uint32_t value = (uint32_t)b;

    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_AutoRun, value);
}

void EQ_SetMouseLook(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_MouseLook, value);
}

bool EQ_CastSpellByGemIndex(uint32_t spellGemIndex)
{
    if (spellGemIndex > (EQ_NUM_SPELL_GEMS - 1))
    {
        return false;
    }

    std::stringstream ss;
    ss << "/cast " << spellGemIndex + 1;

    // cast the spell multiple times in case of fizzles
    for (unsigned int i = 0; i < 4; i++)
    {
        EQ_InterpretCommand(ss.str().c_str());
    }

    return true;
}

std::vector<uint32_t> EQ_GetSpawnList()
{
    std::vector<uint32_t> spawnList;
    spawnList.reserve(4096);

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        spawnList.push_back(spawn);

        spawn = EQ_GetSpawnNext(spawn);
    }

    return spawnList;
}

bool EQ_DoesSpawnExist(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return false;
    }

    auto currentSpawn = EQ_GetFirstSpawn();
    while (currentSpawn != NULL)
    {
        if (currentSpawn == spawn)
        {
            return true;
        }

        currentSpawn = EQ_GetSpawnNext(currentSpawn);
    }

    return false;
}

uint32_t EQ_GetNumNearbySpawns(uint32_t spawnType, float distance, float distanceZ)
{
    uint32_t count = 0;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return count;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);
        auto spawnZ = EQ_GetSpawnZ(spawn);

        auto spawnType_ = EQ_GetSpawnType(spawn);
        if (spawnType_ != spawnType)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        float spawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, spawnY, spawnX);
        if (spawnDistance > distance)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        float spawnDistanceZ = std::fabsf(playerSpawnZ - spawnZ);
        if (spawnDistanceZ > distanceZ)
        {
            spawn = EQ_GetSpawnNext(spawn);
            continue;
        }

        count++;

        spawn = EQ_GetSpawnNext(spawn);
    }

    return count;
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
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerSpawn);
}

uint32_t EQ_GetTargetSpawn()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_TargetSpawn);
}

void EQ_SetTargetSpawn(uint32_t spawn)
{
    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_POINTER_TargetSpawn, spawn);
}

void EQ_SetTargetSpawnByID(uint32_t spawnID)
{
    auto spawn = EQ_GetSpawnByID(spawnID);
    if (spawn == NULL)
    {
        return;
    }

    EQ_SetTargetSpawn(spawn);
}

void EQ_SetTargetSpawnByName(const char* spawnName)
{
    auto spawn = EQ_GetSpawnByName(spawnName);
    if (spawn == NULL)
    {
        return;
    }

    EQ_SetTargetSpawn(spawn);
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

bool EQ_IsSpawnWithinDistanceOfLocation(uint32_t spawn, float y, float x, float z, float distance)
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

bool EQ_IsSpawnWithinDistanceOfSpawn(uint32_t spawn1, uint32_t spawn2, float distance)
{
    auto spawnY = EQ_GetSpawnY(spawn2);
    auto spawnX = EQ_GetSpawnX(spawn2);
    auto spawnZ = EQ_GetSpawnZ(spawn2);

    return EQ_IsSpawnWithinDistanceOfLocation(spawn1, distance, spawnY, spawnX, spawnZ);
}

bool EQ_CastRay(float y1, float x1, float z1, float y2, float x2, float z2)
{
    EQClass::CVector3 vector;
    vector.Set(x1, y1, z1);

    int result = EQ_FUNCTION_CastRay2(vector, EQ_RACE_UNKNOWN, y2, x2, z2);

    return (result != 0);
}

bool EQ_CanSpawnCastRayToLocation(uint32_t spawn, float y, float x, float z)
{
    int result = EQ_FUNCTION_CastRay(spawn, y, x, z);

    return (result != 0);
}

bool EQ_CanSpawnCastRayToSpawn(uint32_t spawn1, uint32_t spawn2)
{
    auto spawnY = EQ_GetSpawnY(spawn2);
    auto spawnX = EQ_GetSpawnX(spawn2);
    auto spawnZ = EQ_GetSpawnZ(spawn2);

    return EQ_CanSpawnCastRayToLocation(spawn1, spawnY, spawnX, spawnZ);
}

bool EQ_IsSpawnTargetable(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_IS_TARGETABLE);
}

bool EQ_IsLocationOnScreen(float y, float x, float z)
{
    float screenX = -1.0f;
    float screenY = -1.0f;
    return EQ_WorldLocationToScreenLocation(y, x, z, screenX, screenY);
}

bool EQ_IsSpawnOnScreen(uint32_t spawn)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    return EQ_IsLocationOnScreen(spawnY, spawnX, spawnZ);
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

bool EQ_IsSpawnMoving(uint32_t spawn)
{
    auto spawnMovementSpeed = EQ_GetSpawnMovementSpeed(spawn);

    return (spawnMovementSpeed != 0.0f);
}

bool EQ_IsPlayerMoving()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    return EQ_IsSpawnMoving(playerSpawn);
}

bool EQ_IsTargetMoving()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return false;
    }

    return EQ_IsSpawnMoving(targetSpawn);
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

bool EQ_IsPlayerBehindSpawn(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    if (spawn == NULL)
    {
        return false;
    }

    if (EQ_IsSpawnBehindSpawnEx(playerSpawn, spawn, 64.0f) == true)
    {
        return true;
    }

    return false;
}

bool EQ_IsPlayerBehindTarget()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return false;
    }

    return EQ_IsPlayerBehindSpawn(targetSpawn);
}

bool EQ_IsSpawnBehindPlayer(uint32_t spawn)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    if (spawn == NULL)
    {
        return false;
    }

    if (EQ_IsSpawnBehindSpawnEx(spawn, playerSpawn, 64.0f) == true)
    {
        return true;
    }

    return false;
}

bool EQ_IsTargetBehindPlayer()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return false;
    }

    return EQ_IsSpawnBehindPlayer(targetSpawn);
}

std::string EQ_GetSpawnNameNumbered(uint32_t spawn)
{
    if (spawn == NULL)
    {
        return std::string();
    }

    char spawnNameNumbered[EQ_SIZE_SPAWN_NAME];
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

uint8_t EQ_GetSpawnLevel(uint32_t spawn)
{
    return ((EQClass::EQPlayer*)spawn)->GetLevel();
}

uint32_t EQ_GetSpawnDirection(uint32_t spawn)
{
    float spawnHeading = EQ_GetSpawnHeading(spawn);

    uint32_t spawnHeadingInt = (uint32_t)spawnHeading;

    uint32_t direction = EQ_DIRECTION_NULL;

    if (spawnHeading == EQ_HEADING_NORTH)
    {
        direction = EQ_DIRECTION_NORTH;
    }
    else if (spawnHeading == EQ_HEADING_NORTH_EAST)
    {
        direction = EQ_DIRECTION_NORTH_EAST;
    }
    else if (spawnHeading == EQ_HEADING_EAST)
    {
        direction = EQ_DIRECTION_EAST;
    }
    else if (spawnHeading == EQ_HEADING_SOUTH_EAST)
    {
        direction = EQ_DIRECTION_SOUTH_EAST;
    }
    else if (spawnHeading == EQ_HEADING_SOUTH)
    {
        direction = EQ_DIRECTION_SOUTH;
    }
    else if (spawnHeading == EQ_HEADING_SOUTH_WEST)
    {
        direction = EQ_DIRECTION_SOUTH_WEST;
    }
    else if (spawnHeading == EQ_HEADING_WEST)
    {
        direction = EQ_DIRECTION_WEST;
    }
    else if (spawnHeading == EQ_HEADING_NORTH_WEST)
    {
        direction = EQ_DIRECTION_NORTH_WEST;
    }
    else
    {
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

void EQ_SetPlayerSpawnHeadingNorth()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_NORTH);
}

void EQ_SetPlayerSpawnHeadingNorthWest()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_NORTH_WEST);
}

void EQ_SetPlayerSpawnHeadingWest()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_WEST);
}

void EQ_SetPlayerSpawnHeadingSouthWest()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_SOUTH_WEST);
}

void EQ_SetPlayerSpawnHeadingSouth()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_SOUTH);
}

void EQ_SetPlayerSpawnHeadingSouthEast()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_SOUTH_EAST);
}

void EQ_SetPlayerSpawnHeadingEast()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_EAST);
}

void EQ_SetPlayerSpawnHeadingNorthEast()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnHeading(playerSpawn, EQ_HEADING_NORTH_EAST);
}

void EQ_TurnLeft()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerHeading = EQ_GetSpawnHeading(playerSpawn);

        playerHeading = EQ_RoundHeading(playerHeading);

        playerHeading = playerHeading + EQ_HEADING_MAX_QUARTER;

        playerHeading = EQ_FixHeading(playerHeading);

        EQ_SetSpawnHeading(playerSpawn, playerHeading);
    }
}

void EQ_TurnRight()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerHeading = EQ_GetSpawnHeading(playerSpawn);

        playerHeading = EQ_RoundHeading(playerHeading);

        playerHeading = playerHeading - EQ_HEADING_MAX_QUARTER;

        playerHeading = EQ_FixHeading(playerHeading);

        EQ_SetSpawnHeading(playerSpawn, playerHeading);
    }
}

void EQ_TurnAround()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerHeading = EQ_GetSpawnHeading(playerSpawn);

        playerHeading = EQ_RoundHeading(playerHeading);

        playerHeading = playerHeading + EQ_HEADING_MAX_HALF;

        playerHeading = EQ_FixHeading(playerHeading);

        EQ_SetSpawnHeading(playerSpawn, playerHeading);
    }
}

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot

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

#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

void EQ_TurnCameraTowardsLocation(float y, float x)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    auto cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
    auto cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);

    float heading = EQ_GetBearing(cameraY, cameraX, y, x);

    EQ_SetSpawnHeading(playerSpawn, heading);
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

void EQ_LookCameraAtLocation(float y, float x, float z)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    auto cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
    auto cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
    auto cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

    float opposite = EQ_CalculateDistance(cameraY, cameraX, y, x);

    //std::cout << "opposite: " << opposite << std::endl;

    float adjacent = std::fabsf(cameraZ - z);

    //std::cout << "adjacent: " << adjacent << std::endl;

    float hypotenuse = std::sqrtf(std::pow(opposite, 2) + std::pow(adjacent, 2));

    //std::cout << "hypotenuse: " << hypotenuse << std::endl;

    float angleRadians = std::acosf(adjacent / hypotenuse); // SOHCAHTOA

    //std::cout << "angle radians: " << angleRadians << std::endl;

    float angleDegrees = EQ_GetDegrees(angleRadians);

    //std::cout << "angle degrees: " << angleDegrees << std::endl;

    EQ_TurnCameraTowardsLocation(y, x);

    if (z > cameraZ)
    {
        EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MAX - angleDegrees);
    }
    else if (z < cameraZ)
    {
        EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MIN + angleDegrees);
    }
}

void EQ_LookCameraAtSpawn(uint32_t spawn)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    EQ_LookCameraAtLocation(spawnY, spawnX, spawnZ);
}


void EQ_LookCameraAtTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    EQ_LookCameraAtSpawn(targetSpawn);
}

void EQ_LookPlayerAtLocation(float y, float x, float z)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_TurnSpawnTowardsLocation(playerSpawn, y, x);

    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    auto cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
    auto cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
    auto cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

    float opposite = EQ_CalculateDistance(cameraY, cameraX, y, x);

    //std::cout << "opposite: " << opposite << std::endl;

    float adjacent = std::fabsf(cameraZ - z);

    //std::cout << "adjacent: " << adjacent << std::endl;

    float hypotenuse = std::sqrtf(std::pow(opposite, 2) + std::pow(adjacent, 2));

    //std::cout << "hypotenuse: " << hypotenuse << std::endl;

    float angleRadians = std::acosf(adjacent / hypotenuse); // SOHCAHTOA

    //std::cout << "angle radians: " << angleRadians << std::endl;

    float angleDegrees = EQ_GetDegrees(angleRadians);

    //std::cout << "angle degrees: " << angleDegrees << std::endl;

    if (z < cameraZ)
    {
        EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MIN + angleDegrees);
    }
    else if (z > cameraZ)
    {
        EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MAX - angleDegrees);
    }

}

void EQ_LookPlayerAtSpawn(uint32_t spawn)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);
    auto spawnZ = EQ_GetSpawnZ(spawn);

    EQ_LookPlayerAtLocation(spawnY, spawnX, spawnZ);
}

void EQ_LookPlayerAtTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    EQ_LookPlayerAtSpawn(targetSpawn);
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

void EQ_PrintTextToChatByColor(const char* text, int color)
{
    EQ_CLASS_POINTER_CEverQuest->dsp_chat(text, color, 1, 1, 0);
}

void EQ_DrawText(const char* text, int x, int y)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, EQ_DRAW_TEXT_COLOR_GRAY);
}

void EQ_DrawTextByColor(const char* text, int x, int y, int color)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, color);
}

void EQ_DrawLine(float lineBeginX, float lineBeginY, float lineEndX, float lineEndY, uint32_t colorARGB)
{
    EQ::Vector3f vectorBegin;
    vectorBegin.X = lineBeginX;
    vectorBegin.Y = lineBeginY;
    vectorBegin.Z = 1.0f;

    EQ::Vector3f vectorEnd;
    vectorEnd.X = lineEndX;
    vectorEnd.Y = lineEndY;
    vectorEnd.Z = 1.0f;

    EQ_CLASS_POINTER_CRender->DrawLine(vectorBegin, vectorEnd, colorARGB);
}

void EQ_DrawLine3D(float lineBeginY, float lineBeginX, float lineBeginZ, float lineEndY, float lineEndX, float lineEndZ, uint32_t colorARGB)
{
    float screenBeginX = 0.0f;
    float screenBeginY = 0.0f;
    bool resultBegin = EQ_WorldLocationToScreenLocation(lineBeginY, lineBeginX, lineBeginZ, screenBeginX, screenBeginY);

    float screenEndX = 0.0f;
    float screenEndY = 0.0f;
    bool resultEnd = EQ_WorldLocationToScreenLocation(lineEndY, lineEndX, lineEndZ, screenEndX, screenEndY);

    EQ_DrawLine(screenBeginX, screenBeginY, screenEndX, screenEndY, colorARGB);
}

void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled)
{
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

        EQ_CLASS_POINTER_CRender->DrawColoredRectangle(rectangle, colorARGB);
    }
    else
    {
        EQ::Vector3f vector1;
        EQ::Vector3f vector2;
        EQ::Vector3f vector3;
        EQ::Vector3f vector4;

        // top left
        vector1.X = x;
        vector1.Y = y;
        vector1.Z = 1.0f;

        // top right
        vector2.X = x + width;
        vector2.Y = y;
        vector2.Z = 1.0f;

        // bottom right
        vector3.X = x + width;
        vector3.Y = y + height;
        vector3.Z = 1.0f;

        // bottom left
        vector4.X = x;
        vector4.Y = y + height;
        vector4.Z = 1.0f;

        EQ_CLASS_POINTER_CRender->DrawLine(vector1, vector2, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(vector2, vector3, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(vector3, vector4, colorARGB);
        EQ_CLASS_POINTER_CRender->DrawLine(vector4, vector1, colorARGB);
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

float EQ_GetCameraFarClipPlane()
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return -1.0f;
    }

    return EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_FAR_CLIP_PLANE);
}

void EQ_SetCameraLocation(float y, float x, float z)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Y, y);
    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_X, x);
    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Z, z);
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

void EQ_SetCameraDrawDistance(float distance)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_DRAW_DISTANCE, distance);
}

void EQ_SetCameraFarClipPlane(float distance)
{
    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_FAR_CLIP_PLANE, distance);
}

bool EQ_WorldLocationToScreenLocation(float worldY, float worldX, float worldZ, float& screenX, float& screenY)
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

bool EQ_WorldLocationToScreenLocationEx(float worldY, float worldX, float worldZ, float& screenX, float& screenY)
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

    // location is offscreen
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

// returns <screenX, screenY, result>
std::tuple<float, float, bool> EQ_WorldLocationToScreenLocationAsTuple(float worldY, float worldX, float worldZ)
{
    float screenX = -1.0f;
    float screenY = -1.0f;
    bool result = EQ_WorldLocationToScreenLocation(worldY, worldX, worldZ, screenX, screenY);

    return std::make_tuple(screenX, screenY, result);
}

void EQ_PlaySound(const char* fileName)
{
    std::stringstream filePath;
    filePath << "sounds/" << fileName;

    PlaySoundA(filePath.str().c_str(), NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQ_StopSound()
{
    PlaySoundA(NULL, NULL, NULL);
}

void EQ_TakeScreenshot(const char* fileName)
{
    EQ_CLASS_POINTER_CRender->TakeScreenshot(fileName);
}

void EQ_CenterView()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_DEFAULT);
}

void EQ_LookUp()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MAX);
}

void EQ_LookDown()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_SetSpawnPitch(playerSpawn, EQ_SPAWN_PITCH_MIN);
}

void EQ_StopFollow()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    //EQ_SetSpawnFollowSpawn(playerSpawn, 0);
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

    //EQ_SetSpawnFollowSpawn(playerSpawn, targetSpawn);
}

void EQ_FollowSpawnByID(uint32_t spawnID)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spawn = EQ_GetSpawnByID(spawnID);
    if (spawn == NULL)
    {
        return;
    }

    EQ_SetTargetSpawn(spawn);
    //EQ_SetSpawnFollowSpawn(playerSpawn, spawn);
}

void EQ_FollowSpawnByName(const char* spawnName)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto spawn = EQ_GetSpawnByName(spawnName);
    if (spawn == NULL)
    {
        return;
    }

    EQ_SetTargetSpawn(spawn);
    //EQ_SetSpawnFollowSpawn(playerSpawn, spawn);
}

void EQ_ClearTarget()
{
    EQ_SetTargetSpawn(NULL);
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

uint32_t EQ_StringMap_GetKeyByValue(std::unordered_map<uint32_t, std::string>& stringMap, const std::string& value)
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

    uint32_t button = EQ_ReadMemory<uint32_t>(window + cxwndButtonOffset);
    if (button == NULL)
    {
        return false;
    }

    ((EQClass::CXWnd*)window)->WndNotification(button, EQ_CXWND_MESSAGE_LEFT_CLICK, (void*)0);

    return true;
}
