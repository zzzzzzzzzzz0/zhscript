//
//  AppDelegate.h
//  webkitsh
//
//  Created by moyea soft on 12-8-28.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Webkit/WebKit.h>
#import "window___.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    NSMutableArray* windows_;
    NSString* zhscript_2_;
    unsigned long zhscript_len_;
    NSOperationQueue *oq_;
}

//以下的绑定需要：点 MainMenu.xib，点 App Delegate 工具栏按钮（左侧），在 Outlets 列表（右侧）里拖动 + 到指定
@property (assign) IBOutlet NSWindow *window_;
@property (assign) IBOutlet WebView *webview_;

-(int) with__;
-(void) api__:(void*)shangji :(void*)ce :(NSMutableArray*)p :(char*)buf :(long)siz :(char**)addr_ret;
-(const char*)url__:(WebFrame *)frame;

@end
