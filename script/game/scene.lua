Scene={}
Scene.entities={}
Scene.load=SceneLoaderGeneric;
Scene.entityMap={
	common=CommonObjectEntity
}

function Scene.LoadEntity( data )
	local logic_data=nil
	if(data.logic_data ~= "")then
		data.logic_data = eval("return {"+data.logic_data+"}")
	end
	local entity_type = "common"
	if logic_data then
		entity_type = logic_data.entity_type
	end
	Scene.entityMap[entity_type].load(data,logic_data)
end

function Scene.Clear()
	-- body
end