#pragma once

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
    filePath << g_applicationName << "/maplocations/" << zoneShortName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
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

