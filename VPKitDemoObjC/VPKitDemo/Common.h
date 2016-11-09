//
//  Common.h
//  FNCamShift
//
//  Created by jonathan on 11/01/2016.
//  Copyright © 2016 foundry. All rights reserved.
//

#ifndef Common_h
#define Common_h

#import "Blocks.h"




/////////////
// LOGGING //
/////////////

#define LOG_APP 1
#define WNLog if(LOG_APP && LOG_ME) NSLog

#define WNLogMethod if(LOG_APP && LOG_ME) NSLog(@"%@ %@ %d",self.class,NSStringFromSelector(_cmd),[NSThread isMainThread]);
#define TNLog if(LOG_APP && TIME_ME) NSLog
#define CNLog if(LOG_APP && TIME_ME) NSLog

#define WNLog if(LOG_APP && LOG_ME) NSLog
#define WWLog if(LOG_APP) NSLog
#define NNLog NSLog   //marks deliberate NSLogs
#define NVLog(var) NSLog(@"%s = %@", #var, var)  //quick check for single object


//#define NSLog(...) CLS_LOG(__VA_ARGS__)

#ifndef DEBUG
#define NSLog(...);
#endif

////////////
// MACROS //
////////////

///BLOCKS//

@class CMDeviceMotion;
typedef void (^Block) ();
typedef void (^BOOLBlock) (BOOL success);
typedef void (^BOOLErrorBlock) (BOOL success, NSError* error);

typedef void (^CMDeviceMotionErroBlock) (CMDeviceMotion* deviceMotion, NSError* error);
typedef void (^NSArrayErrorBlock) (NSArray* array, NSError* error);
typedef void (^NSArrayBlock) (NSArray* array);
typedef void (^MetadataExtractionBlock) (NSArray* deviceMotionArray, NSArray* locationArray, NSArray* testArray);

#endif /* Common_h */
