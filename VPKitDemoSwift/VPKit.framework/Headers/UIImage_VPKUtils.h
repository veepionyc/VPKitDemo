//
//  UIImageView_VPKUtils.h
//  VPKit
//
//  Created by jonathan on 06/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (VPKUtils)

- (CGFloat)imageRatio;
+ (UIImage*) vpk_imageNamed:(NSString*)imageName;
@end
