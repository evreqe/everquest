#pragma once

typedef struct _EQAPPSOUND
{
    unsigned int index;
    std::string text;
    std::string filename;
    bool isEnabled;
} EQAPPSOUND, *PEQAPPSOUND;

bool g_soundsIsEnabled = true;
std::vector<EQAPPSOUND> g_soundsList;

void EQAPP_Sounds_Load();
void EQAPP_Sounds_Print();

void EQAPP_Sounds_Load()
{
    std::cout << "Loading Sounds..." << std::endl;

    g_soundsList.clear();

    std::stringstream filePathIni;
    filePathIni << g_applicationName << "/sounds.ini";

    std::string filePathIniStr = filePathIni.str();

    const char* filePathIniCStr = filePathIniStr.c_str();

    g_soundsIsEnabled = EQAPP_INI_ReadBool(filePathIniCStr, "Sounds", "bEnabled", 1);

    if (g_soundsIsEnabled == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "sounds are disabled");
        return;
    }

    for (size_t i = 0; i < 255; i++)
    {
        std::stringstream ssFilename;
        ssFilename << "sFilename" << i;

        std::string filename = EQAPP_INI_ReadString(filePathIniCStr, "Sounds", ssFilename.str().c_str(), "");
        if (filename.size() == 0)
        {
            break;
        }

        std::stringstream filePath;
        filePath << g_applicationName << "/sounds/" << filename;

        std::stringstream ssText;
        ssText << "sText" << i;

        std::string text = EQAPP_INI_ReadString(filePathIniCStr, "Sounds", ssText.str().c_str(), "");
        if (text.size() == 0)
        {
            break;
        }

        std::stringstream ssEnabled;
        ssEnabled << "bEnabled" << i;

        bool isEnabled = EQAPP_INI_ReadBool(filePathIniCStr, "Sounds", ssEnabled.str().c_str(), 0);

        std::cout << __FUNCTION__ << ": " << filename << " isEnabled: " << std::boolalpha << isEnabled << std::noboolalpha << std::endl;

        EQAPPSOUND sound;
        sound.index        = i;
        sound.text         = text;
        sound.filename     = filePath.str();
        sound.isEnabled    = isEnabled;
        
        g_soundsList.push_back(sound);
    }
}

void EQAPP_Sounds_Print()
{
    std::cout << "Sounds List:" << std::endl;

    for (auto& sound : g_soundsList)
    {
        std::cout << "#" << sound.index << " : " << std::boolalpha << sound.isEnabled << std::noboolalpha << " : " << sound.filename << " : " << sound.text << std::endl;
    }
}
