#pragma once

extern void EQAPP_InterpretCommand_PrintList();

extern bool g_GUIMapWindowIsEnabled;

extern bool g_GUIWaypointEditorWindowIsEnabled;
extern bool g_GUIWaypointEditorWindowWasOpened;

extern bool g_GUITransmogWindowIsEnabled;

bool g_GUIMainWindowIsEnabled = false;

bool g_GUIMainWindowPopupMenuClientsIsOpen = false;

bool g_GUIMainWIndowPopupModalUnloadIsOpen = false;

float g_GUIMainWindowX = 0.0f;
float g_GUIMainWindowY = 0.0f;

float g_GUIMainWindowAlphaActive = 0.8f;
float g_GUIMainWindowAlphaInactive = 0.8f;

static void EQAPP_GUI_MainWindow();
static void EQAPP_GUI_MainWindow_MenuFile();
static void EQAPP_GUI_MainWindow_MenuEdit();
static void EQAPP_GUI_MainWindow_MenuOptions();
static void EQAPP_GUI_MainWindow_MenuCheats();
static void EQAPP_GUI_MainWindow_MenuWaypoints();
static void EQAPP_GUI_MainWindow_MenuClients();
static void EQAPP_GUI_MainWindow_PopupMenuClients();
static void EQAPP_GUI_MainWindow_MenuWindows();
static void EQAPP_GUI_MainWindow_MenuGUI();
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

    if (ImGui::Begin("EQApp##MainWindow", &g_GUIMainWindowIsEnabled, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoInputs) == false)
    {
        ImGui::End();
        return;
    }

    g_GUIMainWIndowPopupModalUnloadIsOpen = false;

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File##MainWindowMenuFile"))
        {
            EQAPP_GUI_MainWindow_MenuFile();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit##MainWindowMenuEdit"))
        {
            EQAPP_GUI_MainWindow_MenuEdit();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Options##MainWindowMenuOptions"))
        {
            EQAPP_GUI_MainWindow_MenuOptions();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Cheats##MainWindowMenuCheats"))
        {
            EQAPP_GUI_MainWindow_MenuCheats();

            ImGui::EndMenu();
        }

        if (g_WaypointIsEnabled == true)
        {
            if (ImGui::BeginMenu("Waypoints##MainWindowMenuWaypoints"))
            {
                EQAPP_GUI_MainWindow_MenuWaypoints();

                ImGui::EndMenu();
            }
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

        if (ImGui::BeginMenu("GUI##MainWindowMenuGUI"))
        {
            EQAPP_GUI_MainWindow_MenuGUI();

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Help##MainWindowMenuHelp"))
        {
            EQAPP_GUI_MainWindow_MenuHelp();

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    if (g_GUIMainWIndowPopupModalUnloadIsOpen == true)
    {
        ImGui::OpenPopup("Unload##MainWindowPopupModalUnload");
    }

    if (ImGui::BeginPopupModal("Unload##MainWindowPopupModalUnload", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Text("Are you sure you want to unload?");

        ImGui::Separator();

        if (ImGui::Button("Yes", ImVec2(120.0f, 0)))
        {
            ImGui::CloseCurrentPopup();

            EQAPP_Unload();
        }

        ImGui::SetItemDefaultFocus();

        ImGui::SameLine();

        if (ImGui::Button("No", ImVec2(120.0f, 0)))
        {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }

    ImGui::End();

    ImGui::PopStyleVar();
}

static void EQAPP_GUI_MainWindow_MenuFile()
{
    ////if (ImGui::MenuItem("Load Scripts##MainWindowMenuItemFileLoadScripts")) { EQAPP_Lua_LoadAndPrintAllScripts(); }
    if (ImGui::MenuItem("Load Files##MainWindowMenuItemFileLoadFiles")) { EQAPP_LoadFiles(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Unload##MainWindowMenuItemFileUnload"))
    {
        g_GUIMainWIndowPopupModalUnloadIsOpen = true;
    }
}

static void EQAPP_GUI_MainWindow_MenuEdit()
{
    if (ImGui::MenuItem("Bazaar Bot##MainWindowMenuItemEditBazaarBot"))
    {
        EQAPP_OpenFileWithNotepad("bazaarbot.txt");
    }
}

static void EQAPP_GUI_MainWindow_MenuOptions()
{
    if (ImGui::MenuItem("Always Attack##MainWindowMenuItemOptionsAlwaysAttack", NULL, g_AlwaysAttackIsEnabled)) { EQAPP_AlwaysAttack_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("ESP##MainWindowMenuItemOptionsESP", NULL, g_ESPIsEnabled)) { EQAPP_ESP_Toggle(); }
    if (ImGui::MenuItem("ESP Height Filter##MainWindowMenuItemOptionsESPHeightFilter", NULL, g_ESPHeightFilterIsEnabled)) { EQAPP_ESP_HeightFilter_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Free Camera##MainWindowMenuItemOptionsFreeCamera", NULL, g_FreeCameraIsEnabled)) { EQAPP_FreeCamera_Toggle(); }
}

static void EQAPP_GUI_MainWindow_MenuCheats()
{
    if (ImGui::MenuItem("Fly##MainWindowMenuItemCheatsFly", NULL, g_CheatFlyIsEnabled)) { EQAPP_Cheat_Fly_Toggle(); }
    if (ImGui::MenuItem("Levitate##MainWindowMenuItemCheatsLevitate", NULL, g_CheatLevitateIsEnabled)) { EQAPP_Cheat_Levitate_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Always Breathe Underwater##MainWindowMenuItemCheatsAlwaysBreatheUnderwater", NULL, g_CheatAlwaysBreatheUnderwaterIsEnabled)) { EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle(); }
    if (ImGui::MenuItem("Always Run Fast##MainWindowMenuItemCheatsAlwaysRunFast", NULL, g_CheatAlwaysRunFastIsEnabled)) { EQAPP_Cheat_AlwaysRunFast_Toggle(); }
    if (ImGui::MenuItem("Always Have Ultravision##MainWindowMenuItemCheatsAlwaysHaveUltravision", NULL, g_CheatAlwaysHaveUltravisionIsEnabled)) { EQAPP_Cheat_AlwaysHaveUltravision_Toggle(); }
    if (ImGui::MenuItem("Always See Invisible##MainWindowMenuItemCheatsAlwaysSeeInvisible", NULL, g_CheatAlwaysSeeInvisibleIsEnabled)) { EQAPP_Cheat_AlwaysSeeInvisible_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Never Blind##MainWindowMenuItemCheatsNeverBlind", NULL, g_CheatNeverBlindIsEnabled)) { EQAPP_Cheat_NeverBlind_Toggle(); }
    if (ImGui::MenuItem("Never Encumbered##MainWindowMenuItemCheatsNeverEncumbered", NULL, g_CheatNeverEncumberedIsEnabled)) { EQAPP_Cheat_NeverEncumbered_Toggle(); }
    if (ImGui::MenuItem("Never Rooted##MainWindowMenuItemCheatsNeverRooted", NULL, g_CheatNeverRootedIsEnabled)) { EQAPP_Cheat_NeverRooted_Toggle(); }
    if (ImGui::MenuItem("Never Slide (ice and slime)##MainWindowMenuItemCheatsNeverSlide", NULL, g_CheatNeverSlideIsEnabled)) { EQAPP_Cheat_NeverSlide_Toggle(); }
    if (ImGui::MenuItem("Never Snared##MainWindowMenuItemCheatsNeverSnared", NULL, g_CheatNeverSnaredIsEnabled)) { EQAPP_Cheat_NeverSnared_Toggle(); }
    if (ImGui::MenuItem("Never Stunned##MainWindowMenuItemCheatsNeverStunned", NULL, g_CheatNeverStunnedIsEnabled)) { EQAPP_Cheat_NeverStunned_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("No Environmental Damage##MainWindowMenuItemCheatsNoEnvironmentalDamage", NULL, g_CheatNoEnvironmentalDamageIsEnabled)) { EQAPP_Cheat_NoEnvironmentalDamage_Toggle(); }
    if (ImGui::MenuItem("No Fall Damage##MainWindowMenuItemCheatsNoFallDamage", NULL, g_CheatNoFallDamageIsEnabled)) { EQAPP_Cheat_NoFallDamage_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Memorize Spells Instantly##MainWindowMenuItemCheatsMemorizeSpellsInstantly", NULL, g_CheatMemorizeSpellsInstantlyIsEnabled)) { EQAPP_Cheat_MemorizeSpellsInstantly_Toggle(); }
    if (ImGui::MenuItem("Scribe Spells Instantly##MainWindowMenuItemCheatsScribeSpellsInstantly", NULL, g_CheatScribeSpellsInstantlyIsEnabled)) { EQAPP_Cheat_ScribeSpellsInstantly_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Wall Hack##MainWindowMenuItemCheatsWallHack", NULL, g_CheatWallHackIsEnabled)) { EQAPP_Cheat_WallHack_Toggle(); }

    ImGui::Separator();

    if (ImGui::MenuItem("Speed Hack##MainWindowMenuItemCheatsSpeedHack", NULL, g_SpeedIsEnabled)) { EQAPP_Speed_Toggle(); }
    ImGui::SliderFloat("##MainWindowMenuItemCheatsSpeedHackValue", &g_SpeedMultiplier, 1.0f, 10.0f, "%.1f");
}

static void EQAPP_GUI_MainWindow_MenuWaypoints()
{
    if (ImGui::MenuItem("Editor##MainWindowMenuItemOptionsWaypointsWaypointEditor", NULL, g_WaypointEditorIsEnabled)) { EQAPP_WaypointEditor_Toggle(); }
    if (ImGui::MenuItem("Editor Height Filter##MainWindowMenuItemOptionsWaypointsWaypointEditorHeightFilter", NULL, g_WaypointEditorHeightFilterIsEnabled)) { EQAPP_WaypointEditor_HeightFilter_Toggle(); }
    if (ImGui::MenuItem("Editor Distance Filter##MainWindowMenuItemOptionsWaypointsWaypointEditorDistanceFilter", NULL, g_WaypointEditorDistanceFilterIsEnabled)) { EQAPP_WaypointEditor_DistanceFilter_Toggle(); }

    if (g_WaypointList.empty() == true)
    {
        ImGui::Separator();

        if (ImGui::MenuItem("(none)##MainWindowMenuItemWaypointsNone")) {}
    }
    else if (g_WaypointList.size() <= 20)
    {
        ImGui::Separator();

        for (auto& waypoint : g_WaypointList)
        {
            if (waypoint.Name.empty() == true)
            {
                continue;
            }

            if (EQAPP_String_BeginsWith(waypoint.Name, "Waypoint") == true)
            {
                continue;
            }

            std::stringstream menuItemLabel;
            menuItemLabel << waypoint.Name << "##MainWindowMenuItemWaypoints" << waypoint.Name << waypoint.Index;

            if (ImGui::MenuItem(menuItemLabel.str().c_str()))
            {
                EQAPP_Waypoint_GotoByName(waypoint.Name.c_str());
            }
        }
    }
    else
    {
        ImGui::Separator();

        ImGui::BeginChild("##MainWindowMenuItemWaypointsList", ImVec2(400,600), false);

        auto waypointList = g_WaypointList;

        std::sort
        (
            waypointList.begin(), waypointList.end(),
            [] (const EQApp::Waypoint& a, const EQApp::Waypoint& b) -> bool
            { 
                return a.Name < b.Name;
            }
        );

        for (auto& waypoint : waypointList)
        {
            if (waypoint.Name.empty() == true)
            {
                continue;
            }

            if (EQAPP_String_BeginsWith(waypoint.Name, "Waypoint") == true)
            {
                continue;
            }

            std::stringstream menuItemLabel;
            menuItemLabel << waypoint.Name;

            if (waypoint.TagList.empty() == false)
            {
                menuItemLabel << " (";

                for (auto& tagName : waypoint.TagList)
                {
                    menuItemLabel << tagName;

                    if (tagName != waypoint.TagList.back())
                    {
                        menuItemLabel << ",";
                    }
                }

                menuItemLabel << ")";
            }

            menuItemLabel << "##MainWindowMenuItemWaypoints" << waypoint.Index;

            if (ImGui::Selectable(menuItemLabel.str().c_str(), false))
            {
                EQAPP_Waypoint_GotoByName(waypoint.Name.c_str());

                ImGui::CloseCurrentPopup();
            }

            ImGui::SameLine(ImGui::GetWindowContentRegionMax().x - 20.0f);

            ImGui::Text("%d", waypoint.Index);
        }

        ImGui::EndChild();
    }
}

static void EQAPP_GUI_MainWindow_MenuClients()
{
    if (EQAPP_UpdateClientWindowList() == false)
    {
        ImGui::MenuItem("(none)##MainWindowMenuItemClientsNone");
        return;
    }

    size_t windowIndex = 0;

    for (auto& [clientWindowTitle, clientWindowHWND] : g_EQAppClientWindowList)
    {
        if (clientWindowHWND == NULL)
        {
            continue;
        }

        if (clientWindowTitle.empty() == true)
        {
            continue;
        }

        std::stringstream menuItemText;
        menuItemText << clientWindowTitle << "##MainWindowMenuItemClients" << windowIndex;

        windowIndex++;

        if (ImGui::MenuItem(menuItemText.str().c_str()))
        {
            ShowWindow(clientWindowHWND, SW_SHOW);

            if (IsIconic(clientWindowHWND) == TRUE) // is window minimized
            {
                ShowWindow(clientWindowHWND, SW_RESTORE);
            }

            SetForegroundWindow(clientWindowHWND);
            SetFocus(clientWindowHWND);
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

static void EQAPP_GUI_MainWindow_MenuWindows()
{
    if (ImGui::MenuItem("Map##MainWindowMenuItemWindowsMap", NULL, false)) { EQ_ToggleBool(g_GUIMapWindowIsEnabled); }

    if (ImGui::MenuItem("Spawn List##MainWindowMenuItemWindowsSpawnList", NULL, false)) {}

    if (g_WaypointIsEnabled == true)
    {
        if (ImGui::MenuItem("Waypoint Editor##MainWindowMenuWaypointEditor"))
        {
            g_GUIWaypointEditorWindowIsEnabled = true;

            g_GUIWaypointEditorWindowWasOpened = true;

            g_WaypointEditorIsEnabled = true;
        }
    }

    if (ImGui::MenuItem("Transmog##MainWindowMenuItemWindowsTransmog", NULL, false)) { EQ_ToggleBool(g_GUITransmogWindowIsEnabled); }
}

static void EQAPP_GUI_MainWindow_MenuGUI()
{
    if (ImGui::MenuItem("Dark Theme##MainWindowMenuItemGUIDarkTheme"))
    {
        ImGui::StyleColorsDark();

        g_GUIDarkThemeIsEnabled = true;
    }

    if (ImGui::MenuItem("Light Theme##MainWindowMenuItemGUILightTheme"))
    {
        ImGui::StyleColorsLight();

        g_GUIDarkThemeIsEnabled = false;
    }

    ImGui::Separator();

    if (ImGui::MenuItem("Show Demo Window##MainWindowMenuItemGUIShowDemoWindow", NULL, &g_GUIDemoWindowIsEnabled)) {}
}

static int MyResizeCallback(ImGuiInputTextCallbackData* data)
{
    if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
    {
        ImVector<char>* my_str = (ImVector<char>*)data->UserData;
        IM_ASSERT(my_str->begin() == data->Buf);
        my_str->resize(data->BufSize);  // NB: On resizing calls, generally data->BufSize == data->BufTextLen + 1
        data->Buf = my_str->begin();
    }
    return 0;
}

static void EQAPP_GUI_MainWindow_MenuHelp()
{
    if (ImGui::MenuItem("Commands##MainWindowMenuItemHelpCommands")) { EQAPP_InterpretCommand_PrintList(); }

    ImGui::Separator();

    if (ImGui::MenuItem("About##MainWindowMenuItemHelpAbout")) {};

    //ImGui::Separator();

    //std::string asdf = EQAPP_ReadFileToString("bazaarbot.txt");

    //ImGui::InputTextMultiline("asdfasdfasdf", &asdf);
}
