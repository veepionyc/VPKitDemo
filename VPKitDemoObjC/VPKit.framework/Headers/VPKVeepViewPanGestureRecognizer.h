//
//  VPKVeepViewPanGestureRecognizer.h
//  Pods
//
//  Created by jonathan on 17/07/2016.
//
//

#import <UIKit/UIKit.h>
@class VPKVeepViewPanGestureRecognizer;

@protocol VPKVeepViewPanGestureRecognizerDelegate <UIGestureRecognizerDelegate>
- (void)isPanning:(VPKVeepViewPanGestureRecognizer*)panGR percentChange:(CGFloat)change;
- (void)didFinishPanning:(VPKVeepViewPanGestureRecognizer*)panGR shouldDismiss:(BOOL)dismiss;


@end

@interface VPKVeepViewPanGestureRecognizer : UIPanGestureRecognizer
@property (nonatomic, weak) id<VPKVeepViewPanGestureRecognizerDelegate>delegate;

@end
