require(DIR_SCRIPT.."game/explosion")
ExplosionTypes=
{
	default=DefaultExplosion
}
SingleModeExplosionDispatcher={}
function SingleModeExplosionDispatcher:notify( invoker, event )
	-- type, event_id, actor, damage, position, range, impulse, attenuate
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
end
-----------------------------------
-----------------------------------
MultiModeExplosionDispatcher={}
function MultiModeExplosionDispatcher.notify( entity, event )
	-- type, event_id, actor, damage, position, range, impulse, attenuate
	if event.event_id ~= Scene.EVENT.EXPLOSION then
		return
	end
	local params=ExplosionTypes[event.type]
	if not params then
		return
	end
end