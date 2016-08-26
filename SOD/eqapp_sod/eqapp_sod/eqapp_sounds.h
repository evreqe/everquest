#ifndef EQAPP_SOUNDS_H
#define EQAPP_SOUNDS_H

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

    g_soundsIsEnabled = EQAPP_INI_ReadBool("eqapp/sounds.ini", "Sounds", "bEnabled", 1);

    if (g_soundsIsEnabled == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "sounds are disabled");
        return;
    }

    for (size_t i = 0; i < 255; i++)
    {
        std::stringstream ssFilename;
        ssFilename << "sFilename" << i;

        std::string filename = EQAPP_INI_ReadString("eqapp/sounds.ini", "Sounds", ssFilename.str().c_str(), "");
        if (filename.size() == 0)
        {
            break;
        }

        std::stringstream filepath;
        filepath << "eqapp\\sounds\\" << filename;

        std::stringstream ssText;
        ssText << "sText" << i;

        std::string text = EQAPP_INI_ReadString("eqapp/sounds.ini", "Sounds", ssText.str().c_str(), "");
        if (text.size() == 0)
        {
            break;
        }

        std::stringstream ssEnabled;
        ssEnabled << "bEnabled" << i;

        bool isEnabled = EQAPP_INI_ReadBool("eqapp/sounds.ini", "Sounds", ssEnabled.str().c_str(), 0);

        std::cout << __FUNCTION__ << ": " << filename << " isEnabled: " << std::boolalpha << isEnabled << std::noboolalpha << std::endl;

        EQAPPSOUND sound;
        sound.index        = i;
        sound.text         = text;
        sound.filename     = filepath.str();
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

#endif // EQAPP_SOUNDS_H