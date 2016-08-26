#ifndef EQAPP_IMGUI_FUNCTIONS_H
#define EQAPP_IMGUI_FUNCTIONS_H

#include "eqapp_imgui.h"

#include "eqapp_imgui_consolewindow.h"
#include "eqapp_imgui_optionswindow.h"

EQAPPIMGUIConsoleWindow g_imguiConsoleWindow;
EQAPPIMGUIOptionsWindow g_imguiOptionsWindow;

bool g_bImguiConsoleWindow = true;
bool g_bImguiOptionsWindow = true;

void EQAPP_IMGUI_Draw();

void EQAPP_IMGUI_MainMenuBar();
void EQAPP_IMGUI_MainMenuItemFile();
void EQAPP_IMGUI_MainMenuItemWindow();

void EQAPP_IMGUI_ConsoleWindow();
void EQAPP_IMGUI_OptionsWindow();

void EQAPP_IMGUI_Draw()
{
    EQAPP_IMGUI_MainMenuBar();

    if (g_bImguiConsoleWindow == true)    EQAPP_IMGUI_ConsoleWindow();
    if (g_bImguiOptionsWindow == true)    EQAPP_IMGUI_OptionsWindow();
}

void EQAPP_IMGUI_MainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            EQAPP_IMGUI_MainMenuItemFile();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            EQAPP_IMGUI_MainMenuItemWindow();
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

void EQAPP_IMGUI_MainMenuItemFile()
{
    ImGui::Separator();

    if (ImGui::MenuItem("Quit", "Pause/Break"))
    {
        EQAPP_Unload();
    }
}

void EQAPP_IMGUI_MainMenuItemWindow()
{
    ImGui::MenuItem("Console", NULL, &g_bImguiConsoleWindow);
    ImGui::MenuItem("Options", NULL, &g_bImguiOptionsWindow);
}

void EQAPP_IMGUI_ConsoleWindow()
{
    g_imguiConsoleWindow.Draw("Console", &g_bImguiConsoleWindow);
}

void EQAPP_IMGUI_OptionsWindow()
{
    g_imguiOptionsWindow.Draw("Options", &g_bImguiOptionsWindow);
}

#endif // EQAPP_IMGUI_FUNCTIONS_H
