/*
 * vte_window___.cpp
 *
 *  Created on: 2013年12月12日
 *      Author: zzzzzzzzzzz
 */
#include "vte_view___.h"
#include "sh-base/s1___.h"

int vte_view___::fork_command__(const char* cmd, const char* env,
		const char* wd) {
	char **argv = NULL;
	if(cmd) {
		g_shell_parse_argv(cmd, NULL, &argv, NULL);
	}
	char** envv = NULL;
	if(env) {
		g_shell_parse_argv(env, NULL, &envv, NULL);
	}
	GError *error = NULL;
	//0
	//VTE_PTY_NO_LASTLOG|VTE_PTY_NO_UTMP|VTE_PTY_NO_WTMP
	VtePtyFlags pf = (VtePtyFlags)(0);
	//0
	//G_SPAWN_CHILD_INHERITS_STDIN|G_SPAWN_SEARCH_PATH|G_SPAWN_FILE_AND_ARGV_ZERO
	//G_SPAWN_SEARCH_PATH
	GSpawnFlags sf = (GSpawnFlags)(0);
	GPid pid = 0;
#ifdef ver_2_91_
	//GCancellable ;
	vte_terminal_spawn_sync(handle__(),
			pf, wd, argv, envv,
			sf, NULL, NULL, &pid, NULL, &error);
#else
	vte_terminal_fork_command_full(handle__(),
			pf, wd, argv, envv,
			sf, NULL, NULL, &pid, &error);
#endif
	g_error_free (error);
	pid_ = pid;
	return pid;
}

vte_view___::vte_view___(GtkWidget* scrolled2, void* window):view___(scrolled2, window) {
	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_set_homogeneous(GTK_BOX(box), FALSE);
	container_add__(box, scrolled2);

	widget_ = vte_terminal_new();
	gtk_object_set_data(GTK_OBJECT(widget_), object_data_view_, (gpointer)this);
	gtk_object_set_data(GTK_OBJECT(widget_), object_data_scrolled_, (gpointer)scrolled2);

	signal_connect__(widget_);

	gtk_box_pack_start(GTK_BOX(box), widget_, TRUE, TRUE, 0);

	GtkWidget *scrollbar = gtk_scrollbar_new(GTK_ORIENTATION_VERTICAL,
#ifdef ver_2_91_
			gtk_scrollable_get_vadjustment(GTK_SCROLLABLE(handle__()))
#else
			vte_terminal_get_adjustment(handle__())
#endif
			);
	gtk_box_pack_end(GTK_BOX(box), scrollbar, FALSE, FALSE, 0);

	gtk_widget_show_all(box);

	pid_ = 0;
}
