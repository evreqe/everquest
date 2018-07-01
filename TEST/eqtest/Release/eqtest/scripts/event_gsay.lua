function GroupSay(text)
    EQ_InterpretCommand("/gsay " .. text)
end

function OnChatText(chatText, chatTextColor)
    if String_BeginsWith(chatText, "You have been assigned the task ") then
        return GroupSay(chatText)
    end
end
