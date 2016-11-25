#WinActivateForce
SetTimer, FixWindows, 1000
Return

`::
WinActivateBottom, EQ:
Return

FixWindows:
IfWinActive, EverQuest
{
WinGet, eq_window, List, EverQuest
Loop, %eq_window%
{
    this_window := eq_window%A_Index%
    WinMaximize, ahk_id %this_window%
}
}
IfWinActive, EQ:
{
WinGet, eq_window, List, EQ:
Loop, %eq_window%
{
    this_window := eq_window%A_Index%
    WinMaximize, ahk_id %this_window%
}
}
Return