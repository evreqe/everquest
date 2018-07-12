#pragma once

namespace EQApp
{
    enum WaypointFlags
    {
        kJump           = 1 << 0,
        kUseDoor        = 1 << 1,
        kClickToZone    = 1 << 2,
        kReserved1      = 1 << 3,
    };

    typedef std::vector<uint32_t> WaypointIndexList;

    typedef struct _Waypoint
    {
        uint32_t Index;
        std::string Name;
        float Y;
        float X;
        float Z;
        WaypointIndexList ConnectIndexList;
        uint32_t Flags = 0;

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
}

bool g_WaypointIsEnabled = true;

bool g_WaypointEditorIsEnabled = false;

uint32_t g_WaypointEditorDrawTextX = 600;
uint32_t g_WaypointEditorDrawTextY = 10;

uint32_t g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
uint32_t g_WaypointEditorToIndex   = EQApp::WaypointIndexNull;

bool g_WaypointFollowPathIsEnabled = false;

float g_WaypointFollowPathDistance = 2.0f;

float g_WaypointUseDoorDistance = 20.0f;

EQApp::WaypointList g_WaypointList;

EQApp::WaypointIndexList g_WaypointGetPathIndexList;

EQApp::WaypointIndexList g_WaypointFollowPathIndexList;

void EQAPP_Waypoint_Editor_Toggle();
void EQAPP_Waypoint_Editor_On();
void EQAPP_Waypoint_Editor_Off();
void EQAPP_Waypoint_FollowPath_Toggle();
void EQAPP_Waypoint_FollowPath_On();
void EQAPP_Waypoint_FollowPath_Off();
void EQAPP_Waypoint_Add(const char* name);
void EQAPP_Waypoint_Remove(uint32_t index);
void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
bool EQAPP_Waypoint_IsConnected(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignY(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignX(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_AlignZ(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_Push(uint32_t index, float distance);
void EQAPP_Waypoint_Pull(uint32_t index, float distance);
uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint_ptr waypoint, EQApp::Waypoint_ptr waypointEnd);
EQApp::Waypoint_ptr EQAPP_Waypoint_GetByIndex(uint32_t index);
uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z);
uint32_t EQAPP_Waypoint_GetIndexNearestInList(EQApp::WaypointIndexList& indexList);
EQApp::WaypointIndexList EQAPP_Waypoint_GetIndexesInLineOfSight();
void EQAPP_Waypoint_RemoveIndexesWithNoConnectionsFromList(EQApp::WaypointIndexList& indexList);
EQApp::WaypointIndexList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PrintPath(EQApp::WaypointIndexList& indexList, uint32_t fromIndex);
void EQAPP_Waypoint_FollowPath(EQApp::WaypointIndexList& indexList);
bool EQAPP_Waypoint_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);
void EQAPP_WaypointList_Clear();
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

void EQAPP_Waypoint_Add(const char* name)
{
    uint32_t index = 0;

    for (auto& waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if (waypoint_it->Index == index)
        {
            index++;
            waypoint_it = g_WaypointList.begin();
        }
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    auto spawnY = -1.0f;
    auto spawnX = -1.0f;
    auto spawnZ = -1.0f;

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn != NULL && targetSpawn != playerSpawn)
    {
        spawnY = EQ_GetSpawnY(targetSpawn);
        spawnX = EQ_GetSpawnX(targetSpawn);
        spawnZ = EQ_GetSpawnZ(targetSpawn);

        float spawnHeading = EQ_GetSpawnHeading(targetSpawn);

        EQ_ApplyVectorForward(spawnY, spawnX, spawnHeading, 5.0f);
    }
    else
    {
        spawnY = EQ_GetSpawnY(playerSpawn);
        spawnX = EQ_GetSpawnX(playerSpawn);
        spawnZ = EQ_GetSpawnZ(playerSpawn);
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

    if (spawnY == -1.0f && spawnX == -1.0f && spawnZ == -1.0f)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "spawn coordinates are null");
        return;
    }

    EQApp::Waypoint waypoint;
    waypoint.Index = index;
    waypoint.Y = spawnY;
    waypoint.X = spawnX;
    waypoint.Z = spawnZ;
    waypoint.Name = waypointName.str();

    g_WaypointList.push_back(waypoint);

    std::cout << "Waypoint added: " << waypointName.str() << " (Index: " << index << ")" << std::endl;
}

void EQAPP_Waypoint_Remove(uint32_t index)
{
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
            std::cout << "Waypoint removed: " << waypoint_it->Name << " (Index: " << index << ")" << std::endl;

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
                std::cout << "Waypoint disconnected: " << waypoint.Name << " (Index: " << waypoint.Index << ")" << std::endl;

                connectIndex_it = waypoint.ConnectIndexList.erase(connectIndex_it);
                connectIndex_it--;
            }
        }
    }
}

void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
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

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "cannot connect waypoint to itself");
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
            std::string debugText = fmt::format("connection already exists from waypoint {} to {}", fromIndex, toIndex);

            EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
            return;
        }
    }

    fromWaypoint->ConnectIndexList.push_back(toIndex);

    std::cout << "Waypoint connected: " << fromWaypoint->Name << " (Index: " << fromIndex << ") to "<< toWaypoint->Name << " (Index: " << toIndex << ")" << std::endl;

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex : toWaypoint->ConnectIndexList)
        {
            if (connectIndex == fromIndex)
            {
                std::string debugText = fmt::format("connection already exists for waypoints {} and {}", fromIndex, toIndex);

                EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
                return;
            }
        }

        toWaypoint->ConnectIndexList.push_back(fromIndex);

        std::cout << "Waypoint connected: " << toWaypoint->Name << " (Index: " << toIndex << ") to " << fromWaypoint->Name << " (Index: " << fromIndex << ")" << std::endl;
    }
}

void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
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

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "cannot disconnect waypoint from itself");
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
            std::cout << "Waypoint disconnected: " << fromWaypoint->Name << " (Index: " << fromIndex << ") to "<< toWaypoint->Name << " (Index: " << toIndex << ")" << std::endl;

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
                std::cout << "Waypoint disconnected: " << toWaypoint->Name << " (Index: " << toIndex << ") to " << fromWaypoint->Name << " (Index: " << fromIndex << ")" << std::endl;

                connectIndex_it = toWaypoint->ConnectIndexList.erase(connectIndex_it);
                connectIndex_it--;
                break;
            }
        }
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

void EQAPP_Waypoint_AlignY(uint32_t fromIndex, uint32_t toIndex)
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

    toWaypoint->Y = fromWaypoint->Y;
}

void EQAPP_Waypoint_AlignX(uint32_t fromIndex, uint32_t toIndex)
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

    toWaypoint->X = fromWaypoint->X;
}

void EQAPP_Waypoint_AlignZ(uint32_t fromIndex, uint32_t toIndex)
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

    toWaypoint->Z = fromWaypoint->Z;
}

void EQAPP_Waypoint_Push(uint32_t index, float distance)
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

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    float playerSpawnY = EQ_GetSpawnY(playerSpawn);
    float playerSpawnX = EQ_GetSpawnX(playerSpawn);
    float playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    float playerSpawnHeading = EQ_GetSpawnHeading(playerSpawn);

    float playerSpawnHeadingRounded = playerSpawnHeading;

    if (playerSpawnHeading > 0.0f)
    {
        playerSpawnHeadingRounded = std::roundf(playerSpawnHeading / EQ_HEADING_MAX_EIGHTH) * EQ_HEADING_MAX_EIGHTH;
    }

    EQ_ApplyVectorForward(waypoint->Y, waypoint->X, playerSpawnHeadingRounded, distance);
}

void EQAPP_Waypoint_Pull(uint32_t index, float distance)
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

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "player spawn is null");
        return;
    }

    float playerSpawnY = EQ_GetSpawnY(playerSpawn);
    float playerSpawnX = EQ_GetSpawnX(playerSpawn);
    float playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    float playerSpawnHeading = EQ_GetSpawnHeading(playerSpawn);

    float playerSpawnHeadingRounded = playerSpawnHeading;

    if (playerSpawnHeading > 0.0f)
    {
        playerSpawnHeadingRounded = std::roundf(playerSpawnHeading / EQ_HEADING_MAX_EIGHTH) * EQ_HEADING_MAX_EIGHTH;
    }

    EQ_ApplyVectorBackward(waypoint->Y, waypoint->X, playerSpawnHeadingRounded, distance);
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
    std::map<float, uint32_t> distanceList;

    for (auto& waypoint : g_WaypointList)
    {
        float distance = EQ_CalculateDistance3D(y, x, z, waypoint.Y, waypoint.X, waypoint.Z);

        distanceList.insert(std::make_pair(distance, waypoint.Index));
    }

    return distanceList.begin()->second;
}

uint32_t EQAPP_Waypoint_GetIndexNearestInList(EQApp::WaypointIndexList& indexList)
{
    std::map<float, uint32_t> distanceList;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return NULL;
    }

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

    return distanceList.begin()->second;
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetIndexesInLineOfSight()
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

void EQAPP_Waypoint_RemoveIndexesWithNoConnectionsFromList(EQApp::WaypointIndexList& indexList)
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

    EQApp::WaypointIndexList indexList = EQAPP_Waypoint_GetIndexesInLineOfSight();
    if (indexList.size() == 0)
    {
        return EQApp::WaypointIndexNull;
    }

    EQAPP_Waypoint_RemoveIndexesWithNoConnectionsFromList(indexList);

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

        auto pathIndexList = EQAPP_Waypoint_GetPath(waypoint->Index, toIndex);
        if (pathIndexList.size() == 0)
        {
            it = distanceList.erase(it);
            it--;
            continue;
        }
    }

    return distanceList.begin()->second;
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex)
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

void EQAPP_Waypoint_PrintPath(EQApp::WaypointIndexList& indexList, uint32_t fromIndex)
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
    g_WaypointList.clear();
}

void EQAPP_WaypointList_Load()
{
    EQAPP_WaypointList_Clear();

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

            if (tokens.size() == 7)
            {
                waypoint.Flags = std::stoul(tokens.at(6));
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

        file << mw.c_str() << std::endl;
    }

    std::cout << "Waypoints saved to file: " << filePathStr << std::endl;

    file.close();
}

void EQAPP_WaypointList_Print()
{
    std::cout << "Waypoint List: " << std::endl;

    if (g_WaypointList.size() == 0)
    {
        std::cout << "No waypoints." << std::endl;
        return;
    }

    for (auto& waypoint : g_WaypointList)
    {
        std::cout << "Index: " << waypoint.Index << " (Name: " << waypoint.Name << ") (YXZ: " << waypoint.Y << ", " << waypoint.X << ", " << waypoint.Z << ")" << std::endl;

        if (waypoint.ConnectIndexList.size() == 0)
        {
            std::cout << "No connections.";
        }
        else
        {
            std::cout << "Connections: ";

            for (auto& connectIndex : waypoint.ConnectIndexList)
            {
                std::cout << connectIndex;

                if (connectIndex != waypoint.ConnectIndexList.back())
                {
                    std::cout << ", ";
                }
            }

            std::cout << std::endl;
        }
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

void EQAPP_Waypoint_FollowPath(EQApp::WaypointIndexList& indexList)
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

    if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull)
    {
        drawText << "From Index: " << g_WaypointEditorFromIndex << "\n";
    }

    if (g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
    {
        drawText << "To Index: " << g_WaypointEditorToIndex << "\n";
    }

    drawText << "ESCAPE - Reset Selection\n";
    drawText << "LEFT-CLICK - Select Waypoint A\n";
    drawText << "RIGHT-CLICK - Select Waypoint B\n";
    drawText << "CONSIDER - Add\n";
    drawText << "REPLY - Remove\n";
    drawText << "JUMP - Connect\n";
    drawText << "DUCK - Disconnect\n";
    drawText << "AUTO-ATTACK - Align\n";

    EQ_DrawTextByColor(drawText.str().c_str(), g_WaypointEditorDrawTextX, g_WaypointEditorDrawTextY, EQ_DRAW_TEXT_COLOR_WHITE);
}

uint32_t EQAPP_WaypointEditor_GetClickedIndex(int x, int y)
{
    for (auto& waypoint : g_WaypointList)
    {
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
            std::string commandText = fmt::format("//WPConnect {},{}", g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

            EQ_InterpretCommand(commandText.c_str());

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_DUCK)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull && g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
        {
            std::string commandText = fmt::format("//WPDisconnect {},{}", g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

            EQ_InterpretCommand(commandText.c_str());

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_CONSIDER)
    {
        EQ_InterpretCommand("//WPAdd");

        g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
        g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

        return true;
    }
    else if (commandID == EQ_EXECUTECMD_REPLY)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull)
        {
            std::string commandText = fmt::format("//WPRemove {}", g_WaypointEditorFromIndex);

            EQ_InterpretCommand(commandText.c_str());

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }
    else if (commandID == EQ_EXECUTECMD_AUTOPRIM)
    {
        if (g_WaypointEditorFromIndex != EQApp::WaypointIndexNull && g_WaypointEditorToIndex != EQApp::WaypointIndexNull)
        {
            std::string commandText = fmt::format("//WPAlign {},{}", g_WaypointEditorFromIndex, g_WaypointEditorToIndex);

            EQ_InterpretCommand(commandText.c_str());

            g_WaypointEditorFromIndex = EQApp::WaypointIndexNull;
            g_WaypointEditorToIndex = EQApp::WaypointIndexNull;

            return true;
        }
    }

    return false;
}
