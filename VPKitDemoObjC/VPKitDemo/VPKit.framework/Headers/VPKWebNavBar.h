//
//  WPKWebNavBar.h
//  VPKit
//
//  Created by jonathan on 29/07/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKNabBarButtonArrowItem.h"
#import "VPKConstants.h"
@class VPKWebNavBar;


@interface VPKWebNavBar : UINavigationBar
@property (nonatomic, assign) BOOL useCloseButton;
@property (nonatomic, strong) NSString* title;
@property (nonatomic, assign) VPKViewMode mode;



@end
