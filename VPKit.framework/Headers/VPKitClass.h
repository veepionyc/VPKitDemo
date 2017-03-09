//
//  VPKit.h
//  VPKit
//
//  Created by jonathan on 31/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@class VPKUserStats;
@class VPKCompetitiveStats;
@class VPKDailyStats;
@class VPKVeepViewer;
@class VPKVeepEditor;
@class VPKImage;
@class VPKPublicVeep;
@class VPKEnvironment;
#import "VPKStyles.h"
#import "VPKPreview.h"
//#import "VPKModels.h"
//#import "VPKStatsConstants.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, VPKServerEnvironment) {
    VPKServerDev,
    VPKServerProduction
};

typedef void (^VPKBOOLResponseCodeErrorBlock)(BOOL success, NSInteger responseCode, NSError* error);

typedef void (^VPKitConsumerIdCompletionBlock)(NSString* consumerID);
typedef void (^VPKitPublicVeepErrorCompletionBlock)(  VPKPublicVeep* _Nullable veep
                                                    , NSError* _Nullable error);
typedef void (^VPKUserStatsErrorBlock)(  VPKUserStats* _Nullable userStats
                                                    , NSError* _Nullable error);

typedef void (^VPKCompetitiveStatsBlock)(VPKCompetitiveStats* _Nullable stats,  NSError* _Nullable  error);
typedef void (^VPKDailyStatsBlock)(VPKDailyStats* _Nullable stats, NSError* _Nullable error);


@interface VPKit : NSObject

/**
     sets the location for error dialogue handling - in the SDK or in the host app.
     
     @param forwardErrors
     YES - error alerts are supressed in the SDK and NSNotifications are forwarded for interception by the host app.
     NO - user-facing error alerts are presented by the SDK.
 
 
 */
+ (void)forwardErrorNotifications:(BOOL)forwardErrors;

+ (void)start;
+ (void)setApplicationID:(nonnull NSString*)appID;
+ (void)setApplicationID:(nonnull NSString*)appID
                clientID:(nullable NSString*)clientID
                  clientSecret:(nullable NSString*)secret;


+ (void)setEmail:(nullable NSString*)email;  //deprecated


+ (void)authenticateWithEmail:(NSString*)email completion:(VPKBOOLResponseCodeErrorBlock)completion;
+ (void)authenticateWithEmail:(NSString*)email password:(nullable NSString*)password completion:(VPKBOOLResponseCodeErrorBlock)completion;

+ (void)setProduction:(BOOL)production;
+ (void)sendIDFA:(BOOL)idfa;

//+ (nonnull NSString*)requestConsumerID;
//+ (void)requestConsumerID:(VPKitConsumerIdCompletionBlock)completionBlock;
+ (void)requestUserStats:(VPKUserStatsErrorBlock)completionBlock;

/**
   gets daily stats for the last seven days for this user
 */
+ (void)getDailyStats:(VPKDailyStatsBlock)completion;

+ (BOOL)authorized;

/**
 gets competitive stats for this user
 */
+ (void)getCompetitiveStats:(VPKCompetitiveStatsBlock)completion;

+ (nullable VPKVeepViewer*)viewerWithImage:(VPKImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view error:( NSError* _Nullable *)error;

+ (nonnull VPKStyles*)styles;

+ (nonnull VPKEnvironment*) environment;

+ (void) requestVeep:(NSString*)veepID completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (NSString*)version;
NS_ASSUME_NONNULL_END
@end
