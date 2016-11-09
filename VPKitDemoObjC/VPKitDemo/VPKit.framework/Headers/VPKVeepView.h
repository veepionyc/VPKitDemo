//
//  VPMultiTracking.h
//  FNCamShift
//
//  Created by jonathan on 21/01/2016.
//  Copyright © 2016 foundry. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKVeepViewModel.h"

@class VPKVeepView;
@class VPKVeepTrackView;


@interface VPKVeepView : UIView

@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, assign) BOOL useVeepLogo;
@property (nonatomic, strong) VPKVeepViewModel* viewModel;

- (instancetype)initWithViewModel:(VPKVeepViewModel*)viewModel;

- (UIImageView*)transitionImageView;

- (VPKVeepTrackView*)selectedTrackView;


- (void)addTrackAtPoint:(CGPoint)point;
- (void)selectTrackView:(VPKVeepTrackView*)track;

@end
