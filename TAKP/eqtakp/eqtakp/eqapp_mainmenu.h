#pragma once

EQApp::GUIButton g_mainMenuGUIButton;

EQApp::GUIMenu g_mainMenuGUIMenu;

void EQAPP_MainMenu_Toggle();
void EQAPP_MainMenu_Load();
void EQAPP_MainMenu_CreateButton();
void EQAPP_MainMenu_CreateMenu();

void EQAPP_MainMenu_Toggle()
{
    g_mainMenuGUIMenu.Toggle();
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
    EQApp::GUIMenuItem g_mainMenuGUIMenuItemAlwaysAttack;
    g_mainMenuGUIMenuItemAlwaysAttack.SetText("Always Attack");
    g_mainMenuGUIMenuItemAlwaysAttack.FitToText();
    g_mainMenuGUIMenuItemAlwaysAttack.SetFunctionLeftClick(&EQAPP_AlwaysAttack_Toggle);
    g_mainMenuGUIMenuItemAlwaysAttack.SetBoolPointer(g_alwaysAttackIsEnabled);

    EQApp::GUIMenuItem g_mainMenuGUIMenuItemFoodAndDrink;
    g_mainMenuGUIMenuItemFoodAndDrink.SetText("Food and Drink");
    g_mainMenuGUIMenuItemFoodAndDrink.FitToText();
    g_mainMenuGUIMenuItemFoodAndDrink.SetFunctionLeftClick(&EQAPP_FoodAndDrink_Toggle);
    g_mainMenuGUIMenuItemFoodAndDrink.SetBoolPointer(g_foodAndDrinkIsEnabled);

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

    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemAlwaysAttack);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemFoodAndDrink);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemESP);
    g_mainMenuGUIMenu.AddMenuItem(g_mainMenuGUIMenuItemExtendedTargets);

    g_mainMenuGUIMenu.SetX(g_mainMenuGUIButton.GetX());
    g_mainMenuGUIMenu.SetY(g_mainMenuGUIButton.GetY() + g_mainMenuGUIButton.GetHeight() + 8);

    g_mainMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_mainMenuGUIMenu);
}



