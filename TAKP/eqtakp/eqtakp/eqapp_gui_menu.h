#pragma once

#include "eqapp_gui_base.h"
#include "eqapp_gui_menuitem.h"

namespace EQApp
{

class GUIMenu : public GUIBase
{

public:
    GUIMenu();
    ~GUIMenu();

    void ToggleOpen();
    void SetOpen(bool bOpen);
    bool IsOpen();
    void AddMenuItem(EQApp::GUIMenuItem menuItem);
    void RemoveMenuItems();
    std::vector<EQApp::GUIMenuItem>* GetMenuItemList();
    void FitToText();
    void OnProcessFrame();
    void Draw();

private:
    std::vector<EQApp::GUIMenuItem> m_menuItemList;

    bool m_isOpen;

    uint32_t m_menuItemsTextWidth;
    uint32_t m_menuItemsTextHeight;

}; // class GUIMenu

GUIMenu::GUIMenu()
{
    m_isOpen = false;

    m_menuItemsTextWidth = 0;
    m_menuItemsTextHeight = 0;
}

GUIMenu::~GUIMenu()
{
    //
}

void GUIMenu::ToggleOpen()
{
    m_isOpen = !m_isOpen;
}

void GUIMenu::SetOpen(bool bOpen)
{
    m_isOpen = bOpen;
}

bool GUIMenu::IsOpen()
{
    return m_isOpen;
}

void GUIMenu::AddMenuItem(EQApp::GUIMenuItem menuItem)
{
    menuItem.SetParentMenu(this);

    m_menuItemList.push_back(menuItem);
}

void GUIMenu::RemoveMenuItems()
{
    m_menuItemList.clear();
}

std::vector<EQApp::GUIMenuItem>* GUIMenu::GetMenuItemList()
{
    return &m_menuItemList;
}

void GUIMenu::FitToText()
{
    m_menuItemsTextWidth = 0;
    m_menuItemsTextHeight = 0;

    for (auto& menuItem : m_menuItemList)
    {
        uint32_t menuItemWidth = menuItem.GetWidth();
        if (menuItemWidth > m_menuItemsTextWidth)
        {
            m_menuItemsTextWidth = menuItemWidth;
        }

        m_menuItemsTextHeight += menuItem.GetHeight() + 1;
    }

    this->SetWidth(m_menuItemsTextWidth + 32);
    this->SetHeight(m_menuItemsTextHeight + 16);
}

void GUIMenu::OnProcessFrame()
{
    this->SetMouseOver(false);
    return;

    EQ::Mouse mouse = EQ_GetMouse();

    bool isMouseOver = EQ_IsPointInsideRectangle(mouse.X, mouse.Y, this->GetX(), this->GetY(), this->GetWidth(), this->GetHeight());

    if (this->IsEnabled() == false)
    {
        this->SetMouseOver(false);
    }
    else
    {
        if (EQ_IsMouseHoveringOverCXWnd() == false && EQ_IsMouseLookEnabled() == false)
        {
            this->SetMouseOver(isMouseOver);
        }
        else
        {
            this->SetMouseOver(false);
        }
    }
}

void GUIMenu::Draw()
{
    EQ_DrawRectangle((float)this->GetX(), (float)this->GetY(), (float)this->GetWidth() + 4.0f, (float)this->GetHeight(), this->GetBackgroundColor(), true);

    uint32_t drawX = this->GetX();
    uint32_t drawY = this->GetY() + 8;

    for (auto& menuItem : m_menuItemList)
    {
        menuItem.SetX(drawX + 16);
        menuItem.SetY(drawY);
        menuItem.SetWidth(this->GetWidth() - 32);

        menuItem.OnProcessFrame();
        menuItem.Draw();

        //if (*menuItem.GetBoolPointer() == true)
        if (menuItem.IsChecked() == true)
        {
            EQ_DrawText("*", drawX + 8, drawY, EQ_COLOR_ARGB_WHITE);
        }

        drawY += menuItem.GetHeight() + 1;
    }

    EQ_DrawRectangle((float)this->GetX(), (float)this->GetY(), (float)this->GetWidth() + 4.0f, (float)this->GetHeight(), this->GetBorderColor(), false);
}

} // namespace EQApp
