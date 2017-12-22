#pragma once

#pragma once

EQApp::GUIButton g_MemoryMenuGUIButton;

EQApp::GUIMenu g_MemoryMenuGUIMenu;

EQApp::GUIMenuItem g_MemoryMenuGUIMenuItem[255]; // g_MemoryFilesMax

void EQAPP_MemoryMenu_Toggle();
void EQAPP_MemoryMenu_Load();
void EQAPP_MemoryMenu_CreateButton();
void EQAPP_MemoryMenu_CreateMenu();

void EQAPP_MemoryMenu_Toggle()
{
    g_MemoryMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_MemoryMenuGUIMenu);
}

void EQAPP_MemoryMenu_Load()
{
    EQAPP_MemoryMenu_CreateButton();
    EQAPP_MemoryMenu_CreateMenu();
}

void EQAPP_MemoryMenu_CreateButton()
{
    g_MemoryMenuGUIButton.SetX(600);
    g_MemoryMenuGUIButton.SetY(6);

    g_MemoryMenuGUIButton.SetWidth(64);
    g_MemoryMenuGUIButton.SetHeight(32);

    g_MemoryMenuGUIButton.SetText("MEMORY");
    g_MemoryMenuGUIButton.FitToText();

    g_MemoryMenuGUIButton.SetFunctionLeftClick(&EQAPP_MemoryMenu_Toggle);

    g_GUIButtonList.push_back(&g_MemoryMenuGUIButton);
}

void EQAPP_MemoryMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_MemoryMenuGUIMenuItemSeparator;
    g_MemoryMenuGUIMenuItemSeparator.SetText("--------------------");
    g_MemoryMenuGUIMenuItemSeparator.FitToText();
    g_MemoryMenuGUIMenuItemSeparator.SetIsSeparator(true);

    for (auto& memory : g_MemoryList)
    {
        std::function<void()> functionLeftClick = std::bind(EQAPP_Memory_ToggleByIndex, memory.Index);

        g_MemoryMenuGUIMenuItem[memory.Index].SetText(memory.Name);
        g_MemoryMenuGUIMenuItem[memory.Index].FitToText();
        g_MemoryMenuGUIMenuItem[memory.Index].SetFunctionLeftClick(functionLeftClick);
        g_MemoryMenuGUIMenuItem[memory.Index].SetBoolPointer(memory.Enabled);

        g_MemoryMenuGUIMenu.AddMenuItem(g_MemoryMenuGUIMenuItem[memory.Index]);
    }

    g_MemoryMenuGUIMenu.SetX(g_MemoryMenuGUIButton.GetX());
    g_MemoryMenuGUIMenu.SetY(g_MemoryMenuGUIButton.GetY() + g_MemoryMenuGUIButton.GetHeight() + 8);

    g_MemoryMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_MemoryMenuGUIMenu);
}
