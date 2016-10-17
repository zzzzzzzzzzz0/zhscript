/*
 * api_tab.cpp
 *
 *  Created on: 2016年2月12日
 *      Author: zzzzzzzzzzz
 */
#include "shell___.h"
#include "extern.h"
#include "extern2.h"

bool shell___::api_page__(void*shangji,void*ce,deque<string>* p,char*buf,long siz,char**addr_ret){
	const string& p0=(*p)[0];
	const string& p1=(*p)[1];
	window___* w;
	int page_num;
	char z = 0;

	if(p1=="标签号"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(p->size()<3){
			l2s__(w->c__()->current_page__()+1,buf);
		}else
			w->c__()->set_page__(s2i__((*p)[2])-1);
		return true;
	}
	if(p1=="标签名"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkWidget*sw = w->c__()->nth_page2__(page_num);if(!sw)return true;
		if(p->size()<3){
			string name2;
			w->name2__(name2, sw);
			cpy__(buf, name2.c_str(), siz);
		} else {
			const char* name = (*p)[2].c_str();
			if(w->c__()->page_num__(name) != notebook_page_no_) {
				err_wufa__(p1, name);
				return true;
			}
			gtk_widget_set_name(sw, name);
		}
		return true;
	}
	if(p1=="标签数目"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		l2s__(w->c__()->n_pages__(), buf);
		return true;
	}
	if(p1=="标签")
		z = 't';
	else if(p1=="标签前")
		z = 'b';
	else if(p1=="隐藏标签")
		z = 'h';
	else if(p1=="隐藏标签前")
		z = 'i';
	else if(p1=="菜单标签")
		z = 'm';
	switch(z) {
	case 't': case 'b': case 'h': case 'i': case 'm':
	{
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkLabel* l;
		switch(z) {
		case 't': case 'h':
			l = w->c__()->label__(page_num);
			break;
		default:
			l = w->c__()->label2__(page_num);
			break;
		case 'm':
			l=w->c__()->menu_label__(page_num);
			break;
		}
		if(!l){
			err_wufa__(p1,p0.c_str());
			return true;
		}
		switch(z) {
		case 'i': case 'h':
			gtk_widget_hide (GTK_WIDGET(l));
			break;
		default:
			if(p->size()<3){
				cpy__(buf, gtk_label_get_text(l), siz);
			}else {
				gtk_widget_show(GTK_WIDGET(l));
				const string& s = (*p)[2];
				gtk_label_set_markup(l, s.c_str());
			}
			break;
		}
		return true;
	}
	}
	if(p1=="标签提示"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		GtkLabel* l=w->c__()->label__(page_num);
		if(!l){
			err_wufa__(p1,p0.c_str());
			return true;
		}
		if(p->size()<3){
			cpy__(buf, gtk_widget_get_tooltip_markup(GTK_WIDGET(l)), siz);
		}else
			gtk_widget_set_tooltip_markup(GTK_WIDGET(l), (*p)[2].c_str());
		return true;
	}
	if(p1=="附"){
		w=get_window__(p0,page_num,p1);if(!w)return true;
		if(err_buzu2__(p, 3, 0))
			return true;
		string name = p1; name += "-"; name += (*p)[2];
		char* data = (char*)w->c__()->get_data__(page_num, name.c_str());
		if(p->size() < 4) {
			cpy__(buf, data, siz);
		}else {
			if(data)
				delete data;
			const string& data1 = (*p)[3];
			size_t siz1 = data1.size() + 1;
			data = new char[siz1];
			cpy__(data, data1.c_str(), siz1);
			w->c__()->set_data__(page_num, name.c_str(), data);
		}
		return true;
	}
	return false;
}
