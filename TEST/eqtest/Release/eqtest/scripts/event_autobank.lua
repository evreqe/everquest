g_AutoBankIsEnabled = 0

function AutoBank_Toggle()
    if g_AutoBankIsEnabled == 0 then
        g_AutoBankIsEnabled = 1
        EQ_PrintTextToChat("Auto Bank: On")
    else

        g_AutoBankIsEnabled = 0
        EQ_PrintTextToChat("Auto Bank: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//AutoBank" then
        AutoBank_Toggle()
        return 1
    end

    if commandText == "//AutoBankOn" then
        if g_AutoBankIsEnabled == 0 then
            AutoBank_Toggle()
            return 1
        end
    end

    if commandText == "//AutoBankOff" then
        if g_AutoBankIsEnabled == 1 then
            AutoBank_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_AutoBankIsEnabled == 1 then
        return 1, "- Auto Bank"
    end
end

function OnFrame()
    if g_AutoBankIsEnabled == 0 then
        return
    end

    EQ_InterpretCommand("/autobank")
end
