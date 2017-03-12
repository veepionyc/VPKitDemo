//
//  VPKImage.h
//  VPKit
//
//  Created by jonathan on 10/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface VPKImage : UIImage
@property (nonatomic, strong, readonly) NSString* veepId;
@property (nonatomic, strong, readonly) NSURL* imageURL;

- (instancetype)initWithImage:(UIImage*)image veepId:(nullable NSString*)veepId;

- (instancetype)initWithImage:(UIImage*)image url:(NSURL*)imageURL;


- (void)updateVeepId:(nonnull NSString*)veepId;
@end
NS_ASSUME_NONNULL_END
