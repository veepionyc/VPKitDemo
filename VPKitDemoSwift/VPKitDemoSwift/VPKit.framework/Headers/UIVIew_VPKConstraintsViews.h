//
//  NSUIView+FNConstraintsViews.h
//  FNToolBox
//
//  Created by jonathan on 06/10/2014.
//  Copyright (c) 2016 NSFoundry Ltd. All rights reserved.

//
@import Foundation;
#if TARGET_OS_IPHONE
@import UIKit;
#define NSUIView UIView

#else
@import AppKit;
#define NSUIView NSView

#endif

void use_VPKConstraintsViews();
//extern NSInteger FORCE_LOAD_VPKConstraintsViews;

//#define AddSubView(superview,subview)  \
//     [superview addView:subview withName:@#subview]




@interface NSUIView (FNConstraintsViews)
/*
 This category adds a constraintsView array to a NSUIView. The array tracks all subviews for which layoutConstraint changes are applicable. On 'updateLayoutConstraints' the array is used to remove all relevant constraints which are then rebuilt. This saves having to keep track of such a list per view, which often leads to crashes if the view is not actually instantiated when 'updateLayoutConstraints' is called.
 
     we return the same view as we pass in for swift lazy view creation friendliness
 
 */

- (NSUIView*)vpk_addView:(NSUIView*)view;

/*
 - (NSUIView*)addView:(NSUIView *)view withName:(NSString*)name;
 adds view to constriantsViews dictionary to NSUIView for use with visual layout formats

 we return the same view as we pass in for swift lazy view creation friendliness

 
 */

- (NSUIView*)vpk_addView:(NSUIView *)view withName:(NSString*)name;

- (void)vpk_removeFromView;



- (NSMutableArray*)vpk_constraintsViews; //views array

- (NSMutableDictionary*)vpk_constrainedViews;  //views dictionary, suitable for ascii constraints views dict

//- (NSLayoutConstraint*)constraintForAttribute:(NSLayoutAttribute)attribute;

//- (NSLayoutConstraint*)constraintForFirstItem:(NSUIView*)firstItem
//                               firstAttribute:(NSLayoutAttribute)firstAttribute
//                                   secondItem:(NSUIView*)secondItem
//                              secondAttribute:(NSLayoutAttribute)secondAttribute;

//- (NSLayoutConstraint*)constraintForView:(NSUIView*)view
//                               attribute:(NSLayoutAttribute)attribute;

- (void)vpk_addSpacers:(int)numberOfSpacers;

@end


