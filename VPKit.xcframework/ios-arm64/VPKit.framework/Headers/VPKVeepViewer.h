//
//  VPImageViewController.h
//  VPKit
//
//  Created by jonathan on 23/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKViewController.h"

@class VPKVeepViewer;
@class VPKPlaylist;

@protocol VPKVeepViewerDelegate <NSObject>

@optional

/**
 When either of these optional delegate methods are implemented, they will have to manage dismissing of the `viewer`.
*/

- (void)veepViewer:(nonnull VPKVeepViewer*)viewer didFinishViewingWithInfo:(nullable NSDictionary*)info;
- (void)veepViewerDidCancel:(nonnull VPKVeepViewer*)viewer;

@end

/**
 A full-screen media viewer for images and video. The `VPKVeepViewer` displays accompanying veep data when available and includes a self-contained web browser. While the VPKVeepViewer can be created directly by the host app it is recommended to use a `VPKPreview` image preview object which can internally manage creating presenting and dismissing of a veep viewer.
 
 @see `VPKPreview`
 
 */

@interface VPKVeepViewer : VPKViewController

/**
 An optional delegate conforming to `VPKVeepViewerDelegate`. If assigned, the delegate must manage dismissing of this `VPKVeepViewer`.
 
 */
@property (nonatomic, weak, nullable) id <VPKVeepViewerDelegate> delegate;

/**
 An optional `adHandler` conforming to the `VPKAdHandler` protocol. Assign an `adHandler` to insert preroll advertising on video content.

 */
@property (nonatomic, weak, nullable) id <VPKAdHandler> adHandler;


/**
 An optional `VPKPlaylist` holding an array of `VPKPlayerItem` video media items. If assigned, a video playlist will display beneath the playing video.
 */
@property (nonatomic, strong, nullable) VPKPlaylist* playlist;




@end
