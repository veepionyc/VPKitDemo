//
//  VPKWebView.h
//  VPKit
//
//  Created by jonathan on 30/07/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <WebKit/WebKit.h>
#import "VPKConstants.h"
@protocol VPKWebViewDelegate <NSObject>
- (void)webViewDidFinishLoading:(WKWebView*)webView;
- (void)webViewDidStartLoading:(WKWebView*)webView;
- (void)webViewTitleChanged:(WKWebView*)webView;
- (void)webViewURLChanged:(WKWebView*)webView;
- (void)webViewTouched:(WKWebView*)webView;
- (BOOL)shouldGoBackToDefault:(WKWebView*)webView;
#ifdef WEB_SEARCHBOX_BUGFIX
- (void)webViewSearchBoxLocated:(WKWebView*)webView;
#endif

@end
@interface VPKWebView : WKWebView

@property (nonatomic, weak) id<VPKWebViewDelegate> delegate;
@property (nonatomic, strong) NSURL* defaultURL;


@end
