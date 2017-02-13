//
//  VPBlockTimer.h
//  VPKit
//
//  Created by jonathan on 09/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPKBlockTimer : NSObject
+ (NSTimer*) scheduleTimerWithInterval:(NSTimeInterval)interval
                                    block:(void(^)())block
                                  repeats:(BOOL)repeats;




//use this one to delay a timer on first firing

+ (NSTimer*) scheduleTimerWithFireDate:(NSDate*)date
                                 interval:(NSTimeInterval)interval
                                    block:(void (^)())block
                                  repeats:(BOOL)repeats;
@end
