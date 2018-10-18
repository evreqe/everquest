g_ShamanBotIsEnabled = 0

g_ShamanBotTargetName = "Skaj"

function ShamanBot_Toggle()
    if g_ShamanBotIsEnabled == 0 then
        g_ShamanBotIsEnabled = 1
        EQ_PrintTextToChat("Shaman Bot: On")
        EQ_ClearTarget()
    else
        g_ShamanBotIsEnabled = 0
        EQ_PrintTextToChat("Shaman Bot: Off")
    end

    return 1
end

function ShamanBot_Heal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_ShamanBotTargetName)
    EQ_InterpretCommand("//Cast 1")
end

function OnInterpretCommand(commandText)
    if commandText == "//ShamanBot" then
        ShamanBot_Toggle()
        return 1
    end

    if commandText == "//ShamanBotOn" then
        if g_ShamanBotIsEnabled == 0 then
            ShamanBot_Toggle()
        end
        return 1
    end

    if commandText == "//ShamanBotOff" then
        if g_ShamanBotIsEnabled == 1 then
            ShamanBot_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//ShamanBotTarget ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_ShamanBotTargetName = tokens[2]

            EQ_PrintTextToChat("Shaman Bot Target: " .. g_ShamanBotTargetName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_ShamanBotIsEnabled == 1 then
        return 1, "- Shaman Bot: " .. g_ShamanBotTargetName
    end
end

function OnFrame()
    if g_ShamanBotIsEnabled == 0 then
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

    EQ_InterpretCommand("//Target " .. g_ShamanBotTargetName)

    targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(80, 90)

        if targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_ShamanBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            ShamanBot_Heal()
        end
    end
end
