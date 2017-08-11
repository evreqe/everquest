#pragma once

namespace EQApp
{

class GUIBase
{

public:
    GUIBase();
    ~GUIBase();

    uint32_t GetX();
    uint32_t GetY();
    uint32_t GetWidth();
    uint32_t GetHeight();
    uint32_t GetFontPointer();
    std::string GetText();
    bool IsMouseOver();
    bool IsVisible();
    bool IsEnabled();
    uint32_t GUIBase::GetBorderColor();
    uint32_t GUIBase::GetBackgroundColor();
    uint32_t GUIBase::GetTextColor();

    void SetX(uint32_t x);
    void SetY(uint32_t y);
    void SetWidth(uint32_t width);
    void SetHeight(uint32_t height);
    void SetFontPointer(uint32_t fontPointer);
    void SetText(const std::string& text);
    void SetMouseOver(bool b);
    void SetVisible(bool b);
    void SetEnabled(bool b);
    void SetBorderColor(uint32_t colorARGB);
    void SetBackgroundColor(uint32_t colorARGB);
    void SetTextColor(uint32_t textColor);
    void SetMouseOverBorderColor(uint32_t colorARGB);
    void SetMouseOverBackgroundColor(uint32_t colorARGB);
    void SetMouseOverTextColor(uint32_t textColor);

private:
    uint32_t m_x;
    uint32_t m_y;
    uint32_t m_width;
    uint32_t m_height;
    uint32_t m_fontPointer;
    std::string m_text;
    bool m_mouseOver;
    bool m_isVisible;
    bool m_isEnabled;
    uint32_t m_borderColorARGB;
    uint32_t m_backgroundColorARGB;
    uint32_t m_textColor;
    uint32_t m_mouseClickBackgroundColorARGB;
    uint32_t m_mouseOverBorderColorARGB;
    uint32_t m_mouseOverBackgroundColorARGB;
    uint32_t m_mouseOverTextColor;
    uint32_t m_disabledTextColor;

}; // class GUIBase

GUIBase::GUIBase()
{
    m_fontPointer = EQ_ADDRESS_POINTER_FONT_ARIAL14;
    m_text = " ";
    m_mouseOver = false;
    m_isVisible = true;
    m_isEnabled = true;
    m_borderColorARGB = 0xFF646464;
    m_backgroundColorARGB = 0x80000000;
    m_textColor = EQ_TEXT_COLOR_WHITE;
    m_mouseClickBackgroundColorARGB = 0xFFFF0000;
    m_mouseOverBorderColorARGB = 0xFF646464;
    m_mouseOverBackgroundColorARGB = 0xFF000000;
    m_mouseOverTextColor = EQ_TEXT_COLOR_YELLOW;
    m_disabledTextColor = EQ_TEXT_COLOR_GRAY;
}

GUIBase::~GUIBase()
{
    //
}

uint32_t GUIBase::GetX() { return m_x; }
uint32_t GUIBase::GetY() { return m_y; }
uint32_t GUIBase::GetWidth() { return m_width; }
uint32_t GUIBase::GetHeight() { return m_height; }
uint32_t GUIBase::GetFontPointer() { return m_fontPointer; }
std::string GUIBase::GetText() { return m_text; }
bool GUIBase::IsMouseOver() { return m_mouseOver; }
bool GUIBase::IsVisible() { return m_isVisible; }
bool GUIBase::IsEnabled() { return m_isEnabled; }

uint32_t GUIBase::GetBorderColor()
{
    return m_mouseOver == false ? m_borderColorARGB : m_mouseOverBorderColorARGB;
}

uint32_t GUIBase::GetBackgroundColor()
{
    if (m_mouseOver == true)
    {
        EQ::Mouse mouse = EQ_GetMouse();
        if (mouse.ClickState == EQ_MOUSE_CLICK_STATE_LEFT)
        {
            return m_mouseClickBackgroundColorARGB;
        }
    }

    return m_mouseOver == false ? m_backgroundColorARGB : m_mouseOverBackgroundColorARGB;
}

uint32_t GUIBase::GetTextColor()
{
    if (m_isEnabled == false)
    {
        return m_disabledTextColor;
    }

    return m_mouseOver == false ? m_textColor : m_mouseOverTextColor;
}

void GUIBase::SetX(uint32_t x) { m_x = x; }
void GUIBase::SetY(uint32_t y) { m_y = y; }
void GUIBase::SetWidth(uint32_t width) { m_width = width; }
void GUIBase::SetHeight(uint32_t height) { m_height = height; }
void GUIBase::SetFontPointer(uint32_t fontPointer) { m_fontPointer = fontPointer; }
void GUIBase::SetText(const std::string& text) { m_text = text; }
void GUIBase::SetMouseOver(bool b) { m_mouseOver = b; }
void GUIBase::SetVisible(bool b) { m_isVisible = b; }
void GUIBase::SetEnabled(bool b) { m_isEnabled = b; }
void GUIBase::SetBorderColor(uint32_t colorARGB) { m_borderColorARGB = colorARGB; }
void GUIBase::SetBackgroundColor(uint32_t colorARGB) { m_backgroundColorARGB = colorARGB; }
void GUIBase::SetTextColor(uint32_t textColor) { m_textColor = textColor; }
void GUIBase::SetMouseOverBorderColor(uint32_t colorARGB) { m_mouseOverBorderColorARGB = colorARGB; }
void GUIBase::SetMouseOverBackgroundColor(uint32_t colorARGB) { m_mouseOverBackgroundColorARGB = colorARGB; }
void GUIBase::SetMouseOverTextColor(uint32_t textColor) { m_mouseOverTextColor = textColor; }

} // namespace EQApp

