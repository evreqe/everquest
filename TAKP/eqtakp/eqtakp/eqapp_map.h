#pragma once

namespace EQApp
{
    typedef struct _MapLine
    {
        EQ::Line Line;
        EQ::ColorRGB Color;
        int Layer;
    } MapLine, *MapLine_ptr;

    typedef struct _MapLabel
    {
        EQ::Location Location;
        EQ::ColorRGB Color;
        int Layer;
        int Size;
        std::string Text;
    } MapLabel, *MapLabel_ptr;
}

bool g_mapIsEnabled = false;

bool g_mapLinesIsEnabled = true;
bool g_mapLabelsIsEnabled = false;
bool g_mapSpawnsIsEnabled = true;

bool g_mapHeightFilterIsEnabled = false;

std::vector<EQApp::MapLine> g_mapLineList;
std::vector<EQApp::MapLabel> g_mapLabelList;

unsigned int g_mapNumLayers = 3;

unsigned int g_mapNumLinesDrawn = 0;
unsigned int g_mapNumLinesMax = 3500;

unsigned int g_mapNumLabelsDrawn = 0;
unsigned int g_mapNumLabelsMax = 1000;

float g_mapX = 4.0f;
float g_mapY = 64.0f;

float g_mapWidth  = 400.0f;
float g_mapHeight = 400.0f;

float g_mapMinX = g_mapX;
float g_mapMaxX = g_mapX + g_mapWidth;

float g_mapMinY = g_mapY;
float g_mapMaxY = g_mapY + g_mapHeight;

float g_mapOriginX = g_mapX + (g_mapWidth  * 0.5f);
float g_mapOriginY = g_mapY + (g_mapHeight * 0.5f);

float g_mapOffsetX = 0.0f;
float g_mapOffsetY = 0.0f;

float g_mapHeightFilterLow  = 10.0f; // z axis
float g_mapHeightFilterHigh = 10.0f; // z axis

float g_mapZoom           = 1.0f;
float g_mapZoomMultiplier = 0.05f; // zoom speed
float g_mapZoomDefault    = 1.0f;
float g_mapZoomMinimum    = 10.0f;
float g_mapZoomMaximum    = 0.01f;

float g_mapMouseWheelZoomMultiplier = 0.5f; // mouse wheel zoom speed

uint32_t g_mapCenterLineColorARGB = 0xFFFF00FF;
float g_mapCenterLineSize = 4.0f;

uint32_t g_mapArrowColorARGB = 0xFFFF00FF;
float g_mapArrowRadius = 20.0f;

uint32_t g_mapBorderColorARGB = 0xFF646464;
uint32_t g_mapBackgroundColorARGB = EQ_TOOLTIP_TEXT_BACKGROUND_COLOR;

float g_mapSpawnDistanceMax = 2000.0f;
float g_mapSpawnDistanceZMax = 2000.0f;

void EQAPP_Map_Toggle();
void EQAPP_Map_Lines_Toggle();
void EQAPP_Map_Labels_Toggle();
void EQAPP_Map_Spawns_Toggle();
bool EQAPP_Map_Load();
bool EQAPP_Map_LoadFile(const std::string& filename, int layer);
void EQAPP_Map_RecalculateScreenCoordinates();
void EQAPP_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY);
void EQAPP_Map_ZoomOut();
void EQAPP_Map_ZoomIn();
void EQAPP_Map_MouseWheelZoomOut();
void EQAPP_Map_MouseWheelZoomIn();
void EQAPP_Map_HandleEvent_HandleMouseWheel(int mouseWheelDelta);
void EQAPP_Map_Scroll(signed int speedX, signed int speedY);
void EQAPP_Map_SetZoom(float zoom);
void EQAPP_Map_ResetZoom();
void EQAPP_Map_Center();
bool EQAPP_Map_IsMouseOver();
void EQAPP_Map_Execute(); // draw

void EQAPP_Map_Toggle()
{
    EQ_ToggleBool(g_mapIsEnabled);
    ////EQAPP_PrintBool("Map", g_mapIsEnabled);

    if (g_mapIsEnabled == true)
    {
        EQAPP_Map_RecalculateScreenCoordinates();
        EQAPP_Map_Center();
    }
}

void EQAPP_Map_Lines_Toggle()
{
    EQ_ToggleBool(g_mapLinesIsEnabled);
    EQAPP_PrintBool("Map Lines", g_mapLinesIsEnabled);
}

void EQAPP_Map_Labels_Toggle()
{
    EQ_ToggleBool(g_mapLabelsIsEnabled);
    EQAPP_PrintBool("Map Labels", g_mapLabelsIsEnabled);
}

void EQAPP_Map_Spawns_Toggle()
{
    EQ_ToggleBool(g_mapSpawnsIsEnabled);
    EQAPP_PrintBool("Map Spawns", g_mapSpawnsIsEnabled);
}

bool EQAPP_Map_Load()
{
    g_mapLineList.clear();
    g_mapLabelList.clear();

    std::string zoneShortName = EQ_POINTER_Zone.ShortName;
    if (zoneShortName.size() == 0)
    {
        return false;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/maps/" << zoneShortName << ".txt";

    EQAPP_Map_LoadFile(filePath.str(), 0); // layer 0 is the base layer

/*
    unsigned int mapLayer = 1;
    for (mapLayer = 1; mapLayer < (g_mapNumLayers + 1); mapLayer++)
    {
        std::stringstream filePathEx;
        filePathEx << g_applicationName << "/maps/" << zoneShortName << "_" << mapLayer << ".txt";

        EQAPP_Map_LoadFile(filePathEx.str(), mapLayer);
    }
*/

    EQAPP_Map_RecalculateScreenCoordinates();
    EQAPP_Map_ResetZoom();
    EQAPP_Map_Center();

    return true;
}

bool EQAPP_Map_LoadFile(const std::string& filename, int layer)
{
    std::ifstream file(filename.c_str());
    if (file.is_open() == false)
    {
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        char lineType = line.at(0);
        line = line.substr(1);

        std::vector<std::string> lineTokens;
        std::istringstream lineStream(line);
        std::string lineToken;
        while (std::getline(lineStream, lineToken, ','))
        {
            lineTokens.push_back(lineToken);
        }

        if (lineTokens.size() == 0)
        {
            continue;
        }

        if (lineType == 'L')
        {
            if (lineTokens.size() != 9)
            {
                continue;
            }

            EQApp::MapLine mapLine;

            mapLine.Line.X1 = std::stof(lineTokens.at(0));
            mapLine.Line.Y1 = std::stof(lineTokens.at(1));
            mapLine.Line.Z1 = std::stof(lineTokens.at(2));

            mapLine.Line.X2 = std::stof(lineTokens.at(3));
            mapLine.Line.Y2 = std::stof(lineTokens.at(4));
            mapLine.Line.Z2 = std::stof(lineTokens.at(5));

            mapLine.Color.R = std::stoi(lineTokens.at(6));
            mapLine.Color.G = std::stoi(lineTokens.at(7));
            mapLine.Color.B = std::stoi(lineTokens.at(8));
            mapLine.Color.Unused = 0xFF;

            if (mapLine.Color.R == 0 && mapLine.Color.G == 0 && mapLine.Color.B == 0)
            {
                mapLine.Color.R = 255;
                mapLine.Color.G = 255;
                mapLine.Color.B = 255;
            }

            mapLine.Layer = layer;

            g_mapLineList.push_back(mapLine);
        }
        else if (lineType == 'P')
        {
            if (lineTokens.size() != 8)
            {
                continue;
            }

            EQApp::MapLabel mapLabel;

            mapLabel.Location.X = std::stof(lineTokens.at(0));
            mapLabel.Location.Y = std::stof(lineTokens.at(1));
            mapLabel.Location.Z = std::stof(lineTokens.at(2));

            mapLabel.Color.R = std::stoi(lineTokens.at(3));
            mapLabel.Color.G = std::stoi(lineTokens.at(4));
            mapLabel.Color.B = std::stoi(lineTokens.at(5));
            mapLabel.Color.Unused = 0xFF;

            mapLabel.Layer = layer;

            mapLabel.Size = std::stoi(lineTokens.at(6));

            mapLabel.Text = lineTokens.at(7);

            EQAPP_String_ReplaceAll(mapLabel.Text, "_", " ");

            g_mapLabelList.push_back(mapLabel);
        }
    }

    return true;
}

void EQAPP_Map_RecalculateScreenCoordinates()
{
    uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);
    uint32_t resolutionHeight = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_HEIGHT);

    g_mapX = ((float)resolutionWidth - 12.0f) - g_mapWidth;
    g_mapY = 4.0f;

    g_mapMinX = g_mapX;
    g_mapMaxX = g_mapX + g_mapWidth;

    g_mapMinY = g_mapY;
    g_mapMaxY = g_mapY + g_mapHeight;

    g_mapOriginX = g_mapX + (g_mapWidth  * 0.5f);
    g_mapOriginY = g_mapY + (g_mapHeight * 0.5f);
}

void EQAPP_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    screenX = (((x * g_mapZoom) + g_mapOriginX) + ((playerSpawn->X + g_mapOffsetX) * g_mapZoom));
    screenY = (((y * g_mapZoom) + g_mapOriginY) + ((playerSpawn->Y + g_mapOffsetY) * g_mapZoom));
}

void EQAPP_Map_ZoomOut()
{
    g_mapZoom -= g_mapZoom * g_mapZoomMultiplier;

    if (g_mapZoom <= g_mapZoomMaximum)
    {
        g_mapZoom = g_mapZoomMaximum;
    }
}

void EQAPP_Map_ZoomIn()
{
    g_mapZoom += g_mapZoom * g_mapZoomMultiplier;

    if (g_mapZoom >= g_mapZoomMinimum)
    {
        g_mapZoom = g_mapZoomMinimum;
    }
}

void EQAPP_Map_MouseWheelZoomOut()
{
    g_mapZoom -= g_mapZoom * g_mapMouseWheelZoomMultiplier;

    if (g_mapZoom <= g_mapZoomMaximum)
    {
        g_mapZoom = g_mapZoomMaximum;
    }
}

void EQAPP_Map_MouseWheelZoomIn()
{
    g_mapZoom += g_mapZoom * g_mapMouseWheelZoomMultiplier;

    if (g_mapZoom >= g_mapZoomMinimum)
    {
        g_mapZoom = g_mapZoomMinimum;
    }
}

void EQAPP_Map_HandleEvent_HandleMouseWheel(int mouseWheelDelta)
{
    if (EQAPP_Map_IsMouseOver() == true)
    {
        if (mouseWheelDelta == EQ_MOUSE_WHEEL_DELTA_UP)
        {
            EQAPP_Map_MouseWheelZoomIn();
        }
        else if (mouseWheelDelta == EQ_MOUSE_WHEEL_DELTA_DOWN)
        {
            EQAPP_Map_MouseWheelZoomOut();
        }
    }
}

void EQAPP_Map_Scroll(signed int speedX, signed int speedY)
{
    if (speedX != 0)
    {
        float addX = (float)speedX;
        if (g_mapZoom != 0.0f)
        {
            addX = addX / g_mapZoom;
        }

        g_mapOffsetX += addX;
    }

    if (speedY != 0)
    {
        float addY= (float)speedY;
        if (g_mapZoom != 0.0f)
        {
            addY = addY / g_mapZoom;
        }

        g_mapOffsetY += addY;
    }
}

void EQAPP_Map_SetZoom(float zoom)
{
    g_mapZoom = zoom;
}

void EQAPP_Map_ResetZoom()
{
    g_mapZoom = 1.0f;
}

void EQAPP_Map_Center()
{
    g_mapOffsetX = 0.0f;
    g_mapOffsetY = 0.0f;
}

bool EQAPP_Map_IsPointInsideMap(uint32_t x, uint32_t y)
{
    return (EQ_IsPointInsideRectangle(x, y, (int)(g_mapX), (int)(g_mapY), (int)g_mapWidth, (int)g_mapHeight) == true);
}

bool EQAPP_Map_IsMouseOver()
{
    uint32_t mouseX = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_X);
    uint32_t mouseY = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_Y);

    return (EQAPP_Map_IsPointInsideMap(mouseX, mouseY) == true);
}

void EQAPP_Map_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto mouse = EQ_GetMouse();
    if (mouse.ClickState == EQ_MOUSE_CLICK_STATE_LEFT)
    {
        if (EQAPP_Map_IsMouseOver() == true)
        {
            if (mouse.SpeedX != 0 || mouse.SpeedY != 0)
            {
                EQAPP_Map_Scroll(mouse.SpeedX, mouse.SpeedY);
            }
        }
    }

    EQ::Location playerLocation;
    playerLocation.X = playerSpawn->X;
    playerLocation.Y = playerSpawn->Y;
    playerLocation.Z = playerSpawn->Z;

    float playerMapX = 0.0f;
    float playerMapY = 0.0f;
    EQAPP_Map_ConvertWorldLocationToScreenPosition(-playerSpawn->X, -playerSpawn->Y, playerMapX, playerMapY);

    auto targetSpawn = EQ_GetTargetSpawn();

    EQ_DrawRectangle(g_mapX, g_mapY, g_mapWidth, g_mapHeight, g_mapBackgroundColorARGB, true);
    EQ_DrawRectangle(g_mapX, g_mapY, g_mapWidth, g_mapHeight, g_mapBorderColorARGB);

    g_mapNumLinesDrawn = 0;
    g_mapNumLabelsDrawn = 0;

    if (g_mapLinesIsEnabled == true)
    {
        for (auto& mapLine : g_mapLineList)
        {
            if (g_mapNumLinesDrawn > g_mapNumLinesMax)
            {
                break;
            }

            if (g_mapHeightFilterIsEnabled == true)
            {
                if (g_mapHeightFilterLow > 0.0f)
                {
                    if
                    (
                        mapLine.Line.Z1 < (playerSpawn->Z - g_mapHeightFilterLow) ||
                        mapLine.Line.Z2 < (playerSpawn->Z - g_mapHeightFilterLow)
                    )
                    {
                        continue;
                    }
                }

                if (g_mapHeightFilterHigh > 0.0f)
                {
                    if
                    (
                        mapLine.Line.Z1 > (playerSpawn->Z + g_mapHeightFilterHigh) ||
                        mapLine.Line.Z2 > (playerSpawn->Z + g_mapHeightFilterHigh)
                    )
                    {
                        continue;
                    }
                }
            }

            EQ::Line line;

            line.X1 = 0.0f;
            line.Y1 = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(mapLine.Line.X1, mapLine.Line.Y1, line.X1, line.Y1);
            line.Z1 = 1.0f;

            line.X2 = 0.0f;
            line.Y2 = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(mapLine.Line.X2, mapLine.Line.Y2, line.X2, line.Y2);
            line.Z2 = 1.0f;

            bool bDrawLine = EQ_LineClip(&line, g_mapMinX, g_mapMinY, g_mapMaxX, g_mapMaxY);
            if (bDrawLine == false)
            {
                continue;
            }

            EQ_DrawLineEx(&line, mapLine.Color.RGB);

            g_mapNumLinesDrawn++;
        }
    }

    if (g_mapLabelsIsEnabled == true)
    {
        for (auto& mapLabel : g_mapLabelList)
        {
            if (g_mapNumLabelsDrawn > g_mapNumLabelsMax)
            {
                break;
            }

            float labelX = 0.0f;
            float labelY = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(mapLabel.Location.X, mapLabel.Location.Y, labelX, labelY);

            if (EQAPP_Map_IsPointInsideMap((int)labelX, (int)labelY) == false)
            {
                continue;
            }

            EQ_DrawTextEx(mapLabel.Text.c_str(), (int)labelX, (int)labelY, EQ_TEXT_COLOR_WHITE, EQ_ADDRESS_POINTER_FONT_ARIAL12);

            g_mapNumLabelsDrawn++;
        }
    }

    if (g_mapSpawnsIsEnabled == true)
    {
        auto spawn = EQ_GetFirstSpawn();
        while (spawn != NULL)
        {
            if (spawn == playerSpawn)
            {
                spawn = spawn->Next;
                continue;
            }

            float spawnMapX = 0.0f;
            float spawnMapY = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(-spawn->X, -spawn->Y, spawnMapX, spawnMapY);

            if
            (
                spawnMapX >= g_mapMaxX ||
                spawnMapY >= g_mapMaxY ||
                spawnMapX <= g_mapMinX ||
                spawnMapY <= g_mapMinY
            )
            {
                spawn = spawn->Next;
                continue;
            }

            EQ::Location spawnLocation;
            spawnLocation.X = spawn->X;
            spawnLocation.Y = spawn->Y;
            spawnLocation.Z = spawn->Z;

            float spawnDistance = EQ_CalculateDistance(spawnLocation.X, spawnLocation.Y, playerLocation.X, playerLocation.Y);

            float spawnDistanceZ = std::fabsf((float)spawnLocation.Z - (float)playerLocation.Z);

            bool useDistance = true;

            if (spawn == targetSpawn || spawn->Type == EQ_SPAWN_TYPE_PLAYER || spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
            {
                useDistance = false;
            }

            if (useDistance == true)
            {
                if (EQ_IsZoneInList(EQ_ZONE_ID_LIST_VERTICAL) == true)
                {
                    if (spawnDistanceZ > g_mapSpawnDistanceZMax)
                    {
                        spawn = spawn->Next;
                        continue;
                    }
                }

                if (spawnDistance > g_mapSpawnDistanceMax)
                {
                    spawn = spawn->Next;
                    continue;
                }
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

            std::string spawnText = "+";

            if (spawn->MovementSpeed > 0.0f)
            {
                spawnText = "*";
            }

            EQ_DrawText(spawnText.c_str(), (int)spawnMapX, (int)spawnMapY, textColor);

            if (EQ_IsMouseHoveringOverCXWnd() == false)
            {
                uint32_t mouseX = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_X);
                uint32_t mouseY = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_MOUSE_Y);

                if (EQAPP_Map_IsMouseOver() == true)
                {
                    if (EQ_IsPointInsideRectangle(mouseX, mouseY, (int)(spawnMapX + 1) - 4, (int)(spawnMapY + 6) - 4, 8, 8) == true)
                    {
                        std::stringstream spawnText;

                        if (spawn->MovementSpeed > 0.0f)
                        {
                            spawnText << "* ";
                        }
                        else
                        {
                            spawnText << "+ ";
                        }

                        spawnText << "[" << (int)spawn->Level << "] ";

                        spawnText << EQ_GetSpawnName(spawn);

                        uint32_t spawnTextFont = EQ_ADDRESS_POINTER_FONT_ARIAL14;

                        uint32_t spawnTextX = mouseX + EQ_MOUSE_CURSOR_WIDTH + 1;
                        uint32_t spawnTextY = mouseY;

                        uint32_t spawnTextWidth = EQ_GetFontTextWidth(spawnText.str().c_str(), spawnTextFont);

                        uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);

                        if ((spawnTextX + spawnTextWidth) > resolutionWidth)
                        {
                            spawnTextX = mouseX - spawnTextWidth - 1;
                        }

                        EQ_DrawTooltipText(spawnText.str().c_str(), spawnTextX, spawnTextY, spawnTextFont);
                    }
                }
            }

            spawn = spawn->Next;
        }
    }

    EQ::Line mapCenterLineHorizontal;
    mapCenterLineHorizontal.X1 = playerMapX - g_mapCenterLineSize;
    mapCenterLineHorizontal.Y1 = playerMapY;
    mapCenterLineHorizontal.Z1 = 1.0f;
    mapCenterLineHorizontal.X2 = playerMapX + g_mapCenterLineSize;
    mapCenterLineHorizontal.Y2 = playerMapY;
    mapCenterLineHorizontal.Z2 = 1.0f;

    EQ::Line mapCenterLineVertical;
    mapCenterLineVertical.X1 = playerMapX;
    mapCenterLineVertical.Y1 = playerMapY - g_mapCenterLineSize;
    mapCenterLineVertical.Z1 = 1.0f;
    mapCenterLineVertical.X2 = playerMapX;
    mapCenterLineVertical.Y2 = playerMapY + g_mapCenterLineSize;
    mapCenterLineVertical.Z2 = 1.0f;

    EQ_DrawLineEx(&mapCenterLineHorizontal, g_mapCenterLineColorARGB);
    EQ_DrawLineEx(&mapCenterLineVertical,   g_mapCenterLineColorARGB);

    float playerHeadingC = playerSpawn->Heading;

    playerHeadingC = playerHeadingC - 128.0f;

    if (playerHeadingC < 0.0f)
    {
        playerHeadingC = playerHeadingC + 512.0f;
    }

    float playerHeadingRadiansC = playerHeadingC * (EQ_PI / 256.0f);

    float arrowAddCX = cosf(playerHeadingRadiansC);
    arrowAddCX = arrowAddCX * g_mapArrowRadius;

    float arrowAddCY = sinf(playerHeadingRadiansC);
    arrowAddCY = arrowAddCY * g_mapArrowRadius;

    float arrowCX = -playerSpawn->X - arrowAddCX;
    float arrowCY = -playerSpawn->Y + arrowAddCY;

    float playerHeadingB = playerHeadingC;

    playerHeadingB = playerHeadingB - 32.0f;

    if (playerHeadingB < 0.0f)
    {
        playerHeadingB = playerHeadingB + 512.0f;
    }

    float playerHeadingRadiansB = playerHeadingB * (EQ_PI / 256.0f);

    float arrowAddBX = cosf(playerHeadingRadiansB);
    arrowAddBX = arrowAddBX * (g_mapArrowRadius * 0.5f);

    float arrowAddBY = sinf(playerHeadingRadiansB);
    arrowAddBY = arrowAddBY * (g_mapArrowRadius * 0.5f);

    float arrowBX = arrowCX + arrowAddBX;
    float arrowBY = arrowCY - arrowAddBY;

    float playerHeadingA = playerHeadingC;

    playerHeadingA = playerHeadingA + 32.0f;

    if (playerHeadingA > 512.0f)
    {
        playerHeadingA = playerHeadingA - 512.0f;
    }

    float playerHeadingRadiansA = playerHeadingA * (EQ_PI / 256.0f);

    float arrowAddAX = cosf(playerHeadingRadiansA);
    arrowAddAX = arrowAddAX * (g_mapArrowRadius * 0.5f);

    float arrowAddAY = sinf(playerHeadingRadiansA);
    arrowAddAY = arrowAddAY * (g_mapArrowRadius * 0.5f);

    float arrowAX = arrowCX + arrowAddAX;
    float arrowAY = arrowCY - arrowAddAY;

    float mapArrowCX = (arrowCX + playerMapX) + playerSpawn->X;
    float mapArrowCY = (arrowCY + playerMapY) + playerSpawn->Y;

    float mapArrowBX = (arrowBX + playerMapX) + playerSpawn->X;
    float mapArrowBY = (arrowBY + playerMapY) + playerSpawn->Y;

    float mapArrowAX = (arrowAX + playerMapX) + playerSpawn->X;
    float mapArrowAY = (arrowAY + playerMapY) + playerSpawn->Y;

    EQ::Line mapArrowLineA;
    mapArrowLineA.X1 = mapArrowCX;
    mapArrowLineA.Y1 = mapArrowCY;
    mapArrowLineA.Z1 = 1.0f;
    mapArrowLineA.X2 = mapArrowAX;
    mapArrowLineA.Y2 = mapArrowAY;
    mapArrowLineA.Z2 = 1.0f;

    EQ::Line mapArrowLineB;
    mapArrowLineB.X1 = mapArrowCX;
    mapArrowLineB.Y1 = mapArrowCY;
    mapArrowLineB.Z1 = 1.0f;
    mapArrowLineB.X2 = mapArrowBX;
    mapArrowLineB.Y2 = mapArrowBY;
    mapArrowLineB.Z2 = 1.0f;

    EQ::Line mapArrowLineC;
    mapArrowLineC.X1 = playerMapX;
    mapArrowLineC.Y1 = playerMapY;
    mapArrowLineC.Z1 = 1.0f;
    mapArrowLineC.X2 = mapArrowCX;
    mapArrowLineC.Y2 = mapArrowCY;
    mapArrowLineC.Z2 = 1.0f;

    EQ_DrawLineEx(&mapArrowLineA, g_mapArrowColorARGB);
    EQ_DrawLineEx(&mapArrowLineB, g_mapArrowColorARGB);
    EQ_DrawLineEx(&mapArrowLineC, g_mapArrowColorARGB);
}



