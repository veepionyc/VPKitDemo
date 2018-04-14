//
//  VPKImage.h
//  VPKit
//
//  Created by jonathan on 10/06/2016.
//  Copyright © 2016 VEEPIO LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKVeep;
@class VPKPublicVeep;
NS_ASSUME_NONNULL_BEGIN

/**
 Drop-in replacement (subclass) for UIImage
 For use in conjunction with VPKPreview
 
 If VPKImage is initialised with null veepId or imageURL it will behave as a standard UIImage
 
 @see `VPKPreview`
 */

@interface VPKImage : UIImage
/**
 The veepId, if available.
 */
@property (nonatomic, strong, readonly, nullable) NSString* veepId;

/**
 The original content URI, if available.
 
 In the case of an image veep, this will match the source URL of the supplied image.
 
 For a video veep, this is the source URI for the video media (_not_ the placeholder image). This need not be an actual URL, but should be the unique identifier used when creating the veep (for example, it could be a youtube id).
 
 The URI is used to match the content to it's veep metadata. If a veepId is provided, the URI is not required as the veep will be fetched by it's id.
 
 */
@property (nonatomic, strong, readonly, nullable) NSURL* originalContentURI;

/**
 The veep metadata associated with the image, if  available
 */
@property (nonatomic, strong, readonly, nullable) VPKVeep* veep;

/**
 An abbreviated, header-only version of a veep, if available.
 */
@property (nonatomic, strong, readonly, nullable) VPKPublicVeep* publicVeep;

/**
 A courtesy property that the host app can use for tracking purposes.
 */
@property (nonatomic, strong, nullable) NSString* mediaIdentifier;

/**
 deprecated 2.5
 */
//@property (nonatomic, strong, readonly) NSURL* imageURL;


/**
 Use initWithImage:veepId if you are identifying veep content using the unique identifier (id) of the veep.
 
 @see `-initWithImage:url:`
 
 
 @param image
 The UIImage that this instance will subclass
 
 @param veepId
 A veep identifier. Veep metadata will be associated with the image using this identifier. The veep Id is returned as part of the veep creation process.
 
 @return An instance of VPKImage.
 
 */

- (instancetype)initWithImage:(UIImage*)image veepId:(nullable NSString*)veepId;

/**
 
 Use initWithImage:url if you are identifying veep content using the original URI used to create the veep.
 
 @see `-initWithImage:veepId:`
 
 
 
 @param image
 The UIImage that this instance will subclass
 
 
 @param contentURI
 The contentURI is the unique identifier for the veep'd resource.
 In the case of an image this will often be the source URL used to obtain the UIImage.
 In the case of video this will be the source address of the video asset.
 The contentURI must be the same URI as was used to create the veep as that is how veeps are identified.
 
 @return An instance of VPKImage.
 
 */

- (instancetype)initWithImage:(UIImage*)image url:(NSURL*)contentURI;

/**
 sets the veep, veepId and originalContentUri
 */
- (void)updateWithVeep:(VPKVeep*)veep;

/**
 sets the publicVeep (a veep header stub), veepId and originalContentUri.
 */
- (void)updateWithPublicVeep:(VPKPublicVeep*)veep;

/**
 sets `veep` to nil and `veepId` to veepId.
 
 @param veepId
 The unique identifier for a veep.
 */
- (void)updateWithVeepId:(nullable NSString*)veepId;



@end
NS_ASSUME_NONNULL_END

