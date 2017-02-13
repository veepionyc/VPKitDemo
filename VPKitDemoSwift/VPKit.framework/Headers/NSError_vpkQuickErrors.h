//
//  NSError_QuickErrors.h
//  FNCategoriesKit
//
//  Created by jonathan on 07/09/2014.
//  Copyright (c) 2014 foundry. All rights reserved.
//

#import <Foundation/Foundation.h>

void NSError_QuickErrors();


@interface NSError (VPK_QuickErrors)
+ (NSError*)vpk_errorWithDescription:(NSString*)description;
+ (NSError*)vpk_errorWithDescription:(NSString*)description code:(NSInteger)code;
+ (NSError*)vpk_errorWithDescription:(NSString *)description reason:(NSString*)reason;

+ (NSError*)vpk_errorFromMethod:(SEL)method withDescription:(NSString*)description;
+ (NSError*)vpk_errorFromMethod:(SEL)method withDescription:(NSString*)description code:(NSInteger)code;
+ (NSError*)vpk_errorFromMethod:(SEL)method withDescription:(NSString*)description reason:(NSString*)reason;
+ (NSError*)vpk_errorFromMethod:(SEL)method withDescription:(NSString*)description underlyingError:(NSError*)error;
+ (NSError*)vpk_errorFromMethodUnknown:(SEL)method;
- (BOOL)vpk_noSuchEntityError;
- (BOOL)vpk_isNSURLError;
- (BOOL) vpk_isNSURLCancelError;

+ (void)vpk_logError:(NSError*)error;
+ (void)vpk_logError:(NSError *)error msg:(NSString*)msg;

- (NSString*)vpk_errorMessage;
@end
