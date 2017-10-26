/*
 * webkitsh_window___.cpp
 *
 *  Created on: 2013-2-8
 *      Author: zzzzzzzzzzz
 */

#include "webkit_view___.h"
#include "sh-base/s1___.h"
#include <iostream>
#include "sh-base/extern.h"

static string true_="true",false_="false";
string webkit_view___::user_agent_;

/*void webkit_view___::close__(int page_num){
	GtkWidget* v=GTK_WIDGET(webview__(page_num));
	if(v)
		gtk_widget_destroy(v);
	window___::close__(page_num);
}*/

webkit_view___::webkit_view___(GtkWidget* scrolled2, void* window, bool is_app_paintable)
:view___(scrolled2, window) {
	target_ = NULL;
	is_app_paintable_ = is_app_paintable;
	widget_ = webview_new__(scrolled2);
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
	/*bool b=*/JSObjectSetPrivate(func, (void*)webkit_view___::from__(wv));
}

static bool geolocation_policy_decision_requested__(WebKitWebView*, WebKitWebFrame*, WebKitGeolocationPolicyDecision* decision) {
	webkit_geolocation_policy_allow(decision);
	return true;
}

GtkWidget* webkit_view___::webview_new__(GtkWidget* scrolled) {
	GtkWidget* webview = webkit_web_view_new ();
	//g_object_ref_sink(webview);
	gtk_object_set_data(GTK_OBJECT(webview),object_data_view_,(gpointer)this);
	if(scrolled) {
		gtk_object_set_data(GTK_OBJECT(webview),object_data_scrolled_,(gpointer)scrolled);
		//gtk_container_add (GTK_CONTAINER (scrolled), webview);
		GtkWidget* scrolled2 = gtk_scrolled_window_new (NULL, NULL);
		gtk_container_add (GTK_CONTAINER (scrolled2), webview);
		gtk_container_add (GTK_CONTAINER (scrolled), scrolled2);
		outer_scrolled_ = scrolled2;

		if(is_app_paintable_) {
			webkit_web_view_set_transparent(WEBKIT_WEB_VIEW(webview), true);
		}

		g_signal_connect(webview,"window-object-cleared",G_CALLBACK(window_object_cleared__),NULL);
		g_object_connect(G_OBJECT(webview),
				"signal::geolocation-policy-decision-requested",
				geolocation_policy_decision_requested__, 0, NULL);
		signal_connect__(webview);
	}
	if(!user_agent_.empty()) {
		WebKitWebSettings* wws=webkit_web_view_get_settings(WEBKIT_WEB_VIEW(webview));
		WebKitWebSettings* wws2=webkit_web_settings_copy(wws);
		g_object_set((GObject*)wws2, "user-agent", user_agent_.c_str(), NULL);
		webkit_web_view_set_settings(WEBKIT_WEB_VIEW(webview), wws2);
	}

	return webview;
}
