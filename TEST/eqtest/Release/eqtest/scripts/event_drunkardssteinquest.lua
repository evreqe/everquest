g_DrunkardsSteinQuestIsEnabled = 0

-- Drunkard's Stein anniversary quest
function OnChatText(chatText, chatTextColor)
    if g_DrunkardsSteinQuestIsEnabled == 0 then
        return
    end

    local zoneID = EQ_GetZoneID()
    if zoneID ~= EQ_ZONE_ID_ABYSMAL then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetName = EQ_GetSpawnName(targetSpawn)
    if targetName == "" then
        return
    end
    
    if String_Contains(targetName, "Galdorin Visigothe") == false then
       return
    end

    if String_Contains(chatText, "Galdorin") == false then
       return
    end

    if String_Contains(chatText, "My stinky stein has rough dirty lips,") == true then
       EQ_InterpretCommand("/say My stinky stein has rough dirty lips,")
    end

    if String_Contains(chatText, "but she loves a deep carouse.") == true then
       EQ_InterpretCommand("/say but she loves a deep carouse.")
    end

    if String_Contains(chatText, "Beer or ale are her great trips.") == true then
       EQ_InterpretCommand("/say Beer or ale are her great trips.")
    end

    if String_Contains(chatText, "No matter how many vows") == true then
       EQ_InterpretCommand("/say No matter how many vows")
    end

    if String_Contains(chatText, "I make or break, my drinking glass") == true then
       EQ_InterpretCommand("/say I make or break, my drinking glass")
    end

    if String_Contains(chatText, "reminds me of my lovely Brasse.") == true then
       EQ_InterpretCommand("/say reminds me of my lovely Brasse.")
    end
end
