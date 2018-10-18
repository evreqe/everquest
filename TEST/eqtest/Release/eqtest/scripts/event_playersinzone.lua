g_PlayersInZoneIsEnabled = 0

g_PlayersInZoneCount = 0

g_PlayersInZoneBeepCount = 0

function PlayersInZone_Toggle()
    if g_PlayersInZoneIsEnabled == 0 then
        g_PlayersInZoneIsEnabled = 1
        EQ_PrintTextToChat("Players in Zone: On")
    else

        g_PlayersInZoneIsEnabled = 0
        EQ_PrintTextToChat("Players in Zone: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//PlayersInZone" then
        PlayersInZone_Toggle()
        return 1
    end

    if commandText == "//PlayersInZoneOn" then
        if g_PlayersInZoneIsEnabled == 0 then
            PlayersInZone_Toggle()
        end
        return 1
    end

    if commandText == "//PlayersInZoneOff" then
        if g_PlayersInZoneIsEnabled == 1 then
            PlayersInZone_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//PlayersInZoneBeepCount ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_PlayersInZoneBeepCount = tonumber(tokens[2])

            EQ_PrintTextToChat("Players in Zone Beep Count: " .. g_PlayersInZoneBeepCount)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_PlayersInZoneIsEnabled == 1 then
        return 1, "- Players in Zone: " .. g_PlayersInZoneCount .. " (Beep: >" .. g_PlayersInZoneBeepCount .. ")"
    end
end

function OnTick()
    if g_PlayersInZoneIsEnabled == 0 then
        return
    end

    local numPlayers = 0

    local spawn = EQ_GetFirstSpawn()

    while spawn ~= 0 do
        local spawnType = EQ_GetSpawnType(spawn)
        if spawnType == EQ_SPAWN_TYPE_PLAYER then
            numPlayers = numPlayers + 1
        end

        spawn = EQ_GetSpawnNext(spawn)
    end

    g_PlayersInZoneCount = numPlayers

    if g_PlayersInZoneBeepCount > 0 then
        if g_PlayersInZoneCount > g_PlayersInZoneBeepCount then
            EQAPP_Beep()
        end
    end

end
