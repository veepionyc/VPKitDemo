//
//  VPKPubiicVeep.h
//  VPKit
//
//  Created by jonathan on 25/06/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 Public interface for a VPKVeep object
 */

@interface VPKPublicVeep : NSObject

/**
 Uniquely identifies a veep
 */
@property (nonnull, nonatomic, strong) NSString* identifier;
/**
 Title string, if provided
 */
@property (nullable, nonatomic, strong) NSString* title;
/**
 Description string, if provided
 */
@property (nullable, nonatomic, strong) NSString* descriptionString;
/**
 Source URI for veep'd media item
 */
@property (nullable, nonatomic, strong) NSURL* originalContentURI;
/**
 Alternative URIs for veep'd media item
 */
@property (nullable, nonatomic, strong) NSArray <NSString*>* alternativeContentURIs;
/**
 Width of media item at soure URI
 */
@property (nullable, nonatomic, strong) NSNumber* originalContentWidth;
/**
 Height of media item at soure URI
 */
@property (nullable, nonatomic, strong) NSNumber* originalContentHeight;
/**
 URL of preview item. This is the poster image if the media item is a video.
 */
@property (nullable, nonatomic, strong) NSString* previewURL;

@end

