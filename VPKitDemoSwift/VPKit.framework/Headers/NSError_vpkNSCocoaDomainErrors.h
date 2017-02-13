//
//  NSError_NSCocoaDomainErrors.h
//  FNCategoriesKit
//
//  Created by jonathan on 29/10/2014.
//  Copyright (c) 2014 foundry. All rights reserved.
//

#import <Foundation/Foundation.h>
void NSError_NSCocoaDomainErrors();

@interface NSError (VPK_NSCocoaDomainErrors)
+ (NSString*)vpk_NSCocoaErrorDomainMessage:(NSError*)error;

@end
