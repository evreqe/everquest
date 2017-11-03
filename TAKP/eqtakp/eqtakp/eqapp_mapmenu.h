#pragma once

EQApp::GUIButton g_mapMenuGUIButton;

EQApp::GUIMenu g_mapMenuGUIMenu;

void EQAPP_MapMenu_Toggle();
void EQAPP_MapMenu_Load();
void EQAPP_MapMenu_CreateButton();
void EQAPP_MapMenu_CreateMenu();

void EQAPP_MapMenu_Toggle()
{
    g_mapMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_mapMenuGUIMenu);
}

void EQAPP_MapMenu_Load()
{
    EQAPP_MapMenu_CreateButton();
    EQAPP_MapMenu_CreateMenu();
}

void EQAPP_MapMenu_CreateButton()
{
    g_mapMenuGUIButton.SetX(500);
    g_mapMenuGUIButton.SetY(6);

    g_mapMenuGUIButton.SetWidth(64);
    g_mapMenuGUIButton.SetHeight(32);

    g_mapMenuGUIButton.SetText("MAP");
    g_mapMenuGUIButton.FitToText();

    g_mapMenuGUIButton.SetFunctionLeftClick(&EQAPP_MapMenu_Toggle);

    g_GUIButtonList.push_back(&g_mapMenuGUIButton);
}

void EQAPP_MapMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_mapMenuGUIMenuItemToggle;
    g_mapMenuGUIMenuItemToggle.SetText("Toggle");
    g_mapMenuGUIMenuItemToggle.FitToText();
    g_mapMenuGUIMenuItemToggle.SetFunctionLeftClick(&EQAPP_Map_Toggle);
    g_mapMenuGUIMenuItemToggle.SetBoolPointer(g_mapIsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemSeparator;
    g_mapMenuGUIMenuItemSeparator.SetText("--------------------");
    g_mapMenuGUIMenuItemSeparator.FitToText();
    g_mapMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLines;
    g_mapMenuGUIMenuItemLines.SetText("Lines");
    g_mapMenuGUIMenuItemLines.FitToText();
    g_mapMenuGUIMenuItemLines.SetFunctionLeftClick(&EQAPP_Map_Lines_Toggle);
    g_mapMenuGUIMenuItemLines.SetBoolPointer(g_mapLinesIsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLabels;
    g_mapMenuGUIMenuItemLabels.SetText("Labels");
    g_mapMenuGUIMenuItemLabels.FitToText();
    g_mapMenuGUIMenuItemLabels.SetFunctionLeftClick(&EQAPP_Map_Labels_Toggle);
    g_mapMenuGUIMenuItemLabels.SetBoolPointer(g_mapLabelsIsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemSpawns;
    g_mapMenuGUIMenuItemSpawns.SetText("Spawns");
    g_mapMenuGUIMenuItemSpawns.FitToText();
    g_mapMenuGUIMenuItemSpawns.SetFunctionLeftClick(&EQAPP_Map_Spawns_Toggle);
    g_mapMenuGUIMenuItemSpawns.SetBoolPointer(g_mapSpawnsIsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLayer0;
    g_mapMenuGUIMenuItemLayer0.SetText("Base Layer");
    g_mapMenuGUIMenuItemLayer0.FitToText();
    g_mapMenuGUIMenuItemLayer0.SetFunctionLeftClick(&EQAPP_Map_Layer0_Toggle);
    g_mapMenuGUIMenuItemLayer0.SetBoolPointer(g_mapLayer0IsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLayer1;
    g_mapMenuGUIMenuItemLayer1.SetText("Layer 1");
    g_mapMenuGUIMenuItemLayer1.FitToText();
    g_mapMenuGUIMenuItemLayer1.SetFunctionLeftClick(&EQAPP_Map_Layer1_Toggle);
    g_mapMenuGUIMenuItemLayer1.SetBoolPointer(g_mapLayer1IsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLayer2;
    g_mapMenuGUIMenuItemLayer2.SetText("Layer 2");
    g_mapMenuGUIMenuItemLayer2.FitToText();
    g_mapMenuGUIMenuItemLayer2.SetFunctionLeftClick(&EQAPP_Map_Layer2_Toggle);
    g_mapMenuGUIMenuItemLayer2.SetBoolPointer(g_mapLayer2IsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemLayer3;
    g_mapMenuGUIMenuItemLayer3.SetText("Layer 3");
    g_mapMenuGUIMenuItemLayer3.FitToText();
    g_mapMenuGUIMenuItemLayer3.SetFunctionLeftClick(&EQAPP_Map_Layer3_Toggle);
    g_mapMenuGUIMenuItemLayer3.SetBoolPointer(g_mapLayer3IsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemHeightFilter;
    g_mapMenuGUIMenuItemHeightFilter.SetText("Height Filter");
    g_mapMenuGUIMenuItemHeightFilter.FitToText();
    g_mapMenuGUIMenuItemHeightFilter.SetFunctionLeftClick(&EQAPP_Map_HeightFilter_Toggle);
    g_mapMenuGUIMenuItemHeightFilter.SetBoolPointer(g_mapHeightFilterIsEnabled);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemCenter;
    g_mapMenuGUIMenuItemCenter.SetText("Center");
    g_mapMenuGUIMenuItemCenter.FitToText();
    g_mapMenuGUIMenuItemCenter.SetFunctionLeftClick(&EQAPP_Map_Center);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemResetZoom;
    g_mapMenuGUIMenuItemResetZoom.SetText("Reset Zoom");
    g_mapMenuGUIMenuItemResetZoom.FitToText();
    g_mapMenuGUIMenuItemResetZoom.SetFunctionLeftClick(&EQAPP_Map_ResetZoom);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemZoomIn;
    g_mapMenuGUIMenuItemZoomIn.SetText("Zoom In");
    g_mapMenuGUIMenuItemZoomIn.FitToText();
    g_mapMenuGUIMenuItemZoomIn.SetFunctionLeftClick(&EQAPP_Map_ZoomIn);

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemZoomOut;
    g_mapMenuGUIMenuItemZoomOut.SetText("Zoom Out");
    g_mapMenuGUIMenuItemZoomOut.FitToText();
    g_mapMenuGUIMenuItemZoomOut.SetFunctionLeftClick(&EQAPP_Map_ZoomOut);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemToggle);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLines);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLabels);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSpawns);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLayer0);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLayer1);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLayer2);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLayer3);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemHeightFilter);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemCenter);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemResetZoom);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemZoomIn);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemZoomOut);

    g_mapMenuGUIMenu.SetX(g_mapMenuGUIButton.GetX());
    g_mapMenuGUIMenu.SetY(g_mapMenuGUIButton.GetY() + g_mapMenuGUIButton.GetHeight() + 8);

    g_mapMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_mapMenuGUIMenu);
}
