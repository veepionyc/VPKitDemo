//
//  AppDelegate.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 09/11/2016.
//  Copyright © 2016 Veepio. All rights reserved.
//

import UIKit
import VPKit


@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

        /*
         Use this app id for testing purposes only. For app deployment, email sdk_support@veepio.com to obtain a unique app id
         */
        
        VPKit.setApplicationIdentifier("VEEPIO_test_app_id")

        
        /*
         Style changes
         These are all optional
         */
        
        VPKit.styles().margin = 12
        VPKit.styles().color.navBar = UIColor.init(white: 0.1, alpha: 1.0)
        VPKit.styles().font.navBarFont = UIFont .systemFont(ofSize: 18, weight: UIFontWeightHeavy);
        VPKit.styles().font.cellNavBarFont = UIFont .systemFont(ofSize: 14, weight: UIFontWeightBold);
        
        return true
    }

}

