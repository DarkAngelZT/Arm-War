options_menu={}
-----------------------------------------
-- Handler to  key input
-----------------------------------------
function options_menu.keyInput( args )
	local keycode = CEGUI.toKeyEventArgs(args)
	if keycode.scancode == CEGUI.Key.Escape then
		if backupSettings ~=nil then
			ApplicationSettings = backupSettings
		end
		--直接退出
		g_ui_table.switchto("main")
	end
end
-----------------------------------------
-- Handler to  ok and cancel button
-----------------------------------------
options_menu.exit = 
function ( args )
	local btnName=CEGUI.toWindowEventArgs(args).window:getName()
	if btnName == "btn_ok" then
		--保存设置
		Application_Save_Settings()
		backupSettings=nil
		--退回主界面
		g_ui_table.switchto("main")
	elseif btnName == "btn_cancel" then
		--还原系统设定
		if backupSettings ~=nil then
			ApplicationSettings = backupSettings
		end
		--直接退出
		g_ui_table.switchto("main")
	end
end
-----------------------------------------
-- Handler to  resulotion combo box
-----------------------------------------
function options_menu.resolutionChange( args )
	--取出当前的选项，作为key来获取表中的分辨率数值
	local selection = CEGUI.toCombobox(CEGUI.toWindowEventArgs(args).window):getText()
	local resolution=options_menu.resolution_list[selection];
	if resolution ~= nil then
		ApplicationSettings.resolution.width=resolution[1]
		ApplicationSettings.resolution.height=resolution[2]
	end

end
-----------------------------------------
-- Handler to  all check box item
-----------------------------------------
function options_menu.checkbox( args )
	local wnd = CEGUI.toToggleButton(CEGUI.toWindowEventArgs(args).window)
	local name = wnd:getName()
	if name == "FullScreen_cb" then
		ApplicationSettings.fullscreen = wnd:isSelected()
	elseif name == "RealTimeShadow" then
		ApplicationSettings.realtimeShadow = wnd:isSelected()
	end
end
-----------------------------------------
-- Handler to  all scroll bar item
-----------------------------------------
function options_menu.scrollbar( args )
	local  wnd = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
	local name = wnd:getName()
	if name == "BGMVolume_sb" then
		ApplicationSettings.SoundVolume.bgm=wnd:getScrollPosition()*100
	elseif name == "EffectVolume_sb" then
		ApplicationSettings.SoundVolume.effect=wnd:getScrollPosition()*100
	end
end
-----------------------------------------
-- function to  refresh ui display
-----------------------------------------
function options_menu.refresh(  )
	--更新分辨率选中条目
	local rootWnd = CEGUI.System:getSingleton():getDefaultGUIContext():getRootWindow()
	local cbx=CEGUI.toCombobox(rootWnd:getChild("Resolution_cb"))
	local  currentResolution = string.format(
		"%d×%d",
		ApplicationSettings.resolution.width,
		ApplicationSettings.resolution.height)
	cbx:setText(currentResolution)
	--“全屏” 勾选框
	local fulscrbtn = CEGUI.toToggleButton(rootWnd:getChild("FullScreen_cb"))
	fulscrbtn:setSelected(ApplicationSettings.fullscreen)
	--”实时阴影“勾选框
	CEGUI.toToggleButton(rootWnd:getChild("RealTimeShadow")):setSelected(ApplicationSettings.realtimeShadow)
	--音效设置
	CEGUI.toScrollbar(rootWnd:getChild("BGMVolume_sb")):setScrollPosition(ApplicationSettings.SoundVolume.bgm/100)
	CEGUI.toScrollbar(rootWnd:getChild("EffectVolume_sb")):setScrollPosition(ApplicationSettings.SoundVolume.effect/100)
end
-----------------------------------------
-- Script Entry Point
-----------------------------------------
-- load our window layout
local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("Options.layout")
g_ui_table.options=root
--初始化支持的分辨率列表
options_menu.resolution_list = {}
local rstr = NeoGraphics:getInstance():GetAvailableResolution()
local rlist =split(rstr,";")
local r
for r=1 , #rlist do
	local str_resolution= split(rlist[r],",")
	local key = str_resolution[1].."×"..str_resolution[2]
	options_menu.resolution_list[key] = {
		tonumber(str_resolution[1]),tonumber(str_resolution[2]),
		text=key
		}
end
local resolution_cbx=CEGUI.toCombobox(root:getChild("Resolution_cb"))

for i,v in pairs(options_menu.resolution_list) do
	local listItem = CEGUI.createListboxTextItem(v.text)
	listItem:setSelectionBrushImage("GlossySerpent/ListboxSelectionBrush")
	resolution_cbx:addItem(listItem)
end


--注册事件
resolution_cbx:subscribeEvent("ListSelectionAccepted","options_menu.resolutionChange")
root:getChild("FullScreen_cb"):subscribeEvent("SelectStateChanged","options_menu.checkbox")
root:getChild("RealTimeShadow"):subscribeEvent("SelectStateChanged","options_menu.checkbox")
root:getChild("BGMVolume_sb"):subscribeEvent("ScrollPositionChanged","options_menu.scrollbar")
root:getChild("EffectVolume_sb"):subscribeEvent("ScrollPositionChanged","options_menu.scrollbar")
root:getChild("btn_ok"):subscribeEvent("Clicked","options_menu.exit")
root:getChild("btn_cancel"):subscribeEvent("Clicked","options_menu.exit")
root:subscribeEvent("KeyUp","options_menu.keyInput")