#pragma once

bool g_ESPIsEnabled = true;

float g_ESPSpawnDistanceMax = 400.0f;

std::vector<std::string> g_ESPSpawnList =
{
    "thorn drakeling",
    "Soulbinder"
};

void EQAPP_ESP_Execute();

void EQAPP_ESP_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == nullptr)
    {
        return;
    }

    EQ::Location playerLocation;
    playerLocation.X = playerSpawn->X;
    playerLocation.Y = playerSpawn->Y;
    playerLocation.Z = playerSpawn->Z;

    auto targetSpawn = EQ_GetTargetSpawn();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != nullptr)
    {
        if (spawn == playerSpawn)
        {
            spawn = spawn->Next;
            continue;
        }

        std::string spawnName = EQ_CLASS_POINTER_CEverQuest->trimName(spawn->Name);

        EQ::Location spawnLocation;
        spawnLocation.X = spawn->X;
        spawnLocation.Y = spawn->Y;
        spawnLocation.Z = spawn->Z;

        float spawnDistance = EQ_CalculateDistance((float)spawnLocation.X, (float)spawnLocation.Y, (float)playerLocation.X, (float)playerLocation.Y);

        bool useDistance = true;

        for (auto& name : g_ESPSpawnList)
        {
            if (spawnName.find(name) != std::string::npos)
            {
                useDistance = false;
                break;
            }
        }

        if (spawn == targetSpawn || spawn->Type == EQ_SPAWN_TYPE_PLAYER || spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            useDistance = false;
        }

        if (EQ_IsKeyPressedAlt() == true)
        {
            useDistance = false;
        }

        if (useDistance == true)
        {
            if (spawnDistance > g_ESPSpawnDistanceMax)
            {
                spawn = spawn->Next;
                continue;
            }
        }

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(spawnLocation, screenX, screenY) == false)
        {
            spawn = spawn->Next;
            continue;
        }

        int textColor = EQ_TEXT_COLOR_WHITE;

        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            textColor = EQ_TEXT_COLOR_RED;
        }
        else if (spawn->Type == EQ_SPAWN_TYPE_NPC)
        {
            textColor = EQ_TEXT_COLOR_CYAN;
        }
        else
        {
            textColor = EQ_TEXT_COLOR_YELLOW;
        }

        if (EQ_IsSpawnGroupMember(spawn) == true)
        {
            textColor = EQ_TEXT_COLOR_LIGHT_GREEN;
        }

        if (spawn == targetSpawn)
        {
            textColor = EQ_TEXT_COLOR_PINK;
        }

        std::stringstream espText;

        espText << "[" << (int)spawn->Level;

        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            espText << " " << EQ_GetClassShortName(spawn->Class);
        }
        else if (spawn->Type == EQ_SPAWN_TYPE_NPC)
        {
            if (spawn->Class != EQ_CLASS_WARRIOR && spawn->Class != EQ_CLASS_BANKER && spawn->Class != EQ_CLASS_MERCHANT)
            {
                espText << " " << EQ_GetClassShortName(spawn->Class);
            }
        }

        espText << "] ";

        espText << spawnName;

        espText << " (" << (int)spawnDistance << ")";

        if (spawn->Type == EQ_SPAWN_TYPE_NPC)
        {
            if (spawn->Class == EQ_CLASS_BANKER)
            {
                espText << "\n(Banker)";
            }
            else if (spawn->Class == EQ_CLASS_MERCHANT)
            {
                espText << "\n(Merchant)";
            }
            else if (spawn->Class >= EQ_CLASS_GUILDMASTER_BEGIN && spawn->Class <= EQ_CLASS_GUILDMASTER_END)
            {
                espText << "\n(" << EQ_GetClassShortName(spawn->Class) << " Guildmaster)";
            }
        }

        EQ_DrawText(espText.str().c_str(), screenX, screenY, textColor);

        spawn = spawn->Next;
    }
}

