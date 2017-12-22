#pragma once

bool g_TreeHackIsEnabled = false;

std::vector<std::string> g_TreeHackTextureFileNameList;

void EQAPP_TreeHack_Toggle();
void EQAPP_TreeHack_Load();

void EQAPP_TreeHack_Toggle()
{
    EQ_ToggleBool(g_TreeHackIsEnabled);
    EQAPP_PrintBool("Tree Hack", g_TreeHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_TreeHackIsEnabled);
}

void EQAPP_TreeHack_Load()
{
    std::cout << "Loading Tree Hack..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_TreeHackTextureFileNameList.clear();
    g_TreeHackTextureFileNameList.reserve(100);

    EQAPP_ReadFileToList("treehack.txt", g_TreeHackTextureFileNameList);

    std::stringstream filePath;
    filePath << "treehack/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_TreeHackTextureFileNameList);
}
