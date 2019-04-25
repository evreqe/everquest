#pragma once

namespace EQApp
{
    typedef struct _Path
    {
        uint32_t Index;
        float Y;
        float X;
        float Z;
        float Distance;
    } Path, *Path_ptr;

    typedef std::vector<EQApp::Path> PathList;
}

bool g_FindPathIsEnabled = true;

bool g_FindPathFollowPathIsEnabled = false;

float g_FindPathFollowPathDistance = 2.0f;

float g_FindPathDrawDistance = 400.0f;

EQApp::PathList g_FindPathFollowPathList;

uint32_t g_FindPathList_reserve = 128;

void EQAPP_FindPath_Toggle();
void EQAPP_FindPath_On();
void EQAPP_FindPath_Off();
void EQAPP_FindPath_FollowPath_Toggle();
void EQAPP_FindPath_FollowPath_On();
void EQAPP_FindPath_FollowPath_Off();
EQApp::PathList EQAPP_FindPath_GetPathList();
void EQAPP_FindPath_FollowPathList(EQApp::PathList& pathList);
bool EQAPP_FindPath_IsActive();
void EQAPP_FindPath_Draw();
void EQAPP_FindPath_FollowPath_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);
bool EQAPP_FindPath_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FindPath_Toggle()
{
    EQ_ToggleBool(g_FindPathIsEnabled);
    EQAPP_PrintBool("Find Path", g_FindPathIsEnabled);
}

void EQAPP_FindPath_On()
{
    if (g_FindPathIsEnabled == false)
    {
        EQAPP_FindPath_Toggle();
    }
}

void EQAPP_FindPath_Off()
{
    if (g_FindPathIsEnabled == true)
    {
        EQAPP_FindPath_Toggle();
    }
}

void EQAPP_FindPath_FollowPath_Toggle()
{
    EQ_ToggleBool(g_FindPathFollowPathIsEnabled);
    EQAPP_PrintBool("Find Path Follow Path", g_FindPathFollowPathIsEnabled);

    if (g_FindPathFollowPathIsEnabled == true)
    {
        EQ_StopFollow();

        g_FollowAISpawn = NULL;

        g_FindPathFollowPathList = EQAPP_FindPath_GetPathList();
        if (g_FindPathFollowPathList.size() == 0)
        {
            std::cout << "Path cannot be found." << std::endl;

            EQAPP_FindPath_FollowPath_Off();
            return;
        }
    }
    else
    {
        EQ_SetAutoRun(false);
    }
}

void EQAPP_FindPath_FollowPath_On()
{
    if (g_FindPathFollowPathIsEnabled == false)
    {
        EQAPP_FindPath_FollowPath_Toggle();
    }
}

void EQAPP_FindPath_FollowPath_Off()
{
    if (g_FindPathFollowPathIsEnabled == true)
    {
        EQAPP_FindPath_FollowPath_Toggle();
    }
}

EQApp::PathList EQAPP_FindPath_GetPathList()
{
    EQApp::PathList paths;

    paths.reserve(g_FindPathList_reserve);

    auto playerPath = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerPath);
    if (playerPath == NULL)
    {
        return paths;
    }

    auto isEnabled = EQ_ReadMemory<uint8_t>(playerPath + EQ_OFFSET_PlayerPath_IS_ENABLED);
    if (isEnabled == 0)
    {
        return paths;
    }

    auto arrayList = EQ_ReadMemory<uint32_t>(playerPath + EQ_OFFSET_PlayerPath_ARRAY_LIST);
    if (arrayList == NULL)
    {
        return paths;
    }

    auto beginY = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_Y);
    auto beginX = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_X);
    auto beginZ = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_Z);

    auto arrayListCount = EQ_ReadMemory<uint32_t>(playerPath + EQ_OFFSET_PlayerPath_ARRAY_LIST_COUNT);

    auto arrayObjectCount = EQ_ReadMemory<uint32_t>(playerPath + EQ_OFFSET_PlayerPath_ARRAY_OBJECT_COUNT);

    uint32_t index = 0;

    for (unsigned int i = 0; i < arrayListCount; i++)
    {
        auto arrayObject = EQ_ReadMemory<uint32_t>(arrayList + (i * 0x04));
        if (arrayObject == NULL)
        {
            break;
        }

        for (unsigned int j = 0; j < arrayObjectCount; j++)
        {
            // each coordinate is size 0x04
            // 0x04 * 3 = 0x0C

            auto y = EQ_ReadMemory<float>(arrayObject + ((j * 0x0C) + (0 * 0x04)));
            auto x = EQ_ReadMemory<float>(arrayObject + ((j * 0x0C) + (1 * 0x04)));
            auto z = EQ_ReadMemory<float>(arrayObject + ((j * 0x0C) + (2 * 0x04)));

            if (y == 0.0f && x == 0.0f)
            {
                break;
            }

            auto distance = EQ_CalculateDistance3D(y, x, z, beginY, beginX, beginZ);

            EQApp::Path path;
            path.Index = index;
            path.Y = y;
            path.X = x;
            path.Z = z;
            path.Distance = distance;

            paths.push_back(path);

            index++;
        }
    }

    std::reverse(paths.begin(), paths.end());

    // remove extraneous paths that aren't between the beginning and the end
    for (auto it = paths.begin(); it != paths.end(); it++)
    {
        auto path = (*it);

        if (path.Y != beginY && path.X != beginX && path.Z != beginZ)
        {
            it = paths.erase(it);
            it--;
            continue;
        }
        else
        {
            break;
        }
    }

    return paths;
}

void EQAPP_FindPath_FollowPathList(EQApp::PathList& pathList)
{
    if (pathList.size() == 0)
    {
        EQAPP_FindPath_FollowPath_Off();
        return;
    }

    auto playerPath = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerPath);
    if (playerPath == NULL)
    {
        return;
    }

    auto isEnabled = EQ_ReadMemory<uint8_t>(playerPath + EQ_OFFSET_PlayerPath_IS_ENABLED);
    if (isEnabled == 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto it = pathList.begin(); it != pathList.end(); it++)
    {
        auto path = (*it);

        float pathDistance = EQ_CalculateDistance(playerY, playerX, path.Y, path.X);
        if (pathDistance > g_FindPathFollowPathDistance)
        {
            EQ_TurnSpawnTowardsLocation(playerSpawn, path.Y, path.X);
            EQ_SetAutoRun(true);
            break;
        }
        else
        {
            auto itLast = std::prev(pathList.end());
            if (it == itLast)
            {
                EQAPP_FindPath_FollowPath_Off();
                return;
            }

            it = pathList.erase(it);
            it--;
            continue;
        }
    }
}

bool EQAPP_FindPath_IsActive()
{
    auto playerPath = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerPath);
    if (playerPath == NULL)
    {
        return false;
    }

    return EQ_ReadMemory<uint8_t>(playerPath + EQ_OFFSET_PlayerPath_IS_ENABLED);
}

void EQAPP_FindPath_Draw()
{
    auto playerPath = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerPath);
    if (playerPath == NULL)
    {
        return;
    }

    auto isEnabled = EQ_ReadMemory<uint8_t>(playerPath + EQ_OFFSET_PlayerPath_IS_ENABLED);
    if (isEnabled == 0)
    {
        return;
    }

    auto pathList = &g_FindPathFollowPathList;
    if (pathList->size() == 0)
    {
        return;
    }

    for (auto& path : *pathList)
    {
        if (path.Distance > g_FindPathDrawDistance)
        {
            continue;
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(path.Y, path.X, path.Z, screenX, screenY);
        if (result == true)
        {
            std::stringstream ss;
            ss << "P" << path.Index << " (" << (int)path.Distance << "m)";

            EQ_DrawTextByColor(ss.str().c_str(), (int)screenX, (int)screenY, EQ_DRAW_TEXT_COLOR_PINK);
        }
    }
}

void EQAPP_FindPath_FollowPath_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    //if (text == "A mystical path appears before you.")
    //{
        //EQAPP_FindPath_FollowPath_On();
    //}

    if (text == "The mystical path fades away." || text == "Mysterious forces prevent you from finding your destination easily.")
    {
        EQAPP_FindPath_FollowPath_Off();
    }
}

bool EQAPP_FindPath_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
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
        EQAPP_FindPath_FollowPath_Off();
        return true;
    }

    return false;
}
