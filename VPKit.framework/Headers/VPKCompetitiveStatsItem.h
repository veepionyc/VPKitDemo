//
//  VPKCompetitiveStatsItem.h
//  VPKit
//
//  Created by jonathan on 04/12/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKParseableObject.h"
NS_ASSUME_NONNULL_BEGIN


/**
 Model object for competitive stats data represented as float `percentile` and int `value`
 */

@interface VPKCompetitiveStatsItem : VPKParseableObject

@property (nonatomic, strong) NSNumber* percentile NS_SWIFT_UNAVAILABLE("");
@property (nonatomic, strong) NSNumber* value NS_SWIFT_UNAVAILABLE("");
@property (nonatomic, assign) float __percentile NS_SWIFT_NAME(percentile);
@property (nonatomic, assign) NSInteger __value NS_SWIFT_NAME(value);
@end

NS_ASSUME_NONNULL_END
