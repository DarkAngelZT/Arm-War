--Loaders
--------------------------------------------
-- Sprite Loader
--------------------------------------------
function SpriteLoader( file_name )
	-- body
	--generate sprite name
	strs=split(file_name,'.')
	path=''
	for i=1,#strs-1,1 do
		path=path..strs[i]
	end
	path=path..'.sprite'
	parent_path='resources/sfx/sprites/'
	--get sprite config
	data=dofile(parent_path..path)
	NeoGraphics:getInstance():getSfxManager():AddSpriteTexture(file_name,data.row, data.column)
end
--------------------------------------------
-- Scene Loader
-- @map_info: a table contain all data about how to load and place object
--------------------------------------------
function SceneLoaderGeneric(map_info)
	-- body
	-- initialize sfx
	NeoGraphics:getInstance():getSfxManager():Init()
end
