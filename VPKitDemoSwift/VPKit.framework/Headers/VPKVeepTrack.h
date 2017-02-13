//
//  VPKVeepTrack.h
//  VPKit
//
//  Created by jonathan on 05/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPKParseableObject.h"
#import "VPKCoordinates.h"

@import CoreMedia;





@interface VPKVeepTrack : VPKParseableObject
@property (nonnull, nonatomic, strong) NSString* trackID;
@property (nullable, nonatomic, strong) NSString* title;
@property (nullable, nonatomic, strong) NSString* descriptionString;
@property (nullable, nonatomic, strong) NSString* url;
@property (nullable, nonatomic, strong) NSString* mediaType;
@property (nonnull, nonatomic, strong) NSMutableArray<NSDictionary*>* coordinateDicts;
@property (nonnull, nonatomic, strong) NSMutableArray<VPKCoordinates*>* coordinatesObjs;
@property (nullable, nonatomic, strong) NSMutableArray<NSString*>* keyframes;
@property (nonnull, nonatomic, strong) NSNumber* monetised;
//@property (nonatomic, strong) NSDictionary* keyframesPoints;
//@property (nonatomic, strong) NSString* pointsChecker;
//@property (nonatomic, assign) CGSize size;


- (nonnull instancetype)initWithTempID:(nonnull NSString*)tempID;

- (nullable NSString*)nearestKeyFrameForFrame:(CMTimeValue)frame;

- (void)setCoordinatesWithFrame:(CGRect)frame center:(CGPoint)center;

@end
