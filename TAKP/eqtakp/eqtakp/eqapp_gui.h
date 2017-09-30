#pragma once

bool g_GUIIsEnabled = true;

std::vector<EQApp::GUIButton*> g_GUIButtonList;
std::vector<EQApp::GUIMenu*> g_GUIMenuList;

void EQAPP_GUI_Execute();
bool EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY);
void EQAPP_GUI_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);
void EQAPP_GUI_CloseAllMenus();
void EQAPP_Gui_CloseAllMenuExcept(EQApp::GUIMenu* menu);

void EQAPP_GUI_Execute()
{
    for (auto& button : g_GUIButtonList)
    {
        if (button->IsVisible() == false)
        {
            continue;
        }

        button->OnProcessFrame();
        button->Draw();
    }

    for (auto& menu : g_GUIMenuList)
    {
        if (menu->IsVisible() == false)
        {
            continue;
        }

        if (menu->IsOpen() == false)
        {
            continue;
        }

        menu->OnProcessFrame();
        menu->Draw();
    }
}

bool EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY)
{
    for (auto& button : g_GUIButtonList)
    {
        if (button->IsEnabled() == false)
        {
            continue;
        }

        if (button->IsVisible() == false)
        {
            continue;
        }

        if (EQ_IsPointInsideRectangle(mouseX, mouseY, button->GetX(), button->GetY(), button->GetWidth(), button->GetHeight()) == true)
        {
            button->OnLeftClick();
            return true;
        }
    }

    for (auto& menu : g_GUIMenuList)
    {
        if (menu->IsEnabled() == false)
        {
            continue;
        }

        if (menu->IsVisible() == false)
        {
            continue;
        }

        if (menu->IsOpen() == false)
        {
            continue;
        }

        for (auto& menuItem : *menu->GetMenuItemList())
        {
            if (menuItem.IsEnabled() == true && menuItem.IsVisible() == true && menuItem.IsSeparator() == false)
            {
                if (EQ_IsPointInsideRectangle(mouseX, mouseY, menuItem.GetX(), menuItem.GetY(), menuItem.GetWidth(), menuItem.GetHeight()) == true)
                {
                    menuItem.OnLeftClick();
                    return true;
                }
            }
        }

    }

    EQAPP_GUI_CloseAllMenus();

    return false;
}

void EQAPP_GUI_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1 && zero != 0)
    {
        return;
    }

    if (commandID == EQ_EXECUTECMD_ESCAPE)
    {
        EQAPP_GUI_CloseAllMenus();
    }
}

void EQAPP_GUI_CloseAllMenus()
{
    for (auto& menu : g_GUIMenuList)
    {
        menu->SetOpen(false);
    }
}

void EQAPP_GUI_CloseAllMenusExcept(EQApp::GUIMenu* menu)
{
    if (menu->IsOpen() == true)
    {
        for (auto& menuEx : g_GUIMenuList)
        {
            if (menu != menuEx)
            {
                menuEx->SetOpen(false);
            }
        }
    }
}




