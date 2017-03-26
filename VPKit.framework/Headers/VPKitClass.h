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

typedef void (^VPKitConsumerIdCompletionBlock)(NSString* consumerId);
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

+ (void)setApplicationId:(nonnull NSString*)appId
                clientId:(nullable NSString*)clientId
                  clientSecret:(nullable NSString*)secret;

+ (void)setProduction:(BOOL)production;

+ (void)sendIDFA:(BOOL)idfa;

#pragma mark - authentication

+ (void)authenticateWithEmail:(NSString*)email
                   completion:(VPKBOOLResponseCodeErrorBlock)completion;

+ (void)authenticateWithEmail:(NSString*)email
                     password:(nullable NSString*)password
                   completion:(VPKBOOLResponseCodeErrorBlock)completion;

+ (BOOL)authorized;


#pragma mark - analytics

+ (void)requestUserStats:(VPKUserStatsErrorBlock)completionBlock;

/**
   gets daily stats for the last seven days for this user
 */
+ (void)getDailyStats:(VPKDailyStatsBlock)completion;


/**
 gets competitive stats for this user
 */
+ (void)getCompetitiveStats:(VPKCompetitiveStatsBlock)completion;

#pragma mark - view controllers

+ (nullable VPKVeepViewer*)viewerWithImage:(VPKImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view error:( NSError* _Nullable *)error;


#pragma mark - environment

+ (nonnull VPKStyles*)styles;

+ (nonnull VPKEnvironment*) environment;

#pragma mark - getting veeps

+ (void) requestVeep:(NSString*)veepId completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (NSString*)version;
NS_ASSUME_NONNULL_END
@end
