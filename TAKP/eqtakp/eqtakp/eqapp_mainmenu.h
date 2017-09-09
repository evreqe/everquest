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

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemTrainSpells;
    g_mainMenuGUIMenuItemTrainSpells.SetText("Train Spells");
    g_mainMenuGUIMenuItemTrainSpells.FitToText();
    g_mainMenuGUIMenuItemTrainSpells.SetFunctionLeftClick(&EQAPP_TrainSpells_Toggle);
    g_mainMenuGUIMenuItemTrainSpells.SetBoolPointer(g_trainSpellsIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemPrintBankInventory;
    g_mainMenuGUIMenuItemPrintBankInventory.SetText("Print Bank Inventory");
    g_mainMenuGUIMenuItemPrintBankInventory.FitToText();
    g_mainMenuGUIMenuItemPrintBankInventory.SetFunctionLeftClick(&EQAPP_PrintBankInventory);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemWriteInventoryToFile;
    g_mainMenuGUIMenuItemWriteInventoryToFile.SetText("Write Inventory to File");
    g_mainMenuGUIMenuItemWriteInventoryToFile.FitToText();
    g_mainMenuGUIMenuItemWriteInventoryToFile.SetFunctionLeftClick(&EQAPP_WriteInventoryToFile);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemLoadSpellSet;
    g_mainMenuGUIMenuItemLoadSpellSet.SetText("Load Default Spellset");
    g_mainMenuGUIMenuItemLoadSpellSet.FitToText();
    g_mainMenuGUIMenuItemLoadSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_Load_Default);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemSaveSpellSet;
    g_mainMenuGUIMenuItemSaveSpellSet.SetText("Save Default Spellset");
    g_mainMenuGUIMenuItemSaveSpellSet.FitToText();
    g_mainMenuGUIMenuItemSaveSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_Save_Default);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemUnload;
    g_mainMenuGUIMenuItemUnload.SetText("Unload");
    g_mainMenuGUIMenuItemUnload.FitToText();
    g_mainMenuGUIMenuItemUnload.SetFunctionLeftClick(&EQAPP_Unload);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAlwaysAttack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAutoLoot);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemCollisionHack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemESP);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemExtendedTargets);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemFoodAndDrink);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemFreeCamera);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemMap);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemReplaceRaces);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSpawnAlert);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSpeedHack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemTrainSpells);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSeparator);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemPrintBankInventory);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemWriteInventoryToFile);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSeparator);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemLoadSpellSet);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSaveSpellSet);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemSeparator);

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemUnload);

    g_mainMenuGUIMenu.SetX(g_mainMenuGUIButton.GetX());
    g_mainMenuGUIMenu.SetY(g_mainMenuGUIButton.GetY() + g_mainMenuGUIButton.GetHeight() + 8);

    g_mainMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_mainMenuGUIMenu);
}



