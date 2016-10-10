#pragma once

bool g_combatHotbuttonIsEnabled = false;
uint32_t g_combatHotbuttonNumber = 1;
uint32_t g_combatHotbuttonTimer = 0;
uint32_t g_combatHotbuttonTimerDelay = 1000;
uint32_t g_combatHotbuttonTimerDelayInSeconds = 1;

void EQAPP_CombatHotbutton_Execute();
void EQAPP_CombatHotbutton_Print();
void EQAPP_CombatHotbutton_Set(uint32_t buttonNumber, uint32_t timerDelayInSeconds);

void EQAPP_CombatHotbutton_Execute()
{
    if (g_combatHotbuttonIsEnabled == false)
    {
        return;
    }

    if (EQ_IsAutoAttackEnabled() == false)
    {
        return;
    }

    uint32_t targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    int spawnType = EQ_ReadMemory<uint8_t>(targetSpawn + EQ_OFFSET_SPAWN_INFO_TYPE);
    if (spawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    if (EQ_IsPlayerCastingSpell() == true)
    {
        return;
    }

    if (EQ_HasTimePassed(g_combatHotbuttonTimer, g_combatHotbuttonTimerDelay) == false)
    {
        return;
    }

    EQ_DoHotButton(g_combatHotbuttonNumber);
}

void EQAPP_CombatHotbutton_Print()
{
    std::cout << "Combat Hotbutton: " << g_combatHotbuttonNumber << " (" << g_combatHotbuttonTimerDelayInSeconds << " second(s))" << std::endl;
}

void EQAPP_CombatHotbutton_Set(uint32_t buttonNumber, uint32_t timerDelayInSeconds)
{
    if (buttonNumber < EQ_HOTBUTTON_NUMBER_MIN || buttonNumber > EQ_HOTBUTTON_NUMBER_MAX)
    {
        std::stringstream ss;
        ss << "invalid hotbutton number specified: " << buttonNumber;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    g_combatHotbuttonNumber = buttonNumber;

    g_combatHotbuttonTimerDelay = (uint32_t)(timerDelayInSeconds * 1000); // convert seconds to milliseconds

    g_combatHotbuttonTimerDelayInSeconds = timerDelayInSeconds;
}

