#pragma once

void EQAPP_LoadOptions();

void EQAPP_LoadOptions()
{
    std::stringstream filePath;
    filePath << ".\\" << g_EQAppName << "\\" << g_EQAppName << ".ini";

    const char* fileName = filePath.str().c_str();

/*
    auto bTest = EQAPP_INI_ReadBool(fileName, section, "bTest", 0);
    auto bTest2 = EQAPP_INI_ReadBool(fileName, section, "bTest2", 0);
    auto fTest = EQAPP_INI_ReadFloat(fileName, section, "fTest", 9.0f);
    auto sTest = EQAPP_INI_ReadString(fileName, section, "sTest", "Default Value");
    auto iTest = EQAPP_INI_ReadInt(fileName, section, "iTest", 13);

    std::cout << "bTest: " << bTest << "\n";
    std::cout << "bTest2: " << bTest2 << "\n";
    std::cout << "fTest: " << fTest << "\n";
    std::cout << "sTest: " << sTest << "\n";
    std::cout << "iTest: " << iTest << "\n";
*/

    g_GUIIsEnabled = EQAPP_INI_ReadBool(fileName, "GUI", "bEnabled", true);

    g_GUIDarkThemeIsEnabled = EQAPP_INI_ReadBool(fileName, "GUI", "bDarkTheme", true);
}
