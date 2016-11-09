//
//  VPKTouchView.h
//  VPKit
//
//  Created by jonathan on 26/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKTouchView;

@protocol VPKTouchViewDelegate <NSObject>

- (void)touchViewTouched:(nonnull VPKTouchView*)view;

@end

@interface VPKTouchView : UIView
@property (nonnull, nonatomic, strong) UIImageView* imageView;
@property (nullable, nonatomic, weak) id <VPKTouchViewDelegate> delegate;
@end
