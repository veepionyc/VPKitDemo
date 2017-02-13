//
//  VPKImage.h
//  VPKit
//
//  Created by jonathan on 10/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VPKImage : UIImage
@property (nonnull, nonatomic, strong, readonly) NSString* veepID;

- (nonnull instancetype)initWithImage:(nonnull UIImage*)image veepID:(nonnull NSString*)veepID;
@end
