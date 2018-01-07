dofile(DIR_SCRIPT.."utilities/utilities.lua")
--------------------------------------------
-- Application control
--------------------------------------------
function Application_Quit(args)
	Application:getInstance():Quit()
end
--------------------------------------------
-- Save application settings
--------------------------------------------
function Application_Save_Settings()
	print("Save system settings...")
	cfgfile=io.open(DIR_DATA.."syscfg.lua","w")
	if cfgfile then
		--header
		cfgfile:write("-- Auto saved system settings\n\n")
		cfgfile:write(string.format("%s%s\n\n","-- File created on: ",os.date()))
		--settings
		cfgfile:write("ApplicationSettings = {}\n\n")
		cfgfile:write(string.format("%s{ %s = %d, %s = %d }\n",
			"ApplicationSettings.resolution = ",
			"width",ApplicationSettings.resolution.width,
			"height",ApplicationSettings.resolution.height))
		cfgfile:write(string.format("%s = \"%s\" -- This cannot be empty\n\n",
			"ApplicationSettings.caption",ApplicationSettings.caption))
		cfgfile:write(string.format("%s%s\n","ApplicationSettings.fullscreen = ", 
			tostring(ApplicationSettings.fullscreen)))
		cfgfile:write(string.format("%s%s\n\n","ApplicationSettings.realtimeShadow = ",
			tostring(ApplicationSettings.realtimeShadow)))

		cfgfile:write(string.format("%s = \"%s\"\n","ApplicationSettings.SoundDevice", 
			ApplicationSettings.SoundDevice))
		cfgfile:write("ApplicationSettings.SoundVolume = {}\n")
		cfgfile:write(string.format("ApplicationSettings.SoundVolume.master = %d\n",
			ApplicationSettings.SoundVolume.master))
		cfgfile:write(string.format("%s%d\n","ApplicationSettings.SoundVolume.bgm = ", 
			ApplicationSettings.SoundVolume.bgm))
		cfgfile:write(string.format("%s%d\n","ApplicationSettings.SoundVolume.effect = ", 
			ApplicationSettings.SoundVolume.effect))

		--close file
		io.close(cfgfile)
	end
	print("Save done.")
end