#ifndef EQAPP_PLAYERALERT_H
#define EQAPP_PLAYERALERT_H

bool g_playerAlertIsEnabled = false;
unsigned int g_playerAlertMinimumNumPlayersInZone = 1;
DWORD g_playerAlertTimer = 0;
DWORD g_playerAlertTimerDelay = 1000;
DWORD g_playerAlertTimerDelayInSeconds = 1;

void EQAPP_PlayerAlert_Execute();
void EQAPP_PlayerAlert_Print();
void EQAPP_PlayerAlert_Set(unsigned int minimumNumPlayersInZone, DWORD timerDelayInSeconds);

void EQAPP_PlayerAlert_Execute()
{
    if (g_playerAlertIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_playerAlertTimer, g_playerAlertTimerDelay) == false)
    {
        return;
    }

    if (EQ_GetNumPlayersInZone() > g_playerAlertMinimumNumPlayersInZone)
    {
        EQAPP_Beep();
    }
}

void EQAPP_PlayerAlert_Print()
{
    if (g_playerAlertTimerDelay == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "timer delay is zero");
        return;
    }

    std::cout << "Player Alert: " <<  g_playerAlertMinimumNumPlayersInZone << " (" << g_playerAlertTimerDelayInSeconds << " second(s))" << std::endl;
}

void EQAPP_PlayerAlert_Set(unsigned int minimumNumPlayersInZone, DWORD timerDelayInSeconds)
{
    g_playerAlertMinimumNumPlayersInZone = minimumNumPlayersInZone;

    g_playerAlertTimerDelay = (DWORD)(timerDelayInSeconds * 1000); // convert seconds to milliseconds

    g_playerAlertTimerDelayInSeconds = timerDelayInSeconds;
}

#endif // EQAPP_PLAYERALERT_H
