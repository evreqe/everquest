function String_Contains(subject, search)
    return string.find(subject, search) ~= nil
end

function String_BeginsWith(subject, search)
   return string.sub(subject, 1, string.len(search)) == search
end

function String_EndsWith(subject, search)
   return search == '' or string.sub(subject, -string.len(search)) == search
end
