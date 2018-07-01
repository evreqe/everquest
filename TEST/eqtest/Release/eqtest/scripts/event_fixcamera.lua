function OnExecuteCommand(commandID, isActive)
    -- center the view when switching to third person camera
    -- swimming in water while in third person can pivot the camera view up and down
    if commandID == EQ_EXECUTECMD_USER1_CAMERA or commandID == EQ_EXECUTECMD_USER2_CAMERA then
        EQ_ExecuteCommand(EQ_EXECUTECMD_CENTERVIEW, 1)
    end
end
