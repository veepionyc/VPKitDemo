//
//  VPKVeepFetcher.h
//  VPKit
//
//  Created by jonathan on 30/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKConstants.h"

@class VPKVeep;
@class VPKUserStats;

typedef void (^VPKitUserStatsErrorCompletionBlock)(   VPKUserStats* _Nullable   userStats
                                                   ,  NSError* _Nullable   error);
NS_ASSUME_NONNULL_BEGIN
@interface VPKVeepFetcher : NSObject

- (instancetype)initWithEmail:(NSString*)email appID:(NSString*)appID;

- (void)teardown;
+  (void) fetchVeep:(NSString*)veepID completion:(VPK_VeepErrorBlock)completion;
+  (void) publishVeep:(VPKVeep*)veep mediaID:(NSString*)mediaID completion:(VPK_MediaIDVeepIDErrorBlock)completion;

+  (void) fetchCurrentUserStats:(VPKitUserStatsErrorCompletionBlock)completion;

@end
NS_ASSUME_NONNULL_END
