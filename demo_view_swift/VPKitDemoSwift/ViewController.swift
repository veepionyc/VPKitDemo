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
        self.versionLabel.text = VPKit.version()
        self.configurePreview1()
        self.configurePreview2()
        self.configureConstraints()
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
    
    
    
    //MARK: - layout boilerplate
    
    
    func configureConstraints()
    {
        let views:[String:UIView] =  [
            "titleLabel":self.titleLabel!
            ,"consumeLabel":self.consumeLabel!
            ,"createLabel":self.createLabel!
            ,"preview1":self.preview1!
            ,"preview2":self.preview2!
            ,"versionLabel":self.versionLabel!
            
            
        ]
        for (_,view) in views {
            view.translatesAutoresizingMaskIntoConstraints = false
        }
        
        var ratio : CGFloat =  1.0
        let height = self.view.bounds.size.height
        
        if (height>0) {
            let width = self.view.bounds.size.width
            ratio = width/height
        }
        
        
        
        let vMargin = 80 * ratio;
        let tMargin = height / 20.0
        let formats =
            [
                "H:|-(vMargin)-[titleLabel]-(vMargin)-|",
                "H:|-(vMargin)-[preview1]-(vMargin)-|",
                "H:|-(vMargin)-[consumeLabel]-(vMargin)-|",
                "H:|-(vMargin)-[preview2]-(vMargin)-|",
                "H:|-(vMargin)-[createLabel]-(vMargin)-|",
                "H:|-(vMargin)-[versionLabel]-(vMargin)-|",
                "V:|-(tMargin)-[titleLabel]-(18)-[preview1]-(4)-[consumeLabel]-(18)-[preview2]-(4)-[createLabel]",
                "V:[versionLabel]-(8)-|"
        ];
        
        for format in formats {
            self.view.addConstraints(
                NSLayoutConstraint.constraints(withVisualFormat: format,
                                               options:NSLayoutFormatOptions(rawValue:0),
                                               metrics: ["vMargin":vMargin, "tMargin":tMargin],
                                               views: views)
            )
        }
        
        guard let vImage = self.preview1?.image else {return}
        var size = vImage.size;
        self.alignHeightToWidth(view:self.preview1!, ratio: size.height/size.width);
        guard let eImage = self.preview2?.image else {return}
        size = eImage.size;
        self.alignHeightToWidth(view:self.preview2!, ratio: size.height/size.width);
        
    }
    
    func alignHeightToWidth (view:UIView, ratio:CGFloat)
    {
        view.superview?.addConstraint(
            NSLayoutConstraint.init(
                item: view,
                attribute: NSLayoutAttribute.height,
                relatedBy: NSLayoutRelation.equal,
                toItem: view,
                attribute: NSLayoutAttribute.width,
                multiplier: ratio, constant: 0)
        )
    }
    

}

