#pragma once

void EQAPP_EnteringZone_HandleEvent_CEverQuest__MoveToZone(void* this_ptr, int zoneID, char* text, int destinationType, int zoneRequestReason)
{
    char zoneFullName[259];
    EQ_CLASS_POINTER_EQWorldData->GetFullZoneName(zoneID, zoneFullName);

    std::stringstream enteringZoneText;
    enteringZoneText << "Entering " << zoneFullName << "...";

    uint32_t resolutionWidth = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_WIDTH);
    uint32_t resolutionHeight = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_RESOLUTION_HEIGHT);

    uint32_t drawX = (uint32_t)(resolutionWidth * 0.5f);
    uint32_t drawY = (uint32_t)(resolutionHeight * 0.5f);

    size_t textWidth = EQ_GetFontTextWidth(enteringZoneText.str().c_str(), EQ_ADDRESS_POINTER_FONT_ARIAL20);

    drawX = drawX - (uint32_t)(textWidth * 0.5f);

    EQ_DrawTextEx(enteringZoneText.str().c_str(), drawX, drawY, 0xFFFFFFFF, EQ_ADDRESS_POINTER_FONT_ARIAL20);
}

