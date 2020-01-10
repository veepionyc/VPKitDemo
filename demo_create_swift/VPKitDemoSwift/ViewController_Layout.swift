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
        for view in self.view.subviews  {
            view.translatesAutoresizingMaskIntoConstraints = false
            view.leftAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.leftAnchor, constant: 20).isActive = true
            view.rightAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.rightAnchor, constant:-20).isActive = true
            if view is UILabel {
                view.heightAnchor.constraint(equalToConstant: 30).isActive = true
            }
        }
        
        var guides = [UILayoutGuide]()
        for idx in 0...3 {
            guides.append(UILayoutGuide())
            self.view.addLayoutGuide(guides[idx])
            guides[0].heightAnchor.constraint(equalTo: guides[idx].heightAnchor).isActive = true
        }
        NSLayoutConstraint.activate( [
            guides[0].topAnchor.constraint(equalTo: self.view.safeAreaLayoutGuide.topAnchor)
            ,titleLabel.topAnchor.constraint(equalTo: guides[0].bottomAnchor)
            ,guides[1].topAnchor.constraint(equalTo: titleLabel.bottomAnchor)
            ,viewerPreview.topAnchor.constraint(equalTo: guides[1].bottomAnchor)
            ,consumeLabel.topAnchor.constraint(equalTo: viewerPreview.bottomAnchor)
            ,guides[2].topAnchor.constraint(equalTo: consumeLabel.bottomAnchor)
            ,editorPreview.topAnchor.constraint(equalTo: guides[2].bottomAnchor)
            ,createLabel.topAnchor.constraint(equalTo: editorPreview.bottomAnchor)
            ,guides[3].topAnchor.constraint(equalTo: createLabel.bottomAnchor)
            ,versionLabel.topAnchor.constraint(equalTo: guides[3].bottomAnchor)
            ,versionLabel.bottomAnchor.constraint(equalTo:self.view.safeAreaLayoutGuide.bottomAnchor)
        ])

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
                attribute: NSLayoutConstraint.Attribute.height,
                relatedBy: NSLayoutConstraint.Relation.equal,
                toItem: view,
                attribute: NSLayoutConstraint.Attribute.width,
                multiplier: ratio, constant: 0)
        )
    }
}

