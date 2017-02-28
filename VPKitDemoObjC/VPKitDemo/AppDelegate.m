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
     
     VPKIT CREDENTIALS
     These test app credentials are for testing purposes only.
     To obtain credentials unique to your app email sdk_support@veepio.com
     
     */
    
    NSString* appID = @"VEEPIO_test_app_id";
    NSString* clientID = @"VsRIkxIfTtkFJhw1ABItnO50B6fSW23NhIRnST53";
    NSString* clientSecret = @"OdWbCaP9i1I2AV2yZUzwfDFE4gU04RDX1HdubnTEg8oWw8F9yWQwjX179zHRXLUad5vrsOo5B7UtFq2utsrWbkjVus5aJKxW8wXTvDknqdgeowunL9yeEN8selNpTOJF";

    
    /*
     
     INITIALISATION
    
     */
    
    [VPKit setApplicationId:appID
                   clientId:clientID
               clientSecret:clientSecret];
    
    
    /*
     
     SANDBOXING
     Testing and development - NO
     Deployment - YES
    
     */
    
    [VPKit setProduction:NO];


    
    /*
     
     STYLE SETTINGS - OPTIONAL
     See header files for full list of settable properties
     
     */
    
    [VPKit styles].margin = 12;
    VPKit.styles.color.navBar = [UIColor colorWithWhite:0.1 alpha:1.0];
    VPKit.styles.font.navBarFont = [UIFont systemFontOfSize:18 weight:UIFontWeightHeavy];
    VPKit.styles.font.cellNavBarFont = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
    
    
    
    return YES;
}



@end
