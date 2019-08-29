#pragma once

bool g_NameColorIsEnabled = true;

EQApp::Timer g_NameColorTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_NameColorTimerInterval = 100;

bool g_NameColorFlicker = false;

uint32_t g_NameColorFlickerColorARGB = 0xFFFFFFFF; // white

uint32_t g_NameColorPlayerColorARGB = 0xFFFF8000; // orange

void EQAPP_NameColor_Toggle();
void EQAPP_NameColor_On();
void EQAPP_NameColor_Off();
void EQAPP_NameColor_Execute();
bool EQAPP_NameColor_HandleEvent_EQPlayer__SetNameSpriteTint(void* this_ptr);

void EQAPP_NameColor_Toggle()
{
    EQ_ToggleBool(g_NameColorIsEnabled);
    EQAPP_PrintBool("Name Color", g_NameColorIsEnabled);
}

void EQAPP_NameColor_On()
{
    if (g_NameColorIsEnabled == false)
    {
        EQAPP_NameColor_Toggle();
    }
}

void EQAPP_NameColor_Off()
{
    if (g_NameColorIsEnabled == true)
    {
        EQAPP_NameColor_Toggle();
    }
}

void EQAPP_NameColor_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInMilliseconds(g_NameColorTimer, g_NameColorTimerInterval) == true)
    {
        EQ_ToggleBool(g_NameColorFlicker);
    }
}

bool EQAPP_NameColor_HandleEvent_EQPlayer__SetNameSpriteTint(void* this_ptr)
{
    bool spawnIsTarget = false;

    auto targetSpawn = EQ_GetTargetSpawn();
    if ((uint32_t)this_ptr == targetSpawn)
    {
        spawnIsTarget = true;
    }

    bool spawnNameColorWasSet = false;

    auto playerSpawn = EQ_GetPlayerSpawn();
    if ((uint32_t)this_ptr == playerSpawn)
    {
        EQ_SetSpawnNameColor(playerSpawn, g_NameColorPlayerColorARGB);

        spawnNameColorWasSet = true;
    }

    if (spawnIsTarget == true && spawnNameColorWasSet == true)
    {
        if (g_NameColorFlicker == true)
        {
            EQ_SetSpawnNameColor(playerSpawn, g_NameColorFlickerColorARGB);
        }
    }

    return false;
}
