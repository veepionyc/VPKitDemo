//
//  UIView+FNLayoutConstraints.h
//  Foundry
//
//  Created by jonathan on 25/06/2014.
//  Copyright (c) 2014 Foundry. All rights reserved.
//
@import Foundation;
#if TARGET_OS_IPHONE
@import UIKit;
#define FNView UIView

#else
@import AppKit;
#define UIView NSView
#define UIEdgeInsets NSEdgeInsets
#define UIEdgeInsetsZero NSEdgeInsetsZero

#endif

void use_VPKLayoutConstraints();
extern NSInteger FORCE_LOAD_VPKLayoutConstraints;


// Collection of helpers to manage autolayout

@interface FNView (VPKLayoutConstraints)
- (void)vpk_testAmbiguity;

/*
 clearConstraints removes constraints associated from that view
 both from self and from the view passed in. 
 This gets rid of unary (intrinsic) constraints.
 */
//- (void)vpk_clearConstraints; // for auto-created subviewsUnderConstraints array
- (void)vpk_clearConstraintsForSubviews; //same as clearConstraints
- (void)vpk_clearConstraintsForViews:(NSArray*)views;
- (void)vpk_clearConstraintsForView:(FNView*)view;

/*
 removeConstraints removes constraints associated from that view
 from self only, so leaves unary constraints in place
 */
//- (void)vpk_removeConstraints; // for auto-created subviewsUnderConstraints array
- (void)vpk_removeConstraintsForSelf;
- (void)vpk_removeConstraintsForSubviews; //as removeConstraints
- (void)vpk_removeConstraintsForViews:(NSArray*)views;
- (void)vpk_removeConstraintsFromSuperview;


- (void)vpk_centerXinSuperview; // horizontally
- (void)vpk_centerYinSuperview; // vertically
- (void)vpk_centerInSuperview;

- (void)vpk_centerXinSuperviewWithOffset:(CGFloat)offset;
- (void)vpk_centerYinSuperviewWithOffset:(CGFloat)offset;

- (void)vpk_alignLeft:(CGFloat)offset;
- (void)vpk_alignTop:(CGFloat)offset;
- (void)vpk_alignRight:(CGFloat)offset;
- (void)vpk_alignBottom:(CGFloat)offet;
- (void)vpk_alignLeading:(CGFloat)offset;
- (void)vpk_alignTrailing:(CGFloat)offset;
- (void)vpk_alignWidth:(CGFloat)width;
- (void)vpk_alignHeight:(CGFloat)height;
- (void)vpk_alignSize:(CGSize)size;
- (void)vpk_alignFrame:(CGRect)frame;

- (void)vpk_alignInsets:(UIEdgeInsets)insets;

- (void)vpk_alignLeft:(CGFloat)offset relation:(NSLayoutRelation)relation;
- (void)vpk_alignTop:(CGFloat)offset relation:(NSLayoutRelation)relation;
- (void)vpk_alignRight:(CGFloat)offset relation:(NSLayoutRelation)relation;
- (void)vpk_alignBottom:(CGFloat)offet relation:(NSLayoutRelation)relation;
- (void)vpk_alignLeading:(CGFloat)offset relation:(NSLayoutRelation)relation;
- (void)vpk_alignTrailing:(CGFloat)offset relation:(NSLayoutRelation)relation;
- (void)vpk_alignWidth:(CGFloat)width relation:(NSLayoutRelation)relation;
- (void)vpk_alignHeight:(CGFloat)height relation:(NSLayoutRelation)relation;


- (void)vpk_fitX;
- (void)vpk_fitY;
- (void)vpk_fit;
- (void)vpk_fitXWithInset:(CGFloat)inset;
- (void)vpk_fitYWithInset:(CGFloat)inset;
- (void)vpk_fitWithInset:(CGFloat)inset;

+ (void)centerXinSuperview:(NSArray*)views;
+ (void)centerYinSuperview:(NSArray*)views;

- (void)vpk_alignHeightToWidth;
- (void)vpk_alignWidthToHeight;
- (void)vpk_alignHeightToWidth:(CGFloat)multiplier;
- (void)vpk_alignWidthToHeight:(CGFloat)multiplier;

#pragma mark - relations between two views

- (void)vpk_matchView:(UIView*)view;

- (void)vpk_matchView:(UIView*)view scale:(CGFloat)scale;

- (void)vpk_alignFrameToView:(FNView*)view
              scale:(CGFloat)multiplier
                  offset:(CGPoint)offset;

- (void)vpk_alignSizeToView:(FNView*)view
             scale:(CGFloat)multiplier;

- (void)vpk_alignWidthToView:(FNView*)view
              scale:(CGFloat)multiplier;

- (void)vpk_alignHeightToView:(FNView*)view
               scale:(CGFloat)multiplier;

- (void)vpk_alignCenterToView:(FNView*)view
                   offset:(CGPoint)offset;

- (void)vpk_alignCenterXtoView:(FNView*)view
                    offset:(CGFloat)offset;

- (void)vpk_alignCenterYtoView:(FNView*)view
                    offset:(CGFloat)offset;


- (void)vpk_alignTopToBottom:(FNView*)view
                  offset:(CGFloat)offset;
- (void)vpk_alignBottomToTop:(FNView*)view
                  offset:(CGFloat)offset;
- (void)vpk_alignLeftToRight:(FNView*)view
                  offset:(CGFloat)offset;
- (void)vpk_alignRightToLeft:(FNView*)view
                  offset:(CGFloat)offset;

- (void)vpk_alignTopToLeft:(FNView*)view
                offset:(CGFloat)offset;
- (void)vpk_alignLeftToTop:(FNView*)view
                offset:(CGFloat)offset;


- (void)vpk_alignTopEdges:(FNView*)view
               offset:(CGFloat)offset;
- (void)vpk_alignBottomEdges:(FNView*)view
                  offset:(CGFloat)offset;
- (void)vpk_alignLeftEdges:(FNView*)view
                offset:(CGFloat)offset;
- (void)vpk_alignRightEdges:(FNView*)view
                 offset:(CGFloat)offset;


/*
 " Invalid pairing of layout attributes "
 - (void)vpk_alignTopToWidth:(UIView*)view
 multiplier:(CGFloat)multiplier;
 
 - (void)vpk_alignTopToHeight:(UIView*)view
 multiplier:(CGFloat)multiplier;
 */

- (void)vpk_alignAttribute:(NSLayoutAttribute)myAttribute
                toView:(FNView*)view
             attribute:(NSLayoutAttribute)theirAttribute
            multiplier:(CGFloat)multiplier
              constant:(CGFloat)constant;







@end
