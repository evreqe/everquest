#pragma once

bool g_DestroyActorsIsEnabled = false;
bool g_DestroyActorsCreateActorExLogIsEnabled = false;

uint32_t g_DestroyActorsTimer = 0;
uint32_t g_DestroyActorsTimerDelay = 3000;

std::vector<std::string> g_DestroyActorsList;

void EQAPP_DestroyActors_Toggle();
void EQAPP_DestroyActors_LoadEx(char* zoneShortName);
void EQAPP_DestroyActors_Load();
void EQAPP_DestroyActors_DestroyByNameInList(uint32_t offsetActorList);
void EQAPP_DestroyActors_DestroyByIndex(uint32_t offsetActorList, uint32_t index);
void EQAPP_DestroyActors_Execute();
void EQAPP_DestroyActors_HandleEvent_EQGraphicsDLL__t3dCreateActorEx(EQ::ActorInstance_ptr actorInstance, EQ::ActorDefinition_ptr actorDefinition);

void EQAPP_DestroyActors_Toggle()
{
    EQ_ToggleBool(g_DestroyActorsIsEnabled);
    EQAPP_PrintBool("Destroy Actors", g_DestroyActorsIsEnabled);

    if (g_DestroyActorsIsEnabled == true)
    {
         EQAPP_DestroyActors_Load();
    }
}

void EQAPP_DestroyActors_CreateActorExLog_Toggle()
{
    EQ_ToggleBool(g_DestroyActorsCreateActorExLogIsEnabled);
    EQAPP_PrintBool("Destroy Actors CreateActorEx Log", g_DestroyActorsCreateActorExLogIsEnabled);
}

void EQAPP_DestroyActors_LoadEx(char* zoneShortName)
{
    std::cout << "Loading Destroy Actors..." << std::endl;

    std::string zoneShortNameStr = zoneShortName;
    if (zoneShortNameStr.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_DestroyActorsList.clear();
    g_DestroyActorsList.reserve(100);

    EQAPP_ReadFileToList("destroyactors.txt", g_DestroyActorsList);

    std::stringstream filePath;
    filePath << "destroyactors/" << zoneShortNameStr << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_DestroyActorsList);
}

void EQAPP_DestroyActors_Load()
{
    if (EQ_IsInGame() == true)
    {
        EQAPP_DestroyActors_LoadEx(EQ_POINTER_Zone.ShortName);
    }
}

void EQAPP_DestroyActors_DestroyByNameInList(uint32_t offsetActorList)
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();
    if (baseAddress == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_GRAPHICS_DLL_NUM_ACTOR_LIST_ACTORS_MAX; i++)
    {
        uint32_t actorListActor = EQ_ReadMemory<uint32_t>((baseAddress + offsetActorList) + (i * EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_SIZE));
        if (actorListActor == NULL)
        {
            break;
        }

        EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)EQ_ReadMemory<uint32_t>(actorListActor + EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_OFFSET_ACTOR_INSTANCE);
        if (actorInstance == NULL)
        {
            continue;
        }

        if (actorInstance->MagicNumber != 24 || actorInstance == (EQ::ActorInstance_ptr)EQ_ADDRESS_POINTER_CAMERA_ACTOR_INSTANCE)
        {
            continue;
        }

        if (actorInstance->ActorDefinition == NULL)
        {
            continue;
        }

        std::string actorDef = actorInstance->ActorDefinition->Name;
        if (actorDef.size() == 0)
        {
            continue;
        }

        for (auto& destroyActor : g_DestroyActorsList)
        {
            if (actorDef == destroyActor)
            {
                EQGraphicsDLL__t3dDestroyActor(EQ_POINTER_CDisplay->Unknown0004, actorInstance);
                break;
            }
        }
    }
}

void EQAPP_DestroyActors_DestroyByIndex(uint32_t offsetActorList, uint32_t index)
{
    uint32_t baseAddress = EQ_GraphicsDLL_GetBaseAddress();
    if (baseAddress == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_GRAPHICS_DLL_NUM_ACTOR_LIST_ACTORS_MAX; i++)
    {
        uint32_t actorListActor = EQ_ReadMemory<uint32_t>((baseAddress + offsetActorList) + (i * EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_SIZE));
        if (actorListActor == NULL)
        {
            break;
        }

        EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)EQ_ReadMemory<uint32_t>(actorListActor + EQ_GRAPHICS_DLL_ACTOR_LIST_ACTOR_OFFSET_ACTOR_INSTANCE);
        if (actorInstance == NULL)
        {
            continue;
        }

        if (actorInstance->MagicNumber != 24 || actorInstance == (EQ::ActorInstance_ptr)EQ_ADDRESS_POINTER_CAMERA_ACTOR_INSTANCE)
        {
            continue;
        }

        if (actorInstance->Index == index)
        {
            EQGraphicsDLL__t3dDestroyActor(EQ_POINTER_CDisplay->Unknown0004, actorInstance);
        }
    }
}

void EQAPP_DestroyActors_Execute()
{
    if (EQ_HasTimePassed(g_DestroyActorsTimer, g_DestroyActorsTimerDelay) == false)
    {
        return;
    }

    EQAPP_DestroyActors_DestroyByNameInList(EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_STATIC);
    EQAPP_DestroyActors_DestroyByNameInList(EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_DYNAMIC);
}

void EQAPP_DestroyActors_HandleEvent_EQGraphicsDLL__t3dCreateActorEx(EQ::ActorInstance_ptr actorInstance, EQ::ActorDefinition_ptr actorDefinition)
{
    if (actorInstance == NULL || actorDefinition == NULL)
    {
        return;
    }

    if (actorInstance->MagicNumber != 24 || actorInstance == (EQ::ActorInstance_ptr)EQ_ADDRESS_POINTER_CAMERA_ACTOR_INSTANCE)
    {
        return;
    }

    if (actorInstance->ActorDefinition == NULL)
    {
        return;
    }

    std::string actorDef = actorDefinition->Name;
    if (actorDef.size() == 0)
    {
        return;
    }

    if (g_DestroyActorsCreateActorExLogIsEnabled == true)
    {
        std::ofstream file;
        file.open("eqtakp/createactorexlog.txt", std::ios::app);
        file << actorDef << "    (" << actorInstance->Y << ", " << actorInstance->X << ", " << actorInstance->Z << ")\n";
        file.close();
    }

    if (g_DestroyActorsList.size() == 0)
    {
        return;
    }

    for (auto& destroyActor : g_DestroyActorsList)
    {
        if (actorDef == destroyActor)
        {
            EQGraphicsDLL__t3dDestroyActor(EQ_POINTER_CDisplay->Unknown0004, actorInstance);
            break;
        }
    }
}

