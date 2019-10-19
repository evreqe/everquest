#pragma once

bool g_ActorCollisionIsEnabled = true;

EQApp::Timer g_ActorCollisionTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_ActorCollisionTimerInterval = 1;

bool g_ActorCollisionDebugIsEnabled = false;

bool g_ActorCollisionAllIsEnabled = false;
bool g_ActorCollisionPlayerIsEnabled = true;

std::vector<std::string> g_ActorCollisionActorDefinitionList;
uint32_t g_ActorCollisionActorDefinitionList_reserve = 1024;

std::set<std::string> g_ActorCollisionActorDefinitionDebugList;

void EQAPP_ActorCollision_Toggle();
void EQAPP_ActorCollision_On();
void EQAPP_ActorCollision_Off();
void EQAPP_ActorCollision_Debug_Toggle();
void EQAPP_ActorCollision_All_Toggle();
void EQAPP_ActorCollision_Player_Toggle();
void EQAPP_ActorCollision_Load();
void EQAPP_ActorCollision_PrintActorDefinitionList();
void EQAPP_ActorCollision_PrintActorDefinitionDebugList();
bool EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors(uint32_t cactor);
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

    g_ActorCollisionActorDefinitionDebugList.clear();
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
    g_ActorCollisionActorDefinitionList.clear();
    g_ActorCollisionActorDefinitionList.reserve(g_ActorCollisionActorDefinitionList_reserve);

    EQAPP_ReadFileToList("actorcollision.txt", g_ActorCollisionActorDefinitionList, false);

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zoneShortName.size() == 0");
        return;
    }

    std::stringstream folderFileName;
    folderFileName << "actorcollision/" << zoneShortName << ".txt";

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), g_ActorCollisionActorDefinitionList, false);
    if (result == true)
    {
        std::cout << "Actor Collision loaded from file: " << folderFileName.str() << std::endl;
    }
}

void EQAPP_ActorCollision_PrintActorDefinitionList()
{
    std::cout << "Actor Collision Actor Definition List:" << std::endl;

    for (auto& actorDefinition : g_ActorCollisionActorDefinitionList)
    {
        std::cout << actorDefinition << std::endl;
    }
}

void EQAPP_ActorCollision_PrintActorDefinitionDebugList()
{
    std::cout << "Actor Collision Actor Definition Debug List:" << std::endl;

    for (auto& actorDefinition : g_ActorCollisionActorDefinitionDebugList)
    {
        std::cout << actorDefinition << std::endl;
    }
}

bool EQAPP_ActorCollision_HandleEvent_CollisionCallbackForActors(uint32_t cactor)
{
    // cactor is EQData::ActorClient()->pcactorex and EQClass::CActorEx

    auto actorDefinitionObject = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_DEFINITION_OBJECT);
    if (actorDefinitionObject == NULL)
    {
        return false;
    }

    auto actorDefinitionAddress = EQ_ReadMemory<uint32_t>(actorDefinitionObject + EQ_OFFSET_ACTOR_DEFINITION_OBJECT_ACTOR_DEFINITION_ADDRESS);
    if (actorDefinitionAddress == NULL)
    {
        return false;
    }

    char actorDefinitionName[EQ_SIZE_ACTOR_DEFINITION_NAME];
    std::memmove(actorDefinitionName, (LPVOID)(actorDefinitionAddress), sizeof(actorDefinitionName));

    ////auto actorApplicationData = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_APPLICATION_DATA);

    auto actorY = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_Y);
    auto actorX = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_X);
    auto actorZ = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_Z);

    auto actorType = EQ_ReadMemory<uint32_t>(cactor + EQ_OFFSET_CActor_ACTOR_TYPE);

    auto actorCollisionScale = EQ_ReadMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE);

    if (g_ActorCollisionDebugIsEnabled == true)
    {
        g_ActorCollisionActorDefinitionDebugList.insert(actorDefinitionName);

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(actorY, actorX, actorZ, screenX, screenY);
        if (result == true)
        {
            std::stringstream drawText;
            drawText << "[Actor] " << actorDefinitionName;

            drawText << "\nAddress: 0x" << std::hex << cactor << std::dec;

            ////drawText << "\nAD: 0x" << fmt::hex(actorApplicationData);

            drawText << "\nType: " << actorType;

            drawText << "\nY: " << actorY;
            drawText << "\nX: " << actorX;
            drawText << "\nZ: " << actorZ;

            drawText << "\nC: " << actorCollisionScale;

            EQ_DrawTextByColor(drawText.str().c_str(), (int)screenX, (int)screenY, EQ_DRAW_TEXT_COLOR_WHITE);
        }
    }

    for (auto& actorDefinitionListName : g_ActorCollisionActorDefinitionList)
    {
        if (EQAPP_String_BeginsWith(actorDefinitionListName, "!") == true)
        {
            std::string trimmedName = actorDefinitionListName;

            trimmedName.erase(0, 1);

            if (strcmp(actorDefinitionName, trimmedName.c_str()) == 0)
            {
                EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 1.0f); // collision

                return false; // collision
            }
        }

        if (EQAPP_String_BeginsWith(actorDefinitionListName, "@") == true)
        {
            std::string trimmedName = actorDefinitionListName;

            trimmedName.erase(0, 1);

            if (strcmp(actorDefinitionName, trimmedName.c_str()) == 0)
            {
                return true; // walk through or climb up and over
            }
        }

        if (EQAPP_String_BeginsWith(actorDefinitionListName, "*") == true)
        {
            std::string trimmedName = actorDefinitionListName;

            trimmedName.erase(0, 1);

            if (strcmp(actorDefinitionName, trimmedName.c_str()) == 0)
            {
                if (EQ_IsAutoRunEnabled() == true)
                {
                    EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 0.0f); // no collision

                    return true;
                }
                else
                {
                    EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 1.0f); // collision

                    return false;
                }
            }
        }

        if (EQAPP_String_BeginsWith(actorDefinitionListName, "^") == true)
        {
            std::string trimmedName = actorDefinitionListName;

            trimmedName.erase(0, 1);

            if (strcmp(actorDefinitionName, trimmedName.c_str()) == 0)
            {
                // move it below the world
                EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_Z, -20000.0f);
                EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_Z, -20000.0f);
                EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_MODEL_Z, -20000.0f);

                EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 0.0f); // no collision

                return true;
            }
        }

        if (strcmp(actorDefinitionName, actorDefinitionListName.c_str()) == 0)
        {
            EQ_WriteMemory<float>(cactor + EQ_OFFSET_CActor_COLLISION_SCALE, 0.0f); // no collision

            return true;
        }
    }

    return false;
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
