//
//  VPKAuthorisation.h
//  VPKit
//
//  Created by jonathan on 28/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import "VPKParseableObject.h"
NS_ASSUME_NONNULL_BEGIN
@interface VPKAuthorisation : VPKParseableObject
@property (nonatomic, strong) NSString* userID;
@property (nonatomic, strong) NSString* accessToken;
@property (nonatomic, strong) NSString* expiresIn;
@property (nonatomic, strong) NSString* tokenType;
@property (nonatomic, strong) NSString* scope;
@property (nonatomic, strong) NSString* refreshToken;
@property (nonatomic, strong, readonly) NSString* email;

- (instancetype)initWithEmail:(NSString*)email;
- (NSString*)authString;
@end
NS_ASSUME_NONNULL_END
