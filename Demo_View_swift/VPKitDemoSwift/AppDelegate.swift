//
//  AppDelegate.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 09/11/2016.
//  Copyright © 2016 Veepio. All rights reserved.
//

import UIKit
import VPKit
import AdSupport

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        /*
         
         VPKIT CREDENTIALS
         These app credentials are for testing purposes only.
         To obtain credentials unique to your app email sdk_support@veepio.com
         
         */
        
        
        let appID = "VEEPIO_test_app_id"
        let clientID = "VsRIkxIfTtkFJhw1ABItnO50B6fSW23NhIRnST53"
        let clientSecret = "OdWbCaP9i1I2AV2yZUzwfDFE4gU04RDX1HdubnTEg8oWw8F9yWQwjX179zHRXLUad5vrsOo5B7UtFq2utsrWbkjVus5aJKxW8wXTvDknqdgeowunL9yeEN8selNpTOJF"
        var userEmail = "anonymous@example.com"
        
        /* IDFA support
         
         if the host app is IDFA-enabled and the user is opt-in, use the IDFA in place of email for anonymous users
         */

        
        if (ASIdentifierManager.shared().isAdvertisingTrackingEnabled)
        {
            if let idfa = ASIdentifierManager.shared().advertisingIdentifier {
                userEmail = "idfa:\(idfa.uuidString)";
            }
        }
        
        
        /*
         
         INITIALISATION
         
         */
        
        VPKit.setApplicationID(appID,
                               clientID: clientID,
                               clientSecret: clientSecret)
        
        VPKit.setEmail(userEmail)
        
        /*
         
         SANDBOXING
         Testing and development - NO
         Deployment - YES
         
         */
        
        VPKit.setProduction(false)
        
        
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

