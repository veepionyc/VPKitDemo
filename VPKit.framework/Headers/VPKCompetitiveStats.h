//
//  VPKCompetitiveStats.h
//  VPKit
//
//  Created by jonathan on 04/12/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKParseableObject.h"
#import "VPKCompetitiveStatsItem.h"
NS_ASSUME_NONNULL_BEGIN

/**
 Model object for sending competetive statistics.
 
 Each statistic is returned as a `VPKCompetitiveStatsItem`
 
 Stats returned:
 
 *  referrals
 *  veepscore
 *  views
 *  previewtouches
 *  expansions
 *  sales
 *  veepselects
 *  veeps
 *  impressions
 *  navigations
 
 @see VPKCompetitiveStatsItem
 */
@interface VPKCompetitiveStats: VPKParseableObject

@property (nonatomic, strong) VPKCompetitiveStatsItem* referrals;
@property (nonatomic, strong) VPKCompetitiveStatsItem* veepscore;
@property (nonatomic, strong) VPKCompetitiveStatsItem* views;
@property (nonatomic, strong) VPKCompetitiveStatsItem* previewtouches;
@property (nonatomic, strong) VPKCompetitiveStatsItem* expansions;
@property (nonatomic, strong) VPKCompetitiveStatsItem* sales;
@property (nonatomic, strong) VPKCompetitiveStatsItem* veepselects;
@property (nonatomic, strong) VPKCompetitiveStatsItem* veeps;
@property (nonatomic, strong) VPKCompetitiveStatsItem* impressions;
@property (nonatomic, strong) VPKCompetitiveStatsItem* navigations;

@end

NS_ASSUME_NONNULL_END
