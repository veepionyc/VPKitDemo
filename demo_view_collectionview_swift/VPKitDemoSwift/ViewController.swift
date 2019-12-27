//
//  CollectionViewController.swift
//  VPKitDemoSwift
//
//  Created by jonathan on 07/09/2018.
//  Copyright © 2018 Veepio. All rights reserved.
//

import UIKit
import VPKit


// MARK: Data

enum media : String {
    case apple1
    ,apple2
    ,apple3
    ,KrispyGlas
    ,stock_photo
    ,tomcruise
    ,tomcruise2
    
    func image()-> UIImage {
        return UIImage.init(named: (self).rawValue)!
    }
    
    func vpkImage()->VPKImage {
        let image = self.image()
        let veepId = self.veepId()
        let vpkimage = VPKImage.init(
             image:image,
            veepId:veepId)
        return vpkimage
    }
    
    func veepId() -> String {
        var veepId = ""
        switch(self){
            
            //stills
        case .apple1,
             .apple2,
             .apple3,
             .stock_photo,
             .KrispyGlas:
            veepId = "1787"
            
            //video
        case .tomcruise,
             .tomcruise2:
            veepId="1788"
        }
        return veepId
    }
}

// MARK: -

class PreviewCell: UICollectionViewCell {
    @IBOutlet weak var preview: VPKPreview!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        preview.invokeViewerForAllImages = true
    }
    
    override func prepareForReuse() {
        preview.reset()
    }
   
    override func layoutSubviews() {
        super.layoutSubviews()
        preview.iconLength =
            preview.bounds.size.width/4
    }
}

// MARK: -

class CollectionViewController: UICollectionViewController, UICollectionViewDelegateFlowLayout {
    
//    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
//        return UIInterfaceOrientationMask.portrait
//    }
//    
    private let previewCell = "PreviewCell"

    let data = [media.apple1, media.apple2, media.apple3, media.KrispyGlas, media.stock_photo, media.tomcruise, media.tomcruise2]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.collectionView?.delegate = self;
        self.collectionView?.contentInset = UIEdgeInsetsMake(10, 10, 10, 10)
        self.navigationItem.title =  "VPKit \(VPKit.sdkVersion())"

    }

    override func willRotate(to toInterfaceOrientation: UIInterfaceOrientation, duration: TimeInterval) {
        self.collectionViewLayout.invalidateLayout()
    }
    
   
    
    // MARK: UICollectionViewDataSource

    override func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }


    override func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 60
    }

    override func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell:PreviewCell = collectionView.dequeueReusableCell(withReuseIdentifier: previewCell, for: indexPath) as! PreviewCell
        let idx: Int = Int(arc4random_uniform(UInt32(data.count)))
        let choice = arc4random_uniform(2)
        let media = data [idx]
        let image = (choice==1) ? media.vpkImage() : media.image()
        cell.preview.image = image
        
        //set to false for a preview to also forwared touches to didSelectItemAt:
        cell.preview.tapGR.cancelsTouchesInView  = false

        return cell
    }

    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
       
        let length = (((self.collectionView?.bounds.size.width)! / 3.0)-16 )
            return  CGSize(width: length, height: length)
        
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        //only if cell.preview.tapGR.cancelsTouchesInView  = false
        print("didselect")
    }


}
