//
//  VPKEndpoints.h
//  Pods
//
//  Created by jonathan on 30/05/2016.
//
//

#import <Foundation/Foundation.h>
#import "VPKConstants.h"
#import "VPKNetwork.h"
#import "VPKVeep.h"

@interface VPKEndpoints : NSObject

- (instancetype)initWithNetwork:(VPKNetwork*)network;

- (void)getVeep:(NSString*)veepid  completion:(VPK_DataErrorBlock)completion;

- (void)postVeep:(VPKVeep*)veep  completion:(VPK_DataErrorBlock)completion;

@end
