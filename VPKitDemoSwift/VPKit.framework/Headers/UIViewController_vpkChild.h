//
//  UIViewController_Child.h
//  Veepio
//
//  Created by jonathan on 23/04/2016.
//  Copyright © 2016 VeePiO. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (Child)
- (void)vpk_addChild:(UIViewController*)child;
- (void)vpk_removeChild:(UIViewController*)child;

@end
