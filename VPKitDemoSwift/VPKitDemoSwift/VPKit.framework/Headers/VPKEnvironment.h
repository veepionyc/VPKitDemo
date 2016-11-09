//
//  VPKEnvironment.h
//  VPKit
//
//  Created by jonathan on 06/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface VPKEnvironment : NSObject
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* appID;
@property (nonatomic, assign) BOOL production;

//- (NSString*)newConsumerID;
- (void)verifyState;

- (NSString*)platform;
- (NSDictionary*)osVersion;
- (NSString *)uuid;
- (NSString*)machineName;
- (NSString*)version;
- (NSString*)build;
- (NSString*)bundleID;
- (NSDictionary*)appVersion;
- (NSDictionary*)sdkVersion;

- (NSBundle*)assetsBundle;
+ (NSBundle*)assetsBundle;

@end
