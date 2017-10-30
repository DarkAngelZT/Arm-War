FontManager={
	fonts={},
	default="OpenSans-Bold-12"
}

function FontManager:createFont( ttf_file, size, new_font_name )
	if self.fonts[new_font_name] then
		return
	end
	local font = NeoGraphics:getInstance():LoadTTFFont("resources/ui/cegui_data/fonts/"..ttf_file,size)
	if font then
		self.fonts[new_font_name]=font
	end
end

function FontManager:getFont( font_name )
	if self.fonts[font_name] then
		return self.fonts[font_name]
	else
		return
	end
end