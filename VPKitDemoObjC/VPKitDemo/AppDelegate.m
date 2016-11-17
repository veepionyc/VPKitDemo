//
//  AppDelegate.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "AppDelegate.h"
#import <VPKit/VPKit.h>
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    /*
     Use this app id for testing purposes only. For app deployment, email sdk_support@veepio.com to obtain a unique app id
     */
    
    [VPKit setApplicationIdentifier:@"VEEPIO_test_app_id"];
   
    
    /*
     Forward error notifications from the SDK to the app
     This is optional
     
     If not forwarded, the SDK will provide user error alerts where appropriate.
     
     If forwarded, this becomes the app's responsibility.
     */
    
    [VPKit forwardErrorNotifications:YES];
    /*
     Style changes
     These are all optional
     */
    
    [VPKit styles].margin = 12;
    VPKit.styles.color.navBar = [UIColor colorWithWhite:0.1 alpha:1.0];
    VPKit.styles.font.navBarFont = [UIFont systemFontOfSize:18 weight:UIFontWeightHeavy];
    VPKit.styles.font.cellNavBarFont = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
    return YES;
}



@end
