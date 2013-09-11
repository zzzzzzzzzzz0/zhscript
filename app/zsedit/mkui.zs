#!/_no/l --e-x-d--。
#!/usr/bin/zhscript --。
加载lib/gjke4。
加载lib/gjk4。
加载lib/regexpr4。
赋予【顶】这以。
迭代解释下代码
	别名号以参数1。
	赋予号1以算术‘号’-1。
	赋予1以调用‘正则替’、下原样
                <child>
                  <object class="GtkVBox" id="vbox___a___a">
                    <property name="visible">True</property>

                    <child>
                      <object class="GtkHBox" id="hbox___a___a">
                        <property name="visible">True</property>
                        <child>
                          <object class="GtkLabel" id="label___a___a">
                            <property name="visible">True</property>
                            <property name="label" translatable="yes">&#x9879;&#x76EE;&#x8FD0;&#x884C;</property>
                          </object>
                          <packing>
                            <property name="expand">False</property>
                            <property name="position">0</property>
                          </packing>
                        </child>
                        <child>
                          <object class="GtkEntry" id="cmd___a___">
                            <property name="visible">True</property>
                            <property name="invisible_char">&#x25CF;</property>
                          </object>
                          <packing>
                            <property name="position">1</property>
                          </packing>
                        </child>
                      </object>
                      <packing>
                        <property name="expand">False</property>
                        <property name="position">0</property>
                      </packing>
                    </child>
                    <child>
                      <object class="GtkHBox" id="hbox___a___b">
                        <property name="visible">True</property>
                        <child>
                          <object class="GtkLabel" id="label___a___b">
                            <property name="visible">True</property>
                            <property name="label" translatable="yes">&#x6CE8;&#x91CA;</property>
                          </object>
                          <packing>
                            <property name="expand">False</property>
                            <property name="position">0</property>
                          </packing>
                        </child>
                        <child>
                          <object class="GtkEntry" id="rem___a___">
                            <property name="visible">True</property>
                            <property name="invisible_char">&#x25CF;</property>
                          </object>
                          <packing>
                            <property name="position">1</property>
                          </packing>
                        </child>
                      </object>
                      <packing>
                        <property name="expand">False</property>
                        <property name="position">1</property>
                      </packing>
                    </child>

                    <child>
                      <object class="GtkScrolledWindow" id="page___a___">
                        <property name="visible">True</property>
                        <property name="can_focus">True</property>
                        <property name="hscrollbar_policy">automatic</property>
                        <property name="vscrollbar_policy">automatic</property>
                        <child>
                          <placeholder/>
                        </child>
                      </object>
                      <packing>
                        <property name="position">2</property>
                      </packing>
                    </child>
                  </object>
                  <packing>
                    <property name="position">___b___</property>
                  </packing>
                </child>
                <child type="tab">
                  <object class="GtkLabel" id="title___a___">
                    <property name="visible">True</property>
                  </object>
                  <packing>
                    <property name="position">___b___</property>
                    <property name="tab_fill">False</property>
                  </packing>
                </child>
上原样、(___a___)、‘号’。
	赋予【顶】这以‘这’调用‘正则替’、‘1’、(___b___)、‘号1’。
上代码、1、2、3、4、5、6、7、8、9、10、11、12、13、14、15、16、17、18、19、20。

执行“cp ui.glade _ui.glade”。
加载lib/xml4。
加载lib/defi。
赋予xml以调用‘xml_from_file’、_ui.glade。
显示‘xml’↙。
赋予【顶】那以。
定义显-示以“赋予【顶】那以‘那’‘参数1’”。
显-示“<?xml version="1.0" encoding="UTF-8" standalone="no"?>”。
定义遍历以“
别名节点以参数1。
别名禁子以参数2。
赋予第1个以1。
循环先
	赋予名以调用‘xml_node_name’、‘节点’。
	如果‘禁子’并且‘名’等于child那么先
		如果‘这’那么显-示‘这’，赋予【顶】这以。
	了否则先
		如果‘第1个’并且‘名’等于text那么赋予名以。
		当‘名’先
			等于comment那么显-示<!--，跳出。
			‘名’那么先
				显-示<‘名’。
	
				赋予属性以调用‘xml_attr’、‘节点’。
				如果‘属性’那么先
					循环先
						赋予属名以调用‘xml_attr_name’、‘属性’。
						赋予属值以调用‘xml_attr_text’、‘属性’。
						显-示“ ‘属名’="‘属值’"”。
						如果‘属名’等于id并且‘属值’等于notebook1那么先
							赋予禁子以1。
						了。
						赋予属性以调用‘xml_next_attr’、‘属性’。
						如果‘属性’否则跳出。
					了。
				了。
				显-示>。
			了。
		了。

		显-示先调用‘xml_node_text’、‘节点’了。
	
		赋予子以调用‘xml_children’、‘节点’。
		如果‘子’那么遍历‘子’、‘禁子’。

		当‘名’先
			等于comment那么显-示-->，跳出。
			‘名’那么显-示</‘名’>字符10。
		了。
	了。
	赋予节点以调用‘xml_next’、‘节点’。
	如果‘节点’否则跳出。
	赋予第1个以0。
了。”。
遍历先调用‘xml_root’、‘xml’了、0。
调用‘xml_free’、‘xml’。
加载lib/doscmd4。
调用‘echo’、‘那’、ui.glade。
