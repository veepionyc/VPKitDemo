//
//  AppDelegate.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import "AppDelegate.h"
#import "VPKit/VPKit.h"

//optional for IDFA support
@import AdSupport;


@interface AppDelegate ()

@end

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
    NSString* appId = @"VeepMaker-Eagles";
    NSString* clientId = @"XGTDTI3XGF91yoSudZmfYXuVu3ZZ5OeHM2UfCtZv";
    NSString* clientSecret = @"4LNUTdiQkakzJH4ZWWnjqiiPX2zc4IADXaLANw0UIUAD35EWbw6NVEd2tLBJKx95jTCXTjIFj4wRUCsgXjAeHb2HtUYDYSaEz3GWuK6xJO7TAS0fZPQP4AZOatMCkFi0";
    
    
    */
    /*
     
     INITIALISATION
     
     */
    
    [VPKit setApplicationId:appId
                   clientId:clientId
               clientSecret:clientSecret];
    
    [VPKit setProduction:YES];
    /*
     
     
     IDFA support - optional
     
     (optional) send IDFA for Veep tracking
     
     This requires host app linking to AdSupport.framework ("link binary with libarires" section of project Build Phases)
     
     Setting this option to YES entails additional reporting requirements when submitting to the app store
     
     https://developer.apple.com/library/content/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html#//apple_ref/doc/uid/TP40011225-CH33-SW8
     
     */
    
    [VPKit sendIDFA:YES];
    
    
    /*
     
     STYLE SETTINGS - OPTIONAL
     See header files for full list of settable properties
     
     */
    
    [VPKit styles].margin = 0;
    VPKit.styles.color.navBar = [UIColor colorWithWhite:0.1 alpha:1.0];
    VPKit.styles.font.navBarFont = [UIFont systemFontOfSize:18 weight:UIFontWeightHeavy];
    VPKit.styles.font.cellNavBarFont = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
    
    
    return YES;
}



@end
