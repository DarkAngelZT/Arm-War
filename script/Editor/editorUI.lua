map_editor={}
--------------------------------------------
-- initialize
--------------------------------------------
function map_editor.Init()
	-- c++ initialize
	NeoEditor:getInstance():Init()
	-- camera
	graphicWrapper=NeoGraphics:getInstance()
	map_editor.camera=graphicWrapper:AddCameraSceneNode()
	map_editor.camera:setPosition(irr.core.vector3df:new_local(35,35,35))
	map_editor.camera:setTarget(irr.core.vector3df:new_local(0,0,0))
	--map info conrainer
	-- default skybox
	map_editor.skyboxTexture=graphicWrapper:LoadTexture(DIR_RESOURCES.."sfx/env/skydome/cloud_skydome.jpg")
	map_editor.skybox=graphicWrapper:AddSkyDomeSceneNode(map_editor.skyboxTexture,16,8,1.0)
	--default ambient colour
	graphicWrapper:SetAmbientLight(irr.video.SColor:new_local(255,255,253,242));
end

--------------------------------------------
-- clean the editor objects
--------------------------------------------
function map_editor.CleanUp()
	-- body
	NeoGraphics:getInstance():CleanUp()
	NeoGraphics:getInstance():UnloadTexture(map_editor.skyboxTexture)
end

--------------------------------------------
-- Event Handler
--------------------------------------------
function map_editor.Menu_File_callback( args )
	-- body
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "New" then
		--create new scene
		return
	elseif btnName == "open" then
		--open file dialog to load map
		return
	elseif btnName == "Quit" then
		g_ui_table.switchto("main")
		map_editor.CleanUp()
	end
end