function String_BeginsWith(subject, search)
   return string.sub(subject, 1, string.len(search)) == search
end

function String_EndsWith(subject, search)
   return search == '' or string.sub(subject, -string.len(search)) == search
end

function GroupSay(text)
    EQ_InterpretCommand("/gsay " .. text)
end

function OnChatText(chatText, chatTextColor)

    if String_BeginsWith(chatText, "You have been assigned the task ") then
        return GroupSay(chatText)
    end

end
