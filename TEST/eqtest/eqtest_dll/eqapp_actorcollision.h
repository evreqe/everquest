#pragma once

bool g_ActorCollisionIsEnabled = true;

EQApp::Timer g_ActorCollisionTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_ActorCollisionTimerInterval = 1;

bool g_ActorCollisionDebugIsEnabled = false;

bool g_ActorCollisionAllIsEnabled = false;
bool g_ActorCollisionPlayerIsEnabled = true;

std::vector<std::string> g_ActorCollisionActorDefinitionList;
uint32_t g_ActorCollisionActorDefinitionList_reserve = 1024;

void EQAPP_ActorCollision_Toggle();
void EQAPP_ActorCollision_On();
void EQAPP_ActorCollision_Off();
void EQAPP_ActorCollision_Debug_Toggle();
void EQAPP_ActorCollision_All_Toggle();
void EQAPP_ActorCollision_Player_Toggle();
void EQAPP_ActorCollision_Load();
void EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors(uint32_t cactor);
bool EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors_Player(uint32_t cactor);

void EQAPP_ActorCollision_Toggle()
{
    EQ_ToggleBool(g_ActorCollisionIsEnabled);
    EQAPP_PrintBool("Actor Collision", g_ActorCollisionIsEnabled);
}

void EQAPP_ActorCollision_On()
{
    if (g_ActorCollisionIsEnabled == false)
    {
        EQAPP_ActorCollision_Toggle();
    }
}

void EQAPP_ActorCollision_Off()
{
    if (g_ActorCollisionIsEnabled == true)
    {
        EQAPP_ActorCollision_Toggle();
    }
}

void EQAPP_ActorCollision_Debug_Toggle()
{
    EQ_ToggleBool(g_ActorCollisionDebugIsEnabled);
    EQAPP_PrintBool("Actor Collision Debug", g_ActorCollisionDebugIsEnabled);
}

void EQAPP_ActorCollision_All_Toggle()
{
    EQ_ToggleBool(g_ActorCollisionAllIsEnabled);
    EQAPP_PrintBool("Actor Collision All", g_ActorCollisionAllIsEnabled);
}

void EQAPP_ActorCollision_Player_Toggle()
{
    EQ_ToggleBool(g_ActorCollisionPlayerIsEnabled);
    EQAPP_PrintBool("Actor Collision Player", g_ActorCollisionPlayerIsEnabled);
}

void EQAPP_ActorCollision_Load()
{
    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zoneShortName.size() == 0");
        return;
    }

    g_ActorCollisionActorDefinitionList.clear();
    g_ActorCollisionActorDefinitionList.reserve(g_ActorCollisionActorDefinitionList_reserve);

    EQAPP_ReadFileToList("actorcollision.txt", g_ActorCollisionActorDefinitionList, false);

    std::stringstream folderFileName;
    folderFileName << "actorcollision/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(folderFileName.str().c_str(), g_ActorCollisionActorDefinitionList, false);
}

void EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors(uint32_t cactor)
{
    auto actorDefinitionObject = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_DEFINITION_OBJECT);
    auto actorDefinitionAddress = EQ_ReadMemory<uint32_t>(actorDefinitionObject + EQ_OFFSET_ACTOR_DEFINITION_OBJECT_ACTOR_DEFINITION_ADDRESS);

    char actorDefinitionName[EQ_SIZE_ACTOR_DEFINITION_NAME];
    std::memmove(actorDefinitionName, (LPVOID)(actorDefinitionAddress), sizeof(actorDefinitionName));

    if (g_ActorCollisionDebugIsEnabled == true)
    {
        ////std::cout << "Actor Collision Debug: " << actorDefinitionName << std::endl;

        auto actorY = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_Y);
        auto actorX = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_X);
        auto actorZ = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_Z);

        auto actorType = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_TYPE);

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(actorY, actorX, actorZ, screenX, screenY);
        if (result == true)
        {
            fmt::MemoryWriter espText;
            espText << "[Actor] " << actorDefinitionName;

            espText << "\nType: " << actorType;

            espText << "\nY: " << actorY;
            espText << "\nX: " << actorX;
            espText << "\nZ: " << actorZ;

            EQ_DrawTextByColor(espText.c_str(), (int)screenX, (int)screenY, EQ_DRAW_TEXT_COLOR_WHITE);
        }
    }

    for (auto& actorDefinitionListName : g_ActorCollisionActorDefinitionList)
    {
        if (strcmp(actorDefinitionName, actorDefinitionListName.c_str()) == 0)
        {
            EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 0.0f); // no collision
        }
    }
}

bool EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors_Player(uint32_t cactor)
{
    uint32_t a1 = cactor;

    if (a1 == NULL)
    {
        return false;
    }

    /* disable collision with players */

    uint32_t v1 = ((CCollisionCallbackForActors1*)a1)->Call_0x20();
    if (v1 != NULL)
    {
        uint32_t v2 = ((CCollisionCallbackForActors1*)a1)->Call_0x30(); // get actor type    CActor::GetType()
        if (v2 == EQ_ACTOR_TYPE_PLAYER)
        {
            uint32_t v3 = ((CCollisionCallbackForActors2*)v1)->Call_0x0C();
            if (v3 != NULL)
            {
                uint32_t v4 = ((CCollisionCallbackForActors3*)v3)->Call_0x44(); // get application data or spawn
                if (v4 != NULL)
                {
                    auto spawnType = EQ_GetSpawnType(v4);
                    if (spawnType == EQ_SPAWN_TYPE_PLAYER)
                    {
                        return true; // no collision
                    }
                }
            }
        }
    }

    return false;
}
