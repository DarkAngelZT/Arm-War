--define basice object for map editor
EditorObject=class()
EditorObject.scene_type="mesh_static"
EditorObject.physics_type="static"
EditorObject.position=irr.core.vector3df:new_local()
EditorObject.rotation=irr.core.vector3df:new_local()
EditorObject.scale=irr.core.vector3df:new_local(1,1,1)
EditorObject.scene_node=nil

function EditorObject:setPosition(position)
	-- body
	if(self.scene_node) then
		self.position=position
		self.scene_node:setPosition(position)
	end
end

function EditorObject:setRotation( rotation )
	-- body
	if self.scene_node then
		self.rotation=rotation
		self.scene_node:setRotaion(rotation)
	end
end

function EditorObject:setScale( scale )
	-- body
	if self.scene_node then
		self.scene_node:setScale(scale)
		self.rotation=scale
	end
end

function EditorObject:setSceneNode( node )
	-- body
	if node then
		self.scene_node=node
		self.position=node:getPosition()
		self.rotation=node:getRotation()
		self.scale=node:getScale()
	end
end

function EditorObject:Serialize( distObjName, fileWriter )
	if fileWriter then
		--begin
		fileWriter:write(distObjName.." = {\n")
		--body
		
		--enclosure
		fileWriter:write("\n} -- "..distObjName)
	end
end

function EditorObject:Clone()
	obj=EditorObject.new()
	obj.scene_type=self.scene_type
	obj.physics_type=self.physics_type
	obj.position=self.position
	obj.rotation=self.rotation
	obj.scale=self.scale
	obj.scene_node=self.scene_node

	return obj
end
--[[map editor functions
these are additional functions for map_editor
]]