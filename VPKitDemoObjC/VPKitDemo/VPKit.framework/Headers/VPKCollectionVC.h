//
//  VPKEditorCollectionVC.h
//  Pods
//
//  Created by jonathan on 12/06/2016.
//
//

#import <UIKit/UIKit.h>
#import "VPKVeepView.h"
#import "VPKHeaderView.h"
#import "VPKConstants.h"

@interface VPKCollectionVC : UIViewController
@property (nonatomic, strong, nonnull) VPKVeepView* veepView;
@property (nonnull, nonatomic, strong) VPKHeaderView* headerView;

@property (nonatomic, strong, nullable) NSArray* cellModels;
@property (nonatomic, strong, nonnull) UICollectionView* collectionView;



- (nullable instancetype)initWithVeepView:(nonnull VPKVeepView*)veepView cellModels:(nullable NSArray*)cellModels mode:(VPKViewMode)mode;

- (void)scrollCellToTop:(NSUInteger)cellIndex;
@end
