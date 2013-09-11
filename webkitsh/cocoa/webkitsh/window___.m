//
//  window___.m
//  webkitsh
//
//  Created by moyea soft on 12-11-10.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import "window___.h"

@implementation window___

-(void)window__:(NSWindow*)w{window_=w;}
-(NSWindow*)window__{return window_;}
-(void)webview__:(WebView*)wv{webview_=wv;}
-(WebView*)webview__{return webview_;}
-(void)name__:(NSString*)n{name_=n;}
-(NSString*)name__{return name_;}
-(void)codes__:(int)i :(NSString*)s {codes_[i] = s;}
-(NSString*)codes__:(int)i{return codes_[i];}

-(void)destroy__{
    [window_ orderOut:nil];
}

-(id)init{
	self = [super init];
	if (!self) {
		return nil;
	}
    for (int i=0; i<s1_length_; i++) {
        codes_[i]=@"";
    }
    return self;
}

@end
