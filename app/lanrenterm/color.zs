赋予颜色文件【主】以‘配置目录’/color.zs。
如果调用‘exist’、‘颜色文件’否则
	调用‘echo’、“设置颜色白底黑字”、‘颜色文件’。

赋予最佳一【主】以131/255,148/255,150/255,1:0,43/255,53/255,1。
赋予白底黑字【主】以0,0,0,1:1,1,1,1。
赋予黑底白字【主】以1,1,1,1:0,0,0,1。
赋予蓝底白字【主】以1,1,1,1:0,0,1,1。
赋予青底黑字【主】以0,0,0,1:0,1,1,1。
赋予红底黄字【主】以1,1,0,1:1,0,0,1。
赋予绿底粉字【主】以1,0,1,1:0,1,0,1。

定义设置颜色【主】以下代码
	别名值以参数1。
	别名窗以参数2。
	如果不存在窗那么赋予窗以主窗。
	
	使‘窗’、附、颜色、‘值’。
	定义处理【穿透】以下代码
		调用‘正则迭’、‘参数1’、
		([^,]+),([^,]+),([^,]+),([^,]+):
		([^,]+),([^,]+),([^,]+),([^,]+)、下代码
			显示‘参数0【上】【上】’‘参数’换行。
			使‘窗’、前景色、算术‘参数1’、算术‘参数2’、算术‘参数3’、算术‘参数4’。
			使‘窗’、背景色、算术‘参数5’、算术‘参数6’、算术‘参数7’、算术‘参数8’。
			退出。
		上代码。
	上代码。
	如果存在‘值’【主】那么处理‘‘值’’。
	处理‘值’。
	调用‘正则迭’、‘参数1’、
	([^,]+),([^,]+),([^,]+):
	([^,]+),([^,]+),([^,]+)、下代码
		显示‘参数0【上】’‘参数’换行。
		使‘窗’、前景色、算术‘参数1’、算术‘参数2’、算术‘参数3’、1。
		使‘窗’、背景色、算术‘参数4’、算术‘参数5’、算术‘参数6’、1。
	上代码。
上代码。

调用‘增至菜单’、‘更多菜单’、
-、
缺省代码为下代码
	别名值以参数0。
	调用‘echo’、“设置颜色‘值’”、‘颜色文件’。
	设置颜色‘值’。
上代码、
单选、
为白底黑字、
为黑底白字、
为最佳一、
为蓝底白字、
为青底黑字、
为红底黄字、
为绿底粉字。
