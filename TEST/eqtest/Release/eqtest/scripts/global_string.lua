function String_BeginsWith(subject, search)
   return string.sub(subject, 1, string.len(search)) == search
end

function String_EndsWith(subject, search)
   return search == '' or string.sub(subject, -string.len(search)) == search
end
