function GroupSay(text)
    EQ_InterpretCommand("/gsay " .. text)
end

function OnChatText(chatText, chatTextColor)
    if String_BeginsWith(chatText, "You have been assigned the task") then
        return GroupSay(chatText)
    end

    if String_BeginsWith(chatText, "You have reached the AA point cap") then
        return GroupSay(chatText)
    end

    if String_BeginsWith(chatText, "Your task") then
        if String_EndsWith(chatText, "has been updated.") then
            return GroupSay(chatText)
        end
    end
end
