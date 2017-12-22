#pragma once

void EQAPP_EnteringZone_DrawText(char* zoneName);
void EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone(void* this_ptr, EQ_ZoneID_t zoneID, char* text, int destinationType, int zoneRequestReason);
void EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone__2(void* this_ptr, char* zoneShortName, char* text, int destinationType, int zoneRequestReason);

void EQAPP_EnteringZone_DrawText(char* zoneName)
{
    std::stringstream enteringZoneText;
    enteringZoneText << "Entering " << zoneName << "...";

    uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);
    uint32_t resolutionHeight = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_HEIGHT);

    uint32_t drawX = (uint32_t)(resolutionWidth * 0.5f);
    uint32_t drawY = (uint32_t)(resolutionHeight * 0.5f);

    size_t textWidth = EQ_GetFontTextWidth(enteringZoneText.str().c_str(), EQ_ADDRESS_POINTER_FONT_ARIAL20);

    drawX = drawX - (uint32_t)(textWidth * 0.5f);

    EQ_DrawTextEx(enteringZoneText.str().c_str(), drawX, drawY, 0xFFFFFFFF, EQ_ADDRESS_POINTER_FONT_ARIAL20);
}

void EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone(void* this_ptr, EQ_ZoneID_t zoneID, char* text, int destinationType, int zoneRequestReason)
{
    char zoneFullName[512];
    EQ_CLASS_POINTER_EQWorldData->GetFullZoneName(zoneID, zoneFullName);

    EQAPP_EnteringZone_DrawText(zoneFullName);
}

void EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone__2(void* this_ptr, char* zoneShortName, char* text, int destinationType, int zoneRequestReason)
{
    EQ_ZoneID_t zoneID = EQ_CLASS_POINTER_EQWorldData->GetIndexFromZoneName(zoneShortName);

    char zoneFullName[512];
    EQ_CLASS_POINTER_EQWorldData->GetFullZoneName(zoneID, zoneFullName);

    EQAPP_EnteringZone_DrawText(zoneFullName);
}
