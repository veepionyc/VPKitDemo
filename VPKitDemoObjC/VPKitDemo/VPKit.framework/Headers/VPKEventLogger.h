//
//  VPOEventLogger.h
//  VPKit
//
//  Created by jonathan on 16/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "VPKEvent.h"

@interface VPKEventLogger : NSObject





+ (nonnull instancetype) sharedLogger;



//touch
+ (void)logTouch:(CGPoint)touchPoint
         forSize:(CGSize)size;

//previewVeepView
+ (void)logPreview:(nonnull NSString*)veepID;

//previewVeepTouch
+ (void)logPreview:(nonnull NSString*)veepID
             touch:(CGPoint)point
           forSize:(CGSize)size;

//previewVeepClose
+ (void)logPreview:(nonnull NSString*)veepID
          duration:(nullable NSNumber*)duration;

//veepView
+ (void)logVeepView:(nonnull NSString*)veepID;

//veepClose
+ (void)logVeepClose:(nonnull NSString*)veepID;

//veepTouch
+ (void)logVeepTouch:(nonnull NSString*)veepID
             atPoint:(CGPoint)point
             forSize:(CGSize)size;

//veepSelect
+ (void)logVeepSelect:(nonnull NSString*)veepID
             trackIdx:(nonnull NSString*)trackIdx
              trackID:(nonnull NSString*)trackID;

//productView
+ (void)logProductView:(nonnull NSString*)veepID
              trackIdx:(nonnull NSString*)trackIdx
               trackID:(nonnull NSString*)trackID
                   url:(nonnull NSURL*)url;


//productViewExpanded
+ (void)logProductViewExpanded:(nonnull NSString*)veepID
                      trackIdx:(nonnull NSString*)trackIdx
                       trackID:(nonnull NSString*)trackID;

//productNavigation
+ (void)logProductNavigation:(nonnull NSString*)veepID
                    trackIdx:(nonnull NSString*)trackIdx
                     trackID:(nonnull NSString*)trackID
                         url:(nonnull NSURL*)url;

//productClose
+ (void)logProductClose:(nonnull NSString*)veepID
               trackIdx:(nonnull NSString*)trackIdx
                trackID:(nonnull NSString*)trackID;
@end
