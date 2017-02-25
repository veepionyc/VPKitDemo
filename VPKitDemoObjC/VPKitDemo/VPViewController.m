//
//  ViewController.m
//  VPKitDemo
//
//  Created by jonathan on 01/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "VPViewController.h"
#import "Common.h"

@import AVFoundation;
@import AVKit;
#import <VPKit/VPKit.h>



@interface VPViewController ()
<
VPKVeepViewerDelegate
, VPKVeepEditorDelegate
, VPKPreviewDelegate
>

@property (nonatomic, strong) VPKVeepViewer* vpViewer;
@property (nonatomic, strong) VPKVeepEditor* vpEditor;

@property (nonatomic, strong) IBOutlet VPKPreview* viewerPreview;
@property (nonatomic, strong) IBOutlet VPKPreview* editorPreview;
@property (nonatomic, strong) IBOutlet UILabel* consumeLabel;
@property (nonatomic, strong) IBOutlet UILabel* createLabel;
@property (nonatomic, strong) IBOutlet UILabel* titleLabel;

@end

@implementation VPViewController




#pragma mark - viewController lifecycle

- (void)viewDidLoad {
    [super viewDidLoad];
    [VPKit setProduction:NO];
    [VPKit setEmail:@"fake@email.com"];
    [self configureViewerWithTestImage];
    [self configureEditor];
    [self configureConstraints];
    
}



#pragma mark - configuration



- (void)configureViewerWithTestImage {
    UIImage* image = [UIImage imageNamed:@"KrispyGlas"];
    image = [[VPKImage alloc] initWithImage:image veepID:@"560"];
    self.viewerPreview.image = image;
}

- (void)configureViewerWithTestVideo {
    UIImage* image = [UIImage imageNamed:@"tomcruise"];
    image = [[VPKImage alloc] initWithImage:image veepID:@"680"];
    self.viewerPreview.image = image;
    
}


- (void)configureEditor {
    UIImage* image = [UIImage imageNamed:@"stock_photo"];
    image = [[VPKImage alloc] initWithImage:image veepID:nil];
    self.editorPreview.image = image;
    /*
     for the editor example, we'll set an optional delegate.
     */
    self.editorPreview.delegate = self;
}




#pragma mark - VPKPreview delegate


- (void)vpkPreviewTouched:(VPKPreview *)preview image:(VPKImage*)image {
    
    [preview hideIcon];
    
    if ([preview isEqual:self.viewerPreview]) {
        [self invokeViewer:image fromView:preview];
    } else {
        [self invokeEditor:image fromView:preview];
    }
}

- (void)invokeViewer:(VPKImage*)image fromView:(UIView*)view {
    
    /*
     invoking the VPKVeepViewer
     
     set the viewer's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
     
     this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default
     
     */
    
    
    self.vpViewer =  [VPKit viewerWithImage:image
                                   fromView:view];
    self.vpViewer.delegate = self;
    self.vpViewer.modalPresentationStyle = UIModalPresentationOverFullScreen;
    [self presentViewController:self.vpViewer animated:YES completion:nil];
    
}

- (void)invokeEditor:(VPKImage*)image fromView:(UIView*)view {
    
    /*
     
     invoking the VPKVeepEditor
     
     
     set the editor's transitioning delegate to a custom transitioning object (or nil) to override supplied transition animations
     
     this code is all OPTIONAL - if you don't set the delegate on VPKPreview, presenting and dismissing behaviour occurs as a default. However, at some point before invoking the editor, users need to be authenticated.
     
     */
    __weak typeof(self) weakself = self;    [VPKit authenticateWithEmail:@"public_test_2_4_6@example.com" completion:^(BOOL success, NSInteger responseCode, NSError * _Nonnull error) {
        __strong typeof(self) strongself = weakself;
        
        /*
         
         Authentication
         
         We authenticate before invoking the editor, as veep creation requires an authenticated user.
         
         Authenticated users are weak (no password) or strong (password-protected)
         
         If responseCode to a weak login attempt is 401 (unauthorised), we can make a similar call for strong authentication with a password.
         
         User account admin can be an implementation detail in the host app or the Veepio Developer control panel.
         
         */
        
        
        if (success) {
            strongself.vpEditor =  [VPKit editorWithImage:image
                                                 fromView:view];
            strongself.vpEditor.delegate = self;
            strongself.vpEditor.modalPresentationStyle = UIModalPresentationOverFullScreen;
            [strongself presentViewController:strongself.vpEditor animated:YES completion:nil];
        } else {
            NSLog(@"%@",error);
        }
    }];
    
    
}


#pragma mark - VPKViewController delegate

/*
 example delegate methods for VPKVeepViewer
 
 */

- (void)veepViewer:(VPKVeepViewer *)viewer didFinishViewingWithInfo:(NSDictionary *)info {
    VPKPublicVeep* pVeep = info[@"veep"];
    NSLog(@"%s %@",__func__, pVeep);
    [self dismissViewControllerAnimated:YES completion:^{
        [self.viewerPreview showIcon];
    }];
}

- (void)veepViewerDidCancel:(VPKVeepViewer *)viewer {
    NSLog(@"%s",__func__);
    [self dismissViewControllerAnimated:YES completion:nil];
}

/*
 example delegate mathods for VPKVeepEditor
 
 */

- (void)veepEditor:(VPKVeepEditor *)editor didPublishVeep:(NSString *)veepID  {
    NSLog(@"%s %@",__func__,veepID);
    [VPKit requestVeep:veepID completionBlock:
     ^(VPKPublicVeep * _Nullable veep, NSError * _Nullable error) {
         NSLog(@"%@",veep);
     }];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)veepEditorDidCancel:(VPKVeepEditor *)editor {
    NSLog(@"%s",__func__);
    [self dismissViewControllerAnimated:YES completion:nil];
}


#pragma mark - (layout boilerplate for the demo app, not relevant to the SDK)


- (void)configureConstraints {
    NSDictionary* dict = NSDictionaryOfVariableBindings(_titleLabel,_viewerPreview,_consumeLabel,_createLabel,_editorPreview);
    for (UIView* view in dict.allValues) {
        view.translatesAutoresizingMaskIntoConstraints = NO;
    };
    
    CGFloat vMargin = 50;
    NSArray* formats =
    @[
      @"H:|-(vMargin)-[_titleLabel]-(vMargin)-|",
      @"H:|-(vMargin)-[_viewerPreview]-(vMargin)-|",
      @"H:|-(vMargin)-[_consumeLabel]-(vMargin)-|",
      @"H:|-(vMargin)-[_editorPreview]-(vMargin)-|",
      @"H:|-(vMargin)-[_createLabel]-(vMargin)-|",
      @"V:|-(38)-[_titleLabel]-(18)-[_viewerPreview]-(4)-[_consumeLabel]-(18)-[_editorPreview]-(4)-[_createLabel]"
      ];
    
    
    for (NSString* format in formats) {
        [self.view addConstraints:
         [NSLayoutConstraint constraintsWithVisualFormat:format
                                                 options:0
                                                 metrics:@{@"vMargin":@(vMargin)}
                                                   views:dict]];
    }
    CGSize size = self.viewerPreview.image.size;
    if (size.width > 0)
        [self alignHeightToWidth:self.viewerPreview ratio: size.height/size.width];
    size = self.editorPreview.image.size;
    if (size.width > 0)
        [self alignHeightToWidth:self.editorPreview ratio: size.height/size.width];
    
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
