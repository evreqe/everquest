#pragma once

EQApp::GUIButton g_SkillsMenuGUIButton;

EQApp::GUIMenu g_SkillsMenuGUIMenu;

void EQAPP_SkillsMenu_Toggle();
void EQAPP_SkillsMenu_Load();
void EQAPP_SkillsMenu_CreateButton();
void EQAPP_SkillsMenu_CreateMenu();

void EQAPP_SkillsMenu_Toggle()
{
    g_SkillsMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_SkillsMenuGUIMenu);
}

void EQAPP_SkillsMenu_Load()
{
    EQAPP_SkillsMenu_CreateButton();
    EQAPP_SkillsMenu_CreateMenu();
}

void EQAPP_SkillsMenu_CreateButton()
{
    g_SkillsMenuGUIButton.SetX(300);
    g_SkillsMenuGUIButton.SetY(6);

    g_SkillsMenuGUIButton.SetWidth(64);
    g_SkillsMenuGUIButton.SetHeight(32);

    g_SkillsMenuGUIButton.SetText("SKILLS");
    g_SkillsMenuGUIButton.FitToText();

    g_SkillsMenuGUIButton.SetFunctionLeftClick(&EQAPP_SkillsMenu_Toggle);

    g_GUIButtonList.push_back(&g_SkillsMenuGUIButton);
}

void EQAPP_SkillsMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemToggle;
    g_SkillsMenuGUIMenuItemToggle.SetText("Toggle");
    g_SkillsMenuGUIMenuItemToggle.FitToText();
    g_SkillsMenuGUIMenuItemToggle.SetFunctionLeftClick(&EQAPP_UseSkills_Toggle);
    g_SkillsMenuGUIMenuItemToggle.SetBoolPointer(g_UseSkillsIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemSeparator;
    g_SkillsMenuGUIMenuItemSeparator.SetText("--------------------");
    g_SkillsMenuGUIMenuItemSeparator.FitToText();
    g_SkillsMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemTaunt;
    g_SkillsMenuGUIMenuItemTaunt.SetText("Taunt");
    g_SkillsMenuGUIMenuItemTaunt.FitToText();
    g_SkillsMenuGUIMenuItemTaunt.SetFunctionLeftClick(&EQAPP_UseSkills_Taunt_Toggle);
    g_SkillsMenuGUIMenuItemTaunt.SetBoolPointer(g_UseSkillsTauntIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemKick;
    g_SkillsMenuGUIMenuItemKick.SetText("Kick");
    g_SkillsMenuGUIMenuItemKick.FitToText();
    g_SkillsMenuGUIMenuItemKick.SetFunctionLeftClick(&EQAPP_UseSkills_Kick_Toggle);
    g_SkillsMenuGUIMenuItemKick.SetBoolPointer(g_UseSkillsKickIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemBash;
    g_SkillsMenuGUIMenuItemBash.SetText("Bash");
    g_SkillsMenuGUIMenuItemBash.FitToText();
    g_SkillsMenuGUIMenuItemBash.SetFunctionLeftClick(&EQAPP_UseSkills_Bash_Toggle);
    g_SkillsMenuGUIMenuItemBash.SetBoolPointer(g_UseSkillsBashIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemSlam;
    g_SkillsMenuGUIMenuItemSlam.SetText("Slam");
    g_SkillsMenuGUIMenuItemSlam.FitToText();
    g_SkillsMenuGUIMenuItemSlam.SetFunctionLeftClick(&EQAPP_UseSkills_Slam_Toggle);
    g_SkillsMenuGUIMenuItemSlam.SetBoolPointer(g_UseSkillsSlamIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemDisarm;
    g_SkillsMenuGUIMenuItemDisarm.SetText("Disarm");
    g_SkillsMenuGUIMenuItemDisarm.FitToText();
    g_SkillsMenuGUIMenuItemDisarm.SetFunctionLeftClick(&EQAPP_UseSkills_Disarm_Toggle);
    g_SkillsMenuGUIMenuItemDisarm.SetBoolPointer(g_UseSkillsDisarmIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemBackstab;
    g_SkillsMenuGUIMenuItemBackstab.SetText("Backstab");
    g_SkillsMenuGUIMenuItemBackstab.FitToText();
    g_SkillsMenuGUIMenuItemBackstab.SetFunctionLeftClick(&EQAPP_UseSkills_Backstab_Toggle);
    g_SkillsMenuGUIMenuItemBackstab.SetBoolPointer(g_UseSkillsBackstabIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemRoundKick;
    g_SkillsMenuGUIMenuItemRoundKick.SetText("Round Kick");
    g_SkillsMenuGUIMenuItemRoundKick.FitToText();
    g_SkillsMenuGUIMenuItemRoundKick.SetFunctionLeftClick(&EQAPP_UseSkills_RoundKick_Toggle);
    g_SkillsMenuGUIMenuItemRoundKick.SetBoolPointer(g_UseSkillsRoundKickIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemFeignDeath;
    g_SkillsMenuGUIMenuItemFeignDeath.SetText("Feign Death");
    g_SkillsMenuGUIMenuItemFeignDeath.FitToText();
    g_SkillsMenuGUIMenuItemFeignDeath.SetFunctionLeftClick(&EQAPP_UseSkills_FeignDeath_Toggle);
    g_SkillsMenuGUIMenuItemFeignDeath.SetBoolPointer(g_UseSkillsFeignDeathIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemMend;
    g_SkillsMenuGUIMenuItemMend.SetText("Mend");
    g_SkillsMenuGUIMenuItemMend.FitToText();
    g_SkillsMenuGUIMenuItemMend.SetFunctionLeftClick(&EQAPP_UseSkills_Mend_Toggle);
    g_SkillsMenuGUIMenuItemMend.SetBoolPointer(g_UseSkillsMendIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemForage;
    g_SkillsMenuGUIMenuItemForage.SetText("Forage");
    g_SkillsMenuGUIMenuItemForage.FitToText();
    g_SkillsMenuGUIMenuItemForage.SetFunctionLeftClick(&EQAPP_UseSkills_Forage_Toggle);
    g_SkillsMenuGUIMenuItemForage.SetBoolPointer(g_UseSkillsForageIsEnabled);

    EQApp::GUIMenuItem g_SkillsMenuGUIMenuItemSenseHeading;
    g_SkillsMenuGUIMenuItemSenseHeading.SetText("Sense Heading");
    g_SkillsMenuGUIMenuItemSenseHeading.FitToText();
    g_SkillsMenuGUIMenuItemSenseHeading.SetFunctionLeftClick(&EQAPP_UseSkills_SenseHeading_Toggle);
    g_SkillsMenuGUIMenuItemSenseHeading.SetBoolPointer(g_UseSkillsSenseHeadingIsEnabled);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemToggle);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSeparator);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemTaunt);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemKick);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemBash);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSlam);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemDisarm);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSeparator);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemBackstab);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSeparator);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemRoundKick);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemFeignDeath);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemMend);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSeparator);

    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemForage);
    g_SkillsMenuGUIMenu.AddMenuItem(g_SkillsMenuGUIMenuItemSenseHeading);

    g_SkillsMenuGUIMenu.SetX(g_SkillsMenuGUIButton.GetX());
    g_SkillsMenuGUIMenu.SetY(g_SkillsMenuGUIButton.GetY() + g_SkillsMenuGUIButton.GetHeight() + 8);

    g_SkillsMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_SkillsMenuGUIMenu);
}
