//
//  VPKCoordinates.h
//  VPKit
//
//  Created by jonathan on 19/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKParseableObject.h"

@interface VPKCoordinates: VPKParseableObject
@property (nonnull, nonatomic, strong) NSString* frame;
@property (nonnull, nonatomic, strong) NSNumber* x;
@property (nonnull, nonatomic, strong) NSNumber* y;


@end
