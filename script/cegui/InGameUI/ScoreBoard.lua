local winMgr = CEGUI.WindowManager:getSingleton()
local root = winMgr:loadLayoutFromFile("inGameHud/Scoreboard.layout")
g_ui_table.hud=root

ScoreBoard={
	ui={
		root=root,
		list=CEGUI.toMultiColumnList(winMgr:createWindow("GlossySerpent/MultiColumnList", "list")),
	},
	players={},
	AddPlayer=function( self, player )
		self.players[player.id]={
			player=player,
			kill=0,
			death=0
		}
	end,
	Init= function( self, player_list )
		for _,v in pairs(player_list) do
			self:AddPlayer(v)
		end
		self:UpdateUI()
		Scene:addInternalObserver(self)
	end ,
	UpdateUI=function( self )
		self.ui.list:resetList()
		for _,v in pairs(self.players) do
			local status = "Online"
			if v.player.state ~=ACTOR_STATE.LIVE then
				status="Destroyed"
			end
			local kd_str = string.format("%d/%d",v.kill,v.death)

			local row=self.ui.list:addRow()
			--name
			local namecol=CEGUI.createListboxTextItem(v.player.name)
			--tank
			local tankcol=CEGUI.createListboxTextItem(v.player.tank_type)
			--status
			local statuscol=CEGUI.createListboxTextItem(status)
			--kill/death
			local kdcol=CEGUI.createListboxTextItem(kd_str)
			--team
			local teamcol=CEGUI.createListboxTextItem(tostring(v.player.team))

			v.ui_status=statuscol
			v.ui_kd=kdcol

			self.ui.list:setItem(namecol,0,row)
			self.ui.list:setItem(tankcol,1,row)
			self.ui.list:setItem(statuscol,2,row)
			self.ui.list:setItem(teamcol,3,row)
			self.ui.list:setItem(kdcol,4,row)
			-- self.ui.list:autoSizeColumnHeader(1)
		end
	end,
	UpdatePlayer=function( self, playerId )
		local p= self.players[playerId]
		if p then
			local status = "Online"
			if p.player.state ~= ACTOR_STATE.LIVE then
				status="Destroyed"
			end
			local kd_str = string.format("%d/%d",p.kill,p.death)
			p.ui_status:setText(status)
			p.ui_kd:setText(kd_str)
			self.ui.list:invalidate(true)
		end
	end,
	Clear=function( self )
		for k,_ in pairs(self.players) do
			self.players[k]=nil
		end
		--clear ui list
		self.ui.list:resetList()
	end,
	setVisible=function( self, visible )
		self.ui.root:setVisible(visible)
	end,
	getVisible=function( self )
		return self.ui.root:isVisible()
	end,
	OnPlayerDead=function( self, victim, attacker )
		local victim_p = self.players[victim.id]
		local attacker_p = self.players[attacker.id]
		if victim then
			victim_p.death = victim_p.death+1
		end
		if attacker_p then
			attacker_p.kill=attacker_p.kill+1
		end
		self:UpdatePlayer(victim.id)
		self:UpdatePlayer(attacker.id)
	end,
	OnPlayerRevive=function( self, player )
		self:UpdatePlayer(player.id)
	end,
	notify=function( self, invoker, event )
		local event_id = event.event_id
		if event_id == Scene.EVENT.PLAYER_DESTROYED then
			self:OnPlayerDead(invoker, event.attacker)
		elseif event_id == Scene.EVENT.PLAYER_REVIVE then
			self:OnPlayerRevive(invoker)
		end
	end,
}

local list = ScoreBoard.ui.list
list:setWidth(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
list:setHeight(CEGUI.PropertyHelper:stringToUDim("{1,0}"))
list:addColumn("Name", 0, CEGUI.PropertyHelper:stringToUDim("{0.25,0}"))
list:addColumn("Tank", 1, CEGUI.PropertyHelper:stringToUDim("{0.2,0}"))
list:addColumn("Status", 2, CEGUI.PropertyHelper:stringToUDim("{0.2,0}"))
list:addColumn("Team", 3, CEGUI.PropertyHelper:stringToUDim("{0.15,0}"))
list:addColumn("K/D", 4, CEGUI.PropertyHelper:stringToUDim("{0.2,0}"))
list:setProperty("ColumnsMovable",CEGUI.PropertyHelper:boolToString(false))
list:setMousePassThroughEnabled(true)
root:addChild(list)