//
//  VPKVeepDescriptionCellModel.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "VPKCellModel.h"
#import "VPKVeep.h"
@interface VPKVeepDescriptionCellModel : VPKCellModel
@property (nonatomic, strong) VPKVeep* data;
@property (nonatomic, strong) NSString* placeholderText;
@property (nonatomic, strong) NSString* labelText;

@end
