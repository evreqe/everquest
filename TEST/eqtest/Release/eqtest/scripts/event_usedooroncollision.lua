function OnFrame()

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerZoneID = EQ_GetSpawnZoneID(playerSpawn)

    if
        playerZoneID == EQ_ZONE_ID_POKNOWLEDGE or
        playerZoneID == EQ_ZONE_ID_GUILDLOBBY or
        playerZoneID == EQ_ZONE_ID_GUILDHALL or
        playerZoneID == EQ_ZONE_ID_BAZAAR or
        playerZoneID == EQ_ZONE_ID_NEXUS
    then

        EQ_UseDoorOnCollision()

    end

end
