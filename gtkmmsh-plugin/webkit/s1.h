/*
 * s1.h
 *
 *  Created on: 2011-2-18
 *      Author: zzzzzzzzzzz
 */

#ifndef S1_H_
#define S1_H_
#include <gtkmm.h>

enum{
	create_web_view_,
	title_changed_,
	hovering_over_link_,
	load_progress_changed_,
	load_committed_,
	load_finished_,
	zhscript_,
	console_message_,
	resource_request_starting_,
	switch_page_,
	script_alert_,
	script_confirm_,
	script_prompt_,
	zs_,
	s1_length_
};
extern Glib::ustring s1_[s1_length_];

extern Glib::ustring true_,false_;

#endif /* S1_H_ */
