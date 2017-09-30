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

    EQApp::GUIMenuItem g_mapMenuGUIMenuItemHeightFilter;
    g_mapMenuGUIMenuItemHeightFilter.SetText("Height Filter");
    g_mapMenuGUIMenuItemHeightFilter.FitToText();
    g_mapMenuGUIMenuItemHeightFilter.SetFunctionLeftClick(&EQAPP_Map_HeightFilter_Toggle);
    g_mapMenuGUIMenuItemHeightFilter.SetBoolPointer(g_mapHeightFilterIsEnabled);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemToggle);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLines);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemLabels);
    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSpawns);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemSeparator);

    g_mapMenuGUIMenu.AddMenuItem(g_mapMenuGUIMenuItemHeightFilter);

    g_mapMenuGUIMenu.SetX(g_mapMenuGUIButton.GetX());
    g_mapMenuGUIMenu.SetY(g_mapMenuGUIButton.GetY() + g_mapMenuGUIButton.GetHeight() + 8);

    g_mapMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_mapMenuGUIMenu);
}
