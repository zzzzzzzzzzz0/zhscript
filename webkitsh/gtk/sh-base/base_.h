/*
 * base_.h
 *
 *  Created on: 2013-4-6
 *      Author: zzzzzzzzzzz
 */

#ifndef BASE__H_
#define BASE__H_

#include <gtk/gtk.h>
#include <string>
using namespace std;

//GTK_CHECK_VERSION(3,0,0)
#ifndef GTK_OBJECT
#define GTK_OBJECT G_OBJECT
#define gtk_object_set_data g_object_set_data
#define gtk_object_get_data g_object_get_data
#define gtk_object_remove_data(o,k) g_object_set_data(o,k,NULL)
#define gtk_notebook_set_page gtk_notebook_set_current_page
#define gtk_hseparator_new() gtk_separator_new(GTK_ORIENTATION_HORIZONTAL)
#define gtk_vseparator_new() gtk_separator_new(GTK_ORIENTATION_VERTICAL)
#define gtk_hbox_new(b,i) gtk_box_new(GTK_ORIENTATION_HORIZONTAL,i)
#define gtk_vbox_new(b,i) gtk_box_new(GTK_ORIENTATION_VERTICAL,i)
#define no_gtk_2_
#endif

#endif /* BASE__H_ */
