//
//  VPKConstants.h
//  VPKit
//
//  Created by jonathan on 28/05/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#ifndef VPKConstants_h
#define VPKConstants_h
#import "VPKUtils.h"
#import "VPKPublicConstants.h"




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




static NSString* const kSearchBoxLocation = @"kSearchBoxLocation";

static NSString* const kSearchBoxFocussed = @"kSearchBoxFocussed";
static NSString* const kWindowTouchStarted = @"kWindowTouchStarted";
static NSString* const kWebViewExpanded = @"kWebViewExpanded";

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


#endif /* VPKConstants_h */


