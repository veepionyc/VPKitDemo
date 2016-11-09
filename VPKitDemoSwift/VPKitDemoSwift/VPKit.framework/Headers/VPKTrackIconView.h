//
//  VPKVeepTrackViewCancelView.h
//  Pods
//
//  Created by jonathan on 01/06/2016.
//
//

#import <UIKit/UIKit.h>
@class VPKTrackIconView;

@protocol VPKTrackIconViewDelegate <NSObject>

- (void)cancelViewTouched:(VPKTrackIconView*)view;
- (void)dollarView:(VPKTrackIconView*)view iconToggled:(BOOL)on;

@end





@interface VPKTrackIconView : UIView
@property (nonatomic, strong) UIColor* color;


@property (nonatomic, weak) id<VPKTrackIconViewDelegate>delegate;

- (instancetype)initWithImage:(UIImage*)image selectedImage:(UIImage*)image;
@end

@interface VPKCancelView : VPKTrackIconView
@end


@interface VPKDollarView : VPKTrackIconView
@end