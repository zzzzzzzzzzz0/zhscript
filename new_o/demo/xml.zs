#!../l -I zh --。
加载lib/xml4。
赋予xml以调用‘xml_from_str’、下原样<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<statuses>
  <status>
    <created_at>Sun May 30 21:59:06 +0800 2010</created_at>
    <id>32086421</id>
    <user>
      <id>5352290</id>
      <name/>
    </user>
  </status>
  <status>
    <created_at>Mon Mar 22 11:12:30 +0800 2010</created_at>
    <id>1308212</id>
    <user>
      <id>545547</id>
      <name/>
    </user>
  </status>
  <test a1="1" a2="" />
</statuses>
<!--注释-->
上原样。

定义“显示一”以“显示‘参数1’”。

定义遍历以下代码
	别名节点以参数1。
	赋予第1个以1。
	循环先
		赋予名以调用‘xml_node_name’、‘节点’。
		如果‘第1个’并且‘名’等于text那么赋予名以。
		当‘名’先
			等于comment那么显示一<!--，跳出。
			‘名’那么先
				显示一<‘名’。
	
				赋予属性以调用‘xml_attr’、‘节点’。
				循环先
					如果不‘属性’那么跳出。
					赋予属名以调用‘xml_attr_name’、‘属性’。
					赋予属值以调用‘xml_attr_text’、‘属性’。
					显示一“ ‘属名’="‘属值’"”。
					赋予属性以调用‘xml_next_attr’、‘属性’。
				了。
				显示一>。
			了。
		了。

		显示一先调用‘xml_node_text’、‘节点’了。
	
		赋予子以调用‘xml_children’、‘节点’。
		如果‘子’那么遍历‘子’。

		当‘名’先
			等于comment那么显示一-->，跳出。
			‘名’那么显示一</‘名’>字符10。
		了。
		赋予节点以调用‘xml_next’、‘节点’。
		如果‘节点’否则跳出。
		赋予第1个以0。
	了。
上代码。
遍历先调用‘xml_root’、‘xml’了。
显示字符10。
调用‘xml_free’、‘xml’。
