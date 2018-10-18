g_PriestBotExIsEnabled = 0

function PriestBotEx_Toggle()
    if g_PriestBotExIsEnabled == 0 then
        g_PriestBotExIsEnabled = 1
        EQ_PrintTextToChat("Priest Bot Ex: On")
        EQ_ClearTarget()
    else
        g_PriestBotExIsEnabled = 0
        EQ_PrintTextToChat("Priest Bot Ex: Off")
    end

    return 1
end

function PriestBotEx_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 1")
end

function PriestBotEx_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 3")
end

function PriestBotEx_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 4")
end

function PriestBotEx_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function OnInterpretCommand(commandText)
    if commandText == "//PriestBotEx" then
        PriestBotEx_Toggle()
        return 1
    end

    if commandText == "//PriestBotExOn" then
        if g_PriestBotIsEnabled == 0 then
            PriestBotEx_Toggle()
        end
        return 1
    end

    if commandText == "//PriestBotExOff" then
        if g_PriestBotExIsEnabled == 1 then
            PriestBotEx_Toggle()
        end
        return 1
    end
end

function OnDrawHUD()
    if g_PriestBotExIsEnabled == 1 then
        return 1, "- Priest Bot Ex"
    end
end

function OnFrame()
    if g_PriestBotExIsEnabled == 0 then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetType = EQ_GetSpawnType(targetSpawn)
    if targetType ~= EQ_SPAWN_TYPE_PLAYER then
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

        local fastHealHP = math.random(80, 90)

        if targetHP <= 35 then
            PriestBotEx_SaveHeal()
            PriestBotEx_InstantHeal()
        elseif targetHP <= 50 then
            PriestBotEx_InstantHeal()
            PriestBotEx_FastHeal()
        elseif targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_PriestBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            PriestBotEx_FastHeal()
            PriestBotEx_BigHeal()
        end
    end
end
