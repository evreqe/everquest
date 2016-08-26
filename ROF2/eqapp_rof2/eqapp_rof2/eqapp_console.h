#pragma once

volatile int g_bConsole = 0;

bool g_consoleIsEnabled = true;

std::stringstream g_consoleStringStream;
std::streambuf* g_consoleStreamBuffer;

void EQAPP_Console_Load();
void EQAPP_Console_Unload();

void EQAPP_Console_Load()
{
    // redirect cout to stringstream
    g_consoleStreamBuffer = std::cout.rdbuf(g_consoleStringStream.rdbuf());

    g_bConsole = 1;
}

void EQAPP_Console_Unload()
{
    // restore cout
    std::cout.rdbuf(g_consoleStreamBuffer);

    g_bConsole = 0;
}

