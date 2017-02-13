//
//  VPKCellModel.h
//  Pods
//
//  Created by jonathan on 11/06/2016.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

@class VPKCellModel;

@protocol VPKModelledCellProtocol <NSObject>

- (void)setCellModel:(id)cellModel;
- (void)setup;
//@optional
//+ (CGFloat) height;
//+ (CGSize)  sizeForModel:(id)model;
@end

@interface VPKCellModel : NSObject

@property (nonatomic, strong) id data;
@property (nonatomic, strong) Class cellClass;
@property (nonatomic, assign) CGSize cellSize;
@property (nonatomic, strong) NSString* reuseIdentifier;
@property (nonatomic, weak) id delegate;

- (void)setup;
@end
