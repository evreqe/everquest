#pragma once

EQApp::GUIButton g_OtherMenuGUIButton;

EQApp::GUIMenu g_OtherMenuGUIMenu;

void EQAPP_OtherMenu_Toggle();
void EQAPP_OtherMenu_Load();
void EQAPP_OtherMenu_CreateButton();
void EQAPP_OtherMenu_CreateMenu();

void EQAPP_OtherMenu_Toggle()
{
    g_OtherMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_OtherMenuGUIMenu);
}

void EQAPP_OtherMenu_Load()
{
    EQAPP_OtherMenu_CreateButton();
    EQAPP_OtherMenu_CreateMenu();
}

void EQAPP_OtherMenu_CreateButton()
{
    g_OtherMenuGUIButton.SetX(700);
    g_OtherMenuGUIButton.SetY(6);

    g_OtherMenuGUIButton.SetWidth(64);
    g_OtherMenuGUIButton.SetHeight(32);

    g_OtherMenuGUIButton.SetText("OTHER");
    g_OtherMenuGUIButton.FitToText();

    g_OtherMenuGUIButton.SetFunctionLeftClick(&EQAPP_OtherMenu_Toggle);

    g_GUIButtonList.push_back(&g_OtherMenuGUIButton);
}

void EQAPP_OtherMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemSeparator;
    g_OtherMenuGUIMenuItemSeparator.SetText("--------------------");
    g_OtherMenuGUIMenuItemSeparator.FitToText();
    g_OtherMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemWallHack;
    g_OtherMenuGUIMenuItemWallHack.SetText("Wall Hack");
    g_OtherMenuGUIMenuItemWallHack.FitToText();
    g_OtherMenuGUIMenuItemWallHack.SetFunctionLeftClick(&EQAPP_WallHack_Toggle);
    g_OtherMenuGUIMenuItemWallHack.SetBoolPointer(g_WallHackIsEnabled);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemWaterHack;
    g_OtherMenuGUIMenuItemWaterHack.SetText("Water Hack");
    g_OtherMenuGUIMenuItemWaterHack.FitToText();
    g_OtherMenuGUIMenuItemWaterHack.SetFunctionLeftClick(&EQAPP_WaterHack_Toggle);
    g_OtherMenuGUIMenuItemWaterHack.SetBoolPointer(g_WaterHackIsEnabled);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemTreeHack;
    g_OtherMenuGUIMenuItemTreeHack.SetText("Tree Hack");
    g_OtherMenuGUIMenuItemTreeHack.FitToText();
    g_OtherMenuGUIMenuItemTreeHack.SetFunctionLeftClick(&EQAPP_TreeHack_Toggle);
    g_OtherMenuGUIMenuItemTreeHack.SetBoolPointer(g_TreeHackIsEnabled);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemDestroyActors;
    g_OtherMenuGUIMenuItemDestroyActors.SetText("Destroy Actors");
    g_OtherMenuGUIMenuItemDestroyActors.FitToText();
    g_OtherMenuGUIMenuItemDestroyActors.SetFunctionLeftClick(&EQAPP_DestroyActors_Toggle);
    g_OtherMenuGUIMenuItemDestroyActors.SetBoolPointer(g_DestroyActorsIsEnabled);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog;
    g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetText("Destroy Actors CreateActorEx Log");
    g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog.FitToText();
    g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetFunctionLeftClick(&EQAPP_DestroyActors_CreateActorExLog_Toggle);
    g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetBoolPointer(g_DestroyActorsCreateActorExLogIsEnabled);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemPrintBankInventory;
    g_OtherMenuGUIMenuItemPrintBankInventory.SetText("Print Bank Inventory");
    g_OtherMenuGUIMenuItemPrintBankInventory.FitToText();
    g_OtherMenuGUIMenuItemPrintBankInventory.SetFunctionLeftClick(&EQAPP_PrintBankInventory);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemWriteInventoryToFile;
    g_OtherMenuGUIMenuItemWriteInventoryToFile.SetText("Write Inventory to File");
    g_OtherMenuGUIMenuItemWriteInventoryToFile.FitToText();
    g_OtherMenuGUIMenuItemWriteInventoryToFile.SetFunctionLeftClick(&EQAPP_WriteInventoryToFile);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadSpellSet;
    g_OtherMenuGUIMenuItemLoadSpellSet.SetText("Load Default Spellset");
    g_OtherMenuGUIMenuItemLoadSpellSet.FitToText();
    g_OtherMenuGUIMenuItemLoadSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_LoadAndStartMemorizing);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemSaveSpellSet;
    g_OtherMenuGUIMenuItemSaveSpellSet.SetText("Save Default Spellset");
    g_OtherMenuGUIMenuItemSaveSpellSet.FitToText();
    g_OtherMenuGUIMenuItemSaveSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_Save_Default);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadAutoLoot;
    g_OtherMenuGUIMenuItemLoadAutoLoot.SetText("Load Auto Loot");
    g_OtherMenuGUIMenuItemLoadAutoLoot.FitToText();
    g_OtherMenuGUIMenuItemLoadAutoLoot.SetFunctionLeftClick(&EQAPP_AutoLoot_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadMap;
    g_OtherMenuGUIMenuItemLoadMap.SetText("Load Map");
    g_OtherMenuGUIMenuItemLoadMap.FitToText();
    g_OtherMenuGUIMenuItemLoadMap.SetFunctionLeftClick(&EQAPP_Map_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadNamedSpawns;
    g_OtherMenuGUIMenuItemLoadNamedSpawns.SetText("Load Named Spawns");
    g_OtherMenuGUIMenuItemLoadNamedSpawns.FitToText();
    g_OtherMenuGUIMenuItemLoadNamedSpawns.SetFunctionLeftClick(&EQAPP_NamedSpawns_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadBazaarSearchItemNames;
    g_OtherMenuGUIMenuItemLoadBazaarSearchItemNames.SetText("Load Bazaar Search Item Names");
    g_OtherMenuGUIMenuItemLoadBazaarSearchItemNames.FitToText();
    g_OtherMenuGUIMenuItemLoadBazaarSearchItemNames.SetFunctionLeftClick(&EQAPP_BazaarSearchWindow_LoadItemNames);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadDestroyActors;
    g_OtherMenuGUIMenuItemLoadDestroyActors.SetText("Load Destroy Actors");
    g_OtherMenuGUIMenuItemLoadDestroyActors.FitToText();
    g_OtherMenuGUIMenuItemLoadDestroyActors.SetFunctionLeftClick(&EQAPP_DestroyActors_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadTreeHack;
    g_OtherMenuGUIMenuItemLoadTreeHack.SetText("Load Tree Hack");
    g_OtherMenuGUIMenuItemLoadTreeHack.FitToText();
    g_OtherMenuGUIMenuItemLoadTreeHack.SetFunctionLeftClick(&EQAPP_TreeHack_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemLoadWaterHack;
    g_OtherMenuGUIMenuItemLoadWaterHack.SetText("Load Water Hack");
    g_OtherMenuGUIMenuItemLoadWaterHack.FitToText();
    g_OtherMenuGUIMenuItemLoadWaterHack.SetFunctionLeftClick(&EQAPP_WaterHack_Load);

    EQApp::GUIMenuItem g_OtherMenuGUIMenuItemToggleShowFPS;
    g_OtherMenuGUIMenuItemToggleShowFPS.SetText("Toggle FPS Overlay");
    g_OtherMenuGUIMenuItemToggleShowFPS.FitToText();
    g_OtherMenuGUIMenuItemToggleShowFPS.SetFunctionLeftClick(&EQ_GraphicsDLL_ToggleShowFPS);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemWallHack);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemWaterHack);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemTreeHack);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSeparator);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemDestroyActors);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemDestroyActorsCreateActorExLog);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSeparator);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemPrintBankInventory);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemWriteInventoryToFile);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSeparator);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadSpellSet);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSaveSpellSet);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSeparator);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadAutoLoot);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadMap);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadNamedSpawns);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadBazaarSearchItemNames);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadDestroyActors);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadTreeHack);
    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemLoadWaterHack);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemSeparator);

    g_OtherMenuGUIMenu.AddMenuItem(g_OtherMenuGUIMenuItemToggleShowFPS);

    g_OtherMenuGUIMenu.SetX(g_OtherMenuGUIButton.GetX());
    g_OtherMenuGUIMenu.SetY(g_OtherMenuGUIButton.GetY() + g_OtherMenuGUIButton.GetHeight() + 8);

    g_OtherMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_OtherMenuGUIMenu);
}
