require(DIR_SCRIPT.."game/logic")

TankEntityLoader={
	standard=StandardTankEntity
}

StandardTankEntity=class(Entity)
StandardTankEntity.tank_type="standard"
StandardTankEntity.actor=nil
StandardTankEntity.fire_effector=nil

function StandardTankEntity:onCreate(id)
	self.id=id or -1
	self.components={
		body={object=nil},
		left_track={object=nil},
		right_track={object=nil},
		turret={object=nil},
		canon={object=nil},
		fire_position=nil,
		turret_hinge=nil,
		canon_hinge=nil,
		left_track_hinge=nil,
		right_track_hinge=nil
	}
	self.property={}
	self.destroyed_prefab={}
end

--@transform:matrix4
function StandardTankEntity:setTransform(transform)
	local body = self.components.body
	local trans = irr.core.matrix4:new_local(
		self.components.body.object:getTankBodyNode():getAbsoluteTransformation(),
		irr.core.matrix4.EM4CONST_INVERSE)
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
-- this function is for network synchronize
-- @sync_data:{turret_rotation,canon_rotation}
function StandardTankEntity:SynchronizeTransform( transform, sync_data )
	local body = self.components.body
	local turret = self.components.turret
	local canon = self.components.canon
	local left_track = self.components.left_track
	local right_track = self.components.right_track
	
	if not turret.offset then
		local trans = irr.core.matrix4:new_local(
			self.components.body.object:getTankBodyNode():getAbsoluteTransformation(),
			irr.core.matrix4.EM4CONST_INVERSE)
		local turret_inverse_trans = irr.core.matrix4:new_local(
			self.components.turret.object:GetSceneNode():getAbsoluteTransformation(),
			irr.core.matrix4.EM4CONST_INVERSE)
		local turret_trans = trans*turret.object:GetSceneNode():getAbsoluteTransformation()
		local canon_trans = turret_inverse_trans*canon.object:GetSceneNode():getAbsoluteTransformation()
		local left_track_trans = trans*left_track.object:getRigidBody():getCenterOfMassTransform()
		local right_track_trans = trans*right_track.object:getRigidBody():getCenterOfMassTransform()
		turret.offset=turret_trans:getTranslation()
		canon.offset=canon_trans:getTranslation()
		left_track.offset=left_track_trans:getTranslation()
		right_track.offset=right_track_trans:getTranslation()
	end

	local turret_pos = irr.core.vector3df:new_local()
	local canon_pos = irr.core.vector3df:new_local()
	local left_track_pos = irr.core.vector3df:new_local()
	local right_track_pos = irr.core.vector3df:new_local()
	transform:transformVect(turret_pos,turret.offset)
	
	transform:transformVect(left_track_pos,left_track.offset)
	transform:transformVect(right_track_pos,right_track.offset)

	body.object:setPosition(transform:getTranslation())
	body.object:setRotation(transform:getRotationDegrees())

	turret.object:setPosition(turret_pos)
	turret.object:setRotation(sync_data.turret_rotation)

	turret.object:GetSceneNode():updateAbsolutePosition()
	turret.object:GetSceneNode():getAbsoluteTransformation():transformVect(canon_pos,canon.offset)
	canon.object:setPosition(canon_pos)
	canon.object:setRotation(sync_data.canon_rotation)

	left_track.object:setPosition(left_track_pos)

	right_track.object:setPosition(right_track_pos)
end

function StandardTankEntity:setTurretAngle( angle_degree )
	local hinge = self.components.turret_hinge
	local current_angle = math.deg(hinge:getHingeAngle())
	if current_angle<0 then
		current_angle=current_angle+360
	end
	local delta_angle=angle_degree-current_angle
	local delta_angle_abs = math.abs(delta_angle)
	local dir = 0
	if delta_angle_abs>0 then
		dir = delta_angle/delta_angle_abs
	end
	if delta_angle_abs>180 then
		dir=dir*-1
		delta_angle = (360 - delta_angle_abs) * dir
	end
	local angular_speed = math.rad(self.property.turret_rotation_speed)*dir

	if delta_angle_abs<10 then
		angular_speed = math.rad(delta_angle)
	end
	hinge:enableAngularMotor(true,angular_speed,0.8)
end

function StandardTankEntity:setCanonAngle( angle_degree )
	local hinge = self.components.canon_hinge
	angle_degree = clamp(
		angle_degree,self.components.canon.min_angle,self.components.canon.max_angle)

	hinge:setMotorTarget(math.rad(angle_degree),0.5)
end

function StandardTankEntity:getTurretAngle()
	local hinge = self.components.turret_hinge
	local current_angle = math.deg(hinge:getHingeAngle())
	if current_angle<0 then
		current_angle=current_angle+360
	end
	return current_angle
end

function StandardTankEntity:getCanonAngle()
	local hinge = self.components.canon_hinge
	local current_angle = math.deg(hinge:getHingeAngle())
	return current_angle
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

	local wheel_anim_speed = 0
	if speed ~= 0 then
		wheel_anim_speed=8/math.abs(speed)
	end

	self.components.body.object:setWheelAnimationSpeed(wheel_anim_speed,side,wheel_dir)
	self.components.body.object:setTrackAnimationSpeed(math.abs(speed),side,track_dir)
end

function StandardTankEntity:getCurrentFireInfo()
	local canon_pos = self.components.canon.object:getPosition()
	local fire_position = 
		self.components.fire_position:getAbsoluteTransformation():getTranslation()
	local fire_direction = fire_position-canon_pos
	fire_direction:normalize()
	return fire_position,fire_direction
end

function StandardTankEntity:getFirePosition()
	return self.components.fire_position:getAbsolutePosition()
end

function StandardTankEntity:getCanonAimPosition(distance)
	distance=distance or 1000
	local from,dir = self:getCurrentFireInfo()
	local to = from+dir*distance
	local raycastResult = NeoPhysics:getInstance():RayCast(from,to)
	if raycastResult.hasHit then
		return raycastResult.m_hitPointWorld
	else
		return to
	end
end

function StandardTankEntity:getTargetAngle( position )
	local turret_angle = 0
	local canon_angle = 0
	local transform = irr.core.matrix4:new_local()
	transform:setTranslation(
		self.components.turret.object:getPosition())
	transform:setRotationDegrees(
		self.components.body.object:getTankBodyNode():getAbsoluteTransformation():getRotationDegrees())
	transform:makeInverse()
	transform:transformVect(position)
	local angles = position:getSphericalCoordinateAngles()
	canon_angle,turret_angle = angles.X,angles.Y
	return turret_angle,canon_angle
end
-------------------------------------------
--get tank component rotation in world space, mainly used for ui update (face to z axis)
-------------------------------------------
function StandardTankEntity:getTankComponentWorldAngles(part_key)
	--calculate rotation
	local rot_euler=self.components[part_key].object:getRotation()
	--convert to quaternion for rotation
	local rot = irr.core.quaternion:new_local(
		math.rad(rot_euler.X),math.rad(rot_euler.Y),math.rad(rot_euler.Z))
	--default forward direction
	local dir = irr.core.vector3df:new_local(1,0,0) 

	dir = rotateVectorByQuaternion(dir,rot)
	angles = dir:getSphericalCoordinateAngles()
	return angles*-1
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

	local tank = StandardTankEntity.new(info.id)
	tank.property.tank_name = info.tank_name
	local data =  info.data
	--组装车身
	tank.components.body.object=neo_scene:CreateStandardTankBodyObject()
	local body_main_node,shape_index_body = 
		StandardTankEntity.LoadRegularComponent(data.components.body )
	tank.components.body.object:setBodyNode(body_main_node)
	local rigid_body = StandardTankEntity.LoadRigidBody(
		tank.components.body.object,shape_index_body, data.components.body)
	rigid_body:setDamping(0.1,0.5)
	rigid_body:setFriction(0.8)
	--添加轮子
	for _,wheel_data in ipairs(data.components.wheel) do
		wheel_data.cast_shadow=ApplicationSettings.realtimeShadow
		local node,_ = Scene.nodeLoader.mesh_animated(wheel_data)
		if node then
			tank.components.body.object:addWheelNode(node,wheel_data.side)
		end
	end
	--组装炮台
	tank.components.turret.object=neo_scene:CreateGameObject()
	local turret_node,shape_index_turret = 
		StandardTankEntity.LoadRegularComponent(data.components.turret)
	tank.components.turret.object:setSceneNode(turret_node)
	local rigid_turret = StandardTankEntity.LoadRigidBody(
		tank.components.turret.object,shape_index_turret, data.components.turret)
	rigid_turret:setActivationState(4)--DISABLE_DEACTIVATION 
	rigid_turret:setDamping(0.1,0.8)
	rigid_turret:setFriction(0.8)
	--组装炮管
	tank.components.canon.object=neo_scene:CreateGameObject()
	tank.components.canon.animation={}
	for _,v in ipairs(data.components.canon.animation) do
		tank.components.canon.animation[v.label]={ from=v.from, to=v.to }
	end
	local canon_node,shape_index_canon =
		StandardTankEntity.LoadRegularComponent(data.components.canon)
	tank.components.canon.object:setSceneNode(canon_node)
	canon_node:setLoopMode(false)
	local rigid_cannon = StandardTankEntity.LoadRigidBody(
		tank.components.canon.object,shape_index_canon, data.components.canon)
	rigid_cannon:setActivationState(4)--DISABLE_DEACTIVATION 
	--组装履带
	for _,v in ipairs(data.components.track) do
		if v.side=="left" then
			tank.components.left_track.object=neo_scene:CreateSimpleTankTrackObject()
			local track_node,shape_index_track = StandardTankEntity.LoadRegularComponent( v )

			tank.components.body.object:addTrackNode(track_node,v.side)
			-- tank.components.left_track.object:setSceneNode(track_node)

			local rigidbody=tank.components.left_track.object:AddRigidBody(
				shape_index_track,v.mass,v.position,v.rotation)
			rigidbody:setDamping(0.1,0.5)
			rigidbody:setFriction(0.8)
		else
			tank.components.right_track.object=neo_scene:CreateSimpleTankTrackObject()
			local track_node,shape_index_track = StandardTankEntity.LoadRegularComponent( v )

			tank.components.body.object:addTrackNode(track_node,v.side)
			-- tank.components.right_track.object:setSceneNode(track_node)

			local rigidbody=tank.components.right_track.object:AddRigidBody(
				shape_index_track,v.mass,v.position,v.rotation)
			rigidbody:setDamping(0.1,0.5)
			rigidbody:setFriction(0.8)
		end
	end
	--设置Id
	tank.components.body.object:setLuaIdentifier(info.id)
	tank.components.turret.object:setLuaIdentifier(info.id)
	tank.components.canon.object:setLuaIdentifier(info.id)
	tank.components.left_track.object:setLuaIdentifier(info.id)
	tank.components.right_track.object:setLuaIdentifier(info.id)
	--设置炮弹发射点
	local fire_point = data.components.fire_point
	local transform = tank.components.canon.object:GetSceneNode():getAbsoluteTransformation()
	local fire_position = irr.core.vector3df(fire_point.position)
	transform:inverseTranslateVect(fire_position)
	tank.components.fire_position=graphics:AddEmptySceneNode(canon_node) 
	tank.components.fire_position:setPosition(fire_position)
	--物理结构组装
	--炮塔与车身
	local pivot_body = irr.core.vector3df:new_local()
	local pivot_turret_body = body_main_node:getPosition()-turret_node:getPosition()
	local axis_body_turret = irr.core.vector3df:new_local(0,1,0)
	local turret_hinge = NeoPhysics:getInstance():CreateHingeJoint(
		rigid_body,rigid_turret,pivot_body,pivot_turret_body,axis_body_turret,axis_body_turret)
	tank.components.turret_hinge=turret_hinge
	turret_hinge:enableAngularMotor(true,0,1)
	physics:AddHingeJointToWorld(turret_hinge)
	--炮管与炮塔
	local pivot_canon = irr.core.vector3df:new_local()
	local pivot_turret_canon = canon_node:getPosition()-turret_node:getPosition()
	local axis_canon_turret = irr.core.vector3df:new_local(0,0,0.5)
	local canon_hinge = NeoPhysics:getInstance():CreateHingeJoint(
		rigid_turret,rigid_cannon,pivot_turret_canon,pivot_canon,axis_canon_turret,axis_canon_turret)
	tank.components.canon_hinge=canon_hinge
	tank.components.canon.max_angle=-data.components.canon.min_angle
	tank.components.canon.min_angle=-data.components.canon.max_angle
	canon_hinge:setLimit(
		-math.rad(data.components.canon.max_angle),
		-math.rad(data.components.canon.min_angle))
	canon_hinge:enableAngularMotor(true,0,0.5)
	physics:AddHingeJointToWorld(canon_hinge)
	--左履带与车身
	local axis_track=axis_canon_turret
	local pivot_left_track = 
		body_main_node:getPosition()-tank.components.left_track.object:getPosition()
	local left_track_hinge = StandardTankEntity.LoadTrackRigidBody(
		rigid_body,tank.components.left_track.object:getRigidBody(),
		pivot_body,pivot_left_track,axis_track)
	tank.components.left_track_hinge=left_track_hinge
	--右履带与车身
	local pivot_right_track = 
		body_main_node:getPosition()-tank.components.right_track.object:getPosition()
	local right_track_hinge = StandardTankEntity.LoadTrackRigidBody(
		rigid_body,tank.components.right_track.object:getRigidBody(),
		pivot_body,pivot_right_track,axis_track)
	tank.components.right_track_hinge=right_track_hinge
	--加入主体组件列表
	local main_body_object = tank.components.body.object
	main_body_object:AddComponent("turretHinge",turret_hinge)
	main_body_object:AddComponent("canonHinge",canon_hinge)
	main_body_object:AddComponent("leftTrackHinge",left_track_hinge)
	main_body_object:AddComponent("rightTrackHinge",right_track_hinge)
	--设置动画
	tank.setAnimation(tank.components.canon,"idle")
	local transform_tank = irr.core.matrix4:new_local()
	transform_tank:setTranslation(info.position)
	transform_tank:setRotationDegrees(info.rotation)
	tank:setTransform(transform_tank)
	--加载炮火特效
	tank.fire_effector=NeoScene:getInstance():addSpriteAnimationEffector(
			irr.core.vector3df(),"canon_1.png",irr.core.dimension2df(8,8))
	--记录逻辑数据
	for k,v in pairs(data.property) do
		tank.property[k]=v
	end
	-- 加载损毁状态的模型
	tank.destroyed_prefab.mesh=NeoGraphics:getInstance():getMesh(data.property.mesh_destroyed)
	tank.destroyed_prefab.shape_index = Scene.collisionShapeLoader.convexHull(
		{mesh=tank.destroyed_prefab.mesh, scale=irr.core.vector3df:new_local(1,1,1)})

	tank:AddEngineSound(tank.components.body.object)

	return tank
end

function StandardTankEntity:AddEngineSound( body_object )
	if body_object then
		local s = Sound:CreateAudioSource("effect","tank_engine", "engine"..self.id,true)
		if s then
			self.components.engine_sound = s
			body_object:AddComponent("engine_sound",s)
		end
	end
end

function StandardTankEntity.LoadRegularComponent( data )
	data.cast_shadow=ApplicationSettings.realtimeShadow
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
	track_hinge:setLimit(math.rad(-0.01),math.rad(0.01))
	return track_hinge
end

function StandardTankEntity.setAnimation(part,key)
	if part.animation and part.animation[key] then
		local animation=part.animation[key]
		tolua.cast(part.object:GetSceneNode(),"irr::scene::IAnimatedMeshSceneNode"):
			setFrameLoop(animation.from,animation.to)
	end
end

function StandardTankEntity:AddToScene()
	local physics = NeoPhysics:getInstance()
	local components = self.components
	physics:AddHingeJointToWorld(components.turret_hinge)
	physics:AddHingeJointToWorld(components.turret_hinge)
	physics:AddHingeJointToWorld(components.left_track_hinge)
	physics:AddHingeJointToWorld(components.right_track_hinge)

	components.body.object:setActive(true)
	components.turret.object:setActive(true)
	components.canon.object:setActive(true)
	components.left_track.object:setActive(true)
	components.right_track.object:setActive(true)
end

function StandardTankEntity:RemoveFromScene()
	local physics = NeoPhysics:getInstance()
	local components = self.components
	physics:RemoveHingeJointFromWorld(components.turret_hinge)
	physics:RemoveHingeJointFromWorld(components.turret_hinge)
	physics:RemoveHingeJointFromWorld(components.left_track_hinge)
	physics:RemoveHingeJointFromWorld(components.right_track_hinge)

	components.body.object:setActive(false)
	components.turret.object:setActive(false)
	components.canon.object:setActive(false)
	components.left_track.object:setActive(false)
	components.right_track.object:setActive(false)
end
function StandardTankEntity:Destroy()
	-- local physics = NeoPhysics:getInstance()
	local components = self.components
	-- physics:RemoveHingeJointFromWorld(components.turret_hinge)
	-- physics:RemoveHingeJointFromWorld(components.turret_hinge)
	-- physics:RemoveHingeJointFromWorld(components.left_track_hinge)
	-- physics:RemoveHingeJointFromWorld(components.right_track_hinge)

	NeoScene:getInstance():DestroyGameObject(components.body.object,true)
	NeoScene:getInstance():DestroyGameObject(components.turret.object,true)
	NeoScene:getInstance():DestroyGameObject(components.canon.object,true)
	NeoScene:getInstance():DestroyGameObject(components.left_track.object,true)
	NeoScene:getInstance():DestroyGameObject(components.right_track.object,true)
end
function StandardTankEntity:Respawn(position,rotation )
	self.components.body.object:ResetPhysicsStates()
	self.components.turret.object:ResetPhysicsStates()
	self.components.canon.object:ResetPhysicsStates()
	self.components.left_track.object:ResetPhysicsStates()
	self.components.right_track.object:ResetPhysicsStates()

	local transform = irr.core.matrix4:new_local()
	transform:setTranslation(position)
	transform:setRotationDegrees(rotation)

	self:setTransform(transform)
	self.components.canon_hinge:setMotorTarget(0,0.1)
	self.components.turret_hinge:setMotorTarget(0,0.1)
	self:AddToScene()
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
	Logic:RegisterEventHandler(
		Logic.EVENT.SHELL_HIT,"StandardTankEntity",StandardTankEntity.MultiModeOnShellHit)
end

--event:NeoEvent 结构
function StandardTankEntity.OnShellHit( event )
	local actor_id = event:getData(0)
	local shell_id = event:getData(1)

	local actor = Logic.actors[actor_id]
	local shell=Scene.entities[shell_id]

	actor:OnShellHit(shell)
end
function StandardTankEntity.MultiModeOnShellHit( event )
	local actor_id = event:getData(0)
	local shell_id = event:getData(1)

	local actor = Logic.actors[actor_id]
	local shell=Scene.entities[shell_id]

	actor:MultiModeOnShellHit(shell)
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
		local left_speed = speed*0.6*dir
		if left_speed == 0 then
			left_speed = -speed*0.2
		end
		local right_speed = speed*dir*0.8
		if right_speed == 0 then
			right_speed = speed*0.2
		end
		self:setTrackSpeed("left",left_speed)
		self:setTrackSpeed("right",right_speed)
	elseif side==1 then
		--right
		local right_speed = speed*0.6*dir
		if right_speed == 0 then
			right_speed = -speed*0.2
		end
		local left_speed = speed*dir*0.8
		if left_speed == 0 then
			left_speed = speed*0.2
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

function StandardTankEntity:StopEngineSound()
	if self.components.engine_sound and self.components.engine_sound:isPlaying() then
		self.components.engine_sound:pause()
	end
end

function StandardTankEntity:PlayEngineSound()
	if self.components.engine_sound and (not self.components.engine_sound:isPlaying()) then
		self.components.engine_sound:play3d(self.components.body.object:getPosition(),2,true)
	end
end

function StandardTankEntity:PlayFireSound(position)
	if position then
		local s = Sound:Play3D("tank_fire_1",position)
		s:setStrength(1)
	end
end

function StandardTankEntity:Attack( shell_type )
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
		owner=self.actor
	}
	--炮弹
	Scene:ShootShell(shell_prop,impulse,data)
	--炮火特效
	self:PlayFireEffect(fire_position)
	--声音
	self:PlayFireSound(fire_position)
	--反作用力
	local turret = self.components.turret.object:getRigidBody()
	local impulse_turret = impulse * -0.2
	turret:applyCentralImpulse(impulse_turret)
	--炮管动画
	StandardTankEntity.setAnimation(self.components.canon,"fire")
end

function StandardTankEntity:CreateDestroyedObject(id)
	local remain = CommonObjectEntity.new()
	remain.gameobject = NeoScene:getInstance():CreateGameObject()
	remain.id = id or "co"..self.actor.id..os.time()
	remain.gameobject:setLuaIdentifier(remain.id)
	Scene.entities[remain.id]=remain
	--加入被摧毁的模型
	local node=NeoGraphics:getInstance():AddMeshSceneNode(self.destroyed_prefab.mesh)
	local body_position = 
		self.components.body.object:getPosition()
	local body_rotation = 
		self.components.body.object:getRotation()
	node:setPosition(body_position)
	node:setRotation(body_rotation)
	node:updateAbsolutePosition()
	remain.gameobject:setSceneNode(node)
	local rigidbody=remain.gameobject:AddRigidBody(self.destroyed_prefab.shape_index,30)
	rigidbody:setFriction(0.9)

	local graphics = NeoGraphics:getInstance()
	--浓烟效果
	local smoke = NeoGraphics:getInstance():AddParticleSystemSceneNode(false,node)
	local center = irr.core.vector3df:new_local(0,0,0)
	local radius = 1.2
	local dir = irr.core.vector3df:new_local(0,1,0)
	local length = 1
	local size_min = irr.core.dimension2df:new_local(2,2)
	local size_max = irr.core.dimension2df:new_local(8,8)
	local smoke_emitter = smoke:createCylinderEmitter(
		center,radius,dir,length,false,irr.core.vector3df:new_local(0,0.006,0),
		10,15,irr.video.SColor:new_local(180, 0, 0, 0),irr.video.SColor:new_local(180, 0, 0, 0),
		1000,2000,0,size_min,size_max)
	local smoke_affector = graphics:CreateColourAffactorQ(
		irr.video.SColor:new_local(180, 0, 0, 0),irr.video.SColor:new_local(0, 0, 0, 0))
	smoke:setEmitter(smoke_emitter)
	smoke:addAffector(smoke_affector)
	local smoke_tex_path = "resources/sfx/particles/explosion04.png"
	local texture=NeoGraphics:getInstance():LoadTexture(smoke_tex_path)
	if texture then
		smoke:setMaterialTexture(0,texture)
	end
	smoke:setMaterialFlag(irr.video.EMF_LIGHTING, false);
	smoke:setMaterialFlag(irr.video.EMF_ZWRITE_ENABLE, false);
	smoke:setMaterialType(irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL);
	return remain
end

function StandardTankEntity:Die(id)
	local entity = self:CreateDestroyedObject(id)
	Scene:OnTankCorpseCreated(entity)
	self:RemoveFromScene()
	if self.actor == Logic.actor_me then
		Scene.cameras.third_person:setTarget(entity.gameobject:GetSceneNode())
	end
end