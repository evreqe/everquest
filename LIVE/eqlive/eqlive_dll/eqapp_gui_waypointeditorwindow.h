#pragma once

bool g_GUIWaypointEditorWindowIsEnabled = false;

bool g_GUIWaypointEditorWindowWasOpened = false;

float g_GUIWaypointEditorWindowX = 0.0f;
float g_GUIWaypointEditorWindowY = 0.0f;

float g_GUIWaypointEditorWindowAlphaActive = 1.0f;
float g_GUIWaypointEditorWindowAlphaInactive = 0.8f;

uint32_t g_GUIWaypointEditorWindowFlagSelectedIndex = 0;
uint32_t g_GUIWaypointEditorWindowFlagSelectedFlag = EQApp::WaypointFlagNull;
std::string g_GUIWaypointEditorWindowFlagSelectedName = "Select a flag...";

static void EQAPP_GUI_WaypointEditorWindow();

static void EQAPP_GUI_WaypointEditorWindow()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true || io.WantCaptureKeyboard == true)
    {
       ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIWaypointEditorWindowAlphaActive);
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUIWaypointEditorWindowAlphaInactive);
    }

    ImGui::SetNextWindowPos(ImVec2(g_GUIWaypointEditorWindowX, g_GUIWaypointEditorWindowY), ImGuiCond_Once);

    if (ImGui::Begin("Waypoint Editor##WaypointEditorWindow", &g_GUIWaypointEditorWindowIsEnabled, ImGuiWindowFlags_AlwaysAutoResize) == false)
    {
        ImGui::End();
        return;
    }

    static auto firstTime = true;
    if (firstTime)
    {
        firstTime = false;

        auto dockspaceLeftID = ImGui::DockBuilderSplitNode(g_GUIDockWindowDockSpaceID, ImGuiDir_Left, 0.25f, nullptr, &g_GUIDockWindowDockSpaceID);

        ImGui::DockBuilderDockWindow("Waypoint Editor##WaypointEditorWindow", dockspaceLeftID);
        ImGui::DockBuilderFinish(g_GUIDockWindowDockSpaceID);
    }

    if (g_WaypointEditorFromIndex == EQApp::WaypointIndexNull)
    {
        ImGui::Text("Waypoint A is not selected.", g_WaypointEditorFromIndex);
    }
    else
    {
        ImGui::Text("Waypoint A: %d", g_WaypointEditorFromIndex);
    }

    if (g_WaypointEditorToIndex == EQApp::WaypointIndexNull)
    {
        ImGui::Text("Waypoint B is not selected.", g_WaypointEditorToIndex);
    }
    else
    {
        ImGui::Text("Waypoint B: %d", g_WaypointEditorToIndex);
    }

    ImGui::Separator();

    ImGui::Columns(2, "mixed", true);

    if (ImGui::Button("Connect##WaypointEditorWindowWaypointConnectButton"))
    {
        EQAPP_WaypointEditor_Command_Connect();
    }

    if (ImGui::Button("Disconnect##WaypointEditorWindowWaypointDisconnectButton"))
    {
        EQAPP_WaypointEditor_Command_Disconnect();
    }

    if (ImGui::Button("Disconnect All##WaypointEditorWindowWaypointDisconnectAllButton"))
    {
        EQAPP_WaypointEditor_Command_DisconnectAll();
    }

    if (ImGui::Button("Add##WaypointEditorWindowWaypointAddButton"))
    {
        EQAPP_WaypointEditor_Command_AddAtPlayer();
    }

    if (ImGui::Button("Add and Connect##WaypointEditorWindowWaypointAddAndConnectButton"))
    {
        EQAPP_WaypointEditor_Command_AddAtPlayerAndConnectToLastAddedIndex();
    }

    if (ImGui::Button("Add between##WaypointEditorWindowWaypointAddBetweenButton"))
    {
        EQAPP_WaypointEditor_Command_AddAtPlayerBetween();
    }

    if (ImGui::Button("Add at Target##WaypointEditorWindowWaypointAddAtTargetButton"))
    {
        EQAPP_WaypointEditor_Command_AddAtTarget();
    }

    if (ImGui::Button("Add at Target between##WaypointEditorWindowWaypointAddAtTargetBetweenButton"))
    {
        EQAPP_WaypointEditor_Command_AddAtTargetBetween();
    }

    if (ImGui::Button("Add behind Target##WaypointEditorWindowWaypointAddBehindTargetButton"))
    {
        EQAPP_WaypointEditor_Command_AddBehindTarget();
    }

    if (ImGui::Button("Remove##WaypointEditorWindowWaypointRemoveButton"))
    {
        EQAPP_WaypointEditor_Command_Remove();
    }

    if (ImGui::Button("Align##WaypointEditorWindowWaypointAlignButton"))
    {
        EQAPP_WaypointEditor_Command_Align();
    }

    if (ImGui::Button("Split##WaypointEditorWindowWaypointSplitButton"))
    {
        EQAPP_WaypointEditor_Command_Split();
    }

    ImGui::NextColumn();

    if (ImGui::Button("Move to Player##WaypointEditorWindowMoveToPlayerButton"))
    {
        EQAPP_WaypointEditor_Command_MoveToPlayer();
    }

    if (ImGui::Button("Move to Target##WaypointEditorWindowMoveToTargetButton"))
    {
        EQAPP_WaypointEditor_Command_MoveToTarget();
    }

    if (g_WaypointEditorFromIndex != NULL)
    {
        auto fromWaypoint = EQAPP_Waypoint_GetByIndex(g_WaypointEditorFromIndex);
        if (fromWaypoint != NULL)
        {
            ImGui::Text(" ");

            ImGui::InputFloat("Y", &fromWaypoint->Y, 1.0f, 5.0f);
            ImGui::InputFloat("X", &fromWaypoint->X, 1.0f, 5.0f);
            ImGui::InputFloat("Z", &fromWaypoint->Z, 1.0f, 5.0f);
        }
    }

    ImGui::Text(" ");

    if (ImGui::Button("NW##WaypointEditorWindowFaceNorthWestButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingNorthWest();
    }

    ImGui::SameLine();

    if (ImGui::Button("N##WaypointEditorWindowFaceNorthButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingNorth();
    }

    ImGui::SameLine();

    if (ImGui::Button("NE##WaypointEditorWindowFaceNorthEastButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingNorthEast();
    }

    if (ImGui::Button("W##WaypointEditorWindowFaceWestButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingWest();
    }

    ImGui::SameLine();

    if (ImGui::Button(" ##WaypointEditorWindowFaceXButton", ImVec2(24,24)))
    {
        //
    }

    ImGui::SameLine();

    if (ImGui::Button("E##WaypointEditorWindowFaceEastButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingEast();
    }

    if (ImGui::Button("SW##WaypointEditorWindowFaceSouthWestButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingSouthWest();
    }

    ImGui::SameLine();

    if (ImGui::Button("S##WaypointEditorWindowFaceSouthButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingSouth();
    }

    ImGui::SameLine();

    if (ImGui::Button("SE##WaypointEditorWindowFaceSouthEastButton", ImVec2(24,24)))
    {
        EQ_SetPlayerSpawnHeadingSouthEast();
    }

    ImGui::Text(" ");

    if (ImGui::Button("Turn Left##WaypointEditorWindowTurnLeftButton"))
    {
        EQ_TurnLeft();
    }

    if (ImGui::Button("Turn Right##WaypointEditorWindowTurnRightButton"))
    {
        EQ_TurnRight();
    }

    if (ImGui::Button("Turn Around##WaypointEditorWindowTurnAroundButton"))
    {
        EQ_TurnAround();
    }

    ImGui::Columns(1);

    if (g_WaypointEditorFromIndex != NULL)
    {
        auto fromWaypoint = EQAPP_Waypoint_GetByIndex(g_WaypointEditorFromIndex);
        if (fromWaypoint != NULL)
        {
            ImGui::Separator();

            ImGui::InputText("Name##WaypointEditorWindowWaypointNameInputText", &fromWaypoint->Name);

            if (ImGui::Button("Reset Name##WaypointEditorWindowResetNameButton"))
            {
                std::stringstream fromWaypointName;
                fromWaypointName << "Waypoint" << fromWaypoint->Index;

                fromWaypoint->Name = fromWaypointName.str();
            }

            ImGui::Separator();

            if (ImGui::BeginCombo("Flags##WaypointEditorWindowFlagCombo", g_GUIWaypointEditorWindowFlagSelectedName.c_str()))
            {
                uint32_t flagIndex = 0;
                for (auto& flagString : EQApp::WaypointFlagsStrings)
                {
                    if (flagString.first == EQApp::WaypointFlagNull)
                    {
                        continue;
                    }

                    std::stringstream flagLabelID;
                    flagLabelID << flagString.second << "##WaypointEditorWindowFlagCombo" << flagString.first;

                    if (ImGui::Selectable(flagLabelID.str().c_str(), flagIndex == g_GUIWaypointEditorWindowFlagSelectedIndex))
                    {
                        g_GUIWaypointEditorWindowFlagSelectedIndex = flagIndex;

                        g_GUIWaypointEditorWindowFlagSelectedFlag = flagString.first;

                        g_GUIWaypointEditorWindowFlagSelectedName = flagString.second;
                    }

                    flagIndex++;
                }

                ImGui::EndCombo();
            }

            if (ImGui::Button("Add Flag"))
            {
                if (g_WaypointEditorFromIndex != NULL)
                {
                    EQAPP_Waypoint_AddFlag(g_WaypointEditorFromIndex, g_GUIWaypointEditorWindowFlagSelectedFlag);
                }
            }

            if (ImGui::Button("Remove Flag"))
            {
                if (g_WaypointEditorFromIndex != NULL)
                {
                    EQAPP_Waypoint_RemoveFlag(g_WaypointEditorFromIndex, g_GUIWaypointEditorWindowFlagSelectedFlag);
                }
            }

            if (ImGui::Button("Clear Flags"))
            {
                if (g_WaypointEditorFromIndex != NULL)
                {
                    EQAPP_Waypoint_ClearFlags(g_WaypointEditorFromIndex);
                }
            }
        }
    }

    ImGui::Separator();

    ImGui::Columns(3, "mixed", false);

    if (ImGui::Button("Undo"))
    {
        EQAPP_Waypoint_Undo();
        EQAPP_WaypointEditor_Command_Reset();
    }

    ImGui::NextColumn();

    if (ImGui::Button("Redo"))
    {
        EQAPP_Waypoint_Redo();
        EQAPP_WaypointEditor_Command_Reset();
    }

    ImGui::Columns(1);

    ImGui::Separator();

    ImGui::Checkbox("Height Filter##WaypointEditorWindowHeightFilterText", &g_WaypointEditorHeightFilterIsEnabled);

    ImGui::DragFloat("Low##WaypointEditorWindowHeightFilterLow", &g_WaypointEditorHeightFilterDistanceLow);
    ImGui::DragFloat("High##WaypointEditorWindowHeightFilterHigh", &g_WaypointEditorHeightFilterDistanceHigh);

    ImGui::Separator();

    ImGui::Checkbox("Distance Filter##WaypointEditorWindowDistanceFilterText", &g_WaypointEditorDistanceFilterIsEnabled);

    ImGui::DragFloat("Distance##WaypointEditorWindowDistanceFilterDistance", &g_WaypointEditorDistanceFilterDistance);

    ImGui::Separator();

    ImGui::Text("------------------------------------------------------------");

    ImGui::Columns(3, "mixed", false);

    if (ImGui::Button("Load"))
    {
        EQAPP_WaypointList_Load();
    }

    ImGui::NextColumn();

    if (ImGui::Button("Save"))
    {
        EQAPP_WaypointList_Save();
    }

    ImGui::Columns(1);

    ImGui::End();

    ImGui::PopStyleVar();
}

