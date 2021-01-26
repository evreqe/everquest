#pragma once

bool g_PowerLevelIsEnabled = false;

EQApp::Timer g_PowerLevelTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_PowerLevelTimerInterval = 1;

uint32_t g_PowerLevelHPPercentDefault = 50;

uint32_t g_PowerLevelHPPercent = 50;

float g_PowerLevelDistance = 100.0f;

std::vector<std::string> g_PowerLevelNames;

void EQAPP_PowerLevel_Toggle();
void EQAPP_PowerLevel_On();
void EQAPP_PowerLevel_Off();
void EQAPP_PowerLevel_Execute();
void EQAPP_PowerLevel_SetHPPercent(uint32_t hpPercent);

void EQAPP_PowerLevel_Toggle()
{
    EQ_ToggleBool(g_PowerLevelIsEnabled);
    EQAPP_PrintBool("Power Level", g_PowerLevelIsEnabled);
}

void EQAPP_PowerLevel_On()
{
    if (g_PowerLevelIsEnabled == false)
    {
        EQAPP_PowerLevel_Toggle();
    }
}

void EQAPP_PowerLevel_Off()
{
    if (g_PowerLevelIsEnabled == true)
    {
        EQAPP_PowerLevel_Toggle();
    }
}

void EQAPP_PowerLevel_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInSeconds(g_PowerLevelTimer, g_PowerLevelTimerInterval) == false)
    {
        return;
    }

    if (EQ_IsAutoAttackEnabled() == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetType = EQ_GetSpawnType(targetSpawn);
    if (targetType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    float targetDistance = EQ_GetSpawnDistance(targetSpawn);
    if (targetDistance > g_PowerLevelDistance)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    auto targetHPPercent = EQ_GetSpawnHPPercent(targetSpawn);
    if (targetHPPercent < g_PowerLevelHPPercent)
    {
        for (auto& name : g_PowerLevelNames)
        {
            std::string commandText = fmt::format("//BCT {} //TargetID {TargetID};//Stand;//Follow;//AutoAttackOn", name);

            EQ_InterpretCommand(commandText.c_str());
        }
    }
}

void EQAPP_PowerLevel_SetHPPercent(uint32_t hpPercent)
{
    if (hpPercent <= 0 || hpPercent > 100)
    {
        g_PowerLevelHPPercent = g_PowerLevelHPPercentDefault;
        return;
    }

    g_PowerLevelHPPercent = hpPercent;
}


