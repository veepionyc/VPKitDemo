//
//  ViewController_Layout.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 14/04/2018.
//  Copyright © 2018 Veepio. All rights reserved.
//

import UIKit



extension ViewController {
    func configureConstraints()
    {
        let views:[String:UIView] =  [
            "titleLabel":self.titleLabel!
            ,"consumeLabel":self.consumeLabel!
            ,"createLabel":self.createLabel!
            ,"viewerPreview":self.viewerPreview!
            ,"editorPreview":self.editorPreview!
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
                "H:|-(vMargin)-[viewerPreview]-(vMargin)-|",
                "H:|-(vMargin)-[consumeLabel]-(vMargin)-|",
                "H:|-(vMargin)-[editorPreview]-(vMargin)-|",
                "H:|-(vMargin)-[createLabel]-(vMargin)-|",
                "H:|-(vMargin)-[versionLabel]-(vMargin)-|",
                "V:|-(tMargin)-[titleLabel]-(18)-[viewerPreview]-(4)-[consumeLabel]-(18)-[editorPreview]-(4)-[createLabel]",
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
        
        guard let vImage = self.viewerPreview?.image else {return}
        var size = vImage.size;
        self.alignHeightToWidth(view:self.viewerPreview!, ratio: size.height/size.width);
        guard let eImage = self.editorPreview?.image else {return}
        size = eImage.size;
        self.alignHeightToWidth(view:self.editorPreview!, ratio: size.height/size.width);
        
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
