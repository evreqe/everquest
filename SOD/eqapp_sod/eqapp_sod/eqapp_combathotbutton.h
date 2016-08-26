#ifndef EQAPP_COMBATHOTBUTTON_H
#define EQAPP_COMBATHOTBUTTON_H

bool g_combatHotbuttonIsEnabled = false;
unsigned int g_combatHotbuttonNumber = 1;
DWORD g_combatHotbuttonTimer = 0;
DWORD g_combatHotbuttonTimerDelay = 1000;
DWORD g_combatHotbuttonTimerDelayInSeconds = 1;

void EQAPP_CombatHotbutton_Execute();
void EQAPP_CombatHotbutton_Print();
void EQAPP_CombatHotbutton_Set(unsigned buttonNumber, DWORD timerDelayInSeconds);

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

    DWORD targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    int spawnType = EQ_ReadMemory<BYTE>(targetSpawn + EQ_OFFSET_SPAWN_INFO_TYPE);
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

void EQAPP_CombatHotbutton_Set(unsigned buttonNumber, DWORD timerDelayInSeconds)
{
    if (buttonNumber < EQ_HOTBUTTON_NUMBER_MIN || buttonNumber > EQ_HOTBUTTON_NUMBER_MAX)
    {
        std::stringstream ss;
        ss << "invalid hotbutton number specified: " << buttonNumber;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    g_combatHotbuttonNumber = buttonNumber;

    g_combatHotbuttonTimerDelay = (DWORD)(timerDelayInSeconds * 1000); // convert seconds to milliseconds

    g_combatHotbuttonTimerDelayInSeconds = timerDelayInSeconds;
}

#endif // EQAPP_COMBATHOTBUTTON_H
