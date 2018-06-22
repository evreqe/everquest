#pragma once

// TODO: re-write

namespace EQApp
{
    typedef std::vector<uint32_t> WaypointIndexList;

    typedef struct _Waypoint
    {
        uint32_t index;
        std::string name;
        float y;
        float x;
        float z;
        WaypointIndexList connectIndexList;

        // A* Star pathfinding algorithm
        bool isOpened;
        bool isClosed;
        uint32_t f = 0;
        uint32_t g = 0;
        uint32_t h = 0;
        struct _Waypoint* parent;
    } Waypoint, *Waypoint_ptr;
}

bool g_WayPointIsEnabled = true;

std::vector<EQApp::Waypoint> g_WaypointList;

void EQAPP_Waypoint_Add(const char* name);
void EQAPP_Waypoint_Remove(uint32_t index);
void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection);
EQApp::Waypoint_ptr EQAPP_Waypoint_GetByIndex(uint32_t index);
uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z);
uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2);
void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint_ptr waypoint, EQApp::Waypoint_ptr waypointEnd);
EQApp::WaypointIndexList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PrintPath(EQApp::WaypointIndexList& indexList, uint32_t fromIndex);
void EQAPP_WaypointList_Clear();
void EQAPP_WaypointList_Load();
void EQAPP_WaypointList_Save();
void EQAPP_WaypointList_Print();

void EQAPP_Waypoint_Add(const char* name)
{
    uint32_t index = 0;

    for (auto& waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if (waypoint_it->index == index)
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
    waypoint.index = index;
    waypoint.y = spawnY;
    waypoint.x = spawnX;
    waypoint.z = spawnZ;
    waypoint.name = waypointName.str();

    g_WaypointList.push_back(waypoint);

    std::cout << "Waypoint added: " << waypointName.str() << " (Index: " << index << ")" << std::endl;
}

void EQAPP_Waypoint_Remove(uint32_t index)
{
    if (g_WaypointList.empty() == true)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "waypoint list is empty");
        return;
    }

    if (index > g_WaypointList.size())
    {
        std::string debugText = fmt::format("index out of bounds: {}", index);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    for (auto& waypoint_it = g_WaypointList.begin(); waypoint_it != g_WaypointList.end(); waypoint_it++)
    {
        if (waypoint_it->index == index)
        {
            std::cout << "Waypoint removed: " << waypoint_it->name << " (Index: " << index << ")" << std::endl;

            waypoint_it = g_WaypointList.erase(waypoint_it);
            waypoint_it--;
        }
    }

    for (auto& waypoint : g_WaypointList)
    {
        for (auto& connectIndex_it = waypoint.connectIndexList.begin(); connectIndex_it != waypoint.connectIndexList.end(); connectIndex_it++)
        {
            if (*connectIndex_it == index)
            {
                std::cout << "Waypoint disconnected: " << waypoint.name << " (Index: " << waypoint.index << ")" << std::endl;

                connectIndex_it = waypoint.connectIndexList.erase(connectIndex_it);
                connectIndex_it--;
            }
        }
    }
}

void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "cannot connect waypoint to itself");
        return;
    }

    if (fromIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("from index out of bounds: {}", fromIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    if (toIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("to index out of bounds: {}", toIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    EQApp::Waypoint_ptr fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    EQApp::Waypoint_ptr toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    for (auto& connectIndex : fromWaypoint->connectIndexList)
    {
        if (connectIndex == toIndex)
        {
            std::string debugText = fmt::format("connection already exists from waypoint {} to {}", fromIndex, toIndex);

            EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
            return;
        }
    }

    fromWaypoint->connectIndexList.push_back(toIndex);

    std::cout << "Waypoint connected: " << fromWaypoint->name << "(Index: " << fromIndex << ") to "<< toWaypoint->name << "(Index: " << toIndex << ")" << std::endl;

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex : toWaypoint->connectIndexList)
        {
            if (connectIndex == fromIndex)
            {
                std::string debugText = fmt::format("connection already exists for waypoints {} and {}", fromIndex, toIndex);

                EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
                return;
            }
        }

        toWaypoint->connectIndexList.push_back(fromIndex);

        std::cout << "Waypoint connected: " << toWaypoint->name << "(Index: " << toIndex << ") to " << fromWaypoint->name << "(Index: " << fromIndex << ")" << std::endl;
    }
}

void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex, bool bOneWayConnection)
{
    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "cannot disconnect waypoint from itself");
        return;
    }

    if (fromIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("from index out of bounds: {}", fromIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    if (toIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("to index out of bounds: {}", toIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return;
    }

    EQApp::Waypoint_ptr fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from waypoint is null");
        return;
    }

    EQApp::Waypoint_ptr toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "to waypoint is null");
        return;
    }

    for (auto& connectIndex_it = fromWaypoint->connectIndexList.begin(); connectIndex_it != fromWaypoint->connectIndexList.end(); connectIndex_it++)
    {
        if (*connectIndex_it == toIndex)
        {
            std::cout << "Waypoint disconnected: " << fromWaypoint->name << "(Index: " << fromIndex << ") to "<< toWaypoint->name << "(Index: " << toIndex << ")" << std::endl;

            connectIndex_it = fromWaypoint->connectIndexList.erase(connectIndex_it);
            connectIndex_it--;
            break;
        }
    }

    if (bOneWayConnection == false)
    {
        for (auto& connectIndex_it = toWaypoint->connectIndexList.begin(); connectIndex_it != toWaypoint->connectIndexList.end(); connectIndex_it++)
        {
            if (*connectIndex_it == fromIndex)
            {
                std::cout << "Waypoint disconnected: " << toWaypoint->name << "(Index: " << toIndex << ") to " << fromWaypoint->name << "(Index: " << fromIndex << ")" << std::endl;

                connectIndex_it = toWaypoint->connectIndexList.erase(connectIndex_it);
                connectIndex_it--;
                break;
            }
        }
    }
}

EQApp::Waypoint_ptr EQAPP_Waypoint_GetByIndex(uint32_t index)
{
    for (auto& waypoint : g_WaypointList)
    {
        if (waypoint.index == index)
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
        float distance = EQ_CalculateDistance3D(x, y, z, waypoint.x, waypoint.y, waypoint.z);

        distanceList.insert(std::make_pair(distance, waypoint.index));
    }

    return distanceList.begin()->second;
}

uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    return waypoint1->g + ((waypoint2->x == waypoint1->x || waypoint2->y == waypoint1->y) ? 10 : 14);
}

uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint_ptr waypoint1, EQApp::Waypoint_ptr waypoint2)
{
    // manhattan distance
    ////return (uint32_t)(std::fabsf(waypoint1->x - waypoint2->x) + std::fabsf(waypoint1->y - waypoint2->y) * 10);

    // euclidean distance
    return (uint32_t)(std::sqrt(std::pow(waypoint2->x - waypoint1->x, 2) + std::pow(waypoint2->y - waypoint1->y, 2) + std::pow(waypoint2->z - waypoint1->z, 2)));
}

void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint_ptr waypoint, EQApp::Waypoint_ptr waypointEnd)
{
    waypoint->g = EQAPP_Waypoint_GetGScore(waypoint, waypoint->parent);
    waypoint->h = EQAPP_Waypoint_GetHScore(waypoint, waypointEnd);

    waypoint->f = waypoint->g + waypoint->h;
}

EQApp::WaypointIndexList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex)
{
    EQApp::WaypointIndexList indexList;

    if (fromIndex == toIndex)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "from index and to index are the same");
        return indexList;
    }

    if (fromIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("from index out of bounds: {}", fromIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return indexList;
    }

    if (toIndex > g_WaypointList.size())
    {
        std::string debugText = fmt::format("to index out of bounds: {}", toIndex);

        EQAPP_PrintDebugText(__FUNCTION__, debugText.c_str());
        return indexList;
    }

    EQApp::Waypoint_ptr begin = EQAPP_Waypoint_GetByIndex(fromIndex);
    EQApp::Waypoint_ptr end   = EQAPP_Waypoint_GetByIndex(toIndex);

    if (begin == NULL || end == NULL)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "begin or end waypoint is null");
        return indexList;
    }

    EQApp::Waypoint_ptr current;
    EQApp::Waypoint_ptr child;

    std::list<EQApp::Waypoint_ptr> openedList;
    std::list<EQApp::Waypoint_ptr> closedList;
    std::list<EQApp::Waypoint_ptr>::iterator waypointListIterator;

    uint32_t numIterations = 0;
    uint32_t maxIterations = 100;

    openedList.push_back(begin);
    begin->isOpened = true;

    while (numIterations == 0 || (current != end && numIterations < maxIterations))
    {
        for (waypointListIterator = openedList.begin(); waypointListIterator != openedList.end(); ++waypointListIterator)
        {
            if (waypointListIterator == openedList.begin() || (*waypointListIterator)->f <= current->f)
            {
                current = (*waypointListIterator);
            }
        }

        if (current == end)
        {
            break;
        }

        openedList.remove(current);
        current->isOpened = false;

        closedList.push_back(current);
        current->isClosed = true;

        for (auto& connectIndex : current->connectIndexList)
        {
            child = EQAPP_Waypoint_GetByIndex(connectIndex);

            if (child == NULL || child == current || child->isClosed == true)
            {
                continue;
            }

            if (child->isOpened == true)
            {
                uint32_t currentGScore = EQAPP_Waypoint_GetGScore(child, current);

                if (child->g > currentGScore)
                {
                    child->parent = current;
                    EQAPP_Waypoint_ComputeScores(child, end);
                }
            }
            else
            {
                openedList.push_back(child);
                child->isOpened = true;

                child->parent = current;
                EQAPP_Waypoint_ComputeScores(child, end);
            }
        }

        numIterations++;
    }

    for (waypointListIterator = openedList.begin(); waypointListIterator != openedList.end(); ++waypointListIterator)
    {
        (*waypointListIterator)->isOpened = false;
    }

    for (waypointListIterator = closedList.begin(); waypointListIterator != closedList.end(); ++waypointListIterator)
    {
        (*waypointListIterator)->isClosed = false;
    }

    while (current->parent != NULL && current != begin)
    {
        indexList.push_back(current->index);
        current = current->parent;
        numIterations++;
    }

    std::reverse(indexList.begin(), indexList.end());

    return indexList;
}

void EQAPP_Waypoint_PrintPath(EQApp::WaypointIndexList& indexList, uint32_t fromIndex)
{
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
    g_WaypointList.clear();

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

        // index, name, y, x, z, connectIndexList
        if (tokens.size() == 6)
        {
            EQApp::Waypoint waypoint;

            waypoint.index = std::stoul(tokens.at(0));
            waypoint.name  = tokens.at(1);
            waypoint.y     = std::stof(tokens.at(2));
            waypoint.x     = std::stof(tokens.at(3));
            waypoint.z     = std::stof(tokens.at(4));

            std::vector<std::string> connections = EQAPP_String_Split(tokens.at(5), ',');
            if (connections.size() != 0)
            {
                if (connections.at(0) != "-1")
                {
                    for (auto& connection : connections)
                    {
                        uint32_t connectIndex = std::stoul(connection);

                        waypoint.connectIndexList.push_back(connectIndex);
                    }
                }
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
        fmt::MemoryWriter ss;
        ss << waypoint.index << "^" << waypoint.name << "^" << waypoint.y << "^" << waypoint.x << "^" << waypoint.z << "^";

        if (waypoint.connectIndexList.size() == 0)
        {
            ss << "-1";
        }
        else
        {
            for (auto& connectIndex : waypoint.connectIndexList)
            {
                ss << connectIndex;

                if (connectIndex != waypoint.connectIndexList.back())
                {
                    ss << ",";
                }
            }
        }

        file << ss.c_str() << std::endl;
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
        std::cout << "Index: " << waypoint.index << " (Name: " << waypoint.name << ") (YXZ: " << waypoint.y << ", " << waypoint.x << ", " << waypoint.z << ")" << std::endl;

        if (waypoint.connectIndexList.size() == 0)
        {
            std::cout << "No connections.";
        }
        else
        {
            std::cout << "Connections: ";

            for (auto& connect : waypoint.connectIndexList)
            {
                std::cout << connect;

                if (connect != waypoint.connectIndexList.back())
                {
                    std::cout << ", ";
                }
            }

            std::cout << std::endl;
        }
    }
}

