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
}

bool g_FollowPathIsEnabled = false;

bool g_FollowPathAutomaticIsEnabled = false;

float g_FollowPathDistance = 15.0f;
float g_FollowPathEndDistance = 5.0f;

std::vector<EQApp::Path> g_FollowPathList;

uint32_t g_FollowPathList_reserve = 128;

void EQAPP_FollowPath_Toggle();
void EQAPP_FollowPath_On();
void EQAPP_FollowPath_Off();
void EQAPP_FollowPath_Automatic_Toggle();
std::vector<EQApp::Path> EQAPP_FollowPath_GetPaths();
void EQAPP_FollowPath_Execute();
bool EQAPP_FollowPath_IsActive();
void EQAPP_FollowPath_Draw();
void EQAPP_FollowPath_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor);
bool EQAPP_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FollowPath_Toggle()
{
    EQ_ToggleBool(g_FollowPathIsEnabled);
    EQAPP_PrintBool("Follow Path", g_FollowPathIsEnabled);

    if (g_FollowPathIsEnabled == true)
    {
        g_FollowPathList = EQAPP_FollowPath_GetPaths();
    }
    else
    {
        EQ_SetAutoRun(false);
    }
}

void EQAPP_FollowPath_On()
{
    if (g_FollowPathIsEnabled == false)
    {
        EQAPP_FollowPath_Toggle();
    }
}

void EQAPP_FollowPath_Off()
{
    if (g_FollowPathIsEnabled == true)
    {
        EQAPP_FollowPath_Toggle();
    }
}

void EQAPP_FollowPath_Automatic_Toggle()
{
    EQ_ToggleBool(g_FollowPathAutomaticIsEnabled);
    EQAPP_PrintBool("Follow Path Automatic", g_FollowPathAutomaticIsEnabled);
}

std::vector<EQApp::Path> EQAPP_FollowPath_GetPaths()
{
    std::vector<EQApp::Path> paths;

    paths.reserve(g_FollowPathList_reserve);

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

    bool bAtStart = false;

    uint32_t index = 0;

    for (unsigned int i = 0; i < arrayListCount; i++)
    {
        if (bAtStart == true)
        {
            break;
        }

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

            auto distance = EQ_CalculateDistance(y, x, beginY, beginX);
            if (distance < g_FollowPathDistance)
            {
                bAtStart = true;
                break;
            }

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

    return paths;
}

void EQAPP_FollowPath_Execute()
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

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    g_FollowPathList = EQAPP_FollowPath_GetPaths();

    if (g_FollowPathList.size() == 0)
     {
        return;
    }

    if (g_FollowPathList.size() > 0)
    {
        g_FollowPathList.pop_back();
    }

/*
    if (g_FollowPathList.size() > 0)
    {
        for (auto& path : g_FollowPathList)
        {
            std::cout << "i: " << path.Index << std::endl;
            std::cout << "y: " << path.Y << std::endl;
            std::cout << "x: " << path.X << std::endl;
            std::cout << "z: " << path.Z << std::endl;
            std::cout << "d: " << path.Distance << std::endl;
        }

        std::cout << "BY: " << g_FollowPathList.back().Y << std::endl;
        std::cout << "BX: " << g_FollowPathList.back().X << std::endl;
    }
*/

    auto playerY = EQ_GetSpawnY(playerSpawn);
    auto playerX = EQ_GetSpawnX(playerSpawn);
    auto playerZ = EQ_GetSpawnZ(playerSpawn);

    ////auto beginY = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_Y);
    ////auto beginX = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_X);
    ////auto beginZ = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_BEGIN_Z);

    auto endY = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_END_Y);
    auto endX = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_END_X);
    auto endZ = EQ_ReadMemory<float>(playerPath + EQ_OFFSET_PlayerPath_END_Z);

    ////auto beginDistance = EQ_CalculateDistance(playerY, playerX, beginY, beginX);
    auto endDistance = EQ_CalculateDistance(playerY, playerX, endY, endX);

    if (endDistance < g_FollowPathEndDistance)
    {
        EQAPP_FollowPath_Off();
    }
    else
    {
        if (g_FollowPathList.size() > 0)
        {
            EQ_TurnSpawnTowardsLocation(playerSpawn, g_FollowPathList.back().Y, g_FollowPathList.back().X);

            EQ_SetAutoRun(true);
        }
    }
}

bool EQAPP_FollowPath_IsActive()
{
    auto playerPath = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_PlayerPath);
    if (playerPath == NULL)
    {
        return false;
    }

    return EQ_ReadMemory<uint8_t>(playerPath + EQ_OFFSET_PlayerPath_IS_ENABLED);
}

void EQAPP_FollowPath_Draw()
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

    auto pathList = EQAPP_FollowPath_GetPaths();

    for (auto& path : pathList)
    {
        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(path.Y, path.X, path.Z, screenX, screenY);
        if (result == true)
        {
            fmt::MemoryWriter mw;
            mw << "P" << path.Index << " (" << (int)path.Distance << "m)";

            EQ_DrawTextByColor(mw.c_str(), (int)screenX, (int)screenY, EQ_DRAW_TEXT_COLOR_PINK);
        }
    }
}

void EQAPP_FollowPath_HandleEvent_CEverQuest__dsp_chat(std::string text, int textColor)
{
    if (text == "The mystical path fades away.")
    {
        EQAPP_FollowPath_Off();
    }
}

bool EQAPP_FollowPath_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1 && zero != 0)
    {
        return false;
    }

    if (commandID == EQ_EXECUTECMD_SIT_STAND)
    {
        EQAPP_FollowPath_Off();
        return true;
    }

    if
    (
        commandID == EQ_EXECUTECMD_FORWARD    ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        EQAPP_FollowPath_Off();
        return true;
    }

    return false;
}
