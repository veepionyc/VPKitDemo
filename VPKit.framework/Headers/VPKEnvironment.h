//
//  VPKEnvironment.h
//  VPKit
//
//  Created by jonathan on 06/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKAppSettings;

typedef  NS_ENUM(NSUInteger, VPKUserType) {
    VPKUserTypeUnknown,
    VPKUserTypeAnonymous,
    VPKUserTypeLightweight,
    VPKUserTypeHeavyweight

};

typedef NS_ENUM(NSUInteger, VPKEnvironmentType) {
    VPKEnvironmentTypeNone,
    VPKEnvironmentTypeDev,
    VPKEnvironmentTypeSandbox,
    VPKEnvironmentTypeProduction,
};

@interface VPKUser : NSObject
@property (nonatomic, strong) NSString* email;
@property (nonatomic, assign) BOOL canDelete;
@property (nonatomic, assign) BOOL canCreate;
@property (nonatomic, assign) VPKUserType userType;
@end

@interface VPKApp : NSObject
@property (nonatomic, assign) BOOL veepPublicByDefault;
@property (nonatomic, copy) NSString* name;
//@property (nonatomic, copy) NSString* appId;  //legacy use
@property (nonatomic, copy) NSString* identifier; // the db key
//@property (nonatomic, copy) NSString* appName;
@property (nonatomic, copy) NSString* clientId;
@property (nonatomic, copy) NSString* clientSecret;
@property (nonatomic, copy) NSString* uuid;
@property (nonatomic, copy) NSString* idfa;



- (NSDictionary*)info;
- (NSString*)consumerId;
- (void)sendIDFA:(BOOL)idfa;


@end

@interface VPKDevice : NSObject


- (NSString*)machineName;
- (NSString*)platform;
- (NSDictionary*)osVersion;
@end

@interface VPKSdk : NSObject
- (NSDictionary*)info;
- (NSString*)infoString;
@end



@interface VPKEnvironment : NSObject
@property (nonatomic, strong) NSUserDefaults* userDefaults;
@property (nonatomic, strong) VPKUser* user;
@property (nonatomic, strong) VPKApp* app;
@property (nonatomic, strong) VPKDevice* device;
@property (nonatomic, strong) VPKSdk* sdk;


@property (nonatomic, strong) NSString* ipAddressDevice;
@property (nonatomic, strong) NSString* ipAddressNetwork;

@property (nonatomic, assign) BOOL shouldMonetise;
@property (nonatomic, assign) BOOL production;
@property (nonatomic, assign, getter= isInitialized,readonly) BOOL initialized;
@property (nonatomic, assign, readonly) BOOL loggedIn;
@property (nonatomic, assign) BOOL forwardErrors;

+ (instancetype)shared;
- (void)sendIDFA:(BOOL)idfa;



@end
