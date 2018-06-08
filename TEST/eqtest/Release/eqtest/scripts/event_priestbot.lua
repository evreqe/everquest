function OnInterpretCommand(commandText)

    if commandText == "//PriestBot" then

        if g_PriestBotIsEnabled == 0 then

            g_PriestBotIsEnabled = 1
            EQ_PrintTextToChat("Priest Bot: On")

        else

            g_PriestBotIsEnabled = 0
            EQ_PrintTextToChat("Priest Bot: Off")

        end

        return 1

    end

    if commandText == "//PriestBotOn" then

        g_PriestBotIsEnabled = 1
        EQ_PrintTextToChat("Priest Bot: On")

        return 1

    end

    if commandText == "//PriestBotOff" then

        g_PriestBotIsEnabled = 0
        EQ_PrintTextToChat("Priest Bot: Off")

        return 1

    end

end

function OnFrame()

    if g_PriestBotIsEnabled == 0 then
        return
    end

    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        if targetHP <= 25 then
            PriestBot_InstantHeal()
        elseif targetHP <= 50 then
            PriestBot_BigHeal()
        elseif targetHP <= 75 then
            PriestBot_FastHeal()
        end
    end

end
