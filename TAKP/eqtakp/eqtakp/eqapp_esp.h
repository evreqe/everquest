#pragma once

namespace EQApp
{
    typedef struct _ESPSpawn
    {
        EQ::Spawn_ptr Spawn;
        uint16_t SpawnID;
        std::string Name;
        std::string LastName;
        EQ::Location Location;
        float Distance;
        float DistanceZ;
        float MovementSpeed;
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
        bool IsYourPet = false;
        bool IsGroupMember = false;
        bool IsInvisible = false;
        bool IsLinkDead = false;
        std::string Text;
        uint32_t TextColor = EQ_TEXT_COLOR_WHITE;
        uint32_t FontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL14;
    } ESPSpawn, *ESPSpawn_ptr;
}

bool g_ESPIsEnabled = true;

bool g_ESPShowSpawnID = false;
bool g_ESPShowStandingState = true;

float g_ESPSpawnDistanceMax = 400.0f;
float g_ESPSpawnDistanceZMax = 10.0f;

uint32_t g_ESPFontPointerDefault = EQ_ADDRESS_POINTER_FONT_ARIAL14;
uint32_t g_ESPFontPointerFarAway = EQ_ADDRESS_POINTER_FONT_ARIAL12;

std::vector<EQApp::ESPSpawn> g_ESPSpawnList;

uint32_t g_ESPSpawnListTimer = 0;
uint32_t g_ESPSpawnListTimerDelay = 1000;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_UpdateSpawnList();
void EQAPP_ESP_DrawDoorSpawns();
void EQAPP_ESP_DrawGroundSpawns();
void EQAPP_ESP_DrawSpawns();
void EQAPP_ESP_Execute();

void EQAPP_ESP_Toggle()
{
    EQ_ToggleBool(g_ESPIsEnabled);
    EQAPP_PrintBool("ESP", g_ESPIsEnabled);
}

void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnID);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnID);
}

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

        espSpawn.Spawn = spawn;

        espSpawn.SpawnID = spawn->SpawnID;

        espSpawn.Name = EQ_GetSpawnName(spawn);
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

        espSpawn.MovementSpeed = spawn->MovementSpeed;

        espSpawn.FontPointer = g_ESPFontPointerDefault;

        espSpawn.ShowAtAnyDistance = false;

        if (spawn->Actor->IsInvisible == 1)
        {
            espSpawn.IsInvisible = true;
        }

        if (spawn->IsLinkDead == 1)
        {
            espSpawn.IsLinkDead = true;
        }

        if (espSpawn.Distance > (g_ESPSpawnDistanceMax * 0.5f))
        {
            espSpawn.FontPointer = g_ESPFontPointerFarAway;
        }

        if (spawn->PetOwnerSpawnID == playerSpawn->SpawnID)
        {
            espSpawn.IsYourPet = true;
        }

        if (g_namedSpawnsIsEnabled == true)
        {
            for (auto& name : g_namedSpawnsList)
            {
                if (espSpawn.Name.find(name) != std::string::npos)
                {
                    espSpawn.ShowAtAnyDistance = true;
                    break;
                }
            }
        }

        if (spawn == targetSpawn || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || espSpawn.IsYourPet == true)
        {
            espSpawn.ShowAtAnyDistance = true;
        }

        if (EQ_IsMouseLookEnabled() == true)
        {
            espSpawn.ShowAtAnyDistance = true;
        }

        if (espSpawn.ShowAtAnyDistance == false)
        {
            if (EQ_IsZoneInList(EQ_ZONE_ID_LIST_VERTICAL) == true)
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

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || espSpawn.IsYourPet == true)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_RED;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_CYAN;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            if (espSpawn.IsInvisible == false)
            {
                espSpawn.TextColor = EQ_TEXT_COLOR_YELLOW;
            }
            else
            {
                espSpawn.TextColor = EQ_TEXT_COLOR_GRAY;
            }
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

        if (espSpawn.MovementSpeed > 0.0f)
        {
            espText << "* ";
        }

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

        if (g_ESPShowStandingState == true)
        {
            if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER)
            {
                if (espSpawn.StandingState == EQ_STANDING_STATE_FEIGN_DEATH)
                {
                    espText << "\n*Feign Death*";
                }
                else if (espSpawn.StandingState == EQ_STANDING_STATE_LOOTING)
                {
                    espText << "\n*Looting*";
                }
                else if (espSpawn.StandingState == EQ_STANDING_STATE_FROZEN)
                {
                    espText << "\n*Frozen*";
                }
            }
        }

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER && espSpawn.IsLinkDead == true)
        {
            espText << "\n*Link Dead*";
        }

        if (g_ESPShowSpawnID == true)
        {
            espText << "\n(ID: 0x" << std::hex << espSpawn.SpawnID << std::dec << ")";
        }

        espSpawn.Text = espText.str();

        g_ESPSpawnList.push_back(espSpawn);

        spawn = spawn->Next;
    }
}

void EQAPP_ESP_DrawDoorSpawns()
{
    auto door = EQ_GetFirstDoorSpawn();
    while (door != NULL)
    {
        std::string doorName = door->Name;
        if (doorName.size() == 0)
        {
            door = door->Next;
            continue;
        }

        auto it = EQ_STRING_MAP_DOOR_SPAWN_NAME.find(doorName);
        if (it == EQ_STRING_MAP_DOOR_SPAWN_NAME.end())
        {
            door = door->Next;
            continue;
        }
        else
        {
            doorName = it->second;
        }

        EQ::Location doorLocation;
        doorLocation.X = door->X;
        doorLocation.Y = door->Y;
        doorLocation.Z = door->Z;

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(doorLocation, screenX, screenY) == false)
        {
            door = door->Next;
            continue;
        }

        std::stringstream doorText;
        doorText << "@ " << doorName;

        EQ_DrawText(doorText.str().c_str(), screenX, screenY, EQ_TEXT_COLOR_WHITE);

        door = door->Next;
    }
}

void EQAPP_ESP_DrawGroundSpawns()
{
    auto groundSpawn = EQ_GetFirstGroundSpawn();
    while (groundSpawn != NULL)
    {
        std::string groundSpawnName = groundSpawn->ActorDef;
        if (groundSpawnName.size() == 0)
        {
            groundSpawn = groundSpawn->Next;
            continue;
        }

        auto it = EQ_STRING_MAP_GROUND_SPAWN_NAME.find(groundSpawnName);
        if (it == EQ_STRING_MAP_GROUND_SPAWN_NAME.end())
        {
            groundSpawn = groundSpawn->Next;
            continue;
        }
        else
        {
            groundSpawnName = it->second;
        }

        EQ::Location groundSpawnLocation;
        groundSpawnLocation.X = groundSpawn->X;
        groundSpawnLocation.Y = groundSpawn->Y;
        groundSpawnLocation.Z = groundSpawn->Z;

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(groundSpawnLocation, screenX, screenY) == false)
        {
            groundSpawn = groundSpawn->Next;
            continue;
        }

        std::stringstream groundSpawnText;
        groundSpawnText << "# " << groundSpawnName;

        EQ_DrawText(groundSpawnText.str().c_str(), screenX, screenY, EQ_TEXT_COLOR_WHITE);

        groundSpawn = groundSpawn->Next;
    }
}

void EQAPP_ESP_DrawSpawns()
{
    EQAPP_ESP_UpdateSpawnList();

    for (auto& espSpawn : g_ESPSpawnList)
    {
        if (espSpawn.Spawn != NULL)
        {
            if (espSpawn.Spawn->SpawnID == espSpawn.SpawnID)
            {
                espSpawn.Location.X = espSpawn.Spawn->X;
                espSpawn.Location.Y = espSpawn.Spawn->Y;
                espSpawn.Location.Z = espSpawn.Spawn->Z;
            }
        }

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(espSpawn.Location, screenX, screenY) == false)
        {
            continue;
        }

        EQ_DrawTextEx(espSpawn.Text.c_str(), screenX, screenY, espSpawn.TextColor, espSpawn.FontPointer);
    }
}

void EQAPP_ESP_Execute()
{
    if (EQ_IsKeyPressedControl() == true)
    {
        return;
    }

    EQAPP_ESP_DrawDoorSpawns();
    EQAPP_ESP_DrawGroundSpawns();
    EQAPP_ESP_DrawSpawns();
}

