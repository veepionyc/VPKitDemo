//
//  VPKit.h
//  VPKit
//
//  Created by jonathan on 31/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPKVeepViewer.h"
#import "VPKVeepEditor.h"
#import "VPKPreview.h"
#import "VPKImage.h"
#import "VPKStyles.h"
#import "VPKEnvironment.h"
#import "VPKEndpoints.h"
#import "VPKPublicVeep.h"
#import "VPKVeepFetcher.h"
#import "VPKUserStats.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, VPKServerEnvironment) {
    VPKServerDev,
    VPKServerProduction
};

typedef void (^VPKitConsumerIdCompletionBlock)(NSString* consumerID);
typedef void (^VPKitPublicVeepErrorCompletionBlock)(  VPKPublicVeep* _Nullable veep
                                                    , NSError* _Nullable error);
typedef void (^VPKUserStatsErrorBlock)(  VPKUserStats* _Nullable userStats
                                                    , NSError* _Nullable error);

@interface VPKit : NSObject

+ (void)setApplicationIdentifier:(nonnull NSString*)appID;
//+ (void)setConsumerIdentifier:(nullable NSString*)consumerID;
//+ (void)setProduction:(BOOL)production;
//+ (void)setConsumerId:(nullable NSString*)consumerID;
//+ (nonnull NSString*)requestConsumerId;
//+ (void)requestConsumerId:(VPKitConsumerIdCompletionBlock)completionBlock;
+ (void)requestUserStats:(VPKUserStatsErrorBlock)completionBlock;

+ (nullable VPKVeepViewer*)viewerWithImage:(VPKImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view;


+ (nonnull VPKStyles*)styles;

+ (nonnull VPKEnvironment*) environment;

+ (void) requestVeep:(NSString*)veepID completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (nonnull VPKVeepFetcher*)fetcher;

+ (BOOL)loggedIn;

NS_ASSUME_NONNULL_END
@end
