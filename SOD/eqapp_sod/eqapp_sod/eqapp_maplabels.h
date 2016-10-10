#pragma once

bool g_mapLabelsIsEnabled = false;
bool g_mapLabelsFilterIsEnabled = false;
uint32_t g_mapLabelsTimer = 0;
uint32_t g_mapLabelsTimerDelay = 10000;
std::string g_mapLabelsFilterName;
uint32_t g_mapLabelsData = 254;
uint32_t g_mapLabelsSize = 2;
uint32_t g_mapLabelsLayer = 3;
uint32_t g_mapLabelsWidth = 20;
uint32_t g_mapLabelsHeight = 12;

void EQAPP_MapLabels_Toggle();
void EQAPP_MapLabels_Remove();
void EQAPP_MapLabels_Add();
void EQAPP_MapLabels_Execute();
void EQAPP_MapLabels_Print();
void EQAPP_MapLabels_Filter_Print();

void EQAPP_MapLabels_Toggle()
{
    EQ_ToggleBool(g_mapLabelsIsEnabled);
    EQAPP_PrintBool("Map Labels", g_mapLabelsIsEnabled);

    if (g_mapLabelsIsEnabled == false)
    {
        EQAPP_MapLabels_Remove();
    }
}

void EQAPP_MapLabels_Remove()
{
    EQ_MapWindow_RemoveLabelByData(g_mapLabelsData);
}

void EQAPP_MapLabels_Add()
{
    EQAPP_MapLabels_Remove();

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    uint32_t spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnLevel = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);

        if (spawnLevel < EQ_LEVEL_MIN || spawnLevel > EQ_LEVEL_MAX)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnType = EQ_ReadMemory<uint8_t>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        if (g_mapLabelsFilterIsEnabled == true && spawnType == EQ_SPAWN_TYPE_NPC)
        {
            std::string spawnNumberedName = EQ_GetSpawnNumberedName(spawn);

            if (spawnNumberedName.find(g_mapLabelsFilterName) == std::string::npos)
            {
                spawn = EQ_GetNextSpawn(spawn); // next
                continue;
            }
        }

        float spawnY = EQ_GetSpawnY(spawn);
        float spawnX = EQ_GetSpawnX(spawn);
        float spawnZ = EQ_GetSpawnZ(spawn);

        EQ::XYZ location;
        location.X = -spawnX; // X and Y must be negative
        location.Y = -spawnY; // X and Y must be negative
        location.Z = spawnZ;

        EQ::ColorARGB color;
        color.A = 255;

        if (spawnType == EQ_SPAWN_TYPE_PLAYER)
        {
            color.R = 255;
            color.G = 0;
            color.B = 0;
        }
        else if (spawnType == EQ_SPAWN_TYPE_NPC)
        {
            color.R = 0;
            color.G = 255;
            color.B = 255;
        }
        else if (spawnType == EQ_SPAWN_TYPE_PLAYER_CORPSE)
        {
            color.R = 255;
            color.G = 128;
            color.B = 0;
        }
        else if (spawnType == EQ_SPAWN_TYPE_NPC_CORPSE)
        {
            color.R = 255;
            color.G = 255;
            color.B = 0;
        }

        EQ::MapLabel mapLabel;
        mapLabel.Location    = location;
        mapLabel.Color       = color;
        mapLabel.Size        = g_mapLabelsSize;
        mapLabel.Label       = (char*)(spawn + EQ_OFFSET_SPAWN_INFO_NAME); // spawn name
        mapLabel.Layer       = g_mapLabelsLayer;
        mapLabel.Width       = g_mapLabelsWidth;
        mapLabel.Height      = g_mapLabelsHeight;
        mapLabel.Data        = g_mapLabelsData;

        EQ_MapWindow_AddLabel(&mapLabel);

        spawn = EQ_GetNextSpawn(spawn); // next
    }

    EQ_UpdateMap();
}

void EQAPP_MapLabels_Execute()
{
    if (g_mapLabelsIsEnabled == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_mapLabelsTimer, g_mapLabelsTimerDelay) == false)
    {
        return;
    }

    EQAPP_MapLabels_Add();
}

void EQAPP_MapLabels_Print()
{
    std::cout << "Map Labels:" << std::endl;

    uint32_t mapViewWnd = EQ_ReadMemory<uint32_t>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "map window view is NULL");
        return;
    }

    EQ::MapLabel* mapLabel = EQ_ReadMemory<EQ::MapLabel*>(mapViewWnd + EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST);
    if (mapLabel == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "first map label is NULL");
        return;
    }

    while (mapLabel != NULL)
    {
        std::cout << mapLabel->Label << std::endl;

        mapLabel = mapLabel->Next;
    }
}

void EQAPP_MapLabels_Filter_Print()
{
    std::cout << "Map Labels Filter: " << g_mapLabelsFilterName << std::endl;
}

