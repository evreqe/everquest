function OnFrame()

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local targetY = EQ_GetSpawnY(targetSpawn)
    local targetX = EQ_GetSpawnX(targetSpawn)
    local targetZ = EQ_GetSpawnZ(targetSpawn)

    local playerY = EQ_GetSpawnY(playerSpawn)
    local playerX = EQ_GetSpawnX(playerSpawn)
    local playerZ = EQ_GetSpawnZ(playerSpawn)

    local lineColor = 0xFFFFFFFF

    local castRayResult = EQ_CanSpawnCastRayToLocation(playerSpawn, targetY, targetX, targetZ)
    if castRayResult == true then
        lineColor = 0xFF00FF00
    else
        lineColor = 0xFFFF0000
    end

    EQ_DrawLine3D(playerY, playerX, playerZ, targetY, targetX, targetZ, lineColor)

end
