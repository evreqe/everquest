#pragma once

bool g_GUIMapWindowIsEnabled = false;

bool g_GUIMapWindowMapLinesIsEnabled = true;
bool g_GUIMapWindowMapLabelsIsEnabled = false;
bool g_GUIMapWindowMapSpawnsIsEnabled = true;

bool g_GUIMapWindowMapHeightFilterIsEnabled = false;

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

LPDIRECT3DTEXTURE9 g_GUIMapWindowMapBackgroundTexture = NULL;

static void EQAPP_GUI_MapWindow();
static void EQAPP_GUI_MapWindow_LoadTextures();
static void EQAPP_GUI_MapWindow_Map_ConvertWorldLocationToScreenPosition(float x, float y, float& screenX, float& screenY);
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomOut();
static void EQAPP_GUI_MapWindow_Map_MouseWheelZoomIn();
static void EQAPP_GUI_MapWindow_Map_Draw();

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
        if (ImGui::BeginMenu("Options##MapWindowMenuOptions"))
        {
            if (ImGui::MenuItem("Lines##MapWindowMenuItemOptionsLines", NULL, &g_GUIMapWindowMapLinesIsEnabled)) {}
            if (ImGui::MenuItem("Labels##MapWindowMenuItemOptionsLabels", NULL, &g_GUIMapWindowMapLabelsIsEnabled)) {}
            if (ImGui::MenuItem("Spawns##MapWindowMenuItemOptionsSpawns", NULL, &g_GUIMapWindowMapSpawnsIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Height Filter##MapWindowMenuItemOptionsHeightFilter", NULL, &g_GUIMapWindowMapHeightFilterIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Base##MapWindowMenuItemOptionsLayer0", NULL, &g_GUIMapWindowMapLayer0IsEnabled)) {}
            if (ImGui::MenuItem("Layer 1##MapWindowMenuItemOptionsLayer1", NULL, &g_GUIMapWindowMapLayer1IsEnabled)) {}
            if (ImGui::MenuItem("Layer 2##MapWindowMenuItemOptionsLayer2", NULL, &g_GUIMapWindowMapLayer2IsEnabled)) {}
            if (ImGui::MenuItem("Layer 3##MapWindowMenuItemOptionsLayer3", NULL, &g_GUIMapWindowMapLayer3IsEnabled)) {}

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

static void EQAPP_GUI_MapWindow_Map_Draw()
{
    ImVec2 drawPosition = ImGui::GetCursorScreenPos();

    g_GUIMapWindowMapX = drawPosition.x;
    g_GUIMapWindowMapY = drawPosition.y;

    g_GUIMapWindowMapMinX = g_GUIMapWindowMapX;
    g_GUIMapWindowMapMaxX = g_GUIMapWindowMapX + g_GUIMapWindowMapWidth;

    g_GUIMapWindowMapMinY = g_GUIMapWindowMapY;
    g_GUIMapWindowMapMaxY = g_GUIMapWindowMapY + g_GUIMapWindowMapHeight;

    g_GUIMapWindowMapOriginX = g_GUIMapWindowMapX + (g_GUIMapWindowMapWidth  * 0.5f);
    g_GUIMapWindowMapOriginY = g_GUIMapWindowMapY + (g_GUIMapWindowMapHeight * 0.5f);

    ImGuiIO& io = ImGui::GetIO();
    if (EQ_IsPointInsideRectangle((int)io.MousePos.x, (int)io.MousePos.y, (int)g_GUIMapWindowMapX, (int)g_GUIMapWindowMapY, (int)g_GUIMapWindowMapWidth, (int)g_GUIMapWindowMapHeight) == true)
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

    if (g_GUIMapWindowMapLinesIsEnabled == true)
    {
        auto mapLines = EQ_MapWindow_GetLines();
        if (mapLines != NULL)
        {
            drawList->PushClipRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), true);
        
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

                if (g_GUIMapWindowMapHeightFilterIsEnabled == true)
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

                ImColor lineColor = ImColor(mapLine->Color.R, mapLine->Color.G, mapLine->Color.B, mapLine->Color.A);

                // convert black lines to white lines
                if (lineColor.Value.x == 0 && lineColor.Value.y == 0 && lineColor.Value.z == 0)
                {
                    lineColor.Value.x = 1;
                    lineColor.Value.y = 1;
                    lineColor.Value.z = 1;
                }

                drawList->AddLine(ImVec2(lineBeginX, lineBeginY), ImVec2(lineEndX, lineEndY), lineColor);

                mapLine = mapLine->Next;
            }

            drawList->PopClipRect();
        }
    }

    // map border
    drawList->AddRect(ImVec2(g_GUIMapWindowMapX, g_GUIMapWindowMapY), ImVec2(g_GUIMapWindowMapMaxX, g_GUIMapWindowMapMaxY), ImColor(1.0f, 1.0f, 1.0f, 1.0f));
}
