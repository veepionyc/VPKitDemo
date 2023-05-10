//
//  VPKDailyStats.h
//  VPKit
//
//  Created by jonathan on 04/12/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <VPKit/VPKParseableObject.h>
NS_ASSUME_NONNULL_BEGIN



/**
 Model object for sending daily statistics.
 
 Use the respective methods to extract values for dates in the `dates` array :
 
 * referrals
 *  views
 *  previewtouches
 *  expansions
 *  sales
 *  veepselects
 *  impressions
 *  navigations
 */

@interface VPKDailyStats: VPKParseableObject

/**
 Formatter for transcribing to and from ISO8601
 */
@property (nonatomic, strong) NSDateFormatter* dateFormatter;

/**
 Array of series labels
 */
@property (nonatomic, strong) NSArray<NSString*>* series;

/**
 Array of dates as ISO8601 strings
 */
@property (nonatomic, strong) NSArray<NSString*>* dateStrings;

/**
 Array of dates as NSDate objects
 */
@property (nonatomic, strong) NSArray<NSDate*>* dates;

/**
 Array of values for all series and all dates. A one-dimensional array of values in series:date order.
 */
@property (nonatomic, strong) NSArray<NSNumber*>* values;

/**
 Array of referrals values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)referrals;

/**
 Array of views values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)views;

/**
 Array of previewtouches values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)previewtouches;

/**
 Array of expansions values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)expansions;

/**
 Array of sales values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)sales;

/**
 Array of veepselects values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)veepselects;

/**
 Array of impressions values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)impressions;


/**
 Array of navigations values for the dates contained in the dates array.
 Values are NSIntegers boxed as NSNumbers.
 */
- (NSArray<NSNumber*>*)navigations;


@end

NS_ASSUME_NONNULL_END
