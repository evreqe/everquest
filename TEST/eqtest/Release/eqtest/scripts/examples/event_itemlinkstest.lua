function OnChatText(chatText, chatTextColor)
    if String_Contains(chatText, "") then
        local m = string.gmatch(chatText, "\018%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x[%w%s%p]+\018")
        for v in m do
            EQAPP_PrintTextToFile("itemlinkstest.txt", v)
        end
    end
end
