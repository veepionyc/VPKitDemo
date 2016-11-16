//
//  VPKVeepLocationCellModel.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "VPKCellModel.h"
#import "VPKVeep.h"

@interface VPKVeepLocationCellModel : VPKCellModel 
@property (nonatomic, strong) NSString* location;
@property (nonatomic, strong) VPKVeep* data;

@end
