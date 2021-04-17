//
//  VPKStyles.h
//  VPKit
//
//  Created by jonathan on 31/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKColorStyles.h"
#import "VPKFontStyles.h"


/**
 Use VPKStyles and it's subclasses to alter the default appearance of the VPKit UI.
 
 */

@interface VPKStyles : NSObject


#pragma mark - units

@property (nonatomic, assign) CGFloat lineWidth;

/**
 set this property to adjust the left and right margins for the Veep View.
 
 
 */
@property (nonatomic, assign) CGFloat margin;


/**
 set this property to adjust the  VPKPreview icon width.
 
 The default value is 50.
 
 
 */
@property (nonatomic, assign) CGFloat previewIconWidth;



#pragma mark - color

/**
 VPKit font styles are set and adjusted in this VPKFontStyles object.
 
 */

@property (nonatomic, strong) VPKFontStyles* font;

/**
 VPKit color styles are set and adjusted in this VPKColorStyles object.
 
 */
@property (nonatomic,strong) VPKColorStyles* color;

- (void)configureAppearance;
- (NSDictionary*)barButtonItemFontAttributes;
- (NSDictionary*)barButtonItemFontAttributesDisabled;
- (NSDictionary*)barButtonItemFontAttributesEnabled;
- (void)configureNavBar:(UINavigationBar*)navBar;
- (void)configureCellNavBar:(UINavigationBar*)navBar;
- (void)configureBarButtonItem:(UIBarButtonItem*)barButtonItem;

@end
