function OnChatText(chatText, chatTextColor)
    --EQAPP_PrintTextToFile("chattext.txt", chatText)

    if String_Contains(chatText, "") then
        if String_Contains(chatText, "tells General:1") == true then
            for m in string.gmatch(chatText, "\018%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x[%w%s%p]+\018") do
                EQAPP_PrintTextToFile("itemlinks.txt", m)
            end
        end
    end
end
