g_SpawnBeepIsEnabled = 0

g_SpawnBeepName = ""

function SpawnBeep_Toggle()
    if g_SpawnBeepIsEnabled == 0 then
        g_SpawnBeepIsEnabled = 1
        EQ_PrintTextToChat("Spawn Beep: On")
    else

        g_SpawnBeepIsEnabled = 0
        EQ_PrintTextToChat("Spawn Beep: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//SpawnBeep" then
        SpawnBeep_Toggle()
        return 1
    end

    if commandText == "//SpawnBeepOn" then
        if g_SpawnBeepIsEnabled == 0 then
            SpawnBeep_Toggle()
        end
        return 1
    end

    if commandText == "//SpawnBeepOff" then
        if g_SpawnBeepIsEnabled == 1 then
            SpawnBeep_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//SpawnBeepName ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_SpawnBeepName = tokens[2]

            EQ_PrintTextToChat("Spawn Beep Name: " .. g_SpawnBeepName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_SpawnBeepIsEnabled == 1 then
        return 1, "- Spawn Beep Name: " .. g_SpawnBeepName
    end
end

function OnTick()
    if g_SpawnBeepIsEnabled == 0 then
        return
    end

    if g_SpawnBeepName == "" then
        return
    end

    local spawn = EQ_GetFirstSpawn()

    while spawn ~= 0 do
        local spawnType = EQ_GetSpawnType(spawn)
        if spawnType == EQ_SPAWN_TYPE_NPC then
            local spawnName = EQ_GetSpawnName(spawn)
            if String_Contains(spawnName, g_SpawnBeepName) == true then
                EQAPP_Beep()
            end
        end

        spawn = EQ_GetSpawnNext(spawn)
    end
end
