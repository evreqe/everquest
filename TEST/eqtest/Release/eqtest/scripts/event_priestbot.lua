g_PriestBotIsEnabled = 0

g_PriestBotTargetName = "Skaj"

function PriestBot_Toggle()
    if g_PriestBotIsEnabled == 0 then
        g_PriestBotIsEnabled = 1
        EQ_PrintTextToChat("Priest Bot: On")
    else
        g_PriestBotIsEnabled = 0
        EQ_PrintTextToChat("Priest Bot: Off")
    end

    return 1
end

function PriestBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 1")
end

function PriestBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 3")
end

function PriestBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 7")
end

function OnInterpretCommand(commandText)
    if commandText == "//PriestBot" then
        PriestBot_Toggle()
        return 1
    end

    if commandText == "//PriestBotOn" then
        if g_PriestBotIsEnabled == 0 then
            PriestBot_Toggle()
            return 1
        end
    end

    if commandText == "//PriestBotOff" then
        if g_PriestBotIsEnabled == 1 then
            PriestBot_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_PriestBotIsEnabled == 1 then
        return 1, "- Priest Bot"
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
        local playerSpawn = EQ_GetPlayerSpawn()
        if playerSpawn == 0 then
            return
        end

        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(60, 80)

        if targetHP <= 25 then
            PriestBot_InstantHeal()
        elseif targetHP <= 50 then
            PriestBot_BigHeal()
        elseif targetHP <= fastHealHP then
            EQ_InterpretCommand("/tell " .. g_PriestBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            PriestBot_FastHeal()
        end
    end
end
