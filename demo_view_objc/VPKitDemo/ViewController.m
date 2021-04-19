//
//  ViewController.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import "ViewController.h"
#import "ViewController_AutoLayout.h"
#import <VPKit/VPKit.h>


@interface ViewController ()<VPKPreviewPassThroughDelegate>
@property (nonatomic, strong) VPKVeepViewer* vpViewer;
@property (nonatomic, strong) VPKVeepEditor* vpEditor;


@end

@implementation ViewController




#pragma mark - viewController lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    self.versionLabel.text = [VPKit sdkVersion];
    [self configureViewer1WithTestVideo];
    [self configureViewer2];
    [self configureConstraints];
    self.viewerPreview1.passThroughDelegate = self;
    self.viewerPreview2.passThroughDelegate = self;
    self.constraints = [[NSMutableArray alloc] init];

    

}

- (BOOL)shouldAutorotate {
    return NO;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

#pragma mark - configuration

- (void)configureViewer1WithTestUrl {
    
    UIImage* image = [UIImage imageNamed:@"stock_photo"];
    //    NSURL* imageURL = [NSURL URLWithString:@"https://phieagles.akamaized.net//PHI/videos/dct/video_audio/2017/12-December/171204_PP_WentzWEB_1-500k.mp4"];

    NSURL* imageURL = [NSURL URLWithString:@"https://raw.githubusercontent.com/veepionyc/VPKitDemo/master/VPKitDemoObjC/VPKitDemo/Assets.xcassets/stock_photo.imageset/photo-1468818461933-b1d79f62434e.jpg"];
    VPKImage* vpkImage = [[VPKImage alloc] initWithImage:image url:imageURL];
    
    //optional parameters
    vpkImage.mediaIdentifier = @"mediaIdentifier";
    vpkImage.customData = @{@"customKey":@"customString"};
    
    vpkImage = [[VPKImage alloc] initWithImage:image url:imageURL];
    self.viewerPreview1.image = vpkImage;
}


- (void)configureViewer1WithTestVideo {
    
    UIImage* image = [UIImage imageNamed:@"tomcruise"];
    NSURL* contentURL = [NSURL URLWithString:@"youtube://ITjsb22-EwQ"];

    VPKImage* vpkImage = [[VPKImage alloc] initWithImage:image url:contentURL];
    
    //optional parameters
    vpkImage.mediaIdentifier = @"mediaIdentifier";
    vpkImage.customData = @{@"customKey":@"customString"};
    
    self.viewerPreview1.image = vpkImage;
    self.viewerPreview1.autoplay = YES;
}


- (void)configureViewer2 {
    UIImage* image = [UIImage imageNamed:@"KrispyGlas"];
    image = [[VPKImage alloc] initWithImage:image veepId:@"1787"];
    self.viewerPreview2.image = image;
}

#pragma mark - example pass-through delegate. Relays UITapGestureRecongizer response in the event a Veep is not available.

- (void)vpkPreview:(VPKPreview *)preview passedThroughTap:(UITapGestureRecognizer *)tapGestureRecognizer {
    //NSLog(@"tapped %@",tapGestureRecognizer);
}


@end
