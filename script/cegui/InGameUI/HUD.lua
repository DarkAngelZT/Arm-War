require(DIR_SCRIPT_CEGUI.."InGameUI/ScoreBoard")

local winMgr = CEGUI.WindowManager:getSingleton()
CEGUI.ImageManager:getSingleton():loadImageset("gameHUD.imageset");
local root = winMgr:loadLayoutFromFile("inGameHud/HUD.layout")
g_ui_table.hud=root