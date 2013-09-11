/*
 * webkitsh_window___.cpp
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#include "webkit_window___.h"
#include "sh-base/s1___.h"
#include <iostream>
#include "sh-base/extern.h"

static string true_="true",false_="false";

webkit_window___* webkit_window___::from__(WebKitWebView* page){
	return (webkit_window___*)gtk_object_get_data(GTK_OBJECT(page),object_data_window_);
}
GtkWidget* webkit_window___::scrolled_from__(WebKitWebView* page){
	return (GtkWidget*)gtk_object_get_data(GTK_OBJECT(page),object_data_scrolled_);
}
WebKitWebView* webkit_window___::webview_from__(GtkNotebook *notebook, int page_num){
	return WEBKIT_WEB_VIEW(get_data__(notebook,page_num,object_data_view_));
}

WebKitWebView* webkit_window___::webview__(int page_num){
	if(!notebook_)
		return WEBKIT_WEB_VIEW(webview_);
	return webview_from__(notebook__(), page_num);
}

void webkit_window___::close__(int page_num){
	GtkWidget* v=GTK_WIDGET(webview__(page_num));
	if(v)
		gtk_widget_destroy(v);
	window___::close__(page_num);
}

GtkWidget* webkit_window___::new__(window_flag___* wf) {
	GtkWidget* scrolled = window___::new__(wf);
	if(wf->has_1page_)
		webview_=webview_new__(scrolled);
	return scrolled;
}

WebKitWebView* webkit_window___::tabpg_new__(const char* name, bool is_hide) {
	GtkWidget* webview;
	if(is_hide) {
		webview = webview_new__(NULL);
	} else {
		if(notebook_) {
			GtkWidget* scrolled2 = window___::tabpg_new__(name);
			webview=webview_new__(scrolled2);
			gtk_widget_show_all (scrolled2);
			gtk_widget_grab_focus(webview);
		} else
			webview = webview_;
	}
	return WEBKIT_WEB_VIEW(webview);
}

webkit_window___::webkit_window___(const char* name, bool is_main):window___(name, is_main) {
	webview_ = NULL;
	target_ = NULL;
}

static JSValueRef
zs__                (JSContextRef     js_context,
                     JSObjectRef      js_function,
                     JSObjectRef      js_this,
                     size_t           argument_count,
                     const JSValueRef js_arguments[],
                     JSValueRef*      js_exception)
{
	if(argument_count<=0){
		return JSValueMakeNull (js_context);
	}
	const char*ret;
	{
		window___* w=reinterpret_cast<window___*>(JSObjectGetPrivate(js_function));
		if(!w){
			return JSValueMakeNull (js_context);
		}
		char** argv=new char*[argument_count+1];
		JSStringRef* jsr=new JSStringRef[argument_count];
		for(size_t i=0;i<argument_count;i++){
			jsr[i]=JSValueToStringCopy(js_context, js_arguments[i], js_exception);
			size_t jsSize = JSStringGetMaximumUTF8CStringSize(jsr[i]);
			argv[i]=new char[jsSize];
			JSStringGetUTF8CString(jsr[i], argv[i], jsSize);
		}
		if(!argv[0][0]){
			ret=NULL;
			for(size_t i=1;i<argument_count;i++)
				cout<<argv[i];
			cout<<endl;
		}else
			ret=call4__(argv[0],NULL,argument_count,(const char**)argv,1);
		for(size_t i=0;i<argument_count;i++){
			delete argv[i];
			JSStringRelease(jsr[i]);
		}
		delete jsr;
		delete argv;
	}

	if(!ret)
		return JSValueMakeNull (js_context);
	JSValueRef ret2;
	if(true_==ret||false_==ret){
		ret2=JSValueMakeBoolean(js_context,true_==ret);
	}else{
		JSStringRef ret1=JSStringCreateWithUTF8CString(ret);
		ret2=JSValueMakeString(js_context,ret1);
		JSStringRelease (ret1);
	}
	return ret2;
}

static void window_object_cleared__(
	WebKitWebView  *wv,
	WebKitWebFrame *wf,
	JSGlobalContextRef ctx,
	gpointer        window_object,
	gpointer        user_data)
{
	const char* name0 = "z$";
    JSStringRef name = JSStringCreateWithUTF8CString(name0);

    JSObjectRef func;
    //func = JSObjectMakeFunctionWithCallback(ctx, name, zs__);
    {
    	JSClassDefinition cd = kJSClassDefinitionEmpty;
		cd.className = name0;
		cd.callAsFunction = zs__;
		JSClassRef cr = JSClassCreate (&cd);
		func = JSObjectMake (ctx, cr, NULL);
    }

    JSObjectRef o = JSContextGetGlobalObject(ctx);
    JSObjectSetProperty(ctx, o, name, func, kJSPropertyAttributeNone, NULL);
    JSStringRelease(name);
    /*bool b=*/JSObjectSetPrivate(func, (void*)webkit_window___::from__(wv));
}

GtkWidget* webkit_window___::webview_new__(GtkWidget* scrolled) {
	GtkWidget* webview = webkit_web_view_new ();
	//g_object_ref_sink(webview);
	gtk_object_set_data(GTK_OBJECT(webview),object_data_window_,(gpointer)this);
	if(scrolled) {
		gtk_object_set_data(GTK_OBJECT(webview),object_data_scrolled_,(gpointer)scrolled);
		gtk_container_add (GTK_CONTAINER (scrolled), webview);
		gtk_object_set_data(GTK_OBJECT(scrolled),object_data_view_,(gpointer)webview);

		if(flag_.is_app_paintable_) {
			webkit_web_view_set_transparent(WEBKIT_WEB_VIEW(webview), true);
		}

		g_signal_connect(webview,"window-object-cleared",G_CALLBACK(window_object_cleared__),NULL);
		for(size_t i = 0; i < s1s_length__(); i++) {
			s1___* s1 = s1s__(i);
			if(s1->type__() == 'w' && s1->cb_) {
				g_signal_connect(webview, s1->signal__(), s1->cb_, NULL);
			}
		}
	}

	return webview;
}
