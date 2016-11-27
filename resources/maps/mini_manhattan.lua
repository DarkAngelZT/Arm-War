local map_info={}
map_info.setting={
map_name = "mini_manhattan",
["ambient colour"] = irr.video.SColor:new_local(255,255,253,242),
["skydome texture"] = "resources/sfx/env/skydome/cloud_skydome.jpg",
logic_data = "",
} -- settings
-- objects
map_info.objects={}
map_info.objects[1] = {
name = "octree",
id = 394383,
scene_type = "octree",
physics_type = "static",
position = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
rotation = irr.core.vector3df:new_local(0.000000,0.000000,0.000000),
scale = irr.core.vector3df:new_local(1.000000,1.000000,1.000000),
mesh_path = "resources/maps/mini_manhattan/city.3ds",
textures = {
"resources/maps/mini_manhattan/bulding.png",
"resources/maps/mini_manhattan/city.png",
}, -- textures
logic_data = "",
} -- map_info.objects[1]
return map_info