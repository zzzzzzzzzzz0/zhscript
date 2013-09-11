//
//  call4_data___.h
//  webkitsh
//
//  Created by moyea soft on 12-11-22.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "window___.h"
#define CALL4_ARGV_MAX_ 16

@interface call4_data___ : NSObject {
    @public
    window___* w_;
    int i1_;
    int argc_;
    const char* argv_[CALL4_ARGV_MAX_];
    NSString* argv2_[CALL4_ARGV_MAX_];
    NSString* code_;
}

-(id)init:(int)i1 :(window___*)w;
-(id)argv_add__:(NSString*)s;
-(id)argv_add2__:(const char*)s;

@end
