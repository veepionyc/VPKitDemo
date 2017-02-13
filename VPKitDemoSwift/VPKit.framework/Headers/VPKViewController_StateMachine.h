//
//  VPKViewController_StateMachine.h
//  VPKit
//
//  Created by jonathan on 22/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "VPKConstants.h"



@interface UIViewController (StateMachine)
- (void)vpk_setState:(VPKState)state;
- (void)vpk_stateChangeRequested:(NSNotification*)notification;
- (void)vpk_listenForStateChange;
- (void)vpk_stateChanged:(NSNotification*)notification;

@end
