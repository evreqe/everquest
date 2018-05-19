function OnExecuteCommand(commandID, isActive)

    local commandName = EQ_GetExecuteCommandNameByID(commandID)

    EQ_PrintTextToChat("Execute Command: " .. commandName .. " (" .. commandID .. ") = " .. isActive)

end