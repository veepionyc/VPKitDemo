//
//  VPKWebContainerViewModel.h
//  VPKit
//
//  Created by jonathan on 29/08/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKConstants.h"

@interface VPKWebContainerViewModel : NSObject
@property (nonatomic, strong) NSNumber* isShowingGoogle;
@property (nonatomic, strong) NSURL* googleURL;
@property (nonatomic, strong) NSURL* amazonURL;
@property (nonatomic, strong) NSURLRequest* googleRequest;
@property (nonatomic, strong) NSURLRequest* amazonRequest;
@property (nonatomic, strong, readonly) NSString* amazonSearchHeaderText;
@property (nonatomic, strong, readonly) NSString* googleSearchHeaderText;


#ifdef WEB_SEARCHBOX_BUGFIX
//@property (nonatomic, assign) BOOL googleSearchBoxLocated;
//@property (nonatomic, assign) BOOL amazonSearchBoxLocated;
#endif

@end
