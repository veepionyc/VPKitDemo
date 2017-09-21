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

@protocol VPKPreviewPassThroughDelegate <NSObject>

- (void)vpkPreview:(nonnull VPKPreview*)preview passedThroughTap:(nonnull UITapGestureRecognizer*)tapGestureRecognizer;

@end

/**
 Drop-in replacement (subclass) for UIImageView
 
 When the `image` property is assigned a suitably initialised VPKImage, the VPKPreview enables Veep Viewing and Veep Editing capabilities
 
 If assigned a standard UIImage, (or a VPKImage that doesn't use it's custom initialisers) this class  behaves as a standard UIImageView.
 
 @see VPKImage
 */

@interface VPKPreview : UIImageView

/**
 Read-only veepId - obtained from the VPKImage if initalised with a veepId, or from the imageURL if there is a matching veep available.
 */
@property (nullable, nonatomic, strong, readonly) NSString* veepId;

/**
 The optional  delegate affords the host app full control over the invoking of Veep Viewer and Veep Editors. If not set, VPKPreview will handle the presenting and dismissing of Viewers and Editors. If set, the host app is responsible for VeepViewer and VeepEditor management using the touch delegate callback.
 */

@property (nullable, nonatomic, weak) id <VPKPreviewDelegate> delegate;

/**
 The optional  pass-through delegate sends a tap gesture recogniser message to the receiver in the event that the VPKPreview doesn't handle it's tap. This is useful where the VPKPreview is view-only and the image has no associated veep content. and the host app wishes to respond to taps that the VPKPreview will ignore.
 */

@property (nullable, nonatomic, weak) id <VPKPreviewPassThroughDelegate> passThroughDelegate;


/**
 if YES the preview will animate when touched for better touch feedback.
 Default is NO.
 */

@property (nonatomic, assign) BOOL animateTouch;


/**
 adjusts the size of the icon. Default is 50.
 */

@property (nonatomic, assign) CGFloat iconLength;

- (void)showIcon;
- (void)hideIcon;
- (void)showIcon:(BOOL)animated;
- (void)hideIcon:(BOOL)animated;
- (void)reset;

/**
Utility function for preview of youtube veep (experimental).
 */

+ (nullable NSURL*)previewURLforYoutubeId:(nonnull NSString*)youtubeId;
@end
