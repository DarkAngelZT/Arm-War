require(DIR_SCRIPT.."game/logic")

PrismTankEntity=class(StandardTankEntity)

function PrismTankEntity:onCreate(id)
	self.tank_type="prism"
	self.components.laser=nil
end

function PrismTankEntity:OnLaserPulseEnd()
	if self.components.laser then
		self.components.laser:setVisible(false)
	end
end

function PrismTankEntity:StartLaserPulse(length)
	if self.components.laser then
		self.components.laser:setScale(irr.core.vector3df:new_local(length+0.2,1,1))
		self.components.laser:setVisible(true)
		self.laser_pulse_timer:Start()
	end
end

function PrismTankEntity:PlayFireEffect(laser_length)
	laser_length = laser_length or 2000
	self:StartLaserPulse(laser_length)
end

function PrismTankEntity.Load( info, logic_data )
	if not info then
		return
	end
	local entity = PrismTankEntity.new(info.id)
	StandardTankEntity.DoLoad(entity,info,logic_data)
	entity:LoadLaser()
	return entity
end

function PrismTankEntity:LoadLaser()
	local resource_path = DIR_TANKS..self.property.tank_name
	local mesh=NeoGraphics:getInstance():getMesh(resource_path.."/ray.obj")
	local node=NeoGraphics:getInstance():AddMeshSceneNode(mesh)
	local texture = NeoGraphics:getInstance():LoadTexture(resource_path.."/ray.jpg")
	node:setMaterialTexture(0,texture)
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setParent(self.components.canon.object:GetSceneNode())
	node:setVisible(false)
	self.components.laser=node

	local timer = Timer.new()
	timer.duration=0.3
	timer:AddTriggerFunction(self.OnLaserPulseEnd,self)
	self.laser_pulse_timer = timer
	Logic:AddTimer(self.laser_pulse_timer)
end

function PrismTankEntity:AddToScene()
	StandardTankEntity.AddToScene(self)
	self.components.laser:setVisible(false)
	self.laser_pulse_timer:Stop()
end

function PrismTankEntity:RemoveFromScene()
	StandardTankEntity.RemoveFromScene(self)
	self.components.laser:setVisible(false)
end

function PrismTankEntity:Destroy()
	StandardTankEntity.Destroy(self)

	if self.laser_pulse_timer then
		Logic:RemoveTimer(self.laser_pulse_timer)
	end
end
-----------------
--event handler
-----------------

function PrismTankEntity.RegisterSingleModeEventHandler( )
	Logic:RegisterEventHandler(
		Logic.EVENT.SHELL_HIT,"PrismTankEntity",StandardTankEntity.OnShellHit)
	Logic:RegisterEventHandler(
		Logic.EVENT.LASER_HIT,"PrismTankEntity",StandardTankEntity.OnLaserHit)
end

function PrismTankEntity.RegisterMultiModeEventHandler( )
	Logic:RegisterEventHandler(
		Logic.EVENT.SHELL_HIT,"PrismTankEntity",StandardTankEntity.MultiModeOnShellHit)
	Logic:RegisterEventHandler(
		Logic.EVENT.LASER_HIT,"PrismTankEntity",StandardTankEntity.MultiModeOnLaserHit)
end

--event:NeoEvent 结构


function PrismTankEntity:PlayFireSound(position)
	if position then
		local s = Sound:Play3D("laser",position)
		s:setStrength(0.5)
	end
end

function PrismTankEntity:Attack( shell_type )
	local fire_position, fire_dir = self:getCurrentFireInfo()

	local data = {
		damage=self.actor.laser_damage or 0,
		owner=self.actor
	}
	--激光
	local target,_ = Scene:ShootLaser(fire_position,fire_dir,data)
	local len = (target - fire_position):getLength()
	--炮火特效
	self:PlayFireEffect(len)
	--声音
	self:PlayFireSound(fire_position)
end