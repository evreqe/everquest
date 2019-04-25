g_DruidBotIsEnabled = 0

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
    EQ_InterpretCommand("//Cast 1")
end

function DruidBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 3")
end

function DruidBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 4")
end

function DruidBot_GroupHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 5")
end

function DruidBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function DruidBot_DyingHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 4")
end

function DruidBot_HealTarget()
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
        EQ_UseAlternateAbilityByName("Spirit of the Bear")
        DruidBot_DyingHeal()
        DruidBot_SaveHeal()
        DruidBot_InstantHeal()
        return 1
    elseif targetHPPercent <= 35 then
        EQ_UseAlternateAbilityByName("Wildtender's Survival")
        DruidBot_SaveHeal()
        DruidBot_InstantHeal()
        return 1
    elseif targetHPPercent <= 50 then
        EQ_UseAlternateAbilityByName("Nature's Blessing")
        DruidBot_InstantHeal()
        DruidBot_FastHeal()
        return 1
    elseif targetHPPercent <= fastHealHP then
        DruidBot_FastHeal()
        DruidBot_BigHeal()
        return 1
    end

    return 0
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
end

function OnDrawHUD()
    if g_DruidBotIsEnabled == 1 then
        return 1, "- Druid Bot"
    end
end

function OnFrame()
    if g_DruidBotIsEnabled == 0 then
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
        EQ_UseAlternateAbilityByName("Group Spirit of the White Wolf")
        EQ_UseAlternateAbilityByName("Nature's Boon")
        EQ_UseAlternateAbilityByName("Fundament: Third Spire of Nature")
        DruidBot_GroupHeal()
        return
    end

    local groupMemberSpawnWithLowestHPPercent = EQ_GetGroupMemberSpawnWithLowestHPPercent()
    if groupMemberSpawnWithLowestHPPercent ~= 0 then
        local groupMemberHPPercent = EQ_GetSpawnHPPercent(groupMemberSpawnWithLowestHPPercent)
        if groupMemberHPPercent <= 90 then
            EQ_SetTargetSpawn(groupMemberSpawnWithLowestHPPercent)
            if DruidBot_HealTarget() == 1 then
                return
            end
        end
    end

    local groupLeaderSpawn = EQ_GetGroupLeaderSpawn()
    if groupLeaderSpawn ~= 0 then
        local groupLeaderHPPercent = EQ_GetSpawnHPPercent(groupLeaderSpawn)
        if groupLeaderHPPercent <= 90 then
            EQ_SetTargetSpawn(groupLeaderSpawn)
            if DruidBot_HealTarget() == 1 then
                return
            end
        end
    end
end
