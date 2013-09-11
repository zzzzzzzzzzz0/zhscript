/*
 * dnd___.cpp
 *
 *  Created on: 2011-9-24
 *      Author: zzzzzzzzzzz
 */

#include "dnd___.h"
#include"plugin_def.h"
//#include "util.cpp"

void dnd_cb___::unset__(){
	switch(type_){
	case'd':
		gtk_drag_dest_unset(w_);
		g_signal_handler_disconnect(w_, sid_);
		break;
	}
}

static void
drag_data_received__
(GtkWidget *widget, GdkDragContext *context, gint x, gint y,
        GtkSelectionData *selection_data, guint target_type, guint time,
        gpointer data)
{
	gboolean dnd_success = FALSE;
	gboolean delete_selection_data = FALSE;

	if ((selection_data != NULL) && (selection_data->length >= 0)) {
		if (context->action == GDK_ACTION_MOVE)
			delete_selection_data = TRUE;

		char a2[16],a3[16];
		sprintf(a2,"%d",target_type);
		sprintf(a3,"%d",context->action);
		dnd_cb___* cb=(dnd_cb___*)data;
		const char*argv[]={(gchar*)selection_data->data,a2,a3};
		int err;
		cb->d_(cb->sh_,call4_1_,cb->code_.c_str(),NULL,NULL,NULL,NULL,3,argv,0,NULL,&err);
		if(err){
			cb->d_(cb->sh_,call4_2_,err);
		}else
			dnd_success = TRUE;
	}

	gtk_drag_finish(context, dnd_success, delete_selection_data, time);
}

void dnd___::del__(GtkWidget* w1){
	for(deque<dnd_cb___*>::iterator di=cb_.begin();di!=cb_.end();){
		dnd_cb___* cb=*di;
		if(cb->w_==w1||!w1){
			di=cb_.erase(di);
			cb->unset__();
			delete cb;
		}else
			di++;
	}
}

dnd___::~dnd___(){
	del__(NULL);
}

int dnd___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji,void*ce) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if(p->size()<3){
			d_(sh_,err_show_buzu_,p);
			return 1;
		}
		Gtk::Widget* w;
		sh_->builder_->get_widget((*p)[2], w);
		if(!w){
			d_(sh_,err_show_wufa_,2,p,2);
			return 1;
		}
		GtkWidget* w1=w->gobj();
		if((*p)[1]=="移除"){
			del__(w1);
			return 1;
		}
		if((*p)[1]=="目标"){
			if(p->size()<6){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			int gdd=0,gda=0;

			dnd_cb___* cb=new dnd_cb___('d',w1,sh_,d_);
			for(size_t i=3;i<p->size();i++){
				const Glib::ustring& p1=(*p)[i];
				if(p1=="代码"){
					if(++i>=p->size()){
						d_(sh_,err_show_buzu_,p);
						delete cb;
						return 1;
					}
					cb->code_=(*p)[i];
					continue;
				}
				if(p1=="复制"){
					gda|=GDK_ACTION_COPY;
					continue;
				}
				if(p1=="移动"){
					gda|=GDK_ACTION_MOVE;
					continue;
				}
				if(p1=="链接"){
					gda|=GDK_ACTION_LINK;
					continue;
				}
				if(p1=="高亮"){
					gdd|=GTK_DEST_DEFAULT_HIGHLIGHT|GTK_DEST_DEFAULT_MOTION;
					continue;
				}
				if(p1=="按钮"){
					gdd|=GTK_DEST_DEFAULT_DROP|GTK_DEST_DEFAULT_MOTION;
					continue;
				}
				delete cb;
				d_(sh_,err_show_buzhichi_,2,p,i);
				return 1;
			}

			gtk_drag_dest_set (w1, (GtkDestDefaults)gdd, 0, 0, (GdkDragAction)gda);
			gtk_drag_dest_add_uri_targets(w1);
			cb->sid_=g_signal_connect (w1, "drag-data-received",G_CALLBACK(drag_data_received__), cb);

			cb_.push_back(cb);
			return 1;
		}
		d_(sh_,err_show_buzhichi_,2,p,1);
		return 1;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new dnd___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
