#pragma once

bool g_GUIMapWindowIsEnabled = false;

bool g_GUIMapWindowMapLinesIsEnabled = true;
bool g_GUIMapWindowMapLabelsIsEnabled = false;
bool g_GUIMapWindowMapSpawnsIsEnabled = true;

bool g_GUIMapWindowMapHeightFilterLinesIsEnabled = false;
bool g_GUIMapWindowMapHeightFilterLabelsIsEnabled = false;
bool g_GUIMapWindowMapHeightFilterSpawnsIsEnabled = false;

bool g_GUIMapWindowMapLayer0IsEnabled = true;
bool g_GUIMapWindowMapLayer1IsEnabled = true;
bool g_GUIMapWindowMapLayer2IsEnabled = false;
bool g_GUIMapWindowMapLayer3IsEnabled = false;

float g_GUIMapWindowX = 0.0f;
float g_GUIMapWindowY = 0.0f;

float g_GUIMapWindowAlphaActive = 1.0f;
float g_GUIMapWindowAlphaInactive = 0.8f;

float g_GUIMapWindowMapX = 0.0f;
float g_GUIMapWindowMapY = 0.0f;

float g_GUIMapWindowMapWidth  = 500.0f;
float g_GUIMapWindowMapHeight = 400.0f;

float g_GUIMapWindowMapMinX = g_GUIMapWindowMapX;
float g_GUIMapWindowMapMaxX = g_GUIMapWindowMapX + g_GUIMapWindowMapWidth;

float g_GUIMapWindowMapMinY = g_GUIMapWindowMapY;
float g_GUIMapWindowMapMaxY = g_GUIMapWindowMapY + g_GUIMapWindowMapHeight;

float g_GUIMapWindowMapOriginX = g_GUIMapWindowMapX + (g_GUIMapWindowMapWidth  * 0.5f);
float g_GUIMapWindowMapOriginY = g_GUIMapWindowMapY + (g_GUIMapWindowMapHeight * 0.5f);

float g_GUIMapWindowMapOffsetX = 0.0f;
float g_GUIMapWindowMapOffsetY = 0.0f;

float g_GUIMapWindowMapHeightFilterLow  = 10.0f; // z axis
float g_GUIMapWindowMapHeightFilterHigh = 10.0f; // z axis

float g_GUIMapWindowMapZoom           = 1.0f;
float g_GUIMapWindowMapZoomMultiplier = 0.05f; // zoom speed
float g_GUIMapWindowMapZoomDefault    = 1.0f;
float g_GUIMapWindowMapZoomMinimum    = 10.0f;
float g_GUIMapWindowMapZoomMaximum    = 0.01f;

float g_GUIMapWindowMapMouseWheelZoomMultiplier = 0.5f; // mouse wheel zoom speed

float g_GUIMapWindowMapMouseCursorSize = 16.0f;

float g_GUIMapWindowMapTextHeightOffset = 5.0f;

float g_GUIMapWindowMapLabelCircleSize = 4.0f;
float g_GUIMapWindowMapSpawnCircleSize = 4.0f;

float g_GUIMapWindowMapArrowSize = 20.0f;

LPDIRECT3DTEXTURE9 g_GUIMapWindowMapBackgroundTexture = NULL;

static void EQAPP_GUI_MapWindow();
static void EQAPP_GUI_MapWindow_LoadTextures();
static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY);
static bool EQAPP_GUI_MapWindow_Map_IsPointInsideMap(int x, int y);
static void EQAPP_GUI_MapWindow_Map_ZoomOut();
static void EQAPP_GUI_MapWindow_Map_ZoomIn();
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut();
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn();
static void EQAPP_GUI_MapWindow_Map_SetZoom(float zoom);
static void EQAPP_GUI_MapWindow_Map_ResetZoom();
static void EQAPP_GUI_MapWindow_Map_Scroll(signed int speedX, signed int speedY);
static void EQAPP_GUI_MapWindow_Map_Center();
static void EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(uint32_t spawn, ImColor& color);
static void EQAPP_GUI_MapWindow_Map_Draw();
static void EQAPP_GUI_MapWindow_Map_PrintDebugInformation();

static void EQAPP_GUI_MapWindow()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true || io.WantCaptureKeyboard == true)
    {
       ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMapWindowAlphaActive);
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMapWindowAlphaInactive);
    }

    ImGui::SetNextWindowPos(ImVec2(g_GUIMapWindowX, g_GUIMapWindowY), ImGuiCond_Once);

    if (ImGui::Begin("Map##MapWindow", &g_GUIMapWindowIsEnabled, ImGuiWindowFlags_MenuBar) == false)
    {
        ImGui::End();
        return;
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File##MapWindowMenuFile"))
        {
            if (ImGui::MenuItem("Print Debug Information##MapWindowMenuItemFilePrintDebugInformation")) EQAPP_GUI_MapWindow_Map_PrintDebugInformation();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options##MapWindowMenuOptions"))
        {
            if (ImGui::MenuItem("Base Layer##MapWindowMenuItemOptionsLayer0", NULL, &g_GUIMapWindowMapLayer0IsEnabled)) {}
            if (ImGui::MenuItem("Layer 1##MapWindowMenuItemOptionsLayer1", NULL, &g_GUIMapWindowMapLayer1IsEnabled)) {}
            if (ImGui::MenuItem("Layer 2##MapWindowMenuItemOptionsLayer2", NULL, &g_GUIMapWindowMapLayer2IsEnabled)) {}
            if (ImGui::MenuItem("Layer 3##MapWindowMenuItemOptionsLayer3", NULL, &g_GUIMapWindowMapLayer3IsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Lines##MapWindowMenuItemOptionsLines", NULL, &g_GUIMapWindowMapLinesIsEnabled)) {}
            if (ImGui::MenuItem("Labels##MapWindowMenuItemOptionsLabels", NULL, &g_GUIMapWindowMapLabelsIsEnabled)) {}
            if (ImGui::MenuItem("Spawns##MapWindowMenuItemOptionsSpawns", NULL, &g_GUIMapWindowMapSpawnsIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Height Filter for Lines##MapWindowMenuItemOptionsHeightFilterForLines", NULL, &g_GUIMapWindowMapHeightFilterLinesIsEnabled)) {}
            if (ImGui::MenuItem("Height Filter for Labels##MapWindowMenuItemOptionsHeightFilterForLabels", NULL, &g_GUIMapWindowMapHeightFilterLabelsIsEnabled)) {}
            if (ImGui::MenuItem("Height Filter for Spawns##MapWindowMenuItemOptionsHeightFilterForSpawns", NULL, &g_GUIMapWindowMapHeightFilterSpawnsIsEnabled)) {}

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    EQAPP_GUI_MapWindow_Map_Draw();

    ImGui::End();
}

static void EQAPP_GUI_MapWindow_LoadTextures()
{
    g_GUIMapWindowMapBackgroundTexture = NULL;

    auto render = EQ_GetRender();
    if (render == NULL)
    {
        return;
    }

    auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
    if (devicePointer == NULL)
    {
        return;
    }

    HRESULT result = D3DXCreateTextureFromFile(devicePointer, L"uifiles\\default\\cart.tga", &g_GUIMapWindowMapBackgroundTexture);
    if (result != D3D_OK)
    {
        std::cout << "D3DXCreateTextureFromFile() failed!" << std::endl;
    }
}

static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    screenX = (((x * g_GUIMapWindowMapZoom) + g_GUIMapWindowMapOriginX) + ((playerSpawnX + g_GUIMapWindowMapOffsetX) * g_GUIMapWindowMapZoom));
    screenY = (((y * g_GUIMapWindowMapZoom) + g_GUIMapWindowMapOriginY) + ((playerSpawnY + g_GUIMapWindowMapOffsetY) * g_GUIMapWindowMapZoom));
}

static bool EQAPP_GUI_MapWindow_Map_IsPointInsideMap(int x, int y)
{
    return EQ_IsPointInsideRectangle(x, y, (int)g_GUIMapWindowMapX, (int)g_GUIMapWindowMapY, (int)g_GUIMapWindowMapWidth, (int)g_GUIMapWindowMapHeight) == true;
}

static void EQAPP_GUI_MapWindow_Map_ZoomOut()
{
    g_GUIMapWindowMapZoom -= g_GUIMapWindowMapZoom * g_GUIMapWindowMapZoomMultiplier;

    if (g_GUIMapWindowMapZoom <= g_GUIMapWindowMapZoomMaximum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMaximum;
    }
}

static void EQAPP_GUI_MapWindow_Map_ZoomIn()
{
    g_GUIMapWindowMapZoom += g_GUIMapWindowMapZoom * g_GUIMapWindowMapZoomMultiplier;

    if (g_GUIMapWindowMapZoom >= g_GUIMapWindowMapZoomMinimum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMinimum;
    }
}

static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut()
{
    g_GUIMapWindowMapZoom -= g_GUIMapWindowMapZoom * g_GUIMapWindowMapMouseWheelZoomMultiplier;

    if (g_GUIMapWindowMapZoom <= g_GUIMapWindowMapZoomMaximum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMaximum;
    }
}

static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn()
{
    g_GUIMapWindowMapZoom += g_GUIMapWindowMapZoom * g_GUIMapWindowMapMouseWheelZoomMultiplier;

    if (g_GUIMapWindowMapZoom >= g_GUIMapWindowMapZoomMinimum)
    {
        g_GUIMapWindowMapZoom = g_GUIMapWindowMapZoomMinimum;
    }
}

static void EQAPP_GUI_MapWindow_Map_SetZoom(float zoom)
{
    g_GUIMapWindowMapZoom = zoom;
}

static void EQAPP_GUI_MapWindow_Map_ResetZoom()
{
    g_GUIMapWindowMapZoom = 1.0f;
}

static void EQAPP_GUI_MapWindow_Map_Scroll(signed int speedX, signed int speedY)
{
    if (speedX != 0)
    {
        float addX = (float)speedX;

        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            addX = addX / g_GUIMapWindowMapZoom;
        }

        g_GUIMapWindowMapOffsetX += addX;
    }

    if (speedY != 0)
    {
        float addY = (float)speedY;

        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            addY = addY / g_GUIMapWindowMapZoom;
        }

        g_GUIMapWindowMapOffsetY += addY;
    }
}

static void EQAPP_GUI_MapWindow_Map_Center()
{
    g_GUIMapWindowMapOffsetX = 0.0f;
    g_GUIMapWindowMapOffsetY = 0.0f;
}

static void EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(uint32_t spawn, ImColor& color)
{
    auto spawnY = EQ_GetSpawnY(spawn);
    auto spawnX = EQ_GetSpawnX(spawn);

    auto spawnHeading = EQ_GetSpawnHeading(spawn);

    // line1

    float line1BeginX = spawnX;
    float line1BeginY = spawnY;

    float line1EndX = spawnX;
    float line1EndY = spawnY;

    EQ_ApplyForwardMovement(line1EndY, line1EndX, spawnHeading, g_GUIMapWindowMapArrowSize);

    float line1BeginMapX = 0.0f;
    float line1BeginMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line1BeginX, -line1BeginY, line1BeginMapX, line1BeginMapY);

    float line1EndMapX = 0.0f;
    float line1EndMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line1EndX, -line1EndY, line1EndMapX, line1EndMapY);

    // line 2

    float line2BeginX = line1EndX;
    float line2BeginY = line1EndY;

    float line2EndX = line1EndX;
    float line2EndY = line1EndY;

    EQ_ApplyBackwardMovement(line2EndY, line2EndX, spawnHeading, g_GUIMapWindowMapArrowSize * 0.5f);
    EQ_ApplyLeftwardMovement(line2EndY, line2EndX, spawnHeading, g_GUIMapWindowMapArrowSize * 0.25f);

    float line2BeginMapX = 0.0f;
    float line2BeginMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line2BeginX, -line2BeginY, line2BeginMapX, line2BeginMapY);

    float line2EndMapX = 0.0f;
    float line2EndMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line2EndX, -line2EndY, line2EndMapX, line2EndMapY);

    // line 3

    float line3BeginX = line1EndX;
    float line3BeginY = line1EndY;

    float line3EndX = line1EndX;
    float line3EndY = line1EndY;

    EQ_ApplyBackwardMovement(line3EndY, line3EndX, spawnHeading, g_GUIMapWindowMapArrowSize * 0.5f);
    EQ_ApplyRightwardMovement(line3EndY, line3EndX, spawnHeading, g_GUIMapWindowMapArrowSize * 0.25f);

    float line3BeginMapX = 0.0f;
    float line3BeginMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line3BeginX, -line3BeginY, line3BeginMapX, line3BeginMapY);

    float line3EndMapX = 0.0f;
    float line3EndMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-line3EndX, -line3EndY, line3EndMapX, line3EndMapY);

    // draw lines

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->AddLine(ImVec2(line1BeginMapX, line1BeginMapY), ImVec2(line1EndMapX, line1EndMapY), color);
    drawList->AddLine(ImVec2(line2BeginMapX, line2BeginMapY), ImVec2(line2EndMapX, line2EndMapY), color);
    drawList->AddLine(ImVec2(line3BeginMapX, line3BeginMapY), ImVec2(line3EndMapX, line3EndMapY), color);
}

static void EQAPP_GUI_MapWindow_Map_Draw()
{
    ImGuiIO& io = ImGui::GetIO();

    uint32_t drawCount = 0;

    ImVec2 drawPosition = ImGui::GetCursorScreenPos();

    g_GUIMapWindowMapX = drawPosition.x;
    g_GUIMapWindowMapY = drawPosition.y;

    ImVec2 mapSize = ImGui::GetContentRegionAvail();

    g_GUIMapWindowMapWidth = mapSize.x;
    g_GUIMapWindowMapHeight = mapSize.y;

    g_GUIMapWindowMapMinX = g_GUIMapWindowMapX;
    g_GUIMapWindowMapMaxX = g_GUIMapWindowMapX + g_GUIMapWindowMapWidth;

    g_GUIMapWindowMapMinY = g_GUIMapWindowMapY;
    g_GUIMapWindowMapMaxY = g_GUIMapWindowMapY + g_GUIMapWindowMapHeight;

    g_GUIMapWindowMapOriginX = g_GUIMapWindowMapX + (g_GUIMapWindowMapWidth  * 0.5f);
    g_GUIMapWindowMapOriginY = g_GUIMapWindowMapY + (g_GUIMapWindowMapHeight * 0.5f);

    if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)io.MousePos.x, (int)io.MousePos.y) == true)
    {
        if (io.MouseWheel < 0.0f)
        {
            EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut();
        }
        else if (io.MouseWheel > 0.0f)
        {
            EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn();
        }
    }

    float spawnCircleSize = g_GUIMapWindowMapSpawnCircleSize;
    if (g_GUIMapWindowMapZoom != 0.0f)
    {
        spawnCircleSize = spawnCircleSize * g_GUIMapWindowMapZoom;

        if (spawnCircleSize < 1.0f)
        {
            spawnCircleSize = 1.0f;
        }
    }

    auto targetSpawn = EQ_GetTargetSpawn();

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
    auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
    auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

    float playerMapX = 0.0f;
    float playerMapY = 0.0f;
    EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-playerSpawnX, -playerSpawnY, playerMapX, playerMapY);

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->PushClipRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), true);

    if (g_GUIMapWindowMapLinesIsEnabled == true)
    {
        auto mapLines = EQ_MapWindow_GetLines();
        if (mapLines != NULL)
        {
            EQ::MapLine_ptr mapLine = (EQ::MapLine_ptr)mapLines;
            while (mapLine != NULL)
            {
                if (g_GUIMapWindowMapLayer0IsEnabled == false)
                {
                    if (mapLine->Layer == 0)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer1IsEnabled == false)
                {
                    if (mapLine->Layer == 1)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer2IsEnabled == false)
                {
                    if (mapLine->Layer == 2)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer3IsEnabled == false)
                {
                    if (mapLine->Layer == 3)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterLinesIsEnabled == true)
                {
                    if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                    {
                        if
                        (
                            mapLine->Begin.Z < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow) ||
                            mapLine->End.Z   < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow)
                        )
                        {
                            mapLine = mapLine->Next;
                            continue;
                        }
                    }

                    if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                    {
                        if
                        (
                            mapLine->Begin.Z > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh) ||
                            mapLine->End.Z   > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh)
                        )
                        {
                            mapLine = mapLine->Next;
                            continue;
                        }
                    }
                }

                float lineBeginX = 0.0f;
                float lineBeginY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->Begin.X, mapLine->Begin.Y, lineBeginX, lineBeginY);

                float lineEndX = 0.0f;
                float lineEndY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->End.X, mapLine->End.Y, lineEndX, lineEndY);

                if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)lineBeginX, (int)lineBeginY) == false)
                {
                    if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)lineEndX, (int)lineEndY) == false)
                    {
                        mapLine = mapLine->Next;
                        continue;
                    }
                }

                ImColor lineColor = ImColor(mapLine->Color.R, mapLine->Color.G, mapLine->Color.B, mapLine->Color.A);

                // convert black lines to white lines
                if (lineColor.Value.x == 0 && lineColor.Value.y == 0 && lineColor.Value.z == 0)
                {
                    lineColor.Value.x = 1;
                    lineColor.Value.y = 1;
                    lineColor.Value.z = 1;
                }

                drawList->AddLine(ImVec2(lineBeginX, lineBeginY), ImVec2(lineEndX, lineEndY), lineColor);
                drawCount++;

                mapLine = mapLine->Next;
            }
        }
    }

    if (g_GUIMapWindowMapSpawnsIsEnabled == true)
    {
        bool spawnMouseHover = false;
        bool spawnMouseHoverDrawCircle = false;
        float spawnMouseHoverX = 0.0f;
        float spawnMouseHoverY = 0.0f;
        std::string spawnMouseHoverText = std::string();
        ImVec2 spawnMouseHoverTextSize;
        ImColor spawnMouseHoverColor = ImColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow
        ImColor spawnMouseHoverBackColor = ImColor(0.0f, 0.0f, 0.0f, 1.0f); // black

        auto spawn = EQ_GetFirstSpawn();
        while (spawn != NULL)
        {
            if (spawn == playerSpawn)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }

            auto spawnType = EQ_GetSpawnType(spawn);

            if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                if (EQ_IsSpawnMount(spawn) == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }

                if (EQ_IsSpawnAura(spawn) == true)
                {
                    spawn = EQ_GetSpawnNext(spawn);
                    continue;
                }
            }

            auto spawnY = EQ_GetSpawnY(spawn);
            auto spawnX = EQ_GetSpawnX(spawn);
            auto spawnZ = EQ_GetSpawnZ(spawn);

            if (g_GUIMapWindowMapHeightFilterSpawnsIsEnabled == true)
            {
                if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                {
                    if (spawnZ < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow))
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                {
                    if (spawnZ > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh))
                    {
                        spawn = EQ_GetSpawnNext(spawn);
                        continue;
                    }
                }
            }

            float spawnMapX = 0.0f;
            float spawnMapY = 0.0f;
            EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(-spawnX, -spawnY, spawnMapX, spawnMapY);

            if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)spawnMapX, (int)spawnMapY) == false)
            {
                spawn = EQ_GetSpawnNext(spawn);
                continue;
            }

            if (spawnMouseHover == false)
            {
                auto mouseDistanceToSpawnX = std::fabsf(io.MousePos.x - spawnMapX);
                auto mouseDistanceToSpawnY = std::fabsf(io.MousePos.y - spawnMapY);

                float mouseDistanceToSpawnCheck = g_GUIMapWindowMapSpawnCircleSize + 1.0f;
                mouseDistanceToSpawnCheck = mouseDistanceToSpawnCheck * g_GUIMapWindowMapZoom;

                if (mouseDistanceToSpawnX < mouseDistanceToSpawnCheck)
                {
                    if (mouseDistanceToSpawnY < mouseDistanceToSpawnCheck)
                    {
                        auto spawnName = EQ_GetSpawnName(spawn);
                        if (spawnName.size() != 0)
                        {
                            std::stringstream ssHoverText;
                            ssHoverText << spawnName;

                            if (spawnType == EQ_SPAWN_TYPE_NPC)
                            {
                                auto spawnLastName = EQ_GetSpawnLastName(spawn);
                                if (spawnLastName.size() != 0)
                                {
                                    ssHoverText << "\n(" << spawnLastName << ")";
                                }
                            }

                            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);

                            spawnMouseHoverTextSize = ImGui::CalcTextSize(ssHoverText.str().c_str(), NULL);

                            spawnMouseHoverX = spawnMapX - (spawnMouseHoverTextSize.x * 0.5f);
                            spawnMouseHoverY = spawnMapY - spawnMouseHoverTextSize.y - g_GUIMapWindowMapTextHeightOffset - (g_GUIMapWindowMapSpawnCircleSize * g_GUIMapWindowMapZoom);

                            spawnMouseHoverText = ssHoverText.str();

                            spawnMouseHover = true;

                            spawnMouseHoverDrawCircle = true;
                        }
                    }
                }
            }

            ImColor spawnColor = ImColor(1.0f, 1.0f, 1.0f, 1.0f); // white

            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
            {
                spawnColor = ImColor(1.0f, 0.0f, 0.0f, 1.0f); // red
            }
            else if (spawnType == EQ_SPAWN_TYPE_NPC)
            {
                spawnColor = ImColor(0.0f, 1.0f, 1.0f, 1.0f); // cyan
            }
            else if (spawnType == EQ_SPAWN_TYPE_CORPSE)
            {
                spawnColor = ImColor(1.0f, 1.0f, 0.0f, 1.0f); // yellow
            }

            if (EQ_IsSpawnMercenary(spawn) == true)
            {
                spawnColor = ImColor(0.5f, 0.0f, 0.0f, 1.0f); // dark red
            }

            if (EQ_IsSpawnPet(spawn) == true)
            {
                spawnColor = ImColor(0.0f, 0.5f, 0.5f, 1.0f); // dark cyan
            }

            if (EQ_IsSpawnGroupMember(spawn) == true)
            {
                spawnColor = ImColor(0.0f, 1.0f, 0.0f, 1.0f); // green
            }

            if (spawn == targetSpawn)
            {
                spawnColor = ImColor(1.0f, 0.0f, 1.0f, 1.0f); // magenta
            }

            drawList->AddCircleFilled(ImVec2(spawnMapX, spawnMapY), spawnCircleSize, spawnColor);
            drawCount++;

            if (spawnMouseHoverDrawCircle == true)
            {
                drawList->AddCircle(ImVec2(spawnMapX, spawnMapY), spawnCircleSize, spawnMouseHoverColor);
                drawCount++;

                spawnMouseHoverDrawCircle = false;
            }

            spawn = EQ_GetSpawnNext(spawn);
        }

        if (spawnMouseHover == true)
        {
            drawList->AddRectFilled(ImVec2(spawnMouseHoverX, spawnMouseHoverY), ImVec2(spawnMouseHoverX + spawnMouseHoverTextSize.x, spawnMouseHoverY + spawnMouseHoverTextSize.y), spawnMouseHoverBackColor);
            drawCount++;

            drawList->AddText(ImVec2(spawnMouseHoverX, spawnMouseHoverY), spawnMouseHoverColor, spawnMouseHoverText.c_str(), NULL);
            drawCount++;
        }
    }

    if (g_GUIMapWindowMapLabelsIsEnabled == true)
    {
        float labelCircleSize = g_GUIMapWindowMapLabelCircleSize;
        if (g_GUIMapWindowMapZoom != 0.0f)
        {
            labelCircleSize = labelCircleSize * g_GUIMapWindowMapZoom;

            if (labelCircleSize < 1.0f)
            {
                labelCircleSize = 1.0f;
            }
        }

        auto mapLabels = EQ_MapWindow_GetLabels();
        if (mapLabels != NULL)
        {
            EQ::MapLabel_ptr mapLabel = (EQ::MapLabel_ptr)mapLabels;
            while (mapLabel != NULL)
            {
                if (g_GUIMapWindowMapLayer0IsEnabled == false)
                {
                    if (mapLabel->Layer == 0)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer1IsEnabled == false)
                {
                    if (mapLabel->Layer == 1)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer2IsEnabled == false)
                {
                    if (mapLabel->Layer == 2)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapLayer3IsEnabled == false)
                {
                    if (mapLabel->Layer == 3)
                    {
                        mapLabel = mapLabel->Next;
                        continue;
                    }
                }

                if (g_GUIMapWindowMapHeightFilterLabelsIsEnabled == true)
                {
                    if (g_GUIMapWindowMapHeightFilterLow > 0.0f)
                    {
                        if (mapLabel->Location.Z < (playerSpawnZ - g_GUIMapWindowMapHeightFilterLow))
                        {
                            mapLabel = mapLabel->Next;
                            continue;
                        }
                    }

                    if (g_GUIMapWindowMapHeightFilterHigh > 0.0f)
                    {
                        if (mapLabel->Location.Z > (playerSpawnZ + g_GUIMapWindowMapHeightFilterHigh))
                        {
                            mapLabel = mapLabel->Next;
                            continue;
                        }
                    }
                }

                float labelMapX = 0.0f;
                float labelMapY = 0.0f;
                EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLabel->Location.X, mapLabel->Location.Y, labelMapX, labelMapY);

                if (EQAPP_GUI_MapWindow_Map_IsPointInsideMap((int)labelMapX, (int)labelMapY) == false)
                {
                    mapLabel = mapLabel->Next;
                    continue;
                }

                ImColor labelColor = ImColor(mapLabel->Color.R, mapLabel->Color.G, mapLabel->Color.B, mapLabel->Color.A);

                // convert black labels to white labels
                if (labelColor.Value.x == 0 && labelColor.Value.y == 0 && labelColor.Value.z == 0)
                {
                    labelColor.Value.x = 1;
                    labelColor.Value.y = 1;
                    labelColor.Value.z = 1;
                }

                drawList->AddCircleFilled(ImVec2(labelMapX, labelMapY), labelCircleSize, labelColor);

                ImVec2 textSize = ImGui::CalcTextSize(mapLabel->Text, NULL);

                labelMapX = labelMapX - (textSize.x * 0.5f);
                labelMapY = labelMapY - textSize.y - g_GUIMapWindowMapTextHeightOffset - (g_GUIMapWindowMapLabelCircleSize * g_GUIMapWindowMapZoom);

                drawList->AddText(ImVec2(labelMapX, labelMapY), labelColor, mapLabel->Text, NULL);
                drawCount++;

                mapLabel = mapLabel->Next;
            }
        }
    }

    // player spawn
    drawList->AddCircleFilled(ImVec2(playerMapX, playerMapY), spawnCircleSize, ImColor(1.0f, 0.5f, 0.0f, 1.0f)); // orange
    drawCount++;

    if (playerSpawn == targetSpawn)
    {
        drawList->AddCircle(ImVec2(playerMapX, playerMapY), spawnCircleSize, ImColor(1.0f, 0.0f, 1.0f, 1.0f)); // magenta
        drawCount++;
    }

    EQAPP_GUI_MapWindow_Map_DrawSpawnArrow(playerSpawn, ImColor(1.0f, 0.5f, 0.0f, 1.0f));
    drawCount += 3;

    drawList->PopClipRect();

    // map border
    drawList->AddRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), ImColor(1.0f, 1.0f, 1.0f, 1.0f));
    drawCount++;

/*
    std::stringstream ss;
    ss << "Draw Count: " << drawCount;

    EQ_DrawText(ss.str().c_str(), 100, 100);
*/
}

static void EQAPP_GUI_MapWindow_Map_PrintDebugInformation()
{
    auto mapLines = EQ_MapWindow_GetLines();
    if (mapLines != NULL)
    {
        EQ::MapLine_ptr mapLine = (EQ::MapLine_ptr)mapLines;
        while (mapLine != NULL)
        {
            std::cout << "mapLine->Begin.X: " << mapLine->Begin.X << std::endl;
            std::cout << "mapLine->Begin.Y: " << mapLine->Begin.Y << std::endl;
            std::cout << "mapLine->End.X: " << mapLine->End.X << std::endl;
            std::cout << "mapLine->End.Y: " << mapLine->End.Y << std::endl;

            float lineBeginX = 0.0f;
            float lineBeginY = 0.0f;
            EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->Begin.X, mapLine->Begin.Y, lineBeginX, lineBeginY);

            float lineEndX = 0.0f;
            float lineEndY = 0.0f;
            EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLine->End.X, mapLine->End.Y, lineEndX, lineEndY);

            std::cout << "lineBeginX: " << lineBeginX << std::endl;
            std::cout << "lineBeginY: " << lineBeginY << std::endl;
            std::cout << "lineEndX: " << lineEndX << std::endl;
            std::cout << "lineEndY: " << lineEndY << std::endl;

            mapLine = mapLine->Next;
        }
    }

    auto mapLabels = EQ_MapWindow_GetLabels();
    if (mapLabels != NULL)
    {
        EQ::MapLabel_ptr mapLabel = (EQ::MapLabel_ptr)mapLabels;
        while (mapLabel != NULL)
        {
            std::cout << "mapLabel->Text: " << mapLabel->Text << std::endl;

            std::cout << "mapLabel->Location.X: " << mapLabel->Location.X << std::endl;
            std::cout << "mapLabel->Location.Y: " << mapLabel->Location.Y << std::endl;

            float labelMapX = 0.0f;
            float labelMapY = 0.0f;
            EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(mapLabel->Location.X, mapLabel->Location.Y, labelMapX, labelMapY);

            std::cout << "labelMapX: " << labelMapX << std::endl;
            std::cout << "labelMapY: " << labelMapY << std::endl;

            mapLabel = mapLabel->Next;
        }
    }
}
