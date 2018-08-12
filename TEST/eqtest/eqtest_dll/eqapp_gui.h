#pragma once

#include "imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern void EQAPP_InterpretCommand_PrintList();

bool g_GUIIsEnabled = true;

bool g_GUIIsLoaded = false;

ImFont* customFont = NULL;

bool g_GUIWindowMainIsEnabled = false;

void EQAPP_GUI_Toggle();
void EQAPP_GUI_On();
void EQAPP_GUI_Off();
bool EQAPP_GUI_Load();
void EQAPP_GUI_Unload();
signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool EQAPP_GUI_HandleEvent_ProcessMouseEvent();
bool EQAPP_GUI_HandleEvent_ProcessKeyboardEvent();
bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta);
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before();
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_After();
void EQAPP_GUI_HandleEvent_CRender__UpdateDisplay();;
static void EQAPP_GUI_Window_Main();
static void EQAPP_GUI_Window_Main_MenuClients();

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

    std::stringstream fontFilePath;
    fontFilePath << g_EQAppName << "/fonts/battlenet.ttf";
    customFont = io.Fonts->AddFontFromFileTTF(fontFilePath.str().c_str(), 14.0f);

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

    ImGui::StyleColorsDark();
    ////ImGui::StyleColorsClassic();

    return true;
}

void EQAPP_GUI_Unload()
{
    g_GUIIsLoaded = false;

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();

    ImGui::DestroyContext();
}

signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_GUIIsLoaded == false)
    {
        return 0;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

        return 0;
    }

    ImGuiIO& io = ImGui::GetIO();
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
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

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
        io.MouseWheel = 0;

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
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

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

bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta)
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
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

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ////bool show_demo_window = true;
    ////ImGui::ShowDemoWindow(&show_demo_window);

    EQAPP_GUI_Window_Main();

    ImGui::EndFrame();

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

static void EQAPP_GUI_Window_Main()
{
    if (ImGui::Begin("EQTEST##WindowMain", &g_GUIWindowMainIsEnabled, ImGuiWindowFlags_MenuBar) == false)
    {
        ImGui::End();
        return;
    }

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File##MenuFile"))
        {
            if (ImGui::MenuItem("Load Scripts##MenuItemFileLoadScripts")) EQAPP_Lua_LoadAndPrintAllScripts();
            if (ImGui::MenuItem("Load Waypoints##MenuItemFileLoadWaypoints")) EQAPP_WaypointList_Load();

            ImGui::Separator();

            if (ImGui::MenuItem("Unload##MenuItemFileUnload")) EQAPP_Unload();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options##MenuOptions"))
        {
            if (ImGui::MenuItem("Always Attack##MenuItemOptionsAlwaysAttack", NULL, &g_AlwaysAttackIsEnabled)) {}

            ImGui::Separator();

            if (ImGui::MenuItem("ESP##MenuItemOptionsESP", NULL, &g_ESPIsEnabled)) {}
            if (ImGui::MenuItem("ESP Height Filter##MenuItemOptionsESPHeightFilter", NULL, &g_ESPHeightFilterIsEnabled)) {}

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Windows##MenuWindows"))
        {
            if (ImGui::MenuItem("Map##MenuItemWindowsMap", NULL, false)) {}

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Clients##MenuClients"))
        {
            EQAPP_GUI_Window_Main_MenuClients();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help##MenuHelp"))
        {
            if (ImGui::MenuItem("Commands##MenuItemHelpCommands")) EQAPP_InterpretCommand_PrintList();

            ImGui::Separator();

            if (ImGui::MenuItem("About##MenuItemHelpAbout")) {};

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    // TODO: chat log and input

    ImGui::End();
}

static void EQAPP_GUI_Window_Main_MenuClients()
{
    if (EQAPP_UpdateClientWindowList() == false)
    {
        ImGui::MenuItem("(none)##MenuItemClientsNone");
        return;
    }

    size_t windowIndex = 0;

    for (auto& clientWindow : g_EQAppClientWindowList)
    {
        if (clientWindow.second == NULL)
        {
            continue;
        }

        if (clientWindow.first.size() == 0)
        {
            continue;
        }

        std::stringstream menuItemText;
        menuItemText << clientWindow.first << "##MenuItemClients" << windowIndex;

        windowIndex++;

        if (ImGui::MenuItem(menuItemText.str().c_str()))
        {
            SetForegroundWindow(clientWindow.second);
            SetFocus(clientWindow.second);
        }
    }
}
