//
//  VPKViewController.h
//  VPKit
//
//  Created by jonathan on 01/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "VPKViews.h"
//#import "VPKModels.h"
//#import "VPKNetwork.h"

@class VPKVeepFetcher;

//#import "VPKVeepTrack+CellModels.h"
//#import "VPKVideo.h"
//
//#import "VPKCollectionVC.h"
//#import "VPKGoogleCellModel.h"
//#import "VPKTouchView.h"
//#import "VPKViewController_StateMachine.h"
//#import "UIViewController_vpkKeyboardWatcher.h"
//
//#import "VPKStyles.h"

//#import "VPKConstants.h"

@class VPKVeepVideoImageView;
@class VPKCollectionVC;
@class VPKBlurTouchView;
@class VPKStyles;
@class VPKGoogleCellModel;
typedef NS_ENUM(NSInteger, VPKViewMode );

NS_ASSUME_NONNULL_BEGIN

@interface VPKViewController : UIViewController
@property (nonatomic, strong, nonnull) VPKVeepVideoImageView* veepView;
@property (nonatomic, weak, nullable) UIImage* image;
@property (nonatomic, strong, nonnull) UIView* sourceView;
@property (nonatomic, assign) CGRect toRect;
@property (nonatomic, assign) CGRect fromRect;
@property (nonatomic, strong, nonnull) UINavigationBar* navBar;
@property (nonatomic, assign) CGRect startRect;
@property (nonatomic, strong, nullable) id selectedTrackObserver;
@property (nonatomic, strong, nonnull) VPKCollectionVC* collectionVC;
//@property (nonatomic, strong, nonnull) VPKGoogleCellModel* googleCellModel;
//@property (nonatomic, strong, nonnull) VPKVeepViewModel* veepViewModel;
@property (nonatomic, strong, nullable) NSString* veepId;
//@property (nonatomic, strong, nullable) NSString* mediaId;
@property (nonatomic, strong, nonnull) VPKBlurTouchView* touchView;
@property (nonatomic, assign) VPKViewMode mode;
@property (nonatomic, strong) VPKVeepFetcher* fetcher;
@property (nonatomic, strong) VPKStyles* styles;
@property (nonatomic, assign) BOOL forwardErrors;
@property (nonatomic, strong) NSURL* originalContentURL;



- (nonnull UIView*)transitioningView;
- (nonnull UIImageView*)transitioningImageView;



- (nonnull instancetype)initWithView:(nullable UIView*)view
                               image:(nonnull UIImage*)image
                              styles:(VPKStyles*)styles
                              itemId:(nonnull NSString*)itemId
                             fetcher:(VPKVeepFetcher*)fetcher;


- (void)configureVeepView;


- (void)showNavBar;
- (void)hideNavBar;

- (void)showFooter;
- (void)showFooter:(nullable void ( ^)(BOOL finished))completion;
- (void)hideFooter;
- (void)hideFooter:(nullable void ( ^)(BOOL finished))completion;



- (void)trackSelected:(nonnull NSString*)trackId;

//- (nonnull UIBarButtonItem*)backButton;
//- (nonnull UIBarButtonItem*)dismissButton;
//- (nonnull UIBarButtonItem*)cancelButton;
//- (nonnull UIBarButtonItem*)nextButton;
//- (nonnull UIBarButtonItem*)publishButton;


- (void)resetCollectionVC;
- (void)dismiss;
- (void)cancel;
- (void)back;
- (void)next;

- (void)startListening;
- (void)stopListening;
- (void)startObserving;
- (void)stopObserving;

- (void)expandWebView:(NSNotification*)notification;
    
- (UIEdgeInsets)safeInsets;
- (BOOL)isIphoneX;
@end

NS_ASSUME_NONNULL_END

