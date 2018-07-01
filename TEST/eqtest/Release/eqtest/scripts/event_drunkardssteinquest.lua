-- Drunkard's Stein anniversary quest
function OnChatText(chatText, chatTextColor)
    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetName = EQ_GetSpawnName(targetSpawn)
    if targetName == "" then
        return
    end
    
    if string.find(targetName, "Galdorin Visigothe") == nil then
       return
    end

    if string.find(chatText, "My stinky stein has rough dirty lips,") then
       EQ_InterpretCommand("/say My stinky stein has rough dirty lips,")
    end

    if string.find(chatText, "but she loves a deep carouse.") then
       EQ_InterpretCommand("/say but she loves a deep carouse.")
    end

    if string.find(chatText, "Beer or ale are her great trips.") then
       EQ_InterpretCommand("/say Beer or ale are her great trips.")
    end

    if string.find(chatText, "No matter how many vows") then
       EQ_InterpretCommand("/say No matter how many vows")
    end

    if string.find(chatText, "I make or break, my drinking glass") then
       EQ_InterpretCommand("/say I make or break, my drinking glass")
    end

    if string.find(chatText, "reminds me of my lovely Brasse.") then
       EQ_InterpretCommand("/say reminds me of my lovely Brasse.")
    end
end
