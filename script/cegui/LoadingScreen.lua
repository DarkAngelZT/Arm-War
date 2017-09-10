local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("loading.layout")
g_ui_table.loading=root

LoadingScreen={}
LoadingScreen.progressBar=CEGUI.toProgressBar(root:getChild("ProgressBar"))
LoadingScreen.percentText=root:getChild("percentText")
LoadingScreen.background=root:getChild("bg")

CEGUI.ImageManager:getSingleton():addFromImageFile("splash_image_loading","splash_image.jpg","images")
LoadingScreen.background:setProperty("Image","splash_image_loading")

LoadingScreen.Init=function()
	LoadingScreen.progressBar:setProgress(0)
	LoadingScreen.percentText:setText("loading...")
end

function LoadingScreen.setProgressPercent( p )
	LoadingScreen.progressBar:setProgress(p/100)
end

function LoadingScreen.setMessage( m )
	LoadingScreen.percentText:setText(m)
end