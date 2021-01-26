#pragma once

extern void EQAPP_FollowAI_StopFollow();

extern bool EQAPP_GUI_IsMouseOver();

namespace EQApp
{
    const char* WaypointMacroFileNameDefault = "_.txt";

    typedef std::vector<uint32_t> WaypointIndexList;

    typedef struct _Waypoint
    {
        uint32_t Index = 0xFFFFFFFF;
        std::string Name; // full name
        float Y;
        float X;
        float Z;
        WaypointIndexList ConnectIndexList;
        uint32_t Flags = 0;
        std::string MacroFileName = WaypointMacroFileNameDefault;
        std::vector<std::string> TagList; // short names

        // editor
        bool IsDrawn = false;

        // A* Star pathfinding algorithm
        bool IsOpened = false;
        bool IsClosed = false;
        uint32_t F = 0;
        uint32_t G = 0;
        uint32_t H = 0;
        struct _Waypoint* Parent = NULL;
    } Waypoint, *Waypoint_ptr;

    typedef std::vector<EQApp::Waypoint> WaypointList;

    uint32_t WaypointIndexNull = 0xFFFFFFFF;

    uint32_t WaypointFlagNull = 0xFFFFFFFF;

    // do not rearrange or you will break compatibility
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
        kWait5Seconds         = 1 << 13,
        kWait10Seconds        = 1 << 14,
        kWait1Minute          = 1 << 15,
    };

    std::unordered_map<uint32_t, std::string> WaypointFlags_Strings =
    {
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
        {WaypointFlags::kWait5Seconds,         "Wait5Seconds"},
        {WaypointFlags::kWait10Seconds,        "Wait10Seconds"},
        {WaypointFlags::kWait1Minute,          "Wait1Minute"},
    };
}

bool g_WaypointIsEnabled = true;

bool g_WaypointEditorIsEnabled = false;

bool g_WaypointEditorHeightFilterIsEnabled = false;

float g_WaypointEditorHeightFilterDistanceLow  = 10.0f;
float g_WaypointEditorHeightFilterDistanceHigh = 10.0f;

bool g_WaypointEditorDistanceFilterIsEnabled = true;

float g_WaypointEditorDistanceFilterDistance = 400.0f;

uint32_t g_WaypointEditorDrawTextX = 600;
uint32_t g_WaypointEditorDrawTextY = 20;

uint32_t g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
uint32_t g_WaypointEditorToIndex   = EQApp::WaypointIndexNull;

uint32_t g_WaypointEditorLastAddedIndex = EQApp::WaypointIndexNull;

uint32_t g_WaypointEditorClickRadius = 25;

bool g_WaypointFollowPathIsEnabled = false;

float g_WaypointFollowPathDistance = 2.0f;

bool g_WaypointFollowPathWaitIsEnabled = false;

EQApp::Timer g_WaypointFollowPathWaitTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_WaypointFollowPathWaitTimerInterval = 5;

uint32_t g_WaypointGetPathListMaxIterations = 4096;

float g_WaypointGotoBySpawnNameDistance = 100.0f;

float g_WaypointUseDoorDistance = 20.0f;

float g_WaypointAddAtTargetDistance = 5.0f;

bool g_WaypointIgnoreWaitIsEnabled = false;

bool g_WaypointIgnoreMovementIsEnabled = false;

EQApp::WaypointList g_WaypointList;

std::list<EQApp::WaypointList> g_WaypointUndoList;
std::list<EQApp::WaypointList> g_WaypointRedoList;

uint32_t g_WaypointUndoCountMax = 100;

EQApp::WaypointIndexList g_WaypointGetPathIndexList;

EQApp::WaypointIndexList g_WaypointFollowPathIndexList;

void EQAPP_WaypointEditor_Reset();
void EQAPP_WaypointEditor_Toggle();
void EQAPP_WaypointEditor_On();
void EQAPP_WaypointEditor_Off();
void EQAPP_WaypointEditor_HeightFilter_Toggle();
void EQAPP_WaypointEditor_HeightFilter_On();
void EQAPP_WaypointEditor_HeightFilter_Off();
void EQAPP_WaypointEditor_DistanceFilter_Toggle();
void EQAPP_WaypointEditor_DistanceFilter_On();
void EQAPP_WaypointEditor_DistanceFilter_Off();
void EQAPP_Waypoint_FollowPath_Toggle();
void EQAPP_Waypoint_FollowPath_On();
void EQAPP_Waypoint_FollowPath_Off();
void EQAPP_Waypoint_IgnoreWait_Toggle();
void EQAPP_Waypoint_IgnoreWait_On();
void EQAPP_Waypoint_IgnoreWait_Off();
void EQAPP_Waypoint_IgnoreMovement_Toggle();
void EQAPP_Waypoint_IgnoreMovement_On();
void EQAPP_Waypoint_IgnoreMovement_Off();
void EQAPP_Waypoint_Undo_AddToList();
void EQAPP_Waypoint_Undo();
void EQAPP_Waypoint_Redo();
void EQAPP_Waypoint_SetName(uint32_t index, const char* name);
void EQAPP_Waypoint_SetMacroFileName(uint32_t index, const char* fileName);
uint32_t  EQAPP_Waypoint_Add(float y, float x, float z, const char* name);
uint32_t  EQAPP_Waypoint_AddAtPlayer(const char* waypointName);
uint32_t  EQAPP_Waypoint_AddAtPlayerAndConnectToLastAddedIndex();
uint32_t  EQAPP_Waypoint_AddAtPlayerBetween(uint32_t fromIndex, uint32_t toIndex);
uint32_t  EQAPP_Waypoint_AddAtTarget(const char* waypointName);
uint32_t  EQAPP_Waypoint_AddAtTargetAndConnectToLastAddedIndex();
uint32_t  EQAPP_Waypoint_AddAtTargetBetween(uint32_t fromIndex, uint32_t toIndex);
uint32_t  EQAPP_Waypoint_AddBehindTarget(const char* waypointName);
uint32_t  EQAPP_Waypoint_AddBehindTargetAndConnectToLastAddedIndex();
uint32_t  EQAPP_Waypoint_Split(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_Remove(uint32_t index);
void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_DisconnectAll(uint32_t index);
bool EQAPP_Waypoint_IsConnected(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_ClearFlags(uint32_t index);
void EQAPP_Waypoint_AddFlag(uint32_t index, uint32_t flag);
void EQAPP_Waypoint_RemoveFlag(uint32_t index, uint32_t flag);
void EQAPP_Waypoint_ClearTags(uint32_t index);
void EQAPP_Waypoint_AddTag(uint32_t index, const char* tagName);
void EQAPP_Waypoint_RemoveTag(uint32_t index, const char* tagName);
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
uint32_t EQAPP_Waypoint_GetIndexNearestToLocationInIndexList(float y, float x, float z, EQApp::WaypointIndexList& indexList);
EQApp::WaypointIndexList EQAPP_Waypoint_GetLineOfSightIndexList();
void EQAPP_Waypoint_RemoveConnectionlessFromIndexList(EQApp::WaypointIndexList& indexList);
uint32_t EQAPP_Waypoint_GetFromIndexForGoto(uint32_t toIndex);
bool EQAPP_Waypoint_Goto(uint32_t toIndex);
void EQAPP_Waypoint_GotoByName(const char* name);
EQApp::WaypointIndexList EQAPP_Waypoint_GetPathIndexList(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PrintPathIndexList(EQApp::WaypointIndexList& indexList, uint32_t fromIndex);
bool EQAPP_Waypoint_FollowPath(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_FollowPathIndexList(EQApp::WaypointIndexList& indexList);
bool EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);
void EQAPP_WaypointList_Clear();
void EQAPP_WaypointList_ClearEx();
void EQAPP_WaypointList_Load();
void EQAPP_WaypointList_Save();
void EQAPP_WaypointList_Print();
void EQAPP_WaypointList_PrintNames();
void EQAPP_WaypointList_Draw();
void EQAPP_WaypointEditor_DrawText();
uint32_t EQAPP_WaypointEditor_GetMouseOverIndex(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__LMouseUp(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_CEverQuest__RMouseUp(int x, int y);
bool EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);
void EQAPP_WaypointEditor_Command_Reset();
void EQAPP_WaypointEditor_Command_Connect();
void EQAPP_WaypointEditor_Command_Disconnect();
void EQAPP_WaypointEditor_Command_DisconnectAll();
void EQAPP_WaypointEditor_Command_AddAtPlayer();
void EQAPP_WaypointEditor_Command_AddAtPlayerAndConnectToLastAddedIndex();
void EQAPP_WaypointEditor_Command_AddAtPlayerBetween();
void EQAPP_WaypointEditor_Command_AddAtTarget();
void EQAPP_WaypointEditor_Command_AddAtTargetBetween();
void EQAPP_WaypointEditor_Command_AddBehindTarget();
void EQAPP_WaypointEditor_Command_Remove();
void EQAPP_WaypointEditor_Command_Align();
void EQAPP_WaypointEditor_Command_Split();
void EQAPP_WaypointEditor_Command_MoveToPlayer();
void EQAPP_WaypointEditor_Command_MoveToTarget();

void EQAPP_WaypointEditor_Reset()
{
    g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
    g_WaypointEditorToIndex   = EQApp::WaypointIndexNull;

    g_WaypointEditorLastAddedIndex = EQApp::WaypointIndexNull;

    g_WaypointUndoList.clear();
    g_WaypointRedoList.clear();

    g_WaypointGetPathIndexList.clear();
    g_WaypointFollowPathIndexList.clear();
}

void EQAPP_WaypointEditor_Toggle()
{
    EQ_ToggleBool(g_WaypointEditorIsEnabled);
    EQAPP_PrintBool("Waypoint Editor", g_WaypointEditorIsEnabled);

    EQAPP_WaypointEditor_Reset();

    if (g_WaypointEditorIsEnabled == false)
    {
        for (auto& waypoint : g_WaypointList)
        {
            waypoint.IsDrawn = false;
        }
    }
}

void EQAPP_WaypointEditor_On()
{
    if (g_WaypointEditorIsEnabled == false)
    {
        EQAPP_WaypointEditor_Toggle();
    }
}

void EQAPP_WaypointEditor_Off()
{
    if (g_WaypointEditorIsEnabled == true)
    {
        EQAPP_WaypointEditor_Toggle();
    }
}

void EQAPP_WaypointEditor_HeightFilter_Toggle()
{
    EQ_ToggleBool(g_WaypointEditorHeightFilterIsEnabled);
    EQAPP_PrintBool("Waypoint Editor Height Filter", g_WaypointEditorHeightFilterIsEnabled);
}

void EQAPP_WaypointEditor_HeightFilter_On()
{
    if (g_WaypointEditorHeightFilterIsEnabled == false)
    {
        EQAPP_WaypointEditor_HeightFilter_Toggle();
    }
}

void EQAPP_WaypointEditor_HeightFilter_Off()
{
    if (g_WaypointEditorHeightFilterIsEnabled == true)
    {
        EQAPP_WaypointEditor_HeightFilter_Toggle();
    }
}

void EQAPP_WaypointEditor_DistanceFilter_Toggle()
{
    EQ_ToggleBool(g_WaypointEditorDistanceFilterIsEnabled);
    EQAPP_PrintBool("Waypoint Editor Distance Filter", g_WaypointEditorDistanceFilterIsEnabled);
}

void EQAPP_WaypointEditor_DistanceFilter_On()
{
    if (g_WaypointEditorDistanceFilterIsEnabled == false)
    {
        EQAPP_WaypointEditor_DistanceFilter_Toggle();
    }
}

void EQAPP_WaypointEditor_DistanceFilter_Off()
{
    if (g_WaypointEditorDistanceFilterIsEnabled == true)
    {
        EQAPP_WaypointEditor_DistanceFilter_Toggle();
    }
}

void EQAPP_Waypoint_FollowPath_Toggle()
{
    EQ_ToggleBool(g_WaypointFollowPathIsEnabled);
    EQAPP_PrintBool("Waypoint Follow Path", g_WaypointFollowPathIsEnabled);

    g_WaypointFollowPathWaitIsEnabled = false;

    if (g_WaypointFollowPathIsEnabled == true)
    {
        EQ_StopFollow();

        EQAPP_FollowAI_StopFollow();

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

void EQAPP_Waypoint_IgnoreWait_Toggle()
{
    EQ_ToggleBool(g_WaypointIgnoreWaitIsEnabled);
    EQAPP_PrintBool("Waypoint Ignore Wait", g_WaypointIgnoreWaitIsEnabled);

    g_WaypointFollowPathWaitIsEnabled = false;
}

void EQAPP_Waypoint_IgnoreWait_On()
{
    if (g_WaypointIgnoreWaitIsEnabled == false)
    {
        EQAPP_Waypoint_IgnoreWait_Toggle();
    }
}

void EQAPP_Waypoint_IgnoreWait_Off()
{
    if (g_WaypointIgnoreWaitIsEnabled == true)
    {
        EQAPP_Waypoint_IgnoreWait_Toggle();
    }
}

void EQAPP_Waypoint_IgnoreMovement_Toggle()
{
    EQ_ToggleBool(g_WaypointIgnoreMovementIsEnabled);
    EQAPP_PrintBool("Waypoint Ignore Movement", g_WaypointIgnoreMovementIsEnabled);

    g_WaypointFollowPathWaitIsEnabled = false;
}

void EQAPP_Waypoint_IgnoreMovement_On()
{
    if (g_WaypointIgnoreMovementIsEnabled == false)
    {
        EQAPP_Waypoint_IgnoreMovement_Toggle();
    }
}

void EQAPP_Waypoint_IgnoreMovement_Off()
{
    if (g_WaypointIgnoreMovementIsEnabled == true)
    {
        EQAPP_Waypoint_IgnoreMovement_Toggle();
    }
}

void EQAPP_Waypoint_Undo_AddToList()
{
    if (g_WaypointUndoList.size() >= g_WaypointUndoCountMax)
    {
        g_WaypointUndoList.pop_front();
    }

    g_WaypointUndoList.push_back(g_WaypointList);
    g_WaypointRedoList.clear();

    //std::cout << "Undo list size: " << g_WaypointUndoList.size() << "\n";
    //std::cout << "Redo list size: " << g_WaypointRedoList.size() << "\n";
}

void EQAPP_Waypoint_Undo()
{
    if (g_WaypointUndoList.empty() == true)
    {
        std::cout << "Waypoint undo list is empty.\n";
        return;
    }

    g_WaypointRedoList.push_back(g_WaypointList);

    g_WaypointList = g_WaypointUndoList.back();

    g_WaypointUndoList.pop_back();

    //std::cout << "Undo list size: " << g_WaypointUndoList.size() << "\n";
    //std::cout << "Redo list size: " << g_WaypointRedoList.size() << "\n";
}

void EQAPP_Waypoint_Redo()
{
    if (g_WaypointRedoList.empty() == true)
    {
        std::cout << "Waypoint redo list is empty.\n";
        return;
    }

    g_WaypointUndoList.push_back(g_WaypointList);

    g_WaypointList = g_WaypointRedoList.back();

    g_WaypointRedoList.pop_back();

    //std::cout << "Undo list size: " << g_WaypointUndoList.size() << "\n";
    //std::cout << "Redo list size: " << g_WaypointRedoList.size() << "\n";
}

void EQAPP_Waypoint_SetName(uint32_t index, const char* name)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    if (EQAPP_String_IsAlphaNumericWithSpaces(name) == false)
    {
        std::cout << fmt::format("Name '{}' contains illegal characters, must be letters and numbers only.\n", name);
        return;
    }

    waypoint->Name = name;

    std::cout << fmt::format("Waypoint index '{}' name to set '{}'.\n", waypoint->Index, name);
}

void EQAPP_Waypoint_SetMacroFileName(uint32_t index, const char* fileName)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    if (EQAPP_String_IsAlphaNumericWithSpaces(fileName) == false)
    {
        std::cout << fmt::format("Macro file name '{}' contains illegal characters, must be letters and numbers only.\n", fileName);
        return;
    }

    waypoint->MacroFileName = fileName;

    std::cout << fmt::format("Waypoint index '{}' macro file name to set '{}'.\n", waypoint->Index, fileName);
}

uint32_t EQAPP_Waypoint_Add(float y, float x, float z, const char* name)
{
    EQAPP_Waypoint_Undo_AddToList();

    uint32_t index = 0;

    if (g_WaypointList.empty() == false)
    {
        index = g_WaypointList.at(0).Index;
    }

    // assign an index value by incrementing by 1 until we find an index that does not already exist
    for (auto waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if ((*waypoint_it).Index == index)
        {
            index++;

            waypoint_it = g_WaypointList.begin();
        }
    }

    bool bIsNameAlphaAndDigits = EQAPP_String_IsAlphaNumericWithSpaces(name);
    if (bIsNameAlphaAndDigits == false)
    {
        std::cout << fmt::format("Waypoint name '{}' contains illegal characters, must be letters and numbers only.\n", name);

        std::cout << "Falling back to default waypoint name.\n";
    }

    std::string waypointName = std::string();

    if (strlen(name) == 0 || bIsNameAlphaAndDigits == false)
    {
        waypointName = fmt::format("Waypoint{}", index);
    }
    else
    {
        waypointName = name;
    }

    EQApp::Waypoint waypoint;
    waypoint.Index = index;
    waypoint.Y = y;
    waypoint.X = x;
    waypoint.Z = z;
    waypoint.Name = waypointName;

    g_WaypointList.push_back(waypoint);

    std::cout << fmt::format("Waypoint index '{}' added.\n", index);

    g_WaypointEditorLastAddedIndex = index;

    return index;
}

uint32_t EQAPP_Waypoint_AddAtPlayer(const char* waypointName)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return EQApp::WaypointIndexNull;
    }

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    return EQAPP_Waypoint_Add(playerY, playerX, playerZ, waypointName);
}

uint32_t EQAPP_Waypoint_AddAtPlayerAndConnectToLastAddedIndex()
{
    auto lastAddedIndex = g_WaypointEditorLastAddedIndex;

    if (lastAddedIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "lastAddedIndex is null");
        return EQApp::WaypointIndexNull;
    }

    auto index = EQAPP_Waypoint_AddAtPlayer("");

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(index, lastAddedIndex, false);

    return index;
}

uint32_t EQAPP_Waypoint_AddAtPlayerBetween(uint32_t fromIndex, uint32_t toIndex)
{
    EQAPP_Waypoint_Disconnect(fromIndex, toIndex, false);

    auto betweenIndex = EQAPP_Waypoint_AddAtPlayer("");

    if (betweenIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "betweenIndex is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(fromIndex, betweenIndex, false);
    EQAPP_Waypoint_Connect(betweenIndex, toIndex, false);

    return betweenIndex;
}

uint32_t EQAPP_Waypoint_AddAtTarget(const char* waypointName)
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return EQApp::WaypointIndexNull;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    float heading = EQ_GetSpawnHeading(targetSpawn);

    EQ_ApplyForwardMovement(targetY, targetX, heading, g_WaypointAddAtTargetDistance);

    auto index = EQAPP_Waypoint_Add(targetY, targetX, targetZ, waypointName);

    EQ_ClearTarget();

    return index;
}

uint32_t EQAPP_Waypoint_AddAtTargetAndConnectToLastAddedIndex()
{
    auto lastAddedIndex = g_WaypointEditorLastAddedIndex;

    if (lastAddedIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "lastAddedIndex is null");
        return EQApp::WaypointIndexNull;
    }

    auto index = EQAPP_Waypoint_AddAtTarget("");

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(index, lastAddedIndex, false);

    return index;
}

uint32_t EQAPP_Waypoint_AddBehindTarget(const char* waypointName)
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return EQApp::WaypointIndexNull;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    float heading = EQ_GetSpawnHeading(targetSpawn);

    EQ_ApplyBackwardMovement(targetY, targetX, heading, g_WaypointAddAtTargetDistance);

    auto index = EQAPP_Waypoint_Add(targetY, targetX, targetZ, waypointName);

    EQ_ClearTarget();

    return index;
}

uint32_t EQAPP_Waypoint_AddBehindTargetAndConnectToLastAddedIndex()
{
    auto lastAddedIndex = g_WaypointEditorLastAddedIndex;

    if (lastAddedIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "lastAddedIndex is null");
        return EQApp::WaypointIndexNull;
    }

    auto index = EQAPP_Waypoint_AddBehindTarget("");

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(index, lastAddedIndex, false);

    return index;
}

uint32_t EQAPP_Waypoint_AddAtTargetBetween(uint32_t fromIndex, uint32_t toIndex)
{
    EQAPP_Waypoint_Disconnect(fromIndex, toIndex, false);

    auto betweenIndex = EQAPP_Waypoint_AddAtTarget("");

    if (betweenIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "betweenIndex is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(fromIndex, betweenIndex, false);
    EQAPP_Waypoint_Connect(betweenIndex, toIndex, false);

    return betweenIndex;
}

uint32_t EQAPP_Waypoint_Split(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return EQApp::WaypointIndexNull;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return EQApp::WaypointIndexNull;
    }

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex and toIndex are the same");
        return EQApp::WaypointIndexNull;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return EQApp::WaypointIndexNull;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Disconnect(fromIndex, toIndex, false);

    float splitY = std::midpoint(fromWaypoint->Y, toWaypoint->Y);
    float splitX = std::midpoint(fromWaypoint->X, toWaypoint->X);
    float splitZ = std::midpoint(fromWaypoint->Z, toWaypoint->Z);

    auto betweenIndex = EQAPP_Waypoint_Add(splitY, splitX, splitZ, "");

    if (betweenIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "betweenIndex is null");
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_Connect(fromIndex, betweenIndex, false);
    EQAPP_Waypoint_Connect(betweenIndex, toIndex, false);

    return betweenIndex;
}

void EQAPP_Waypoint_Remove(uint32_t index)
{
    EQAPP_Waypoint_Undo_AddToList();

    if (index == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "index is null");
        return;
    }

    if (g_WaypointList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "g_WaypointList is empty");
        return;
    }

    auto numErased = std::erase_if
    (
        g_WaypointList,
    [index](const EQApp::Waypoint& waypoint) -> bool
        {
            if (waypoint.Index == index)
            {
                std::cout << fmt::format("Waypoint index '{}' removed.\n", index);
                return true;
            }

            return false;
        }
    );

    for (auto& waypoint : g_WaypointList)
    {
        auto numErased = std::erase_if
        (
            waypoint.ConnectIndexList,
        [index, waypoint](uint32_t connectIndex) -> bool
            {
                if (connectIndex == index)
                {
                    std::cout << fmt::format("Waypoint index '{}' disconnected from waypoint index '{}'.\n", waypoint.Index, connectIndex);
                    return true;
                }

                return false;
            }
        );
    }
}

void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    EQAPP_Waypoint_Undo_AddToList();

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex and toIndex are the same");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return;
    }

    std::string connectAlreadyExists = fmt::format("Waypoint connection already exists from index '{}' to index '{}'.\n", fromIndex, toIndex);

    for (auto& connectIndex : fromWaypoint->ConnectIndexList)
    {
        if (connectIndex == toIndex)
        {
            std::cout << connectAlreadyExists;
            return;
        }
    }

    fromWaypoint->ConnectIndexList.push_back(toIndex);

    std::cout << fmt::format("Waypoint index '{}' connected to waypoint index '{}'.\n", fromIndex, toIndex);

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex : toWaypoint->ConnectIndexList)
        {
            if (connectIndex == fromIndex)
            {
                std::cout << connectAlreadyExists;
                return;
            }
        }

        toWaypoint->ConnectIndexList.push_back(fromIndex);

        std::cout << fmt::format("Waypoint index '{}' connected to waypoint index '{}'.\n", toIndex, fromIndex);
    }
}

void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    EQAPP_Waypoint_Undo_AddToList();

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex and toIndex are the same");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return;
    }

    auto numErased = std::erase_if
    (
        fromWaypoint->ConnectIndexList,
    [fromIndex, toIndex](uint32_t connectIndex) -> bool
        {
            if (connectIndex == toIndex)
            {
                std::cout << fmt::format("Waypoint index '{}' disconnected from waypoint index '{}'.\n", fromIndex, toIndex);
                return true;
            }

            return false;
        }
    );

    if (bOneWayConnection == false)
    {
        auto numErased = std::erase_if
        (
            toWaypoint->ConnectIndexList,
        [toIndex, fromIndex](uint32_t connectIndex) -> bool
            {
                if (connectIndex == fromIndex)
                {
                    std::cout << fmt::format("Waypoint index '{}' disconnected from waypoint index '{}'.\n", toIndex, fromIndex);
                    return true;
                }

                return false;
            }
        );
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
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return false;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return false;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
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
    EQAPP_Waypoint_Undo_AddToList();

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

    std::cout << fmt::format("Waypoint index '{}' flags cleared.\n", waypoint->Index);
}

void EQAPP_Waypoint_AddFlag(uint32_t index, uint32_t flag)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    std::string flagName = EQApp::WaypointFlags_Strings[flag];
    if (flagName.empty() == false)
    {
        std::cout << fmt::format("Waypoint index '{}' added flag '{}'.\n", waypoint->Index, flagName);
    }
}

void EQAPP_Waypoint_RemoveFlag(uint32_t index, uint32_t flag)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    std::string flagName = EQApp::WaypointFlags_Strings[flag];
    if (flagName.empty() == false)
    {
        std::cout << fmt::format("Waypoint index '{}' removed flag '{}'.\n", waypoint->Index, flagName);
    }
}

void EQAPP_Waypoint_ClearTags(uint32_t index)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    waypoint->TagList.clear();

    std::cout << fmt::format("Waypoint index '{}' tags cleared.\n", waypoint->Index);
}

void EQAPP_Waypoint_AddTag(uint32_t index, const char* tagName)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    if (tagName == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "tagName is null");
        return;
    }

    bool bAlreadyExists = std::find
    (
        waypoint->TagList.begin(), waypoint->TagList.end(),
        tagName
    ) != waypoint->TagList.end();

    if (bAlreadyExists == true)
    {
        std::cout << fmt::format("Waypoint index '{}' already has tag '{}'.\n", waypoint->Index, tagName);
        return;
    }

    bool bIsAlphaAndDigits = EQAPP_String_IsAlphaNumericWithSpaces(tagName);
    if (bIsAlphaAndDigits == false)
    {
        std::cout << fmt::format("Tag '{}' contains illegal characters, must be letters and numbers only.\n", tagName);
        return;
    }

    waypoint->TagList.push_back(tagName);

    std::cout << fmt::format("Waypoint index '{}' added tag '{}'.\n", waypoint->Index, tagName);
}

void EQAPP_Waypoint_RemoveTag(uint32_t index, const char* tagName)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    if (tagName == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "tagName is null");
        return;
    }

    auto numErased = std::erase_if
    (
        waypoint->TagList,
        [index, tagName](const std::string& tag) -> bool
        {
            if (tag == tagName)
            {
                std::cout << fmt::format("Waypoint index '{}' removed tag '{}'.\n", index, tagName);

                return true;
            }

            return false;
        }
    );
}

void EQAPP_Waypoint_Align(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
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
    EQAPP_Waypoint_Undo_AddToList();

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return;
    }

    fromWaypoint->Y = toWaypoint->Y;

    std::cout << fmt::format("Waypoint index '{}' aligned with waypoint index '{}' on the Y-Axis.\n", fromIndex, toIndex);
}

void EQAPP_Waypoint_AlignX(uint32_t fromIndex, uint32_t toIndex)
{
    EQAPP_Waypoint_Undo_AddToList();

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return;
    }

    fromWaypoint->X = toWaypoint->X;

    std::cout << fmt::format("Waypoint index '{}' aligned with waypoint index '{}' on the X-Axis.\n", fromIndex, toIndex);
}

void EQAPP_Waypoint_AlignZ(uint32_t fromIndex, uint32_t toIndex)
{
    EQAPP_Waypoint_Undo_AddToList();

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return;
    }

    auto toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toWaypoint is null");
        return;
    }

    fromWaypoint->Z = toWaypoint->Z;

    std::cout << fmt::format("Waypoint index '{}' aligned with waypoint index '{}' on the Z-Axis.\n", fromIndex, toIndex);
}

void EQAPP_Waypoint_PushAwayFromPlayer(uint32_t index, float distance, bool roundToNearestDirection)
{
    EQAPP_Waypoint_Undo_AddToList();

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
        EQAPP_PrintDebugText(__FUNCTION__, "playerSpawn is null");
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

    EQ_ApplyForwardMovement(waypoint->Y, waypoint->X, playerHeading, distance);

    std::cout << fmt::format("Waypoint index '{}' pushed '{}' distance.\n", index, distance);
}

void EQAPP_Waypoint_PullTowardsPlayer(uint32_t index, float distance, bool roundToNearestDirection)
{
    EQAPP_Waypoint_Undo_AddToList();

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
        EQAPP_PrintDebugText(__FUNCTION__, "playerSpawn is null");
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

    EQ_ApplyBackwardMovement(waypoint->Y, waypoint->X, playerHeading, distance);

    std::cout << fmt::format("Waypoint index '{}' pulled '{}' distance.\n", index, distance);
}

void EQAPP_Waypoint_MoveToLocation(uint32_t index, float y, float x, float z)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    std::cout << fmt::format("Waypoint index '{}' moved to location '{}', '{}', '{}'.\n", index, y, x, z);
}

void EQAPP_Waypoint_MoveToPlayer(uint32_t index)
{
    EQAPP_Waypoint_Undo_AddToList();

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
        EQAPP_PrintDebugText(__FUNCTION__, "playerSpawn is null");
        return;
    }

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    waypoint->Y = playerY;
    waypoint->X = playerX;
    waypoint->Z = playerZ;

    std::cout << fmt::format("Waypoint index '{}' moved to player.", index);
}

void EQAPP_Waypoint_MoveToTarget(uint32_t index)
{
    EQAPP_Waypoint_Undo_AddToList();

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
        EQAPP_PrintDebugText(__FUNCTION__, "targetSpawn is null");
        return;
    }

    auto targetY = EQ_GetSpawnY(targetSpawn);
    auto targetX = EQ_GetSpawnX(targetSpawn);
    auto targetZ = EQ_GetSpawnZ(targetSpawn);

    waypoint->Y = targetY;
    waypoint->X = targetX;
    waypoint->Z = targetZ;

    std::cout << fmt::format("Waypoint index '{}' moved to target.", index);
}

void EQAPP_Waypoint_MoveUp(uint32_t index, float distance)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    std::cout << fmt::format("Waypoint index '{}' moved up '{}' distance.\n", index, distance);
}

void EQAPP_Waypoint_MoveDown(uint32_t index, float distance)
{
    EQAPP_Waypoint_Undo_AddToList();

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

    std::cout << fmt::format("Waypoint index '{}' moved down '{}' distance.\n", index, distance);
}

uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    // TODO: insert optimizations here

    uint32_t score = waypoint1->G;

    score = score + 1;

    return score;
}

uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    // manhattan distance
    //uint32_t score = (uint32_t)(std::fabsf(waypoint1->X - waypoint2->X) + std::fabsf(waypoint1->Y - waypoint2->Y) * 10);

    // euclidean distance
    uint32_t score = (uint32_t)
    (
        std::sqrtf
        (
            std::powf(waypoint2->X - waypoint1->X, 2) + 
            std::powf(waypoint2->Y - waypoint1->Y, 2) +
            std::powf(waypoint2->Z - waypoint1->Z, 2)
        )
    );

    score = score + 1;

    return score;
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

    std::string debugText = fmt::format("index '{}' not found", index);

    EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());

    return NULL;
}

uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z)
{
    if (g_WaypointList.empty() == true)
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

uint32_t EQAPP_Waypoint_GetIndexNearestToLocationInIndexList(float y, float x, float z, EQApp::WaypointIndexList& indexList)
{
    std::map<float, uint32_t> distanceList;

    for (auto& index : indexList)
    {
        if (index == EQApp::WaypointIndexNull)
        {
            continue;
        }

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

EQApp::WaypointIndexList EQAPP_Waypoint_GetLineOfSightIndexList()
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

void EQAPP_Waypoint_RemoveConnectionlessFromIndexList(EQApp::WaypointIndexList& indexList)
{
/*
    for (auto it = indexList.begin(); it != indexList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(*it);
        if (waypoint == NULL)
        {
            continue;
        }

        if (waypoint->ConnectIndexList.empty() == true)
        {
            it = indexList.erase(it);
            it--;
            continue;
        }
    }
*/

    auto numErased = std::erase_if
    (
        indexList,
    [](uint32_t index) -> bool
        {
            auto waypoint = EQAPP_Waypoint_GetByIndex(index);
            if (waypoint != NULL)
            {
                if (waypoint->ConnectIndexList.empty() == true)
                {
                    return true;
                }
            }

            return false;
        }
    );
}

uint32_t EQAPP_Waypoint_GetFromIndexForGoto(uint32_t toIndex)
{
    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return EQApp::WaypointIndexNull;
    }

    auto indexList = EQAPP_Waypoint_GetLineOfSightIndexList();
    if (indexList.empty() == true)
    {
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_RemoveConnectionlessFromIndexList(indexList);

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

/*
    for (auto it = distanceList.begin(); it != distanceList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(it->second);
        if (waypoint == NULL)
        {
            continue;
        }

        auto pathIndexList = EQAPP_Waypoint_GetPathIndexList(waypoint->Index, toIndex);
        if (pathIndexList.empty() == true)
        {
            it = distanceList.erase(it);
            it--;
            continue;
        }
    }
*/

    auto numErased = std::erase_if
    (
        distanceList,
    [toIndex](const std::pair<float, uint32_t>& distancePair) -> bool
        {
            auto index = distancePair.second;

            auto waypoint = EQAPP_Waypoint_GetByIndex(index);
            if (waypoint != NULL)
            {
                auto pathIndexList = EQAPP_Waypoint_GetPathIndexList(waypoint->Index, toIndex);
                if (pathIndexList.empty() == true)
                {
                    return true;
                }
            }

            return false;
        }
    );

    if (distanceList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "distanceList is empty");
        return EQApp::WaypointIndexNull;
    }

    return distanceList.begin()->second;
}

bool EQAPP_Waypoint_Goto(uint32_t toIndex)
{
    uint32_t fromIndex = EQAPP_Waypoint_GetFromIndexForGoto(toIndex);
    if (fromIndex == EQApp::WaypointIndexNull || toIndex == EQApp::WaypointIndexNull)
    {
        std::cout << "No waypoint path can be found using goto.\n";

        return false;
    }
    else
    {
        bool result = EQAPP_Waypoint_FollowPath(fromIndex, toIndex);
        if (result == false)
        {
            return false;
        }
    }

    return true;
}

void EQAPP_Waypoint_GotoByName(const char* name)
{
    std::cout << fmt::format("Waypoint goto by name '{}'.\n", name);

    uint32_t toIndex = EQApp::WaypointIndexNull;

    EQApp::WaypointIndexList indexList;

    bool bFoundByWaypointName = false;

    for (auto& waypoint : g_WaypointList)
    {
        if (waypoint.Name == name)
        {
            indexList.push_back(waypoint.Index);

            std::cout << fmt::format("Waypoint index '{}' found with name '{}'.\n", waypoint.Index, waypoint.Name);

            bFoundByWaypointName = true;
        }
    }

    // use tags if name cannot be found
    if (bFoundByWaypointName == false)
    {
        for (auto& waypoint : g_WaypointList)
        {
            for (auto& tagName : waypoint.TagList)
            {
                if (tagName == name)
                {
                    indexList.push_back(waypoint.Index);

                    std::cout << fmt::format("Waypoint index '{}' found with tag name '{}'.\n", waypoint.Index, tagName);
                }
            }
        }
    }

    if (indexList.empty() == true)
    {
        std::cout << fmt::format("Waypoint with name '{}' not found.\n", name);
        return;
    }

    if (indexList.size() == 1)
    {
        toIndex = indexList.at(0);
    }
    else if (indexList.size() > 1)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto playerY = EQ_GetSpawnY(playerSpawn);
            auto playerX = EQ_GetSpawnX(playerSpawn);
            auto playerZ = EQ_GetSpawnZ(playerSpawn);

            toIndex = EQAPP_Waypoint_GetIndexNearestToLocationInIndexList(playerY, playerX, playerZ, indexList);

            std::cout << fmt::format("Waypoint nearest to player is index '{}'.\n", toIndex);
        }
    }

    bool result = EQAPP_Waypoint_Goto(toIndex);
    if (result == false)
    {
        std::cout << fmt::format("Waypoint goto by name has failed using index '{}'.\n", toIndex);

        std::cout << "Attempting to find an alternate route...\n";

        bool bFoundAlternateRoute = false;

        for (auto& index : indexList)
        {
            bool result2 = EQAPP_Waypoint_Goto(index);
            if (result2 == true)
            {
                std::cout << fmt::format("Alternate route found using waypoint index '{}'.\n", index);

                bFoundAlternateRoute = true;

                break;
            }
        }

        if (bFoundAlternateRoute == false)
        {
            std::cout << "Failed to find an alternate route!\n";
        }
    }
}

void EQAPP_Waypoint_GotoBySpawnName(const char* spawnName)
{
    if (spawnName == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "spawnName is null");
        return;
    }

    std::cout << fmt::format("Waypoint goto by spawn name '{}'.\n", spawnName);

    uint32_t toIndex = EQApp::WaypointIndexNull;

    EQApp::WaypointIndexList indexList;

    for (auto& waypoint : g_WaypointList)
    {
        if (waypoint.Index == EQApp::WaypointIndexNull)
        {
            continue;
        }

        indexList.push_back(waypoint.Index);
    }

    if (indexList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "indexList is empty");
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "playerSpawn is null");
        return;
    }

    auto playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "playerName is empty");
        return;
    }

    auto spawnList = EQ_GetSpawnList();
    if (spawnList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "spawnList is empty");
        return;
    }

    for (auto& spawn : spawnList)
    {
        auto spawnListName = EQ_GetSpawnName(spawn);

        if (spawnListName.empty() == true)
        {
            continue;
        }

        if (spawnListName == playerName)
        {
            continue;
        }

        if (spawnListName == spawnName)
        {
            auto spawnY = EQ_GetSpawnY(spawn);
            auto spawnX = EQ_GetSpawnX(spawn);
            auto spawnZ = EQ_GetSpawnZ(spawn);

            toIndex = EQAPP_Waypoint_GetIndexNearestToLocationInIndexList(spawnY, spawnX, spawnZ, indexList);

            std::cout << fmt::format("Waypoint nearest to '{}' is '{}'.\n", spawnName, toIndex);

            auto waypoint = EQAPP_Waypoint_GetByIndex(toIndex);
            if (waypoint != NULL)
            {
                float waypointDistance = EQ_CalculateDistance3D(spawnY, spawnX, spawnZ, waypoint->Y, waypoint->X, waypoint->Z);

                if (waypointDistance > g_WaypointGotoBySpawnNameDistance)
                {
                    std::cout << fmt::format("Waypoint index '{}' is too far away from '{}'.\n", toIndex, spawnName);
                    return;
                }

                if (EQ_CanSpawnCastRayToLocation(spawn, waypoint->Y, waypoint->X, waypoint->Z) == false)
                {
                    std::cout << fmt::format("Waypoint index '{}' cannot be seen by '{}'.\n", toIndex, spawnName);
                    return;
                }
            }

            break;
        }
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        std::cout << fmt::format("Waypoint goto by spawn name has failed because waypoint index '{}' is null.\n", toIndex);
        return;
    }

    bool result = EQAPP_Waypoint_Goto(toIndex);
    if (result == false)
    {
        std::cout << fmt::format("Waypoint goto by spawn name has failed using waypoint index '{}'\n", toIndex);
    }
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetPathIndexList(uint32_t fromIndex, uint32_t toIndex)
{
    EQApp::WaypointIndexList indexList;

    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return indexList;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return indexList;
    }

    // do not check if fromIndex and toIndex are the same or this function will not work
    //if (fromIndex == toIndex)

    auto begin = EQAPP_Waypoint_GetByIndex(fromIndex);
    auto end   = EQAPP_Waypoint_GetByIndex(toIndex);

    if (begin == NULL || end == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "begin or end waypoint is null");
        return indexList;
    }

    if (begin->ConnectIndexList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "begin waypoint has no connections");
        return indexList;
    }

    // there may be a one way connection to the end
    //if (end->ConnectIndexList.empty() == true)
    
    EQApp::Waypoint_ptr current = NULL;
    EQApp::Waypoint_ptr child = NULL;

    std::list<EQApp::Waypoint_ptr> openedList;
    std::list<EQApp::Waypoint_ptr> closedList;

    uint32_t numIterations = 0;
    uint32_t maxIterations = g_WaypointGetPathListMaxIterations;

    openedList.push_back(begin);
    begin->IsOpened = true;

    while (numIterations == 0 || (current != end && numIterations < maxIterations))
    {
        for (auto waypoint_it = openedList.begin(); waypoint_it != openedList.end(); waypoint_it++)
        {
            if (waypoint_it == openedList.begin() || (*waypoint_it)->F <= current->F)
            {
                current = (*waypoint_it);
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

    for (auto& waypoint : openedList)
    {
        waypoint->IsOpened = false;
    }

    for (auto& waypoint : closedList)
    {
        waypoint->IsClosed = false;
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
        std::cout << fmt::format("{}() has failed because a path to the end waypoint cannot be found.\n", __FUNCTION__);
        std::cout << fmt::format("End waypoint index is '{}'.\n", toIndex);
        std::cout << fmt::format("Last found waypoint index is '{}'.\n", indexList.back());

        EQAPP_PrintDebugText(__FUNCTION__, "end waypoint cannot be found");

        indexList.clear();

        return indexList;
    }

    return indexList;
}

void EQAPP_Waypoint_PrintPathIndexList(EQApp::WaypointIndexList& indexList, uint32_t fromIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return;
    }

    std::cout << "Waypoint Path: ";

    if (indexList.empty() == true)
    {
        std::cout << "No path.\n";
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

    std::cout << "\n";
}

void EQAPP_WaypointList_Clear()
{
    EQAPP_Waypoint_Undo_AddToList();

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
    if (zoneShortName.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zoneShortName is null");
        return;
    }

    std::string filePath = fmt::format("{}/waypoints/{}.txt", g_EQAppName, zoneShortName);

    std::ifstream file;
    file.open(filePath.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::string debugText = fmt::format("failed to open file: {}", filePath);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() == true)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        std::vector<std::string> tokenList = EQAPP_String_Split(line, '^');
        if (tokenList.empty() == true)
        {
            continue;
        }

        // index, name, y, x, z, connectIndexList, flags, macroFileName, tagList
        if (tokenList.size() >= 6)
        {
            EQApp::Waypoint waypoint;

            waypoint.Index = std::stoul(tokenList.at(0));
            waypoint.Name  = tokenList.at(1);
            waypoint.Y     = std::stof(tokenList.at(2));
            waypoint.X     = std::stof(tokenList.at(3));
            waypoint.Z     = std::stof(tokenList.at(4));

            std::vector<std::string> connectionList = EQAPP_String_Split(tokenList.at(5), ',');
            if (connectionList.empty() == false)
            {
                if (connectionList.at(0) != "-1")
                {
                    for (auto& connection : connectionList)
                    {
                        uint32_t connectIndex = std::stoul(connection);

                        waypoint.ConnectIndexList.push_back(connectIndex);
                    }
                }
            }

            if (tokenList.size() > 6)
            {
                waypoint.Flags = std::stoul(tokenList.at(6));
            }

            if (tokenList.size() > 7)
            {
                waypoint.MacroFileName = tokenList.at(7);
            }

            if (tokenList.size() > 8)
            {
                std::vector<std::string> tagList = EQAPP_String_Split(tokenList.at(8), ',');

                auto numErased = std::erase_if
                (
                    tagList,
                    [](const std::string& tagName) -> bool
                    {
                        return tagName == "_";
                    }
                );

                waypoint.TagList = tagList;
            }

            g_WaypointList.push_back(waypoint);
        }
    }

    std::cout << fmt::format("Waypoints loaded from file: {}\n", filePath);

    file.close();
}

void EQAPP_WaypointList_Save()
{
    if (g_WaypointList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "g_WaypointList is empty");
        return;
    }

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zoneShortName is null");
        return;
    }

    std::string filePath = fmt::format("{}/waypoints/{}.txt", g_EQAppName, zoneShortName);

    std::fstream file;
    file.open(filePath.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::string debugText = fmt::format("failed to open file: {}", filePath);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    file << "#Index^Name^Y^X^Z^ConnectionList^Flags^MacroFileName^TagList\n";

    for (auto& waypoint : g_WaypointList)
    {
        std::stringstream ss;
        ss << waypoint.Index << "^" << waypoint.Name << "^" << waypoint.Y << "^" << waypoint.X << "^" << waypoint.Z << "^";

        if (waypoint.ConnectIndexList.empty() == true)
        {
            ss << "-1";
        }
        else
        {
            for (auto& connectIndex : waypoint.ConnectIndexList)
            {
                ss << connectIndex;

                if (connectIndex != waypoint.ConnectIndexList.back())
                {
                    ss << ",";
                }
            }
        }

        ss << "^" << waypoint.Flags;

        if (waypoint.MacroFileName.empty() == true)
        {
            ss << "^" << EQApp::WaypointMacroFileNameDefault;
        }
        else
        {
            ss << "^" << waypoint.MacroFileName;
        }

        ss << "^";

        if (waypoint.TagList.empty() == true)
        {
            ss << "_";
        }
        else
        {
            for (auto& tag : waypoint.TagList)
            {
                if (tag.empty() == true)
                {
                    continue;
                }

                if (tag.at(0) == '_')
                {
                    continue;
                }

                ss << tag;

                if (tag != waypoint.TagList.back())
                {
                    ss << ",";
                }
            }
        }

        file << ss.str().c_str() << "\n";
    }

    std::cout << fmt::format("Waypoints saved to file: {}\n", filePath);

    file.close();

    g_WaypointUndoList.clear();
    g_WaypointRedoList.clear();
}

void EQAPP_WaypointList_Print()
{
    std::cout << "Waypoint List:\n";

    if (g_WaypointList.empty() == true)
    {
        std::cout << "No waypoints found.\n";
        return;
    }

    for (auto& waypoint : g_WaypointList)
    {
        std::cout << fmt::format
        (
            FMT_COMPILE
            (
                "[{}] {} ({}, {}, {})\n"
            ),
            waypoint.Index, waypoint.Name, waypoint.Y, waypoint.X, waypoint.Z
        );
    }
}

void EQAPP_WaypointList_PrintNames()
{
    std::cout << "Waypoint Names List:\n";

    if (g_WaypointList.empty() == true)
    {
        std::cout << "No waypoints found.\n";
        return;
    }

    auto waypointList = g_WaypointList;

    std::sort
    (
        waypointList.begin(), waypointList.end(),
        [] (const EQApp::Waypoint& a, const EQApp::Waypoint& b) -> bool
        { 
            return a.Name < b.Name;
        }
    );

    for (auto& waypoint : waypointList)
    {
        if (waypoint.Name.empty() == true)
        {
            continue;
        }

        if (EQAPP_String_BeginsWith(waypoint.Name, "Waypoint") == true)
        {
            continue;
        }

        std::cout << fmt::format
        (
            FMT_COMPILE
            (
                "[{}] {}\n"
            ),
            waypoint.Index, waypoint.Name
        );
    }
}

void EQAPP_WaypointList_Draw()
{
    if (g_WaypointList.empty() == true)
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

            if (g_WaypointEditorDistanceFilterIsEnabled == true)
            {
                float waypointDistance = EQ_CalculateDistance3D(playerSpawnY, playerSpawnX, playerSpawnZ, waypoint.Y, waypoint.X, waypoint.Z);

                if (waypointDistance > g_WaypointEditorDistanceFilterDistance)
                {
                    waypoint.IsDrawn = false;
                    continue;
                }
            }

            waypoint.IsDrawn = true;

            std::stringstream drawText;
            drawText << "[Waypoint] " << waypoint.Name;

            drawText << "\nIndex: " << waypoint.Index;

            drawText << "\nY: " << waypoint.Y;
            drawText << "\nX: " << waypoint.X;
            drawText << "\nZ: " << waypoint.Z;

            drawText << "\nC: ";

            if (waypoint.ConnectIndexList.empty() == true)
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

            for (auto& connectIndex : waypoint.ConnectIndexList)
            {
                auto connectWaypoint = EQAPP_Waypoint_GetByIndex(connectIndex);
                if (connectWaypoint == NULL)
                {
                    continue;
                }

                // one way connection
                if (EQAPP_Waypoint_IsConnected(waypoint.Index, connectWaypoint->Index) == true)
                {
                    if (EQAPP_Waypoint_IsConnected(connectWaypoint->Index, waypoint.Index) == false)
                    {
                        drawText << "\n1: " << waypoint.Index << " -> " << connectWaypoint->Index;
                    }
                }
            }

            if (waypoint.Flags != 0)
            {
                drawText << "\nFlags: ";

                if (waypoint.Flags & EQApp::WaypointFlags::kStand)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kStand];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kDuck)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kDuck];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kJump)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kJump];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kUseDoor)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kUseDoor];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kClickToZone)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kClickToZone];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceNorth)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorth];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceNorthEast)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorthEast];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceEast)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceEast];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceSouthEast)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouthEast];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceSouth)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouth];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceSouthWest)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouthWest];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceWest)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceWest];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kFaceNorthWest)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorthWest];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kWait5Seconds)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait5Seconds];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kWait10Seconds)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait10Seconds];
                }

                if (waypoint.Flags & EQApp::WaypointFlags::kWait1Minute)
                {
                    drawText << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait1Minute];
                }
            }

            if (waypoint.MacroFileName.empty() == false && waypoint.MacroFileName != EQApp::WaypointMacroFileNameDefault)
            {
                drawText << "\nMacro: " << waypoint.MacroFileName;
            }

            if (waypoint.TagList.empty() == false)
            {
                drawText << "\nTags: ";

                for (auto& tag : waypoint.TagList)
                {
                    drawText << tag;

                    if (tag != waypoint.TagList.back())
                    {
                        drawText << ",";
                    }
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

            if (EQAPP_GUI_IsMouseOver() == false)
            {
                if (EQ_IsMouseLookEnabled() == false)
                {
                    auto mouseX = EQ_GetMouseX();
                    auto mouseY = EQ_GetMouseY();
                    if (EQAPP_WaypointEditor_GetMouseOverIndex(mouseX, mouseY) == waypoint.Index)
                    {
                        textColor = EQ_DRAW_TEXT_COLOR_PINK;
                    }
                }
            }

            EQ_DrawTextByColor(drawText.str().c_str(), (int)waypointScreenX, (int)waypointScreenY, textColor);
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
                uint32_t lineColor = EQ_COLOR_ARGB_WHITE;

                // one way connection
                if (EQAPP_Waypoint_IsConnected(waypoint.Index, connectWaypoint->Index) == true)
                {
                    if (EQAPP_Waypoint_IsConnected(connectWaypoint->Index, waypoint.Index) == false)
                    {
                        lineColor = EQ_COLOR_ARGB_YELLOW;
                    }
                }

                EQ_DrawLine(waypointScreenX, waypointScreenY, connectWaypointScreenX, connectWaypointScreenY, lineColor);
            }
        }
    }

        for (auto it = g_WaypointGetPathIndexList.begin(); it != g_WaypointGetPathIndexList.end(); it++)
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

bool EQAPP_Waypoint_FollowPath(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromIndex is null");
        return false;
    }

    if (toIndex == EQApp::WaypointIndexNull)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "toIndex is null");
        return false;
    }

    auto fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "fromWaypoint is null");
        return false;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "playerSpawn is null");
        return false;
    }

    if (EQ_CanSpawnCastRayToLocation(playerSpawn, fromWaypoint->Y, fromWaypoint->X, fromWaypoint->Z) == true)
    {
        g_WaypointFollowPathIndexList = EQAPP_Waypoint_GetPathIndexList(fromIndex, toIndex);
        if (g_WaypointFollowPathIndexList.empty() == false)
        {
            g_WaypointGetPathIndexList = g_WaypointFollowPathIndexList;

            std::cout << fmt::format("Following waypoint path from waypoint index '{}' to waypoint index '{}'.\n", fromIndex, toIndex);

            EQAPP_Waypoint_FollowPath_On();
        }
        else
        {
            std::cout << fmt::format("No waypoint path can be found from waypoint index '{}' to waypoint index '{}'.\n", fromIndex, toIndex);
            return false;
        }
    }
    else
    {
        std::cout << fmt::format("You cannot see the starting waypoint index '{}'.\n", fromIndex);
        return false;
    }

    return true;
}

void EQAPP_Waypoint_FollowPathIndexList(EQApp::WaypointIndexList& indexList)
{
    if (indexList.empty() == true)
    {
        EQAPP_Waypoint_FollowPath_Off();
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (g_WaypointFollowPathWaitIsEnabled == true && g_WaypointIgnoreWaitIsEnabled == false)
    {
        if (EQAPP_Timer_HasTimeElapsedInSeconds(g_WaypointFollowPathWaitTimer, g_WaypointFollowPathWaitTimerInterval) == true)
        {
            g_WaypointFollowPathWaitIsEnabled = false;
        }
        else
        {
            EQ_SetAutoRun(false);
            return;
        }
    }

    EQ_UseDoorOnCollision();

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto it = indexList.begin(); it != indexList.end(); it++)
    {
        auto waypoint = EQAPP_Waypoint_GetByIndex(*it);
        if (waypoint == NULL)
        {
            continue;
        }

        float waypointDistance = EQ_CalculateDistance(playerY, playerX, waypoint->Y, waypoint->X);

        if (waypointDistance > g_WaypointFollowPathDistance)
        {
            EQ_TurnSpawnTowardsLocation(playerSpawn, waypoint->Y, waypoint->X);
            EQ_SetAutoRun(true);

            if (EQ_IsSpawnSwimming(playerSpawn) == true)
            {
                if ((waypoint->Z - 1.0f) > playerZ)
                {
                    // look up
                    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
                    EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHUP, 1);
                }
                else if ((waypoint->Z + 1.0f) < playerZ)
                {
                    // look down
                    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
                    EQ_ExecuteCommand(EQ_EXECUTECMD_PITCHDOWN, 1);
                }
                else
                {
                    // look forward
                    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
                    EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1);
                }
            }

            return;
        }

        if (waypoint->Flags != 0)
        {
            std::cout << "Waypoint Follow Path: ";

            if (waypoint->Flags & EQApp::WaypointFlags::kStand)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kStand];

                EQ_InterpretCommand("/stand");
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kDuck)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kDuck];

                EQ_ExecuteCommand(EQ_EXECUTECMD_DUCK, 1);
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kJump)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kJump];

                EQ_ExecuteCommand(EQ_EXECUTECMD_JUMP, 1);
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kUseDoor)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kUseDoor];

                EQ_UseDoorByDistance(g_WaypointUseDoorDistance);
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorth)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorth];

                EQ_SetPlayerSpawnHeadingNorth();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorthEast)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorthEast];

                EQ_SetPlayerSpawnHeadingNorthEast();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceEast)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceEast];

                EQ_SetPlayerSpawnHeadingEast();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouthEast)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouthEast];

                EQ_SetPlayerSpawnHeadingSouthEast();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouth)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouth];

                EQ_SetPlayerSpawnHeadingSouth();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceSouthWest)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceSouthWest];

                EQ_SetPlayerSpawnHeadingSouthWest();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceWest)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceWest];

                EQ_SetPlayerSpawnHeadingWest();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kFaceNorthWest)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kFaceNorthWest];

                EQ_SetPlayerSpawnHeadingNorthWest();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kWait5Seconds)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait5Seconds];

                g_WaypointFollowPathWaitIsEnabled = true;

                g_WaypointFollowPathWaitTimerInterval = 5;

                g_WaypointFollowPathWaitTimer = EQAPP_Timer_GetTimeNow();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kWait10Seconds)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait10Seconds];

                g_WaypointFollowPathWaitIsEnabled = true;

                g_WaypointFollowPathWaitTimerInterval = 10;

                g_WaypointFollowPathWaitTimer = EQAPP_Timer_GetTimeNow();
            }

            if (waypoint->Flags & EQApp::WaypointFlags::kWait1Minute)
            {
                std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kWait1Minute];

                g_WaypointFollowPathWaitIsEnabled = true;

                g_WaypointFollowPathWaitTimerInterval = 60;

                g_WaypointFollowPathWaitTimer = EQAPP_Timer_GetTimeNow();
            }

            auto itLast = std::prev(indexList.end());
            if (it == itLast)
            {
                EQAPP_Waypoint_FollowPath_Off();

                if (waypoint->MacroFileName.empty() == false && waypoint->MacroFileName != EQApp::WaypointMacroFileNameDefault)
                {
                    std::cout << fmt::format("Macro '{}'", waypoint->MacroFileName);

                    EQAPP_Macro_ExecuteFile(waypoint->MacroFileName.c_str());
                }

                if (waypoint->Flags & EQApp::WaypointFlags::kClickToZone)
                {
                    std::cout << EQApp::WaypointFlags_Strings[EQApp::WaypointFlags::kClickToZone];

                    for (unsigned int i = 0; i < 10; i++)
                    {
                        EQ_UseDoorByDistance(g_WaypointUseDoorDistance);
                    }
                }

                std::cout << "\n";

                return;
            }

            std::cout << "\n";
        }

        it = indexList.erase(it);
        it--;
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
        commandID == EQ_EXECUTECMD_SIT_STAND    ||
        commandID == EQ_EXECUTECMD_FORWARD      ||
        commandID == EQ_EXECUTECMD_BACK         ||
        commandID == EQ_EXECUTECMD_LEFT         ||
        commandID == EQ_EXECUTECMD_RIGHT        ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        if (g_WaypointIgnoreMovementIsEnabled == false)
        {
            EQAPP_Waypoint_FollowPath_Off();
        }

        return true;
    }

    return false;
}

void EQAPP_WaypointEditor_DrawText()
{
    std::stringstream drawText;

    drawText << "WAYPOINT EDITOR\n"
                "ESCAPE - Reset Selection\n"
                "LEFT-CLICK - Select Waypoint A\n"
                "RIGHT-CLICK - Select Waypoint B\n"
                "CONSIDER - Add\n"
                "TELL - Add Target\n"
                "REPLY - Remove\n"
                "JUMP - Connect\n"
                "DUCK - Disconnect\n"
                "AUTO-ATTACK - Align\n"
                "\n";

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

uint32_t EQAPP_WaypointEditor_GetMouseOverIndex(int x, int y)
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
            if (std::abs((int)waypointScreenX - x) < (int)g_WaypointEditorClickRadius)
            {
                if (std::abs((int)waypointScreenY - y) < (int)g_WaypointEditorClickRadius)
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
    auto index = EQAPP_WaypointEditor_GetMouseOverIndex(x, y);
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
    auto index = EQAPP_WaypointEditor_GetMouseOverIndex(x, y);
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

void EQAPP_WaypointEditor_Command_Reset()
{
    g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
    g_WaypointEditorToIndex = EQApp::WaypointIndexNull;
}

void EQAPP_WaypointEditor_Command_Connect()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_Connect(g_WaypointEditorFromIndex, g_WaypointEditorToIndex, false);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_Disconnect()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_Disconnect(g_WaypointEditorFromIndex, g_WaypointEditorToIndex, false);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_DisconnectAll()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_DisconnectAll(g_WaypointEditorFromIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddAtPlayer()
{
    EQAPP_Waypoint_AddAtPlayer("");

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddAtPlayerAndConnectToLastAddedIndex()
{
    EQAPP_Waypoint_AddAtPlayerAndConnectToLastAddedIndex();

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddAtPlayerBetween()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_AddAtPlayerBetween(g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddAtTarget()
{
    EQAPP_Waypoint_AddAtTarget("");

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddAtTargetBetween()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_AddAtTargetBetween(g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_AddBehindTarget()
{
    EQAPP_Waypoint_AddBehindTarget("");

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_Remove()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_Remove(g_WaypointEditorFromIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_Align()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_Align(g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_Split()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull || g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_Split(g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_MoveToPlayer()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_MoveToPlayer(g_WaypointEditorFromIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

void EQAPP_WaypointEditor_Command_MoveToTarget()
{
    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull)
    {
        return;
    }

    EQAPP_Waypoint_MoveToTarget(g_WaypointEditorFromIndex);

    EQAPP_WaypointEditor_Command_Reset();
}

bool EQAPP_WaypointEditor_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1)
    {
        return false;
    }

    if (commandID == EQ_EXECUTECMD_CLEAR_TARGET || commandID == EQ_EXECUTECMD_CLOSE_TOP_WINDOW)
    {
        EQAPP_WaypointEditor_Command_Reset();

        return false;
    }

    if (commandID == EQ_EXECUTECMD_JUMP)
    {
        EQAPP_WaypointEditor_Command_Connect();

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_DUCK)
    {
        EQAPP_WaypointEditor_Command_Disconnect();

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_CONSIDER)
    {
        EQAPP_WaypointEditor_Command_AddAtPlayer();

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_TELL)
    {
        EQAPP_WaypointEditor_Command_AddAtTarget();

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_REPLY)
    {
        EQAPP_WaypointEditor_Command_Remove();

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_AUTOPRIM)
    {
        EQAPP_WaypointEditor_Command_Align();

        return true;
    }

    return false;
}

