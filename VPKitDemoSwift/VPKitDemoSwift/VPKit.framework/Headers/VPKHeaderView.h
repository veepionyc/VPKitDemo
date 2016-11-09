//
//  VPKHeaderView.h
//  VPKit
//
//  Created by jonathan on 08/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKVeepView.h"
@class VPKHeaderView;

@protocol VPKHeaderViewDelegate <NSObject>

- (void)headerViewTouched:(VPKHeaderView*)view;
@end
@interface VPKHeaderView : UICollectionReusableView
@property (nonatomic, weak) VPKVeepView* veepView;
@property (nonatomic, strong) NSString* message;
@property (nonatomic, weak) id<VPKHeaderViewDelegate>delegate;
- (void)hideLabel;
- (void)showLabel;
@end
