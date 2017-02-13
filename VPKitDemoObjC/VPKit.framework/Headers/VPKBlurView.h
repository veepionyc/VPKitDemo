//
//  VPKBlurView.h
//  VPKit
//
//  Created by jonathan on 01/08/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VPKBlurView : UIView
@property (nonatomic, strong) UIImage* image;
@property (nonatomic, strong) UIView* contentView;
- (instancetype)initWithStyle:(UIBlurEffectStyle)style;
- (instancetype)initWithFrame:(CGRect)frame style:(UIBlurEffectStyle)style;

@end
