//
//  UIAlertController_QuickAlerts.h
//  FNToolBox
//
//  Created by jonathan on 10/10/2014.
//  Copyright (c) 2016 NSFoundry Ltd. All rights reserved.

//

@import UIKit;
#import "VPKConstants.h"
//typedef void (^VPK_AlertActionBlock)(UIAlertAction* action);

@interface UIAlertController (vpkQuickAlerts)

+ (UIAlertController*)vpk_alertControllerWithTitle:(NSString*)title
                                       message:(NSString*)message
                                        action:(NSString*)action;

+ (UIAlertController*)vpk_alertControllerWithTitle:(NSString*)title
                                       message:(NSString*)message
                                       actions:(NSArray*)actions
                                 actionHandler:(VPK_AlertActionBlock)actionHandler;

+ (UIAlertController*)vpk_alertControllerWithTitle:(NSString*)title
                                       message:(NSString*)message
                                       actions:(NSArray*)actions
                                preferredStyle:(UIAlertControllerStyle)preferredStyle
                                 actionHandler:(VPK_AlertActionBlock)actionHandler;


+ (UIAlertController*)vpk_alertControllerWithError:(NSError*)error;

+ (UIAlertController*)vpk_alertControllerWithErrorExtended:(NSError*)error;

+ (UIAlertController*)vpk_alertControllerWithMessage:(NSString*)message;

+ (UIAlertController*)vpk_alertControllerWithTitle:(NSString*)title;

+ (UIAlertController*)vpk_alertControllerWithTitle:(NSString*)title
                   message:(NSString*)message;


+ (void)vpk_presentAlertWithError:(NSError*)error;

+ (void)vpk_presentAlertWithMessage:(NSString*)message;

+ (void)vpk_presentAlertWithTitle:(NSString*)title;

+ (void)vpk_presentAlertWithTitle:(NSString*)title
                      message:(NSString*)message;

+ (void)vpk_presentAlertWithTitle:(NSString*)title
                      message:(NSString*)message
                      actions:(NSArray*)actions
                actionHandler:(VPK_AlertActionBlock)handler;

+ (void)vpk_presentAlertWithTitle:(NSString*)title
                      message:(NSString*)message
                      actions:(NSArray*)actions
               preferredStyle:(UIAlertControllerStyle)preferredStyle
                actionHandler:(VPK_AlertActionBlock)handler;

- (void)vpk_presentAlert;
@end
