//
//  VPKVeepTrack + CellModels.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKVeepTrack.h"
#import "VPKGoogleCellModel.h"

@interface VPKVeepTrack (CellModels)

- (VPKGoogleCellModel*)googleCellModel:(VPKViewMode)mode;
@end
