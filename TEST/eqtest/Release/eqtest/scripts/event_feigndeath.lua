function OnChatText(chatText, chatTextColor)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerSpawnName = EQ_GetSpawnName(playerSpawn)
    if playerSpawnName == "" then
        return
    end

    -- stand up when feign death fails
    if chatText == playerSpawnName .. " has fallen to the ground." then
       EQ_InterpretCommand("/stand")
    end
end
