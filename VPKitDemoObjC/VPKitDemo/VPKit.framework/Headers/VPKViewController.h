//
//  VPKViewController.h
//  VPKit
//
//  Created by jonathan on 01/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPKVeepView.h"
#import "VPKVeep.h"
#import "VPKVeepTrack+CellModels.h"

#import "VPKVeepViewModel.h"
#import "VPKCollectionVC.h"
#import "VPKGoogleCellModel.h"
#import "VPKTouchView.h"
#import "VPKViewController_StateMachine.h"
#import "UIViewController_vpkKeyboardWatcher.h"

#import "VPKConstants.h"

@class VPKGoogleCellModel;

NS_ASSUME_NONNULL_BEGIN

@interface VPKViewController : UIViewController
@property (nonatomic, strong, nonnull) VPKVeepView* veepView;
@property (nonatomic, weak, nullable) UIImage* image;
@property (nonatomic, strong, nonnull) UIView* sourceView;
@property (nonatomic, assign) CGRect toRect;
@property (nonatomic, assign) CGRect fromRect;
@property (nonatomic, strong, nonnull) UINavigationBar* navBar;
@property (nonatomic, assign) CGRect startRect;
@property (nonatomic, strong, nullable) id selectedTrackObserver;
@property (nonatomic, strong, nonnull) VPKCollectionVC* collectionVC;
//@property (nonatomic, strong, nonnull) VPKGoogleCellModel* googleCellModel;
@property (nonatomic, assign) BOOL useVeepLogo;
//@property (nonatomic, strong, nonnull) VPKVeepViewModel* veepViewModel;
@property (nonatomic, strong, nullable) NSString* veepID;
@property (nonatomic, strong, nullable) NSString* mediaID;
@property (nonatomic, strong, nonnull) VPKTouchView* touchView;
@property (nonatomic, assign) VPKViewMode mode;


- (nonnull UIView*)transitioningView;
- (nonnull UIImageView*)transitioningImageView;



- (nonnull instancetype)initWithView:(nullable UIView*)view
                               image:(nonnull UIImage*)image
                              itemID:(nonnull NSString*)itemID;


- (CGFloat)navBarHeight;


- (void)showNavBar;
- (void)hideNavBar;

- (void)showFooter;
- (void)showFooter:(nullable VPK_BOOLBlock)completion;
- (void)hideFooter;
- (void)hideFooter:(nullable VPK_BOOLBlock)completion;



- (void)trackSelected:(nonnull NSString*)trackID;

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

@end

NS_ASSUME_NONNULL_END

