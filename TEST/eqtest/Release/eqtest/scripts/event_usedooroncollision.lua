function OnFrame()
    local zoneID = EQ_GetZoneID()

    if
        zoneID == EQ_ZONE_ID_POKNOWLEDGE or
        zoneID == EQ_ZONE_ID_GUILDLOBBY or
        -- does not work because zone ID for an instance is random
        --zoneID == EQ_ZONE_ID_GUILDHALL or
        zoneID == EQ_ZONE_ID_BAZAAR or
        zoneID == EQ_ZONE_ID_NEXUS
    then
        EQ_UseDoorOnCollision()
        return
    end

    local zoneShortName = EQ_GetZoneShortName()

    if zoneShortName == "guildhall" then
        EQ_UseDoorOnCollision()
        return
    end
end
