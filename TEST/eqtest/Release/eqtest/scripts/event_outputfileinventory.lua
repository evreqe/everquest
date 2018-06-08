function OutputFileInventory()
    EQ_InterpretCommand("/outputfile inventory")
end

function OnLoad()
    OutputFileInventory()
end

function OnUnload()
    OutputFileInventory()
end

function OnEnterZone(zoneID)
    OutputFileInventory()
end

function OnChatText(chatText, chatTextColor)

    if String_EndsWith(chatText, "'Welcome to my bank!'") then
        OutputFileInventory()
        return
    end

    if String_EndsWith(chatText, "'Come back soon!'") then
        OutputFileInventory()
        return
    end

    if String_BeginsWith(chatText, "It will take you about ") then
        if String_EndsWith(chatText, " seconds to prepare your camp.") then
            OutputFileInventory()
            return
        end
    end

end