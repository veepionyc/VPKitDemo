//
//  VPKCell.h
//  VPKit
//
//  Created by jonathan on 21/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKCellModel.h"
#import "VPKCellDivider.h"

@interface VPKCell : UICollectionViewCell <VPKModelledCellProtocol>
@property (nonatomic, strong) VPKCellDivider* divider;

@property (nonatomic, assign) BOOL showDivider;
@end
