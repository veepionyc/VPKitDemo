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
 Video media item URL. This is the only required property.
 */
@property (nonatomic, strong, nonnull) NSURL* originalContentURL;

/**
 Title string, if provided
 */
@property (nonatomic, strong, nullable)  NSString* title;

/**
 Preview image URL, if provided. One of `previewURL` and `previewImage` is required.
 */
@property (nonatomic, strong, nullable) NSURL* previewURL;

/**
 Preview UIImage, if provided.  One of `previewImage` and `previewURL` is required.
 */
@property (nonatomic, strong, nullable) UIImage* previewImage;

/**
 Placeholder UIImage, if provided. Will be replaced with `previewImage`, as obtained from a `previewURL`, when available
 */
@property (nonatomic, strong, nullable) UIImage* placeholderImage;

/**
Media identifier string, if provided
 */
@property (nonatomic, strong, nullable) NSString* mediaIdentifier;

/**
Custom data string, if provided
 */
@property (nonatomic, strong, nullable) NSString* customData;

@end

NS_ASSUME_NONNULL_END


