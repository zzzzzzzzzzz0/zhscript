/*
 * dlg.cpp
 *
 *  Created on: 2013年12月26日
 *      Author: zzzzzzzzzzz
 */
#include "def1.h"
#include "for_arg_.h"
#include "call_util.cpp"
#include <stdio.h>

/*#include <gtk/gtkdialog.h>
#include <gtk/gtkmessagedialog.h>
#include <gtk/gtkfilechooser.h>
#include <gtk/gtkfilechooserdialog.h>
#include <gtk/gtkstock.h>*/
#include <gtk/gtk.h>

#include <string>
#include <deque>
using namespace std;

int s2i__(const char* s1,int i){
	int i1=i;
	sscanf(s1,"%d",&i1);
	return i1;
}
bool err_buzu2__(const deque<string>* p, size_t need, int* err){
	if(p->size()<need){
		*err = 10;
		return true;
	}
	return false;
}

dlle___ int msgbox__(GtkWindow*parent, int argc, ...) {
	const char* text = "";
	const char* title = "";
	GtkDialogFlags flags;
	GtkMessageType type;
	GtkButtonsType buttons;
	flags=GTK_DIALOG_DESTROY_WITH_PARENT;
	type=GTK_MESSAGE_INFO;
	buttons=GTK_BUTTONS_OK;
	_for_args2( argc )
	switch(i) {
	case 0:
		text = s;
		break;
	case 1:
		title = s;
		break;
	case 2:
		type=(GtkMessageType)s2i__(s, type);
		break;
	case 3:
		buttons=(GtkButtonsType)s2i__(s,buttons);
		break;
	case 4:
		flags=(GtkDialogFlags)s2i__(s,flags);
		break;
	}
	_next_args
	GtkWidget* dialog = gtk_message_dialog_new (parent,
		flags,type,buttons,"%s",text);
	gtk_window_set_title(GTK_WINDOW(dialog), title);
	int ret = gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy (dialog);
	return ret;
}

dlle___ void file_select__(int* err, char**addr_ret, GtkWindow*parent,
		const char* type1, int argc, ...) {
	string type = type1;
	GtkFileChooserAction fca;
	const char* ok = GTK_STOCK_OPEN;
	if(type == "打开") {
		fca = GTK_FILE_CHOOSER_ACTION_OPEN;
	} else if(type == "保存") {
		fca = GTK_FILE_CHOOSER_ACTION_SAVE;
		ok = GTK_STOCK_SAVE;
	} else if(type == "文件夹") {
		fca = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
	} else if(type == "建立文件夹") {
		fca = GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
	} else {
		*err = 1;
		return;
	}

	deque<string> p1;
	_for_args( argc )
		p1.push_back(s ? s : "");
	_next_args
	deque<string>* p = &p1;

	GtkWidget *dialog = gtk_file_chooser_dialog_new (
			p->size() > 0 ? p1[0].c_str() : type1,
			parent,
			fca,
			GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
			ok,  GTK_RESPONSE_ACCEPT,
			NULL);
	GtkFileChooser* fc = GTK_FILE_CHOOSER (dialog);

	for(unsigned int i = 1; i < p->size(); i++) {
		const string& pi=(*p)[i];
		if(pi=="预选"){
			if(err_buzu2__(p, ++i, err))
				return;
			string& name=(*p)[i];
			if(name.length()>0){
				size_t i1=name.rfind('/');
				if(i1!=string::npos){
					gtk_file_chooser_set_current_folder(fc, name.substr(0,i1).c_str());
				}
				if(i1!=name.length()-1){
					gtk_file_chooser_set_filename(fc, name.c_str());
					gtk_file_chooser_select_filename(fc, name.c_str());
				}
			}
			continue;
		}
		if(pi=="类型"){
			if(err_buzu2__(p, ++i, err))
				return;
			GtkFileFilter* filter = gtk_file_filter_new();
			gtk_file_filter_set_name(filter, (*p)[i].c_str());
			if(err_buzu2__(p, ++i, err))
				return;
			gtk_file_filter_add_pattern(filter, (*p)[i].c_str());
			gtk_file_chooser_add_filter(fc, filter);
			continue;
		}
		if(pi == "覆盖确认") {
			gtk_file_chooser_set_do_overwrite_confirmation (fc, TRUE);
			continue;
		}
		*err = 2;
		return;
	}
	if (gtk_dialog_run (GTK_DIALOG (dialog)) ==  GTK_RESPONSE_ACCEPT)
	{
		char *filename = gtk_file_chooser_get_filename (fc);
		*addr_ret = dup__(filename);
		g_free (filename);
	}
	gtk_widget_destroy (dialog);
}
