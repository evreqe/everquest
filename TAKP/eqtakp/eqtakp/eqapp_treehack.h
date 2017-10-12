#pragma once

bool g_treeHackIsEnabled = false;

std::vector<std::string> g_treeHackTextureFileNameList;

void EQAPP_TreeHack_Toggle();
void EQAPP_TreeHack_Load();

void EQAPP_TreeHack_Toggle()
{
    EQ_ToggleBool(g_treeHackIsEnabled);
    EQAPP_PrintBool("Tree Hack", g_treeHackIsEnabled);

    EQ_GraphicsDLL_SetUseTNL(g_treeHackIsEnabled);
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

    g_treeHackTextureFileNameList.clear();
    g_treeHackTextureFileNameList.reserve(100);

    EQAPP_ReadFileToList("treehack.txt", g_treeHackTextureFileNameList);

    std::stringstream filePath;
    filePath << "treehack/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_treeHackTextureFileNameList);
}
