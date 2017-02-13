//
//  VPKNabBarButtonArrowItem.h
//  VPKit
//
//  Created by jonathan on 14/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef NS_ENUM(NSInteger, VPKArrowDirection) {
    VPKArrowDirectionNone,
    VPKArrowDirectionLeft,
    VPKArrowDirectionUp,
    VPKArrowDirectionRight,
    VPKArrowDirectionDown,
};

@interface VPKNabBarButtonArrowItem : UIBarButtonItem
@property (nonatomic, assign, readonly) VPKArrowDirection arrowDirection;
//- (instancetype)initWithDirection:(VPKArrowDirection)direction;

- (instancetype)initWithDirection:(VPKArrowDirection)direction target:(id)target action:(SEL)selector;


//- (void)pointUp:(BOOL)animated;
//- (void)pointDown:(BOOL)animated;
@end
