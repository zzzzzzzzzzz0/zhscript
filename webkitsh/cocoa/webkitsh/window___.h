//
//  window___.h
//  webkitsh
//
//  Created by moyea soft on 12-11-10.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Webkit/WebKit.h>
#include"s1.h"

@interface window___ : NSObject {
    NSWindow* window_;
    WebView* webview_;
    NSString *name_;
    NSString* codes_[s1_length_];
}

-(void)window__:(NSWindow*)w;
-(NSWindow*)window__;
-(void)webview__:(WebView*)wv;
-(WebView*)webview__;
-(void)name__:(NSString*)n;
-(NSString*)name__;
-(void)codes__:(int)i:(NSString*)s;
-(NSString*)codes__:(int)i;

-(void)destroy__;

@end
