#pragma once

bool g_espIsEnabled            = true;
bool g_espSpawnIsEnabled       = true;
bool g_espGroundSpawnIsEnabled = true;
bool g_espDoorIsEnabled        = false;
bool g_espSkeletonIsEnabled    = false;
bool g_espZoneActorIsEnabled   = false;
bool g_espWaypointIsEnabled    = false;

float g_espSpawnDistance       = 400.0f;
float g_espGroundSpawnDistance = 200.0f;
float g_espDoorDistance        = 100.0f;
float g_espSkeletonDistance    = 100.0f;
float g_espZoneActorDistance   = 200.0f;
float g_espWaypointDistance    = 1000.0f;

uint32_t g_espGroundSpawnColorARGB = 0xFFFFFFFF;
uint32_t g_espDoorColorARGB        = 0xFFFFFFFF;
uint32_t g_espZoneActorColorARGB   = 0xFFFFFFFF;
uint32_t g_espWaypointColorARGB    = 0xFFC0C0C0;
uint32_t g_espLocatorColorARGB     = 0xFFFFFFFF;
uint32_t g_espFindColorARGB        = 0xFF00FF80;

bool g_espSkeletonHideByLineOfSightIsEnabled = false;
bool g_espSkeletonDrawLinesIsEnabled         = false;
bool g_espSkeletonDrawAddressesIsEnabled     = false;

bool g_espLocatorIsEnabled = false;
bool g_espLocatorDrawLineIsEnabled = true;
float g_espLocatorY = 0.0f;
float g_espLocatorX = 0.0f;
float g_espLocatorZ = 0.0f;
uint32_t g_espLocatorFontSize = 5;

bool g_espFindIsEnabled = false;
bool g_espFindDrawLineIsEnabled = true;
std::string g_espFindSpawnName;
uint32_t g_espFindCount = 0;

uint32_t g_espNumDrawText = 0;
uint32_t g_espNumNpcCorpseMax = 10;

float g_espHalfDistanceColorDarkenPercent = 0.90f;

