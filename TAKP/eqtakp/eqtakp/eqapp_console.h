#pragma once

volatile int g_bConsole = 0;

std::stringstream g_consoleStringStream;
std::streambuf* g_consoleStreamBuffer;

void EQAPP_Console_Load();
void EQAPP_Console_Unload();
void EQAPP_Console_Print();

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

void EQAPP_Console_Print()
{
    // print redirected std::cout to the chat window
    for (std::string text; std::getline(g_consoleStringStream, text, '\n');)
    {
        EQ_WriteChatText(text.c_str());
    }
    g_consoleStringStream.str(std::string());
    g_consoleStringStream.clear();
}
