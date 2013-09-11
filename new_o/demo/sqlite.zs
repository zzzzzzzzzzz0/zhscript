#!../l --。
加载lib/defi。
加载lib/sqlite4。
赋予库以调用‘【sqlite4】打开’、/tmp/test.sqlite。
显示‘库’↙。

赋予sql以“CREATE TABLE SensorData(
ID INTEGER PRIMARY KEY,
SensorID INTEGER,
SiteNum INTEGER,
Time VARCHAR(12),
SensorParameter REAL
);”。
赋予1以调用‘【sqlite4】执行’、‘库’、‘sql’。
显示‘1’↙。

赋予1以调用‘【sqlite4】执行’、‘库’、“delete from SensorData”。
显示‘1’↙。

赋予1以调用‘【sqlite4】执行’、‘库’、“INSERT INTO "SensorData" VALUES(NULL , 1 , 1 , '200605011206', 18.9 );”。
显示‘1’↙。
赋予1以调用‘【sqlite4】执行’、‘库’、“INSERT INTO "SensorData" VALUES(NULL , 1 , 1 , '200605011306', 16.4 );”。
显示‘1’↙。

赋予1以调用‘【sqlite4】得表’、下代码
	显示→‘参数’↙。
上代码、‘库’、“SELECT * FROM SensorData”、1。
显示‘1’↙。

赋予1以调用‘【sqlite4】关闭’、‘库’。
显示‘1’↙。
加载lib/sqlite4-。