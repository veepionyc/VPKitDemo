//
//  NavigationController.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 07/09/2018.
//  Copyright © 2018 Veepio. All rights reserved.
//

import UIKit

class NavigationController: UINavigationController {
    
    //constrain to portrait to test that VPKit Viewer can still rotate to landscape and rotate back when closing
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.portrait
    }
    
    override var shouldAutorotate: Bool {
        return false
    }
 

}
