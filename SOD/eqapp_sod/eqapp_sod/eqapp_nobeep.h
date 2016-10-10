#pragma once

std::vector<std::string> g_noBeepList;

void EQAPP_NoBeep_Load();
void EQAPP_NoBeep_Print();

void EQAPP_NoBeep_Load()
{
    std::cout << "Loading No Beep..." << std::endl;

    g_noBeepList.clear();

    EQAPP_ReadFileToList("nobeep.txt", g_noBeepList);
}

void EQAPP_NoBeep_Print()
{
    std::cout << "No Beep List:" << std::endl;

    for (auto& text : g_noBeepList)
    {
        std::cout << text << std::endl;
    }
}

