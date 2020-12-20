#pragma once

bool g_SpeedIsEnabled = false;

float g_SpeedMultiplier = 2.0f;

float g_SpeedMultiplierMin = 1.0f;
float g_SpeedMultiplierMax = 100.0f;

void EQAPP_Speed_Toggle();
void EQAPP_Speed_On();
void EQAPP_Speed_Off();
void EQAPP_Speed_Execute();
void EQAPP_Speed_SetAccelerationFriction(float accelerationFriction);
void EQAPP_Speed_SetAccelerationFrictionToDefault();
void EQAPP_Speed_SetAccelerationFrictionByMultiplier(float multiplier);

void EQAPP_Speed_Toggle()
{
    EQ_ToggleBool(g_SpeedIsEnabled);
    EQAPP_PrintBool("Speed", g_SpeedIsEnabled);

    if (g_SpeedIsEnabled == false)
    {
        EQAPP_Speed_SetAccelerationFrictionToDefault();
    }
}

void EQAPP_Speed_On()
{
    if (g_SpeedIsEnabled == false)
    {
        EQAPP_Speed_Toggle();
    }
}

void EQAPP_Speed_Off()
{
    if (g_SpeedIsEnabled == true)
    {
        EQAPP_Speed_Toggle();
    }
}

void EQAPP_Speed_Execute()
{
    if (g_SpeedMultiplier < g_SpeedMultiplierMin)
    {
        g_SpeedMultiplier = g_SpeedMultiplierMin;
    }

    if (g_SpeedMultiplier > g_SpeedMultiplierMax)
    {
        g_SpeedMultiplier = g_SpeedMultiplierMax;
    }

    EQAPP_Speed_SetAccelerationFrictionByMultiplier(g_SpeedMultiplier);
}

void EQAPP_Speed_SetAccelerationFriction(float accelerationFriction)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    EQ_WriteMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_ACCELERATION_FRICTION, accelerationFriction);
}

void EQAPP_Speed_SetAccelerationFrictionToDefault()
{
    EQAPP_Speed_SetAccelerationFriction(EQ_SPAWN_ACCELERATION_FRICTION_DEFAULT);
}

void EQAPP_Speed_SetAccelerationFrictionByMultiplier(float multiplier)
{
    EQAPP_Speed_SetAccelerationFriction(EQ_SPAWN_ACCELERATION_FRICTION_DEFAULT * multiplier);
}



