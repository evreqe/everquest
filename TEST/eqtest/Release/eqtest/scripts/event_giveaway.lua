g_GiveawayIsEnabled = 0

g_GiveawayPlayerName = "Jenhunda"

g_GiveawayItemName = "Symbol of the Dragon's Scale"

g_GiveawayClock = os.clock
function Giveaway_Sleep(n)  -- seconds
  local t0 = g_GiveawayClock()
  while g_GiveawayClock() - t0 <= n do end
end

function Giveaway_Toggle()
    if g_GiveawayIsEnabled == 0 then
        g_GiveawayIsEnabled = 1
        EQ_PrintTextToChat("Giveaway: On")
    else

        g_GiveawayIsEnabled = 0
        EQ_PrintTextToChat("Giveaway: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//Giveaway" then
        Giveaway_Toggle()
        return 1
    end

    if commandText == "//GiveawayOn" then
        if g_GiveawayIsEnabled == 0 then
            Giveaway_Toggle()
        end
        return 1
    end

    if commandText == "//GiveawayOff" then
        if g_GiveawayIsEnabled == 1 then
            Giveaway_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//GiveawayPlayer ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_GiveawayPlayerName = tokens[2]

            EQ_PrintTextToChat("Giveaway Player Name: " .. g_GiveawayPlayerName)
        end

        return 1
    end

    if String_BeginsWith(commandText, "//GiveawayItem ") == true then
        g_GiveawayItemName = string.sub(commandText, 16, -1)

        EQ_PrintTextToChat("Giveaway Item Name: " .. g_GiveawayItemName)

        return 1
    end
end

function OnDrawHUD()
    if g_GiveawayIsEnabled == 1 then
        return 1, "- Giveaway: " .. g_GiveawayPlayerName .. " (" .. g_GiveawayItemName .. ")"
    end
end

function OnChatText(chatText, chatTextColor)
    if g_GiveawayIsEnabled == 0 then
        return
    end

    EQAPP_PrintTextToFile("giveaway.txt", chatText)

    if String_Contains(chatText, "") == false then
        return
    end

    local playerName = EQ_GetPlayerSpawnName()
    if String_Contains(chatText, playerName) == true then
        return
    end

    if g_GiveawayPlayerName == "" or g_GiveawayItemName == "" then
        return
    end

    if String_Contains(chatText, "1" .. g_GiveawayPlayerName .. "") == false then
        return
    end

    if String_Contains(chatText, "tells General:1") == false then
        return
    end

    for m in string.gmatch(chatText, "\018%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x[%w%s%p]+\018") do
        if String_Contains(m, g_GiveawayItemName) == true then
            Giveaway_Sleep(1)
            EQ_InterpretCommand("/1 " .. m)
            g_GiveawayIsEnabled = 0
            EQ_PrintTextToChat("Giveaway: Off")
            break
        end
    end
end
