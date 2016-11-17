//
//  VPKConstants.h
//  VPKit
//
//  Created by jonathan on 28/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#ifndef VPKConstants_h
#define VPKConstants_h
#import <UIKit/UIKit.h>

@class VPKVeep;

//#define USE_DEPENDENCIES

#define GOOGLE_BACK_FUNCTION //undef TBR
#define NEW_OBSERVERS //undef TBR
#define BLUR_NAVBAR
#define WEB_FOOTER //undef TBR
#define WEB_FOOTER_MIN_SCREENHEIGHT 0
#define WEB_SEARCHBOX_BUGFIX // check ios10
#define USE_TRACKIDX //legacy code, TBR

#ifdef WEB_SEARCHBOX_BUGFIX
static CGFloat const kIPhone5WebSearchBugFix = 10;
static CGFloat const kIPhone6WebSearchBugFix = 40;
static CGFloat const kIPhone6PlusWebSearchBugFix = 20;
#endif


typedef NS_ENUM(NSInteger, VPKState) {
    VPKStateNone,
    VPKStateViewer,
    VPKStateViewerTrackDeselected,
    VPKStateViewerTrackSelected,
    VPKStateEditorNewTrack,
    VPKStateEditorGoogleSearch,
    VPKStateEditorFoundPage,
    VPKStateEditorSavedTracks,
    VPKStateEditorBoostTrack,
    VPKStateEditorAddVeepData,
    VPKStateEditorPublished
    
};

typedef NS_ENUM(NSInteger, VPKViewMode ) {
    VPKViewModeNone,
    VPKViewModeConsume,
    VPKViewModeCreate
};

typedef void (^VPK_IdBlock)(id thing);
typedef void (^VPK_ErrorBlock) (NSError* error);
typedef void (^VPK_DataBlock)(NSData* data);
typedef void (^VPK_DataErrorBlock) (NSData* data, NSError* error);
typedef void (^VPK_BOOLErrorBlock) (BOOL success, NSError* error);
typedef void (^VPK_VeepErrorBlock) (VPKVeep* veep, NSError* error);
typedef void (^VPK_StringErrorBlock) (NSString* string, NSError* error);
typedef void (^VPK_DictionaryErrorBlock) (NSDictionary* dict, NSError* error);
typedef void (^VPK_MediaIDVeepIDErrorBlock) (NSString* mediaID, NSString* veepID, NSError* error);



typedef void (^VPK_AlertActionBlock)(UIAlertAction* action);
typedef void (^VPK_ImageErrorBlock)(UIImage* image, NSError* error);
typedef void (^VPK_ImageBlock)(UIImage* image);
typedef void (^VPK_BOOLBlock) (BOOL success);


#define VPK_EMBEDDED_ERROR_KEY @"VPK_EMBEDDED_ERROR_KEY"
#define VPK_RESET_NOTIFICATION @"VPK_RESET_NOTIFICATION"

static NSString* const vpkInternalErrorNotification = @"vpkInternalErrorNotification";
static NSString* const vpkInternalErrorKey = @"vpkInternalErrorKey";

static NSString* const kVPKStateKey = @"kVPKStateKey";

static NSString* const kVPKStateChangeRequest = @"kVPKStateChangeRequest";
static NSString* const kVPKStateChanged = @"kVPKStateChanged";

static NSString* const kSearchBoxLocation = @"kSearchBoxLocation";

static NSString* const kSearchBoxFocussed = @"kSearchBoxFocussed";
static NSString* const kWindowTouchStarted = @"kWindowTouchStarted";

static NSString* const kUpArrowButtonTouched = @"kUpArrowButtonTouched";
static NSString* const kDownArrowButtonTouched = @"kDownArrowButtonTouched";
static NSString* const kBackArrowButtonTouched = @"kBackArrowButtonTouched";
static NSString* const kNextArrowButtonTouched = @"kNextArrowButtonTouched";
static NSString* const kCrossButtonTouched = @"kCrossButtonTouched";

static NSString* const kWebViewNavStateChanged = @"kWebViewNavStateChanged";
static NSString* const kWebViewExpansionStateChanged = @"kWebViewExpansionStateChanged";
//static NSString* const kShouldGoBackForGoogle = @"kShouldGoBackForGoogle";
static NSString* const kShouldGoBackForSources = @"kShouldGoBackForSources";


static NSString* const kVeepViewIsPanning = @"kVeepViewIsPanning";
static NSString* const kVeepViewDidFinishPanning = @"kVeepViewDidFinishPanning";


static const CGFloat kGoogleHeight = 258;
static const CGFloat kCellNavbarHeight = 44;
static const CGFloat kNavbarHeight = 64;
static const CGFloat kNavbarHeightExtended = 84;

static const CGFloat kStatusBarHeight = 20;


//backend API locations
//static NSString* const kLambdaScheme = @"https";
//static NSString* const kDockerScheme = @"https";
//static NSString* const kLambdaHost = @"yhc88w66n1.execute-api.us-east-1.amazonaws.com";
//static NSString* const kDockerHost = @"sdk-api.dev.veep.io";
//static NSString* const kLambaEndpoint = @"dev";
//static NSString* const kDockerEndpoint = @"";
//
////static NSString* const kLambdaVersionPrefix = @"/api/v1.0";
////static NSString* const kDockerVersionPrefix = @"/api/v1.0";
//static NSString* const kLambdaVersionPrefix = @"";
//static NSString* const kDockerVersionPrefix = @"";




static NSString* const kDevScheme = @"https";
static NSString* const kProdScheme = @"https";
static NSString* const kDevHost = @"sdk-api.dev.veep.io";
static NSString* const kProdHost = @"sdk-api.prod.veep.io";
static NSString* const kDevEndpoint = @"";
static NSString* const kProdEndpoint = @"";

//static NSString* const kLambdaVersionPrefix = @"/api/v1.0";
//static NSString* const kDockerVersionPrefix = @"/api/v1.0";
static NSString* const kDevVersionPrefix = @"";
static NSString* const kProdVersionPrefix = @"";



static NSString* const kVeepsEndpoint = @"veeps/";
static NSString* const kLightweightUsersTokenEndpoint = @"lightweight_users/token/";
static NSString* const kCurrentUserStatsEndpoint = @"/users/current/stats/";

//typedef NS_ENUM(NSInteger, VPKBackendType) {
//    VPKBackendTypeNone,
//    VPKBackendTypeLambda,
//    VPKBackendTypeDocker
//};

//static VPKBackendType const kBackendType = VPKBackendTypeDocker;


//Kinesis credentials
static NSString* const kKinesisAccessKeyExperimental = @"AKIAI53XZICKAHWIBTSQ";
static NSString* const kKinesisSecretKeyExperimental = @"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";
static NSString* const kKinesisStreamNameExperimental = @"veepio-analytics-experimental";

static NSString* const kKinesisAccessKeyProduction = @"AKIAIZCMAPJLDEUB6PJQ";
static NSString* const kKinesisSecretKeyProduction = @"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";
static NSString* const kKinesisStreamNameProduction = @"veepio-analytics-production";





#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
static void vpk_runOnMainThread(void (^block)(void))
{
    if (!block) return;
    
    if ( [[NSThread currentThread] isMainThread] ) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

static void vpk_runInBackground(void (^block)(void))
{
    if (!block) return;
    
    if ( [[NSThread currentThread] isMainThread] ) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), block);

    } else {
        block();

    }
}
#pragma clang diagnostic pop    


//////// LOGGING ////////


#define LOG_APP 1

#define LOG_DEALLOCS 0

#define VPLogMethod if(LOG_APP && LOG_ME) NSLog(@"%@ %@",self.class,NSStringFromSelector(_cmd));

#define VPLog if(LOG_APP && LOG_ME) NSLog

#define VPDeallocLog if(LOG_DEALLOCS) NSLog(@"%@ %@",self.class,NSStringFromSelector(_cmd));

#define VPKLog(...) VPLogMethod VPLog(__VA_ARGS__)


//#define NSLog(...) CLS_LOG(__VA_ARGS__)

#ifndef DEBUG
#define NSLog(...);

#endif

////////// WEAKIFY STRONGIFY //////

#define vpk_weakify(_) __weak typeof(_) _ ## _weak_ = (_);
#define vpk_strongify(_) __strong typeof(_) _ = _ ## _weak_;


#endif /* VPKConstants_h */
