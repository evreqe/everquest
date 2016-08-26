#ifndef EQAPP_ZONESHORTNAMES_H
#define EQAPP_ZONESHORTNAMES_H

std::vector<std::string> g_zoneShortNamesList;
std::vector<std::string>::iterator g_zoneShortNamesListIterator;

void EQAPP_ZoneShortNames_Load();
void EQAPP_ZoneShortNames_Print();

void EQAPP_ZoneShortNames_Load()
{
    std::cout << "Loading Zone Short Names..." << std::endl;

    g_zoneShortNamesList.clear();

    std::string filePathStr = "eqapp/zoneshortnames.txt";

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        g_zoneShortNamesList.push_back(line);
    }

    g_zoneShortNamesListIterator = g_zoneShortNamesList.begin();

    file.close();
}

void EQAPP_ZoneShortNames_Print()
{
    std::cout << "Zone Short Names List:" << std::endl;

    for (auto& zoneShortName : g_zoneShortNamesList)
    {
        std::cout << zoneShortName << std::endl;
    }
}

#endif // EQAPP_ZONESHORTNAMES_H
