//
//  UIView+vpk_BlurView.h
//  Foundry
//
//  Created by jonathan on 04/07/2014.
//  Copyright (c) 2014 Foundry. All rights reserved.
//
#import <UIKit/UIKit.h>




@interface UIView (WNBlurView)

+ (UIView*)vpk_BlurView;
+ (UIView*)vpk_BlurViewLite;
+ (UIView*)vpk_BlurViewLiteDark;
+ (UIView*)vpk_BlurViewDark;
+ (UIView*)vpk_BlurViewMiniDark;


+ (UIView*)vpk_blurView:(UIBlurEffectStyle)style;
+ (UIView*)vpk_blurVibrantView:(UIBlurEffectStyle)style;
+ (UIView*)vpk_contentViewForVisualEffectView:(UIVisualEffectView*)blurView;


@end
