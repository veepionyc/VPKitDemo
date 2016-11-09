//
//  WKWebView_UserScripts.h
//  VPKit
//
//  Created by jonathan on 30/07/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <WebKit/WebKit.h>

@interface WKWebView (UserScripts)


- (NSString*)simpleJsCallback;
- (NSString*)simplejs;
- (WKUserScript*)searchBoxLocationScript;
- (WKUserScript*)searchBoxFocussedScript;
- (WKUserScript*)windowTouchStartScript;
@end
