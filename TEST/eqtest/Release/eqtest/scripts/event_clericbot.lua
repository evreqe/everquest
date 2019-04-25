g_ClericBotIsEnabled = 0

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

function ClericBot_GroupHOT()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 6")
end

function ClericBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function ClericBot_DyingHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 9")
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

    if targetHPPercent <= 15 then
        EQ_UseAlternateAbilityByName("Quiet Prayer")
        ClericBot_DyingHeal()
        ClericBot_SaveHeal()
        ClericBot_InstantHeal()
        return 1
    elseif targetHPPercent <= 35 then
        EQ_UseAlternateAbilityByName("Celestial Rapidity")
        EQ_UseAlternateAbilityByName("Burst of Life")
        ClericBot_SaveHeal()
        ClericBot_InstantHeal()
        return 1
    elseif targetHPPercent <= 50 then
        EQ_UseAlternateAbilityByName("Flurry of Life")
        EQ_UseAlternateAbilityByName("Healing Frenzy")
        EQ_UseAlternateAbilityByName("Celestial Regeneration")
        ClericBot_InstantHeal()
        ClericBot_FastHeal()
        return 1
    elseif targetHPPercent <= fastHealHP then
        EQ_UseAlternateAbilityByName("Healing Frenzy")
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
end

function OnDrawHUD()
    if g_ClericBotIsEnabled == 1 then
        return 1, "- Cleric Bot"
    end
end

function OnFrame()
    if g_ClericBotIsEnabled == 0 then
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
    if groupAverageHPPercent == -1 then
        return
    end

    if groupAverageHPPercent <= 60 then
        EQ_UseAlternateAbilityByName("Channeling the Divine")
        EQ_UseAlternateAbilityByName("Exquisite Benediction")
        EQ_UseAlternateAbilityByName("Fundament: Third Spire of Divinity")
        EQ_UseAlternateAbilityByName("Beacon of Life")
        ClericBot_GroupHeal()
        return
    elseif groupAverageHPPercent <= 80 then
        ClericBot_GroupHOT()
        return
    end

    local groupLeaderSpawn = EQ_GetGroupLeaderSpawn()
    if groupLeaderSpawn == 0 then
        return
    end

    local groupLeaderHPPercent = EQ_GetSpawnHPPercent(groupLeaderSpawn)
    if groupLeaderHPPercent <= 90 then
        EQ_SetTargetSpawn(groupLeaderSpawn)
        if ClericBot_HealTarget() == 1 then
            return
        end
    end

    local groupMemberSpawnWithLowestHPPercent = EQ_GetGroupMemberSpawnWithLowestHPPercent()
    if groupMemberSpawnWithLowestHPPercent ~= 0 then
        local groupMemberHPPercent = EQ_GetSpawnHPPercent(groupMemberSpawnWithLowestHPPercent)
        if groupMemberHPPercent <= 90 then
            EQ_SetTargetSpawn(groupMemberSpawnWithLowestHPPercent)
            if ClericBot_HealTarget() == 1 then
                return
            end
        end
    end
end
