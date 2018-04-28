EQ_PrintTextToChat("Spawn List:")

local spawn = EQ_GetFirstSpawn()

while spawn ~= 0 do
    local spawnText = ""

    local spawnLevel = EQ_GetSpawnLevel(spawn)
    if spawnLevel ~= 0 then
        spawnText = spawnText .. "[" .. spawnLevel .. "]"
    end

    local spawnName = EQ_GetSpawnName(spawn)
    if spawnName ~= "" then
        spawnText = spawnText .. " " .. spawnName
    end

    local spawnType = EQ_GetSpawnType(spawn)
    if spawnType == EQ_SPAWN_TYPE_NPC then
        local spawnLastName = EQ_GetSpawnLastName(spawn)
        if spawnLastName ~= "" then
            spawnText = spawnText .. " (" .. spawnLastName .. ")"
        end
    end

    if spawnText ~= "" then
        EQ_PrintTextToChat(spawnText)
    end

    spawn = EQ_GetSpawnNext(spawn)
end
