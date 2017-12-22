#pragma once

bool g_WaterHackIsEnabled = false;

std::vector<std::string> g_WaterHackTextureFileNameList;

void EQAPP_WaterHack_Toggle();
void EQAPP_WaterHack_Load();

void EQAPP_WaterHack_Toggle()
{
    EQ_ToggleBool(g_WaterHackIsEnabled);
    EQAPP_PrintBool("Water Hack", g_WaterHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_WaterHackIsEnabled);
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

    g_WaterHackTextureFileNameList.clear();
    g_WaterHackTextureFileNameList.reserve(100);

    EQAPP_ReadFileToList("waterhack.txt", g_WaterHackTextureFileNameList);

    std::stringstream filePath;
    filePath << "waterhack/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_WaterHackTextureFileNameList);
}