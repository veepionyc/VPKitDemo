//
//  UIView_VPKLoader.h
//  Foundry
//
//  Created by jonathan on 12/10/2013.
//  Copyright (c) 2013 Foundry. All rights reserved.
//

#import <UIKit/UIKit.h>
void UIView_vpkLoader();

typedef NS_ENUM(NSInteger, VPK_LoaderType) {
    VPK_LoaderTypeOriginal,
    VPK_LoaderTypeTransparent,
    VPK_LoaderTypeBlur
};


@interface UIView (VPKLoader)

- (void) vpk_showLoader;
- (void) vpk_showLoader:(CGFloat)delay;
- (void) vpk_showBlockingLoader;
- (void) vpk_hideLoader;

/**
 *  Shows loader on a background with alpha 0.5 - white for a gray indicator, black for a white indicator.
 *
 *  @param style - any UIActivityIndicatorView style
 *
 */
- (void) vpk_showLoaderWithStyle:(UIActivityIndicatorViewStyle)style;
- (void) vpk_showLoaderWithStyle:(UIActivityIndicatorViewStyle)style delay:(CGFloat)delay;

/**
 *  Shows loader with transparent background - so the apperance is just the same as a standard UIActivityIndicatorView.
 *
 *  @param style - any UIActivityIndicatorView style
 *
 */

- (void) vpk_showLoaderWithTransparentStyle:(UIActivityIndicatorViewStyle)style;
- (void) vpk_showLoaderWithTransparentStyle:(UIActivityIndicatorViewStyle)style delay:(CGFloat)delay;
/**
 *  Shows loader with style and type params 
 *
 *  @param style - any UIActivityIndicatorView style
 *
 */
- (void) vpk_showLoaderWithBlurStyle:(UIActivityIndicatorViewStyle)style;
- (void) vpk_showLoaderWithBlurStyle:(UIActivityIndicatorViewStyle)style delay:(CGFloat)delay;

/**
 *  As above but with point parameter (default position in the above is centre of view)
 *
 *  @param point - point in view on which activityView will be centered
 *
 */
- (void)vpk_showLoaderAtPoint:(CGPoint)point;
- (void)vpk_showLoaderWithStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point;
- (void)vpk_showLoaderWithTransparentStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point;
- (void)vpk_showLoaderWithBlurStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point;


- (void)vpk_showLoaderAtPoint:(CGPoint)point scale:(CGFloat)scale;
- (void)vpk_showLoaderWithStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point scale:(CGFloat)scale;
- (void)vpk_showLoaderWithTransparentStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point scale:(CGFloat)scale;

- (void)vpk_showLoaderAtPoint:(CGPoint)point scale:(CGFloat)scale delay:(CGFloat)delay;
- (void)vpk_showLoaderWithStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point scale:(CGFloat)scale delay:(CGFloat)delay;
- (void)vpk_showLoaderWithTransparentStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point scale:(CGFloat)scale delay:(CGFloat)delay;

- (void)vpk_showLoaderWithBlurStyle:(UIActivityIndicatorViewStyle)style atPoint:(CGPoint)point scale:(CGFloat)scale;
@end
