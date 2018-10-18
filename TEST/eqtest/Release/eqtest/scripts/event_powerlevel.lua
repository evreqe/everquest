g_PowerLevelIsEnabled = 0

g_PowerLevelHPDefault = 45

g_PowerLevelHP = g_PowerLevelHPDefault

g_PowerLevelNames = {}

function PowerLevel_Toggle()
    if g_PowerLevelIsEnabled == 0 then
        g_PowerLevelIsEnabled = 1
        EQ_PrintTextToChat("Power Level: On")
    else

        g_PowerLevelIsEnabled = 0
        EQ_PrintTextToChat("Power Level: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//PowerLevel" then
        PowerLevel_Toggle()
        return 1
    end

    if commandText == "//PowerLevelOn" then
        if g_PowerLevelIsEnabled == 0 then
            PowerLevel_Toggle()
        end
        return 1
    end

    if commandText == "//PowerLevelOff" then
        if g_PowerLevelIsEnabled == 1 then
            PowerLevel_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//PowerLevelHP ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_PowerLevelHP = tonumber(tokens[2])

            if g_PowerLevelHP <= 0 or g_PowerLevelHP >= 100 then
                g_PowerLevelHP = g_PowerLevelHPDefault
            end

            EQ_PrintTextToChat("Power Level HP%: " .. g_PowerLevelHP)
        end

        return 1
    end

    if String_BeginsWith(commandText, "//PowerLevelNames ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_PowerLevelNames = String_Split(tokens[2], ",")

            EQ_PrintTextToChat("Power Level Names: " .. table.concat(g_PowerLevelNames, ", "))
        end

        return 1
    end
end

function OnDrawHUD()
    if g_PowerLevelIsEnabled == 1 then
        return 1, "- Power Level: " .. g_PowerLevelHP .. "%"
    end
end

function OnOneSecond()
    if g_PowerLevelIsEnabled == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetType = EQ_GetSpawnType(targetSpawn)
    if targetType ~= EQ_SPAWN_TYPE_NPC then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP <= g_PowerLevelHP then
        for _,name in ipairs(g_PowerLevelNames) do
            EQ_InterpretCommand("//BCT " .. name .. " //Stand;//TargetID ${Target.ID};//Follow;//AutoAttackOn")
        end
    end
end
