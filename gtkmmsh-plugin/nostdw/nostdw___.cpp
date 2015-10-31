/*
 * nostdw___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "nostdw___.h"
#include"plugin_def.h"

float s2f__(const Glib::ustring&s,float d=0.0){
	sscanf(s.c_str(),"%f",&d);
	return d;
}

gint32 s2i__(const Glib::ustring&s,gint32 i=-1){
	sscanf(s.c_str(),"%d",&i);
	return i;
}

Gtk::Window* nostdw___::ww__(std::deque<Glib::ustring>* p,int i){
	if(p->size()<=i)
		return sh_->main_win_;
	Gtk::Window* w;
	sh_->builder_->get_widget((*p)[i], w);
	if(!w){
		d_(sh_,err_show_wufa_,2,p,i);
	}
	return w;
}

int nostdw___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	const Glib::ustring& p0=(*p)[0];

	if(p0=="置顶"){
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		ww->set_keep_above(true);
		return 1;
	}
	if(p0=="取消置顶"){
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		ww->set_keep_above(false);
		return 1;
	}
	if(p0=="无边框"){
		Gtk::Window* ww=ww__(p,1);
		if(!ww)
			return 1;
		ww->set_decorated(false);
		return 1;
	}
	if(p0=="窗口背景"){
		if(siz==-1)return 1;
		Gtk::Window* w=ww__(p,2);
		if(!w)
			return 1;
		Glib::RefPtr<Gdk::Window> w2=w->get_window();
		if(w2){
			if(!w->get_app_paintable()){
				w->set_app_paintable(true);
				//w->realize();
				/*Gtk::Widget* w1=dynamic_cast<Gtk::Widget*>(w);
				gtk_widget_realize(w1->gobj());*/
			}

			const Glib::ustring& p1=(*p)[1];
			if(p1.size()>0&&p1[0]=='#'){
				Gdk::Color c;
				Glib::ustring c1=p1.substr(1);
				c.set(c1);
				cout<<c1<<"="<<c.to_string()<<endl;
				w2->set_background(c);
			}else{
#ifdef ver_gtk3_
				//gtk_layout_put(w, , 0, 0);

				/*GtkCssProvider *provider = gtk_css_provider_new ();
				gtk_style_context_add_provider_for_screen (w2->get_screen()->gobj(),
					GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				Glib::ustring s = "GtkWindow {background-image:url('" + p1 + "');}";
				gtk_css_provider_load_from_data (GTK_CSS_PROVIDER (provider), s.c_str(), -1, NULL);
				g_object_unref (provider);*/

				/*pb_=Gdk::Pixbuf::create_from_file(p1,w->get_width(),w->get_height(),false);
				GtkStyle *style = gtk_style_new ();
				style->bg_pixmap [0] = pb_->gobj();
				gtk_widget_set_style (w, style);*/
#else
				pb_=Gdk::Pixbuf::create_from_file(p1,w->get_width(),w->get_height(),false);
				Glib::RefPtr<Gdk::Pixmap> pm;
				Glib::RefPtr<Gdk::Bitmap> bm;
				pb_->render_pixmap_and_mask(pm,bm,128);
				w->shape_combine_mask(bm,0,0);
				w2->set_back_pixmap(pm,false);
#endif
			}
		}

		return 1;
	}
	if(p0=="不透明度"||p0=="透明度"){
		if(siz==-1)return 1;
		if(p->size()<=1)
			d_(sh_,err_show_buzu_,p);
		else{
			Gtk::Window* ww=ww__(p,2);
			if(!ww)
				return 1;
			ww->set_opacity(s2f__((*p)[1]));
		}
		return 1;
	}
	if(p0=="a值"){
		if(siz==-1)return 1;
		if(p->size()<=2)
			d_(sh_,err_show_buzu_,p);
		else{
			if(pb_){
				const GdkPixbuf *pb1=pb_->gobj ();
				int w,h;
				guchar *ps;
				unsigned long n,r;
				w=pb_->get_width();
				h=pb_->get_height();
				ps=gdk_pixbuf_get_pixels(pb1);
				n=gdk_pixbuf_get_n_channels(pb1);
				r=gdk_pixbuf_get_rowstride(pb1);

				int x=s2i__((*p)[1]);
				int y=s2i__((*p)[2]);
				if(x>=0&&x<w&&y>=0&&y<h){
					unsigned long o=r * y + n * x;
					sprintf(buf,"%d",ps[o+n-1]);
				}
			}
		}
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new nostdw___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

