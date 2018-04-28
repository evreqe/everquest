EQ_PrintTextToChat("Testing123")

EQ_PrintTextToChat("PI: " .. EQ_PI)

local playerSpawn = EQ_GetPlayerSpawn()
if playerSpawn ~= 0 then
    local playerName = EQ_GetSpawnName(playerSpawn)
    if playerName ~= "" then
        EQ_PrintTextToChat("Player Name: " .. playerName)
    end
end
