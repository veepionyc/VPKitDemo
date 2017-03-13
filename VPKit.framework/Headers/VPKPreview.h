//
//  VPKImageView.h
//  VPKit
//
//  Created by jonathan on 07/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKImage;
@class VPKPreview;

@class VPKPreview;
@protocol VPKPreviewDelegate <NSObject>

- (void)vpkPreviewTouched:(nonnull VPKPreview*)preview image:(nonnull VPKImage*)image;
@end

@interface VPKPreview : UIImageView

@property (nonatomic, assign) UIBlurEffectStyle blurEffectStyle;
@property (nullable, nonatomic, weak) id <VPKPreviewDelegate> delegate;
@property (nonatomic, assign) BOOL showData;
- (void)showIcon;
- (void)hideIcon;
- (void)showIcon:(BOOL)animated;
- (void)hideIcon:(BOOL)animated;
- (void)reset;

#pragma mark - utility function for preview of youtube veep (only used for demo app)

+ (nullable NSURL*)previewURLforYoutubeId:(nonnull NSString*)youtubeId;
@end
