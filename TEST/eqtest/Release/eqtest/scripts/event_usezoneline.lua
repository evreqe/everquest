local function TryToZone(direction, y, x, z, distance)

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerDirection = EQ_GetSpawnDirection(playerSpawn)
    if playerDirection == direction then

        if EQ_IsSpawnWithinDistanceOfLocation(playerSpawn, y, x, z, distance) == true then

            if EQ_CanSpawnCastRayToLocation(playerSpawn, y, x, z) == true then

                EQ_PrintTextToChat("[EQTEST] Trying to zone...")

                EQ_InterpretCommand("//FirstPersonCamera")
                EQ_InterpretCommand("//CenterView")
                EQ_InterpretCommand("//Use")

            end

        end

    end

end

function OnOneSecond()

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerZoneID = EQ_GetSpawnZoneID(playerSpawn)

    if playerZoneID == EQ_ZONE_ID_POKNOWLEDGE then

        -- pok to guild lobby
        TryToZone(EQ_DIRECTION_SOUTH_WEST, -368.79, 1415.53, -115.66, 30)

        -- pok to bazaar
        TryToZone(EQ_DIRECTION_NORTH_WEST, 335.63, 1447.69, -115.91, 30)

        -- pok to nexus
        TryToZone(EQ_DIRECTION_NORTH, 449.45, -76.54, -152.87, 15)

        -- pok to potranquility
        TryToZone(EQ_DIRECTION_EAST, -148.07, -321.99, -152.87, 15)

        -- pok to crescent reach
        TryToZone(EQ_DIRECTION_EAST, 60.04, -148.25, -153.74, 15)

        -- pok to the arena
        TryToZone(EQ_DIRECTION_SOUTH, -456.02, 142.87, -153.87, 15)

        return

    end

    if playerZoneID == EQ_ZONE_ID_GUILDLOBBY then

        -- guild lobby to pok
        TryToZone(EQ_DIRECTION_SOUTH, -60.45, 19.92, 4.79, 15)

        -- guild lobby to guild hall
        TryToZone(EQ_DIRECTION_NORTH, 619.96, -48.36, 1.13, 15)

        return

    end

    -- this doesn't work because guild hall is an instance
    -- so the zone ID is some random number
    if playerZoneID == EQ_ZONE_ID_GUILDHALL then

        -- guild hall to guild lobby
        TryToZone(EQ_DIRECTION_SOUTH, -157.62, -3.09, 3.13, 15)

        return

    end

    if playerZoneID == EQ_ZONE_ID_BAZAAR then

        -- bazaar to pok
        TryToZone(EQ_DIRECTION_EAST, 0.17, -444, -29.22, 15)

        return

    end

    if playerZoneID == EQ_ZONE_ID_NEXUS then

        -- nexus to pok
        TryToZone(EQ_DIRECTION_WEST, 45.09, 471.91, -27.98, 15)

        return

    end

    if playerZoneID == EQ_ZONE_ID_POTRANQUILITY then

        -- potranquility to pok
        TryToZone(EQ_DIRECTION_WEST, 772.49, -1446.59, -876.78, 10)
        TryToZone(EQ_DIRECTION_NORTH, 763.45, -1437.17, -876.78, 10)

        return

    end

end
