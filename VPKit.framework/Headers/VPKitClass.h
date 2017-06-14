//
//  VPKit.h
//  VPKit
//
//  Created by jonathan on 31/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@class VPKVeepViewer;
@class VPKVeepEditor;
@class VPKImage;
@class VPKPublicVeep;
@class VPKEnvironment;
@class VPKVeep;

#import "VPKStats.h"
#import "VPKStyles.h"
#import "VPKPreview.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, VPKServerEnvironment) {
    VPKServerDev,
    VPKServerProduction
};

typedef void (^VPKNetworkResponseBlock)(BOOL success, NSInteger responseCode, NSError* _Nullable error);
typedef void (^VPKBOOLErrorBlock)(BOOL success, NSError* _Nullable error);


typedef void (^VPKitConsumerIdCompletionBlock)(NSString* consumerId);
typedef void (^VPKitPublicVeepErrorCompletionBlock)(  VPKPublicVeep* _Nullable veep
                                                    , NSError* _Nullable error);
typedef void (^VPKUserStatsErrorBlock)(  VPKUserStats* _Nullable userStats
                                                    , NSError* _Nullable error);

typedef void (^VPKCompetitiveStatsBlock)(VPKCompetitiveStats* _Nullable stats,  NSError* _Nullable  error);
typedef void (^VPKDailyStatsBlock)(VPKDailyStats* _Nullable stats, NSError* _Nullable error);

/**
 Public entry point for the VPKit framework
 */

@interface VPKit : NSObject

/**
     sets the location for error dialogue handling - in the SDK or in the host app.
     
     @param forwardErrors 
         YES - error alerts are supressed in the SDK and NSNotifications are forwarded for interception by the host app.
         NO - user-facing error alerts are presented by the SDK.
 
 
 */
+ (void)forwardErrorNotifications:(BOOL)forwardErrors;


/**
SDK initialization.

This method is usually called from your App Delegate
 
Obtain these credentials by registering your app with the VEEPIO developer portal
 https://developer.veep.io

@param clientId - OAuth2 client_id credential
@param clientSecret - OAuth2 client_secret credential



 */
+ (void)setApplicationId:(nonnull NSString*)appId
                clientId:(nullable NSString*)clientId
                  clientSecret:(nullable NSString*)clientSecret;

- (void)setApplicationId:(nonnull NSString*)appId
                clientId:(nullable NSString*)clientId
            clientSecret:(nullable NSString*)clientSecret;

+ (void)setProduction:(BOOL)production;

- (void)setProduction:(BOOL)production;


- (instancetype)initUnique;

/**
IDFA support - optional
 
This requires host app linking to AdSupport.framework ("link binary with libarires" section of project Build Phases)
 
 @param idfa  Setting this option to YES entails additional reporting requirements when submitting to the app store
 
[See Apple docs for more information](https://developer.apple.com/library/content/documentation/LanguagesUtilities/Conceptual/iTunesConnect_Guide/Chapters/SubmittingTheApp.html#//apple_ref/doc/uid/TP40011225-CH33-SW8)
 
 */
+ (void)sendIDFA:(BOOL)idfa;

/**
Log out user from the default SDK.
 
This method will teardown the networking stack, remove OAuth2 tokens and delete user data and permissions. Application credentials (clientId and clientSecret) will persist.
 */

+ (void)logout;

/**

 Log out user from an SDK instance.
 
This method will teardown the networking stack, remove OAuth2 tokens and delete user data and permissions. Application credentials (clientId and clientSecret) will persist.
 */

- (void)logout;


#pragma mark - authentication

/**
 Class-level lighweight authentication for users with email identifier but no password.
 
 @param email user email as unique user identifier.
 @param completion Block to run on completion of authentication request.
 */

+ (void)authenticateWithEmail:(NSString*)email
                   completion:(VPKNetworkResponseBlock)completion;


/**
Class-level heavyweight authentication for users with email identifier and password.
 
 @param email user email as unique user identifier.
 @param password  user password string
 @param completion Block to run on completion of authentication request.
 */

+ (void)authenticateWithEmail:(NSString*)email
                     password:(nullable NSString*)password
                   completion:(VPKNetworkResponseBlock)completion;

/**
Instance-level heavyweight authentication for users with email identifier and password.
 
 @param email user email as unique user identifier.
 @param password  user password string
 @param completion Block to run on completion of authentication request.
 */

- (void)authenticateWithEmail:(NSString*)email
                     password:(nullable NSString*)password
                   completion:(VPKNetworkResponseBlock)completion;

+ (BOOL)authorized;


#pragma mark - analytics
    
/**---------------------------------------------------------------------------------------
 * @name Analytics
 *  ---------------------------------------------------------------------------------------
 */

+ (void)requestUserStats:(VPKUserStatsErrorBlock)completionBlock;

/**
   gets daily stats for the last seven days for this user
 */
+ (void)getDailyStats:(VPKDailyStatsBlock)completion;


/**
 gets competitive stats for this user
 */
+ (void)getCompetitiveStats:(VPKCompetitiveStatsBlock)completion;

#pragma mark - view controllers
    
/**---------------------------------------------------------------------------------------
 * @name View Controllers
 *  ---------------------------------------------------------------------------------------
 */

+ (nullable VPKVeepViewer*)viewerWithImage:(VPKImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view;

+ (nullable VPKVeepEditor*)editorWithImage:(UIImage*)image fromView:(UIView*)view error:( NSError* _Nullable *)error;


#pragma mark - environment

+ (nonnull VPKStyles*)styles;

+ (nonnull VPKEnvironment*) environment;

- (nonnull VPKEnvironment*) environment;


#pragma mark - getting veeps

+ (void) requestVeep:(NSString*)veepId completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

+ (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

- (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

/**
A string representation of the VPKit version.
 
 @return NSString description with version and build numbers.
 */

+ (NSString*)sdkVersion;

#pragma mark - veep distribution

/**
Copy veeps from the default app to a destination app. The default app is invoked by the class method. The destination app instance is passed in as a parameter.
 
 @param veepId The identifier of the veep to be copied.
 @param kit Instance of VPKit that represents the destination app to copy to.
 @param completion Block to run on completion of distribution network request.
 */

+ (void)copyVeep:(NSString*)veepId
           toKit:(VPKit*)kit
      completion:(VPKitPublicVeepErrorCompletionBlock)completion;

/**
Remove the most recent version of a veep from the default app.

 This is a *lightweight* deletion. It deletes the most recent version of a veep leaving previous versions intact.
 
 @param veepId The identifier of the veep to be deleted.
 @param completion Block to run on completion of distribution network request.
 */
+ (void)deleteVeep:(NSString*)veepId
        completion:(VPKBOOLErrorBlock)completion;

/**
Remove the most recent version of a veep from an app instance.

 This is a *lightweight* deletion. It deletes the most recent version of a veep leaving previous versions intact.
 
 @param veepId The identifier of the veep to be deleted.
 @param completion Block to run on completion of distribution network request.
 */
- (void)deleteVeep:(NSString*)veepId
        completion:(VPKBOOLErrorBlock)completion;



/**
Remove all versions of a veep from the default app.
 
 This is a *heavyweight* deletion. It deletes the current version and all previous versions as identified by the veep's root ID.

 @param veepId The identifier of the veep to be removed.

 @param completion Block to run on completion of network request.
 */

+ (void)deleteVeeps:(NSString*)veepId completion:(VPKBOOLErrorBlock)completion;

/**
Remove all versions of a veep from an app instance.

 This is a *heavyweight* deletion. It deletes the current version and all previous versions as identified by the veep's root ID.
 
 @param veepId The identifier of the veep to be removed.
 
 @param completion Block to run on completion of network request.
 */

- (void)deleteVeeps:(NSString*)veepId completion:(VPKBOOLErrorBlock)completion;

NS_ASSUME_NONNULL_END
@end
