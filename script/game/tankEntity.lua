require(DIR_SCRIPT.."game/logic")

TankEntityLoader={
	standard=StandardTankEntity
}

StandardTankEntity=class(Entity)
StandardTankEntity.tank_type="standard"
StandardTankEntity.actor=nil
StandardTankEntity.property={}
StandardTankEntity.components={
	body={object=nil},
	left_track={object=nil},
	right_track={object=nil},
	turret={object=nil},
	canon={object=nil},
	fire_position=irr.core.vector3df:new_local(),
	body_hinge=nil,
	turret_hinge=nil,
	canon_hinge=nil,
	left_track_hinge=nil,
	right_track_hinge=nil
}
StandardTankEntity.fire_effector=nil
--@transform:matrix4
function StandardTankEntity:setTransform(transform)
	local body = self.components.body
	local trans = irr.core.matrix4:new_local(
		self.components.body.object:GetSceneNode():getAbsoluteTransformation())
	trans:makeInverse()
	--转换坐标
	local turret = self.components.turret
	local canon = self.components.canon
	local left_track = self.components.left_track
	local right_track = self.components.right_track

	local turret_trans = trans*turret.object:GetSceneNode():getAbsoluteTransformation()
	local canon_trans = trans*canon.object:GetSceneNode():getAbsoluteTransformation()
	local left_track_trans = trans*left_track.object:getRigidBody():getCenterOfMassTransform()
	local right_track_trans = trans*right_track.object:getRigidBody():getCenterOfMassTransform()

	turret_trans=transform*turret_trans
	canon_trans=transform*canon_trans
	left_track_trans=transform*left_track_trans
	right_track_trans=transform*right_track_trans

	body.object:setPosition(transform:getTranslation())
	body.object:setRotation(transform:getRotationDegrees())

	turret.object:setPosition(turret_trans:getTranslation())
	turret.object:setRotation(turret_trans:getRotationDegrees())

	canon.object:setPosition(canon_trans:getTranslation())
	canon.object:setRotation(canon_trans:getRotationDegrees())

	left_track.object:setPosition(left_track_trans:getTranslation())
	left_track.object:setRotation(left_track_trans:getRotationDegrees())

	right_track.object:setPosition(right_track_trans:getTranslation())
	right_track.object:setRotation(right_track_trans:getRotationDegrees())
end

function StandardTankEntity:setTurretAngle( angle_degree )
	local hinge = self.components.turret_hinge
	local current_angle = math.deg(hinge:getHingeAngle())
	if current_angle<0 then
		current_angle=current_angle+360
	end
	local d = math.min(
		angle_degree-current_angle,360-angle_degree+current_angle)/self.property.turret_rotation_speed
	if angle_degree>180 then
		angle_degree=angle_degree-360
	end
	d=math.abs(d)
	if d<0.1 then
		d=0.1
	end
	hinge:setMotorTarget(math.rad(angle_degree),d)
end

function StandardTankEntity:setCanonAngle( angle_degree )
	local hinge = self.components.canon_hinge
	local current_angle = math.deg(hinge:getHingeAngle())
	--print(current_angle)

	hinge:setMotorTarget(math.rad(angle_degree),1)
end

function StandardTankEntity:setTrackSpeed( side, speed )
	if side=="left" then
		self.components.left_track.object:setSpeed(speed)
	else
		self.components.right_track.object:setSpeed(speed)
	end
	local wheel_dir=-1
	local track_dir = irr.core.vector2df(-1,0)
	if speed<0 then
		wheel_dir=1
		track_dir.X=1
	end

	self.components.body.object:setWheelAnimationSpeed(8/math.abs(speed),side,wheel_dir)
	self.components.body.object:setTrackAnimationSpeed(math.abs(speed),side,track_dir)
end

function StandardTankEntity:getCurrentFireInfo()
	local tranform = self.components.canon.object:GetSceneNode():getAbsoluteTransformation()
	local fire_position = irr.core.vector3df:new_local()
	tranform:transformVect(fire_position,self.components.fire_position)
	local fire_direction = fire_position-self.components.canon.object:getPosition()
	fire_direction:normalize()
	return fire_position,fire_direction
end

function StandardTankEntity:PlayFireEffect( position )
	local param = tolua.cast(self.fire_effector:getParameters(),"BillboardAnimationEffectorParams")
	param.origin=position
	self.fire_effector:Play()
end

function StandardTankEntity.Load( info, logic_data )
	if not info then
		return
	end

	local graphics = NeoGraphics:getInstance()
	local physics = NeoPhysics:getInstance()
	local neo_scene = NeoScene:getInstance()

	local self = StandardTankEntity.new()

	self.property.tank_name = info.tank_name
	local data =  info.data
	--组装车身
	self.components.body.object=neo_scene:CreateStandardTankBodyObject()
	local body_main_node,shape_index_body = 
		StandardTankEntity.LoadRegularComponent(data.components.body )
	self.components.body.object:setBodyNode(body_main_node)
	local rigid_body = StandardTankEntity.LoadRigidBody(
		self.components.body.object,shape_index_body, data.components.body)
	--添加轮子
	for _,wheel_data in ipairs(data.components.wheel) do
		local node,_ = Scene.nodeLoader.mesh_animated(wheel_data)
		if node then
			self.components.body.object:addWheelNode(node,wheel_data.side)
		end
	end
	--组装炮台
	self.components.turret.object=neo_scene:CreateGameObject()
	local turret_node,shape_index_turret = 
		StandardTankEntity.LoadRegularComponent(data.components.turret)
	self.components.turret.object:setSceneNode(turret_node)
	local rigid_turret = StandardTankEntity.LoadRigidBody(
		self.components.turret.object,shape_index_turret, data.components.turret)
	rigid_turret:setActivationState(4)--DISABLE_DEACTIVATION 
	--组装炮管
	self.components.canon.object=neo_scene:CreateGameObject()
	self.components.canon.animation={}
	for _,v in ipairs(data.components.canon.animation) do
		self.components.canon.animation[v.label]={ from=v.from, to=v.to }
	end
	local canon_node,shape_index_canon =
		StandardTankEntity.LoadRegularComponent(data.components.canon)
	self.components.canon.object:setSceneNode(canon_node)
	canon_node:setLoopMode(false)
	local rigid_cannon = StandardTankEntity.LoadRigidBody(
		self.components.canon.object,shape_index_canon, data.components.canon)
	rigid_cannon:setActivationState(4)--DISABLE_DEACTIVATION 
	--组装履带
	for _,v in ipairs(data.components.track) do
		if v.side=="left" then
			self.components.left_track.object=neo_scene:CreateSimpleTankTrackObject()
			local track_node,shape_index_track = StandardTankEntity.LoadRegularComponent( v )

			self.components.body.object:addTrackNode(track_node,v.side)
			-- self.components.left_track.object:setSceneNode(track_node)

			local rigidbody=self.components.left_track.object:AddRigidBody(
				shape_index_track,v.mass,v.position,v.rotation)
			rigidbody:setDamping(0.1,0.9)
		else
			self.components.right_track.object=neo_scene:CreateSimpleTankTrackObject()
			local track_node,shape_index_track = StandardTankEntity.LoadRegularComponent( v )

			self.components.body.object:addTrackNode(track_node,v.side)
			-- self.components.right_track.object:setSceneNode(track_node)

			local rigidbody=self.components.right_track.object:AddRigidBody(
				shape_index_track,v.mass,v.position,v.rotation)
			rigidbody:setDamping(0.1,0.9)
		end
	end
	--设置Id
	self.components.body.object:setLuaIdentifier(info.id)
	self.components.turret.object:setLuaIdentifier(info.id)
	self.components.canon.object:setLuaIdentifier(info.id)
	self.components.left_track.object:setLuaIdentifier(info.id)
	self.components.right_track.object:setLuaIdentifier(info.id)
	--设置炮弹发射点
	local fire_point = data.components.fire_point
	local transform = self.components.turret.object:GetSceneNode():getAbsoluteTransformation()
	transform:inverseTranslateVect(fire_point.position)
	self.components.fire_position=fire_point.position
	--物理结构组装
	--炮塔与车身
	local pivot_body = irr.core.vector3df:new_local()
	local pivot_turret_body = body_main_node:getPosition()-turret_node:getPosition()
	local axis_body_turret = irr.core.vector3df:new_local(0,1,0)
	local turret_hinge = NeoPhysics:getInstance():CreateHingeJoint(
		rigid_body,rigid_turret,pivot_body,pivot_turret_body,axis_body_turret,axis_body_turret)
	self.components.turret_hinge=turret_hinge
	turret_hinge:enableAngularMotor(true,0,1)
	physics:AddHingeJointToWorld(turret_hinge)
	--炮管与炮塔
	local pivot_canon = irr.core.vector3df:new_local()
	local pivot_turret_canon = canon_node:getPosition()-turret_node:getPosition()
	local axis_canon_turret = irr.core.vector3df:new_local(0,0,0.5)
	local canon_hinge = NeoPhysics:getInstance():CreateHingeJoint(
		rigid_turret,rigid_cannon,pivot_turret_canon,pivot_canon,axis_canon_turret,axis_canon_turret)
	self.components.canon_hinge=canon_hinge
	canon_hinge:setLimit(
		-math.rad(data.components.canon.max_angle),
		-math.rad(data.components.canon.min_angle))
	canon_hinge:enableAngularMotor(true,0,0.5)
	physics:AddHingeJointToWorld(canon_hinge)
	--左履带与车身
	local axis_track=axis_canon_turret
	local pivot_left_track = 
		body_main_node:getPosition()-self.components.left_track.object:getPosition()
	local left_track_hinge = StandardTankEntity.LoadTrackRigidBody(
		rigid_body,self.components.left_track.object:getRigidBody(),
		pivot_body,pivot_left_track,axis_track)
	self.components.left_track_hinge=left_track_hinge
	--右履带与车身
	local pivot_right_track = 
		body_main_node:getPosition()-self.components.right_track.object:getPosition()
	local right_track_hinge = StandardTankEntity.LoadTrackRigidBody(
		rigid_body,self.components.right_track.object:getRigidBody(),
		pivot_body,pivot_right_track,axis_track)
	self.components.right_track_hinge=right_track_hinge
	--加入主体组件列表
	local main_body_object = self.components.body.object
	main_body_object:AddComponent("turretHinge",turret_hinge)
	main_body_object:AddComponent("canonHinge",canon_hinge)
	main_body_object:AddComponent("leftTrackHinge",left_track_hinge)
	main_body_object:AddComponent("rightTrackHinge",right_track_hinge)
	--设置动画
	self.setAnimation(self.components.canon,"idle")
	local transform = irr.core.matrix4:new_local()
	transform:setTranslation(info.position)
	transform:setRotationDegrees(info.rotation)
	self:setTransform(transform)
	--加载炮火特效
	self.fire_effector=NeoScene:getInstance():addSpriteAnimationEffector(
			irr.core.vector3df(),"canon_1.png",irr.core.dimension2df(10,10))
	--记录逻辑数据
	for k,v in pairs(data.property) do
		self.property[k]=v
	end

	return self
end

function StandardTankEntity.LoadRegularComponent( data )
	local node, node_mesh = Scene.nodeLoader.mesh_animated(data)
	local shape_index=-1
	local collision_mesh_path = data.collision_mesh_path
	if collision_mesh_path ~= "" then
		local collsion_mesh = NeoGraphics:getInstance():getMesh(collision_mesh_path)
		shape_index = Scene.collisionShapeLoader.convexHull(
		{mesh=collsion_mesh, scale=data.scale})
	else
		shape_index = Scene.collisionShapeLoader.convexHull(
		{mesh=node_mesh, scale=data.scale})
	end
	return node,shape_index
end

function StandardTankEntity.LoadRigidBody( targetObj,shape_index ,data )
	if shape_index>=0 then
		return targetObj:AddRigidBody(shape_index,data.mass)
	end
end

function StandardTankEntity.LoadTrackRigidBody( bodyRigidBody,trackRigidBody,bodyPivot,trackPivot,axis )
	local track_hinge = NeoPhysics:getInstance():CreateHingeJoint(
		bodyRigidBody,trackRigidBody,bodyPivot,trackPivot,axis,axis)
	NeoPhysics:getInstance():AddHingeJointToWorld(track_hinge)
	track_hinge:setLimit(math.rad(-1.5),math.rad(2))
	return track_hinge
end

function StandardTankEntity.setAnimation(part,key)
	if part.animation and part.animation[key] then
		local animation=part.animation[key]
		tolua.cast(part.object:GetSceneNode(),"const irr::scene::IAnimatedMeshSceneNode"):
			setFrameLoop(animation.from,animation.to)
	end
end

-----------------
--event handler
-----------------
StandardTankEntity.event_handlers={
}

function StandardTankEntity.RegisterSingleModeEventHandler( )
	Logic:RegisterEventHandler(
		Logic.EVENT.SHELL_HIT,"StandardTankEntity",StandardTankEntity.OnShellHit)
end

function StandardTankEntity.RegisterMultiModeEventHandler( )

end

--event:NeoEvent 结构
function StandardTankEntity.OnShellHit( event )
	
end

-----------------
--command interface
-----------------
--dir 前：1，后：-1，不动 0
--side 左-1，右：1，无 0
function StandardTankEntity:Move( dir, side )
	local speed = self.property.max_speed
	if side==-1 then
		--left
		local left_speed = speed*0.12*dir
		if left_speed == 0 then
			left_speed = -speed
		end
		local right_speed = speed*dir
		if right_speed == 0 then
			right_speed = speed
		end
		self:setTrackSpeed("left",left_speed)
		self:setTrackSpeed("right",right_speed)
	elseif side==1 then
		--right
		local right_speed = speed*0.12*dir
		if right_speed == 0 then
			right_speed = -speed
		end
		local left_speed = speed*dir
		if left_speed == 0 then
			left_speed = speed
		end
		self:setTrackSpeed("left",left_speed)
		self:setTrackSpeed("right",right_speed)
	else
		--forward
		self:setTrackSpeed("left",speed*dir)
		self:setTrackSpeed("right",speed*dir)
	end
end

function StandardTankEntity:Stop()
	self:setTrackSpeed("left",0)
	self:setTrackSpeed("right",0)
end

function StandardTankEntity:Attack( shell_type, actor )
	local fire_position, fire_dir = self:getCurrentFireInfo()
	local impulse = fire_dir*self.property.fire_power
	local vector = irr.core.vector3df:new_local(1,0,0)
	local matrix = irr.core.matrix4:new_local():buildRotateFromTo(vector,fire_dir)
	local shell_rot = matrix:getRotationDegrees()
	local shell_prop = {
		shell_type=shell_type,
		position=fire_position,
		rotation=shell_rot
	}
	local data = {
		owner=actor
	}
	print("effect")
	self:PlayFireEffect(fire_position)
	--print("animation")
	--StandardTankEntity.setAnimation(self.components.canon,"fire")
	print("bullet")
	Scene:ShootShell(shell_prop,impulse,data)
	print("impulse")
	self.components.turret.object:getRigidBody():applyCentralImpulse(impulse*-1)
end