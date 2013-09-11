/*
 * huitu___.cpp
 *
 *  Created on: 2010-9-13
 *      Author: zzzzzzzzzzz
 */

#include "huitu___.h"
#include"plugin_def.h"
#include"util.cpp"

float s2f__(const Glib::ustring&s,float d=0.0){
	sscanf(s.c_str(),"%f",&d);
	return d;
}

void cos__(Glib::ustring& d1,char*buf){
    //cpy__(buf,cos(s2f__(d1)),32);
	sprintf(buf,"%f",cos(s2f__(d1)));
}

void sin__(Glib::ustring& d1,char*buf){
    //cpy__(buf,sin(s2f__(d1)),32);
	sprintf(buf,"%f",sin(s2f__(d1)));
}

class area___{
private:
	shell___* sh_;
	direct___ d_;
	huitu___* ht_;
	Gtk::DrawingArea* da_;
	Cairo::RefPtr<Cairo::Context> cr_;
	bool expose_evt__(GdkEventExpose* event);
	void test__();
public:
	area___(Gtk::DrawingArea* da,huitu___*ht,shell___* sh,direct___ d){
		da_=da;
		ht_=ht;
		sh_=sh;
		d_=d;
		da->signal_expose_event().connect(sigc::mem_fun(*this, &area___::expose_evt__), false);
	}
	Glib::ustring code_;
	void shuaxin__(){
	    Glib::RefPtr<Gdk::Window> w = da_->get_window();
	    if (w) {
	    	Gtk::Allocation a = da_->get_allocation();
	        Gdk::Rectangle r(0, 0,a.get_width(),a.get_height());
	        w->invalidate_rect(r, false);
	    }
	}
	void get_width__(char*buf){
	    cpy__(buf,da_->get_allocation().get_width(),32);
	}
	void get_height__(char*buf){
	    cpy__(buf,da_->get_allocation().get_height(),32);
	}
	void huaju__(char*buf){
	    Glib::RefPtr<Gdk::Window> w = da_->get_window();
	    if (w) {
	    	cr_ = w->create_cairo_context();
	    }
	}
	bool keyi__(){
	    Glib::RefPtr<Gdk::Window> w = da_->get_window();
	    if(!w)
	    	return false;
	    if(!cr_)
	    	return false;
	    return true;
	}
	void scale__(Glib::ustring& w,Glib::ustring& h){
		cr_->scale(s2i__(w), s2i__(h));
	}
	void scale2__(Glib::ustring& x,Glib::ustring& y){
		cr_->scale(s2f__(x), s2f__(y));
	}
	void translate__(Glib::ustring& d1,Glib::ustring& d2){
		cr_->translate(s2f__(d1), s2f__(d2));
	}
	void set_line_width__(Glib::ustring& d1){
		cr_->set_line_width(s2f__(d1));
	}
	void set_source_rgba__(Glib::ustring& d1,Glib::ustring& d2,Glib::ustring& d3,Glib::ustring& d4){
		cr_->set_source_rgba(s2f__(d1),s2f__(d2),s2f__(d3),s2f__(d4));
	}
	void arc__(Glib::ustring& d1,Glib::ustring& d2,Glib::ustring& d3,Glib::ustring& d4,Glib::ustring& d5){
		cr_->arc(s2f__(d1),s2f__(d2),s2f__(d3),s2f__(d4),s2f__(d5));
	}
	void move_to__(Glib::ustring& d1,Glib::ustring& d2){
		cr_->move_to(s2f__(d1),s2f__(d2));
	}
	void line_to__(Glib::ustring& d1,Glib::ustring& d2){
		cr_->line_to(s2f__(d1),s2f__(d2));
	}
	void save__(){
		cr_->save();
	}
	void paint__(){
		cr_->paint();
	}
	void restore__(){
		cr_->restore();
	}
	void fill_preserve__(){
		cr_->fill_preserve();
	}
	void stroke_preserve__(){
		cr_->stroke_preserve();
	}
	void stroke__(){
		cr_->stroke();
	}
	void clip__(){
		cr_->clip();
	}
	void fill__(){
		cr_->fill();
	}
	void set_line_cap__(Cairo::LineCap lc){
		cr_->set_line_cap(lc);
	}
	void set_source__(Glib::ustring& src,Glib::ustring& x,Glib::ustring& y){
		Cairo::RefPtr< Cairo::ImageSurface > is;
		is = Cairo::ImageSurface::create_from_png (src);
		cr_->set_source(is,s2f__(x),s2f__(y));
	}
	void rotate__(Glib::ustring& d1){
		cr_->rotate(s2f__(d1));
	}
};

area___* get_area__(std::deque<Glib::ustring>* p,shell___*sh,direct___ d,size_t i=2){
	if(p->size()<=i){
		d(sh,err_show_buzu_,p);
		return NULL;
	}
	area___* a=dynamic_cast<area___*>((area___*)s2l__((*p)[i],0));
	if(!a)
		d(sh,err_show_wufa_,3,p,i,1);
	return a;
}

area___* get_area2__(std::deque<Glib::ustring>* p,shell___*sh,direct___ d,size_t i=2){
	area___* a=get_area__(p,sh,d,i);
	if(a){
		if(!a->keyi__()){
			d(sh,err_show_wufa_,3,p,0,1);
			return NULL;
		}
	}
	return a;
}

int huitu___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if(p->size()>1){
			area___* a;
			try{
				if((*p)[1]=="裁剪域"){
					if((a=get_area2__(p,sh_,d_)))
						a->clip__();
					return 1;
				}
				if((*p)[1]=="描画二"){
					if((a=get_area2__(p,sh_,d_)))
						a->stroke_preserve__();
					return 1;
				}
				if((*p)[1]=="描画"){
					if((a=get_area2__(p,sh_,d_)))
						a->stroke__();
					return 1;
				}
				if((*p)[1]=="填充二"){
					if((a=get_area2__(p,sh_,d_)))
						a->fill_preserve__();
					return 1;
				}
				if((*p)[1]=="填充"){
					if((a=get_area2__(p,sh_,d_)))
						a->fill__();
					return 1;
				}
				if((*p)[1]=="恢复"){
					if((a=get_area2__(p,sh_,d_)))
						a->restore__();
					return 1;
				}
				if((*p)[1]=="上色"||(*p)[1]=="绘制"){
					if((a=get_area2__(p,sh_,d_)))
						a->paint__();
					return 1;
				}
				if((*p)[1]=="保存"){
					if((a=get_area2__(p,sh_,d_)))
						a->save__();
					return 1;
				}
				if((*p)[1]=="平移"){
					if((a=get_area2__(p,sh_,d_,4)))
						a->translate__((*p)[2],(*p)[3]);
					return 1;
				}
				if((*p)[1]=="线宽"){
					if((a=get_area2__(p,sh_,d_,3)))
						a->set_line_width__((*p)[2]);
					return 1;
				}
				if((*p)[1]=="弧线"){
					if((a=get_area2__(p,sh_,d_,7)))
						a->arc__((*p)[2],(*p)[3],(*p)[4],(*p)[5],(*p)[6]);
					return 1;
				}
				if((*p)[1]=="坐标"){
					if((a=get_area2__(p,sh_,d_,4)))
						a->move_to__((*p)[2],(*p)[3]);
					return 1;
				}
				if((*p)[1]=="直线到"){
					if((a=get_area2__(p,sh_,d_,4)))
						a->line_to__((*p)[2],(*p)[3]);
					return 1;
				}
				if((*p)[1]=="颜色"){
					if((a=get_area2__(p,sh_,d_,6)))
						a->set_source_rgba__((*p)[2],(*p)[3],(*p)[4],(*p)[5]);
					return 1;
				}
				if((*p)[1]=="范围"){
					if((a=get_area2__(p,sh_,d_,4)))
						a->scale__((*p)[2],(*p)[3]);
					return 1;
				}
				if((*p)[1]=="缩放"){
					if((a=get_area2__(p,sh_,d_,4)))
						a->scale2__((*p)[2],(*p)[3]);
					return 1;
				}
				if((*p)[1]=="圆形线帽"){
					if((a=get_area2__(p,sh_,d_)))
						a->set_line_cap__(Cairo::LINE_CAP_ROUND);
					return 1;
				}
				if((*p)[1]=="源"){
					if((a=get_area2__(p,sh_,d_,5)))
						a->set_source__((*p)[2],(*p)[3],(*p)[4]);
					return 1;
				}
				if((*p)[1]=="旋转"){
					if((a=get_area2__(p,sh_,d_,3)))
						a->rotate__((*p)[2]);
					return 1;
				}

				if((*p)[1]=="cos"){
					if((a=get_area2__(p,sh_,d_,3)))
						cos__((*p)[2],buf);
					return 1;
				}
				if((*p)[1]=="sin"){
					if((a=get_area2__(p,sh_,d_,3)))
						sin__((*p)[2],buf);
					return 1;
				}
				if((*p)[1]=="宽"){
					if((a=get_area__(p,sh_,d_)))
						a->get_width__(buf);
					return 1;
				}
				if((*p)[1]=="高"){
					if((a=get_area__(p,sh_,d_)))
						a->get_height__(buf);
					return 1;
				}

				if((*p)[1]=="获得画具"){
					if((a=get_area__(p,sh_,d_)))
						a->huaju__(buf);
					return 1;
				}
				if((*p)[1]=="画架"){
					Gtk::DrawingArea* da;
					sh_->builder_->get_widget((*p)[2], da);
					if(!da){
						d_(sh_,err_show_wufa_,3,p,2,1);
						return 1;
					}
					a=new area___(da,this,sh_,d_);
					l2s__((long)a,buf);
					return 1;
				}
				if((*p)[1]=="代码"){
					if((a=get_area__(p,sh_,d_,3)))
						a->code_=(*p)[2];
					return 1;
				}
				if((*p)[1]=="刷新"){
					if((a=get_area__(p,sh_,d_)))
						a->shuaxin__();
					return 1;
				}
			}catch(...){
				d_(sh_,err_show_wufa_,3,p,0,1);
				return 1;
			}

			d_(sh_,err_show_buzhichi_,1,p);
			return 1;
		}
		d_(sh_,err_show_buzu_,p);
		return 1;
	}
	return 0;
}

bool area___::expose_evt__(GdkEventExpose* event){
	if(code_.size()>0){
		Glib::RefPtr<Gdk::Window> window=da_->get_window();
		if(window){
			cr_ = window->create_cairo_context();
			if(event){
				cr_->rectangle(event->area.x, event->area.y,
						event->area.width, event->area.height);
				cr_->clip();
			}

#ifdef debug_
			test__();
#else
			char buf[32];
			l2s__((long)this,buf);
			d_(sh_,on_,code_.c_str(),NULL,3,ht_->name__(),"重绘",buf);
#endif
		}
		return true;
	}
	return false;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new huitu___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}

#ifdef debug_
void area___::test__(){
	int width, height;
	width=da_->get_allocation().get_width();
	height=da_->get_allocation().get_height();

	double m_radius=0.42;
	double m_line_width=0.05;

	// scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
	// the center of the window
	cr_->scale(width, height);
	cr_->translate(0.5, 0.5);
	cr_->set_line_width(m_line_width);

	cr_->save();
	cr_->set_source_rgba(0.337, 0.612, 0.117, 0.9);   // green
	cr_->paint();
	cr_->restore();
	cr_->arc(0, 0, m_radius, 0, 2 * M_PI);
	cr_->save();
	cr_->set_source_rgba(1.0, 1.0, 1.0, 0.8);
	cr_->fill_preserve();
	cr_->restore();
	cr_->stroke_preserve();
	cr_->clip();

	//clock ticks
	for (int i = 0; i < 12; i++)
	{
		double inset = 0.05;

		cr_->save();
		cr_->set_line_cap(Cairo::LINE_CAP_ROUND);

		if(i % 3 != 0)
		{
			inset *= 0.8;
			cr_->set_line_width(0.03);
		}

		cr_->move_to(
				(m_radius - inset) * cos (i * M_PI / 6),
				(m_radius - inset) * sin (i * M_PI / 6));
		cr_->line_to (
				m_radius * cos (i * M_PI / 6),
				m_radius * sin (i * M_PI / 6));
		cr_->stroke();
		cr_->restore(); // stack-pen-size
	}

	// store the current time
	time_t rawtime;
	time(&rawtime);
	struct tm * timeinfo = localtime (&rawtime);

	// compute the angles of the indicators of our clock
	double minutes = timeinfo->tm_min * M_PI / 30;
	double hours = timeinfo->tm_hour * M_PI / 6;
	double seconds= timeinfo->tm_sec * M_PI / 30;
	cout<<timeinfo->tm_min<<","<<timeinfo->tm_hour<<","<<timeinfo->tm_sec<<endl;

	cr_->save();
	cr_->set_line_cap(Cairo::LINE_CAP_ROUND);

	// draw the seconds hand
	cr_->save();
	cr_->set_line_width(m_line_width / 3);
	cr_->set_source_rgba(0.7, 0.7, 0.7, 0.8); // gray
	cr_->move_to(0, 0);
	cr_->line_to(sin(seconds) * (m_radius * 0.9),
			-cos(seconds) * (m_radius * 0.9));
	cr_->stroke();
	cr_->restore();

	// draw the minutes hand
	cr_->set_source_rgba(0.117, 0.337, 0.612, 0.9);   // blue
	cr_->move_to(0, 0);
	cr_->line_to(sin(minutes + seconds / 60) * (m_radius * 0.8),
			-cos(minutes + seconds / 60) * (m_radius * 0.8));
	cr_->stroke();

	// draw the hours hand
	cr_->set_source_rgba(0.337, 0.612, 0.117, 0.9);   // green
	cr_->move_to(0, 0);
	cr_->line_to(sin(hours + minutes / 12.0) * (m_radius * 0.5),
			-cos(hours + minutes / 12.0) * (m_radius * 0.5));
	cr_->stroke();
	cr_->restore();

	// draw a little dot in the middle
	cr_->arc(0, 0, m_line_width / 3.0, 0, 2 * M_PI);
	cr_->fill();
}
#endif
