#!/usr/bin/zhscript --。
加载lib/defi。
加载lib/gjk4。
加载lib/gjke4。

新建数组子、3、
br、heiju、2、
bn、heima、2、
bb、heixiang、2、
ba、heishi、2、
bk、heishuai、1、
bc、heipao、2、
bp、heizu、5、

rr、hongju、2、
rn、hongma、2、
rb、hongxiang、2、
ra、hongshi、2、
rk、hongshuai、1、
rc、hongpao、2、
rp、hongzu、5。

显示下原样<?xml version="1.0"?>
<interface>
  <requires lib="gtk+" version="2.16"/>
  <!-- interface-naming-policy project-wide -->
  <object class="GtkWindow" id="main_window">
    <property name="visible">True</property>
    <property name="events">GDK_BUTTON_PRESS_MASK | GDK_STRUCTURE_MASK</property>
    <property name="title" translatable="yes">&#x8857;&#x5934;&#x8C61;&#x68CB;</property>
    <property name="resizable">False</property>
    <property name="window_position">center</property>
    <child>
      <object class="GtkFixed" id="di">
        <property name="width_request">521</property>
        <property name="height_request">577</property>
        <property name="visible">True</property>
上原样。

序迭代数组下代码
	赋予序以算术‘参数1’%7。
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数4’那么跳出。
		赋予名以‘参数3’‘号’。
		赋予x以0。
		赋予y以0。
		当‘序’先
			大于等于1并且小于等于4那么先
				如果‘号’等于1
					那么赋予x以算术‘序’-1。
					否则赋予x以算术9-‘序’。
				跳出。
			了。
			等于5那么赋予x以4，跳出。
			等于6那么先
				如果‘号’等于1
					那么赋予x以1。
					否则赋予x以7。
				赋予y以2。
				跳出。
			了。
			等于0那么先
				赋予x以算术(‘号’-1)*2。
				赋予y以3。
				跳出。
			了。
		了。
		如果‘参数1’大于7那么
			赋予y以算术9-‘y’。
		赋予x以算术‘x’*57。
		赋予y以算术‘y’*57。
		如果‘参数1’大于7那么
			赋予y以算术‘y’-4。
显示下原样
        <child>
          <object class="GtkButton" id="上原样‘名’下原样">
            <property name="visible">True</property>
            <property name="can_focus">True</property>
            <property name="receives_default">True</property>
            <property name="image">image_上原样‘名’下原样</property>
            <property name="relief">none</property>
          </object>
          <packing>
            <property name="x">上原样‘x’下原样</property>
            <property name="y">上原样‘y’下原样</property>
          </packing>
        </child>
上原样。
	了。
上代码、子。

显示下原样
      </object>
    </child>
  </object>
上原样。

迭代数组下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数3’那么跳出。
显示下原样
  <object class="GtkImage" id="image_上原样‘参数2’‘号’下原样">
    <property name="visible">True</property>
    <property name="pixbuf">上原样‘参数1’下原样.gif</property>
  </object>
上原样。
	了。
上代码、子。

显示下原样
</interface>
上原样。


显示<!--。
序迭代数组下代码
	赋予号以0。
	循环先
		赋予号以算术‘号’+1。
		如果‘号’大于‘参数4’那么跳出。
		赋予名以‘参数3’‘号’。
		显示‘名’“、”。
	了。
上代码、子。
显示-->↙。