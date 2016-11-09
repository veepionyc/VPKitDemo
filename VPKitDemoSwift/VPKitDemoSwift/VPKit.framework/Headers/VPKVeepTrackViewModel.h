//
//  VPKVeepTrackViewModel.h
//  VPKit
//
//  Created by jonathan on 11/08/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKVeepTrack.h"
@interface VPKVeepTrackViewModel : NSObject
@property (nonatomic, strong) NSString* trackID;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, assign) BOOL monetised;
@property (nonatomic, strong) VPKVeepTrack* track;

@end
