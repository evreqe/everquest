function OnFrame()

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local targetX = EQ_GetSpawnX(targetSpawn)
    local targetY = EQ_GetSpawnY(targetSpawn)
    local targetZ = EQ_GetSpawnZ(targetSpawn)

    local playerX = EQ_GetSpawnX(playerSpawn)
    local playerY = EQ_GetSpawnY(playerSpawn)
    local playerZ = EQ_GetSpawnZ(playerSpawn)

    EQ_DrawLine3D(playerX, playerY, playerZ, targetX, targetY, targetZ, 0xFF00FF00)

end
