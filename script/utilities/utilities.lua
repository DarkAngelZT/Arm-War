--------------------------------------------
-- deepcopy functions
--------------------------------------------
function deepcopy(orig)
    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in next, orig, nil do
            copy[deepcopy(orig_key)] = deepcopy(orig_value)
        end
        setmetatable(copy, deepcopy(getmetatable(orig)))
    else -- number, string, boolean, etc
        copy = orig
    end
    return copy
end
--------------------------------------------
-- string split functions
--------------------------------------------
function split( str,patern)
    local iter=string.gmatch(str,"[^"..patern.."]+")
    local result = {}
    for i in iter do
        table.insert(result,i)
    end
    return result
end