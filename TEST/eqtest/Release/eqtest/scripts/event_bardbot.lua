g_BardBotIsEnabled = 0

g_BardBotMelody = {1, 2, 3, 4, 5}

function BardBot_Toggle()
    EQ_InterpretCommand("/stopsong")
    EQ_InterpretCommand("/melody")

    if g_BardBotIsEnabled == 0 then
        g_BardBotIsEnabled = 1
        EQ_PrintTextToChat("Bard Bot: On")
    else

        g_BardBotIsEnabled = 0
        EQ_PrintTextToChat("Bard Bot: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//BardBot" then
        BardBot_Toggle()
        return 1
    end

    if commandText == "//BardBotOn" then
        if g_BardBotIsEnabled == 0 then
            BardBot_Toggle()
        end
        return 1
    end

    if commandText == "//BardBotOff" then
        if g_BardBotIsEnabled == 1 then
            BardBot_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//BardBotMelody ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_BardBotMelody = String_Split(tokens[2], ",")

            EQ_PrintTextToChat("Bard Bot Melody: " .. table.concat(g_BardBotMelody, ", "))
        end

        return 1
    end
end

function OnDrawHUD()
    if g_BardBotIsEnabled == 1 then
        return 1, "- Bard Bot: " .. table.concat(g_BardBotMelody, ", ")
    end
end

function OnTick()
    if g_BardBotIsEnabled == 0 then
        return
    end

    if EQ_CastingWindow_IsOpen() == true then
        return
    end

    if EQ_IsSpellGemIndexReadyToCast(0) == false then
        return
    end

    EQ_InterpretCommand("/melody " .. table.concat(g_BardBotMelody, " "))
end
