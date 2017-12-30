require(DIR_SCRIPT.."game/entity")

SynchronizedObject=class()

function SynchronizedObject:onCreate(id)
	self.id=id
	self.obj_type="common"
	Synchronizer:AddObject(self)
end

function SynchronizedObject:PostConstruct()
	self.entity=Scene.entities[self.id]
end

function SynchronizedObject:OnDestroy()
	Synchronizer.objects[self.id]=nil
end

function SynchronizedObject:OnSerialize( stream )
	if self.entity then
		local gameobject = self.entity.gameobject
		local rigid_body = gameobject:getRigidBody()
		if not rigid_body:isSimulationActive() then
			return
		end
		-- position
		BitStreamHelper.SerializeVector3(stream,gameobject:getPosition())
		-- rotation
		BitStreamHelper.SerializeVector3(stream,gameobject:getRotation())
		-- linear velocity
		BitStreamHelper.SerializeVector3(stream,rigid_body:getLinearVelocity())
		-- angular velocity
		BitStreamHelper.SerializeVector3(stream,rigid_body:getAngularVelocity())
	end
end

function SynchronizedObject:OnDeserialize( stream )
	if not self.entity then
		if not Scene.entities[self.id] then
			return
		else
			self:PostConstruct()		
		end
	end
	if self.entity and self.entity.gameobject then
		local gameobject = self.entity.gameobject
		local rigid_body = gameobject:getRigidBody()
		local temp_vec3 = irr.core.vector3df:new_local()
		-- position
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		gameobject:setPosition(temp_vec3)
		-- rotation
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		gameobject:setRotation(temp_vec3)
		-- linear velocity
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		rigid_body:setLinearVelocity(temp_vec3)
		-- angular velocity
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		rigid_body:setAngularVelocity(temp_vec3)

		rigid_body:activate(true)
	end
end

function SynchronizedObject:OnSerializeConstruct( stream )
	if self.entity then
		local gameobject = self.entity.gameobject
		-- position
		BitStreamHelper.SerializeVector3(stream,gameobject:getPosition())
		-- rotation
		BitStreamHelper.SerializeVector3(stream,gameobject:getRotation())

	end
end

function SynchronizedObject:OnDeserializeConstruction( stream )
	if self.entity and self.entity.gameobject then
		local gameobject = self.entity.gameobject
		local temp_vec3 = irr.core.vector3df:new_local()
		-- position
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		gameobject:setPosition(temp_vec3)
		-- rotation
		BitStreamHelper.DeserializeVector3(stream,temp_vec3)
		gameobject:setRotation(temp_vec3)
	end
end

function SynchronizedObject:OnPostDeserializeConstruct( stream )
	
end