/*
 * main.c
 *
 *  Created on: 2012-10-26
 *      Author: zzzzzzzzzzz
 */
#include <gtk/gtk.h>
#define bool int
#include"../new_gg/for_arg_.h"

bool gtk_init_check__(int argc,...){
#define argc2 16
	char* argv2[argc2];
	if(argc>=argc2)
		argc=argc2;
	_for_args( argc )
	argv2[i]=s;
	_next_args
	return gtk_init_check(&argc,&argv2);
}

void gtk_main__(){gtk_main();}

void gtk_main_quit__(){gtk_main_quit();}
