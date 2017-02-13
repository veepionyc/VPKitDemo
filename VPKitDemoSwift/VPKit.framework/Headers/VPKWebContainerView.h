//
//  VPKWebContainerView.h
//  VPKit
//
//  Created by jonathan on 29/08/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKWebContainerViewModel.h"
#import "VPKWebView.h"

@import WebKit;

@interface VPKWebContainerView : UIView

@property (nonatomic, strong) NSNumber* isShowingGoogle;
@property (nonatomic, weak, readonly) WKWebView* webView;



- (instancetype)initWithModel:(VPKWebContainerViewModel*)model delegate:(id <VPKWebViewDelegate>)delegate;

- (void)showGoogleView;
- (void)showAmazonView;

- (void)reset;
- (void)loadDefaultRequests;

- (void)loadRequest:(NSURLRequest*)request;

@end
