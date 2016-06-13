#include <gtk/gtk.h>
#include "def1.h"
#include <iostream>
#include "api1.cpp"
#include <string>

class data___ {
public:
	std::string code_;
};

static void drag_data_received__(GtkWidget *widget,
		GdkDragContext *context,
		gint x,gint y,
		GtkSelectionData *data,
		guint info,
		guint time,
		gpointer user_data)
{
	GdkAtom atom=gtk_selection_data_get_data_type(data);
	if(gtk_targets_include_uri(&atom,1)){
		gchar **uris=gtk_selection_data_get_uris(data);
		gint i=0;
		int err;
		while(uris[i]!=NULL){
			gchar* f1 = g_filename_from_uri(uris[i], NULL, NULL);
#ifdef ver_test2_
			std::cout << f1 << std::endl;
#else
			const char* ret = callback_(jsq_, main_qu_, &err, NULL, ((data___*)user_data)->code_.c_str(), false, NULL, 1, f1);
			switch(err) {
			case jieshiqi_err_go_ + keyword_exit_:
				break;
			default:
				l4_err_out_(jsq_, ret, err, 1);
			}
			g_free(f1);
#endif
			i++;
		}
		g_strfreev(uris);
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

#ifdef ver_test2_
#include <vte/vte.h>
int main(int argc,char *argv[]) {
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
