#pragma once

bool g_LanternIsEnabled = true;

EQApp::Timer g_LanternTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LanternTimerInterval = 1;

uint32_t g_LanternLight = NULL;

void EQAPP_Lantern_Toggle();
void EQAPP_Lantern_On();
void EQAPP_Lantern_Off();
void EQAPP_Lantern_Execute();

void EQAPP_Lantern_Toggle()
{
    EQ_ToggleBool(g_LanternIsEnabled);
    EQAPP_PrintBool("Lantern", g_LanternIsEnabled);
}

void EQAPP_Lantern_On()
{
    if (g_LanternIsEnabled == false)
    {
        EQAPP_Lantern_Toggle();
    }
}

void EQAPP_Lantern_Off()
{
    if (g_LanternIsEnabled == true)
    {
        EQAPP_Lantern_Toggle();
    }
}

void EQAPP_Lantern_Execute()
{
    if (EQAPP_Timer_HasTimeElapsed(g_LanternTimer, g_LanternTimerInterval) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (EQ_GetSpawnLightInterface(playerSpawn) == NULL)
    {
        float playerY = EQ_GetSpawnY(playerSpawn);
        float playerX = EQ_GetSpawnX(playerSpawn);
        float playerZ = EQ_GetSpawnZ(playerSpawn);

        g_LanternLight = EQ_CLASS_POINTER_CDisplay->CreateLight(EQ_LIGHT_TYPE_GLOOMING_DEEP_LANTERN, 0.0f, playerY, playerX, playerZ + 4.0f);

        EQ_SetPlayerLightInterface(g_LanternLight);
    }
}
