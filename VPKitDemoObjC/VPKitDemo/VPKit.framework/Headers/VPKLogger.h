//
//  VPVLogger.h
//  VPKit
//
//  Created by jonathan on 09/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LOG_APP 1

#define VPLogMethod if(LOG_APP && LOG_ME) NSLog(@"%@ %@",self.class,NSStringFromSelector(_cmd));

#define VPLog if(LOG_APP && LOG_ME) NSLog

//#define NSLog(...) CLS_LOG(__VA_ARGS__)

#ifndef DEBUG
#define NSLog(...);

#endif


@interface VPKLogger : NSObject

@end

