#pragma once

EQApp::GUIButton g_skillsMenuGUIButton;

EQApp::GUIMenu g_skillsMenuGUIMenu;

void EQAPP_SkillsMenu_Toggle();
void EQAPP_SkillsMenu_Load();
void EQAPP_SkillsMenu_CreateButton();
void EQAPP_SkillsMenu_CreateMenu();

void EQAPP_SkillsMenu_Toggle()
{
    g_skillsMenuGUIMenu.ToggleOpen();
}

void EQAPP_SkillsMenu_Load()
{
    EQAPP_SkillsMenu_CreateButton();
    EQAPP_SkillsMenu_CreateMenu();
}

void EQAPP_SkillsMenu_CreateButton()
{
    g_skillsMenuGUIButton.SetX(400);
    g_skillsMenuGUIButton.SetY(6);

    g_skillsMenuGUIButton.SetWidth(64);
    g_skillsMenuGUIButton.SetHeight(32);

    g_skillsMenuGUIButton.SetText("SKILLS");
    g_skillsMenuGUIButton.FitToText();

    g_skillsMenuGUIButton.SetFunctionLeftClick(&EQAPP_SkillsMenu_Toggle);

    g_GUIButtonList.push_back(&g_skillsMenuGUIButton);
}

void EQAPP_SkillsMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemSeparator;
    g_skillsMenuGUIMenuItemSeparator.SetText("--------------------");
    g_skillsMenuGUIMenuItemSeparator.FitToText();
    g_skillsMenuGUIMenuItemSeparator.SetIsSeparator(true);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemTaunt;
    g_skillsMenuGUIMenuItemTaunt.SetText("Taunt");
    g_skillsMenuGUIMenuItemTaunt.FitToText();
    g_skillsMenuGUIMenuItemTaunt.SetFunctionLeftClick(&EQAPP_UseSkills_Taunt_Toggle);
    g_skillsMenuGUIMenuItemTaunt.SetBoolPointer(g_useSkillsTauntIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemKick;
    g_skillsMenuGUIMenuItemKick.SetText("Kick");
    g_skillsMenuGUIMenuItemKick.FitToText();
    g_skillsMenuGUIMenuItemKick.SetFunctionLeftClick(&EQAPP_UseSkills_Kick_Toggle);
    g_skillsMenuGUIMenuItemKick.SetBoolPointer(g_useSkillsKickIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemBash;
    g_skillsMenuGUIMenuItemBash.SetText("Bash");
    g_skillsMenuGUIMenuItemBash.FitToText();
    g_skillsMenuGUIMenuItemBash.SetFunctionLeftClick(&EQAPP_UseSkills_Bash_Toggle);
    g_skillsMenuGUIMenuItemBash.SetBoolPointer(g_useSkillsBashIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemSlam;
    g_skillsMenuGUIMenuItemSlam.SetText("Slam");
    g_skillsMenuGUIMenuItemSlam.FitToText();
    g_skillsMenuGUIMenuItemSlam.SetFunctionLeftClick(&EQAPP_UseSkills_Slam_Toggle);
    g_skillsMenuGUIMenuItemSlam.SetBoolPointer(g_useSkillsSlamIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemDisarm;
    g_skillsMenuGUIMenuItemDisarm.SetText("Disarm");
    g_skillsMenuGUIMenuItemDisarm.FitToText();
    g_skillsMenuGUIMenuItemDisarm.SetFunctionLeftClick(&EQAPP_UseSkills_Disarm_Toggle);
    g_skillsMenuGUIMenuItemDisarm.SetBoolPointer(g_useSkillsDisarmIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemBackstab;
    g_skillsMenuGUIMenuItemBackstab.SetText("Backstab");
    g_skillsMenuGUIMenuItemBackstab.FitToText();
    g_skillsMenuGUIMenuItemBackstab.SetFunctionLeftClick(&EQAPP_UseSkills_Backstab_Toggle);
    g_skillsMenuGUIMenuItemBackstab.SetBoolPointer(g_useSkillsBackstabIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemRoundKick;
    g_skillsMenuGUIMenuItemRoundKick.SetText("Round Kick");
    g_skillsMenuGUIMenuItemRoundKick.FitToText();
    g_skillsMenuGUIMenuItemRoundKick.SetFunctionLeftClick(&EQAPP_UseSkills_RoundKick_Toggle);
    g_skillsMenuGUIMenuItemRoundKick.SetBoolPointer(g_useSkillsRoundKickIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemForage;
    g_skillsMenuGUIMenuItemForage.SetText("Forage");
    g_skillsMenuGUIMenuItemForage.FitToText();
    g_skillsMenuGUIMenuItemForage.SetFunctionLeftClick(&EQAPP_UseSkills_Forage_Toggle);
    g_skillsMenuGUIMenuItemForage.SetBoolPointer(g_useSkillsForageIsEnabled);

    EQApp::GUIMenuItem g_skillsMenuGUIMenuItemSenseHeading;
    g_skillsMenuGUIMenuItemSenseHeading.SetText("Sense Heading");
    g_skillsMenuGUIMenuItemSenseHeading.FitToText();
    g_skillsMenuGUIMenuItemSenseHeading.SetFunctionLeftClick(&EQAPP_UseSkills_SenseHeading_Toggle);
    g_skillsMenuGUIMenuItemSenseHeading.SetBoolPointer(g_useSkillsSenseHeadingIsEnabled);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemTaunt);
    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemKick);
    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemBash);
    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemSlam);
    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemDisarm);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemSeparator);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemBackstab);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemSeparator);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemRoundKick);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemSeparator);

    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemForage);
    g_skillsMenuGUIMenu.AddMenuItem(g_skillsMenuGUIMenuItemSenseHeading);

    g_skillsMenuGUIMenu.SetX(g_skillsMenuGUIButton.GetX());
    g_skillsMenuGUIMenu.SetY(g_skillsMenuGUIButton.GetY() + g_skillsMenuGUIButton.GetHeight() + 8);

    g_skillsMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_skillsMenuGUIMenu);
}
