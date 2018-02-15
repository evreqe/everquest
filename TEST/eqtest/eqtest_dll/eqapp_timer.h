#pragma once

#include <chrono>
#include <string>

namespace EQApp
{
    typedef std::chrono::time_point<std::chrono::steady_clock> Timer;
    typedef long long TimerInterval; // delay is in seconds
} // namespace EQApp

EQApp::Timer EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval EQAPP_Timer_GetTimeElapsed(EQApp::Timer& timer);
bool EQAPP_Timer_HasTimeElapsed(EQApp::Timer& timer, EQApp::TimerInterval timerInterval);
std::string EQAPP_Timer_GetTimeAsString();

EQApp::Timer EQAPP_Timer_GetTimeNow()
{
    return std::chrono::steady_clock::now();
}

EQApp::TimerInterval EQAPP_Timer_GetTimeElapsed(EQApp::Timer& timer)
{
    return std::chrono::duration_cast<std::chrono::seconds>(EQAPP_Timer_GetTimeNow() - timer).count();
}

bool EQAPP_Timer_HasTimeElapsed(EQApp::Timer& timer, EQApp::TimerInterval timerInterval)
{
    auto timeNow = EQAPP_Timer_GetTimeNow();

    auto timeElapsed = EQAPP_Timer_GetTimeElapsed(timer);
    if (timeElapsed >= timerInterval)
    {
        timer = EQAPP_Timer_GetTimeNow();
        return true;
    }

    return false;
}

std::string EQAPP_Timer_GetTimeAsString()
{
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

    char timeText[1024];
    ctime_s(timeText, sizeof(timeText), &time);

    return timeText;
}
