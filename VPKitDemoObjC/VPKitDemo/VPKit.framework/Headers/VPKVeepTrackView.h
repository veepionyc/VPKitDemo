//
//  VPTrackingView.h
//  FNCamShift
//
//  Created by jonathan on 21/01/2016.
//  Copyright © 2016 foundry. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKTrackViewPanGestureRecognizer.h"
#import "VPKVeepTrackViewModel.h"
@class VPKVeepTrackView;

@protocol VPKVeepTrackViewDelegate <NSObject>

- (void)trackPannedWithGR:(VPKTrackViewPanGestureRecognizer*)gestureRecognizer;

- (void)trackTouched:(VPKVeepTrackView*)trackView;

- (void)trackCancelled:(VPKVeepTrackView*)trackView;
- (void)track:(VPKVeepTrackView*)trackView monetised:(BOOL)monetised;
@end

@interface VPKVeepTrackView : UIView
@property (nonatomic, weak) id<VPKVeepTrackViewDelegate> delegate;
@property (nonatomic, strong) VPKVeepTrackViewModel* viewModel;
@property (nonatomic, strong) UIColor* borderColor;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, assign) CGFloat blobWidth;
@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL useVeepLogo;

- (instancetype)initWithFrame:(CGRect)frame
                     viewModel:(VPKVeepTrackViewModel*)viewModel
                     delegate:(id<VPKVeepTrackViewDelegate>)delegate;
@end
