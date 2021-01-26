#pragma once

namespace EQApp
{
    typedef std::chrono::time_point<std::chrono::steady_clock> Timer;
    typedef long long TimerInterval;
} // namespace EQApp

EQApp::Timer EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval EQAPP_Timer_GetTimeElapsedInSeconds(EQApp::Timer& timer);
bool EQAPP_Timer_HasTimeElapsedInSeconds(EQApp::Timer& timer, EQApp::TimerInterval timerInterval);
EQApp::TimerInterval EQAPP_Timer_GetTimeElapsedInMilliseconds(EQApp::Timer& timer);
bool EQAPP_Timer_HasTimeElapsedInMilliseconds(EQApp::Timer& timer, EQApp::TimerInterval timerInterval);

EQApp::Timer EQAPP_Timer_GetTimeNow()
{
    return std::chrono::steady_clock::now();
}

EQApp::TimerInterval EQAPP_Timer_GetTimeElapsedInSeconds(EQApp::Timer& timer)
{
    return std::chrono::duration_cast<std::chrono::seconds>(EQAPP_Timer_GetTimeNow() - timer).count();
}

bool EQAPP_Timer_HasTimeElapsedInSeconds(EQApp::Timer& timer, EQApp::TimerInterval timerInterval)
{
    auto timeElapsed = EQAPP_Timer_GetTimeElapsedInSeconds(timer);
    if (timeElapsed >= timerInterval)
    {
        timer = EQAPP_Timer_GetTimeNow();
        return true;
    }

    return false;
}

EQApp::TimerInterval EQAPP_Timer_GetTimeElapsedInMilliseconds(EQApp::Timer& timer)
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(EQAPP_Timer_GetTimeNow() - timer).count();
}

bool EQAPP_Timer_HasTimeElapsedInMilliseconds(EQApp::Timer& timer, EQApp::TimerInterval timerInterval)
{
    auto timeElapsed = EQAPP_Timer_GetTimeElapsedInMilliseconds(timer);
    if (timeElapsed >= timerInterval)
    {
        timer = EQAPP_Timer_GetTimeNow();
        return true;
    }

    return false;
}

