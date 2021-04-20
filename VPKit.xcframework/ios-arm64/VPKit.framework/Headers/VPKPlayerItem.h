//
//  VPKPlayerItem.h
//  VPKit
//
//  Created by jonathan on 12/12/2020.
//  Copyright © 2020 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

NS_ASSUME_NONNULL_BEGIN


/**
 Metadata object for defining a video as part of a video playlist, which consists of an array of these items. Video playlists can be assigned to the `playlist` property of a `VPKPreview` or `VPKVeepViewer`
 */

@interface VPKPlayerItem : NSObject

/**
 Video media item URL (required)
 */
@property (nonatomic, copy, nonnull) NSURL* originalContentURL;

/**
 Preview image URL (required).
 
 This will be used as the thumbnail image in the playlist, and as the poster image for the video.
 */
@property (nonatomic, copy, nonnull) NSURL* previewURL;


/**
 Title string, if provided (optional)
 */
@property (nonatomic, copy, nullable)  NSString* title;


/**
Media identifier string, if provided (optional)
 */
@property (nonatomic, copy, nullable) NSString* mediaIdentifier;

/**
Custom data dictionary of strings (optional)
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString*, NSString*>* customData;



@end

/**
 VPKPlaylist stores a collection of VPKPlayerItem items and optionally a placeholder image for VPKPlayerItem cells.
 */
@interface VPKPlaylist : NSObject
/**
 Array of `VPKPlayerItem` objects.
 */
@property (nonatomic, copy, nonnull, readonly) NSArray <VPKPlayerItem*>*   items;
/**
 Optional placeholder image.
 */
@property (nonatomic, strong, nullable) UIImage* placeholderImage;

/**
Required initialiser.
 */
- (instancetype) initWithItems:(NSArray <VPKPlayerItem*>*) items;
@end



NS_ASSUME_NONNULL_END


