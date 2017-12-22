#pragma once

EQApp::GUIButton g_MapMenuGUIButton;

EQApp::GUIMenu g_MapMenuGUIMenu;

void EQAPP_MapMenu_Toggle();
void EQAPP_MapMenu_Load();
void EQAPP_MapMenu_CreateButton();
void EQAPP_MapMenu_CreateMenu();

void EQAPP_MapMenu_Toggle()
{
    g_MapMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_MapMenuGUIMenu);
}

void EQAPP_MapMenu_Load()
{
    EQAPP_MapMenu_CreateButton();
    EQAPP_MapMenu_CreateMenu();
}

void EQAPP_MapMenu_CreateButton()
{
    g_MapMenuGUIButton.SetX(500);
    g_MapMenuGUIButton.SetY(6);

    g_MapMenuGUIButton.SetWidth(64);
    g_MapMenuGUIButton.SetHeight(32);

    g_MapMenuGUIButton.SetText("MAP");
    g_MapMenuGUIButton.FitToText();

    g_MapMenuGUIButton.SetFunctionLeftClick(&EQAPP_MapMenu_Toggle);

    g_GUIButtonList.push_back(&g_MapMenuGUIButton);
}

void EQAPP_MapMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_MapMenuGUIMenuItemToggle;
    g_MapMenuGUIMenuItemToggle.SetText("Toggle");
    g_MapMenuGUIMenuItemToggle.FitToText();
    g_MapMenuGUIMenuItemToggle.SetFunctionLeftClick(&EQAPP_Map_Toggle);
    g_MapMenuGUIMenuItemToggle.SetBoolPointer(g_MapIsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemSeparator;
    g_MapMenuGUIMenuItemSeparator.SetText("--------------------");
    g_MapMenuGUIMenuItemSeparator.FitToText();
    g_MapMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLines;
    g_MapMenuGUIMenuItemLines.SetText("Lines");
    g_MapMenuGUIMenuItemLines.FitToText();
    g_MapMenuGUIMenuItemLines.SetFunctionLeftClick(&EQAPP_Map_Lines_Toggle);
    g_MapMenuGUIMenuItemLines.SetBoolPointer(g_MapLinesIsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLabels;
    g_MapMenuGUIMenuItemLabels.SetText("Labels");
    g_MapMenuGUIMenuItemLabels.FitToText();
    g_MapMenuGUIMenuItemLabels.SetFunctionLeftClick(&EQAPP_Map_Labels_Toggle);
    g_MapMenuGUIMenuItemLabels.SetBoolPointer(g_MapLabelsIsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemSpawns;
    g_MapMenuGUIMenuItemSpawns.SetText("Spawns");
    g_MapMenuGUIMenuItemSpawns.FitToText();
    g_MapMenuGUIMenuItemSpawns.SetFunctionLeftClick(&EQAPP_Map_Spawns_Toggle);
    g_MapMenuGUIMenuItemSpawns.SetBoolPointer(g_MapSpawnsIsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLayer0;
    g_MapMenuGUIMenuItemLayer0.SetText("Base Layer");
    g_MapMenuGUIMenuItemLayer0.FitToText();
    g_MapMenuGUIMenuItemLayer0.SetFunctionLeftClick(&EQAPP_Map_Layer0_Toggle);
    g_MapMenuGUIMenuItemLayer0.SetBoolPointer(g_MapLayer0IsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLayer1;
    g_MapMenuGUIMenuItemLayer1.SetText("Layer 1");
    g_MapMenuGUIMenuItemLayer1.FitToText();
    g_MapMenuGUIMenuItemLayer1.SetFunctionLeftClick(&EQAPP_Map_Layer1_Toggle);
    g_MapMenuGUIMenuItemLayer1.SetBoolPointer(g_MapLayer1IsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLayer2;
    g_MapMenuGUIMenuItemLayer2.SetText("Layer 2");
    g_MapMenuGUIMenuItemLayer2.FitToText();
    g_MapMenuGUIMenuItemLayer2.SetFunctionLeftClick(&EQAPP_Map_Layer2_Toggle);
    g_MapMenuGUIMenuItemLayer2.SetBoolPointer(g_MapLayer2IsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemLayer3;
    g_MapMenuGUIMenuItemLayer3.SetText("Layer 3");
    g_MapMenuGUIMenuItemLayer3.FitToText();
    g_MapMenuGUIMenuItemLayer3.SetFunctionLeftClick(&EQAPP_Map_Layer3_Toggle);
    g_MapMenuGUIMenuItemLayer3.SetBoolPointer(g_MapLayer3IsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemHeightFilter;
    g_MapMenuGUIMenuItemHeightFilter.SetText("Height Filter");
    g_MapMenuGUIMenuItemHeightFilter.FitToText();
    g_MapMenuGUIMenuItemHeightFilter.SetFunctionLeftClick(&EQAPP_Map_HeightFilter_Toggle);
    g_MapMenuGUIMenuItemHeightFilter.SetBoolPointer(g_MapHeightFilterIsEnabled);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemCenter;
    g_MapMenuGUIMenuItemCenter.SetText("Center");
    g_MapMenuGUIMenuItemCenter.FitToText();
    g_MapMenuGUIMenuItemCenter.SetFunctionLeftClick(&EQAPP_Map_Center);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemResetZoom;
    g_MapMenuGUIMenuItemResetZoom.SetText("Reset Zoom");
    g_MapMenuGUIMenuItemResetZoom.FitToText();
    g_MapMenuGUIMenuItemResetZoom.SetFunctionLeftClick(&EQAPP_Map_ResetZoom);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemZoomIn;
    g_MapMenuGUIMenuItemZoomIn.SetText("Zoom In");
    g_MapMenuGUIMenuItemZoomIn.FitToText();
    g_MapMenuGUIMenuItemZoomIn.SetFunctionLeftClick(&EQAPP_Map_ZoomIn);

    EQApp::GUIMenuItem g_MapMenuGUIMenuItemZoomOut;
    g_MapMenuGUIMenuItemZoomOut.SetText("Zoom Out");
    g_MapMenuGUIMenuItemZoomOut.FitToText();
    g_MapMenuGUIMenuItemZoomOut.SetFunctionLeftClick(&EQAPP_Map_ZoomOut);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemToggle);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemSeparator);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLines);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLabels);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemSpawns);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemSeparator);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLayer0);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLayer1);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLayer2);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemLayer3);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemSeparator);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemHeightFilter);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemSeparator);

    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemCenter);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemResetZoom);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemZoomIn);
    g_MapMenuGUIMenu.AddMenuItem(g_MapMenuGUIMenuItemZoomOut);

    g_MapMenuGUIMenu.SetX(g_MapMenuGUIButton.GetX());
    g_MapMenuGUIMenu.SetY(g_MapMenuGUIButton.GetY() + g_MapMenuGUIButton.GetHeight() + 8);

    g_MapMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_MapMenuGUIMenu);
}
