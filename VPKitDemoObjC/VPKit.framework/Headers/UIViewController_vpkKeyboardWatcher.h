//
//  UIViewController_KeyboardWatcher.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>




@interface UIViewController (vpk_KeyboardWatcher)



- (CGFloat)vpk_keyboardHeight;
- (void)vpk_setKeyboardNotifications:(BOOL)on;
- (void)vpk_keyboardWillShowNotification:(NSNotification*)notification;
- (void)vpk_keyboardWillHideNotification:(NSNotification*)notification;
- (void)vpk_keyboardDidShowNotification:(NSNotification *)notification;
- (void)vpk_keyboardDidHideNotification:(NSNotification *)notification;
- (void)vpk_keyboardWillChangeFrameNotification:(NSNotification*)notification;

@end
