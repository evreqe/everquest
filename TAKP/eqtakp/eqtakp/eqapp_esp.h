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
        bool IsNamedSpawn = false;
        bool IsTarget = false;
        bool IsPet = false;
        bool IsYourPet = false;
        bool IsGroupMember = false;
        bool IsInvisible = false;
        bool IsLinkDead = false;
        bool IsFollowed = false;
        std::string Text;
        uint32_t TextColor = EQ_TEXT_COLOR_WHITE;
        uint32_t FontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL14;
        uint32_t SkeletonLineColorARGB = 0xFF808080;
    } ESPSpawn, *ESPSpawn_ptr;
}

bool g_ESPIsEnabled = true;

bool g_ESPShowSpawnID = false;
bool g_ESPShowStandingState = true;

float g_ESPSpawnDistanceMax = 400.0f;
float g_ESPSpawnDistanceZMax = 10.0f;

bool g_ESPSkeletonsIsEnabled = false;

float g_ESPSkeletonsDistanceMax = 100.0f;

uint32_t g_ESPSkeletonsNumBoneLinesDrawn = 0;
uint32_t g_ESPSkeletonsNumBoneLinesMax = 200;

uint32_t g_ESPFontPointerDefault = EQ_ADDRESS_POINTER_FONT_ARIAL14;
uint32_t g_ESPFontPointerFarAway = EQ_ADDRESS_POINTER_FONT_ARIAL12;

std::vector<EQApp::ESPSpawn> g_ESPSpawnList;

uint32_t g_ESPSpawnListTimer = 0;
uint32_t g_ESPSpawnListTimerDelay = 1000;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_Skeletons_Toggle();
void EQAPP_ESP_ShowSpawnID_Toggle();
void EQAPP_ESP_DrawLineBetweenBones(EQ::ModelBone_ptr bone1, EQ::ModelBone_ptr bone2, uint32_t lineColorARGB);
void EQAPP_ESP_DrawSkeleton(EQ::ModelBone_ptr bone, uint32_t lineColorARGB);
void EQAPP_ESP_DrawSkeletonForSpawn(EQ::Spawn_ptr spawn, uint32_t lineColorARGB);
bool EQAPP_ESP_Functor_SortSpawnListByDistance(const EQApp::ESPSpawn& spawn1, const EQApp::ESPSpawn& spawn2);
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

void EQAPP_ESP_Skeletons_Toggle()
{
    EQ_ToggleBool(g_ESPSkeletonsIsEnabled);
    EQAPP_PrintBool("ESP Skeletons", g_ESPSkeletonsIsEnabled);
}

void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnID);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnID);
}

void EQAPP_ESP_DrawLineBetweenBones(EQ::ModelBone_ptr bone1, EQ::ModelBone_ptr bone2, uint32_t lineColorARGB)
{
    if (bone1 == NULL || bone2 == NULL)
    {
        return;
    }

    EQ::Location location1 = {bone1->Y, bone1->X, bone1->Z};
    EQ::Location location2 = {bone2->Y, bone2->X, bone2->Z};

    float screenX1 = 0.0f;
    float screenY1 = 0.0f;
    if (EQ_WorldSpaceToScreenSpaceFloat(location1, screenX1, screenY1) == false)
    {
        return;
    }

    float screenX2 = 0.0f;
    float screenY2 = 0.0f;
    if (EQ_WorldSpaceToScreenSpaceFloat(location2, screenX2, screenY2) == false)
    {
        return;
    }

    if (screenX1 < 0.0 || screenY1 < 0.0 || screenX2 < 0.0 || screenY2 < 0.0)
    {
        return;
    }

    EQ::Line line;
    line.X1 = screenX1;
    line.Y1 = screenY1;
    line.Z1 = 1.0f;
    line.X2 = screenX2;
    line.Y2 = screenY2;
    line.Z2 = 1.0f;

    EQGraphicsDLL__t3dDeferLine(&line, lineColorARGB);

    g_ESPSkeletonsNumBoneLinesDrawn++;
}

void EQAPP_ESP_DrawSkeleton(EQ::ModelBone_ptr bone, uint32_t lineColorARGB)
{
    // note: this is a recursive function, it calls itself

    if (bone == NULL)
    {
        return;
    }

    if (bone->NumChildren == 0)
    {
        return;
    }

    for (size_t i = 0; i < bone->NumChildren; i++)
    {
        if (bone->ChildBones->Child[i] == NULL)
        {
            continue;
        }

        if (strstr(bone->ChildBones->Child[i]->Name, "POINT") == NULL)
        {
            ////std::cout << "Bone Name: " << bone->ChildBones->Child[i]->Name << std::endl;

            EQAPP_ESP_DrawLineBetweenBones(bone, bone->ChildBones->Child[i], lineColorARGB);
        }

        EQAPP_ESP_DrawSkeleton(bone->ChildBones->Child[i], lineColorARGB);
    }
}

void EQAPP_ESP_DrawSkeletonForSpawn(EQ::Spawn_ptr spawn, uint32_t lineColorARGB)
{
    if (spawn == NULL)
    {
        return;
    }

    if (spawn->Actor == NULL)
    {
        return;
    }

    if (spawn->Actor->Model == NULL)
    {
        return;
    }

    EQ::ModelBone_ptr rootBone = spawn->Actor->Model->RootBone;
    if (rootBone == NULL)
    {
        return;
    }

    if (rootBone->NumChildren == 0)
    {
        return;
    }

    EQ::ModelBone_ptr firstBone = rootBone->ChildBones->Child[0];
    if (firstBone == NULL)
    {
        return;
    }

    if (firstBone->NumChildren == 0)
    {
        return;
    }

    EQAPP_ESP_DrawSkeleton(firstBone, lineColorARGB);
}

bool EQAPP_ESP_Functor_SortSpawnListByDistance(const EQApp::ESPSpawn& spawn1, const EQApp::ESPSpawn& spawn2)
{
    return spawn1.Distance < spawn2.Distance;
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

        if (spawn->PetOwnerSpawnID != 0)
        {
            espSpawn.IsPet = true;
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
                    espSpawn.IsNamedSpawn = true;
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
        espSpawn.SkeletonLineColorARGB = 0xFF808080;

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER || espSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || espSpawn.IsYourPet == true)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_RED;
            espSpawn.SkeletonLineColorARGB = 0xFF800000;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            espSpawn.TextColor = EQ_TEXT_COLOR_CYAN;
            espSpawn.SkeletonLineColorARGB = 0xFF008080;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            if (espSpawn.IsInvisible == false)
            {
                espSpawn.TextColor = EQ_TEXT_COLOR_YELLOW;
                espSpawn.SkeletonLineColorARGB = 0xFF808000;
            }
            else
            {
                espSpawn.TextColor = EQ_TEXT_COLOR_GRAY;
                espSpawn.SkeletonLineColorARGB = 0xFF404040;
            }
        }

        if (EQ_IsSpawnGroupMember(spawn) == true)
        {
            espSpawn.IsGroupMember = true;

            espSpawn.TextColor = EQ_TEXT_COLOR_LIGHT_GREEN;
            espSpawn.SkeletonLineColorARGB = 0xFF008000;
        }

        if (spawn == targetSpawn)
        {
            espSpawn.IsTarget = true;

            espSpawn.TextColor = EQ_TEXT_COLOR_PINK;
            espSpawn.SkeletonLineColorARGB = 0xFF800080;
        }

        if (espSpawn.IsNamedSpawn == true)
        {
            espSpawn.FontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL16;
        }

        if (spawn == playerSpawn->Actor->FollowedSpawn)
        {
            espSpawn.IsFollowed = true;
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

        if (espSpawn.IsPet == true)
        {
            espText << "\n(Pet)";
        }

        if (espSpawn.IsFollowed == true)
        {
            espText << "\n*Following*";
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

        if (g_spawnCastSpellIsEnabled == true && g_spawnCastSpellESPIsEnabled == true)
        {
            for (auto& spawnCastSpell : g_spawnCastSpellList)
            {
                if (spawnCastSpell->Spawn == spawn)
                {
                    espText << "\n(" << spawnCastSpell->SpellName << ")";

                    if (spawnCastSpell->SpellCastTimeCountdown > 0)
                    {
                        float spellCastTimeCurrentFloat = (float)(spawnCastSpell->SpellCastTimeCountdown / 1000.0f);

                        espText.precision(1);
                        espText << " " << std::fixed << spellCastTimeCurrentFloat;
                    }

                    break;
                }
            }
        }

        espSpawn.Text = espText.str();

        g_ESPSpawnList.push_back(espSpawn);

        spawn = spawn->Next;
    }

    std::sort(g_ESPSpawnList.begin(), g_ESPSpawnList.end(), EQAPP_ESP_Functor_SortSpawnListByDistance);
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
    g_ESPSkeletonsNumBoneLinesDrawn = 0;

    EQAPP_ESP_UpdateSpawnList();

    for (auto& espSpawn : g_ESPSpawnList)
    {
        if (espSpawn.Spawn == NULL)
        {
            continue;
        }

        if (espSpawn.Spawn->SpawnID == espSpawn.SpawnID)
        {
            espSpawn.Location.X = espSpawn.Spawn->X;
            espSpawn.Location.Y = espSpawn.Spawn->Y;
            espSpawn.Location.Z = espSpawn.Spawn->Z;
        }

        if (g_ESPSkeletonsIsEnabled == true)
        {
            if (g_ESPSkeletonsNumBoneLinesDrawn < g_ESPSkeletonsNumBoneLinesMax)
            {
                if (espSpawn.Distance < g_ESPSkeletonsDistanceMax)
                {
                    EQAPP_ESP_DrawSkeletonForSpawn(espSpawn.Spawn, espSpawn.SkeletonLineColorARGB);
                }
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

