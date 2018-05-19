function OnExecuteCommand(commandID, isActive)

    if commandID == EQ_EXECUTECMD_USER1_CAMERA or commandID == EQ_EXECUTECMD_USER2_CAMERA then

        EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1)

    end

end