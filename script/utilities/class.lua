--用lua实现OOP,修改子云风的bolg:http://blog.codingnow.com/cloud/LuaOO
local _class={}
 
function class(super)
	local class_type={}
	class_type.onCreate=false
	class_type.super=super
	class_type.new=function(...) 
			local obj={}
			do
				local create
				create = function(c,...)
					if c.super then
						create(c.super,...)
					end
					if c.onCreate then
						c.onCreate(obj,...)
					end
				end
 
				create(class_type,...)
			end
			setmetatable(obj,{ __index=_class[class_type] })
			return obj
		end
	local value_table={}
	_class[class_type]=value_table
 
	setmetatable(class_type,{__newindex=
		function(table,key,value)
			value_table[key]=value
		end
	})
 
	if super then
		setmetatable(value_table,{__index=
			function(table,key)
				local ret=_class[super][key]
				value_table[key]=ret
				return ret
			end
		})
	end
 
	return class_type
end