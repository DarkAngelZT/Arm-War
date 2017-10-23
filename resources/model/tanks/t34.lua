local tank={}
tank.components={}
tank.components.wheel={}
tank.components.track={}
tank.tank_name = "t34"
tank.components.track[1] = {
id = 141603,
name = "TankTrack_left",
scene_type = "tank_track",
position = irr.core.vector3df:new_local(-1.082627,0.000000,2.368140),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/track.obj",
collision_mesh_path = "",
mass = 6.000000,
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.track[1]
tank.components.track[2] = {
id = 606969,
name = "TankTrack_right",
scene_type = "tank_track",
position = irr.core.vector3df:new_local(-1.082627,0.000000,-2.360087),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/track.obj",
collision_mesh_path = "",
mass = 6.000000,
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.track[2]
tank.components.turret = {
id = 783099,
name = "TankTurret",
scene_type = "tank_turret",
position = irr.core.vector3df:new_local(0.000000,3.021843,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/turret.obj",
collision_mesh_path = "",
mass = 3.000000,
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.turret
tank.components.canon = {
id = 911647,
name = "TankCanon",
scene_type = "tank_canon",
position = irr.core.vector3df:new_local(1.727631,3.728226,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/canon.x",
collision_mesh_path = "resources/model/tanks/t34/t34_canon_collision.obj",
mass = 2.000000,
min_angle=-5,
max_angle=45,
autoplay = true,
startLoop = "idle",
animation = {
{ id = 1, label = "idle", from = 0, to = 0 },
{ id = 2, label = "fire", from = 1, to = 15 },
},
} -- tank.components.canon
tank.components.fire_point = {
name = "TankFirePoint",
id = 242887,
scene_type = "tank_fire_point",
position = irr.core.vector3df:new_local(5.945448,3.799506,0.019874),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
canon_id = 911647,
} -- tank.components.fire_point
tank.components.body = {
id = 394383,
name = "TankBody",
scene_type = "tank_body",
position = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/body.obj",
collision_mesh_path = "",
mass = 5.000000,
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.body
tank.components.wheel[1] = {
name = "TankWheel_left",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(2.693243,1.269679,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[1]
tank.components.wheel[2] = {
name = "TankWheel_left",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(0.924955,1.219899,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[2]
tank.components.wheel[3] = {
name = "TankWheel_left",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-0.807885,1.268874,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[3]
tank.components.wheel[4] = {
name = "TankWheel_left",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-2.530607,1.231423,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[4]
tank.components.wheel[5] = {
name = "TankWheel_left",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-4.177855,1.231712,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[5]
tank.components.wheel[6] = {
name = "TankWheel_left_front",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(3.987177,1.599830,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_front.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[6]
tank.components.wheel[7] = {
name = "TankWheel_right_back",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-5.687564,1.481726,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r_back.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[7]
tank.components.wheel[8] = {
name = "TankWheel_left_back",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-5.687564,1.481726,2.332120),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_l_back.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[8]
tank.components.wheel[9] = {
name = "TankWheel_right",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-4.177855,1.231712,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[9]
tank.components.wheel[10] = {
name = "TankWheel_right",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-2.530607,1.231712,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[10]
tank.components.wheel[11] = {
name = "TankWheel_right",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-0.807885,1.231712,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[11]
tank.components.wheel[12] = {
name = "TankWheel_right",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(0.924955,1.231712,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[12]
tank.components.wheel[13] = {
name = "TankWheel_right",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(2.693243,1.231712,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_r.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[13]
tank.components.wheel[14] = {
name = "TankWheel_right_front",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(3.987177,1.599830,-2.493460),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/t34/wheel_front.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[14]
tank.property = {turret_rotation_speed = 70,
tank_type = "standard",
health = 120,
fire_power = 200,
armor = 3.5,
max_speed = 14.7,
ricochet_possibility = 0.4,
reload_time = 15,
mesh_destoryed="resources/model/tanks/t34/t34_destroyed.obj",
}
return tank
