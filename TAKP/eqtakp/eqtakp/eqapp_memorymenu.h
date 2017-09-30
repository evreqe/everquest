#pragma once

#pragma once

EQApp::GUIButton g_memoryMenuGUIButton;

EQApp::GUIMenu g_memoryMenuGUIMenu;

EQApp::GUIMenuItem g_memoryMenuGUIMenuItem[255]; // g_memoryFilesMax

void EQAPP_MemoryMenu_Toggle();
void EQAPP_MemoryMenu_Load();
void EQAPP_MemoryMenu_CreateButton();
void EQAPP_MemoryMenu_CreateMenu();

void EQAPP_MemoryMenu_Toggle()
{
    g_memoryMenuGUIMenu.ToggleOpen();

    EQAPP_GUI_CloseAllMenusExcept(&g_memoryMenuGUIMenu);
}

void EQAPP_MemoryMenu_Load()
{
    EQAPP_MemoryMenu_CreateButton();
    EQAPP_MemoryMenu_CreateMenu();
}

void EQAPP_MemoryMenu_CreateButton()
{
    g_memoryMenuGUIButton.SetX(600);
    g_memoryMenuGUIButton.SetY(6);

    g_memoryMenuGUIButton.SetWidth(64);
    g_memoryMenuGUIButton.SetHeight(32);

    g_memoryMenuGUIButton.SetText("MEMORY");
    g_memoryMenuGUIButton.FitToText();

    g_memoryMenuGUIButton.SetFunctionLeftClick(&EQAPP_MemoryMenu_Toggle);

    g_GUIButtonList.push_back(&g_memoryMenuGUIButton);
}

void EQAPP_MemoryMenu_CreateMenu()
{
    EQApp::GUIMenuItem g_memoryMenuGUIMenuItemSeparator;
    g_memoryMenuGUIMenuItemSeparator.SetText("--------------------");
    g_memoryMenuGUIMenuItemSeparator.FitToText();
    g_memoryMenuGUIMenuItemSeparator.SetIsSeparator(true);

    for (auto& memory : g_memoryList)
    {
        std::function<void()> functionLeftClick = std::bind(EQAPP_Memory_ToggleByIndex, memory.Index);

        g_memoryMenuGUIMenuItem[memory.Index].SetText(memory.Name);
        g_memoryMenuGUIMenuItem[memory.Index].FitToText();
        g_memoryMenuGUIMenuItem[memory.Index].SetFunctionLeftClick(functionLeftClick);
        g_memoryMenuGUIMenuItem[memory.Index].SetBoolPointer(memory.Enabled);

        g_memoryMenuGUIMenu.AddMenuItem(g_memoryMenuGUIMenuItem[memory.Index]);
    }

    g_memoryMenuGUIMenu.SetX(g_memoryMenuGUIButton.GetX());
    g_memoryMenuGUIMenu.SetY(g_memoryMenuGUIButton.GetY() + g_memoryMenuGUIButton.GetHeight() + 8);

    g_memoryMenuGUIMenu.FitToText();

    g_GUIMenuList.push_back(&g_memoryMenuGUIMenu);
}
