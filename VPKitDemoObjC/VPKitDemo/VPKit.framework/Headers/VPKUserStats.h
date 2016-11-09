//
//  VPKUserStats.h
//  VPKit
//
//  Created by jonathan on 28/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "VPKParseableObject.h"

@interface VPKUserStats : VPKParseableObject

@property (nonatomic, strong) NSNumber* impressions NS_SWIFT_UNAVAILABLE("");
@property (nonatomic, strong) NSNumber* views NS_SWIFT_UNAVAILABLE("");
@property (nonatomic, strong) NSNumber* referrals NS_SWIFT_UNAVAILABLE("");


@property (nonatomic, assign, readonly) NSUInteger __impressions NS_SWIFT_NAME(impressions);
@property (nonatomic, assign, readonly) NSUInteger __views NS_SWIFT_NAME(views);
@property (nonatomic, assign, readonly) NSUInteger __referrals NS_SWIFT_NAME(referrals);

@end
