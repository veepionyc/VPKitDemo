//
//  VPKNetwork.h
//  VPKit
//
//  Created by jonathan on 28/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPKConstants.h"
@interface VPKNetwork : NSObject


#pragma mark - generic interfaces

- (instancetype)initWithEmail:(NSString*)email;
- (void)teardown;

- (BOOL)authorised;

- (void)authorise:(VPK_BOOLErrorBlock)completion;

-(void)GET:(NSString*)path
     query:(NSDictionary*)arguments
   success:(VPK_DataBlock)successBlock
   failure:(VPK_ErrorBlock)failureBlock;

-(void)POST:(NSString*)path
       data:(NSDictionary*)data
    success:(VPK_DataBlock)successBlock
    failure:(VPK_ErrorBlock)failureBlock;

-(void)PUT:(NSString*)path
      data:(NSDictionary*)data
   success:(VPK_DataBlock)successBlock
   failure:(VPK_ErrorBlock)failureBlock;
@end
