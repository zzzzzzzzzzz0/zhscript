//
//  AppDelegate.m
//  webkitsh
//
//  Created by moyea soft on 12-8-28.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import "AppDelegate.h"
//../../../../trunk/new_gg/
//User Header Search Paths
//$HOME/Documents/src/zhscript/trunk/new_gg
#include "l4/l4___.cc"
#include "l4/keyword.h"
#include "for_arg_.h"
#include "def1.h"
#include "call_util.cpp"
#include <deque>
#import <crt_externs.h>
#import "call4_data___.h"

static bool file__(const char* path,const char* ext,const char* sp,string& cmdline){
	string file;
	file=path;
	file+=ext;
	struct stat info;
	if(lstat(file.c_str(), &info) == 0){
		cmdline+=sp;
		cmdline+=file;
		return true;
	}
	return false;
}
static bool file__(const char* path,string& cmdline){
	int i=0;
	if(file__(path,".ini"," -I ",cmdline))
		i++;
	if(file__(path,".zs"," ",cmdline))
		i++;
	return i>0;
}

static l4___ l4_;
static void* l4_main_qu_;
static string null_;
static NSString *true_=@"true",*false_=@"false";
static string code_;
static window___* main_window_;

static void err__(int err, const char* ret){
	if(err)
		cerr<<endl<<ret<<l4_.err_<<l4_.err__()<<l4_.errinfo__(err)<<endl;
}

static void err__(const char* s,const char* s2=NULL,const char* s3=NULL){
	cerr<<endl;
	if(s)
		cerr<<s;
	if(s2)
		cerr<<s2;
	if(s3)
		cerr<<s3;
	cerr<<endl;
}
static void err_buzu__(const char* s=NULL){
	err__(s,"参数不足");
}
static void err_wufa__(const char* s3,const char* s=NULL){
	err__(s,"无法",s3);
}
static void err_buzhichi__(const char* s3,const char* s=NULL){
	err__(s,"不支持",s3);
}

static void main_window_destroy__(){
    [main_window_ destroy__];
}

static const char* call4__(const char* code,const char* src2,int argc,const char**argv2,int from){
	int err;
	const char* ret=l4_.l4_callback3_2__(l4_.l4__(),&err,NULL,code,false,src2,l4_main_qu_,
                                         argc,argv2,from);
	switch(err){
        case 0:
        case jieshiqi_go_+keyword_exit_:
            break;
        case jieshiqi_go_+keyword_end_:
            main_window_destroy__();
            break;
        default:
            err__(err,ret);
            break;
	}
	return ret;
}
static const char* call4a__(window___* w,int i1,int argc,const char**argv2){
	const char* code="";
    if (w) {
        code=[[w codes__:i1] UTF8String];
    }
	if(!code[0]){
		code=code_.c_str();
	}
    if (w) {
        argv2[argc++]=[[w name__] UTF8String];
    }
	return call4__(code,[s1_[i1][0] UTF8String],argc,argv2,0);
}
const char* call4__(window___* w,int i1,int argc,...){
	const char*argv2[CALL4_ARGV_MAX_];
	_for_args( argc )
    argv2[i]=s;
	_next_args
	return call4a__(w,i1,argc,argv2);
}

static void suidao__(char**addr_ret,char*buf,long siz,AppDelegate* sh,void*ce,void* shangji,int argc,...) {
	NSMutableArray* p=[NSMutableArray new];
	_for_args( argc )
    if (s) {
        [p addObject:[NSString stringWithUTF8String:s]];
    } else {
        [p addObject:[NSString stringWithUTF8String:null_.c_str()]];
    }
	_next_args
	[sh api__:shangji :ce :p :buf :siz :addr_ret];
}

@implementation AppDelegate

-(void)call4__:(call4_data___*)data{
    if (data->i1_ >= 0) {
        call4a__(data->w_, data->i1_, data->argc_, data->argv_);
    } else {
        call4__([data->code_ UTF8String], NULL, data->argc_, data->argv_, 0);
    }
}
-(void)io_call4__:(call4_data___*)data :(BOOL)io{
    if (io) {
        NSInvocationOperation* io=[[NSInvocationOperation alloc] initWithTarget:self selector:@selector(call4__:) object:data];
        //[[AppDelegate sharedOperationQueue] addOperation:io];
        [oq_ addOperation:io];
        //[self performSelectorOnMainThread:@selector(call4__:) withObject:data waitUntilDone:NO];
    }else{
        [self call4__:data];
    }
}

//(WebFrame *)wf
//WebView* wv=[wf webView];
-(window___*) get_window__:(WebView*)wv{
    for (int i=0; i<[windows_ count]; i++) {
        window___* w=[windows_ objectAtIndex:i];
        if(wv==[w webview__]){
            return w;
        }
    }
    return nil;
}
-(window___*) get_window2__:(NSString *)name{
    for (int i=0; i<[windows_ count]; i++) {
        window___* w=[windows_ objectAtIndex:i];
        if([name isEqualToString:[w name__]]){
            return w;
        }
    }
    return nil;
}
-(window___*) get_window3__:(NSWindow*)w1{
    for (int i=0; i<[windows_ count]; i++) {
        window___* w=[windows_ objectAtIndex:i];
        if(w1==[w window__]){
            return w;
        }
    }
    return nil;
}

-(window___*) get_window__:(NSString*)name :(int)page_num :(NSString *) help{
	window___* w;
    w=[self get_window2__:name];
	if(!w){
		err_wufa__([help UTF8String],[name UTF8String]);
	}
	return w;
}
-(void) new_window__:(window___*) w{
    [self io_call4__:[[call4_data___ alloc]init:new_window_ :w ] :NO];
}
-(window___*) new_window2__:(NSString*)name{
	window___* w=[self get_window2__:name];
	if(!w){
		w=[window___ new];
        [w name__:name];
		[windows_ addObject:w];
        [self new_window__:w];
	}
	return w;
}

-(void) show_window__:(window___*) w{
    [self io_call4__:[[call4_data___ alloc]init:show_window_ :w ] :NO];
}

-(void) api__:(void*)shangji :(void*)ce :(NSMutableArray*)p :(char*)buf :(long)siz :(char**)addr_ret {
	if([p count]<1){
		err_buzu__();
		return;
	}
    //for(id s in p) {NSLog(@"%@",s);}
    
    NSString* p0=[p objectAtIndex:0];
	if([p count]<2){
		err_buzu__();
		return;
	}
    //[_webView windowScriptObject];
    NSString* p1=[p objectAtIndex:1];
    window___* w;
	int page_num = 0;
    if ([p1 isEqualToString:@"插脚"]) {
        if ([p count]<3) {
            err_buzu__();
            return;
        }
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        [[w webview__] stringByEvaluatingJavaScriptFromString:[p objectAtIndex:2]];
        return;
    }
    if ([p1 isEqualToString:@"内容"]) {
        if ([p count]<3) {
            err_buzu__();
            return;
        }
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        //nil
        //[NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]]
        NSURL* baseurl=[NSURL fileURLWithPath:app_path_ isDirectory:YES];
		for(size_t i=3; i<[p count]; i++) {
			NSString* p3=[p objectAtIndex:i];
			if(++i >= [p count]) {
                err_buzu__();
				return;
            }
            NSString* p4=[p objectAtIndex:i];
            if ([p3 isEqualToString:@"基址"]) {
                //URLWithString:
                baseurl = [NSURL fileURLWithPath:p4 isDirectory:YES];
                continue;
            }
            err_buzhichi__([p3 UTF8String],[p4 UTF8String]);
            return;
		}
        //NSLog(@"%@",baseurl);
        //fileURLWithPath:
        //[[_webView mainFrame]loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://baidu.com"]]];
        [[[w webview__] mainFrame] loadHTMLString:[p objectAtIndex:2] baseURL:baseurl];
        return;
    }
    //标签号
    //标签
    if ([p1 isEqualToString:@"标题"]) {
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        if ([p count]<3) {
        }else{
            [[w window__] setTitle:[p objectAtIndex:2]];
        }
        return;
    }
    if ([p1 isEqualToString:@"移动"]) {
        if ([p count]<4) {
            err_buzu__();
            return;
        }
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        NSWindow* w2=[w window__];
        NSRect r=[[NSScreen mainScreen] visibleFrame],r2=[w2 frame];
        float x=[[p objectAtIndex:2]floatValue],y=[[p objectAtIndex:3]floatValue];
        y=r.size.height-r2.size.height-y;
        [w2 setFrameOrigin:NSMakePoint(x,y)];
        return;
    }
    //||p1==s1_[create_web_view_][0]
    if ([p1 isEqualToString:@"访问"]) {
        if ([p count]<3) {
            err_buzu__();
            return;
        }
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        [[w webview__] setMainFrameURL:[p objectAtIndex:2]];
        return;
    }
    //活动
    //激活
    //隐藏
    if([p1 isEqualToString:s1_[window_destroy_][0]]){
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        [w destroy__];
        return;
    }
    if ([p1 isEqualToString:@"大小"]) {
        if ([p count]<4) {
            err_buzu__();
            return;
        }
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        NSWindow* w2=[w window__];
        NSRect r2=[w2 frame];
        r2.size.width=[[p objectAtIndex:2]floatValue];
        r2.size.height=[[p objectAtIndex:3]floatValue];
        NSRect r3=NSMakeRect(0,0,100,100);
        NSRect r4=[NSWindow contentRectForFrameRect:r3 styleMask:NSTitledWindowMask];
        r2.size.height+=r3.size.height-r4.size.height;
        [w2 setFrame:r2 display:true];
        return;
    }
    //刷新
    //前进
    //后退
    //最大化
    //加钮
    //不可关闭
    //目标
    if ([p1 isEqualToString:@"居中"]) {
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        [[w window__] center];
        return;
    }
    //显现
    //侦听
    //创建
    if ([p1 isEqualToString:@"侦听"]) {
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
		for(size_t i2=2;i2<[p count];i2++){
			NSString* p2=[p objectAtIndex:i2];
			int i1=-1;
			for(int i=0;i<s1_length_;i++){
				if([p2 isEqualToString:s1_[i][0]]){
					i1=i;
					break;
				}
			}
			if(i1>=0){
				/*const char* s1=s1_[i1][1];
				if(s1){
					w->cb_[i1]=cb_[i1];
				}*/
			}else{
				err_buzhichi__([p2 UTF8String],[p1 UTF8String]);
				return;
			}
			if(++i2>=[p count])
				break;
			[w codes__:i1 :[p objectAtIndex:i2]];
		}
		return;
	}
    if ([p1 isEqualToString:@"文件选择"]) {
        NSOpenPanel* op = NULL;
        NSSavePanel* sp = NULL;
        NSString* type=[p objectAtIndex:2];
        if ([type isEqualToString:@"打开"]) {
            op = [NSOpenPanel openPanel];
            //[op setCanChooseFiles:YES];
            //[op setCanChooseDirectories:NO];
        }
        else if ([type isEqualToString:@"保存"]) {
            sp = [NSSavePanel savePanel];
            op = (NSOpenPanel*)sp;
        }
        else if ([type isEqualToString:@"文件夹"]) {
            op = [NSOpenPanel openPanel];
            [op setCanChooseFiles:NO];
            [op setCanChooseDirectories:YES];
        }
        else {
            err_buzhichi__([type UTF8String],[p1 UTF8String]);
            return;
        }
        if ([ p count] > 3) {
            [op setTitle:[p objectAtIndex:3]];
        }
        for (NSUInteger i = 4; i < [p count]; i++) {
            NSString* pi = [p objectAtIndex:i];
            if ([pi isEqualToString:@"预选"]) {
                if (++i >= [p count]) {
                    err_buzu__([p1 UTF8String]);
                    return;
                }
                [op setDirectoryURL:[NSURL URLWithString:[p objectAtIndex:i]]];
                continue;
            }
            if ([pi isEqualToString:@"允许多选"]) {
                [op setAllowsMultipleSelection:YES];
                continue;
            }
        }
        if ( [op runModal] == NSOKButton )
        {
            NSArray* URLs = [op URLs];
            NSMutableString* s = [NSMutableString new];
            for (int i = 0; i <[URLs count]; i++) {
                NSString *filename = [[URLs objectAtIndex:i]relativePath];
                if (i>0) {
                    [s appendString:@"\n"];
                }
                [s appendString:filename];
            }
            *addr_ret = dup__([s UTF8String]);
        }
        return;
    }
    //图标
    if ([p1 isEqualToString:@"不透明度"]) {
        if ([p count]<3) {
            err_buzu__();
            return;
        }
        w = [self get_window__:p0 :page_num :p1]; if(!w) return;
        [[w window__] setAlphaValue:[[p objectAtIndex:2] floatValue]];
        return;
    }
    if ([p1 isEqualToString:@"透明"]) {
        w = [self get_window__:p0 :page_num :p1]; if(!w) return;
        //[[w webview__] setOpaque:NO];
        [[w webview__] setDrawsBackground:NO];
        //[[w webview__] setBackgroundColor:[NSColor clearColor]];
        return;
    }
    if ([p1 isEqualToString:@"无修饰"]) {
        w=[self get_window__:p0 :page_num :p1];if(!w)return;
        [[w window__] setStyleMask:NSBorderlessWindowMask];
        [[w window__] setAcceptsMouseMovedEvents:YES];
        [[w window__] setMovableByWindowBackground:YES];
        [[w window__] setLevel:NSNormalWindowLevel];
        return;
    }
    //xid
    if([p0 isEqualToString:@"代码"]){
		code_=[p1 UTF8String];
		return;
	}
	err_buzhichi__([p1 UTF8String]);
}

-(int) with__ {
    int err;
    {
        int argc=*_NSGetArgc();
        char** argv=*_NSGetArgv();
        const char* path=argv[0];
        
		string buf;
		if(which__(path,buf))
			path=buf.c_str();
        
        string cmdline=(const char*)"-S syn-zh -E err-zh";
		if(!file__(path,cmdline)&&get_lnk__(path,buf,true)){
			path=buf.c_str();
			file__(path,cmdline);
		}
        err=l4_.init__(path,cmdline.c_str(),argc,argv,1);
    }
    if(!err){
		//l4_.env__(*_NSGetEnviron());
		l4_main_qu_=l4_.new_main_qu__();
		null_=l4_.keyword__(keyword_null_);
		const char
        *dy=l4_.keyword__(keyword_call_)
        ,*ky=l4_.keyword__(keyword_kaiyinhao_)
        ,*by=l4_.keyword__(keyword_biyinhao_)
        ,*d=l4_.keyword__(keyword_dunhao_)
        ,*bs=l4_.keyword__(keyword_bianliangshi_)
        ,*bz=l4_.keyword__(keyword_bianliangzhong_)
        ,*c=l4_.keyword__(keyword_params_)
        ,*j=l4_.keyword__(keyword_juhao_)
        ,*cb=l4_.keyword__(keyword_callback_)
        ,*zs=l4_.keyword__(keyword_zhujieshi_)
        ,*zz=l4_.keyword__(keyword_zhujiezhong_)
        ,*sj=l4_.keyword__(keyword_shangji_)
        ;
        NSString* buf;
		string s;
		s+=dy;
        buf=[NSString stringWithFormat:@"%lx",(long)suidao__];
		s+=ky;s+="ASZ/";s+=[buf UTF8String];s+="/&-$11-&";s+=by;s+=d;
        buf=[NSString stringWithFormat:@"%lx",(long)self];
		s+=ky;s+=[buf UTF8String];s+=by;s+=d;
		s+=bs;s+=zs;s+=sj;s+=zz;s+=cb;s+='1';s+=bz;s+=d;
		s+=bs;s+=c;s+=bz;s+=j;
		err=l4_.def_new__("使",s.c_str(),true,false,l4_main_qu_);
    }
	if(!err){
        app_path_ = [[[NSBundle mainBundle] resourcePath] stringByAppendingString:@"/../MacOS"];
        
		err=l4_.jieshi__(l4_main_qu_);
		if(err==errinfo_src_file_){
			err=0;
		}
	}
	err__(err,"");
	if(err)
		return 255;
    
    [self new_window__:main_window_];
    [self show_window__:main_window_];
    
	return l4_.exit_code__();
}

-(NSString*)url2__:(WebFrame *)frame{
    return [[[[frame dataSource] request] URL] absoluteString];
}
-(const char*)url__:(WebFrame *)frame{
    return [[self url2__:frame] UTF8String];
}

//跳转到 WebFrameLoadDelegate.h 去看
- (void)webView:(WebView *)sender didClearWindowObject:(WebScriptObject *)windowObject forFrame:(WebFrame *)frame {
    //NSLog(@"didClearWindowObject");
    [windowObject setValue:self forKey:@"z$"];
}
-(const char*)cc__:(id)a1 {
    if ([a1 isKindOfClass:[NSString class]]) {
        return [a1 UTF8String];
    }
    else if ([a1 isKindOfClass:[NSNull class]] ||
             [[a1 className] isEqualToString:@"WebUndefined"] ||
             a1==nil) {
        return null_.c_str();
    }
    else if ([[a1 className] isEqualToString:@"__NSCFString"] ||
             [[a1 className] isEqualToString:@"__NSCFConstantString"]) {
        return 0;
    }
    else {
        return [[a1 stringValue] UTF8String];
    }
}
- (id)invokeDefaultMethodWithArguments:(NSArray *)args {
    int argc=(int)[args count];
    if(argc==0)
        return nil;
    
    const char*ret;
    const char **argv = (const char **) malloc(sizeof(char *) * (argc));
    for(int i=0;i<argc;i++){
        argv[i]=[self cc__:[args objectAtIndex:i]];
    }
    if (!**argv) {
        for(int i=1;i<argc;i++){
            cout<<argv[i];
        }
        cout<<endl;
        ret=0;
    } else {
        ret=call4__(argv[0],NULL,argc,argv,1);
    }
    free(argv);
    if (!ret) {
        return nil;
    }
    NSString* ret2=[NSString stringWithUTF8String:ret];
    /*if ([true_ isEqualToString:ret2]) {
     return true;
     }
     if ([false_ isEqualToString:ret2]) {
     return false;
     }*/
    return ret2;
}
- (void)zs_b__:(id)p0:(id)p1:(id)p2:(id)p3:(id)p4:(id)p5:(id)p6:(id)p7:(id)p8:(id)p9:(id)p10:(id)p11:(id)p12:(id)p13:(id)p14:(id)p15 {
    call4_data___* data = [call4_data___ new];
    data->i1_ = -1;
    data->code_ = [NSString stringWithUTF8String:[self cc__:p0]];
    [data argv_add2__:[self cc__:p1]];
    [data argv_add2__:[self cc__:p2]];
    [data argv_add2__:[self cc__:p3]];
    [data argv_add2__:[self cc__:p4]];
    [data argv_add2__:[self cc__:p5]];
    [data argv_add2__:[self cc__:p6]];
    [data argv_add2__:[self cc__:p7]];
    [data argv_add2__:[self cc__:p8]];
    [data argv_add2__:[self cc__:p9]];
    [data argv_add2__:[self cc__:p10]];
    [data argv_add2__:[self cc__:p11]];
    [data argv_add2__:[self cc__:p12]];
    [data argv_add2__:[self cc__:p13]];
    [data argv_add2__:[self cc__:p14]];
    [data argv_add2__:[self cc__:p15]];
    [self io_call4__:data :YES];
}
+ (NSString *)webScriptNameForSelector:(SEL)selector {
    if(selector == @selector(zs_b__::::::::::::::::)) {
        return @"b";
    }
    return nil;
}
+ (BOOL)isSelectorExcludedFromWebScript:(SEL)selector {
    return NO;
}
+ (NSString *)webScriptNameForKey:(const char *)key {
    return nil;
}
+ (BOOL)isKeyExcludedFromWebScript:(const char *)name {
    return YES;
}
- (id)invokeUndefinedMethodFromWebScript:(NSString *)name withArguments:(NSArray *)args {
    NSLog(@"undefined invoked: %@(%@)", name, args);
    return nil;
}
- (void)webView:(WebView *)sender didReceiveTitle:(NSString *)title forFrame:(WebFrame *)frame {
    [self io_call4__:[[[call4_data___ alloc]init:title_changed_ :[self get_window__:sender] ] argv_add__:title] :NO];
}
- (void)webView:(WebView *)sender didCommitLoadForFrame:(WebFrame *)frame {
    [self io_call4__:[[[call4_data___ alloc]init:load_committed_ :[self get_window__:sender] ] argv_add__:[self url2__:frame]] :NO];
}
- (void)webView:(WebView *)sender didFinishLoadForFrame:(WebFrame *)frame {
    [self io_call4__:[[[call4_data___ alloc]init:load_finished_ :[self get_window__:sender] ] argv_add__:[self url2__:frame]] :NO];
}
- (void)webView:(WebView *)sender runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WebFrame *)frame {
    //NSLog(@"%@ %@ %@", self, NSStringFromSelector(_cmd), message);
    NSAlert* alert = [NSAlert new];
    [alert setAlertStyle:NSInformationalAlertStyle];
    [alert setMessageText:message];
    [alert runModal];
    [self io_call4__:[[[call4_data___ alloc]init:script_alert_ :[self get_window__:sender] ] argv_add__:message] :NO];
}
- (BOOL)webView:(WebView *)sender runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WebFrame *)frame {
    NSAlert* alert = [NSAlert new];
    [alert setAlertStyle:NSInformationalAlertStyle];
    [alert setMessageText:message];
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
    BOOL b;
    NSInteger result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
        b=YES;
    else
        b=NO;
    [self io_call4__:[[[call4_data___ alloc]init:script_confirm_ :[self get_window__:sender] ] argv_add__:message] :NO];
    return b;
}
- (NSString *)webView:(WebView *)sender runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(NSString *)defaultText initiatedByFrame:(WebFrame *)frame{
    call4_data___* data=[[call4_data___ alloc]init:script_prompt_ :[self get_window__:sender] ];
    [data argv_add__:prompt];
    [data argv_add__:defaultText];
    [self io_call4__:data :NO];
    return nil;
}
- (WebView *)webView:(WebView *)sender createWebViewWithRequest:(NSURLRequest *)request{
    window___* w=[self get_window__:sender];
    [self io_call4__:[[call4_data___ alloc]init:create_web_view_ :w ] :NO];
    WebView *wv;
    wv=[w webview__];
    return wv;
}
-(void)webView:(WebView*)webView decidePolicyForNavigationAction:(NSDictionary*)actionInformation request:(NSURLRequest*)request frame:(WebFrame*)frame decisionListener:(id<WebPolicyDecisionListener>)listener{
    if ([request.URL.scheme isEqualToString:zhscript_2_]) {
        [self io_call4__:[[[call4_data___ alloc]init:zhscript_ :[self get_window__:webView] ] argv_add__:[[request.URL absoluteString]substringFromIndex:zhscript_len_]] :NO];
        
        [listener ignore];
        return;
    }
    [listener use];
}
- (BOOL)windowShouldClose:(id)window{
    [self io_call4__:[[call4_data___ alloc]init:window_destroy_ :[self get_window3__:window] ] :NO];
    return YES;
}
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;  //quit when main window is closed
}
- (void)webView:(WebView *)sender runOpenPanelForFileButtonWithResultListener:(id <WebOpenPanelResultListener>)resultListener
{
    NSOpenPanel* openDlg = [NSOpenPanel openPanel];
    [openDlg setCanChooseFiles:YES];
    [openDlg setCanChooseDirectories:NO];
    if ( [openDlg runModal] == NSOKButton )
    {
        NSArray* URLs = [openDlg URLs];
        /*NSMutableArray *files = [NSMutableArray new];
        for (int i = 0; i <[URLs count]; i++) {
            NSString *filename = [[URLs objectAtIndex:i]relativePath];
            [files addObject:filename];
        }
        for(int i = 0; i < [files count]; i++ )
        {
            NSString* fileName = [files objectAtIndex:i];
            [resultListener chooseFilename:fileName];
        }*/
        for (int i = 0; i <[URLs count]; i++) {
            NSString *filename = [[URLs objectAtIndex:i]relativePath];
            //NSLog(@"%d--%@--", i, filename);
            [resultListener chooseFilename:filename];
        }
    }
}
- (void)webView:(WebView *)sender didStartProvisionalLoadForFrame:(WebFrame *)frame {
    //NSLog(@"didStartProvisionalLoadForFrame");
}
- (void)webView:(WebView *)sender didReceiveServerRedirectForProvisionalLoadForFrame:(WebFrame *)frame {
    //NSLog(@"didReceiveServerRedirectForProvisionalLoadForFrame");
}
- (void)webView:(WebView *)sender didFailProvisionalLoadWithError:(NSError *)error forFrame:(WebFrame *)frame {
    NSLog(@"didFailProvisionalLoadWithError %@",error);
}
- (void)webView:(WebView *)sender didReceiveIcon:(NSImage *)image forFrame:(WebFrame *)frame {
    //NSLog(@"didReceiveIcon");
}
- (void)webView:(WebView *)sender didFailLoadWithError:(NSError *)error forFrame:(WebFrame *)frame {
    NSLog(@"didFailLoadWithError %@",error);
}
- (void)webView:(WebView *)sender didChangeLocationWithinPageForFrame:(WebFrame *)frame {
    //NSLog(@"didChangeLocationWithinPageForFrame");
}
- (void)webView:(WebView *)sender willPerformClientRedirectToURL:(NSURL *)URL delay:(NSTimeInterval)seconds fireDate:(NSDate *)date forFrame:(WebFrame *)frame {
    //NSLog(@"willPerformClientRedirectToURL %@,%f,%@",URL,seconds,date);
}
- (void)webView:(WebView *)sender didCancelClientRedirectForFrame:(WebFrame *)frame {
    //NSLog(@"didCancelClientRedirectForFrame");
}
- (void)webView:(WebView *)sender willCloseFrame:(WebFrame *)frame {
    //NSLog(@"willCloseFrame");
}

- (void) awakeFromNib {
    [NSApp setDelegate: self];
    
    [_webview_ setUIDelegate:self];
    [_webview_ setFrameLoadDelegate:self];
    [_webview_ setResourceLoadDelegate:self];
    [_webview_ setPolicyDelegate:self];
    
    windows_=[NSMutableArray new];
    zhscript_2_ = [NSString stringWithString:s1_[zhscript_][0]];
    zhscript_len_ = [zhscript_2_ length];
    zhscript_2_ = [zhscript_2_ substringToIndex:zhscript_len_ - 1];
    oq_=[NSOperationQueue new];

    main_window_=[window___ new];
    [main_window_ name__:@"主窗"];
    [main_window_ window__:_window_];
    [main_window_ webview__:_webview_];
	[windows_ addObject:main_window_];

    [self with__];
}
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
}

@end

/*
 - (void) handleTimer: (NSTimer *) timer
 {
 NSLog(@"url %@", [_webView stringByEvaluatingJavaScriptFromString:@"location.href;"]);
 }

[NSTimer scheduledTimerWithTimeInterval: 2
 target: self
 selector: @selector(handleTimer:)
 userInfo: nil
 repeats: NO];
*/