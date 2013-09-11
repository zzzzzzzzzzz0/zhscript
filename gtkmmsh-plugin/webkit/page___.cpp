/*
 * page___.cpp
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */
#include"page___.h"
#include"util.h"

void page___::close__(){
	webkit_web_view_execute_script (wwv_,
			"var body=document.getElementsByTagName('body')[0];"
			"body.parentNode.removeChild(body);"
			);
	g_object_unref(wwv_);
	if(n_){
		if(parent_&&sw_==n_->get_nth_page(n_->get_current_page())){
			for(int pn=0;pn<n_->get_n_pages();pn++){
				if(parent_==n_->get_nth_page(pn)){
					n_->set_current_page(pn);
					break;
				}
			}
		}
		n_->remove_page(*sw_);
	}
}

void page___::titletip__(const Glib::ustring &str){
	if(title_)
		title_->set_tooltip_markup(str);
}
const char*page___::titletip__(){
	if(title_)
		return title_->get_tooltip_markup().c_str();
	return NULL;
}
void page___::title__(const Glib::ustring &str){
	if(title_)
		title_->set_markup(str);
}
const char*page___::title__(){
	if(title_)
		return title_->get_text().c_str();
	return NULL;
}

void page___::titletip__(char**addr_ret){
	if(title_)
		*addr_ret=dup__(title_->get_tooltip_markup().c_str());
}
void page___::title__(char**addr_ret){
	if(title_)
		*addr_ret=dup__(title_->get_text().c_str());
}

page___::page___(size_t i,Gtk::Notebook* n,WebKitWebView* wwv,Gtk::ScrolledWindow*sw){
	n_=n;
	wwv_=wwv;
	sw_=sw;
	gtk_container_add(GTK_CONTAINER(sw->gobj()), (GtkWidget*)wwv);
	sw->set_data("ctl",this);
	if(n_){
		Gtk::HBox*hb=Gtk::manage(new Gtk::HBox(false,0));
		title_=Gtk::manage(new Gtk::Label());
		hb->pack_start(*title_,false,false);
		if(i>0){
			char s[16];
			title_->set_text(l2s__(i,s));
			Gtk::Button*b=Gtk::manage(new Gtk::Button());
			Gtk::Image *img= Gtk::manage(new Gtk::Image( Gtk::StockID (Gtk::Stock::CLOSE),
                    Gtk::ICON_SIZE_MENU));
			b->set_relief(Gtk::RELIEF_NONE);
			b->set_image(*img);
			b->signal_clicked().connect(sigc::mem_fun(*this, &page___::close__));
			hb->pack_end(*b,false,false);
		}
		hb->show_all();
		int pn=n_->get_current_page();
		if(i>0)
			parent_=n_->get_nth_page(pn);
		else
			parent_=NULL;
		pn=n_->insert_page (*sw,*hb, pn+1);
		n_->show_all_children ();
		n_->set_current_page(pn);
	}else
		title_=NULL;
}
