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
    
    @IBOutlet var titleLabel: UILabel!
    @IBOutlet var consumeLabel: UILabel!
    @IBOutlet var createLabel: UILabel!
    @IBOutlet var vPreview: VPKPreview!
    @IBOutlet var ePreview: VPKPreview!
    
    
    
    //MARK: - viewController lifecycle
    
    required init?(coder aDecoder: NSCoder)
    {
        super.init(coder: aDecoder)
        //fatalError("init(coder:) has not been implemented")
    }

    override func viewDidLoad()
    {
        super.viewDidLoad()
        VPKit.setProduction(false)
        VPKit.setEmail("fake@email.com");
        self.configureViewerWithTestImage()
        self.configureEditor()
        self.configureConstraints()
        
    }
    
    

    //MARK: - configuration
    
    func configureViewerWithTestImage()
    {
        guard let image = UIImage.init(named: "KrispyGlas") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepID:"560")
        self.vPreview.image = previewImage
    }
    
    func configureViewerWithTestVideo()
    {
        guard let image = UIImage.init(named: "tomcruise") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepID:"680")
        self.vPreview.image = previewImage
    }
    
    func configureEditor()
    {
        guard let image = UIImage.init(named: "stock_photo") else {return}
        let previewImage: VPKImage = VPKImage(image: image, veepID:nil)
        self.ePreview.image = previewImage
        /*
         for the editor example, we'll set an optional delegate.
         */
        self.ePreview.delegate = self
    }
    
    
    
    
    //MARK: -  VPKPreview delegate
    
    func vpkPreviewTouched(_ preview:VPKPreview, image:VPKImage)
    {
        if preview.isEqual(self.vPreview) {
            self.invokeViewer(image: image, fromView: preview)
        } else {
            self.invokeEditor(image: image, fromView: preview)
        }
    }

    func invokeViewer(image:VPKImage, fromView view:UIView)
    {
        
        /*
         invoking the VPKVeepViewer
         
         set the viewer's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
         
         this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default
         */
        
        
        guard let vpViewer = VPKit.viewer(with: image, from: view) else { return }
        vpViewer.delegate = self
        vpViewer.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
        self.present(vpViewer, animated: true, completion: nil)
    }
    
    func invokeEditor(image:VPKImage, fromView view:UIView)
    {
        
        
        /*
         
         invoking the VPKVeepEditor
         
         
         set the editor's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
         
         this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default. However, at some point before invoking the editor, user authentication needs to be dealt with.
         
         */
        
        
        VPKit.authenticate(withEmail: "public_test_2_4_6@example.com")
        {
            [weak self] (success, responseCode, error) in
            
            /*
             
             Authentication
             
             We authenticate before invoking the editor, as veep creation requires an authenticated user.
             
             Authenticated users are weak (no password) or strong (password-protected)
             
             If responseCode to a weak login attempt is 401 (unauthorised), we can make a similar call for strong authentication with a password.
             
             User account admin can be an implementation detail in the host app or the Veepio Developer control panel.
             
             */
            
            if (success) {
                guard let vpEditor = VPKit.editor(with: image, from: view) else { return }
                vpEditor.delegate = self
                vpEditor.modalPresentationStyle = UIModalPresentationStyle.overFullScreen
                self?.present(vpEditor, animated: true, completion: nil)

            } else {
                print("\(error)")
            }
        }
        
        
    }
    
    



    
    
    
    //MARK: - VPKViewController delegate functions
    
    /*
     delegate methods for VPKVeepViewer
     
     */
    
    func veepViewer(_ viewer: VPKVeepViewer, didFinishViewingWithInfo info: [AnyHashable : Any]?)
    {
        
        // the veep object can be read from info["veep"] if required

        self.dismiss(animated: true, completion:  {
            self.vPreview?.showIcon(true)
        })
    }
    
    func veepViewerDidCancel(_ viewer: VPKVeepViewer) {
        self.dismiss(animated: true, completion: nil)
    }
    
    /*
     delegate mathods for VPKVeepEditor
     
     */
    
    func veepEditor(_ editor: VPKVeepEditor, didPublishVeep veepID: String)
    {
        /*
         demo method to get a publicVeep object from a veepID
         */
        VPKit.requestVeep(veepID) { (veep, error) in
            if ((veep) != nil){
                print("\(veep)")
            } else {
                print("\(error)")
            }
        }
        self.dismiss(animated: true, completion: nil)
    }
    
    func veepEditorDidCancel(_ editor: VPKVeepEditor)
    {
        self.dismiss(animated: true, completion: nil)
    }
    
    
    //MARK: - layout boilerplate
    
    
    func configureConstraints()
    {
        let views:[String:UIView] =  [
            "titleLabel":self.titleLabel!
            ,"consumeLabel":self.consumeLabel!
            ,"createLabel":self.createLabel!
            ,"vPreview":self.vPreview!
            ,"ePreview":self.ePreview!
            
        ]
        for (_,view) in views {
            view.translatesAutoresizingMaskIntoConstraints = false
        }
        
        let vMargin = 50;
        let formats =
            [
                "H:|-(vMargin)-[titleLabel]-(vMargin)-|",
                "H:|-(vMargin)-[vPreview]-(vMargin)-|",
                "H:|-(vMargin)-[consumeLabel]-(vMargin)-|",
                "H:|-(vMargin)-[ePreview]-(vMargin)-|",
                "H:|-(vMargin)-[createLabel]-(vMargin)-|",
                "V:|-(38)-[titleLabel]-(18)-[vPreview]-(4)-[consumeLabel]-(18)-[ePreview]-(4)-[createLabel]"
        ];
        
        for format in formats {
            self.view.addConstraints(
                NSLayoutConstraint.constraints(withVisualFormat: format,
                                               options:NSLayoutFormatOptions(rawValue:0),
                                               metrics: ["vMargin":vMargin],
                                               views: views)
            )
        }
        
        guard let vImage = self.vPreview?.image else {return}
        var size = vImage.size;
        self.alignHeightToWidth(view:self.vPreview!, ratio: size.height/size.width);
        guard let eImage = self.ePreview?.image else {return}
        size = eImage.size;
        self.alignHeightToWidth(view:self.ePreview!, ratio: size.height/size.width);
        
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

