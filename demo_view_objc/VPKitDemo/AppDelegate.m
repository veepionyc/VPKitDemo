//
//  AppDelegate.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import "AppDelegate.h"
#import <VPKit/VPKit.h>


@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    /*
     
     APP CREDENTIALS: required
     
     These app credentials are for testing purposes only.
     To obtain credentials unique to your app visit the VEEPIO developer portal
     https://developer.veep.io
     */
    
    NSString* appId = @"VEEPIO_by_url_test_app_id";
    NSString* clientId = @"1zArpBErovQ1MjVHvigJqXwE8qt47U2Yy5XzG3CP";
    NSString* clientSecret = @"VpLIvEetceUnHBEIf6fLUwLxELBh2QesZ6iLLiPHCesRLXfOLLJNcFfmp03wJfGaJquO3V8KqHjtvzlufuXfWWgcpWVw9wxfBJNYdZh96JHV5hk44dJbqiCqplrKcSml";
    
    
    /*
     
     INITIALISATION
     
     */
    
    [VPKit setApplicationId:appId
                   clientId:clientId
               clientSecret:clientSecret];
    
    /*
     
     ENVIRONMENT
     
     The sandbox service is offline; use the production environment.
     
     */
    
    VPKit.environment.production = YES;
    
    /*
     
     IDFA support - optional, off by default
     
     Since VPKit 2.11 advertising-identifier collection is an explicit opt-in
     ([VPKit sendIDFA:YES]), honoured only while the app holds App Tracking
     Transparency authorisation. This demo does not opt in. An app that does must
     link AdSupport and AppTrackingTransparency, add NSUserTrackingUsageDescription,
     and declare tracking in its own privacy manifest.
     See https://veepionyc.github.io/ for details.
     
     */
    
    
    /*
     
     STYLE SETTINGS - OPTIONAL
     See header files for full list of settable properties
     
     */
    
    VPKit.styles.margin = 0;
    VPKit.styles.color.navBar = [UIColor colorWithWhite:0.1 alpha:1.0];
    VPKit.styles.font.navBarFont = [UIFont systemFontOfSize:18 weight:UIFontWeightHeavy];
    VPKit.styles.font.cellNavBarFont = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
    
    
    return YES;
}


#pragma mark - UISceneSession lifecycle

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    return [[UISceneConfiguration alloc] initWithName:@"Default" sessionRole:connectingSceneSession.role];
}


@end


@implementation SceneDelegate

@end
