赋予帐号以隧道内容为username。
赋予密码以隧道内容为password。
显示‘肇事者’-‘动作’-‘帐号’-‘密码’字符10。

如果‘帐号’等于“”或者‘密码’等于“”那么隧道提示为帐号或者密码等于空，退出。

加载lib/base64。
赋予【顶】协议头片段2以“‘协议头片段1’
Authorization: Basic ”先调用‘base64encode’为‘帐号’:‘密码’了“字符13字符10”。

赋予1以解释‘更新表格’。
显示‘1’字符10。
如果‘1’小于1那么删除【顶】协议头片段2，隧道提示为登入失败，退出。

隧道标签页为notebook1为1。
隧道标签页为notebook2为0。

