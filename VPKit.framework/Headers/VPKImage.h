//
//  VPKImage.h
//  VPKit
//
//  Created by jonathan on 10/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKVeep;
NS_ASSUME_NONNULL_BEGIN

/**
 Drop-in replacement (subclass) for UIImage
 For use in conjunction with VPKPreview
 
  If VPKImage is initialised with null veepId or imageURL it will behave as a standard UIImage
 
 @see VPKPreview
 */

@interface VPKImage : UIImage
@property (nonatomic, strong, readonly, nullable) NSString* veepId;
@property (nonatomic, strong, readonly, nullable) NSURL* originalContentURI;
@property (nonatomic, strong, readonly, nullable) VPKVeep* veep;

/**
 deprecated 2.5
 */
//@property (nonatomic, strong, readonly) NSURL* imageURL;


/**
 Use initWithImage:veepId if you are identifying veep content using the unique identifier (id) of the veep.
 
 The veep Id is returned as part of the veep creation process.
 */

- (instancetype)initWithImage:(UIImage*)image veepId:(nullable NSString*)veepId;

/**
 
 Use initWithImage:url if you are identifying veep content using the original URI used to create the veep.
The contentURI is the unique identifier for the veep'd resource.
In the case of an image this will often be the source URL used to obtain the UIImage.
In the case of video this will be the source address of the video asset.

 The contentURI must be the same URI as was used to create the veep as that is how veeps are identified.
 */

- (instancetype)initWithImage:(UIImage*)image url:(NSURL*)contentURI;

/**
 sets the veep, veepId and originalContentUri
*/
- (void)updateWithVeep:(VPKVeep*)veep;

/**
sets self.veep to nil and self.veepId to veepId
 */
- (void)updateWithVeepId:(nullable NSString*)veepId;



@end
NS_ASSUME_NONNULL_END
