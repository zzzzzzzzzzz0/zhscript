/*
 * unique.cpp
 *
 *  Created on: 2011-11-19
 *      Author: zzzzzzzzzzz
 */


#include <stdio.h>
#include <string>
#include <unique/unique.h>
#include"../new_gg/def1.h"

static void* jsq_;
static callback2___ cb_;
static void* shangji_;

dlle___ void init__(callback2___ cb,void* jsq,void* shangji){
	jsq_=jsq;
	cb_=cb;
	shangji_=shangji;
}

dlle___ void unref__(UniqueApp *app){
	g_object_unref (app);
}

dlle___ void send_message__(const gchar*str,gint command_id,UniqueApp *app){
	UniqueMessageData *message = unique_message_data_new();
	unique_message_data_set_text (message, str, -1);
	unique_app_send_message (app, command_id, message);
	unique_message_data_free (message);
}

static std::string message_received_code_;
static UniqueResponse
message_received__ (UniqueApp *app,
                     UniqueCommand command,
                     UniqueMessageData *message,
                     guint time_,
                     gpointer user_data)
{
  UniqueResponse res;
  gchar *texto = unique_message_data_get_text (message);
  char s[32];
  sprintf(s,"%d",command);
  int err;
  cb_(jsq_,shangji_,&err,message_received_code_.c_str(),false,2,texto,s);
  res = UNIQUE_RESPONSE_OK;
  return res;
}

dlle___ void add_message_received__(const char*code,UniqueApp *app){
	message_received_code_=code;
	g_signal_connect (G_OBJECT (app), "message-received",
	                      G_CALLBACK (message_received__), NULL);
}
