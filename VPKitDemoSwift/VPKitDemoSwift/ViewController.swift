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
    
    deinit {
        self.stopListening()
    }
    
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
        self.startListening()
        
    }
    
    //MARK: - configuration
    
    func configureImageButton() {
        self.view.addSubview(self.imageButton)
    }
    
    func configurePreview() {
        guard let image = UIImage.init(named: "KrispyGlas") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepID:"674")
        self.preview.image = previewImage;
        /*
         setting the delegate is OPTIONAL - if it is unset, default behaviour handles presenting and dismissing
         */
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
        /*
         invoking the VPKVeepEditor
         
         set the editor's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
         
         */
        guard let image = self.imageButton.image else {return}
        guard let vpEditor = VPKit.editor(with: image, from: self.imageButton) else {return}
        vpEditor.delegate = self
        vpEditor.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
        self.present(vpEditor, animated: true, completion: nil)
        
    }
    
    func vpkPreviewTouched(_ preview:VPKPreview, image:VPKImage){
        /*
         invoking the VPKVeepViewer
         
         set the viewer's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
         
         this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default
         */
        guard let viewer = VPKit.viewer(with: image, from: preview) else {return}
        viewer.delegate = self
        viewer.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
        preview.hideIcon()
        self.present(viewer, animated: true, completion: nil)
    }
    
    //MARK: - VPKViewController delegate functions
    
    /*
     delegate methods for VPKVeepViewer
     
     */
    
    func veepViewer(_ viewer: VPKVeepViewer, didFinishViewingWithInfo info: [AnyHashable : Any]?) {
        
        // the veep object can be read from info["veep"] if required

        self.dismiss(animated: true, completion:  {
            self.preview.showIcon(true)
        })
    }
    
    func veepViewerDidCancel(_ viewer: VPKVeepViewer) {
        self.dismiss(animated: true, completion: nil)
    }
    
    /*
     delegate mathods for VPKVeepEditor
     
     */
    
    func veepEditor(_ editor: VPKVeepEditor, didPublishVeep veepID: String) {
        self.dismiss(animated: true, completion: nil)
    }
    
    func veepEditorDidCancel(_ editor: VPKVeepEditor) {
        self.dismiss(animated: true, completion: nil)
    }
    
    //MARK: Error handling
    
    /**
     Error handling
     
     
     @param notification NSNotification with userInfo dictionary containing a single item: the NSError at userInfo[VPKErrorKey].
     
     
     @discussion
     
     To propagate error notifications to the host app, call:
     [VPKit setForwardErrorNotifications:YES]
     
     if notifications are not forwarded, they are handled by the SDK with user-facing alerts where appropriate.
     
     */
    
    func errorReceived(notification: NSNotification) {
        guard let error: NSError = notification.userInfo?[VPKErrorKey] as! NSError? else {return}
        UIAlertController.vpk_presentAlertWithError(error)
    }
    
    func startListening() {
        NotificationCenter.default.addObserver(self, selector: #selector(errorReceived), name: NSNotification.Name(rawValue: VPKErrorNotification), object: nil)
    }
    
    func stopListening() {
        NotificationCenter.default.removeObserver(self)
    }

}

