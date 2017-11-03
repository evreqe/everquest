#pragma once

EQApp::GUIButton g_mainMenuGUIButton;

EQApp::GUIMenu g_mainMenuGUIMenu;

void EQAPP_MainMenu_Toggle();
void EQAPP_MainMenu_Load();
void EQAPP_MainMenu_CreateButton();
void EQAPP_MainMenu_CreateMenu();

void EQAPP_MainMenu_Toggle()
{
    g_mainMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_mainMenuGUIMenu);
}

void EQAPP_MainMenu_Load()
{
    EQAPP_MainMenu_CreateButton();
    EQAPP_MainMenu_CreateMenu();
}

void EQAPP_MainMenu_CreateButton()
{
    g_mainMenuGUIButton.SetX(200);
    g_mainMenuGUIButton.SetY(6);

    g_mainMenuGUIButton.SetWidth(64);
    g_mainMenuGUIButton.SetHeight(32);

    g_mainMenuGUIButton.SetText("EQTAKP");
    g_mainMenuGUIButton.FitToText();

    g_mainMenuGUIButton.SetFunctionLeftClick(&EQAPP_MainMenu_Toggle);

    g_GUIButtonList.push_back(&g_mainMenuGUIButton);
}

void EQAPP_MainMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_mainMenuGUIMenuItemSeparator;
    g_mainMenuGUIMenuItemSeparator.SetText("--------------------");
    g_mainMenuGUIMenuItemSeparator.FitToText();
    g_mainMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemAlwaysAttack;
    g_mainMenuGUIMenuItemAlwaysAttack.SetText("Always Attack");
    g_mainMenuGUIMenuItemAlwaysAttack.FitToText();
    g_mainMenuGUIMenuItemAlwaysAttack.SetFunctionLeftClick(&EQAPP_AlwaysAttack_Toggle);
    g_mainMenuGUIMenuItemAlwaysAttack.SetBoolPointer(g_alwaysAttackIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemAutoGroup;
    g_mainMenuGUIMenuItemAutoGroup.SetText("Auto Group");
    g_mainMenuGUIMenuItemAutoGroup.FitToText();
    g_mainMenuGUIMenuItemAutoGroup.SetFunctionLeftClick(&EQAPP_AutoGroup_Toggle);
    g_mainMenuGUIMenuItemAutoGroup.SetBoolPointer(g_autoGroupIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemAutoLoot;
    g_mainMenuGUIMenuItemAutoLoot.SetText("Auto Loot");
    g_mainMenuGUIMenuItemAutoLoot.FitToText();
    g_mainMenuGUIMenuItemAutoLoot.SetFunctionLeftClick(&EQAPP_AutoLoot_Toggle);
    g_mainMenuGUIMenuItemAutoLoot.SetBoolPointer(g_autoLootIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemCollisionHack;
    g_mainMenuGUIMenuItemCollisionHack.SetText("Collision Hack");
    g_mainMenuGUIMenuItemCollisionHack.FitToText();
    g_mainMenuGUIMenuItemCollisionHack.SetFunctionLeftClick(&EQAPP_CollisionHack_Toggle);
    g_mainMenuGUIMenuItemCollisionHack.SetBoolPointer(g_collisionHackIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemESP;
    g_mainMenuGUIMenuItemESP.SetText("ESP");
    g_mainMenuGUIMenuItemESP.FitToText();
    g_mainMenuGUIMenuItemESP.SetFunctionLeftClick(&EQAPP_ESP_Toggle);
    g_mainMenuGUIMenuItemESP.SetBoolPointer(g_ESPIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemExtendedTargets;
    g_mainMenuGUIMenuItemExtendedTargets.SetText("Extended Targets");
    g_mainMenuGUIMenuItemExtendedTargets.FitToText();
    g_mainMenuGUIMenuItemExtendedTargets.SetFunctionLeftClick(&EQAPP_ExtendedTargets_Toggle);
    g_mainMenuGUIMenuItemExtendedTargets.SetBoolPointer(g_extendedTargetsIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemExtendedTargetsHeightFilter;
    g_mainMenuGUIMenuItemExtendedTargetsHeightFilter.SetText("ET Height Filter");
    g_mainMenuGUIMenuItemExtendedTargetsHeightFilter.FitToText();
    g_mainMenuGUIMenuItemExtendedTargetsHeightFilter.SetFunctionLeftClick(&EQAPP_ExtendedTargets_HeightFilter_Toggle);
    g_mainMenuGUIMenuItemExtendedTargetsHeightFilter.SetBoolPointer(g_extendedTargetsHeightFilterIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemFoodAndDrink;
    g_mainMenuGUIMenuItemFoodAndDrink.SetText("Food and Drink");
    g_mainMenuGUIMenuItemFoodAndDrink.FitToText();
    g_mainMenuGUIMenuItemFoodAndDrink.SetFunctionLeftClick(&EQAPP_FoodAndDrink_Toggle);
    g_mainMenuGUIMenuItemFoodAndDrink.SetBoolPointer(g_foodAndDrinkIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemFreeCamera;
    g_mainMenuGUIMenuItemFreeCamera.SetText("Free Camera");
    g_mainMenuGUIMenuItemFreeCamera.FitToText();
    g_mainMenuGUIMenuItemFreeCamera.SetFunctionLeftClick(&EQAPP_FreeCamera_Toggle);
    g_mainMenuGUIMenuItemFreeCamera.SetBoolPointer(g_freeCameraIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemHotButtonKeys;
    g_mainMenuGUIMenuItemHotButtonKeys.SetText("Hot Button Keys");
    g_mainMenuGUIMenuItemHotButtonKeys.FitToText();
    g_mainMenuGUIMenuItemHotButtonKeys.SetFunctionLeftClick(&EQAPP_HotButtonKeys_Toggle);
    g_mainMenuGUIMenuItemHotButtonKeys.SetBoolPointer(g_hotButtonKeysIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemLevelOfDetail;
    g_mainMenuGUIMenuItemLevelOfDetail.SetText("Level of Detail");
    g_mainMenuGUIMenuItemLevelOfDetail.FitToText();
    g_mainMenuGUIMenuItemLevelOfDetail.SetFunctionLeftClick(&EQAPP_LevelOfDetail_Toggle);
    g_mainMenuGUIMenuItemLevelOfDetail.SetBoolPointer(g_levelOfDetailIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemMap;
    g_mainMenuGUIMenuItemMap.SetText("Map");
    g_mainMenuGUIMenuItemMap.FitToText();
    g_mainMenuGUIMenuItemMap.SetFunctionLeftClick(&EQAPP_Map_Toggle);
    g_mainMenuGUIMenuItemMap.SetBoolPointer(g_mapIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemReplaceRaces;
    g_mainMenuGUIMenuItemReplaceRaces.SetText("Replace Races");
    g_mainMenuGUIMenuItemReplaceRaces.FitToText();
    g_mainMenuGUIMenuItemReplaceRaces.SetFunctionLeftClick(&EQAPP_ReplaceRaces_Toggle);
    g_mainMenuGUIMenuItemReplaceRaces.SetBoolPointer(g_replaceRacesIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemSpawnAlert;
    g_mainMenuGUIMenuItemSpawnAlert.SetText("Spawn Alert");
    g_mainMenuGUIMenuItemSpawnAlert.FitToText();
    g_mainMenuGUIMenuItemSpawnAlert.SetFunctionLeftClick(&EQAPP_SpawnAlert_Toggle);
    g_mainMenuGUIMenuItemSpawnAlert.SetBoolPointer(g_spawnAlertIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemSpeedHack;
    g_mainMenuGUIMenuItemSpeedHack.SetText("Speed Hack");
    g_mainMenuGUIMenuItemSpeedHack.FitToText();
    g_mainMenuGUIMenuItemSpeedHack.SetFunctionLeftClick(&EQAPP_SpeedHack_Toggle);
    g_mainMenuGUIMenuItemSpeedHack.SetBoolPointer(g_speedHackIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemTargetRing;
    g_mainMenuGUIMenuItemTargetRing.SetText("Target Ring");
    g_mainMenuGUIMenuItemTargetRing.FitToText();
    g_mainMenuGUIMenuItemTargetRing.SetFunctionLeftClick(&EQAPP_TargetRing_Toggle);
    g_mainMenuGUIMenuItemTargetRing.SetBoolPointer(g_targetRingIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemTrainSpells;
    g_mainMenuGUIMenuItemTrainSpells.SetText("Train Spells");
    g_mainMenuGUIMenuItemTrainSpells.FitToText();
    g_mainMenuGUIMenuItemTrainSpells.SetFunctionLeftClick(&EQAPP_TrainSpells_Toggle);
    g_mainMenuGUIMenuItemTrainSpells.SetBoolPointer(g_trainSpellsIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemUnload;
    g_mainMenuGUIMenuItemUnload.SetText("Unload");
    g_mainMenuGUIMenuItemUnload.FitToText();
    g_mainMenuGUIMenuItemUnload.SetFunctionLeftClick(&EQAPP_Unload);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAlwaysAttack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAutoGroup);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAutoLoot);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemCollisionHack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemESP);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemExtendedTargets);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemExtendedTargetsHeightFilter);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemFoodAndDrink);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemFreeCamera);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemHotButtonKeys);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemLevelOfDetail);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemMap);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemReplaceRaces);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSpawnAlert);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSpeedHack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemTargetRing);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemTrainSpells);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSeparator);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemUnload);

    g_mainMenuGUIMenu.SetX(g_mainMenuGUIButton.GetX());
    g_mainMenuGUIMenu.SetY(g_mainMenuGUIButton.GetY() + g_mainMenuGUIButton.GetHeight() + 8);

    g_mainMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_mainMenuGUIMenu);
}



