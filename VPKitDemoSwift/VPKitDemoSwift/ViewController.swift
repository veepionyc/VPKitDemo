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
    , VPKVeepEditorDelegate
    , VPKVeepViewerDelegate
    , VPKPreviewDelegate
{
    
    //MARK: - properties
    
    lazy var titleLabel: UILabel = {
        return ViewController.newLabel(text: "VEEPIO SDK Demo")
    }()
    
    lazy var  consumeLabel: UILabel = {
        return ViewController.newLabel(text: "Consume Veep")
        
    }()
    
    lazy var  createLabel: UILabel = {
        return  ViewController.newLabel(text: "Create Veep")
    }()
    
    class func newLabel (text: String) -> UILabel {
        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        label.textAlignment = NSTextAlignment.center
        label.font = UIFont.systemFont(ofSize: 14)
        label.text = text
        return label;
    }
    
    lazy var preview: VPKPreview = {
        let preview = VPKPreview()
        preview.translatesAutoresizingMaskIntoConstraints = false
        return preview
    }()
    
    lazy var imageButton: UIImageView = {
        let button = UIButton(type:UIButtonType.custom)
        button.translatesAutoresizingMaskIntoConstraints = false
        button.addTarget(self, action: #selector(imageViewButtonPushed(sender:)), for: UIControlEvents.touchUpInside)
        let imageView = UIImageView(frame:CGRect.zero)
        imageView.translatesAutoresizingMaskIntoConstraints = false
        imageView.image = UIImage.init(named: "stock_photo")
        imageView.contentMode = UIViewContentMode.scaleAspectFit
        imageView.isUserInteractionEnabled = true
        imageView.addSubview(button)
        
        let formats = [
            "V:|[button]|",
            "H:|[button]|"
        ]
        for format in formats {
            imageView.addConstraints(
                NSLayoutConstraint.constraints(withVisualFormat: format,
                                               options:NSLayoutFormatOptions(rawValue:0),
                                               metrics: [:],
                                               views: ["button":button])
            )
        }
        return imageView
    }()
    
    //MARK: - viewController lifecycle
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        //fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.addSubview(self.titleLabel)
        self.view.addSubview(self.consumeLabel)
        self.view.addSubview(self.createLabel)
        self.configurePreview()
        self.configureImageButton()
        self.configureConstraints()
        
    }
    
    //MARK: - configuration
    
    func configureImageButton() {
        self.view.addSubview(self.imageButton)
    }
    
    func configurePreview() {
        guard let image = UIImage.init(named: "KrispyGlas") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepID:"658")
        self.preview.image = previewImage;
        self.preview.delegate = self
        self.view.addSubview(self.preview)
    }
    
   
    func configureConstraints() {
        let views:[String:UIView] =  [
            "titleLabel":self.titleLabel
            ,"consumeLabel":self.consumeLabel
            ,"createLabel":self.createLabel
            ,"preview":self.preview
            ,"imageButton":self.imageButton
            
        ]
        let vMargin = 50;
        let formats =
            [
                "H:|-(vMargin)-[titleLabel]-(vMargin)-|",
                "H:|-(vMargin)-[preview]-(vMargin)-|",
                "H:|-(vMargin)-[consumeLabel]-(vMargin)-|",
                "H:|-(vMargin)-[imageButton]-(vMargin)-|",
                "H:|-(vMargin)-[createLabel]-(vMargin)-|",
                "V:|-(38)-[titleLabel]-(18)-[preview]-(4)-[consumeLabel]-(18)-[imageButton]-(4)-[createLabel]"
        ];
        
        for format in formats {
            self.view.addConstraints(
                NSLayoutConstraint.constraints(withVisualFormat: format,
                                               options:NSLayoutFormatOptions(rawValue:0),
                                               metrics: ["vMargin":vMargin],
                                               views: views)
            )
        }
        
        guard let previewImage = self.preview.image else {return}
        var size = previewImage.size;
        self.alignHeightToWidth(view:self.preview, ratio: size.height/size.width);
        guard let buttonImage = self.imageButton.image else {return}
        size = buttonImage.size;
        self.alignHeightToWidth(view:self.imageButton, ratio: size.height/size.width);
        
    }
    
    func alignHeightToWidth (view:UIView, ratio:CGFloat) {
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
    
    //MARK: - interactions

    func imageViewButtonPushed(sender:UIButton){
        guard let image = self.imageButton.image else {return}
        guard let vpEditor = VPKit.editor(with: image, from: self.imageButton) else {return}
        vpEditor.useVeepLogo = false
        vpEditor.delegate = self
        vpEditor.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
        self.present(vpEditor, animated: true, completion: nil)
        
    }
    
    func vpkPreviewTouched(_ preview:VPKPreview, image:VPKImage){
        guard let viewer = VPKit.viewer(with: image, from: preview) else {return}
        viewer.delegate = self
        viewer.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
        preview.hideIcon()
        self.present(viewer, animated: true, completion: nil)
    }
    
    //MARK: - VPKViewController delegate functions
    
    func veepEditor(_ editor: VPKVeepEditor, didPublishVeep veepID: String) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func veepEditorDidCancel(_ editor: VPKVeepEditor) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func veepViewer(_ viewer: VPKVeepViewer, didFinishViewingWithInfo info: [AnyHashable : Any]?) {
        self.dismiss(animated: true, completion:  {
            self.preview.showIcon(true)
        })
    }
    
    func veepViewerDidCancel(_ viewer: VPKVeepViewer) {
        self.dismiss(animated: true, completion: nil)
    }
}

