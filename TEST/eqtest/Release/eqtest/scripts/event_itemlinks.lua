function OnChatText(chatText, chatTextColor)
    if String_Contains(chatText, "") then
        if String_Contains(chatText, "tells General:1") == true then
            for m in string.gmatch(chatText, "\018%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x[%w%s%p]+\018") do
                if String_Contains(m, "00000000000000000000000000000000000000000000000000000000") == false then
                    EQAPP_PrintTextToFile("itemlinks.txt", m)
                end
            end
        end
    end
end
