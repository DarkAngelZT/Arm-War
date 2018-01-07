print '启动程序...'

--注册系统变量
DIR_DATA="resources/data/"
DIR_RESOURCES="resources/"
DIR_SOUND="resources/sound/"
DIR_EDITOR="resources/Editor/"
DIR_MAPS="resources/maps/"
DIR_MAP_PREVIEW="resources/ui/images/mapPreview/"
DIR_TANKS="resources/model/tanks/"
DIR_SHELL="resources/model/ammo/shell/"
DIR_SCRIPT="script/"
DIR_SCRIPT_CEGUI="script/cegui/"

print '加载系统配置...'
require(DIR_DATA..'syscfg')
require(DIR_SCRIPT..'system_function_init')
