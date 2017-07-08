#pragma once

#include <functional>

#include "eqapp_gui_base.h"
#include "eqapp_gui_menu.h"

namespace EQApp
{

class GUIMenuItem : public GUIBase
{
public:
    GUIMenuItem();
    ~GUIMenuItem();

    void OnLeftClick();

    void SetFunctionLeftClick(std::function<void()> f);

    bool* GetBoolPointer();
    void SetBoolPointer(bool& b);

    EQApp::GUIMenu* GetParentMenu();
    void SetParentMenu(EQApp::GUIMenu* menu);
    bool HasParentMenu();

    EQApp::GUIMenu* GetSubMenu();
    void SetSubMenu(EQApp::GUIMenu* menu);
    bool HasSubMenu();

    void FitToText();
    void OnProcessFrame();
    void Draw();

private:
    EQApp::GUIMenu* m_parentMenu;
    EQApp::GUIMenu* m_subMenu;

    std::function<void()> m_functionLeftClick;

    bool* m_bool_ptr = NULL; // isChecked

}; // class GUIMenuItem

GUIMenuItem::GUIMenuItem()
{
    m_parentMenu = NULL;
    m_subMenu = NULL;
}

GUIMenuItem::~GUIMenuItem()
{
    //
}

void GUIMenuItem::OnLeftClick()
{
    m_functionLeftClick();
}

void GUIMenuItem::SetFunctionLeftClick(std::function<void()> f)
{
    m_functionLeftClick = std::bind(f);
}

bool* GUIMenuItem::GetBoolPointer()
{
    return m_bool_ptr;
}

void GUIMenuItem::SetBoolPointer(bool& b)
{
    m_bool_ptr = &b;
}

EQApp::GUIMenu* GUIMenuItem::GetParentMenu()
{
    return m_parentMenu;
}

void GUIMenuItem::SetParentMenu(EQApp::GUIMenu* menu)
{
    m_parentMenu = menu;
}

bool GUIMenuItem::HasParentMenu()
{
    return m_parentMenu != NULL;
}

EQApp::GUIMenu* GUIMenuItem::GetSubMenu()
{
    return m_subMenu;
}

void GUIMenuItem::SetSubMenu(EQApp::GUIMenu* menu)
{
    m_subMenu = menu;
}

bool GUIMenuItem::HasSubMenu()
{
    return m_subMenu != NULL;
}

void GUIMenuItem::FitToText()
{
    uint32_t fontWidth = EQ_GetFontTextWidth(this->GetText().c_str(), this->GetFontPointer());
    uint32_t fontHeight = EQ_GetFontTextHeight(this->GetFontPointer());

    this->SetWidth(fontWidth);
    this->SetHeight(fontHeight);
}

void GUIMenuItem::OnProcessFrame()
{
    EQ::Mouse mouse = EQ_GetMouse();

    bool isMouseOver = EQ_IsPointInsideRectangle(mouse.X, mouse.Y, this->GetX(), this->GetY(), this->GetWidth(), this->GetHeight());

    if (EQ_IsMouseHoveringOverCXWnd() == false && EQ_IsMouseLookEnabled() == false)
    {
        this->SetMouseOver(isMouseOver);
    }
    else
    {
        this->SetMouseOver(false);
    }
}

void GUIMenuItem::Draw()
{
    EQApp::GUIBase* menu = (EQApp::GUIBase*)this->GetParentMenu();

    //EQ_DrawRectangle((float)this->GetX(), (float)this->GetY(), (float)this->GetWidth() + 4.0f, (float)this->GetHeight(), this->GetBackgroundColor(), true);

    if (this->IsMouseOver() == true)
    {
        EQ_DrawRectangle((float)menu->GetX(), (float)this->GetY(), (float)menu->GetWidth() + 4.0f, (float)this->GetHeight() + 1.0f, this->GetBackgroundColor(), true);
    }

    EQ_DrawText(this->GetText().c_str(), this->GetX() + 3, this->GetY(), this->GetTextColor());
}

} // namespace EQApp
