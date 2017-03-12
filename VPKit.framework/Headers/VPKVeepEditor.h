//
//  VPKVeepCreator.h
//  VPKit
//
//  Created by jonathan on 29/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKViewController.h"

@class VPKVeepEditor;

@protocol VPKVeepEditorDelegate <NSObject>

- (void)veepEditor:(nonnull VPKVeepEditor*)editor didPublishVeep:(nonnull NSString*)veepId;

- (void)veepEditorDidCancel:(nonnull VPKVeepEditor*)editor;

@end

@interface VPKVeepEditor : VPKViewController
@property (nonatomic, weak, nullable) id <VPKVeepEditorDelegate> delegate;



@end
