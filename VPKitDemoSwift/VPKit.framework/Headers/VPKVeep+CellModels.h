//
//  VPKVeep+CellModels.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKVeepTitleCellModel.h"
#import "VPKVeepDescriptionCellModel.h"
#import "VPKVeepLocationCellModel.h"

@interface VPKVeep (CellModels)
- (VPKVeepTitleCellModel*)titleCellModel;
- (VPKVeepDescriptionCellModel*)descriptionCellModel;
- (VPKVeepLocationCellModel*)locationCellModel;
@end
