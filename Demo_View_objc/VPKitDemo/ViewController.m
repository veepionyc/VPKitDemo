//
//  ViewController.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "ViewController.h"
#import <VPKit/VPKit.h>


@interface ViewController ()


@property (nonatomic, strong) VPKVeepViewer* vpViewer;
@property (nonatomic, strong) VPKVeepEditor* vpEditor;

@property (nonatomic, strong) IBOutlet VPKPreview* viewerPreview1;
@property (nonatomic, strong) IBOutlet VPKPreview* viewerPreview2;
@property (nonatomic, strong) IBOutlet UILabel* consumeLabel;
@property (nonatomic, strong) IBOutlet UILabel* createLabel;
@property (nonatomic, strong) IBOutlet UILabel* titleLabel;
@property (nonatomic, strong) IBOutlet UILabel* versionLabel;
@end

@implementation ViewController




#pragma mark - viewController lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.versionLabel.text = [VPKit version];
    [self configureViewer1];
    [self configureViewer2];
    [self configureConstraints];

}



#pragma mark - configuration

- (void)configureViewer1 {
    
    UIImage* image = [UIImage imageNamed:@"stock_photo"];
    NSURL* imageURL = [NSURL URLWithString:@"https://raw.githubusercontent.com/veepionyc/VPKitDemo/master/VPKitDemoObjC/VPKitDemo/Assets.xcassets/stock_photo.imageset/photo-1468818461933-b1d79f62434e.jpg"];
    image = [[VPKImage alloc] initWithImage:image url:imageURL];
    self.viewerPreview1.image = image;    
}


- (void)configureViewer2 {
    UIImage* image = [UIImage imageNamed:@"KrispyGlas"];
    image = [[VPKImage alloc] initWithImage:image veepID:@"560"];
    self.viewerPreview2.image = image;
}



#pragma mark - (layout boilerplate for the demo app, not relevant to the SDK)


- (void)configureConstraints {
    NSLog(@"%s",__func__);
    
    NSDictionary* dict = NSDictionaryOfVariableBindings(_titleLabel,_viewerPreview1,_consumeLabel,_createLabel,_viewerPreview2,_versionLabel);
    for (UIView* view in dict.allValues) {
        view.translatesAutoresizingMaskIntoConstraints = NO;
    };
    CGFloat ratio = self.view.bounds.size.height>0?self.view.bounds.size.width/self.view.bounds.size.height:1.0;
    CGFloat vMargin = 80*ratio;
    CGFloat tMargin = self.view.bounds.size.height/20.0;
    NSArray* formats =
    @[
      @"H:|-(vMargin)-[_titleLabel]-(vMargin)-|",
      @"H:|-(vMargin)-[_viewerPreview1]-(vMargin)-|",
      @"H:|-(vMargin)-[_consumeLabel]-(vMargin)-|",
      @"H:|-(vMargin)-[_viewerPreview2]-(vMargin)-|",
      @"H:|-(vMargin)-[_createLabel]-(vMargin)-|",
      @"H:|-(vMargin)-[_versionLabel]-(vMargin)-|",
      
      @"V:|-(tMargin)-[_titleLabel]-(18)-[_viewerPreview1]-(4)-[_consumeLabel]-(18)-[_viewerPreview2]-(4)-[_createLabel]",
      @"V:[_versionLabel]-(8)-|"
      ];
    
    
    for (NSString* format in formats) {
        [self.view addConstraints:
         [NSLayoutConstraint constraintsWithVisualFormat:format
                                                 options:0
                                                 metrics:@{@"vMargin":@(vMargin),@"tMargin":@(tMargin)}
                                                   views:dict]];
    }
    CGSize size = self.viewerPreview1.image.size;
    if (size.width > 0)
        [self alignHeightToWidth:self.viewerPreview1 ratio: size.height/size.width];
    size = self.viewerPreview2.image.size;
    if (size.width > 0)
        [self alignHeightToWidth:self.viewerPreview2 ratio: size.height/size.width];
    
}

- (void)alignHeightToWidth:(UIView*)view ratio:(CGFloat)ratio{
    [view.superview addConstraint:
     [NSLayoutConstraint constraintWithItem:view
                                  attribute:NSLayoutAttributeHeight
                                  relatedBy:NSLayoutRelationEqual
                                     toItem:view
                                  attribute:NSLayoutAttributeWidth
                                 multiplier:ratio
                                   constant:0]];
}


@end
