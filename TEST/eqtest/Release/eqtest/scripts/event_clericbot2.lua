g_ClericBotIsEnabled = 0

g_ClericBotTargetName = "Skaj"

function ClericBot_Toggle()
    if g_ClericBotIsEnabled == 0 then
        g_ClericBotIsEnabled = 1
        EQ_PrintTextToChat("Cleric Bot: On")
        EQ_ClearTarget()
    else
        g_ClericBotIsEnabled = 0
        EQ_PrintTextToChat("Cleric Bot: Off")
    end

    return 1
end

function ClericBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 1")
end

function ClericBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 3")
end

function ClericBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 4")
end

function ClericBot_GroupHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 5")
end

function ClericBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function ClericBot_HealTarget()
    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return 0
    end

    local targetHPPercent = EQ_GetSpawnHPPercent(targetSpawn)
    if targetHPPercent == 0 then
        return 0
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

    math.randomseed(os.time() + playerHP)

    local fastHealHP = math.random(80, 90)

    if targetHPPercent <= 35 then
        ClericBot_SaveHeal()
        ClericBot_InstantHeal()
        return 1
    elseif targetHPPercent <= 50 then
        ClericBot_InstantHeal()
        ClericBot_FastHeal()
        return 1
    elseif targetHPPercent <= fastHealHP then
        ClericBot_FastHeal()
        ClericBot_BigHeal()
        return 1
    end

    return 0
end

function OnInterpretCommand(commandText)
    if commandText == "//ClericBot" then
        ClericBot_Toggle()
        return 1
    end

    if commandText == "//ClericBotOn" then
        if g_ClericBotIsEnabled == 0 then
            ClericBot_Toggle()
        end
        return 1
    end

    if commandText == "//ClericBotOff" then
        if g_ClericBotIsEnabled == 1 then
            ClericBot_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//ClericBotTarget ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_ClericBotTargetName = tokens[2]

            EQ_PrintTextToChat("Cleric Bot Target: " .. g_ClericBotTargetName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_ClericBotIsEnabled == 1 then
        return 1, "- Cleric Bot" .. g_ClericBotTargetName
    end
end

function OnFrame()
    if g_ClericBotIsEnabled == 0 then
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

    local groupAverageHPPercent = EQ_GetGroupAverageHPPercent()
    if groupAverageHPPercent <= 50 then
        ClericBot_GroupHeal()
        return
    end

    local groupMemberSpawnWithLowestHPPercent = EQ_GetGroupMemberSpawnWithLowestHPPercent()
    if groupMemberSpawnWithLowestHPPercent ~= 0 then
        local groupMemberHPPercent = EQ_GetSpawnHPPercent(groupMemberSpawnWithLowestHPPercent)
        if groupMemberHPPercent <= 90 then
            EQ_SetTarget(groupMemberSpawnWithLowestHPPercent)
            if ClericBot_HealTarget() == 1 then
                return
            end
        end
    end

    local groupLeaderSpawn = EQ_GetGroupLeaderSpawn()
    if groupLeaderSpawn ~= 0 then
        local groupLeaderHPPercent = EQ_GetSpawnHPPercent(groupLeaderSpawn)
        if groupLeaderHPPercent <= 90 then
            EQ_SetTarget(groupLeaderSpawn)
            if ClericBot_HealTarget() == 1 then
                return
            end
        end
    end
end
