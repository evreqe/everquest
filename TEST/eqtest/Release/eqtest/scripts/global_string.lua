function String_Contains(subject, search)
    return string.find(subject, search) ~= nil
end

function String_BeginsWith(subject, search)
   return string.sub(subject, 1, string.len(search)) == search
end

function String_EndsWith(subject, search)
   return search == '' or string.sub(subject, -string.len(search)) == search
end

function String_Split(subject, delimiter)
    result = {}

    for match in (subject .. delimiter):gmatch("(.-)" .. delimiter) do
        table.insert(result, match)
    end

    return result
end

function String_RemoveLastCharacter(subject)
    return subject:sub(1, -2)
end
