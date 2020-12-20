#pragma once

bool g_ESPIsEnabled = false;

bool g_ESPHeightFilterIsEnabled = false;

float g_ESPHeightFilterDistanceLow  = 10.0f;
float g_ESPHeightFilterDistanceHigh = 10.0f;

bool g_ESPShowSpawnsIsEnabled = true;
bool g_ESPShowSpawnIDIsEnabled = false;
bool g_ESPShowDoorsIsEnabled = false;

float g_ESPSpawnDistance = 400.0f;
float g_ESPDoorDistance  = 100.0f;

bool g_ESPFindLineIsEnabled = false;

bool g_ESPLineOfSightIsEnabled = false;

std::string g_ESPFindSpawnName;
std::string g_ESPFindSpawnLastName;
uint32_t g_ESPFindSpawnID = 0;
uint32_t g_ESPFindSpawnLevel = 0;

uint32_t g_ESPFindSpawnNameCount = 0;
uint32_t g_ESPFindSpawnLastNameCount = 0;
uint32_t g_ESPFindSpawnIDCount = 0;
uint32_t g_ESPFindSpawnLevelCount = 0;

int g_ESPSpawnClickX = -1;
int g_ESPSpawnClickY = -1;

float g_ESPSpawnClickDistance = 400.0f;

int g_ESPSpawnClickRadius = 25;

std::unordered_map<uint32_t, std::string> g_ESPSpawnTagList; // <uint32_t spawnID, std::string tag>

void EQAPP_ESP_Toggle();
void EQAPP_ESP_On();
void EQAPP_ESP_Off();
void EQAPP_ESP_HeightFilter_Toggle();
void EQAPP_ESP_FindLine_Toggle();
void EQAPP_ESP_LineOfSight_Toggle();
void EQAPP_ESP_ShowSpawnID_Toggle();
void EQAPP_ESP_ShowSpawns_Toggle();
void EQAPP_ESP_ShowDoors_Toggle();
void EQAPP_ESP_DrawSpawns();
void EQAPP_ESP_DrawDoors();
void EQAPP_ESP_Execute();
bool EQAPP_ESP_HandleEvent_CEverQuest__LMouseUp(int x, int y);

void EQAPP_ESP_Toggle()
{
    EQ_ToggleBool(g_ESPIsEnabled);
    EQAPP_PrintBool("ESP", g_ESPIsEnabled);
}

void EQAPP_ESP_On()
{
    if (g_ESPIsEnabled == false)
    {
        EQAPP_ESP_Toggle();
    }
}

void EQAPP_ESP_Off()
{
    if (g_ESPIsEnabled == true)
    {
        EQAPP_ESP_Toggle();
    }
}

void EQAPP_ESP_HeightFilter_Toggle()
{
    EQ_ToggleBool(g_ESPHeightFilterIsEnabled);
    EQAPP_PrintBool("ESP Height Filter", g_ESPHeightFilterIsEnabled);
}

void EQAPP_ESP_FindLine_Toggle()
{
    EQ_ToggleBool(g_ESPFindLineIsEnabled);
    EQAPP_PrintBool("ESP Find Line", g_ESPFindLineIsEnabled);
}

void EQAPP_ESP_LineOfSight_Toggle()
{
    EQ_ToggleBool(g_ESPLineOfSightIsEnabled);
    EQAPP_PrintBool("ESP Line of Sight", g_ESPLineOfSightIsEnabled);
}


void EQAPP_ESP_ShowSpawnID_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnIDIsEnabled);
    EQAPP_PrintBool("ESP Show Spawn ID", g_ESPShowSpawnIDIsEnabled);
}

void EQAPP_ESP_ShowSpawns_Toggle()
{
    EQ_ToggleBool(g_ESPShowSpawnsIsEnabled);
    EQAPP_PrintBool("ESP Show Spawns", g_ESPShowSpawnsIsEnabled);
}

void EQAPP_ESP_ShowDoors_Toggle()
{
    EQ_ToggleBool(g_ESPShowDoorsIsEnabled);
    EQAPP_PrintBool("ESP Show Doors", g_ESPShowDoorsIsEnabled);
}

void EQAPP_ESP_DrawSpawns()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    auto targetSpawn = EQ_GetTargetSpawn();

    g_ESPFindSpawnNameCount = 0;
    g_ESPFindSpawnLastNameCount = 0;
    g_ESPFindSpawnIDCount = 0;
    g_ESPFindSpawnLevelCount = 0;

    auto spawnList = EQ_GetSpawnList();
    for (auto spawnListIt = spawnList.begin(); spawnListIt != spawnList.end(); spawnListIt++)
    {
        auto spawn = *spawnListIt;
        if (spawn == NULL)
        {
            continue;
        }

        // move players to the back of the list
        auto spawnType = EQ_GetSpawnType(spawn);
        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            std::rotate(spawnListIt, spawnListIt + 1, spawnList.end());
        }
    }

    for (auto& spawn : spawnList)
    {
        if (spawn == NULL)
        {
            continue;
        }

        if (spawn == playerSpawn)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);
        std::string spawnLastName = EQ_GetSpawnLastName(spawn);

        auto spawnY = EQ_GetSpawnY(spawn);
        auto spawnX = EQ_GetSpawnX(spawn);
        auto spawnZ = EQ_GetSpawnZ(spawn);

        float spawnDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, spawnY, spawnX);

        auto spawnID = EQ_GetSpawnID(spawn);
        auto spawnType = EQ_GetSpawnType(spawn);
        auto spawnLevel = EQ_GetSpawnLevel(spawn);
        //auto spawnRace = EQ_GetSpawnRace(spawn);
        auto spawnClass = EQ_GetSpawnClass(spawn);

        auto spawnStandingState = EQ_GetSpawnStandingState(spawn);

        bool bIgnoreDistance = false;
        bool bOutOfRange = false;
        bool bDrawLine = false;
        bool bNewSpawn = false;
        bool bSpecialSpawn = false;

        for (auto& namedSpawnID : g_NamedSpawnsIDList)
        {
            if (spawnID == namedSpawnID)
            {
                bIgnoreDistance = true;
                break;
            }
        }

        for (auto& specialSpawnID : g_NamedSpawnsSpecialSpawnsIDList)
        {
            if (spawnID == specialSpawnID)
            {
                bIgnoreDistance = true;
                bSpecialSpawn = true;
                break;
            }
        }

        if (g_NamedSpawnsNewSpawnsIsEnabled == true)
        {
            for (auto& newSpawnID : g_NamedSpawnsNewSpawnsIDList)
            {
                if (spawnID == newSpawnID)
                {
                    bIgnoreDistance = true;
                    bNewSpawn = true;
                    break;
                }
            }
        }

        if (g_ESPFindSpawnName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnName, g_ESPFindSpawnName) == true)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnNameCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (g_ESPFindSpawnLastName.size() != 0)
        {
            if (EQAPP_String_Contains(spawnLastName, g_ESPFindSpawnLastName) == true)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnLastNameCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (g_ESPFindSpawnID != 0)
        {
            if (spawnID == g_ESPFindSpawnID)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnIDCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (g_ESPFindSpawnLevel != 0)
        {
            if (spawnLevel >= g_ESPFindSpawnLevel)
            {
                bIgnoreDistance = true;

                g_ESPFindSpawnLevelCount++;

                if (g_ESPFindLineIsEnabled == true)
                {
                    bDrawLine = true;
                }
            }
        }

        if (spawnDistance > g_ESPSpawnDistance)
        {
            bOutOfRange = true;
        }

        if (EQ_IsMouseLookEnabled() == false && bIgnoreDistance == false)
        {
            if (bOutOfRange == true)
            {
                continue;
            }

            if (g_ESPHeightFilterIsEnabled == true)
            {
                if (spawnZ < playerSpawnZ)
                {
                    if ((playerSpawnZ - spawnZ) > g_ESPHeightFilterDistanceLow)
                    {
                        continue;
                    }
                }
                else if (spawnZ > playerSpawnZ)
                {
                    if ((spawnZ - playerSpawnZ) > g_ESPHeightFilterDistanceHigh)
                    {
                        continue;
                    }
                }
            }
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(spawnY, spawnX, spawnZ, screenX, screenY);
        if (result == true)
        {
/*
            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (EQ_IsSpawnMount(spawn) == true)
                {
                    continue;
                }

                if (EQ_IsSpawnAura(spawn) == true)
                {
                    continue;
                }
            }
*/

            std::stringstream drawText;

            drawText << "[" << (int)spawnLevel;

            bool bShowSpawnClassShortName = true;

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (spawnClass == EQ_CLASS_WARRIOR || spawnClass == EQ_CLASS_BANKER || spawnClass == EQ_CLASS_MERCHANT)
                {
                    bShowSpawnClassShortName = false;
                }
            }

            if (bShowSpawnClassShortName == true)
            {
                auto spawnClassShortName = EQ_GetClassShortNameByID(spawnClass);
                if (spawnClassShortName.size() != 0)
                {
                    drawText << " " << spawnClassShortName;
                }
            }

            drawText << "] " << spawnName;

            if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                drawText << "'s corpse";
            }

            drawText << " (" << (int)spawnDistance << "m)";

            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                if (spawnStandingState == EQ_STANDING_STATE_FEIGN_DEATH)
                {
                    drawText << "\n* Feign Death *";
                }
            }

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (spawnLastName.size() != 0)
                {
                    drawText << "\n(" << spawnLastName << ")";
                }
            }

            if (g_ESPShowSpawnIDIsEnabled == true)
            {
                drawText << "\n(ID: " << spawnID << ")";
            }

            if (g_NamedSpawnsNewSpawnsIsEnabled == true)
            {
                if (bNewSpawn == true)
                {
                    drawText << "\n* New Spawn *";
                }
            }

            if (bSpecialSpawn == true)
            {
                drawText << "\n* Special Spawn *";
            }

            for (auto tag : g_ESPSpawnTagList)
            {
                if (tag.first == spawn)
                {
                    drawText << "\n* Tag: " << tag.second << " *";
                }
            }

            int textColor = EQ_DRAW_TEXT_COLOR_WHITE;

            if (spawn == targetSpawn)
            {
                textColor = EQ_DRAW_TEXT_COLOR_PINK;
            }
            else
            {
                if (bIgnoreDistance == true)
                {
                    textColor = EQ_DRAW_TEXT_COLOR_GREEN;
                }
                else
                {
                    if (spawnType == EQ_SPAWN_TYPE_PLAYER)
                    {
                        textColor = EQ_DRAW_TEXT_COLOR_RED;
                    }
                    else if (spawnType == EQ_SPAWN_TYPE_NPC)
                    {
                        if (bOutOfRange == true)
                        {
                            textColor = EQ_DRAW_TEXT_COLOR_GRAY;
                        }
                        else
                        {
                            textColor = EQ_DRAW_TEXT_COLOR_TEAL;
                        }
                    }
                    else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
                    {
                        textColor = EQ_DRAW_TEXT_COLOR_YELLOW;
                    }
                }
            }

            // hold ALT then left-click to target a spawn by their ESP text
            if (GetAsyncKeyState(VK_MENU))
            {
                if (spawnDistance <= g_ESPSpawnClickDistance)
                {
                    int mouseX = EQ_GetMouseX();
                    int mouseY = EQ_GetMouseY();

                    if (std::abs((int)screenX - mouseX) < g_ESPSpawnClickRadius)
                    {
                        if (std::abs((int)screenY - mouseY) < g_ESPSpawnClickRadius)
                        {
                            textColor = EQ_DRAW_TEXT_COLOR_BLUE;
                        }
                    }

                    if (std::abs((int)screenX - g_ESPSpawnClickX) < g_ESPSpawnClickRadius)
                    {
                        if (std::abs((int)screenY - g_ESPSpawnClickY) < g_ESPSpawnClickRadius)
                        {
                            EQ_SetTargetSpawn(spawn);

                            g_ESPSpawnClickX = -1;
                            g_ESPSpawnClickY = -1;
                        }
                    }
                }
            }

            if (g_ESPFindLineIsEnabled == true && bDrawLine == true)
            {
                EQ_DrawLine(0.0f, 0.0f, screenX, screenY, EQ_COLOR_ARGB_GREY);
            }

            if (g_ESPLineOfSightIsEnabled == true)
            {
                if (EQ_CanSpawnCastRayToSpawn(playerSpawn, spawn) == true)
                {
                    EQ_DrawLine(0.0f, 0.0f, screenX, screenY, EQ_COLOR_ARGB_GREY);
                }
            }

            EQ_DrawTextByColor(drawText.str().c_str(), (int)screenX, (int)screenY, textColor);
        }
    }
}

void EQAPP_ESP_DrawDoors()
{
    auto switchManager = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQSwitchManager);
    if (switchManager == NULL)
    {
        return;
    }

    auto numDoors = EQ_ReadMemory<uint32_t>(switchManager + EQ_OFFSET_EQSwitchManager_NUM_SWITCHES);
    if (numDoors == 0)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    //auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    for (unsigned int i = 0; i < numDoors; i++)
    {
        auto door = EQ_ReadMemory<uint32_t>(switchManager + (EQ_OFFSET_EQSwitchManager_FIRST_SWITCH + (i * 0x04)));
        if (door == NULL)
        {
            continue;
        }

        auto doorY = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Y);
        auto doorX = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_X);
        auto doorZ = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_Z);

        float doorDistance = EQ_CalculateDistance(playerSpawnY, playerSpawnX, doorY, doorX);
        if (doorDistance > g_ESPDoorDistance)
        {
            continue;
        }

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(doorY, doorX, doorZ, screenX, screenY);
        if (result == true)
        {
            char doorName[EQ_SIZE_EQSwitch_NAME];
            std::memmove(doorName, (LPVOID)(door + EQ_OFFSET_EQSwitch_NAME), sizeof(doorName));

            std::stringstream drawText;
            drawText << "[Door] " << doorName << " (" << (int)doorDistance << "m)";

            drawText << "\nAddress: 0x" << std::hex << door << std::dec;

            ////auto doorObjectType = EQ_ReadMemory<uint8_t>(door + EQ_OFFSET_EQSwitch_OBJECT_TYPE);
            auto doorType = EQ_ReadMemory<uint8_t>(door + EQ_OFFSET_EQSwitch_TYPE);

            ////drawText << "\nObject Type: " << (int)doorObjectType;
            drawText << "\nType: " << (int)doorType;

            drawText << "\nY: " << doorY;
            drawText << "\nX: " << doorX;
            drawText << "\nZ: " << doorZ;

            auto doorHeading = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_HEADING);
            ////auto doorAngle = EQ_ReadMemory<float>(door + EQ_OFFSET_EQSwitch_ANGLE);

            drawText << "\nHeading: " << doorHeading;
            ////drawText << "\nAngle: " << doorAngle;

            auto doorKeyID = EQ_ReadMemory<uint32_t>(door + EQ_OFFSET_EQSwitch_KEY_ID);
            if (doorKeyID != EQ_SWITCH_KEY_ID_NULL)
            {
                drawText << "\nKey ID: " <<  std::hex << doorKeyID << std::dec;
            }

            ////auto doorIsUseable = EQ_ReadMemory<uint8_t>(door + EQ_OFFSET_EQSwitch_IS_USEABLE);
            ////drawText << "\nIs Useable: " << (int)doorIsUseable;

            EQ_DrawTextByColor(drawText.str().c_str(), (int)screenX, (int)screenY, EQ_DRAW_TEXT_COLOR_WHITE);
        }
    }
}

void EQAPP_ESP_Execute()
{
    if (g_ESPShowSpawnsIsEnabled == true)
    {
        EQAPP_ESP_DrawSpawns();
    }

    if (g_ESPShowDoorsIsEnabled == true)
    {
        EQAPP_ESP_DrawDoors();
    }
}

bool EQAPP_ESP_HandleEvent_CEverQuest__LMouseUp(int x, int y)
{
    if (GetAsyncKeyState(VK_MENU))
    {
        g_ESPSpawnClickX = x;
        g_ESPSpawnClickY = y;

        return true;
    }

    return false;
}
