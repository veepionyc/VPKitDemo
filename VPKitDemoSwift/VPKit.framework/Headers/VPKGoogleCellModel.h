//
//  VPKGoogleCellModel.h
//  Pods
//
//  Created by jonathan on 14/06/2016.
//
//

//#import <VPKit/VPKit.h>
#import "VPKCellModel.h"
#import "VPKVeepTrack.h"
#import "VPKConstants.h"
@class VPKGoogleCellModel;

@protocol VPKGoogleCellModelDelegate <NSObject>
@optional
- (void)googleCellModelUpdatedURL:(VPKGoogleCellModel *)cellModel navigated:(BOOL)changed;

@end


typedef NS_ENUM(NSInteger, GoogleCellState) {
    GoogleCellStateNone,
    GoogleCellStateViewer,
    GoogleCellStateSearch,
    GoogleCellStatePublish
    
};

@interface VPKGoogleCellModel : VPKCellModel

@property (nonatomic, weak) id<VPKGoogleCellModelDelegate>delegate;
@property (nonatomic, assign) GoogleCellState initialState;
@property (nonatomic, assign) GoogleCellState currentState;
@property (nonatomic, strong) NSURL* url;
@property (nonatomic, assign) BOOL fullScreened;
@property (nonatomic, strong) VPKVeepTrack* data;
@property (nonatomic, assign) VPKViewMode mode;


- (instancetype)initWithMode:(VPKViewMode)mode;
//- (BOOL)isValidVeepTrackURL;
//- (BOOL)isGoogleSearchPage:(NSString*)urlString;
//- (BOOL)isAmazonNonProductPage:(NSString*)urlString;

//- (NSURL*)veepSourcesURL;
- (BOOL)shouldGoBackToDefault;
- (void)changeURL:(NSURL*)url;
- (NSURL*)initialURL;
- (NSString*)headerText:(BOOL)forGoogle;

@end
