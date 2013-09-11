#!../l -I zh --。
加载lib/regexpr4。
加载lib/redireconsoi4。
赋予视频以如果存在参数1那么‘参数1’否则/_vid/夏.rm。
赋予信息以调用‘重定向输出’、显示“mplayer -identify ‘视频’ -nosound -vc dummy -vo null”字符10。
显示‘信息’字符10。
赋予长以调用‘regexpr’、‘信息’、“ID_LENGTH=([^字符10]+)”。
如果‘长’否则显示“‘视频’可能不存在字符10”，结束。
赋予宽以调用‘regexpr’、‘信息’、ID_VIDEO_WIDTH=([^字符10]+)。
赋予高以调用‘regexpr’、‘信息’、ID_VIDEO_HEIGHT=([^字符10]+)。
显示“
视频：字符9‘视频’字符10
长：字符9‘长’字符10
宽x高：字符9‘宽’x‘高’字符10
”。
