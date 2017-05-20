#pragma once

namespace EQApp
{
    typedef struct _ESPSpawn
    {
        EQ::Spawn_ptr SpawnInfo;
        uint16_t ID;
        std::string Name;
        std::string LastName;
        EQ::Location Location;
        float Distance;
        float DistanceZ;
        int Level;
        int Type;
        int Class;
        std::string ClassShortName;
        int GuildID;
        int StandingState;
        int HPCurrent;
        int HPMax;
        bool ShowAtAnyDistance = false;
        bool IsTarget = false;
        bool IsGroupMember = false;
        std::string Text;
        uint32_t TextColor = EQ_TEXT_COLOR_WHITE;
    } ESPSpawn, *ESPSpawn_ptr;
}

bool g_ESPIsEnabled = true;

float g_ESPSpawnDistanceMax = 400.0f;
float g_ESPSpawnDistanceZMax = 100.0f;

std::vector<EQApp::ESPSpawn> g_ESPSpawnList;
uint32_t g_ESPSpawnListTimer = 0;
uint32_t g_ESPSpawnListTimerDelay = 1000;

std::vector<std::string> g_ESPNamedSpawnList =
{
    "Soulbinder",
    "Banker",
    "Priest of Discord",
};

void EQAPP_ESP_UpdateSpawnList();
void EQAPP_ESP_Execute();

void EQAPP_ESP_UpdateSpawnList()
{
    if (EQ_HasTimePassed(g_ESPSpawnListTimer, g_ESPSpawnListTimerDelay) == false)
    {
        return;
    }

    g_ESPSpawnList.clear();

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = spawn->Next;
            continue;
        }

        EQApp::ESPSpawn espSpawn;

        espSpawn.SpawnInfo = spawn;

        espSpawn.ID = spawn->SpawnID;

        espSpawn.Name = EQ_CLASS_POINTER_CEverQuest->trimName(spawn->Name);
        espSpawn.LastName = spawn->LastName;

        espSpawn.Location.X = spawn->X;
        espSpawn.Location.Y = spawn->Y;
        espSpawn.Location.Z = spawn->Z;

        espSpawn.Level = spawn->Level;
        espSpawn.Type = spawn->Type;
        espSpawn.Class = spawn->Class;
        espSpawn.ClassShortName = EQ_GetClassShortName(spawn->Class);
        espSpawn.GuildID = spawn->GuildID;
        espSpawn.StandingState = spawn->StandingState;
        espSpawn.HPCurrent = spawn->HPCurrent;
        espSpawn.HPMax = spawn->HPMax;

        espSpawn.Distance = EQ_CalculateDistance(spawn->X, spawn->Y, playerSpawn->X, playerSpawn->Y);
        espSpawn.DistanceZ = std::fabsf(spawn->Z - playerSpawn->Z);

        espSpawn.ShowAtAnyDistance = true;

        for (auto& name : g_ESPNamedSpawnList)
        {
            if (espSpawn.Name.find(name) != std::string::npos)
            {
                espSpawn.ShowAtAnyDistance = false;
                break;
            }
        }

        if (spawn == targetSpawn || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            espSpawn.ShowAtAnyDistance = false;
        }

        if (EQ_IsKeyPressedControl() == true)
        {
            espSpawn.ShowAtAnyDistance = false;
        }

        if (espSpawn.ShowAtAnyDistance == true)
        {
            if (EQ_IsZoneVertical() == true)
            {
                if (espSpawn.DistanceZ > g_ESPSpawnDistanceZMax)
                {
                    spawn = spawn->Next;
                    continue;
                }
            }

            if (espSpawn.Distance > g_ESPSpawnDistanceMax)
            {
                spawn = spawn->Next;
                continue;
            }
        }

        espSpawn.TextColor = EQ_TEXT_COLOR_WHITE;

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_RED;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_CYAN;
        }
        else
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_YELLOW;
        }

        if (EQ_IsSpawnGroupMember(spawn) == true)
        {
            espSpawn.IsGroupMember = true;

            espSpawn.TextColor = EQ_TEXT_COLOR_LIGHT_GREEN;
        }

        if (spawn == targetSpawn)
        {
            espSpawn.IsTarget = true;

            espSpawn.TextColor = EQ_TEXT_COLOR_PINK;
        }

        std::stringstream espText;

        espText << "[" << espSpawn.Level;

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER)
        {
            espText << " " << espSpawn.ClassShortName;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            if ((espSpawn.Class != EQ_CLASS_WARRIOR) && (espSpawn.Class != EQ_CLASS_BANKER) && (espSpawn.Class != EQ_CLASS_MERCHANT))
            {
                espText << " " << espSpawn.ClassShortName;
            }
        }

        espText << "] ";

        espText << espSpawn.Name;

        espText << " (" << (int)espSpawn.Distance << ")";

        if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            if (espSpawn.Class == EQ_CLASS_BANKER)
            {
                espText << "\n(Banker)";
            }
            else if (espSpawn.Class == EQ_CLASS_MERCHANT)
            {
                espText << "\n(Merchant)";
            }
            else if ((espSpawn.Class >= EQ_CLASS_GUILDMASTER_BEGIN) && (espSpawn.Class <= EQ_CLASS_GUILDMASTER_END))
            {
                espText << "\n(" << espSpawn.ClassShortName << " Guildmaster)";
            }
        }

        espSpawn.Text = espText.str();

        g_ESPSpawnList.push_back(espSpawn);

        spawn = spawn->Next;
    }
}

void EQAPP_ESP_Execute()
{
    EQAPP_ESP_UpdateSpawnList();

    for (auto& spawn : g_ESPSpawnList)
    {
        if (spawn.SpawnInfo != NULL)
        {
            if (spawn.SpawnInfo->SpawnID == spawn.ID)
            {
                spawn.Location.X = spawn.SpawnInfo->X;
                spawn.Location.Y = spawn.SpawnInfo->Y;
                spawn.Location.Z = spawn.SpawnInfo->Z;
            }
        }

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(spawn.Location, screenX, screenY) == false)
        {
            continue;
        }

        EQ_DrawText(spawn.Text.c_str(), screenX, screenY, spawn.TextColor);
    }
}

