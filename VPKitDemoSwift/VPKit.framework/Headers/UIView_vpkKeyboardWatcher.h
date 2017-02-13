//
//  UIViewController_KeyboardWatcher.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface NSNotification (vpk_KeyboardWatcher)
- (CGFloat)keyboardTopInView:(UIView*)view;
- (CGFloat)keyboardTop;
- (CGFloat)keyboardHeightInView:(UIView*)view;
- (CGFloat)keyboardHeight;
- (CGRect)keyboardRect;

@end

@interface UIView (vpk_KeyboardWatcher)



- (CGFloat)keyboardHeight;
- (void)setKeyboardNotifications:(BOOL)on;
- (void)keyboardWillShowNotification:(NSNotification*)notification;
- (void)keyboardWillHideNotification:(NSNotification*)notification;
- (void)keyboardDidShowNotification:(NSNotification *)notification;
- (void)keyboardDidHideNotification:(NSNotification *)notification;
- (void)keyboardWillChangeFrameNotification:(NSNotification*)notification;

@end
