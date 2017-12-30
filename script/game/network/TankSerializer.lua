TankSerializer={
	serializers={}
}

function TankSerializer:Serialize( tank_entity, stream )
	local tank_type = tank_entity.tank_type
	if not stream then
		print("Error: null bitstream when serializing tank")
		return
	end
	if (not tank_type) or (not self.serializers[tank_type]) then
		print("Unsupported tank type:",tank_type)
		return
	end
	self.serializers[tank_type](tank_entity,stream)
end

TankSerializer.serializers.standard=function( tank_entity, stream )
	local components = tank_entity.components
	local rigid_tankbody = components.body.object:getRigidBody()
	local rigid_turret = components.turret.object:getRigidBody()
	local rigid_canon = components.canon.object:getRigidBody()
	--body position
	BitStreamHelper.SerializeVector3(stream,components.body.object:getPosition())
	--body rotation
	BitStreamHelper.SerializeVector3(stream,components.body.object:getRotation())
	--body linear velocity
	BitStreamHelper.SerializeVector3(stream,rigid_tankbody:getLinearVelocity())
	--body angular velocity
	BitStreamHelper.SerializeVector3(stream,rigid_tankbody:getAngularVelocity())
	--turret rotation
	BitStreamHelper.SerializeVector3(stream,components.turret.object:getRotation())
	--turret angular velocity
	BitStreamHelper.SerializeVector3(stream,rigid_turret:getAngularVelocity())
	--canon rotation
	BitStreamHelper.SerializeVector3(stream,components.canon.object:getRotation())
	--canon angular velocity
	BitStreamHelper.SerializeVector3(stream,rigid_canon:getAngularVelocity())
end