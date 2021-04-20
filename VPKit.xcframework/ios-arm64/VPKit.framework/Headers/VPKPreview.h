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
@class VPKPlayerItem;
@class VPKPlaylist;
@class VPKPreview;
@protocol VPKAdHandler;

@protocol VPKPreviewDelegate <NSObject>

- (void)vpkPreviewTouched:(nonnull VPKPreview*)preview image:(nonnull VPKImage*)image;

@end

@protocol VPKPreviewPassThroughDelegate <NSObject>
@optional
/**
 tap detected and ignored by VPKPreview.
 */
- (void)vpkPreview:(nonnull VPKPreview*)preview passedThroughTap:(nonnull UITapGestureRecognizer*)tapGestureRecognizer;
/**
 tap detected and handled by VPKPreview.
 */
- (void)vpkPreview:(nonnull VPKPreview*)preview handledTap:(nonnull UITapGestureRecognizer*)tapGestureRecognizer;
@end

/**
 Drop-in replacement (subclass) for UIImageView
 
 When the `image` property is assigned a suitably initialised VPKImage, the VPKPreview enables Veep Viewing and Veep Editing capabilities
 
 If assigned a standard UIImage, (or a VPKImage that doesn't use it's custom initialisers) this class  behaves as a standard UIImageView.
 
 @see `VPKImage`
 */


@interface VPKPreview : UIImageView

/**
 
 if set to YES the veep viewer will be presented regardless of whether the user has permissions to edit veeps. Default is NO.
 
 */
@property (nonatomic, assign) BOOL readonly;

/**
 Read-only veepId - obtained from the VPKImage if initalised with a veepId, or from the imageURL if there is a matching veep available.
 */
@property (nullable, nonatomic, strong, readonly) NSString* veepId;

/**
 The optional  touch delegate affords the host app full control over the invoking of Veep Viewer and Veep Editors. If not set, VPKPreview will handle the presenting and dismissing of Viewers and Editors. If set, the host app is responsible for VeepViewer and VeepEditor management using the touch delegate callback.
 */

@property (nullable, nonatomic, weak) id <VPKPreviewDelegate> delegate;

/**
 The optional  pass-through delegate sends tap gesture recogniser messages to the receiver. in the event that the VPKPreview doesn't handle it's tap. This is useful where the VPKPreview is view-only and the image has no associated veep content. and the host app wishes to respond to taps that the VPKPreview will ignore.
 */

@property (nullable, nonatomic, weak) id <VPKPreviewPassThroughDelegate> passThroughDelegate;

/**
 Readonly UITapGesetureRecognizer - set cancelsTouchesInView to NO to continue to receive didSelect: messages in collection view cells.
 */

@property (nonatomic, strong, nonnull, readonly) UITapGestureRecognizer* tapGR;


/**
if YES touching a VPKPreview will invoke the VPKit image viewer for all images. If NO, viewer will be invoked only for Veep'd images. Default is NO.
 */
@property (nonatomic, assign) BOOL invokeViewerForAllImages;

    
/**
 if YES the preview will animate when touched for better touch feedback.
 Default is NO.
 */

@property (nonatomic, assign) BOOL animateTouch;


/**
 adjusts the size of the icon. Default is 50.
 */

@property (nonatomic, assign) CGFloat iconLength;


/**
 use short-term caching for VeepIds. Default is YES;
 */
@property (nonatomic, assign) BOOL useCache;


/**
autoplay. Default is YES;
 */
@property (nonatomic, assign) BOOL autoplay;

/**
optional video playlist
 */
@property (nonatomic, copy, nullable) VPKPlaylist*   playlist;

/**
optional ad handler
 */
@property (nonatomic, weak, nullable) id <VPKAdHandler> adHandler;


/**
 Shows the veep content icon.
 */
- (void)showIcon;

/**
 Hides the veep content icon.
 */
- (void)hideIcon;

/**
 Shows the veep content icon, optionally animated.
 @param animated
 Enables (disables) icon animation.
 */
- (void)showIcon:(BOOL)animated;

/**
 Hides the veep content icon, optionally animated.
 @param animated
 Enables (disables) icon animation.
 */
- (void)hideIcon:(BOOL)animated;

/**
 Reset the preview: sets the image, imageurl and corresponding veep metadata to nil.
 */
- (void)reset;

/**
 Dismisses the veepviewer or veepeditor view controller, if it is currently presented.
 @param animated
 Enables (disables) icon animation.
 */
- (void)dismiss:(BOOL)animated;


/**
 returns playback time if a video is currently playing in the VPKit SDK.
 Returns -1 if video not loaded.
*/
- (Float64)currentPlaybackTime;

/**
 returns video duration if a video is currently loaded in the VPKit SDK.
 Returns -1 if video not loaded.
 */
- (Float64)duration;

/**
 returns NSDictionary of Quality of Service data for currently playing video. Returns nil if video not loaded.
 */
- (nullable NSDictionary*)qualityOfServiceDict;


/**
returns a sessionId.
 */
- (nullable NSString*)sessionIdentifier;

/**
 returns a mediaIdentifier.
 */
- (nullable NSString*)mediaIdentifier;

/**
Utility method for preview of youtube veep (experimental).
 */

+ (nullable NSURL*)previewURLforYoutubeId:(nonnull NSString*)youtubeId;
@end
