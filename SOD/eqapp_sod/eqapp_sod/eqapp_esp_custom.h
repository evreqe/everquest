#ifndef EQAPP_ESP_CUSTOM_H
#define EQAPP_ESP_CUSTOM_H

typedef struct _EQAPPESPCUSTOM
{
    float y;
    float x;
    float z;
    DWORD color;
    unsigned int size = 2;
    std::string text;
} EQAPPESPCUSTOM, *PEQAPPESPCUSTOM;

bool g_espCustomIsEnabled = true;
std::vector<EQAPPESPCUSTOM> g_espCustomList;
float g_espCustomDistance = 400.0f;

void EQAPP_ESP_Custom_Load();
void EQAPP_ESP_Custom_Draw();

void EQAPP_ESP_Custom_Load()
{
    std::cout << "Loading Custom ESP..." << std::endl;

    g_espCustomList.clear();

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << "eqapp/esp/" << zoneShortName << ".txt";

    std::ifstream file;
    file.open(filePath.str().c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        float y;
        float x;
        float z;
        unsigned int red;
        unsigned int green;
        unsigned int blue;
        unsigned int size;
        char text[1024];

        int result = sscanf_s(line.c_str(), "%f %f %f %d %d %d %d %s", &y, &x, &z, &red, &green, &blue, &size, text, sizeof(text));

        if (result == 8)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(text);

            unsigned int alpha = 255;

            EQAPPESPCUSTOM espCustom;
            espCustom.y        = y;
            espCustom.x        = x;
            espCustom.z        = z;
            espCustom.color    = (alpha << 24) + (red << 16) + (green << 8) + blue; // 0xAARRGGBB
            espCustom.size     = size;
            espCustom.text     = text;

            g_espCustomList.push_back(espCustom);
        }
    }

    file.close();
}

void EQAPP_ESP_Custom_Draw()
{
    if (g_espCustomIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();

    FLOAT playerY = EQ_GetSpawnY(playerSpawn);
    FLOAT playerX = EQ_GetSpawnX(playerSpawn);
    FLOAT playerZ = EQ_GetSpawnZ(playerSpawn);

    for (auto& espCustom : g_espCustomList)
    {
        float distance = EQ_CalculateDistance3d(playerX, playerY, playerZ, espCustom.x, espCustom.y, espCustom.z);
        if (distance > g_espCustomDistance)
        {
            continue;
        }

        int screenX = -1;
        int screenY = -1;
        bool result = EQ_WorldSpaceToScreenSpace(espCustom.x, espCustom.y, espCustom.z, screenX, screenY);
        if (result == false)
        {
            continue;
        }

        std::stringstream ss;
        ss << "# " << espCustom.text << " (" << (int)distance << ")";
        EQ_DrawText(ss.str().c_str(), screenX, screenY, espCustom.color, espCustom.size);
    }
}

#endif // EQAPP_ESP_CUSTOM_H
