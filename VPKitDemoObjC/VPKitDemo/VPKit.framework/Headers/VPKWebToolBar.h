//
//  VPKWebToolBar.h
//  VPKit
//
//  Created by jonathan on 29/07/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKNabBarButtonArrowItem.h"
#import "VPKConstants.h"


@interface VPKWebToolBar : UIView
@property (nonatomic, assign) BOOL useCloseButton;
- (void)reset;
@end
