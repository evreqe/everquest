#pragma once

bool g_waterHackIsEnabled = false;

std::vector<std::string> g_waterHackTextureFileNameList;

void EQAPP_WaterHack_Toggle();
void EQAPP_WaterHack_Load();

void EQAPP_WaterHack_Toggle()
{
    EQ_ToggleBool(g_waterHackIsEnabled);
    EQAPP_PrintBool("Water Hack", g_waterHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_waterHackIsEnabled);
}

void EQAPP_WaterHack_Load()
{
    std::cout << "Loading Water Hack..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_waterHackTextureFileNameList.clear();
    g_waterHackTextureFileNameList.reserve(100);

    EQAPP_ReadFileToList("waterhack.txt", g_waterHackTextureFileNameList);

    std::stringstream filePath;
    filePath << "waterhack/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_waterHackTextureFileNameList);
}