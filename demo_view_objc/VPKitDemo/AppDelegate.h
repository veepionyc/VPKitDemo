//
//  AppDelegate.h
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@end


/*
 
 SCENE DELEGATE
 
 Apps built with the iOS 27 SDK must adopt the UIScene life cycle, otherwise they launch
 without a window. UIKit loads Main.storyboard into this scene's window from the
 UIApplicationSceneManifest entry in Info.plist. VPKit itself works under either life cycle.
 
 */

@interface SceneDelegate : UIResponder <UIWindowSceneDelegate>

@property (strong, nonatomic) UIWindow *window;

@end
