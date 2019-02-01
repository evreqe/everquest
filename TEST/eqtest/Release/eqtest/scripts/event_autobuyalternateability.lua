g_AutoBuyAAIsEnabled = 1

function AutoBuyAA_Toggle()
    if g_AutoBuyAAIsEnabled == 0 then
        g_AutoBuyAAIsEnabled = 1
        EQ_PrintTextToChat("Auto Buy AA: On")
    else
        g_AutoBuyAAIsEnabled = 0
        EQ_PrintTextToChat("Auto Buy AA: Off")
    end

end

function OnInterpretCommand(commandText)
    if commandText == "//AutoBuyAA" then
        AutoBuyAA_Toggle()
        return 1
    end

    if commandText == "//AutoBuyAAOn" then
        if g_AutoBuyAAIsEnabled == 0 then
            AutoBuyAA_Toggle()
        end
        return 1
    end

    if commandText == "//AutoBuyAAOff" then
        if g_AutoBuyAAIsEnabled == 1 then
            AutoBuyAA_Toggle()
        end
        return 1
    end
end

function OnDrawHUD()
    if g_AutoBuyAAIsEnabled == 1 then
        return 1, "- Auto Buy AA"
    end
end

function OnChatText(chatText, chatTextColor)
    if String_BeginsWith(chatText, "You have reached the AA point cap") then
        return BuyAA()
    end
end

function BuyAA()
    return
end
