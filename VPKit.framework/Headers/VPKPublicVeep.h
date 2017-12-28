//
//  VPKPubiicVeep.h
//  VPKit
//
//  Created by jonathan on 25/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VPKPublicVeep : NSObject
@property (nonnull, nonatomic, strong) NSString* identifier;
@property (nullable, nonatomic, strong) NSString* title;
@property (nullable, nonatomic, strong) NSString* descriptionString;
@property (nullable, nonatomic, strong) NSURL* originalContentURI;
@property (nullable, nonatomic, strong) NSNumber* originalContentWidth;
@property (nullable, nonatomic, strong) NSNumber* originalContentHeight;
@property (nullable, nonatomic, strong) NSString* previewURL;

@end
