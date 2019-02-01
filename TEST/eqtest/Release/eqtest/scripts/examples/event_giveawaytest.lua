g_GiveawayTestClock = os.clock
function GiveawayTest_Sleep(n)  -- seconds
    local t0 = g_GiveawayTestClock()
    while g_GiveawayTestClock() - t0 <= n do end
end

function OnChatText(chatText, chatTextColor)
    if String_Contains(chatText, "") == false then
        return
    end

    local playerName = EQ_GetPlayerSpawnName()
    if String_Contains(chatText, playerName) == true then
        return
    end

    if String_Contains(chatText, "1Jenhunda") == false then
        return
    end

    if String_Contains(chatText, "tells General:1") == false then
        return
    end

    for m in string.gmatch(chatText, "\018%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x[%w%s%p]+\018") do
        if String_Contains(m, "00000000000000000000000000000000000000000000000000000000") == false then
            GiveawayTest_Sleep(1)
            EQ_InterpretCommand("/say " .. m)
        end
    end
end
