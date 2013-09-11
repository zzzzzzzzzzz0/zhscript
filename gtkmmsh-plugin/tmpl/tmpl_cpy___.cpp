/*
 * cpy_tmpl.cpp
 *
 *  Created on: 2010-6-9
 *      Author: zzzzzzzzzzz
 */

#include "tmpl___.h"
#include"util.h"
#include"plugin_def.h"

Gtk::Container* tmpl___::cpy_tmpl__(Gtk::Container*c,Gtk::Container*c2,Gtk::Container*c4){
	tmpl_cpy_idx_=0;
	return tmpl_cpy__(c,c2,c4);
}
class button___{
private:
	Glib::ustring argv_[4];
	shell___* sh_;
	direct___ d_;
	Glib::ustring code_;
public:
	button___(const char*zhao,const char*dong,const char*arg3,const char*arg4,shell___* sh,direct___ d){
		sh_=sh;
		d_=d;
		argv_[0]=zhao;
		argv_[1]=dong;
		argv_[2]=arg3;
		argv_[3]=arg4;
	}
	void on__(){
		d_(sh_,on_,code_.c_str(),NULL,4,argv_[0].c_str(),argv_[1].c_str(),argv_[2].c_str(),argv_[3].c_str());
	}
};

Gtk::Container* tmpl___::tmpl_cpy__(Gtk::Container*c,Gtk::Container*c2,Gtk::Container*c4){
	tmpl_cpy_idx_++;
	if(!c2){
		for(;;){
			Gtk::Frame* f=dynamic_cast<Gtk::Frame*>(c);
			if(f){
				Gtk::Frame*f2=Gtk::manage(new Gtk::Frame());
				f2->set_label(f->get_label());
				f2->set_shadow_type(f->get_shadow_type());
				c2=f2;
				break;
			}
			return NULL;
		}
		c2->set_visible(true);
		c4=c2;
	}
	Glib::ListHandle<Gtk::Widget*> ls=c->get_children();
	for(Glib::ListHandle<Gtk::Widget*>::const_iterator i=ls.begin();i!=ls.end();i++){
		Gtk::Widget*w=*i;
		Gtk::Widget*w1=NULL;
		//w1=Gtk::manage(Glib::wrap(w->gobj()));
		for(;;){
			Gtk::Alignment*a = dynamic_cast<Gtk::Alignment*>(w);
			if(a){
				Gtk::Alignment*a2;
				a2=Gtk::manage(new Gtk::Alignment(
						a->property_xalign(),a->property_yalign(),
						a->property_xscale(),a->property_yscale()
						));
				a2->set_padding(
						a->property_top_padding(),
						a->property_bottom_padding(),
						a->property_left_padding(),
						a->property_right_padding());
				w1=a2;
				break;
			}
			Gtk::HBox*hb=dynamic_cast<Gtk::HBox*>(w);
			if(hb){
				Gtk::HBox*hb2;
				hb2=Gtk::manage(new Gtk::HBox(hb->get_homogeneous(),hb->get_spacing()));
				//hb2=Gtk::manage(new Gtk::HBox(hb->gobj_copy()));
				w1=hb2;
				break;
			}
			Gtk::VButtonBox*vbb=dynamic_cast<Gtk::VButtonBox*>(w);
			if(vbb){
				Gtk::VButtonBox*vbb2;
				vbb2=Gtk::manage(new Gtk::VButtonBox(vbb->property_layout_style(),vbb->get_spacing()));
				w1=vbb2;
				break;
			}

			Gtk::TextView*tv=dynamic_cast<Gtk::TextView*>(w);
			if(tv){
				Gtk::TextView*tv2;
				tv2=Gtk::manage(new Gtk::TextView());
				tv2->set_wrap_mode(tv->get_wrap_mode());
				tv2->set_editable(tv->get_editable());
				w1=tv2;
				break;
			}
			Gtk::Button*b=dynamic_cast<Gtk::Button*>(w);
			if(b){
				Gtk::Button*b2;
				//b2=Glib::wrap(b->gobj(),true);
				b2=Gtk::manage(new Gtk::Button());
				b2->set_label(b->get_label());
				float xalign, yalign;
				b->get_alignment (xalign, yalign);
				b2->set_alignment (xalign, yalign);
				b2->set_focus_on_click(b->get_focus_on_click());

				char buf[32],buf2[8];
				button___* ctl=new button___("按钮"
						,"模板"
						,l2s__((long)c4,buf)
						,l2s__(tmpl_cpy_idx_+1,buf2)
						,sh_,d_);
				b2->signal_clicked().connect(sigc::mem_fun(*ctl, &button___::on__));
				b2->set_data("ctl",ctl);

				w1=b2;
				break;
			}
			Gtk::Label*l=dynamic_cast<Gtk::Label*>(w);
			if(l){
				Gtk::Label*l2=Gtk::manage(new Gtk::Label());
				l2->set_use_markup(l->get_use_markup());
				if(l->get_use_markup())
					l2->set_markup(l->get_label());
				else
					l2->set_label(l->get_label());
				w1=l2;
				break;
			}
			Gtk::Entry* e=dynamic_cast<Gtk::Entry*>(w);
			if(e){
				Gtk::Entry* e2=Gtk::manage(new Gtk::Entry());
				e2->set_text(e->get_text());
				w1=e2;
				break;
			}
			Gtk::Image*img=dynamic_cast<Gtk::Image*>(w);
			if(img){
				Gtk::Image*img2=Gtk::manage(new Gtk::Image());
				//img->property_stock();
				w1=img2;
				break;
			}
			d_(sh_,err_show_,3,"模板处理",w->get_name().c_str(),"时没对应");
			return NULL;
		}
		if(!w1)
			continue;
		w1->set_visible(w->get_visible());
		/*Gtk::Container* cp=w->get_parent();
		if(cp){
			cout<<cp->get_name()<<" "<<w1->get_name()<<endl;
		}*/

		for(;;){
			Gtk::HBox*hb3;
			Gtk::VButtonBox*vbb3;
			Gtk::Button*b3;
			Gtk::Label*l3;
			hb3=dynamic_cast<Gtk::HBox*>(c2);
			vbb3=dynamic_cast<Gtk::VButtonBox*>(w1);
			if(hb3&&vbb3){
				hb3->pack_start(*vbb3,false,false,0);
				break;
			}
			b3=dynamic_cast<Gtk::Button*>(w1);
			if(hb3&&b3){
				hb3->pack_start(*b3,false,false,0);
				break;
			}
			l3=dynamic_cast<Gtk::Label*>(w1);
			if(hb3&&l3){
				hb3->pack_start(*l3,false,false,0);
				break;
			}
			vbb3=dynamic_cast<Gtk::VButtonBox*>(c2);
			b3=dynamic_cast<Gtk::Button*>(w1);
			if(b3&&vbb3){
				vbb3->pack_start(*b3,false,false,0);
				break;
			}
			c2->add(*w1);
			break;
		}

		Gtk::Container* c1 = dynamic_cast<Gtk::Container*>(w);
		if(c1){
			if(!tmpl_cpy__(c1,dynamic_cast<Gtk::Container*>(w1),c4))
				return NULL;
			continue;
		}
		tmpl_cpy_idx_++;
	}
	return c2;
}
