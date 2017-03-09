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


@interface VPKStyles : NSObject


#pragma mark - units

@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) CGFloat margin;



#pragma mark - color

@property (nonatomic, strong) VPKFontStyles* font;
@property (nonatomic,strong) VPKColorStyles* color;

- (void)configureAppearance;
- (NSDictionary*)barButtonItemFontAttributes;
- (NSDictionary*)barButtonItemFontAttributesDisabled;
- (NSDictionary*)barButtonItemFontAttributesEnabled;
- (void)configureNavBar:(UINavigationBar*)navBar;
- (void)configureCellNavBar:(UINavigationBar*)navBar;
- (void)configureBarButtonItem:(UIBarButtonItem*)barButtonItem;

@end
