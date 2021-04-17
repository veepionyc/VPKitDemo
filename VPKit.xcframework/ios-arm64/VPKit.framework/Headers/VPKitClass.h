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
@class VPKVeep;
@class VPKVeepFetcher;
@class VPKAuthorization;

#import "VPKStats.h"
#import "VPKStyles.h"
#import "VPKPreview.h"
#import "VPKPublicConstants.h"
#import "VPKEnvironment.h"
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
typedef void (^VPKitVeepErrorCompletionBlock)(  VPKVeep* _Nullable veep
                                                    , NSError* _Nullable error);

typedef void (^VPKVeepIdentifierErrorCompletionBlock)(  NSString* _Nullable identifier
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
         YES - error alerts are supressed in the SDK and NSNotifications are forwarded for interception by the host app. The notification name is vpkErrorNotification. The NSError is added to the Notification's userInfo dictionary with key vpkErrorKey
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
+ (void)setApplicationId:(nonnull NSString*)appName
                clientId:(nullable NSString*)clientId
                  clientSecret:(nullable NSString*)clientSecret;

- (void)setApplicationId:(nonnull NSString*)appName
                clientId:(nullable NSString*)clientId
            clientSecret:(nullable NSString*)clientSecret;

+ (void)setAuth:(VPKAuthorization *)auth
            env:(VPKEnvironmentType)env
          identifier:(NSString*)identifier
        name:(NSString*)name
      canCreate:(BOOL)canCreate
      canDelete:(BOOL)canDelete;

- (void)setAuth:(VPKAuthorization *)auth
            env:(VPKEnvironmentType)env
          identifier:(NSString*)identifier
        name:(NSString*)name
      canCreate:(BOOL)canCreate
      canDelete:(BOOL)canDelete;

+ (void)setProduction:(BOOL)production;

- (void)setProduction:(BOOL)production;

/**
 Monetisation support
 
@param shouldMonetise
 
set to YES if requiring Amazon affiliation button during Veep Create
 
*/

+ (void)setShouldMonetise:(BOOL)shouldMonetise;

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
/**
Create a VPKVeepViewer. This is the view controller for viewing image and video content with Veep metadata.
 @param preview The VPKPreview containing the image to be viewed with the VeepViewer.This view's image provides the image data for viewing. The view frame is used for the transition geometry when presenting and dismissing.
 */

+ (nullable VPKVeepViewer*)viewerWithPreview:(VPKPreview*)preview; //NEW 2.7.0

/**
Create a VPKVeepViewer. Usse this method to provide image data with higher resolution than contained in the VPKPreview imageView.
 @param image The image data for display in the Veep Viewer.
 @param preview A VPKPreview that handles the Viewer delegate methods and provdies frame geometry for presenting and dismissing the Veep Viewr.

*/

+ (nullable VPKVeepViewer*)viewerWithImage:(UIImage*)image fromPreview:(VPKPreview*)preview;  //NEW 2.7.0

/**
Create a VPKVeepViewer. DEPRECATED from v 2.7.0
@param image the image to be viewed with the VeepViewer.
@param view  the view framing the image. This view is used to provide the transition geometry when presenting and dismissing.
*/

+ (nullable VPKVeepViewer*)viewerWithImage:(UIImage*)image fromView:(UIView*)view; //DEPRECATED 2.7.0

/**
Presents a viewer on a new overlaying UIWindow - allows full orientation changes on the viewer while underlying controller may have more restricted orientations.
*/
    
+ (void)presentViewer:(VPKVeepViewer*)viewer;

#pragma mark - environment 
+ (nonnull VPKVeepFetcher*)fetcher;

- (nonnull VPKVeepFetcher*)fetcher;


+ (nonnull VPKStyles*)styles;

+ (nonnull VPKEnvironment*) environment;

- (nonnull VPKEnvironment*) environment;


#pragma mark - getting veeps
/**
    request a veep by veepId and return a VPKPublicVeep in the completion handler
 */

+ (void) requestVeep:(NSString*)veepId completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

/**
 Request a veep by veepId and return a VPKVeep in the completion handler.
 */

+ (void) getVeep:(NSString*)veepId completionBlock:(VPKitVeepErrorCompletionBlock)completion;

/**
Request a veep by originalContentURI and return a VPKPublicVeep in the completion handler.
 */
+ (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

- (void) requestVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

/**
Request a veep by originalContentURI and return a VPKVeep in the completion handler.
 */

+ (void) getVeepWithURL:(NSURL*)imageURL completionBlock:(VPKitVeepErrorCompletionBlock)completion;


/**
Request a veep identifier by originalContentURI and return the identifier as an NSString in the completion handler.
 */

+ (void) getVeepIdWithURI:(NSURL*)originalContentURI useCache:(BOOL)useCache completionBlock:(VPKVeepIdentifierErrorCompletionBlock)completion;

/**
Request a veep header by originalContentURI and return the header as an VPKPublicVeep in the completion handler.
 */

+ (void) getVeepHeaderWithURI:(NSURL*)originalContentURI useCache:(BOOL)useCache completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

- (void) getVeepHeaderWithURI:(NSURL*)originalContentURI useCache:(BOOL)useCache completionBlock:(VPKitPublicVeepErrorCompletionBlock)completion;

/**
A string representation of the VPKit version.
 
@return NSString description with version and build numbers.
 */

+ (NSString*)sdkVersion;


NS_ASSUME_NONNULL_END
@end
