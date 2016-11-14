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
--------------------------------------------
-- make directory
--------------------------------------------
function createDirectory( dirname )
    os.execute("mkdir " .. dirname)
end
--------------------------------------------
-- copy file
--------------------------------------------
function copyFile( inf, out )
    local inp = assert(io.open(inf, "rb"))
    local out = assert(io.open(out, "wb"))
    
    local data = inp:read("*all")
    out:write(data)
    
    assert(out:close())
end
--------------------------------------------
-- separate folder path and file name
--------------------------------------------
function parsePath( path )
    dir,file = path:match('(.*[/\\])(.*)')
    return dir, file
end
--------------------------------------------
-- id generator
--------------------------------------------
IDGenerator={
    ids={},
    Generate=function (self)
        local id=math.random(999999)
        while self.ids[id] do
            id=math.random(999999)
        end
        self.ids[id]=true
        return id
    end,
    Reset=function(self)
        self.ids={}
    end,
    Register=function (self,id)
        self.ids[id]=true
    end,
    Unregister=function( self, id )
        self.ids[id]=false
    end
}

function makeId()
    return IDGenerator:Generate()
end

function deleteId( id )
    IDGenerator:Unregister(id)
end