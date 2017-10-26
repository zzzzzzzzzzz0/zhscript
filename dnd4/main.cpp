#include <gtk/gtk.h>
#include "def1.h"
#include <iostream>
#include "api1.cpp"
#include <string>
#include <stdlib.h>

class data___ {
public:
	std::string code_;
};

static void chuli__(const std::string &code, gchar *uri) {
	gchar* f1 = g_filename_from_uri(uri, NULL, NULL);
#ifdef ver_test2_
	std::cout << code << "(" << f1 << ")" << std::endl;
#else
	int err;
	const char* ret = callback_(jsq_, main_qu_, &err, NULL, code.c_str(), false, NULL, 1, f1);
	switch(err) {
	case jieshiqi_err_go_ + keyword_exit_:
		break;
	default:
		l4_err_out_(jsq_, ret, err, 1);
	}
	g_free(f1);
#endif
}

static void drag_data_received__(GtkWidget *widget,
		GdkDragContext *context,
		gint x,gint y,
		GtkSelectionData *data,
		guint info,
		guint time,
		gpointer user_data)
{
#ifdef ver_test2_
	std::cout << "drag_data_received__"
			<< "data.data(" << gtk_selection_data_get_data (data) << ")"
			<< std::endl;
#endif
	GdkAtom atom=gtk_selection_data_get_data_type(data);
#ifdef ver_test2_
	std::cout << "gdk_atom_name(" << gdk_atom_name (atom) << ")" << std::endl;
#endif
	const std::string &code = ((data___*)user_data)->code_;
	if(gtk_targets_include_uri(&atom,1))
	{
		gchar **uris=gtk_selection_data_get_uris(data);
		gint i=0;
		while(uris[i]!=NULL)
			chuli__(code, uris[i++]);
		g_strfreev(uris);
	}
	else {
		gchar *uris = (gchar *)gtk_selection_data_get_text (data);
		if(uris) {
			for(int i = 0, i2 = 0;; i++) {
				gchar c = uris[i];
				bool b = !c;
				if(c == '\n' || c == '\r' || b) {
					uris[i] = 0;
					if(i2 < i)
						chuli__(code, uris + i2);
					i2 = i + 1;
				}
				if(b)
					break;
			}
		}
	}

	gtk_drag_finish(context,TRUE,TRUE,time);
}

static GtkTargetEntry files_drop_targets[] = {
	{ "STRING",			0, 0 },
	{ "UTF8_STRING",	0, 0 },
	{ "text/plain",		0, 0 },
	{ "text/uri-list",	0, 0 }
};
dlle___ void add__(GtkWidget *w1, GdkDragAction da, const char* code) {
	data___* data = new data___();
	data->code_ = code;
	g_signal_connect(w1, "drag-data-received", G_CALLBACK(drag_data_received__), data);
	gtk_drag_dest_set(w1, GTK_DEST_DEFAULT_ALL, files_drop_targets, G_N_ELEMENTS(files_drop_targets), da);
}
dlle___ void add2__(GtkWidget *w1, const char* da2, const char* code) {
	GdkDragAction da = GDK_ACTION_DEFAULT;
	if(da2) {
		std::string da3 = da2;
		if(da3 == "复制")
			da = GDK_ACTION_COPY;
		else if(da3 == "移动")
			da = GDK_ACTION_MOVE;
		else if(da3 == "链接")
			da = GDK_ACTION_LINK;
		else
			da = (GdkDragAction)atoi(da2);
	}
	add__(w1, da, code);
}

#ifdef ver_test2_
#include <vte/vte.h>
int main(int argc,char *argv[]) {
	std::cout
	<< GDK_ACTION_DEFAULT << std::endl
	<< GDK_ACTION_COPY << std::endl
	<< GDK_ACTION_MOVE << std::endl
	<< GDK_ACTION_LINK << std::endl
	<< GDK_ACTION_PRIVATE << std::endl
	<< GDK_ACTION_ASK << std::endl
	;

	gtk_init(&argc,&argv);
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"5");
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),400,300);
	g_signal_connect(G_OBJECT(window),"destroy", G_CALLBACK(gtk_main_quit),NULL);

	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_set_homogeneous(GTK_BOX(box), FALSE);
	gtk_container_add(GTK_CONTAINER(window), box);
	GtkWidget *vte = vte_terminal_new();
	gchar *fake_argv[] = {"/bin/bash", "-", NULL};
	vte_terminal_spawn_sync(VTE_TERMINAL(vte), (VtePtyFlags)0, NULL, fake_argv, NULL, (GSpawnFlags)0, NULL, NULL, NULL, NULL, NULL);
	g_signal_connect(G_OBJECT(vte), "child_exited", G_CALLBACK(gtk_main_quit), NULL);
	gtk_box_pack_start(GTK_BOX(box), vte, TRUE, TRUE, 0);
	add__(vte, GDK_ACTION_LINK, "");

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
#endif
