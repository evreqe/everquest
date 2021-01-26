#pragma once

#include "imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool g_GUIIsEnabled = true;

bool g_GUIIsLoaded = false;

bool g_GUIIsRendered = false;

bool g_GUIDarkThemeIsEnabled = true;

bool g_GUIDemoWindowIsEnabled = false;

ImFont* g_GUIFont = NULL;

#include "eqapp_gui_dockwindow.h"
#include "eqapp_gui_mainwindow.h"
#include "eqapp_gui_mapwindow.h"
#include "eqapp_gui_waypointeditorwindow.h"
#include "eqapp_gui_transmogwindow.h"

void EQAPP_GUI_Toggle();
void EQAPP_GUI_On();
void EQAPP_GUI_Off();
bool EQAPP_GUI_Load();
void EQAPP_GUI_Unload();
bool EQAPP_GUI_IsMouseOver();
signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool EQAPP_GUI_HandleEvent_ProcessMouseEvent();
bool EQAPP_GUI_HandleEvent_ProcessKeyboardEvent();
bool EQAPP_GUI_HandleEvent_CXWndManager__DrawCursor();
bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta);
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before();
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_After();
void EQAPP_GUI_HandleEvent_CRender__UpdateDisplay();

void EQAPP_GUI_Toggle()
{
    EQ_ToggleBool(g_GUIIsEnabled);
    EQAPP_PrintBool("GUI", g_GUIIsEnabled);
}

void EQAPP_GUI_On()
{
    if (g_GUIIsEnabled == false)
    {
        EQAPP_GUI_Toggle();
    }
}

void EQAPP_GUI_Off()
{
    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_Toggle();
    }
}

bool EQAPP_GUI_Load()
{
    HWND window = EQ_GetWindow();
    if (window == NULL)
    {
        return false;
    }

    auto render = EQ_GetRender();
    if (render == NULL)
    {
        return false;
    }

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;    // enable keyboard controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigDockingWithShift = true;
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    g_GUIFont = io.Fonts->AddFontDefault();
    if (g_GUIFont == NULL)
    {
        return false;
    }

    if (ImGui_ImplWin32_Init(window) == false)
    {
        return false;
    }

    auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
    if (devicePointer == NULL)
    {
        return false;
    }

    if (ImGui_ImplDX9_Init(devicePointer) == false)
    {
        return false;
    }

    ImGuiStyle& style = ImGui::GetStyle();
    style.FrameBorderSize = 1.0f;

    if (g_GUIDarkThemeIsEnabled == true)
    {
        ImGui::StyleColorsDark();
    }
    else
    {
        ImGui::StyleColorsLight();
    }

    ////EQAPP_GUI_MapWindow_LoadTextures();

    return true;
}

void EQAPP_GUI_Unload()
{
    g_GUIIsLoaded = false;

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();

    ImGui::DestroyContext();
}

bool EQAPP_GUI_IsMouseOver()
{
    if (g_GUIIsEnabled == false)
    {
        return false;
    }

    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) == false)
    {
        return false;
    }

    return true;
}

signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_GUIIsLoaded == false)
    {
        return 0;
    }

    ImGuiIO& io = ImGui::GetIO();

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        // have to do this to fix a bug when switching windows
        // game would think it was still in the foreground
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

        return 0;
    }

    if (io.WantCaptureMouse == true || (io.WantCaptureKeyboard == true && EQ_IsPlayerMoving() == false))
    {
        if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam))
        {
            return 1;
        }

        return -1;
    }

    return 0;
}

bool EQAPP_GUI_HandleEvent_ProcessMouseEvent()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        EQ_FUNCTION_FlushDxMouse();

        //EQ::MouseState_ptr mouseState = (EQ::MouseState_ptr)EQ_ADDRESS_DirectInputMouseCopy;
        //mouseState->InWindow = 0;

        return true;
    }
    else
    {
        memset(io.MouseDown, 0, sizeof(io.MouseDown));
        io.MouseWheel = 0.0f;

        //EQ::MouseState_ptr mouseState = (EQ::MouseState_ptr)EQ_ADDRESS_DirectInputMouseCopy;
        //mouseState->InWindow = 1;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_ProcessKeyboardEvent()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true || EQ_IsPlayerMoving() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureKeyboard == true)
    {
        EQ_FUNCTION_FlushDxKeyboard();

        return true;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_CXWndManager__DrawCursor()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        return true;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta)
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        return true;
    }

    if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) == true)
    {
        return true;
    }

    return false;
}

void EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    ImGui_ImplDX9_InvalidateDeviceObjects();
}

void EQAPP_GUI_HandleEvent_CRender__ResetDevice_After()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    ImGui_ImplDX9_CreateDeviceObjects();
}

void EQAPP_GUI_NamePlates()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        auto playerSpawnY = EQ_GetSpawnY(playerSpawn);
        auto playerSpawnX = EQ_GetSpawnX(playerSpawn);
        auto playerSpawnZ = EQ_GetSpawnZ(playerSpawn);

        float screenX = -1.0f;
        float screenY = -1.0f;
        bool result = EQ_WorldLocationToScreenLocation(playerSpawnY, playerSpawnX, playerSpawnZ, screenX, screenY);
        if (result == true)
        {
            ImGuiWindowFlags windowFlags =
                ImGuiWindowFlags_AlwaysAutoResize |
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_NoBackground |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoScrollWithMouse |
                ImGuiWindowFlags_NoSavedSettings |
                ImGuiWindowFlags_NoInputs;

            ImGui::SetNextWindowPos(ImVec2(screenX - 50.0f, screenY));

            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

            bool visible = true;

            ImGui::Begin("", &visible, windowFlags);

            ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(255.0f, 0.0f, 0.0f, 255.0f));
            ImGui::ProgressBar(50.0f, ImVec2(100, 0), "HP");
            ImGui::PopStyleColor();

            ImGui::End();

            ImGui::PopStyleVar(3);

            ImGui::End();
        }
    }
}

void EQAPP_GUI_HandleEvent_CRender__UpdateDisplay()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    if (EQ_IsWindowInBackground() == true)
    {
        return;
    }

    g_GUIIsRendered = false;

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    EQAPP_GUI_DockWindow();

    if (g_GUIDemoWindowIsEnabled == true)
    {
        ImGui::ShowDemoWindow(&g_GUIDemoWindowIsEnabled);
    }

    EQAPP_GUI_MainWindow();

    if (g_GUIMapWindowIsEnabled == true)
    {
        EQAPP_GUI_MapWindow();
    }

    if (g_GUIWaypointEditorWindowIsEnabled == true)
    {
        EQAPP_GUI_WaypointEditorWindow();
    }
    else
    {
        if (g_GUIWaypointEditorWindowWasOpened == true)
        {
            g_WaypointEditorIsEnabled = false;

            g_GUIWaypointEditorWindowWasOpened = false;
        }
    }

    if (g_GUITransmogWindowIsEnabled == true)
    {
        EQAPP_GUI_TransmogWindow();
    }

    ImGui::EndFrame();

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    g_GUIIsRendered = true;
}


