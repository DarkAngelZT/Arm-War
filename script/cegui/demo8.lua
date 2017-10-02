-----------------------------------------
-- Start of handler functions
-----------------------------------------
-----------------------------------------
-- Alpha slider handler (not used!)
-----------------------------------------
function sliderHandler(args)
    CEGUI.System:getSingleton():getDefaultGUIContext():getRootWindow():setAlpha(CEGUI.toSlider(CEGUI.toWindowEventArgs(args).window):getCurrentValue())
end

-----------------------------------------
-- Handler to slide pane
--
-- Here we move the 'Demo8' sheet window
-- and re-position the scrollbar
-----------------------------------------
function panelSlideHandler(args)
    local scroller = CEGUI.toScrollbar(CEGUI.toWindowEventArgs(args).window)
    local demoWnd = CEGUI.System:getSingleton():getDefaultGUIContext():getRootWindow():getChild("Demo8")

    local parentPixelHeight = demoWnd:getParent():getPixelSize().height
    local relHeight = CEGUI.CoordConverter:asRelative(demoWnd:getHeight(), parentPixelHeight)

    scroller:setPosition(CEGUI.UVector2(CEGUI.UDim(0,0), CEGUI.UDim(scroller:getScrollPosition() / relHeight,0)))
    demoWnd:setPosition(CEGUI.UVector2(CEGUI.UDim(0,0), CEGUI.UDim(-scroller:getScrollPosition(),0)))
end

-----------------------------------------
-- Handler to set preview colour when
-- colour selector scrollers change
-----------------------------------------
function colourChangeHandler(args)
    local root = CEGUI.System:getSingleton():getDefaultGUIContext():getRootWindow()
    
    local r = CEGUI.toScrollbar(root:getChild("Demo8/Window1/Controls/Red")):getScrollPosition()
    local g = CEGUI.toScrollbar(root:getChild("Demo8/Window1/Controls/Green")):getScrollPosition()
    local b = CEGUI.toScrollbar(root:getChild("Demo8/Window1/Controls/Blue")):getScrollPosition()
    local col = CEGUI.Colour:new_local(r, g, b, 1)
    local crect = CEGUI.ColourRect(col)

    root:getChild("Demo8/Window1/Controls/ColourSample"):setProperty("ImageColours", CEGUI.PropertyHelper:colourRectToString(crect))
end


-----------------------------------------
-- Handler to add an item to the box
-----------------------------------------
function addItemHandler(args)
    local root = CEGUI.System:getSingleton():getDefaultGUIContext():getRootWindow()

    local text = root:getChild("Demo8/Window1/Controls/Editbox"):getText()
    local cols = CEGUI.PropertyHelper:stringToColourRect(root:getChild("Demo8/Window1/Controls/ColourSample"):getProperty("ImageColours"))

    local newItem = CEGUI.createListboxTextItem(text, 0, nil, false, true)
    newItem:setSelectionBrushImage("TaharezLook/MultiListSelectionBrush")
    newItem:setSelectionColours(cols)

    CEGUI.toListbox(root:getChild("Demo8/Window1/Listbox")):addItem(newItem)
end

function testCallback(args)
    local  event=toNeoEvent(args)
    if event:getTriggerId()==0 then
        if tonumber(event:getData(0))==irr.KEY_KEY_V then
            if tonumber(event:getData(1))==1 then
                print('button V is pressed down')
            else
                print("button V is left up")
            end
        end
    elseif event:getTriggerId()==1 then
        type=event:getData(0)
        if type=='W' then
            print ("mouse wheel: "..tonumber(event:getData(1)))
        else
            if type=="L" then
                mousebt="Left mouse button"
            else 
                mousebt="Right mouse button"
            end
            if event:getData(1)=="1" then
                op=" is pressed down"
            else
                op=" is left up"
            end
            print(mousebt..op)
        end
    end--if
end--function
-----------------------------------------
-- Script Entry Point
-----------------------------------------
local guiSystem = CEGUI.System:getSingleton()
local schemeMgr = CEGUI.SchemeManager:getSingleton()
local winMgr = CEGUI.WindowManager:getSingleton()

-- load our demo8 scheme
schemeMgr:createFromFile("GlossySerpent.scheme");
-- load our demo8 window layout
local root = winMgr:loadLayoutFromFile("mainMenu.layout")
-- set the layout as the root
guiSystem:getDefaultGUIContext():setRootWindow(root)
-- set default mouse cursor
guiSystem:getDefaultGUIContext():getMouseCursor():setDefaultImage("GlossySerpentCursors/MouseArrow")
-- set the Tooltip type
guiSystem:getDefaultGUIContext():setDefaultTooltipType("GlossySerpent/Tooltip")

-- subscribe required events
-- root:getChild("Demo8/ViewScroll"):subscribeEvent("ScrollPositionChanged", "panelSlideHandler")
-- root:getChild("Demo8/Window1/Controls/Blue"):subscribeEvent("ScrollPositionChanged", "colourChangeHandler")
-- root:getChild("Demo8/Window1/Controls/Red"):subscribeEvent("ScrollPositionChanged", "colourChangeHandler")
-- root:getChild("Demo8/Window1/Controls/Green"):subscribeEvent("ScrollPositionChanged", "colourChangeHandler")
-- root:getChild("Demo8/Window1/Controls/Add"):subscribeEvent("Clicked", "addItemHandler")
local gl=NeoGameLogic:getInstance()
local trigger=NeoTrigger:create()
trigger:setTriggerFunction("testCallback")
trigger:addTriggerCondition(0)
trigger:addTriggerCondition(1)
gl:RegisterTrigger(trigger)

-- v3=irr.core.vector3df:new_local(1,2,3)
-- v3_2=irr.core.vector3df:new_local(0,0,0)
-- print(v3<v3_2)
-- print((v3-v3_2).X)
-- v3.X=2
-- print(v3:getInterpolated(v3_2,0.5).X)