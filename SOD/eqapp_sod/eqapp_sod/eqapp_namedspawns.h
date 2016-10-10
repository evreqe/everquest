#pragma once

bool g_namedSpawnsIsEnabled = true;
std::vector<std::string> g_namedSpawnsList;
uint32_t g_namedSpawnsX = 1200;
uint32_t g_namedSpawnsY = 28;
float g_namedSpawnsWidth  = 256.0f;
float g_namedSpawnsHeight = 512.0f;
uint32_t g_namedSpawnsColorARGB = 0xFFFFFFFF;

void EQAPP_NamedSpawns_Load();
void EQAPP_NamedSpawns_Execute();
void EQAPP_NamedSpawns_Print();

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

void EQAPP_NamedSpawns_Execute()
{
    if (g_namedSpawnsIsEnabled == false || g_namedSpawnsList.size() == 0)
    {
        return;
    }

    uint32_t fontSize   = 2;
    uint32_t fontHeight = EQ_GetFontHeight(fontSize);

    uint32_t numSpawns = 0;

    if (g_namedSpawnsWidth > 0 && g_namedSpawnsHeight > 0)
    {
        EQ_DrawQuad((float)g_namedSpawnsX, (float)g_namedSpawnsY, g_namedSpawnsWidth, g_namedSpawnsHeight, EQ_TOOLTIP_COLOR);
    }

    std::stringstream ssDrawText;

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);
        if (spawnType != EQ_SPAWN_TYPE_NPC)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnIdPetOwner = EQ_ReadMemory<uint32_t>(spawn + EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID);
        if (spawnIdPetOwner != 0)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnLevel = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);
        if (spawnLevel < EQ_LEVEL_MIN || spawnLevel > EQ_LEVEL_MAX)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawn);

        for (auto& namedSpawn : g_namedSpawnsList)
        {
            if (spawnName.find(namedSpawn) != std::string::npos)
            {
                ssDrawText << spawnName << "\n";
                numSpawns++;
                break;
            }
        }

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    EQ_DrawText(ssDrawText.str().c_str(), g_namedSpawnsX, g_namedSpawnsY, g_namedSpawnsColorARGB, fontSize);

    if (numSpawns > 0)
    {
        g_namedSpawnsHeight = (float)(numSpawns * fontHeight);
    }
    else
    {
        g_namedSpawnsHeight = 0.0f;
    }
}

void EQAPP_NamedSpawns_Print()
{
    std::cout << "Named Spawns List:" << std::endl;

    size_t index = 1;

    for (auto& text : g_namedSpawnsList)
    {
        std::cout << "#" << index << ": " << text << std::endl;

        index++;
    }
}

