//
//  call4_data___.m
//  webkitsh
//
//  Created by moyea soft on 12-11-22.
//  Copyright (c) 2012年 zhscript. All rights reserved.
//

#import "call4_data___.h"

@implementation call4_data___

-(id)init:(int)i1 :(window___*)w {
	self = [super init];
	if (!self) {
		return nil;
	}
    w_=w;
    i1_=i1;
    argc_=0;
    return self;
}

-(id)argv_add__:(NSString*)s{
    argv2_[argc_]=s;
    argv_[argc_]=[argv2_[argc_] UTF8String];
    argc_++;
    
    return self;
}

-(id)argv_add2__:(const char*)s {
    if(!s)
        return self;
    return [self argv_add__:[NSString stringWithUTF8String:s]];
}

@end
