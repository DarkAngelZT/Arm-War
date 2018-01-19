local tank={}
tank.components={}
tank.components.wheel={}
tank.components.track={}
tank.tank_name = "maus"
tank.components.track[1] = {
id = 769914,
name = "TankTrack_l",
scene_type = "tank_track",
position = irr.core.vector3df:new_local(2.320998,0.015165,2.870448),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_track.obj",
collision_mesh_path = "",
mass = 20.000000,
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.track[1]
tank.components.track[2] = {
id = 400229,
name = "TankTrack_r",
scene_type = "tank_track",
position = irr.core.vector3df:new_local(2.320998,0.015165,-2.100557),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_track.obj",
collision_mesh_path = "",
mass = 20.000000,
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
position = irr.core.vector3df:new_local(-0.784235,4.093414,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_turret.obj",
collision_mesh_path = "",
mass = 10.000000,
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.turret
tank.components.canon = {
id = 911647,
name = "TankCanon",
scene_type = "tank_canon",
position = irr.core.vector3df:new_local(3.687766,5.520816,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/canon.x",
collision_mesh_path = "resources/model/tanks/maus/canon_col.obj",
mass = 3.000000,
min_angle = -5.000000,
max_angle = 45.000000,
autoplay = true,
startLoop = "idle",
animation = {
{ id = 1, label = "idle", from = 0, to = 0 },
{ id = 2, label = "fire", from = 1, to = 15 },
},
} -- tank.components.canon
tank.components.fire_point = {
name = "TankFirePoint",
id = 970634,
scene_type = "tank_fire_point",
position = irr.core.vector3df:new_local(15.304369,5.173468,-0.037012),
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
mesh_path = "resources/model/tanks/maus/maus_body.obj",
collision_mesh_path = "",
mass = 15.000000,
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.body
tank.components.wheel[1] = {
name = "TankWheel_fl",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(10.619404,1.417910,2.493890),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/fblw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[1]
tank.components.wheel[2] = {
name = "TankWheel_fr",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(10.606834,1.392523,-2.560178),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/fbrw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[2]
tank.components.wheel[3] = {
name = "TankWheel_br",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-6.207540,1.296517,-2.560178),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/fbrw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[3]
tank.components.wheel[4] = {
name = "TankWheel_bl",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-6.238755,1.260677,2.444848),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/fblw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[4]
tank.components.wheel[5] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-3.876077,0.722363,2.704908),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[5]
tank.components.wheel[6] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-1.166682,0.722363,2.704908),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[6]
tank.components.wheel[7] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(1.237167,0.722363,2.704908),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[7]
tank.components.wheel[8] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(3.578787,0.722363,2.704908),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[8]
tank.components.wheel[9] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(5.913903,0.722363,2.704908),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[9]
tank.components.wheel[10] = {
name = "TankWheel_lw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(8.373323,0.722363,2.634478),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_lw.obj",
side = "left",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[10]
tank.components.wheel[11] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(8.383675,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[11]
tank.components.wheel[12] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(5.844763,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[12]
tank.components.wheel[13] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(3.609522,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[13]
tank.components.wheel[14] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(1.167763,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[14]
tank.components.wheel[15] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-1.229395,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[15]
tank.components.wheel[16] = {
name = "TankWheel_rw",
scene_type = "tank_wheel",
position = irr.core.vector3df:new_local(-4.025164,0.672302,-2.598651),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/model/tanks/maus/maus_rw.obj",
side = "right",
autoplay = true,
startLoop = "",
animation = {
},
} -- tank.components.wheel[16]
tank.property = {tank_type = "standard",
mesh_destroyed = "resources/model/tanks/maus/maus_des.obj",
turret_rotation_speed = 50,
}
return tank
