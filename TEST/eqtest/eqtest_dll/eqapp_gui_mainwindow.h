#pragma once

bool g_GUIMainWindowIsEnabled = false;

bool g_GUIMainWindowPopupMenuClientsIsOpen = false;

float g_GUIMainWindowX = 0.0f;
float g_GUIMainWindowY = 0.0f;

float g_GUIMainWindowAlphaActive = 0.8f;
float g_GUIMainWindowAlphaInactive = 0.8f;

static void EQAPP_GUI_MainWindow();
static void EQAPP_GUI_MainWindow_MenuFile();
static void EQAPP_GUI_MainWindow_MenuOptions();
static void EQAPP_GUI_MainWindow_MenuWindows();
static void EQAPP_GUI_MainWindow_MenuClients();
static void EQAPP_GUI_MainWindow_PopupMenuClients();
static void EQAPP_GUI_MainWindow_MenuWaypoints();
static void EQAPP_GUI_MainWindow_MenuHelp();

static void EQAPP_GUI_MainWindow()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true || io.WantCaptureKeyboard == true)
    {
       ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMainWindowAlphaActive);
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIMainWindowAlphaInactive);
    }

    EQAPP_GUI_MainWindow_PopupMenuClients();

    ImGui::SetNextWindowPos(ImVec2(g_GUIMainWindowX, g_GUIMainWindowY), ImGuiCond_Once);

    if (ImGui::Begin("EQTEST##MainWindow", &g_GUIMainWindowIsEnabled, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize) == false)
    {
        ImGui::End();
        return;
    }

    if (ImGui::Button("EQTEST"))
    {
        ImGui::OpenPopup("Clients##MainWindowMenu");
    }

    if (ImGui::BeginPopup("Clients##MainWindowMenu"))
    {
        if (ImGui::BeginMenu("File##MainWindowMenuFile"))
        {
            EQAPP_GUI_MainWindow_MenuFile();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options##MainWindowMenuOptions"))
        {
            EQAPP_GUI_MainWindow_MenuOptions();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Windows##MainWindowMenuWindows"))
        {
            EQAPP_GUI_MainWindow_MenuWindows();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Clients##MainWindowMenuClients"))
        {
            EQAPP_GUI_MainWindow_MenuClients();

            ImGui::EndMenu();
        }

        if (g_WaypointEditorIsEnabled == true)
        {
            if (ImGui::BeginMenu("Waypoints##MainWindowMenuWaypoints"))
            {
                EQAPP_GUI_MainWindow_MenuWaypoints();

                ImGui::EndMenu();
            }
        }

        if (ImGui::BeginMenu("Help##MenuHelp"))
        {
            EQAPP_GUI_MainWindow_MenuHelp();

            ImGui::EndMenu();
        }

        ImGui::EndPopup();
    }

    ImGui::End();

    ImGui::PopStyleVar();
}

static void EQAPP_GUI_MainWindow_MenuFile()
{
    if (ImGui::MenuItem("Load Scripts##MainWindowMenuItemFileLoadScripts")) EQAPP_Lua_LoadAndPrintAllScripts();
    if (ImGui::MenuItem("Load Waypoints##MainWindowMenuItemFileLoadWaypoints")) EQAPP_WaypointList_Load();

    ImGui::Separator();

    if (ImGui::MenuItem("Unload##MainWindowMenuItemFileUnload")) EQAPP_Unload();
}

static void EQAPP_GUI_MainWindow_MenuOptions()
{
    if (ImGui::MenuItem("Always Attack##MainWindowMenuItemOptionsAlwaysAttack", NULL, &g_AlwaysAttackIsEnabled)) {}

    ImGui::Separator();

    if (ImGui::MenuItem("ESP##MainWindowMenuItemOptionsESP", NULL, &g_ESPIsEnabled)) {}
    if (ImGui::MenuItem("ESP Height Filter##MainWindowMenuItemOptionsESPHeightFilter", NULL, &g_ESPHeightFilterIsEnabled)) {}
}

static void EQAPP_GUI_MainWindow_MenuWindows()
{
    if (ImGui::MenuItem("Map##MainWindowMenuItemWindowsMap", NULL, false)) {}
    if (ImGui::MenuItem("Spawn List##MainWindowMenuItemWindowsSpawnList", NULL, false)) {}
}

static void EQAPP_GUI_MainWindow_MenuClients()
{
    if (EQAPP_UpdateClientWindowList() == false)
    {
        ImGui::MenuItem("(none)##MainWindowMenuItemClientsNone");
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
        menuItemText << clientWindow.first << "##MainWindowMenuItemClients" << windowIndex;

        windowIndex++;

        if (ImGui::MenuItem(menuItemText.str().c_str()))
        {
            ShowWindow(clientWindow.second, SW_SHOW);

            if (IsIconic(clientWindow.second) == TRUE) // is window minimized
            {
                ShowWindow(clientWindow.second, SW_RESTORE);
            }

            SetForegroundWindow(clientWindow.second);
            SetFocus(clientWindow.second);
        }
    }
}

static void EQAPP_GUI_MainWindow_PopupMenuClients()
{
    if (g_GUIMainWindowPopupMenuClientsIsOpen == true)
    {
        ImGui::OpenPopup("Clients##MainWindowPopupMenuClients");

        g_GUIMainWindowPopupMenuClientsIsOpen = false;
    }

    if (ImGui::BeginPopup("Clients##MainWindowPopupMenuClients"))
    {
        EQAPP_GUI_MainWindow_MenuClients();
        ImGui::EndPopup();
    }
}

static void EQAPP_GUI_MainWindow_MenuWaypoints()
{
    if (ImGui::MenuItem("Connect##MainWindowMenuItemWaypointsConnect")) EQAPP_WaypointEditor_Command_Connect();
    if (ImGui::MenuItem("Disconnect##MainWindowMenuItemWaypointsDisconnect")) EQAPP_WaypointEditor_Command_Disconnect();
}

static void EQAPP_GUI_MainWindow_MenuHelp()
{
    if (ImGui::MenuItem("Commands##MainWindowMenuItemHelpCommands")) EQAPP_InterpretCommand_PrintList();

    ImGui::Separator();

    if (ImGui::MenuItem("About##MainWindowMenuItemHelpAbout")) {};
}
