print '启动程序...'

--注册系统变量
DIR_DATA="resources/data/"
DIR_RESOURCES="resources/"
DIR_EDITOR="resources/Editor/"
DIR_MAPS="resources/maps/"
DIR_SCRIPT="script/"
DIR_SCRIPT_CEGUI="script/cegui/"

print '加载系统配置...'
dofile(DIR_DATA..'syscfg.lua')
dofile(DIR_SCRIPT..'system_function_init.lua')
