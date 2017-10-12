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
        int Race;
        int Class;
        std::string ClassShortName;
        int GuildID;
        int StandingState;
        int HPCurrent;
        int HPMax;
        int PrimaryItemType;
        int SecondaryItemType;
        bool ShowAtAnyDistance = false;
        bool IsNamedSpawn = false;
        bool IsNewSpawn = false;
        bool IsTarget = false;
        bool IsPet = false;
        bool IsYourPet = false;
        bool IsGroupMember = false;
        bool IsInvisible = false;
        bool IsLinkDead = false;
        bool IsFollowed = false;
        bool IsHoldingPrimaryItem = false;
        bool IsHoldingSecondaryItem = false;
        bool IsTrader = false;
        std::string Text;
        uint32_t TextColorARGB = EQ_COLOR_ARGB_WHITE;
        uint32_t FontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL14;
        uint32_t SkeletonLineColorARGB = EQ_COLOR_ARGB_GRAY;
    } ESPSpawn, *ESPSpawn_ptr;
}

bool g_ESPIsEnabled = true;

bool g_ESPSpawnsIsEnabled = true;
bool g_ESPSpawnSkeletonsIsEnabled = false;
bool g_ESPGroundSpawnsIsEnabled = true;
bool g_ESPDoorSpawnsIsEnabled = true;
bool g_ESPActorsIsEnabled = false;

bool g_ESPShowNamedSpawnsOnly = false;

bool g_ESPShowSpawnID = false;
bool g_ESPShowSpawnRace = false;
bool g_ESPShowSpawnStandingState = true;
bool g_ESPShowSpawnWeapon = false;

bool g_ESPShowActorIndex = false;

float g_ESPSpawnDistanceMax = 400.0f;
float g_ESPSpawnDistanceZMax = 10.0f;

float g_ESPSpawnSkeletonsDistanceMax = 100.0f;

uint32_t g_ESPSpawnSkeletonsNumBoneLinesDrawn = 0;
uint32_t g_ESPSpawnSkeletonsNumBoneLinesMax = 200;

uint32_t g_ESPFontPointerDefault = EQ_ADDRESS_POINTER_FONT_ARIAL14;
uint32_t g_ESPFontPointerFarAway = EQ_ADDRESS_POINTER_FONT_ARIAL12;

std::vector<EQApp::ESPSpawn> g_ESPSpawnList;

uint32_t g_ESPSpawnListTimer = 0;
uint32_t g_ESPSpawnListTimerDelay = 1000;

void EQAPP_ESP_Toggle();
void EQAPP_ESP_Spawns_Toggle();
void EQAPP_ESP_GroundSpawns_Toggle();
void EQAPP_ESP_DoorSpawns_Toggle();
void EQAPP_ESP_Actors_Toggle();
void EQAPP_ESP_SpawnSkeletons_Toggle();
void EQAPP_ESP_ShowSpawnID_Toggle();
void EQAPP_ESP_ShowSpawnRace_Toggle();
void EQAPP_ESP_ShowSpawnWeapon_Toggle();
void EQAPP_ESP_ShowActorIndex_Toggle();
void EQAPP_ESP_DrawLineBetweenBones(EQ::ModelBone_ptr bone1, EQ::ModelBone_ptr bone2, uint32_t lineColorARGB);
void EQAPP_ESP_DrawSkeleton(EQ::ModelBone_ptr bone, uint32_t lineColorARGB);
void EQAPP_ESP_DrawSkeletonForSpawn(EQ::Spawn_ptr spawn, uint32_t lineColorARGB);
bool EQAPP_ESP_Sort_ESPSpawnByDistance(const EQApp::ESPSpawn& spawn1, const EQApp::ESPSpawn& spawn2);
void EQAPP_ESP_UpdateSpawnList();
void EQAPP_ESP_DrawDoorSpawns();
void EQAPP_ESP_DrawGroundSpawns();
void EQAPP_ESP_DrawSpawns();
void EQAPP_ESP_DrawActorList(uint32_t offsetActorList);
void EQAPP_ESP_DrawActors();
void EQAPP_ESP_Execute();

void EQAPP_ESP_Toggle()
{
    EQ_ToggleBool(g_ESPIsEnabled);
    EQAPP_PrintBool("ESP", g_ESPIsEnabled);
}

void EQAPP_ESP_Spawns_Toggle()
{
    EQ_ToggleBool(g_ESPSpawnsIsEnabled);
    EQAPP_PrintBool("ESP Spawns", g_ESPSpawnsIsEnabled);
}

void EQAPP_ESP_GroundSpawns_Toggle()
{
    EQ_ToggleBool(g_ESPGroundSpawnsIsEnabled);
    EQAPP_PrintBool("ESP Ground Spawns", g_ESPGroundSpawnsIsEnabled);
}

void EQAPP_ESP_DoorSpawns_Toggle()
{
    EQ_ToggleBool(g_ESPDoorSpawnsIsEnabled);
    EQAPP_PrintBool("ESP Door Spawns", g_ESPDoorSpawnsIsEnabled);
}

void EQAPP_ESP_Actors_Toggle()
{
    EQ_ToggleBool(g_ESPActorsIsEnabled);
    EQAPP_PrintBool("ESP Actors", g_ESPActorsIsEnabled);
}

void EQAPP_ESP_SpawnSkeletons_Toggle()
{
    EQ_ToggleBool(g_ESPSpawnSkeletonsIsEnabled);
    EQAPP_PrintBool("ESP Spawn Skeletons", g_ESPSpawnSkeletonsIsEnabled);
}

void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnID);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnID);
}

void EQAPP_ESP_ShowSpawnRace_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnRace);
    EQAPP_PrintBool("ESP Show Spawn Race", g_ESPShowSpawnRace);
}

void EQAPP_ESP_ShowSpawnWeapon_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnWeapon);
    EQAPP_PrintBool("ESP Show Spawn Weapon", g_ESPShowSpawnWeapon);
}

void EQAPP_ESP_ShowActorIndex_Toggle()
{
    EQ_ToggleBool(g_ESPShowActorIndex);
    EQAPP_PrintBool("ESP Show Actor Index", g_ESPShowActorIndex);
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

    g_ESPSpawnSkeletonsNumBoneLinesDrawn++;
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

bool EQAPP_ESP_Sort_ESPSpawnByDistance(const EQApp::ESPSpawn& spawn1, const EQApp::ESPSpawn& spawn2)
{
    return spawn1.Distance < spawn2.Distance;
}

void EQAPP_ESP_UpdateSpawnList()
{
    if (EQ_HasTimePassed(g_ESPSpawnListTimer, g_ESPSpawnListTimerDelay) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    g_ESPSpawnList.clear();
    g_ESPSpawnList.reserve(1000);

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
        espSpawn.Race = spawn->Race;
        espSpawn.Class = spawn->Class;
        espSpawn.ClassShortName = EQ_GetClassShortName(spawn->Class);
        espSpawn.GuildID = spawn->GuildID;
        espSpawn.StandingState = spawn->StandingState;
        espSpawn.HPCurrent = spawn->HPCurrent;
        espSpawn.HPMax = spawn->HPMax;
        espSpawn.PrimaryItemType = spawn->Actor->PrimaryItemType;
        espSpawn.SecondaryItemType = spawn->Actor->SecondaryItemType;

        espSpawn.Distance = EQ_CalculateDistance(spawn->X, spawn->Y, playerSpawn->X, playerSpawn->Y);
        espSpawn.DistanceZ = std::fabsf(spawn->Z - playerSpawn->Z);

        espSpawn.MovementSpeed = spawn->MovementSpeed;

        espSpawn.FontPointer = g_ESPFontPointerDefault;

        espSpawn.ShowAtAnyDistance = false;

        if (spawn->Actor->IsInvisible == 1)
        {
            espSpawn.IsInvisible = true;
        }

        if (spawn->Actor->PrimaryItemType != 0)
        {
            espSpawn.IsHoldingPrimaryItem = true;
        }

        if (spawn->Actor->SecondaryItemType != 0)
        {
            espSpawn.IsHoldingSecondaryItem = true;
        }

        if (spawn->Actor->IsTrader == 1)
        {
            espSpawn.IsTrader = true;
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

            if (g_ESPShowNamedSpawnsOnly == true)
            {
                if (espSpawn.IsNamedSpawn == false)
                {
                    spawn = spawn->Next;
                    continue;
                }
            }
        }

        if (g_spawnAlertIsEnabled == true && g_spawnAlertShowNewSpawn == true)
        {
            for (auto& spawnID : g_spawnAlertNewSpawnIDList)
            {
                if (spawnID == espSpawn.SpawnID)
                {
                    espSpawn.IsNewSpawn = true;
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

        espSpawn.TextColorARGB = EQ_COLOR_ARGB_WHITE;
        espSpawn.SkeletonLineColorARGB = 0xFF808080;

        if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER || espSpawn.IsYourPet == true)
        {
            espSpawn.TextColorARGB = EQ_COLOR_ARGB_RED;
            espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_MAROON;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            espSpawn.TextColorARGB = EQ_COLOR_ARGB_MAROON;
            espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_BLACK;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            espSpawn.TextColorARGB = EQ_COLOR_ARGB_AQUA;
            espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_TEAL;
        }
        else if (espSpawn.Type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            if (espSpawn.IsInvisible == false)
            {
                espSpawn.TextColorARGB = EQ_COLOR_ARGB_YELLOW;
                espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_OLIVE;
            }
            else
            {
                espSpawn.TextColorARGB = EQ_COLOR_ARGB_GRAY;
                espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_GRAY_DARK;
            }
        }

        if (espSpawn.Type != EQ_SPAWN_TYPE_PLAYER_CORPSE && espSpawn.Type != EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            if (espSpawn.IsTrader == true)
            {
                espSpawn.TextColorARGB = EQ_COLOR_ARGB_PINK;
                espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_WHITE;
            }

            if (EQ_IsSpawnGroupMember(spawn) == true)
            {
                espSpawn.IsGroupMember = true;

                espSpawn.TextColorARGB = EQ_COLOR_ARGB_LIME;
                espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_GREEN;
            }

            if (espSpawn.IsNamedSpawn == true)
            {
                espSpawn.FontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL16;

                espSpawn.TextColorARGB = EQ_COLOR_ARGB_GREEN_BLUE;
                espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_WHITE;
            }
        }

        if (spawn == targetSpawn)
        {
            espSpawn.IsTarget = true;

            espSpawn.TextColorARGB = EQ_COLOR_ARGB_FUCHSIA;
            espSpawn.SkeletonLineColorARGB = EQ_COLOR_ARGB_MAGENTA;
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

        if (espSpawn.IsNewSpawn == true)
        {
            espText << "\n*New Spawn*";
        }

        if (g_ESPShowSpawnStandingState == true)
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
                else if (espSpawn.StandingState == EQ_STANDING_STATE_FROZEN && espSpawn.IsLinkDead == false)
                {
                    espText << "\n*Frozen*";
                }
            }
        }

        if (espSpawn.IsLinkDead == true && espSpawn.Type == EQ_SPAWN_TYPE_PLAYER)
        {
            espText << "\n*Link Dead*";
        }

        if (g_ESPShowSpawnID == true)
        {
            espText << "\n(ID: 0x" << std::hex << espSpawn.SpawnID << std::dec << ")";
        }

        if (g_ESPShowSpawnRace == true)
        {
            espText << "\n(Race: " << espSpawn.Race << ")";
        }

        if (g_ESPShowSpawnWeapon == true)
        {
            if (espSpawn.IsHoldingPrimaryItem == true)
            {
                espText << "\n(Primary: ";

                auto it = EQ_STRING_MAP_ITEM_TYPE_NAME.find(espSpawn.PrimaryItemType);
                if (it == EQ_STRING_MAP_ITEM_TYPE_NAME.end())
                {
                    espText << espSpawn.PrimaryItemType;
                }
                else
                {
                    espText << it->second;
                }

                espText << "*";
            }

            if (espSpawn.IsHoldingSecondaryItem == true)
            {
                espText << "\n(Secondary: ";

                auto it = EQ_STRING_MAP_ITEM_TYPE_NAME.find(espSpawn.SecondaryItemType);
                if (it == EQ_STRING_MAP_ITEM_TYPE_NAME.end())
                {
                    espText << espSpawn.SecondaryItemType;
                }
                else
                {
                    espText << it->second;
                }

                espText << ")";
            }
        }

        if (g_spawnCastSpellIsEnabled == true && g_spawnCastSpellESPIsEnabled == true)
        {
            for (auto& spawnCastSpell : g_spawnCastSpellList)
            {
                if (spawnCastSpell->Spawn == NULL)
                {
                    continue;
                }

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

    std::sort(g_ESPSpawnList.begin(), g_ESPSpawnList.end(), EQAPP_ESP_Sort_ESPSpawnByDistance);
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

        EQ_DrawText(doorText.str().c_str(), screenX, screenY, EQ_COLOR_ARGB_WHITE);

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

        EQ_DrawText(groundSpawnText.str().c_str(), screenX, screenY, EQ_COLOR_ARGB_WHITE);

        groundSpawn = groundSpawn->Next;
    }
}

void EQAPP_ESP_DrawSpawns()
{
    g_ESPSpawnSkeletonsNumBoneLinesDrawn = 0;

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

        if (g_ESPSpawnSkeletonsIsEnabled == true)
        {
            if (g_ESPSpawnSkeletonsNumBoneLinesDrawn < g_ESPSpawnSkeletonsNumBoneLinesMax)
            {
                if (espSpawn.Distance < g_ESPSpawnSkeletonsDistanceMax)
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

        EQ_DrawTextEx(espSpawn.Text.c_str(), screenX, screenY, espSpawn.TextColorARGB, espSpawn.FontPointer);
    }
}

void EQAPP_ESP_DrawActorList(uint32_t offsetActorList)
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

        EQ::Location actorLocation;
        actorLocation.Y = actorInstance->Y;
        actorLocation.X = actorInstance->X;
        actorLocation.Z = actorInstance->Z;

        uint32_t screenX = 0;
        uint32_t screenY = 0;
        if (EQ_WorldSpaceToScreenSpace(actorLocation, screenX, screenY) == false)
        {
            continue;
        }

        std::stringstream actorText;
        actorText << "& " << actorDef;

        if (g_ESPShowActorIndex == true)
        {
            actorText << "\n(Index: " << actorInstance->Index << ")";
        }

        EQ_DrawText(actorText.str().c_str(), screenX, screenY, EQ_COLOR_ARGB_WHITE);
    }
}

void EQAPP_ESP_DrawActors()
{
    EQAPP_ESP_DrawActorList(EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_STATIC);
    EQAPP_ESP_DrawActorList(EQ_GRAPHICS_DLL_OFFSET_ACTOR_LIST_DYNAMIC);
}

void EQAPP_ESP_Execute()
{
    if (EQ_IsKeyPressedControl() == true)
    {
        return;
    }

    if (EQ_IsKeyPressedShift() == true)
    {
        g_ESPShowNamedSpawnsOnly = true;
    }
    else
    {
        g_ESPShowNamedSpawnsOnly = false;
    }

    if (g_ESPActorsIsEnabled == true)
    {
        EQAPP_ESP_DrawActors();
    }

    if (g_ESPDoorSpawnsIsEnabled == true)
    {
        EQAPP_ESP_DrawDoorSpawns();
    }

    if (g_ESPGroundSpawnsIsEnabled == true)
    {
        EQAPP_ESP_DrawGroundSpawns();
    }

    if (g_ESPSpawnsIsEnabled == true)
    {
        EQAPP_ESP_DrawSpawns();
    }
}


