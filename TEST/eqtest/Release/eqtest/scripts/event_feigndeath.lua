-- stand up when feign death fails
function OnChatText(chatText, chatTextColor)

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerName = EQ_GetSpawnName(playerSpawn)
    if playerName == "" then
        return
    end

    if chatText == playerName .. " has fallen to the ground." then
       EQ_InterpretCommand("/stand")
    end

end
