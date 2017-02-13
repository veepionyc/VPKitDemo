//
//  VPKVeep.h
//  VPKit
//
//  Created by jonathan on 05/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VPKVeepTrack.h"
#import "VPKParseableObject.h"
#import "VPKPublicVeep.h"

@interface VPKVeep : VPKParseableObject
//@property (nonatomic, strong) NSURL* mediaURL;
//@property (nonatomic, strong) UIImage* thumbNailImage;
//@property (nonatomic, strong) NSString* createdDateString;
//@property (nonatomic, strong) NSString* videoName;
//@property (nonatomic, assign) NSInteger voteCount;
//@property (nonatomic, assign) NSInteger viewCount;

@property (nullable, nonatomic, strong) NSString* veepID;
@property (nullable, nonatomic, strong) NSString* creatorEmail;
@property (nullable, nonatomic, strong) NSString* title;
@property (nullable, nonatomic, strong) NSString* descriptionString;

@property (nullable, nonatomic, strong) NSNumber* veepScore;
@property (nullable, nonatomic, strong) NSString* heroImageURL;
@property (nullable, nonatomic, strong) NSString* contentURL;

@property (nullable, nonatomic, assign) NSNumber* privatised;
@property (nullable, nonatomic, assign) NSNumber* hidden;

@property (nullable, nonatomic, strong) NSString* veepType;
@property (nullable, nonatomic, strong) NSString*  geoTag;
@property (nonnull, nonatomic, strong) NSNumber* owner;

@property (nullable, nonatomic, strong) NSMutableArray<VPKVeepTrack*>* tracks;


- (nonnull VPKPublicVeep*)publicVeep;

- (nullable VPKVeepTrack*)trackWithID:(nonnull NSString*)trackID;

@end
