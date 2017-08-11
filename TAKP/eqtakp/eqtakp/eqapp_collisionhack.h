#pragma once

bool g_collisionHackIsEnabled = false;

bool g_collisionHackDebugIsEnabled = false;

void EQAPP_CollisionHack_Toggle();
void EQAPP_CollisionHack_Debug_Toggle();
void EQAPP_CollisionHack_HandleEvent_CollisionCallbackForMove(EQ::ActorInstance_ptr actorInstance, EQ::Spawn_ptr spawn);

void EQAPP_CollisionHack_Toggle()
{
    EQ_ToggleBool(g_collisionHackIsEnabled);
    EQAPP_PrintBool("Collision Hack", g_collisionHackIsEnabled);

    if (g_collisionHackIsEnabled == true)
    {
        EQ_SetActorCollision(false);

        std::cout << "You can now walk through players/npcs and doors and climb over most objects." << std::endl;
    }
    else
    {
        EQ_SetActorCollision(true);

        std::cout << "Collision has been restored to normal." << std::endl;
    }
}

void EQAPP_CollisionHack_Debug_Toggle()
{
    EQ_ToggleBool(g_collisionHackDebugIsEnabled);
    EQAPP_PrintBool("Collision Hack Debug", g_collisionHackDebugIsEnabled);
}

void EQAPP_CollisionHack_HandleEvent_CollisionCallbackForMove(EQ::ActorInstance_ptr actorInstance, EQ::Spawn_ptr spawn)
{
    if (actorInstance == NULL || spawn == NULL)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL || spawn != playerSpawn)
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

    if (g_collisionHackDebugIsEnabled == true)
    {
        std::cout << "Collision Hack Debug:" << std::endl;
        std::cout << "Name: " << actorInstance->ActorDefinition->Name << std::endl;
        std::cout << "Y: " << actorInstance->WorldY << std::endl;
        std::cout << "X: " << actorInstance->WorldX << std::endl;
        std::cout << "Z: " << actorInstance->WorldZ << std::endl;
        std::cout << "Region Number: " << actorInstance->RegionNumber << std::endl;
        std::cout << "Bounding Radius: " << actorInstance->BoundingRadius << std::endl;
        std::cout << "Scale Factor: " << actorInstance->ScaleFactor << std::endl;
        std::cout << "Collision Size: " << actorInstance->ActorCollision->CollisionSize << std::endl;

        std::cout << "-" << std::endl;

        std::cout << "Magic Number: "  << (int)actorInstance->ActorDefinition->MagicNumber << std::endl;
        std::cout << "Magic Number 2: " << (int)actorInstance->ActorDefinition->MagicNumber2 << std::endl;
        std::cout << "Magic Number 3: " << (int)actorInstance->ActorDefinition->MagicNumber3 << std::endl;
        std::cout << "Magic Number 4: " << (int)actorInstance->ActorDefinition->MagicNumber4 << std::endl;
        std::cout << "Magic Number 5: " << (int)actorInstance->ActorDefinition->MagicNumber5 << std::endl;
        std::cout << "Magic Number 6: " << (int)actorInstance->ActorDefinition->MagicNumber6 << std::endl;
        std::cout << "Magic Number 7: " << (int)actorInstance->ActorDefinition->MagicNumber7 << std::endl;
        std::cout << "Magic Number 8: " << (int)actorInstance->ActorDefinition->MagicNumber8 << std::endl;
        std::cout << "Magic Number 9: " << (int)actorInstance->ActorDefinition->MagicNumber9 << std::endl;
        std::cout << "Magic Number 10: " << (int)actorInstance->ActorDefinition->MagicNumber10 << std::endl;
        std::cout << "Magic Number 11: " << (int)actorInstance->ActorDefinition->MagicNumber11 << std::endl;

        std::cout << "-" << std::endl;

        if (actorInstance->ActorDefinition->MagicNumber6 == 17)
        {
            if (actorInstance->UserData != NULL)
            {
                if (actorInstance->UserData->MagicNumber == 3)
                {
                    std::cout << "Spawn Name: " << actorInstance->UserData->Name << std::endl;
                }
            }
        }

        std::cout << " " << std::endl;
    }

    EQ_SetActorCollision(false);
}

