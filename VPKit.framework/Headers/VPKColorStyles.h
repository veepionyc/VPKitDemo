//
//  VPKColorStyles.h
//  VPKit
//
//  Created by jonathan on 31/05/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//
//

#import <UIKit/UIKit.h>

/**
 VPKit color styles are set and adjusted here.
 
 */

@interface VPKColorStyles : NSObject

/**
 VEEPIO green. Default color for veep track rectangles.
 */
@property (nonatomic, strong) UIColor* vpkGreen; //used

/**
 Color to use for the main navigation bar.
 */
@property (nonatomic, strong) UIColor* navBar; //used

/**
 Color to use for the main navigation bar text.
 */
@property (nonatomic, strong) UIColor* navBarText;

/**
 Light color to use for the main navigation bar.
 */
@property (nonatomic, strong) UIColor* navBarLight; //used


/**
 Dark color to use for the main navigation bar.
 */
@property (nonatomic, strong) UIColor* navBarDark; //used

/**
 Color to use for the cell navigation bar.
 */
@property (nonatomic, strong) UIColor* cellNavBar; //used

/**
 Gray color to use for the cell navigation bar.
 */
@property (nonatomic, strong) UIColor* cellMidGrey; //used

/**
 :nodoc:
 */
@property (nonatomic, strong) UIColor* searchBar;

/**
 :nodoc:
 */
@property (nonatomic, strong) UIColor* alertButton;

/**
 :nodoc:
 */
@property (nonatomic, strong) UIColor* alertText;

/**
 :nodoc:
 */
@property (nonatomic, strong) UIColor* on;

/**
 :nodoc:
 */
@property (nonatomic, strong) UIColor* off;

@end

