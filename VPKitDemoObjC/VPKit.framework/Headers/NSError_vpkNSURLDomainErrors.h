//
//  NSError_NSURLDomainErrors.h
//  FNCategoriesKit
//
//  Created by jonathan on 29/10/2014.
//  Copyright (c) 2014 foundry. All rights reserved.
//

#import <Foundation/Foundation.h>

void NSError_NSURLDomainErrors();

@interface NSError ( VPK_NSURLDomainErrors)
+ (NSString*) vpk_NSURLErrorDomainMessage:(NSError*)error;
+ (NSInteger) vpk_NSURLErrorCancelled;
@end
