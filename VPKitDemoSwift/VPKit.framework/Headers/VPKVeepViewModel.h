//
//  VOKVeepViewModelNew.h
//  VPKit
//
//  Created by jonathan on 19/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKVeep.h"
#import "VPKConstants.h"



@interface VPKVeepViewModel : NSObject
@property (nonatomic, strong, readonly) UIImage* image;
@property (nonatomic, strong, readonly) VPKVeep* veep;

@property (nonatomic, strong) NSString* selectedTrackID;
#ifdef USE_TRACKIDX
@property (nonatomic, strong) NSMutableArray* trackIDs;
#endif
@property (nonatomic, assign, readonly, getter=isEditable) BOOL editable;
@property (nonatomic, assign) BOOL locked; //cannot deselect, can delete
@property (nonatomic, strong) NSNumber* observableLock; //cannot deselect, can delete



- (instancetype)initWithImage:(UIImage*)image veepID:(NSString*)veepID;

- (NSNumber*)trackIdxForTrackID:(NSString*)trackID;

//editing functions
- (void)createTrackWithID:(NSString*)tempID frame:(CGRect)frame center:(CGPoint)center;
- (void)deleteTrack:(NSString*)trackID;
- (void)monetiseTrack:(NSString*)trackID monetised:(BOOL)on;
- (void)updateSelectedTrackWithFrame:(CGRect)frame center:(CGPoint)center;
//- (void)updateSelectedTrackURL:(NSURL*)url;

- (void)publishVeepWithMediaID:(NSString*)mediaID completion:(VPK_MediaIDVeepIDErrorBlock)completion;


@end
