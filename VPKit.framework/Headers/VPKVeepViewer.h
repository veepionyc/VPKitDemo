//
//  VPImageViewController.h
//  VPKit
//
//  Created by jonathan on 23/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKViewController.h"

@class VPKVeepViewer;
@protocol VPKVeepViewerDelegate <NSObject>
@optional
- (void)veepViewer:(nonnull VPKVeepViewer*)viewer didFinishViewingWithInfo:(nullable NSDictionary*)info;
- (void)veepViewerDidCancel:(nonnull VPKVeepViewer*)viewer;

@end

@interface VPKVeepViewer : VPKViewController
@property (nonatomic, weak, nullable) id <VPKVeepViewerDelegate> delegate;




@end
