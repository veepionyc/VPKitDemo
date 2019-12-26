//
//  VPKWindow.h
//  VPKUtils
//
//  Created by jonathan on 09/03/2019.
//  Copyright © 2019 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface VPKWindow : UIWindow
@property (nonatomic, strong) UIWindow* presentingWindow;
+ (nullable UIWindow *)findWindow;

@end

NS_ASSUME_NONNULL_END
