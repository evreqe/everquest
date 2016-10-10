#pragma once

std::vector<std::string> g_zoneShortNamesList;
std::vector<std::string>::iterator g_zoneShortNamesListIterator;

void EQAPP_ZoneShortNames_Load();
void EQAPP_ZoneShortNames_Print();

void EQAPP_ZoneShortNames_Load()
{
    std::cout << "Loading Zone Short Names..." << std::endl;

    g_zoneShortNamesList.clear();

    EQAPP_ReadFileToList("zoneshortnames.txt", g_zoneShortNamesList);

    g_zoneShortNamesListIterator = g_zoneShortNamesList.begin();
}

void EQAPP_ZoneShortNames_Print()
{
    std::cout << "Zone Short Names List:" << std::endl;

    for (auto& text : g_zoneShortNamesList)
    {
        std::cout << text << std::endl;
    }
}

