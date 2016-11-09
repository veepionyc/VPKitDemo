//
//  UIViewController_Presents.h
//  FNToolBox
//
//  Created by jonathan on 11/10/2014.
//  Copyright (c) 2016 NSFoundry Ltd. All rights reserved.

//

void UIViewController_vpkPresents();

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface UIViewController (vpkPresents)

- (void)vpk_present:(UIViewController*)viewController
       animated:(BOOL)animated;
- (void)vpk_present:(UIViewController*)viewController;
@end

