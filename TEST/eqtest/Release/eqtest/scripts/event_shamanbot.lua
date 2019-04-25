g_ShamanBotIsEnabled = 0

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

function ShamanBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 1")
end

function ShamanBot_GroupHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 2")
end

function ShamanBot_GroupHOT()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 3")
end

function ShamanBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function ShamanBot_DyingHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 6")
end

function ShamanBot_HealTarget()
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

    if targetHPPercent <= 15 then
        EQ_UseAlternateAbilityByName("Spiritual Blessing")
        ShamanBot_DyingHeal()
        ShamanBot_SaveHeal()
        ShamanBot_GroupHeal()
        return 1
    elseif targetHPPercent <= 35 then
        EQ_UseAlternateAbilityByName("Soothsayer's Intervention")
        EQ_UseAlternateAbilityByName("Union of Spirits")
        ShamanBot_SaveHeal()
        ShamanBot_GroupHOT()
        return 1
    elseif targetHPPercent <= 60 then
        EQ_UseAlternateAbilityByName("Spirit Guardian")
        EQ_UseAlternateAbilityByName("Ancestral Aid")
        ShamanBot_GroupHeal()
        ShamanBot_BigHeal()
        return 1
    elseif targetHPPercent <= fastHealHP then
        ShamanBot_BigHeal()
        return 1
    end

    return 0
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
end

function OnDrawHUD()
    if g_ShamanBotIsEnabled == 1 then
        return 1, "- Shaman Bot"
    end
end

function OnFrame()
    if g_ShamanBotIsEnabled == 0 then
        return
    end

    if EQ_CastingWindow_IsOpen() == true then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local groupAverageHPPercent = EQ_GetGroupAverageHPPercent()
    if groupAverageHPPercent ~= -1 and groupAverageHPPercent <= 60 then
        EQ_UseAlternateAbilityByName("Fundament: Second Spire of Ancestors")
        EQ_UseAlternateAbilityByName("Call of the Ancients")
        ShamanBot_GroupHeal()
        return
    end

    local groupMemberSpawnWithLowestHPPercent = EQ_GetGroupMemberSpawnWithLowestHPPercent()
    if groupMemberSpawnWithLowestHPPercent ~= 0 then
        local groupMemberHPPercent = EQ_GetSpawnHPPercent(groupMemberSpawnWithLowestHPPercent)
        if groupMemberHPPercent <= 90 then
            EQ_SetTargetSpawn(groupMemberSpawnWithLowestHPPercent)
            if ShamanBot_HealTarget() == 1 then
                return
            end
        end
    end

    local groupLeaderSpawn = EQ_GetGroupLeaderSpawn()
    if groupLeaderSpawn ~= 0 then
        local groupLeaderHPPercent = EQ_GetSpawnHPPercent(groupLeaderSpawn)
        if groupLeaderHPPercent <= 90 then
            EQ_SetTargetSpawn(groupLeaderSpawn)
            if ShamanBot_HealTarget() == 1 then
                return
            end
        end
    end
end
