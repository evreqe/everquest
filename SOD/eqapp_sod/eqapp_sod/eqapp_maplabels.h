#ifndef EQAPP_MAPLABELS_H
#define EQAPP_MAPLABELS_H

bool g_mapLabelsIsEnabled = false;
bool g_mapLabelsFilterIsEnabled = false;
DWORD g_mapLabelsTimer = 0;
DWORD g_mapLabelsTimerDelay = 10000;
std::string g_mapLabelsFilterName;
DWORD g_mapLabelsData = 254;
DWORD g_mapLabelsSize = 2;
DWORD g_mapLabelsLayer = 3;
DWORD g_mapLabelsWidth = 20;
DWORD g_mapLabelsHeight = 12;

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

    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    DWORD spawn = EQ_GetFirstSpawn();
    while (spawn)
    {
        if (spawn == playerSpawn)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnLevel = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_LEVEL);

        if (spawnLevel < EQ_LEVEL_MIN || spawnLevel > EQ_LEVEL_MAX)
        {
            spawn = EQ_GetNextSpawn(spawn); // next
            continue;
        }

        int spawnType = EQ_ReadMemory<BYTE>(spawn + EQ_OFFSET_SPAWN_INFO_TYPE);

        if (g_mapLabelsFilterIsEnabled == true && spawnType == EQ_SPAWN_TYPE_NPC)
        {
            char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
            memcpy(spawnNumberedName, (LPVOID)(spawn + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

            if (strstr(spawnNumberedName, g_mapLabelsFilterName.c_str()) == NULL)
            {
                spawn = EQ_GetNextSpawn(spawn); // next
                continue;
            }
        }

        FLOAT spawnY = EQ_GetSpawnY(spawn);
        FLOAT spawnX = EQ_GetSpawnX(spawn);
        FLOAT spawnZ = EQ_GetSpawnZ(spawn);

        EQXYZ location;
        location.X = -spawnX; // X and Y must be negative
        location.Y = -spawnY; // X and Y must be negative
        location.Z = spawnZ;

        EQARGBCOLOR color;
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

        EQMAPLABEL mapLabel;
        mapLabel.Location    = location;
        mapLabel.Color       = color;
        mapLabel.Size        = g_mapLabelsSize;
        mapLabel.Label       = (PCHAR)(spawn + EQ_OFFSET_SPAWN_INFO_NAME); // spawn name
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

    DWORD mapViewWnd = EQ_ReadMemory<DWORD>(EQ_POINTER_CMapViewWnd);
    if (mapViewWnd == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "map window view is NULL");
        return;
    }

    struct _EQMAPLABEL* mapLabel = EQ_ReadMemory<struct _EQMAPLABEL*>(mapViewWnd + EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST);
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

#endif //EQAPP_MAPLABELS_H
