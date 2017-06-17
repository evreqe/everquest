#pragma once

namespace EQApp
{
    typedef struct _ExtendedTargetsSpawn
    {
        EQ::Spawn_ptr Spawn;
        uint16_t SpawnID;
        std::string Name;
        std::string LastName;
        int Level;
        int Type;
        int Class;
        std::string ClassShortName;
        bool IsTarget = false;
        bool IsPet = false;
        bool IsYourPet = false;
        bool IsGroupMember = false;
        std::string Text;
        uint32_t TextColor = EQ_TEXT_COLOR_WHITE;
        uint32_t X;
        uint32_t Y;
        uint32_t Width;
        uint32_t Height;
    } ExtendedTargetsSpawn, *ExtendedTargetsSpawn_ptr;
}

bool g_extendedTargetsIsEnabled = true;

std::vector<EQApp::ExtendedTargetsSpawn> g_extendedTargetsSpawnList;

uint32_t g_extendedTargetsSpawnListTimer = 0;
uint32_t g_extendedTargetsSpawnListTimerDelay = 1000;

size_t g_extendedTargetsNumSpawns = 10;

float g_extendedTargetsSpawnDistanceMax = 100.0f;
float g_extendedTargetsSpawnDistanceZMax = 10.0f;

uint32_t g_extendedTargetsFontHeight = 1;

float g_extendedTargetsDefaultX = 4.0f;
float g_extendedTargetsDefaultY = 412.0f;

float g_extendedTargetsX = 4.0f;
float g_extendedTargetsY = 412.0f;

float g_extendedTargetsWidth  = 200.0f;
float g_extendedTargetsHeight = 200.0f;

uint32_t g_extendedTargetsBorderColorARGB     = 0xFF646464;
uint32_t g_extendedTargetsBackgroundColorARGB = 0x80000000;

void EQAPP_ExtendedTargets_Toggle();
void EQAPP_ExtendedTargets_Load();
void EQAPP_ExtendedTargets_RecalculateScreenCoordinates();
void EQAPP_ExtendedTargets_UpdateSpawnList();
void EQAPP_ExtendedTargets_Execute();
bool EQAPP_ExtendedTargets_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY);

void EQAPP_ExtendedTargets_Toggle()
{
    EQ_ToggleBool(g_extendedTargetsIsEnabled);
    EQAPP_PrintBool("Extended Targets", g_extendedTargetsIsEnabled);

    if (g_extendedTargetsIsEnabled == true)
    {
        EQAPP_ExtendedTargets_RecalculateScreenCoordinates();
    }
}

void EQAPP_ExtendedTargets_Load()
{
    g_extendedTargetsSpawnList.clear();

    EQAPP_ExtendedTargets_RecalculateScreenCoordinates();
}

void EQAPP_ExtendedTargets_RecalculateScreenCoordinates()
{
    g_extendedTargetsFontHeight = EQ_GetFontTextHeight(EQ_ADDRESS_POINTER_FONT_ARIAL14);

    uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);
    uint32_t resolutionHeight = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_HEIGHT);

    g_extendedTargetsX = (float)resolutionWidth - g_extendedTargetsDefaultX - g_extendedTargetsWidth;
    g_extendedTargetsY = (float)(g_extendedTargetsDefaultY + g_extendedTargetsFontHeight); // 4.0f + g_mapHeight + 8.0f + fontHeight;
}

void EQAPP_ExtendedTargets_UpdateSpawnList()
{
    if (EQ_HasTimePassed(g_extendedTargetsSpawnListTimer, g_extendedTargetsSpawnListTimerDelay) == false)
    {
        return;
    }

    g_extendedTargetsSpawnList.clear();

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();

    std::vector<std::pair<float, uint16_t>> spawnDistanceList; // float distance, uint16_t spawnID

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if (spawn == playerSpawn)
        {
            spawn = spawn->Next;
            continue;
        }

        if (spawn->Type != EQ_SPAWN_TYPE_PLAYER && spawn->Type != EQ_SPAWN_TYPE_NPC)
        {
            spawn = spawn->Next;
            continue;
        }

        float spawnDistance = EQ_CalculateDistance(spawn->X, spawn->Y, playerSpawn->X, playerSpawn->Y);
        if (spawnDistance > g_extendedTargetsSpawnDistanceMax)
        {
            spawn = spawn->Next;
            continue;
        }

        float spawnDistanceZ = std::fabsf(spawn->Z - playerSpawn->Z);
        if (spawnDistanceZ > g_extendedTargetsSpawnDistanceZMax)
        {
            spawn = spawn->Next;
            continue;
        }

        spawnDistanceList.push_back(std::make_pair(spawnDistance, spawn->SpawnID));

        spawn = spawn->Next;
    }

    std::sort(spawnDistanceList.begin(), spawnDistanceList.end());

    spawnDistanceList.resize(g_extendedTargetsNumSpawns);

    uint32_t spawnIndex = 0;

    for (auto& sdlSpawn : spawnDistanceList)
    {
        uint16_t spawnID = sdlSpawn.second;

        EQ::Spawn_ptr spawn = EQ_GetSpawnByID(spawnID);
        if (spawn == NULL)
        {
            continue;
        }

        EQApp::ExtendedTargetsSpawn etSpawn;

        etSpawn.Spawn = spawn;
        etSpawn.SpawnID = spawn->SpawnID;

        etSpawn.Name = EQ_CLASS_POINTER_CEverQuest->trimName(spawn->Name);
        etSpawn.LastName = spawn->LastName;

        etSpawn.Level = spawn->Level;
        etSpawn.Type = spawn->Type;
        etSpawn.Class = spawn->Class;
        etSpawn.ClassShortName = EQ_GetClassShortName(spawn->Class);

        if (spawn->PetOwnerSpawnID != 0)
        {
            etSpawn.IsPet = true;
        }

        if (spawn->PetOwnerSpawnID == playerSpawn->SpawnID)
        {
            etSpawn.IsYourPet = true;
        }

        etSpawn.TextColor = EQ_TEXT_COLOR_WHITE;

        if (etSpawn.Type == EQ_SPAWN_TYPE_PLAYER || etSpawn.Type == EQ_SPAWN_TYPE_PLAYER_CORPSE || etSpawn.IsYourPet == true)
        {
            etSpawn.TextColor = EQ_TEXT_COLOR_RED;
        }
        else if (etSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            etSpawn.TextColor = EQ_TEXT_COLOR_CYAN;
        }
        else if (etSpawn.Type == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            etSpawn.TextColor = EQ_TEXT_COLOR_YELLOW;
        }

        if (EQ_IsSpawnGroupMember(spawn) == true)
        {
            etSpawn.IsGroupMember = true;

            etSpawn.TextColor = EQ_TEXT_COLOR_LIGHT_GREEN;
        }

        if (spawn == targetSpawn)
        {
            etSpawn.IsTarget = true;

            etSpawn.TextColor = EQ_TEXT_COLOR_PINK;
        }

        std::stringstream etText;

        etText << "[" << etSpawn.Level;

        if (etSpawn.Type == EQ_SPAWN_TYPE_PLAYER)
        {
            etText << " " << etSpawn.ClassShortName;
        }
        else if (etSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            if ((etSpawn.Class != EQ_CLASS_WARRIOR) && (etSpawn.Class != EQ_CLASS_BANKER) && (etSpawn.Class != EQ_CLASS_MERCHANT))
            {
                etText << " " << etSpawn.ClassShortName;
            }
        }

        etText << "] ";

        etText << etSpawn.Name;

        if (etSpawn.Type == EQ_SPAWN_TYPE_NPC)
        {
            if (etSpawn.IsPet == true)
            {
                etText << " (Pet)";
            }

            if (etSpawn.Class == EQ_CLASS_BANKER)
            {
                etText << " (Banker)";
            }
            else if (etSpawn.Class == EQ_CLASS_MERCHANT)
            {
                etText << " (Merchant)";
            }
            else if ((etSpawn.Class >= EQ_CLASS_GUILDMASTER_BEGIN) && (etSpawn.Class <= EQ_CLASS_GUILDMASTER_END))
            {
                etText << " (Trainer)";
            }

            etText << "    0x" << std::hex << etSpawn.SpawnID << std::dec;
        }

        etSpawn.Text = etText.str();

        size_t fontWidth = EQ_GetFontTextWidth(etSpawn.Text.c_str(), EQ_ADDRESS_POINTER_FONT_ARIAL14);

        etSpawn.X = (uint32_t)g_extendedTargetsX;
        etSpawn.Y = (uint32_t)(g_extendedTargetsY + (spawnIndex * g_extendedTargetsFontHeight));
        etSpawn.Width = fontWidth;
        etSpawn.Height = g_extendedTargetsFontHeight;

        spawnIndex++;

        g_extendedTargetsSpawnList.push_back(etSpawn);
    }
}

void EQAPP_ExtendedTargets_Execute()
{
    EQAPP_ExtendedTargets_UpdateSpawnList();

    if (g_extendedTargetsSpawnList.size() == 0)
    {
        return;
    }

    size_t numExtendedTargets = g_extendedTargetsSpawnList.size();

    EQ_DrawRectangle
    (
        (float)g_extendedTargetsX - 4.0f,
        (float)(g_extendedTargetsY - g_extendedTargetsFontHeight),
        (float)g_extendedTargetsWidth,
        (float)((numExtendedTargets + 1) * g_extendedTargetsFontHeight),
        g_extendedTargetsBackgroundColorARGB, true
    );

    EQ_DrawRectangle
    (
        (float)g_extendedTargetsX - 4.0f,
        (float)(g_extendedTargetsY - g_extendedTargetsFontHeight),
        (float)g_extendedTargetsWidth,
        (float)((numExtendedTargets + 1) * g_extendedTargetsFontHeight),
        g_extendedTargetsBorderColorARGB, false
    );

    std::string etText = "Extended Targets: ";
    EQ_DrawText(etText.c_str(), (int)g_extendedTargetsX, (int)(g_extendedTargetsY - g_extendedTargetsFontHeight), EQ_TEXT_COLOR_WHITE);

    uint32_t mouseX = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_X);
    uint32_t mouseY = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_Y);

    for (auto& etSpawn : g_extendedTargetsSpawnList)
    {
        if (EQ_IsPointInsideRectangle(mouseX, mouseY, (int)etSpawn.X, (int)etSpawn.Y, (int)etSpawn.Width, (int)etSpawn.Height) == true)
        {
            if (EQ_IsMouseHoveringOverCXWnd() == false && EQ_IsMouseLookEnabled() == false)
            {
                EQ_DrawRectangle((float)etSpawn.X, (float)etSpawn.Y, (float)etSpawn.Width, (float)etSpawn.Height, EQ_TOOLTIP_TEXT_BACKGROUND_COLOR, true);
            }
        }

        EQ_DrawText(etSpawn.Text.c_str(), etSpawn.X, etSpawn.Y, etSpawn.TextColor);
    }
}

bool EQAPP_ExtendedTargets_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY)
{
    for (auto& etSpawn : g_extendedTargetsSpawnList)
    {
        if (EQ_IsPointInsideRectangle(mouseX, mouseY, etSpawn.X, etSpawn.Y, etSpawn.Width, etSpawn.Height) == true)
        {
            if (etSpawn.Spawn != NULL)
            {
                EQ_SetTargetSpawn(etSpawn.Spawn);
                return true;
            }
        }
    }

    return false;
}
