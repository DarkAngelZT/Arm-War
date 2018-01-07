require(DIR_SCRIPT.."game/explosion")
ExplosionTypes=
{
	default=DefaultExplosion
}
SingleModeExplosionDispatcher={}
function SingleModeExplosionDispatcher:notify( invoker, event )
	-- type, event_id, damage, position, range, impulse, attenuate
	if event.event_id ~= Scene.EVENT.EXPLOSION then
		return
	end
	local params=ExplosionTypes[event.type]
	if not params then
		return
	end
	local effect_param = BasicExplosionEffectParams:new_local()
	effect_param.fRadius = 2
	effect_param.origin = event.position
	effect_param.material_name_high_speed = "explosion01.png";
	effect_param.material_name_low_speed = "explosion02.png";
	effect_param.start_color_high_speed = params.effector_param.start_color_high_speed
	effect_param.end_color_high_speed = params.effector_param.end_color_high_speed
	effect_param.start_color_low_speed = params.effector_param.start_color_low_speed
	effect_param.end_color_low_speed = params.effector_param.end_color_low_speed
	effect_param.shock_wave_color = params.effector_param.shock_wave_color
	local physics_param = BasicExplosionParams:new_local()
	physics_param.nEventID=Logic.EVENT.EXPLOSION
	physics_param.fRange = event.range
	physics_param.fImpulse = event.impulse
	physics_param.bAttenuateByRange = event.attenuate
	physics_param.origin = event.position
	physics_param:PushScriptValue(tostring(invoker.id))
	physics_param:PushScriptValue(tostring(event.damage))
	local explosion = NeoScene:getInstance():CreateExplosion(
		params.explosion_type_internal,effect_param,physics_param)
	explosion:Play()
	--sound
	local audio = ExplosionTypes[event.type].sound or "explosion_1"
	local sound_strength = ExplosionTypes[event.type].sound_strength or 1
	local s = Sound:Play3D(audio, event.position)
end
-----------------------------------
-----------------------------------
MultiModeExplosionDispatcher={}
function MultiModeExplosionDispatcher:DoExplosion( explosion_type, data )
	--data = { invokerId, damage, position, range, impulse, attenuate }
	local params=ExplosionTypes[explosion_type]
	if not params then
		return
	end
	local effect_param = BasicExplosionEffectParams:new_local()
	effect_param.fRadius = 2
	effect_param.origin = data.position
	effect_param.material_name_high_speed = "explosion01.png";
	effect_param.material_name_low_speed = "explosion02.png";
	effect_param.start_color_high_speed = params.effector_param.start_color_high_speed
	effect_param.end_color_high_speed = params.effector_param.end_color_high_speed
	effect_param.start_color_low_speed = params.effector_param.start_color_low_speed
	effect_param.end_color_low_speed = params.effector_param.end_color_low_speed
	effect_param.shock_wave_color = params.effector_param.shock_wave_color
	local physics_param = BasicExplosionParams:new_local()
	physics_param.nEventID=Logic.EVENT.EXPLOSION
	physics_param.fRange = data.range
	physics_param.fImpulse = data.impulse
	physics_param.bAttenuateByRange = data.attenuate
	physics_param.origin = data.position
	physics_param:PushScriptValue(tostring(data.invokerId))
	physics_param:PushScriptValue(tostring(data.damage))
	local explosion = NeoScene:getInstance():CreateExplosion(
		params.explosion_type_internal,effect_param,physics_param)
	explosion:Play()
	--sound
	local audio = ExplosionTypes[event.type].sound or "explosion_1"
	local sound_strength = ExplosionTypes[event.type].sound_strength or 1
	local s = Sound:Play3D(audio, event.position)
	s:setStrength(sound_strength)
end
function MultiModeExplosionDispatcher:notify( invoker, event )
	-- type, event_id, damage, position, range, impulse, attenuate
	if event.event_id ~= Scene.EVENT.EXPLOSION then
		return
	end
	if Synchronizer.network:isServer() then
		--broadcast
		Synchronizer:OnGameEvent(ID_GAME_EVENT_EXPLOSION,{
			explosion_type=event.type, invokerId=invoker.id, damage=event.damage, 
			position=event.position, range=event.range, impulse=event.impulse, attenuate=event.attenuate })
		--execute
		self:DoExplosion(event.type,{
			invokerId=invoker.id,damage=event.damage, position=event.position, range=event.range, impulse=event.impulse, attenuate=event.attenuate })
	end
end