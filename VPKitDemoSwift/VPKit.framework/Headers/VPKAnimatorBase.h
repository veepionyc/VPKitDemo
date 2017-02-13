//
//  TransitionAnimationBase.h
//  Foundry
//
//  Created by jonathan on 04/09/2014.
//  Copyright (c) 2014 Foundry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
    Abstract base class for Transition Animation objects
*/

typedef NS_ENUM(NSInteger, WNAnimationType) {
    WNAnimationTypeNone = 0,
    WNAnimationTypePresent = 1 << 0,
    WNAnimationTypeDismiss = 1 << 1,
    WNAnimationTypePush = 1 << 2,
    WNAnimationTypePop = 1 << 3
    
};

@protocol VPKTransitionAnimationProtocol <NSObject>

@property (nonatomic, assign) WNAnimationType type;

@end

@interface VPKAnimatorBase : NSObject <VPKTransitionAnimationProtocol, UIViewControllerAnimatedTransitioning>

@property (nonatomic, strong) id<UIViewControllerContextTransitioning> context;
@property (nonatomic, weak) UIView* containerView;
@property (nonatomic, assign) WNAnimationType type;
@property (nonatomic, weak) UIViewController* toVC;
@property (nonatomic, weak) UIViewController* fromVC;
@property (nonatomic, weak) UIView* toView;
@property (nonatomic, weak) UIView* fromView;

- (void)setupPropertiesForContext:( id <UIViewControllerContextTransitioning> ) transitionContext;
@end
