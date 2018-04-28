-- Brasse test
function OnChatText(chatText, chatTextColor)

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetName = EQ_GetSpawnName(targetSpawn)
    if targetName == "" then
        return
    end
    
    if string.find(targetName, "Brasse") == nil then
       return
    end

    if string.find(chatText, "I'm way ahead of you.") then
       EQ_InterpretCommand("/sit")
    end

end
