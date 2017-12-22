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

bool g_MapIsEnabled = false;

bool g_MapLinesIsEnabled = true;
bool g_MapLabelsIsEnabled = false;
bool g_MapSpawnsIsEnabled = true;

bool g_MapHeightFilterIsEnabled = false;

bool g_MapLayer0IsEnabled = true;
bool g_MapLayer1IsEnabled = false;
bool g_MapLayer2IsEnabled = false;
bool g_MapLayer3IsEnabled = false;

bool g_Map3DIsEnabled = false;

std::vector<EQApp::MapLine> g_MapLineList;
std::vector<EQApp::MapLabel> g_MapLabelList;

unsigned int g_MapNumLayers = 3;

unsigned int g_MapNumLinesDrawn = 0;
unsigned int g_MapNumLinesMax = 3500;

unsigned int g_MapNumLabelsDrawn = 0;
unsigned int g_MapNumLabelsMax = 1000;

float g_MapX = 4.0f;
float g_MapY = 64.0f;

float g_MapWidth  = 400.0f;
float g_MapHeight = 400.0f;

float g_MapMinX = g_MapX;
float g_MapMaxX = g_MapX + g_MapWidth;

float g_MapMinY = g_MapY;
float g_MapMaxY = g_MapY + g_MapHeight;

float g_MapOriginX = g_MapX + (g_MapWidth  * 0.5f);
float g_MapOriginY = g_MapY + (g_MapHeight * 0.5f);

float g_MapOffsetX = 0.0f;
float g_MapOffsetY = 0.0f;

float g_MapHeightFilterLow  = 10.0f; // z axis
float g_MapHeightFilterHigh = 10.0f; // z axis

float g_MapZoom           = 1.0f;
float g_MapZoomMultiplier = 0.05f; // zoom speed
float g_MapZoomDefault    = 1.0f;
float g_MapZoomMinimum    = 10.0f;
float g_MapZoomMaximum    = 0.01f;

float g_MapMouseWheelZoomMultiplier = 0.5f; // mouse wheel zoom speed

uint32_t g_MapCenterLineColorARGB = EQ_COLOR_ARGB_FUCHSIA;
float g_MapCenterLineSize = 4.0f;

uint32_t g_MapArrowColorARGB = EQ_COLOR_ARGB_FUCHSIA;
float g_MapArrowRadius = 20.0f;

uint32_t g_MapBorderColorARGB = EQ_COLOR_ARGB_GRAY;
uint32_t g_MapBackgroundColorARGB = EQ_COLOR_ARGB_TOOLTIP_TEXT_BACKGROUND;

float g_MapSpawnDistanceMax = 20000.0f;
float g_MapSpawnDistanceZMax = 20.0f;

void EQAPP_Map_Toggle();
void EQAPP_Map_Lines_Toggle();
void EQAPP_Map_Labels_Toggle();
void EQAPP_Map_Spawns_Toggle();
void EQAPP_Map_Layer0_Toggle();
void EQAPP_Map_Layer1_Toggle();
void EQAPP_Map_Layer2_Toggle();
void EQAPP_Map_Layer3_Toggle();
void EQAPP_Map_HeightFilter_Toggle();
void EQAPP_Map_3D_Toggle();
bool EQAPP_Map_Load();
bool EQAPP_Map_LoadFile(const std::string& filename, uint32_t layer);
void EQAPP_Map_RecalculateScreenCoordinates();
void EQAPP_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY);
void EQAPP_Map_ZoomOut();
void EQAPP_Map_ZoomIn();
void EQAPP_Map_MouseWheelZoomOut();
void EQAPP_Map_MouseWheelZoomIn();
void EQAPP_Map_HandleEvent_HandleMouseWheel(signed int mouseWheelDelta);
void EQAPP_Map_Scroll(signed int speedX, signed int speedY);
void EQAPP_Map_SetZoom(float zoom);
void EQAPP_Map_ResetZoom();
void EQAPP_Map_Center();
bool EQAPP_Map_IsPointInsideMap(uint32_t x, uint32_t y);
bool EQAPP_Map_IsMouseOver();
void EQAPP_Map_Execute(); // draw

void EQAPP_Map_Toggle()
{
    EQ_ToggleBool(g_MapIsEnabled);
    ////EQAPP_PrintBool("Map", g_MapIsEnabled);

    if (g_MapIsEnabled == true)
    {
        EQAPP_Map_RecalculateScreenCoordinates();
        EQAPP_Map_Center();
    }
}

void EQAPP_Map_Lines_Toggle()
{
    EQ_ToggleBool(g_MapLinesIsEnabled);
    EQAPP_PrintBool("Map Lines", g_MapLinesIsEnabled);
}

void EQAPP_Map_Labels_Toggle()
{
    EQ_ToggleBool(g_MapLabelsIsEnabled);
    EQAPP_PrintBool("Map Labels", g_MapLabelsIsEnabled);
}

void EQAPP_Map_Spawns_Toggle()
{
    EQ_ToggleBool(g_MapSpawnsIsEnabled);
    EQAPP_PrintBool("Map Spawns", g_MapSpawnsIsEnabled);
}

void EQAPP_Map_Layer0_Toggle()
{
    EQ_ToggleBool(g_MapLayer0IsEnabled);
    EQAPP_PrintBool("Map Base Layer", g_MapLayer0IsEnabled);
}

void EQAPP_Map_Layer1_Toggle()
{
    EQ_ToggleBool(g_MapLayer1IsEnabled);
    EQAPP_PrintBool("Map Layer 1", g_MapLayer1IsEnabled);
}

void EQAPP_Map_Layer2_Toggle()
{
    EQ_ToggleBool(g_MapLayer2IsEnabled);
    EQAPP_PrintBool("Map Layer 2", g_MapLayer2IsEnabled);
}

void EQAPP_Map_Layer3_Toggle()
{
    EQ_ToggleBool(g_MapLayer3IsEnabled);
    EQAPP_PrintBool("Map Layer 3", g_MapLayer3IsEnabled);
}

void EQAPP_Map_HeightFilter_Toggle()
{
    EQ_ToggleBool(g_MapHeightFilterIsEnabled);
    EQAPP_PrintBool("Map Height Filter", g_MapHeightFilterIsEnabled);
}

void EQAPP_Map_3D_Toggle()
{
    EQ_ToggleBool(g_Map3DIsEnabled);
    EQAPP_PrintBool("Map 3D", g_Map3DIsEnabled);
}

bool EQAPP_Map_Load()
{
    g_MapLineList.clear();
    g_MapLineList.reserve(1000);

    g_MapLabelList.clear();
    g_MapLabelList.reserve(100);

    std::string zoneShortName = EQ_POINTER_Zone.ShortName;
    if (zoneShortName.size() == 0)
    {
        return false;
    }

    std::stringstream filePath;
    filePath << g_EQAppName << "/maps/" << zoneShortName << ".txt";

    EQAPP_Map_LoadFile(filePath.str(), 0); // layer 0 is the base layer

    for (unsigned int mapLayer = 1; mapLayer < (g_MapNumLayers + 1); mapLayer++)
    {
        std::stringstream filePathEx;
        filePathEx << g_EQAppName << "/maps/" << zoneShortName << "_" << mapLayer << ".txt";

        EQAPP_Map_LoadFile(filePathEx.str(), mapLayer);
    }

    EQAPP_Map_RecalculateScreenCoordinates();
    EQAPP_Map_ResetZoom();
    EQAPP_Map_Center();

    return true;
}

bool EQAPP_Map_LoadFile(const std::string& filename, uint32_t layer)
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

            g_MapLineList.push_back(mapLine);
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

            g_MapLabelList.push_back(mapLabel);
        }
    }

    return true;
}

void EQAPP_Map_RecalculateScreenCoordinates()
{
    uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);
    uint32_t resolutionHeight = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_HEIGHT);

    g_MapX = ((float)resolutionWidth - 4.0f) - g_MapWidth;
    g_MapY = 4.0f;

    g_MapMinX = g_MapX;
    g_MapMaxX = g_MapX + g_MapWidth;

    g_MapMinY = g_MapY;
    g_MapMaxY = g_MapY + g_MapHeight;

    g_MapOriginX = g_MapX + (g_MapWidth  * 0.5f);
    g_MapOriginY = g_MapY + (g_MapHeight * 0.5f);
}

void EQAPP_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    screenX = (((x * g_MapZoom) + g_MapOriginX) + ((playerSpawn->X + g_MapOffsetX) * g_MapZoom));
    screenY = (((y * g_MapZoom) + g_MapOriginY) + ((playerSpawn->Y + g_MapOffsetY) * g_MapZoom));
}

void EQAPP_Map_ZoomOut()
{
    g_MapZoom -= g_MapZoom * g_MapZoomMultiplier;

    if (g_MapZoom <= g_MapZoomMaximum)
    {
        g_MapZoom = g_MapZoomMaximum;
    }
}

void EQAPP_Map_ZoomIn()
{
    g_MapZoom += g_MapZoom * g_MapZoomMultiplier;

    if (g_MapZoom >= g_MapZoomMinimum)
    {
        g_MapZoom = g_MapZoomMinimum;
    }
}

void EQAPP_Map_MouseWheelZoomOut()
{
    g_MapZoom -= g_MapZoom * g_MapMouseWheelZoomMultiplier;

    if (g_MapZoom <= g_MapZoomMaximum)
    {
        g_MapZoom = g_MapZoomMaximum;
    }
}

void EQAPP_Map_MouseWheelZoomIn()
{
    g_MapZoom += g_MapZoom * g_MapMouseWheelZoomMultiplier;

    if (g_MapZoom >= g_MapZoomMinimum)
    {
        g_MapZoom = g_MapZoomMinimum;
    }
}

void EQAPP_Map_HandleEvent_HandleMouseWheel(signed int mouseWheelDelta)
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
        if (g_MapZoom != 0.0f)
        {
            addX = addX / g_MapZoom;
        }

        g_MapOffsetX += addX;
    }

    if (speedY != 0)
    {
        float addY= (float)speedY;
        if (g_MapZoom != 0.0f)
        {
            addY = addY / g_MapZoom;
        }

        g_MapOffsetY += addY;
    }
}

void EQAPP_Map_SetZoom(float zoom)
{
    g_MapZoom = zoom;
}

void EQAPP_Map_ResetZoom()
{
    g_MapZoom = 1.0f;
}

void EQAPP_Map_Center()
{
    g_MapOffsetX = 0.0f;
    g_MapOffsetY = 0.0f;
}

bool EQAPP_Map_IsPointInsideMap(uint32_t x, uint32_t y)
{
    return (EQ_IsPointInsideRectangle(x, y, (int)(g_MapX), (int)(g_MapY), (int)g_MapWidth, (int)g_MapHeight) == true);
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
        if (EQAPP_Map_IsMouseOver() == true && EQ_IsMouseHoveringOverCXWnd() == false)
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

    EQ_DrawRectangle(g_MapX, g_MapY, g_MapWidth, g_MapHeight, g_MapBackgroundColorARGB, true);
    EQ_DrawRectangle(g_MapX, g_MapY, g_MapWidth, g_MapHeight, g_MapBorderColorARGB);

    g_MapNumLinesDrawn = 0;
    g_MapNumLabelsDrawn = 0;

    if (g_MapLinesIsEnabled == true)
    {
        for (auto& mapLine : g_MapLineList)
        {
            if (g_MapNumLinesDrawn > g_MapNumLinesMax)
            {
                break;
            }

            if (g_MapLayer0IsEnabled == false)
            {
                if (mapLine.Layer == 0)
                {
                    continue;
                }
            }

            if (g_MapLayer1IsEnabled == false)
            {
                if (mapLine.Layer == 1)
                {
                    continue;
                }
            }

            if (g_MapLayer2IsEnabled == false)
            {
                if (mapLine.Layer == 2)
                {
                    continue;
                }
            }

            if (g_MapLayer3IsEnabled == false)
            {
                if (mapLine.Layer == 3)
                {
                    continue;
                }
            }

            if (g_MapHeightFilterIsEnabled == true)
            {
                if (g_MapHeightFilterLow > 0.0f)
                {
                    if
                    (
                        mapLine.Line.Z1 < (playerSpawn->Z - g_MapHeightFilterLow) ||
                        mapLine.Line.Z2 < (playerSpawn->Z - g_MapHeightFilterLow)
                    )
                    {
                        continue;
                    }
                }

                if (g_MapHeightFilterHigh > 0.0f)
                {
                    if
                    (
                        mapLine.Line.Z1 > (playerSpawn->Z + g_MapHeightFilterHigh) ||
                        mapLine.Line.Z2 > (playerSpawn->Z + g_MapHeightFilterHigh)
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

            bool bDrawLine = EQ_LineClip(&line, g_MapMinX, g_MapMinY, g_MapMaxX, g_MapMaxY);
            if (bDrawLine == false)
            {
                continue;
            }

            EQ_DrawLineEx(&line, mapLine.Color.RGB);

            g_MapNumLinesDrawn++;
        }
    }

    if (g_MapLabelsIsEnabled == true)
    {
        for (auto& mapLabel : g_MapLabelList)
        {
            if (g_MapNumLabelsDrawn > g_MapNumLabelsMax)
            {
                break;
            }

            if (g_MapLayer0IsEnabled == false)
            {
                if (mapLabel.Layer == 0)
                {
                    continue;
                }
            }

            if (g_MapLayer1IsEnabled == false)
            {
                if (mapLabel.Layer == 1)
                {
                    continue;
                }
            }

            if (g_MapLayer2IsEnabled == false)
            {
                if (mapLabel.Layer == 2)
                {
                    continue;
                }
            }

            if (g_MapLayer3IsEnabled == false)
            {
                if (mapLabel.Layer == 3)
                {
                    continue;
                }
            }

            float labelX = 0.0f;
            float labelY = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(mapLabel.Location.X, mapLabel.Location.Y, labelX, labelY);

            if (EQAPP_Map_IsPointInsideMap((int)labelX, (int)labelY) == false)
            {
                continue;
            }

            EQ_DrawTextEx(mapLabel.Text.c_str(), (int)labelX, (int)labelY, EQ_COLOR_ARGB_WHITE, EQ_ADDRESS_POINTER_FONT_ARIAL12);

            g_MapNumLabelsDrawn++;
        }
    }

    if (g_MapSpawnsIsEnabled == true)
    {
        uint32_t numSpawnsMouseOver = 0;

        auto spawn = EQ_GetFirstSpawn();
        while (spawn != NULL)
        {
            if (spawn == playerSpawn)
            {
                spawn = spawn->Next;
                continue;
            }

            if (EQ_IsSpawnTargetable(spawn) == false)
            {
                spawn = spawn->Next;
                continue;
            }

            float spawnMapX = 0.0f;
            float spawnMapY = 0.0f;
            EQAPP_Map_ConvertWorldLocationToScreenPosition(-spawn->X, -spawn->Y, spawnMapX, spawnMapY);

            if
            (
                spawnMapX >= g_MapMaxX ||
                spawnMapY >= g_MapMaxY ||
                spawnMapX <= g_MapMinX ||
                spawnMapY <= g_MapMinY
            )
            {
                spawn = spawn->Next;
                continue;
            }

            EQ::Location spawnLocation;
            spawnLocation.X = spawn->X;
            spawnLocation.Y = spawn->Y;
            spawnLocation.Z = spawn->Z;

            ////float spawnDistance = EQ_CalculateDistance(spawnLocation.X, spawnLocation.Y, playerLocation.X, playerLocation.Y);

            float spawnDistanceZ = std::fabsf((float)spawnLocation.Z - (float)playerLocation.Z);

            bool useDistance = true;

            if
            (
                spawn == targetSpawn ||
                EQ_IsSpawnGroupMember(spawn) == true ||
                spawn->Type == EQ_SPAWN_TYPE_PLAYER ||
                spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE
            )
            {
                useDistance = false;
            }

            if (useDistance == true)
            {
                if (g_MapHeightFilterIsEnabled == true)
                {
                    if (spawnDistanceZ > g_MapSpawnDistanceZMax)
                    {
                        spawn = spawn->Next;
                        continue;
                    }
                }

                ////if (spawnDistance > g_MapSpawnDistanceMax)
                if (EQ_IsWithinDistance(spawnLocation.X, spawnLocation.Y, playerLocation.X, playerLocation.Y, g_MapSpawnDistanceMax) == false)
                {
                    spawn = spawn->Next;
                    continue;
                }
            }

            uint32_t textColorARGB = EQ_COLOR_ARGB_WHITE;

            if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
            {
                textColorARGB = EQ_COLOR_ARGB_RED;
            }
            else if (spawn->Type == EQ_SPAWN_TYPE_PLAYER_CORPSE)
            {
                textColorARGB = EQ_COLOR_ARGB_MAROON;
            }
            else if (spawn->Type == EQ_SPAWN_TYPE_NPC)
            {
                textColorARGB = EQ_COLOR_ARGB_AQUA;
            }
            else if (spawn->Type == EQ_SPAWN_TYPE_NPC_CORPSE)
            {
                textColorARGB = EQ_COLOR_ARGB_YELLOW;
            }

            if (EQ_IsSpawnGroupMember(spawn) == true)
            {
                textColorARGB = EQ_COLOR_ARGB_LIME;
            }

            if (spawn == targetSpawn)
            {
                textColorARGB = EQ_COLOR_ARGB_FUCHSIA;
            }

            std::string spawnText = "+";

            if (spawn->MovementSpeed > 0.0f)
            {
                spawnText = "*";
            }

            EQ_DrawText(spawnText.c_str(), (int)spawnMapX, (int)spawnMapY, textColorARGB);

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

                        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
                        {
                            spawnText << " (Player)";
                        }
                        else
                        {
                            if (spawn->PetOwnerSpawnID != 0)
                            {
                                spawnText << " (Pet)";
                            }
                        }

                        const char* spawnTextC = spawnText.str().c_str();

                        uint32_t spawnTextFont = EQ_ADDRESS_POINTER_FONT_ARIAL14;

                        uint32_t spawnTextX = mouseX + EQ_MOUSE_CURSOR_WIDTH + 1;
                        uint32_t spawnTextY = mouseY;

                        uint32_t spawnTextWidth = EQ_GetFontTextWidth(spawnTextC, spawnTextFont);
                        uint32_t spawnTextHeight = EQ_GetFontTextHeight(spawnTextFont);

                        uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);

                        if ((spawnTextX + spawnTextWidth) > resolutionWidth)
                        {
                            spawnTextX = mouseX - spawnTextWidth - 1;
                        }

                        if (numSpawnsMouseOver > 0)
                        {
                            spawnTextY = spawnTextY + (numSpawnsMouseOver * spawnTextHeight);
                        }

                        EQ_DrawTooltipText(spawnTextC, spawnTextX, spawnTextY, spawnTextFont);

                        numSpawnsMouseOver++;
                    }
                }
            }

            spawn = spawn->Next;
        }
    }

    EQ::Line mapCenterLineHorizontal;
    mapCenterLineHorizontal.X1 = playerMapX - g_MapCenterLineSize;
    mapCenterLineHorizontal.Y1 = playerMapY;
    mapCenterLineHorizontal.Z1 = 1.0f;
    mapCenterLineHorizontal.X2 = playerMapX + g_MapCenterLineSize;
    mapCenterLineHorizontal.Y2 = playerMapY;
    mapCenterLineHorizontal.Z2 = 1.0f;

    EQ::Line mapCenterLineVertical;
    mapCenterLineVertical.X1 = playerMapX;
    mapCenterLineVertical.Y1 = playerMapY - g_MapCenterLineSize;
    mapCenterLineVertical.Z1 = 1.0f;
    mapCenterLineVertical.X2 = playerMapX;
    mapCenterLineVertical.Y2 = playerMapY + g_MapCenterLineSize;
    mapCenterLineVertical.Z2 = 1.0f;

    EQ_DrawLineEx(&mapCenterLineHorizontal, g_MapCenterLineColorARGB);
    EQ_DrawLineEx(&mapCenterLineVertical,   g_MapCenterLineColorARGB);

    float playerHeadingC = playerSpawn->Heading;

    playerHeadingC = playerHeadingC - 128.0f;

    if (playerHeadingC < 0.0f)
    {
        playerHeadingC = playerHeadingC + 512.0f;
    }

    float playerHeadingRadiansC = playerHeadingC * (EQ_PI / 256.0f);

    float arrowAddCX = cosf(playerHeadingRadiansC);
    arrowAddCX = arrowAddCX * g_MapArrowRadius;

    float arrowAddCY = sinf(playerHeadingRadiansC);
    arrowAddCY = arrowAddCY * g_MapArrowRadius;

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
    arrowAddBX = arrowAddBX * (g_MapArrowRadius * 0.5f);

    float arrowAddBY = sinf(playerHeadingRadiansB);
    arrowAddBY = arrowAddBY * (g_MapArrowRadius * 0.5f);

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
    arrowAddAX = arrowAddAX * (g_MapArrowRadius * 0.5f);

    float arrowAddAY = sinf(playerHeadingRadiansA);
    arrowAddAY = arrowAddAY * (g_MapArrowRadius * 0.5f);

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

    EQ_DrawLineEx(&mapArrowLineA, g_MapArrowColorARGB);
    EQ_DrawLineEx(&mapArrowLineB, g_MapArrowColorARGB);
    EQ_DrawLineEx(&mapArrowLineC, g_MapArrowColorARGB);
}

void EQAPP_Map_3D_Execute()
{
    g_MapNumLinesDrawn = 0;

    for (auto& mapLine : g_MapLineList)
    {
        if (g_MapNumLinesDrawn > g_MapNumLinesMax)
        {
            break;
        }

        EQ::Location location1;
        location1.Y = -mapLine.Line.Y1;
        location1.X = -mapLine.Line.X1;
        location1.Z = mapLine.Line.Z1;

        float screenX1 = 0.0f;
        float screenY1 = 0.0f;
        if (EQ_WorldSpaceToScreenSpaceFloat(location1, screenX1, screenY1) == false)
        {
            continue;
        }

        EQ::Location location2;
        location2.Y = -mapLine.Line.Y2;
        location2.X = -mapLine.Line.X2;
        location2.Z = mapLine.Line.Z2;

        float screenX2 = 0.0f;
        float screenY2 = 0.0f;
        if (EQ_WorldSpaceToScreenSpaceFloat(location2, screenX2, screenY2) == false)
        {
            continue;
        }

        EQ::Line line;

        line.X1 = screenX1;
        line.Y1 = screenY1;
        line.Z1 = 0.0f;

        line.X2 = screenX2;
        line.Y2 = screenY2;
        line.Z2 = 0.0f;

        EQ_DrawLineEx(&line, mapLine.Color.RGB);

        g_MapNumLinesDrawn++;
    }
}


