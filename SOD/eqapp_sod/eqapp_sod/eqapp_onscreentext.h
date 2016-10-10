#pragma once

bool g_onScreenTextIsEnabled = true;
std::list<std::string> g_onScreenTextList;
uint32_t g_onScreenTextCountMax = 10;
uint32_t g_onScreenTextX = 1200;
uint32_t g_onScreenTextY = 500;
uint32_t g_onScreenTextTimer = 0;
uint32_t g_onScreenTextTimerDelay = 5000;
uint32_t g_onScreenTextColorARGB = 0xFFFFFFFF;

void EQAPP_OnScreenText_Execute();
void EQAPP_OnScreenText_Print();
void EQAPP_OnScreenText_Add(std::string str);
void EQAPP_OnScreenText_AddSpawnMessage(uint32_t spawnInfo, bool bDespawn);

void EQAPP_OnScreenText_Execute()
{
    if (g_onScreenTextIsEnabled == false || g_onScreenTextList.size() == 0)
    {
        return;
    }

    if (EQ_HasTimePassed(g_onScreenTextTimer, g_onScreenTextTimerDelay) == true)
    {
        g_onScreenTextList.pop_front();
    }

    std::stringstream ssDrawText;

    size_t textCount = 0;

    for (auto g_onScreenTextList_it = g_onScreenTextList.rbegin(); g_onScreenTextList_it != g_onScreenTextList.rend(); g_onScreenTextList_it++)
    {
        std::string text = *g_onScreenTextList_it;

        if (textCount >= g_onScreenTextCountMax)
        {
            break;
        }

        ssDrawText << text << "\n";

        textCount++;
    }

    EQ_DrawText(ssDrawText.str().c_str(), g_onScreenTextX, g_onScreenTextY, g_onScreenTextColorARGB, 2);
}

void EQAPP_OnScreenText_Print()
{
    std::cout << "On Screen Text List:" << std::endl;

    for (auto& text : g_onScreenTextList)
    {
        std::cout << text << std::endl;
    }
}

void EQAPP_OnScreenText_Add(std::string str)
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    g_onScreenTextTimer = EQ_GetTimer();
    g_onScreenTextList.push_back(str);
}

void EQAPP_OnScreenText_AddSpawnMessage(uint32_t spawnInfo, bool bDespawn)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    if (EQ_IsInGame() == false)
    {
        return;
    }

    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
    memcpy(spawnName, (void*)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

    int spawnType = EQ_ReadMemory<uint8_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_TYPE);

    if (spawnType == EQ_SPAWN_TYPE_PLAYER)
    {
        if (EQ_IsSpawnInGroup(spawnInfo) == false)
        {
            if (strlen(spawnName) > EQ_SPAWN_NAME_LENGTH_MIN - 1)
            {
                std::stringstream ss;
                ss << spawnName;

                if (bDespawn == false)
                {
                    ss << " has entered the zone.";
                }
                else
                {
                    ss << " has left the zone.";
                }

                EQAPP_OnScreenText_Add(ss.str());
            }
        }
    }
    else if (spawnType == EQ_SPAWN_TYPE_NPC)
    {
        for (auto& namedSpawn : g_namedSpawnsList)
        {
            if (strstr(spawnName, namedSpawn.c_str()) != NULL)
            {
                std::stringstream ss;
                ss << spawnName;

                if (bDespawn == false)
                {
                    ss << " has spawned.";
                }
                else
                {
                    ss << " has despawned.";
                }

                EQAPP_OnScreenText_Add(ss.str());

                break;
            }
        }
    }
}

