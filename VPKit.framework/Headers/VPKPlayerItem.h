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

@interface VPKPlayerItem : NSObject
@property (nonatomic, strong, nonnull) NSURL* originalContentURL;
@property (nonatomic, strong, nullable)  NSString* title;
@property (nonatomic, strong, nullable) NSURL* previewURL;
@property (nonatomic, strong, nullable) UIImage* previewImage;
@property (nonatomic, strong, nullable) UIImage* placeholderImage;
@property (nonatomic, strong, nullable) NSString* mediaIdentifier;
@property (nonatomic, strong, nullable) NSString* customData;

@end

NS_ASSUME_NONNULL_END


