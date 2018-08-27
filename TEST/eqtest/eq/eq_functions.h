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

EQ_MACRO_FUNCTION_FunctionAtAddress(char* __cdecl EQ_FUNCTION_CrashDetected(), EQ_ADDRESS_FUNCTION_CrashDetected);
typedef char* (__cdecl* EQ_FUNCTION_TYPE_CrashDetected)();

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CollisionCallbackForActors(uint32_t cactor), EQ_ADDRESS_FUNCTION_CollisionCallbackForActors);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CollisionCallbackForActors)(uint32_t cactor);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CastRay(uint32_t spawn, float y, float x, float z), EQ_ADDRESS_FUNCTION_CastRay);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay)(uint32_t spawn, float y, float x, float z);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_CastRay2(const EQClass::CVector3& sourcePosition, int race, float destinationX, float destinationY, float destinationZ), EQ_ADDRESS_FUNCTION_CastRay2);
typedef int (__cdecl* EQ_FUNCTION_TYPE_CastRay2)(const EQClass::CVector3& sourcePosition, int race, float destinationX, float destinationY, float destinationZ);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_ExecuteCmd(uint32_t commandID, int isActive, void* unknown, int zero), EQ_ADDRESS_FUNCTION_ExecuteCmd);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ExecuteCmd)(uint32_t commandID, int isActive, void* unknown, int zero);

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQ_FUNCTION_DoSpellEffect(int type, int unknown, uint32_t spell, uint32_t spawn1, uint32_t spawn2, EQ::Location_ptr location, uint32_t missile, uint32_t duration), EQ_ADDRESS_FUNCTION_DoSpellEffect);
typedef int (__cdecl* EQ_FUNCTION_TYPE_DoSpellEffect)(int type, int unknown, uint32_t spell, uint32_t spawn1, uint32_t spawn2, EQ::Location_ptr location, uint32_t missile, uint32_t duration);

EQ_MACRO_FUNCTION_FunctionAtAddress(LRESULT __stdcall EQ_FUNCTION_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam), EQ_ADDRESS_FUNCTION_WindowProc);
typedef LRESULT (__stdcall* EQ_FUNCTION_TYPE_WindowProc)(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQ_FUNCTION_ProcessMouseEvent(), EQ_ADDRESS_FUNCTION_ProcessMouseEvent);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ProcessMouseEvent)();

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQ_FUNCTION_ProcessKeyboardEvent(), EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent);
typedef int (__cdecl* EQ_FUNCTION_TYPE_ProcessKeyboardEvent)();

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQ_FUNCTION_FlushDxMouse(), EQ_ADDRESS_FUNCTION_FlushDxMouse);
typedef int (__cdecl* EQ_FUNCTION_TYPE_FlushDxMouse)();

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQ_FUNCTION_FlushDxKeyboard(), EQ_ADDRESS_FUNCTION_FlushDxKeyboard);
typedef int (__cdecl* EQ_FUNCTION_TYPE_FlushDxKeyboard)();

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
bool EQ_IsSpellIDMemorized(uint32_t spellID);
bool EQ_IsSpellNameMemorized(const char* spellName);
bool EQ_IsSpellGemIndexReadyToCast(uint32_t spellGemIndex);
bool EQ_IsSpellIDReadyToCast(uint32_t spellID);
bool EQ_IsSpellNameReadyToCast(const char* spellName);
bool EQ_HasTimeElapsed(uint32_t& timer, uint32_t& timerInterval);
bool EQ_IsZoneIDSafe(uint32_t zoneID);
HWND EQ_GetWindow();
uint32_t EQ_GetTimer();
uint32_t EQ_GetCamera();
uint32_t EQ_GetRender();

POINT EQ_GetMousePosition();
std::tuple<int, int> EQ_GetMousePositionAsTuple();
int EQ_GetMouseX();
int EQ_GetMouseY();
void EQ_MouseLeftClickWorld(int x, int y);
void EQ_MouseRightClickWorld(int x, int y);

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

uint32_t EQ_GetZoneID();
std::string EQ_GetZoneLongName();
std::string EQ_GetZoneShortName();
float EQ_GetZoneGravity();
void EQ_SetZoneGravity(float gravity);

bool EQ_IsFogEnabled();
void EQ_SetFog(bool b);
float EQ_GetFogDistanceBegin();
float EQ_GetFogDistanceEnd();
void EQ_SetFogDistanceBegin(float distance);
void EQ_SetFogDistanceEnd(float distance);

uint32_t EQ_GetAuraManager();
uint32_t EQ_GetNumAurasActive();
bool EQ_IsAuraNameActive(const char* name);
void EQ_PrintAuraNames();

uint32_t EQ_GetSpellManager();
uint32_t EQ_GetSpellByID(uint32_t spellID);
uint32_t EQ_GetSpellIDByName(const char* spellName);
std::string EQ_GetSpellNameByID(uint32_t spellID);

uint32_t EQ_GetPlayerCharacter();
uint32_t EQ_GetXTargetManager();
uint32_t EQ_GetXTargetType(uint32_t index);
uint32_t EQ_GetXTargetStatus(uint32_t index);
uint32_t EQ_GetXTargetSpawn(uint32_t index);
std::string EQ_GetXTargetName(uint32_t index);
uint32_t EQ_GetGroup();
uint32_t EQ_GetCI2();
uint32_t EQ_GetCharInfo2();
uint32_t EQ_GetMemorizedSpellID(uint32_t spellGemIndex);
uint32_t EQ_GetSpellGemIndexBySpellID(uint32_t spellID);
uint32_t EQ_GetSpellGemIndexBySpellName(const char* spellName);

bool EQ_CastSpellByGemIndex(uint32_t spellGemIndex);
bool EQ_CastSpellByName(const char* spellName);
bool EQ_CastSpellByID(uint32_t spellID);

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

uint32_t EQ_GetGroupCount();
std::vector<uint32_t> EQ_GetGroupMemberSpawnList();
uint32_t EQ_GetGroupMemberSpawn(uint32_t index);
uint32_t EQ_GetGroupLeaderSpawn();

bool EQ_IsSpawnBuyer(uint32_t spawn);
bool EQ_IsSpawnTrader(uint32_t spawn);
bool EQ_IsSpawnMercenary(uint32_t spawn);
bool EQ_IsSpawnPet(uint32_t spawn);
bool EQ_IsSpawnMount(uint32_t spawn);
bool EQ_IsSpawnAura(uint32_t spawn);
bool EQ_IsSpawnGroupMember(uint32_t spawn);
bool EQ_IsSpawnGroupLeader(uint32_t spawn);

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

bool EQ_IsSpawnFlying(uint32_t spawn);
bool EQ_IsSpawnLevitating(uint32_t spawn);

bool EQ_IsSpawnMoving(uint32_t spawn);
bool EQ_IsPlayerMoving();
bool EQ_IsTargetMoving();

bool EQ_IsSpawnBehindSpawn(uint32_t spawn1, uint32_t spawn2);
bool EQ_IsSpawnBehindSpawnEx(uint32_t spawn1, uint32_t spawn2, float angle);
bool EQ_IsPlayerBehindTarget();
bool EQ_IsTargetBehindPlayer();

bool EQ_IsSpawnClassTank(uint32_t spawn);
bool EQ_IsSpawnClassPriest(uint32_t spawn);
bool EQ_IsSpawnClassCaster(uint32_t spawn);
bool EQ_IsSpawnClassMelee(uint32_t spawn);
bool EQ_IsSpawnClassHybrid(uint32_t spawn);

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
uint32_t EQ_GetSpawnActorClient(uint32_t spawn);
uint32_t EQ_GetSpawnRace(uint32_t spawn);
uint32_t EQ_GetSpawnClass(uint32_t spawn);
uint32_t EQ_GetSpawnGender(uint32_t spawn);
uint32_t EQ_GetSpawnStandingState(uint32_t spawn);
int64_t EQ_GetSpawnHPCurrent(uint32_t spawn);
int64_t EQ_GetSpawnHPMax(uint32_t spawn);
uint32_t EQ_GetSpawnHPPercent(uint32_t spawn);
int32_t EQ_GetSpawnManaCurrent(uint32_t spawn);
int32_t EQ_GetSpawnManaMax(uint32_t spawn);
uint32_t EQ_GetSpawnManaPercent(uint32_t spawn);
uint32_t EQ_GetSpawnEnduranceCurrent(uint32_t spawn);
uint32_t EQ_GetSpawnEnduranceMax(uint32_t spawn);
uint32_t EQ_GetSpawnEndurancePercent(uint32_t spawn);
uint32_t EQ_GetSpawnFollowSpawn(uint32_t spawn);
uint32_t EQ_GetSpawnGravityType(uint32_t spawn);
uint32_t EQ_GetSpawnDirection(uint32_t spawn);
uint32_t EQ_GetSpawnPetSpawnID(uint32_t spawn);

void EQ_SetSpawnNameColor(uint32_t spawn, uint32_t colorARGB);

void EQ_SetSpawnAreaFriction(uint32_t spawn, float friction);
void EQ_SetSpawnAccelerationFriction(uint32_t spawn, float friction);
void EQ_SetSpawnHeading(uint32_t spawn, float heading);
void EQ_SetSpawnPitch(uint32_t spawn, float pitch);
void EQ_SetSpawnHeight(uint32_t spawn, float height);
void EQ_SetSpawnFollowSpawn(uint32_t spawn, uint32_t followSpawn);
void EQ_SetSpawnGravityType(uint32_t spawn, uint32_t gravityType);

void EQ_SetPlayerSpawnHeadingNorth();
void EQ_SetPlayerSpawnHeadingNorthWest();
void EQ_SetPlayerSpawnHeadingWest();
void EQ_SetPlayerSpawnHeadingSouthWest();
void EQ_SetPlayerSpawnHeadingSouth();
void EQ_SetPlayerSpawnHeadingSouthEast();
void EQ_SetPlayerSpawnHeadingEast();
void EQ_SetPlayerSpawnHeadingNorthEast();

bool EQ_SetSpawnItemSlot(uint32_t spawn, uint32_t updateItemSlot, const char* itemDefinition);
bool EQ_SetSpawnItemSlotPrimary(uint32_t spawn, const char* itemDefinition);
bool EQ_SetSpawnItemSlotSecondary(uint32_t spawn, const char* itemDefinition);
bool EQ_SetSpawnItemSlotHead(uint32_t spawn, const char* itemDefinition);

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
void EQ_LookCameraAtTarget();
void EQ_LookPlayerAtLocation(float y, float x, float z);
void EQ_LookPlayerAtTarget();

void EQ_InterpretCommand(const char* text);
void EQ_ExecuteCommand(uint32_t commandID, int isActive);

void EQ_PrintTextToChat(const char* text);
void EQ_PrintTextToChatByColor(const char* text, int color);

void EQ_SetDrawTextFontStyle(uint32_t fontStyle);
void EQ_DrawText(const char* text, int x, int y);
void EQ_DrawTextByColor(const char* text, int x, int y, int color);
void EQ_DrawTextByStyle(const char* text, int x, int y, int color, uint32_t fontStyle);

void EQ_DrawLine(float lineBeginX, float lineBeginY, float lineEndX, float lineEndY, uint32_t colorARGB);
void EQ_DrawLine3D(float lineBeginY, float lineBeginX, float lineBeginZ, float lineEndY, float lineEndX, float lineEndZ, uint32_t colorARGB);
void EQ_DrawRectangle(float x, float y, float width, float height, uint32_t colorARGB, bool isFilled);

uint32_t EQ_GetCameraType();
float EQ_GetCameraPitch();
float EQ_GetCameraFieldOfView();
float EQ_GetCameraDrawDistance();

void EQ_SetCameraType(uint32_t cameraType);
void EQ_SetCameraLocation(float y, float x, float z);
void EQ_SetCameraPitch(float pitch);
void EQ_SetCameraFieldOfView(float fieldOfView);
void EQ_SetCameraDrawDistance(float distance);

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
void EQ_TargetPet();

std::string EQ_StringMap_GetValueByKey(std::unordered_map<uint32_t, std::string>& stringMap, uint32_t key);
uint32_t EQ_StringMap_GetKeyByValue(std::unordered_map<uint32_t, std::string>& stringMap, const std::string& value);

std::string EQ_GetSpawnTypeAsString(uint32_t spawnType);
std::string EQ_GetStandingStateAsString(uint32_t standingState);
std::string EQ_GetDirectionAsString(uint32_t direction);
std::string EQ_GetZoneNameByID(uint32_t zoneID);
std::string EQ_GetZoneShortNameByID(uint32_t zoneID);
std::string EQ_GetRaceNameByID(uint32_t race);
std::string EQ_GetRaceShortNameByID(uint32_t race);
std::string EQ_GetClassNameByID(uint32_t class_);
std::string EQ_GetClassShortNameByID(uint32_t class_);

void EQ_UseAlternateAbility(uint32_t alternateAbilityID);
void EQ_UseDiscipline(const char* disciplineName);
void EQ_UseAbility(uint32_t abilityNumber);
void EQ_UseItem(const char* itemName);

void EQ_UseDoor(const char* doorName);
void EQ_UseDoorByDistance(float distance);
void EQ_UseDoorOnCollision();
void EQ_SetStateForAllDoors(uint8_t state);
void EQ_OpenAllDoors();
void EQ_CloseAllDoors();

void EQ_CXStr_Set(EQ::CXStr** cxstr, const char* text);
void EQ_CXStr_Append(EQ::CXStr** cxstr, const char* text);

bool EQ_CXWnd_BringToTop(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_IsActive(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_IsOpen(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_Open(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_Close(uint32_t cxwndAddressPointer);
bool EQ_CXWnd_ClickButton(uint32_t cxwndAddressPointer, uint32_t cxwndButtonOffset);

bool EQ_BazaarWindow_IsOpen();
bool EQ_BazaarWindow_ClickBeginTraderButton();
bool EQ_BazaarWindow_ClickEndTraderButton();

bool EQ_BazaarConfirmationWindow_IsOpen();
bool EQ_BazaarConfirmationWindow_ClickToParcelsButton();
bool EQ_BazaarConfirmationWindow_ClickCancelButton();

uint32_t EQ_GetBazaarSearchWindow();
bool EQ_BazaarSearchWindow_IsOpen();
void EQ_BazaarSearchWindow_DoQuery();
uint32_t EQ_BazaarSearchWindow_GetListCount();
uint32_t EQ_BazaarSearchWindow_GetListIndexByItemName(const char* itemName, bool useExactComparsion);
bool EQ_BazaarSearchWindow_BuyItem(uint32_t listIndex);
uint32_t EQ_BazaarSearchWindow_GetListIndex();
uint32_t EQ_BazaarSearchWindow_GetItemID(uint32_t listIndex);
uint32_t EQ_BazaarSearchWindow_GetItemQuantity(uint32_t listIndex);
uint32_t EQ_BazaarSearchWindow_GetItemPrice(uint32_t listIndex);
std::string EQ_BazaarSearchWindow_GetItemName(uint32_t listIndex);
std::string EQ_BazaarSearchWindow_GetTraderName(uint32_t listIndex);
bool EQ_BazaarSearchWindow_ClickFindItemsButton();
bool EQ_BazaarSearchWindow_ClickUpdateTradersButton();
bool EQ_BazaarSearchWindow_ClickResetButton();

bool EQ_TaskSelectWindow_IsOpen();
bool EQ_TaskSelectWindow_ClickAcceptButton();
bool EQ_TaskSelectWindow_ClickDeclineButton();

bool EQ_LargeDialogWindow_IsOpen();
bool EQ_LargeDialogWindow_ClickOKButton();
bool EQ_LargeDialogWindow_ClickYesButton();
bool EQ_LargeDialogWindow_ClickNoButton();
void EQ_LargeDialogWindow_Open(const char* titleText, const char* bodyText);
void EQ_LargeDialogWindow_OpenWithTimer(const char* titleText, const char* bodyText, unsigned long closeTimer);

bool EQ_ConfirmationDialog_IsOpen();
bool EQ_ConfirmationDialog_ClickYesButton();
bool EQ_ConfirmationDialog_ClickNoButton();
bool EQ_ConfirmationDialog_ClickCancelButton();
bool EQ_ConfirmationDialog_ClickOKButton();

uint32_t EQ_GetPlayerWindow();
bool EQ_PlayerWindow_IsOpen();
uint32_t EQ_PlayerWindow_GetCombatState();

uint32_t EQ_GetTargetWindow();
bool EQ_TargetWindow_IsOpen();
bool EQ_TargetWindow_FindBuffSpellID(uint32_t spellID);
bool EQ_TargetWindow_FindBuffSpellName(const char* spellName);

uint32_t EQ_GetPetInfoWindow();
bool EQ_PetInfoWindow_IsOpen();
uint32_t EQ_PetInfoWindow_GetSpawnID();
bool EQ_PetInfoWindow_FindBuffSpellID(uint32_t spellID);
bool EQ_PetInfoWindow_FindBuffSpellName(const char* spellName);

uint32_t EQ_GetLongBuffWindow();
bool EQ_LongBuffWindow_IsOpen();
uint32_t EQ_GetShortBuffWindow();
bool EQ_ShortBuffWindow_IsOpen();
bool EQ_BuffWindows_FindBuffSpellID(uint32_t spellID);
bool EQ_BuffWindows_FindBuffSpellName(const char* spellName);
bool EQ_BuffWindows_RemoveBuffSpellID(uint32_t spellID);
bool EQ_BuffWindows_RemoveBuffSpellName(const char* spellName);

uint32_t EQ_GetCastSpellWindow();
bool EQ_CastSpellWindow_IsOpen();
uint32_t EQ_CastSpellWindow_GetSpellGemStateByIndex(uint32_t index);
uint32_t EQ_CastSpellWindow_GetSpellGemStateBySpellID(uint32_t spellID);
uint32_t EQ_CastSpellWindow_GetSpellGemStateBySpellName(const char* spellName);

uint32_t EQ_GetCastingWindow();
bool EQ_CastingWindow_IsOpen();

uint32_t EQ_GetMapWindow();
bool EQ_MapWindow_IsOpen();
uint32_t EQ_MapWindow_GetLines();
uint32_t EQ_MapWindow_GetLabels();

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

bool EQ_IsSpellIDMemorized(uint32_t spellID)
{
    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);

    return (spellGemIndex != EQ_SPELL_GEM_INDEX_NULL);
}

bool EQ_IsSpellNameMemorized(const char* spellName)
{
    auto spellID = EQ_GetSpellIDByName(spellName);
    if (spellID == EQ_SPELL_ID_NULL)
    {
        return false;
    }

    return EQ_IsSpellIDMemorized(spellID);
}

bool EQ_IsSpellGemIndexReadyToCast(uint32_t spellGemIndex)
{
    auto spellGemState = EQ_CastSpellWindow_GetSpellGemStateByIndex(spellGemIndex);
    if (spellGemState == EQ_SPELL_GEM_STATE_NULL)
    {
        return false;
    }

    return (spellGemState == EQ_SPELL_GEM_STATE_READY_TO_CAST);
}

bool EQ_IsSpellIDReadyToCast(uint32_t spellID)
{
    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);
    if (spellGemIndex == EQ_SPELL_GEM_INDEX_NULL)
    {
        return false;
    }

    return EQ_IsSpellGemIndexReadyToCast(spellGemIndex);
}

bool EQ_IsSpellNameReadyToCast(const char* spellName)
{
    auto spellGemState = EQ_CastSpellWindow_GetSpellGemStateBySpellName(spellName);
    if (spellGemState == EQ_SPELL_GEM_STATE_NULL)
    {
        return false;
    }

    return (spellGemState == EQ_SPELL_GEM_STATE_READY_TO_CAST);
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

void EQ_MouseLeftClickWorld(int x, int y)
{
    auto time = EQ_GetTimer() - 100;

    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_LeftMouseHeldTime, time);

    EQ_CLASS_POINTER_CEverQuest->LMouseUp(x, y);
}

void EQ_MouseRightClickWorld(int x, int y)
{
    EQ_CLASS_POINTER_CEverQuest->RMouseUp(x, y);
}

bool EQ_IsNetStatusEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_NetStatus);
}

bool EQ_IsAutoAttackEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AutoAttack);
}

bool EQ_IsAutoFireEnabled()
{
    return EQ_ReadMemory<uint8_t>(EQ_ADDRESS_AutoFire);
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

void EQ_SetAutoFire(bool b)
{
    uint8_t value = (uint8_t)b;

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_AutoFire, value);
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

uint32_t EQ_GetZoneID()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_EQZoneInfo + EQ_OFFSET_EQZoneInfo_ZONE_ID);
}

std::string EQ_GetZoneLongName()
{
    char zoneLongName[EQ_SIZE_EQZoneInfo_ZONE_LONG_NAME];
    std::memmove(zoneLongName, (LPVOID)(EQ_ADDRESS_EQZoneInfo + EQ_OFFSET_EQZoneInfo_ZONE_LONG_NAME), sizeof(zoneLongName));

    return zoneLongName;
}

std::string EQ_GetZoneShortName()
{
    char zoneShortName[EQ_SIZE_EQZoneInfo_ZONE_SHORT_NAME];
    std::memmove(zoneShortName, (LPVOID)(EQ_ADDRESS_EQZoneInfo + EQ_OFFSET_EQZoneInfo_ZONE_SHORT_NAME), sizeof(zoneShortName));

    return zoneShortName;
}

float EQ_GetZoneGravity()
{
    return EQ_ReadMemory<float>(EQ_ADDRESS_EQZoneInfo + EQ_OFFSET_EQZoneInfo_ZONE_GRAVITY);
}

void EQ_SetZoneGravity(float gravity)
{
    EQ_WriteMemory<float>(EQ_ADDRESS_EQZoneInfo + EQ_OFFSET_EQZoneInfo_ZONE_GRAVITY, gravity);
}

bool EQ_IsFogEnabled()
{
    auto value = EQ_ReadMemory<uint8_t>(EQ_ADDRESS_FogEnabled);

    return value == EQ_FOG_ON;
}

void EQ_SetFog(bool b)
{
    uint8_t value = EQ_FOG_OFF;

    if (b == true)
    {
        value = EQ_FOG_ON;
    }

    EQ_WriteMemory<uint8_t>(EQ_ADDRESS_FogEnabled, value);
}

float EQ_GetFogDistanceBegin()
{
    return EQ_ReadMemory<float>(EQ_ADDRESS_FogDistanceBegin);
}

float EQ_GetFogDistanceEnd()
{
    return EQ_ReadMemory<float>(EQ_ADDRESS_FogDistanceEnd);
}

void EQ_SetFogDistanceBegin(float distance)
{
    EQ_WriteMemory<float>(EQ_ADDRESS_FogDistanceBegin, distance);
}

void EQ_SetFogDistanceEnd(float distance)
{
    EQ_WriteMemory<float>(EQ_ADDRESS_FogDistanceEnd, distance);
}

uint32_t EQ_GetAuraManager()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_AuraManager);
}

uint32_t EQ_GetNumAurasActive()
{
    auto auraManager = EQ_GetAuraManager();
    if (auraManager == NULL)
    {
        return 0;
    }

    return EQ_ReadMemory<uint32_t>(auraManager + EQ_OFFSET_AuraManager_NUM_AURAS);
}

bool EQ_IsAuraNameActive(const char* name)
{
    auto auraManager = EQ_GetAuraManager();
    if (auraManager == NULL)
    {
        return false;
    }

    auto numAurasActive = EQ_GetNumAurasActive();
    if (numAurasActive == 0)
    {
        return false;
    }

    auto auras = EQ_ReadMemory<uint32_t>(auraManager + EQ_OFFSET_AuraManager_AURAS);
    if (auras == NULL)
    {
        return false;
    }

    auto aura = EQ_ReadMemory<uint32_t>(auras + EQ_OFFSET_AURAS_Aura);
    if (aura == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < numAurasActive; i++)
    {
        auto auraOffset = i * sizeof(EQData::_AURAINFO);

        char auraName[EQ_SIZE_AURA_NAME];
        std::memmove(auraName, (LPVOID)(aura + auraOffset + EQ_OFFSET_AURA_NAME), sizeof(auraName));

        if (strcmp(auraName, name) == 0)
        {
            return true;
        }
    }

    return false;
}

void EQ_PrintAuraNames()
{
    auto auraManager = EQ_GetAuraManager();
    if (auraManager == NULL)
    {
        return;
    }

    auto numAurasActive = EQ_GetNumAurasActive();
    if (numAurasActive == 0)
    {
        return;
    }

    auto auras = EQ_ReadMemory<uint32_t>(auraManager + EQ_OFFSET_AuraManager_AURAS);
    if (auras == NULL)
    {
        return;
    }

    auto aura = EQ_ReadMemory<uint32_t>(auras + EQ_OFFSET_AURAS_Aura);
    if (aura == NULL)
    {
        return;
    }

    std::cout << "Aura Names: " << std::endl;

    for (unsigned int i = 0; i < numAurasActive; i++)
    {
        auto auraOffset = i * sizeof(EQData::_AURAINFO);

        char auraName[EQ_SIZE_AURA_NAME];
        std::memmove(auraName, (LPVOID)(aura + auraOffset + EQ_OFFSET_AURA_NAME), sizeof(auraName));

        std::cout << auraName << std::endl;
    }
}

uint32_t EQ_GetSpellManager()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_SpellManager);
}

uint32_t EQ_GetSpellByID(uint32_t spellID)
{
    auto spellManager = EQ_GetSpellManager();
    if (spellManager == NULL)
    {
        return EQ_SPELL_ID_NULL;
    }

    for (unsigned int i = 0; i < EQ_NUM_SPELLS; i++)
    {
        auto spell = EQ_ReadMemory<uint32_t>(spellManager + EQ_OFFSET_SpellManager_SPELLS + (i * 0x04));
        if (spell == NULL)
        {
            continue;
        }

        auto spellManagerSpellID = EQ_ReadMemory<uint32_t>(spell + EQ_OFFSET_SPELL_ID);
        if (spellID == spellManagerSpellID)
        {
            return spell;
        }
    }

    return EQ_SPELL_ID_NULL;
}

uint32_t EQ_GetSpellIDByName(const char* spellName)
{
    auto spellManager = EQ_GetSpellManager();
    if (spellManager == NULL)
    {
        return EQ_SPELL_ID_NULL;
    }

    for (unsigned int i = 0; i < EQ_NUM_SPELLS; i++)
    {
        auto spell = EQ_ReadMemory<uint32_t>(spellManager + EQ_OFFSET_SpellManager_SPELLS + (i * 0x04));
        if (spell == NULL)
        {
            continue;
        }

        char spellManagerSpellName[EQ_SIZE_SPELL_NAME];
        std::memmove(spellManagerSpellName, (LPVOID)(spell + EQ_OFFSET_SPELL_NAME), sizeof(spellManagerSpellName));

        if (strcmp(spellManagerSpellName, spellName) == 0)
        {
            auto spellManagerSpellID = EQ_ReadMemory<uint32_t>(spell + EQ_OFFSET_SPELL_ID);

            return spellManagerSpellID;
        }
    }

    return EQ_SPELL_ID_NULL;
}

std::string EQ_GetSpellNameByID(uint32_t spellID)
{
    auto spellManager = EQ_GetSpellManager();
    if (spellManager == NULL)
    {
        return std::string();
    }

    for (unsigned int i = 0; i < EQ_NUM_SPELLS; i++)
    {
        auto spell = EQ_ReadMemory<uint32_t>(spellManager + EQ_OFFSET_SpellManager_SPELLS + (i * 0x04));
        if (spell == NULL)
        {
            continue;
        }

        auto spellManagerSpellID = EQ_ReadMemory<uint32_t>(spell + EQ_OFFSET_SPELL_ID);
        if (spellID == spellManagerSpellID)
        {
            char spellManagerSpellName[EQ_SIZE_SPELL_NAME];
            std::memmove(spellManagerSpellName, (LPVOID)(spell + EQ_OFFSET_SPELL_NAME), sizeof(spellManagerSpellName));

            return spellManagerSpellName;
        }
    }

    return std::string();
}

uint32_t EQ_GetPlayerCharacter()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerCharacter);
}

uint32_t EQ_GetXTargetManager()
{
    auto playerCharacter = EQ_GetPlayerCharacter();
    if (playerCharacter == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerCharacter + EQ_OFFSET_CHARACTER_XTargetManager);
}

uint32_t EQ_GetXTargetType(uint32_t index)
{
    if (index > (EQ_NUM_XTARGETS - 1))
    {
        return EQ_XTARGET_TYPE_NULL;
    }

    auto xTargetManager = EQ_GetXTargetManager();
    if (xTargetManager == NULL)
    {
        return EQ_XTARGET_TYPE_NULL;
    }

    auto xTargets = EQ_ReadMemory<uint32_t>(xTargetManager + EQ_OFFSET_XTargetManager_XTARGETS);
    if (xTargets == NULL)
    {
        return EQ_XTARGET_TYPE_NULL;
    }

    auto xTargetType = EQ_ReadMemory<uint32_t>(xTargets + (index * sizeof(_XTARGETSLOT)) + EQ_OFFSET_XTARGET_TYPE);

    return xTargetType;
}

uint32_t EQ_GetXTargetStatus(uint32_t index)
{
    if (index > (EQ_NUM_XTARGETS - 1))
    {
        return EQ_XTARGET_STATUS_NULL;
    }

    auto xTargetManager = EQ_GetXTargetManager();
    if (xTargetManager == NULL)
    {
        return EQ_XTARGET_STATUS_NULL;
    }

    auto xTargets = EQ_ReadMemory<uint32_t>(xTargetManager + EQ_OFFSET_XTargetManager_XTARGETS);
    if (xTargets == NULL)
    {
        return EQ_XTARGET_STATUS_NULL;
    }

    auto xTargetStatus = EQ_ReadMemory<uint32_t>(xTargets + (index * sizeof(_XTARGETSLOT)) + EQ_OFFSET_XTARGET_STATUS);

    return xTargetStatus;
}

uint32_t EQ_GetXTargetSpawn(uint32_t index)
{
    if (index > (EQ_NUM_XTARGETS - 1))
    {
        return NULL;
    }

    auto xTargetManager = EQ_GetXTargetManager();
    if (xTargetManager == NULL)
    {
        return NULL;
    }

    auto xTargets = EQ_ReadMemory<uint32_t>(xTargetManager + EQ_OFFSET_XTargetManager_XTARGETS);
    if (xTargets == NULL)
    {
        return NULL;
    }

    auto xTargetSpawnID = EQ_ReadMemory<uint32_t>(xTargets + (index * sizeof(_XTARGETSLOT)) + EQ_OFFSET_XTARGET_SPAWN_ID);

    auto xTargetSpawn = EQ_GetSpawnByID(xTargetSpawnID);

    return xTargetSpawn;
}

std::string EQ_GetXTargetName(uint32_t index)
{
    if (index > (EQ_NUM_XTARGETS - 1))
    {
        return std::string();
    }

    auto xTargetManager = EQ_GetXTargetManager();
    if (xTargetManager == NULL)
    {
        return std::string();
    }

    auto xTargets = EQ_ReadMemory<uint32_t>(xTargetManager + EQ_OFFSET_XTargetManager_XTARGETS);
    if (xTargets == NULL)
    {
        return std::string();
    }

    char xTargetName[EQ_SIZE_XTARGET_NAME];
    std::memmove(xTargetName, (LPVOID)(xTargets + (index * sizeof(_XTARGETSLOT)) + EQ_OFFSET_XTARGET_NAME), sizeof(xTargetName));

    return xTargetName;
}

uint32_t EQ_GetGroup()
{
    auto playerCharacter = EQ_GetPlayerCharacter();
    if (playerCharacter == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerCharacter + EQ_OFFSET_CHARACTER_GROUP);
}

uint32_t EQ_GetCI2()
{
    auto playerCharacter = EQ_GetPlayerCharacter();
    if (playerCharacter == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerCharacter + EQ_OFFSET_CHARACTER_CI2);
}

uint32_t EQ_GetCharInfo2()
{
    auto CI2 = EQ_GetCI2();
    if (CI2 == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(CI2 + EQ_OFFSET_CI2_CHARINFO2);
}

uint32_t EQ_GetMemorizedSpellID(uint32_t spellGemIndex)
{
    if (spellGemIndex > (EQ_NUM_SPELL_GEMS - 1))
    {
        return EQ_SPELL_ID_NULL;
    }

    auto charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        return EQ_SPELL_ID_NULL;
    }

    return EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHARINFO2_MEMORIZED_SPELLS + (spellGemIndex * 0x04));
}

uint32_t EQ_GetSpellGemIndexBySpellID(uint32_t spellID)
{
    if (spellID != EQ_SPELL_ID_NULL)
    {
        for (unsigned int i = 0; i < EQ_NUM_SPELL_GEMS; i++)
        {
            auto memorizedSpellID = EQ_GetMemorizedSpellID(i);
            if (memorizedSpellID == spellID)
            {
                return i;
            }
        }
    }

    return EQ_SPELL_GEM_INDEX_NULL;
}

uint32_t EQ_GetSpellGemIndexBySpellName(const char* spellName)
{
    auto spellID = EQ_GetSpellIDByName(spellName);
    if (spellID == EQ_SPELL_ID_NULL)
    {
        EQ_SPELL_GEM_INDEX_NULL;
        
    }

    return EQ_GetSpellGemIndexBySpellID(spellID);
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

bool EQ_CastSpellByID(uint32_t spellID)
{
    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);
    if (spellGemIndex == EQ_SPELL_GEM_INDEX_NULL)
    {
        return false;
    }

    return EQ_CastSpellByGemIndex(spellGemIndex);
}

bool EQ_CastSpellByName(const char* spellName)
{
    std::string spellNameStr = spellName;
    std::string spellNameRank2 = spellNameStr + " Rk. II";
    std::string spellNameRank3 = spellNameStr + " Rk. III";

    uint32_t spellGemIndex      = EQ_GetSpellGemIndexBySpellName(spellNameStr.c_str());
    uint32_t spellGemIndexRank2 = EQ_GetSpellGemIndexBySpellName(spellNameRank2.c_str());
    uint32_t spellGemIndexRank3 = EQ_GetSpellGemIndexBySpellName(spellNameRank3.c_str());

    if (spellGemIndexRank3 != EQ_SPELL_GEM_INDEX_NULL)
    {
        return EQ_CastSpellByGemIndex(spellGemIndex);
    }
    else
    {
        if (spellGemIndexRank2 != EQ_SPELL_GEM_INDEX_NULL)
        {
            return EQ_CastSpellByGemIndex(spellGemIndexRank2);
        }
        else
        {
            if (spellGemIndex != EQ_SPELL_GEM_INDEX_NULL)
            {
                return EQ_CastSpellByGemIndex(spellGemIndex);
            }
        }
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

uint32_t EQ_GetGroupCount()
{
    auto group = EQ_GetGroup();
    if (group == NULL)
    {
        return 0;
    }

    uint32_t groupCount = 0;

    for (size_t i = 0; i < EQ_NUM_GROUP_MEMBERS; i++)
    {
        auto groupMember = EQ_ReadMemory<uint32_t>(group + EQ_OFFSET_Group_GROUP_MEMBERS + (i * 0x04));
        if (groupMember == NULL)
        {
            continue;
        }

        auto groupMemberSpawn = EQ_ReadMemory<uint32_t>(groupMember + EQ_OFFSET_GROUP_MEMBER_SPAWN);
        if (groupMemberSpawn == NULL)
        {
            continue;
        }

        groupCount++;
    }

    return groupCount;
}

std::vector<uint32_t> EQ_GetGroupMemberSpawnList()
{
    std::vector<uint32_t> groupMemberSpawnList;

    auto group = EQ_GetGroup();
    if (group == NULL)
    {
        return groupMemberSpawnList;
    }

    for (size_t i = 0; i < EQ_NUM_GROUP_MEMBERS; i++)
    {
        auto groupMember = EQ_ReadMemory<uint32_t>(group + EQ_OFFSET_Group_GROUP_MEMBERS + (i * 0x04));
        if (groupMember == NULL)
        {
            continue;
        }

        auto groupMemberSpawn = EQ_ReadMemory<uint32_t>(groupMember + EQ_OFFSET_GROUP_MEMBER_SPAWN);
        if (groupMemberSpawn == NULL)
        {
            continue;
        }

        groupMemberSpawnList.push_back(groupMemberSpawn);
    }

    return groupMemberSpawnList;
}

uint32_t EQ_GetGroupMemberSpawn(uint32_t index)
{
    if (index > (EQ_NUM_GROUP_MEMBERS - 1))
    {
        return NULL;
    }

    auto group =  EQ_GetGroup();
    if (group == NULL)
    {
        return NULL;
    }

    auto groupMember = EQ_ReadMemory<uint32_t>(group + EQ_OFFSET_Group_GROUP_MEMBERS + (index * 0x04));
    if (groupMember == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(groupMember + EQ_OFFSET_GROUP_MEMBER_SPAWN);
}

uint32_t EQ_GetGroupLeaderSpawn()
{
    auto group = EQ_GetGroup();
    if (group == NULL)
    {
        return NULL;
    }

    auto groupLeader = EQ_ReadMemory<uint32_t>(group + EQ_OFFSET_Group_GROUP_MEMBER_LEADER);
    if (groupLeader == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(groupLeader + EQ_OFFSET_GROUP_MEMBER_SPAWN);
}

bool EQ_IsSpawnBuyer(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_IS_BUYER);
}

bool EQ_IsSpawnTrader(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_IS_TRADER);
}

bool EQ_IsSpawnMercenary(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_IS_MERCENARY);
}

bool EQ_IsSpawnPet(uint32_t spawn)
{
    auto spawnPetOwnerSpawnID = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_PET_OWNER_SPAWN_ID);

    return spawnPetOwnerSpawnID != 0;
}

bool EQ_IsSpawnMount(uint32_t spawn)
{
    auto spawnMountRiderSpawn = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_MOUNT_RIDER_SPAWN);

    return spawnMountRiderSpawn != NULL;
}

bool EQ_IsSpawnAura(uint32_t spawn)
{
    auto spawnRace = EQ_GetSpawnRace(spawn);
    auto spawnClass = EQ_GetSpawnClass(spawn);

    return spawnRace == EQ_RACE_INVISIBLE_MAN && spawnClass == EQ_CLASS_OBJECT;
}

bool EQ_IsSpawnGroupMember(uint32_t spawn)
{
    auto groupMemberSpawnList = EQ_GetGroupMemberSpawnList();
    if (groupMemberSpawnList.size() == 0)
    {
        return false;
    }

    for (auto& groupMemberSpawn : groupMemberSpawnList)
    {
        if (groupMemberSpawn == NULL)
        {
            continue;
        }

        if (groupMemberSpawn == spawn)
        {
            return true;
        }
    }

    return false;
}

bool EQ_IsSpawnGroupLeader(uint32_t spawn)
{
    auto groupLeaderSpawn = EQ_GetGroupLeaderSpawn();
    if (groupLeaderSpawn == NULL)
    {
        return false;
    }

    return (spawn == groupLeaderSpawn);
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
    ////return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_IS_TARGETABLE);

    return ((EQClass::EQPlayer*)spawn)->IsTargetable();
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

bool EQ_IsSpawnFlying(uint32_t spawn)
{
    return EQ_GetSpawnGravityType(spawn) == EQ_GRAVITY_TYPE_FLYING;
}

bool EQ_IsSpawnLevitating(uint32_t spawn)
{
    return EQ_GetSpawnGravityType(spawn) == EQ_GRAVITY_TYPE_LEVITATING;
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

    if (EQ_IsSpawnBehindSpawnEx(playerSpawn, targetSpawn, 64.0f) == true)
    {
        return true;
    }

    return false;
}

bool EQ_IsTargetBehindPlayer()
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

    if (EQ_IsSpawnBehindSpawnEx(targetSpawn, playerSpawn, 64.0f) == true)
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

uint32_t EQ_GetSpawnZoneID(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_ZONE_ID);
}

uint32_t EQ_GetSpawnLevel(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_LEVEL);
}

uint32_t EQ_GetSpawnActorClient(uint32_t spawn)
{
    return spawn + EQ_OFFSET_SPAWN_ACTOR_CLIENT;
}

uint32_t EQ_GetSpawnRace(uint32_t spawn)
{
    ////return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_RACE);

    auto actorClient = EQ_GetSpawnActorClient(spawn);
    if (actorClient == NULL)
    {
        return EQ_RACE_UNKNOWN;
    }

    return ((EQData::ActorClient*)actorClient)->Race;
}

uint32_t EQ_GetSpawnClass(uint32_t spawn)
{
    ////return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_CLASS);

    auto actorClient = EQ_GetSpawnActorClient(spawn);
    if (actorClient == NULL)
    {
        return EQ_CLASS_UNKNOWN;
    }

    return ((EQData::ActorClient*)actorClient)->Class;
}

uint32_t EQ_GetSpawnGender(uint32_t spawn)
{
    ////return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_GENDER);

    auto actorClient = EQ_GetSpawnActorClient(spawn);
    if (actorClient == NULL)
    {
        return EQ_GENDER_UNKNOWN;
    }

    return ((EQData::ActorClient*)actorClient)->Gender;
}

uint32_t EQ_GetSpawnStandingState(uint32_t spawn)
{
    return EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_STANDING_STATE);
}

int64_t EQ_GetSpawnHPCurrent(uint32_t spawn)
{
    return EQ_ReadMemory<int64_t>(spawn + EQ_OFFSET_SPAWN_HP_CURRENT);
}

int64_t EQ_GetSpawnHPMax(uint32_t spawn)
{
    return EQ_ReadMemory<int64_t>(spawn + EQ_OFFSET_SPAWN_HP_MAX);
}

uint32_t EQ_GetSpawnHPPercent(uint32_t spawn)
{
    auto current = EQ_GetSpawnHPCurrent(spawn);
    auto max     = EQ_GetSpawnHPMax(spawn);

    auto multiplied = current * 100;

    // prevent divide by zero
    if (multiplied == 0 || max == 0)
    {
        return 0;
    }

    return (uint32_t)(multiplied / max);
}

int32_t EQ_GetSpawnManaCurrent(uint32_t spawn)
{
    return EQ_ReadMemory<int32_t>(spawn + EQ_OFFSET_SPAWN_MANA_CURRENT);
}

int32_t EQ_GetSpawnManaMax(uint32_t spawn)
{
    return EQ_ReadMemory<int32_t>(spawn + EQ_OFFSET_SPAWN_MANA_MAX);
}

uint32_t EQ_GetSpawnManaPercent(uint32_t spawn)
{
    auto current = EQ_GetSpawnManaCurrent(spawn);
    auto max     = EQ_GetSpawnManaMax(spawn);

    auto multiplied = current * 100;

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

    auto multiplied = current * 100;

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

uint32_t EQ_GetSpawnGravityType(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_GRAVITY_TYPE);
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

uint32_t EQ_GetSpawnPetSpawnID(uint32_t spawn)
{
    return EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_PET_SPAWN_ID);
}

void EQ_SetSpawnNameColor(uint32_t spawn, uint32_t colorARGB)
{
    if (spawn == NULL)
    {
        return;
    }

    auto spawnActorClient = EQ_GetSpawnActorClient(spawn);
    if (spawnActorClient == NULL)
    {
        return;
    }

    auto spawnCActorEx = ((EQData::ActorClient*)spawnActorClient)->pcactorex;
    if (spawnCActorEx == NULL)
    {
        return;
    }
            
    if (((EQClass::CActorEx*)spawnCActorEx)->CanSetName(0) == false)
    {
        return;
    }

    ((EQClass::CActorEx*)spawnCActorEx)->SetNameColor(colorARGB);
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

void EQ_SetSpawnGravityType(uint32_t spawn, uint32_t gravityType)
{
    EQ_WriteMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_GRAVITY_TYPE, gravityType);
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

    EQ_SetCameraType(EQ_CAMERA_TYPE_FIRST_PERSON);

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

void EQ_LookCameraAtTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    EQ_LookCameraAtLocation(targetY, targetX, targetZ);
}

void EQ_LookPlayerAtLocation(float y, float x, float z)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_TurnSpawnTowardsLocation(playerSpawn, y, x);

    if (EQ_GetCameraType() != EQ_CAMERA_TYPE_FIRST_PERSON)
    {
        EQ_SetCameraType(EQ_CAMERA_TYPE_FIRST_PERSON);
        return;
    }

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

void EQ_LookPlayerAtTarget()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    EQ_LookPlayerAtLocation(targetY, targetX, targetZ);
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

void EQ_SetDrawTextFontStyle(uint32_t fontStyle)
{
    if (fontStyle < EQ_FONT_STYLE_MIN || fontStyle > EQ_FONT_STYLE_MAX)
    {
        return;
    }

    auto windowManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CXWndManager);
    if (windowManager == NULL)
    {
        return;
    }

    auto fontsArray = EQ_ReadMemory<uint32_t>(windowManager + EQ_OFFSET_CXWndManager_FONTS_ARRAY);
    if (fontsArray == NULL)
    {
        return;
    }

    auto fonts = EQ_ReadMemory<uint32_t>(windowManager + (EQ_OFFSET_CXWndManager_FONTS_ARRAY + 0x04)); // have to add offset 0x04 to get actual array from the EQ array class
    if (fonts == NULL)
    {
        return;
    }

    auto font = EQ_ReadMemory<uint32_t>(fonts + (EQ_FONT_INDEX_DEFAULT * 0x04)); // each font pointer (uint32_t) takes up 0x04 bytes in the array
    if (font == NULL)
    {
        return;
    }

    EQ_WriteMemory<uint32_t>(font + EQ_OFFSET_CTextureFont_STYLE, fontStyle);
}

void EQ_DrawText(const char* text, int x, int y)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, EQ_DRAW_TEXT_COLOR_GRAY);
}

void EQ_DrawTextByColor(const char* text, int x, int y, int color)
{
    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, color);
}

void EQ_DrawTextByStyle(const char* text, int x, int y, int color, uint32_t fontStyle)
{
    EQ_SetDrawTextFontStyle(fontStyle);

    EQ_CLASS_POINTER_CDisplay->WriteTextHD2(text, x, y, color);

    EQ_SetDrawTextFontStyle(EQ_FONT_STYLE_DEFAULT);
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

uint32_t EQ_GetCameraType()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_CameraType);
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

void EQ_SetCameraType(uint32_t cameraType)
{
    EQ_WriteMemory<uint32_t>(EQ_ADDRESS_CameraType, cameraType);
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
    EQ_SetSpawnFollowSpawn(playerSpawn, spawn);
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
    EQ_SetSpawnFollowSpawn(playerSpawn, spawn);
}

void EQ_ClearTarget()
{
    EQ_SetTargetSpawn(NULL);
}

void EQ_TargetPet()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto petSpawnID = EQ_GetSpawnPetSpawnID(playerSpawn);

    EQ_SetTargetSpawnByID(petSpawnID);
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

std::string EQ_GetSpawnTypeAsString(uint32_t spawnType)
{
    return EQ_StringMap_GetValueByKey(EQ_SPAWN_TYPE_Strings, spawnType);
}

std::string EQ_GetStandingStateAsString(uint32_t standingState)
{
    return EQ_StringMap_GetValueByKey(EQ_STANDING_STATE_Strings, standingState);
}

std::string EQ_GetDirectionAsString(uint32_t direction)
{
    return EQ_StringMap_GetValueByKey(EQ_DIRECTION_Strings, direction);
}

std::string EQ_GetZoneNameByID(uint32_t zoneID)
{
    return EQ_StringMap_GetValueByKey(EQ_ZONE_ID_LongName_Strings, zoneID);
}

std::string EQ_GetZoneShortNameByID(uint32_t zoneID)
{
    return EQ_StringMap_GetValueByKey(EQ_ZONE_ID_ShortName_Strings, zoneID);
}

std::string EQ_GetRaceNameByID(uint32_t race)
{
    return EQ_StringMap_GetValueByKey(EQ_RACE_LongName_Strings, race);
}

std::string EQ_GetRaceShortNameByID(uint32_t race)
{
    return EQ_StringMap_GetValueByKey(EQ_RACE_ShortName_Strings, race);
}

std::string EQ_GetClassNameByID(uint32_t class_)
{
    return EQ_StringMap_GetValueByKey(EQ_CLASS_LongName_Strings, class_);
}

std::string EQ_GetClassShortNameByID(uint32_t class_)
{
    return EQ_StringMap_GetValueByKey(EQ_CLASS_ShortName_Strings, class_);
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

void EQ_UseDoor(const char* doorName)
{
    auto switchManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQSwitchManager);
    if (switchManager == NULL)
    {
        return;
    }

    auto numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_EQSwitchManager_NUM_SWITCHES);
    if (numDoors == 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    for (unsigned int i = 0; i < numDoors; i++)
    {
        auto door = EQ_ReadMemory<uint32_t>(switchManager + (EQ_OFFSET_EQSwitchManager_FIRST_SWITCH + (i * 0x04)));
        if (door == NULL)
        {
            continue;
        }

        auto doorY = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Y);
        auto doorX = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_X);
        auto doorZ = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Z);

        float doorDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, doorY, doorX);
        if (doorDistance > EQ_USE_DOOR_DISTANCE_DEFAULT)
        {
            continue;
        }

        char doorName_[EQ_SIZE_EQSwitch_NAME];
        std::memmove(doorName_, (LPVOID)(door + EQ_OFFSET_EQSwitch_NAME), sizeof(doorName_));

        if (strcmp(doorName, doorName_) != 0)
        {
            continue;
        }

        auto playerSpawnID = EQ_GetSpawnID(playerSpawn);

        ((EQClass::EQSwitch*)door)->UseSwitch(playerSpawnID, 0, 0, 0);
    }
}

void EQ_UseDoorByDistance(float distance)
{
    auto switchManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQSwitchManager);
    if (switchManager == NULL)
    {
        return;
    }

    auto numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_EQSwitchManager_NUM_SWITCHES);
    if (numDoors == 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    for (unsigned int i = 0; i < numDoors; i++)
    {
        auto door = EQ_ReadMemory<uint32_t>(switchManager + (EQ_OFFSET_EQSwitchManager_FIRST_SWITCH + (i * 0x04)));
        if (door == NULL)
        {
            continue;
        }

        auto doorY = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Y);
        auto doorX = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_X);
        auto doorZ = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Z);

        float doorDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, doorY, doorX);
        if (doorDistance > distance)
        {
            continue;
        }

        auto playerSpawnID = EQ_GetSpawnID(playerSpawn);

        ((EQClass::EQSwitch*)door)->UseSwitch(playerSpawnID, 0, 0, 0);
    }
}

void EQ_UseDoorOnCollision()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnCollideWithActorType = EQ_GetSpawnCollideWithActorType(playerSpawn);
    if (playerSpawnCollideWithActorType != EQ_ACTOR_TYPE_SWITCH)
    {
        return;
    }

    auto switchManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQSwitchManager);
    if (switchManager == NULL)
    {
        return;
    }

    auto numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_EQSwitchManager_NUM_SWITCHES);
    if (numDoors == 0)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    for (unsigned int i = 0; i < numDoors; i++)
    {
        auto door = EQ_ReadMemory<uint32_t>(switchManager + (EQ_OFFSET_EQSwitchManager_FIRST_SWITCH + (i * 0x04)));
        if (door == NULL)
        {
            continue;
        }

        auto doorState = EQ_ReadMemory<uint8_t>(door + EQ_OFFSET_EQSwitch_STATE);
        if (doorState != EQ_SWITCH_STATE_CLOSED)
        {
            continue;
        }

        auto doorY = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Y);
        auto doorX = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_X);
        auto doorZ = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Z);

        float doorDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, doorY, doorX);
        if (doorDistance > EQ_USE_DOOR_DISTANCE_DEFAULT)
        {
            continue;
        }

        //auto doorBearing = EQ_GetBearing(playerSpawnY, playerSpawnX, doorY, doorX);
        //std::cout << "door bearing: " << doorBearing << std::endl;

        auto playerSpawnID = EQ_GetSpawnID(playerSpawn);

        ((EQClass::EQSwitch*)door)->UseSwitch(playerSpawnID, 0, 0, 0);
    }
}

void EQ_SetStateForAllDoors(uint8_t state)
{
    auto switchManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQSwitchManager);
    if (switchManager == NULL)
    {
        return;
    }

    auto numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_EQSwitchManager_NUM_SWITCHES);
    if (numDoors == 0)
    {
        return;
    }

    for (unsigned int i = 0; i < numDoors; i++)
    {
        auto door = EQ_ReadMemory<uint32_t>(switchManager + (EQ_OFFSET_EQSwitchManager_FIRST_SWITCH + (i * 0x04)));
        if (door == NULL)
        {
            continue;
        }

        ((EQClass::EQSwitch*)door)->ChangeState(state, 0, 0);
    }
}

void EQ_OpenAllDoors()
{
    EQ_SetStateForAllDoors(EQ_SWITCH_STATE_OPENING);
}

void EQ_CloseAllDoors()
{
    EQ_SetStateForAllDoors(EQ_SWITCH_STATE_CLOSING);
}

void EQ_CXStr_Set(EQ::CXStr** cxstr, const char* text)
{ 
    EQClass::CXStr* temp = (EQClass::CXStr*)cxstr;

    (*temp) = text;

    cxstr = (EQ::CXStr**)temp;
}

void EQ_CXStr_Append(EQ::CXStr** cxstr, const char* text)
{
    EQClass::CXStr* temp = (EQClass::CXStr*)cxstr;

    (*temp) += text;

    cxstr = (EQ::CXStr**)temp;
}

bool EQ_CXWnd_BringToTop(uint32_t cxwndAddressPointer)
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

    bool isOpen = ((EQClass::CXWnd*)window)->IsReallyVisible();
    if (isOpen == false)
    {
        return false;
    }

    ((EQClass::CXWnd*)window)->BringToTop(true);

    return true;
}

bool EQ_CXWnd_IsActive(uint32_t cxwndAddressPointer)
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

    return ((EQClass::CXWnd*)window)->IsActive();
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

    return ((EQClass::CXWnd*)window)->IsReallyVisible();
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

    bool isOpen = ((EQClass::CXWnd*)window)->IsReallyVisible();
    if (isOpen == false)
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

uint32_t EQ_GetBazaarSearchWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
}

bool EQ_BazaarSearchWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBazaarSearchWnd) == true);
}

void EQ_BazaarSearchWindow_DoQuery()
{
    EQ_CLASS_POINTER_CBazaarSearchWnd->doQuery();
}

void EQ_BazaarSearchWindow_PrintList()
{
    if (EQ_BazaarSearchWindow_IsOpen() == false)
    {
        return;
    }

    uint32_t listCount = EQ_BazaarSearchWindow_GetListCount();
    if (listCount == 0)
    {
        return;
    }

    std::cout << "Bazaar Search Window List:" << std::endl;

    for (size_t i = 0; i < listCount; i++)
    {
        uint32_t itemID = EQ_BazaarSearchWindow_GetItemID(i);
        if (itemID == 0)
        {
            continue;
        }

        uint32_t itemQuantity = EQ_BazaarSearchWindow_GetItemQuantity(i);
        if (itemQuantity == 0)
        {
            continue;
        }

        uint32_t itemPrice = EQ_BazaarSearchWindow_GetItemPrice(i);
        if (itemPrice == 0)
        {
            continue;
        }

        itemPrice = (uint32_t)(itemPrice / 1000); // price in platinum pieces

        std::string itemName = EQ_BazaarSearchWindow_GetItemName(i);
        if (itemName.size() == 0)
        {
            continue;
        }

        std::string traderName = EQ_BazaarSearchWindow_GetTraderName(i);
        if (traderName.size() == 0)
        {
            continue;
        }

        std::cout << itemName << ", " << itemQuantity << "x, " << itemPrice << "pp, " << traderName << std::endl;
    }

    std::cout << listCount << " item(s) in list." << std::endl;
}

uint32_t EQ_BazaarSearchWindow_GetListCount()
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return 0;
    }

    uint32_t listCount = 0;

    for (size_t i = 0; i < EQ_BAZAAR_SEARCH_MAX_RESULTS_PER_TRADER; i++)
    {
        uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (i * EQ_SIZE_CBazaarSearchWnd_ITEM)));
        if (itemID == 0)
        {
            break;
        }

        listCount++;
    }

    return listCount;
}

uint32_t EQ_BazaarSearchWindow_GetListIndexByItemName(const char* itemName, bool useExactComparsion)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return EQ_BAZAAR_SEARCH_LIST_INDEX_NULL;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return EQ_BAZAAR_SEARCH_LIST_INDEX_NULL;
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

    return EQ_BAZAAR_SEARCH_LIST_INDEX_NULL;
}

bool EQ_BazaarSearchWindow_BuyItem(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return false;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return false;
    }

    EQ_WriteMemory<uint32_t>(bazaarSearchWindow + EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX, listIndex);

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemID == 0)
    {
        return false;
    }

    uint32_t itemPrice = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemPrice == 0)
    {
        return false;
    }

    uint32_t itemQuantity = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemQuantity == 0)
    {
        return false;
    }

    bool result = EQ_CLASS_POINTER_CBazaarSearchWnd->BuyItem(itemQuantity);

    return result;
}

uint32_t EQ_BazaarSearchWindow_GetListIndex()
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return EQ_BAZAAR_SEARCH_LIST_INDEX_NULL;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return EQ_BAZAAR_SEARCH_LIST_INDEX_NULL;
    }

    uint32_t listIndex = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX);

    return listIndex;
}

uint32_t EQ_BazaarSearchWindow_GetItemID(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));

    return itemID;
}

uint32_t EQ_BazaarSearchWindow_GetItemQuantity(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemID == 0)
    {
        return 0;
    }

    uint32_t itemQuantity = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));

    return itemQuantity;
}

uint32_t EQ_BazaarSearchWindow_GetItemPrice(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return 0;
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return 0;
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemID == 0)
    {
        return 0;
    }

    uint32_t itemPrice = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));

    return itemPrice;
}

std::string EQ_BazaarSearchWindow_GetItemName(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return std::string();
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return std::string();
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemID == 0)
    {
        return std::string();
    }

    char itemName[EQ_SIZE_CBazaarSearchWnd_ITEM_NAME];
    std::memmove(itemName, (LPVOID)(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM))), sizeof(itemName));

    return itemName;
}

std::string EQ_BazaarSearchWindow_GetTraderName(uint32_t listIndex)
{
    uint32_t bazaarSearchWindow = EQ_GetBazaarSearchWindow();
    if (bazaarSearchWindow == NULL)
    {
        return std::string();
    }

    bool isOpen = ((EQClass::CXWnd*)bazaarSearchWindow)->IsReallyVisible();
    if (isOpen == false)
    {
        return std::string();
    }

    uint32_t itemID = EQ_ReadMemory<uint32_t>(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_ITEM_ID + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM)));
    if (itemID == 0)
    {
        return std::string();
    }

    char traderName[EQ_SIZE_CBazaarSearchWnd_TRADER_NAME];
    std::memmove(traderName, (LPVOID)(bazaarSearchWindow + (EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME + (listIndex * EQ_SIZE_CBazaarSearchWnd_ITEM))), sizeof(traderName));

    return traderName;
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

bool EQ_TaskSelectWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CTaskSelectWnd) == true);
}

bool EQ_TaskSelectWindow_ClickAcceptButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CTaskSelectWnd, EQ_OFFSET_CTaskSelectWnd_BUTTON_ACCEPT);
}

bool EQ_TaskSelectWindow_ClickDeclineButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CTaskSelectWnd, EQ_OFFSET_CTaskSelectWnd_BUTTON_DECLINE);
}

bool EQ_LargeDialogWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CLargeDialogWnd) == true);
}

bool EQ_LargeDialogWindow_ClickOKButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CLargeDialogWnd, EQ_OFFSET_CLargeDialogWnd_BUTTON_OK);
}

bool EQ_LargeDialogWindow_ClickYesButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CLargeDialogWnd, EQ_OFFSET_CLargeDialogWnd_BUTTON_YES);
}

bool EQ_LargeDialogWindow_ClickNoButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CLargeDialogWnd, EQ_OFFSET_CLargeDialogWnd_BUTTON_NO);
}

bool EQ_ConfirmationDialog_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CConfirmationDialog) == true);
}

bool EQ_ConfirmationDialog_ClickYesButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CConfirmationDialog, EQ_OFFSET_CConfirmationDialog_BUTTON_YES);
}

bool EQ_ConfirmationDialog_ClickNoButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CConfirmationDialog, EQ_OFFSET_CConfirmationDialog_BUTTON_NO);
}

bool EQ_ConfirmationDialog_ClickCancelButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CConfirmationDialog, EQ_OFFSET_CConfirmationDialog_BUTTON_CANCEL);
}

bool EQ_ConfirmationDialog_ClickOKButton()
{
    return EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CConfirmationDialog, EQ_OFFSET_CConfirmationDialog_BUTTON_OK);
}

void EQ_LargeDialogWindow_Open(const char* titleText, const char* bodyText)
{
    EQ_LargeDialogWindow_OpenWithTimer(titleText, bodyText, 0);
}

void EQ_LargeDialogWindow_OpenWithTimer(const char* titleText, const char* bodyText, unsigned long closeTimer)
{
    if (EQ_LargeDialogWindow_IsOpen() == false)
    {
        EQClass::CXStr bodyTextCXStr(bodyText);
        EQClass::CXStr titleTextCXStr(titleText);

        EQ_CLASS_POINTER_CLargeDialogWnd->Open(false, bodyTextCXStr, closeTimer, titleTextCXStr, false, NULL, NULL);
    }
}

uint32_t EQ_GetPlayerWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CPlayerWnd);
}

bool EQ_PlayerWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CPlayerWnd) == true);
}

uint32_t EQ_PlayerWindow_GetCombatState()
{
    auto playerWindow = EQ_GetPlayerWindow();
    if (playerWindow == NULL)
    {
        return EQ_COMBAT_STATE_NULL;
    }

    return EQ_ReadMemory<uint32_t>(playerWindow + EQ_OFFSET_CPlayerWnd_COMBAT_STATE);
}

uint32_t EQ_GetTargetWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CTargetWnd);
}

bool EQ_TargetWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CTargetWnd) == true);
}

bool EQ_TargetWindow_FindBuffSpellID(uint32_t spellID)
{
    auto targetWindow = EQ_GetTargetWindow();
    if (targetWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_BUFF_SLOTS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(targetWindow + EQ_OFFSET_CTargetWnd_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            return true;
        }
    }

    return false;
}

bool EQ_TargetWindow_FindBuffSpellName(const char* spellName)
{
    std::string spellNameStr = spellName;
    std::string spellNameRank2 = spellNameStr + " Rk. II";
    std::string spellNameRank3 = spellNameStr + " Rk. III";

    auto spellID      = EQ_GetSpellIDByName(spellName);
    auto spellIDRank2 = EQ_GetSpellIDByName(spellNameRank2.c_str());
    auto spellIDRank3 = EQ_GetSpellIDByName(spellNameRank3.c_str());

    bool result =      EQ_TargetWindow_FindBuffSpellID(spellID);
    bool resultRank2 = EQ_TargetWindow_FindBuffSpellID(spellIDRank2);
    bool resultRank3 = EQ_TargetWindow_FindBuffSpellID(spellIDRank3);

    return (result == true || resultRank2 == true || resultRank3 == true);
}

uint32_t EQ_GetPetInfoWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CPetInfoWindow);
}

bool EQ_PetInfoWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CPetInfoWindow) == true);
}

uint32_t EQ_PetInfoWindow_GetSpawnID()
{
    auto petInfoWindow = EQ_GetPetInfoWindow();
    if (petInfoWindow == NULL)
    {
        return EQ_SPAWN_ID_NULL;
    }

    return EQ_ReadMemory<uint32_t>(petInfoWindow + EQ_OFFSET_CPetInfoWindow_SPAWN_ID);
}

bool EQ_PetInfoWindow_FindBuffSpellID(uint32_t spellID)
{
    auto petInfoWindow = EQ_GetPetInfoWindow();
    if (petInfoWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_BUFF_SLOTS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(petInfoWindow + EQ_OFFSET_CPetInfoWindow_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            return true;
        }
    }

    return false;
}

bool EQ_PetInfoWindow_FindBuffSpellName(const char* spellName)
{
    std::string spellNameStr = spellName;
    std::string spellNameRank2 = spellNameStr + " Rk. II";
    std::string spellNameRank3 = spellNameStr + " Rk. III";

    auto spellID      = EQ_GetSpellIDByName(spellName);
    auto spellIDRank2 = EQ_GetSpellIDByName(spellNameRank2.c_str());
    auto spellIDRank3 = EQ_GetSpellIDByName(spellNameRank3.c_str());

    bool result =      EQ_PetInfoWindow_FindBuffSpellID(spellID);
    bool resultRank2 = EQ_PetInfoWindow_FindBuffSpellID(spellIDRank2);
    bool resultRank3 = EQ_PetInfoWindow_FindBuffSpellID(spellIDRank3);

    return (result == true || resultRank2 == true || resultRank3 == true);
}

uint32_t EQ_GetLongBuffWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBuffWnd_Long);
}

bool EQ_LongBuffWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBuffWnd_Long) == true);
}

uint32_t EQ_GetShortBuffWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CBuffWnd_Short);
}

bool EQ_ShortBuffWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CBuffWnd_Short) == true);
}

bool EQ_BuffWindows_FindBuffSpellID(uint32_t spellID)
{
    auto longBuffWindow = EQ_GetLongBuffWindow();
    if (longBuffWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_LONG_BUFFS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(longBuffWindow + EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            return true;
        }
    }

    auto shortBuffWindow = EQ_GetShortBuffWindow();
    if (shortBuffWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_SHORT_BUFFS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(shortBuffWindow + EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            return true;
        }
    }

    return false;
}

bool EQ_BuffWindows_FindBuffSpellName(const char* spellName)
{
    std::string spellNameStr = spellName;
    std::string spellNameRank2 = spellNameStr + " Rk. II";
    std::string spellNameRank3 = spellNameStr + " Rk. III";

    auto spellID      = EQ_GetSpellIDByName(spellName);
    auto spellIDRank2 = EQ_GetSpellIDByName(spellNameRank2.c_str());
    auto spellIDRank3 = EQ_GetSpellIDByName(spellNameRank3.c_str());

    bool result =      EQ_BuffWindows_FindBuffSpellID(spellID);
    bool resultRank2 = EQ_BuffWindows_FindBuffSpellID(spellIDRank2);
    bool resultRank3 = EQ_BuffWindows_FindBuffSpellID(spellIDRank3);

    return (result == true || resultRank2 == true || resultRank3 == true);
}

bool EQ_BuffWindows_RemoveBuffSpellID(uint32_t spellID)
{
    auto longBuffWindow = EQ_GetLongBuffWindow();
    if (longBuffWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_LONG_BUFFS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(longBuffWindow + EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            auto buffButtonOffset = EQ_OFFSET_CBuffWnd_BUFF_BUTTONS + (i * 0x04);

            EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBuffWnd_Long, buffButtonOffset);

            return true;
        }
    }

    auto shortBuffWindow = EQ_GetShortBuffWindow();
    if (shortBuffWindow == NULL)
    {
        return false;
    }

    for (unsigned int i = 0; i < EQ_NUM_SHORT_BUFFS; i++)
    {
        auto buffSpellID = EQ_ReadMemory<uint32_t>(shortBuffWindow + EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS + (i * 0x04));
        if (buffSpellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        if (buffSpellID == spellID)
        {
            auto buffButtonOffset = EQ_OFFSET_CBuffWnd_BUFF_BUTTONS + (i * 0x04);

            EQ_CXWnd_ClickButton(EQ_ADDRESS_POINTER_CBuffWnd_Short, buffButtonOffset);

            return true;
        }
    }

    return false;
}

bool EQ_BuffWindows_RemoveBuffSpellName(const char* spellName)
{
    std::string spellNameStr = spellName;
    std::string spellNameRank2 = spellNameStr + " Rk. II";
    std::string spellNameRank3 = spellNameStr + " Rk. III";

    auto spellID      = EQ_GetSpellIDByName(spellName);
    auto spellIDRank2 = EQ_GetSpellIDByName(spellNameRank2.c_str());
    auto spellIDRank3 = EQ_GetSpellIDByName(spellNameRank3.c_str());

    bool result =      EQ_BuffWindows_RemoveBuffSpellID(spellID);
    bool resultRank2 = EQ_BuffWindows_RemoveBuffSpellID(spellIDRank2);
    bool resultRank3 = EQ_BuffWindows_RemoveBuffSpellID(spellIDRank3);

    return (result == true || resultRank2 == true || resultRank3 == true);
}

uint32_t EQ_GetCastSpellWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CCastSpellWnd);
}

bool EQ_CastSpellWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CCastSpellWnd) == true);
}

uint32_t EQ_CastSpellWindow_GetSpellGemStateByIndex(uint32_t index)
{
    auto castSpellWindow = EQ_GetCastSpellWindow();
    if (castSpellWindow == NULL)
    {
        return EQ_SPELL_GEM_STATE_NULL;
    }

    auto spellGemWindow = EQ_ReadMemory<uint32_t>(castSpellWindow + EQ_OFFSET_CCastSpellWnd_SPELL_GEMS + (index * 0x04));
    if (spellGemWindow == NULL)
    {
        return EQ_SPELL_GEM_STATE_NULL;
    }

    auto spellGemState = EQ_ReadMemory<uint32_t>(spellGemWindow + EQ_OFFSET_CSpellGemWnd_STATE);

    return spellGemState;
}

uint32_t EQ_CastSpellWindow_GetSpellGemStateBySpellID(uint32_t spellID)
{
    auto spellGemIndex = EQ_GetSpellGemIndexBySpellID(spellID);
    if (spellGemIndex == EQ_SPELL_GEM_INDEX_NULL)
    {
        return EQ_SPELL_GEM_STATE_NULL;
    }

    auto spellGemState = EQ_CastSpellWindow_GetSpellGemStateByIndex(spellGemIndex);

    return spellGemState;
}

uint32_t EQ_CastSpellWindow_GetSpellGemStateBySpellName(const char* spellName)
{
    auto spellID = EQ_GetSpellIDByName(spellName);
    if (spellID == EQ_SPELL_ID_NULL)
    {
        return EQ_SPELL_GEM_STATE_NULL;
    }

    return EQ_CastSpellWindow_GetSpellGemStateBySpellID(spellID);
}

uint32_t EQ_GetCastingWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CCastingWnd);
}

bool EQ_CastingWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CCastingWnd) == true);
}

uint32_t EQ_GetMapWindow()
{
    return EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_CMapViewWnd);
}

bool EQ_MapWindow_IsOpen()
{
    return (EQ_CXWnd_IsOpen(EQ_ADDRESS_POINTER_CMapViewWnd) == true);
}

uint32_t EQ_MapWindow_GetLines()
{
    auto mapWindow = EQ_GetMapWindow();
    if (mapWindow == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(mapWindow + EQ_OFFSET_CMapViewWnd_LINES);
}

uint32_t EQ_MapWindow_GetLabels()
{
    auto mapWindow = EQ_GetMapWindow();
    if (mapWindow == NULL)
    {
        return NULL;
    }

    return EQ_ReadMemory<uint32_t>(mapWindow + EQ_OFFSET_CMapViewWnd_LABELS);
}
