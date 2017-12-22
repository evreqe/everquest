#pragma once

EQApp::GUIButton g_MainMenuGUIButton;

EQApp::GUIMenu g_MainMenuGUIMenu;

void EQAPP_MainMenu_Toggle();
void EQAPP_MainMenu_Load();
void EQAPP_MainMenu_CreateButton();
void EQAPP_MainMenu_CreateMenu();

void EQAPP_MainMenu_Toggle()
{
    g_MainMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_MainMenuGUIMenu);
}

void EQAPP_MainMenu_Load()
{
    EQAPP_MainMenu_CreateButton();
    EQAPP_MainMenu_CreateMenu();
}

void EQAPP_MainMenu_CreateButton()
{
    g_MainMenuGUIButton.SetX(200);
    g_MainMenuGUIButton.SetY(6);

    g_MainMenuGUIButton.SetWidth(64);
    g_MainMenuGUIButton.SetHeight(32);

    g_MainMenuGUIButton.SetText("EQTAKP");
    g_MainMenuGUIButton.FitToText();

    g_MainMenuGUIButton.SetFunctionLeftClick(&EQAPP_MainMenu_Toggle);

    g_GUIButtonList.push_back(&g_MainMenuGUIButton);
}

void EQAPP_MainMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_MainMenuGUIMenuItemSeparator;
    g_MainMenuGUIMenuItemSeparator.SetText("--------------------");
    g_MainMenuGUIMenuItemSeparator.FitToText();
    g_MainMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemAlwaysAttack;
    g_MainMenuGUIMenuItemAlwaysAttack.SetText("Always Attack");
    g_MainMenuGUIMenuItemAlwaysAttack.FitToText();
    g_MainMenuGUIMenuItemAlwaysAttack.SetFunctionLeftClick(&EQAPP_AlwaysAttack_Toggle);
    g_MainMenuGUIMenuItemAlwaysAttack.SetBoolPointer(g_AlwaysAttackIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemAutoGroup;
    g_MainMenuGUIMenuItemAutoGroup.SetText("Auto Group");
    g_MainMenuGUIMenuItemAutoGroup.FitToText();
    g_MainMenuGUIMenuItemAutoGroup.SetFunctionLeftClick(&EQAPP_AutoGroup_Toggle);
    g_MainMenuGUIMenuItemAutoGroup.SetBoolPointer(g_AutoGroupIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemAutoLoot;
    g_MainMenuGUIMenuItemAutoLoot.SetText("Auto Loot");
    g_MainMenuGUIMenuItemAutoLoot.FitToText();
    g_MainMenuGUIMenuItemAutoLoot.SetFunctionLeftClick(&EQAPP_AutoLoot_Toggle);
    g_MainMenuGUIMenuItemAutoLoot.SetBoolPointer(g_AutoLootIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemCollisionHack;
    g_MainMenuGUIMenuItemCollisionHack.SetText("Collision Hack");
    g_MainMenuGUIMenuItemCollisionHack.FitToText();
    g_MainMenuGUIMenuItemCollisionHack.SetFunctionLeftClick(&EQAPP_CollisionHack_Toggle);
    g_MainMenuGUIMenuItemCollisionHack.SetBoolPointer(g_CollisionHackIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemESP;
    g_MainMenuGUIMenuItemESP.SetText("ESP");
    g_MainMenuGUIMenuItemESP.FitToText();
    g_MainMenuGUIMenuItemESP.SetFunctionLeftClick(&EQAPP_ESP_Toggle);
    g_MainMenuGUIMenuItemESP.SetBoolPointer(g_ESPIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemExtendedTargets;
    g_MainMenuGUIMenuItemExtendedTargets.SetText("Extended Targets");
    g_MainMenuGUIMenuItemExtendedTargets.FitToText();
    g_MainMenuGUIMenuItemExtendedTargets.SetFunctionLeftClick(&EQAPP_ExtendedTargets_Toggle);
    g_MainMenuGUIMenuItemExtendedTargets.SetBoolPointer(g_ExtendedTargetsIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemExtendedTargetsHeightFilter;
    g_MainMenuGUIMenuItemExtendedTargetsHeightFilter.SetText("ET Height Filter");
    g_MainMenuGUIMenuItemExtendedTargetsHeightFilter.FitToText();
    g_MainMenuGUIMenuItemExtendedTargetsHeightFilter.SetFunctionLeftClick(&EQAPP_ExtendedTargets_HeightFilter_Toggle);
    g_MainMenuGUIMenuItemExtendedTargetsHeightFilter.SetBoolPointer(g_ExtendedTargetsHeightFilterIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemFoodAndDrink;
    g_MainMenuGUIMenuItemFoodAndDrink.SetText("Food and Drink");
    g_MainMenuGUIMenuItemFoodAndDrink.FitToText();
    g_MainMenuGUIMenuItemFoodAndDrink.SetFunctionLeftClick(&EQAPP_FoodAndDrink_Toggle);
    g_MainMenuGUIMenuItemFoodAndDrink.SetBoolPointer(g_FoodAndDrinkIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemFreeCamera;
    g_MainMenuGUIMenuItemFreeCamera.SetText("Free Camera");
    g_MainMenuGUIMenuItemFreeCamera.FitToText();
    g_MainMenuGUIMenuItemFreeCamera.SetFunctionLeftClick(&EQAPP_FreeCamera_Toggle);
    g_MainMenuGUIMenuItemFreeCamera.SetBoolPointer(g_FreeCameraIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemHotButtonKeys;
    g_MainMenuGUIMenuItemHotButtonKeys.SetText("Hot Button Keys");
    g_MainMenuGUIMenuItemHotButtonKeys.FitToText();
    g_MainMenuGUIMenuItemHotButtonKeys.SetFunctionLeftClick(&EQAPP_HotButtonKeys_Toggle);
    g_MainMenuGUIMenuItemHotButtonKeys.SetBoolPointer(g_HotButtonKeysIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemLevelOfDetail;
    g_MainMenuGUIMenuItemLevelOfDetail.SetText("Level of Detail");
    g_MainMenuGUIMenuItemLevelOfDetail.FitToText();
    g_MainMenuGUIMenuItemLevelOfDetail.SetFunctionLeftClick(&EQAPP_LevelOfDetail_Toggle);
    g_MainMenuGUIMenuItemLevelOfDetail.SetBoolPointer(g_LevelOfDetailIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemMap;
    g_MainMenuGUIMenuItemMap.SetText("Map");
    g_MainMenuGUIMenuItemMap.FitToText();
    g_MainMenuGUIMenuItemMap.SetFunctionLeftClick(&EQAPP_Map_Toggle);
    g_MainMenuGUIMenuItemMap.SetBoolPointer(g_MapIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemReplaceRaces;
    g_MainMenuGUIMenuItemReplaceRaces.SetText("Replace Races");
    g_MainMenuGUIMenuItemReplaceRaces.FitToText();
    g_MainMenuGUIMenuItemReplaceRaces.SetFunctionLeftClick(&EQAPP_ReplaceRaces_Toggle);
    g_MainMenuGUIMenuItemReplaceRaces.SetBoolPointer(g_ReplaceRacesIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemSpawnAlert;
    g_MainMenuGUIMenuItemSpawnAlert.SetText("Spawn Alert");
    g_MainMenuGUIMenuItemSpawnAlert.FitToText();
    g_MainMenuGUIMenuItemSpawnAlert.SetFunctionLeftClick(&EQAPP_SpawnAlert_Toggle);
    g_MainMenuGUIMenuItemSpawnAlert.SetBoolPointer(g_SpawnAlertIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemSpeedHack;
    g_MainMenuGUIMenuItemSpeedHack.SetText("Speed Hack");
    g_MainMenuGUIMenuItemSpeedHack.FitToText();
    g_MainMenuGUIMenuItemSpeedHack.SetFunctionLeftClick(&EQAPP_SpeedHack_Toggle);
    g_MainMenuGUIMenuItemSpeedHack.SetBoolPointer(g_SpeedHackIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemTargetRing;
    g_MainMenuGUIMenuItemTargetRing.SetText("Target Ring");
    g_MainMenuGUIMenuItemTargetRing.FitToText();
    g_MainMenuGUIMenuItemTargetRing.SetFunctionLeftClick(&EQAPP_TargetRing_Toggle);
    g_MainMenuGUIMenuItemTargetRing.SetBoolPointer(g_TargetRingIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemTrainSpells;
    g_MainMenuGUIMenuItemTrainSpells.SetText("Train Spells");
    g_MainMenuGUIMenuItemTrainSpells.FitToText();
    g_MainMenuGUIMenuItemTrainSpells.SetFunctionLeftClick(&EQAPP_TrainSpells_Toggle);
    g_MainMenuGUIMenuItemTrainSpells.SetBoolPointer(g_TrainSpellsIsEnabled);

    EQApp::GUIMenuItem g_MainMenuGUIMenuItemUnload;
    g_MainMenuGUIMenuItemUnload.SetText("Unload");
    g_MainMenuGUIMenuItemUnload.FitToText();
    g_MainMenuGUIMenuItemUnload.SetFunctionLeftClick(&EQAPP_Unload);

    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemAlwaysAttack);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemAutoGroup);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemAutoLoot);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemCollisionHack);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemESP);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemExtendedTargets);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemExtendedTargetsHeightFilter);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemFoodAndDrink);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemFreeCamera);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemHotButtonKeys);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemLevelOfDetail);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemMap);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemReplaceRaces);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemSpawnAlert);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemSpeedHack);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemTargetRing);
    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemTrainSpells);

    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemSeparator);

    g_MainMenuGUIMenu.AddMenuItem(g_MainMenuGUIMenuItemUnload);

    g_MainMenuGUIMenu.SetX(g_MainMenuGUIButton.GetX());
    g_MainMenuGUIMenu.SetY(g_MainMenuGUIButton.GetY() + g_MainMenuGUIButton.GetHeight() + 8);

    g_MainMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_MainMenuGUIMenu);
}



