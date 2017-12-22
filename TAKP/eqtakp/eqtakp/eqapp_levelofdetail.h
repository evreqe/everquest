#pragma once

bool g_LevelOfDetailIsEnabled = false;

float g_LevelOfDetailDistance = 400.0f;

void EQAPP_LevelOfDetail_Toggle();

bool EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__t3dPaintHierarchicalSprite(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance);
bool EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__s3dPaintDMSprite2(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance);

void EQAPP_LevelOfDetail_Toggle()
{
    EQ_ToggleBool(g_LevelOfDetailIsEnabled);
    EQAPP_PrintBool("Level of Detail", g_LevelOfDetailIsEnabled);
}

bool EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__t3dPaintHierarchicalSprite(int* world, int* renderContext, EQ::ActorInstance_ptr actorInstance)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    if (actorInstance->Flags & 0x10000000) // ignore players/npcs, only cull objects
    {
        if (EQ_IsWithinDistance(playerSpawn->X, playerSpawn->Y, actorInstance->X, actorInstance->Y, g_LevelOfDetailDistance) == false)
        {
            return true;
        }
    }

    return false;
}

bool EQAPP_LevelOfDetail_HandleEvent_EQGraphicsDLL__s3dPaintDMSprite2(int* world, int* renderContext, int* actor)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    // TODO
    uint32_t unknown1 = EQ_ReadMemory<uint32_t>((uint32_t)world + 0x17C);
    uint32_t unknown2 = EQ_ReadMemory<uint32_t>(unknown1 + (4 * *actor));

    EQ::ActorInstance_ptr actorInstance = (EQ::ActorInstance_ptr)unknown2;

    ////if (actorInstance->Flags & 0x20000000) // TODO
    ////{
        if (EQ_IsWithinDistance(playerSpawn->X, playerSpawn->Y, actorInstance->X, actorInstance->Y, g_LevelOfDetailDistance) == false)
        {
            return true;
        }
    ////}

    return false;
}

