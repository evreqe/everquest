g_DruidBotIsEnabled = 0

g_DruidBotTargetName = "Skaj"

function DruidBot_Toggle()
    if g_DruidBotIsEnabled == 0 then
        g_DruidBotIsEnabled = 1
        EQ_PrintTextToChat("Druid Bot: On")
        EQ_ClearTarget()
    else
        g_DruidBotIsEnabled = 0
        EQ_PrintTextToChat("Druid Bot: Off")
    end

    return 1
end

function DruidBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_DruidBotTargetName)
    EQ_InterpretCommand("//Cast 1")
end

function DruidBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_DruidBotTargetName)
    EQ_InterpretCommand("//Cast 3")
end

function DruidBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_DruidBotTargetName)
    EQ_InterpretCommand("//Cast 4")
end

function DruidBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_DruidBotTargetName)
    EQ_InterpretCommand("//Cast 7")
end

function OnInterpretCommand(commandText)
    if commandText == "//DruidBot" then
        DruidBot_Toggle()
        return 1
    end

    if commandText == "//DruidBotOn" then
        if g_DruidBotIsEnabled == 0 then
            DruidBot_Toggle()
        end
        return 1
    end

    if commandText == "//DruidBotOff" then
        if g_DruidBotIsEnabled == 1 then
            DruidBot_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//DruidBotTarget ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_DruidBotTargetName = tokens[2]

            EQ_PrintTextToChat("Druid Bot Target: " .. g_DruidBotTargetName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_DruidBotIsEnabled == 1 then
        return 1, "- Druid Bot: " .. g_DruidBotTargetName
    end
end

function OnFrame()
    if g_DruidBotIsEnabled == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == playerSpawn then
        return
    end

    if targetSpawn ~= 0 then
        local targetType = EQ_GetSpawnType(targetSpawn)
        if targetType ~= EQ_SPAWN_TYPE_PLAYER then
            return
        end
    end

    EQ_InterpretCommand("//Target " .. g_DruidBotTargetName)

    targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(80, 90)

        if targetHP <= 35 then
            DruidBot_SaveHeal()
            DruidBot_InstantHeal()
        elseif targetHP <= 50 then
            DruidBot_InstantHeal()
            DruidBot_FastHeal()
        elseif targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_DruidBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            DruidBot_FastHeal()
            DruidBot_BigHeal()
        end
    end
end
