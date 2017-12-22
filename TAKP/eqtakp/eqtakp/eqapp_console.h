#pragma once

volatile int g_ConsoleIsLoaded = 0;

std::stringstream g_ConsoleStringStream;
std::streambuf* g_ConsoleStreamBuffer;

void EQAPP_Console_Load();
void EQAPP_Console_Unload();
void EQAPP_Console_Print();

void EQAPP_Console_Load()
{
    setvbuf(stdout, 0, _IOLBF, 4096);

    // redirect cout to stringstream
    g_ConsoleStreamBuffer = std::cout.rdbuf(g_ConsoleStringStream.rdbuf());

    g_ConsoleIsLoaded = 1;
}

void EQAPP_Console_Unload()
{
    // restore cout
    std::cout.rdbuf(g_ConsoleStreamBuffer);

    g_ConsoleIsLoaded = 0;
}

void EQAPP_Console_Print()
{
    // print redirected cout to the chat window
    for (std::string text; std::getline(g_ConsoleStringStream, text, '\n');)
    {
        EQ_WriteChatText(text.c_str());
    }

    g_ConsoleStringStream.str(std::string());
    g_ConsoleStringStream.clear();
}
