/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) zzzzzzzzzzz 2010 <zzzzzzzzzzzgg@gmail.com>
 *
 * rptestj is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rptestj is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "shell.h"

int
main (int argc, char *argv[], char** env)
{
#ifdef ver_thread_
	Glib::thread_init();
	gdk_threads_init();
#endif
	shell___ sh;
	return sh.with__(argc, argv, env);
}
