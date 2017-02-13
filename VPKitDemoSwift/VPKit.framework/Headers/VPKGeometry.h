//
//  VPGeometry.h
//  VPKit
//
//  Created by jonathan on 09/03/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

@import UIKit;

@interface VPKGeometry : NSObject


+ (CGPoint)pointMapped:(CGPoint)point fromVideoSize:(CGSize)videoSize toViewSize:(CGSize)viewSize;
+ (CGSize)sizeMapped:(CGSize)size fromVideoSize:(CGSize)videoSize toViewSize:(CGSize)viewSize;

+ (CGPoint)normalisedPoint:(CGPoint)point containerSize:(CGSize)size;
+ (CGSize)normalisedSize:(CGSize)innerSize containerSize:(CGSize)size;
+ (CGRect)normalisedFrame:(CGRect)frame containerSize:(CGSize)size;

+(CGPoint)denormalisedPoint:(CGPoint)normalisedPoint containerSize:(CGSize)size;

+ (CGSize)denormalisedSize:(CGSize)normalisedSize containerSize:(CGSize)size;

+ (CGRect)denormalisedFrame:(CGRect)frame containerSize:(CGSize)size;
@end
