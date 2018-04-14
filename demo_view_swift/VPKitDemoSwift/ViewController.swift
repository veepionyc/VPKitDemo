//
//  ViewController.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 09/11/2016.
//  Copyright © 2016 Veepio. All rights reserved.
//

import UIKit
import VPKit

class ViewController:
    UIViewController

{
    
    //MARK: - properties
    
    @IBOutlet var titleLabel: UILabel!
    @IBOutlet var consumeLabel: UILabel!
    @IBOutlet var createLabel: UILabel!
    @IBOutlet var versionLabel: UILabel!
    @IBOutlet var preview1: VPKPreview!
    @IBOutlet var preview2: VPKPreview!
    
    
    
    //MARK: - viewController lifecycle
    
    required init?(coder aDecoder: NSCoder)
    {
        super.init(coder: aDecoder)
    }

    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.versionLabel.text = VPKit.sdkVersion()
        self.configurePreview1()
        self.configurePreview2()
        self.configureConstraints()
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.portrait
    }
    
    //MARK: - configuration
    
    func configurePreview1()
    {
        guard let image = UIImage.init(named: "stock_photo") else {return}
        let imageURL = URL(string: "https://raw.githubusercontent.com/veepionyc/VPKitDemo/master/VPKitDemoObjC/VPKitDemo/Assets.xcassets/stock_photo.imageset/photo-1468818461933-b1d79f62434e.jpg")!
        let previewImage: VPKImage = VPKImage(image: image, url:imageURL)
        self.preview1.image = previewImage
    }
    
    func configurePreview2()
    {
        guard let image = UIImage.init(named: "KrispyGlas") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepId:"1787")
        self.preview2.image = previewImage
    }
    
    

}

