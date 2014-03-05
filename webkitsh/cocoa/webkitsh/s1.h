#ifndef S1_H_
#define S1_H_
#import <Foundation/NSString.h>

enum{
	navigation_requested_,
	create_web_view_,
	title_changed_,
	hovering_over_link_,
	load_progress_changed_,
	load_committed_,
	load_finished_,
	resource_request_starting_,
	console_message_,
	script_alert_,
	script_confirm_,
	script_prompt_,
	switch_page_,
    
	zhscript_,
    
	new_window_,
	show_window_,
	window_destroy_,

    open_file_,
    system_terminate_,
    
	s1_length_
};
extern NSString* s1_[s1_length_][1];


#endif /* S1_H_ */