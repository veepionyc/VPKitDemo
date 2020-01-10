//
//  AppDelegate.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
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
    
    NSString* appId = @"VEEPIO_test_app_id";
    NSString* clientId = @"VsRIkxIfTtkFJhw1ABItnO50B6fSW23NhIRnST53";
    NSString* clientSecret = @"OdWbCaP9i1I2AV2yZUzwfDFE4gU04RDX1HdubnTEg8oWw8F9yWQwjX179zHRXLUad5vrsOo5B7UtFq2utsrWbkjVus5aJKxW8wXTvDknqdgeowunL9yeEN8selNpTOJF";
    
    /*
     
     INITIALISATION
     
     */
    
    [VPKit setApplicationId:appId
                   clientId:clientId
               clientSecret:clientSecret];
    
        
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
    
    [VPKit styles].margin = 12;
    VPKit.styles.color.navBar = [UIColor colorWithWhite:0.1 alpha:1.0];
    VPKit.styles.font.navBarFont = [UIFont systemFontOfSize:18 weight:UIFontWeightHeavy];
    VPKit.styles.font.cellNavBarFont = [UIFont systemFontOfSize:14 weight:UIFontWeightBold];
   // [VPKit setProduction:YES    ];
  //  [VPKit setShouldMonetise:YES];
    
    return YES;
}



@end
