#pragma once

bool g_GUIIsEnabled = true;

std::vector<EQApp::GUIButton*> g_GUIButtonList;
std::vector<EQApp::GUIMenu*> g_GUIMenuList;

void EQAPP_GUI_Execute();
bool EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY);

void EQAPP_GUI_Execute()
{
    for (auto& button : g_GUIButtonList)
    {
        button->OnProcessFrame();
        button->Draw();
    }

    for (auto& menu : g_GUIMenuList)
    {
        //for (auto& menuItem : *menu.GetMenuItemList())
        //{
            //std::cout << "menu item text: " << menuItem.GetText() << std::endl;
        //}

        if (menu->IsEnabled() == true)
        {
            menu->OnProcessFrame();
            menu->Draw();
        }
    }
}

bool EQAPP_GUI_HandleEvent_CEverQuest__LMouseUp(uint16_t mouseX, uint16_t mouseY)
{
    for (auto& button : g_GUIButtonList)
    {
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

        for (auto& menuItem : *menu->GetMenuItemList())
        {
            if (menuItem.IsSeparator() == false)
            {
                if (EQ_IsPointInsideRectangle(mouseX, mouseY, menuItem.GetX(), menuItem.GetY(), menuItem.GetWidth(), menuItem.GetHeight()) == true)
                {
                    menuItem.OnLeftClick();
                    return true;
                }
            }
        }

    }

    for (auto& menu : g_GUIMenuList)
    {
        menu->SetEnabled(false);
    }

    return false;
}



