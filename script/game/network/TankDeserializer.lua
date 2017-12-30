TankDeserializer={
	deserializers={}
}

function TankDeserializer:Deserialize( tank_entity, stream )
	local tank_type = tank_entity.tank_type
	if not stream then
		print("Error: null bitstream when deserializing tank")
	end
	if (not tank_type) or (not self.deserializers[tank_type]) then
		print("Unsupported tank type:",tank_type)
		return
	end
	self.deserializers[tank_type](tank_entity,stream)
end

TankDeserializer.deserializers.standard=function( tank_entity, stream )
	local components = tank_entity.components
	local rigid_tankbody = components.body.object:getRigidBody()
	local rigid_turret = components.turret.object:getRigidBody()
	local rigid_canon = components.canon.object:getRigidBody()
	local temp_vec3 = irr.core.vector3df:new_local()

	local body_pos = irr.core.vector3df:new_local()
	local body_rot = irr.core.vector3df:new_local()
	local turret_rot = irr.core.vector3df:new_local()
	local canon_rot = irr.core.vector3df:new_local()
	--body position
	BitStreamHelper.DeserializeVector3(stream,body_pos)
	--body rotation
	BitStreamHelper.DeserializeVector3(stream,body_rot)
	--body linear velocity
	BitStreamHelper.DeserializeVector3(stream,temp_vec3)
	rigid_tankbody:setLinearVelocity(temp_vec3)
	--body angular velocity
	BitStreamHelper.DeserializeVector3(stream,temp_vec3)
	rigid_tankbody:setAngularVelocity(temp_vec3)
	--turret rotation
	BitStreamHelper.DeserializeVector3(stream,turret_rot)
	--turret angular velocity
	BitStreamHelper.DeserializeVector3(stream,temp_vec3)
	rigid_turret:setAngularVelocity(temp_vec3)
	--canon rotation
	BitStreamHelper.DeserializeVector3(stream,canon_rot)
	--canon angular velocity
	BitStreamHelper.DeserializeVector3(stream,temp_vec3)
	rigid_canon:setAngularVelocity(temp_vec3)
	
	local transform = irr.core.matrix4:new_local()
	transform:setTranslation(body_pos)
	transform:setRotationDegrees(body_rot)

	tank_entity:SynchronizeTransform(transform,{turret_rotation=turret_rot,canon_rotation=canon_rot})
end