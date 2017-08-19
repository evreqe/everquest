#pragma once

EQApp::GUIButton g_ESPMenuGUIButton;

EQApp::GUIMenu g_ESPMenuGUIMenu;

void EQAPP_ESPMenu_Toggle();
void EQAPP_ESPMenu_Load();
void EQAPP_ESPMenu_CreateButton();
void EQAPP_ESPMenu_CreateMenu();

void EQAPP_ESPMenu_Toggle()
{
    g_ESPMenuGUIMenu.ToggleOpen();
}

void EQAPP_ESPMenu_Load()
{
    EQAPP_ESPMenu_CreateButton();
    EQAPP_ESPMenu_CreateMenu();
}

void EQAPP_ESPMenu_CreateButton()
{
    g_ESPMenuGUIButton.SetX(600);
    g_ESPMenuGUIButton.SetY(6);

    g_ESPMenuGUIButton.SetWidth(64);
    g_ESPMenuGUIButton.SetHeight(32);

    g_ESPMenuGUIButton.SetText("ESP");
    g_ESPMenuGUIButton.FitToText();

    g_ESPMenuGUIButton.SetFunctionLeftClick(&EQAPP_ESPMenu_Toggle);

    g_GUIButtonList.push_back(&g_ESPMenuGUIButton);
}

void EQAPP_ESPMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemSeparator;
    g_ESPMenuGUIMenuItemSeparator.SetText("--------------------");
    g_ESPMenuGUIMenuItemSeparator.FitToText();
    g_ESPMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemSpawns;
    g_ESPMenuGUIMenuItemSpawns.SetText("Spawns");
    g_ESPMenuGUIMenuItemSpawns.FitToText();
    g_ESPMenuGUIMenuItemSpawns.SetFunctionLeftClick(&EQAPP_ESP_Spawns_Toggle);
    g_ESPMenuGUIMenuItemSpawns.SetBoolPointer(g_ESPSpawnsIsEnabled);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemGroundSpawns;
    g_ESPMenuGUIMenuItemGroundSpawns.SetText("Ground Spawns");
    g_ESPMenuGUIMenuItemGroundSpawns.FitToText();
    g_ESPMenuGUIMenuItemGroundSpawns.SetFunctionLeftClick(&EQAPP_ESP_GroundSpawns_Toggle);
    g_ESPMenuGUIMenuItemGroundSpawns.SetBoolPointer(g_ESPGroundSpawnsIsEnabled);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemDoorSpawns;
    g_ESPMenuGUIMenuItemDoorSpawns.SetText("Door Spawns");
    g_ESPMenuGUIMenuItemDoorSpawns.FitToText();
    g_ESPMenuGUIMenuItemDoorSpawns.SetFunctionLeftClick(&EQAPP_ESP_DoorSpawns_Toggle);
    g_ESPMenuGUIMenuItemDoorSpawns.SetBoolPointer(g_ESPDoorSpawnsIsEnabled);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemActors;
    g_ESPMenuGUIMenuItemActors.SetText("Actors");
    g_ESPMenuGUIMenuItemActors.FitToText();
    g_ESPMenuGUIMenuItemActors.SetFunctionLeftClick(&EQAPP_ESP_Actors_Toggle);
    g_ESPMenuGUIMenuItemActors.SetBoolPointer(g_ESPActorsIsEnabled);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemSpawnSkeletons;
    g_ESPMenuGUIMenuItemSpawnSkeletons.SetText("Spawn Skeletons");
    g_ESPMenuGUIMenuItemSpawnSkeletons.FitToText();
    g_ESPMenuGUIMenuItemSpawnSkeletons.SetFunctionLeftClick(&EQAPP_ESP_SpawnSkeletons_Toggle);
    g_ESPMenuGUIMenuItemSpawnSkeletons.SetBoolPointer(g_ESPSpawnSkeletonsIsEnabled);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemShowSpawnID;
    g_ESPMenuGUIMenuItemShowSpawnID.SetText("Show Spawn ID");
    g_ESPMenuGUIMenuItemShowSpawnID.FitToText();
    g_ESPMenuGUIMenuItemShowSpawnID.SetFunctionLeftClick(&EQAPP_ESP_ShowSpawnID_Toggle);
    g_ESPMenuGUIMenuItemShowSpawnID.SetBoolPointer(g_ESPShowSpawnID);

    EQApp::GUIMenuItem g_ESPMenuGUIMenuItemShowSpawnWeapon;
    g_ESPMenuGUIMenuItemShowSpawnWeapon.SetText("Show Spawn Weapon");
    g_ESPMenuGUIMenuItemShowSpawnWeapon.FitToText();
    g_ESPMenuGUIMenuItemShowSpawnWeapon.SetFunctionLeftClick(&EQAPP_ESP_ShowSpawnWeapon_Toggle);
    g_ESPMenuGUIMenuItemShowSpawnWeapon.SetBoolPointer(g_ESPShowSpawnWeapon);

    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemSpawns);
    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemGroundSpawns);
    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemDoorSpawns);

    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemSeparator);

    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemActors);
    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemSpawnSkeletons);

    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemSeparator);

    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemShowSpawnID);
    g_ESPMenuGUIMenu.AddMenuItem(g_ESPMenuGUIMenuItemShowSpawnWeapon);

    g_ESPMenuGUIMenu.SetX(g_ESPMenuGUIButton.GetX());
    g_ESPMenuGUIMenu.SetY(g_ESPMenuGUIButton.GetY() + g_ESPMenuGUIButton.GetHeight() + 8);

    g_ESPMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_ESPMenuGUIMenu);
}
