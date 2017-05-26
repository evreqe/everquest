#pragma once

bool g_namedSpawnsIsEnabled = true;
std::vector<std::string> g_namedSpawnsList;

void EQAPP_NamedSpawns_Load();

void EQAPP_NamedSpawns_Load()
{
    std::cout << "Loading Named Spawns..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_namedSpawnsList.clear();

    EQAPP_ReadFileToList("namedspawns.txt", g_namedSpawnsList);

    std::stringstream filePath;
    filePath << "namedspawns/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_namedSpawnsList);
}

