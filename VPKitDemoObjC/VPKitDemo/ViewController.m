//
//  ViewController.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "ViewController.h"
#import "Common.h"

@import AVFoundation;
@import AVKit;
#import <VPKit/VPKit.h>


@interface ViewController ()
<
  VPKVeepViewerDelegate
, VPKVeepEditorDelegate
, VPKPreviewDelegate
>

@property (nonatomic, strong) VPKVeepViewer* vpViewer;
@property (nonatomic, strong) VPKVeepEditor* vpEditor;
@property (nonatomic, strong) UIImageView* imageButton;
@property (nonatomic, strong) VPKPreview* vpkPreview;
@property (nonatomic, strong) UILabel* consumeLabel;
@property (nonatomic, strong) UILabel* createLabel;
@property (nonatomic, strong) UILabel* titleLabel;

@end

@implementation ViewController

#pragma mark - lazy initialisers



-(VPKPreview*)vpkPreview {
    if (!_vpkPreview) {
        _vpkPreview = [[VPKPreview alloc] init];
        _vpkPreview.translatesAutoresizingMaskIntoConstraints = NO;
    }
    return _vpkPreview;
}

- (UIImageView*)imageButton {
    if (!_imageButton) {
        UIButton* button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.translatesAutoresizingMaskIntoConstraints = NO;
        [button addTarget:self
                   action:@selector(imageViewButtonPushed:)
         forControlEvents:UIControlEventTouchUpInside];
        
        _imageButton = [[UIImageView alloc] initWithFrame:CGRectZero];
        _imageButton.translatesAutoresizingMaskIntoConstraints = NO;
        _imageButton.image = [UIImage imageNamed:@"stock_photo"];
        _imageButton.contentMode = UIViewContentModeScaleAspectFit;
        _imageButton.userInteractionEnabled = YES;
        [_imageButton addSubview:button];
        
        NSArray* formats =
        @[
          @"V:|[button]|",
          @"H:|[button]|"
          ];
        
        for (NSString* format in formats) {
            [_imageButton addConstraints:
             [NSLayoutConstraint constraintsWithVisualFormat:format
                                                     options:0 metrics:@{}
                                                       views:@{@"button":button}]];
        }
    }
    return _imageButton;
}


#pragma mark - viewController lifecycle

- (void)dealloc {
    [self stopListening];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self configureLabels];
    [self configureVpkPreview];
    [self configureImageButton];
    [self configureConstraints];
    [self startListening];
}

#pragma mark - configuration

- (void)configureLabels {
    self.createLabel = [self newLabel:@"Create Veep"];
    self.consumeLabel = [self newLabel:@"Consume Veep"];
    self.titleLabel = [self newLabel:@"VEEPIO SDK Demo"];
}

- (UILabel*)newLabel:(NSString*)text {
    UILabel* label = [[UILabel alloc] init];
    label.translatesAutoresizingMaskIntoConstraints = NO;
    label.textAlignment = NSTextAlignmentCenter;
    label.font = [UIFont systemFontOfSize:14];
    label.text = text;
    [self.view addSubview:label];
    return label;
}

- (void)configureImageButton {
    [self.view addSubview:self.imageButton];
}

- (void)configureVpkPreview {
    [self.view addSubview:self.vpkPreview];
    UIImage* image = [UIImage imageNamed:@"KrispyGlas"];
    image = [[VPKImage alloc] initWithImage:image veepID:@"674"];
    self.vpkPreview.image = image;
    
    /*
     setting the delegate is OPTIONAL - if it is unset, default behaviour handles presenting and dismissing
     */
    
    self.vpkPreview.delegate = self;
}

- (void)configureConstraints {
    NSDictionary* dict = NSDictionaryOfVariableBindings(_titleLabel,_vpkPreview,_consumeLabel,_imageButton,_createLabel);
    CGFloat vMargin = 50;
    NSArray* formats =
    @[
     @"H:|-(vMargin)-[_titleLabel]-(vMargin)-|",
     @"H:|-(vMargin)-[_vpkPreview]-(vMargin)-|",
     @"H:|-(vMargin)-[_consumeLabel]-(vMargin)-|",
     @"H:|-(vMargin)-[_imageButton]-(vMargin)-|",
     @"H:|-(vMargin)-[_createLabel]-(vMargin)-|",
     @"V:|-(38)-[_titleLabel]-(18)-[_vpkPreview]-(4)-[_consumeLabel]-(18)-[_imageButton]-(4)-[_createLabel]"
     ];
    
    
    for (NSString* format in formats) {
        [self.view addConstraints:
         [NSLayoutConstraint constraintsWithVisualFormat:format
                                                 options:0
                                                 metrics:@{@"vMargin":@(vMargin)}
                                                   views:dict]];
    }
    CGSize size = self.vpkPreview.image.size;
    [self alignHeightToWidth:self.vpkPreview ratio: size.height/size.width];
    size = self.imageButton.image.size;
    [self alignHeightToWidth:self.imageButton ratio: size.height/size.width];
    
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

#pragma mark - interactions


- (void)imageViewButtonPushed:(UIButton*)sender {
    /*
     invoking the VPKVeepEditor
     
     set the editor's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations

     */
    self.vpEditor = [VPKit editorWithImage:self.imageButton.image
                                  fromView:self.imageButton];
    if (self.vpEditor) {
        self.vpEditor.delegate = self;
        self.vpEditor.modalPresentationStyle = UIModalPresentationOverFullScreen;
        [self presentViewController:self.vpEditor animated:YES completion:nil];
    }
}


#pragma mark - VPKPreview delegate


- (void)vpkPreviewTouched:(VPKPreview *)preview image:(VPKImage*)image {
    /*
     invoking the VPKVeepViewer
     
     set the viewer's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
     
     this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default
     
     */
    self.vpViewer = [VPKit viewerWithImage:image
                                  fromView:preview];
    self.vpViewer.delegate = self;
    self.vpViewer.modalPresentationStyle = UIModalPresentationOverFullScreen;
    [preview hideIcon];
    [self presentViewController:self.vpViewer animated:YES completion:nil];
}

#pragma mark - VPKViewController delegate

/*
    delegate methods for VPKVeepViewer
 
 */

- (void)veepViewer:(VPKVeepViewer *)viewer didFinishViewingWithInfo:(NSDictionary *)info {
    VPKPublicVeep* pVeep = info[@"veep"];
    NSLog(@"%s %@",__func__, pVeep);
    [self dismissViewControllerAnimated:YES completion:^{
        [self.vpkPreview showIcon];
    }];
}

- (void)veepViewerDidCancel:(VPKVeepViewer *)viewer {
    NSLog(@"%s",__func__);
    [self dismissViewControllerAnimated:YES completion:nil];
}

/*
    delegate mathods for VPKVeepEditor
 
 */

- (void)veepEditor:(VPKVeepEditor *)editor didPublishVeep:(NSString *)veepID  {
    [VPKit requestVeep:veepID completionBlock:
     ^(VPKPublicVeep * _Nullable veep, NSError * _Nullable error) {
         NSLog(@"%@",veep);
     }];
    NSLog(@"%s %@",__func__,veepID);
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)veepEditorDidCancel:(VPKVeepEditor *)editor {
    NSLog(@"%s",__func__);
    [self dismissViewControllerAnimated:YES completion:nil];
}


#pragma mark - error handling

/**
 Error handling

 
 @param notification NSNotification with userInfo dictionary containing a single item: the NSError at userInfo[VPKErrorKey].
 
 
 @discussion
 
 To propagate error notifications to the host app, call:
 [VPKit setForwardErrorNotifications:YES]  
 
 if notifications are not forwarded, they are handled by the SDK with user-facing alerts where appropriate.
 
 */

- (void)errorReceived:(NSNotification*)notification {
    NSError* error = notification.userInfo[VPKErrorKey];
    if (!error) return;
    [UIAlertController vpk_presentAlertWithError:error];
}

- (void)startListening {
    SEL selector = NSSelectorFromString(VPKErrorNotification);
    [NSNotificationCenter.defaultCenter addObserver:self
                                           selector:selector
                                               name:VPKErrorNotification
                                             object:nil];
}

- (void)stopListening {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
