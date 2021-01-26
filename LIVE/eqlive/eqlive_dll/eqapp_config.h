#pragma once

toml::parse_result g_Config;

void EQAPP_ConfigList_Load();
void EQAPP_Config_Load();

void EQAPP_ConfigList_Load()
{
    std::string fileName = fmt::format("{}/config.txt", g_EQAppName);

    g_Config = toml::parse_file(fileName);

    if (g_Config.empty() == false)
    {
        std::cout << fmt::format("Configuration loaded from file: {}.\n", fileName);
    }
}

void EQAPP_Config_Load()
{
    EQAPP_ConfigList_Load();

    if (g_Config.empty() == true)
    {
        return;
    }

    g_GUIIsEnabled = g_Config["GUI"]["bEnabled"].value_or(g_GUIIsEnabled);
    g_GUIDarkThemeIsEnabled = g_Config["GUI"]["bDarkTheme"].value_or(g_GUIDarkThemeIsEnabled);
}
