#pragma once

namespace EQApp
{
    typedef struct _Waypoint
    {
        uint32_t index;
        float y;
        float x;
        float z;
        std::vector<uint32_t> connectList;
        std::string name;

        // A* Star pathfinding algorithm
        bool isOpened;
        bool isClosed;
        uint32_t f = 0;
        uint32_t g = 0;
        uint32_t h = 0;
        struct _Waypoint* parent = NULL;
    } Waypoint, *Waypoint_ptr;

    typedef std::vector<uint32_t> WaypointPathList;
}

std::vector<EQApp::Waypoint> g_waypointList;

void EQAPP_Waypoint_Add();
void EQAPP_Waypoint_Remove(uint32_t index);
void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex);
EQApp::Waypoint* EQAPP_Waypoint_GetByIndex(uint32_t index);
uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z);
uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint* waypoint1, EQApp::Waypoint* waypoint2);
uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint* waypoint1, EQApp::Waypoint* waypoint2);
void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint* waypoint, EQApp::Waypoint* waypointEnd);
EQApp::WaypointPathList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex);
void EQAPP_Waypoint_PrintPath(EQApp::WaypointPathList& pathList, uint32_t fromIndex);
void EQAPP_WaypointList_Clear();
void EQAPP_WaypointList_Load();
void EQAPP_WaypointList_Save();
void EQAPP_WaypointList_Print();

void EQAPP_Waypoint_Add()
{
    uint32_t index = 0;

    for (auto& waypoint_it = g_waypointList.begin(); waypoint_it != g_waypointList.end(); waypoint_it++)
    {
        if (waypoint_it->index == index)
        {
            index++;
            waypoint_it = g_waypointList.begin();
        }
    }

    uint32_t spawnInfo = EQ_GetTargetSpawn();
    if (spawnInfo == NULL)
    {
        spawnInfo = EQ_GetPlayerSpawn();
        if (spawnInfo == NULL)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "target and player spawns are NULL");
            return;
        }
    }

    float spawnY = EQ_ReadMemory<float>(spawnInfo + 0x64);
    float spawnX = EQ_ReadMemory<float>(spawnInfo + 0x68);
    float spawnZ = EQ_ReadMemory<float>(spawnInfo + 0x6C);

    std::stringstream waypointName;
    waypointName << "Waypoint_" << index;

    EQApp::Waypoint waypoint;
    waypoint.index = index;
    waypoint.y = spawnY;
    waypoint.x = spawnX;
    waypoint.z = spawnZ;
    waypoint.name = waypointName.str();

    g_waypointList.push_back(waypoint);

    std::cout << "[error] " << __FUNCTION__ << ": added waypoint " << index << std::endl;
}

void EQAPP_Waypoint_Remove(uint32_t index)
{
    if (g_waypointList.empty() == true)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "waypoint list is empty");
        return;
    }

    if (index > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": index out of bounds: " << index << std::endl;
        return;
    }

    for (auto& waypoint_it = g_waypointList.begin(); waypoint_it != g_waypointList.end(); waypoint_it++)
    {
        if (waypoint_it->index == index)
        {
            waypoint_it = g_waypointList.erase(waypoint_it);
            waypoint_it--;
        }
    }

    for (auto& waypoint : g_waypointList)
    {
        for (auto& connectIndex_it = waypoint.connectList.begin(); connectIndex_it != waypoint.connectList.end(); connectIndex_it++)
        {
            if (*connectIndex_it == index)
            {
                connectIndex_it = waypoint.connectList.erase(connectIndex_it);
                connectIndex_it--;
            }
        }
    }

    std::cout << "[error] " << __FUNCTION__ << ": removed waypoint " << index << std::endl;
}

void EQAPP_Waypoint_Connect(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == toIndex)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "cannot connect waypoint to itself");
        return;
    }

    if (fromIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": from index out of bounds: " << fromIndex << std::endl;
        return;
    }

    if (toIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": to index out of bounds: " << toIndex << std::endl;
        return;
    }

    EQApp::Waypoint* fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "from waypoint is NULL");
        return;
    }

    for (auto& connectIndex : fromWaypoint->connectList)
    {
        if (connectIndex == toIndex)
        {
            std::cout << "[error] " << __FUNCTION__ << ": connection already exists for waypoints " << fromIndex << " and " << toIndex << std::endl;
            return;
        }
    }

    fromWaypoint->connectList.push_back(toIndex);

    EQApp::Waypoint* toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "to waypoint is NULL");
        return;
    }

    for (auto& connectIndex : toWaypoint->connectList)
    {
        if (connectIndex == fromIndex)
        {
            std::cout << "[error] " << __FUNCTION__ << ": connection already exists for waypoints " << fromIndex << " and " << toIndex << std::endl;
            return;
        }
    }

    toWaypoint->connectList.push_back(fromIndex);

    std::cout << "[error] " << __FUNCTION__ << ": connected waypoints " << fromIndex << " and " << toIndex << std::endl;
}

void EQAPP_Waypoint_Disconnect(uint32_t fromIndex, uint32_t toIndex)
{
    if (fromIndex == toIndex)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "cannot disconnect waypoint from itself");
        return;
    }

    if (fromIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": from index out of bounds: " << fromIndex << std::endl;
        return;
    }

    if (toIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": to index out of bounds: " << toIndex << std::endl;
        return;
    }

    EQApp::Waypoint* fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
    if (fromWaypoint == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "from waypoint is NULL");
        return;
    }

    for (auto& connectIndex_it = fromWaypoint->connectList.begin(); connectIndex_it != fromWaypoint->connectList.end(); connectIndex_it++)
    {
        if (*connectIndex_it == toIndex)
        {
            connectIndex_it = fromWaypoint->connectList.erase(connectIndex_it);
            connectIndex_it--;
            break;
        }
    }

    EQApp::Waypoint* toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
    if (toWaypoint == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "to waypoint is NULL");
        return;
    }

    for (auto& connectIndex_it = toWaypoint->connectList.begin(); connectIndex_it != toWaypoint->connectList.end(); connectIndex_it++)
    {
        if (*connectIndex_it == fromIndex)
        {
            connectIndex_it = toWaypoint->connectList.erase(connectIndex_it);
            connectIndex_it--;
            break;
        }
    }

    std::cout << "[error] " << __FUNCTION__ << ": disconnected waypoints " << fromIndex << " and " << toIndex << std::endl;
}

EQApp::Waypoint* EQAPP_Waypoint_GetByIndex(uint32_t index)
{
    for (auto& waypoint : g_waypointList)
    {
        if (waypoint.index == index)
        {
            return &waypoint;
        }
    }

    std::cout << "[error] " << __FUNCTION__ << ": index not found: " << index << std::endl;
    return NULL;
}

uint32_t EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z)
{
    std::map<float, uint32_t> distanceList;

    for (auto& waypoint : g_waypointList)
    {
        float distance = EQ_CalculateDistance3d(x, y, z, waypoint.x, waypoint.y, waypoint.z);

        distanceList.insert(std::make_pair(distance, waypoint.index));
    }

    return distanceList.begin()->second;
}

uint32_t EQAPP_Waypoint_GetGScore(EQApp::Waypoint* waypoint1, EQApp::Waypoint* waypoint2)
{
    return waypoint1->g + ((waypoint2->x == waypoint1->x || waypoint2->y == waypoint1->y) ? 10 : 14);
}

uint32_t EQAPP_Waypoint_GetHScore(EQApp::Waypoint* waypoint1, EQApp::Waypoint* waypoint2)
{
    // manhattan distance
    //return (uint32_t)(abs(waypoint1->x - waypoint2->x) + abs(waypoint1->y - waypoint2->y) * 10);

    // euclidean distance
    return (uint32_t)(sqrt(pow(waypoint2->x - waypoint1->x, 2) + pow(waypoint2->y - waypoint1->y, 2) + pow(waypoint2->z - waypoint1->z, 2)));
}

void EQAPP_Waypoint_ComputeScores(EQApp::Waypoint* waypoint, EQApp::Waypoint* waypointEnd)
{
    waypoint->g = EQAPP_Waypoint_GetGScore(waypoint, waypoint->parent);
    waypoint->h = EQAPP_Waypoint_GetHScore(waypoint, waypointEnd);

    waypoint->f = waypoint->g + waypoint->h;
}

EQApp::WaypointPathList EQAPP_Waypoint_GetPath(uint32_t fromIndex, uint32_t toIndex)
{
    EQApp::WaypointPathList pathList;

    if (fromIndex == toIndex)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "from index and to index are the same");
        return pathList;
    }

    if (fromIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": from index out of bounds: " << fromIndex << std::endl;
        return pathList;
    }

    if (toIndex > g_waypointList.size())
    {
        std::cout << "[error] " << __FUNCTION__ << ": to index out of bounds: " << toIndex << std::endl;
        return pathList;
    }

    EQApp::Waypoint* start = EQAPP_Waypoint_GetByIndex(fromIndex);
    EQApp::Waypoint* end   = EQAPP_Waypoint_GetByIndex(toIndex);

    if (start == NULL || end == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "start or end waypoint is NULL");
        return pathList;
    }

    EQApp::Waypoint* current;
    EQApp::Waypoint* child;

    std::list<EQApp::Waypoint*> openedList;
    std::list<EQApp::Waypoint*> closedList;
    std::list<EQApp::Waypoint*>::iterator waypointListIterator;

    uint32_t numIterations = 0;
    uint32_t maxIterations = 100;

    openedList.push_back(start);
    start->isOpened = true;

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

        for (auto& connectIndex : current->connectList)
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

    while (current->parent != NULL && current != start)
    {
        pathList.push_back(current->index);
        current = current->parent;
        numIterations++;
    }

    std::reverse(pathList.begin(), pathList.end());

    return pathList;
}

void EQAPP_Waypoint_PrintPath(EQApp::WaypointPathList& pathList, uint32_t fromIndex)
{
    std::cout << "Waypoint Path: " << fromIndex << " -> ";

    for (auto& pathIndex : pathList)
    {
        std::cout << pathIndex;

        if (&pathIndex != &pathList.back())
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

void EQAPP_WaypointList_Clear()
{
    g_waypointList.clear();
}

void EQAPP_WaypointList_Load()
{
    g_waypointList.clear();

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/waypoints/" << zoneShortName << ".txt";

    std::string filePathStr = filePath.str();

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        uint32_t index;
        float y;
        float x;
        float z;
        char connect[1024];
        char name[1024];

        int result = sscanf_s(line.c_str(), "%d %f %f %f %s %s", &index, &y, &x, &z, connect, sizeof(connect), name, sizeof(name));

        if (result == 6)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQApp::Waypoint waypoint;
            waypoint.index = index;
            waypoint.y = y;
            waypoint.x = x;
            waypoint.z = z;
            waypoint.name = name;

            if (strcmp(connect, "none") != 0)
            {
                std::istringstream connectSplit(connect);
                std::vector<std::string> connectTokens;
                for (std::string connectToken; std::getline(connectSplit, connectToken, ','); waypoint.connectList.push_back(std::stoul(connectToken, nullptr, 10)));
            }

            g_waypointList.push_back(waypoint);
        }
    }

    std::stringstream ss;
    ss << "waypoints loaded from file: " << filePathStr;

    EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());

    file.close();
}

void EQAPP_WaypointList_Save()
{
    if (g_waypointList.empty() == true)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "waypoint list is empty");
        return;
    }

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/waypoints/" << zoneShortName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    for (auto& waypoint : g_waypointList)
    {
        // index y x z connect name
        std::stringstream ss;
        ss.precision(5);

        ss << waypoint.index << " " << waypoint.y << " " << waypoint.x << " " << waypoint.z << " ";

        if (waypoint.connectList.size() == 0)
        {
            ss << "none";
        }
        else
        {
            for (auto& connectIndex : waypoint.connectList)
            {
                ss << connectIndex;

                if (&connectIndex != &waypoint.connectList.back())
                {
                    ss << ",";
                }
            }
        }

        ss << " Waypoint_" << waypoint.index;

        file << ss.str() << std::endl;
    }

    std::stringstream ss;
    ss << "waypoints saved to file: " << filePathStr;

    EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());

    file.close();
}

void EQAPP_WaypointList_Print()
{
    std::cout << "Waypoint List: " << std::endl;

    if (g_waypointList.size() == 0)
    {
        std::cout << "empty" << std::endl;
        return;
    }

    for (auto& waypoint : g_waypointList)
    {
        std::cout << waypoint.index << " " << waypoint.y << " " << waypoint.x << " " << waypoint.z << " ";

        if (waypoint.connectList.size() == 0)
        {
            std::cout << "none";
        }
        else
        {
            for (auto& connect : waypoint.connectList)
            {
                std::cout << connect;

                if (&connect != &waypoint.connectList.back())
                {
                    std::cout << ",";
                }
            }
        }

        std::cout << " " << waypoint.name << std::endl;
    }
}

