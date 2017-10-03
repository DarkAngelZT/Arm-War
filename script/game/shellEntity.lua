require(DIR_SCRIPT.."game/logic")

ShellFactory={
	prototype={},
	init=function( self, type_list )
		for _,v in ipairs(type_list) do
			local shell_info = assert(readAllText(DIR_SHELL..v..".info"))
			local shell={}
			shell.property=eval("{"..shell_info.."}")
			shell.mesh=NeoGraphics:getInstance():getMesh(DIR_SHELL..shell.property.model)
			shell.collision_shape_index=NeoPhysics:getInstance():CreateConvexHullShape(shell.mesh)
			self.prototype[v]=shell
		end
	end,
	clear=function( self )
		for k,v in pairs(self.prototype) do
			NeoPhysics:getInstance():RemoveCollisionShape(v.collision_shape_index)
			prototype[k]=nil
		end
	end,
	create=function( self, shell_type )
		if self.prototype then
			local prototype = self.prototype[shell_type]
			if not prototype then
				return
			end
			local object = NeoScene:getInstance():CreateGameObject()
			local node=NeoGraphics:getInstance():AddAnimatedMeshSceneNode(prototype.mesh)
			object:setSceneNode(node)
			object:AddRigidBody(prototype.collision_shape_index,prototype.property.mass)
			local shell = ShellEntity.new()
			shell.gameobject=object
			shell.shell_type=shell_type
			shell.property=deepcopy(prototype.property)
			return shell
		end
	end
}

ShellEntity=class(Entity)
ShellEntity.name="ShellEntity"
ShellEntity.gameobject=nil
ShellEntity.property={}
ShellEntity.owner=nil
ShellEntity.shell_type="AP"
function ShellEntity:setActive( state )
	self.gameobject:setActive(state)
end

function ShellEntity.Load( data, logic_data )
	local shell = ShellEntity.create(data)
	for k,v in pairs(logic_data) do
		shell[k]=v
	end
	return shell
end
--data variable:
--shell_type, position, rotation
function ShellEntity.create( data )
	local shell = ShellFactory:create(data.shell_type)
	shell.gameobject:setPosition(data.position)
	shell.gameobject:setRotation(data.rotation)
	shell.id="sh"..makeId()
	shell.gameobject:setLuaIdentifier(shell.id)
	shell.gameobject:setOnCollisionEnterLuaCallback("ShellEntity.OnCollisionEnter")
	Scene.entities[shell.id]=shell
	return shell
end
--param variable:
--shell_type, position, rotation
function ShellEntity:setParameters( param )
	self.gameobject:setPosition(param.position)
	self.gameobject:setRotation(param.rotation)
end

function ShellEntity:Destroy()
	NeoScene:getInstance():DestroyGameObject(self.gameobject,true)
	Scene.entities[shell.id]=nil
end

function ShellEntity.OnCollisionEnter( id_self, id_another )
	local target = Scene.entities[id_another]
	local shell=Scene.entities[id_self]
	if target.actor then
		--触发击中事件
		NeoGameLogic:getInstance():TriggerEvent(Logic.EVENT.SHELL_HIT,target.actor.id,id_self)
	end
	Scene.shell_pool[shell.shell_type]:returnObject(shell)
end

-----------------
--event handler
-----------------
ShellEntity.event_handlers={
}

function ShellEntity.RegisterSingleModeEventHandler( )
end