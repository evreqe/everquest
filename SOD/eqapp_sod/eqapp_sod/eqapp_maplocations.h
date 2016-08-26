#ifndef EQAPP_MAPLOCATIONS_H
#define EQAPP_MAPLOCATIONS_H

void EQAPP_MapLocations_WriteToFile();

void EQAPP_MapLocations_WriteToFile()
{
    std::cout << "Saving map locations to file..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << "eqapp/maplocations/" << zoneShortName << ".txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    DWORD spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
        if (spawnType != EQ_SPAWN_TYPE_NPC)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        std::string mapLocation = EQ_GetSpawnMapLocationString(spawn);

        file << mapLocation << std::endl;

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    file.close();
}

#endif // EQAPP_MAPLOCATIONS_H
