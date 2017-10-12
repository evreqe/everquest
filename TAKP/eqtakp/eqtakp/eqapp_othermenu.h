#pragma once

EQApp::GUIButton g_otherMenuGUIButton;

EQApp::GUIMenu g_otherMenuGUIMenu;

void EQAPP_OtherMenu_Toggle();
void EQAPP_OtherMenu_Load();
void EQAPP_OtherMenu_CreateButton();
void EQAPP_OtherMenu_CreateMenu();

void EQAPP_OtherMenu_Toggle()
{
    g_otherMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_otherMenuGUIMenu);
}

void EQAPP_OtherMenu_Load()
{
    EQAPP_OtherMenu_CreateButton();
    EQAPP_OtherMenu_CreateMenu();
}

void EQAPP_OtherMenu_CreateButton()
{
    g_otherMenuGUIButton.SetX(700);
    g_otherMenuGUIButton.SetY(6);

    g_otherMenuGUIButton.SetWidth(64);
    g_otherMenuGUIButton.SetHeight(32);

    g_otherMenuGUIButton.SetText("OTHER");
    g_otherMenuGUIButton.FitToText();

    g_otherMenuGUIButton.SetFunctionLeftClick(&EQAPP_OtherMenu_Toggle);

    g_GUIButtonList.push_back(&g_otherMenuGUIButton);
}

void EQAPP_OtherMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_otherMenuGUIMenuItemSeparator;
    g_otherMenuGUIMenuItemSeparator.SetText("--------------------");
    g_otherMenuGUIMenuItemSeparator.FitToText();
    g_otherMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemWallHack;
    g_otherMenuGUIMenuItemWallHack.SetText("Wall Hack");
    g_otherMenuGUIMenuItemWallHack.FitToText();
    g_otherMenuGUIMenuItemWallHack.SetFunctionLeftClick(&EQAPP_WallHack_Toggle);
    g_otherMenuGUIMenuItemWallHack.SetBoolPointer(g_wallHackIsEnabled);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemWaterHack;
    g_otherMenuGUIMenuItemWaterHack.SetText("Water Hack");
    g_otherMenuGUIMenuItemWaterHack.FitToText();
    g_otherMenuGUIMenuItemWaterHack.SetFunctionLeftClick(&EQAPP_WaterHack_Toggle);
    g_otherMenuGUIMenuItemWaterHack.SetBoolPointer(g_waterHackIsEnabled);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemTreeHack;
    g_otherMenuGUIMenuItemTreeHack.SetText("Tree Hack");
    g_otherMenuGUIMenuItemTreeHack.FitToText();
    g_otherMenuGUIMenuItemTreeHack.SetFunctionLeftClick(&EQAPP_TreeHack_Toggle);
    g_otherMenuGUIMenuItemTreeHack.SetBoolPointer(g_treeHackIsEnabled);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemDestroyActors;
    g_otherMenuGUIMenuItemDestroyActors.SetText("Destroy Actors");
    g_otherMenuGUIMenuItemDestroyActors.FitToText();
    g_otherMenuGUIMenuItemDestroyActors.SetFunctionLeftClick(&EQAPP_DestroyActors_Toggle);
    g_otherMenuGUIMenuItemDestroyActors.SetBoolPointer(g_destroyActorsIsEnabled);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog;
    g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetText("Destroy Actors CreateActorEx Log");
    g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog.FitToText();
    g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetFunctionLeftClick(&EQAPP_DestroyActors_CreateActorExLog_Toggle);
    g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog.SetBoolPointer(g_destroyActorsCreateActorExLogIsEnabled);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemPrintBankInventory;
    g_otherMenuGUIMenuItemPrintBankInventory.SetText("Print Bank Inventory");
    g_otherMenuGUIMenuItemPrintBankInventory.FitToText();
    g_otherMenuGUIMenuItemPrintBankInventory.SetFunctionLeftClick(&EQAPP_PrintBankInventory);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemWriteInventoryToFile;
    g_otherMenuGUIMenuItemWriteInventoryToFile.SetText("Write Inventory to File");
    g_otherMenuGUIMenuItemWriteInventoryToFile.FitToText();
    g_otherMenuGUIMenuItemWriteInventoryToFile.SetFunctionLeftClick(&EQAPP_WriteInventoryToFile);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadSpellSet;
    g_otherMenuGUIMenuItemLoadSpellSet.SetText("Load Default Spellset");
    g_otherMenuGUIMenuItemLoadSpellSet.FitToText();
    g_otherMenuGUIMenuItemLoadSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_LoadAndStartMemorizing);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemSaveSpellSet;
    g_otherMenuGUIMenuItemSaveSpellSet.SetText("Save Default Spellset");
    g_otherMenuGUIMenuItemSaveSpellSet.FitToText();
    g_otherMenuGUIMenuItemSaveSpellSet.SetFunctionLeftClick(&EQAPP_SpellSet_Save_Default);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadAutoLoot;
    g_otherMenuGUIMenuItemLoadAutoLoot.SetText("Load Auto Loot");
    g_otherMenuGUIMenuItemLoadAutoLoot.FitToText();
    g_otherMenuGUIMenuItemLoadAutoLoot.SetFunctionLeftClick(&EQAPP_AutoLoot_Load);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadMap;
    g_otherMenuGUIMenuItemLoadMap.SetText("Load Map");
    g_otherMenuGUIMenuItemLoadMap.FitToText();
    g_otherMenuGUIMenuItemLoadMap.SetFunctionLeftClick(&EQAPP_Map_Load);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadNamedSpawns;
    g_otherMenuGUIMenuItemLoadNamedSpawns.SetText("Load Named Spawns");
    g_otherMenuGUIMenuItemLoadNamedSpawns.FitToText();
    g_otherMenuGUIMenuItemLoadNamedSpawns.SetFunctionLeftClick(&EQAPP_NamedSpawns_Load);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadBazaarSearchItemNames;
    g_otherMenuGUIMenuItemLoadBazaarSearchItemNames.SetText("Load Bazaar Search Item Names");
    g_otherMenuGUIMenuItemLoadBazaarSearchItemNames.FitToText();
    g_otherMenuGUIMenuItemLoadBazaarSearchItemNames.SetFunctionLeftClick(&EQAPP_BazaarSearchWindow_LoadItemNames);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadDestroyActors;
    g_otherMenuGUIMenuItemLoadDestroyActors.SetText("Load Destroy Actors");
    g_otherMenuGUIMenuItemLoadDestroyActors.FitToText();
    g_otherMenuGUIMenuItemLoadDestroyActors.SetFunctionLeftClick(&EQAPP_DestroyActors_Load);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadTreeHack;
    g_otherMenuGUIMenuItemLoadTreeHack.SetText("Load Tree Hack");
    g_otherMenuGUIMenuItemLoadTreeHack.FitToText();
    g_otherMenuGUIMenuItemLoadTreeHack.SetFunctionLeftClick(&EQAPP_TreeHack_Load);

    EQApp::GUIMenuItem g_otherMenuGUIMenuItemLoadWaterHack;
    g_otherMenuGUIMenuItemLoadWaterHack.SetText("Load Water Hack");
    g_otherMenuGUIMenuItemLoadWaterHack.FitToText();
    g_otherMenuGUIMenuItemLoadWaterHack.SetFunctionLeftClick(&EQAPP_WaterHack_Load);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemWallHack);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemWaterHack);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemTreeHack);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemSeparator);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemDestroyActors);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemDestroyActorsCreateActorExLog);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemSeparator);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemPrintBankInventory);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemWriteInventoryToFile);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemSeparator);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadSpellSet);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemSaveSpellSet);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemSeparator);

    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadAutoLoot);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadMap);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadNamedSpawns);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadBazaarSearchItemNames);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadDestroyActors);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadTreeHack);
    g_otherMenuGUIMenu.AddMenuItem(g_otherMenuGUIMenuItemLoadWaterHack);


    g_otherMenuGUIMenu.SetX(g_otherMenuGUIButton.GetX());
    g_otherMenuGUIMenu.SetY(g_otherMenuGUIButton.GetY() + g_otherMenuGUIButton.GetHeight() + 8);

    g_otherMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_otherMenuGUIMenu);
}
