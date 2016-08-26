#ifndef EQAPP_WAYPOINT_H
#define EQAPP_WAYPOINT_H

typedef struct _EQAPPWAYPOINT
{
    unsigned int index;
    float y;
    float x;
    float z;
    std::vector<unsigned int> connectList;
    std::string name;

    // A* Star pathfinding algorithm
    bool isOpened;
    bool isClosed;
    unsigned int f = 0;
    unsigned int g = 0;
    unsigned int h = 0;
    struct _EQAPPWAYPOINT* parent = NULL;
} EQAPPWAYPOINT, *PEQAPPWAYPOINT;

std::vector<EQAPPWAYPOINT> g_waypointList;

typedef std::vector<unsigned int> EQAPPWaypointPathList;

void EQAPP_Waypoint_Add();
void EQAPP_Waypoint_Remove(unsigned int index);
void EQAPP_Waypoint_Connect(unsigned int fromIndex, unsigned int toIndex);
void EQAPP_Waypoint_Disconnect(unsigned int fromIndex, unsigned int toIndex);
PEQAPPWAYPOINT EQAPP_Waypoint_GetByIndex(unsigned int index);
unsigned int EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z);
unsigned int EQAPP_Waypoint_GetGScore(PEQAPPWAYPOINT waypoint1, PEQAPPWAYPOINT waypoint2);
unsigned int EQAPP_Waypoint_GetHScore(PEQAPPWAYPOINT waypoint1, PEQAPPWAYPOINT waypoint2);
void EQAPP_Waypoint_ComputeScores(PEQAPPWAYPOINT waypoint, PEQAPPWAYPOINT waypointEnd);
EQAPPWaypointPathList EQAPP_Waypoint_GetPath(unsigned int fromIndex, unsigned int toIndex);
void EQAPP_Waypoint_PrintPath(EQAPPWaypointPathList& pathList, unsigned int fromIndex);
void EQAPP_WaypointList_Clear();
void EQAPP_WaypointList_Load();
void EQAPP_WaypointList_Save();
void EQAPP_WaypointList_Print();

void EQAPP_Waypoint_Add()
{
    unsigned int index = 0;

    for (auto& waypoint_it = g_waypointList.begin(); waypoint_it != g_waypointList.end(); waypoint_it++)
    {
        if (waypoint_it->index == index)
        {
            index++;
            waypoint_it = g_waypointList.begin();
        }
    }

    DWORD spawnInfo = EQ_GetTargetSpawn();
    if (spawnInfo == NULL)
    {
        spawnInfo = EQ_GetPlayerSpawn();
        if (spawnInfo == NULL)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "target and player spawns are NULL");
            return;
        }
    }

    FLOAT spawnY = EQ_ReadMemory<FLOAT>(spawnInfo + 0x64);
    FLOAT spawnX = EQ_ReadMemory<FLOAT>(spawnInfo + 0x68);
    FLOAT spawnZ = EQ_ReadMemory<FLOAT>(spawnInfo + 0x6C);

    std::stringstream waypointName;
    waypointName << "Waypoint_" << index;

    EQAPPWAYPOINT waypoint;
    waypoint.index = index;
    waypoint.y = spawnY;
    waypoint.x = spawnX;
    waypoint.z = spawnZ;
    waypoint.name = waypointName.str();

    g_waypointList.push_back(waypoint);

    std::cout << "[error] " << __FUNCTION__ << ": added waypoint " << index << std::endl;
}

void EQAPP_Waypoint_Remove(unsigned int index)
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

void EQAPP_Waypoint_Connect(unsigned int fromIndex, unsigned int toIndex)
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

    PEQAPPWAYPOINT fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
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

    PEQAPPWAYPOINT toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
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

void EQAPP_Waypoint_Disconnect(unsigned int fromIndex, unsigned int toIndex)
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

    PEQAPPWAYPOINT fromWaypoint = EQAPP_Waypoint_GetByIndex(fromIndex);
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

    PEQAPPWAYPOINT toWaypoint = EQAPP_Waypoint_GetByIndex(toIndex);
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

PEQAPPWAYPOINT EQAPP_Waypoint_GetByIndex(unsigned int index)
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

unsigned int EQAPP_Waypoint_GetIndexNearestToLocation(float y, float x, float z)
{
    std::map<float, unsigned int> distanceList;

    for (auto& waypoint : g_waypointList)
    {
        float distance = EQ_CalculateDistance3d(x, y, z, waypoint.x, waypoint.y, waypoint.z);

        distanceList.insert(std::make_pair(distance, waypoint.index));
    }

    return distanceList.begin()->second;
}

unsigned int EQAPP_Waypoint_GetGScore(PEQAPPWAYPOINT waypoint1, PEQAPPWAYPOINT waypoint2)
{
    return waypoint1->g + ((waypoint2->x == waypoint1->x || waypoint2->y == waypoint1->y) ? 10 : 14);
}

unsigned int EQAPP_Waypoint_GetHScore(PEQAPPWAYPOINT waypoint1, PEQAPPWAYPOINT waypoint2)
{
    // manhattan distance
    //return (unsigned int)(abs(waypoint1->x - waypoint2->x) + abs(waypoint1->y - waypoint2->y) * 10);

    // euclidean distance
    return (unsigned int)(sqrt(pow(waypoint2->x - waypoint1->x, 2) + pow(waypoint2->y - waypoint1->y, 2) + pow(waypoint2->z - waypoint1->z, 2)));
}

void EQAPP_Waypoint_ComputeScores(PEQAPPWAYPOINT waypoint, PEQAPPWAYPOINT waypointEnd)
{
    waypoint->g = EQAPP_Waypoint_GetGScore(waypoint, waypoint->parent);
    waypoint->h = EQAPP_Waypoint_GetHScore(waypoint, waypointEnd);

    waypoint->f = waypoint->g + waypoint->h;
}

EQAPPWaypointPathList EQAPP_Waypoint_GetPath(unsigned int fromIndex, unsigned int toIndex)
{
    EQAPPWaypointPathList pathList;

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

    PEQAPPWAYPOINT start = EQAPP_Waypoint_GetByIndex(fromIndex);
    PEQAPPWAYPOINT end   = EQAPP_Waypoint_GetByIndex(toIndex);

    if (start == NULL || end == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "start or end waypoint is NULL");
        return pathList;
    }

    PEQAPPWAYPOINT current;
    PEQAPPWAYPOINT child;

    std::list<PEQAPPWAYPOINT> openedList;
    std::list<PEQAPPWAYPOINT> closedList;
    std::list<PEQAPPWAYPOINT>::iterator waypointListIterator;

    unsigned int numIterations = 0;
    unsigned int maxIterations = 100;

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
                unsigned int currentGScore = EQAPP_Waypoint_GetGScore(child, current);

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

void EQAPP_Waypoint_PrintPath(EQAPPWaypointPathList& pathList, unsigned int fromIndex)
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
    filePath << "eqapp/waypoints/" << zoneShortName << ".txt";

    std::ifstream file;
    file.open(filePath.str().c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

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

        unsigned int index;
        float y;
        float x;
        float z;
        char connect[1024];
        char name[1024];

        int result = sscanf_s(line.c_str(), "%d %f %f %f %s %s", &index, &y, &x, &z, connect, sizeof(connect), name, sizeof(name));

        if (result == 6)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPPWAYPOINT waypoint;
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
    ss << "waypoints loaded from file: " << filePath.str();

    EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());

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
    filePath << "eqapp/waypoints/" << zoneShortName << ".txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

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
    ss << "waypoints  saved to file: " << filePath.str();

    EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());

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

#endif // EQAPP_WAYPOINT_H
