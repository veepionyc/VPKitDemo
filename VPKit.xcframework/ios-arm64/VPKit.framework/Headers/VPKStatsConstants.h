//
//  VPKStatsConstants.h
//  VPKit
//
//  Created by jonathan on 04/12/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#ifndef VPKStatsConstants_h
#define VPKStatsConstants_h
@class VPKCompetitiveStats;
@class VPKDailyStats;

typedef void (^vpk_CompetitiveStatsBlock)(VPKCompetitiveStats* _Nullable stats,  NSError* _Nullable  error);
typedef void (^vpk_DailyStatsBlock)(VPKDailyStats* _Nullable stats, NSError* _Nullable error);


#endif /* VPKStatsConstants_h */
