g_PriestBot2IsEnabled = 0

g_PriestBot2TargetName = "Skaj"

function PriestBot2_Toggle()
    if g_PriestBot2IsEnabled == 0 then
        g_PriestBot2IsEnabled = 1
        EQ_PrintTextToChat("Priest Bot 2: On")
        EQ_ClearTarget()
    else
        g_PriestBot2IsEnabled = 0
        EQ_PrintTextToChat("Priest Bot 2: Off")
    end

    return 1
end

function PriestBot2_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
    EQ_InterpretCommand("//Cast 1")
end

function PriestBot2_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
    EQ_InterpretCommand("//Cast 3")
end

function PriestBot2_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
    EQ_InterpretCommand("//Cast 4")
end

function PriestBot2_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
    EQ_InterpretCommand("//Cast 7")
end

function PriestBot2_HealOverTimeAndWardOfVie()
    if EQ_BuffWindows_FindBuffSpellName("Elixir of the Seas Rk. II") == false then
        EQ_InterpretCommand("//StopFollow")
        EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
        EQ_InterpretCommand("//Cast 6")
    else
        if EQ_TargetWindow_FindBuffSpellName("Rallied Greater Ward of Vie Rk. II") == false then
            EQ_InterpretCommand("//StopFollow")
            EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)
            EQ_InterpretCommand("//Cast 9")
        end
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//PriestBot2" then
        PriestBot2_Toggle()
        return 1
    end

    if commandText == "//PriestBot2On" then
        if g_PriestBot2IsEnabled == 0 then
            PriestBot2_Toggle()
        end
        return 1
    end

    if commandText == "//PriestBot2Off" then
        if g_PriestBot2IsEnabled == 1 then
            PriestBot2_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//PriestBot2Target ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_PriestBot2TargetName = tokens[2]

            EQ_PrintTextToChat("Priest Bot 2 Target: " .. g_PriestBot2TargetName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_PriestBot2IsEnabled == 1 then
        return 1, "- Priest Bot 2 : " .. g_PriestBot2TargetName
    end
end

function OnFrame()
    if g_PriestBot2IsEnabled == 0 then
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

    EQ_InterpretCommand("//Target " .. g_PriestBot2TargetName)

    targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(80, 90)

        if targetHP <= 99 then
            PriestBot2_HealOverTimeAndWardOfVie()
        end

        if targetHP <= 35 then
            PriestBot2_SaveHeal()
            PriestBot2_InstantHeal()
        elseif targetHP <= 50 then
            PriestBot2_InstantHeal()
            PriestBot2_FastHeal()
        elseif targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_PriestBot2TargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            PriestBot2_FastHeal()
            PriestBot2_BigHeal()
        end
    end
end
