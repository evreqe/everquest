#pragma once

#include <functional>

#include "eqapp_gui_base.h"

namespace EQApp
{

class GUIButton : public GUIBase
{

public:
    GUIButton();
    ~GUIButton();

    void OnLeftClick();
    void OnRightClick();

    void SetFunctionLeftClick(std::function<void()> f);
    void SetFunctionRightClick(std::function<void()> f);

    void FitToText();
    void OnProcessFrame();
    void Draw();

private:
    std::function<void()> m_functionLeftClick;
    std::function<void()> m_functionRightClick;

}; // class GUIButton

GUIButton::GUIButton()
{
    //
}

GUIButton::~GUIButton()
{
    //
}

void GUIButton::OnLeftClick()
{
    m_functionLeftClick();
}

void GUIButton::OnRightClick()
{
    m_functionRightClick();
}

void GUIButton::SetFunctionLeftClick(std::function<void()> f)
{
    m_functionLeftClick = std::bind(f);
}

void GUIButton::SetFunctionRightClick(std::function<void()> f)
{
    m_functionRightClick = std::bind(f);
}

void GUIButton::FitToText()
{
    uint32_t fontWidth = EQ_GetFontTextWidth(this->GetText().c_str(), this->GetFontPointer());
    uint32_t fontHeight = EQ_GetFontTextHeight(this->GetFontPointer());

    this->SetWidth(fontWidth);
    this->SetHeight(fontHeight);
}

void GUIButton::OnProcessFrame()
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

void GUIButton::Draw()
{
    EQ_DrawRectangle((float)this->GetX(), (float)this->GetY(), (float)this->GetWidth() + 4.0f, (float)this->GetHeight(), this->GetBackgroundColor(), true);
    EQ_DrawRectangle((float)this->GetX(), (float)this->GetY(), (float)this->GetWidth() + 4.0f, (float)this->GetHeight(), this->GetBorderColor(), false);

    EQ_DrawText(this->GetText().c_str(), this->GetX() + 3, this->GetY(), this->GetTextColor());
}

} // namespace EQApp
