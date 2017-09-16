#pragma once

bool g_destroyActorsIsEnabled = true;

std::vector<std::string> g_destroyActorsList;

void EQAPP_DestroyActors_Load(char* zoneShortName);
void EQAPP_DestroyActors_HandleEvent_EQGraphicsDLL__t3dCreateActorEx(EQ::ActorInstance_ptr actorInstance, EQ::ActorDefinition_ptr actorDefinition);

void EQAPP_DestroyActors_Load(char* zoneShortName)
{
    std::cout << "Loading Destroy Actors..." << std::endl;

    std::string zoneShortNameStr = zoneShortName;
    if (zoneShortNameStr.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_destroyActorsList.clear();

    EQAPP_ReadFileToList("destroyactors.txt", g_destroyActorsList);

    std::stringstream filePath;
    filePath << "destroyactors/" << zoneShortNameStr << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_destroyActorsList);
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

    //std::ofstream file;
    //file.open("eqtakp/createactorexlog.txt", std::ios::app);
    //file << actorDef << "\n";

    if (g_destroyActorsList.size() == 0)
    {
        return;
    }

    for (auto& destroyActor : g_destroyActorsList)
    {
        if (actorDef == destroyActor)
        {
            EQGraphicsDLL__t3dDestroyActor(EQ_POINTER_CDisplay->Unknown0004, actorInstance);
        }
    }
}

