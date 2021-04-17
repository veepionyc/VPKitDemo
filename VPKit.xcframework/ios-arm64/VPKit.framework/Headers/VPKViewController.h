//
//  VPKViewController.h
//  VPKit
//
//  Created by jonathan on 01/06/2016.
//  Copyright © 2016 jonathan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class VPKPlayerItem;
@class VPKVeepFetcher;
@class VPKVeepVideoImageView;
@class VPKCollectionVC;
@class VPKBlurTouchView;
@class VPKStyles;
@class VPKGoogleCellModel;
@class VPKVeep;
@class VPKImage;
@class VPKSessionData;
@class VPKPlayerItem;
@protocol VPKAdHandler;

typedef NS_ENUM(NSInteger, VPKViewMode );

NS_ASSUME_NONNULL_BEGIN

@interface VPKViewController : UIViewController
@property (nonatomic, strong) VPKVeepVideoImageView* veepView;
@property (nonatomic, weak, nullable) UIImage* image;
@property (nonatomic, strong, nonnull) UIView* sourceView;
@property (nonatomic, assign) CGRect toRect;
@property (nonatomic, assign) CGRect fromRect;
@property (nonatomic, strong, nonnull) VPKCollectionVC* collectionVC;
//@property (nonatomic, strong, nullable) NSString* veepId;
@property (nonatomic, strong, nonnull) VPKBlurTouchView* touchView;
@property (nonatomic, assign, readonly) VPKViewMode mode;
@property (nonatomic, strong) VPKVeepFetcher* fetcher;
@property (nonatomic, strong) VPKStyles* styles;
@property (nonatomic, assign) BOOL forwardErrors;
@property (nonatomic, copy) VPKSessionData* mainSessionData;
@property (nonatomic, assign) BOOL autoplay;

- (nonnull UIView*)transitioningView;
- (nonnull UIImageView*)transitioningImageView;



- (nonnull instancetype)initWithView:(nullable UIView*)view
                               image:(nonnull UIImage*)image
                              styles:(VPKStyles*)styles
                             fetcher:(VPKVeepFetcher*)fetcher;


- (void)configureVeepView;


- (void)showFooter;
- (void)showFooter:(nullable void ( ^)(BOOL finished))completion;
- (void)hideFooter;
- (void)hideFooter:(nullable void ( ^)(BOOL finished))completion;

- (void)trackSelected:(nonnull NSString*)trackId;


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
    
- (VPKImage*)vpkImage;

- (void)logVeepView;
- (void)logVeepSelect:(NSString*)trackId;
- (void)logProductView:(NSString*)trackId URL:(NSURL*)URL;
- (void)logProductNavigation:(NSString*)trackId URL:(NSURL*)URL;
- (void)logProductExpand:(NSString*)trackId;
- (void)logProductClose:(NSString*)trackId;
- (void)logVeepViewClose;

#pragma mark - heartbeat
- (Float64)duration;
- (Float64)currentPlaybackTime;
- (nullable NSDictionary*)qualityOfServiceDict;

@end

NS_ASSUME_NONNULL_END

