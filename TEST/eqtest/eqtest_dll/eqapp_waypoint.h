#pragma once

#include "eqapp_lua.h"

namespace EQApp
{
    typedef std::vector<uint32_t> WaypointIndexList;

    typedef struct _Waypoint
    {
        uint32_t Index;
        std::string Name;
        float Y;
        float X;
        float Z;
        WaypointIndexList ConnectIndexList;
        uint32_t Flags = 0; // optional
        std::string ScriptFilename; // optional

        // editor
        bool IsDrawn = false;

        // A* Star pathfinding algorithm
        bool IsOpened;
        bool IsClosed;
        uint32_t F = 0;
        uint32_t G = 0;
        uint32_t H = 0;
        struct _Waypoint* Parent;
    } Waypoint, *Waypoint_ptr;

    typedef std::vector<EQApp::Waypoint> WaypointList;

    uint32_t WaypointIndexNull = 0xFFFFFFFF;

    uint32_t WaypointFlagNull = 0xFFFFFFFF;

    enum WaypointFlags
    {
        kStand                = 1 << 0,
        kDuck                 = 1 << 1,
        kJump                 = 1 << 2,
        kUseDoor              = 1 << 3,
        kClickToZone          = 1 << 4,
        kFaceNorth            = 1 << 5,
        kFaceNorthEast        = 1 << 6,
        kFaceEast             = 1 << 7,
        kFaceSouthEast        = 1 << 8,
        kFaceSouth            = 1 << 9,
        kFaceSouthWest        = 1 << 10,
        kFaceWest             = 1 << 11,
        kFaceNorthWest        = 1 << 12,
    };

    std::unordered_map<uint32_t, std::string> WaypointFlagsStrings =
    {
        {WaypointFlagNull,                     "None"},
        {WaypointFlags::kStand,                "Stand"},
        {WaypointFlags::kDuck,                 "Duck"},
        {WaypointFlags::kJump,                 "Jump"},
        {WaypointFlags::kUseDoor,              "UseDoor"},
        {WaypointFlags::kClickToZone,          "ClickToZone"},
        {WaypointFlags::kFaceNorth,            "FaceNorth"},
        {WaypointFlags::kFaceNorthEast,        "FaceNorthEast"},
        {WaypointFlags::kFaceEast,             "FaceEast"},
        {WaypointFlags::kFaceSouthEast,        "FaceSouthEast"},
        {WaypointFlags::kFaceSouth,            "FaceSouth"},
        {WaypointFlags::kFaceSouthWest,        "FaceSouthWest"},
        {WaypointFlags::kFaceWest,             "FaceWest"},
        {WaypointFlags::kFaceNorthWest,        "FaceNorthWest"},
    };
}

bool g_WaypointIsEnabled = true;

bool g_WaypointEditorIsEnabled = false;

bool g_WaypointEditorHeightFilterIsEnabled = false;

float g_WaypointEditorHeightFilterDistanceLow  = 10.0f;
float g_WaypointEditorHeightFilterDistanceHigh = 10.0f;

uint32_t g_WaypointEditorDrawTextX = 600;
uint32_t g_WaypointEditorDrawTextY = 10;

uint32_t g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
uint32_t g_WaypointEditorToIndex   = EQApp::WaypointIndexNull;

bool g_WaypointFollowPathIsEnabled = false;

float g_WaypointFollowPathDistance = 2.0f;

float g_WaypointUseDoorDistance = 20.0f;

float g_WaypointAddTargetDistance = 5.0f;

EQApp::WaypointList g_WaypointList;

EQApp::WaypointList g_WaypointListUndo;
EQApp::WaypointList g_WaypointListRedo;

EQApp::WaypointIndexList g_WaypointGetPathIndexList;

EQApp::WaypointIndexList g_WaypointFollowPathIndexList;

void EQAPP_Waypoint_Editor_Toggle();
void EQAPP_Waypoint_Editor_On();
void EQAPP_Waypoint_Editor_Off();
void EQAPP_Waypoint_Editor_HeightFilter_Toggle();
void EQAPP_Waypoint_Editor_HeightFilter_On();
void EQAPP_Waypoint_Editor_HeightFilter_Off();
void EQAPP_Waypoint_FollowPath_Toggle();
void EQAPP_Waypoint_FollowPath_On();
void EQAPP_Waypoint_FollowPath_Off();
void EQAPP_Waypoint_Undo();
void EQAPP_Waypoint_Redo();
void EQAPP_Waypoint_SetName(uint32_t index, const char* name);
void EQAPP_Waypoint_Add(float y, float x, float z, const char* name);
void EQAPP_Waypoint_AddAtPlayer(const char* waypointName);
void EQAPP_Waypoint_AddAtPlayerAndConnectLastTwoIndexes();
void EQAPP_Waypoint_AddAtTarget(const char* waypointName);
void EQAPP_Waypoint_AddAtTargetAndConnectLastTwoIndexes();
void EQAPP_Waypoint_AddBehindTarget(const char* waypointName);
void EQAPP_Waypoint_AddBehindTargetAndConnectLastTwoIndexes();
void EQAPP_Waypoint_Remove(uint32_t index);
void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_ConnectLastTwoIndexes();
void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_DisconnectAll(uint32_t index);
bool EQAPP_Waypoint_IsConnected(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_ClearFlags(uint32_t index);
void EQAPP_Waypoint_AddFlag(uint32_t index, uint32_t flag);
void EQAPP_Waypoint_RemoveFlag(uint32_t index, uint32_t flag);
void EQAPP_Waypoint_Align(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignY(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignX(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignZ(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PushAwayFromPlayer(uint32_t index, float distance, bool roundToNearestDirection);
void EQAPP_Waypoint_PullTowardsPlayer(uint32_t index, float distance, bool roundToNearestDirection);
void EQAPP_Waypoint_MoveToLocation(uint32_t index, float y, float x, float z);
void EQAPP_Waypoint_MoveToPlayer(uint32_t index);
void EQAPP_Waypoint_MoveToTarget(uint32_t index);
void EQAPP_Waypoint_MoveUp(uint32_t index, float distance);
void EQAPP_Waypoint_MoveDown(uint32_t index, float distance);
uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint_ptr waypoint, EQApp::Waypoint_ptr waypointEnd);
EQApp::Waypoint_ptr EQAPP_Waypoint_GetByIndex(uint32_t index);
uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z);
uint32_t EQAPP_Waypoint_GetIndexNearestToLocationInList(float y, float x, float z, EQApp::WaypointIndexList& indexList);
EQApp::WaypointIndexList EQAPP_Waypoint_GetLineOfSightList();
void EQAPP_Waypoint_RemoveConnectionlessFromList(EQApp::WaypointIndexList& indexList);
uint32_t EQAPP_Waypoint_GetIndexForGoto(uint32_t toIndex);
void EQAPP_Waypoint_Goto(uint32_t toIndex);
EQApp::WaypointIndexList EQAPP_Waypoint_GetPathList(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PrintPathList(EQApp::WaypointIndexList& indexList, uint32_t fromIndex);
void EQAPP_Waypoint_FollowPath(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_FollowPathList(EQApp::WaypointIndexList& indexList);
bool EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);
void EQAPP_WaypointList_Clear();
void EQAPP_WaypointList_ClearEx();
void EQAPP_WaypointList_Load();
void EQAPP_WaypointList_Save();
void EQAPP_WaypointList_Print();
void EQAPP_WaypointList_Draw();
void EQAPP_WaypointEditor_DrawText();
uint32_t EQAPP_WaypointEditor_GetClickedIndex(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__LMouseUp(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__RMouseUp(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_Waypoint_Editor_Toggle()
{
    EQ_ToggleBool(g_WaypointEditorIsEnabled);
    EQAPP_PrintBool("Waypoint Editor", g_WaypointEditorIsEnabled);
}

void EQAPP_Waypoint_Editor_On()
{
    if (g_WaypointEditorIsEnabled == false)
    {
        EQAPP_Waypoint_Editor_Toggle();
    }
}

void EQAPP_Waypoint_Editor_Off()
{
    if (g_WaypointEditorIsEnabled == true)
    {
        EQAPP_Waypoint_Editor_Toggle();
    }
}

void EQAPP_Waypoint_Editor_HeightFilter_Toggle()
{
    EQ_ToggleBool(g_WaypointEditorHeightFilterIsEnabled);
    EQAPP_PrintBool("Waypoint Editor Height Filter", g_WaypointEditorHeightFilterIsEnabled);
}

void EQAPP_Waypoint_Editor_HeightFilter_On()
{
    if (g_WaypointEditorHeightFilterIsEnabled == false)
    {
        EQAPP_Waypoint_Editor_HeightFilter_Toggle();
    }
}

void EQAPP_Waypoint_Editor_HeightFilter_Off()
{
    if (g_WaypointEditorHeightFilterIsEnabled == true)
    {
        EQAPP_Waypoint_Editor_HeightFilter_Toggle();
    }
}

void EQAPP_Waypoint_FollowPath_Toggle()
{
    EQ_ToggleBool(g_WaypointFollowPathIsEnabled);
    EQAPP_PrintBool("Waypoint Follow Path", g_WaypointFollowPathIsEnabled);

    if (g_WaypointFollowPathIsEnabled == true)
    {
        EQ_StopFollow();

        g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        g_WaypointEditorToIndex = EQApp::WaypointIndexNull;
    }
    else
    {
        EQ_SetAutoRun(false);

        g_WaypointGetPathIndexList.clear();
    }
}

void EQAPP_Waypoint_FollowPath_On()
{
    if (g_WaypointFollowPathIsEnabled == false)
    {
        EQAPP_Waypoint_FollowPath_Toggle();
    }
}

void EQAPP_Waypoint_FollowPath_Off()
{
    if (g_WaypointFollowPathIsEnabled == true)
    {
        EQAPP_Waypoint_FollowPath_Toggle();
    }
}

void EQAPP_Waypoint_Undo()
{
    if (g_WaypointListUndo.size() != 0)
    {
        g_WaypointListRedo = g_WaypointList;

        g_WaypointList = g_WaypointListUndo;
    }
}

void EQAPP_Waypoint_Redo()
{
    if (g_WaypointListRedo.size() != 0)
    {
        g_WaypointListUndo = g_WaypointList;

        g_WaypointList = g_WaypointListRedo;
    }
}

void EQAPP_Waypoint_SetName(uint32_t index, const char* name)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Name = name;

    std::cout << "Waypoint index " << waypoint->Index << " name set to: " << name;
}

void EQAPP_Waypoint_SetScriptFilename(uint32_t index, const char* scriptFilename)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->ScriptFilename = scriptFilename;

    std::cout << "Waypoint index " << waypoint->Index << " script filename set to: " << scriptFilename;
}

void EQAPP_Waypoint_AddAtPlayer(const char* waypointName)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto y = EQ_GetSpawnY(playerSpawn);
        auto x = EQ_GetSpawnX(playerSpawn);
        auto z = EQ_GetSpawnZ(playerSpawn);

        EQAPP_Waypoint_Add(y, x, z, waypointName);
    }
}

void EQAPP_Waypoint_AddAtPlayerAndConnectLastTwoIndexes()
{
    EQAPP_Waypoint_AddAtPlayer("");
    EQAPP_Waypoint_ConnectLastTwoIndexes();
}

void EQAPP_Waypoint_AddAtTarget(const char* waypointName)
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn != NULL)
    {
        auto y = EQ_GetSpawnY(targetSpawn);
        auto x = EQ_GetSpawnX(targetSpawn);
        auto z = EQ_GetSpawnZ(targetSpawn);

        float heading = EQ_GetSpawnHeading(targetSpawn);

        EQ_ApplyVectorForward(y, x, heading, g_WaypointAddTargetDistance);

        EQAPP_Waypoint_Add(y, x, z, waypointName);

        EQ_ClearTarget();
    }
}

void EQAPP_Waypoint_AddAtTargetAndConnectLastTwoIndexes()
{
    EQAPP_Waypoint_AddAtTarget("");
    EQAPP_Waypoint_ConnectLastTwoIndexes();
}

void EQAPP_Waypoint_AddBehindTarget(const char* waypointName)
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn != NULL)
    {
        auto y = EQ_GetSpawnY(targetSpawn);
        auto x = EQ_GetSpawnX(targetSpawn);
        auto z = EQ_GetSpawnZ(targetSpawn);

        float heading = EQ_GetSpawnHeading(targetSpawn);

        EQ_ApplyVectorBackward(y, x, heading, g_WaypointAddTargetDistance);

        EQAPP_Waypoint_Add(y, x, z, waypointName);

        EQ_ClearTarget();
    }
}

void EQAPP_Waypoint_AddBehindTargetAndConnectLastTwoIndexes()
{
    EQAPP_Waypoint_AddBehindTarget("");
    EQAPP_Waypoint_ConnectLastTwoIndexes();
}

void EQAPP_Waypoint_Add(float y, float x, float z, const char* name)
{
    g_WaypointListUndo = g_WaypointList;

    uint32_t index = 0;

    for (auto& waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if (waypoint_it->Index == index)
        {
            index++;
            waypoint_it = g_WaypointList.begin();
        }
    }

    std::stringstream waypointName;

    if (strlen(name) == 0)
    {
        waypointName << "Waypoint" << index;
    }
    else
    {
        waypointName << name;
    }

    EQApp::Waypoint waypoint;
    waypoint.Index = index;
    waypoint.Y = y;
    waypoint.X = x;
    waypoint.Z = z;
    waypoint.Name = waypointName.str();

    g_WaypointList.push_back(waypoint);

    std::cout << "Waypoint index " << index << " added." << std::endl;
}

void EQAPP_Waypoint_Remove(uint32_t index)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    if (g_WaypointList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint list is empty");
        return;
    }

    for (auto& waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if (waypoint_it->Index == index)
        {
            std::cout << "Waypoint index " << index << " removed." << std::endl;

            waypoint_it = g_WaypointList.erase(waypoint_it);
            waypoint_it--;
        }
    }

    for (auto& waypoint : g_WaypointList)
    {
        for (auto& connectIndex_it = waypoint.ConnectIndexList.begin(); connectIndex_it != waypoint.ConnectIndexList.end(); connectIndex_it++)
        {
            if (*connectIndex_it == index)
            {
                std::cout << "Waypoint index " << waypoint.Index << " disconnected from waypoint index " << *connectIndex_it << "." << std::endl;

                connectIndex_it = waypoint.ConnectIndexList.erase(connectIndex_it);
                connectIndex_it--;
            }
        }
    }
}

void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    g_WaypointListUndo = g_WaypointList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index and to index are the same");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    for (auto& connectIndex : fromWaypoint->ConnectIndexList)
    {
        if (connectIndex == toIndex)
        {
            std::string debugText = fmt::format("connection already exists from index {} to index {}", fromIndex, toIndex);

            EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
            return;
        }
    }

    fromWaypoint->ConnectIndexList.push_back(toIndex);

    std::cout << "Waypoint index " << fromIndex << " connected to waypoint index " << toIndex << "." << std::endl;

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex : toWaypoint->ConnectIndexList)
        {
            if (connectIndex == fromIndex)
            {
                std::string debugText = fmt::format("connection already exists from index {} to index {}", toIndex, fromIndex);

                EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
                return;
            }
        }

        toWaypoint->ConnectIndexList.push_back(fromIndex);

        std::cout << "Waypoint index " << toIndex << " connected to waypoint index " << fromIndex << "." << std::endl;
    }
}

void EQAPP_Waypoint_ConnectLastTwoIndexes()
{
    EQApp::Waypoint_ptr lastWaypoint = &g_WaypointList.back();
    if (lastWaypoint != NULL)
    {
        auto lastIndex = lastWaypoint->Index;
        if (lastIndex > 0)
        {
            EQAPP_Waypoint_Connect(lastIndex, lastIndex - 1, false);
        }
    }
}

void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    g_WaypointListUndo = g_WaypointList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index and to index are the same");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    for (auto& connectIndex_it = fromWaypoint->ConnectIndexList.begin(); connectIndex_it != fromWaypoint->ConnectIndexList.end(); connectIndex_it++)
    {
        if (*connectIndex_it == toIndex)
        {
            std::cout << "Waypoint index " << fromIndex << " disconnected from waypoint index "<< toIndex << "." << std::endl;

            connectIndex_it = fromWaypoint->ConnectIndexList.erase(connectIndex_it);
            connectIndex_it--;
            break;
        }
    }

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex_it = toWaypoint->ConnectIndexList.begin(); connectIndex_it != toWaypoint->ConnectIndexList.end(); connectIndex_it++)
        {
            if (*connectIndex_it == fromIndex)
            {
                std::cout << "Waypoint index " << toIndex << " disconnected from waypoint index "<< fromIndex << "." << std::endl;

                connectIndex_it = toWaypoint->ConnectIndexList.erase(connectIndex_it);
                connectIndex_it--;
                break;
            }
        }
    }
}

void EQAPP_Waypoint_DisconnectAll(uint32_t index)
{
    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    for (auto& connectIndex : waypoint->ConnectIndexList)
    {
        EQAPP_Waypoint_Disconnect(index, connectIndex, false);
    }
}

bool EQAPP_Waypoint_IsConnected(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return false;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return false;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return false;
    }

    for (auto& connectIndex : fromWaypoint->ConnectIndexList)
    {
        if (connectIndex == toIndex)
        {
            return true;
        }
    }

    return false;
}

void EQAPP_Waypoint_ClearFlags(uint32_t index)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Flags = 0;

    std::cout << "Waypoint index " << waypoint->Index << " flags cleared.";
}

void EQAPP_Waypoint_AddFlag(uint32_t index, uint32_t flag)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Flags |= flag;

    std::string flagName = EQ_StringMap_GetValueByKey(EQApp::WaypointFlagsStrings, flag);
    if (flagName.size() != 0)
    {
        std::cout << "Waypoint index " << waypoint->Index << " added flag: " << flagName;
    }
}

void EQAPP_Waypoint_RemoveFlag(uint32_t index, uint32_t flag)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    if (flag == EQApp::WaypointFlagNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "flag is null");
        return;
    }

    waypoint->Flags ^= flag;

    std::string flagName = EQ_StringMap_GetValueByKey(EQApp::WaypointFlagsStrings, flag);
    if (flagName.size() != 0)
    {
        std::cout << "Waypoint index " << waypoint->Index << " removed flag: " << flagName;
    }
}

void EQAPP_Waypoint_Align(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    auto diffX = std::fabsf(fromWaypoint->X - toWaypoint->X);
    auto diffY = std::fabsf(fromWaypoint->Y - toWaypoint->Y);

    if (diffY < diffX)
    {
        EQAPP_Waypoint_AlignY(fromIndex, toIndex);
    }
    else
    {
        EQAPP_Waypoint_AlignX(fromIndex, toIndex);
    }
}

void EQAPP_Waypoint_AlignY(uint32_t fromIndex, uint32_t toIndex)
{
    g_WaypointListUndo = g_WaypointList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    fromWaypoint->Y = toWaypoint->Y;

    std::cout << "Waypoint index " << fromIndex << " aligned with waypoint index " << toIndex << " on the Y-Axis.";
}

void EQAPP_Waypoint_AlignX(uint32_t fromIndex, uint32_t toIndex)
{
    g_WaypointListUndo = g_WaypointList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    fromWaypoint->X = toWaypoint->X;

    std::cout << "Waypoint index " << fromIndex << " aligned with waypoint index " << toIndex << " on the X-Axis.";
}

void EQAPP_Waypoint_AlignZ(uint32_t fromIndex, uint32_t toIndex)
{
    g_WaypointListUndo = g_WaypointList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    fromWaypoint->Z = toWaypoint->Z;

    std::cout << "Waypoint index " << fromIndex << " aligned with waypoint index " << toIndex << " on the Z-Axis.";
}

void EQAPP_Waypoint_PushAwayFromPlayer(uint32_t index, float distance, bool roundToNearestDirection)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    float playerHeading = EQ_GetSpawnHeading(playerSpawn);

    if (roundToNearestDirection == true)
    {
        if (playerHeading > 0.0f)
        {
            playerHeading = std::roundf(playerHeading / EQ_HEADING_MAX_EIGHTH) * EQ_HEADING_MAX_EIGHTH;
        }
    }

    EQ_ApplyVectorForward(waypoint->Y, waypoint->X, playerHeading, distance);

    std::cout << "Waypoint index " << index << " pushed " << distance << " distance.";
}

void EQAPP_Waypoint_PullTowardsPlayer(uint32_t index, float distance, bool roundToNearestDirection)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    float playerHeading = EQ_GetSpawnHeading(playerSpawn);

    if (roundToNearestDirection == true)
    {
        if (playerHeading > 0.0f)
        {
            playerHeading = std::roundf(playerHeading / EQ_HEADING_MAX_EIGHTH) * EQ_HEADING_MAX_EIGHTH;
        }
    }

    EQ_ApplyVectorBackward(waypoint->Y, waypoint->X, playerHeading, distance);

    std::cout << "Waypoint index " << index << " pulled " << distance << " distance.";
}

void EQAPP_Waypoint_MoveToLocation(uint32_t index, float y, float x, float z)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Y = y;
    waypoint->X = x;
    waypoint->Z = z;

    std::cout << "Waypoint index " << index << " moved to location: " << y << ", " << x << ", " << z;
}

void EQAPP_Waypoint_MoveToPlayer(uint32_t index)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    waypoint->Y = playerY;
    waypoint->X = playerX;
    waypoint->Z = playerZ;

    std::cout << "Waypoint index " << index << " moved to player.";
}

void EQAPP_Waypoint_MoveToTarget(uint32_t index)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "target spawn is null");
        return;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    waypoint->Y = targetY;
    waypoint->X = targetX;
    waypoint->Z = targetZ;

    std::cout << "Waypoint index " << index << " moved to target.";
}

void EQAPP_Waypoint_MoveUp(uint32_t index, float distance)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Z = waypoint->Z + distance;

    std::cout << "Waypoint index " << index << " moved up " << distance << " distance.";
}

void EQAPP_Waypoint_MoveDown(uint32_t index, float distance)
{
    g_WaypointListUndo = g_WaypointList;

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    auto waypoint = EQAPP_Waypoint_GetByIndex(index);
    if (waypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint is null");
        return;
    }

    waypoint->Z = waypoint->Z - distance;

    std::cout << "Waypoint index " << index << " moved down " << distance << " distance.";
}

uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    // TODO: insert optimizations here

    return waypoint1->G;
}

uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    // manhattan distance
    ////return (uint32_t)(std::fabsf(waypoint1->x - waypoint2->x) + std::fabsf(waypoint1->y - waypoint2->y) * 10);

    // euclidean distance
    return (uint32_t)(std::sqrt(std::pow(waypoint2->X - waypoint1->X, 2) + std::pow(waypoint2->Y - waypoint1->Y, 2) + std::pow(waypoint2->Z - waypoint1->Z, 2)));
}

void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint_ptr waypoint, EQApp::Waypoint_ptr waypointEnd)
{
    waypoint->G = EQAPP_Waypoint_GetGScore(waypoint, waypoint->Parent);
    waypoint->H = EQAPP_Waypoint_GetHScore(waypoint, waypointEnd);

    waypoint->F = waypoint->G + waypoint->H;
}

EQApp::Waypoint_ptr EQAPP_Waypoint_GetByIndex(uint32_t index)
{
    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return NULL;
    }

    for (auto& waypoint : g_WaypointList)
    {
        if (waypoint.Index == index)
        {
            return &waypoint;
        }
    }

    std::string debugText = fmt::format("index not found: {}", index);

    EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
    return NULL;
}

uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z)
{
    if (g_WaypointList.size() == 0)
    {
        return EQApp::WaypointIndexNull;
    }

    std::map<float, uint32_t> distanceList;

    for (auto& waypoint : g_WaypointList)
    {
        float distance = EQ_CalculateDistance3D(y, x, z, waypoint.Y, waypoint.X, waypoint.Z);

        distanceList.insert(std::make_pair(distance, waypoint.Index));
    }

    return distanceList.begin()->second;
}

uint32_t EQAPP_Waypoint_GetIndexNearestToLocationInList(float y, float x, float z, EQApp::WaypointIndexList& indexList)
{
    std::map<float, uint32_t> distanceList;

    for (auto& index : indexList)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(index);
        if (waypoint == NULL)
        {
            continue;
        }

        float distance = EQ_CalculateDistance3D(y, x, z, waypoint->Y, waypoint->X, waypoint->Z);

        distanceList.insert(std::make_pair(distance, waypoint->Index));
    }

    return distanceList.begin()->second;
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetLineOfSightList()
{
    EQApp::WaypointIndexList indexList;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return indexList;
    }

    for (auto& waypoint : g_WaypointList)
    {
        if (EQ_CanSpawnCastRayToLocation(playerSpawn, waypoint.Y, waypoint.X, waypoint.Z) == true)
        {
            indexList.push_back(waypoint.Index);
        }
    }

    return indexList;
}

void EQAPP_Waypoint_RemoveConnectionlessFromList(EQApp::WaypointIndexList& indexList)
{
    for (auto it = indexList.begin(); it != indexList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(*it);
        if (waypoint == NULL)
        {
            continue;
        }

        if (waypoint->ConnectIndexList.size() == 0)
        {
            it = indexList.erase(it);
            it--;
            continue;
        }
    }
}

uint32_t EQAPP_Waypoint_GetIndexForGoto(uint32_t toIndex)
{
    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return EQApp::WaypointIndexNull;
    }

    auto indexList = EQAPP_Waypoint_GetLineOfSightList();
    if (indexList.size() == 0)
    {
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_RemoveConnectionlessFromList(indexList);

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return EQApp::WaypointIndexNull;
    }

    std::map<float, uint32_t> distanceList;

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    for (auto& index : indexList)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(index);
        if (waypoint == NULL)
        {
            continue;
        }

        float distance = EQ_CalculateDistance3D(playerSpawnY, playerSpawnX, playerSpawnZ, waypoint->Y, waypoint->X, waypoint->Z);

        distanceList.insert(std::make_pair(distance, waypoint->Index));
    }

    for (auto it = distanceList.begin(); it != distanceList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(it->second);
        if (waypoint == NULL)
        {
            continue;
        }

        auto pathIndexList = EQAPP_Waypoint_GetPathList(waypoint->Index, toIndex);
        if (pathIndexList.size() == 0)
        {
            it = distanceList.erase(it);
            it--;
            continue;
        }
    }

    return distanceList.begin()->second;
}

void EQAPP_Waypoint_Goto(uint32_t toIndex)
{
    uint32_t fromIndex = EQAPP_Waypoint_GetIndexForGoto(toIndex);
    if (fromIndex == EQApp::WaypointIndexNull || toIndex == EQApp::WaypointIndexNull)
    {
        std::cout << "No waypoint path can be found from waypoint index " << fromIndex << " to waypoint index " << toIndex << "." << std::endl;
    }

    if (fromIndex != EQApp::WaypointIndexNull && toIndex != EQApp::WaypointIndexNull)
    {
        EQAPP_Waypoint_FollowPath(fromIndex, toIndex);
    }
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetPathList(uint32_t fromIndex, uint32_t toIndex)
{
    EQApp::WaypointIndexList indexList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return indexList;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return indexList;
    }

/*
    // have to comment this out for goto waypoint to work

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index and to index are the same");
        return indexList;
    }
*/

    auto begin = EQAPP_Waypoint_GetByIndex(fromIndex);
    auto end   = EQAPP_Waypoint_GetByIndex(toIndex);

    if (begin == NULL || end == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "begin or end waypoint is null");
        return indexList;
    }


    if (begin->ConnectIndexList.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "begin waypoint has no connections");
        return indexList;
    }

/*
    // may be one way connection to the end

    if (end->ConnectIndexList.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "end waypoint has no connections");
        return indexList;
    }
*/

    EQApp::Waypoint_ptr current;
    EQApp::Waypoint_ptr child;

    std::list<EQApp::Waypoint_ptr> openedList;
    std::list<EQApp::Waypoint_ptr> closedList;
    std::list<EQApp::Waypoint_ptr>::iterator waypointListIterator;

    uint32_t numIterations = 0;
    uint32_t maxIterations = 100;

    openedList.push_back(begin);
    begin->IsOpened = true;

    while (numIterations == 0 || (current != end && numIterations < maxIterations))
    {
        for (waypointListIterator = openedList.begin(); waypointListIterator != openedList.end(); ++waypointListIterator)
        {
            if (waypointListIterator == openedList.begin() || (*waypointListIterator)->F <= current->F)
            {
                current = (*waypointListIterator);
            }
        }

        if (current == end)
        {
            break;
        }

        openedList.remove(current);
        current->IsOpened = false;

        closedList.push_back(current);
        current->IsClosed = true;

        for (auto& connectIndex : current->ConnectIndexList)
        {
            child = EQAPP_Waypoint_GetByIndex(connectIndex);

            if (child == NULL || child == current || child->IsClosed == true)
            {
                continue;
            }

            if (child->IsOpened == true)
            {
                uint32_t currentGScore = EQAPP_Waypoint_GetGScore(child, current);

                if (child->G > currentGScore)
                {
                    child->Parent = current;
                    EQAPP_Waypoint_ComputeScores(child, end);
                }
            }
            else
            {
                openedList.push_back(child);
                child->IsOpened = true;

                child->Parent = current;
                EQAPP_Waypoint_ComputeScores(child, end);
            }
        }

        numIterations++;
    }

    for (waypointListIterator = openedList.begin(); waypointListIterator != openedList.end(); ++waypointListIterator)
    {
        (*waypointListIterator)->IsOpened = false;
    }

    for (waypointListIterator = closedList.begin(); waypointListIterator != closedList.end(); ++waypointListIterator)
    {
        (*waypointListIterator)->IsClosed = false;
    }

    while (current->Parent != NULL && current != begin)
    {
        indexList.push_back(current->Index);
        current = current->Parent;
        numIterations++;
    }

    indexList.push_back(fromIndex);

    std::reverse(indexList.begin(), indexList.end());

    if (indexList.back() != toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "end waypoint cannot be reached");
        indexList.clear();
        return indexList;
    }

    return indexList;
}

void EQAPP_Waypoint_PrintPathList(EQApp::WaypointIndexList& indexList, uint32_t fromIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    std::cout << "Waypoint Path: ";

    if (indexList.size() == 0)
    {
        std::cout << "No path." << std::endl;
        return;
    }

    std::cout << fromIndex << " -> ";

    for (auto& index : indexList)
    {
        std::cout << index;

        if (index != indexList.back())
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

void EQAPP_WaypointList_Clear()
{
    g_WaypointListUndo = g_WaypointList;

    g_WaypointList.clear();
}

void EQAPP_WaypointList_ClearEx()
{
    g_WaypointList.clear();
}

void EQAPP_WaypointList_Load()
{
    EQAPP_WaypointList_ClearEx();

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    std::stringstream filePath;
    filePath << g_EQAppName << "/waypoints/" << zoneShortName << ".txt";

    std::string filePathStr = filePath.str();

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(line, '^');
        if (tokens.size() == 0)
        {
            continue;
        }

        // index, name, y, x, z, connectIndexList, flags
        if (tokens.size() >= 6)
        {
            EQApp::Waypoint waypoint;

            waypoint.Index = std::stoul(tokens.at(0));
            waypoint.Name  = tokens.at(1);
            waypoint.Y     = std::stof(tokens.at(2));
            waypoint.X     = std::stof(tokens.at(3));
            waypoint.Z     = std::stof(tokens.at(4));

            std::vector<std::string> connections = EQAPP_String_Split(tokens.at(5), ',');
            if (connections.size() != 0)
            {
                if (connections.at(0) != "-1")
                {
                    for (auto& connection : connections)
                    {
                        uint32_t connectIndex = std::stoul(connection);

                        waypoint.ConnectIndexList.push_back(connectIndex);
                    }
                }
            }

            if (tokens.size() > 6)
            {
                waypoint.Flags = std::stoul(tokens.at(6));
            }

            if (tokens.size() > 7)
            {
                waypoint.ScriptFilename = tokens.at(7);
            }

            g_WaypointList.push_back(waypoint);
        }
    }

    std::cout << "Waypoints loaded from file: " << filePathStr << std::endl;

    file.close();
}

void EQAPP_WaypointList_Save()
{
    if (g_WaypointList.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint list is empty");
        return;
    }

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    std::stringstream filePath;
    filePath << g_EQAppName << "/waypoints/" << zoneShortName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    file << "#Index^Name^Y^X^Z^ConnectionList^(Flags)^(ScriptFilename)\n";

    for (auto& waypoint : g_WaypointList)
    {
        fmt::MemoryWriter mw;
        mw << waypoint.Index << "^" << waypoint.Name << "^" << waypoint.Y << "^" << waypoint.X << "^" << waypoint.Z << "^";

        if (waypoint.ConnectIndexList.size() == 0)
        {
            mw << "-1";
        }
        else
        {
            for (auto& connectIndex : waypoint.ConnectIndexList)
            {
                mw << connectIndex;

                if (connectIndex != waypoint.ConnectIndexList.back())
                {
                    mw << ",";
                }
            }
        }

        if (waypoint.Flags != 0)
        {
            mw << "^" << waypoint.Flags;
        }

        if (waypoint.ScriptFilename.size() != 0)
        {
            mw << "^" << waypoint.ScriptFilename;
        }

        file << mw.c_str() << "\n";
    }

    std::cout << "Waypoints saved to file: " << filePathStr << std::endl;

    file.close();
}

void EQAPP_WaypointList_Print()
{
    std::cout << "Waypoint List: " << std::endl;

    if (g_WaypointList.size() == 0)
    {
        std::cout << "No waypoints found." << std::endl;
        return;
    }

    for (auto& waypoint : g_WaypointList)
    {
        std::cout << "Index: " << waypoint.Index << " (Name: " << waypoint.Name << ") (YXZ: " << waypoint.Y << ", " << waypoint.X << ", " << waypoint.Z << ")" << std::endl;
    }
}

void EQAPP_WaypointList_Draw()
{
    if (g_WaypointList.size() == 0)
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

    for (auto& waypoint : g_WaypointList)
    {
        float waypointScreenX = -1.0f;
        float waypointScreenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(waypoint.Y, waypoint.X, waypoint.Z, waypointScreenX, waypointScreenY);
        if (result == true)
        {
            if (g_WaypointEditorHeightFilterIsEnabled == true)
            {
                if (waypoint.Z < playerSpawnZ)
                {
                    if ((playerSpawnZ - waypoint.Z) > g_WaypointEditorHeightFilterDistanceLow)
                    {
                        waypoint.IsDrawn = false;
                        continue;
                    }
                }
                else if (waypoint.Z > playerSpawnZ)
                {
                    if ((waypoint.Z - playerSpawnZ) > g_WaypointEditorHeightFilterDistanceHigh)
                    {
                        waypoint.IsDrawn = false;
                        continue;
                    }
                }
            }

            waypoint.IsDrawn = true;

            fmt::MemoryWriter drawText;
            drawText << "[Waypoint] " << waypoint.Name;

            drawText << "\nIndex: " << waypoint.Index;

            drawText << "\nY: " << waypoint.Y;
            drawText << "\nX: " << waypoint.X;
            drawText << "\nZ: " << waypoint.Z;

            drawText << "\nC: ";

            if (waypoint.ConnectIndexList.size() == 0)
            {
                drawText << "None";
            }
            else
            {
                for (auto& connectIndex : waypoint.ConnectIndexList)
                {
                    drawText << connectIndex;

                    if (connectIndex != waypoint.ConnectIndexList.back())
                    {
                        drawText << ",";
                    }
                }
            }

            if (waypoint.Flags != 0)
            {
                drawText << "\nF: ";

                if (waypoint.Flags & EQApp::WaypointFlags::kJump)
                {
                    drawText << "Jump ";
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kUseDoor)
                {
                    drawText << "UseDoor ";
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kClickToZone)
                {
                    drawText << "ClickToZone ";
                }
            }

            uint32_t textColor = EQ_DRAW_TEXT_COLOR_WHITE;

            if (waypoint.Index == g_WaypointEditorFromIndex)
            {
                textColor = EQ_DRAW_TEXT_COLOR_GREEN;
            }
            else if (waypoint.Index == g_WaypointEditorToIndex)
            {
                textColor = EQ_DRAW_TEXT_COLOR_TEAL;
            }

            auto mouseX = EQ_GetMouseX();
            auto mouseY = EQ_GetMouseY();
            if (EQAPP_WaypointEditor_GetClickedIndex(mouseX, mouseY) == waypoint.Index)
            {
                textColor = EQ_DRAW_TEXT_COLOR_PINK;
            }

            EQ_DrawTextByColor(drawText.c_str(), (int)waypointScreenX, (int)waypointScreenY, textColor);
        }

        for (auto& connectIndex : waypoint.ConnectIndexList)
        {
            auto connectWaypoint = EQAPP_Waypoint_GetByIndex(connectIndex);
            if (connectWaypoint == NULL)
            {
                continue;
            }

            float connectWaypointScreenX = -1.0f;
            float connectWaypointScreenY = -1.0f;
            bool result = EQ_WorldLocationToScreenLocation(connectWaypoint->Y, connectWaypoint->X, connectWaypoint->Z, connectWaypointScreenX, connectWaypointScreenY);
            if (result == true)
            {
                EQ_DrawLine(waypointScreenX, waypointScreenY, connectWaypointScreenX, connectWaypointScreenY, EQ_COLOR_ARGB_WHITE);
            }
        }
    }

        for (auto& it = g_WaypointGetPathIndexList.begin(); it != g_WaypointGetPathIndexList.end(); it++)
        {
            auto waypoint1 = EQAPP_Waypoint_GetByIndex(*it);
            if (waypoint1 == NULL)
            {
                continue;
            }

            auto itLast = std::prev(g_WaypointGetPathIndexList.end());
            if (it == itLast || it == g_WaypointGetPathIndexList.end())
            {
                break;
            }

            auto itNext = std::next(it, 1);

            auto waypoint2 = EQAPP_Waypoint_GetByIndex(*itNext);
            if (waypoint2 == NULL)
            {
                continue;
            }

            float screenX1 = -1.0f;
            float screenY1 = -1.0f;
            bool result1 = EQ_WorldLocationToScreenLocation(waypoint1->Y, waypoint1->X, waypoint1->Z, screenX1, screenY1);

            float screenX2 = -1.0f;
            float screenY2 = -1.0f;
            bool result2 = EQ_WorldLocationToScreenLocation(waypoint2->Y, waypoint2->X, waypoint2->Z, screenX2, screenY2);

            if (result1 == true && result2 == true)
            {
                EQ_DrawLine(screenX1, screenY1, screenX2, screenY2, EQ_COLOR_ARGB_RED);
            }
        }
}

void EQAPP_Waypoint_FollowPath(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to index is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    if (EQ_CanSpawnCastRayToLocation(playerSpawn, fromWaypoint->Y, fromWaypoint->X, fromWaypoint->Z) == true)
    {
        g_WaypointFollowPathIndexList = EQAPP_Waypoint_GetPathList(fromIndex, toIndex);
        if (g_WaypointFollowPathIndexList.size() != 0)
        {
            g_WaypointGetPathIndexList = g_WaypointFollowPathIndexList;

            std::cout << "Following waypoint path from waypoint index " << fromIndex << " to waypoint index " << toIndex << "." << std::endl;

            EQAPP_Waypoint_FollowPath_On();
        }
        else
        {
            std::cout << "No waypoint path can be found from waypoint index " << fromIndex << " to waypoint index " << toIndex << "." << std::endl;
        }
    }
    else
    {
        std::cout << "You cannot see the starting waypoint index " << fromIndex << "." << std::endl;
    }
}

void EQAPP_Waypoint_FollowPathList(EQApp::WaypointIndexList& indexList)
{
    // TODO: look up, down, forward if swimming and waypoints are underwater (going to Veksar, etc)

    if (indexList.size() == 0)
    {
        EQAPP_Waypoint_FollowPath_Off();
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_UseDoorOnCollision();

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto it = indexList.begin(); it != indexList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(*it);
        if (waypoint != NULL)
        {
            float waypointDistance = EQ_CalculateDistance(playerY, playerX, waypoint->Y, waypoint->X);

            if (waypointDistance > g_WaypointFollowPathDistance)
            {
                EQ_TurnSpawnTowardsLocation(playerSpawn, waypoint->Y, waypoint->X);
                EQ_SetAutoRun(true);
                break;
            }
            else
            {
                if (waypoint->Flags & EQApp::WaypointFlags::kStand)
                {
                    EQ_InterpretCommand("/stand");

                    std::cout << "Waypoint Follow Path: Stand" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kDuck)
                {
                    EQ_ExecuteCommand(EQ_EXECUTECMD_DUCK, 1);

                    std::cout << "Waypoint Follow Path: Duck" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kJump)
                {
                    EQ_ExecuteCommand(EQ_EXECUTECMD_JUMP, 1);

                    std::cout << "Waypoint Follow Path: Jump" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kUseDoor)
                {
                    EQ_UseDoorByDistance(g_WaypointUseDoorDistance);

                    std::cout << "Waypoint Follow Path: UseDoor" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorth)
                {
                    EQ_SetPlayerSpawnHeadingNorth();

                    std::cout << "Waypoint Follow Path: FaceNorth" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorthEast)
                {
                    EQ_SetPlayerSpawnHeadingNorthEast();

                    std::cout << "Waypoint Follow Path: FaceNorthEast" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceEast)
                {
                    EQ_SetPlayerSpawnHeadingEast();

                    std::cout << "Waypoint Follow Path: FaceEast" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouthEast)
                {
                    EQ_SetPlayerSpawnHeadingSouthEast();

                    std::cout << "Waypoint Follow Path: FaceSouthEast" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouth)
                {
                    EQ_SetPlayerSpawnHeadingSouth();

                    std::cout << "Waypoint Follow Path: FaceSouth" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouthWest)
                {
                    EQ_SetPlayerSpawnHeadingSouthWest();

                    std::cout << "Waypoint Follow Path: FaceSouthWest" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceWest)
                {
                    EQ_SetPlayerSpawnHeadingWest();

                    std::cout << "Waypoint Follow Path: FaceWest" << std::endl;
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorthWest)
                {
                    EQ_SetPlayerSpawnHeadingNorthWest();

                    std::cout << "Waypoint Follow Path: FaceNorthWest" << std::endl;
                }

                if (waypoint->ScriptFilename.size() != 0)
                {
                    EQAPP_Lua_ExecuteFile(&g_LuaState, waypoint->ScriptFilename.c_str());
                }

                auto itLast = std::prev(indexList.end());
                if (it == itLast)
                {
                    if (waypoint->Flags & EQApp::WaypointFlags::kClickToZone)
                    {
                        for (unsigned int i = 0; i < 10; i++)
                        {
                            EQ_UseDoorByDistance(g_WaypointUseDoorDistance);
                        }

                        std::cout << "Waypoint Follow Path: ClickToZone" << std::endl;
                    }

                    EQAPP_Waypoint_FollowPath_Off();
                    return;
                }

                it = indexList.erase(it);
                it--;
                continue;
            }
        }
    }
}

bool EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1)
    {
        return false;
    }

    if
    (
        commandID == EQ_EXECUTECMD_SIT_STAND  ||
        commandID == EQ_EXECUTECMD_FORWARD    ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        EQAPP_Waypoint_FollowPath_Off();
        return true;
    }

    return false;
}

void EQAPP_WaypointEditor_DrawText()
{
    fmt::MemoryWriter drawText;

    drawText << "WAYPOINT EDITOR\n";
    drawText << "ESCAPE - Reset Selection\n";
    drawText << "LEFT-CLICK - Select Waypoint A\n";
    drawText << "RIGHT-CLICK - Select Waypoint B\n";
    drawText << "CONSIDER - Add\n";
    drawText << "TELL - Add Target\n";
    drawText << "REPLY - Remove\n";
    drawText << "JUMP - Connect\n";
    drawText << "DUCK - Disconnect\n";
    drawText << "AUTO-ATTACK - Align\n";
    drawText << "\n";

    if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull)
    {
        drawText << "From Index: " << g_WaypointEditorFromIndex << "\n";
    }

    if (g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
    {
        drawText << "To Index: " << g_WaypointEditorToIndex << "\n";
    }

    EQ_DrawTextByColor(drawText.str().c_str(), g_WaypointEditorDrawTextX, g_WaypointEditorDrawTextY, EQ_DRAW_TEXT_COLOR_WHITE);
}

uint32_t EQAPP_WaypointEditor_GetClickedIndex(int x, int y)
{
    for (auto& waypoint : g_WaypointList)
    {
        if (waypoint.IsDrawn == false)
        {
            continue;
        }

        float waypointScreenX = -1.0f;
        float waypointScreenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(waypoint.Y, waypoint.X, waypoint.Z, waypointScreenX, waypointScreenY);
        if (result == true)
        {
            int screenX = (int)waypointScreenX;
            int screenY = (int)waypointScreenY;

            if (std::abs(screenX - x) < 25)
            {
                if (std::abs(screenY - y) < 25)
                {
                    return waypoint.Index;
                }
            }
        }
    }

    return EQApp::WaypointIndexNull;
}

bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__LMouseUp(int x, int y)
{
    auto index = EQAPP_WaypointEditor_GetClickedIndex(x, y);
    if (index != EQApp::WaypointIndexNull)
    {
        g_WaypointEditorFromIndex = index;

        if (g_WaypointEditorFromIndex == g_WaypointEditorToIndex)
        {
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;
        }

        return true;
    }

    return false;
}

bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__RMouseUp(int x, int y)
{
    auto index = EQAPP_WaypointEditor_GetClickedIndex(x, y);
    if (index != EQApp::WaypointIndexNull)
    {
        g_WaypointEditorToIndex = index;

        if (g_WaypointEditorToIndex == g_WaypointEditorFromIndex)
        {
            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        }

        return true;
    }

    return false;
}

bool EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1)
    {
        return false;
    }

    if (commandID == EQ_EXECUTECMD_CLEAR_TARGET || commandID == EQ_EXECUTECMD_CLOSE_TOP_WINDOW)
    {
        g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

        return false;
    }

    if (commandID == EQ_EXECUTECMD_JUMP)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull && g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
        {
            EQAPP_Waypoint_Connect(g_WaypointEditorFromIndex, g_WaypointEditorToIndex, false);

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_DUCK)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull && g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
        {
            EQAPP_Waypoint_Disconnect(g_WaypointEditorFromIndex, g_WaypointEditorToIndex, false);

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_CONSIDER)
    {
        EQAPP_Waypoint_AddAtPlayer("");

        g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_TELL)
    {
        EQAPP_Waypoint_AddAtTarget("");

        g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_REPLY)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull)
        {
            EQAPP_Waypoint_Remove(g_WaypointEditorFromIndex);

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_AUTOPRIM)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull && g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
        {
            EQAPP_Waypoint_Align(g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }

    return false;
}
