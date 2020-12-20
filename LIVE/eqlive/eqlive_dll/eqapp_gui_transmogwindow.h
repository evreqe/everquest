#pragma once

bool g_GUITransmogWindowIsEnabled = false;

bool g_GUITransmogWindowWasOpened = false;

float g_GUITransmogWindowX = 0.0f;
float g_GUITransmogWindowY = 0.0f;

float g_GUITransmogWindowAlphaActive = 1.0f;
float g_GUITransmogWindowAlphaInactive = 0.8f;

int g_GUITransmogWindowUpdateItemSlotPrimaryID = 0;
int g_GUITransmogWindowUpdateItemSlotSecondaryID = 0;

static void EQAPP_GUI_TransmogWindow();

static void EQAPP_GUI_TransmogWindow()
{
    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true || io.WantCaptureKeyboard == true)
    {
       ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUITransmogWindowAlphaActive);
    }
    else
    {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, g_GUITransmogWindowAlphaInactive);
    }

    ImGui::SetNextWindowPos(ImVec2(g_GUITransmogWindowX, g_GUITransmogWindowY), ImGuiCond_Once);

    if (ImGui::Begin("Transmog##TransmogWindow", &g_GUITransmogWindowIsEnabled, ImGuiWindowFlags_AlwaysAutoResize) == false)
    {
        ImGui::End();
        return;
    }

    if (ImGui::InputInt("Primary##TransmogWindowPrimaryID", &g_GUITransmogWindowUpdateItemSlotPrimaryID))
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnItemSlotPrimary(playerSpawn, g_GUITransmogWindowUpdateItemSlotPrimaryID);
        }
    }

    if (ImGui::InputInt("Secondary##TransmogWindowSecondaryID", &g_GUITransmogWindowUpdateItemSlotSecondaryID))
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnItemSlotSecondary(playerSpawn, g_GUITransmogWindowUpdateItemSlotSecondaryID);
        }
    }

    ImGui::Separator();

    if (ImGui::Button("Reset"))
    {
        g_GUITransmogWindowUpdateItemSlotPrimaryID = 0;
        g_GUITransmogWindowUpdateItemSlotSecondaryID = 0;

        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            EQ_SetSpawnItemSlotPrimary(playerSpawn, 0);
            EQ_SetSpawnItemSlotSecondary(playerSpawn, 0);
        }
    }

    ImGui::End();

    ImGui::PopStyleVar();
}
