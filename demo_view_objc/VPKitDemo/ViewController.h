//
//  ViewController.h
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKPreview;
@interface ViewController : UIViewController



@property (nonatomic, strong) IBOutlet VPKPreview* viewerPreview1;
@property (nonatomic, strong) IBOutlet VPKPreview* viewerPreview2;
@property (nonatomic, strong) IBOutlet UILabel* consumeLabel;
@property (nonatomic, strong) IBOutlet UILabel* createLabel;
@property (nonatomic, strong) IBOutlet UILabel* titleLabel;
@property (nonatomic, strong) IBOutlet UILabel* versionLabel;
@property (nonatomic, strong) NSMutableArray* constraints;
@end

