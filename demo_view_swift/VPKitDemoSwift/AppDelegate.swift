//
//  AppDelegate.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 09/11/2016.
//  Copyright © 2016 Veepio. All rights reserved.
//

import UIKit
import VPKit


@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        /*
         
         APP CREDENTIALS: required
         
         These app credentials are for testing purposes only.
         To obtain credentials unique to your app visit the VEEPIO developer portal
         https://developer.veep.io
         */
        
        
        let appId = "VEEPIO_by_url_test_app_id"
        let clientId = "1zArpBErovQ1MjVHvigJqXwE8qt47U2Yy5XzG3CP"
        let clientSecret = "VpLIvEetceUnHBEIf6fLUwLxELBh2QesZ6iLLiPHCesRLXfOLLJNcFfmp03wJfGaJquO3V8KqHjtvzlufuXfWWgcpWVw9wxfBJNYdZh96JHV5hk44dJbqiCqplrKcSml"
        
        /*
         
         INITIALISATION
         
         */
        
        VPKit.setApplicationId(appId,
                               clientId: clientId,
                               clientSecret: clientSecret)
        
        /*
         
         ENVIRONMENT
         
         The sandbox service is offline; use the production environment.
         
         */
        
        VPKit.environment().production = true
        
        /*
         
         IDFA support - optional, off by default
         
         Since VPKit 2.11 advertising-identifier collection is an explicit opt-in
         (VPKit.sendIDFA(true)), honoured only while the app holds App Tracking
         Transparency authorisation. This demo does not opt in. An app that does must
         link AdSupport and AppTrackingTransparency, add NSUserTrackingUsageDescription,
         and declare tracking in its own privacy manifest.
         See https://veepionyc.github.io/ for details.
         
         */
        
        
        /*
         
         STYLE SETTINGS - OPTIONAL
         See header files for full list of settable properties
         
         */
        
        VPKit.styles().margin = 12
        VPKit.styles().color.navBar = UIColor(white: 0.1, alpha: 1.0)
        VPKit.styles().font.navBarFont = UIFont.systemFont(ofSize: 18, weight: .heavy)
        VPKit.styles().font.cellNavBarFont = UIFont.systemFont(ofSize: 14, weight: .bold)
        
        return true
    }
    
    // MARK: UISceneSession lifecycle
    
    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default", sessionRole: connectingSceneSession.role)
    }
    
}


/*
 
 SCENE DELEGATE
 
 Apps built with the iOS 27 SDK must adopt the UIScene life cycle, otherwise they launch
 without a window. UIKit loads Main.storyboard into this scene's window from the
 UIApplicationSceneManifest entry in Info.plist. VPKit itself works under either life cycle.
 
 */

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
    var window: UIWindow?
}
