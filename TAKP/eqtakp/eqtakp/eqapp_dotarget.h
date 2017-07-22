#pragma once

bool g_doTargetIsEnabled = true;

bool EQAPP_DoTarget_HandleEvent_do_target(class EQClass::EQPlayer* player, const char* findSpawnName_);

bool EQAPP_DoTarget_HandleEvent_do_target(class EQClass::EQPlayer* player, const char* findSpawnName_)
{
    if (findSpawnName_ == NULL)
    {
        return false;
    }

    std::string findSpawnName = findSpawnName_;
    if (findSpawnName.size() == 0)
    {
        return false;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == (EQ::Spawn_ptr)player)
        {
            spawn = spawn->Next;
            continue;
        }

        if (spawn->Type != EQ_SPAWN_TYPE_PLAYER)
        {
            spawn = spawn->Next;
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        if (spawnName.size() == 0)
        {
            spawn = spawn->Next;
            continue;
        }

        if (spawnName == findSpawnName)
        {
            EQ_SetTargetSpawn(spawn);

            std::cout << "DoTarget: " << spawnName << std::endl;

            return true;
        }

        spawn = spawn->Next;
    }

    return false;
}

