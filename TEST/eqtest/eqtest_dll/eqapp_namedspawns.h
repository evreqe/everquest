#pragma once

bool g_NamedSpawnsIsEnabled = true;

std::vector<std::string> g_NamedSpawnsList;
uint32_t g_NamedSpawnsList_reserve = 1024;

void EQAPP_NamedSpawns_Toggle();
void EQAPP_NamedSpawns_On();
void EQAPP_NamedSpawns_Off();
void EQAPP_NamedSpawns_Load();

void EQAPP_NamedSpawns_Toggle()
{
    EQ_ToggleBool(g_NamedSpawnsIsEnabled);
    EQAPP_PrintBool("Named Spawns", g_NamedSpawnsIsEnabled);
}

void EQAPP_NamedSpawns_On()
{
    if (g_NamedSpawnsIsEnabled == false)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_Off()
{
    if (g_NamedSpawnsIsEnabled == true)
    {
        EQAPP_NamedSpawns_Toggle();
    }
}

void EQAPP_NamedSpawns_Load()
{
    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintDebugText(__FUNCTION__, "zone short name is null");
        return;
    }

    g_NamedSpawnsList.clear();
    g_NamedSpawnsList.reserve(g_NamedSpawnsList_reserve);

    EQAPP_ReadFileToList("namedspawns.txt", g_NamedSpawnsList, false);

    std::stringstream folderFileName;
    folderFileName << "namedspawns/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(folderFileName.str().c_str(), g_NamedSpawnsList, false);
}
