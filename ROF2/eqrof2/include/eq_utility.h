#pragma once

#include <windows.h>

#include "eq.h"

template <class T>
void EQ_Log(const char* text, T number);

void EQ_ToggleBool(bool& b);
void EQ_CopyStringToClipboard(const char* str);

template <class T>
void EQ_Log(const char* text, T number)
{
    std::fstream file;
    file.open("Logs/eqlog.txt", std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

void EQ_ToggleBool(bool& b)
{
    b = !b;
}

void EQ_CopyStringToClipboard(const char* str)
{
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, strlen(str) + 1);
    memcpy(GlobalLock(mem), str, strlen(str) + 1);
    GlobalUnlock(mem);

    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, mem);
    CloseClipboard();
}