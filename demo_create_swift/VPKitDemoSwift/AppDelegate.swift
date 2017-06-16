//
//  AppDelegate.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 09/11/2016.
//  Copyright © 2016 Veepio. All rights reserved.
//

import UIKit
import VPKit

//optional for IDFA support
import AdSupport




@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        /*
         
         APP CREDENTIALS: required
         
         These app credentials are for testing purposes only.
         To obtain credentials unique to your app visit the VEEPIO developer portal
         https://developer.veep.io
         */
        
        
        let appId = "VEEPIO_test_app_id"
        let clientId = "VsRIkxIfTtkFJhw1ABItnO50B6fSW23NhIRnST53"
        let clientSecret = "OdWbCaP9i1I2AV2yZUzwfDFE4gU04RDX1HdubnTEg8oWw8F9yWQwjX179zHRXLUad5vrsOo5B7UtFq2utsrWbkjVus5aJKxW8wXTvDknqdgeowunL9yeEN8selNpTOJF"
        
        /*
         
         INITIALISATION
         
         */
        
        VPKit.setApplicationId(appId,
                               clientId: clientId,
                               clientSecret: clientSecret)

        
        /*
         
         IDFA support
         
         (optional) send IDFA for Veep tracking
         
         This requires host app linking to AdSupport.framework ("link binary with libarires" section of project Build Phases)
         
         Setting this option to YES entails additional reporting requirements when submitting to the app store
         
         https://developer.apple.com/library/content/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html#//apple_ref/doc/uid/TP40011225-CH33-SW8
         
         */
        
        VPKit.sendIDFA(true)
        
       
        /*
         
         STYLE SETTINGS - OPTIONAL
         See header files for full list of settable properties
         
         */
        
        VPKit.styles().margin = 12
        VPKit.styles().color.navBar = UIColor.init(white: 0.1, alpha: 1.0)
        VPKit.styles().font.navBarFont = UIFont .systemFont(ofSize: 18, weight: UIFontWeightHeavy);
        VPKit.styles().font.cellNavBarFont = UIFont .systemFont(ofSize: 14, weight: UIFontWeightBold);
        
        return true
    }
    
}

